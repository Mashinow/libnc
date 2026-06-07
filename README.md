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

## Build

Build the main library from the repository root:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc.dll libnc.c -Wl,--out-implib,libnc.dll.a
```

Build the CUDA backend DLL if you want GPU acceleration:

```bash
gcc -std=gnu11 -O2 -I. -shared -o libnc_cuda.dll src/libnc_cuda_backend.c -L. -lnc -Wl,--out-implib,libnc_cuda.dll.a
```

Build the tests from the repository root:

```bash
gcc -std=gnu11 -O2 -I. tests/nctest.c libnc.c -o nctest.exe
gcc -std=gnu11 -O2 -I. tests/matmul_test.c libnc.c -o matmul_test.exe
gcc -std=gnu11 -O2 -I. tests/ncspeed.c libnc.c -o ncspeed.exe
gcc -std=gnu11 -O2 -I. tests/own_tests.c libnc.c -o own_tests.exe
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
