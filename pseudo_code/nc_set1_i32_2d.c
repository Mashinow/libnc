// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_set1_i32_2d
// Included functions: 3

// ======================================================
// Function: nc_set1_i32_2d @ 0x66A17530
// ======================================================

__int64 __fastcall nc_set1_i32_2d(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // rbp
  __int64 v5; // rax
  int v9; // ecx
  __int64 (__fastcall *v10)(__int64, __int64, int *, __int64); // r10
  __int64 v11; // r9
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rdi
  int v16[4]; // [rsp+20h] [rbp-48h] BYREF
  __int64 v17; // [rsp+30h] [rbp-38h]
  __int64 v18; // [rsp+38h] [rbp-30h]
  __int64 v19; // [rsp+40h] [rbp-28h]
  __int64 v20; // [rsp+48h] [rbp-20h]

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v5 = *(unsigned int *)(a1 + 48);
  v17 = a2;
  v18 = a3;
  switch ( (_DWORD)v5 )
  {
    case 4:
      LOWORD(v16[0]) = a4;
      break;
    case 5:
      v16[0] = a4;
      break;
    case 3:
      LOBYTE(v16[0]) = a4;
      break;
    default:
      abort();
  }
  v9 = *(_DWORD *)(a1 + 80);
  if ( v9 == 2 )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v4 + 88);
    v11 = nc_type_size_table[v5];
    v12 = *(_QWORD *)(a1 + 56);
  }
  else
  {
    sub_66A33D40("y->n_dims == n_dims", "libnc.c", 4938);
    v9 = *(_DWORD *)(a1 + 80);
    v10 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v4 + 88);
    v11 = nc_type_size_table[*(unsigned int *)(a1 + 48)];
    v12 = *(_QWORD *)(a1 + 56);
    v13 = 0i64;
    if ( v9 <= 0 )
      return v10(v4, v12 + v13, v16, v11);
  }
  v14 = *(_QWORD *)(a1 + 88) * a2;
  v13 = v14;
  if ( v9 != 1 )
  {
    v13 = *(_QWORD *)(a1 + 96) * a3 + v14;
    if ( v9 != 2 )
    {
      v13 += v19 * *(_QWORD *)(a1 + 104);
      if ( v9 != 3 )
        v13 += *(_QWORD *)(a1 + 112) * v20;
    }
  }
  return v10(v4, v12 + v13, v16, v11);
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

