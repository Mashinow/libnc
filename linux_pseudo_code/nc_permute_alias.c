// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_permute_alias
// Included functions: 2

// ======================================================
// Function: nc_permute_alias @ 0x21AD0
// ======================================================

__int64 __fastcall nc_permute_alias(_DWORD *ptr, int a2, int *a3)
{
  int v3; // ebp
  char *v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rax
  char *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // rax
  char *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rax
  char *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r13
  _DWORD *v19; // rax
  _DWORD *v21; // [rsp+8h] [rbp-70h] BYREF
  __int64 v22[4]; // [rsp+10h] [rbp-68h] BYREF
  __int64 v23[9]; // [rsp+30h] [rbp-48h] BYREF

  v3 = ptr[20];
  if ( v3 != a2 )
    __assert_fail("x->n_dims == n_dims", "libnc.c", 0x1954u, "nc_permute_alias");
  if ( v3 > 0 )
  {
    v5 = (char *)&ptr[2 * *a3];
    v6 = *((_QWORD *)v5 + 15);
    v7 = *((_QWORD *)v5 + 11);
    v22[0] = v6;
    v23[0] = v7;
    if ( v3 != 1 )
    {
      v8 = (char *)&ptr[2 * a3[1]];
      v9 = *((_QWORD *)v8 + 15);
      v10 = *((_QWORD *)v8 + 11);
      v22[1] = v9;
      v23[1] = v10;
      if ( v3 != 2 )
      {
        v11 = (char *)&ptr[2 * a3[2]];
        v12 = *((_QWORD *)v11 + 15);
        v13 = *((_QWORD *)v11 + 11);
        v22[2] = v12;
        v23[2] = v13;
        if ( v3 != 3 )
        {
          v14 = (char *)&ptr[2 * a3[3]];
          v15 = *((_QWORD *)v14 + 15);
          v16 = *((_QWORD *)v14 + 11);
          v22[3] = v15;
          v23[3] = v16;
        }
      }
    }
  }
  v17 = nc_new_tensor_from_buffer(
          *((_QWORD *)ptr + 3),
          *((_QWORD *)ptr + 5),
          ptr[12],
          v3,
          (int)v22,
          (unsigned int)*((_QWORD *)ptr + 7) - *(_DWORD *)(*((_QWORD *)ptr + 5) + 40LL),
          (__int64)v23);
  v21 = ptr;
  v18 = v17;
  v19 = sub_17800(29, (__int64 *)(v17 + 24), (void **)(v17 + 32), (__int64)&v21);
  if ( v19 )
  {
    v19[14] = v3;
    if ( v3 > 0 )
    {
      v19[15] = *a3;
      if ( v3 != 1 )
      {
        v19[16] = a3[1];
        if ( v3 != 2 )
        {
          v19[17] = a3[2];
          if ( v3 != 3 )
            v19[18] = a3[3];
        }
      }
    }
  }
  nc_free_tensor(ptr);
  return v18;
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

