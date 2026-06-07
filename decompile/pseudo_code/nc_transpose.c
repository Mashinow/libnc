// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_transpose
// Included functions: 3

// ======================================================
// Function: nc_transpose @ 0x66A24D60
// ======================================================

_QWORD *__fastcall nc_transpose(__int64 a1)
{
  int v1; // ebp
  __int64 v3; // rax
  __int64 v4; // rdx
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax
  _QWORD *v9; // r12
  __int64 *v11; // rax
  __int64 v12; // r13
  __int64 *v13; // r14
  _QWORD *v14; // rbx
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 *v19; // rcx
  _QWORD *v20; // rbx
  __int64 v21; // rdx
  _DWORD *v22; // rcx
  int Src[2]; // [rsp+40h] [rbp-98h] BYREF
  int v24; // [rsp+48h] [rbp-90h]
  int v25; // [rsp+4Ch] [rbp-8Ch]
  __int64 v26[4]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v27[13]; // [rsp+70h] [rbp-68h] BYREF

  v1 = *(_DWORD *)(a1 + 80);
  if ( v1 <= 1 )
  {
    sub_66A33D40("x->n_dims >= 2", "libnc.c", 6517);
    v1 = *(_DWORD *)(a1 + 80);
  }
  Src[0] = 1;
  Src[1] = 0;
  if ( v1 <= 2 )
  {
    if ( v1 <= 0 )
      goto LABEL_10;
  }
  else
  {
    v24 = 2;
    if ( v1 != 3 )
      v25 = 3;
  }
  v26[0] = *(_QWORD *)(a1 + 128);
  v27[0] = *(_QWORD *)(a1 + 96);
  if ( v1 != 1 )
  {
    v26[1] = *(_QWORD *)(a1 + 120);
    v27[1] = *(_QWORD *)(a1 + 88);
    if ( v1 != 2 )
    {
      v3 = a1 + 8i64 * v24;
      v4 = *(_QWORD *)(v3 + 120);
      v5 = *(_QWORD *)(v3 + 88);
      v26[2] = v4;
      v27[2] = v5;
      if ( v1 != 3 )
      {
        v6 = a1 + 8i64 * v25;
        v7 = *(_QWORD *)(v6 + 120);
        v8 = *(_QWORD *)(v6 + 88);
        v26[3] = v7;
        v27[3] = v8;
      }
    }
  }
LABEL_10:
  v9 = nc_new_tensor_from_buffer(
         *(_QWORD *)(a1 + 24),
         *(_QWORD *)(a1 + 40),
         *(_DWORD *)(a1 + 48),
         v1,
         v26,
         *(_QWORD *)(a1 + 56) - *(_QWORD *)(*(_QWORD *)(a1 + 40) + 40i64),
         v27);
  if ( !*(_QWORD *)(a1 + 32) )
    goto LABEL_11;
  v11 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
  v12 = v9[3];
  v13 = v11;
  *v11 = *(_QWORD *)(a1 + 32);
  v14 = aligned_malloc(0x80ui64, 0x40ui64);
  if ( !v14 )
  {
    MEMORY[0x10] = 0;
    BUG();
  }
  memset(v14, 0, 0x80ui64);
  *((_DWORD *)v14 + 4) = 1;
  *((_DWORD *)v14 + 5) = 29;
  *((_DWORD *)v14 + 6) = 1;
  v15 = aligned_malloc(8ui64, 0x40ui64);
  v16 = *v13;
  v14[4] = v15;
  if ( v16 )
  {
    ++*(_DWORD *)(v16 + 16);
    *v15 = v16;
  }
  else
  {
    *v15 = 0i64;
  }
  v17 = *(_QWORD *)(v12 + 72);
  *(_QWORD *)(v12 + 72) = v17 + 1;
  v14[12] = v17;
  v18 = *(_QWORD *)(v12 + 32);
  *(_QWORD *)(v18 + 8) = v14;
  *v14 = v18;
  v14[1] = v12 + 32;
  *(_QWORD *)(v12 + 32) = v14;
  _aligned_free(v13);
  v19 = (__int64 *)v9[4];
  if ( v19 )
    nc_free_node(v19);
  v9[4] = v14;
  *((_DWORD *)v14 + 14) = v1;
  if ( v1 > 0 )
  {
    memcpy((char *)v14 + 60, Src, 4i64 * (unsigned int)(v1 - 1) + 4);
    nc_free_tensor((_DWORD *)a1);
    if ( *((_BYTE *)v9 + 72) )
      return v9;
  }
  else
  {
LABEL_11:
    nc_free_tensor((_DWORD *)a1);
    if ( *((_BYTE *)v9 + 72) )
      return v9;
  }
  v20 = nc_new_tensor_nz(*(_QWORD *)(v9[5] + 24i64), *((_DWORD *)v9 + 12), *((_DWORD *)v9 + 20), (__int64)(v9 + 15));
  nc_tensor_copy((__int64)v20, (__int64)v9);
  v21 = v9[4];
  if ( v21 )
  {
    ++*(_DWORD *)(v21 + 16);
    v20[4] = v21;
  }
  v22 = v9;
  v9 = v20;
  nc_free_tensor(v22);
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

