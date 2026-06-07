// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_from_tensor
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_from_tensor @ 0x66A14C50
// ======================================================

_QWORD *__fastcall nc_new_tensor_from_tensor(__int64 a1)
{
  __int64 v1; // rsi
  _QWORD *v2; // rbx

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v2 = nc_new_tensor_nz(v1, *(_DWORD *)(a1 + 48), *(_DWORD *)(a1 + 80), a1 + 120);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(v1 + 104))(
    v1,
    v2[7],
    0i64,
    *(_QWORD *)(v2[5] + 48i64),
    0);
  return v2;
}

