// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_gelu
// Included functions: 2

// ======================================================
// Function: nc_gelu @ 0x25A10
// ======================================================

unsigned int *__fastcall nc_gelu(unsigned int *ptr)
{
  unsigned int *v2; // r12
  __int64 v3; // rax
  char *v4; // r15
  __int64 v5; // r14
  __int64 v6; // rax
  int v7; // ecx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 *v10; // rbp
  unsigned __int64 v11; // r13
  int v12; // edx
  __int64 v13; // r9
  void (__fastcall *v14)(__int64, __int64, __int64, __int64, __int64, __int64); // r10
  __int64 v15; // rsi
  __int64 v16; // rcx
  __int64 v17; // rdi
  __int64 v18; // r8
  __int64 v19; // rdx
  __int64 v20; // rdx
  int v21; // ecx
  __int64 v22; // rax
  __int64 v23; // rax
  int v24; // ecx
  __int64 v25; // rdx
  _QWORD *v26; // rax
  _QWORD *v27; // rbp
  __int64 v28; // rax
  _QWORD *v29; // r13
  __int64 v30; // rax
  __int64 v31; // rbp
  int v33; // r14d
  __int64 v34; // r13
  int v35; // ecx
  __int64 v36; // rax
  __int64 v37; // rdx
  unsigned int v38; // esi
  int v39; // edx
  int v40; // edx
  int v41; // ecx
  __int64 v42; // rax
  __int64 v43; // rax
  int v44; // ecx
  __int64 v45; // rdx
  __int64 v46; // [rsp+8h] [rbp-80h]
  __int64 v47; // [rsp+10h] [rbp-78h]
  __int64 v48; // [rsp+18h] [rbp-70h]
  unsigned int *v49; // [rsp+28h] [rbp-60h] BYREF
  __int64 v50; // [rsp+30h] [rbp-58h] BYREF
  __int64 v51; // [rsp+38h] [rbp-50h]
  __int64 v52; // [rsp+40h] [rbp-48h]
  __int64 v53; // [rsp+48h] [rbp-40h]

  v46 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( ptr[12] > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_gelu");
  if ( *((_QWORD *)ptr + 4) )
  {
    v2 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], ptr[20], ptr + 30);
    v3 = nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], ptr[20], ptr + 30);
    LODWORD(v4) = v2[20];
    v5 = v3;
    if ( (int)v4 > 0 && *((_BYTE *)v2 + 73) && *(_BYTE *)(v3 + 73) && *((_BYTE *)ptr + 73) )
    {
      v6 = *((_QWORD *)v2 + 15);
      if ( (_DWORD)v4 != 1 )
      {
        if ( *((_BYTE *)v2 + 74) && *(_BYTE *)(v5 + 74) && *((_BYTE *)ptr + 74) )
        {
          v6 *= *((_QWORD *)v2 + 16);
          if ( (_DWORD)v4 != 2 )
          {
            if ( *((_BYTE *)v2 + 75) && *(_BYTE *)(v5 + 75) && *((_BYTE *)ptr + 75) )
            {
              v6 *= *((_QWORD *)v2 + 17);
              if ( (_DWORD)v4 != 3 )
              {
                if ( *((_BYTE *)v2 + 76) && *(_BYTE *)(v5 + 76) && *((_BYTE *)ptr + 76) )
                {
                  v6 *= *((_QWORD *)v2 + 18);
                  LODWORD(v4) = 4;
                }
                else
                {
                  LODWORD(v4) = 3;
                }
              }
            }
            else
            {
              LODWORD(v4) = 2;
            }
          }
        }
        else
        {
          LODWORD(v4) = 1;
        }
      }
      v47 = (int)v6;
    }
    else
    {
      v47 = 1LL;
      LODWORD(v4) = 0;
    }
    v50 = 0LL;
    v7 = ptr[20];
    if ( v7 <= 1 )
    {
      v9 = 0LL;
    }
    else
    {
      v8 = 1LL;
      do
        *(&v50 + v8++) = 0LL;
      while ( v7 > (int)v8 );
      v9 = v50;
    }
    v10 = &v50 + (int)v4;
    v48 = (int)v4 + 12LL;
    v11 = (unsigned __int64)&ptr[2 * ((_DWORD)v4 + 1)];
    goto LABEL_27;
  }
  v2 = ptr;
  if ( ptr[4] != 1 )
    v2 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], ptr[20], ptr + 30);
  v33 = v2[20];
  if ( v33 > 0 && *((_BYTE *)v2 + 73) && *((_BYTE *)ptr + 73) )
  {
    v34 = *((_QWORD *)v2 + 15);
    if ( v33 != 1 )
    {
      if ( *((_BYTE *)v2 + 74) && *((_BYTE *)ptr + 74) )
      {
        v34 *= *((_QWORD *)v2 + 16);
        if ( v33 != 2 )
        {
          if ( *((_BYTE *)v2 + 75) && *((_BYTE *)ptr + 75) )
          {
            v34 *= *((_QWORD *)v2 + 17);
            if ( v33 != 3 )
            {
              if ( *((_BYTE *)v2 + 76) && *((_BYTE *)ptr + 76) )
              {
                v34 *= *((_QWORD *)v2 + 18);
                v33 = 4;
              }
              else
              {
                v33 = 3;
              }
            }
          }
          else
          {
            v33 = 2;
          }
        }
      }
      else
      {
        v33 = 1;
      }
    }
    v34 = (int)v34;
  }
  else
  {
    v34 = 1LL;
    v33 = 0;
  }
  v50 = 0LL;
  v35 = ptr[20];
  if ( v35 <= 1 )
  {
    v9 = 0LL;
  }
  else
  {
    v36 = 1LL;
    do
      *(&v50 + v36++) = 0LL;
    while ( v35 > (int)v36 );
    v9 = v50;
  }
  v10 = &v50 + v33;
  v47 = v33 + 12LL;
  v37 = (unsigned int)(v33 + 1);
  v38 = v33;
  v5 = v34;
  v4 = (char *)&ptr[2 * v37];
  v11 = v38;
  while ( 1 )
  {
    if ( v9 == -1 )
      goto LABEL_97;
    v39 = ptr[20];
    v13 = ptr[12];
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v46 + 272);
    v15 = *((_QWORD *)ptr + 7);
    if ( v39 <= 0 )
    {
      v16 = 0LL;
    }
    else
    {
      v16 = *((_QWORD *)ptr + 11) * v9;
      if ( v39 != 1 )
      {
        v16 += *((_QWORD *)ptr + 12) * v51;
        if ( v39 != 2 )
        {
          v16 += *((_QWORD *)ptr + 13) * v52;
          if ( v39 != 3 )
          {
            v17 = v53;
            v18 = *((_QWORD *)ptr + 14);
            if ( v39 != 4 )
              goto LABEL_33;
            v16 += v18 * v53;
          }
        }
      }
    }
    v40 = v2[20];
    v16 += v15;
    v15 = *((_QWORD *)v2 + 7);
    if ( v40 <= 0 )
    {
      v9 = 0LL;
      goto LABEL_91;
    }
    v9 *= *((_QWORD *)v2 + 11);
    if ( v40 != 1 )
    {
      v9 += *((_QWORD *)v2 + 12) * v51;
      if ( v40 != 2 )
      {
        v9 += *((_QWORD *)v2 + 13) * v52;
        if ( v40 != 3 )
          break;
      }
    }
LABEL_91:
    v14(v46, v9 + v15, 0LL, v16, v5, v13);
    v41 = ptr[20];
    if ( (int)v11 >= v41 )
      goto LABEL_96;
    v42 = *v10 + 1;
    *v10 = v42;
    if ( *(_QWORD *)&ptr[2 * v47 + 6] == v42 )
    {
      v43 = 0LL;
      v44 = v41 - 1 - v11;
      while ( 1 )
      {
        v10[v43] = 0LL;
        if ( v43 == v44 )
          break;
        v45 = v10[v43 + 1] + 1;
        v10[++v43] = v45;
        if ( v45 != *(_QWORD *)&v4[8 * v43 + 112] )
          goto LABEL_99;
      }
LABEL_96:
      v50 = -1LL;
LABEL_97:
      if ( v2 != ptr )
        nc_free_tensor(ptr);
      return v2;
    }
LABEL_99:
    v9 = v50;
  }
  v17 = v53;
  v18 = *((_QWORD *)v2 + 14);
  if ( v40 == 4 )
  {
    v9 += v18 * v53;
    goto LABEL_91;
  }
LABEL_33:
  while ( 2 )
  {
    v16 += v18 * v17;
LABEL_34:
    v16 += v15;
    v15 = *(unsigned int *)(v5 + 80);
    v17 = *(_QWORD *)(v5 + 56);
    if ( (int)v15 > 0 )
    {
LABEL_35:
      v19 = *(_QWORD *)(v5 + 88) * v9;
      if ( (_DWORD)v15 != 1 )
      {
        v19 += *(_QWORD *)(v5 + 96) * v51;
        if ( (_DWORD)v15 != 2 )
        {
          v19 += *(_QWORD *)(v5 + 104) * v52;
          if ( (_DWORD)v15 != 3 )
          {
            v18 = v53;
            if ( (_DWORD)v15 == 4 )
            {
              v19 += *(_QWORD *)(v5 + 112) * v53;
              goto LABEL_40;
            }
            continue;
          }
        }
      }
      goto LABEL_40;
    }
    break;
  }
  while ( 1 )
  {
    v19 = 0LL;
LABEL_40:
    v20 = v17 + v19;
    v17 = v2[20];
    v15 = *((_QWORD *)v2 + 7);
    if ( (int)v17 <= 0 )
    {
      v9 = 0LL;
    }
    else
    {
      v9 *= *((_QWORD *)v2 + 11);
      if ( (_DWORD)v17 != 1 )
      {
        v9 += *((_QWORD *)v2 + 12) * v51;
        if ( (_DWORD)v17 != 2 )
        {
          v9 += *((_QWORD *)v2 + 13) * v52;
          if ( (_DWORD)v17 != 3 )
          {
            v18 = v53;
            if ( (_DWORD)v17 != 4 )
              goto LABEL_33;
            v9 += *((_QWORD *)v2 + 14) * v53;
          }
        }
      }
    }
    v14(v46, v9 + v15, v20, v16, v47, v13);
    v21 = ptr[20];
    if ( (int)v4 >= v21 )
      goto LABEL_51;
    v22 = *v10 + 1;
    *v10 = v22;
    if ( *(_QWORD *)&ptr[2 * v48 + 6] == v22 )
      break;
LABEL_53:
    v9 = v50;
LABEL_27:
    if ( v9 == -1 )
      goto LABEL_51;
    v12 = ptr[20];
    v13 = ptr[12];
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v46 + 272);
    v15 = *((_QWORD *)ptr + 7);
    if ( v12 > 0 )
    {
      v16 = *((_QWORD *)ptr + 11) * v9;
      if ( v12 != 1 )
      {
        v16 += *((_QWORD *)ptr + 12) * v51;
        if ( v12 != 2 )
        {
          v16 += *((_QWORD *)ptr + 13) * v52;
          if ( v12 != 3 )
          {
            v17 = v53;
            v18 = *((_QWORD *)ptr + 14);
            goto LABEL_33;
          }
        }
      }
      goto LABEL_34;
    }
    v17 = *(_QWORD *)(v5 + 56);
    v16 = *((_QWORD *)ptr + 7);
    v15 = *(unsigned int *)(v5 + 80);
    if ( (int)v15 > 0 )
      goto LABEL_35;
  }
  v23 = 0LL;
  v24 = v21 - 1 - (_DWORD)v4;
  while ( 1 )
  {
    v10[v23] = 0LL;
    if ( v24 == v23 )
      break;
    v25 = v10[v23 + 1] + 1;
    v10[++v23] = v25;
    if ( v25 != *(_QWORD *)(v11 + 8 * v23 + 112) )
      goto LABEL_53;
  }
LABEL_51:
  v49 = ptr;
  v26 = sub_17800(23, (__int64 *)v2 + 3, (void **)v2 + 4, (__int64)&v49);
  *((_DWORD *)v26 + 10) = 2;
  v27 = v26;
  v28 = nc_malloc(0x10uLL);
  v27[6] = v28;
  v29 = (_QWORD *)v28;
  v30 = nc_dup_tensor(ptr);
  v31 = v27[6];
  *v29 = v30;
  *(_QWORD *)(v31 + 8) = nc_dup_tensor(v5);
  nc_free_tensor((void *)v5);
  nc_free_tensor(ptr);
  return v2;
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

