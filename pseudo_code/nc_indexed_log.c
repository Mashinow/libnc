// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_indexed_log
// Included functions: 1

// ======================================================
// Function: nc_indexed_log @ 0x66A28330
// ======================================================

_QWORD *__fastcall nc_indexed_log(__int64 a1, _DWORD *a2)
{
  _QWORD *element; // rax
  _QWORD *v5; // r13
  __int64 *v7; // rax
  __int64 v8; // r12
  __int64 *v9; // r15
  _QWORD *v10; // rbx
  _QWORD *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 *v15; // rcx
  _QWORD *v16; // rax

  ++a2[4];
  ++*(_DWORD *)(a1 + 16);
  element = nc_get_element(a1, (__int64)a2);
  v5 = nc_log((__int64)element);
  if ( *(_QWORD *)(a1 + 32) )
  {
    v7 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v8 = v5[3];
    v9 = v7;
    *v7 = *(_QWORD *)(a1 + 32);
    v10 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v10 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v10, 0, 0x80ui64);
    *((_DWORD *)v10 + 4) = 1;
    *((_DWORD *)v10 + 5) = 19;
    *((_DWORD *)v10 + 6) = 1;
    v11 = aligned_malloc(8ui64, 0x40ui64);
    v12 = *v9;
    v10[4] = v11;
    if ( v12 )
    {
      ++*(_DWORD *)(v12 + 16);
      *v11 = v12;
    }
    else
    {
      *v11 = 0i64;
    }
    v13 = *(_QWORD *)(v8 + 72);
    *(_QWORD *)(v8 + 72) = v13 + 1;
    v10[12] = v13;
    v14 = *(_QWORD *)(v8 + 32);
    *(_QWORD *)(v14 + 8) = v10;
    *v10 = v14;
    v10[1] = v8 + 32;
    *(_QWORD *)(v8 + 32) = v10;
    _aligned_free(v9);
    v15 = (__int64 *)v5[4];
    if ( v15 )
      nc_free_node(v15);
    v5[4] = v10;
    *((_DWORD *)v10 + 10) = 1;
    v16 = aligned_malloc(8ui64, 0x40ui64);
    v10[6] = v16;
    ++a2[4];
    *v16 = a2;
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor(a2);
  return v5;
}

