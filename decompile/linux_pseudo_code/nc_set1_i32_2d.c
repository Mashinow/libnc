// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set1_i32_2d
// Included functions: 1

// ======================================================
// Function: nc_set1_i32_2d @ 0x18C60
// ======================================================

__int64 __fastcall nc_set1_i32_2d(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[0] = a2;
  v5[1] = a3;
  return nc_set1_i32(a1, 2LL, v5, a4);
}

