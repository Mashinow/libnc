// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reduce_sum
// Included functions: 4

// ======================================================
// Function: nc_reduce_sum @ 0x66A1EFA0
// ======================================================

__int64 __fastcall nc_reduce_sum(_QWORD *a1, __int64 a2, int a3)
{
  __int64 v3; // r13
  unsigned int v7; // edx
  _QWORD *v8; // r12
  __int64 v10; // rdi
  int v11; // eax
  int v12; // edx
  __int64 v13; // r15
  int v14; // eax
  __int64 v15; // rbx
  unsigned int v16; // edx
  _QWORD *v17; // rax
  int v18; // eax
  __int64 v19; // rdx
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 *v22; // rbx
  __int64 v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // rdx
  __int64 v26; // rcx
  __int64 v27; // [rsp+48h] [rbp-90h]
  int v28; // [rsp+5Ch] [rbp-7Ch]
  __int64 v29[2]; // [rsp+60h] [rbp-78h] BYREF
  __int64 v30[13]; // [rsp+70h] [rbp-68h] BYREF

  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( *(_DWORD *)(a2 + 80) < a3 )
    sub_66A33D40("n_dims1 <= x->n_dims", "libnc.c", 5667);
  v7 = *(_DWORD *)(a2 + 48);
  if ( v7 > 1 )
    nc_error("unsupported type for %s\n", "nc_reduce_sum");
  v28 = *(_DWORD *)(a2 + 80) - a3;
  if ( !v28 )
  {
    v8 = (_QWORD *)a2;
    if ( a1 )
      return nc_add((__int64)a1, a2);
    return (__int64)v8;
  }
  if ( a1 )
  {
    if ( v3 != *(_QWORD *)(a1[5] + 24i64) )
      nc_error("all operation tensors must be on the same device");
  }
  else
  {
    a1 = nc_new_tensor_nz(v3, v7, a3, a2 + 120);
    nc_tensor_set_u32((__int64)a1, 0);
    v7 = *(_DWORD *)(a2 + 48);
  }
  if ( v7 )
  {
    ++*((_DWORD *)a1 + 4);
    v8 = nc_convert((__int64)a1, 0);
  }
  else
  {
    v8 = a1;
    if ( *((_DWORD *)a1 + 4) != 1 )
    {
      v8 = nc_new_tensor_nz(*(_QWORD *)(a1[5] + 24i64), *((_DWORD *)a1 + 12), *((_DWORD *)a1 + 20), (__int64)(a1 + 15));
      nc_tensor_copy((__int64)v8, (__int64)a1);
    }
  }
  if ( !a3 )
  {
    v18 = *(_DWORD *)(a2 + 80);
    if ( v18 <= 0 )
    {
      v30[0] = 0i64;
      v13 = 0i64;
      v21 = 0i64;
      v27 = 1i64;
      goto LABEL_65;
    }
    if ( !*(_BYTE *)(a2 + 73) )
    {
      v27 = 1i64;
      v13 = 0i64;
LABEL_61:
      v30[0] = 0i64;
      if ( v18 <= 1 )
      {
        v21 = 0i64;
        goto LABEL_65;
      }
LABEL_62:
      v20 = 1i64;
      do
        v30[v20++] = 0i64;
      while ( v18 > (int)v20 );
      v21 = v30[0];
LABEL_65:
      v10 = a2 + 8i64 * (unsigned int)(v13 + 1);
      v22 = &v30[(int)v13];
      while ( v21 != -1 )
      {
        if ( v18 <= 0 )
        {
          v23 = 0i64;
        }
        else
        {
          v23 = *(_QWORD *)(a2 + 88) * v21;
          if ( v18 != 1 )
          {
            v23 += *(_QWORD *)(a2 + 96) * v30[1];
            if ( v18 != 2 )
            {
              v23 += *(_QWORD *)(a2 + 104) * v30[2];
              if ( v18 != 3 )
              {
                if ( v18 != 4 )
                  goto LABEL_72;
                v23 += *(_QWORD *)(a2 + 112) * v30[3];
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v3 + 376))(
          v3,
          v8[7],
          0i64,
          *(_QWORD *)(a2 + 56) + v23,
          0i64,
          v27,
          1i64,
          *(_DWORD *)(a2 + 48));
        v18 = *(_DWORD *)(a2 + 80);
        if ( v18 <= (int)v13 )
          goto LABEL_80;
        v24 = *v22 + 1;
        *v22 = v24;
        if ( *(_QWORD *)(a2 + 8 * ((int)v13 + 12i64) + 24) == v24 )
        {
          v25 = 0i64;
          while ( 1 )
          {
            v22[v25] = 0i64;
            if ( v25 == v18 - 1 - (_DWORD)v13 )
              break;
            v26 = v22[v25 + 1] + 1;
            v22[++v25] = v26;
            if ( v26 != *(_QWORD *)(v10 + 8 * v25 + 112) )
              goto LABEL_82;
          }
LABEL_80:
          v30[0] = -1i64;
          v16 = *(_DWORD *)(a2 + 48);
          if ( !v16 )
            goto LABEL_42;
          goto LABEL_81;
        }
LABEL_82:
        v21 = v30[0];
      }
      goto LABEL_41;
    }
    v19 = *(_QWORD *)(a2 + 120);
    if ( v18 == 1 )
    {
      v13 = 1i64;
      goto LABEL_60;
    }
    if ( *(_BYTE *)(a2 + 74) )
    {
      v19 *= *(_QWORD *)(a2 + 128);
      if ( v18 == 2 )
      {
        v13 = 2i64;
        goto LABEL_60;
      }
      if ( *(_BYTE *)(a2 + 75) )
      {
        v19 *= *(_QWORD *)(a2 + 136);
        if ( v18 == 3 )
        {
          v13 = 3i64;
          goto LABEL_60;
        }
        if ( *(_BYTE *)(a2 + 76) )
        {
          v19 *= *(_QWORD *)(a2 + 144);
          v13 = 4i64;
LABEL_60:
          v27 = (int)v19;
          goto LABEL_61;
        }
        v13 = 3i64;
      }
      else
      {
        v13 = 2i64;
      }
    }
    else
    {
      v13 = 1i64;
    }
    v30[0] = 0i64;
    v27 = (int)v19;
    goto LABEL_62;
  }
  if ( a3 <= 0 || !*(_BYTE *)(a2 + 73) || !*((_BYTE *)v8 + 73) )
  {
    v10 = 1i64;
    goto LABEL_86;
  }
  v10 = *(_QWORD *)(a2 + 120);
  if ( a3 == 1 )
    goto LABEL_28;
  if ( !*(_BYTE *)(a2 + 74) || !*((_BYTE *)v8 + 74) )
    goto LABEL_86;
  v10 *= *(_QWORD *)(a2 + 128);
  if ( a3 == 2 )
  {
    v11 = 2;
    goto LABEL_27;
  }
  if ( !*(_BYTE *)(a2 + 75) || !*((_BYTE *)v8 + 75) )
    goto LABEL_86;
  v10 *= *(_QWORD *)(a2 + 136);
  if ( a3 == 3 )
  {
    v11 = 3;
LABEL_27:
    if ( a3 == v11 )
      goto LABEL_28;
    goto LABEL_86;
  }
  if ( *(_BYTE *)(a2 + 76) && *((_BYTE *)v8 + 76) )
  {
    v10 *= *(_QWORD *)(a2 + 144);
    v11 = 4;
    goto LABEL_27;
  }
LABEL_86:
  sub_66A33D40("first_axis == n_dims1", "libnc.c", 5709);
LABEL_28:
  v12 = *(_DWORD *)(a2 + 80);
  if ( a3 >= v12 )
  {
    v14 = a3;
    v15 = 1i64;
    v13 = a3;
  }
  else
  {
    v13 = a3;
    if ( !*(_BYTE *)(a2 + a3 + 73) )
    {
LABEL_72:
      v15 = 1i64;
      goto LABEL_73;
    }
    v14 = a3 + 1;
    v15 = *(_QWORD *)(a2 + 8i64 * a3 + 120);
    if ( a3 + 1 < v12 )
    {
      if ( !*(_BYTE *)(a2 + v14 + 73) )
        goto LABEL_73;
      v15 *= *(_QWORD *)(a2 + 8i64 * v14 + 120);
      v14 = a3 + 2;
      if ( v12 <= a3 + 2 )
        goto LABEL_39;
      if ( !*(_BYTE *)(a2 + v14 + 73) )
        goto LABEL_73;
      v15 *= *(_QWORD *)(a2 + 8i64 * v14 + 120);
      v14 = a3 + 3;
      if ( v12 <= a3 + 3 )
        goto LABEL_39;
      if ( !*(_BYTE *)(a2 + v14 + 73) )
        goto LABEL_73;
      v15 *= *(_QWORD *)(a2 + 8i64 * v14 + 120);
      v14 = a3 + 4;
      if ( v12 <= a3 + 4 )
        goto LABEL_39;
      if ( !*(_BYTE *)(a2 + v14 + 73) )
      {
LABEL_73:
        sub_66A33D40("axis1 == x->n_dims", "libnc.c", 5716);
        goto LABEL_40;
      }
      v15 *= *(_QWORD *)(a2 + 8i64 * v14 + 120);
      v14 = a3 + 5;
    }
  }
LABEL_39:
  if ( v12 != v14 )
    goto LABEL_73;
LABEL_40:
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _DWORD))(v3 + 368))(
    v3,
    v8[7],
    *(_QWORD *)(a2 + 56),
    *(_QWORD *)(a2 + 8 * v13 + 88) >> dword_66A375E0[*(unsigned int *)(a2 + 48)],
    v10,
    v15,
    *(_DWORD *)(a2 + 48));
LABEL_41:
  v16 = *(_DWORD *)(a2 + 48);
  if ( v16 )
LABEL_81:
    v8 = nc_convert((__int64)v8, v16);
LABEL_42:
  v29[0] = (__int64)a1;
  v29[1] = a2;
  v17 = sub_66A15DA0(5, v8 + 3, (__int64 **)v8 + 4, 2, (__int64)v29);
  if ( v17 )
  {
    *((_DWORD *)v17 + 14) = v28;
    if ( v28 > 0 )
    {
      v17[8] = *(_QWORD *)(a2 + 8i64 * a3 + 120);
      if ( v28 != 1 )
      {
        v17[9] = *(_QWORD *)(a2 + 8i64 * (a3 + 1) + 120);
        if ( v28 != 2 )
        {
          v17[10] = *(_QWORD *)(a2 + 8i64 * (a3 + 2) + 120);
          if ( v28 != 3 )
            v17[11] = *(_QWORD *)(a2 + 8i64 * (a3 + 3) + 120);
        }
      }
    }
  }
  if ( a1 != v8 )
    nc_free_tensor(a1);
  nc_free_tensor((_DWORD *)a2);
  return (__int64)v8;
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

