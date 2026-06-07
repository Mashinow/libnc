// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_div
// Included functions: 1

// ======================================================
// Function: nc_div @ 0x1EC70
// ======================================================

__int64 __fastcall nc_div(void *ptr, void *a2)
{
  void *v2; // rax

  v2 = (void *)nc_recip(a2);
  return nc_mul(ptr, v2);
}

