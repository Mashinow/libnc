# real_code layout

This directory contains the maintained implementation split out of the repository root.

## Modules

- `libnc_impl.c` - main implementation and public API entry points.
- `libnc_internal.h` - internal types, helper prototypes, and cross-module declarations.
- `libnc_parallel.c` - internal worker-pool and `parallel_for` helper.
- `libnc_device_helpers.c` - device construction and compatibility helpers.
- `libnc_graph_helpers.c` - graph merge / concat helpers.
- `libnc_param_io.c` - parameter/state save-load helpers.

## Current status

- The shipped tests in `nctest.c` pass on the current build and print `all tests success`.
- `matmul_test.c`, `ncspeed.c`, and `own_tests.c` also pass on the current build.
- `nctest.c` is logically aligned with `etalon_nctest.c`; the differences are diagnostic logging and the explicit success marker.
- The runtime has an internal worker pool, but it is only enabled when a context is created with `nb_threads > 1`. The default benchmark path stays single-threaded unless a caller explicitly asks for parallelism.
- BF16 parameters keep an internal F32 shadow copy during optimizer updates so the update path can preserve more precision than a raw BF16 in-place step.
- The original binary exposes a job-based parallel layer with pthread primitives; this implementation follows the same spirit with an internal worker pool, but it is still CPU-only.

## Build

Build from the repository root so includes resolve correctly:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc.dll libnc.c -Wl,--out-implib,libnc.dll.a
```

## Notes

- Keep `#include` directives at the top of files.
- Keep public API behavior aligned with `pseudo_code/` unless the pseudocode is clearly broken. In that case, prefer a logically correct implementation.
- When you change runtime behavior, update both this README and `IMPLEMENTATION_CHECKLIST.md`.
