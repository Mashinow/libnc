// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_concat
// Included functions: 4

// ======================================================
// Function: nc_concat @ 0x66A236B0
// ======================================================

_QWORD *__fastcall nc_concat(__int64 *a1, int a2, int a3)
{
  __int64 v4; // r15
  bool v5; // cc
  __int64 v6; // r14
  __int64 *v7; // rdi
  int v8; // edx
  __int64 v9; // r12
  int i; // r13d
  _QWORD *v11; // r12
  int v13; // r8d
  unsigned int v14; // edx
  unsigned __int64 v15; // rbp
  __int64 *v16; // rsi
  __int64 v17; // r15
  __int64 v18; // r14
  _QWORD *v19; // rdi
  __int64 *v20; // rdi
  _QWORD *v21; // rax
  _QWORD *v22; // rbp
  unsigned __int64 v23; // rax
  _DWORD *v24; // rcx
  _QWORD *v25; // rax
  __int64 v26; // [rsp+38h] [rbp-90h]
  __int64 v27; // [rsp+40h] [rbp-88h]
  __int64 v28; // [rsp+48h] [rbp-80h]
  __int64 v29[13]; // [rsp+60h] [rbp-68h] BYREF

  if ( a2 <= 0 )
    sub_66A33D40("n_inputs >= 1", "libnc.c", 6237);
  v4 = *a1;
  v26 = *(_QWORD *)(*(_QWORD *)(*a1 + 40) + 24i64);
  v27 = *(_QWORD *)(*a1 + 8i64 * a3 + 120);
  if ( a3 < 0 || a3 >= *(_DWORD *)(v4 + 80) )
  {
    sub_66A33D40("axis >= 0 && axis < x0->n_dims", "libnc.c", 6241);
    v5 = a2 <= 1;
    if ( a2 != 1 )
      goto LABEL_6;
    return (_QWORD *)*a1;
  }
  v5 = a2 <= 1;
  if ( a2 == 1 )
    return (_QWORD *)*a1;
LABEL_6:
  if ( !v5 )
  {
    v6 = a1[1];
    if ( v26 != *(_QWORD *)(*(_QWORD *)(v6 + 40) + 24i64) )
LABEL_20:
      nc_error("all operation tensors must be on the same device");
    v7 = a1 + 2;
    while ( 1 )
    {
      if ( *(_DWORD *)(v6 + 80) != *(_DWORD *)(v4 + 80) )
        sub_66A33D40("x->n_dims == x0->n_dims", "libnc.c", 6251);
      if ( *(_DWORD *)(v6 + 48) != *(_DWORD *)(v4 + 48) )
        sub_66A33D40("x->item_type == x0->item_type", "libnc.c", 6252);
      v8 = *(_DWORD *)(v6 + 80);
      v9 = 120i64;
      for ( i = 0; i < v8; v9 += 8i64 )
      {
        if ( a3 != i && *(_QWORD *)(v6 + v9) != *(_QWORD *)(v4 + v9) )
        {
          sub_66A33D40("x->dims[j] == x0->dims[j]", "libnc.c", 6255);
          v8 = *(_DWORD *)(v6 + 80);
        }
        ++i;
      }
      v27 += *(_QWORD *)(v6 + 8 * (a3 + 12i64) + 24);
      if ( v7 == &a1[(unsigned int)(a2 - 2) + 2] )
        break;
      v6 = *v7++;
      if ( v26 != *(_QWORD *)(*(_QWORD *)(v6 + 40) + 24i64) )
        goto LABEL_20;
    }
  }
  v13 = *(_DWORD *)(v4 + 80);
  if ( v13 > 0 )
  {
    v29[0] = *(_QWORD *)(v4 + 120);
    if ( v13 != 1 )
    {
      v29[1] = *(_QWORD *)(v4 + 128);
      if ( v13 != 2 )
      {
        v29[2] = *(_QWORD *)(v4 + 136);
        if ( v13 != 3 )
          v29[3] = *(_QWORD *)(v4 + 144);
      }
    }
  }
  v14 = *(_DWORD *)(v4 + 48);
  v29[a3] = v27;
  v11 = nc_new_tensor_nz(v26, v14, v13, (__int64)v29);
  if ( a2 <= 0 )
  {
    v25 = sub_66A15DA0(14, v11 + 3, (__int64 **)v11 + 4, a2, (__int64)a1);
    if ( v25 )
    {
      *((_DWORD *)v25 + 16) = a3;
      v25[7] = aligned_malloc(8i64 * a2, 0x40ui64);
    }
  }
  else
  {
    v15 = 0i64;
    v16 = a1;
    v28 = 8i64 * (unsigned int)(a2 - 1) + 8;
    v17 = 8i64 * a3;
    do
    {
      v18 = *v16++;
      v19 = nc_slice_alias((__int64)v11, a3, v15, *(_QWORD *)(v18 + v17 + 120) + v15);
      nc_tensor_copy((__int64)v19, v18);
      nc_free_tensor(v19);
      v15 += *(_QWORD *)(v18 + v17 + 120);
    }
    while ( v16 != (__int64 *)((char *)a1 + v28) );
    v20 = a1;
    v21 = sub_66A15DA0(14, v11 + 3, (__int64 **)v11 + 4, a2, (__int64)a1);
    v22 = v21;
    if ( v21 )
    {
      *((_DWORD *)v21 + 16) = a3;
      v21[7] = aligned_malloc(8i64 * a2, 0x40ui64);
      v23 = 0i64;
      do
      {
        *(_QWORD *)(v22[7] + v23) = *(_QWORD *)(a1[v23 / 8] + 8 * (a3 + 12i64) + 24);
        v23 += 8i64;
      }
      while ( v28 != v23 );
    }
    do
    {
      v24 = (_DWORD *)*v20++;
      nc_free_tensor(v24);
    }
    while ( v16 != v20 );
  }
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

