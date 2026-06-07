// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_concat
// Included functions: 1

// ======================================================
// Function: nc_concat @ 0x20DF0
// ======================================================

size_t __fastcall nc_concat(void **a1, int a2, int a3)
{
  size_t v4; // rbx
  __int64 v5; // rdx
  __int64 v6; // r12
  _QWORD *v7; // r15
  __int64 v8; // rbx
  int v9; // ecx
  _QWORD *v10; // r14
  __int64 v11; // rsi
  __int64 i; // rax
  __int64 v13; // rax
  __int64 v14; // r15
  void **v15; // r14
  __int64 v16; // rbx
  void *v17; // r12
  void **v18; // r12
  void **v19; // r14
  int v20; // eax
  void **v21; // rdx
  _QWORD *v22; // rsi
  __int64 v23; // rax
  __int64 v24; // r15
  __int64 v25; // rax
  __int64 v26; // rbx
  __int64 v27; // rdi
  __int64 v28; // r13
  __int64 v29; // rax
  __int64 v30; // rax
  void *v31; // rdi
  __int64 v32; // rax
  __int64 v33; // rdx
  __int64 v34; // rax
  void *v35; // rdi
  size_t size; // [rsp+18h] [rbp-90h]
  size_t sizea; // [rsp+18h] [rbp-90h]
  __int64 sizeb; // [rsp+18h] [rbp-90h]
  size_t v42; // [rsp+28h] [rbp-80h]
  __int64 v43; // [rsp+40h] [rbp-68h]
  __int64 v44[11]; // [rsp+50h] [rbp-58h] BYREF

  if ( a2 <= 0 )
    __assert_fail("n_inputs >= 1", "libnc.c", 0x185Du, "nc_concat");
  v4 = (size_t)*a1;
  if ( a3 < 0 || (LODWORD(v5) = *(_DWORD *)(v4 + 80), a3 >= (int)v5) )
    __assert_fail("axis >= 0 && axis < x0->n_dims", "libnc.c", 0x1861u, "nc_concat");
  if ( a2 == 1 )
    return v4;
  size = *(_QWORD *)(*(_QWORD *)(v4 + 40) + 24LL);
  v6 = 1LL;
  v7 = *a1;
  v8 = *(_QWORD *)(v4 + 8 * (a3 + 12LL) + 24);
  do
  {
    v9 = v5;
    v10 = a1[v6];
    if ( size != *(_QWORD *)(v10[5] + 24LL) )
      nc_error("all operation tensors must be on the same device", size);
    v5 = *((unsigned int *)v10 + 20);
    if ( (_DWORD)v5 != v9 )
      __assert_fail("x->n_dims == x0->n_dims", "libnc.c", 0x186Bu, "nc_concat");
    v11 = *((unsigned int *)v7 + 12);
    if ( *((_DWORD *)v10 + 12) != (_DWORD)v11 )
      __assert_fail("x->item_type == x0->item_type", "libnc.c", 0x186Cu, "nc_concat");
    for ( i = 0LL; v9 > (int)i; ++i )
    {
      if ( a3 != (_DWORD)i && v10[i + 15] != v7[i + 15] )
        __assert_fail("x->dims[j] == x0->dims[j]", "libnc.c", 0x186Fu, "nc_concat");
    }
    v13 = v10[a3 + 15] + v8;
    ++v6;
    v8 = v13;
  }
  while ( a2 > (int)v6 );
  if ( (int)v5 > 0 )
  {
    v44[0] = v7[15];
    if ( (_DWORD)v5 != 1 )
    {
      v44[1] = v7[16];
      if ( (_DWORD)v5 != 2 )
      {
        v44[2] = v7[17];
        if ( (_DWORD)v5 != 3 )
          v44[3] = v7[18];
      }
    }
  }
  v14 = 0LL;
  v44[a3] = v13;
  v15 = a1;
  sizea = nc_new_tensor_nz(size, v11, v5, v44);
  do
  {
    v16 = (__int64)*v15++;
    v17 = (void *)nc_slice_alias(sizea, (unsigned int)a3);
    nc_tensor_copy(v17, v16);
    nc_free_tensor(v17);
    v14 += *(_QWORD *)(v16 + 8LL * a3 + 120);
  }
  while ( &a1[(unsigned int)(a2 - 1) + 1] != v15 );
  v18 = v15;
  v4 = sizea;
  v19 = a1;
  v20 = 0;
  v21 = a1;
  while ( !*((_QWORD *)*v21 + 4) )
  {
    ++v20;
    ++v21;
    if ( a2 == v20 )
      goto LABEL_38;
  }
  if ( a2 == v20 )
    goto LABEL_38;
  sizeb = 8LL * a2;
  v22 = (_QWORD *)nc_malloc(sizeb);
  v23 = 0LL;
  do
  {
    v22[v23] = *((_QWORD *)a1[v23] + 4);
    ++v23;
  }
  while ( a2 > (int)v23 );
  v43 = *(_QWORD *)(v4 + 24);
  v24 = nc_mallocz(0x80uLL);
  *(_DWORD *)(v24 + 16) = 1;
  *(_DWORD *)(v24 + 20) = 14;
  *(_DWORD *)(v24 + 24) = a2;
  v25 = nc_malloc(sizeb);
  v42 = v4;
  v26 = 0LL;
  for ( *(_QWORD *)(v24 + 32) = v25; ; v25 = *(_QWORD *)(v24 + 32) )
  {
    v27 = v22[v26];
    v28 = 8 * v26;
    if ( !v27 )
      break;
    ++v26;
    *(_QWORD *)(v25 + v28) = nc_dup_node(v27);
    if ( a2 <= (int)v26 )
      goto LABEL_33;
LABEL_30:
    ;
  }
  *(_QWORD *)(v25 + 8 * v26++) = 0LL;
  if ( a2 > (int)v26 )
    goto LABEL_30;
LABEL_33:
  v4 = v42;
  v29 = *(_QWORD *)(v43 + 72);
  *(_QWORD *)(v43 + 72) = v29 + 1;
  *(_QWORD *)(v24 + 96) = v29;
  v30 = *(_QWORD *)(v43 + 32);
  *(_QWORD *)(v30 + 8) = v24;
  *(_QWORD *)v24 = v30;
  *(_QWORD *)(v24 + 8) = v43 + 32;
  *(_QWORD *)(v43 + 32) = v24;
  nc_free(v22);
  v31 = *(void **)(v42 + 32);
  if ( v31 )
    nc_free_node(v31);
  *(_QWORD *)(v42 + 32) = v24;
  *(_DWORD *)(v24 + 64) = a3;
  v32 = nc_malloc(sizeb);
  *(_QWORD *)(v24 + 56) = v32;
  v33 = v32;
  v34 = 0LL;
  while ( 1 )
  {
    *(_QWORD *)(v33 + 8 * v34) = *((_QWORD *)a1[v34] + a3 + 15);
    if ( a2 <= (int)++v34 )
      break;
    v33 = *(_QWORD *)(v24 + 56);
  }
  do
  {
LABEL_38:
    v35 = *v19++;
    nc_free_tensor(v35);
  }
  while ( v18 != v19 );
  return v4;
}

