// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_select
// Included functions: 3

// ======================================================
// Function: nc_select @ 0x1FE20
// ======================================================

__int64 __fastcall nc_select(_QWORD *ptr, _QWORD *a2, _QWORD *a3)
{
  __int64 v6; // rdi
  __int64 v7; // rdx
  __int64 v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rax
  int v14; // edi
  __int64 v15; // r12
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r11
  __int64 *v19; // rbx
  __int64 v20; // rdx
  int v21; // eax
  __int64 v22; // r8
  __int64 v23; // rcx
  __int64 v24; // rsi
  int v25; // eax
  int v26; // eax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rdx
  _QWORD *v30; // rax
  _QWORD *v31; // rbx
  _QWORD *v32; // rax
  int v34; // [rsp+Ch] [rbp-8Ch]
  __int64 v35; // [rsp+10h] [rbp-88h]
  __int64 v36; // [rsp+20h] [rbp-78h]
  __int64 v37[2]; // [rsp+30h] [rbp-68h] BYREF
  __int64 v38; // [rsp+40h] [rbp-58h] BYREF
  __int64 v39; // [rsp+48h] [rbp-50h]
  __int64 v40; // [rsp+50h] [rbp-48h]
  __int64 v41; // [rsp+58h] [rbp-40h]

  v6 = *(_QWORD *)(ptr[5] + 24LL);
  v35 = v6;
  if ( v6 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( v6 != *(_QWORD *)(a3[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( *((_DWORD *)a2 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_select");
  if ( *((_DWORD *)a3 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_select");
  if ( *((_DWORD *)ptr + 12) != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_select");
  v7 = *((unsigned int *)a2 + 20);
  if ( (_DWORD)v7 != *((_DWORD *)a3 + 20) )
LABEL_10:
    sub_18270("select", (__int64)a2, (__int64)a3);
  if ( (int)v7 <= 0 )
  {
    if ( (_DWORD)v7 == *((_DWORD *)ptr + 20) )
      goto LABEL_23;
LABEL_90:
    sub_18270("select", (__int64)a2, (__int64)ptr);
  }
  v8 = a3[15];
  if ( v8 != a2[15] )
    goto LABEL_10;
  v9 = 1LL;
  while ( (int)v7 > (int)v9 )
  {
    v10 = a2[v9++ + 15];
    if ( v10 != a3[v9 + 14] )
      goto LABEL_10;
  }
  if ( (_DWORD)v7 != *((_DWORD *)ptr + 20) || v8 != ptr[15] )
    goto LABEL_90;
  v11 = 1LL;
  while ( (int)v7 > (int)v11 )
  {
    v12 = a2[v11++ + 15];
    if ( v12 != ptr[v11 + 14] )
      goto LABEL_90;
  }
LABEL_23:
  v13 = nc_new_tensor_nz(*(_QWORD *)(a2[5] + 24LL), *((unsigned int *)a2 + 12), v7, a2 + 15);
  v14 = *(_DWORD *)(v13 + 80);
  v15 = v13;
  if ( v14 <= 0 )
  {
    v34 = 0;
    v18 = 0LL;
    v38 = 0LL;
    v36 = 1LL;
    goto LABEL_49;
  }
  if ( !*(_BYTE *)(v13 + 73) || !*((_BYTE *)ptr + 73) || !*((_BYTE *)a2 + 73) || !*((_BYTE *)a3 + 73) )
  {
    v36 = 1LL;
    v34 = 0;
    goto LABEL_45;
  }
  v16 = *(_QWORD *)(v13 + 120);
  if ( v14 == 1 )
  {
    v34 = 1;
    goto LABEL_44;
  }
  if ( !*(_BYTE *)(v15 + 74) || !*((_BYTE *)ptr + 74) || !*((_BYTE *)a2 + 74) || !*((_BYTE *)a3 + 74) )
  {
    v34 = 1;
LABEL_93:
    v38 = 0LL;
    v36 = (int)v16;
LABEL_46:
    v17 = 1LL;
    do
      *(&v38 + v17++) = 0LL;
    while ( v14 > (int)v17 );
    v18 = v38;
    goto LABEL_49;
  }
  v16 *= *(_QWORD *)(v15 + 128);
  if ( v14 == 2 )
  {
    v34 = 2;
    goto LABEL_44;
  }
  if ( !*(_BYTE *)(v15 + 75) || !*((_BYTE *)ptr + 75) || !*((_BYTE *)a2 + 75) || !*((_BYTE *)a3 + 75) )
  {
    v34 = 2;
    goto LABEL_93;
  }
  v16 *= *(_QWORD *)(v15 + 136);
  if ( v14 == 3 )
  {
    v34 = 3;
    goto LABEL_44;
  }
  if ( !*(_BYTE *)(v15 + 76) || !*((_BYTE *)ptr + 76) || !*((_BYTE *)a2 + 76) || !*((_BYTE *)a3 + 76) )
  {
    v34 = 3;
    goto LABEL_93;
  }
  v16 *= *(_QWORD *)(v15 + 144);
  v34 = 4;
LABEL_44:
  v36 = (int)v16;
LABEL_45:
  v38 = 0LL;
  if ( v14 > 1 )
    goto LABEL_46;
  v18 = 0LL;
LABEL_49:
  v19 = &v38 + v34;
  while ( 1 )
  {
    if ( v18 == -1 )
      goto LABEL_81;
    v20 = a3[7];
    v21 = *((_DWORD *)a3 + 20);
    if ( v21 > 0 )
    {
      v22 = a3[11] * v18;
      if ( v21 != 1 )
      {
        v22 += a3[12] * v39;
        if ( v21 != 2 )
        {
          v22 += a3[13] * v40;
          if ( v21 != 3 )
          {
            v23 = v41;
            v24 = a3[14];
            goto LABEL_56;
          }
        }
      }
      goto LABEL_57;
    }
    v25 = *((_DWORD *)a2 + 20);
    v22 = a3[7];
    v20 = a2[7];
    if ( v25 > 0 )
    {
      while ( 1 )
      {
        v23 = a2[11] * v18;
        if ( v25 == 1 )
          break;
        v23 += a2[12] * v39;
        if ( v25 == 2 )
          break;
        v23 += a2[13] * v40;
        if ( v25 == 3 )
          break;
        v24 = v41;
        if ( v25 == 4 )
        {
          v23 += a2[14] * v41;
          break;
        }
LABEL_56:
        v22 += v24 * v23;
LABEL_57:
        v25 = *((_DWORD *)a2 + 20);
        v22 += v20;
        v20 = a2[7];
        if ( v25 <= 0 )
          goto LABEL_86;
      }
      v26 = *((_DWORD *)ptr + 20);
      v23 += v20;
      v24 = ptr[7];
      if ( v26 > 0 )
      {
LABEL_64:
        v20 = ptr[11] * v18;
        if ( v26 != 1 )
        {
          v20 += ptr[12] * v39;
          if ( v26 != 2 )
          {
            v20 += ptr[13] * v40;
            if ( v26 != 3 )
            {
              if ( v26 != 4 )
                goto LABEL_56;
              v20 += ptr[14] * v41;
            }
          }
        }
        v20 += v24;
        v24 = *(_QWORD *)(v15 + 56);
        if ( v14 <= 0 )
          goto LABEL_88;
        goto LABEL_70;
      }
    }
    else
    {
LABEL_86:
      v26 = *((_DWORD *)ptr + 20);
      v24 = ptr[7];
      v23 = v20;
      if ( v26 > 0 )
        goto LABEL_64;
    }
    v20 = v24;
    v24 = *(_QWORD *)(v15 + 56);
    if ( v14 <= 0 )
    {
LABEL_88:
      v18 = 0LL;
      goto LABEL_75;
    }
LABEL_70:
    v18 *= *(_QWORD *)(v15 + 88);
    if ( v14 != 1 )
    {
      v18 += *(_QWORD *)(v15 + 96) * v39;
      if ( v14 != 2 )
      {
        v18 += *(_QWORD *)(v15 + 104) * v40;
        if ( v14 != 3 )
        {
          if ( v14 == 4 )
          {
            v18 += *(_QWORD *)(v15 + 112) * v41;
            goto LABEL_75;
          }
          goto LABEL_56;
        }
      }
    }
LABEL_75:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v35 + 328))(
      v35,
      v18 + v24,
      v20,
      v23,
      v22,
      v36);
    v14 = *(_DWORD *)(v15 + 80);
    if ( v34 >= v14 )
      goto LABEL_80;
    v27 = *v19 + 1;
    *v19 = v27;
    if ( *(_QWORD *)(v15 + 8 * (v34 + 12LL) + 24) == v27 )
      break;
LABEL_84:
    v18 = v38;
  }
  v28 = 0LL;
  while ( 1 )
  {
    v19[v28] = 0LL;
    if ( v28 == v14 - 1 - v34 )
      break;
    v29 = v19[v28 + 1] + 1;
    v19[++v28] = v29;
    if ( v29 != *(_QWORD *)(v15 + 8LL * (unsigned int)(v34 + 1) + 8 * v28 + 112) )
      goto LABEL_84;
  }
LABEL_80:
  v38 = -1LL;
LABEL_81:
  v37[0] = (__int64)a2;
  v37[1] = (__int64)a3;
  v30 = sub_17590(27, (__int64 *)(v15 + 24), (void **)(v15 + 32), v37);
  v31 = v30;
  if ( v30 )
  {
    *((_DWORD *)v30 + 10) = 1;
    v32 = (_QWORD *)nc_malloc(8uLL);
    v31[6] = v32;
    *v32 = nc_dup_tensor(ptr);
  }
  nc_free_tensor(a2);
  nc_free_tensor(a3);
  nc_free_tensor(ptr);
  return v15;
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
// Function: sub_17590 @ 0x17590
// ======================================================

_QWORD *__fastcall sub_17590(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  __int64 *v7; // rax
  __int64 v8; // r12
  __int64 *v9; // rbp
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  _QWORD *v14; // r14
  __int64 v15; // rax
  __int64 v16; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(0x10uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*a4 + 32LL);
  v7[1] = *(_QWORD *)(a4[1] + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 2;
  v12 = (_QWORD *)nc_malloc(0x10uLL);
  v13 = *v9;
  v14 = v12;
  v11[4] = v12;
  if ( !v13 )
  {
    *v12 = 0LL;
    if ( v9[1] )
      goto LABEL_6;
LABEL_11:
    v14[1] = 0LL;
    goto LABEL_7;
  }
  *v12 = nc_dup_node();
  v14 = (_QWORD *)v11[4];
  if ( !v9[1] )
    goto LABEL_11;
LABEL_6:
  v14[1] = nc_dup_node();
LABEL_7:
  v15 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v15 + 1;
  v11[12] = v15;
  v16 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v16 + 8) = v11;
  *v11 = v16;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

