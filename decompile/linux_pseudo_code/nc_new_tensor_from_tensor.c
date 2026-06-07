// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_from_tensor
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_from_tensor @ 0x16B20
// ======================================================

__int64 __fastcall nc_new_tensor_from_tensor(__int64 a1)
{
  return nc_new_tensor(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL),
           *(unsigned int *)(a1 + 48),
           *(unsigned int *)(a1 + 80),
           a1 + 120);
}

