// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_resize
// Included functions: 1

// ======================================================
// Function: nc_resize @ 0x21A90
// ======================================================

__int64 __fastcall nc_resize(int *a1)
{
  if ( a1[20] <= 0 )
    __assert_fail("x->n_dims >= 1", "libnc.c", 0x1946u, "nc_resize");
  return nc_pad(a1);
}

