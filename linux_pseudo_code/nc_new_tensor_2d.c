// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_2d
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_2d @ 0x16BF0
// ======================================================

__int64 __fastcall nc_new_tensor_2d(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5[3]; // [rsp+0h] [rbp-18h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  return nc_new_tensor(a1, a2, 2LL, v5);
}

