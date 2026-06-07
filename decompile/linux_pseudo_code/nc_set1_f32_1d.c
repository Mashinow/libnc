// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set1_f32_1d
// Included functions: 1

// ======================================================
// Function: nc_set1_f32_1d @ 0x18C10
// ======================================================

__int64 __fastcall nc_set1_f32_1d(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+8h] [rbp-10h] BYREF

  v3 = a2;
  return nc_set1_f32(a1, 1LL, &v3);
}

