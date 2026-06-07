// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor
// Included functions: 1

// ======================================================
// Function: nc_new_tensor @ 0x66A14C10
// ======================================================

_QWORD *__fastcall nc_new_tensor(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  _QWORD *v5; // rbx

  v5 = nc_new_tensor_nz(a1, a2, a3, a4);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(a1 + 104))(
    a1,
    v5[7],
    0i64,
    *(_QWORD *)(v5[5] + 48i64),
    0);
  return v5;
}

