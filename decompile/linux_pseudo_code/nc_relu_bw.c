// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_relu_bw
// Included functions: 2

// ======================================================
// Function: nc_relu_bw @ 0x24BA0
// ======================================================

__int64 __fastcall nc_relu_bw(_QWORD *ptr, _QWORD *a2)
{
  __int64 v4; // r13
  unsigned int v5; // eax
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rsi
  __int64 v11; // r15
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 *v15; // rbx
  char *v16; // rbp
  int v17; // edx
  __int64 v18; // rdi
  __int64 v19; // rcx
  __int64 v20; // r8
  __int64 v21; // r11
  __int64 v22; // rdx
  __int64 v23; // rdx
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rdx
  int v28; // [rsp+Ch] [rbp-7Ch]
  __int64 v29; // [rsp+10h] [rbp-78h]
  __int64 v30[2]; // [rsp+20h] [rbp-68h] BYREF
  __int64 v31; // [rsp+30h] [rbp-58h] BYREF
  __int64 v32; // [rsp+38h] [rbp-50h]
  __int64 v33; // [rsp+40h] [rbp-48h]
  __int64 v34; // [rsp+48h] [rbp-40h]

  v4 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v4 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v5 = *((_DWORD *)ptr + 12);
  if ( *((_DWORD *)a2 + 12) != v5 || v5 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_relu_bw");
  v6 = *((unsigned int *)ptr + 20);
  if ( (_DWORD)v6 != *((_DWORD *)a2 + 20) )
LABEL_7:
    __assert_fail("same_dims(yg1, xd1)", "libnc.c", 0x1C15u, "nc_relu_bw");
  if ( (int)v6 > 0 )
  {
    if ( a2[15] != ptr[15] )
      goto LABEL_7;
    v7 = 1LL;
    while ( (int)v6 > (int)v7 )
    {
      v8 = ptr[v7++ + 15];
      if ( v8 != a2[v7 + 14] )
        goto LABEL_7;
    }
  }
  v9 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v6, ptr + 15);
  LODWORD(v10) = *((_DWORD *)ptr + 20);
  v11 = v9;
  if ( (int)v10 <= 0 )
  {
    v31 = 0LL;
    v14 = 0LL;
    v29 = 1LL;
    v28 = 0;
    goto LABEL_35;
  }
  if ( !*((_BYTE *)ptr + 73) || !*(_BYTE *)(v9 + 73) || !*((_BYTE *)a2 + 73) )
  {
    v29 = 1LL;
    v28 = 0;
LABEL_31:
    v31 = 0LL;
    if ( (int)v10 <= 1 )
    {
      v14 = 0LL;
      goto LABEL_35;
    }
    goto LABEL_32;
  }
  v12 = ptr[15];
  if ( (_DWORD)v10 == 1 )
  {
    v28 = 1;
    goto LABEL_30;
  }
  if ( *((_BYTE *)ptr + 74) && *(_BYTE *)(v11 + 74) && *((_BYTE *)a2 + 74) )
  {
    v12 *= ptr[16];
    if ( (_DWORD)v10 == 2 )
    {
      v28 = 2;
      goto LABEL_30;
    }
    if ( *((_BYTE *)ptr + 75) && *(_BYTE *)(v11 + 75) && *((_BYTE *)a2 + 75) )
    {
      v12 *= ptr[17];
      if ( (_DWORD)v10 == 3 )
      {
        v28 = 3;
        goto LABEL_30;
      }
      if ( *((_BYTE *)ptr + 76) && *(_BYTE *)(v11 + 76) && *((_BYTE *)a2 + 76) )
      {
        v12 *= ptr[18];
        v28 = 4;
LABEL_30:
        v29 = (int)v12;
        goto LABEL_31;
      }
      v28 = 3;
    }
    else
    {
      v28 = 2;
    }
  }
  else
  {
    v28 = 1;
  }
  v31 = 0LL;
  v29 = (int)v12;
LABEL_32:
  v13 = 1LL;
  do
    *(&v31 + v13++) = 0LL;
  while ( (int)v10 > (int)v13 );
  v14 = v31;
LABEL_35:
  v15 = &v31 + v28;
  v16 = (char *)&ptr[v28 + 1];
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
        v19 += a2[12] * v32;
        if ( v17 != 2 )
        {
          v19 += a2[13] * v33;
          if ( v17 != 3 )
          {
            v20 = v34;
            v21 = a2[14];
            goto LABEL_42;
          }
        }
      }
      goto LABEL_43;
    }
    v19 = a2[7];
    v18 = ptr[7];
    if ( (int)v10 <= 0 )
    {
LABEL_64:
      v22 = 0LL;
      goto LABEL_49;
    }
    while ( 1 )
    {
      v22 = ptr[11] * v14;
      if ( (_DWORD)v10 != 1 )
      {
        v22 += ptr[12] * v32;
        if ( (_DWORD)v10 != 2 )
        {
          v22 += ptr[13] * v33;
          if ( (_DWORD)v10 != 3 )
          {
            v20 = v34;
            v21 = ptr[14];
            if ( (_DWORD)v10 != 4 )
              goto LABEL_42;
            v22 += v21 * v34;
          }
        }
      }
LABEL_49:
      v23 = v18 + v22;
      v18 = *(unsigned int *)(v11 + 80);
      v10 = *(_QWORD *)(v11 + 56);
      if ( (int)v18 <= 0 )
        break;
      v14 *= *(_QWORD *)(v11 + 88);
      if ( (_DWORD)v18 == 1 )
        goto LABEL_55;
      v14 += *(_QWORD *)(v11 + 96) * v32;
      if ( (_DWORD)v18 == 2 )
        goto LABEL_55;
      v14 += *(_QWORD *)(v11 + 104) * v33;
      if ( (_DWORD)v18 == 3 )
        goto LABEL_55;
      v20 = v34;
      v21 = *(_QWORD *)(v11 + 112);
      if ( (_DWORD)v18 == 4 )
      {
        v14 += v21 * v34;
        goto LABEL_55;
      }
LABEL_42:
      v19 += v21 * v20;
LABEL_43:
      v19 += v18;
      v18 = ptr[7];
      if ( (int)v10 <= 0 )
        goto LABEL_64;
    }
    v14 = 0LL;
LABEL_55:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD))(v4 + 248))(
      v4,
      v14 + v10,
      v23,
      v19,
      v29,
      *((unsigned int *)ptr + 12));
    LODWORD(v10) = *((_DWORD *)ptr + 20);
    if ( (int)v10 <= v28 )
      goto LABEL_60;
    v24 = *v15 + 1;
    *v15 = v24;
    if ( ptr[v28 + 15] != v24 )
    {
LABEL_61:
      v14 = v31;
      continue;
    }
    break;
  }
  v25 = 0LL;
  while ( 1 )
  {
    v15[v25] = 0LL;
    if ( (_DWORD)v10 - 1 - v28 == v25 )
      break;
    v26 = v15[v25 + 1] + 1;
    v15[++v25] = v26;
    if ( v26 != *(_QWORD *)&v16[8 * v25 + 112] )
      goto LABEL_61;
  }
LABEL_60:
  v30[0] = (__int64)ptr;
  v30[1] = (__int64)a2;
  sub_17590(0, (__int64 *)(v11 + 24), (void **)(v11 + 32), v30);
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v11;
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

