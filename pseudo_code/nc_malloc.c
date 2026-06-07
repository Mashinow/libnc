// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_malloc
// Included functions: 1

// ======================================================
// Function: nc_malloc @ 0x66A10620
// ======================================================

void *__fastcall nc_malloc(size_t a1)
{
  return aligned_malloc(a1, 0x40ui64);
}

