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

For the current detailed status, see [IMPLEMENTATION_CHECKLIST.md](/F:/source/repos/libnc/IMPLEMENTATION_CHECKLIST.md).

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
