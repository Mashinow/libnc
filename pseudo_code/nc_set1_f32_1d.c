// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_set1_f32_1d
// Included functions: 3

// ======================================================
// Function: nc_set1_f32_1d @ 0x66A17300
// ======================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall nc_set1_f32_1d(__int64 a1, __int64 a2, double _XMM2_8, __int64 a4, __int64 a5)
{
  __int64 v5; // rsi
  __int64 v6; // rax
  int v10; // edx
  int v11; // ecx
  __int64 (__fastcall *v12)(__int64, __int64, int *, __int64); // r10
  __int64 v13; // r9
  __int64 v14; // rax
  __int64 v15; // rdx
  int v17[10]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v19; // [rsp+60h] [rbp+18h]
  __int64 v20; // [rsp+68h] [rbp+20h]

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v6 = *(unsigned int *)(a1 + 48);
  if ( (_DWORD)v6 )
  {
    if ( (_DWORD)v6 != 1 )
      abort();
    __asm
    {
      vmovd   ecx, xmm2
      vmovd   edx, xmm2
    }
    v10 = _EDX + (HIWORD(_ECX) & 1) + 0x7FFF;
    v11 = *(_DWORD *)(a1 + 80);
    LOWORD(v17[0]) = HIWORD(v10);
    if ( v11 != 1 )
    {
LABEL_4:
      sub_66A33D40("y->n_dims == n_dims", "libnc.c", 4959);
      v11 = *(_DWORD *)(a1 + 80);
      v12 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v5 + 88);
      v13 = nc_type_size_table[*(unsigned int *)(a1 + 48)];
      v14 = *(_QWORD *)(a1 + 56);
      v15 = 0i64;
      if ( v11 <= 0 )
        return v12(v5, v14 + v15, v17, v13);
      goto LABEL_5;
    }
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 80);
    __asm { vmovss  [rsp+48h+var_28], xmm2 }
    if ( v11 != 1 )
      goto LABEL_4;
  }
  v12 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v5 + 88);
  v13 = nc_type_size_table[v6];
  v14 = *(_QWORD *)(a1 + 56);
LABEL_5:
  v15 = a2 * *(_QWORD *)(a1 + 88);
  if ( v11 != 1 )
  {
    v15 += v19 * *(_QWORD *)(a1 + 96);
    if ( v11 != 2 )
    {
      v15 += *(_QWORD *)(a1 + 104) * v20;
      if ( v11 != 3 )
        v15 += *(_QWORD *)(a1 + 112) * a5;
    }
  }
  return v12(v5, v14 + v15, v17, v13);
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

