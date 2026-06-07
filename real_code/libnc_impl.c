#include "libnc.h"

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <malloc.h>
#include <xmmintrin.h>
#endif

const char *nc_type_name_table[NC_TYPE_COUNT] = {
    "f32",
    "bf16",
    "f16",
    "i8",
    "i16",
    "i32",
};

size_t nc_type_size_table[NC_TYPE_COUNT] = {
    4, 2, 2, 1, 2, 4,
};

static const uint8_t nc_type_shift_table[NC_TYPE_COUNT] = { 2, 1, 1, 0, 1, 2 };

static void *aligned_malloc(size_t size, size_t align);
static void aligned_free(void *ptr);

static char *nc_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *p = nc_malloc(len);
    memcpy(p, s, len);
    return p;
}

void *nc_malloc(size_t size)
{
    return aligned_malloc(size, 0x40);
}

void *nc_mallocz(size_t size)
{
    void *p = aligned_malloc(size, 0x40);
    if (p)
        memset(p, 0, size);
    return p;
}

void nc_free(void *ptr)
{
    aligned_free(ptr);
}

static void *aligned_malloc(size_t size, size_t align)
{
    if (align < sizeof(void *))
        align = sizeof(void *);
#ifdef _WIN32
    return _aligned_malloc(size, align);
#else
    void *base = malloc(size + align - 1 + sizeof(void *));
    if (!base)
        return NULL;
    uintptr_t raw = (uintptr_t)base + sizeof(void *);
    uintptr_t aligned = (raw + align - 1) & ~(uintptr_t)(align - 1);
    ((void **)aligned)[-1] = base;
    return (void *)aligned;
#endif
}

static void aligned_free(void *ptr)
{
    if (!ptr)
        return;
#ifdef _WIN32
    _aligned_free(ptr);
#else
    free(((void **)ptr)[-1]);
#endif
}

void nc_error(char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    fputs("ERROR: ", stderr);
    vfprintf(stderr, format, ap);
    fputc('\n', stderr);
    va_end(ap);
    abort();
}

void nc_prof_dump(void)
{
}

void nc_fpu_init(void)
{
#ifdef _MSC_VER
    _mm_setcsr(0x9FC0u);
#elif defined(__SSE__)
    _mm_setcsr(0x9FC0u);
#endif
}

typedef enum {
    NC_OP_NONE = 0,
    NC_OP_PARAM,
    NC_OP_STOP_GRAD,
    NC_OP_ADD,
    NC_OP_SUB,
    NC_OP_MUL,
    NC_OP_DIV,
    NC_OP_NEG,
    NC_OP_RECIP,
    NC_OP_MIN,
    NC_OP_MAX,
    NC_OP_SELECT,
    NC_OP_MASKED_FILL,
    NC_OP_SIGMOID,
    NC_OP_TANH,
    NC_OP_RELU,
    NC_OP_GELU,
    NC_OP_LOG,
    NC_OP_LSTM_CLAMPED,
    NC_OP_LERP,
    NC_OP_CONVERT,
    NC_OP_RESHAPE,
    NC_OP_REPEAT,
    NC_OP_REDUCE_SUM,
    NC_OP_REDUCE_SUM_SQR,
    NC_OP_SLICE,
    NC_OP_SLICE_ADD,
    NC_OP_CONCAT,
    NC_OP_PERMUTE,
    NC_OP_MATMUL,
    NC_OP_MATMUL_ADD,
    NC_OP_GET_COL,
    NC_OP_ADD_COL,
    NC_OP_GET_ELEMENT,
    NC_OP_ADD_ELEMENT,
    NC_OP_SOFTMAX,
    NC_OP_INDEXED_LOG,
    NC_OP_LAYER_NORM,
    NC_OP_RMS_NORM,
    NC_OP_SLT_MAT_SET,
    NC_OP_REL_SHIFT,
    NC_OP_PAD,
    NC_OP_TENSOR_COPY,
} NCOp;

struct NCContext;
struct NCDevice;
struct NCTensorBuffer;
struct NCNode;

typedef struct NCTensor {
    struct list_head link;
    int ref_count;
    struct NCContext *context;
    struct NCDevice *device;
    struct NCTensorBuffer *buffer;
    struct NCNode *node;
    NCTypeEnum item_type;
    size_t item_size;
    int n_dims;
    size_t dims[NC_N_DIMS_MAX];
    size_t strides[NC_N_DIMS_MAX]; /* in bytes */
    size_t n_elems;
    size_t byte_offset;
    BOOL is_contiguous;
    char *name;
} NCTensor;

typedef struct NCTensorBuffer {
    struct list_head link;
    int ref_count;
    struct NCDevice *device;
    void *data;
    size_t size;
} NCTensorBuffer;

typedef struct NCDevice {
    struct list_head link;
    struct NCContext *context;
    char *name;
    BOOL is_host;
} NCDevice;

typedef struct NCContext {
    struct list_head devices;
    struct list_head buffers;
    struct list_head tensors;
    struct list_head nodes;
    int nb_threads;
    size_t heap_size;
    NCDevice *cpu_device;
} NCContext;

typedef struct NCNode {
    struct list_head link;
    int ref_count;
    struct NCContext *context;
    NCOp op;
    const struct NCNode *parent;
    int parent_arg_index;
    int n_args;
    NCTensor **args;
    void *opaque;
    int axis;
    ssize_t start;
    ssize_t end;
    ssize_t value;
    float fvalue;
    BOOL bvalue;
} NCNode;

typedef struct NCRNDState {
    struct list_head link;
    NCDevice *device;
    uint32_t state;
} NCRNDState;

typedef struct SGDOptVarState {
    struct list_head link;
    NCParam *param;
    NCSGDOptState *owner;
    float m;
    float v;
} SGDOptVarState;

typedef struct NCSGDOptState {
    struct list_head link;
    NCContext *context;
    SGDOptParams params;
    struct list_head vars;
} NCSGDOptState;

 #include "libnc_device_helpers.c"
static void context_track_node(NCContext *ctx, NCNode *n);
void nc_node_set_parent(NCNode *n, int arg_index, const NCNode *n1);

#include "libnc_graph_helpers.c"

static inline size_t item_shift(NCTypeEnum type)
{
    return nc_type_shift_table[type];
}

static inline size_t tensor_numel(const NCTensor *t)
{
    return t->n_elems ? t->n_elems : 1;
}

static inline size_t tensor_elem_offset(const NCTensor *t, const size_t idx[NC_N_DIMS_MAX])
{
    size_t off = t->byte_offset;
    for (int i = 0; i < t->n_dims; i++)
        off += idx[i] * t->strides[i];
    return off;
}

static inline void *tensor_data_ptr(const NCTensor *t)
{
    return (uint8_t *)t->buffer->data + t->byte_offset;
}

static inline const void *tensor_const_data_ptr(const NCTensor *t)
{
    return (const uint8_t *)t->buffer->data + t->byte_offset;
}

static inline size_t tensor_contig_stride(const NCTensor *t, int axis)
{
    return t->strides[axis] >> item_shift(t->item_type);
}

static void tensor_compute_layout(NCTensor *t)
{
    size_t item_size = t->item_size;
    size_t stride = item_size;
    t->n_elems = 1;
    for (int i = t->n_dims - 1; i >= 0; i--) {
        t->strides[i] = stride;
        stride *= t->dims[i];
        t->n_elems *= t->dims[i];
        if (i == 0)
            break;
    }
    t->is_contiguous = TRUE;
}

static float nc_load_f32(const void *ptr, NCTypeEnum type)
{
    switch (type) {
    case NC_TYPE_F32:
        return *(const float *)ptr;
    case NC_TYPE_BF16: {
        uint32_t v = (uint32_t)(*(const uint16_t *)ptr) << 16;
        float f;
        memcpy(&f, &v, sizeof(f));
        return f;
    }
    case NC_TYPE_F16: {
        uint16_t h = *(const uint16_t *)ptr;
        uint32_t s = (h >> 15) & 1;
        uint32_t e = (h >> 10) & 0x1f;
        uint32_t m = h & 0x3ff;
        uint32_t f;
        if (e == 0) {
            if (m == 0) {
                f = s << 31;
            } else {
                e = 1;
                while ((m & 0x400) == 0) {
                    m <<= 1;
                    e--;
                }
                m &= 0x3ff;
                f = (s << 31) | ((e + 127 - 15) << 23) | (m << 13);
            }
        } else if (e == 31) {
            f = (s << 31) | 0x7f800000u | (m << 13);
        } else {
            f = (s << 31) | ((e + 127 - 15) << 23) | (m << 13);
        }
        float out;
        memcpy(&out, &f, sizeof(out));
        return out;
    }
    case NC_TYPE_I8:
        return (float)*(const int8_t *)ptr;
    case NC_TYPE_I16:
        return (float)*(const int16_t *)ptr;
    case NC_TYPE_I32:
        return (float)*(const int32_t *)ptr;
    default:
        return 0.0f;
    }
}

static void nc_store_f32(void *ptr, NCTypeEnum type, float value)
{
    switch (type) {
    case NC_TYPE_F32:
        *(float *)ptr = value;
        break;
    case NC_TYPE_BF16: {
        uint32_t u;
        memcpy(&u, &value, sizeof(u));
        *(uint16_t *)ptr = (uint16_t)(u >> 16);
        break;
    }
    case NC_TYPE_F16: {
        uint32_t x;
        memcpy(&x, &value, sizeof(x));
        uint32_t sign = (x >> 16) & 0x8000u;
        int32_t exp = (int32_t)((x >> 23) & 0xff) - 127 + 15;
        uint32_t mant = x & 0x7fffffu;
        uint16_t out;
        if (exp <= 0) {
            if (exp < -10) {
                out = (uint16_t)sign;
            } else {
                mant = (mant | 0x800000u) >> (1 - exp);
                out = (uint16_t)(sign | (mant + 0x1000u) >> 13);
            }
        } else if (exp >= 31) {
            out = (uint16_t)(sign | 0x7c00u);
            if (mant)
                out |= (mant >> 13) ? (mant >> 13) : 1;
        } else {
            out = (uint16_t)(sign | (exp << 10) | ((mant + 0x1000u) >> 13));
        }
        *(uint16_t *)ptr = out;
        break;
    }
    case NC_TYPE_I8:
        *(int8_t *)ptr = (int8_t)lrintf(value);
        break;
    case NC_TYPE_I16:
        *(int16_t *)ptr = (int16_t)lrintf(value);
        break;
    case NC_TYPE_I32:
        *(int32_t *)ptr = (int32_t)lrintf(value);
        break;
    default:
        break;
    }
}

static float nc_load_elem(const NCTensor *t, const uint8_t *base, size_t offset)
{
    return nc_load_f32(base + offset, t->item_type);
}

static void nc_store_elem(NCTensor *t, uint8_t *base, size_t offset, float value)
{
    nc_store_f32(base + offset, t->item_type, value);
}

static void tensor_copy_recursive(NCTensor *dst, const NCTensor *src,
                                  int dim, size_t doff, size_t soff)
{
    if (dim == src->n_dims) {
        memcpy((uint8_t *)tensor_data_ptr(dst) + doff,
               (const uint8_t *)tensor_const_data_ptr(src) + soff,
               src->item_size);
        return;
    }
    for (size_t i = 0; i < src->dims[dim]; i++) {
        tensor_copy_recursive(dst, src, dim + 1,
                              doff + i * dst->strides[dim],
                              soff + i * src->strides[dim]);
    }
}

static void tensor_map_unary_recursive(NCTensor *dst, const NCTensor *src,
                                       int dim, size_t doff, size_t soff,
                                       float (*fn)(float, void *), void *opaque)
{
    if (dim == src->n_dims) {
        float x = nc_load_elem(src, tensor_const_data_ptr(src), soff);
        nc_store_elem(dst, tensor_data_ptr(dst), doff, fn(x, opaque));
        return;
    }
    for (size_t i = 0; i < src->dims[dim]; i++) {
        tensor_map_unary_recursive(dst, src, dim + 1,
                                   doff + i * dst->strides[dim],
                                   soff + i * src->strides[dim],
                                   fn, opaque);
    }
}

static void tensor_map_binary_recursive(NCTensor *dst, const NCTensor *a, const NCTensor *b,
                                        int dim, size_t doff, size_t aoff, size_t boff,
                                        float (*fn)(float, float, void *), void *opaque)
{
    if (dim == dst->n_dims) {
        float x = nc_load_elem(a, tensor_const_data_ptr(a), aoff);
        float y = nc_load_elem(b, tensor_const_data_ptr(b), boff);
        nc_store_elem(dst, tensor_data_ptr(dst), doff, fn(x, y, opaque));
        return;
    }
    for (size_t i = 0; i < dst->dims[dim]; i++) {
        tensor_map_binary_recursive(dst, a, b, dim + 1,
                                    doff + i * dst->strides[dim],
                                    aoff + i * a->strides[dim],
                                    boff + i * b->strides[dim],
                                    fn, opaque);
    }
}

static void tensor_fill_recursive(NCTensor *dst, int dim, size_t doff, float value)
{
    if (dim == dst->n_dims) {
        nc_store_elem(dst, tensor_data_ptr(dst), doff, value);
        return;
    }
    for (size_t i = 0; i < dst->dims[dim]; i++)
        tensor_fill_recursive(dst, dim + 1, doff + i * dst->strides[dim], value);
}

static size_t tensor_offset_from_indexes(const NCTensor *x, int n_dims, const size_t *idx)
{
    size_t off = 0;
    for (int i = 0; i < n_dims; i++)
        off += idx[i] * x->strides[i];
    return off;
}

static void tensor_fill_zero(NCTensor *t)
{
    memset(tensor_data_ptr(t), 0, t->n_elems * t->item_size);
}

static void tensor_make_contiguous_stride(NCTensor *t)
{
    tensor_compute_layout(t);
}

static void context_track_tensor(NCContext *ctx, NCTensor *t)
{
    list_add_tail(&t->link, &ctx->tensors);
    ctx->heap_size += sizeof(*t);
}

static void context_untrack_tensor(NCTensor *t)
{
    if (t->context)
        t->context->heap_size -= sizeof(*t);
    list_del(&t->link);
}

static void context_track_buffer(NCContext *ctx, NCTensorBuffer *b)
{
    list_add_tail(&b->link, &ctx->buffers);
    ctx->heap_size += sizeof(*b) + b->size;
}

static void context_untrack_buffer(NCTensorBuffer *b)
{
    if (b->device && b->device->context)
        b->device->context->heap_size -= sizeof(*b) + b->size;
    list_del(&b->link);
}

static void context_track_device(NCContext *ctx, NCDevice *d)
{
    list_add_tail(&d->link, &ctx->devices);
    ctx->heap_size += sizeof(*d);
}

static void context_untrack_device(NCDevice *d)
{
    if (d->context)
        d->context->heap_size -= sizeof(*d);
    list_del(&d->link);
}

static void context_track_node(NCContext *ctx, NCNode *n)
{
    list_add_tail(&n->link, &ctx->nodes);
    n->context = ctx;
    ctx->heap_size += sizeof(*n);
}

static void context_untrack_node(NCNode *n)
{
    if (n->context)
        n->context->heap_size -= sizeof(*n);
    list_del(&n->link);
}

static NCTensor *tensor_alloc_base(NCDevice *d, NCTypeEnum type, int n_dims, const size_t *dims)
{
    NCContext *ctx = d->context;
    NCTensor *t = nc_mallocz(sizeof(*t));
    t->ref_count = 1;
    t->context = ctx;
    t->device = d;
    t->item_type = type;
    t->item_size = nc_type_size_table[type];
    t->n_dims = n_dims;
    for (int i = 0; i < n_dims; i++)
        t->dims[i] = dims[i];
    tensor_make_contiguous_stride(t);
    context_track_tensor(ctx, t);
    return t;
}

static NCTensorBuffer *buffer_alloc_base(NCDevice *d, size_t size)
{
    NCContext *ctx = d->context;
    NCTensorBuffer *b = nc_mallocz(sizeof(*b));
    b->ref_count = 1;
    b->device = d;
    b->size = size;
    b->data = nc_mallocz(size ? size : 1);
    context_track_buffer(ctx, b);
    return b;
}

static void tensor_assign_buffer(NCTensor *t, NCTensorBuffer *b, size_t offset)
{
    t->buffer = b;
    t->byte_offset = offset;
}

static void tensor_add_node(NCTensor *t, NCOp op, int n_args, NCTensor **args)
{
    NCNode *n = nc_mallocz(sizeof(*n));
    n->ref_count = 1;
    n->op = op;
    n->n_args = n_args;
    if (n_args > 0) {
        n->args = nc_mallocz(sizeof(NCTensor *) * n_args);
        for (int i = 0; i < n_args; i++) {
            n->args[i] = args[i];
            if (args[i])
                args[i]->ref_count++;
        }
    }
    context_track_node(t->context, n);
    t->node = n;
}

static void node_free(NCNode *n)
{
    if (!n)
        return;
    for (int i = 0; i < n->n_args; i++)
        if (n->args && n->args[i])
            nc_free_tensor(n->args[i]);
    nc_free(n->args);
    if (n->op == NC_OP_PERMUTE && n->opaque)
        nc_free(n->opaque);
    context_untrack_node(n);
    nc_free(n);
}

static NCTensor *tensor_new_copy_like(const NCTensor *x, BOOL zero)
{
    NCTensor *y = tensor_alloc_base(x->device, x->item_type, x->n_dims, x->dims);
    tensor_assign_buffer(y, buffer_alloc_base(x->device, x->n_elems * x->item_size), 0);
    if (!zero)
        memcpy(tensor_data_ptr(y), tensor_const_data_ptr(x), x->n_elems * x->item_size);
    return y;
}

static NCTensor *tensor_new_alias_like(const NCTensor *x)
{
    NCTensor *y = nc_mallocz(sizeof(*y));
    *y = *x;
    y->ref_count = 1;
    y->name = x->name ? nc_strdup(x->name) : NULL;
    y->buffer = x->buffer;
    y->buffer->ref_count++;
    y->node = NULL;
    y->link.next = y->link.prev = NULL;
    context_track_tensor(x->context, y);
    return y;
}

static void tensor_free_payload(NCTensor *t)
{
    if (t->node) {
        node_free(t->node);
        t->node = NULL;
    }
    if (t->buffer) {
        if (--t->buffer->ref_count == 0) {
            context_untrack_buffer(t->buffer);
            nc_free(t->buffer->data);
            nc_free(t->buffer);
        }
        t->buffer = NULL;
    }
    if (t->name) {
        nc_free(t->name);
        t->name = NULL;
    }
    context_untrack_tensor(t);
    nc_free(t);
}

NCContext *nc_context_init(int nb_threads)
{
    NCContext *ctx = nc_mallocz(sizeof(*ctx));
    init_list_head(&ctx->devices);
    init_list_head(&ctx->buffers);
    init_list_head(&ctx->tensors);
    init_list_head(&ctx->nodes);
    ctx->nb_threads = nb_threads;
    ctx->cpu_device = nc_mallocz(sizeof(*ctx->cpu_device));
    ctx->cpu_device->context = ctx;
    ctx->cpu_device->name = nc_strdup("cpu");
    ctx->cpu_device->is_host = TRUE;
    context_track_device(ctx, ctx->cpu_device);
    nc_fpu_init();
    return ctx;
}

void nc_context_end(NCContext *ctx)
{
    if (!ctx)
        return;
    while (!list_empty(&ctx->tensors)) {
        struct list_head *el = ctx->tensors.next;
        NCTensor *t = list_entry(el, NCTensor, link);
        t->ref_count = 1;
        nc_free_tensor(t);
    }
    while (!list_empty(&ctx->buffers)) {
        struct list_head *el = ctx->buffers.next;
        NCTensorBuffer *b = list_entry(el, NCTensorBuffer, link);
        b->ref_count = 1;
        nc_free_tensor_buffer(b);
    }
    while (!list_empty(&ctx->nodes)) {
        struct list_head *el = ctx->nodes.next;
        NCNode *n = list_entry(el, NCNode, link);
        node_free(n);
    }
    while (!list_empty(&ctx->devices)) {
        struct list_head *el = ctx->devices.next;
        NCDevice *d = list_entry(el, NCDevice, link);
        context_untrack_device(d);
        nc_free(d->name);
        nc_free(d);
    }
    nc_free(ctx);
}

NCDevice *nc_new_cpu_device(NCContext *ctx)
{
    return ctx ? ctx->cpu_device : NULL;
}

NCDevice *nc_new_cuda_device(NCContext *ctx, int device_index)
{
    if (!ctx)
        return NULL;
    return nc_device_alloc_cuda_compat(ctx, device_index);
}

NCDevice *nc_new_device(NCContext *ctx, const char *device_name)
{
    if (!ctx || !device_name)
        return NULL;
    if (!strcmp(device_name, "cpu"))
        return nc_new_cpu_device(ctx);
    if (!strncmp(device_name, "cuda", 4)) {
        int device_index = 0;
        const char *p = device_name + 4;
        if (*p == ':')
            device_index = atoi(p + 1);
        return nc_new_cuda_device(ctx, device_index);
    }
    return NULL;
}

void nc_synchronize(NCDevice *d)
{
    (void)d;
}

NCTensorBuffer *nc_new_tensor_buffer(NCDevice *d, size_t size)
{
    return buffer_alloc_base(d, size);
}

NCTensorBuffer *nc_dup_tensor_buffer(const NCTensorBuffer *b)
{
    ((NCTensorBuffer *)b)->ref_count++;
    return (NCTensorBuffer *)b;
}

void nc_free_tensor_buffer(NCTensorBuffer *b)
{
    if (!b)
        return;
    if (--b->ref_count > 0)
        return;
    context_untrack_buffer(b);
    nc_free(b->data);
    nc_free(b);
}

NCTensor *nc_new_tensor_nz(NCDevice *d, NCTypeEnum type, int n_dims, const size_t *dims)
{
    if (type < 0 || type >= NC_TYPE_COUNT)
        nc_error("type >= 0 && type < NC_TYPE_COUNT");
    if (n_dims < 0 || n_dims > NC_N_DIMS_MAX)
        nc_error("n_dims <= N_DIMS_MAX");
    NCTensor *t = tensor_alloc_base(d, type, n_dims, dims);
    size_t bytes = t->n_elems * t->item_size;
    tensor_assign_buffer(t, buffer_alloc_base(d, bytes), 0);
    return t;
}

NCTensor *nc_new_tensor(NCDevice *d, NCTypeEnum type, int n_dims, const size_t *dims)
{
    NCTensor *t = nc_new_tensor_nz(d, type, n_dims, dims);
    tensor_fill_zero(t);
    return t;
}

NCTensor *nc_new_tensor_from_buffer(NCDevice *d, NCTensorBuffer *b, NCTypeEnum type,
                                    int n_dims, const size_t *dims, size_t byte_offset,
                                    const size_t *strides)
{
    NCTensor *t = nc_mallocz(sizeof(*t));
    t->ref_count = 1;
    t->context = d->context;
    t->device = d;
    t->buffer = nc_dup_tensor_buffer(b);
    t->item_type = type;
    t->item_size = nc_type_size_table[type];
    t->n_dims = n_dims;
    t->byte_offset = byte_offset;
    for (int i = 0; i < n_dims; i++) {
        t->dims[i] = dims[i];
        t->strides[i] = strides[i];
    }
    size_t n = 1;
    for (int i = 0; i < n_dims; i++)
        n *= dims[i];
    t->n_elems = n;
    t->is_contiguous = FALSE;
    context_track_tensor(t->context, t);
    return t;
}

NCTensor *nc_new_tensor_from_tensor(const NCTensor *x)
{
    return tensor_new_copy_like(x, FALSE);
}

NCTensor *nc_new_tensor_from_tensor_nz(const NCTensor *x)
{
    return tensor_new_copy_like(x, TRUE);
}

NCTensor *nc_new_scalar(NCDevice *d, NCTypeEnum type)
{
    size_t one = 1;
    return nc_new_tensor(d, type, 0, &one);
}

NCTensor *nc_new_tensor_1d(NCDevice *d, NCTypeEnum type, size_t len)
{
    return nc_new_tensor(d, type, 1, &len);
}

NCTensor *nc_new_tensor_2d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1)
{
    size_t dims[2] = { n0, n1 };
    return nc_new_tensor(d, type, 2, dims);
}

NCTensor *nc_new_tensor_3d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1, size_t n2)
{
    size_t dims[3] = { n0, n1, n2 };
    return nc_new_tensor(d, type, 3, dims);
}

NCTensor *nc_new_tensor_4d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1, size_t n2, size_t n3)
{
    size_t dims[4] = { n0, n1, n2, n3 };
    return nc_new_tensor(d, type, 4, dims);
}

static NCTensor *nc_tensor_set_name_str_impl(NCTensor *x, const char *s)
{
    if (x->name)
        nc_free(x->name);
    x->name = nc_strdup(s);
    return x;
}

NCTensor *nc_tensor_set_name_str(NCTensor *x, const char *s)
{
    return nc_tensor_set_name_str_impl(x, s);
}

NCTensor *__attribute__((format(printf, 2, 3))) nc_tensor_set_name(NCTensor *x, const char *fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    return nc_tensor_set_name_str_impl(x, buf);
}

NCTensor *nc_dup_tensor(const NCTensor *x)
{
    ((NCTensor *)x)->ref_count++;
    return (NCTensor *)x;
}

void nc_free_tensor(NCTensor *x)
{
    if (!x)
        return;
    if (--x->ref_count > 0)
        return;
    tensor_free_payload(x);
}

void nc_dump_dims(const char *str, NCTensor *x)
{
    printf("%s %s", nc_type_name_table[x->item_type], str);
    if (x->n_dims > 0) {
        putchar('[');
        for (int i = 0; i < x->n_dims; i++) {
            if (i)
                printf(", ");
            printf("%zu", x->dims[i]);
        }
        putchar(']');
    }
}

void nc_dump_tensor(const char *name, NCTensor *x, size_t n)
{
    printf("%s %s", nc_type_name_table[x->item_type], name);
    if (x->n_dims > 0) {
        putchar('[');
        for (int i = 0; i < x->n_dims; i++) {
            if (i)
                printf(", ");
            printf("%zu", x->dims[i]);
        }
        putchar(']');
    }
    if (n == 0) {
        putchar('\n');
        return;
    }
    printf(" =");
    size_t total = tensor_numel(x);
    size_t limit = n < total ? n : total;
    const uint8_t *base = tensor_const_data_ptr(x);
    for (size_t i = 0; i < limit; i++) {
        if (i % 8 == 0)
            printf("\n  ");
        printf("%8.3g", (double)nc_load_f32(base + i * x->item_size, x->item_type));
        if (i + 1 < limit)
            putchar(' ');
    }
    putchar('\n');
}

uint32_t nc_tensor_get_hash(NCTensor *x)
{
    if (!x->is_contiguous) {
        NCTensor *tmp = nc_new_tensor_from_tensor(x);
        uint32_t h = nc_tensor_get_hash(tmp);
        nc_free_tensor(tmp);
        return h;
    }
    uint32_t h = 2166136261u;
    const uint8_t *base = tensor_const_data_ptr(x);
    size_t nbytes = tensor_numel(x) * x->item_size;
    for (size_t i = 0; i < nbytes; i++) {
        h ^= base[i];
        h *= 16777619u;
    }
    return h;
}

void nc_dump_tensor_hash(const char *name, const NCTensor *x)
{
    printf("%s: 0x%08x\n", name, nc_tensor_get_hash((NCTensor *)x));
}

NCNode *nc_get_node(NCTensor *x)
{
    return x->node;
}

static NCTensor *tensor_from_slice_alias(const NCTensor *x, int axis, size_t start, size_t end)
{
    if (axis < 0 || axis >= x->n_dims)
        nc_error("axis >= 0 && axis < x->n_dims");
    if (start >= end)
        nc_error("start < end");
    if (end > x->dims[axis])
        nc_error("start >= 0 && end <= x->dims[axis]");
    NCTensor *y = tensor_new_alias_like(x);
    y->dims[axis] = end - start;
    y->byte_offset += start * x->strides[axis];
    y->n_elems = x->n_elems / x->dims[axis] * y->dims[axis];
    y->is_contiguous = FALSE;
    return y;
}

NCTensor *nc_slice_alias(const NCTensor *x1, int axis, size_t start, size_t end)
{
    return tensor_from_slice_alias(x1, axis, start, end);
}

NCTypeEnum nc_tensor_get_item_type(const NCTensor *x)
{
    return x->item_type;
}

NCTensorData *nc_tensor_get_data(NCTensorData *sd, const NCTensor *x)
{
    sd->item_type = x->item_type;
    sd->item_size = x->item_size;
    sd->data = (void *)tensor_const_data_ptr(x);
    sd->stride = x->n_elems;
    sd->n_dims = x->n_dims;
    sd->dims = x->dims;
    sd->strides = x->strides;
    return sd;
}

void *nc_tensor_get_ptr(NCTensor *x, size_t *pstride)
{
    if (pstride)
        *pstride = (x->n_dims > 0) ? (x->strides[0] >> item_shift(x->item_type)) : 1;
    return tensor_data_ptr(x);
}

const size_t *nc_tensor_get_dims(const NCTensor *x, int *pn_dims)
{
    if (pn_dims)
        *pn_dims = x->n_dims;
    return x->dims;
}

void nc_tensor_set_zero(NCTensor *y)
{
    tensor_fill_zero(y);
}

static void tensor_set_constant(NCTensor *y, float v)
{
    tensor_fill_recursive(y, 0, 0, v);
}

void nc_tensor_set_f32(NCTensor *y, float val)
{
    tensor_set_constant(y, val);
}

static uint32_t rnd_u32(NCRNDState *s)
{
    uint32_t x = s->state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    s->state = x;
    return x;
}

NCRNDState *nc_rnd_init(NCDevice *d, uint32_t seed)
{
    NCRNDState *s = nc_mallocz(sizeof(*s));
    s->device = d;
    s->state = seed ? seed : 1;
    init_list_head(&s->link);
    return s;
}

void nc_rnd_end(NCRNDState *s)
{
    if (!s)
        return;
    nc_free(s);
}

static float rnd_float(NCRNDState *s)
{
    return (rnd_u32(s) >> 8) * (1.0f / 16777216.0f);
}

void nc_tensor_set_rnd_unif(NCTensor *y, float avg, float range, NCRNDState *rnd_state)
{
    size_t total = tensor_numel(y);
    uint8_t *base = tensor_data_ptr(y);
    for (size_t i = 0; i < total; i++) {
        float v = avg + (rnd_float(rnd_state) * 2.0f - 1.0f) * range;
        nc_store_f32(base + i * y->item_size, y->item_type, v);
    }
}

void nc_tensor_set_dropout(NCTensor *y, float prob, NCRNDState *rnd_state)
{
    size_t total = tensor_numel(y);
    uint8_t *base = tensor_data_ptr(y);
    float scale = prob < 1.0f ? 1.0f / (1.0f - prob) : 0.0f;
    for (size_t i = 0; i < total; i++) {
        float v = nc_load_f32(base + i * y->item_size, y->item_type);
        if (rnd_float(rnd_state) < prob)
            v = 0.0f;
        else
            v *= scale;
        nc_store_f32(base + i * y->item_size, y->item_type, v);
    }
}

static void tensor_set_indexed(NCTensor *y, int n_dims, const size_t *idx, float value)
{
    size_t off = tensor_offset_from_indexes(y, n_dims, idx);
    nc_store_f32((uint8_t *)tensor_data_ptr(y) + off, y->item_type, value);
}

void nc_set1_i32(NCTensor *y, int n_dims, const size_t *tab_indexes, int32_t val)
{
    tensor_set_indexed(y, n_dims, tab_indexes, (float)val);
}

void nc_set1_i32_1d(NCTensor *y, size_t i0, int32_t val)
{
    size_t idx[1] = { i0 };
    nc_set1_i32(y, 1, idx, val);
}

void nc_set1_i32_2d(NCTensor *y, size_t i0, size_t i1, int32_t val)
{
    size_t idx[2] = { i0, i1 };
    nc_set1_i32(y, 2, idx, val);
}

void nc_set1_f32(NCTensor *y, int n_dims, const size_t *tab_indexes, float val)
{
    tensor_set_indexed(y, n_dims, tab_indexes, val);
}

void nc_set1_f32_1d(NCTensor *y, size_t i0, float val)
{
    size_t idx[1] = { i0 };
    nc_set1_f32(y, 1, idx, val);
}

int32_t nc_get1_i32(const NCTensor *x, int n_dims, const size_t *tab_indexes)
{
    size_t off = tensor_offset_from_indexes(x, n_dims, tab_indexes);
    return (int32_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + off, x->item_type));
}

float nc_get1_f32(const NCTensor *x, int n_dims, const size_t *tab_indexes)
{
    size_t off = tensor_offset_from_indexes(x, n_dims, tab_indexes);
    return nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + off, x->item_type);
}

float nc_get1_f32_1d(const NCTensor *x, size_t i0)
{
    size_t idx[1] = { i0 };
    return nc_get1_f32(x, 1, idx);
}

float nc_get_scalar_f32(const NCTensor *x)
{
    if (x->n_dims != 0)
        nc_error("x->n_dims == n_dims");
    return nc_load_f32(tensor_const_data_ptr(x), x->item_type);
}

void nc_tensor_copy(NCTensor *dst, NCTensor *src)
{
    if (dst->n_dims != src->n_dims)
        nc_error("same_dims(dst, src)");
    for (int i = 0; i < dst->n_dims; i++)
        if (dst->dims[i] != src->dims[i])
            nc_error("same_dims(dst, src)");
    size_t total = tensor_numel(src);
    if (dst->is_contiguous && src->is_contiguous && dst->item_size == src->item_size) {
        memcpy(tensor_data_ptr(dst), tensor_const_data_ptr(src), total * src->item_size);
        return;
    }
    tensor_copy_recursive(dst, src, 0, 0, 0);
}

void nc_tensor_convert(NCTensor *dst, NCTensor *src)
{
    if (dst->n_dims != src->n_dims)
        nc_error("same_dims(dst, src)");
    for (int i = 0; i < dst->n_dims; i++)
        if (dst->dims[i] != src->dims[i])
            nc_error("same_dims(dst, src)");
    size_t total = tensor_numel(src);
    uint8_t *d = tensor_data_ptr(dst);
    const uint8_t *s = tensor_const_data_ptr(src);
    for (size_t i = 0; i < total; i++) {
        float v = nc_load_f32(s + i * src->item_size, src->item_type);
        nc_store_f32(d + i * dst->item_size, dst->item_type, v);
    }
}

size_t nc_get_heap_size(NCContext *ctx)
{
    return ctx ? ctx->heap_size : 0;
}

NCContext *nc_get_tensor_context(const NCTensor *x)
{
    return x->context;
}

NCDevice *nc_get_tensor_device(const NCTensor *x)
{
    return x->device;
}

NCTensor *nc_tensor_to_device(NCTensor *x, NCDevice *d)
{
    if (x->device == d)
        return x;
    NCTensor *y = nc_new_tensor_nz(d, x->item_type, x->n_dims, x->dims);
    nc_tensor_copy(y, x);
    if (x->node)
        tensor_add_node(y, x->node->op, x->node->n_args, x->node->args);
    nc_free_tensor(x);
    return y;
}

NCTensor *nc_tensor_to_cpu_device(NCTensor *x)
{
    return nc_tensor_to_device(x, x->context->cpu_device);
}

NCTensor *nc_convert(NCTensor *x, NCTypeEnum new_type)
{
    if (x->item_type == new_type)
        return nc_dup_tensor(x);
    NCTensor *y = nc_new_tensor_nz(x->device, new_type, x->n_dims, x->dims);
    nc_tensor_convert(y, x);
    nc_free_tensor(x);
    return y;
}

static float fn_add(float a, float b, void *opaque) { (void)opaque; return a + b; }
static float fn_sub(float a, float b, void *opaque) { (void)opaque; return a - b; }
static float fn_mul(float a, float b, void *opaque) { (void)opaque; return a * b; }
static float fn_div(float a, float b, void *opaque) { (void)opaque; return a / b; }
static float fn_min(float a, float b, void *opaque) { (void)opaque; return a < b ? a : b; }
static float fn_max(float a, float b, void *opaque) { (void)opaque; return a > b ? a : b; }

static NCTensor *tensor_binary_same_shape(NCTensor *a, NCTensor *b, float (*fn)(float, float, void *), NCOp op)
{
    if (a->device != b->device)
        nc_error("all operation tensors must be on the same device");
    if (a->n_dims != b->n_dims)
        nc_error("same_dims(y, x1)");
    for (int i = 0; i < a->n_dims; i++)
        if (a->dims[i] != b->dims[i])
            nc_error("same_dims(y, x1)");
    if (a->item_type != b->item_type || a->item_type > NC_TYPE_BF16)
        nc_error("unsupported type for operation");
    NCTensor *y = nc_new_tensor_nz(a->device, a->item_type, a->n_dims, a->dims);
    tensor_map_binary_recursive(y, a, b, 0, 0, 0, 0, fn, NULL);
    NCTensor *args[2] = { a, b };
    tensor_add_node(y, op, 2, args);
    return y;
}

NCTensor *nc_add(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_add, NC_OP_ADD);
}

NCTensor *nc_sub(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_sub, NC_OP_SUB);
}

NCTensor *nc_mul(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_mul, NC_OP_MUL);
}

NCTensor *nc_div(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_div, NC_OP_DIV);
}

NCTensor *nc_min(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_min, NC_OP_MIN);
}

NCTensor *nc_max(NCTensor *x1, NCTensor *x2)
{
    return tensor_binary_same_shape(x1, x2, fn_max, NC_OP_MAX);
}

NCTensor *nc_neg(NCTensor *x)
{
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    size_t total = tensor_numel(x);
    for (size_t i = 0; i < total; i++) {
        float v = -nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_NEG, 1, args);
    return y;
}

NCTensor *nc_recip(NCTensor *x)
{
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    size_t total = tensor_numel(x);
    for (size_t i = 0; i < total; i++) {
        float v = 1.0f / nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_RECIP, 1, args);
    return y;
}

NCTensor *nc_select(NCTensor *z, NCTensor *x1, NCTensor *x2)
{
    if (z->n_dims != x1->n_dims || z->n_dims != x2->n_dims)
        nc_error("same_dims");
    for (int i = 0; i < z->n_dims; i++)
        if (z->dims[i] != x1->dims[i] || z->dims[i] != x2->dims[i])
            nc_error("same_dims");
    NCTensor *y = nc_new_tensor_nz(x1->device, x1->item_type, x1->n_dims, x1->dims);
    size_t total = tensor_numel(x1);
    for (size_t i = 0; i < total; i++) {
        float vz = nc_load_f32((const uint8_t *)tensor_const_data_ptr(z) + i * z->item_size, z->item_type);
        float v = vz == 0.0f
            ? nc_load_f32((const uint8_t *)tensor_const_data_ptr(x1) + i * x1->item_size, x1->item_type)
            : nc_load_f32((const uint8_t *)tensor_const_data_ptr(x2) + i * x2->item_size, x2->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[3] = { z, x1, x2 };
    tensor_add_node(y, NC_OP_SELECT, 3, args);
    return y;
}

NCTensor *nc_masked_fill(NCTensor *x, NCTensor *mask, float c, BOOL mask_inv)
{
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    size_t total = tensor_numel(x);
    for (size_t i = 0; i < total; i++) {
        float m = nc_load_f32((const uint8_t *)tensor_const_data_ptr(mask) + i * mask->item_size, mask->item_type);
        float v = nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        BOOL pred = mask_inv ? (m == 0.0f) : (m != 0.0f);
        if (pred)
            v = c;
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[2] = { x, mask };
    tensor_add_node(y, NC_OP_MASKED_FILL, 2, args);
    return y;
}

static float fn_sigmoid(float x, void *opaque) { (void)opaque; return 1.0f / (1.0f + expf(-x)); }
static float fn_tanh(float x, void *opaque) { (void)opaque; return tanhf(x); }
static float fn_relu(float x, void *opaque) { (void)opaque; return x > 0.0f ? x : 0.0f; }
static float fn_gelu(float x, void *opaque)
{
    (void)opaque;
    return 0.5f * x * (1.0f + tanhf(0.7978845608f * (x + 0.044715f * x * x * x)));
}
static float fn_log(float x, void *opaque) { (void)opaque; return logf(x); }

static NCTensor *tensor_unary_same_shape(NCTensor *x, float (*fn)(float, void *), NCOp op)
{
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    tensor_map_unary_recursive(y, x, 0, 0, 0, fn, NULL);
    NCTensor *args[1] = { x };
    tensor_add_node(y, op, 1, args);
    return y;
}

NCTensor *nc_sigmoid(NCTensor *x) { return tensor_unary_same_shape(x, fn_sigmoid, NC_OP_SIGMOID); }
NCTensor *nc_tanh(NCTensor *x) { return tensor_unary_same_shape(x, fn_tanh, NC_OP_TANH); }
NCTensor *nc_relu(NCTensor *x) { return tensor_unary_same_shape(x, fn_relu, NC_OP_RELU); }
NCTensor *nc_gelu(NCTensor *x) { return tensor_unary_same_shape(x, fn_gelu, NC_OP_GELU); }
NCTensor *nc_log(NCTensor *x) { return tensor_unary_same_shape(x, fn_log, NC_OP_LOG); }

NCTensor *nc_lstm_clamped(NCTensor *cp, NCTensor *in, NCTensor *fg, NCTensor *ig)
{
    NCTensor *y = nc_new_tensor_nz(cp->device, cp->item_type, cp->n_dims, cp->dims);
    size_t total = tensor_numel(cp);
    for (size_t i = 0; i < total; i++) {
        float cpv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(cp) + i * cp->item_size, cp->item_type);
        float inv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(in) + i * in->item_size, in->item_type);
        float fgv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(fg) + i * fg->item_size, fg->item_type);
        float igv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(ig) + i * ig->item_size, ig->item_type);
        float v = cpv * fgv + fminf(1.0f - fgv, igv) * inv;
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[4] = { cp, in, fg, ig };
    tensor_add_node(y, NC_OP_LSTM_CLAMPED, 4, args);
    return y;
}

NCTensor *nc_lerp(NCTensor *a, NCTensor *b, NCTensor *t)
{
    NCTensor *y = nc_new_tensor_nz(a->device, a->item_type, a->n_dims, a->dims);
    size_t total = tensor_numel(a);
    for (size_t i = 0; i < total; i++) {
        float av = nc_load_f32((const uint8_t *)tensor_const_data_ptr(a) + i * a->item_size, a->item_type);
        float bv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(b) + i * b->item_size, b->item_type);
        float tv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(t) + i * t->item_size, t->item_type);
        float v = av * (1.0f - tv) + bv * tv;
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[3] = { a, b, t };
    tensor_add_node(y, NC_OP_LERP, 3, args);
    return y;
}

NCTensor *nc_reshape(NCTensor *x, int n_dims, const size_t *dims)
{
    size_t total = 1;
    for (int i = 0; i < n_dims; i++)
        total *= dims[i];
    if (total != tensor_numel(x))
        nc_error("reshape element count mismatch");
    if (!x->is_contiguous)
        x = nc_make_contiguous(x);
    NCTensor *y = tensor_new_alias_like(x);
    y->n_dims = n_dims;
    for (int i = 0; i < n_dims; i++)
        y->dims[i] = dims[i];
    tensor_make_contiguous_stride(y);
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_RESHAPE, 1, args);
    return y;
}

NCTensor *nc_reshape_1d(NCTensor *x, size_t n0)
{
    return nc_reshape(x, 1, &n0);
}

NCTensor *nc_reshape_2d(NCTensor *x, size_t n0, size_t n1)
{
    size_t dims[2] = { n0, n1 };
    return nc_reshape(x, 2, dims);
}

NCTensor *nc_reshape_3d(NCTensor *x, size_t n0, size_t n1, size_t n2)
{
    size_t dims[3] = { n0, n1, n2 };
    return nc_reshape(x, 3, dims);
}

NCTensor *nc_reshape_4d(NCTensor *x, size_t n0, size_t n1, size_t n2, size_t n3)
{
    size_t dims[4] = { n0, n1, n2, n3 };
    return nc_reshape(x, 4, dims);
}

NCTensor *nc_repeat(NCTensor *x, int n_dims, const size_t *dims)
{
    if (n_dims < 1)
        nc_error("n_dims >= 1");
    int out_dims = x->n_dims + n_dims;
    if (out_dims > NC_N_DIMS_MAX)
        nc_error("n_dims1 <= N_DIMS_MAX");
    size_t odims[NC_N_DIMS_MAX] = {0};
    for (int i = 0; i < x->n_dims; i++)
        odims[i] = x->dims[i];
    for (int i = 0; i < n_dims; i++)
        odims[x->n_dims + i] = dims[i];
    NCTensor *y = nc_new_tensor(x->device, x->item_type, out_dims, odims);
    size_t x_total = tensor_numel(x);
    size_t repeat = 1;
    for (int i = 0; i < n_dims; i++)
        repeat *= dims[i];
    uint8_t *dst = tensor_data_ptr(y);
    const uint8_t *src = tensor_const_data_ptr(x);
    size_t out_total = x_total * repeat;
    for (size_t i = 0; i < out_total; i++) {
        float v = nc_load_f32(src + (i % x_total) * x->item_size, x->item_type);
        nc_store_f32(dst + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_REPEAT, 1, args);
    return y;
}

NCTensor *nc_repeat_1d(NCTensor *x, size_t n)
{
    return nc_repeat(x, 1, &n);
}

NCTensor *nc_reduce_sum(NCTensor *y0, NCTensor *x, int n_dims)
{
    if (n_dims < 0 || n_dims > x->n_dims)
        nc_error("n_dims <= x->n_dims");
    if (!y0) {
        size_t dims[NC_N_DIMS_MAX] = {0};
        for (int i = 0; i < n_dims; i++)
            dims[i] = x->dims[i];
        y0 = nc_new_tensor(x->device, x->item_type, n_dims, dims);
    }
    tensor_fill_zero(y0);
    size_t total = tensor_numel(x);
    size_t collapse = 1;
    for (int i = n_dims; i < x->n_dims; i++)
        collapse *= x->dims[i];
    if (n_dims == x->n_dims) {
        nc_tensor_copy(y0, x);
        return y0;
    }
    size_t y_total = tensor_numel(y0);
    for (size_t i = 0; i < total; i++) {
        size_t yidx = i / collapse;
        float v = nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        float cur = nc_load_f32((uint8_t *)tensor_data_ptr(y0) + yidx * y0->item_size, y0->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y0) + yidx * y0->item_size, y0->item_type, cur + v);
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y0, NC_OP_REDUCE_SUM, 1, args);
    (void)y_total;
    return y0;
}

NCTensor *nc_sum(NCTensor *x)
{
    return nc_reduce_sum(NULL, x, 0);
}

NCTensor *nc_reduce_sum_sqr(NCTensor *x)
{
    NCTensor *y = nc_new_scalar(x->device, x->item_type);
    float acc = 0.0f;
    size_t total = tensor_numel(x);
    for (size_t i = 0; i < total; i++) {
        float v = nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        acc += v * v;
    }
    nc_store_f32(tensor_data_ptr(y), y->item_type, acc);
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_REDUCE_SUM_SQR, 1, args);
    return y;
}

NCTensor *nc_slice(NCTensor *x, int axis, size_t start, size_t end)
{
    NCTensor *y = tensor_from_slice_alias(x, axis, start, end);
    if (!y->is_contiguous)
        y = nc_make_contiguous(y);
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_SLICE, 1, args);
    if (y->node) {
        y->node->axis = axis;
        y->node->start = (ssize_t)start;
        y->node->end = (ssize_t)end;
    }
    return y;
}

NCTensor *nc_slice_add(NCTensor *y0, NCTensor *x, int axis, size_t start)
{
    if (!y0)
        y0 = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    if (axis < 0 || axis >= y0->n_dims)
        nc_error("axis >= 0 && axis < x->n_dims");
    size_t end = start + x->dims[axis];
    if (end > y0->dims[axis])
        nc_error("start >= 0 && end <= x->dims[axis]");
    size_t total = tensor_numel(x);
    for (size_t i = 0; i < total; i++) {
        size_t idx[NC_N_DIMS_MAX] = {0};
        size_t tmp = i;
        for (int d = x->n_dims - 1; d >= 0; d--) {
            idx[d] = tmp % x->dims[d];
            tmp /= x->dims[d];
            if (d == 0)
                break;
        }
        idx[axis] += start;
        size_t doff = tensor_offset_from_indexes(y0, y0->n_dims, idx);
        float cur = nc_load_f32((uint8_t *)tensor_data_ptr(y0) + doff, y0->item_type);
        float v = nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + i * x->item_size, x->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y0) + doff, y0->item_type, cur + v);
    }
    NCTensor *args[2] = { y0, x };
    tensor_add_node(y0, NC_OP_SLICE_ADD, 2, args);
    return y0;
}

NCTensor *nc_concat(NCTensor **inputs, int n_inputs, int axis)
{
    if (n_inputs <= 0)
        nc_error("n_inputs >= 1");
    NCTensor *x0 = inputs[0];
    if (n_inputs == 1)
        return nc_dup_tensor(x0);
    if (axis < 0 || axis >= x0->n_dims)
        nc_error("axis >= 0 && axis < x0->n_dims");
    size_t out_dims[NC_N_DIMS_MAX];
    for (int i = 0; i < x0->n_dims; i++)
        out_dims[i] = x0->dims[i];
    size_t axis_sum = 0;
    for (int k = 0; k < n_inputs; k++) {
        NCTensor *x = inputs[k];
        if (x->n_dims != x0->n_dims || x->item_type != x0->item_type)
            nc_error("x->n_dims == x0->n_dims");
        for (int i = 0; i < x->n_dims; i++)
            if (i != axis && x->dims[i] != x0->dims[i])
                nc_error("x->dims[j] == x0->dims[j]");
        axis_sum += x->dims[axis];
    }
    out_dims[axis] = axis_sum;
    NCTensor *y = nc_new_tensor(x0->device, x0->item_type, x0->n_dims, out_dims);
    size_t cursor = 0;
    for (int k = 0; k < n_inputs; k++) {
        NCTensor *x = inputs[k];
        NCTensor *sl = tensor_from_slice_alias(y, axis, cursor, cursor + x->dims[axis]);
        nc_tensor_copy(sl, x);
        nc_free_tensor(sl);
        cursor += x->dims[axis];
    }
    NCTensor **args = nc_mallocz(sizeof(NCTensor *) * n_inputs);
    for (int i = 0; i < n_inputs; i++)
        args[i] = inputs[i];
    tensor_add_node(y, NC_OP_CONCAT, n_inputs, args);
    nc_free(args);
    return y;
}

NCTensor *nc_vconcat(NCTensor **inputs, int n_inputs) { return nc_concat(inputs, n_inputs, 0); }
NCTensor *nc_hconcat(NCTensor **inputs, int n_inputs) { return nc_concat(inputs, n_inputs, 1); }

void nc_split(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size, int axis)
{
    if (n_outputs <= 0 || axis < 0 || axis >= x->n_dims)
        nc_error("split args");
    size_t pos = 0;
    size_t total_axis = x->dims[axis];
    if (!tab_size) {
        if (total_axis % (size_t)n_outputs)
            nc_error("split: output sizes does not match input size");
    }
    for (int i = 0; i < n_outputs; i++) {
        size_t len = tab_size ? tab_size[i] : total_axis / (size_t)n_outputs;
        if (pos + len > total_axis)
            nc_error("split: output sizes does not match input size");
        tab_y[i] = nc_slice(x, axis, pos, pos + len);
        pos += len;
    }
    if (pos != total_axis)
        nc_error("split: output sizes does not match input size");
}

void nc_vsplit(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size)
{
    nc_split(tab_y, x, n_outputs, tab_size, 0);
}

void nc_hsplit(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size)
{
    nc_split(tab_y, x, n_outputs, tab_size, 1);
}

static NCTensor *pad_resize(NCTensor *x, ssize_t left_len, NCPadEnum left_op,
                            ssize_t right_len, NCPadEnum right_op)
{
    (void)left_op;
    (void)right_op;
    size_t new_len = x->dims[0];
    ssize_t start = 0;
    if (left_len < 0) {
        start = -left_len;
        if ((size_t)start > x->dims[0])
            start = x->dims[0];
        new_len = x->dims[0] - (size_t)start;
    } else {
        new_len = x->dims[0] + (size_t)left_len + (right_len > 0 ? (size_t)right_len : 0);
    }
    size_t dims[NC_N_DIMS_MAX];
    for (int i = 0; i < x->n_dims; i++)
        dims[i] = x->dims[i];
    dims[0] = new_len;
    NCTensor *y = nc_new_tensor(x->device, x->item_type, x->n_dims, dims);
    tensor_fill_zero(y);
    size_t copy_start = left_len > 0 ? (size_t)left_len : 0;
    size_t copy_len = x->dims[0];
    if (left_len < 0)
        copy_len -= (size_t)(-left_len);
    if (right_len < 0 && copy_len > (size_t)(-right_len))
        copy_len -= (size_t)(-right_len);
    NCTensor *sl = nc_slice_alias(y, 0, copy_start, copy_start + copy_len);
    NCTensor *sx = nc_slice_alias(x, 0, (size_t)(start > 0 ? start : 0), (size_t)(start > 0 ? start : 0) + copy_len);
    nc_tensor_copy(sl, sx);
    nc_free_tensor(sl);
    nc_free_tensor(sx);
    return y;
}

NCTensor *nc_pad(NCTensor *x, ssize_t left_len, NCPadEnum left_op, ssize_t right_len, NCPadEnum right_op)
{
    return pad_resize(x, left_len, left_op, right_len, right_op);
}

NCTensor *nc_resize(NCTensor *x, size_t n)
{
    ssize_t right = (ssize_t)n - (ssize_t)x->dims[0];
    return nc_pad(x, 0, NC_PAD_ZERO, right, NC_PAD_ZERO);
}

NCTensor *nc_make_contiguous(NCTensor *x)
{
    if (x->is_contiguous)
        return x;
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    nc_tensor_copy(y, x);
    if (x->node)
        tensor_add_node(y, x->node->op, x->node->n_args, x->node->args);
    if (x->node && x->node->op == NC_OP_PERMUTE && x->node->opaque && y->node) {
        int *axis = nc_malloc(sizeof(int) * (size_t)x->node->n_args);
        memcpy(axis, x->node->opaque, sizeof(int) * (size_t)x->node->n_args);
        y->node->opaque = axis;
    }
    nc_free_tensor(x);
    return y;
}

NCTensor *nc_permute_alias(NCTensor *x, int n_dims, const int *axis)
{
    if (n_dims != x->n_dims)
        nc_error("n_dims == x->n_dims");
    NCTensor *y = tensor_new_alias_like(x);
    for (int i = 0; i < n_dims; i++) {
        y->dims[i] = x->dims[axis[i]];
        y->strides[i] = x->strides[axis[i]];
    }
    y->is_contiguous = FALSE;
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_PERMUTE, 1, args);
    if (y->node) {
        int *saved_axis = nc_malloc(sizeof(int) * (size_t)n_dims);
        memcpy(saved_axis, axis, sizeof(int) * (size_t)n_dims);
        y->node->opaque = saved_axis;
    }
    return y;
}

NCTensor *nc_permute(NCTensor *x, int n_dims, const int *axis)
{
    NCTensor *y = nc_permute_alias(x, n_dims, axis);
    y = nc_make_contiguous(y);
    return y;
}

NCTensor *nc_transpose(NCTensor *x)
{
    if (x->n_dims != 2)
        nc_error("transpose expects 2D tensor");
    int axis[2] = { 1, 0 };
    return nc_permute(x, 2, axis);
}

static NCTensor *matmul_2d(NCTensor *w, NCTensor *x)
{
    if (w->n_dims != 2 || x->n_dims != 2)
        nc_error("matmul expects 2D tensors");
    if (w->dims[1] != x->dims[0])
        nc_error("k == x->dims[0]");
    size_t out_dims[2] = { w->dims[0], x->dims[1] };
    NCTensor *y = nc_new_tensor(w->device, w->item_type, 2, out_dims);
    for (size_t i = 0; i < out_dims[0]; i++) {
        for (size_t j = 0; j < out_dims[1]; j++) {
            float acc = 0.0f;
            for (size_t k = 0; k < w->dims[1]; k++) {
                size_t wi = i * w->strides[0] + k * w->strides[1];
                size_t xi = k * x->strides[0] + j * x->strides[1];
                float a = nc_load_f32((uint8_t *)tensor_const_data_ptr(w) + wi, w->item_type);
                float b = nc_load_f32((uint8_t *)tensor_const_data_ptr(x) + xi, x->item_type);
                acc += a * b;
            }
            size_t yi = i * y->strides[0] + j * y->strides[1];
            nc_store_f32((uint8_t *)tensor_data_ptr(y) + yi, y->item_type, acc);
        }
    }
    NCTensor *args[2] = { w, x };
    tensor_add_node(y, NC_OP_MATMUL, 2, args);
    return y;
}

NCTensor *nc_matmul(NCTensor *w, NCTensor *x)
{
    return matmul_2d(w, x);
}

NCTensor *nc_matmul_add(NCTensor *w, NCTensor *x, NCTensor *y0, BOOL w_trans, BOOL x_trans)
{
    if (w_trans || x_trans)
        nc_error("transposed matmul is not supported in this simplified build");
    NCTensor *y = nc_matmul(w, x);
    if (y0) {
        NCTensor *sum = nc_add(y, y0);
        nc_free_tensor(y);
        y = sum;
    }
    NCTensor *args[3] = { w, x, y0 };
    tensor_add_node(y, NC_OP_MATMUL_ADD, 3, args);
    return y;
}

NCTensor *nc_matmul_stride(NCTensor *w, NCTensor *x)
{
    return nc_matmul(w, x);
}

NCTensor *nc_get_col(NCTensor *w, NCTensor *x)
{
    if (w->n_dims != 2 || x->n_dims != 1)
        nc_error("get_col shapes");
    size_t out_dims[2] = { w->dims[0], x->dims[0] };
    NCTensor *y = nc_new_tensor(w->device, w->item_type, 2, out_dims);
    for (size_t c = 0; c < x->dims[0]; c++) {
        size_t col = (size_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + c * x->item_size, x->item_type));
        if (col >= w->dims[1])
            nc_error("get_col index");
        for (size_t r = 0; r < w->dims[0]; r++) {
            size_t wi = r * w->strides[0] + col * w->strides[1];
            size_t yi = r * y->strides[0] + c * y->strides[1];
            float v = nc_load_f32((uint8_t *)tensor_const_data_ptr(w) + wi, w->item_type);
            nc_store_f32((uint8_t *)tensor_data_ptr(y) + yi, y->item_type, v);
        }
    }
    NCTensor *args[2] = { w, x };
    tensor_add_node(y, NC_OP_GET_COL, 2, args);
    return y;
}

NCTensor *nc_add_col(NCTensor *z, NCTensor *x, NCTensor *w)
{
    if (w->n_dims != 2 || z->n_dims != 2 || x->n_dims != 1)
        nc_error("add_col shapes");
    NCTensor *y = nc_new_tensor_from_tensor(w);
    for (size_t c = 0; c < x->dims[0]; c++) {
        size_t col = (size_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + c * x->item_size, x->item_type));
        if (col >= y->dims[1])
            nc_error("add_col index");
        for (size_t r = 0; r < y->dims[0]; r++) {
            size_t yi = r * y->strides[0] + col * y->strides[1];
            size_t zi = r * z->strides[0] + c * z->strides[1];
            float cur = nc_load_f32((uint8_t *)tensor_const_data_ptr(y) + yi, y->item_type);
            float add = nc_load_f32((const uint8_t *)tensor_const_data_ptr(z) + zi, z->item_type);
            nc_store_f32((uint8_t *)tensor_data_ptr(y) + yi, y->item_type, cur + add);
        }
    }
    NCTensor *args[3] = { z, x, w };
    tensor_add_node(y, NC_OP_ADD_COL, 3, args);
    return y;
}

NCTensor *nc_get_element(NCTensor *w, NCTensor *x)
{
    if (w->n_dims != 2 || x->n_dims != 1)
        nc_error("get_element shapes");
    size_t out_dims[1] = { x->dims[0] };
    NCTensor *y = nc_new_tensor(w->device, w->item_type, 1, out_dims);
    for (size_t c = 0; c < x->dims[0]; c++) {
        size_t row = (size_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + c * x->item_size, x->item_type));
        if (row >= w->dims[0])
            nc_error("get_element index");
        size_t wi = row * w->strides[0] + c * w->strides[1];
        float v = nc_load_f32((uint8_t *)tensor_const_data_ptr(w) + wi, w->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + c * y->item_size, y->item_type, v);
    }
    NCTensor *args[2] = { w, x };
    tensor_add_node(y, NC_OP_GET_ELEMENT, 2, args);
    return y;
}

NCTensor *nc_add_element(NCTensor *z, NCTensor *x, NCTensor *w)
{
    if (w->n_dims != 2 || z->n_dims != 1 || x->n_dims != 1)
        nc_error("add_element shapes");
    NCTensor *y = nc_new_tensor_from_tensor(w);
    for (size_t c = 0; c < x->dims[0]; c++) {
        size_t row = (size_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + c * x->item_size, x->item_type));
        size_t wi = row * y->strides[0] + c * y->strides[1];
        float cur = nc_load_f32((uint8_t *)tensor_const_data_ptr(y) + wi, y->item_type);
        float add = nc_load_f32((const uint8_t *)tensor_const_data_ptr(z) + c * z->item_size, z->item_type);
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + wi, y->item_type, cur + add);
    }
    NCTensor *args[3] = { z, x, w };
    tensor_add_node(y, NC_OP_ADD_ELEMENT, 3, args);
    return y;
}

NCTensor *nc_soft_max(NCTensor *x)
{
    if (x->n_dims == 0)
        return nc_dup_tensor(x);
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    int axis = x->n_dims - 1;
    size_t outer = 1;
    for (int i = 0; i < axis; i++)
        outer *= x->dims[i];
    size_t inner = x->dims[axis];
    for (size_t o = 0; o < outer; o++) {
        const uint8_t *xb = tensor_const_data_ptr(x) + o * inner * x->item_size;
        uint8_t *yb = tensor_data_ptr(y) + o * inner * y->item_size;
        float maxv = -INFINITY;
        for (size_t i = 0; i < inner; i++)
            maxv = fmaxf(maxv, nc_load_f32(xb + i * x->item_size, x->item_type));
        float sum = 0.0f;
        for (size_t i = 0; i < inner; i++) {
            float e = expf(nc_load_f32(xb + i * x->item_size, x->item_type) - maxv);
            sum += e;
            nc_store_f32(yb + i * y->item_size, y->item_type, e);
        }
        for (size_t i = 0; i < inner; i++) {
            float v = nc_load_f32(yb + i * y->item_size, y->item_type) / sum;
            nc_store_f32(yb + i * y->item_size, y->item_type, v);
        }
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_SOFTMAX, 1, args);
    return y;
}

NCTensor *nc_indexed_log(NCTensor *x, NCTensor *eout)
{
    if (x->n_dims != 2 || eout->n_dims != 1)
        nc_error("indexed_log shapes");
    size_t out_dims[1] = { eout->dims[0] };
    NCTensor *y = nc_new_tensor(x->device, x->item_type, 1, out_dims);
    for (size_t i = 0; i < eout->dims[0]; i++) {
        size_t idx = (size_t)lrintf(nc_load_f32((const uint8_t *)tensor_const_data_ptr(eout) + i * eout->item_size, eout->item_type));
        if (idx >= x->dims[1])
            nc_error("indexed_log index");
        size_t off = i * x->strides[0] + idx * x->strides[1];
        float v = logf(fmaxf(1e-30f, nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + off, x->item_type)));
        nc_store_f32((uint8_t *)tensor_data_ptr(y) + i * y->item_size, y->item_type, v);
    }
    NCTensor *args[2] = { x, eout };
    tensor_add_node(y, NC_OP_INDEXED_LOG, 2, args);
    return y;
}

static NCTensor *norm_last_dim(NCTensor *x, float eps, BOOL rms)
{
    if (x->n_dims == 0)
        return nc_dup_tensor(x);
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    int axis = x->n_dims - 1;
    size_t outer = 1;
    for (int i = 0; i < axis; i++)
        outer *= x->dims[i];
    size_t inner = x->dims[axis];
    for (size_t o = 0; o < outer; o++) {
        const uint8_t *xb = tensor_const_data_ptr(x) + o * inner * x->item_size;
        uint8_t *yb = tensor_data_ptr(y) + o * inner * y->item_size;
        float mean = 0.0f;
        for (size_t i = 0; i < inner; i++) {
            float v = nc_load_f32(xb + i * x->item_size, x->item_type);
            mean += rms ? v * v : v;
        }
        mean /= (float)inner;
        float denom = sqrtf(mean + eps);
        for (size_t i = 0; i < inner; i++) {
            float v = nc_load_f32(xb + i * x->item_size, x->item_type);
            if (!rms)
                v -= mean;
            nc_store_f32(yb + i * y->item_size, y->item_type, v / denom);
        }
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, rms ? NC_OP_RMS_NORM : NC_OP_LAYER_NORM, 1, args);
    return y;
}

NCTensor *nc_layer_norm(NCTensor *x, float eps) { return norm_last_dim(x, eps, FALSE); }
NCTensor *nc_rms_norm(NCTensor *x, float eps) { return norm_last_dim(x, eps, TRUE); }

NCTensor *nc_slt_mat_set(NCTensor *x, size_t pos, float c)
{
    NCTensor *y = nc_make_contiguous(x);
    if (y->n_dims != 2)
        return y;
    for (size_t i = pos; i < y->dims[0]; i++) {
        for (size_t j = 0; j <= i && j < y->dims[1]; j++) {
            size_t off = i * y->strides[0] + j * y->strides[1];
            nc_store_f32((uint8_t *)tensor_data_ptr(y) + off, y->item_type, c);
        }
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_SLT_MAT_SET, 1, args);
    return y;
}

NCTensor *nc_rel_shift(NCTensor *x, ssize_t pos, ssize_t mult)
{
    NCTensor *y = nc_new_tensor_nz(x->device, x->item_type, x->n_dims, x->dims);
    tensor_fill_zero(y);
    if (x->n_dims == 0)
        return nc_dup_tensor(x);
    size_t outer = 1;
    for (int i = 0; i < x->n_dims - 1; i++)
        outer *= x->dims[i];
    size_t inner = x->dims[x->n_dims - 1];
    for (size_t o = 0; o < outer; o++) {
        for (size_t j = 0; j < inner; j++) {
            ssize_t src = (ssize_t)j - pos - (ssize_t)o * mult;
            if (src < 0 || src >= (ssize_t)inner)
                continue;
            size_t doff = o * inner * y->item_size + j * y->item_size;
            size_t soff = o * inner * x->item_size + (size_t)src * x->item_size;
            float v = nc_load_f32((const uint8_t *)tensor_const_data_ptr(x) + soff, x->item_type);
            nc_store_f32((uint8_t *)tensor_data_ptr(y) + doff, y->item_type, v);
        }
    }
    NCTensor *args[1] = { x };
    tensor_add_node(y, NC_OP_REL_SHIFT, 1, args);
    return y;
}

NCTensor *nc_set_param(NCTensor *x, void *opaque)
{
    tensor_add_node(x, NC_OP_PARAM, 0, NULL);
    x->node->opaque = opaque;
    return x;
}

NCTensor *nc_stop_grad(NCTensor *x)
{
    NCTensor *y = nc_new_tensor_from_tensor(x);
    if (y->node) {
        node_free(y->node);
        y->node = NULL;
    }
    return y;
}

NCNode *nc_dup_node(const NCNode *n)
{
    if (!n)
        return NULL;
    NCNode *m = nc_mallocz(sizeof(*m));
    *m = *n;
    if (n->n_args > 0 && n->args) {
        m->args = nc_mallocz(sizeof(NCTensor *) * n->n_args);
        for (int i = 0; i < n->n_args; i++) {
            m->args[i] = n->args[i];
            if (m->args[i])
                m->args[i]->ref_count++;
        }
    }
    return m;
}

void nc_free_node(NCNode *n)
{
    node_free(n);
}

void nc_node_set_parent(NCNode *n, int arg_index, const NCNode *n1)
{
    if (!n || arg_index < 0 || arg_index >= n->n_args)
        return;
    if (n->parent)
        nc_free_node((NCNode *)n->parent);
    if (n1)
        ((NCNode *)n1)->ref_count++;
    n->parent = n1;
    n->parent_arg_index = arg_index;
}

void nc_node_set_arg(NCNode *n, int arg_index, const NCTensor *x)
{
    if (!n || arg_index < 0 || arg_index >= n->n_args)
        return;
    if (!n->args)
        n->args = nc_mallocz(sizeof(NCTensor *) * n->n_args);
    if (n->args[arg_index])
        nc_free_tensor(n->args[arg_index]);
    n->args[arg_index] = (NCTensor *)x;
    if (n->args[arg_index])
        n->args[arg_index]->ref_count++;
}

static NCTensor *tensor_clone_like(const NCTensor *src)
{
    return nc_new_tensor_from_tensor(src);
}

static void tensor_scale_inplace(NCTensor *x, float scale)
{
    size_t total = tensor_numel(x);
    uint8_t *base = tensor_data_ptr(x);
    for (size_t i = 0; i < total; i++) {
        float v = nc_load_f32(base + i * x->item_size, x->item_type);
        nc_store_f32(base + i * x->item_size, x->item_type, v * scale);
    }
}

static void tensor_mul_inplace(NCTensor *dst, const NCTensor *src)
{
    size_t total = tensor_numel(dst);
    uint8_t *dbase = tensor_data_ptr(dst);
    const uint8_t *sbase = tensor_const_data_ptr(src);
    for (size_t i = 0; i < total; i++) {
        float dv = nc_load_f32(dbase + i * dst->item_size, dst->item_type);
        float sv = nc_load_f32(sbase + i * src->item_size, src->item_type);
        nc_store_f32(dbase + i * dst->item_size, dst->item_type, dv * sv);
    }
}

static void tensor_add_inplace(NCTensor *dst, const NCTensor *src)
{
    size_t total = tensor_numel(dst);
    uint8_t *dbase = tensor_data_ptr(dst);
    const uint8_t *sbase = tensor_const_data_ptr(src);
    for (size_t i = 0; i < total; i++) {
        float dv = nc_load_f32(dbase + i * dst->item_size, dst->item_type);
        float sv = nc_load_f32(sbase + i * src->item_size, src->item_type);
        nc_store_f32(dbase + i * dst->item_size, dst->item_type, dv + sv);
    }
}

static NCTensor *tensor_mul_like(const NCTensor *a, const NCTensor *b)
{
    NCTensor *y = tensor_clone_like(a);
    tensor_mul_inplace(y, b);
    return y;
}

static NCTensor *tensor_add_like(const NCTensor *a, const NCTensor *b)
{
    NCTensor *y = tensor_clone_like(a);
    tensor_add_inplace(y, b);
    return y;
}

static NCTensor *tensor_scaled_like(const NCTensor *a, float scale)
{
    NCTensor *y = tensor_clone_like(a);
    tensor_scale_inplace(y, scale);
    return y;
}

static void backward_tensor(NCTensor *x, NCTensor *grad, NCParamUpdateFunc *param_update_func, int flags)
{
    if (!x || !grad)
        return;
    if (!x->node) {
        nc_free_tensor(grad);
        return;
    }

    switch (x->node->op) {
    case NC_OP_PARAM:
        if (param_update_func)
            param_update_func(x->node->opaque, grad, NULL);
        nc_free_tensor(grad);
        return;
    case NC_OP_STOP_GRAD:
        nc_free_tensor(grad);
        return;
    case NC_OP_ADD: {
        backward_tensor(x->node->args[0], nc_dup_tensor(grad), param_update_func, flags);
        backward_tensor(x->node->args[1], grad, param_update_func, flags);
        return;
    }
    case NC_OP_SUB: {
        backward_tensor(x->node->args[0], nc_dup_tensor(grad), param_update_func, flags);
        tensor_scale_inplace(grad, -1.0f);
        backward_tensor(x->node->args[1], grad, param_update_func, flags);
        return;
    }
    case NC_OP_NEG:
        tensor_scale_inplace(grad, -1.0f);
        backward_tensor(x->node->args[0], grad, param_update_func, flags);
        return;
    case NC_OP_MUL:
        backward_tensor(x->node->args[0], tensor_mul_like(grad, x->node->args[1]), param_update_func, flags);
        backward_tensor(x->node->args[1], tensor_mul_like(grad, x->node->args[0]), param_update_func, flags);
        nc_free_tensor(grad);
        return;
    case NC_OP_DIV: {
        backward_tensor(x->node->args[0], tensor_scaled_like(tensor_mul_like(grad, nc_recip(nc_dup_tensor(x->node->args[1]))), 1.0f), param_update_func, flags);
        NCTensor *num = tensor_mul_like(grad, x->node->args[0]);
        NCTensor *den = tensor_mul_like(x->node->args[1], x->node->args[1]);
        NCTensor *g1 = tensor_mul_like(num, nc_recip(den));
        tensor_scale_inplace(g1, -1.0f);
        backward_tensor(x->node->args[1], g1, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_RECIP: {
        NCTensor *sq = tensor_mul_like(x->node->args[0], x->node->args[0]);
        NCTensor *g0 = tensor_mul_like(grad, nc_recip(sq));
        tensor_scale_inplace(g0, -1.0f);
        backward_tensor(x->node->args[0], g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_RELU: {
        NCTensor *g0 = tensor_clone_like(grad);
        size_t total = tensor_numel(g0);
        const uint8_t *xbase = tensor_const_data_ptr(x->node->args[0]);
        uint8_t *gbase = tensor_data_ptr(g0);
        for (size_t i = 0; i < total; i++) {
            float xv = nc_load_f32(xbase + i * x->node->args[0]->item_size, x->node->args[0]->item_type);
            float gv = nc_load_f32(gbase + i * g0->item_size, g0->item_type);
            nc_store_f32(gbase + i * g0->item_size, g0->item_type, xv > 0.0f ? gv : 0.0f);
        }
        backward_tensor(x->node->args[0], g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_SIGMOID: {
        NCTensor *g0 = tensor_clone_like(grad);
        size_t total = tensor_numel(g0);
        uint8_t *gbase = tensor_data_ptr(g0);
        const uint8_t *ybase = tensor_const_data_ptr(x);
        for (size_t i = 0; i < total; i++) {
            float yv = nc_load_f32(ybase + i * x->item_size, x->item_type);
            float gv = nc_load_f32(gbase + i * g0->item_size, g0->item_type);
            nc_store_f32(gbase + i * g0->item_size, g0->item_type, gv * yv * (1.0f - yv));
        }
        backward_tensor(x->node->args[0], g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_TANH: {
        NCTensor *g0 = tensor_clone_like(grad);
        size_t total = tensor_numel(g0);
        uint8_t *gbase = tensor_data_ptr(g0);
        const uint8_t *ybase = tensor_const_data_ptr(x);
        for (size_t i = 0; i < total; i++) {
            float yv = nc_load_f32(ybase + i * x->item_size, x->item_type);
            float gv = nc_load_f32(gbase + i * g0->item_size, g0->item_type);
            nc_store_f32(gbase + i * g0->item_size, g0->item_type, gv * (1.0f - yv * yv));
        }
        backward_tensor(x->node->args[0], g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_LOG: {
        NCTensor *g0 = tensor_mul_like(grad, nc_recip(nc_dup_tensor(x->node->args[0])));
        backward_tensor(x->node->args[0], g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_LERP: {
        NCTensor *a = x->node->args[0];
        NCTensor *b = x->node->args[1];
        NCTensor *t = x->node->args[2];
        NCTensor *one_minus_t = tensor_clone_like(t);
        size_t total = tensor_numel(t);
        uint8_t *b1 = tensor_data_ptr(one_minus_t);
        const uint8_t *tb = tensor_const_data_ptr(t);
        for (size_t i = 0; i < total; i++) {
            float tv = nc_load_f32(tb + i * t->item_size, t->item_type);
            nc_store_f32(b1 + i * one_minus_t->item_size, one_minus_t->item_type, 1.0f - tv);
        }
        backward_tensor(a, tensor_mul_like(grad, one_minus_t), param_update_func, flags);
        backward_tensor(b, tensor_mul_like(grad, t), param_update_func, flags);
        NCTensor *gt = tensor_mul_like(grad, tensor_add_like(b, tensor_scaled_like(a, -1.0f)));
        backward_tensor(t, gt, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_RESHAPE:
        backward_tensor(x->node->args[0], nc_reshape(grad, x->node->args[0]->n_dims, x->node->args[0]->dims), param_update_func, flags);
        return;
    case NC_OP_REPEAT:
        backward_tensor(x->node->args[0], nc_reduce_sum(NULL, grad, x->node->args[0]->n_dims), param_update_func, flags);
        return;
    case NC_OP_SLICE: {
        NCTensor *src = x->node->args[0];
        NCTensor *g0 = nc_new_tensor_nz(src->device, src->item_type, src->n_dims, src->dims);
        nc_tensor_set_zero(g0);
        NCTensor *sl = nc_slice_alias(g0, x->node->axis, (size_t)x->node->start, (size_t)x->node->end);
        nc_tensor_copy(sl, grad);
        nc_free_tensor(sl);
        backward_tensor(src, g0, param_update_func, flags);
        nc_free_tensor(grad);
        return;
    }
    case NC_OP_PERMUTE: {
        int n = x->node->n_args;
        int *axis = (int *)x->node->opaque;
        if (axis && n > 0) {
            int inv[NC_N_DIMS_MAX] = {0};
            for (int i = 0; i < n; i++)
                inv[axis[i]] = i;
            backward_tensor(x->node->args[0], nc_permute(grad, n, inv), param_update_func, flags);
            return;
        }
        break;
    }
    case NC_OP_MATMUL: {
        NCTensor *w = x->node->args[0];
        NCTensor *in = x->node->args[1];
        backward_tensor(w, nc_matmul(grad, nc_transpose(nc_dup_tensor(in))), param_update_func, flags);
        backward_tensor(in, nc_matmul(nc_transpose(nc_dup_tensor(w)), grad), param_update_func, flags);
        return;
    }
    case NC_OP_REDUCE_SUM:
    case NC_OP_REDUCE_SUM_SQR: {
        NCTensor *src = x->node->args[0];
        if (x->node->op == NC_OP_REDUCE_SUM_SQR) {
            NCTensor *g0 = tensor_mul_like(src, nc_dup_tensor(grad));
            tensor_scale_inplace(g0, 2.0f);
            backward_tensor(src, g0, param_update_func, flags);
        } else {
            NCTensor *g0 = nc_repeat(grad, src->n_dims, src->dims);
            backward_tensor(src, g0, param_update_func, flags);
        }
        return;
    }
    default:
        break;
    }

    nc_free_tensor(grad);
}

void nc_backward(const NCTensor *x, NCTensor *grad, NCParamUpdateFunc *param_update_func, int flags)
{
    if (!grad) {
        grad = nc_new_scalar(x->device, x->item_type);
        nc_tensor_set_f32(grad, 1.0f);
    }
    backward_tensor((NCTensor *)x, grad, param_update_func, flags);
}

void nc_dump_graph(NCTensor *x)
{
    if (!x)
        return;
    printf("tensor %p op=%d dims=", (void *)x, x->node ? (int)x->node->op : -1);
    for (int i = 0; i < x->n_dims; i++)
        printf("%s%zu", i ? "x" : "", x->dims[i]);
    putchar('\n');
}

void nc_param_list_init(NCParamList *pl)
{
    init_list_head(&pl->param_list);
    pl->add_graph = FALSE;
}

void nc_param_list_set_graph(NCParamList *pl, BOOL add_graph)
{
    pl->add_graph = add_graph;
}

NCParam *nc_new_param_str(NCParamList *pl, NCTensor **pval, const char *str)
{
    NCParam *p = nc_mallocz(sizeof(*p));
    p->pval = pval;
    p->name = nc_strdup(str);
    init_list_head(&p->link);
    list_add_tail(&p->link, &pl->param_list);
    return p;
}

NCParam *__attribute__((format(printf, 3, 4))) nc_new_param(NCParamList *pl, NCTensor **pval, const char *fmt, ...)
{
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    return nc_new_param_str(pl, pval, buf);
}

void nc_param_list_end(NCParamList *pl)
{
    struct list_head *el, *el1;
    list_for_each_safe(el, el1, &pl->param_list) {
        NCParam *p = list_entry(el, NCParam, link);
        list_del(&p->link);
        nc_free(p->name);
        nc_free(p);
    }
}

NCParam *nc_find_param(NCParamList *pl, const char *name)
{
    struct list_head *el;
    list_for_each(el, &pl->param_list) {
        NCParam *p = list_entry(el, NCParam, link);
        if (!strcmp(p->name, name))
            return p;
    }
    return NULL;
}

size_t nc_get_param_count(NCParamList *pl)
{
    size_t c = 0;
    struct list_head *el;
    list_for_each(el, &pl->param_list)
        c++;
    return c;
}

#include "libnc_param_io.c"

NCSGDOptState *nc_sgd_opt_init(NCContext *m, const SGDOptParams *p)
{
    NCSGDOptState *s = nc_mallocz(sizeof(*s));
    s->context = m;
    s->params = *p;
    init_list_head(&s->vars);
    init_list_head(&s->link);
    return s;
}

void nc_sgd_opt_end(NCSGDOptState *s)
{
    if (!s)
        return;
    struct list_head *el, *el1;
    list_for_each_safe(el, el1, &s->vars) {
        SGDOptVarState *v = list_entry(el, SGDOptVarState, link);
        list_del(&v->link);
        nc_free(v);
    }
    nc_free(s);
}

void sgd_opt_update_var(void *opaque, NCTensor *yg, NCTensor *get_col_index)
{
    (void)get_col_index;
    SGDOptVarState *v = opaque;
    if (!v || !v->param || !v->param->pval || !*v->param->pval || !yg)
        return;
    NCTensor *p = *v->param->pval;
    size_t total = tensor_numel(p);
    for (size_t i = 0; i < total; i++) {
        float pv = nc_load_f32((uint8_t *)tensor_const_data_ptr(p) + i * p->item_size, p->item_type);
        float gv = nc_load_f32((const uint8_t *)tensor_const_data_ptr(yg) + i * yg->item_size, yg->item_type);
        pv -= v->owner->params.lr * gv;
        nc_store_f32((uint8_t *)tensor_data_ptr(p) + i * p->item_size, p->item_type, pv);
    }
}

void nc_sgd_opt_set_all(NCParamList *param_list, NCSGDOptState *s)
{
    struct list_head *el;
    list_for_each(el, &param_list->param_list) {
        NCParam *p = list_entry(el, NCParam, link);
        nc_sgd_opt_set(p, s);
    }
}

void nc_sgd_opt_set(NCParam *x, NCSGDOptState *s)
{
    if (!x)
        return;
    if (!s) {
        if (x->sgd_opt) {
            list_del(&x->sgd_opt->link);
            nc_free(x->sgd_opt);
            x->sgd_opt = NULL;
        }
        return;
    }
    SGDOptVarState *v = nc_mallocz(sizeof(*v));
    v->param = x;
    v->owner = s;
    init_list_head(&v->link);
    list_add_tail(&v->link, &s->vars);
    x->sgd_opt = v;
}

void nc_sgd_opt_update(NCSGDOptState *s)
{
    struct list_head *el;
    list_for_each(el, &s->vars) {
        SGDOptVarState *v = list_entry(el, SGDOptVarState, link);
        if (v->param && v->param->saved_grad)
            sgd_opt_update_var(v, v->param->saved_grad, NULL);
    }
}

void nc_sgd_opt_set_lr(NCSGDOptState *s, float lr)
{
    s->params.lr = lr;
}

float nc_sgd_opt_get_lr(NCSGDOptState *s)
{
    return s->params.lr;
}

NCTensor *nc_sgd_opt_get_grad(NCParam *p)
{
    return p ? p->saved_grad : NULL;
}

void rnd_init(RNDState *s, uint32_t seed)
{
    s->seed = seed ? seed : 1;
    s->idx = 0;
    s->y1 = 0;
}

uint32_t rnd_unif_u32(RNDState *s)
{
    uint32_t x = s->seed;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    s->seed = x;
    return x;
}

float rnd_unif(RNDState *s)
{
    return (rnd_unif_u32(s) >> 8) * (1.0f / 16777216.0f);
}

void rnd_unif_vec(float *tab, size_t n, float mu, float range, RNDState *s)
{
    for (size_t i = 0; i < n; i++)
        tab[i] = mu + (rnd_unif(s) * 2.0f - 1.0f) * range;
}

void rnd_unif_mat(float *tab, size_t stride, size_t h, size_t w, float mu, float sigma, RNDState *s)
{
    for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
            tab[i * stride + j] = mu + (rnd_unif(s) * 2.0f - 1.0f) * sigma;
}

float vec_sum_f32(const float *tab, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++)
        sum += tab[i];
    return sum;
}

int nc_topk(NCTopKEntry **ptab, double *psum, const float *prob, size_t n, int topk, float topp)
{
    if (topk < 0)
        topk = 0;
    if ((size_t)topk > n)
        topk = (int)n;
    NCTopKEntry *tab = nc_malloc(sizeof(*tab) * n);
    for (size_t i = 0; i < n; i++) {
        tab[i].val = prob[i];
        tab[i].idx = (uint32_t)i;
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (tab[j].val > tab[i].val) {
                NCTopKEntry tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
    double sum = 0.0;
    int k = 0;
    for (; k < topk; k++) {
        if (k > 0 && sum >= topp)
            break;
        sum += tab[k].val;
    }
    *ptab = tab;
    if (psum)
        *psum = sum;
    return k;
}
