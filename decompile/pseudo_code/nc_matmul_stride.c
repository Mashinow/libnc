// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_matmul_stride
// Included functions: 3

// ======================================================
// Function: nc_matmul_stride @ 0x66A268E0
// ======================================================

_QWORD *__fastcall nc_matmul_stride(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v5; // r14
  int v6; // esi
  unsigned int v7; // r9d
  __int64 v8; // r15
  _QWORD *v9; // rbx
  __int64 v10; // rdi
  __int64 *v11; // r9
  __int64 v12; // rdi
  __int64 v13; // rdi
  __int64 v14; // rsi
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  unsigned int v22; // [rsp+38h] [rbp-80h]
  __int64 *v23; // [rsp+38h] [rbp-80h]
  unsigned int v24; // [rsp+38h] [rbp-80h]
  unsigned int *v25; // [rsp+48h] [rbp-70h]

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( !*(_DWORD *)(v2 + 32) )
    sub_66A33D40("d->is_host", "libnc.c", 6683);
  v25 = **(unsigned int ***)(v2 + 24);
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( (*(_DWORD *)(a1 + 48) & 0xFFFFFFFD) != 0 )
    sub_66A33D40("w->item_type == NC_TYPE_F32 || w->item_type == NC_TYPE_F16", "libnc.c", 6689);
  if ( *(_DWORD *)(a2 + 48) )
    sub_66A33D40("x->item_type == NC_TYPE_F32", "libnc.c", 6690);
  if ( *(_DWORD *)(a1 + 80) != 3 )
    sub_66A33D40("w->n_dims == 3", "libnc.c", 6691);
  if ( *(_DWORD *)(a2 + 80) != 2 )
    sub_66A33D40("x->n_dims == 2", "libnc.c", 6692);
  v5 = *(_QWORD *)(a2 + 128);
  v6 = *(_DWORD *)(a1 + 120) * *(_QWORD *)(a1 + 136);
  if ( *(_DWORD *)(a1 + 128) != *(_QWORD *)(a2 + 120) )
    sub_66A33D40("k == x->dims[0]", "libnc.c", 6696);
  v7 = *(_DWORD *)(a2 + 48);
  v8 = *(_QWORD *)(v2 + 16);
  if ( v7 > 5 )
  {
    v24 = *(_DWORD *)(a2 + 48);
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
    v7 = v24;
  }
  v22 = v7;
  v9 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v9 )
  {
    MEMORY[0x18] = v8;
    BUG();
  }
  memset(v9, 0, 0x98ui64);
  *((_BYTE *)v9 + 73) = 1;
  *((_DWORD *)v9 + 12) = v22;
  v10 = nc_type_size_table[v22];
  *((_BYTE *)v9 + 74) = 1;
  *((_BYTE *)v9 + 72) = 1;
  v11 = *(__int64 **)(v2 + 16);
  v9[11] = v10;
  v12 = v6 * v10;
  v23 = v11;
  v9[15] = v6;
  v9[12] = v12;
  v13 = (int)v5 * v12;
  v9[8] = v6;
  v9[3] = v8;
  *((_DWORD *)v9 + 4) = 1;
  *((_DWORD *)v9 + 20) = 2;
  v9[16] = (int)v5;
  v14 = ((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(56i64, 64i64);
  *(_DWORD *)(v14 + 16) = 1;
  *(_QWORD *)(v14 + 24) = v2;
  v15 = (*(__int64 (__fastcall **)(__int64, __int64, __int64))(v2 + 48))(v2, v14 + 40, v13);
  *(_QWORD *)(v14 + 32) = v15;
  if ( !v15 )
    nc_error("not enough device memory", v16, v17, v23);
  v18 = *v23;
  *(_QWORD *)(v14 + 48) = v13;
  *(_QWORD *)(v18 + 8) = v14;
  *(_QWORD *)v14 = v18;
  v19 = *(_QWORD *)(v14 + 40);
  *(_QWORD *)(v14 + 8) = v23;
  *v23 = v14;
  v9[7] = v19;
  v20 = *(_QWORD *)(v8 + 16);
  v9[5] = v14;
  *(_QWORD *)(v20 + 8) = v9;
  *v9 = v20;
  v9[1] = v8 + 16;
  *(_QWORD *)(v8 + 16) = v9;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(v2 + 104))(v2, v9[7], 0i64, v13, 0);
  nc_job_get_max_threads(v25);
  nc_job_exec();
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
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

