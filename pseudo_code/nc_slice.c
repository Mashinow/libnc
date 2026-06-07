// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_slice
// Included functions: 3

// ======================================================
// Function: nc_slice @ 0x66A22FA0
// ======================================================

__int64 __fastcall nc_slice(__int64 a1, int a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 v4; // rbp
  __int64 v9; // r14
  __int64 v10; // rdx
  int v11; // r9d
  __int64 v12; // rax
  __int64 v13; // rbx
  _QWORD *v14; // rax
  __int64 v15; // rbp
  _DWORD *v17; // rax
  _DWORD *v18; // rbx
  _QWORD *v19; // rax
  __int64 v20; // rdx
  __int64 *v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 *v24; // rcx
  _QWORD *v25; // rbx
  __int64 v26; // rdx
  _DWORD *v27; // rcx
  __int64 *Block; // [rsp+40h] [rbp-78h]
  __int64 v29; // [rsp+48h] [rbp-70h]
  unsigned __int64 v30; // [rsp+50h] [rbp-68h] BYREF
  unsigned __int64 v31; // [rsp+58h] [rbp-60h]
  unsigned __int64 v32; // [rsp+60h] [rbp-58h]
  __int64 v33; // [rsp+68h] [rbp-50h]

  v4 = *(_QWORD *)(a1 + 24);
  if ( a2 >= 0 && a2 < *(_DWORD *)(a1 + 80) )
  {
    if ( a3 < a4 )
      goto LABEL_4;
LABEL_19:
    sub_66A33D40("start < end", "libnc.c", 4000);
    v9 = a1 + 8i64 * a2;
    if ( a4 <= *(_QWORD *)(v9 + 120) )
      goto LABEL_5;
    goto LABEL_20;
  }
  sub_66A33D40("axis >= 0 && axis < x->n_dims", "libnc.c", 3999);
  if ( a3 >= a4 )
    goto LABEL_19;
LABEL_4:
  v9 = a1 + 8i64 * a2;
  if ( a4 <= *(_QWORD *)(v9 + 120) )
    goto LABEL_5;
LABEL_20:
  sub_66A33D40("start >= 0 && end <= x->dims[axis]", "libnc.c", 4001);
LABEL_5:
  v10 = *(_QWORD *)(a1 + 40);
  v11 = *(_DWORD *)(a1 + 80);
  v12 = *(_QWORD *)(v9 + 88) * a3 + *(_QWORD *)(a1 + 56) - *(_QWORD *)(v10 + 40);
  if ( v11 <= 0 )
    goto LABEL_15;
  if ( a2 )
  {
    v30 = *(_QWORD *)(a1 + 120);
    if ( v11 == 1 )
      goto LABEL_15;
    if ( a2 == 1 )
    {
      v31 = a4 - a3;
      if ( v11 != 2 )
        goto LABEL_11;
      goto LABEL_15;
    }
  }
  else
  {
    v30 = a4 - a3;
    if ( v11 == 1 )
      goto LABEL_15;
  }
  v31 = *(_QWORD *)(a1 + 128);
  if ( v11 <= 2 )
    goto LABEL_15;
  if ( a2 != 2 )
  {
LABEL_11:
    v32 = *(_QWORD *)(a1 + 136);
    if ( v11 <= 3 )
      goto LABEL_15;
    v13 = a4 - a3;
    if ( a2 == 3 )
      goto LABEL_14;
    goto LABEL_13;
  }
  v32 = a4 - a3;
  if ( v11 != 3 )
  {
LABEL_13:
    v13 = *(_QWORD *)(a1 + 144);
LABEL_14:
    v33 = v13;
  }
LABEL_15:
  v14 = nc_new_tensor_from_buffer(v4, v10, *(_DWORD *)(a1 + 48), v11, (__int64 *)&v30, v12, (__int64 *)(a1 + 88));
  v15 = (__int64)v14;
  if ( !*((_BYTE *)v14 + 72) )
  {
    v25 = nc_new_tensor_nz(
            *(_QWORD *)(v14[5] + 24i64),
            *((_DWORD *)v14 + 12),
            *((_DWORD *)v14 + 20),
            (__int64)(v14 + 15));
    nc_tensor_copy((__int64)v25, v15);
    v26 = *(_QWORD *)(v15 + 32);
    if ( v26 )
    {
      ++*(_DWORD *)(v26 + 16);
      v25[4] = v26;
    }
    v27 = (_DWORD *)v15;
    v15 = (__int64)v25;
    nc_free_tensor(v27);
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    Block = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v29 = *(_QWORD *)(v15 + 24);
    *Block = *(_QWORD *)(a1 + 32);
    v17 = aligned_malloc(0x80ui64, 0x40ui64);
    v18 = v17;
    if ( !v17 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v17, 0, 0x80ui64);
    v17[4] = 1;
    v17[5] = 15;
    v17[6] = 1;
    v19 = aligned_malloc(8ui64, 0x40ui64);
    *((_QWORD *)v18 + 4) = v19;
    v20 = *Block;
    if ( *Block )
    {
      ++*(_DWORD *)(v20 + 16);
      v21 = Block;
      *v19 = v20;
    }
    else
    {
      *v19 = 0i64;
      v21 = Block;
    }
    v22 = *(_QWORD *)(v29 + 72);
    *(_QWORD *)(v29 + 72) = v22 + 1;
    *((_QWORD *)v18 + 12) = v22;
    v23 = *(_QWORD *)(v29 + 32);
    *(_QWORD *)(v23 + 8) = v18;
    *(_QWORD *)v18 = v23;
    *((_QWORD *)v18 + 1) = v29 + 32;
    *(_QWORD *)(v29 + 32) = v18;
    _aligned_free(v21);
    v24 = *(__int64 **)(v15 + 32);
    if ( v24 )
      nc_free_node(v24);
    *(_QWORD *)(v15 + 32) = v18;
    v18[14] = a2;
    *((_QWORD *)v18 + 8) = a3;
    *((_QWORD *)v18 + 9) = *(_QWORD *)(v9 + 120);
  }
  nc_free_tensor((_DWORD *)a1);
  return v15;
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

