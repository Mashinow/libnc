# libnc reconstruction

This repository is a clean-room reconstruction of `libnc` based on the public header file and decompiled pseudocode. The original project was created by Fabrice Bellard, and the original rights remain with him.

## Project facts

- `src/` contains the maintained implementation split into logical source files.
- `tests/` contains the shipped regression and benchmark programs.
- `decompile/` contains the reverse-engineering references used during reconstruction.
- `libnc.c` is the single translation-unit entry point used to build the main library.
- `doc/libnc.md` is the main documentation for the project.

## Current status

- The core CPU tensor API is implemented and the shipped Windows tests pass on the current build.
- An optional CUDA backend source exists and is loaded through a portable runtime hook when available.
- Some graph-optimization, serialization, and optimizer edge cases are still documented as partial in the implementation checklist.

## Documentation

Read the main documentation here:

- [doc/libnc.md](./doc/libnc.md)
