// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_param
// Included functions: 3

// ======================================================
// Function: nc_new_param @ 0x66A318A0
// ======================================================

_QWORD *nc_new_param(__int64 *a1, __int64 *a2, const char *a3, ...)
{
  _QWORD *v5; // rbx
  __int64 v6; // rax
  _QWORD *result; // rax
  __int64 v8; // r15
  _QWORD *v9; // rsi
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rsi
  _QWORD *v13; // rax
  __int64 v14; // [rsp+28h] [rbp-A0h]
  char Buffer[136]; // [rsp+40h] [rbp-88h] BYREF
  va_list ArgList; // [rsp+E8h] [rbp+20h] BYREF

  va_start(ArgList, a3);
  j__vsnprintf(Buffer, 0x40ui64, a3, ArgList);
  v5 = aligned_malloc(0x38ui64, 0x40ui64);
  if ( !v5 )
  {
    MEMORY[0x10] = a2;
    BUG();
  }
  memset(v5, 0, 0x38ui64);
  v5[2] = a2;
  v5[3] = strdup(Buffer);
  if ( *((_DWORD *)a1 + 4) )
  {
    v8 = *a2;
    if ( *(_QWORD *)(*a2 + 32) )
      sub_66A33D40("!x->node", "libnc.c", 5351);
    v14 = *(_QWORD *)(v8 + 24);
    v9 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v9 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v9, 0, 0x80ui64);
    *((_DWORD *)v9 + 4) = 1;
    *((_DWORD *)v9 + 5) = 1;
    v9[4] = aligned_malloc(0i64, 0x40ui64);
    v10 = *(_QWORD *)(v14 + 72);
    *(_QWORD *)(v14 + 72) = v10 + 1;
    v9[12] = v10;
    v11 = *(_QWORD *)(v14 + 32);
    *(_QWORD *)(v11 + 8) = v9;
    *v9 = v11;
    v9[1] = v14 + 32;
    *(_QWORD *)(v14 + 32) = v9;
    *(_QWORD *)(v8 + 32) = v9;
    v9[7] = v5;
    *((_DWORD *)v9 + 16) = 0;
    v12 = *(_QWORD *)(*a2 + 32);
    if ( v12 )
    {
      free(*(void **)(v12 + 104));
      *(_QWORD *)(v12 + 104) = strdup(Buffer);
    }
    if ( *(_DWORD *)(v8 + 48) == 1 )
    {
      v13 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(v8 + 40) + 24i64), 1u, *(_DWORD *)(v8 + 80), v8 + 120);
      v5[4] = v13;
      nc_tensor_set_u32((__int64)v13, 0x8000u);
    }
  }
  v6 = *a1;
  *(_QWORD *)(v6 + 8) = v5;
  *v5 = v6;
  result = v5;
  v5[1] = a1;
  *a1 = (__int64)v5;
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

