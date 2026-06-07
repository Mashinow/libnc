// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_add_element
// Included functions: 4

// ======================================================
// Function: nc_add_element @ 0x66A27610
// ======================================================

_QWORD *__fastcall nc_add_element(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rdi
  unsigned int v7; // eax
  int v8; // edx
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rax
  _QWORD *v11; // r14
  __int64 v12; // rax
  _QWORD *v13; // rbx
  __int64 v14; // rcx
  __int64 v15; // rax
  int v16; // edx
  __int64 v17; // rax
  __int64 v18; // rsi
  int v19; // edx
  __int64 v20; // r8
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // r9
  int v24; // edx
  __int64 v25; // r15
  __int64 v26; // rdx
  __int64 v27; // rdx
  int v28; // r8d
  __int64 v29; // rax
  __int64 v30; // rdx
  _QWORD *v31; // rax
  _QWORD *v32; // rbx
  _QWORD *v33; // rax
  __int64 v35; // rax
  __int64 v36; // rcx
  __int64 v37[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v38; // [rsp+60h] [rbp-68h] BYREF
  __int64 v39; // [rsp+68h] [rbp-60h]
  __int64 v40; // [rsp+70h] [rbp-58h]
  __int64 v41; // [rsp+78h] [rbp-50h]
  __int64 v42; // [rsp+80h] [rbp-48h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v3 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) || v3 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v7 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a3 + 48) != v7 || v7 > 1 || *(_DWORD *)(a2 + 48) != 5 )
    nc_error("unsupported type for %s\n", "nc_add_element");
  v8 = *(_DWORD *)(a2 + 80);
  if ( *(_DWORD *)(a3 + 80) != v8 + 1 )
  {
    sub_66A33D40("w->n_dims == (x->n_dims + 1)", "libnc.c", 6858);
    v8 = *(_DWORD *)(a2 + 80);
  }
  v9 = 0i64;
  v10 = v8;
  while ( v9 < v10 )
  {
    while ( 1 )
    {
      ++v9;
      if ( *(_QWORD *)(a3 + 8 * v9 + 120) == *(_QWORD *)(a2 + 8 * v9 + 112) )
        break;
      sub_66A33D40("w->dims[i + 1] == x->dims[i]", "libnc.c", 6860);
      v10 = *(int *)(a2 + 80);
      v8 = *(_DWORD *)(a2 + 80);
      if ( v9 >= v10 )
        goto LABEL_12;
    }
  }
LABEL_12:
  if ( *(_DWORD *)(a1 + 80) != v8 )
  {
LABEL_13:
    sub_66A33D40("same_dims(z, x)", "libnc.c", 6862);
    goto LABEL_14;
  }
  if ( v8 > 0 )
  {
    if ( *(_QWORD *)(a2 + 120) == *(_QWORD *)(a1 + 120) )
    {
      v35 = 1i64;
      while ( v8 > (int)v35 )
      {
        v36 = *(_QWORD *)(a1 + 8 * v35++ + 120);
        if ( v36 != *(_QWORD *)(a2 + 8 * v35 + 112) )
          goto LABEL_13;
      }
      goto LABEL_14;
    }
    goto LABEL_13;
  }
LABEL_14:
  v11 = (_QWORD *)a3;
  if ( *(_DWORD *)(a3 + 16) != 1 )
  {
    v11 = nc_new_tensor_nz(v3, *(_DWORD *)(a3 + 48), *(_DWORD *)(a3 + 80), a3 + 120);
    nc_tensor_copy((__int64)v11, a3);
  }
  v12 = *(_QWORD *)(a2 + 24);
  ++*(_DWORD *)(a2 + 16);
  v13 = (_QWORD *)a2;
  v14 = *(_QWORD *)(v12 + 64);
  if ( v14 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
  {
    v13 = nc_new_tensor_nz(v14, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 80), a2 + 120);
    nc_tensor_copy((__int64)v13, a2);
    v15 = *(_QWORD *)(a2 + 32);
    if ( v15 )
    {
      ++*(_DWORD *)(v15 + 16);
      v13[4] = v15;
    }
    nc_free_tensor((_DWORD *)a2);
  }
  v39 = 0i64;
  v16 = *((_DWORD *)v13 + 20);
  if ( v16 <= 1 )
  {
    v18 = 0i64;
  }
  else
  {
    v17 = 1i64;
    do
      *(&v38 + ++v17) = 0i64;
    while ( v16 > (int)v17 );
LABEL_23:
    v18 = v39;
  }
  while ( v18 != -1 )
  {
    v19 = *((_DWORD *)v13 + 20);
    v20 = v13[7];
    if ( v19 <= 0 )
    {
      v21 = 0i64;
    }
    else
    {
      v21 = v13[11] * v18;
      if ( v19 != 1 )
      {
        v21 += v13[12] * v40;
        if ( v19 != 2 )
        {
          v21 += v13[13] * v41;
          if ( v19 != 3 )
          {
            v22 = v42;
            v23 = v13[14];
            goto LABEL_30;
          }
        }
      }
    }
    while ( 1 )
    {
      v24 = *(_DWORD *)(v20 + v21);
      v25 = v24;
      if ( v24 < 0 || (unsigned __int64)v24 >= v11[15] )
        sub_66A33D40("c >= 0 && c < y->dims[0]", "libnc.c", 6876);
      v21 = *((unsigned int *)v11 + 20);
      v20 = v11[7];
      v38 = v25;
      if ( (int)v21 <= 0 )
      {
        v26 = 0i64;
      }
      else
      {
        v26 = v11[11] * v25;
        if ( (_DWORD)v21 != 1 )
        {
          v26 += v11[12] * v18;
          if ( (_DWORD)v21 != 2 )
          {
            v26 += v11[13] * v40;
            if ( (_DWORD)v21 != 3 )
            {
              v22 = v41;
              v23 = v11[14];
              if ( (_DWORD)v21 != 4 )
                goto LABEL_30;
              v26 += v23 * v41;
            }
          }
        }
      }
      v22 = *(unsigned int *)(a1 + 80);
      v27 = v20 + v26;
      v20 = *(_QWORD *)(a1 + 56);
      if ( (int)v22 <= 0 )
        break;
      v21 = *(_QWORD *)(a1 + 88) * v18;
      if ( (_DWORD)v22 == 1 )
        goto LABEL_46;
      v21 += *(_QWORD *)(a1 + 96) * v40;
      if ( (_DWORD)v22 == 2 )
        goto LABEL_46;
      v21 += *(_QWORD *)(a1 + 104) * v41;
      if ( (_DWORD)v22 == 3 )
        goto LABEL_46;
      v23 = v42;
      if ( (_DWORD)v22 == 4 )
      {
        v21 += *(_QWORD *)(a1 + 112) * v42;
        goto LABEL_46;
      }
LABEL_30:
      v21 += v23 * v22;
    }
    v21 = 0i64;
LABEL_46:
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v3 + 168))(
      v3,
      v27,
      0i64,
      v27,
      0i64,
      v20 + v21,
      0i64,
      1i64,
      1i64,
      *(_DWORD *)(a1 + 48));
    v28 = *((_DWORD *)v13 + 20);
    if ( v28 <= 0 )
    {
LABEL_51:
      v39 = -1i64;
      break;
    }
    v39 = ++v18;
    if ( v13[15] == v18 )
    {
      v29 = 1i64;
      while ( 1 )
      {
        *(&v38 + v29) = 0i64;
        if ( v28 <= (int)v29 )
          goto LABEL_51;
        v30 = *(&v38 + v29 + 1) + 1;
        *(&v38 + ++v29) = v30;
        if ( v30 != v13[v29 + 14] )
          goto LABEL_23;
      }
    }
  }
  nc_free_tensor(v13);
  v37[0] = a1;
  v37[1] = a3;
  v31 = sub_66A15DA0(34, v11 + 3, (__int64 **)v11 + 4, 2, (__int64)v37);
  v32 = v31;
  if ( v31 )
  {
    *((_DWORD *)v31 + 10) = 1;
    v33 = aligned_malloc(8ui64, 0x40ui64);
    v32[6] = v33;
    ++*(_DWORD *)(a2 + 16);
    *v33 = a2;
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  if ( v11 != (_QWORD *)a3 )
    nc_free_tensor((_DWORD *)a3);
  return v11;
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

