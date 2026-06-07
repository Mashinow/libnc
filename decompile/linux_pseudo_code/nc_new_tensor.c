// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor
// Included functions: 1

// ======================================================
// Function: nc_new_tensor @ 0x16AE0
// ======================================================

__int64 __fastcall nc_new_tensor(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbx

  v4 = nc_new_tensor_nz(a1, a2, a3, a4);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(a1 + 104))(
    a1,
    *(_QWORD *)(v4 + 56),
    0LL,
    *(_QWORD *)(*(_QWORD *)(v4 + 40) + 48LL),
    0LL);
  return v4;
}

