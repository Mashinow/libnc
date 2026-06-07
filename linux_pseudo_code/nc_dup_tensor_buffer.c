// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dup_tensor_buffer
// Included functions: 1

// ======================================================
// Function: nc_dup_tensor_buffer @ 0x16430
// ======================================================

__int64 __fastcall nc_dup_tensor_buffer(__int64 a1)
{
  __int64 result; // rax

  result = a1;
  ++*(_DWORD *)(a1 + 16);
  return result;
}

