// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_get_col
// Included functions: 3

// ======================================================
// Function: nc_get_col @ 0x66A26C20
// ======================================================

_QWORD *__fastcall nc_get_col(__int64 a1, __int64 a2)
{
  __int64 v2; // rbx
  __int64 v5; // rax
  unsigned int v6; // edx
  _QWORD *v7; // r12
  __int64 *v9; // rax
  __int64 v10; // r13
  __int64 *v11; // r15
  _QWORD *v12; // rbx
  _QWORD *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 *v17; // rcx
  _QWORD *v18; // rax
  int v19; // [rsp+48h] [rbp-60h]
  __int64 v20[11]; // [rsp+50h] [rbp-58h] BYREF

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a2 + 48) != 5 )
    nc_error("unsupported type for %s\n", "nc_get_col");
  if ( *(_DWORD *)(a1 + 80) != 2 )
    sub_66A33D40("w->n_dims == 2", "libnc.c", 6729);
  if ( *(_DWORD *)(a2 + 80) != 1 )
    sub_66A33D40("x->n_dims == 1", "libnc.c", 6730);
  if ( *(_BYTE *)(a2 + 73) )
  {
    if ( *(_BYTE *)(a1 + 73) )
      goto LABEL_9;
  }
  else
  {
    sub_66A33D40("x->contig[0]", "libnc.c", 6731);
    if ( *(_BYTE *)(a1 + 73) )
      goto LABEL_9;
  }
  sub_66A33D40("w->contig[0]", "libnc.c", 6732);
LABEL_9:
  v5 = *(_QWORD *)(a2 + 120);
  v6 = *(_DWORD *)(a1 + 48);
  v20[0] = *(_QWORD *)(a1 + 120);
  v20[1] = v5;
  v7 = nc_new_tensor_nz(v2, v6, 2, (__int64)v20);
  v19 = dword_66A375E0[*(unsigned int *)(a1 + 48)];
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _DWORD, int))(v2 + 448))(
    v2,
    v7[7],
    v7[12] >> v19,
    *(_QWORD *)(a1 + 56),
    *(_QWORD *)(a1 + 96) >> v19,
    *(_QWORD *)(a1 + 128),
    *(_QWORD *)(a2 + 56),
    *(_QWORD *)(a1 + 120),
    *(_QWORD *)(a2 + 120),
    v19);
  if ( *(_QWORD *)(a1 + 32) )
  {
    v9 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v10 = v7[3];
    v11 = v9;
    *v9 = *(_QWORD *)(a1 + 32);
    v12 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v12 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v12, 0, 0x80ui64);
    *((_DWORD *)v12 + 4) = 1;
    *((_DWORD *)v12 + 5) = 31;
    *((_DWORD *)v12 + 6) = 1;
    v13 = aligned_malloc(8ui64, 0x40ui64);
    v14 = *v11;
    v12[4] = v13;
    if ( v14 )
    {
      ++*(_DWORD *)(v14 + 16);
      *v13 = v14;
    }
    else
    {
      *v13 = 0i64;
    }
    v15 = *(_QWORD *)(v10 + 72);
    *(_QWORD *)(v10 + 72) = v15 + 1;
    v12[12] = v15;
    v16 = *(_QWORD *)(v10 + 32);
    *(_QWORD *)(v16 + 8) = v12;
    *v12 = v16;
    v12[1] = v10 + 32;
    *(_QWORD *)(v10 + 32) = v12;
    _aligned_free(v11);
    v17 = (__int64 *)v7[4];
    if ( v17 )
      nc_free_node(v17);
    v7[4] = v12;
    *((_DWORD *)v12 + 10) = 1;
    v18 = aligned_malloc(8ui64, 0x40ui64);
    v12[6] = v18;
    ++*(_DWORD *)(a2 + 16);
    *v18 = a2;
    v12[7] = *(_QWORD *)(a1 + 128);
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v7;
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

