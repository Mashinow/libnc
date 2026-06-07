// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_convert
// Included functions: 2

// ======================================================
// Function: nc_convert @ 0x1B490
// ======================================================

_QWORD *__fastcall nc_convert(_QWORD *ptr, __int64 a2)
{
  _QWORD *v2; // rbp
  _QWORD *v3; // rax
  __int64 v5[4]; // [rsp+8h] [rbp-20h] BYREF

  v2 = ptr;
  if ( *((_DWORD *)ptr + 12) != (_DWORD)a2 )
  {
    v2 = (_QWORD *)nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), a2, *((unsigned int *)ptr + 20), ptr + 15);
    nc_tensor_convert(v2, ptr);
    v5[0] = (__int64)ptr;
    v3 = sub_17800(2, v2 + 3, (void **)v2 + 4, (__int64)v5);
    if ( v3 )
      *((_DWORD *)v3 + 14) = *((_DWORD *)ptr + 12);
    nc_free_tensor(ptr);
  }
  return v2;
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

