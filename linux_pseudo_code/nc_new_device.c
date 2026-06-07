// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_device
// Included functions: 1

// ======================================================
// Function: nc_new_device @ 0x16280
// ======================================================

__int64 __fastcall nc_new_device(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)a2 == 99 && *(_BYTE *)(a2 + 1) == 112 && *(_BYTE *)(a2 + 2) == 117 && !*(_BYTE *)(a2 + 3) )
    return nc_new_cpu_device();
  if ( !strcmp((const char *)a2, "cuda") )
    return nc_new_cuda_device(a1, 0);
  return 0LL;
}

