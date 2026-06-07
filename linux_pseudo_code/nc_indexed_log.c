// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_indexed_log
// Included functions: 2

// ======================================================
// Function: nc_indexed_log @ 0x23B60
// ======================================================

__int64 __fastcall nc_indexed_log(void *ptr, void *a2)
{
  void *v2; // rbx
  void *v3; // rax
  void *element; // rax
  __int64 v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // r13
  _QWORD *v8; // rax
  void *v10; // [rsp+8h] [rbp-30h] BYREF

  v2 = (void *)nc_dup_tensor(a2);
  v3 = (void *)nc_dup_tensor(ptr);
  element = (void *)nc_get_element(v3, v2);
  v10 = ptr;
  v5 = nc_log(element);
  v6 = sub_17800(19, (__int64 *)(v5 + 24), (void **)(v5 + 32), (__int64)&v10);
  if ( v6 )
  {
    *((_DWORD *)v6 + 10) = 1;
    v7 = v6;
    v8 = (_QWORD *)nc_malloc(8uLL);
    v7[6] = v8;
    *v8 = nc_dup_tensor(a2);
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v5;
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

