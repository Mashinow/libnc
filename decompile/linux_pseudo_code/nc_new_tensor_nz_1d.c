// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_nz_1d
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_nz_1d @ 0x16A70
// ======================================================

__int64 __fastcall nc_new_tensor_nz_1d(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // [rsp+8h] [rbp-10h] BYREF

  v4 = a3;
  return nc_new_tensor_nz(a1, a2, 1LL, &v4);
}

