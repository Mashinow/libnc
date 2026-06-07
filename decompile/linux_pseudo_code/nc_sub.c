// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sub
// Included functions: 1

// ======================================================
// Function: nc_sub @ 0x1DE50
// ======================================================

__int64 __fastcall nc_sub(void *a1, void *a2)
{
  void *v2; // rax

  v2 = (void *)nc_neg(a2);
  return nc_add(a1, v2);
}

