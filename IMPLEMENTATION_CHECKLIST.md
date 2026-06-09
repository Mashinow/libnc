# libnc implementation checklist

Статус отражает текущее состояние кода в `src/` и базовых зависимостей `cutils.h` / `list.h`.

## Utility helpers

### Covered by `cutils.h`
- [x] `BOOL` / `TRUE` / `FALSE`
- [x] `bfloat16_t`
- [x] `get_cycles`
- [x] `max_int`
- [x] `min_int`
- [x] `max_size_t`
- [x] `min_size_t`
- [x] `max_ssize_t`
- [x] `min_ssize_t`
- [x] `clamp_int`
- [x] `clamp_float`
- [x] `clz32`
- [x] `clz64`
- [x] `floor_log2`
- [x] `ceil_log2`
- [x] `squaref`

### Covered by `list.h`
- [x] `init_list_head`
- [x] `list_add`
- [x] `list_add_tail`
- [x] `list_del`
- [x] `list_empty`
- [x] `list_for_each`
- [x] `list_for_each_safe`
- [x] `list_for_each_prev`
- [x] `list_for_each_prev_safe`

Note: these helpers do not need a duplicate implementation in `src/` because they are included through `libnc.h`.

## Implemented

### Runtime / core
- [x] `nc_malloc`
- [x] `nc_mallocz`
- [x] `nc_free`
- [x] `nc_error`
- [x] `nc_prof_dump`
- [x] `nc_fpu_init`

### Context / devices / buffers
- [x] `nc_context_init`
- [x] `nc_context_end`
- [x] `nc_new_cpu_device`
- [x] `nc_new_device` for `cpu`
- [~] `nc_new_cuda_device` - searches executable dir, `PATH`, CUDA env vars, and portable overrides (`LIBNC_CUDA_DLL`, `LIBNC_CUDA_DIR`, `LIBNC_CUDA_HOME`) for the real `libnc_cuda.dll`/`libnc_cuda.so` backend built from `src/libnc_cuda_backend.c` on Windows or `src/libnc_cuda_backend_linux.c` on Linux, then falls back to the compatibility device
- [~] `nc_new_device` for `cuda[:index]` - routes through the CUDA loader hook and the real CUDA backend DLL, then falls back to the compatibility device path
- [x] `nc_synchronize`
- [x] `nc_new_tensor_buffer`
- [x] `nc_dup_tensor_buffer`
- [x] `nc_free_tensor_buffer`

### Tensor creation / lifecycle
- [x] `nc_new_tensor`
- [x] `nc_new_tensor_from_tensor`
- [x] `nc_new_tensor_from_tensor_nz`
- [x] `nc_new_scalar`
- [x] `nc_new_tensor_1d`
- [x] `nc_new_tensor_2d`
- [x] `nc_new_tensor_3d`
- [x] `nc_new_tensor_4d`
- [x] `nc_tensor_set_name`
- [x] `nc_dup_tensor`
- [x] `nc_free_tensor`
- [x] `nc_get_node`
- [x] `nc_slice_alias`
- [x] `nc_tensor_get_item_type`
- [x] `nc_tensor_get_data`
- [x] `nc_tensor_get_ptr`
- [x] `nc_tensor_get_dims`
- [x] `nc_tensor_get_hash`
- [x] `nc_dump_tensor`
- [x] `nc_dump_tensor_hash`
- [x] `nc_dump_dims`

### Tensor writes / reads
- [x] `nc_tensor_set_zero`
- [x] `nc_tensor_set_f32`
- [x] `nc_rnd_init`
- [x] `nc_rnd_end`
- [x] `nc_tensor_set_rnd_unif`
- [x] `nc_tensor_set_dropout`
- [x] `nc_set1_i32`
- [x] `nc_set1_i32_1d`
- [x] `nc_set1_i32_2d`
- [x] `nc_set1_f32`
- [x] `nc_set1_f32_1d`
- [x] `nc_get1_i32`
- [x] `nc_get1_f32`
- [x] `nc_get1_f32_1d`
- [x] `nc_get_scalar_f32`
- [x] `nc_tensor_copy`
- [x] `nc_tensor_convert`
- [x] `nc_get_heap_size`
- [x] `nc_get_tensor_context`
- [x] `nc_get_tensor_device`
- [x] `nc_tensor_to_device`
- [x] `nc_tensor_to_cpu_device`
- [x] `nc_convert`

### Element-wise ops
- [x] `nc_add`
- [x] `nc_neg`
- [x] `nc_sub`
- [x] `nc_mul`
- [x] `nc_div`
- [x] `nc_recip`
- [x] `nc_min`
- [x] `nc_max`
- [x] `nc_select`
- [x] `nc_masked_fill`
- [x] `nc_sigmoid`
- [x] `nc_tanh`
- [x] `nc_relu`
- [x] `nc_gelu`
- [x] `nc_log`
- [x] `nc_lstm_clamped`
- [x] `nc_lerp`

### Shape / layout / slicing
- [x] `nc_reshape`
- [x] `nc_reshape_1d`
- [x] `nc_reshape_2d`
- [x] `nc_reshape_3d`
- [x] `nc_reshape_4d`
- [x] `nc_repeat`
- [x] `nc_repeat_1d`
- [x] `nc_reduce_sum`
- [x] `nc_sum`
- [x] `nc_reduce_sum_sqr`
- [x] `nc_slice`
- [x] `nc_slice_add`
- [x] `nc_concat`
- [x] `nc_vconcat`
- [x] `nc_hconcat`
- [x] `nc_split`
- [x] `nc_vsplit`
- [x] `nc_hsplit`
- [x] `nc_pad`
- [x] `nc_resize`
- [x] `nc_make_contiguous`
- [x] `nc_permute_alias`
- [x] `nc_permute`
- [x] `nc_transpose`

### Linear algebra / indexed ops
- [x] `nc_matmul`
- [x] `nc_matmul_add`
- [x] `nc_matmul_stride`
- [x] `nc_get_col`
- [x] `nc_add_col`
- [x] `nc_get_element`
- [x] `nc_add_element`
- [x] `nc_soft_max`
- [x] `nc_indexed_log`
- [x] `nc_layer_norm`
- [x] `nc_rms_norm`
- [x] `nc_slt_mat_set`
- [x] `nc_rel_shift`

### Autodiff / graph / params
- [x] `nc_set_param`
- [x] `nc_stop_grad`
- [x] `nc_dup_node`
- [x] `nc_free_node`
- [~] `nc_node_set_parent` - simplified node/parent wiring compared with the original binary
- [~] `nc_node_set_arg` - simplified node/arg wiring compared with the original binary
- [x] `nc_dump_graph`
- [x] `nc_param_list_init`
- [x] `nc_param_list_set_graph`
- [x] `nc_new_param_str`
- [x] `nc_new_param`
- [x] `nc_param_list_end`
- [x] `nc_find_param`
- [x] `nc_get_param_count`
- [~] `nc_save_coefs`
- [~] `nc_load_coefs`
- [~] `nc_save_state`
- [~] `nc_load_state`

### Optimizer / misc
- [~] `nc_sgd_opt_init`
- [~] `nc_sgd_opt_end`
- [~] `nc_sgd_opt_set_all`
- [~] `nc_sgd_opt_set`
- [~] `nc_sgd_opt_update`
- [x] `nc_sgd_opt_set_lr`
- [x] `nc_sgd_opt_get_lr`
- [x] `nc_sgd_opt_get_grad`
- [~] `BF16 low_part shadow` - BF16 params keep an F32 shadow copy for optimizer updates, but this is still not a full original low-16-bit ADAM implementation.
- [x] `rnd_init`
- [x] `rnd_unif_u32`
- [x] `rnd_unif`
- [x] `rnd_unif_vec`
- [x] `rnd_unif_mat`
- [x] `vec_sum_f32`
- [x] `nc_topk`

### CUDA backend
- [x] `nc_new_cuda_device_internal` in `src/libnc_cuda_backend.c`
- [x] `nc_cuda` tensor kernels for `add` / `sub` / `mul` / `div` / `min` / `max`
- [x] `nc_cuda` tensor kernels for `neg` / `recip` / `sigmoid` / `tanh` / `relu` / `gelu` / `log`
- [x] `nc_cuda` tensor kernels for `matmul`
- [x] `nc_cuda` tensor kernels for `convert`
- [x] `nc_cuda` tensor kernels for `reduce_sum` / `reduce_sum_sqr`
- [x] `nc_cuda` tensor kernels for `soft_max`
- [x] `nc_cuda` tensor kernels for `layer_norm` / `rms_norm`
- [x] `nc_cuda` tensor kernels for `rnd_unif` / `rnd_dropout`
- [x] `nc_cuda` tensor kernels for `masked_fill`

## Partial / intentionally simplified

- [~] `nc_backward` - working and passes `nctest`, but still not a perfect 1:1 mirror of every original edge case.
- [~] `nc_combine_nodes` - basic working graph merge logic, not the full original optimizer.
- [~] `nc_concat_node` - correct for current tests, but still simplified wiring.
- [~] `nc_concat_optimization` - simplified concat optimization pass.
- [~] `nc_new_cuda_device` - CUDA support is optional, but the repo now includes a real backend DLL source and the loader still falls back cleanly when it is missing.
- [~] `nc_cuda` backend - the GPU backend is now implemented in `src/libnc_cuda_backend.c` with a Linux entry point in `src/libnc_cuda_backend_linux.c`, but it remains optional and only covers the hot tensor ops that the current tests and benchmarks need.

## Verification

- `nctest.exe -d cpu` passes and prints `all tests success`
- `matmul_test.exe` passes on the current build
- `ncspeed.exe` passes on the current build
- `own_tests.exe` passes on the current build

## Notes

- `nctest.c` is kept logically aligned with `etalon_nctest.c`; differences are limited to diagnostics and the success marker.
- Internal parallel execution exists, but it is only enabled when a context is created with `nb_threads > 1`. The default benchmark path stays single-threaded unless a caller explicitly opts in.
- If we add a real CUDA backend or expand the serialized parameter format, this checklist should be updated together with the code.
