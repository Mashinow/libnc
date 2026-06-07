# libnc implementation checklist

Статус ниже относится к текущему состоянию `libnc.c` и файлов в `real_code/`.

## Реализовано

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
- [x] `nc_new_device` для `cpu`
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
- [x] `nc_node_set_parent`
- [x] `nc_node_set_arg`
- [x] `nc_dump_graph`
- [x] `nc_param_list_init`
- [x] `nc_param_list_set_graph`
- [x] `nc_new_param_str`
- [x] `nc_new_param`
- [x] `nc_param_list_end`
- [x] `nc_find_param`
- [x] `nc_get_param_count`
- [x] `nc_save_coefs`
- [x] `nc_load_coefs`
- [x] `nc_save_state`
- [x] `nc_load_state`

### Optimizer / misc
- [x] `nc_sgd_opt_init`
- [x] `nc_sgd_opt_end`
- [x] `nc_sgd_opt_set_all`
- [x] `nc_sgd_opt_set`
- [x] `nc_sgd_opt_update`
- [x] `nc_sgd_opt_set_lr`
- [x] `nc_sgd_opt_get_lr`
- [x] `nc_sgd_opt_get_grad`
- [x] `rnd_init`
- [x] `rnd_unif_u32`
- [x] `rnd_unif`
- [x] `rnd_unif_vec`
- [x] `rnd_unif_mat`
- [x] `vec_sum_f32`
- [x] `nc_topk`

## Частично реализовано

- [~] `nc_new_cuda_device` - логически исправлена: создает compat-устройство `cuda:<index>` вместо буквального `return NULL` из сломанного псевдокода.
- [~] `nc_new_device` - поддерживает `cpu` и `cuda[:index]`; ветка `cuda` направляется в compat-реализацию.
- [~] `nc_combine_nodes` - текущая логика еще не перенесена из псевдокода полностью.
- [~] `nc_concat_node` - текущая логика еще не перенесена из псевдокода полностью.
- [~] `nc_concat_optimization` - текущая логика еще не перенесена из псевдокода полностью.
- [~] `nc_node_set_parent` - адаптировано под текущую структуру, но еще не зеркалит псевдокод byte-for-byte.
- [~] `nc_node_set_arg` - адаптировано под текущую структуру, но еще не зеркалит псевдокод byte-for-byte.
- [~] `nc_backward` - уже не заглушка, но не весь оригинальный набор покрыт.
- [~] `nc_save_coefs` / `nc_load_coefs` / `nc_save_state` / `nc_load_state` - формат уже ближе к псевдокоду, но еще без полного покрытия всех крайних случаев оригинала.
- [~] `nc_sgd_opt_init` / `nc_sgd_opt_set` / `nc_sgd_opt_update` - рабочий SGD-каркас, но без полного набора алгоритмов оригинала.

## Примечание

- Внутренние helpers в `real_code/` не перечисляются отдельно, если они не объявлены в `libnc.h`.
- Если добавим полноценный CUDA backend, чеклист нужно обновить снова.
