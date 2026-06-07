// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_malloc
// Included functions: 1

// ======================================================
// Function: nc_malloc @ 0x11200
// ======================================================

void *__fastcall nc_malloc(size_t size)
{
  bool v1; // zf
  void *result; // rax
  void *memptr; // [rsp+8h] [rbp-10h] BYREF

  v1 = posix_memalign(&memptr, 0x40uLL, size) == 0;
  result = 0LL;
  if ( v1 )
    return memptr;
  return result;
}

