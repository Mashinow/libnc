#include <pthread.h>

typedef void (*NCParallelRangeFunc)(void *opaque, size_t start, size_t end);

typedef struct NCParallelState {
    int n_threads;
    pthread_t *threads;
    pthread_mutex_t mutex;
    pthread_cond_t cond_work;
    pthread_cond_t cond_done;
    unsigned int generation;
    int stop;
    int active;
    size_t count;
    size_t next;
    size_t chunk;
    NCParallelRangeFunc fn;
    void *opaque;
} NCParallelState;

static int nc_parallel_auto_threads(int nb_threads)
{
    enum { NC_PARALLEL_MAX_THREADS = 8 };
    if (nb_threads > 1)
        return nb_threads > NC_PARALLEL_MAX_THREADS ? NC_PARALLEL_MAX_THREADS : nb_threads;
    {
        const char *s = getenv("NUMBER_OF_PROCESSORS");
        int n = s ? atoi(s) : 1;
        if (n < 1)
            n = 1;
        if (n > NC_PARALLEL_MAX_THREADS)
            n = NC_PARALLEL_MAX_THREADS;
        return n;
    }
}

static NCParallelState *nc_parallel_state_create(int nb_threads)
{
    int n_threads = nc_parallel_auto_threads(nb_threads);
    if (n_threads <= 1)
        return NULL;

    NCParallelState *ps = nc_mallocz(sizeof(*ps));
    if (!ps)
        nc_error("out of memory\n");
    ps->n_threads = n_threads;
    ps->threads = nc_mallocz(sizeof(*ps->threads) * (size_t)(n_threads - 1));
    if (!ps->threads)
        nc_error("out of memory\n");
    pthread_mutex_init(&ps->mutex, NULL);
    pthread_cond_init(&ps->cond_work, NULL);
    pthread_cond_init(&ps->cond_done, NULL);
    return ps;
}

static void nc_parallel_state_destroy(NCParallelState *ps)
{
    if (!ps)
        return;
    nc_free(ps->threads);
    pthread_mutex_destroy(&ps->mutex);
    pthread_cond_destroy(&ps->cond_work);
    pthread_cond_destroy(&ps->cond_done);
    nc_free(ps);
}

static size_t nc_parallel_choose_chunk(size_t count, int n_threads, size_t min_chunk)
{
    size_t chunk;
    if (count == 0)
        return 0;
    chunk = count / (size_t)(n_threads * 4);
    if (chunk < min_chunk)
        chunk = min_chunk;
    if (chunk == 0)
        chunk = 1;
    return chunk;
}

static void nc_parallel_claim_range(NCParallelState *ps, size_t *start, size_t *end)
{
    pthread_mutex_lock(&ps->mutex);
    *start = ps->next;
    if (*start >= ps->count) {
        *end = *start;
    } else {
        *end = *start + ps->chunk;
        if (*end > ps->count)
            *end = ps->count;
        ps->next = *end;
    }
    pthread_mutex_unlock(&ps->mutex);
}

static void nc_parallel_do_work(NCParallelState *ps)
{
    for (;;) {
        size_t start, end;
        nc_parallel_claim_range(ps, &start, &end);
        if (start >= end)
            break;
        ps->fn(ps->opaque, start, end);
    }
}

static void *nc_parallel_worker_thread(void *opaque)
{
    NCContext *ctx = opaque;
    NCParallelState *ps = ctx->parallel;
    unsigned int seen = 0;

    pthread_mutex_lock(&ps->mutex);
    for (;;) {
        while (!ps->stop && ps->generation == seen)
            pthread_cond_wait(&ps->cond_work, &ps->mutex);
        if (ps->stop)
            break;
        seen = ps->generation;
        pthread_mutex_unlock(&ps->mutex);
        nc_parallel_do_work(ps);
        pthread_mutex_lock(&ps->mutex);
        if (--ps->active == 0)
            pthread_cond_signal(&ps->cond_done);
    }
    pthread_mutex_unlock(&ps->mutex);
    return NULL;
}

static void nc_parallel_state_start(NCContext *ctx, NCParallelState *ps)
{
    int worker_count = ps->n_threads - 1;
    for (int i = 0; i < worker_count; i++) {
        if (pthread_create(&ps->threads[i], NULL, nc_parallel_worker_thread, ctx) != 0) {
            pthread_mutex_lock(&ps->mutex);
            ps->stop = TRUE;
            pthread_cond_broadcast(&ps->cond_work);
            pthread_mutex_unlock(&ps->mutex);
            for (int j = 0; j < i; j++)
                pthread_join(ps->threads[j], NULL);
            nc_parallel_state_destroy(ps);
            ctx->parallel = NULL;
            return;
        }
    }
}

static void nc_parallel_state_end(NCParallelState *ps)
{
    if (!ps)
        return;
    pthread_mutex_lock(&ps->mutex);
    ps->stop = TRUE;
    pthread_cond_broadcast(&ps->cond_work);
    pthread_mutex_unlock(&ps->mutex);
    for (int i = 0; i < ps->n_threads - 1; i++)
        pthread_join(ps->threads[i], NULL);
    nc_parallel_state_destroy(ps);
}

static void nc_parallel_for(NCContext *ctx, size_t count, size_t min_chunk,
                            NCParallelRangeFunc fn, void *opaque)
{
    NCParallelState *ps = ctx ? ctx->parallel : NULL;
    if (!ps || ps->n_threads <= 1 || count < min_chunk * (size_t)ps->n_threads) {
        if (count > 0)
            fn(opaque, 0, count);
        return;
    }

    pthread_mutex_lock(&ps->mutex);
    ps->fn = fn;
    ps->opaque = opaque;
    ps->count = count;
    ps->next = 0;
    ps->chunk = nc_parallel_choose_chunk(count, ps->n_threads, min_chunk);
    ps->active = ps->n_threads;
    ps->generation++;
    pthread_cond_broadcast(&ps->cond_work);
    pthread_mutex_unlock(&ps->mutex);

    nc_parallel_do_work(ps);

    pthread_mutex_lock(&ps->mutex);
    if (--ps->active == 0)
        pthread_cond_signal(&ps->cond_done);
    while (ps->active > 0)
        pthread_cond_wait(&ps->cond_done, &ps->mutex);
    pthread_mutex_unlock(&ps->mutex);
}
