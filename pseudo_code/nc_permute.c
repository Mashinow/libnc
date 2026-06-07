// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_permute
// Included functions: 3

// ======================================================
// Function: nc_permute @ 0x66A24AA0
// ======================================================

_QWORD *__fastcall nc_permute(__int64 a1, int a2, int *a3)
{
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rax
  _QWORD *v18; // r12
  __int64 *v20; // rax
  __int64 v21; // r14
  _QWORD *v22; // rbx
  _QWORD *v23; // rax
  __int64 v24; // rdx
  __int64 *v25; // rcx
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 *v28; // rcx
  _QWORD *v29; // rbx
  __int64 v30; // rdx
  _DWORD *v31; // rcx
  __int64 *Block; // [rsp+48h] [rbp-90h]
  __int64 v33[4]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v34[13]; // [rsp+70h] [rbp-68h] BYREF

  if ( a2 != *(_DWORD *)(a1 + 80) )
    sub_66A33D40("x->n_dims == n_dims", "libnc.c", 6484);
  if ( a2 > 0 )
  {
    v6 = a1 + 8i64 * *a3;
    v7 = *(_QWORD *)(v6 + 120);
    v8 = *(_QWORD *)(v6 + 88);
    v33[0] = v7;
    v34[0] = v8;
    if ( a2 != 1 )
    {
      v9 = a1 + 8i64 * a3[1];
      v10 = *(_QWORD *)(v9 + 120);
      v11 = *(_QWORD *)(v9 + 88);
      v33[1] = v10;
      v34[1] = v11;
      if ( a2 != 2 )
      {
        v12 = a1 + 8i64 * a3[2];
        v13 = *(_QWORD *)(v12 + 120);
        v14 = *(_QWORD *)(v12 + 88);
        v33[2] = v13;
        v34[2] = v14;
        if ( a2 != 3 )
        {
          v15 = a1 + 8i64 * a3[3];
          v16 = *(_QWORD *)(v15 + 120);
          v17 = *(_QWORD *)(v15 + 88);
          v33[3] = v16;
          v34[3] = v17;
        }
      }
    }
  }
  v18 = nc_new_tensor_from_buffer(
          *(_QWORD *)(a1 + 24),
          *(_QWORD *)(a1 + 40),
          *(_DWORD *)(a1 + 48),
          a2,
          v33,
          *(_QWORD *)(a1 + 56) - *(_QWORD *)(*(_QWORD *)(a1 + 40) + 40i64),
          v34);
  if ( !*(_QWORD *)(a1 + 32) )
    goto LABEL_9;
  v20 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
  v21 = v18[3];
  Block = v20;
  *v20 = *(_QWORD *)(a1 + 32);
  v22 = aligned_malloc(0x80ui64, 0x40ui64);
  if ( !v22 )
  {
    MEMORY[0x10] = 0;
    BUG();
  }
  memset(v22, 0, 0x80ui64);
  *((_DWORD *)v22 + 4) = 1;
  *((_DWORD *)v22 + 5) = 29;
  *((_DWORD *)v22 + 6) = 1;
  v23 = aligned_malloc(8ui64, 0x40ui64);
  v22[4] = v23;
  v24 = *Block;
  if ( *Block )
  {
    ++*(_DWORD *)(v24 + 16);
    v25 = Block;
    *v23 = v24;
  }
  else
  {
    *v23 = 0i64;
    v25 = Block;
  }
  v26 = *(_QWORD *)(v21 + 72);
  *(_QWORD *)(v21 + 72) = v26 + 1;
  v22[12] = v26;
  v27 = *(_QWORD *)(v21 + 32);
  *(_QWORD *)(v27 + 8) = v22;
  *v22 = v27;
  v22[1] = v21 + 32;
  *(_QWORD *)(v21 + 32) = v22;
  _aligned_free(v25);
  v28 = (__int64 *)v18[4];
  if ( v28 )
    nc_free_node(v28);
  v18[4] = v22;
  *((_DWORD *)v22 + 14) = a2;
  if ( a2 <= 0
    || (*((_DWORD *)v22 + 15) = *a3, a2 == 1)
    || (*((_DWORD *)v22 + 16) = a3[1], a2 == 2)
    || (*((_DWORD *)v22 + 17) = a3[2], a2 == 3) )
  {
LABEL_9:
    nc_free_tensor((_DWORD *)a1);
    if ( *((_BYTE *)v18 + 72) )
      return v18;
  }
  else
  {
    *((_DWORD *)v22 + 18) = a3[3];
    nc_free_tensor((_DWORD *)a1);
    if ( *((_BYTE *)v18 + 72) )
      return v18;
  }
  v29 = nc_new_tensor_nz(*(_QWORD *)(v18[5] + 24i64), *((_DWORD *)v18 + 12), *((_DWORD *)v18 + 20), (__int64)(v18 + 15));
  nc_tensor_copy((__int64)v29, (__int64)v18);
  v30 = v18[4];
  if ( v30 )
  {
    ++*(_DWORD *)(v30 + 16);
    v29[4] = v30;
  }
  v31 = v18;
  v18 = v29;
  nc_free_tensor(v31);
  return v18;
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

