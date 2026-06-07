// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_nz_3d
// Included functions: 3

// ======================================================
// Function: nc_new_tensor_nz_3d @ 0x66A14A80
// ======================================================

_QWORD *__fastcall nc_new_tensor_nz_3d(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // r13
  _QWORD *v10; // rbx
  __int64 v11; // r9
  __int64 v12; // r9
  __int64 *v13; // r12
  __int64 v14; // rsi
  __int64 v15; // rdi
  _DWORD *v16; // rsi
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  _QWORD *result; // rax

  v5 = *(_QWORD *)(a1 + 16);
  if ( a2 > 5 )
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  v10 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v10 )
  {
    MEMORY[0x18] = v5;
    BUG();
  }
  memset(v10, 0, 0x98ui64);
  *((_DWORD *)v10 + 12) = a2;
  v10[16] = a4;
  v11 = nc_type_size_table[a2];
  *((_BYTE *)v10 + 73) = 1;
  *((_BYTE *)v10 + 74) = 1;
  v10[11] = v11;
  v12 = a3 * v11;
  *((_BYTE *)v10 + 75) = 1;
  *((_BYTE *)v10 + 72) = 1;
  v13 = *(__int64 **)(a1 + 16);
  v14 = v12 * a4;
  v10[12] = v12;
  v10[3] = v5;
  *((_DWORD *)v10 + 4) = 1;
  v10[13] = v14;
  v15 = a5 * v14;
  *((_DWORD *)v10 + 20) = 3;
  v10[15] = a3;
  v10[17] = a5;
  v10[8] = a3;
  v16 = aligned_malloc(0x38ui64, 0x40ui64);
  v16[4] = 1;
  *((_QWORD *)v16 + 3) = a1;
  v17 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v16 + 10, v15);
  *((_QWORD *)v16 + 4) = v17;
  if ( !v17 )
    nc_error("not enough device memory");
  v18 = *v13;
  *((_QWORD *)v16 + 6) = v15;
  *(_QWORD *)(v18 + 8) = v16;
  *(_QWORD *)v16 = v18;
  v19 = *((_QWORD *)v16 + 5);
  *((_QWORD *)v16 + 1) = v13;
  *v13 = (__int64)v16;
  v10[7] = v19;
  v20 = *(_QWORD *)(v5 + 16);
  v10[5] = v16;
  *(_QWORD *)(v20 + 8) = v10;
  *v10 = v20;
  v10[1] = v5 + 16;
  result = v10;
  *(_QWORD *)(v5 + 16) = v10;
  return result;
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

