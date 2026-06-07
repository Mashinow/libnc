// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_slt_mat_set
// Included functions: 2

// ======================================================
// Function: nc_slt_mat_set @ 0x66A2CB30
// ======================================================

// local variable allocation has failed, the output may be wrong!
_QWORD *__fastcall nc_slt_mat_set(__int64 a1, __int64 a2, double _XMM2_8)
{
  __int64 v3; // rsi
  int v7; // r8d
  _QWORD *v8; // rax
  _QWORD *v9; // r12
  __int64 v10; // rax
  __int64 v11; // r14
  int v12; // ecx
  __int64 v13; // r15
  __int64 v14; // rax
  __int64 v15; // r13
  __int64 v16; // rdx
  __int64 v17; // r8
  __int64 v18; // r8
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // r9
  int v21; // r8d
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 *v25; // rax
  __int64 v26; // r13
  __int64 *v27; // r14
  _QWORD *v28; // rsi
  _QWORD *v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 *v33; // rcx
  unsigned int v34; // [rsp+3Ch] [rbp-6Ch]
  __int64 v35; // [rsp+40h] [rbp-68h] BYREF
  __int64 v36; // [rsp+48h] [rbp-60h]
  __int64 v37; // [rsp+50h] [rbp-58h]
  __int64 v38; // [rsp+58h] [rbp-50h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  __asm { vmovd   edi, xmm2 }
  if ( *(_DWORD *)(a1 + 48) )
    nc_error("unsupported type for %s\n", "nc_slt_mat_set");
  v7 = *(_DWORD *)(a1 + 80);
  if ( v7 <= 1 || (unsigned __int64)(a2 + *(_QWORD *)(a1 + 128) - 1) > *(_QWORD *)(a1 + 120) )
    sub_66A16930("slt_mat_set", a1, 0i64);
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    v35 = 0i64;
    v9 = (_QWORD *)a1;
LABEL_6:
    v10 = 1i64;
    do
      *(&v35 + v10++) = 0i64;
    while ( v7 > (int)v10 );
    v11 = v35;
    goto LABEL_9;
  }
  v8 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), 0, v7, a1 + 120);
  v7 = *(_DWORD *)(a1 + 80);
  v35 = 0i64;
  v9 = v8;
  if ( v7 > 1 )
    goto LABEL_6;
  v11 = 0i64;
LABEL_9:
  v34 = _EDI;
LABEL_10:
  while ( v11 != -1 )
  {
    v12 = *((_DWORD *)v9 + 20);
    v13 = v9[7];
    if ( v12 > 0 )
    {
      v14 = v9[11] * v11;
      v15 = v36;
      if ( v12 != 1 )
      {
        v14 += v9[12] * v36;
        if ( v12 != 2 )
        {
          v14 += v9[13] * v37;
          if ( v12 != 3 )
          {
            v16 = v38;
            v17 = v9[14];
            goto LABEL_16;
          }
        }
      }
      goto LABEL_17;
    }
    v16 = *(unsigned int *)(a1 + 80);
    v15 = v36;
    v14 = *(_QWORD *)(a1 + 56);
    if ( (int)v16 > 0 )
    {
      while ( 1 )
      {
        v17 = *(_QWORD *)(a1 + 88) * v11;
        if ( (_DWORD)v16 == 1 )
          break;
        v17 += *(_QWORD *)(a1 + 96) * v15;
        if ( (_DWORD)v16 == 2 )
          break;
        v17 += *(_QWORD *)(a1 + 104) * v37;
        if ( (_DWORD)v16 == 3 )
          break;
        if ( (_DWORD)v16 == 4 )
        {
          v17 += *(_QWORD *)(a1 + 112) * v38;
          break;
        }
LABEL_16:
        v14 += v17 * v16;
LABEL_17:
        v16 = *(unsigned int *)(a1 + 80);
        v13 += v14;
        v14 = *(_QWORD *)(a1 + 56);
        if ( (int)v16 <= 0 )
          goto LABEL_39;
      }
    }
    else
    {
LABEL_39:
      v17 = 0i64;
    }
    v18 = v14 + v17;
    v19 = a2 + v15;
    if ( v18 != v13 )
      (*(void (__fastcall **)(__int64, __int64, __int64, unsigned __int64))(v3 + 64))(v3, v13, v18, 4 * v19);
    v20 = *(_QWORD *)(a1 + 120);
    if ( v19 < v20 )
      (*(void (__fastcall **)(__int64, unsigned __int64, _QWORD, unsigned __int64, int))(v3 + 104))(
        v3,
        v13 + 4 * v19,
        v34,
        v20 - v19,
        2);
    v21 = *(_DWORD *)(a1 + 80);
    if ( v21 <= 1 )
      goto LABEL_32;
    v36 = v15 + 1;
    if ( v15 + 1 == *(_QWORD *)(a1 + 128) )
    {
      v22 = 2i64;
      while ( 1 )
      {
        *(&v35 + v22 - 1) = 0i64;
        if ( v21 <= (int)v22 )
          break;
        v23 = *(&v35 + v22) + 1;
        *(&v35 + v22++) = v23;
        if ( v23 != *(_QWORD *)(a1 + 8 * v22 + 112) )
        {
          v11 = v35;
          goto LABEL_10;
        }
      }
LABEL_32:
      v35 = -1i64;
      break;
    }
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v25 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v26 = v9[3];
    v27 = v25;
    *v25 = *(_QWORD *)(a1 + 32);
    v28 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v28 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v28, 0, 0x80ui64);
    *((_DWORD *)v28 + 4) = 1;
    *((_DWORD *)v28 + 5) = 35;
    *((_DWORD *)v28 + 6) = 1;
    v29 = aligned_malloc(8ui64, 0x40ui64);
    v30 = *v27;
    v28[4] = v29;
    if ( v30 )
    {
      ++*(_DWORD *)(v30 + 16);
      *v29 = v30;
    }
    else
    {
      *v29 = 0i64;
    }
    v31 = *(_QWORD *)(v26 + 72);
    *(_QWORD *)(v26 + 72) = v31 + 1;
    v28[12] = v31;
    v32 = *(_QWORD *)(v26 + 32);
    *(_QWORD *)(v32 + 8) = v28;
    *v28 = v32;
    v28[1] = v26 + 32;
    *(_QWORD *)(v26 + 32) = v28;
    _aligned_free(v27);
    v33 = (__int64 *)v9[4];
    if ( v33 )
      nc_free_node(v33);
    v9[4] = v28;
    v28[7] = a2;
  }
  if ( (_QWORD *)a1 != v9 )
    nc_free_tensor((_DWORD *)a1);
  return v9;
}

// ======================================================
// Function: sub_66A16930 @ 0x66A16930
// ======================================================

void __fastcall __noreturn sub_66A16930(const char *a1, __int64 a2, __int64 a3)
{
  printf("dimension error for %s: ", a1);
  nc_dump_dims("x1", a2);
  if ( a3 )
  {
    printf(", ");
    nc_dump_dims("x2", a3);
  }
  putchar(10);
  abort();
}

