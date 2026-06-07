// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_make_contiguous
// Included functions: 1

// ======================================================
// Function: nc_make_contiguous @ 0x66A1AA40
// ======================================================

_QWORD *__fastcall nc_make_contiguous(__int64 a1)
{
  _QWORD *v3; // rsi
  __int64 v4; // rdx

  if ( *(_BYTE *)(a1 + 72) )
    return (_QWORD *)a1;
  v3 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), *(_DWORD *)(a1 + 48), *(_DWORD *)(a1 + 80), a1 + 120);
  nc_tensor_copy((__int64)v3, a1);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    ++*(_DWORD *)(v4 + 16);
    v3[4] = v4;
  }
  nc_free_tensor((_DWORD *)a1);
  return v3;
}

