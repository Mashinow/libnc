// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_reduce_sum_sqr
// Included functions: 2

// ======================================================
// Function: nc_reduce_sum_sqr @ 0x1C4A0
// ======================================================

__int64 __fastcall nc_reduce_sum_sqr(_QWORD *ptr)
{
  __int64 v1; // rax
  __int64 v2; // rbp
  __int64 v3; // rax
  int v4; // esi
  __int64 v5; // r13
  __int64 v6; // r12
  int v7; // ebx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 *v10; // r15
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v16; // [rsp+0h] [rbp-78h]
  _QWORD *v17; // [rsp+18h] [rbp-60h] BYREF
  __int64 v18[11]; // [rsp+20h] [rbp-58h] BYREF

  v1 = ptr[5];
  v2 = *(_QWORD *)(v1 + 24);
  if ( *((_DWORD *)ptr + 12) > 1u )
    nc_error("unsupported type for %s\n", (char)"nc_reduce_sum_sqr");
  v3 = nc_new_tensor(*(_QWORD *)(v1 + 24), 0LL, 0LL, 0LL);
  v4 = *((_DWORD *)ptr + 20);
  v5 = v3;
  if ( v4 <= 0 )
  {
    v18[0] = 0LL;
    v7 = 0;
    v9 = 0LL;
    v16 = 1LL;
    goto LABEL_17;
  }
  if ( !*((_BYTE *)ptr + 73) )
  {
    v16 = 1LL;
    v7 = 0;
    goto LABEL_13;
  }
  v6 = ptr[15];
  if ( v4 == 1 )
  {
    v7 = 1;
    goto LABEL_12;
  }
  if ( !*((_BYTE *)ptr + 74) )
  {
    v7 = 1;
LABEL_40:
    v18[0] = 0LL;
    v16 = (int)v6;
LABEL_14:
    v8 = 1LL;
    do
      v18[v8++] = 0LL;
    while ( v4 > (int)v8 );
    v9 = v18[0];
    goto LABEL_17;
  }
  v6 *= ptr[16];
  if ( v4 == 2 )
  {
    v7 = 2;
    goto LABEL_12;
  }
  if ( !*((_BYTE *)ptr + 75) )
  {
    v7 = 2;
    goto LABEL_40;
  }
  v6 *= ptr[17];
  if ( v4 == 3 )
  {
    v7 = 3;
    goto LABEL_12;
  }
  if ( !*((_BYTE *)ptr + 76) )
  {
    v7 = 3;
    goto LABEL_40;
  }
  v6 *= ptr[18];
  v7 = 4;
LABEL_12:
  v16 = (int)v6;
LABEL_13:
  v18[0] = 0LL;
  if ( v4 > 1 )
    goto LABEL_14;
  v9 = 0LL;
LABEL_17:
  v10 = &v18[v7];
  while ( v9 != -1 )
  {
    if ( v4 <= 0 )
      goto LABEL_24;
    v11 = ptr[11] * v9;
    if ( v4 != 1 )
    {
      v11 += ptr[12] * v18[1];
      if ( v4 != 2 )
      {
        v11 += ptr[13] * v18[2];
        if ( v4 != 3 )
        {
          if ( v4 != 4 )
          {
LABEL_24:
            v11 = 0LL;
            goto LABEL_25;
          }
          v11 += ptr[14] * v18[3];
        }
      }
    }
LABEL_25:
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v2 + 384))(
      v2,
      *(_QWORD *)(v5 + 56),
      0LL,
      ptr[7] + v11,
      0LL,
      v16,
      1LL,
      *((unsigned int *)ptr + 12));
    v4 = *((_DWORD *)ptr + 20);
    if ( v4 <= v7 )
      break;
    v12 = *v10 + 1;
    *v10 = v12;
    if ( v12 == ptr[v7 + 15] )
    {
      v13 = 0LL;
      do
      {
        v10[v13] = 0LL;
        if ( v13 == v4 - 1 - v7 )
          goto LABEL_30;
        v14 = v10[v13 + 1] + 1;
        v10[++v13] = v14;
      }
      while ( v14 == ptr[(unsigned int)(v7 + 1) + 14 + v13] );
    }
    v9 = v18[0];
  }
LABEL_30:
  v17 = ptr;
  sub_17800(0, (__int64 *)(v5 + 24), (void **)(v5 + 32), (__int64)&v17);
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

