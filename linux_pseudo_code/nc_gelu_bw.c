// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_gelu_bw
// Included functions: 2

// ======================================================
// Function: nc_gelu_bw @ 0x253B0
// ======================================================

void *__fastcall nc_gelu_bw(_QWORD *ptr, _QWORD *a2, __int64 a3)
{
  _QWORD *v3; // r14
  _QWORD *v4; // r13
  __int64 v6; // rbx
  unsigned int v7; // eax
  int *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  int v14; // ecx
  _QWORD *v15; // r10
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r15
  __int64 *v19; // rbx
  int v20; // edx
  __int64 v21; // r8
  int v22; // edx
  __int64 v23; // r8
  __int64 v24; // rcx
  __int64 v25; // rcx
  int v26; // esi
  __int64 v27; // rdx
  __int64 v28; // rdx
  int v29; // edi
  __int64 v30; // r15
  int v31; // esi
  __int64 v32; // rdx
  __int64 v33; // rdx
  int v34; // esi
  __int64 v35; // rcx
  _QWORD *v36; // r10
  void *v37; // r13
  int *v38; // r14
  void *v39; // r10
  __int64 v41; // rax
  int v42; // [rsp+0h] [rbp-A8h]
  _QWORD *v43; // [rsp+0h] [rbp-A8h]
  void *v44; // [rsp+0h] [rbp-A8h]
  __int64 v45; // [rsp+8h] [rbp-A0h]
  int *ptra; // [rsp+18h] [rbp-90h]
  __int64 v47; // [rsp+20h] [rbp-88h]
  __int64 v48[4]; // [rsp+30h] [rbp-78h] BYREF
  __int64 v49; // [rsp+50h] [rbp-58h] BYREF
  __int64 v50; // [rsp+58h] [rbp-50h]
  __int64 v51; // [rsp+60h] [rbp-48h]
  __int64 v52; // [rsp+68h] [rbp-40h]

  v3 = (_QWORD *)a3;
  v4 = a2;
  v6 = *(_QWORD *)(ptr[5] + 24LL);
  v45 = v6;
  if ( v6 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( v6 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v7 = *((_DWORD *)ptr + 12);
  if ( v7 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_gelu_bw");
  if ( *((_DWORD *)a2 + 12) != v7 )
    nc_error("unsupported type for %s\n", (char)"nc_gelu_bw");
  if ( *(_DWORD *)(a3 + 48) != v7 )
    nc_error("unsupported type for %s\n", (char)"nc_gelu_bw");
  LODWORD(v8) = *((_DWORD *)ptr + 20);
  v42 = (int)v8;
  if ( (_DWORD)v8 != *((_DWORD *)a2 + 20) )
LABEL_12:
    __assert_fail("same_dims(yg, x)", "libnc.c", 0x1C53u, "nc_gelu_bw");
  if ( (int)v8 <= 0 )
  {
LABEL_56:
    if ( (_DWORD)v8 == *((_DWORD *)v3 + 20) )
    {
      if ( *((_DWORD *)ptr + 4) == 1 )
      {
        v49 = 0LL;
        v15 = ptr;
        v18 = 0LL;
        v42 = 0;
        v47 = 1LL;
        goto LABEL_50;
      }
LABEL_92:
      v41 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), (unsigned int)v42, ptr + 15);
      v14 = *((_DWORD *)ptr + 20);
      v15 = (_QWORD *)v41;
      v42 = *(_DWORD *)(v41 + 80);
      if ( v42 <= 0 )
        goto LABEL_93;
      goto LABEL_25;
    }
LABEL_57:
    __assert_fail("same_dims(yg, z)", "libnc.c", 0x1C54u, "nc_gelu_bw");
  }
  v9 = a2[15];
  if ( v9 != ptr[15] )
    goto LABEL_12;
  v10 = 1LL;
  while ( *((_DWORD *)ptr + 20) > (int)v10 )
  {
    v11 = ptr[v10++ + 15];
    if ( v11 != a2[v10 + 14] )
      goto LABEL_12;
  }
  if ( v42 != *((_DWORD *)v3 + 20) )
    goto LABEL_57;
  v12 = 1LL;
  if ( v9 != v3[15] )
    goto LABEL_57;
  while ( v42 > (int)v12 )
  {
    v13 = ptr[v12++ + 15];
    if ( v13 != v3[v12 + 14] )
      goto LABEL_57;
  }
  if ( *((_DWORD *)ptr + 4) != 1 )
    goto LABEL_92;
  v14 = v42;
  v15 = ptr;
LABEL_25:
  if ( *((_BYTE *)v15 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)v4 + 73) && *((_BYTE *)v3 + 73) )
  {
    v16 = v15[15];
    if ( v42 > 1 && *((_BYTE *)v15 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)v4 + 74) && *((_BYTE *)v3 + 74) )
    {
      v16 *= v15[16];
      if ( v42 != 2 )
      {
        if ( *((_BYTE *)v15 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)v4 + 75) && *((_BYTE *)v3 + 75) )
        {
          v16 *= v15[17];
          if ( v42 != 3 )
          {
            if ( *((_BYTE *)v15 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)v4 + 76) && *((_BYTE *)v3 + 76) )
            {
              v16 *= v15[18];
              v42 = 4;
            }
            else
            {
              v42 = 3;
            }
          }
        }
        else
        {
          v42 = 2;
        }
      }
    }
    else
    {
      v42 = 1;
    }
    v47 = (int)v16;
    goto LABEL_46;
  }
LABEL_93:
  v47 = 1LL;
  v42 = 0;
LABEL_46:
  v49 = 0LL;
  if ( v14 <= 1 )
  {
    v18 = 0LL;
  }
  else
  {
    v17 = 1LL;
    do
      *(&v49 + v17++) = 0LL;
    while ( v14 > (int)v17 );
    v18 = v49;
  }
LABEL_50:
  v19 = &v49 + v42;
  v8 = (int *)v3;
  v3 = v4;
  v4 = v15;
  if ( v18 == -1 )
  {
LABEL_87:
    v36 = v4;
    v37 = v3;
    v38 = v8;
  }
  else
  {
    while ( 1 )
    {
      v20 = v8[20];
      if ( v20 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *((_QWORD *)v8 + 11) * v18;
        if ( v20 != 1 )
        {
          v21 += *((_QWORD *)v8 + 12) * v50;
          if ( v20 != 2 )
          {
            v21 += *((_QWORD *)v8 + 13) * v51;
            if ( v20 != 3 )
            {
              if ( v20 != 4 )
                goto LABEL_56;
              v21 += *((_QWORD *)v8 + 14) * v52;
            }
          }
        }
      }
      v22 = *((_DWORD *)v3 + 20);
      v23 = *((_QWORD *)v8 + 7) + v21;
      if ( v22 <= 0 )
      {
        v24 = 0LL;
      }
      else
      {
        v24 = v3[11] * v18;
        if ( v22 != 1 )
        {
          v24 += v3[12] * v50;
          if ( v22 != 2 )
          {
            v24 += v3[13] * v51;
            if ( v22 != 3 )
            {
              if ( v22 != 4 )
                goto LABEL_56;
              v24 += v3[14] * v52;
            }
          }
        }
      }
      v25 = v3[7] + v24;
      v26 = *((_DWORD *)ptr + 20);
      if ( v26 <= 0 )
      {
        v27 = 0LL;
      }
      else
      {
        v27 = ptr[11] * v18;
        if ( v26 != 1 )
        {
          v27 += ptr[12] * v50;
          if ( v26 != 2 )
          {
            v27 += ptr[13] * v51;
            if ( v26 != 3 )
            {
              if ( v26 != 4 )
                goto LABEL_56;
              v27 += ptr[14] * v52;
            }
          }
        }
      }
      v28 = ptr[7] + v27;
      v29 = *((_DWORD *)v4 + 20);
      if ( v29 <= 0 )
      {
        v30 = 0LL;
      }
      else
      {
        v30 = v4[11] * v18;
        if ( v29 != 1 )
        {
          v30 += v4[12] * v50;
          if ( v29 != 2 )
          {
            v30 += v4[13] * v51;
            if ( v29 != 3 )
            {
              if ( v29 != 4 )
                goto LABEL_56;
              v30 += v4[14] * v52;
            }
          }
        }
      }
      ptra = v8;
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))(v45 + 264))(
        v45,
        v30 + v4[7],
        v28,
        v25,
        v23,
        v47,
        *((unsigned int *)ptr + 12));
      v31 = *((_DWORD *)ptr + 20);
      v8 = ptra;
      if ( v31 <= v42 )
        break;
      v32 = *v19 + 1;
      *v19 = v32;
      if ( ptr[v42 + 15] == v32 )
      {
        v33 = 0LL;
        v34 = v31 - 1 - v42;
        do
        {
          v19[v33] = 0LL;
          if ( v34 == v33 )
            goto LABEL_82;
          v35 = v19[v33 + 1] + 1;
          v19[++v33] = v35;
        }
        while ( v35 == ptr[(unsigned int)(v42 + 1) + 14 + v33] );
      }
      v18 = v49;
      if ( v49 == -1 )
        goto LABEL_87;
    }
LABEL_82:
    v49 = -1LL;
    v36 = v4;
    v37 = v3;
    v38 = ptra;
  }
  v43 = v36;
  v48[0] = (__int64)ptr;
  v48[1] = (__int64)v37;
  v48[2] = (__int64)v38;
  sub_176C0(0, v36 + 3, (void **)v36 + 4, v48);
  v39 = v43;
  if ( ptr != v43 )
  {
    nc_free_tensor(ptr);
    v39 = v43;
  }
  v44 = v39;
  nc_free_tensor(v37);
  nc_free_tensor(v38);
  return v44;
}

// ======================================================
// Function: sub_176C0 @ 0x176C0
// ======================================================

_QWORD *__fastcall sub_176C0(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  _QWORD *v4; // r15
  _QWORD *v8; // rax
  __int64 v9; // r13
  _QWORD *v10; // r12
  __int64 v11; // rax
  __int64 v12; // rbx
  _DWORD *v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rbp
  __int64 v16; // rax
  __int64 v17; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
  {
    v4 = *(_QWORD **)(a4[2] + 32LL);
    if ( !v4 )
      return v4;
  }
  v8 = (_QWORD *)nc_malloc(0x18uLL);
  v9 = *a2;
  v10 = v8;
  *v8 = *(_QWORD *)(*a4 + 32LL);
  v8[1] = *(_QWORD *)(a4[1] + 32LL);
  v11 = a4[2];
  v12 = 0LL;
  v10[2] = *(_QWORD *)(v11 + 32);
  v13 = (_DWORD *)nc_mallocz(0x80uLL);
  v13[4] = 1;
  v4 = v13;
  v13[5] = a1;
  v13[6] = 3;
  v14 = nc_malloc(0x18uLL);
  v4[4] = v14;
  while ( v10[v12] )
  {
    v15 = (_QWORD *)(v14 + v12 * 8);
    ++v12;
    *v15 = nc_dup_node();
    if ( v12 == 3 )
      goto LABEL_10;
LABEL_7:
    v14 = v4[4];
  }
  *(_QWORD *)(v14 + v12 * 8) = 0LL;
  if ( ++v12 != 3 )
    goto LABEL_7;
LABEL_10:
  v16 = *(_QWORD *)(v9 + 72);
  *(_QWORD *)(v9 + 72) = v16 + 1;
  v4[12] = v16;
  v17 = *(_QWORD *)(v9 + 32);
  *(_QWORD *)(v17 + 8) = v4;
  *v4 = v17;
  v4[1] = v9 + 32;
  *(_QWORD *)(v9 + 32) = v4;
  nc_free(v10);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v4;
  return v4;
}

