// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dup_tensor
// Included functions: 1

// ======================================================
// Function: nc_dup_tensor @ 0x166B0
// ======================================================

__int64 __fastcall nc_dup_tensor(__int64 a1)
{
  __int64 result; // rax

  result = a1;
  ++*(_DWORD *)(a1 + 16);
  return result;
}

