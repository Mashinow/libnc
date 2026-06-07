// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_get_col
// Included functions: 2

// ======================================================
// Function: nc_get_col @ 0x22790
// ======================================================

__int64 __fastcall nc_get_col(_QWORD *ptr, _QWORD *a2)
{
  __int64 v2; // r13
  __int64 v3; // r12
  unsigned int v4; // r8d
  _QWORD *v5; // rax
  _QWORD *v6; // r13
  _QWORD *v7; // rax
  __int64 v9[6]; // [rsp+8h] [rbp-30h] BYREF

  v2 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v2 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( *((_DWORD *)a2 + 12) != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_get_col");
  if ( *((_DWORD *)ptr + 20) != 2 )
    __assert_fail("w->n_dims == 2", "libnc.c", 0x1A49u, "nc_get_col");
  if ( *((_DWORD *)a2 + 20) != 1 )
    __assert_fail("x->n_dims == 1", "libnc.c", 0x1A4Au, "nc_get_col");
  if ( !*((_BYTE *)a2 + 73) )
    __assert_fail("x->contig[0]", "libnc.c", 0x1A4Bu, "nc_get_col");
  if ( !*((_BYTE *)ptr + 73) )
    __assert_fail("w->contig[0]", "libnc.c", 0x1A4Cu, "nc_get_col");
  v3 = nc_new_tensor_nz_2d(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), ptr[15], a2[15]);
  v4 = dword_30520[*((unsigned int *)ptr + 12)];
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))(v2 + 448))(
    v2,
    *(_QWORD *)(v3 + 56),
    *(_QWORD *)(v3 + 96) >> v4,
    ptr[7],
    ptr[12] >> v4,
    *((unsigned int *)ptr + 32),
    a2[7],
    ptr[15],
    a2[15],
    v4);
  v9[0] = (__int64)ptr;
  v5 = sub_17800(31, (__int64 *)(v3 + 24), (void **)(v3 + 32), (__int64)v9);
  v6 = v5;
  if ( v5 )
  {
    *((_DWORD *)v5 + 10) = 1;
    v7 = (_QWORD *)nc_malloc(8uLL);
    v6[6] = v7;
    *v7 = nc_dup_tensor(a2);
    v6[7] = ptr[16];
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v3;
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

