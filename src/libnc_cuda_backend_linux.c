/*
 * Linux entry point for the CUDA backend shared library.
 *
 * This file intentionally stays small and pulls in the platform-neutral
 * backend implementation from libnc_cuda_backend.c, which now supports
 * both Windows and Linux loader/runtime discovery.
 */

#define LIBNC_CUDA_BACKEND_LINUX 1
#include "libnc_cuda_backend.c"
