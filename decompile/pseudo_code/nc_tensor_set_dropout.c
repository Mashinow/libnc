// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_dropout
// Included functions: 3

// ======================================================
// Function: nc_tensor_set_dropout @ 0x66A19830
// ======================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall nc_tensor_set_dropout(__int64 a1, double _XMM1_8)
{
  __int64 v3; // rdi
  int v6; // r8d
  __int64 v7; // rbp
  int v8; // esi
  __int64 v9; // rax
  __int64 result; // rax
  __int64 *v11; // rbx
  __int64 v12; // rax
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v17[4]; // [rsp+30h] [rbp-78h] BYREF

  __asm { vmovaps [rsp+0A8h+var_58], xmm6 }
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  __asm { vmovaps xmm6, xmm1 }
  if ( *(_DWORD *)(a1 + 48) > 1u )
    sub_66A33D40("y->item_type == NC_TYPE_F32 || y->item_type == NC_TYPE_BF16", "libnc.c", 5228);
  v6 = *(_DWORD *)(a1 + 80);
  if ( v6 <= 0 )
  {
    v7 = 1i64;
    v8 = 0;
    result = 0i64;
    v17[0] = 0i64;
    goto LABEL_17;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v7 = 1i64;
    v8 = 0;
    goto LABEL_13;
  }
  v7 = *(_QWORD *)(a1 + 120);
  if ( v6 == 1 )
  {
    v8 = 1;
    goto LABEL_12;
  }
  if ( !*(_BYTE *)(a1 + 74) )
  {
    v8 = 1;
LABEL_40:
    v17[0] = 0i64;
    v7 = (int)v7;
LABEL_14:
    v9 = 1i64;
    do
      v17[v9++] = 0i64;
    while ( v6 > (int)v9 );
    result = v17[0];
    goto LABEL_17;
  }
  v7 *= *(_QWORD *)(a1 + 128);
  if ( v6 == 2 )
  {
    v8 = 2;
    goto LABEL_12;
  }
  if ( !*(_BYTE *)(a1 + 75) )
  {
    v8 = 2;
    goto LABEL_40;
  }
  v7 *= *(_QWORD *)(a1 + 136);
  if ( v6 == 3 )
  {
    v8 = 3;
    goto LABEL_12;
  }
  if ( !*(_BYTE *)(a1 + 76) )
  {
    v8 = 3;
    goto LABEL_40;
  }
  v7 *= *(_QWORD *)(a1 + 144);
  v8 = 4;
LABEL_12:
  v7 = (int)v7;
LABEL_13:
  v17[0] = 0i64;
  if ( v6 > 1 )
    goto LABEL_14;
  result = 0i64;
LABEL_17:
  v11 = &v17[v8];
  while ( result != -1 )
  {
    if ( v6 <= 0 )
      goto LABEL_24;
    v12 = *(_QWORD *)(a1 + 88) * result;
    if ( v6 != 1 )
    {
      v12 += *(_QWORD *)(a1 + 96) * v17[1];
      if ( v6 != 2 )
      {
        v12 += *(_QWORD *)(a1 + 104) * v17[2];
        if ( v6 != 3 )
        {
          if ( v6 != 4 )
          {
LABEL_24:
            v12 = 0i64;
            goto LABEL_25;
          }
          v12 += *(_QWORD *)(a1 + 112) * v17[3];
        }
      }
    }
LABEL_25:
    __asm { vmovaps xmm3, xmm6 }
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 480))(v3, v12 + *(_QWORD *)(a1 + 56), v7);
    v6 = *(_DWORD *)(a1 + 80);
    if ( v6 <= v8 )
      break;
    v14 = *v11 + 1;
    *v11 = v14;
    if ( v14 == *(_QWORD *)(a1 + 8 * (v8 + 12i64) + 24) )
    {
      result = 0i64;
      do
      {
        v11[result] = 0i64;
        if ( result == v6 - 1 - v8 )
          goto LABEL_30;
        v15 = v11[result + 1] + 1;
        v11[++result] = v15;
      }
      while ( v15 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v8 + 1) + 8 * result + 112) );
    }
    result = v17[0];
  }
LABEL_30:
  __asm { vmovaps xmm6, [rsp+0A8h+var_58] }
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

