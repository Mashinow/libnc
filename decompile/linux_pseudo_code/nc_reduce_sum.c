// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_reduce_sum
// Included functions: 2

// ======================================================
// Function: nc_reduce_sum @ 0x1D4A0
// ======================================================

unsigned int *__fastcall nc_reduce_sum(unsigned int *ptr, _QWORD *a2, int a3)
{
  unsigned int *v3; // r14
  __int64 v4; // r13
  int v5; // eax
  unsigned int *v6; // rbp
  __int64 v8; // r8
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  __int64 v12; // r9
  _QWORD *v13; // rax
  int v14; // edi
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 *v18; // rbx
  unsigned int *v19; // rax
  __int64 v20; // rbp
  unsigned int *v21; // r13
  __int64 v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // rdx
  void *v26; // rax
  int v27; // [rsp+4h] [rbp-84h]
  __int64 v28; // [rsp+8h] [rbp-80h]
  int v30; // [rsp+1Ch] [rbp-6Ch]
  __int64 v31[2]; // [rsp+20h] [rbp-68h] BYREF
  __int64 v32[11]; // [rsp+30h] [rbp-58h] BYREF

  v3 = ptr;
  v4 = *(_QWORD *)(a2[5] + 24LL);
  v5 = *((_DWORD *)a2 + 20);
  if ( v5 < a3 )
    __assert_fail("n_dims1 <= x->n_dims", "libnc.c", 0x1623u, "nc_reduce_sum");
  if ( *((_DWORD *)a2 + 12) > 1u )
    nc_error("unsupported type for %s\n", (char)"nc_reduce_sum");
  v30 = v5 - a3;
  if ( v5 == a3 )
  {
    v6 = (unsigned int *)a2;
    if ( ptr )
      return (unsigned int *)nc_add(ptr, a2);
    return v6;
  }
  if ( ptr )
  {
    if ( v4 != *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL) )
      nc_error("all operation tensors must be on the same device", (char)a2);
  }
  else
  {
    v3 = (unsigned int *)nc_new_tensor_nz(v4, *((unsigned int *)a2 + 12), (unsigned int)a3, a2 + 15);
    nc_tensor_set_zero(v3);
  }
  if ( *((_DWORD *)a2 + 12) )
  {
    v26 = (void *)nc_dup_tensor(v3);
    v6 = (unsigned int *)nc_convert(v26);
  }
  else
  {
    v6 = v3;
    if ( v3[4] != 1 )
    {
      v6 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)v3 + 5) + 24LL), v3[12], v3[20], v3 + 30);
      nc_tensor_copy(v6, v3);
    }
  }
  if ( a3 )
  {
    if ( a3 > 0 && *((_BYTE *)a2 + 73) && *((_BYTE *)v6 + 73) )
    {
      v8 = a2[15];
      if ( a3 == 1 )
      {
        v9 = 1;
LABEL_29:
        v10 = *((_DWORD *)a2 + 20);
        if ( v10 <= v9 )
        {
          v11 = v9;
          v12 = 1LL;
        }
        else
        {
          if ( !*((_BYTE *)a2 + v9 + 73) )
            goto LABEL_100;
          v11 = v9 + 1;
          v12 = a2[v9 + 15];
          if ( v9 + 1 < v10 )
          {
            if ( !*((_BYTE *)a2 + v11 + 73) )
              goto LABEL_100;
            v12 *= a2[v11 + 15];
            v11 = v9 + 2;
            if ( v9 + 2 < v10 )
            {
              if ( !*((_BYTE *)a2 + v11 + 73) )
                goto LABEL_100;
              v12 *= a2[v11 + 15];
              v11 = v9 + 3;
              if ( v10 > v9 + 3 )
              {
                if ( !*((_BYTE *)a2 + v11 + 73) )
                  goto LABEL_100;
                v12 *= a2[v11 + 15];
                v11 = v9 + 4;
                if ( v9 + 4 < v10 )
                {
                  if ( !*((_BYTE *)a2 + v11 + 73) )
                    goto LABEL_100;
                  v12 *= a2[v11 + 15];
                  v11 = v9 + 5;
                }
              }
            }
          }
        }
        if ( v11 == v10 )
        {
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))(v4 + 368))(
            v4,
            *((_QWORD *)v6 + 7),
            a2[7],
            a2[a3 + 11] >> dword_30520[*((unsigned int *)a2 + 12)],
            v8,
            v12,
            *((unsigned int *)a2 + 12));
          goto LABEL_42;
        }
LABEL_100:
        __assert_fail("axis1 == x->n_dims", "libnc.c", 0x1654u, "nc_reduce_sum");
      }
      if ( *((_BYTE *)a2 + 74) && *((_BYTE *)v6 + 74) )
      {
        v8 *= a2[16];
        if ( a3 == 2 )
        {
          v9 = 2;
        }
        else
        {
          if ( !*((_BYTE *)a2 + 75) || !*((_BYTE *)v6 + 75) )
            goto LABEL_101;
          v8 *= a2[17];
          if ( a3 == 3 )
          {
            v9 = 3;
          }
          else
          {
            if ( !*((_BYTE *)a2 + 76) || !*((_BYTE *)v6 + 76) )
              goto LABEL_101;
            v8 *= a2[18];
            v9 = 4;
          }
        }
        if ( a3 == v9 )
          goto LABEL_29;
      }
    }
LABEL_101:
    __assert_fail("first_axis == n_dims1", "libnc.c", 0x164Du, "nc_reduce_sum");
  }
  v14 = *((_DWORD *)a2 + 20);
  if ( v14 <= 0 )
  {
    v32[0] = 0LL;
    v17 = 0LL;
    v27 = 0;
    v28 = 1LL;
    goto LABEL_66;
  }
  if ( !*((_BYTE *)a2 + 73) )
  {
    v27 = 0;
    v28 = 1LL;
LABEL_62:
    v32[0] = 0LL;
    if ( v14 <= 1 )
    {
      v17 = 0LL;
      goto LABEL_66;
    }
    goto LABEL_63;
  }
  v15 = a2[15];
  if ( v14 == 1 )
  {
    v27 = 1;
    goto LABEL_61;
  }
  if ( *((_BYTE *)a2 + 74) )
  {
    v15 *= a2[16];
    if ( v14 == 2 )
    {
      v27 = 2;
      goto LABEL_61;
    }
    if ( *((_BYTE *)a2 + 75) )
    {
      v15 *= a2[17];
      if ( v14 == 3 )
      {
        v27 = 3;
        goto LABEL_61;
      }
      if ( *((_BYTE *)a2 + 76) )
      {
        v15 *= a2[18];
        v27 = 4;
LABEL_61:
        v28 = (int)v15;
        goto LABEL_62;
      }
      v27 = 3;
    }
    else
    {
      v27 = 2;
    }
  }
  else
  {
    v27 = 1;
  }
  v32[0] = 0LL;
  v28 = (int)v15;
LABEL_63:
  v16 = 1LL;
  do
    v32[v16++] = 0LL;
  while ( v14 > (int)v16 );
  v17 = v32[0];
LABEL_66:
  v18 = &v32[v27];
  v19 = v6;
  v20 = v4;
  v21 = v19;
  if ( v17 == -1 )
  {
LABEL_81:
    v6 = v21;
LABEL_42:
    if ( *((_DWORD *)a2 + 12) )
      goto LABEL_79;
    goto LABEL_43;
  }
  while ( 1 )
  {
    if ( v14 <= 0 )
    {
LABEL_72:
      v22 = 0LL;
      goto LABEL_73;
    }
    v22 = a2[11] * v17;
    if ( v14 != 1 )
    {
      v22 += a2[12] * v32[1];
      if ( v14 != 2 )
      {
        v22 += a2[13] * v32[2];
        if ( v14 != 3 )
        {
          if ( v14 != 4 )
            goto LABEL_72;
          v22 += a2[14] * v32[3];
        }
      }
    }
LABEL_73:
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, __int64))(v20 + 376))(
      v20,
      *((_QWORD *)v21 + 7),
      0LL,
      v22 + a2[7],
      0LL,
      v28,
      1LL);
    v14 = *((_DWORD *)a2 + 20);
    if ( v14 <= v27 )
      goto LABEL_78;
    v23 = *v18 + 1;
    *v18 = v23;
    if ( a2[v27 + 15] == v23 )
      break;
LABEL_80:
    v17 = v32[0];
    if ( v32[0] == -1 )
      goto LABEL_81;
  }
  v24 = 0LL;
  while ( 1 )
  {
    v18[v24] = 0LL;
    if ( v24 == v14 - 1 - v27 )
      break;
    v25 = v18[v24 + 1] + 1;
    v18[++v24] = v25;
    if ( v25 != a2[(unsigned int)(v27 + 1) + 14 + v24] )
      goto LABEL_80;
  }
LABEL_78:
  v32[0] = -1LL;
  v6 = v21;
  if ( *((_DWORD *)a2 + 12) )
LABEL_79:
    v6 = (unsigned int *)nc_convert(v6);
LABEL_43:
  v31[0] = (__int64)v3;
  v31[1] = (__int64)a2;
  v13 = sub_17590(5, (__int64 *)v6 + 3, (void **)v6 + 4, v31);
  if ( v13 )
  {
    *((_DWORD *)v13 + 14) = v30;
    if ( v30 > 0 )
    {
      v13[8] = a2[a3 + 15];
      if ( v30 != 1 )
      {
        v13[9] = a2[a3 + 16];
        if ( v30 != 2 )
        {
          v13[10] = a2[a3 + 17];
          if ( v30 != 3 )
            v13[11] = a2[a3 + 18];
        }
      }
    }
  }
  if ( v3 != v6 )
    nc_free_tensor(v3);
  nc_free_tensor(a2);
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

