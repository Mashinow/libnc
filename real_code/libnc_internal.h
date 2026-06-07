#ifndef LIBNC_INTERNAL_H
#define LIBNC_INTERNAL_H

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
    size_t strides[NC_N_DIMS_MAX];
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

static void context_track_buffer(NCContext *ctx, NCTensorBuffer *b);
static void context_untrack_buffer(NCTensorBuffer *b);
static void context_track_tensor(NCContext *ctx, NCTensor *t);
static void context_untrack_tensor(NCTensor *t);
static void context_track_node(NCContext *ctx, NCNode *n);
static void context_untrack_node(NCNode *n);
static void context_track_device(NCContext *ctx, NCDevice *d);
static void context_untrack_device(NCDevice *d);
static inline size_t tensor_numel(const NCTensor *t);
static inline void *tensor_data_ptr(const NCTensor *t);
static inline const void *tensor_const_data_ptr(const NCTensor *t);
void nc_node_set_parent(NCNode *n, int arg_index, const NCNode *n1);

#endif /* LIBNC_INTERNAL_H */
