// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_param_str
// Included functions: 3

// ======================================================
// Function: nc_new_param_str @ 0x66A316F0
// ======================================================

_QWORD *__fastcall nc_new_param_str(__int64 *a1, __int64 *a2, const char *a3)
{
  _QWORD *v6; // rbx
  __int64 v7; // rax
  _QWORD *result; // rax
  __int64 v9; // r15
  _QWORD *v10; // rsi
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rsi
  _QWORD *v14; // rax
  __int64 v15; // [rsp+28h] [rbp-50h]

  v6 = aligned_malloc(0x38ui64, 0x40ui64);
  if ( !v6 )
  {
    MEMORY[0x10] = a2;
    BUG();
  }
  memset(v6, 0, 0x38ui64);
  v6[2] = a2;
  v6[3] = strdup(a3);
  if ( *((_DWORD *)a1 + 4) )
  {
    v9 = *a2;
    if ( *(_QWORD *)(*a2 + 32) )
      sub_66A33D40("!x->node", "libnc.c", 5351);
    v15 = *(_QWORD *)(v9 + 24);
    v10 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v10 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v10, 0, 0x80ui64);
    *((_DWORD *)v10 + 4) = 1;
    *((_DWORD *)v10 + 5) = 1;
    v10[4] = aligned_malloc(0i64, 0x40ui64);
    v11 = *(_QWORD *)(v15 + 72);
    *(_QWORD *)(v15 + 72) = v11 + 1;
    v10[12] = v11;
    v12 = *(_QWORD *)(v15 + 32);
    *(_QWORD *)(v12 + 8) = v10;
    *v10 = v12;
    v10[1] = v15 + 32;
    *(_QWORD *)(v15 + 32) = v10;
    *(_QWORD *)(v9 + 32) = v10;
    v10[7] = v6;
    *((_DWORD *)v10 + 16) = 0;
    v13 = *(_QWORD *)(*a2 + 32);
    if ( v13 )
    {
      free(*(void **)(v13 + 104));
      *(_QWORD *)(v13 + 104) = strdup(a3);
    }
    if ( *(_DWORD *)(v9 + 48) == 1 )
    {
      v14 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(v9 + 40) + 24i64), 1u, *(_DWORD *)(v9 + 80), v9 + 120);
      v6[4] = v14;
      nc_tensor_set_u32((__int64)v14, 0x8000u);
    }
  }
  v7 = *a1;
  *(_QWORD *)(v7 + 8) = v6;
  *v6 = v7;
  result = v6;
  v6[1] = a1;
  *a1 = (__int64)v6;
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

