// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_transpose
// Included functions: 1

// ======================================================
// Function: nc_transpose @ 0x21C50
// ======================================================

__int64 __fastcall nc_transpose(__int64 a1)
{
  __int64 v1; // rsi
  int v3[6]; // [rsp+0h] [rbp-18h] BYREF

  v1 = *(unsigned int *)(a1 + 80);
  if ( (int)v1 <= 1 )
    __assert_fail("x->n_dims >= 2", "libnc.c", 0x1975u, "nc_transpose");
  v3[0] = 1;
  v3[1] = 0;
  if ( (_DWORD)v1 != 2 )
  {
    v3[2] = 2;
    if ( (_DWORD)v1 != 3 )
      v3[3] = 3;
  }
  return nc_permute(a1, v1, v3);
}

