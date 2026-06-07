// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_get_ptr
// Included functions: 1

// ======================================================
// Function: nc_tensor_get_ptr @ 0x66A153E0
// ======================================================

__int64 __fastcall nc_tensor_get_ptr(__int64 a1, _QWORD *a2)
{
  if ( a2 )
    *a2 = *(_QWORD *)(a1 + 64);
  return *(_QWORD *)(a1 + 56);
}

