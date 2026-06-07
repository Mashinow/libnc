// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_neg
// Included functions: 2

// ======================================================
// Function: nc_neg @ 0x1DB40
// ======================================================

__int64 __fastcall nc_neg(_QWORD *ptr)
{
  __int64 v2; // rsi
  __int64 v3; // rax
  int v4; // ebp
  __int64 v5; // r13
  __int64 v6; // r12
  int v7; // ecx
  __int64 v8; // rax
  __int64 v9; // rsi
  __int64 *v10; // rbx
  int v11; // ecx
  __int64 v12; // r10
  __int64 v13; // rdx
  __int64 v14; // rdi
  __int64 v15; // r11
  int v16; // ecx
  int v17; // ecx
  __int64 v18; // rax
  __int64 v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  __int64 v23; // [rsp+0h] [rbp-78h]
  __int64 v24; // [rsp+8h] [rbp-70h]
  _QWORD *v25; // [rsp+18h] [rbp-60h] BYREF
  __int64 v26; // [rsp+20h] [rbp-58h] BYREF
  __int64 v27; // [rsp+28h] [rbp-50h]
  __int64 v28; // [rsp+30h] [rbp-48h]
  __int64 v29; // [rsp+38h] [rbp-40h]

  v2 = *((unsigned int *)ptr + 12);
  v23 = *(_QWORD *)(ptr[5] + 24LL);
  if ( (_DWORD)v2 )
    nc_error("unsupported type for %s\n", (char)"nc_neg");
  v3 = nc_new_tensor_nz(v23, v2, *((unsigned int *)ptr + 20), ptr + 15);
  v4 = *(_DWORD *)(v3 + 80);
  v5 = v3;
  if ( v4 > 0 && *(_BYTE *)(v3 + 73) && *((_BYTE *)ptr + 73) )
  {
    v6 = *(_QWORD *)(v3 + 120);
    if ( v4 != 1 )
    {
      if ( *(_BYTE *)(v3 + 74) && *((_BYTE *)ptr + 74) )
      {
        v6 *= *(_QWORD *)(v3 + 128);
        if ( v4 != 2 )
        {
          if ( *(_BYTE *)(v3 + 75) && *((_BYTE *)ptr + 75) )
          {
            v6 *= *(_QWORD *)(v3 + 136);
            if ( v4 != 3 )
            {
              if ( *(_BYTE *)(v3 + 76) && *((_BYTE *)ptr + 76) )
              {
                v6 *= *(_QWORD *)(v3 + 144);
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
    v24 = (int)v6;
  }
  else
  {
    v24 = 1LL;
    v4 = 0;
  }
  v26 = 0LL;
  v7 = *((_DWORD *)ptr + 20);
  if ( v7 <= 1 )
  {
    v9 = 0LL;
  }
  else
  {
    v8 = 1LL;
    do
      *(&v26 + v8++) = 0LL;
    while ( v7 > (int)v8 );
    v9 = v26;
  }
  v10 = &v26 + v4;
  while ( v9 != -1 )
  {
    v11 = *((_DWORD *)ptr + 20);
    v12 = ptr[7];
    if ( v11 > 0 )
    {
      v13 = ptr[11] * v9;
      if ( v11 != 1 )
      {
        v13 += ptr[12] * v27;
        if ( v11 != 2 )
        {
          v13 += ptr[13] * v28;
          if ( v11 != 3 )
          {
            v14 = v29;
            v15 = ptr[14];
            goto LABEL_27;
          }
        }
      }
      goto LABEL_28;
    }
    v16 = *(_DWORD *)(v5 + 80);
    v14 = *(_QWORD *)(v5 + 56);
    v13 = ptr[7];
    if ( v16 > 0 )
    {
      while ( 1 )
      {
        v9 *= *(_QWORD *)(v5 + 88);
        if ( v16 == 1 )
          break;
        v9 += *(_QWORD *)(v5 + 96) * v27;
        if ( v16 == 2 )
          break;
        v9 += *(_QWORD *)(v5 + 104) * v28;
        if ( v16 == 3 )
          break;
        v12 = v29;
        v15 = *(_QWORD *)(v5 + 112);
        if ( v16 == 4 )
        {
          v9 += v15 * v29;
          break;
        }
LABEL_27:
        v13 += v15 * v14;
LABEL_28:
        v16 = *(_DWORD *)(v5 + 80);
        v13 += v12;
        v14 = *(_QWORD *)(v5 + 56);
        if ( v16 <= 0 )
          goto LABEL_42;
      }
    }
    else
    {
LABEL_42:
      v9 = 0LL;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v23 + 192))(v23, v14 + v9, v13, v24);
    v17 = *((_DWORD *)ptr + 20);
    if ( v17 <= v4 )
      break;
    v18 = *v10 + 1;
    *v10 = v18;
    if ( v18 == ptr[v4 + 15] )
    {
      v19 = 0LL;
      v20 = v17 - 1 - v4;
      do
      {
        v10[v19] = 0LL;
        if ( v20 == v19 )
          goto LABEL_39;
        v21 = v10[v19 + 1] + 1;
        v10[++v19] = v21;
      }
      while ( v21 == ptr[(unsigned int)(v4 + 1) + 14 + v19] );
    }
    v9 = v26;
  }
LABEL_39:
  v25 = ptr;
  sub_17800(8, (__int64 *)(v5 + 24), (void **)(v5 + 32), (__int64)&v25);
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

