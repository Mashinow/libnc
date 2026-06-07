// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sigmoid_bw
// Included functions: 2

// ======================================================
// Function: nc_sigmoid_bw @ 0x23C10
// ======================================================

unsigned int *__fastcall nc_sigmoid_bw(unsigned int *ptr, _QWORD *a2)
{
  unsigned int v4; // eax
  int v5; // r15d
  __int64 v6; // rax
  __int64 v7; // rdx
  int v8; // ecx
  unsigned int *v9; // r13
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 *v13; // rbx
  char *v14; // r12
  int v15; // edx
  __int64 v16; // rsi
  __int64 v17; // rcx
  __int64 v18; // rdi
  __int64 v19; // r8
  __int64 v20; // rdx
  __int64 v21; // rdx
  int v22; // ecx
  __int64 v23; // rax
  __int64 v24; // rax
  int v25; // ecx
  __int64 v26; // rdx
  __int64 v28; // rax
  __int64 v29; // [rsp+8h] [rbp-80h]
  __int64 v30; // [rsp+10h] [rbp-78h]
  __int64 v31[2]; // [rsp+20h] [rbp-68h] BYREF
  __int64 v32; // [rsp+30h] [rbp-58h] BYREF
  __int64 v33; // [rsp+38h] [rbp-50h]
  __int64 v34; // [rsp+40h] [rbp-48h]
  __int64 v35; // [rsp+48h] [rbp-40h]

  v29 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( v29 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v4 = ptr[12];
  if ( *((_DWORD *)a2 + 12) != v4 || v4 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_sigmoid_bw");
  v5 = ptr[20];
  if ( v5 != *((_DWORD *)a2 + 20) )
LABEL_7:
    __assert_fail("same_dims(yg1, yd1)", "libnc.c", 0x1B8Eu, "nc_sigmoid_bw");
  if ( v5 > 0 )
  {
    if ( a2[15] != *((_QWORD *)ptr + 15) )
      goto LABEL_7;
    v6 = 1LL;
    while ( v5 > (int)v6 )
    {
      v7 = *(_QWORD *)&ptr[2 * v6++ + 30];
      if ( v7 != a2[v6 + 14] )
        goto LABEL_7;
    }
    if ( ptr[4] == 1 )
    {
      v8 = ptr[20];
      v9 = ptr;
LABEL_15:
      if ( *((_BYTE *)v9 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)a2 + 73) )
      {
        v10 = *((_QWORD *)v9 + 15);
        if ( v5 != 1 )
        {
          if ( *((_BYTE *)v9 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) )
          {
            v10 *= *((_QWORD *)v9 + 16);
            if ( v5 != 2 )
            {
              if ( *((_BYTE *)v9 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) )
              {
                v10 *= *((_QWORD *)v9 + 17);
                if ( v5 != 3 )
                {
                  if ( *((_BYTE *)v9 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) )
                  {
                    v10 *= *((_QWORD *)v9 + 18);
                    v5 = 4;
                  }
                  else
                  {
                    v5 = 3;
                  }
                }
              }
              else
              {
                v5 = 2;
              }
            }
          }
          else
          {
            v5 = 1;
          }
        }
        v30 = (int)v10;
        goto LABEL_32;
      }
LABEL_70:
      v30 = 1LL;
      v5 = 0;
LABEL_32:
      v32 = 0LL;
      if ( v8 <= 1 )
      {
        v12 = 0LL;
      }
      else
      {
        v11 = 1LL;
        do
          *(&v32 + v11++) = 0LL;
        while ( v8 > (int)v11 );
        v12 = v32;
      }
      goto LABEL_36;
    }
LABEL_69:
    v28 = nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], (unsigned int)v5, ptr + 30);
    v8 = ptr[20];
    v5 = *(_DWORD *)(v28 + 80);
    v9 = (unsigned int *)v28;
    if ( v5 <= 0 )
      goto LABEL_70;
    goto LABEL_15;
  }
  if ( ptr[4] != 1 )
    goto LABEL_69;
  v9 = ptr;
  v5 = 0;
  v12 = 0LL;
  v32 = 0LL;
  v30 = 1LL;
LABEL_36:
  v13 = &v32 + v5;
  v14 = (char *)&ptr[2 * (v5 + 1)];
  while ( v12 != -1 )
  {
    v15 = *((_DWORD *)a2 + 20);
    v16 = a2[7];
    if ( v15 <= 0 )
    {
      v17 = 0LL;
    }
    else
    {
      v17 = a2[11] * v12;
      if ( v15 != 1 )
      {
        v17 += a2[12] * v33;
        if ( v15 != 2 )
        {
          v17 += a2[13] * v34;
          if ( v15 != 3 )
          {
            v18 = v35;
            v19 = a2[14];
            goto LABEL_43;
          }
        }
      }
    }
    while ( 1 )
    {
      v17 += v16;
      v16 = ptr[20];
      v18 = *((_QWORD *)ptr + 7);
      if ( (int)v16 <= 0 )
      {
        v20 = 0LL;
      }
      else
      {
        v20 = *((_QWORD *)ptr + 11) * v12;
        if ( (_DWORD)v16 != 1 )
        {
          v20 += *((_QWORD *)ptr + 12) * v33;
          if ( (_DWORD)v16 != 2 )
          {
            v20 += *((_QWORD *)ptr + 13) * v34;
            if ( (_DWORD)v16 != 3 )
            {
              v19 = v35;
              if ( (_DWORD)v16 != 4 )
                goto LABEL_43;
              v20 += *((_QWORD *)ptr + 14) * v35;
            }
          }
        }
      }
      v21 = v18 + v20;
      v18 = v9[20];
      v16 = *((_QWORD *)v9 + 7);
      if ( (int)v18 <= 0 )
        break;
      v12 *= *((_QWORD *)v9 + 11);
      if ( (_DWORD)v18 == 1 )
        goto LABEL_56;
      v12 += *((_QWORD *)v9 + 12) * v33;
      if ( (_DWORD)v18 == 2 )
        goto LABEL_56;
      v12 += *((_QWORD *)v9 + 13) * v34;
      if ( (_DWORD)v18 == 3 )
        goto LABEL_56;
      v19 = v35;
      if ( (_DWORD)v18 == 4 )
      {
        v12 += *((_QWORD *)v9 + 14) * v35;
        goto LABEL_56;
      }
LABEL_43:
      v17 += v19 * v18;
    }
    v12 = 0LL;
LABEL_56:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD))(v29 + 216))(
      v29,
      v12 + v16,
      v21,
      v17,
      v30,
      ptr[12]);
    v22 = ptr[20];
    if ( v22 <= v5 )
    {
LABEL_61:
      v32 = -1LL;
      break;
    }
    v23 = *v13 + 1;
    *v13 = v23;
    if ( *(_QWORD *)&ptr[2 * v5 + 30] == v23 )
    {
      v24 = 0LL;
      v25 = v22 - 1 - v5;
      do
      {
        v13[v24] = 0LL;
        if ( v24 == v25 )
          goto LABEL_61;
        v26 = v13[v24 + 1] + 1;
        v13[++v24] = v26;
      }
      while ( v26 == *(_QWORD *)&v14[8 * v24 + 112] );
    }
    v12 = v32;
  }
  v31[0] = (__int64)ptr;
  v31[1] = (__int64)a2;
  sub_17590(0, (__int64 *)v9 + 3, (void **)v9 + 4, v31);
  if ( ptr != v9 )
    nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v9;
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

