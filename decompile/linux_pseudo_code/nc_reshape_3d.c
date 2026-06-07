// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_reshape_3d
// Included functions: 1

// ======================================================
// Function: nc_reshape_3d @ 0x1BE40
// ======================================================

__int64 __fastcall nc_reshape_3d(void *a1, char a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  char v7[8]; // [rsp+0h] [rbp-28h] BYREF
  __int64 v8; // [rsp+8h] [rbp-20h]
  __int64 v9; // [rsp+10h] [rbp-18h]

  v8 = a3;
  v9 = a4;
  return nc_reshape(a1, 3LL, (__int64)v7, a4, a5, a6, a2);
}

