// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_slice_alias
// Included functions: 3

// ======================================================
// Function: nc_slice_alias @ 0x66A14700
// ======================================================

_QWORD *__fastcall nc_slice_alias(__int64 a1, int a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 v4; // rbp
  __int64 v9; // r13
  __int64 v10; // rdx
  int v11; // r9d
  __int64 v12; // rax
  __int64 v13; // rdi
  unsigned __int64 v15; // [rsp+40h] [rbp-58h] BYREF
  unsigned __int64 v16; // [rsp+48h] [rbp-50h]
  unsigned __int64 v17; // [rsp+50h] [rbp-48h]
  __int64 v18; // [rsp+58h] [rbp-40h]

  v4 = *(_QWORD *)(a1 + 24);
  if ( a2 >= 0 && a2 < *(_DWORD *)(a1 + 80) )
  {
    if ( a3 < a4 )
      goto LABEL_4;
LABEL_17:
    sub_66A33D40("start < end", "libnc.c", 4000);
    v9 = a1 + 8i64 * a2;
    if ( a4 <= *(_QWORD *)(v9 + 120) )
      goto LABEL_5;
    goto LABEL_18;
  }
  sub_66A33D40("axis >= 0 && axis < x->n_dims", "libnc.c", 3999);
  if ( a3 >= a4 )
    goto LABEL_17;
LABEL_4:
  v9 = a1 + 8i64 * a2;
  if ( a4 <= *(_QWORD *)(v9 + 120) )
    goto LABEL_5;
LABEL_18:
  sub_66A33D40("start >= 0 && end <= x->dims[axis]", "libnc.c", 4001);
LABEL_5:
  v10 = *(_QWORD *)(a1 + 40);
  v11 = *(_DWORD *)(a1 + 80);
  v12 = *(_QWORD *)(v9 + 88) * a3 + *(_QWORD *)(a1 + 56) - *(_QWORD *)(v10 + 40);
  if ( v11 <= 0 )
    return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
  if ( !a2 )
  {
    v15 = a4 - a3;
    if ( v11 == 1 )
      return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
LABEL_9:
    v16 = *(_QWORD *)(a1 + 128);
    if ( v11 <= 2 )
      return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
    if ( a2 == 2 )
    {
      v17 = a4 - a3;
      if ( v11 == 3 )
        return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
      goto LABEL_13;
    }
    goto LABEL_11;
  }
  v15 = *(_QWORD *)(a1 + 120);
  if ( v11 == 1 )
    return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
  if ( a2 != 1 )
    goto LABEL_9;
  v16 = a4 - a3;
  if ( v11 == 2 )
    return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
LABEL_11:
  v17 = *(_QWORD *)(a1 + 136);
  if ( v11 > 3 )
  {
    v13 = a4 - a3;
    if ( a2 == 3 )
    {
LABEL_14:
      v18 = v13;
      return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
    }
LABEL_13:
    v13 = *(_QWORD *)(a1 + 144);
    goto LABEL_14;
  }
  return nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v15, v12, (__int64 *)(a1 + 88));
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

