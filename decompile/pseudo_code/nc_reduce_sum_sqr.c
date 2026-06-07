// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reduce_sum_sqr
// Included functions: 1

// ======================================================
// Function: nc_reduce_sum_sqr @ 0x66A1DCC0
// ======================================================

_QWORD *__fastcall nc_reduce_sum_sqr(__int64 a1)
{
  __int64 v1; // r12
  __int64 v3; // rsi
  _QWORD *v4; // rbp
  __int64 v5; // rdi
  __int64 *v6; // r13
  _DWORD *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  int v12; // eax
  __int64 v13; // r13
  int v14; // edi
  __int64 v15; // rdx
  __int64 *v16; // r8
  __int64 v17; // rcx
  __int64 *v18; // rbx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 *v21; // rdx
  __int64 v22; // rcx
  __int64 *v24; // rax
  __int64 v25; // rsi
  __int64 *v26; // r12
  _QWORD *v27; // rbx
  _QWORD *v28; // rax
  __int64 v29; // rdx
  __int64 v30; // rax
  __int64 v31; // rax
  __int64 *v32; // rcx
  __int64 v33[13]; // [rsp+50h] [rbp-68h] BYREF

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(_DWORD *)(a1 + 48) > 1u )
    nc_error("unsupported type for %s\n", "nc_reduce_sum_sqr");
  v3 = *(_QWORD *)(v1 + 16);
  v4 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v4 )
  {
    MEMORY[0x18] = v3;
    BUG();
  }
  memset(v4, 0, 0x98ui64);
  *((_BYTE *)v4 + 72) = 1;
  v4[3] = v3;
  v5 = nc_type_size_table[0];
  *((_DWORD *)v4 + 4) = 1;
  v4[15] = 1i64;
  v6 = *(__int64 **)(v1 + 16);
  v4[8] = 1i64;
  v7 = aligned_malloc(0x38ui64, 0x40ui64);
  v7[4] = 1;
  *((_QWORD *)v7 + 3) = v1;
  v8 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(v1 + 48))(v1, v7 + 10, v5);
  *((_QWORD *)v7 + 4) = v8;
  if ( !v8 )
    nc_error("not enough device memory");
  v9 = *v6;
  *((_QWORD *)v7 + 6) = v5;
  *(_QWORD *)(v9 + 8) = v7;
  *(_QWORD *)v7 = v9;
  v10 = *((_QWORD *)v7 + 5);
  *((_QWORD *)v7 + 1) = v6;
  *v6 = (__int64)v7;
  v4[7] = v10;
  v11 = *(_QWORD *)(v3 + 16);
  v4[5] = v7;
  *(_QWORD *)(v11 + 8) = v4;
  *v4 = v11;
  v4[1] = v3 + 16;
  *(_QWORD *)(v3 + 16) = v4;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(v1 + 104))(v1, v4[7], 0i64, v5, 0);
  v12 = *(_DWORD *)(a1 + 80);
  if ( v12 <= 0 )
  {
    v13 = 1i64;
    v14 = 0;
    v16 = v33;
    v17 = 0i64;
    v33[0] = 0i64;
    goto LABEL_18;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v13 = 1i64;
    v14 = 0;
    goto LABEL_14;
  }
  v13 = *(_QWORD *)(a1 + 120);
  if ( v12 == 1 )
  {
    v14 = 1;
    goto LABEL_13;
  }
  if ( !*(_BYTE *)(a1 + 74) )
  {
    v14 = 1;
    goto LABEL_52;
  }
  v13 *= *(_QWORD *)(a1 + 128);
  if ( v12 == 2 )
  {
    v14 = 2;
    goto LABEL_13;
  }
  if ( !*(_BYTE *)(a1 + 75) )
  {
    v14 = 2;
    goto LABEL_52;
  }
  v13 *= *(_QWORD *)(a1 + 136);
  if ( v12 == 3 )
  {
    v14 = 3;
    goto LABEL_13;
  }
  if ( !*(_BYTE *)(a1 + 76) )
  {
    v14 = 3;
LABEL_52:
    v33[0] = 0i64;
    v13 = (int)v13;
LABEL_15:
    v15 = 1i64;
    v16 = v33;
    do
      v33[v15++] = 0i64;
    while ( v12 > (int)v15 );
    v17 = v33[0];
    goto LABEL_18;
  }
  v13 *= *(_QWORD *)(a1 + 144);
  v14 = 4;
LABEL_13:
  v13 = (int)v13;
LABEL_14:
  v33[0] = 0i64;
  if ( v12 > 1 )
    goto LABEL_15;
  v17 = 0i64;
  v16 = v33;
LABEL_18:
  v18 = &v33[v14];
  while ( v17 != -1 )
  {
    if ( v12 <= 0 )
      goto LABEL_25;
    v19 = *(_QWORD *)(a1 + 88) * v17;
    if ( v12 != 1 )
    {
      v19 += *(_QWORD *)(a1 + 96) * v33[1];
      if ( v12 != 2 )
      {
        v19 += *(_QWORD *)(a1 + 104) * v33[2];
        if ( v12 != 3 )
        {
          if ( v12 != 4 )
          {
LABEL_25:
            v19 = 0i64;
            goto LABEL_26;
          }
          v19 += *(_QWORD *)(a1 + 112) * v33[3];
        }
      }
    }
LABEL_26:
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v1 + 384))(
      v1,
      v4[7],
      0i64,
      *(_QWORD *)(a1 + 56) + v19,
      0i64,
      v13,
      1i64,
      *(_DWORD *)(a1 + 48));
    v12 = *(_DWORD *)(a1 + 80);
    if ( v12 <= v14 )
      goto LABEL_31;
    v20 = *v18 + 1;
    *v18 = v20;
    if ( v20 == *(_QWORD *)(a1 + 8 * (v14 + 12i64) + 24) )
    {
      v21 = 0i64;
      v16 = (__int64 *)(unsigned int)(v12 - 1 - v14);
      while ( 1 )
      {
        v18[(_QWORD)v21] = 0i64;
        if ( v21 == v16 )
          break;
        v22 = v18[(_QWORD)v21 + 1] + 1;
        v18[(_QWORD)v21 + 1] = v22;
        v21 = (__int64 *)((char *)v21 + 1);
        if ( v22 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v14 + 1) + 8i64 * (_QWORD)v21 + 112) )
          goto LABEL_34;
      }
LABEL_31:
      v33[0] = -1i64;
      break;
    }
LABEL_34:
    v17 = v33[0];
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v24 = (__int64 *)((__int64 (__fastcall *)(__int64, __int64, __int64 *))aligned_malloc)(8i64, 64i64, v16);
    v25 = v4[3];
    v26 = v24;
    *v24 = *(_QWORD *)(a1 + 32);
    v27 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(128i64, 64i64);
    if ( !v27 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v27, 0, 0x80ui64);
    *((_DWORD *)v27 + 4) = 1;
    *((_DWORD *)v27 + 6) = 1;
    v28 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(8i64, 64i64);
    v29 = *v26;
    v27[4] = v28;
    if ( v29 )
    {
      ++*(_DWORD *)(v29 + 16);
      *v28 = v29;
    }
    else
    {
      *v28 = 0i64;
    }
    v30 = *(_QWORD *)(v25 + 72);
    *(_QWORD *)(v25 + 72) = v30 + 1;
    v27[12] = v30;
    v31 = *(_QWORD *)(v25 + 32);
    *(_QWORD *)(v31 + 8) = v27;
    *v27 = v31;
    v27[1] = v25 + 32;
    *(_QWORD *)(v25 + 32) = v27;
    _aligned_free(v26);
    v32 = (__int64 *)v4[4];
    if ( v32 )
      nc_free_node(v32);
    v4[4] = v27;
  }
  nc_free_tensor((_DWORD *)a1);
  return v4;
}

