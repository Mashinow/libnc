// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_nz_3d
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_nz_3d @ 0x16AB0
// ======================================================

__int64 __fastcall nc_new_tensor_nz_3d(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6[5]; // [rsp+0h] [rbp-28h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  v6[2] = a5;
  return nc_new_tensor_nz(a1, a2, 3LL, v6);
}

