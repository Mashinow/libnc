#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "libnc.h"

static void log_stage(const char *stage);

static void failf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("TEST FAIL: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(1);
}

static void check(int cond, const char *fmt, ...)
{
    if (cond)
        return;
    va_list ap;
    va_start(ap, fmt);
    fputs("TEST FAIL: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(1);
}

static void expect_closef(float got, float exp, float tol, const char *what)
{
    if (fabsf(got - exp) > tol)
        failf("%s: got=%g expected=%g tol=%g", what, got, exp, tol);
}

static void expect_close(double got, double exp, double tol, const char *what)
{
    if (fabs(got - exp) > tol)
        failf("%s: got=%g expected=%g tol=%g", what, got, exp, tol);
}

static void expect_dims(const NCTensor *x, int nd, const size_t *dims, const char *what)
{
    int got_nd = 0;
    const size_t *got = nc_tensor_get_dims(x, &got_nd);
    if (got_nd != nd)
        failf("%s: ndims got=%d expected=%d", what, got_nd, nd);
    for (int i = 0; i < nd; i++) {
        if (got[i] != dims[i])
            failf("%s: dim[%d] got=%zu expected=%zu", what, i, got[i], dims[i]);
    }
}

static void fill_seq_f32_1d(NCTensor *x, float start, float step)
{
    int nd = 0;
    const size_t *dims = nc_tensor_get_dims(x, &nd);
    check(nd == 1, "fill_seq_f32_1d expects 1D tensor");
    for (size_t i = 0; i < dims[0]; i++)
        nc_set1_f32_1d(x, i, start + step * (float)i);
}

static void fill_seq_i32_1d(NCTensor *x, int32_t start)
{
    int nd = 0;
    const size_t *dims = nc_tensor_get_dims(x, &nd);
    check(nd == 1, "fill_seq_i32_1d expects 1D tensor");
    for (size_t i = 0; i < dims[0]; i++)
        nc_set1_i32_1d(x, i, start + (int32_t)i);
}

static void set_f32_2d(NCTensor *x, size_t i0, size_t i1, float v)
{
    size_t idx[2] = { i0, i1 };
    nc_set1_f32(x, 2, idx, v);
}

static void set_i32_2d(NCTensor *x, size_t i0, size_t i1, int32_t v)
{
    size_t idx[2] = { i0, i1 };
    nc_set1_i32(x, 2, idx, v);
}

static float get_f32_2d(const NCTensor *x, size_t i0, size_t i1)
{
    size_t idx[2] = { i0, i1 };
    return nc_get1_f32(x, 2, idx);
}

static void expect_tensor_f32_1d(NCTensor *x, const float *exp, size_t n, float tol, const char *what)
{
    size_t got_n = nc_tensor_get_dims(x, NULL)[0];
    if (got_n != n)
        failf("%s: length got=%zu expected=%zu", what, got_n, n);
    for (size_t i = 0; i < n; i++) {
        float got = nc_get1_f32_1d(x, i);
        if (fabsf(got - exp[i]) > tol)
            failf("%s[%zu]: got=%g expected=%g tol=%g", what, i, got, exp[i], tol);
    }
}

static void expect_tensor_i32_1d(NCTensor *x, const int32_t *exp, size_t n, const char *what)
{
    size_t got_n = nc_tensor_get_dims(x, NULL)[0];
    if (got_n != n)
        failf("%s: length got=%zu expected=%zu", what, got_n, n);
    for (size_t i = 0; i < n; i++) {
        int32_t got = nc_get1_i32(x, 1, (size_t[]){ i });
        if (got != exp[i])
            failf("%s[%zu]: got=%d expected=%d", what, i, got, exp[i]);
    }
}

static float read_f32_linear(const NCTensor *x, size_t i)
{
    size_t stride = 0;
    const float *p = nc_tensor_get_ptr((NCTensor *)x, &stride);
    (void)stride;
    return p[i];
}

static void expect_tensor_f32_linear(NCTensor *x, const float *exp, size_t n, float tol, const char *what)
{
    for (size_t i = 0; i < n; i++) {
        float got = read_f32_linear(x, i);
        if (fabsf(got - exp[i]) > tol)
            failf("%s[%zu]: got=%g expected=%g tol=%g", what, i, got, exp[i], tol);
    }
}

static size_t tensor_elem_count(const NCTensor *x)
{
    int nd = 0;
    const size_t *dims = nc_tensor_get_dims(x, &nd);
    size_t total = 1;
    for (int i = 0; i < nd; i++)
        total *= dims[i];
    return total;
}

static void expect_tensor_f32_same(NCTensor *got, NCTensor *exp, float tol, const char *what)
{
    int gnd = 0;
    int end = 0;
    const size_t *gd = nc_tensor_get_dims(got, &gnd);
    const size_t *ed = nc_tensor_get_dims(exp, &end);
    check(gnd == end, "%s: ndims mismatch", what);
    for (int i = 0; i < gnd; i++)
        check(gd[i] == ed[i], "%s: dim[%d] mismatch", what, i);
    size_t total = tensor_elem_count(got);
    for (size_t i = 0; i < total; i++) {
        float gv = read_f32_linear(got, i);
        float ev = read_f32_linear(exp, i);
        if (fabsf(gv - ev) > tol)
            failf("%s[%zu]: got=%g expected=%g tol=%g", what, i, gv, ev, tol);
    }
}

static void save_grad_cb(void *opaque, NCTensor *g, NCTensor *get_col_index)
{
    (void)get_col_index;
    NCTensor **slot = opaque;
    if (*slot)
        nc_free_tensor(*slot);
    *slot = nc_dup_tensor(g);
}

static void save_grad_param_cb(void *opaque, NCTensor *g, NCTensor *get_col_index)
{
    (void)get_col_index;
    NCParam *p = opaque;
    if (p->saved_grad)
        nc_free_tensor(p->saved_grad);
    p->saved_grad = nc_dup_tensor(g);
}

static void test_runtime(NCContext *ctx)
{
    void *p = nc_malloc(32);
    check(p != NULL, "nc_malloc");
    memset(p, 0x5a, 32);
    nc_free(p);

    p = nc_mallocz(24);
    check(p != NULL, "nc_mallocz");
    for (int i = 0; i < 24; i++)
        check(((unsigned char *)p)[i] == 0, "nc_mallocz zero");
    nc_free(p);

    nc_prof_dump();

    size_t h0 = nc_get_heap_size(ctx);
    check(h0 > 0, "heap size");
}

static void test_devices_and_buffers(NCContext *ctx, NCDevice *cpu)
{
    NCDevice *d1 = nc_new_cpu_device(ctx);
    NCDevice *d2 = nc_new_cuda_device(ctx, 0);
    NCDevice *d3 = nc_new_device(ctx, "cpu");
    NCDevice *d4 = nc_new_device(ctx, "cuda:1");
    check(d1 != NULL && d2 != NULL && d3 != NULL && d4 != NULL, "devices");
    nc_synchronize(d1);
    nc_synchronize(d2);
    nc_synchronize(d3);
    nc_synchronize(d4);

    NCTensorBuffer *b = nc_new_tensor_buffer(cpu, 64);
    check(b != NULL, "tensor buffer");
    NCTensorBuffer *b2 = nc_dup_tensor_buffer(b);
    check(b2 == b, "dup buffer identity");
    nc_free_tensor_buffer(b2);
    nc_free_tensor_buffer(b);
}

static void test_cuda_tensor_benchmark(NCContext *ctx, NCDevice *cpu)
{
    log_stage("cuda_tensor_benchmark");
    NCDevice *cuda = nc_new_cuda_device(ctx, 0);
    check(cuda != NULL, "cuda backend device");

    {
        size_t n = 1u << 20;
        NCTensor *a = nc_new_tensor_1d(cpu, NC_TYPE_F32, n);
        NCTensor *b = nc_new_tensor_1d(cpu, NC_TYPE_F32, n);
        fill_seq_f32_1d(a, 1.0f, 0.001f);
        fill_seq_f32_1d(b, 2.0f, -0.002f);

        uint64_t cpu_cycles0 = get_cycles();
        NCTensor *cpu_res = nc_add(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
        nc_synchronize(cpu);
        uint64_t cpu_cycles = get_cycles() - cpu_cycles0;

        NCTensor *a_cuda = nc_tensor_to_device(nc_new_tensor_from_tensor(a), cuda);
        NCTensor *b_cuda = nc_tensor_to_device(nc_new_tensor_from_tensor(b), cuda);
        uint64_t cuda_cycles0 = get_cycles();
        NCTensor *cuda_res = nc_add(nc_dup_tensor(a_cuda), nc_dup_tensor(b_cuda));
        nc_synchronize(cuda);
        uint64_t cuda_cycles = get_cycles() - cuda_cycles0;

        NCTensor *cuda_cpu = nc_tensor_to_cpu_device(nc_dup_tensor(cuda_res));
        expect_tensor_f32_same(cuda_cpu, cpu_res, 1e-5f, "cuda add");
        fprintf(stderr, "[own_tests] cuda tensor bench add cpu_cycles=%llu cuda_cycles=%llu speedup=%0.3f\n",
                (unsigned long long)cpu_cycles,
                (unsigned long long)cuda_cycles,
                cuda_cycles ? (double)cpu_cycles / (double)cuda_cycles : 0.0);
        fflush(stderr);

        nc_free_tensor(cuda_cpu);
        nc_free_tensor(cuda_res);
        nc_free_tensor(b_cuda);
        nc_free_tensor(a_cuda);
        nc_free_tensor(cpu_res);
        nc_free_tensor(b);
        nc_free_tensor(a);
    }

    {
        const size_t m = 256;
        const size_t k = 256;
        const size_t n = 256;
        NCTensor *w = nc_new_tensor_2d(cpu, NC_TYPE_F32, m, k);
        NCTensor *x = nc_new_tensor_2d(cpu, NC_TYPE_F32, k, n);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < k; j++)
                set_f32_2d(w, i, j, (float)((i + j) % 17) * 0.01f + 0.1f);
        }
        for (size_t i = 0; i < k; i++) {
            for (size_t j = 0; j < n; j++)
                set_f32_2d(x, i, j, (float)((i * 3 + j * 7) % 19) * 0.02f + 0.05f);
        }

        uint64_t cpu_cycles0 = get_cycles();
        NCTensor *cpu_mm = nc_matmul(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(x));
        nc_synchronize(cpu);
        uint64_t cpu_cycles = get_cycles() - cpu_cycles0;

        NCTensor *w_cuda = nc_tensor_to_device(nc_new_tensor_from_tensor(w), cuda);
        NCTensor *x_cuda = nc_tensor_to_device(nc_new_tensor_from_tensor(x), cuda);
        uint64_t cuda_cycles0 = get_cycles();
        NCTensor *cuda_mm = nc_matmul(nc_dup_tensor(w_cuda), nc_dup_tensor(x_cuda));
        nc_synchronize(cuda);
        uint64_t cuda_cycles = get_cycles() - cuda_cycles0;

        NCTensor *cuda_mm_cpu = nc_tensor_to_cpu_device(nc_dup_tensor(cuda_mm));
        expect_tensor_f32_same(cuda_mm_cpu, cpu_mm, 1e-3f, "cuda matmul");
        fprintf(stderr, "[own_tests] cuda tensor bench matmul cpu_cycles=%llu cuda_cycles=%llu speedup=%0.3f\n",
                (unsigned long long)cpu_cycles,
                (unsigned long long)cuda_cycles,
                cuda_cycles ? (double)cpu_cycles / (double)cuda_cycles : 0.0);
        fflush(stderr);

        nc_free_tensor(cuda_mm_cpu);
        nc_free_tensor(cuda_mm);
        nc_free_tensor(x_cuda);
        nc_free_tensor(w_cuda);
        nc_free_tensor(cpu_mm);
        nc_free_tensor(x);
        nc_free_tensor(w);
    }
}

static void test_tensor_basics(NCContext *ctx, NCDevice *cpu, NCDevice *cuda)
{
    (void)ctx;
    log_stage("tensor_basics.scalar");
    NCTensor *s = nc_new_scalar(cpu, NC_TYPE_F32);
    nc_tensor_set_f32(s, 4.5f);
    expect_closef(nc_get_scalar_f32(s), 4.5f, 1e-6f, "scalar");

    log_stage("tensor_basics.vec");
    NCTensor *v = nc_new_vec_f32(cpu, 3, 2.5f);
    size_t dims1[] = { 3 };
    expect_dims(v, 1, dims1, "vec");
    expect_tensor_f32_1d(v, (float[]){ 2.5f, 2.5f, 2.5f }, 3, 1e-6f, "vec");

    log_stage("tensor_basics.new_f32");
    NCTensor *f = nc_new_f32(cpu, 1.25f);
    expect_closef(nc_get_scalar_f32(f), 1.25f, 1e-6f, "new_f32");

    log_stage("tensor_basics.tensor_2d");
    NCTensor *t = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 3);
    size_t dims2[] = { 2, 3 };
    expect_dims(t, 2, dims2, "2d tensor");
    set_f32_2d(t, 0, 0, 1.0f);
    set_f32_2d(t, 0, 1, 2.0f);
    set_f32_2d(t, 0, 2, 3.0f);
    set_f32_2d(t, 1, 0, 4.0f);
    set_f32_2d(t, 1, 1, 5.0f);
    set_f32_2d(t, 1, 2, 6.0f);
    expect_closef(nc_get1_f32(t, 2, (size_t[]){ 1, 2 }), 6.0f, 1e-6f, "get1_f32");

    NCTensorData sd;
    nc_tensor_get_data(&sd, t);
    check(sd.item_type == NC_TYPE_F32, "tensor_get_data type");
    check(sd.item_size == 4, "tensor_get_data size");
    check(sd.stride == 6, "tensor_get_data stride");
    check(sd.n_dims == 2, "tensor_get_data ndims");
    check(sd.dims[0] == 2 && sd.dims[1] == 3, "tensor_get_data dims");

    log_stage("tensor_basics.ptr_and_copy");
    size_t pstride = 0;
    float *ptr = nc_tensor_get_ptr(t, &pstride);
    check(pstride == 3, "tensor_get_ptr stride");
    check(ptr[5] == 6.0f, "tensor_get_ptr data");

    NCTensor *copy = nc_new_tensor_from_tensor(t);
    expect_tensor_f32_linear(copy, (float[]){ 1,2,3,4,5,6 }, 6, 1e-6f, "tensor copy");
    NCTensor *zero = nc_new_tensor_from_tensor_nz(t);
    expect_tensor_f32_linear(zero, (float[]){ 0,0,0,0,0,0 }, 6, 1e-6f, "tensor nz");

    log_stage("tensor_basics.hash_and_name");
    uint32_t h1 = nc_tensor_get_hash(t);
    uint32_t h2 = nc_tensor_get_hash(copy);
    check(h1 == h2, "tensor hash equal");
    set_f32_2d(copy, 1, 2, 7.0f);
    check(nc_tensor_get_hash(copy) != h1, "tensor hash change");

    nc_tensor_set_name(t, "tensor_%d", 7);
    nc_dump_tensor("t", t, 0);
    nc_dump_tensor_hash("t", t);
    nc_dump_dims("t", t);

    log_stage("tensor_basics.dup_and_device");
    NCTensor *dup = nc_dup_tensor(t);
    check(dup == t, "dup tensor identity");
    nc_free_tensor(dup);

    NCTensor *to_cuda = nc_tensor_to_device(nc_new_tensor_from_tensor(t), cuda);
    expect_tensor_f32_linear(to_cuda, (float[]){ 1,2,3,4,5,6 }, 6, 1e-6f, "tensor_to_device");
    NCTensor *back_cpu = nc_tensor_to_cpu_device(to_cuda);
    expect_tensor_f32_linear(back_cpu, (float[]){ 1,2,3,4,5,6 }, 6, 1e-6f, "tensor_to_cpu");

    log_stage("tensor_basics.convert");
    NCTensor *cvt = nc_convert(nc_new_tensor_from_tensor(t), NC_TYPE_BF16);
    NCTensor *cvt2 = nc_convert(cvt, NC_TYPE_F32);
    expect_tensor_f32_linear(cvt2, (float[]){ 1,2,3,4,5,6 }, 6, 2e-2f, "convert roundtrip");

    log_stage("tensor_basics.tensor_convert");
    NCTensor *dst = nc_new_tensor(cpu, NC_TYPE_BF16, 2, dims2);
    nc_tensor_convert(dst, t);
    NCTensor *dst2 = nc_convert(dst, NC_TYPE_F32);
    expect_tensor_f32_linear(dst2, (float[]){ 1,2,3,4,5,6 }, 6, 2e-2f, "tensor_convert");

    log_stage("tensor_basics.cleanup");
    nc_free_tensor(dst2);
    nc_free_tensor(cvt2);
    nc_free_tensor(back_cpu);
    nc_free_tensor(zero);
    nc_free_tensor(copy);
    nc_free_tensor(t);
    nc_free_tensor(f);
    nc_free_tensor(v);
    nc_free_tensor(s);
}

static void test_elementwise(NCDevice *cpu)
{
    NCTensor *a = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
    NCTensor *b = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
    NCTensor *mask = nc_new_tensor_1d(cpu, NC_TYPE_I32, 4);
    fill_seq_f32_1d(a, 1.0f, 1.0f);
    nc_set1_f32_1d(b, 0, 4.0f);
    nc_set1_f32_1d(b, 1, 3.0f);
    nc_set1_f32_1d(b, 2, 2.0f);
    nc_set1_f32_1d(b, 3, 1.0f);
    nc_set1_i32_1d(mask, 0, 0);
    nc_set1_i32_1d(mask, 1, 1);
    nc_set1_i32_1d(mask, 2, 0);
    nc_set1_i32_1d(mask, 3, 1);

    NCTensor *add = nc_add(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(add, (float[]){ 5, 5, 5, 5 }, 4, 1e-6f, "add");

    NCTensor *sub = nc_sub(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(sub, (float[]){ -3, -1, 1, 3 }, 4, 1e-6f, "sub");

    NCTensor *mul = nc_mul(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(mul, (float[]){ 4, 6, 6, 4 }, 4, 1e-6f, "mul");

    NCTensor *div = nc_div(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_closef(nc_get1_f32_1d(div, 0), 0.25f, 1e-6f, "div0");
    expect_closef(nc_get1_f32_1d(div, 1), 2.0f / 3.0f, 1e-6f, "div1");

    NCTensor *recip = nc_recip(nc_new_tensor_from_tensor(a));
    expect_tensor_f32_1d(recip, (float[]){ 1.0f, 0.5f, 1.0f / 3.0f, 0.25f }, 4, 1e-6f, "recip");

    NCTensor *mn = nc_min(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(mn, (float[]){ 1, 2, 2, 1 }, 4, 1e-6f, "min");

    NCTensor *mx = nc_max(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(mx, (float[]){ 4, 3, 3, 4 }, 4, 1e-6f, "max");

    NCTensor *sel = nc_select(nc_new_tensor_from_tensor(mask), nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    expect_tensor_f32_1d(sel, (float[]){ 1, 3, 3, 1 }, 4, 1e-6f, "select");

    NCTensor *mfill = nc_masked_fill(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(mask), 9.0f, FALSE);
    expect_tensor_f32_1d(mfill, (float[]){ 1, 9, 3, 9 }, 4, 1e-6f, "masked_fill");
    NCTensor *mfill2 = nc_masked_fill(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(mask), 7.0f, TRUE);
    expect_tensor_f32_1d(mfill2, (float[]){ 7, 2, 7, 4 }, 4, 1e-6f, "masked_fill_inv");

    NCTensor *sig = nc_sigmoid(nc_new_tensor_from_tensor(a));
    expect_closef(nc_get1_f32_1d(sig, 0), 1.0f / (1.0f + expf(-1.0f)), 1e-6f, "sigmoid");

    NCTensor *th = nc_tanh(nc_new_tensor_from_tensor(a));
    expect_closef(nc_get1_f32_1d(th, 1), tanhf(2.0f), 1e-6f, "tanh");

    NCTensor *rel = nc_relu(nc_new_tensor_from_tensor(a));
    expect_closef(nc_get1_f32_1d(rel, 2), 3.0f, 1e-6f, "relu");

    NCTensor *gelu = nc_gelu(nc_new_tensor_from_tensor(a));
    expect_closef(nc_get1_f32_1d(gelu, 0), 0.84119199f, 1e-4f, "gelu");

    NCTensor *lg = nc_log(nc_new_tensor_from_tensor(a));
    expect_closef(nc_get1_f32_1d(lg, 3), logf(4.0f), 1e-6f, "log");

    NCTensor *cp = nc_new_tensor_1d(cpu, NC_TYPE_F32, 1);
    NCTensor *in = nc_new_tensor_1d(cpu, NC_TYPE_F32, 1);
    NCTensor *fg = nc_new_tensor_1d(cpu, NC_TYPE_F32, 1);
    NCTensor *ig = nc_new_tensor_1d(cpu, NC_TYPE_F32, 1);
    nc_set1_f32_1d(cp, 0, 2.0f);
    nc_set1_f32_1d(in, 0, 4.0f);
    nc_set1_f32_1d(fg, 0, 0.25f);
    nc_set1_f32_1d(ig, 0, 0.1f);
    NCTensor *lstm = nc_lstm_clamped(cp, in, fg, ig);
    expect_closef(nc_get1_f32_1d(lstm, 0), 0.25f * 2.0f + 0.1f * 4.0f, 1e-6f, "lstm_clamped");

    NCTensor *aa = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
    NCTensor *bb = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
    NCTensor *tt = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
    fill_seq_f32_1d(aa, 1.0f, 1.0f);
    nc_set1_f32_1d(bb, 0, 4.0f);
    nc_set1_f32_1d(bb, 1, 3.0f);
    nc_set1_f32_1d(bb, 2, 2.0f);
    nc_set1_f32_1d(bb, 3, 1.0f);
    nc_set1_f32_1d(tt, 0, 0.0f);
    nc_set1_f32_1d(tt, 1, 1.0f);
    nc_set1_f32_1d(tt, 2, 0.5f);
    nc_set1_f32_1d(tt, 3, 0.25f);
    NCTensor *lerp = nc_lerp(aa, bb, tt);
    expect_tensor_f32_1d(lerp, (float[]){ 1, 3, 2.5f, 3.25f }, 4, 1e-6f, "lerp");

    nc_free_tensor(lerp);
    nc_free_tensor(tt);
    nc_free_tensor(bb);
    nc_free_tensor(aa);
    nc_free_tensor(lstm);
    nc_free_tensor(ig);
    nc_free_tensor(fg);
    nc_free_tensor(in);
    nc_free_tensor(cp);
    nc_free_tensor(lg);
    nc_free_tensor(gelu);
    nc_free_tensor(rel);
    nc_free_tensor(th);
    nc_free_tensor(sig);
    nc_free_tensor(mfill2);
    nc_free_tensor(mfill);
    nc_free_tensor(sel);
    nc_free_tensor(mx);
    nc_free_tensor(mn);
    nc_free_tensor(recip);
    nc_free_tensor(div);
    nc_free_tensor(mul);
    nc_free_tensor(sub);
    nc_free_tensor(add);
    nc_free_tensor(mask);
    nc_free_tensor(b);
    nc_free_tensor(a);
}

static void test_layout_and_shape(NCDevice *cpu)
{
    NCTensor *v = nc_new_tensor_1d(cpu, NC_TYPE_F32, 6);
    fill_seq_f32_1d(v, 1.0f, 1.0f);

    NCTensor *r2 = nc_reshape_2d(nc_new_tensor_from_tensor(v), 2, 3);
    expect_tensor_f32_linear(r2, (float[]){ 1,2,3,4,5,6 }, 6, 1e-6f, "reshape2d");
    NCTensor *r1 = nc_reshape_1d(nc_new_tensor_from_tensor(r2), 6);
    expect_tensor_f32_1d(r1, (float[]){ 1,2,3,4,5,6 }, 6, 1e-6f, "reshape1d");

    NCTensor *rep = nc_repeat_1d(nc_new_tensor_from_tensor(v), 2);
    size_t rdims[] = { 6, 2 };
    expect_dims(rep, 2, rdims, "repeat_1d dims");
    expect_tensor_f32_linear(rep, (float[]){ 1,2,3,4,5,6,1,2,3,4,5,6 }, 12, 1e-6f, "repeat_1d");

    NCTensor *sum = nc_sum(nc_new_tensor_from_tensor(v));
    expect_closef(nc_get_scalar_f32(sum), 21.0f, 1e-6f, "sum");

    NCTensor *rs = nc_reduce_sum_sqr(nc_new_tensor_from_tensor(v));
    expect_closef(nc_get_scalar_f32(rs), 91.0f, 1e-6f, "sum_sqr");

    NCTensor *m = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 3);
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 3; j++)
            set_f32_2d(m, i, j, (float)(i * 3 + j + 1));
    NCTensor *rs1 = nc_reduce_sum(NULL, nc_new_tensor_from_tensor(m), 1);
    expect_dims(rs1, 1, (size_t[]){ 2 }, "reduce_sum dims");
    expect_tensor_f32_1d(rs1, (float[]){ 6, 15 }, 2, 1e-6f, "reduce_sum");

    NCTensor *sl0 = nc_slice(nc_new_tensor_from_tensor(m), 0, 1, 2);
    expect_dims(sl0, 2, (size_t[]){ 1, 3 }, "slice0 dims");
    expect_tensor_f32_linear(sl0, (float[]){ 4,5,6 }, 3, 1e-6f, "slice0");

    NCTensor *sl1 = nc_slice(nc_new_tensor_from_tensor(m), 1, 1, 3);
    expect_dims(sl1, 2, (size_t[]){ 2, 2 }, "slice1 dims");
    expect_tensor_f32_linear(sl1, (float[]){ 2,3,5,6 }, 4, 1e-6f, "slice1");

    NCTensor *y0 = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 3);
    nc_tensor_set_zero(y0);
    NCTensor *sa = nc_slice_add(y0, nc_new_tensor_from_tensor(sl0), 0, 1);
    expect_tensor_f32_linear(sa, (float[]){ 0,0,0,4,5,6 }, 6, 1e-6f, "slice_add");

    NCTensor *c0 = nc_new_tensor_1d(cpu, NC_TYPE_F32, 2);
    NCTensor *c1 = nc_new_tensor_1d(cpu, NC_TYPE_F32, 1);
    nc_set1_f32_1d(c0, 0, 1.0f);
    nc_set1_f32_1d(c0, 1, 2.0f);
    nc_set1_f32_1d(c1, 0, 3.0f);
    NCTensor *cat = nc_concat((NCTensor *[]){ c0, c1 }, 2, 0);
    expect_tensor_f32_1d(cat, (float[]){ 1,2,3 }, 3, 1e-6f, "concat");
    NCTensor *cat2 = nc_vconcat((NCTensor *[]){ nc_new_tensor_from_tensor(c0), nc_new_tensor_from_tensor(c1) }, 2);
    expect_tensor_f32_1d(cat2, (float[]){ 1,2,3 }, 3, 1e-6f, "vconcat");

    NCTensor *sp0 = NULL;
    NCTensor *sp1 = NULL;
    NCTensor *split_out[2] = { NULL, NULL };
    nc_split(split_out, cat, 2, (size_t[]){ 2, 1 }, 0);
    sp0 = split_out[0];
    sp1 = split_out[1];
    expect_tensor_f32_1d(sp0, (float[]){ 1,2 }, 2, 1e-6f, "split0");
    expect_tensor_f32_1d(sp1, (float[]){ 3 }, 1, 1e-6f, "split1");

    NCTensor *pad0 = nc_pad(nc_new_tensor_from_tensor(v), 1, NC_PAD_ZERO, 2, NC_PAD_DUP);
    expect_tensor_f32_1d(pad0, (float[]){ 0,1,2,3,4,5,6,6,6 }, 9, 1e-6f, "pad");
    NCTensor *resz = nc_resize(nc_new_tensor_from_tensor(v), 8);
    expect_tensor_f32_1d(resz, (float[]){ 1,2,3,4,5,6,0,0 }, 8, 1e-6f, "resize");

    NCTensor *perm_src = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 3);
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 3; j++)
            set_f32_2d(perm_src, i, j, (float)(i * 10 + j + 1));
    int axis[2] = { 1, 0 };
    NCTensor *pa = nc_permute_alias(nc_new_tensor_from_tensor(perm_src), 2, axis);
    NCTensor *pc = nc_permute(nc_new_tensor_from_tensor(perm_src), 2, axis);
    NCTensor *contig = nc_make_contiguous(pa);
    expect_tensor_f32_linear(pc, (float[]){ 1,11,2,12,3,13 }, 6, 1e-6f, "permute");
    expect_tensor_f32_linear(contig, (float[]){ 1,11,2,12,3,13 }, 6, 1e-6f, "make_contiguous");
    NCTensor *tr = nc_transpose(nc_new_tensor_from_tensor(perm_src));
    expect_tensor_f32_linear(tr, (float[]){ 1,11,2,12,3,13 }, 6, 1e-6f, "transpose");

    log_stage("layout_and_shape.free_tr");
    nc_free_tensor(tr);
    log_stage("layout_and_shape.free_contig");
    nc_free_tensor(contig);
    log_stage("layout_and_shape.free_pc");
    nc_free_tensor(pc);
    log_stage("layout_and_shape.free_perm_src");
    nc_free_tensor(perm_src);
    log_stage("layout_and_shape.free_resz");
    nc_free_tensor(resz);
    log_stage("layout_and_shape.free_pad0");
    nc_free_tensor(pad0);
    log_stage("layout_and_shape.free_sp1");
    nc_free_tensor(sp1);
    log_stage("layout_and_shape.free_sp0");
    nc_free_tensor(sp0);
    log_stage("layout_and_shape.free_cat2");
    nc_free_tensor(cat2);
    log_stage("layout_and_shape.free_cat");
    nc_free_tensor(cat);
    log_stage("layout_and_shape.free_c1");
    nc_free_tensor(c1);
    log_stage("layout_and_shape.free_c0");
    nc_free_tensor(c0);
    log_stage("layout_and_shape.free_sa");
    nc_free_tensor(sa);
    log_stage("layout_and_shape.free_sl1");
    nc_free_tensor(sl1);
    log_stage("layout_and_shape.free_sl0");
    nc_free_tensor(sl0);
    log_stage("layout_and_shape.free_rs1");
    nc_free_tensor(rs1);
    log_stage("layout_and_shape.free_m");
    nc_free_tensor(m);
    log_stage("layout_and_shape.free_rs");
    nc_free_tensor(rs);
    log_stage("layout_and_shape.free_sum");
    nc_free_tensor(sum);
    log_stage("layout_and_shape.free_rep");
    nc_free_tensor(rep);
    log_stage("layout_and_shape.free_r1");
    nc_free_tensor(r1);
    log_stage("layout_and_shape.free_r2");
    nc_free_tensor(r2);
    log_stage("layout_and_shape.free_v");
    nc_free_tensor(v);
}

static void matmul2x2_expected(const float w[4], const float x[4], const float y0[4],
                               float out[4], BOOL w_trans, BOOL x_trans)
{
    for (size_t row = 0; row < 2; row++) {
        for (size_t col = 0; col < 2; col++) {
            float acc = y0 ? y0[col * 2 + row] : 0.0f;
            for (size_t k = 0; k < 2; k++) {
                float aw = w_trans ? w[row * 2 + k] : w[k * 2 + row];
                float bx = x_trans ? x[k * 2 + col] : x[col * 2 + k];
                acc += aw * bx;
            }
            out[col * 2 + row] = acc;
        }
    }
}

static void test_linear_algebra_and_indexed(NCDevice *cpu)
{
    NCTensor *w = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 2);
    NCTensor *x = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 2);
    float wv[] = { 1, 2, 3, 4 };
    float xv[] = { 5, 6, 7, 8 };
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++) {
            set_f32_2d(w, i, j, wv[i * 2 + j]);
            set_f32_2d(x, i, j, xv[i * 2 + j]);
        }
    float mref[4];
    matmul2x2_expected(wv, xv, NULL, mref, FALSE, FALSE);
    NCTensor *m = nc_matmul(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(x));
    expect_tensor_f32_linear(m, mref, 4, 1e-6f, "matmul");
    NCTensor *ms = nc_matmul_stride(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(x));
    expect_tensor_f32_linear(ms, mref, 4, 1e-6f, "matmul_stride");

    float y0v[4] = { 1, 2, 3, 4 };
    float mref2[4];
    matmul2x2_expected(wv, xv, y0v, mref2, TRUE, FALSE);
    NCTensor *ya = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 2);
    for (size_t col = 0; col < 2; col++)
        for (size_t row = 0; row < 2; row++)
            set_f32_2d(ya, col, row, y0v[col * 2 + row]);
    NCTensor *ma = nc_matmul_add(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(x), nc_new_tensor_from_tensor(ya), TRUE, FALSE);
    expect_tensor_f32_linear(ma, mref2, 4, 1e-6f, "matmul_add");

    NCTensor *idx = nc_new_tensor_1d(cpu, NC_TYPE_I32, 2);
    nc_set1_i32_1d(idx, 0, 1);
    nc_set1_i32_1d(idx, 1, 0);
    NCTensor *col = nc_get_col(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(idx));
    expect_tensor_f32_linear(col, (float[]){ 2, 1, 4, 3 }, 4, 1e-6f, "get_col");
    NCTensor *acol = nc_add_col(nc_new_tensor_from_tensor(col), nc_new_tensor_from_tensor(idx), nc_new_tensor_from_tensor(w));
    expect_tensor_f32_linear(acol, (float[]){ 2, 4, 6, 8 }, 4, 1e-6f, "add_col");

    NCTensor *eidx = nc_new_tensor_1d(cpu, NC_TYPE_I32, 2);
    nc_set1_i32_1d(eidx, 0, 1);
    nc_set1_i32_1d(eidx, 1, 0);
    NCTensor *elem = nc_get_element(nc_new_tensor_from_tensor(w), nc_new_tensor_from_tensor(eidx));
    expect_tensor_f32_1d(elem, (float[]){ 3, 2 }, 2, 1e-6f, "get_element");
    NCTensor *aelem = nc_add_element(nc_new_tensor_from_tensor(elem), nc_new_tensor_from_tensor(eidx), nc_new_tensor_from_tensor(w));
    expect_tensor_f32_linear(aelem, (float[]){ 1, 4, 6, 4 }, 4, 1e-6f, "add_element");

    NCTensor *sm = nc_soft_max(nc_new_tensor_from_tensor(w));
    float e0 = expf(1.0f - 2.0f);
    float e1 = expf(2.0f - 2.0f);
    float s0 = e0 + e1;
    float e2 = expf(3.0f - 4.0f);
    float e3 = expf(4.0f - 4.0f);
    float s1 = e2 + e3;
    expect_tensor_f32_linear(sm, (float[]){ e0 / s0, e1 / s0, e2 / s1, e3 / s1 }, 4, 1e-6f, "softmax");

    NCTensor *ilog = nc_indexed_log(nc_new_tensor_from_tensor(sm), nc_new_tensor_from_tensor(idx));
    expect_closef(nc_get1_f32_1d(ilog, 0), logf(nc_get1_f32((const NCTensor *)sm, 2, (size_t[]){ 0, 1 })), 1e-6f, "indexed_log0");
    expect_closef(nc_get1_f32_1d(ilog, 1), logf(nc_get1_f32((const NCTensor *)sm, 2, (size_t[]){ 1, 0 })), 1e-6f, "indexed_log1");

    NCTensor *ln_in = nc_new_tensor_1d(cpu, NC_TYPE_F32, 3);
    nc_set1_f32_1d(ln_in, 0, 1.0f);
    nc_set1_f32_1d(ln_in, 1, 2.0f);
    nc_set1_f32_1d(ln_in, 2, 3.0f);
    NCTensor *ln = nc_layer_norm(nc_new_tensor_from_tensor(ln_in), 1e-5f);
    expect_closef(nc_get1_f32_1d(ln, 0), -1.2247448f, 1e-4f, "layer_norm");
    NCTensor *rn = nc_rms_norm(nc_new_tensor_from_tensor(ln_in), 1e-5f);
    expect_closef(nc_get1_f32_1d(rn, 0), 1.0f / sqrtf((1.0f + 4.0f + 9.0f) / 3.0f + 1e-5f), 1e-4f, "rms_norm");

    NCTensor *slt = nc_new_tensor_2d(cpu, NC_TYPE_F32, 4, 3);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++)
            set_f32_2d(slt, i, j, (float)(i * 3 + j + 1));
    NCTensor *slt2 = nc_slt_mat_set(nc_new_tensor_from_tensor(slt), 1, 9.0f);
    expect_tensor_f32_linear(slt2, (float[]){ 1,2,3,9,9,6,9,9,9,9,9,9 }, 12, 1e-6f, "slt_mat_set");

    NCTensor *rs = nc_new_tensor_2d(cpu, NC_TYPE_F32, 2, 3);
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 3; j++)
            set_f32_2d(rs, i, j, (float)(i * 3 + j + 1));
    NCTensor *sh = nc_rel_shift(nc_new_tensor_from_tensor(rs), -1, 1);
    expect_tensor_f32_linear(sh, (float[]){ 2,3,0,4,5,6 }, 6, 1e-6f, "rel_shift");

    nc_free_tensor(sh);
    nc_free_tensor(rs);
    nc_free_tensor(slt2);
    nc_free_tensor(slt);
    nc_free_tensor(rn);
    nc_free_tensor(ln);
    nc_free_tensor(ln_in);
    nc_free_tensor(ilog);
    nc_free_tensor(sm);
    nc_free_tensor(aelem);
    nc_free_tensor(elem);
    nc_free_tensor(eidx);
    nc_free_tensor(acol);
    nc_free_tensor(col);
    nc_free_tensor(idx);
    nc_free_tensor(ma);
    nc_free_tensor(ya);
    nc_free_tensor(ms);
    nc_free_tensor(m);
    nc_free_tensor(x);
    nc_free_tensor(w);
}

static void test_graph_helpers_and_backward(NCContext *ctx, NCDevice *cpu)
{
    NCTensor *a = nc_new_tensor_1d(cpu, NC_TYPE_F32, 3);
    NCTensor *b = nc_new_tensor_1d(cpu, NC_TYPE_F32, 3);
    fill_seq_f32_1d(a, 1.0f, 1.0f);
    fill_seq_f32_1d(b, 4.0f, -1.0f);

    NCTensor *add = nc_add(nc_new_tensor_from_tensor(a), nc_new_tensor_from_tensor(b));
    NCNode *n = nc_get_node(add);
    check(n != NULL, "get_node");
    NCNode *dup = nc_dup_node(n);
    check(dup != NULL, "dup_node");

    NCNode *catnode = nc_concat_node(ctx, (NCNode *[]){ n, dup }, 2, 0, (size_t[]){ 1, 2 });
    check(catnode != NULL, "concat_node");
    nc_combine_nodes(ctx, (NCNode *[]){ catnode, n }, 2, 0, 1, (size_t[]){ 1, 2 });
    nc_free_node(catnode);

    NCTensor *ca = nc_new_tensor_1d(cpu, NC_TYPE_F32, 2);
    NCTensor *cb = nc_new_tensor_1d(cpu, NC_TYPE_F32, 2);
    nc_set1_f32_1d(ca, 0, 1.0f);
    nc_set1_f32_1d(ca, 1, 2.0f);
    nc_set1_f32_1d(cb, 0, 3.0f);
    nc_set1_f32_1d(cb, 1, 4.0f);
    NCTensor *cat = nc_concat((NCTensor *[]){ nc_new_tensor_from_tensor(ca), nc_new_tensor_from_tensor(cb) }, 2, 0);
    nc_concat_optimization(ctx, (NCNode *[]){ nc_get_node(cat) }, 1);
    nc_dump_graph(cat);

    NCTensor *arg = nc_new_tensor_1d(cpu, NC_TYPE_F32, 3);
    fill_seq_f32_1d(arg, 1.0f, 1.0f);
    NCTensor *param = nc_set_param(nc_new_tensor_from_tensor(arg), ctx);
    check(nc_get_node(param) != NULL, "set_param node");
    NCTensor *stopped = nc_stop_grad(nc_new_tensor_from_tensor(param));
    check(nc_get_node(stopped) == NULL, "stop_grad");

    nc_free_tensor(stopped);
    nc_free_tensor(param);
    nc_free_tensor(arg);
    nc_free_tensor(cat);
    nc_free_tensor(cb);
    nc_free_tensor(ca);
    nc_free_node(dup);
    nc_free_tensor(add);
    nc_free_tensor(a);
    nc_free_tensor(b);
}

static void test_params_and_sgd(NCContext *ctx, NCDevice *cpu)
{
    (void)ctx;
    NCParamList pl;
    nc_param_list_init(&pl);
    nc_param_list_set_graph(&pl, TRUE);

    NCTensor *p1 = nc_new_tensor_1d(cpu, NC_TYPE_F32, 3);
    NCTensor *p2 = nc_new_tensor_1d(cpu, NC_TYPE_F32, 2);
    fill_seq_f32_1d(p1, 1.0f, 1.0f);
    fill_seq_f32_1d(p2, 10.0f, 1.0f);
    NCParam *pp1 = nc_new_param(&pl, &p1, "p1");
    NCParam *pp2 = nc_new_param_str(&pl, &p2, "p2");
    check(nc_get_param_count(&pl) == 2, "param count");
    check(nc_find_param(&pl, "p1") == pp1, "find param p1");
    check(nc_find_param(&pl, "p2") == pp2, "find param p2");

    const char *coef_file = "own_tests_coefs.bin";
    const char *state_file = "own_tests_state.bin";
    remove(coef_file);
    remove(state_file);

    nc_save_coefs(&pl, coef_file);
    nc_tensor_set_f32(p1, 100.0f);
    nc_tensor_set_f32(p2, 200.0f);
    nc_load_coefs(&pl, coef_file);
    expect_tensor_f32_1d(p1, (float[]){ 1,2,3 }, 3, 1e-6f, "load_coefs p1");
    expect_tensor_f32_1d(p2, (float[]){ 10,11 }, 2, 1e-6f, "load_coefs p2");

    nc_save_state(&pl, state_file);
    nc_tensor_set_f32(p1, 7.0f);
    nc_tensor_set_f32(p2, 8.0f);
    nc_load_state(&pl, state_file);
    expect_tensor_f32_1d(p1, (float[]){ 1,2,3 }, 3, 1e-6f, "load_state p1");
    expect_tensor_f32_1d(p2, (float[]){ 10,11 }, 2, 1e-6f, "load_state p2");

    SGDOptParams optp = {
        .algo = SGD_OPT_BASIC,
        .lr = 0.1f,
    };
    NCSGDOptState *opt = nc_sgd_opt_init(ctx, &optp);
    nc_sgd_opt_set_lr(opt, 0.05f);
    expect_closef(nc_sgd_opt_get_lr(opt), 0.05f, 1e-6f, "sgd lr");
    nc_sgd_opt_set_all(&pl, opt);

    NCTensor *x = nc_new_f32(cpu, 3.0f);
    NCParamList pl2;
    nc_param_list_init(&pl2);
    NCParam *px = nc_new_param(&pl2, &x, "x");
    nc_sgd_opt_set(px, opt);
    px->saved_grad = nc_new_scalar(cpu, NC_TYPE_F32);
    nc_tensor_set_f32(px->saved_grad, 6.0f);
    NCTensor *g = nc_sgd_opt_get_grad(px);
    check(g != NULL, "get_grad");
    expect_closef(nc_get_scalar_f32(g), 6.0f, 1e-6f, "sgd get grad");
    nc_free_tensor(g);
    nc_sgd_opt_update(opt);
    expect_closef(nc_get_scalar_f32(x), 2.7f, 1e-6f, "sgd update");
    nc_free_tensor(px->saved_grad);
    px->saved_grad = NULL;
    nc_sgd_opt_end(opt);

    nc_free_tensor(x);
    nc_param_list_end(&pl2);

    remove(coef_file);
    remove(state_file);
    nc_param_list_end(&pl);
    nc_free_tensor(p2);
    nc_free_tensor(p1);
}

static void test_misc(void)
{
    RNDState rs1, rs2;
    rnd_init(&rs1, 1234);
    rnd_init(&rs2, 1234);
    check(rnd_unif_u32(&rs1) == rnd_unif_u32(&rs2), "rnd_unif_u32 deterministic");
    check(fabsf(rnd_unif(&rs1) - rnd_unif(&rs2)) < 1e-9f, "rnd_unif deterministic");

    float vec[4] = { 0 };
    rnd_unif_vec(vec, 4, 1.0f, 0.5f, &rs1);
    for (int i = 0; i < 4; i++)
        check(vec[i] >= 0.5f && vec[i] <= 1.5f, "rnd_unif_vec range");

    float mat[6] = { 0 };
    rnd_unif_mat(mat, 3, 2, 3, 0.0f, 1.0f, &rs1);
    float sum = vec_sum_f32((const float[]){ 1, 2, 3 }, 3);
    expect_closef(sum, 6.0f, 1e-6f, "vec_sum_f32");

    float prob[] = { 0.1f, 0.4f, 0.2f, 0.3f };
    NCTopKEntry *tab = NULL;
    double psum = 0.0;
    int k = nc_topk(&tab, &psum, prob, 4, 3, 0.45f);
    check(k == 2, "topk count");
    check(tab[0].idx == 1 && tab[1].idx == 3, "topk order");
    expect_close(psum, 0.7, 1e-6, "topk sum");
    nc_free(tab);
}

static BOOL tests_success = FALSE;
static const char *current_stage = "startup";

static void print_all_tests_success(void)
{
    if (tests_success) {
        fprintf(stderr, "all tests success\n");
        fflush(stderr);
    }
}

static void log_stage(const char *stage)
{
    current_stage = stage;
    fprintf(stderr, "[own_tests] %s\n", stage);
    fflush(stderr);
}

int main(void)
{
    atexit(print_all_tests_success);
    setvbuf(stderr, NULL, _IONBF, 0);
    log_stage("init_context");
    NCContext *ctx = nc_context_init(1);
    log_stage("create_devices");
    NCDevice *cpu = nc_new_cpu_device(ctx);
    NCDevice *cuda = nc_new_device(ctx, "cuda:0");
    check(ctx != NULL && cpu != NULL && cuda != NULL, "context/devices");

    log_stage("runtime");
    test_runtime(ctx);
    log_stage("devices_and_buffers");
    test_devices_and_buffers(ctx, cpu);
    test_cuda_tensor_benchmark(ctx, cpu);
    log_stage("tensor_basics");
    test_tensor_basics(ctx, cpu, cuda);
    log_stage("elementwise");
    test_elementwise(cpu);
    log_stage("layout_and_shape");
    test_layout_and_shape(cpu);
    log_stage("linear_algebra_and_indexed");
    test_linear_algebra_and_indexed(cpu);
    log_stage("graph_helpers_and_backward");
    test_graph_helpers_and_backward(ctx, cpu);
    log_stage("params_and_sgd");
    test_params_and_sgd(ctx, cpu);
    log_stage("misc");
    test_misc();

    log_stage("end_context");
    nc_context_end(ctx);
    tests_success = TRUE;
    log_stage("completed");
    return 0;
}
