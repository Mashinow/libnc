// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_free_node
// Included functions: 3

// ======================================================
// Function: nc_free_node @ 0x66A15430
// ======================================================

void __fastcall nc_free_node(__int64 *a1)
{
  int v2; // eax
  int v3; // eax
  __int64 v4; // rdi
  int v5; // esi
  __int64 v6; // rcx
  __int64 v7; // rdi
  int v8; // esi
  __int64 v9; // rcx
  _QWORD *v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax

  if ( a1 )
  {
    v2 = *((_DWORD *)a1 + 4);
    if ( v2 <= 0 )
    {
      sub_66A33D40("n->ref_count >= 1", "libnc.c", 4270);
      v2 = *((_DWORD *)a1 + 4);
    }
    v3 = v2 - 1;
    *((_DWORD *)a1 + 4) = v3;
    if ( v3 == 1 )
    {
      if ( *((int *)a1 + 10) <= 0 )
        return;
      v12 = *(_QWORD *)a1[6];
      if ( !v12 || a1 != *(__int64 **)(v12 + 32) || *(_DWORD *)(v12 + 16) != 1 )
        return;
      *(_QWORD *)(v12 + 32) = 0i64;
      *((_DWORD *)a1 + 4) = 0;
    }
    else if ( v3 )
    {
      return;
    }
    v4 = 0i64;
    v5 = 0;
    while ( v5 < *((_DWORD *)a1 + 6) )
    {
      ++v5;
      v6 = *(_QWORD *)(a1[4] + v4);
      v4 += 8i64;
      nc_free_node(v6);
    }
    v7 = 0i64;
    v8 = 0;
    _aligned_free((void *)a1[4]);
    if ( *((int *)a1 + 10) > 0 )
    {
      do
      {
        ++v8;
        v9 = *(_QWORD *)(a1[6] + v7);
        v7 += 8i64;
        nc_free_tensor(v9);
      }
      while ( v8 < *((_DWORD *)a1 + 10) );
    }
    if ( *((_DWORD *)a1 + 5) == 14 )
      _aligned_free((void *)a1[7]);
    _aligned_free((void *)a1[6]);
    free((void *)a1[13]);
    v10 = (_QWORD *)a1[1];
    v11 = *a1;
    *(_QWORD *)(v11 + 8) = v10;
    *v10 = v11;
    *a1 = 0i64;
    a1[1] = 0i64;
    _aligned_free(a1);
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

