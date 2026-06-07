# LibNC Documentation

This document combines the original LibNC manual structure with the current state of this reconstruction.

Source notes:
- original manual: `doc/libnc.html` from the 2021 release
- reconstruction status: see [`IMPLEMENTATION_CHECKLIST.md`](https://github.com/Mashinow/libnc/blob/master/IMPLEMENTATION_CHECKLIST.md)
- current code layout: `src/`, `tests/`, `decompile/`

## 1. What LibNC is

LibNC is a C library for tensor manipulation and automatic differentiation. The original project targets machine-learning style workloads such as LSTM and Transformers. The design goals emphasized:

- a small C API
- a shared-library / DLL style deployment model
- define-by-run automatic differentiation
- high performance on CPU and GPU
- optimized float32 and BF16 support
- deterministic behavior
- reproducibility on CPU across platforms
- compute-graph optimization for online learning

This reconstruction follows the same architecture, with a CPU implementation in `src/` and an optional CUDA backend source path.

## 2. Original manual overview

### 2.1 Usage

LibNC is meant to be linked as a shared library or DLL. The public API is pure C, so it can be used from C, C++, and foreign-function interfaces.

The upstream documentation describes the original project as requiring x86 with AVX2, and as offering CUDA support as an optional backend. In this reconstruction:

- the CPU path is the primary implementation
- the CUDA backend is optional
- the shipped tests cover CPU behavior directly and CUDA behavior when the backend is present

### 2.2 Main concepts

- `NCContext` is the library instance. It owns runtime state, devices, random generators, and parallel helpers.
- `NCDevice` represents a compute device, currently CPU or CUDA-compatible.
- `NCTensor` is the main data object. It carries shape, type, buffer, graph links, and gradients.
- `NCTensorBuffer` is the underlying storage that may be shared between tensors.

Most tensor operations require operands on the same device.

### 2.3 Tensor layout

LibNC uses a layout convention where the smallest dimension comes first and matrices are stored in a column-major style. That affects:

- `nc_matmul`
- slicing and concatenation
- permutation and transpose
- serialization

New tensors are contiguous unless a view or alias changes the layout.

### 2.4 Automatic differentiation engine

LibNC uses define-by-run autodiff:

- the graph is built as operations are executed
- user-created tensors normally do not start with a graph parent
- parameter tensors are attached to the graph explicitly
- backward traversal propagates gradients from outputs to inputs

The shipped tests exercise both standard gradients and Hessian-vector style flows.

## 3. Implementation details from the original manual

### 3.1 Determinism

The upstream project emphasizes deterministic outputs: the same computation on the same system should produce the same result across runs. The reconstruction keeps that property for the CPU path used by the tests.

### 3.2 Reproducibility

The manual distinguishes determinism from reproducibility across CPU brands, OSes, and thread counts. The original documentation states that CPU results were intended to be reproducible, while GPU results could differ because of hardware-specific behavior. This reconstruction keeps the same distinction in mind.

### 3.3 Compute graph optimization

LibNC includes graph optimizations such as matrix-product factorization. The original manual specifically mentions `nc_concat_optimization()` for online learning, where sequential evaluation steps can be combined to improve compute-device utilization.

This reconstruction preserves that behavior at the API level, but some graph edge cases are still simplified compared to the original binary. See the implementation checklist for the current status.

### 3.4 CUDA backend

The original documentation describes NVIDIA CUDA support as optional and contained in a separate `libnc_cuda` component. That backend depends on CUDA and cuBLAS. Only Ampere GPUs were originally supported to take advantage of hardware BF16 support.

The reconstructed project keeps the same split:

- `src/libnc_cuda_backend.c` implements the CUDA backend source
- `src/libnc_cuda_loader.c` discovers and loads the backend at runtime
- if the backend is missing, the library falls back to the compatibility path

### 3.5 BF16 support

BF16 is a truncated 16-bit float format derived from float32. The original manual says BF16 is supported on both CPU and GPU, and that the ADAM optimizer keeps the low 16 bits of parameters to avoid precision loss during updates.

This reconstruction follows the same idea:

- BF16 tensors are handled on the CPU path
- BF16 parameters keep a float32 shadow copy for optimizer updates
- the GPU backend has BF16-aware tensor kernels where the backend is present

## 4. Build and platform notes

### Windows

Build the main library:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc.dll libnc.c -Wl,--out-implib,libnc.dll.a
```

Build the CUDA backend:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc_cuda.dll src/libnc_cuda_backend.c -L. -lnc -Wl,--out-implib,libnc_cuda.dll.a
```

Build the shipped tests:

```bash
gcc -std=gnu11 -O2 -I. tests/nctest.c libnc.c -o nctest.exe
gcc -std=gnu11 -O2 -I. tests/matmul_test.c libnc.c -o matmul_test.exe
gcc -std=gnu11 -O2 -I. tests/ncspeed.c libnc.c -o ncspeed.exe
gcc -std=gnu11 -O2 -I. tests/own_tests.c libnc.c -o own_tests.exe
```

### Linux / WSL

Build the shared objects:

```bash
gcc -std=gnu11 -O2 -fPIC -I. -shared -o libnc.so libnc.c -lpthread -ldl -lm
gcc -std=gnu11 -O2 -fPIC -I. -shared -o libnc_cuda.so src/libnc_cuda_backend.c -L. -lnc -lpthread -ldl -lm
```

Build the tests:

```bash
gcc -std=gnu11 -O2 -I. tests/nctest.c libnc.c -o nctest -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/matmul_test.c libnc.c -o matmul_test -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/ncspeed.c libnc.c -o ncspeed -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/own_tests.c libnc.c -o own_tests -lpthread -ldl -lm
```

### Verified status

- Windows 10 has been validated in this reconstruction
- Linux / WSL support is documented and is being checked separately

## 5. Core types

| Type | Meaning |
|---|---|
| `NCContext` | library runtime instance |
| `NCDevice` | CPU or CUDA device wrapper |
| `NCTensor` | tensor object with data, layout, graph links, and gradients |
| `NCTensorBuffer` | shared storage object |
| `NCNode` | graph node metadata |
| `NCRNDState` | per-device random state |
| `NCSGDOptState` | optimizer state object |
| `NCParamList` | list of registered parameter bindings |
| `NCParam` | one parameter binding entry |
| `RNDState` | standalone utility RNG state |

Important enums and helper types:

- `NCTypeEnum`: `NC_TYPE_F32`, `NC_TYPE_BF16`, `NC_TYPE_F16`, `NC_TYPE_I8`, `NC_TYPE_I16`, `NC_TYPE_I32`
- `NCPadEnum`: `NC_PAD_ZERO`, `NC_PAD_DUP`, `NC_TRIM_NORMAL`, `NC_TRIM_SUM`
- `SGDOptAlgoEnum`: `SGD_OPT_BASIC`, `SGD_OPT_ADAM`, `SGD_OPT_TEST`
- `SGDOptParams`: optimizer configuration
- `NCTopKEntry`: output record for `nc_topk`

## 6. API reference

### 6.1 Profiling and low-level memory

| Function | Returns | What it does |
|---|---:|---|
| `void nc_prof_dump(void)` | void | Prints profiling counters if profiling is enabled. |
| `void *nc_malloc(size_t size)` | `void *` | Allocates raw memory using the library allocator. |
| `void *nc_mallocz(size_t size)` | `void *` | Allocates zero-initialized memory. |
| `void nc_free(void *ptr)` | void | Frees memory allocated by the library allocator. |

### 6.2 Context, devices, buffers

| Function | Returns | What it does |
|---|---:|---|
| `NCContext *nc_context_init(int nb_threads)` | `NCContext *` | Creates a runtime context and optionally enables internal parallelism. |
| `void nc_context_end(NCContext *m)` | void | Destroys the context and frees all owned runtime state. |
| `NCDevice *nc_new_cpu_device(NCContext *m)` | `NCDevice *` | Creates the CPU device for a context. |
| `NCDevice *nc_new_cuda_device(NCContext *m, int device_index)` | `NCDevice *` | Creates a CUDA device or a compatibility fallback device. |
| `BOOL nc_cuda_backend_available(void)` | `BOOL` | Returns whether a real external CUDA backend was discovered. |
| `NCDevice *nc_new_device(NCContext *m, const char *device_name)` | `NCDevice *` | Parses a device name such as `cpu` or `cuda:0`. |
| `void nc_synchronize(NCDevice *d)` | void | Waits for pending device work to finish. |
| `NCTensorBuffer *nc_new_tensor_buffer(NCDevice *d, size_t size)` | `NCTensorBuffer *` | Allocates a tensor buffer on a device. |
| `NCTensorBuffer *nc_dup_tensor_buffer(const NCTensorBuffer *b)` | `NCTensorBuffer *` | Duplicates a buffer reference or copies buffer state. |
| `void nc_free_tensor_buffer(NCTensorBuffer *b)` | void | Releases a tensor buffer. |

### 6.3 Tensor creation and inspection

| Function | Returns | What it does |
|---|---:|---|
| `NCTensor *nc_new_tensor(NCDevice *d, NCTypeEnum type, int n_dims, const size_t *dims)` | `NCTensor *` | Creates a tensor with explicit shape. |
| `NCTensor *nc_new_tensor_from_tensor(const NCTensor *x)` | `NCTensor *` | Clones a tensor including its metadata. |
| `NCTensor *nc_new_tensor_from_tensor_nz(const NCTensor *x)` | `NCTensor *` | Clones a tensor while preserving nonzero semantics used by the API. |
| `NCTensor *nc_new_scalar(NCDevice *d, NCTypeEnum type)` | `NCTensor *` | Creates a scalar tensor. |
| `NCTensor *nc_new_tensor_1d(NCDevice *d, NCTypeEnum type, size_t len)` | `NCTensor *` | Creates a 1D tensor. |
| `NCTensor *nc_new_tensor_2d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1)` | `NCTensor *` | Creates a 2D tensor. |
| `NCTensor *nc_new_tensor_3d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1, size_t n2)` | `NCTensor *` | Creates a 3D tensor. |
| `NCTensor *nc_new_tensor_4d(NCDevice *d, NCTypeEnum type, size_t n0, size_t n1, size_t n2, size_t n3)` | `NCTensor *` | Creates a 4D tensor. |
| `NCTensor *nc_tensor_set_name(NCTensor *x, const char *fmt, ...)` | `NCTensor *` | Assigns a formatted debug name. |
| `NCTensor *nc_dup_tensor(const NCTensor *x)` | `NCTensor *` | Duplicates a tensor and its metadata. |
| `void nc_free_tensor(NCTensor *x)` | void | Releases a tensor. |
| `void nc_dump_tensor(const char *name, NCTensor *x, size_t n)` | void | Prints the first `n` tensor values for debugging. |
| `uint32_t nc_tensor_get_hash(NCTensor *x)` | `uint32_t` | Returns a hash of tensor contents and layout. |
| `void nc_dump_tensor_hash(const char *name, const NCTensor *x)` | void | Prints the tensor hash for debugging. |
| `NCNode *nc_get_node(NCTensor *x)` | `NCNode *` | Returns the backing graph node for a tensor. |
| `NCTensor *nc_slice_alias(const NCTensor *x1, int axis, size_t start, size_t end)` | `NCTensor *` | Creates a gradient-free alias to a slice view. |
| `NCTypeEnum nc_tensor_get_item_type(const NCTensor *x)` | `NCTypeEnum` | Returns the tensor element type. |
| `NCTensorData *nc_tensor_get_data(NCTensorData *sd, const NCTensor *x)` | `NCTensorData *` | Fills a tensor-data descriptor for inspection. |
| `void *nc_tensor_get_ptr(NCTensor *x, size_t *pstride)` | `void *` | Returns the raw data pointer and optional leading stride. |
| `const size_t *nc_tensor_get_dims(const NCTensor *x, int *pn_dims)` | `const size_t *` | Returns the tensor dimensions. |

### 6.4 Data access and mutation

| Function | Returns | What it does |
|---|---:|---|
| `void nc_tensor_set_zero(NCTensor *y)` | void | Fills a tensor with zero. |
| `void nc_tensor_set_f32(NCTensor *y, float val)` | void | Fills a tensor with a float32 value. |
| `NCRNDState *nc_rnd_init(NCDevice *d, uint32_t seed)` | `NCRNDState *` | Creates a per-device random state. |
| `void nc_rnd_end(NCRNDState *s)` | void | Destroys a random state. |
| `void nc_tensor_set_rnd_unif(NCTensor *y, float avg, float range, NCRNDState *rnd_state)` | void | Fills a tensor with uniform random values. |
| `void nc_tensor_set_dropout(NCTensor *y, float prob, NCRNDState *rnd_state)` | void | Fills a tensor with dropout mask values. |
| `void nc_set1_i32(NCTensor *y, int n_dims, const size_t *tab_indexes, int32_t val)` | void | Writes one int32 element at an indexed position. |
| `void nc_set1_i32_1d(NCTensor *y, size_t i0, int32_t val)` | void | Writes one int32 element in 1D form. |
| `void nc_set1_i32_2d(NCTensor *y, size_t i0, size_t i1, int32_t val)` | void | Writes one int32 element in 2D form. |
| `void nc_set1_f32(NCTensor *y, int n_dims, const size_t *tab_indexes, float val)` | void | Writes one float32 element at an indexed position. |
| `void nc_set1_f32_1d(NCTensor *y, size_t i0, float val)` | void | Writes one float32 element in 1D form. |
| `int32_t nc_get1_i32(const NCTensor *x, int n_dims, const size_t *tab_indexes)` | `int32_t` | Reads one int32 element at an indexed position. |
| `float nc_get1_f32(const NCTensor *x, int n_dims, const size_t *tab_indexes)` | `float` | Reads one float32 element at an indexed position. |
| `float nc_get1_f32_1d(const NCTensor *x, size_t i0)` | `float` | Reads one float32 element in 1D form. |
| `float nc_get_scalar_f32(const NCTensor *x)` | `float` | Reads a scalar tensor as float32. |
| `void nc_tensor_copy(NCTensor *dst, NCTensor *src)` | void | Copies tensor data and compatible metadata. |
| `void nc_tensor_convert(NCTensor *dst, NCTensor *src)` | void | Converts tensor contents between supported element types. |
| `void nc_dump_dims(const char *str, NCTensor *x)` | void | Prints the tensor dimensions for debugging. |
| `size_t nc_get_heap_size(NCContext *m)` | `size_t` | Returns the context heap size. |
| `NCContext *nc_get_tensor_context(const NCTensor *x)` | `NCContext *` | Returns the owning context of a tensor. |
| `NCTensor *nc_tensor_to_device(NCTensor *x, NCDevice *d)` | `NCTensor *` | Moves or clones a tensor to a device. |
| `NCTensor *nc_tensor_to_cpu_device(NCTensor *x)` | `NCTensor *` | Convenience wrapper that moves a tensor to CPU. |
| `NCDevice *nc_get_tensor_device(const NCTensor *x)` | `NCDevice *` | Returns the owning device of a tensor. |
| `NCTensor *nc_convert(NCTensor *x, NCTypeEnum new_type)` | `NCTensor *` | Returns a converted tensor. |

### 6.5 Element-wise operations

| Function | Returns | What it does |
|---|---:|---|
| `NCTensor *nc_add(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise addition. |
| `NCTensor *nc_neg(NCTensor *x)` | `NCTensor *` | Element-wise negation. |
| `NCTensor *nc_sub(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise subtraction. |
| `NCTensor *nc_mul(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise multiplication. |
| `NCTensor *nc_div(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise division. |
| `NCTensor *nc_recip(NCTensor *x)` | `NCTensor *` | Reciprocal, `1 / x`. |
| `NCTensor *nc_min(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise minimum. |
| `NCTensor *nc_max(NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Element-wise maximum. |
| `NCTensor *nc_select(NCTensor *z, NCTensor *x1, NCTensor *x2)` | `NCTensor *` | Chooses `x1` where `z == 0` and `x2` otherwise. |
| `NCTensor *nc_masked_fill(NCTensor *x, NCTensor *mask, float c, BOOL mask_inv)` | `NCTensor *` | Replaces masked values by a constant. |
| `NCTensor *nc_sigmoid(NCTensor *x)` | `NCTensor *` | Sigmoid activation. |
| `NCTensor *nc_tanh(NCTensor *x)` | `NCTensor *` | Hyperbolic tangent. |
| `NCTensor *nc_relu(NCTensor *x)` | `NCTensor *` | Rectified linear unit. |
| `NCTensor *nc_gelu(NCTensor *x)` | `NCTensor *` | GELU activation. |
| `NCTensor *nc_log(NCTensor *x)` | `NCTensor *` | Natural logarithm. |
| `NCTensor *nc_lstm_clamped(NCTensor *cp, NCTensor *in, NCTensor *fg, NCTensor *ig)` | `NCTensor *` | LSTM-style clamped update: `cp * fg + min(1 - fg, ig) * in`. |
| `NCTensor *nc_lerp(NCTensor *a, NCTensor *b, NCTensor *t)` | `NCTensor *` | Linear interpolation `a * (1 - t) + b * t`. |

### 6.6 Shape, layout, slicing, and concatenation

| Function | Returns | What it does |
|---|---:|---|
| `NCTensor *nc_new_vec_f32(NCDevice *d, size_t n, float val)` | `NCTensor *` | Creates a float32 vector filled with a constant. |
| `NCTensor *nc_new_f32(NCDevice *d, float val)` | `NCTensor *` | Creates a float32 scalar initialized to `val`. |
| `NCTensor *nc_reshape(NCTensor *x, int n_dims, const size_t *dims)` | `NCTensor *` | Changes the visible shape without changing data order. |
| `NCTensor *nc_reshape_1d(NCTensor *x, size_t n0)` | `NCTensor *` | 1D reshape helper. |
| `NCTensor *nc_reshape_2d(NCTensor *x, size_t n0, size_t n1)` | `NCTensor *` | 2D reshape helper. |
| `NCTensor *nc_reshape_3d(NCTensor *x, size_t n0, size_t n1, size_t n2)` | `NCTensor *` | 3D reshape helper. |
| `NCTensor *nc_reshape_4d(NCTensor *x, size_t n0, size_t n1, size_t n2, size_t n3)` | `NCTensor *` | 4D reshape helper. |
| `NCTensor *nc_repeat(NCTensor *x, int n_dims, const size_t *dims)` | `NCTensor *` | Tiles a tensor by repeating its data along new axes. |
| `NCTensor *nc_repeat_1d(NCTensor *x, size_t n)` | `NCTensor *` | 1D repeat helper. |
| `NCTensor *nc_reduce_sum(NCTensor *y0, NCTensor *x, int n_dims)` | `NCTensor *` | Reduces all dimensions beyond `n_dims` with summation, optionally adding into `y0`. |
| `NCTensor *nc_sum(NCTensor *x)` | `NCTensor *` | Sums all elements of a tensor. |
| `NCTensor *nc_reduce_sum_sqr(NCTensor *x)` | `NCTensor *` | Sums squares of all elements. |
| `NCTensor *nc_slice(NCTensor *x, int axis, size_t start, size_t end)` | `NCTensor *` | Returns a slice view or tensor slice. |
| `NCTensor *nc_slice_add(NCTensor *y0, NCTensor *x, int axis, size_t start)` | `NCTensor *` | Adds a sliced tensor into `y0` at the requested offset. |
| `NCTensor *nc_concat(NCTensor **inputs, int n_inputs, int axis)` | `NCTensor *` | Concatenates tensors along an axis. |
| `NCTensor *nc_vconcat(NCTensor **inputs, int n_inputs)` | `NCTensor *` | Concatenates along axis 0. |
| `NCTensor *nc_hconcat(NCTensor **inputs, int n_inputs)` | `NCTensor *` | Concatenates along axis 1. |
| `void nc_split(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size, int axis)` | void | Splits a tensor into multiple outputs. |
| `void nc_vsplit(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size)` | void | Splits along axis 0. |
| `void nc_hsplit(NCTensor **tab_y, NCTensor *x, int n_outputs, const size_t *tab_size)` | void | Splits along axis 1. |
| `NCTensor *nc_pad(NCTensor *x, ssize_t left_len, NCPadEnum left_op, ssize_t right_len, NCPadEnum right_op)` | `NCTensor *` | Pads or trims axis 0. |
| `NCTensor *nc_resize(NCTensor *x, size_t n)` | `NCTensor *` | Convenience wrapper around `nc_pad()` for 1D resizing. |
| `NCTensor *nc_make_contiguous(NCTensor *x)` | `NCTensor *` | Returns a contiguous copy if needed. |
| `NCTensor *nc_permute_alias(NCTensor *x, int n_dims, const int *axis)` | `NCTensor *` | Creates a dimension-permuted alias. |
| `NCTensor *nc_permute(NCTensor *x, int n_dims, const int *axis)` | `NCTensor *` | Permutes dimensions and materializes a contiguous tensor. |
| `NCTensor *nc_transpose(NCTensor *x)` | `NCTensor *` | Special case of permutation for 2D tensors. |

### 6.7 Matrix, indexed, and normalization ops

| Function | Returns | What it does |
|---|---:|---|
| `NCTensor *nc_matmul(NCTensor *w, NCTensor *x)` | `NCTensor *` | Matrix multiplication in LibNC layout conventions. |
| `NCTensor *nc_matmul_add(NCTensor *w, NCTensor *x, NCTensor *y0, BOOL w_trans, BOOL x_trans)` | `NCTensor *` | Matrix multiplication plus optional accumulation and transpose flags. |
| `NCTensor *nc_matmul_stride(NCTensor *w, NCTensor *x)` | `NCTensor *` | Strided matrix multiplication helper. |
| `NCTensor *nc_get_col(NCTensor *w, NCTensor *x)` | `NCTensor *` | Gathers columns from a matrix. |
| `NCTensor *nc_add_col(NCTensor *z, NCTensor *x, NCTensor *w)` | `NCTensor *` | Scatters vectors into matrix columns. |
| `NCTensor *nc_get_element(NCTensor *w, NCTensor *x)` | `NCTensor *` | Gathers one element per column. |
| `NCTensor *nc_add_element(NCTensor *z, NCTensor *x, NCTensor *w)` | `NCTensor *` | Scatters one element per column. |
| `NCTensor *nc_soft_max(NCTensor *x)` | `NCTensor *` | Numerically stable softmax. |
| `NCTensor *nc_indexed_log(NCTensor *x, NCTensor *eout)` | `NCTensor *` | Log of selected elements, optimized for `soft_max` + `get_element` style flows. |
| `NCTensor *nc_layer_norm(NCTensor *x, float eps)` | `NCTensor *` | Layer normalization across the last dimensions. |
| `NCTensor *nc_rms_norm(NCTensor *x, float eps)` | `NCTensor *` | RMS normalization. |
| `NCTensor *nc_slt_mat_set(NCTensor *x, size_t pos, float c)` | `NCTensor *` | Sets an element in a special matrix layout. |
| `NCTensor *nc_rel_shift(NCTensor *x, ssize_t pos, ssize_t mult)` | `NCTensor *` | Relative-position shift with zero padding. |

### 6.8 Graph and automatic differentiation

| Function | Returns | What it does |
|---|---:|---|
| `NCTensor *nc_set_param(NCTensor *x, void *opaque)` | `NCTensor *` | Marks a tensor as a trainable parameter. |
| `NCTensor *nc_stop_grad(NCTensor *x)` | `NCTensor *` | Returns a graph-detached tensor. |
| `NCNode *nc_dup_node(const NCNode *n)` | `NCNode *` | Duplicates graph-node metadata. |
| `void nc_free_node(NCNode *n)` | void | Frees a graph node. |
| `void nc_combine_nodes(NCContext *m, NCNode **tab_op1, int count, int axis, int elem_size, const size_t *tab_elem_size)` | void | Merges nodes for graph optimization. |
| `NCNode *nc_concat_node(NCContext *m, NCNode **inputs, int count, int axis, const size_t *tab_size)` | `NCNode *` | Builds a concat node for graph optimization. |
| `void nc_concat_optimization(NCContext *m, NCNode **concat_nodes, int count)` | void | Optimizes multiple concat nodes together. |
| `void nc_node_set_parent(NCNode *n, int arg_index, const NCNode *n1)` | void | Assigns a graph parent to a node argument. |
| `void nc_node_set_arg(NCNode *n, int arg_index, const NCTensor *x)` | void | Binds a tensor argument to a graph node. |
| `void nc_backward(const NCTensor *x, NCTensor *grad, NCParamUpdateFunc *param_update_func, int flags)` | void | Runs reverse-mode autodiff and optional parameter update callbacks. |
| `void nc_dump_graph(NCTensor *x)` | void | Prints the graph for debugging. |

### 6.9 Parameters and serialized state

| Function | Returns | What it does |
|---|---:|---|
| `void nc_param_list_init(NCParamList *pl)` | void | Initializes a parameter list. |
| `void nc_param_list_set_graph(NCParamList *pl, BOOL add_graph)` | void | Enables or disables automatic graph attachment for new parameters. |
| `NCParam *nc_new_param_str(NCParamList *pl, NCTensor **pval, const char *str)` | `NCParam *` | Registers a parameter with a fixed name. |
| `NCParam *nc_new_param(NCParamList *pl, NCTensor **pval, const char *fmt, ...)` | `NCParam *` | Registers a parameter with a formatted name. |
| `void nc_param_list_end(NCParamList *pl)` | void | Releases a parameter list and its bookkeeping. |
| `NCParam *nc_find_param(NCParamList *pl, const char *name)` | `NCParam *` | Looks up a parameter by name. |
| `size_t nc_get_param_count(NCParamList *pl)` | `size_t` | Returns the number of registered parameters. |
| `void nc_save_coefs(NCParamList *pl, const char *filename)` | void | Saves parameter coefficients. |
| `void nc_load_coefs(NCParamList *pl, const char *filename)` | void | Loads parameter coefficients. |
| `void nc_save_state(NCParamList *pl, const char *filename)` | void | Saves the parameter state, including optimizer-related metadata where applicable. |
| `void nc_load_state(NCParamList *pl, const char *filename)` | void | Loads parameter state. |

### 6.10 SGD optimizer

| Function | Returns | What it does |
|---|---:|---|
| `NCSGDOptState *nc_sgd_opt_init(NCContext *m, const SGDOptParams *p)` | `NCSGDOptState *` | Creates an optimizer state. |
| `void nc_sgd_opt_end(NCSGDOptState *s)` | void | Destroys an optimizer state. |
| `void sgd_opt_update_var(void *opaque, NCTensor *yg, NCTensor *get_col_index)` | void | Internal update callback used during parameter updates. |
| `void nc_sgd_opt_set_all(NCParamList *param_list, NCSGDOptState *s)` | void | Attaches one optimizer to all parameters in a list. |
| `void nc_sgd_opt_set(NCParam *x, NCSGDOptState *s)` | void | Attaches or detaches one parameter from an optimizer. |
| `void nc_sgd_opt_update(NCSGDOptState *s)` | void | Runs one optimizer step. |
| `void nc_sgd_opt_set_lr(NCSGDOptState *s, float lr)` | void | Sets the optimizer learning rate. |
| `float nc_sgd_opt_get_lr(NCSGDOptState *s)` | `float` | Returns the current learning rate. |
| `NCTensor *nc_sgd_opt_get_grad(NCParam *p)` | `NCTensor *` | Returns the saved gradient for test/debug use. |

### 6.11 Miscellaneous utilities

| Function | Returns | What it does |
|---|---:|---|
| `void rnd_init(RNDState *s, uint32_t seed)` | void | Initializes the standalone utility RNG. |
| `uint32_t rnd_unif_u32(RNDState *s)` | `uint32_t` | Returns a uniform 32-bit random integer. |
| `float rnd_unif(RNDState *s)` | `float` | Returns a uniform float in `[0, 1)`. |
| `void rnd_unif_vec(float *tab, size_t n, float mu, float range, RNDState *s)` | void | Fills a vector with uniform random values. |
| `void rnd_unif_mat(float *tab, size_t stride, size_t h, size_t w, float mu, float sigma, RNDState *s)` | void | Fills a matrix with uniform random values. |
| `float vec_sum_f32(const float *tab, size_t n)` | `float` | Sums a float32 array. |
| `int nc_topk(NCTopKEntry **ptab, double *psum, const float *prob, size_t n, int topk, float topp)` | `int` | Extracts a top-k / nucleus-sampling style prefix from a probability vector. |

## 7. Common usage examples

### 7.1 Create a context and a tensor

```c
NCContext *ctx = nc_context_init(1);
NCDevice *cpu = nc_new_cpu_device(ctx);
NCTensor *x = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
nc_tensor_set_f32(x, 1.0f);
```

### 7.2 Run a simple element-wise expression

```c
NCTensor *a = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
NCTensor *b = nc_new_tensor_1d(cpu, NC_TYPE_F32, 4);
NCTensor *y = nc_add(nc_sigmoid(a), nc_relu(b));
```

### 7.3 Multiply matrices

```c
NCTensor *w = nc_new_tensor_2d(cpu, NC_TYPE_F32, 4, 4);
NCTensor *x = nc_new_tensor_2d(cpu, NC_TYPE_F32, 4, 1);
NCTensor *y = nc_matmul(w, x);
```

### 7.4 Attach a parameter and run backward

```c
NCParamList pl;
nc_param_list_init(&pl);

NCTensor *w = nc_new_tensor_2d(cpu, NC_TYPE_F32, 4, 4);
nc_new_param(&pl, &w, "layer.w");
NCTensor *loss = nc_sum(nc_mul(w, w));
nc_backward(loss, NULL, NULL, 0);
```

### 7.5 Save and load parameter state

```c
nc_save_state(&pl, "model.state");
nc_load_state(&pl, "model.state");
```

## 8. Notes on the reconstruction

- The implementation is strong where the shipped tests are strongest.
- Some graph-optimization and optimizer corner cases are still simplified compared to the original binary.
- The CUDA backend exists as source in `src/`, but it remains optional.
- The doc and checklist should be updated together whenever the runtime behavior changes.

