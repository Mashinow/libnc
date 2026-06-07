// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sub
// Included functions: 1

// ======================================================
// Function: nc_sub @ 0x66A1FD00
// ======================================================

__int64 __fastcall nc_sub(__int64 a1, __int64 a2)
{
  _QWORD *v3; // rax

  v3 = nc_neg(a2);
  return nc_add(a1, (__int64)v3);
}

