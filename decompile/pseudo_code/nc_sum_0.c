// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sum_0
// Included functions: 4

// ======================================================
// Function: nc_sum_0 @ 0x66A1A540
// ======================================================

_QWORD *__fastcall nc_sum_0(__int64 a1)
{
  __int64 v1; // rbp
  __int64 v3; // rbx
  __int64 v4; // r12
  _QWORD *v5; // r13
  __int64 v6; // r14
  __int64 *v7; // rdi
  _DWORD *v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  unsigned int v13; // r11d
  _QWORD *v14; // r14
  int v15; // eax
  __int64 v16; // r15
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 *v19; // rbx
  __int64 v20; // rcx
  __int64 v22; // rdx
  __int64 v23; // rdx
  __int64 v24; // rcx
  _QWORD *v25; // rax
  _QWORD *v26; // rax
  int v27; // [rsp+4Ch] [rbp-7Ch]
  __int64 v28[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v29[13]; // [rsp+60h] [rbp-68h] BYREF

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(int *)(a1 + 80) < 0 )
    sub_66A33D40("n_dims1 <= x->n_dims", "libnc.c", 5667);
  v3 = *(unsigned int *)(a1 + 48);
  if ( (unsigned int)v3 > 1 )
    nc_error("unsupported type for %s\n", "nc_reduce_sum");
  v27 = *(_DWORD *)(a1 + 80);
  if ( !v27 )
    return (_QWORD *)a1;
  v4 = *(_QWORD *)(v1 + 16);
  v5 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v5 )
  {
LABEL_30:
    MEMORY[0x18] = v4;
    BUG();
  }
  memset(v5, 0, 0x98ui64);
  *((_DWORD *)v5 + 12) = v3;
  *((_BYTE *)v5 + 72) = 1;
  v6 = nc_type_size_table[v3];
  v5[3] = v4;
  *((_DWORD *)v5 + 4) = 1;
  v7 = *(__int64 **)(v1 + 16);
  v5[15] = 1i64;
  v5[8] = 1i64;
  v8 = aligned_malloc(0x38ui64, 0x40ui64);
  v8[4] = 1;
  *((_QWORD *)v8 + 3) = v1;
  v9 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(v1 + 48))(v1, v8 + 10, v6);
  *((_QWORD *)v8 + 4) = v9;
  if ( !v9 )
    nc_error("not enough device memory");
  v10 = *v7;
  *((_QWORD *)v8 + 6) = v6;
  *(_QWORD *)(v10 + 8) = v8;
  *(_QWORD *)v8 = v10;
  v11 = *((_QWORD *)v8 + 5);
  *((_QWORD *)v8 + 1) = v7;
  *v7 = (__int64)v8;
  v5[7] = v11;
  v12 = *(_QWORD *)(v4 + 16);
  v5[5] = v8;
  *(_QWORD *)(v12 + 8) = v5;
  *v5 = v12;
  v5[1] = v4 + 16;
  *(_QWORD *)(v4 + 16) = v5;
  nc_tensor_set_u32((__int64)v5, 0);
  v13 = *(_DWORD *)(a1 + 48);
  if ( v13 )
  {
    ++*((_DWORD *)v5 + 4);
    v26 = nc_convert((__int64)v5, 0);
    v13 = *(_DWORD *)(a1 + 48);
    v14 = v26;
  }
  else
  {
    v14 = v5;
    if ( *((_DWORD *)v5 + 4) != 1 )
    {
      v14 = nc_new_tensor_nz(*(_QWORD *)(v5[5] + 24i64), *((_DWORD *)v5 + 12), *((_DWORD *)v5 + 20), (__int64)(v5 + 15));
      nc_tensor_copy((__int64)v14, (__int64)v5);
      v13 = *(_DWORD *)(a1 + 48);
    }
  }
  v15 = *(_DWORD *)(a1 + 80);
  if ( v15 <= 0 )
  {
    v4 = 0i64;
    v16 = 1i64;
    v18 = 0i64;
    v29[0] = 0i64;
    goto LABEL_24;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v16 = 1i64;
    v4 = 0i64;
LABEL_20:
    v29[0] = 0i64;
    if ( v15 <= 1 )
    {
      v18 = 0i64;
      goto LABEL_24;
    }
    goto LABEL_21;
  }
  v16 = *(_QWORD *)(a1 + 120);
  if ( v15 == 1 )
  {
    v4 = 1i64;
    goto LABEL_19;
  }
  if ( *(_BYTE *)(a1 + 74) )
  {
    v16 *= *(_QWORD *)(a1 + 128);
    if ( v15 == 2 )
    {
      v4 = 2i64;
      goto LABEL_19;
    }
    if ( *(_BYTE *)(a1 + 75) )
    {
      v16 *= *(_QWORD *)(a1 + 136);
      if ( v15 == 3 )
      {
        v4 = 3i64;
        goto LABEL_19;
      }
      if ( *(_BYTE *)(a1 + 76) )
      {
        v16 *= *(_QWORD *)(a1 + 144);
        v4 = 4i64;
LABEL_19:
        v16 = (int)v16;
        goto LABEL_20;
      }
      v4 = 3i64;
    }
    else
    {
      v4 = 2i64;
    }
  }
  else
  {
    v4 = 1i64;
  }
  v29[0] = 0i64;
  v16 = (int)v16;
LABEL_21:
  v17 = 1i64;
  do
    v29[v17++] = 0i64;
  while ( v15 > (int)v17 );
  v18 = v29[0];
LABEL_24:
  v19 = &v29[(int)v4];
  if ( v18 == -1 )
  {
LABEL_50:
    if ( !v13 )
      goto LABEL_40;
  }
  else
  {
    while ( 1 )
    {
      if ( v15 <= 0 )
      {
        v20 = 0i64;
      }
      else
      {
        v20 = *(_QWORD *)(a1 + 88) * v18;
        if ( v15 != 1 )
        {
          v20 += v29[1] * *(_QWORD *)(a1 + 96);
          if ( v15 != 2 )
          {
            v20 += *(_QWORD *)(a1 + 104) * v29[2];
            if ( v15 != 3 )
            {
              if ( v15 != 4 )
                goto LABEL_30;
              v20 += *(_QWORD *)(a1 + 112) * v29[3];
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, __int64, unsigned int))(v1 + 376))(
        v1,
        v14[7],
        0i64,
        *(_QWORD *)(a1 + 56) + v20,
        0i64,
        v16,
        1i64,
        v13);
      v15 = *(_DWORD *)(a1 + 80);
      if ( v15 <= (int)v4 )
        break;
      v22 = *v19 + 1;
      *v19 = v22;
      if ( *(_QWORD *)(a1 + 8 * ((int)v4 + 12i64) + 24) == v22 )
      {
        v23 = 0i64;
        do
        {
          v19[v23] = 0i64;
          if ( v23 == v15 - 1 - (_DWORD)v4 )
            goto LABEL_39;
          v24 = v19[v23 + 1] + 1;
          v19[++v23] = v24;
        }
        while ( v24 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v4 + 1) + 8 * v23 + 112) );
      }
      v18 = v29[0];
      v13 = *(_DWORD *)(a1 + 48);
      if ( v29[0] == -1 )
        goto LABEL_50;
    }
LABEL_39:
    v13 = *(_DWORD *)(a1 + 48);
    v29[0] = -1i64;
    if ( !v13 )
      goto LABEL_40;
  }
  v14 = nc_convert((__int64)v14, v13);
LABEL_40:
  v28[0] = (__int64)v5;
  v28[1] = a1;
  v25 = sub_66A15DA0(5, v14 + 3, (__int64 **)v14 + 4, 2, (__int64)v28);
  if ( v25 )
  {
    *((_DWORD *)v25 + 14) = v27;
    if ( v27 > 0 )
    {
      v25[8] = *(_QWORD *)(a1 + 120);
      if ( v27 != 1 )
      {
        v25[9] = *(_QWORD *)(a1 + 128);
        if ( v27 != 2 )
        {
          v25[10] = *(_QWORD *)(a1 + 136);
          if ( v27 != 3 )
            v25[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  if ( v14 != v5 )
    nc_free_tensor(v5);
  nc_free_tensor((_DWORD *)a1);
  return v14;
}

// ======================================================
// Function: sub_66A33D40 @ 0x66A33D40
// ======================================================

void __fastcall sub_66A33D40(const char *a1, const char *a2, int a3)
{
  size_t v5; // rax
  wchar_t *v6; // rsi
  size_t v7; // rax
  const wchar_t *v8; // rax
  wchar_t v9; // cx
  __int64 v10; // r9
  wchar_t *v11; // rbx
  wchar_t v12; // cx
  __int64 v13; // r9

  v5 = strlen(a1);
  v6 = (wchar_t *)malloc(2 * v5 + 2);
  v7 = strlen(a2);
  v8 = (const wchar_t *)malloc(2 * v7 + 2);
  v9 = *(unsigned __int8 *)a1;
  v10 = 0i64;
  v11 = (wchar_t *)v8;
  if ( (_BYTE)v9 )
  {
    do
    {
      v6[v10++] = v9;
      v9 = (unsigned __int8)a1[v10];
    }
    while ( (_BYTE)v9 );
    v10 *= 2i64;
  }
  v12 = *(unsigned __int8 *)a2;
  *(wchar_t *)((char *)v6 + v10) = 0;
  v13 = 0i64;
  if ( (_BYTE)v12 )
  {
    do
    {
      v8[v13++] = v12;
      v12 = (unsigned __int8)a2[v13];
    }
    while ( (_BYTE)v12 );
    v13 *= 2i64;
  }
  *(const wchar_t *)((char *)v8 + v13) = 0;
  sub_66A33C00(v6, v8, a3);
  free(v6);
  free(v11);
}

// ======================================================
// Function: sub_66A33C00 @ 0x66A33C00
// ======================================================

int __fastcall sub_66A33C00(const wchar_t *a1, const wchar_t *a2, int a3)
{
  wchar_t *v6; // rbp
  int result; // eax
  FILE *v8; // rax
  WCHAR Filename[284]; // [rsp+40h] [rbp-238h] BYREF

  v6 = (wchar_t *)malloc(0x4000ui64);
  if ( a2 )
  {
    if ( !*a2 )
      a2 = L"<unknown>";
  }
  else
  {
    a2 = L"<unknown>";
  }
  if ( a1 )
  {
    if ( !*a1 )
      a1 = L"?";
  }
  else
  {
    a1 = L"?";
  }
  if ( !GetModuleFileNameW(0i64, Filename, 0x104u) )
    wcscpy(Filename, L"<unknown>");
  snwprintf(
    v6,
    0x1FFFui64,
    L"Assertion failed!\n\nProgram: %ws\nFile: %ws, Line %u\n\nExpression: %ws",
    Filename,
    a2,
    a3,
    a1);
  if ( !unk_66A3D5B0 )
  {
    v8 = _iob_func();
    fwprintf(v8 + 2, L"%ws\n", v6);
    abort();
  }
  result = MessageBoxW(0i64, v6, L"MinGW Runtime Assertion", 0x12012u);
  if ( result == 3 )
  {
    raise(22);
    exit(3);
  }
  if ( result != 5 )
    abort();
  return result;
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

