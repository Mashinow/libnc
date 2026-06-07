// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_get1_f32_1d
// Included functions: 3

// ======================================================
// Function: nc_get1_f32_1d @ 0x66A1A1F0
// ======================================================

__m128 __fastcall nc_get1_f32_1d(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rsi
  int v6; // edx
  void (__fastcall *v8)(__int64, int *, __int64, __int64); // r10
  __int64 v9; // rax
  __int64 v10; // r8
  __m128 result; // xmm0
  int v12[7]; // [rsp+2Ch] [rbp-1Ch] BYREF
  __int64 v14; // [rsp+60h] [rbp+18h]
  __int64 v15; // [rsp+68h] [rbp+20h]

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v6 = *(_DWORD *)(a1 + 80);
  if ( v6 != 1 )
  {
    sub_66A33D40("x->n_dims == n_dims", "libnc.c", 5434);
    if ( !*(_DWORD *)(a1 + 48) )
      goto LABEL_3;
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a1 + 48) )
  {
LABEL_9:
    sub_66A33D40("x->item_type == NC_TYPE_F32", "libnc.c", 5435);
LABEL_3:
    v6 = *(_DWORD *)(a1 + 80);
    v8 = *(void (__fastcall **)(__int64, int *, __int64, __int64))(v5 + 96);
    v9 = 0i64;
    v10 = *(_QWORD *)(a1 + 56);
    if ( v6 <= 0 )
      goto LABEL_8;
    goto LABEL_4;
  }
  v8 = *(void (__fastcall **)(__int64, int *, __int64, __int64))(v5 + 96);
  v10 = *(_QWORD *)(a1 + 56);
LABEL_4:
  v9 = a2 * *(_QWORD *)(a1 + 88);
  if ( v6 != 1 )
  {
    v9 += v14 * *(_QWORD *)(a1 + 96);
    if ( v6 != 2 )
    {
      v9 += v15 * *(_QWORD *)(a1 + 104);
      if ( v6 != 3 )
        v9 += *(_QWORD *)(a1 + 112) * a5;
    }
  }
LABEL_8:
  v8(v5, v12, v9 + v10, 4i64);
  __asm { vmovss  xmm0, [rsp+48h+var_1C] }
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

