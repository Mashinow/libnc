// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_relu
// Included functions: 2

// ======================================================
// Function: nc_relu @ 0x25050
// ======================================================

__int64 __fastcall nc_relu(_QWORD *ptr)
{
  __int64 v2; // rsi
  __int64 v3; // r12
  __int64 v4; // rax
  int v5; // r13d
  __int64 v6; // r15
  __int64 v7; // rax
  int v8; // ecx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 *v11; // rbx
  __int64 v12; // rdx
  int v13; // edi
  __int64 v14; // r13
  char *v15; // r14
  int v16; // r12d
  int v17; // ecx
  __int64 v18; // rsi
  __int64 v19; // rdx
  __int64 v20; // rdi
  __int64 v21; // r11
  int v22; // ecx
  int v23; // ecx
  __int64 v24; // rax
  __int64 v25; // rax
  int v26; // ecx
  __int64 v27; // rdx
  _QWORD *v28; // rax
  _QWORD *v29; // rbx
  _QWORD *v30; // rax
  __int64 v32; // [rsp+0h] [rbp-78h]
  __int64 v33; // [rsp+8h] [rbp-70h]
  _QWORD *v34; // [rsp+18h] [rbp-60h] BYREF
  __int64 v35; // [rsp+20h] [rbp-58h] BYREF
  __int64 v36; // [rsp+28h] [rbp-50h]
  __int64 v37; // [rsp+30h] [rbp-48h]
  __int64 v38; // [rsp+38h] [rbp-40h]

  v2 = *((unsigned int *)ptr + 12);
  v3 = *(_QWORD *)(ptr[5] + 24LL);
  if ( (unsigned int)v2 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_relu");
  v4 = nc_new_tensor_nz(v3, v2, *((unsigned int *)ptr + 20), ptr + 15);
  v5 = *(_DWORD *)(v4 + 80);
  v6 = v4;
  if ( v5 > 0 && *(_BYTE *)(v4 + 73) && *((_BYTE *)ptr + 73) )
  {
    v7 = *(_QWORD *)(v4 + 120);
    if ( v5 != 1 )
    {
      if ( *(_BYTE *)(v6 + 74) && *((_BYTE *)ptr + 74) )
      {
        v7 *= *(_QWORD *)(v6 + 128);
        if ( v5 != 2 )
        {
          if ( *(_BYTE *)(v6 + 75) && *((_BYTE *)ptr + 75) )
          {
            v7 *= *(_QWORD *)(v6 + 136);
            if ( v5 != 3 )
            {
              if ( *(_BYTE *)(v6 + 76) && *((_BYTE *)ptr + 76) )
              {
                v7 *= *(_QWORD *)(v6 + 144);
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
    v32 = (int)v7;
  }
  else
  {
    v32 = 1LL;
    v5 = 0;
  }
  v35 = 0LL;
  v8 = *((_DWORD *)ptr + 20);
  if ( v8 <= 1 )
  {
    v10 = 0LL;
  }
  else
  {
    v9 = 1LL;
    do
      *(&v35 + v9++) = 0LL;
    while ( v8 > (int)v9 );
    v10 = v35;
  }
  v11 = &v35 + v5;
  v33 = v5 + 12LL;
  v12 = (unsigned int)(v5 + 1);
  v13 = v5;
  v14 = v3;
  v15 = (char *)&ptr[v12];
  v16 = v13;
  while ( v10 != -1 )
  {
    v17 = *((_DWORD *)ptr + 20);
    v18 = ptr[7];
    if ( v17 > 0 )
    {
      v19 = ptr[11] * v10;
      if ( v17 != 1 )
      {
        v19 += ptr[12] * v36;
        if ( v17 != 2 )
        {
          v19 += ptr[13] * v37;
          if ( v17 != 3 )
          {
            v20 = v38;
            v21 = ptr[14];
            goto LABEL_28;
          }
        }
      }
      goto LABEL_29;
    }
    v22 = *(_DWORD *)(v6 + 80);
    v19 = ptr[7];
    v18 = *(_QWORD *)(v6 + 56);
    if ( v22 > 0 )
    {
      while ( 1 )
      {
        v10 *= *(_QWORD *)(v6 + 88);
        if ( v22 == 1 )
          break;
        v10 += *(_QWORD *)(v6 + 96) * v36;
        if ( v22 == 2 )
          break;
        v10 += *(_QWORD *)(v6 + 104) * v37;
        if ( v22 == 3 )
          break;
        v20 = v38;
        v21 = *(_QWORD *)(v6 + 112);
        if ( v22 == 4 )
        {
          v10 += v21 * v38;
          break;
        }
LABEL_28:
        v19 += v21 * v20;
LABEL_29:
        v22 = *(_DWORD *)(v6 + 80);
        v19 += v18;
        v18 = *(_QWORD *)(v6 + 56);
        if ( v22 <= 0 )
          goto LABEL_46;
      }
    }
    else
    {
LABEL_46:
      v10 = 0LL;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD))(v14 + 256))(
      v14,
      v10 + v18,
      v19,
      v32,
      *((unsigned int *)ptr + 12));
    v23 = *((_DWORD *)ptr + 20);
    if ( v23 <= v16 )
      goto LABEL_40;
    v24 = *v11 + 1;
    *v11 = v24;
    if ( v24 == ptr[v33 + 3] )
    {
      v25 = 0LL;
      v26 = v23 - 1 - v16;
      while ( 1 )
      {
        v11[v25] = 0LL;
        if ( v26 == v25 )
          break;
        v27 = v11[v25 + 1] + 1;
        v11[++v25] = v27;
        if ( v27 != *(_QWORD *)&v15[8 * v25 + 112] )
          goto LABEL_44;
      }
LABEL_40:
      v35 = -1LL;
      break;
    }
LABEL_44:
    v10 = v35;
  }
  v34 = ptr;
  v28 = sub_17800(22, (__int64 *)(v6 + 24), (void **)(v6 + 32), (__int64)&v34);
  v29 = v28;
  if ( v28 )
  {
    *((_DWORD *)v28 + 10) = 1;
    v30 = (_QWORD *)nc_malloc(8uLL);
    v29[6] = v30;
    *v30 = nc_dup_tensor(ptr);
  }
  nc_free_tensor(ptr);
  return v6;
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

