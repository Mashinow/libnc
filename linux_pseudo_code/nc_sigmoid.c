// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sigmoid
// Included functions: 2

// ======================================================
// Function: nc_sigmoid @ 0x240A0
// ======================================================

_QWORD *__fastcall nc_sigmoid(_QWORD *ptr)
{
  __int64 v2; // r12
  _QWORD *v3; // r15
  int v4; // r13d
  __int64 v5; // rax
  int v6; // ecx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 *v9; // rbx
  __int64 v10; // rdx
  int v11; // edi
  __int64 v12; // r13
  char *v13; // r14
  int v14; // r12d
  int v15; // ecx
  __int64 v16; // rsi
  __int64 v17; // rdx
  __int64 v18; // rdi
  __int64 v19; // r11
  int v20; // ecx
  int v21; // ecx
  __int64 v22; // rax
  __int64 v23; // rax
  int v24; // ecx
  __int64 v25; // rdx
  _QWORD *v26; // rax
  _QWORD *v27; // rbx
  _QWORD *v28; // rax
  __int64 v30; // [rsp+0h] [rbp-78h]
  __int64 v31; // [rsp+8h] [rbp-70h]
  _QWORD *v32; // [rsp+18h] [rbp-60h] BYREF
  __int64 v33; // [rsp+20h] [rbp-58h] BYREF
  __int64 v34; // [rsp+28h] [rbp-50h]
  __int64 v35; // [rsp+30h] [rbp-48h]
  __int64 v36; // [rsp+38h] [rbp-40h]

  v2 = *(_QWORD *)(ptr[5] + 24LL);
  if ( *((_DWORD *)ptr + 12) > 1u )
    nc_error("unsupported type for %s\n", (char)"nc_sigmoid");
  v3 = ptr;
  if ( *((_DWORD *)ptr + 4) != 1 )
    v3 = (_QWORD *)nc_new_tensor_nz(
                     *(_QWORD *)(ptr[5] + 24LL),
                     *((unsigned int *)ptr + 12),
                     *((unsigned int *)ptr + 20),
                     ptr + 15);
  v4 = *((_DWORD *)v3 + 20);
  if ( v4 > 0 && *((_BYTE *)v3 + 73) && *((_BYTE *)ptr + 73) )
  {
    v5 = v3[15];
    if ( v4 != 1 )
    {
      if ( *((_BYTE *)v3 + 74) && *((_BYTE *)ptr + 74) )
      {
        v5 *= v3[16];
        if ( v4 != 2 )
        {
          if ( *((_BYTE *)v3 + 75) && *((_BYTE *)ptr + 75) )
          {
            v5 *= v3[17];
            if ( v4 != 3 )
            {
              if ( *((_BYTE *)v3 + 76) && *((_BYTE *)ptr + 76) )
              {
                v5 *= v3[18];
                v4 = 4;
              }
              else
              {
                v4 = 3;
              }
            }
          }
          else
          {
            v4 = 2;
          }
        }
      }
      else
      {
        v4 = 1;
      }
    }
    v30 = (int)v5;
  }
  else
  {
    v30 = 1LL;
    v4 = 0;
  }
  v33 = 0LL;
  v6 = *((_DWORD *)ptr + 20);
  if ( v6 <= 1 )
  {
    v8 = 0LL;
  }
  else
  {
    v7 = 1LL;
    do
      *(&v33 + v7++) = 0LL;
    while ( v6 > (int)v7 );
    v8 = v33;
  }
  v9 = &v33 + v4;
  v31 = v4 + 12LL;
  v10 = (unsigned int)(v4 + 1);
  v11 = v4;
  v12 = v2;
  v13 = (char *)&ptr[v10];
  v14 = v11;
  while ( v8 != -1 )
  {
    v15 = *((_DWORD *)ptr + 20);
    v16 = ptr[7];
    if ( v15 > 0 )
    {
      v17 = ptr[11] * v8;
      if ( v15 != 1 )
      {
        v17 += ptr[12] * v34;
        if ( v15 != 2 )
        {
          v17 += ptr[13] * v35;
          if ( v15 != 3 )
          {
            v18 = v36;
            v19 = ptr[14];
            goto LABEL_30;
          }
        }
      }
      goto LABEL_31;
    }
    v20 = *((_DWORD *)v3 + 20);
    v17 = ptr[7];
    v16 = v3[7];
    if ( v20 > 0 )
    {
      while ( 1 )
      {
        v8 *= v3[11];
        if ( v20 == 1 )
          break;
        v8 += v3[12] * v34;
        if ( v20 == 2 )
          break;
        v8 += v3[13] * v35;
        if ( v20 == 3 )
          break;
        v18 = v36;
        v19 = v3[14];
        if ( v20 == 4 )
        {
          v8 += v19 * v36;
          break;
        }
LABEL_30:
        v17 += v19 * v18;
LABEL_31:
        v20 = *((_DWORD *)v3 + 20);
        v17 += v16;
        v16 = v3[7];
        if ( v20 <= 0 )
          goto LABEL_50;
      }
    }
    else
    {
LABEL_50:
      v8 = 0LL;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD))(v12 + 224))(
      v12,
      v8 + v16,
      v17,
      v30,
      *((unsigned int *)ptr + 12));
    v21 = *((_DWORD *)ptr + 20);
    if ( v21 <= v14 )
      goto LABEL_42;
    v22 = *v9 + 1;
    *v9 = v22;
    if ( ptr[v31 + 3] == v22 )
    {
      v23 = 0LL;
      v24 = v21 - 1 - v14;
      while ( 1 )
      {
        v9[v23] = 0LL;
        if ( v24 == v23 )
          break;
        v25 = v9[v23 + 1] + 1;
        v9[++v23] = v25;
        if ( v25 != *(_QWORD *)&v13[8 * v23 + 112] )
          goto LABEL_48;
      }
LABEL_42:
      v33 = -1LL;
      break;
    }
LABEL_48:
    v8 = v33;
  }
  v32 = ptr;
  v26 = sub_17800(20, v3 + 3, (void **)v3 + 4, (__int64)&v32);
  v27 = v26;
  if ( v26 )
  {
    *((_DWORD *)v26 + 10) = 1;
    v28 = (_QWORD *)nc_malloc(8uLL);
    v27[6] = v28;
    *v28 = nc_dup_tensor(v3);
  }
  if ( v3 != ptr )
    nc_free_tensor(ptr);
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

