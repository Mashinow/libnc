// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_convert
// Included functions: 1

// ======================================================
// Function: nc_convert @ 0x66A1A3E0
// ======================================================

_QWORD *__fastcall nc_convert(__int64 a1, unsigned int a2)
{
  _QWORD *v3; // rbp
  __int64 *v5; // rax
  __int64 v6; // r12
  __int64 *v7; // r14
  _QWORD *v8; // rbx
  _QWORD *v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 *v13; // rcx
  int v14; // eax

  if ( *(_DWORD *)(a1 + 48) == a2 )
    return (_QWORD *)a1;
  v3 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), a2, *(_DWORD *)(a1 + 80), a1 + 120);
  nc_tensor_convert((__int64)v3, a1);
  if ( *(_QWORD *)(a1 + 32) )
  {
    v5 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v6 = v3[3];
    v7 = v5;
    *v5 = *(_QWORD *)(a1 + 32);
    v8 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v8 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v8, 0, 0x80ui64);
    *((_DWORD *)v8 + 4) = 1;
    *((_DWORD *)v8 + 5) = 2;
    *((_DWORD *)v8 + 6) = 1;
    v9 = aligned_malloc(8ui64, 0x40ui64);
    v10 = *v7;
    v8[4] = v9;
    if ( v10 )
    {
      ++*(_DWORD *)(v10 + 16);
      *v9 = v10;
    }
    else
    {
      *v9 = 0i64;
    }
    v11 = *(_QWORD *)(v6 + 72);
    *(_QWORD *)(v6 + 72) = v11 + 1;
    v8[12] = v11;
    v12 = *(_QWORD *)(v6 + 32);
    *(_QWORD *)(v12 + 8) = v8;
    *v8 = v12;
    v8[1] = v6 + 32;
    *(_QWORD *)(v6 + 32) = v8;
    _aligned_free(v7);
    v13 = (__int64 *)v3[4];
    if ( v13 )
      nc_free_node(v13);
    v14 = *(_DWORD *)(a1 + 48);
    v3[4] = v8;
    *((_DWORD *)v8 + 14) = v14;
  }
  nc_free_tensor((_DWORD *)a1);
  return v3;
}

