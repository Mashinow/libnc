// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_relu_bw
// Included functions: 4

// ======================================================
// Function: nc_relu_bw @ 0x66A29630
// ======================================================

_QWORD *__fastcall nc_relu_bw(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  unsigned int v5; // edx
  int v6; // r8d
  __int64 v7; // rcx
  _QWORD *v8; // rax
  __int64 v9; // rdx
  _QWORD *v10; // r13
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 *v14; // rbx
  int v15; // ecx
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // r14
  __int64 v19; // r15
  __int64 v20; // rcx
  int v21; // ecx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v26; // rax
  __int64 v27; // rcx
  int v28; // [rsp+3Ch] [rbp-8Ch]
  __int64 v29; // [rsp+40h] [rbp-88h]
  __int64 v30[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v31; // [rsp+60h] [rbp-68h] BYREF
  __int64 v32; // [rsp+68h] [rbp-60h]
  __int64 v33; // [rsp+70h] [rbp-58h]
  __int64 v34; // [rsp+78h] [rbp-50h]

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v5 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a2 + 48) != v5 || v5 > 1 )
    nc_error("unsupported type for %s\n", "nc_relu_bw");
  v6 = *(_DWORD *)(a1 + 80);
  if ( v6 != *(_DWORD *)(a2 + 80) )
    goto LABEL_5;
  if ( v6 > 0 )
  {
    if ( *(_QWORD *)(a1 + 120) != *(_QWORD *)(a2 + 120) )
    {
LABEL_5:
      sub_66A33D40("same_dims(yg1, xd1)", "libnc.c", 7189);
      v6 = *(_DWORD *)(a1 + 80);
      v5 = *(_DWORD *)(a1 + 48);
      v7 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
      goto LABEL_6;
    }
    v26 = 1i64;
    while ( v6 > (int)v26 )
    {
      v27 = *(_QWORD *)(a1 + 8 * v26++ + 120);
      if ( v27 != *(_QWORD *)(a2 + 8 * v26 + 112) )
        goto LABEL_5;
    }
  }
  v7 = v2;
LABEL_6:
  v8 = nc_new_tensor_nz(v7, v5, v6, a1 + 120);
  LODWORD(v9) = *(_DWORD *)(a1 + 80);
  v10 = v8;
  if ( (int)v9 <= 0 )
  {
    v31 = 0i64;
    v13 = 0i64;
    v29 = 1i64;
    v28 = 0;
    goto LABEL_28;
  }
  if ( !*(_BYTE *)(a1 + 73) || !*((_BYTE *)v8 + 73) || !*(_BYTE *)(a2 + 73) )
  {
    v29 = 1i64;
    v28 = 0;
LABEL_24:
    v31 = 0i64;
    if ( (int)v9 <= 1 )
    {
      v13 = 0i64;
      goto LABEL_28;
    }
    goto LABEL_25;
  }
  v11 = *(_QWORD *)(a1 + 120);
  if ( (_DWORD)v9 == 1 )
  {
    v28 = 1;
    goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 74) && *((_BYTE *)v10 + 74) && *(_BYTE *)(a2 + 74) )
  {
    v11 *= *(_QWORD *)(a1 + 128);
    if ( (_DWORD)v9 == 2 )
    {
      v28 = 2;
      goto LABEL_23;
    }
    if ( *(_BYTE *)(a1 + 75) && *((_BYTE *)v10 + 75) && *(_BYTE *)(a2 + 75) )
    {
      v11 *= *(_QWORD *)(a1 + 136);
      if ( (_DWORD)v9 == 3 )
      {
        v28 = 3;
        goto LABEL_23;
      }
      if ( *(_BYTE *)(a1 + 76) && *((_BYTE *)v10 + 76) && *(_BYTE *)(a2 + 76) )
      {
        v11 *= *(_QWORD *)(a1 + 144);
        v28 = 4;
LABEL_23:
        v29 = (int)v11;
        goto LABEL_24;
      }
      v28 = 3;
    }
    else
    {
      v28 = 2;
    }
  }
  else
  {
    v28 = 1;
  }
  v31 = 0i64;
  v29 = (int)v11;
LABEL_25:
  v12 = 1i64;
  do
    *(&v31 + v12++) = 0i64;
  while ( (int)v9 > (int)v12 );
  v13 = v31;
LABEL_28:
  v14 = &v31 + v28;
  while ( 2 )
  {
    if ( v13 == -1 )
      goto LABEL_53;
    v15 = *(_DWORD *)(a2 + 80);
    v16 = *(_QWORD *)(a2 + 56);
    if ( v15 > 0 )
    {
      v17 = *(_QWORD *)(a2 + 88) * v13;
      if ( v15 != 1 )
      {
        v17 += *(_QWORD *)(a2 + 96) * v32;
        if ( v15 != 2 )
        {
          v17 += *(_QWORD *)(a2 + 104) * v33;
          if ( v15 != 3 )
          {
            v18 = v34;
            v19 = *(_QWORD *)(a2 + 112);
            goto LABEL_35;
          }
        }
      }
      goto LABEL_36;
    }
    v20 = *(_QWORD *)(a1 + 56);
    v17 = *(_QWORD *)(a2 + 56);
    if ( (int)v9 <= 0 )
    {
LABEL_57:
      v16 = 0i64;
      goto LABEL_42;
    }
    while ( 1 )
    {
      v16 = *(_QWORD *)(a1 + 88) * v13;
      if ( (_DWORD)v9 != 1 )
      {
        v16 += *(_QWORD *)(a1 + 96) * v32;
        if ( (_DWORD)v9 != 2 )
        {
          v16 += *(_QWORD *)(a1 + 104) * v33;
          if ( (_DWORD)v9 != 3 )
          {
            v18 = v34;
            v19 = *(_QWORD *)(a1 + 112);
            if ( (_DWORD)v9 != 4 )
              goto LABEL_35;
            v16 += v19 * v34;
          }
        }
      }
LABEL_42:
      v16 += v20;
      v21 = *((_DWORD *)v10 + 20);
      v9 = v10[7];
      if ( v21 <= 0 )
        break;
      v13 *= v10[11];
      if ( v21 == 1 )
        goto LABEL_48;
      v13 += v10[12] * v32;
      if ( v21 == 2 )
        goto LABEL_48;
      v13 += v10[13] * v33;
      if ( v21 == 3 )
        goto LABEL_48;
      v18 = v34;
      v19 = v10[14];
      if ( v21 == 4 )
      {
        v13 += v19 * v34;
        goto LABEL_48;
      }
LABEL_35:
      v17 += v19 * v18;
LABEL_36:
      v17 += v16;
      v20 = *(_QWORD *)(a1 + 56);
      if ( (int)v9 <= 0 )
        goto LABEL_57;
    }
    v13 = 0i64;
LABEL_48:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _DWORD))(v2 + 248))(
      v2,
      v13 + v9,
      v16,
      v17,
      v29,
      *(_DWORD *)(a1 + 48));
    LODWORD(v9) = *(_DWORD *)(a1 + 80);
    if ( (int)v9 <= v28 )
      goto LABEL_53;
    v22 = *v14 + 1;
    *v14 = v22;
    if ( *(_QWORD *)(a1 + 8 * (v28 + 12i64) + 24) != v22 )
    {
LABEL_54:
      v13 = v31;
      continue;
    }
    break;
  }
  v23 = 0i64;
  while ( 1 )
  {
    v14[v23] = 0i64;
    if ( v23 == (_DWORD)v9 - 1 - v28 )
      break;
    v24 = v14[v23 + 1] + 1;
    v14[++v23] = v24;
    if ( v24 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v28 + 1) + 8 * v23 + 112) )
      goto LABEL_54;
  }
LABEL_53:
  v30[0] = a1;
  v30[1] = a2;
  sub_66A15DA0(0, v10 + 3, (__int64 **)v10 + 4, 2, (__int64)v30);
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v10;
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

// ======================================================
// Function: sub_66A15DA0 @ 0x66A15DA0
// ======================================================

_QWORD *__fastcall sub_66A15DA0(int a1, __int64 *a2, __int64 **a3, int a4, __int64 a5)
{
  _QWORD *result; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  void *v11; // r15
  __int64 v12; // rax
  __int64 v13; // r13
  _QWORD *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rax
  size_t v20; // r12
  void *v21; // rax

  if ( a4 <= 0 )
  {
    if ( !a4 )
      return 0i64;
    v20 = 8i64 * a4;
    v21 = aligned_malloc(v20, 0x40ui64);
    v13 = *a2;
    v11 = v21;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v14[4] = aligned_malloc(v20, 0x40ui64);
LABEL_13:
      v18 = *(_QWORD *)(v13 + 72);
      *(_QWORD *)(v13 + 72) = v18 + 1;
      v14[12] = v18;
      v19 = *(_QWORD *)(v13 + 32);
      *(_QWORD *)(v19 + 8) = v14;
      *v14 = v19;
      v14[1] = v13 + 32;
      *(_QWORD *)(v13 + 32) = v14;
      _aligned_free(v11);
      if ( *a3 )
        nc_free_node(*a3);
      *a3 = v14;
      return v14;
    }
LABEL_22:
    MEMORY[0x10] = 0;
    BUG();
  }
  result = *(_QWORD **)(*(_QWORD *)a5 + 32i64);
  if ( result )
    goto LABEL_7;
  v9 = 1i64;
  while ( (int)v9 < a4 )
  {
    v10 = *(_QWORD *)(a5 + 8 * v9++);
    if ( *(_QWORD *)(v10 + 32) )
      goto LABEL_7;
  }
  if ( (_DWORD)v9 != a4 )
  {
LABEL_7:
    v11 = aligned_malloc(8i64 * a4, 0x40ui64);
    v12 = 0i64;
    do
    {
      *((_QWORD *)v11 + v12) = *(_QWORD *)(*(_QWORD *)(a5 + 8 * v12) + 32i64);
      ++v12;
    }
    while ( a4 > (int)v12 );
    v13 = *a2;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v15 = aligned_malloc(8i64 * a4, 0x40ui64);
      v16 = 0i64;
      v14[4] = v15;
      do
      {
        while ( 1 )
        {
          v17 = *((_QWORD *)v11 + v16);
          if ( !v17 )
            break;
          ++*(_DWORD *)(v17 + 16);
          v15[v16++] = v17;
          if ( a4 <= (int)v16 )
            goto LABEL_13;
        }
        v15[v16++] = 0i64;
      }
      while ( a4 > (int)v16 );
      goto LABEL_13;
    }
    goto LABEL_22;
  }
  return result;
}

