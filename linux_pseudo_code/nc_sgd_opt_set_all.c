// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sgd_opt_set_all
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_set_all @ 0x2E6C0
// ======================================================

__int64 __fastcall nc_sgd_opt_set_all(__int64 a1, __int64 a2)
{
  __int64 i; // rbx
  __int64 result; // rax

  for ( i = *(_QWORD *)(a1 + 8); i != a1; i = *(_QWORD *)(i + 8) )
    result = nc_sgd_opt_set(i, a2);
  return result;
}

