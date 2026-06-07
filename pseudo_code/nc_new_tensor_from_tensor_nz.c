// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_from_tensor_nz
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_from_tensor_nz @ 0x66A14CA0
// ======================================================

_QWORD *__fastcall nc_new_tensor_from_tensor_nz(__int64 a1)
{
  return nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
}

