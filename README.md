# libnc reconstruction

This repository contains a clean-room style reconstruction of `libnc` made from the public header file and decompiled pseudocode. The implementation itself lives in `src/`, the shipped tests are in `tests/`, and reverse-engineering references are kept under `decompile/`.

The original `libnc` project was created by Fabrice Bellard. This repository is only a reconstruction effort based on public headers and decompiled material, and all rights to the original project remain with Fabrice Bellard.

## What is in this repo

- `libnc.c` - single translation unit entry point for the main library build.
- `libnc.h` - public API.
- `cutils.h`, `list.h` - supporting utility headers used by the public API.
- `src/` - maintained implementation split into logical source files.
- `tests/` - test programs that validate the rebuilt library.
- `decompile/` - reference material from binaries, pseudocode, and structural notes.

## Project goal

The goal of this project is to recreate the original `libnc` codebase using GPT-4-mini as a reconstruction aid, starting from:

- the public header files
- pseudocode extracted from binaries
- reference structures and etalon artifacts

The focus is on producing readable, working, and fast code that behaves correctly on the shipped tests.

## Implementation overview

The current implementation is strong in the core areas that the shipped tests exercise:

- tensor creation, copying, conversion, indexing, and layout helpers
- element-wise math, reductions, reshapes, slicing, concatenation, and permutation
- matrix multiplication, softmax, layer norm, RMS norm, and indexed tensor ops
- BF16 handling for CPU paths and optimizer shadow copies
- a working optional CUDA backend source with a portable loader path

The parts that are still intentionally simplified or only partially matched to the original binary are:

- full graph optimization and node wiring edge cases
- `nc_backward` parity for every original special case
- full serialized state/coef format compatibility in all corner cases
- the exact original SGD/ADAM behavior and all low-level CUDA backend details

For the current detailed status, see [IMPLEMENTATION_CHECKLIST.md](https://github.com/Mashinow/libnc/blob/master/IMPLEMENTATION_CHECKLIST.md).

## Documentation overview

The original LibNC manual is organized around a small set of practical topics:

- usage and supported platforms
- the main runtime concepts (`NCContext`, `NCTensor`, `NCTensorBuffer`)
- tensor layout and storage conventions
- the automatic differentiation engine
- determinism and reproducibility guarantees
- compute graph optimization for online learning
- CUDA backend behavior
- BF16 support and optimizer precision handling

The sections below summarize those ideas in the context of this reconstruction.

### Usage

LibNC is a C library that is intended to be linked as a shared library or DLL. It exposes a C API, so it can be called from C and from other languages through FFI layers.

The upstream documentation describes the original project as optimized for x86 CPUs with AVX2 support, with optional CUDA acceleration. The reconstructed code keeps that shape: the CPU path is the primary implementation, while CUDA is handled through an optional backend source and loader path.

The shipped tests in this repository are:

- `tests/nctest.c` for API and autodiff coverage
- `tests/matmul_test.c` for matrix multiplication correctness and layout checks
- `tests/ncspeed.c` for throughput and stability checks
- `tests/own_tests.c` for broader project-specific regression coverage

### Main concepts

- `NCContext` is the top-level library instance. It owns devices, runtime state, random number generators, and parallel helpers.
- `NCTensor` is the basic data object. It stores shape, item type, device association, graph links, and optional gradients.
- `NCTensorBuffer` is the underlying storage container that can be shared between tensors.

Most tensor operations expect operands to live on the same device. In practice, that means CPU tensors stay on CPU and CUDA tensors stay in the CUDA backend unless an explicit transfer is requested.

Unlike some eager frameworks, LibNC does not rely on implicit broadcasting for every operation. Shapes need to match the operation semantics defined by the API.

### Tensor layout

New tensors store contiguous elements by default. The library enumerates dimensions with the smallest dimension first, and matrices use a column-major style layout.

That means a matrix with 2 rows and 3 columns is stored as a tensor with shape `(3, 2)` in the underlying layout conventions used by the API.

This choice matters for:

- `nc_matmul` and `nc_matmul_add`
- slices and concatenation
- layout transforms like `nc_permute` and `nc_transpose`
- serialization and parameter dumps

### Automatic differentiation engine

LibNC uses define-by-run automatic differentiation. The graph is built as tensors are created and combined, and backward traversal is then performed from the output node.

Practical consequences:

- user-created tensors normally start without a graph parent
- parameter tensors are attached to the graph through helper APIs
- backward passes can be combined with graph retention when online-learning style updates are needed

The current reconstruction keeps the define-by-run shape and the shipped tests exercise both first-order gradients and Hessian-vector-product style flows.

### Determinism

The original documentation emphasizes deterministic results. That means the same computation should return the same result on the same system across runs.

This repository preserves that goal for the CPU path and keeps the random-number and reduction logic stable enough for the shipped tests.

### Reproducibility

The upstream manual distinguishes determinism from reproducibility:

- determinism is about repeated runs on the same system
- reproducibility is about getting stable results across different thread counts, CPU brands, and operating systems

The original documentation notes that the CPU backend was intended to be reproducible, while the GPU backend could differ because of hardware-specific rounding behavior. This reconstruction keeps that distinction in mind, especially around BF16 and CUDA paths.

### Compute graph optimization

The original manual describes graph optimization as a way to improve online learning throughput. The main idea is to combine sequential evaluation steps into a graph that can be executed more efficiently on the compute device.

The manual specifically mentions `nc_concat_optimization()` as the tool for that use case.

In this repository, graph optimization is present but still partially simplified compared to the upstream binary. The important user-facing behavior is preserved, but some optimizer edge cases are still documented in the implementation checklist.

### CUDA backend

The upstream documentation describes CUDA as an optional backend contained in a separate `libnc_cuda` component.

In the reconstruction:

- the CUDA backend source lives in `src/libnc_cuda_backend.c`
- backend discovery is handled by `src/libnc_cuda_loader.c`
- the loader can fall back to a compatibility path if the external backend is not available

That keeps the CPU build usable on systems without a CUDA installation, while still allowing a real CUDA backend to be used when present.

### BF16 support

BF16 is a 16-bit truncated float format used to reduce memory bandwidth and storage costs while preserving much of the numerical range of float32.

The original documentation says BF16 is supported on both CPU and GPU backends, and that the ADAM optimizer keeps the low 16 bits of parameters so the update path does not lose precision.

This reconstruction follows the same general idea:

- BF16 tensors are handled on the CPU path
- BF16 parameters keep an internal float32 shadow copy for optimizer updates
- the checklist marks the BF16 path as functional but not a literal byte-for-byte clone of the original low-level optimizer implementation

### License note

The upstream manual states that the library was free to use as a binary shared library and that source access was controlled by the original author.

This repository is not the upstream source tree. It is a reconstruction effort, and the original project remains attributed to Fabrice Bellard.

## Build

Build the main library from the repository root:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc.dll libnc.c -Wl,--out-implib,libnc.dll.a
```

On Linux or WSL, build the shared object instead:

```bash
gcc -std=gnu11 -O2 -fPIC -I. -shared -o libnc.so libnc.c -lpthread -ldl -lm
```

Build the CUDA backend DLL if you want GPU acceleration:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc_cuda.dll src/libnc_cuda_backend.c -L. -lnc -Wl,--out-implib,libnc_cuda.dll.a
```

On Linux or WSL, build the CUDA backend shared object instead:

```bash
gcc -std=gnu11 -O2 -fPIC -I. -shared -o libnc_cuda.so src/libnc_cuda_backend.c -L. -lnc -lpthread -ldl -lm
```

Build the tests from the repository root:

```bash
gcc -std=gnu11 -O2 -I. tests/nctest.c libnc.c -o nctest.exe
gcc -std=gnu11 -O2 -I. tests/matmul_test.c libnc.c -o matmul_test.exe
gcc -std=gnu11 -O2 -I. tests/ncspeed.c libnc.c -o ncspeed.exe
gcc -std=gnu11 -O2 -I. tests/own_tests.c libnc.c -o own_tests.exe
```

On Linux or WSL, use the shared object and pthread/dl/libm links:

```bash
gcc -std=gnu11 -O2 -I. tests/nctest.c libnc.c -o nctest -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/matmul_test.c libnc.c -o matmul_test -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/ncspeed.c libnc.c -o ncspeed -lpthread -ldl -lm
gcc -std=gnu11 -O2 -I. tests/own_tests.c libnc.c -o own_tests -lpthread -ldl -lm
```

## Verification

- `tests/nctest.c` should print `all tests success`
- `tests/matmul_test.c` should print `all tests success`
- `tests/ncspeed.c` should print `all tests success`
- `tests/own_tests.c` should print `all tests success`
- The repository has been validated on Windows 10 so far; Linux/WSL support is being checked separately.

## Notes

- Keep `#include` directives at the top of source files.
- Keep `decompile/` out of release archives.
- If you change runtime behavior, update `src/README.md` and `IMPLEMENTATION_CHECKLIST.md` together with the code.
