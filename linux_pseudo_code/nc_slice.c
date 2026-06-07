// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_slice
// Included functions: 2

// ======================================================
// Function: nc_slice @ 0x20C90
// ======================================================

__int64 __fastcall nc_slice(_QWORD *ptr, unsigned int a2, __int64 a3)
{
  void *v4; // rax
  __int64 contiguous; // r12
  _QWORD *v6; // rax
  __int64 v8[6]; // [rsp+8h] [rbp-30h] BYREF

  v4 = (void *)nc_slice_alias(ptr, a2);
  v8[0] = (__int64)ptr;
  contiguous = nc_make_contiguous(v4);
  v6 = sub_17800(15, (__int64 *)(contiguous + 24), (void **)(contiguous + 32), (__int64)v8);
  if ( v6 )
  {
    *((_DWORD *)v6 + 14) = a2;
    v6[8] = a3;
    v6[9] = ptr[(int)a2 + 15];
  }
  nc_free_tensor(ptr);
  return contiguous;
}

// ======================================================
// Function: sub_17800 @ 0x17800
// ======================================================

_QWORD *__fastcall sub_17800(int a1, __int64 *a2, void **a3, __int64 a4)
{
  __int64 *v7; // rax
  __int64 v8; // rbp
  __int64 *v9; // r14
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rax

  if ( !*(_QWORD *)(*(_QWORD *)a4 + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(8uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*(_QWORD *)a4 + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 1;
  v12 = (_QWORD *)nc_malloc(8uLL);
  v13 = *v9;
  v11[4] = v12;
  if ( v13 )
    *v12 = nc_dup_node();
  else
    *v12 = 0LL;
  v14 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v14 + 1;
  v11[12] = v14;
  v15 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v15 + 8) = v11;
  *v11 = v15;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

