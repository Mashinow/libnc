// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set1_i32_1d
// Included functions: 1

// ======================================================
// Function: nc_set1_i32_1d @ 0x18C30
// ======================================================

__int64 __fastcall nc_set1_i32_1d(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // [rsp+8h] [rbp-10h] BYREF

  v4 = a2;
  return nc_set1_i32(a1, 1LL, &v4, a3);
}

