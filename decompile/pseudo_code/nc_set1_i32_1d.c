// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_set1_i32_1d
// Included functions: 3

// ======================================================
// Function: nc_set1_i32_1d @ 0x66A17420
// ======================================================

__int64 __fastcall nc_set1_i32_1d(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rsi
  __int64 v6; // rax
  int v8; // ecx
  __int64 (__fastcall *v9)(__int64, __int64, int *, __int64); // r10
  __int64 v10; // r9
  __int64 v11; // rax
  __int64 v12; // rdx
  int v14[10]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v16; // [rsp+60h] [rbp+18h]
  __int64 v17; // [rsp+68h] [rbp+20h]

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v6 = *(unsigned int *)(a1 + 48);
  switch ( (_DWORD)v6 )
  {
    case 4:
      LOWORD(v14[0]) = a3;
      break;
    case 5:
      v14[0] = a3;
      break;
    case 3:
      LOBYTE(v14[0]) = a3;
      break;
    default:
      abort();
  }
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 == 1 )
  {
    v9 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v5 + 88);
    v10 = nc_type_size_table[v6];
    v11 = *(_QWORD *)(a1 + 56);
  }
  else
  {
    sub_66A33D40("y->n_dims == n_dims", "libnc.c", 4938);
    v8 = *(_DWORD *)(a1 + 80);
    v9 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v5 + 88);
    v10 = nc_type_size_table[*(unsigned int *)(a1 + 48)];
    v11 = *(_QWORD *)(a1 + 56);
    v12 = 0i64;
    if ( v8 <= 0 )
      return v9(v5, v11 + v12, v14, v10);
  }
  v12 = a2 * *(_QWORD *)(a1 + 88);
  if ( v8 != 1 )
  {
    v12 += v16 * *(_QWORD *)(a1 + 96);
    if ( v8 != 2 )
    {
      v12 += *(_QWORD *)(a1 + 104) * v17;
      if ( v8 != 3 )
        v12 += *(_QWORD *)(a1 + 112) * a5;
    }
  }
  return v9(v5, v11 + v12, v14, v10);
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

