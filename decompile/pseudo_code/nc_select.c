// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_select
// Included functions: 3

// ======================================================
// Function: nc_select @ 0x66A21FC0
// ======================================================

_QWORD *__fastcall nc_select(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rdi
  __int64 v7; // rcx
  int v8; // r8d
  __int64 v9; // r9
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  _QWORD *v14; // rax
  int v15; // r11d
  _QWORD *v16; // rdi
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // r15
  __int64 *v20; // rbx
  int v21; // edx
  __int64 v22; // rcx
  __int64 v23; // rax
  __int64 v24; // r8
  __int64 v25; // r9
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rdx
  _QWORD *v29; // rax
  _QWORD *v30; // rbx
  _QWORD *v31; // rax
  int v33; // [rsp+3Ch] [rbp-9Ch]
  __int64 v34; // [rsp+40h] [rbp-98h]
  __int64 v35; // [rsp+50h] [rbp-88h]
  __int64 v36[2]; // [rsp+60h] [rbp-78h] BYREF
  __int64 v37; // [rsp+70h] [rbp-68h] BYREF
  __int64 v38; // [rsp+78h] [rbp-60h]
  __int64 v39; // [rsp+80h] [rbp-58h]
  __int64 v40; // [rsp+88h] [rbp-50h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v34 = v3;
  v7 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( v3 != v7 || v3 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a2 + 48) || *(_DWORD *)(a3 + 48) || *(_DWORD *)(a1 + 48) != 5 )
    nc_error("unsupported type for %s\n", "nc_select");
  v8 = *(_DWORD *)(a2 + 80);
  if ( v8 != *(_DWORD *)(a3 + 80) )
LABEL_7:
    sub_66A16930("select", a2, a3);
  if ( v8 <= 0 )
  {
    if ( v8 == *(_DWORD *)(a1 + 80) )
      goto LABEL_18;
LABEL_85:
    sub_66A16930("select", a2, a1);
  }
  v9 = *(_QWORD *)(a3 + 120);
  if ( v9 != *(_QWORD *)(a2 + 120) )
    goto LABEL_7;
  v10 = 1i64;
  while ( v8 > (int)v10 )
  {
    v11 = *(_QWORD *)(a2 + 8 * v10++ + 120);
    if ( v11 != *(_QWORD *)(a3 + 8 * v10 + 112) )
      goto LABEL_7;
  }
  if ( v8 != *(_DWORD *)(a1 + 80) || *(_QWORD *)(a1 + 120) != v9 )
    goto LABEL_85;
  v12 = 1i64;
  while ( v8 > (int)v12 )
  {
    v13 = *(_QWORD *)(a2 + 8 * v12++ + 120);
    if ( v13 != *(_QWORD *)(a1 + 8 * v12 + 112) )
      goto LABEL_85;
  }
LABEL_18:
  v14 = nc_new_tensor_nz(v7, 0, v8, a2 + 120);
  v15 = *((_DWORD *)v14 + 20);
  v16 = v14;
  if ( v15 <= 0 )
  {
    v33 = 0;
    v19 = 0i64;
    v37 = 0i64;
    v35 = 1i64;
    goto LABEL_44;
  }
  if ( !*((_BYTE *)v14 + 73) || !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) || !*(_BYTE *)(a3 + 73) )
  {
    v35 = 1i64;
    v33 = 0;
    goto LABEL_40;
  }
  v17 = v14[15];
  if ( v15 == 1 )
  {
    v33 = 1;
    goto LABEL_39;
  }
  if ( !*((_BYTE *)v16 + 74) || !*(_BYTE *)(a1 + 74) || !*(_BYTE *)(a2 + 74) || !*(_BYTE *)(a3 + 74) )
  {
    v33 = 1;
LABEL_88:
    v37 = 0i64;
    v35 = (int)v17;
LABEL_41:
    v18 = 1i64;
    do
      *(&v37 + v18++) = 0i64;
    while ( v15 > (int)v18 );
    v19 = v37;
    goto LABEL_44;
  }
  v17 *= v16[16];
  if ( v15 == 2 )
  {
    v33 = 2;
    goto LABEL_39;
  }
  if ( !*((_BYTE *)v16 + 75) || !*(_BYTE *)(a1 + 75) || !*(_BYTE *)(a2 + 75) || !*(_BYTE *)(a3 + 75) )
  {
    v33 = 2;
    goto LABEL_88;
  }
  v17 *= v16[17];
  if ( v15 == 3 )
  {
    v33 = 3;
    goto LABEL_39;
  }
  if ( !*((_BYTE *)v16 + 76) || !*(_BYTE *)(a1 + 76) || !*(_BYTE *)(a2 + 76) || !*(_BYTE *)(a3 + 76) )
  {
    v33 = 3;
    goto LABEL_88;
  }
  v17 *= v16[18];
  v33 = 4;
LABEL_39:
  v35 = (int)v17;
LABEL_40:
  v37 = 0i64;
  if ( v15 > 1 )
    goto LABEL_41;
  v19 = 0i64;
LABEL_44:
  v20 = &v37 + v33;
  while ( v19 != -1 )
  {
    v21 = *(_DWORD *)(a3 + 80);
    v22 = *(_QWORD *)(a3 + 56);
    if ( v21 <= 0 )
    {
      v23 = 0i64;
    }
    else
    {
      v23 = *(_QWORD *)(a3 + 88) * v19;
      if ( v21 != 1 )
      {
        v23 += *(_QWORD *)(a3 + 96) * v38;
        if ( v21 != 2 )
        {
          v23 += *(_QWORD *)(a3 + 104) * v39;
          if ( v21 != 3 )
          {
            v24 = v40;
            v25 = *(_QWORD *)(a3 + 112);
            goto LABEL_51;
          }
        }
      }
    }
    while ( 1 )
    {
      v22 += v23;
      v23 = *(unsigned int *)(a2 + 80);
      if ( (int)v23 <= 0 )
      {
        v25 = 0i64;
      }
      else
      {
        v25 = *(_QWORD *)(a2 + 88) * v19;
        if ( (_DWORD)v23 != 1 )
        {
          v25 += *(_QWORD *)(a2 + 96) * v38;
          if ( (_DWORD)v23 != 2 )
          {
            v25 += *(_QWORD *)(a2 + 104) * v39;
            if ( (_DWORD)v23 != 3 )
            {
              v24 = v40;
              if ( (_DWORD)v23 != 4 )
                goto LABEL_51;
              v25 += *(_QWORD *)(a2 + 112) * v40;
            }
          }
        }
      }
      v23 = *(unsigned int *)(a1 + 80);
      v25 += *(_QWORD *)(a2 + 56);
      if ( (int)v23 <= 0 )
      {
        v24 = 0i64;
      }
      else
      {
        v24 = *(_QWORD *)(a1 + 88) * v19;
        if ( (_DWORD)v23 != 1 )
        {
          v24 += *(_QWORD *)(a1 + 96) * v38;
          if ( (_DWORD)v23 != 2 )
          {
            v24 += *(_QWORD *)(a1 + 104) * v39;
            if ( (_DWORD)v23 != 3 )
            {
              if ( (_DWORD)v23 != 4 )
                goto LABEL_51;
              v24 += *(_QWORD *)(a1 + 112) * v40;
            }
          }
        }
      }
      v24 += *(_QWORD *)(a1 + 56);
      if ( v15 <= 0 )
        break;
      v19 *= v16[11];
      if ( v15 == 1 )
        goto LABEL_70;
      v19 += v16[12] * v38;
      if ( v15 == 2 )
        goto LABEL_70;
      v19 += v16[13] * v39;
      if ( v15 == 3 )
        goto LABEL_70;
      v23 = v40;
      if ( v15 == 4 )
      {
        v19 += v16[14] * v40;
        goto LABEL_70;
      }
LABEL_51:
      v23 += v25 * v24;
    }
    v19 = 0i64;
LABEL_70:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v34 + 328))(
      v34,
      v19 + v16[7],
      v24,
      v25,
      v22,
      v35);
    v15 = *((_DWORD *)v16 + 20);
    if ( v33 >= v15 )
    {
LABEL_75:
      v37 = -1i64;
      break;
    }
    v26 = *v20 + 1;
    *v20 = v26;
    if ( v16[v33 + 15] == v26 )
    {
      v27 = 0i64;
      do
      {
        v20[v27] = 0i64;
        if ( v27 == v15 - 1 - v33 )
          goto LABEL_75;
        v28 = v20[v27 + 1] + 1;
        v20[++v27] = v28;
      }
      while ( v28 == v16[(unsigned int)(v33 + 1) + 14 + v27] );
    }
    v19 = v37;
  }
  v36[0] = a2;
  v36[1] = a3;
  v29 = sub_66A15DA0(27, v16 + 3, (__int64 **)v16 + 4, 2, (__int64)v36);
  v30 = v29;
  if ( v29 )
  {
    *((_DWORD *)v29 + 10) = 1;
    v31 = aligned_malloc(8ui64, 0x40ui64);
    v30[6] = v31;
    ++*(_DWORD *)(a1 + 16);
    *v31 = a1;
  }
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)a3);
  nc_free_tensor((_DWORD *)a1);
  return v16;
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

// ======================================================
// Function: sub_66A15DA0 @ 0x66A15DA0
// ======================================================

_QWORD *__fastcall sub_66A15DA0(int a1, __int64 *a2, __int64 **a3, int a4, __int64 a5)
{
  _QWORD *result; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  void *v11; // r15
  __int64 v12; // rax
  __int64 v13; // r13
  _QWORD *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rax
  size_t v20; // r12
  void *v21; // rax

  if ( a4 <= 0 )
  {
    if ( !a4 )
      return 0i64;
    v20 = 8i64 * a4;
    v21 = aligned_malloc(v20, 0x40ui64);
    v13 = *a2;
    v11 = v21;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v14[4] = aligned_malloc(v20, 0x40ui64);
LABEL_13:
      v18 = *(_QWORD *)(v13 + 72);
      *(_QWORD *)(v13 + 72) = v18 + 1;
      v14[12] = v18;
      v19 = *(_QWORD *)(v13 + 32);
      *(_QWORD *)(v19 + 8) = v14;
      *v14 = v19;
      v14[1] = v13 + 32;
      *(_QWORD *)(v13 + 32) = v14;
      _aligned_free(v11);
      if ( *a3 )
        nc_free_node(*a3);
      *a3 = v14;
      return v14;
    }
LABEL_22:
    MEMORY[0x10] = 0;
    BUG();
  }
  result = *(_QWORD **)(*(_QWORD *)a5 + 32i64);
  if ( result )
    goto LABEL_7;
  v9 = 1i64;
  while ( (int)v9 < a4 )
  {
    v10 = *(_QWORD *)(a5 + 8 * v9++);
    if ( *(_QWORD *)(v10 + 32) )
      goto LABEL_7;
  }
  if ( (_DWORD)v9 != a4 )
  {
LABEL_7:
    v11 = aligned_malloc(8i64 * a4, 0x40ui64);
    v12 = 0i64;
    do
    {
      *((_QWORD *)v11 + v12) = *(_QWORD *)(*(_QWORD *)(a5 + 8 * v12) + 32i64);
      ++v12;
    }
    while ( a4 > (int)v12 );
    v13 = *a2;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v15 = aligned_malloc(8i64 * a4, 0x40ui64);
      v16 = 0i64;
      v14[4] = v15;
      do
      {
        while ( 1 )
        {
          v17 = *((_QWORD *)v11 + v16);
          if ( !v17 )
            break;
          ++*(_DWORD *)(v17 + 16);
          v15[v16++] = v17;
          if ( a4 <= (int)v16 )
            goto LABEL_13;
        }
        v15[v16++] = 0i64;
      }
      while ( a4 > (int)v16 );
      goto LABEL_13;
    }
    goto LABEL_22;
  }
  return result;
}

