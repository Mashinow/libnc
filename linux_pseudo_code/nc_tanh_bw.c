// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tanh_bw
// Included functions: 2

// ======================================================
// Function: nc_tanh_bw @ 0x24400
// ======================================================

__int64 __fastcall nc_tanh_bw(_QWORD *ptr, _QWORD *a2)
{
  unsigned int v4; // eax
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rax
  int v9; // r15d
  __int64 v10; // r14
  __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 *v15; // rbx
  char *v16; // r12
  int v17; // edx
  __int64 v18; // rsi
  __int64 v19; // rcx
  __int64 v20; // rdi
  __int64 v21; // r8
  __int64 v22; // rdx
  __int64 v23; // rdx
  int v24; // ecx
  __int64 v25; // rax
  __int64 v26; // rax
  int v27; // ecx
  __int64 v28; // rdx
  __int64 v30; // [rsp+8h] [rbp-80h]
  __int64 v31; // [rsp+10h] [rbp-78h]
  __int64 v32[2]; // [rsp+20h] [rbp-68h] BYREF
  __int64 v33; // [rsp+30h] [rbp-58h] BYREF
  __int64 v34; // [rsp+38h] [rbp-50h]
  __int64 v35; // [rsp+40h] [rbp-48h]
  __int64 v36; // [rsp+48h] [rbp-40h]

  v30 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v30 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v4 = *((_DWORD *)ptr + 12);
  if ( *((_DWORD *)a2 + 12) != v4 || v4 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_tanh_bw");
  v5 = *((unsigned int *)ptr + 20);
  if ( (_DWORD)v5 != *((_DWORD *)a2 + 20) )
LABEL_7:
    __assert_fail("same_dims(yg1, yd1)", "libnc.c", 0x1BD7u, "nc_tanh_bw");
  if ( (int)v5 > 0 )
  {
    if ( a2[15] != ptr[15] )
      goto LABEL_7;
    v6 = 1LL;
    while ( (int)v5 > (int)v6 )
    {
      v7 = ptr[v6++ + 15];
      if ( v7 != a2[v6 + 14] )
        goto LABEL_7;
    }
  }
  v8 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v5, ptr + 15);
  v9 = *(_DWORD *)(v8 + 80);
  v10 = v8;
  if ( v9 > 0 && *(_BYTE *)(v8 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)a2 + 73) )
  {
    v11 = *(_QWORD *)(v8 + 120);
    if ( v9 != 1 )
    {
      if ( *(_BYTE *)(v10 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) )
      {
        v11 *= *(_QWORD *)(v10 + 128);
        if ( v9 != 2 )
        {
          if ( *(_BYTE *)(v10 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) )
          {
            v11 *= *(_QWORD *)(v10 + 136);
            if ( v9 != 3 )
            {
              if ( *(_BYTE *)(v10 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) )
              {
                v11 *= *(_QWORD *)(v10 + 144);
                v9 = 4;
              }
              else
              {
                v9 = 3;
              }
            }
          }
          else
          {
            v9 = 2;
          }
        }
      }
      else
      {
        v9 = 1;
      }
    }
    v31 = (int)v11;
  }
  else
  {
    v31 = 1LL;
    v9 = 0;
  }
  v33 = 0LL;
  v12 = *((_DWORD *)ptr + 20);
  if ( v12 <= 1 )
  {
    v14 = 0LL;
  }
  else
  {
    v13 = 1LL;
    do
      *(&v33 + v13++) = 0LL;
    while ( v12 > (int)v13 );
    v14 = v33;
  }
  v15 = &v33 + v9;
  v16 = (char *)&ptr[v9 + 1];
  while ( 2 )
  {
    if ( v14 == -1 )
      goto LABEL_60;
    v17 = *((_DWORD *)a2 + 20);
    v18 = a2[7];
    if ( v17 > 0 )
    {
      v19 = a2[11] * v14;
      if ( v17 != 1 )
      {
        v19 += a2[12] * v34;
        if ( v17 != 2 )
        {
          v19 += a2[13] * v35;
          if ( v17 != 3 )
          {
            v20 = v36;
            v21 = a2[14];
            goto LABEL_42;
          }
        }
      }
      goto LABEL_43;
    }
    v20 = ptr[7];
    v19 = a2[7];
    v18 = *((unsigned int *)ptr + 20);
    if ( (int)v18 <= 0 )
    {
LABEL_64:
      v22 = 0LL;
      goto LABEL_49;
    }
    while ( 1 )
    {
      v22 = ptr[11] * v14;
      if ( (_DWORD)v18 != 1 )
      {
        v22 += ptr[12] * v34;
        if ( (_DWORD)v18 != 2 )
        {
          v22 += ptr[13] * v35;
          if ( (_DWORD)v18 != 3 )
          {
            v21 = v36;
            if ( (_DWORD)v18 != 4 )
              goto LABEL_42;
            v22 += ptr[14] * v36;
          }
        }
      }
LABEL_49:
      v23 = v20 + v22;
      v20 = *(unsigned int *)(v10 + 80);
      v18 = *(_QWORD *)(v10 + 56);
      if ( (int)v20 <= 0 )
        break;
      v14 *= *(_QWORD *)(v10 + 88);
      if ( (_DWORD)v20 == 1 )
        goto LABEL_55;
      v14 += *(_QWORD *)(v10 + 96) * v34;
      if ( (_DWORD)v20 == 2 )
        goto LABEL_55;
      v14 += *(_QWORD *)(v10 + 104) * v35;
      if ( (_DWORD)v20 == 3 )
        goto LABEL_55;
      v21 = v36;
      if ( (_DWORD)v20 == 4 )
      {
        v14 += *(_QWORD *)(v10 + 112) * v36;
        goto LABEL_55;
      }
LABEL_42:
      v19 += v21 * v20;
LABEL_43:
      v19 += v18;
      v18 = *((unsigned int *)ptr + 20);
      v20 = ptr[7];
      if ( (int)v18 <= 0 )
        goto LABEL_64;
    }
    v14 = 0LL;
LABEL_55:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD))(v30 + 232))(
      v30,
      v14 + v18,
      v23,
      v19,
      v31,
      *((unsigned int *)ptr + 12));
    v24 = *((_DWORD *)ptr + 20);
    if ( v24 <= v9 )
      goto LABEL_60;
    v25 = *v15 + 1;
    *v15 = v25;
    if ( v25 != ptr[v9 + 15] )
    {
LABEL_61:
      v14 = v33;
      continue;
    }
    break;
  }
  v26 = 0LL;
  v27 = v24 - 1 - v9;
  while ( 1 )
  {
    v15[v26] = 0LL;
    if ( v27 == v26 )
      break;
    v28 = v15[v26 + 1] + 1;
    v15[++v26] = v28;
    if ( v28 != *(_QWORD *)&v16[8 * v26 + 112] )
      goto LABEL_61;
  }
LABEL_60:
  v32[0] = (__int64)ptr;
  v32[1] = (__int64)a2;
  sub_17590(0, (__int64 *)(v10 + 24), (void **)(v10 + 32), v32);
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v10;
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

