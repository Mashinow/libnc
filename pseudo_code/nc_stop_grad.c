// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_stop_grad
// Included functions: 1

// ======================================================
// Function: nc_stop_grad @ 0x66A19D00
// ======================================================

_QWORD *__fastcall nc_stop_grad(__int64 a1)
{
  __int64 *v2; // rcx
  _QWORD *v3; // rsi

  v2 = *(__int64 **)(a1 + 32);
  if ( !v2 )
    return (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    nc_free_node(v2);
    *(_QWORD *)(a1 + 32) = 0i64;
    return (_QWORD *)a1;
  }
  else
  {
    v3 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
    nc_tensor_copy((__int64)v3, a1);
    nc_free_tensor((_DWORD *)a1);
    return v3;
  }
}

