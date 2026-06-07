// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_div
// Included functions: 1

// ======================================================
// Function: nc_div @ 0x66A20CA0
// ======================================================

_QWORD *__fastcall nc_div(__int64 a1, __int64 a2)
{
  _QWORD *v3; // rax

  v3 = nc_recip(a2);
  return nc_mul(a1, (__int64)v3);
}

