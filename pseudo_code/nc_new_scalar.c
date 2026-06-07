// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_scalar
// Included functions: 3

// ======================================================
// Function: nc_new_scalar @ 0x66A14CC0
// ======================================================

_QWORD *__fastcall nc_new_scalar(__int64 a1, unsigned int a2)
{
  __int64 v2; // r12
  __int64 v3; // rsi
  _QWORD *v5; // rbx
  __int64 v6; // rdi
  __int64 *v7; // r13
  _DWORD *v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax

  v2 = *(_QWORD *)(a1 + 16);
  v3 = a2;
  if ( a2 > 5 )
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  v5 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v5 )
  {
    MEMORY[0x18] = v2;
    BUG();
  }
  memset(v5, 0, 0x98ui64);
  *((_DWORD *)v5 + 12) = v3;
  *((_BYTE *)v5 + 72) = 1;
  v6 = nc_type_size_table[v3];
  v5[3] = v2;
  *((_DWORD *)v5 + 4) = 1;
  v7 = *(__int64 **)(a1 + 16);
  v5[15] = 1i64;
  v5[8] = 1i64;
  v8 = aligned_malloc(0x38ui64, 0x40ui64);
  v8[4] = 1;
  *((_QWORD *)v8 + 3) = a1;
  v9 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v8 + 10, v6);
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
  v12 = *(_QWORD *)(v2 + 16);
  v5[5] = v8;
  *(_QWORD *)(v12 + 8) = v5;
  *v5 = v12;
  v5[1] = v2 + 16;
  *(_QWORD *)(v2 + 16) = v5;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(a1 + 104))(a1, v5[7], 0i64, v6, 0);
  return v5;
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

