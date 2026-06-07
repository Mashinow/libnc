// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_mallocz
// Included functions: 1

// ======================================================
// Function: nc_mallocz @ 0x66A10630
// ======================================================

void *__fastcall nc_mallocz(size_t Size)
{
  void *v2; // rax
  void *v3; // rbx

  v2 = aligned_malloc(Size, 0x40ui64);
  v3 = v2;
  if ( v2 )
    memset(v2, 0, Size);
  return v3;
}

