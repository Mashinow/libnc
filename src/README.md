# src layout

This directory contains the maintained implementation split out of the repository root.

## Modules

- `libnc_impl.c` - main implementation and public API entry points.
- `libnc_internal.h` - internal types, helper prototypes, and cross-module declarations.
- `libnc_parallel.c` - internal worker-pool and `parallel_for` helper.
- `libnc_device_helpers.c` - device construction and compatibility helpers.
- `libnc_cuda_loader.c` - optional external CUDA DLL/SO loader hook.
- `libnc_cuda_backend.c` - real CUDA backend source that exports `nc_new_cuda_device_internal`.
- `libnc_graph_helpers.c` - graph merge / concat helpers.
- `libnc_param_io.c` - parameter/state save-load helpers.

## Current status

- The shipped tests in `tests/nctest.c` pass on the current build and print `all tests success`.
- `tests/matmul_test.c`, `tests/ncspeed.c`, and `tests/own_tests.c` also pass on the current build.
- `tests/nctest.c` is logically aligned with `decompile/etalon_nctest.c`; the differences are diagnostic logging and the explicit success marker.
- `tests/own_tests.c` now benchmarks actual CUDA tensor ops through `libnc_cuda.dll`; on the current machine, `matmul` shows a clear speedup while `add` remains mostly transfer-bound.
- The runtime has an internal worker pool, but it is only enabled when a context is created with `nb_threads > 1`. The default benchmark path stays single-threaded unless a caller explicitly asks for parallelism.
- BF16 parameters keep an internal F32 shadow copy during optimizer updates so the update path can preserve more precision than a raw BF16 in-place step.
- The original binary exposes a job-based parallel layer with pthread primitives; this implementation follows the same spirit with an internal worker pool, but it is still CPU-only.
- `nc_new_cuda_device()` searches the executable directory, `PATH`, and CUDA environment variables for `libnc_cuda.dll` or `libnc_cuda.so`, and preloads CUDA runtime libraries by filename pattern rather than by versioned names. The Windows loader also honors `LIBNC_CUDA_DLL`, `LIBNC_CUDA_DIR`, and `LIBNC_CUDA_HOME` overrides when present.
## Notes

- Keep `#include` directives at the top of files.
- Keep public API behavior aligned with `pseudo_code/` unless the pseudocode is clearly broken. In that case, prefer a logically correct implementation.
- When you change runtime behavior, update both this README and `IMPLEMENTATION_CHECKLIST.md`.
- The repository has been validated on Windows 10 so far; Linux/WSL support is being checked separately.
