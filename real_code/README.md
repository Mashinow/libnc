# real_code layout

- `libnc_impl.c` - current main implementation moved out of the repository root.
- `libnc_extra.c` - small missing API additions that are easier to keep separate.
- `libnc_device_helpers.c` - device constructors and compatibility helpers.
- `libnc_graph_helpers.c` - graph node helpers for concat/merge logic.
- `libnc_param_io.c` - parameter save/load helpers and file format handling.

Planned next split:
- `libnc_runtime.c`
- `libnc_tensor.c`
- `libnc_ops.c`
- `libnc_graph.c`
- `libnc_params.c`
- `libnc_misc.c`
