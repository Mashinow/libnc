// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_free_tensor
// Included functions: 3

// ======================================================
// Function: nc_free_tensor @ 0x66A15570
// ======================================================

void __fastcall nc_free_tensor(_DWORD *a1)
{
  int v2; // eax
  int v3; // eax
  __int64 v4; // rcx
  __int64 v5; // rdx
  _QWORD *v6; // rax
  _DWORD *v7; // rsi
  void (__cdecl *v8)(void *); // rdi
  int v9; // eax
  int v10; // eax
  __int64 v11; // rcx
  _QWORD *v12; // rdx
  __int64 v13; // rax
  __int64 v14; // rdx
  void **v15; // rax

  if ( !a1 )
    return;
  v2 = a1[4];
  if ( v2 <= 0 )
  {
    sub_66A33D40("x->ref_count >= 1", "libnc.c", 3922);
    v2 = a1[4];
  }
  v3 = v2 - 1;
  a1[4] = v3;
  if ( v3 == 1 )
  {
    v4 = *((_QWORD *)a1 + 4);
    if ( !v4 )
      return;
    if ( *(_DWORD *)(v4 + 16) != 1 )
      return;
    if ( *(int *)(v4 + 40) <= 0 )
      return;
    v15 = *(void ***)(v4 + 48);
    if ( a1 != *v15 )
      return;
    *v15 = 0i64;
    a1[4] = 0;
  }
  else
  {
    if ( v3 )
      return;
    v4 = *((_QWORD *)a1 + 4);
    if ( !v4 )
      goto LABEL_8;
  }
  nc_free_node((__int64 *)v4);
LABEL_8:
  v5 = *(_QWORD *)a1;
  v6 = (_QWORD *)*((_QWORD *)a1 + 1);
  v7 = (_DWORD *)*((_QWORD *)a1 + 5);
  v8 = _aligned_free;
  *(_QWORD *)(v5 + 8) = v6;
  *v6 = v5;
  *(_QWORD *)a1 = 0i64;
  *((_QWORD *)a1 + 1) = 0i64;
  if ( !v7 )
    goto LABEL_12;
  v9 = v7[4];
  if ( v9 <= 0 )
  {
    sub_66A33D40("b->ref_count >= 1", "libnc.c", 3849);
    v9 = v7[4];
  }
  v10 = v9 - 1;
  v8 = _aligned_free;
  v7[4] = v10;
  if ( !v10 )
  {
    v11 = *(_QWORD *)v7;
    v12 = (_QWORD *)*((_QWORD *)v7 + 1);
    v13 = *((_QWORD *)v7 + 3);
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    v14 = *((_QWORD *)v7 + 4);
    *(_QWORD *)v7 = 0i64;
    *((_QWORD *)v7 + 1) = 0i64;
    (*(void (__fastcall **)(__int64, __int64))(v13 + 56))(v13, v14);
    _aligned_free(v7);
    _aligned_free(a1);
  }
  else
  {
LABEL_12:
    ((void (__fastcall *)(_DWORD *))v8)(a1);
  }
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

