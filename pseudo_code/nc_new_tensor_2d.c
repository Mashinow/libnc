// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_2d
// Included functions: 3

// ======================================================
// Function: nc_new_tensor_2d @ 0x66A14E70
// ======================================================

_QWORD *__fastcall nc_new_tensor_2d(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r12
  __int64 v5; // rsi
  _QWORD *v9; // rbx
  __int64 v10; // rdi
  __int64 v11; // rdi
  __int64 *v12; // r13
  __int64 v13; // rdi
  _DWORD *v14; // rsi
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax

  v4 = *(_QWORD *)(a1 + 16);
  v5 = a2;
  if ( a2 > 5 )
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  v9 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v9 )
  {
    MEMORY[0x18] = v4;
    BUG();
  }
  memset(v9, 0, 0x98ui64);
  *((_DWORD *)v9 + 12) = v5;
  v9[15] = a3;
  v10 = nc_type_size_table[v5];
  v9[8] = a3;
  *((_BYTE *)v9 + 73) = 1;
  v9[11] = v10;
  v11 = a3 * v10;
  *((_BYTE *)v9 + 74) = 1;
  *((_BYTE *)v9 + 72) = 1;
  v12 = *(__int64 **)(a1 + 16);
  v9[12] = v11;
  v13 = a4 * v11;
  v9[3] = v4;
  *((_DWORD *)v9 + 4) = 1;
  *((_DWORD *)v9 + 20) = 2;
  v9[16] = a4;
  v14 = aligned_malloc(0x38ui64, 0x40ui64);
  v14[4] = 1;
  *((_QWORD *)v14 + 3) = a1;
  v15 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v14 + 10, v13);
  *((_QWORD *)v14 + 4) = v15;
  if ( !v15 )
    nc_error("not enough device memory");
  v16 = *v12;
  *((_QWORD *)v14 + 6) = v13;
  *(_QWORD *)(v16 + 8) = v14;
  *(_QWORD *)v14 = v16;
  v17 = *((_QWORD *)v14 + 5);
  *((_QWORD *)v14 + 1) = v12;
  *v12 = (__int64)v14;
  v9[7] = v17;
  v18 = *(_QWORD *)(v4 + 16);
  v9[5] = v14;
  *(_QWORD *)(v18 + 8) = v9;
  *v9 = v18;
  v9[1] = v4 + 16;
  *(_QWORD *)(v4 + 16) = v9;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(a1 + 104))(a1, v9[7], 0i64, v13, 0);
  return v9;
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

