// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_layer_norm
// Included functions: 3

// ======================================================
// Function: nc_layer_norm @ 0x26590
// ======================================================

_QWORD *__fastcall nc_layer_norm(_QWORD *a1, __m128 a2)
{
  return sub_178F0(a1, 1u, a2);
}

// ======================================================
// Function: sub_178F0 @ 0x178F0
// ======================================================

_QWORD *__fastcall sub_178F0(_QWORD *ptr, unsigned int a2, __m128 _XMM0)
{
  __int64 v4; // rdx
  _QWORD *v5; // r15
  __int64 v6; // rax
  __int64 v7; // r13
  int v8; // eax
  __int64 v9; // rdi
  __int64 v10; // rdi
  __int64 v11; // rdx
  __int64 v12; // r11
  __int64 *v13; // rbx
  __int64 v14; // rdx
  __int64 v15; // r8
  __int64 v16; // rcx
  __int64 v17; // rsi
  int v18; // eax
  int v19; // eax
  __int64 v21; // rdx
  __int64 v22; // rdx
  __int64 v23; // rcx
  _QWORD *v24; // rbx
  __int64 v25; // rax
  _QWORD *v26; // r12
  __int64 v27; // rax
  __int64 v28; // rbx
  int v30; // [rsp+Ch] [rbp-9Ch]
  __int64 v31; // [rsp+10h] [rbp-98h]
  __int64 v32; // [rsp+20h] [rbp-88h]
  _QWORD *v35; // [rsp+48h] [rbp-60h] BYREF
  __int64 v36; // [rsp+50h] [rbp-58h] BYREF
  __int64 v37; // [rsp+58h] [rbp-50h]
  __int64 v38; // [rsp+60h] [rbp-48h]
  __int64 v39; // [rsp+68h] [rbp-40h]
  __int64 v40; // [rsp+70h] [rbp-38h]

  __asm { vmovss  [rsp+0A8h+var_74], xmm0 }
  v31 = *(_QWORD *)(ptr[5] + 24LL);
  if ( *((_DWORD *)ptr + 12) > 1u )
    nc_error("unsupported type for %s\n", (char)"nc_layer_norm1");
  v4 = *((unsigned int *)ptr + 20);
  if ( (int)v4 <= 0 )
    __assert_fail("x->n_dims >= 1", "libnc.c", 0x1CC8u, "nc_layer_norm1");
  if ( !*((_BYTE *)ptr + 73) )
    __assert_fail("x->contig[0]", "libnc.c", 0x1CC9u, "nc_layer_norm1");
  v5 = ptr;
  if ( *((_DWORD *)ptr + 4) != 1 )
  {
    v6 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v4, ptr + 15);
    LODWORD(v4) = *((_DWORD *)ptr + 20);
    v5 = (_QWORD *)v6;
  }
  v7 = nc_new_tensor_nz(v31, 0LL, (unsigned int)(v4 - 1), ptr + 16);
  v8 = *((_DWORD *)ptr + 20);
  if ( v8 <= 1 )
  {
    v12 = 0LL;
    v30 = 1;
    v36 = 0LL;
    v32 = 1LL;
  }
  else
  {
    if ( *((_BYTE *)ptr + 74) && *((_BYTE *)v5 + 74) && *(_BYTE *)(v7 + 73) )
    {
      v9 = ptr[16];
      v32 = ptr[16];
      if ( v8 != 2 && *((_BYTE *)ptr + 75) && *((_BYTE *)v5 + 75) && *(_BYTE *)(v7 + 74) )
      {
        v10 = ptr[17] * v9;
        v32 = v10;
        if ( v8 != 3 && *((_BYTE *)ptr + 76) && *((_BYTE *)v5 + 76) && *(_BYTE *)(v7 + 75) )
        {
          v30 = 4;
          v32 = ptr[18] * v10;
        }
        else
        {
          v30 = 3;
        }
      }
      else
      {
        v30 = 2;
      }
    }
    else
    {
      v30 = 1;
      v32 = 1LL;
    }
    v36 = 0LL;
    v11 = 1LL;
    do
      *(&v36 + v11++) = 0LL;
    while ( v8 > (int)v11 );
    v12 = v36;
  }
  v13 = &v36 + v30;
  while ( 2 )
  {
    if ( v12 == -1 )
      goto LABEL_49;
    v14 = ptr[7];
    if ( v8 > 0 )
    {
      v15 = ptr[11] * v12;
      if ( v8 != 1 )
      {
        v15 += ptr[12] * v37;
        if ( v8 != 2 )
        {
          v15 += ptr[13] * v38;
          if ( v8 != 3 )
          {
            v16 = v39;
            v17 = ptr[14];
            goto LABEL_30;
          }
        }
      }
      goto LABEL_31;
    }
    v18 = *(_DWORD *)(v7 + 80);
    v15 = ptr[7];
    v14 = *(_QWORD *)(v7 + 56);
    if ( v18 <= 0 )
    {
LABEL_57:
      v16 = 0LL;
      goto LABEL_37;
    }
    while ( 1 )
    {
      v16 = *(_QWORD *)(v7 + 88) * v37;
      if ( v18 != 1 )
      {
        v16 += *(_QWORD *)(v7 + 96) * v38;
        if ( v18 != 2 )
        {
          v16 += *(_QWORD *)(v7 + 104) * v39;
          if ( v18 != 3 )
          {
            v17 = v40;
            if ( v18 != 4 )
              goto LABEL_30;
            v16 += *(_QWORD *)(v7 + 112) * v40;
          }
        }
      }
LABEL_37:
      v19 = *((_DWORD *)v5 + 20);
      v16 += v14;
      v14 = v5[8];
      if ( v19 <= 0 )
        break;
      v12 *= v5[11];
      if ( v19 == 1 )
        goto LABEL_43;
      v12 += v5[12] * v37;
      if ( v19 == 2 )
        goto LABEL_43;
      v12 += v5[13] * v38;
      if ( v19 == 3 )
        goto LABEL_43;
      v17 = v5[14];
      if ( v19 == 4 )
      {
        v12 += v17 * v39;
        goto LABEL_43;
      }
LABEL_30:
      v15 += v17 * v16;
LABEL_31:
      v18 = *(_DWORD *)(v7 + 80);
      v15 += v14;
      v14 = *(_QWORD *)(v7 + 56);
      if ( v18 <= 0 )
        goto LABEL_57;
    }
    v12 = 0LL;
LABEL_43:
    __asm { vmovss  xmm0, [rsp+0C8h+var_74] }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD, double, _QWORD, __int64, _QWORD, _QWORD))(v31 + 416))(
      v31,
      v5[7] + v12,
      v14,
      v16,
      v15,
      ptr[8],
      *(double *)&_XMM0,
      ptr[15],
      v32,
      a2,
      *((unsigned int *)ptr + 12));
    v8 = *((_DWORD *)ptr + 20);
    if ( v30 >= v8 )
      goto LABEL_48;
    v21 = *v13 + 1;
    *v13 = v21;
    if ( ptr[v30 + 15] != v21 )
    {
LABEL_54:
      v12 = v36;
      continue;
    }
    break;
  }
  v22 = 0LL;
  while ( 1 )
  {
    v13[v22] = 0LL;
    if ( v8 - 1 - v30 == v22 )
      break;
    v23 = v13[v22 + 1] + 1;
    v13[++v22] = v23;
    if ( v23 != ptr[(unsigned int)(v30 + 1) + 14 + v22] )
      goto LABEL_54;
  }
LABEL_48:
  v36 = -1LL;
LABEL_49:
  v35 = ptr;
  v24 = sub_17800(24, v5 + 3, (void **)v5 + 4, (__int64)&v35);
  if ( v24 )
  {
    *((_DWORD *)v24 + 10) = 2;
    *((_DWORD *)v24 + 14) = a2;
    v25 = nc_malloc(0x10uLL);
    v24[6] = v25;
    v26 = (_QWORD *)v25;
    v27 = nc_dup_tensor(v5);
    v28 = v24[6];
    *v26 = v27;
    *(_QWORD *)(v28 + 8) = nc_dup_tensor(v7);
  }
  nc_free_tensor((void *)v7);
  if ( v5 != ptr )
    nc_free_tensor(ptr);
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

