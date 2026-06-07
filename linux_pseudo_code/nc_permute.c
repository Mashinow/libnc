// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_permute
// Included functions: 1

// ======================================================
// Function: nc_permute @ 0x21C30
// ======================================================

__int64 __fastcall nc_permute(void *a1)
{
  void *v1; // rax

  v1 = (void *)nc_permute_alias(a1);
  return nc_make_contiguous(v1);
}

