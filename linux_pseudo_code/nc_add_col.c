// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_add_col
// Included functions: 2

// ======================================================
// Function: nc_add_col @ 0x22960
// ======================================================

_QWORD *__fastcall nc_add_col(_QWORD *ptr, _QWORD *a2, _QWORD *a3)
{
  __int64 v4; // r14
  __int64 v5; // rax
  _QWORD *v6; // r13
  _QWORD *v7; // rax
  _QWORD *v8; // r14
  _QWORD *v9; // rax
  __int64 v11[9]; // [rsp+0h] [rbp-48h] BYREF

  v4 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v4 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( v4 != *(_QWORD *)(a3[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( *((_DWORD *)a2 + 12) != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_add_col");
  if ( *((_DWORD *)ptr + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_add_col");
  if ( *((_DWORD *)a2 + 20) != 1 )
    __assert_fail("x->n_dims == 1", "libnc.c", 0x1A6Du, "nc_add_col");
  if ( !*((_BYTE *)a2 + 73) )
    __assert_fail("x->contig[0]", "libnc.c", 0x1A6Eu, "nc_add_col");
  if ( *((_DWORD *)ptr + 20) != 2 )
    __assert_fail("z->n_dims == 2", "libnc.c", 0x1A6Fu, "nc_add_col");
  if ( ptr[16] != a2[15] )
    __assert_fail("z->dims[1] == x->dims[0]", "libnc.c", 0x1A70u, "nc_add_col");
  if ( *((_DWORD *)a3 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_add_col");
  if ( *((_DWORD *)a3 + 20) != 2 )
    __assert_fail("w->n_dims == 2", "libnc.c", 0x1A73u, "nc_add_col");
  v5 = a3[15];
  if ( v5 != ptr[15] )
    __assert_fail("w->dims[0] == z->dims[0]", "libnc.c", 0x1A74u, "nc_add_col");
  v6 = a3;
  if ( *((_DWORD *)a3 + 4) != 1 )
  {
    v6 = (_QWORD *)nc_new_tensor_nz(*(_QWORD *)(a3[5] + 24LL), *((unsigned int *)a3 + 12), 2LL, a3 + 15);
    nc_tensor_copy(v6, a3);
    v5 = ptr[15];
  }
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _QWORD))(v4 + 456))(
    v4,
    v6[7],
    v6[12] >> 2,
    v6[16],
    ptr[7],
    ptr[12] >> 2,
    a2[7],
    v5,
    a2[15]);
  v11[0] = (__int64)ptr;
  v11[1] = (__int64)a3;
  v7 = sub_17590(32, v6 + 3, (void **)v6 + 4, v11);
  v8 = v7;
  if ( v7 )
  {
    *((_DWORD *)v7 + 10) = 1;
    v9 = (_QWORD *)nc_malloc(8uLL);
    v8[6] = v9;
    *v9 = nc_dup_tensor(a2);
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  if ( v6 != a3 )
    nc_free_tensor(a3);
  return v6;
}

// ======================================================
// Function: sub_17590 @ 0x17590
// ======================================================

_QWORD *__fastcall sub_17590(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  __int64 *v7; // rax
  __int64 v8; // r12
  __int64 *v9; // rbp
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  _QWORD *v14; // r14
  __int64 v15; // rax
  __int64 v16; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(0x10uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*a4 + 32LL);
  v7[1] = *(_QWORD *)(a4[1] + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 2;
  v12 = (_QWORD *)nc_malloc(0x10uLL);
  v13 = *v9;
  v14 = v12;
  v11[4] = v12;
  if ( !v13 )
  {
    *v12 = 0LL;
    if ( v9[1] )
      goto LABEL_6;
LABEL_11:
    v14[1] = 0LL;
    goto LABEL_7;
  }
  *v12 = nc_dup_node();
  v14 = (_QWORD *)v11[4];
  if ( !v9[1] )
    goto LABEL_11;
LABEL_6:
  v14[1] = nc_dup_node();
LABEL_7:
  v15 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v15 + 1;
  v11[12] = v15;
  v16 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v16 + 8) = v11;
  *v11 = v16;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

