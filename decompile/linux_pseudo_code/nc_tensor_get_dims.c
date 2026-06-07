// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_get_dims
// Included functions: 1

// ======================================================
// Function: nc_tensor_get_dims @ 0x16D50
// ======================================================

__int64 __fastcall nc_tensor_get_dims(__int64 a1, _DWORD *a2)
{
  if ( a2 )
    *a2 = *(_DWORD *)(a1 + 80);
  return a1 + 120;
}

