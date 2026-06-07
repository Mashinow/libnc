// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_to_cpu_device
// Included functions: 1

// ======================================================
// Function: nc_tensor_to_cpu_device @ 0x66A18C30
// ======================================================

_QWORD *__fastcall nc_tensor_to_cpu_device(__int64 a1)
{
  __int64 v2; // rcx
  _QWORD *v3; // rsi
  __int64 v4; // rax

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 64i64);
  v3 = (_QWORD *)a1;
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64) )
  {
    v3 = nc_new_tensor_nz(v2, *(_DWORD *)(a1 + 48), *(_DWORD *)(a1 + 80), a1 + 120);
    nc_tensor_copy((__int64)v3, a1);
    v4 = *(_QWORD *)(a1 + 32);
    if ( v4 )
    {
      ++*(_DWORD *)(v4 + 16);
      v3[4] = v4;
    }
    nc_free_tensor((_DWORD *)a1);
  }
  return v3;
}

