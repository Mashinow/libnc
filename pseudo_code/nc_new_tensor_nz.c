// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_nz
// Included functions: 3

// ======================================================
// Function: nc_new_tensor_nz @ 0x66A140A0
// ======================================================

_QWORD *__fastcall nc_new_tensor_nz(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  __int64 v4; // r12
  __int64 v5; // r14
  void *(__cdecl *v9)(size_t, size_t); // r13
  _QWORD *v10; // rbx
  __int64 v11; // rdi
  __int64 *v12; // r14
  _DWORD *v13; // rsi
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  _QWORD *result; // rax
  __int64 v19; // rax
  __int64 v20; // rdi
  unsigned int v21; // eax

  v4 = *(_QWORD *)(a1 + 16);
  v5 = a2;
  if ( a2 <= 5 )
  {
    if ( a3 >= 0 )
      goto LABEL_3;
LABEL_20:
    sub_66A33D40("n_dims >= 0", "libnc.c", 3866);
    v9 = aligned_malloc;
    v10 = aligned_malloc(0x98ui64, 0x40ui64);
    if ( v10 )
    {
      memset(v10, 0, 0x98ui64);
      v10[3] = v4;
      *((_DWORD *)v10 + 4) = 1;
      *((_DWORD *)v10 + 12) = v5;
      v11 = nc_type_size_table[v5];
      *((_DWORD *)v10 + 20) = a3;
      v10[11] = v11;
      goto LABEL_22;
    }
LABEL_10:
    MEMORY[0x18] = v4;
    BUG();
  }
  sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  if ( a3 < 0 )
    goto LABEL_20;
LABEL_3:
  if ( a3 > 4 )
    sub_66A33D40("n_dims <= N_DIMS_MAX", "libnc.c", 3867);
  v9 = aligned_malloc;
  v10 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v10 )
    goto LABEL_10;
  memset(v10, 0, 0x98ui64);
  v10[3] = v4;
  *((_DWORD *)v10 + 4) = 1;
  *((_DWORD *)v10 + 12) = v5;
  v11 = nc_type_size_table[v5];
  *((_DWORD *)v10 + 20) = a3;
  if ( !a3 )
  {
    v10[15] = 1i64;
    v10[8] = 1i64;
    goto LABEL_8;
  }
  v19 = 0i64;
  do
  {
    v10[v19 + 15] = *(_QWORD *)(a4 + 8 * v19);
    ++v19;
  }
  while ( a3 > (int)v19 );
  v10[11] = v11;
  if ( a3 > 1 )
  {
    v20 = v10[15] * v11;
    v10[12] = v20;
    if ( a3 != 2 )
    {
      v20 *= v10[16];
      v10[13] = v20;
      if ( a3 != 3 )
      {
        v20 *= v10[17];
        v10[14] = v20;
      }
    }
    v10[8] = v10[15];
    v21 = a3 - 1;
    v11 = v10[a3 + 14] * v20;
    goto LABEL_18;
  }
LABEL_22:
  v10[8] = v10[15];
  v21 = a3 - 1;
  v11 *= v10[a3 + 14];
  if ( a3 > 0 )
LABEL_18:
    memset((char *)v10 + 73, 1, v21 + 1i64);
LABEL_8:
  *((_BYTE *)v10 + 72) = 1;
  v12 = *(__int64 **)(a1 + 16);
  v13 = v9(0x38ui64, 0x40ui64);
  v13[4] = 1;
  *((_QWORD *)v13 + 3) = a1;
  v14 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v13 + 10, v11);
  *((_QWORD *)v13 + 4) = v14;
  if ( !v14 )
    nc_error("not enough device memory");
  v15 = *v12;
  *((_QWORD *)v13 + 6) = v11;
  *(_QWORD *)(v15 + 8) = v13;
  *(_QWORD *)v13 = v15;
  v16 = *((_QWORD *)v13 + 5);
  *((_QWORD *)v13 + 1) = v12;
  *v12 = (__int64)v13;
  v10[7] = v16;
  v17 = *(_QWORD *)(v4 + 16);
  v10[5] = v13;
  *(_QWORD *)(v17 + 8) = v10;
  *v10 = v17;
  v10[1] = v4 + 16;
  result = v10;
  *(_QWORD *)(v4 + 16) = v10;
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

