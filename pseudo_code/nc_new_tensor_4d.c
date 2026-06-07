// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_4d
// Included functions: 3

// ======================================================
// Function: nc_new_tensor_4d @ 0x66A15190
// ======================================================

_QWORD *__fastcall nc_new_tensor_4d(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // r14
  _QWORD *v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rdi
  __int64 v14; // rdi
  __int64 *v15; // r12
  __int64 v16; // rdi
  __int64 v17; // rdi
  _DWORD *v18; // rsi
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax

  v6 = *(_QWORD *)(a1 + 16);
  if ( a2 > 5 )
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  v11 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v11 )
  {
    MEMORY[0x18] = v6;
    BUG();
  }
  memset(v11, 0, 0x98ui64);
  *((_BYTE *)v11 + 73) = 1;
  v11[16] = a4;
  v12 = nc_type_size_table[a2];
  *((_BYTE *)v11 + 74) = 1;
  *((_BYTE *)v11 + 75) = 1;
  v11[11] = v12;
  v13 = a3 * v12;
  v11[17] = a5;
  *((_BYTE *)v11 + 76) = 1;
  v11[12] = v13;
  v14 = a4 * v13;
  *((_BYTE *)v11 + 72) = 1;
  v15 = *(__int64 **)(a1 + 16);
  v11[3] = v6;
  v11[13] = v14;
  v16 = a5 * v14;
  *((_DWORD *)v11 + 4) = 1;
  *((_DWORD *)v11 + 12) = a2;
  v11[14] = v16;
  v17 = a6 * v16;
  *((_DWORD *)v11 + 20) = 4;
  v11[15] = a3;
  v11[18] = a6;
  v11[8] = a3;
  v18 = aligned_malloc(0x38ui64, 0x40ui64);
  v18[4] = 1;
  *((_QWORD *)v18 + 3) = a1;
  v19 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v18 + 10, v17);
  *((_QWORD *)v18 + 4) = v19;
  if ( !v19 )
    nc_error("not enough device memory");
  v20 = *v15;
  *((_QWORD *)v18 + 6) = v17;
  *(_QWORD *)(v20 + 8) = v18;
  *(_QWORD *)v18 = v20;
  v21 = *((_QWORD *)v18 + 5);
  *((_QWORD *)v18 + 1) = v15;
  *v15 = (__int64)v18;
  v11[7] = v21;
  v22 = *(_QWORD *)(v6 + 16);
  v11[5] = v18;
  *(_QWORD *)(v22 + 8) = v11;
  *v11 = v22;
  v11[1] = v6 + 16;
  *(_QWORD *)(v6 + 16) = v11;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(a1 + 104))(a1, v11[7], 0i64, v17, 0);
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

