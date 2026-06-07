// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_slt_mat_set
// Included functions: 3

// ======================================================
// Function: nc_slt_mat_set @ 0x28110
// ======================================================

_QWORD *__fastcall nc_slt_mat_set(_QWORD *ptr, __int64 a2, __m128 _XMM0)
{
  __int64 v5; // rbx
  __int64 v6; // rdx
  __int64 v7; // rax
  _QWORD *v8; // r14
  __int64 v9; // rax
  __int64 v10; // r12
  int v11; // ecx
  __int64 v12; // rdx
  __int64 v13; // r15
  __int64 v14; // rsi
  __int64 v15; // rdi
  int v16; // ecx
  __int64 v17; // rbp
  __int64 v18; // rdx
  unsigned __int64 v19; // r9
  unsigned __int64 v20; // rcx
  int v21; // esi
  __int64 v22; // rax
  __int64 v23; // rdx
  _QWORD *v24; // rax
  unsigned int v27; // [rsp+14h] [rbp-6Ch]
  _QWORD *v28; // [rsp+20h] [rbp-60h] BYREF
  __int64 v29; // [rsp+28h] [rbp-58h] BYREF
  __int64 v30; // [rsp+30h] [rbp-50h]
  __int64 v31; // [rsp+38h] [rbp-48h]
  __int64 v32; // [rsp+40h] [rbp-40h]

  __asm { vmovd   ebp, xmm0 }
  v5 = *(_QWORD *)(ptr[5] + 24LL);
  if ( *((_DWORD *)ptr + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_slt_mat_set");
  v6 = *((unsigned int *)ptr + 20);
  if ( (int)v6 <= 1 || (unsigned __int64)(a2 + ptr[16] - 1) > ptr[15] )
    sub_18270("slt_mat_set", (__int64)ptr, 0LL);
  if ( *((_DWORD *)ptr + 4) == 1 )
  {
    v29 = 0LL;
    v8 = ptr;
LABEL_6:
    v9 = 1LL;
    do
      *(&v29 + v9++) = 0LL;
    while ( (int)v6 > (int)v9 );
    v10 = v29;
    goto LABEL_9;
  }
  v7 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v6, ptr + 15);
  LODWORD(v6) = *((_DWORD *)ptr + 20);
  v29 = 0LL;
  v8 = (_QWORD *)v7;
  if ( (int)v6 > 1 )
    goto LABEL_6;
  v10 = 0LL;
LABEL_9:
  v27 = _EBP;
LABEL_10:
  while ( v10 != -1 )
  {
    v11 = *((_DWORD *)v8 + 20);
    if ( v11 > 0 )
    {
      v12 = v8[11] * v10;
      v13 = v30;
      if ( v11 != 1 )
      {
        v12 += v8[12] * v30;
        if ( v11 != 2 )
        {
          v12 += v8[13] * v31;
          if ( v11 != 3 )
          {
            v14 = v32;
            v15 = v8[14];
            goto LABEL_16;
          }
        }
      }
      goto LABEL_17;
    }
    v16 = *((_DWORD *)ptr + 20);
    v13 = v30;
    v17 = v8[7];
    v14 = ptr[7];
    if ( v16 > 0 )
    {
      while ( 1 )
      {
        v12 = ptr[11] * v10;
        if ( v16 == 1 )
          break;
        v12 += ptr[12] * v13;
        if ( v16 == 2 )
          break;
        v12 += ptr[13] * v31;
        if ( v16 == 3 )
          break;
        v15 = v32;
        if ( v16 == 4 )
        {
          v12 += ptr[14] * v32;
          break;
        }
LABEL_16:
        v12 += v15 * v14;
LABEL_17:
        v16 = *((_DWORD *)ptr + 20);
        v17 = v8[7] + v12;
        v14 = ptr[7];
        if ( v16 <= 0 )
          goto LABEL_40;
      }
    }
    else
    {
LABEL_40:
      v12 = 0LL;
    }
    v18 = v14 + v12;
    v19 = a2 + v13;
    if ( v18 != v17 )
    {
      (*(void (__fastcall **)(__int64, __int64, __int64, unsigned __int64))(v5 + 64))(v5, v17, v18, 4 * v19);
      v19 = a2 + v13;
    }
    v20 = ptr[15];
    if ( v19 < v20 )
      (*(void (__fastcall **)(__int64, unsigned __int64, _QWORD, unsigned __int64, __int64))(v5 + 104))(
        v5,
        v17 + 4 * v19,
        v27,
        v20 - v19,
        2LL);
    v21 = *((_DWORD *)ptr + 20);
    if ( v21 <= 1 )
      goto LABEL_32;
    v30 = v13 + 1;
    if ( ptr[16] == v13 + 1 )
    {
      v22 = 2LL;
      while ( 1 )
      {
        *(&v29 + v22 - 1) = 0LL;
        if ( v21 <= (int)v22 )
          break;
        v23 = *(&v29 + v22) + 1;
        *(&v29 + v22++) = v23;
        if ( v23 != ptr[v22 + 14] )
        {
          v10 = v29;
          goto LABEL_10;
        }
      }
LABEL_32:
      v29 = -1LL;
      break;
    }
  }
  v28 = ptr;
  v24 = sub_17800(35, v8 + 3, (void **)v8 + 4, (__int64)&v28);
  if ( v24 )
    v24[7] = a2;
  if ( ptr != v8 )
    nc_free_tensor(ptr);
  return v8;
}

// ======================================================
// Function: sub_18270 @ 0x18270
// ======================================================

void __fastcall __noreturn sub_18270(const char *a1, __int64 a2, __int64 a3)
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

