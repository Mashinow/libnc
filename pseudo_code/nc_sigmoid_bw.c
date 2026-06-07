// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sigmoid_bw
// Included functions: 4

// ======================================================
// Function: nc_sigmoid_bw @ 0x66A284A0
// ======================================================

_QWORD *__fastcall nc_sigmoid_bw(__int64 a1, __int64 a2)
{
  __int64 v2; // rdi
  unsigned int v5; // edx
  int v6; // r13d
  _QWORD *v7; // rbp
  __int64 v8; // rcx
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 *v13; // rbx
  int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // r14
  int v19; // edx
  int v20; // ecx
  __int64 v21; // rax
  __int64 v22; // rax
  int v23; // ecx
  __int64 v24; // rdx
  __int64 v26; // rax
  __int64 v27; // rcx
  __int64 v28; // [rsp+40h] [rbp-88h]
  __int64 v29[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v30; // [rsp+60h] [rbp-68h] BYREF
  __int64 v31; // [rsp+68h] [rbp-60h]
  __int64 v32; // [rsp+70h] [rbp-58h]
  __int64 v33; // [rsp+78h] [rbp-50h]

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v5 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a2 + 48) != v5 || v5 > 1 )
    nc_error("unsupported type for %s\n", "nc_sigmoid_bw");
  v6 = *(_DWORD *)(a1 + 80);
  if ( v6 != *(_DWORD *)(a2 + 80) )
    goto LABEL_5;
  if ( v6 <= 0 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
    if ( *(_DWORD *)(a1 + 16) == 1 )
    {
      v7 = (_QWORD *)a1;
      v6 = 0;
      v12 = 0i64;
      v30 = 0i64;
      v28 = 1i64;
      goto LABEL_30;
    }
    goto LABEL_7;
  }
  if ( *(_QWORD *)(a1 + 120) != *(_QWORD *)(a2 + 120) )
  {
LABEL_5:
    v7 = (_QWORD *)a1;
    sub_66A33D40("same_dims(yg1, yd1)", "libnc.c", 7054);
    if ( *(_DWORD *)(a1 + 16) == 1 )
      goto LABEL_8;
    v6 = *(_DWORD *)(a1 + 80);
    v5 = *(_DWORD *)(a1 + 48);
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
LABEL_7:
    v7 = nc_new_tensor_nz(v8, v5, v6, a1 + 120);
LABEL_8:
    v6 = *((_DWORD *)v7 + 20);
    v9 = *(_DWORD *)(a1 + 80);
    if ( v6 <= 0 )
      goto LABEL_70;
    goto LABEL_9;
  }
  v26 = 1i64;
  while ( v6 > (int)v26 )
  {
    v27 = *(_QWORD *)(a1 + 8 * v26++ + 120);
    if ( v27 != *(_QWORD *)(a2 + 8 * v26 + 112) )
      goto LABEL_5;
  }
  v9 = v6;
  v7 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
  {
    v8 = v2;
    goto LABEL_7;
  }
LABEL_9:
  if ( *((_BYTE *)v7 + 73) && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
  {
    v10 = v7[15];
    if ( v6 != 1 )
    {
      if ( *((_BYTE *)v7 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
      {
        v10 *= v7[16];
        if ( v6 != 2 )
        {
          if ( *((_BYTE *)v7 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
          {
            v10 *= v7[17];
            if ( v6 != 3 )
            {
              if ( *((_BYTE *)v7 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
              {
                v10 *= v7[18];
                v6 = 4;
              }
              else
              {
                v6 = 3;
              }
            }
          }
          else
          {
            v6 = 2;
          }
        }
      }
      else
      {
        v6 = 1;
      }
    }
    v28 = (int)v10;
    goto LABEL_26;
  }
LABEL_70:
  v28 = 1i64;
  v6 = 0;
LABEL_26:
  v30 = 0i64;
  if ( v9 <= 1 )
  {
    v12 = 0i64;
  }
  else
  {
    v11 = 1i64;
    do
      *(&v30 + v11++) = 0i64;
    while ( v9 > (int)v11 );
    v12 = v30;
  }
LABEL_30:
  v13 = &v30 + v6;
  while ( 2 )
  {
    if ( v12 == -1 )
      goto LABEL_56;
    v14 = *(_DWORD *)(a2 + 80);
    v15 = *(_QWORD *)(a2 + 56);
    if ( v14 > 0 )
    {
      v16 = *(_QWORD *)(a2 + 88) * v12;
      if ( v14 != 1 )
      {
        v16 += *(_QWORD *)(a2 + 96) * v31;
        if ( v14 != 2 )
        {
          v16 += *(_QWORD *)(a2 + 104) * v32;
          if ( v14 != 3 )
          {
            v17 = v33;
            v18 = *(_QWORD *)(a2 + 112);
            goto LABEL_37;
          }
        }
      }
      goto LABEL_38;
    }
    v19 = *(_DWORD *)(a1 + 80);
    v16 = *(_QWORD *)(a2 + 56);
    v15 = *(_QWORD *)(a1 + 56);
    if ( v19 <= 0 )
    {
LABEL_62:
      v17 = 0i64;
      goto LABEL_44;
    }
    while ( 1 )
    {
      v17 = *(_QWORD *)(a1 + 88) * v12;
      if ( v19 != 1 )
      {
        v17 += *(_QWORD *)(a1 + 96) * v31;
        if ( v19 != 2 )
        {
          v17 += *(_QWORD *)(a1 + 104) * v32;
          if ( v19 != 3 )
          {
            v18 = v33;
            if ( v19 != 4 )
              goto LABEL_37;
            v17 += *(_QWORD *)(a1 + 112) * v33;
          }
        }
      }
LABEL_44:
      v17 += v15;
      v15 = *((unsigned int *)v7 + 20);
      if ( (int)v15 <= 0 )
        break;
      v12 *= v7[11];
      if ( (_DWORD)v15 == 1 )
        goto LABEL_50;
      v12 += v7[12] * v31;
      if ( (_DWORD)v15 == 2 )
        goto LABEL_50;
      v12 += v7[13] * v32;
      if ( (_DWORD)v15 == 3 )
        goto LABEL_50;
      v18 = v33;
      if ( (_DWORD)v15 == 4 )
      {
        v12 += v7[14] * v33;
        goto LABEL_50;
      }
LABEL_37:
      v16 += v18 * v17;
LABEL_38:
      v19 = *(_DWORD *)(a1 + 80);
      v16 += v15;
      v15 = *(_QWORD *)(a1 + 56);
      if ( v19 <= 0 )
        goto LABEL_62;
    }
    v12 = 0i64;
LABEL_50:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _DWORD))(v2 + 216))(
      v2,
      v12 + v7[7],
      v17,
      v16,
      v28,
      *(_DWORD *)(a1 + 48));
    v20 = *(_DWORD *)(a1 + 80);
    if ( v20 <= v6 )
      goto LABEL_55;
    v21 = *v13 + 1;
    *v13 = v21;
    if ( *(_QWORD *)(a1 + 8 * (v6 + 12i64) + 24) != v21 )
    {
LABEL_59:
      v12 = v30;
      continue;
    }
    break;
  }
  v22 = 0i64;
  v23 = v20 - 1 - v6;
  while ( 1 )
  {
    v13[v22] = 0i64;
    if ( v23 == v22 )
      break;
    v24 = v13[v22 + 1] + 1;
    v13[++v22] = v24;
    if ( v24 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v6 + 1) + 8 * v22 + 112) )
      goto LABEL_59;
  }
LABEL_55:
  v30 = -1i64;
LABEL_56:
  v29[0] = a1;
  v29[1] = a2;
  sub_66A15DA0(0, v7 + 3, (__int64 **)v7 + 4, 2, (__int64)v29);
  if ( (_QWORD *)a1 != v7 )
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

