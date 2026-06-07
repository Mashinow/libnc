// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_lerp
// Included functions: 4

// ======================================================
// Function: nc_lerp @ 0x66A2C500
// ======================================================

_QWORD *__fastcall nc_lerp(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rax
  __int64 v4; // rdi
  int v8; // edx
  int v9; // r8d
  int v10; // r8d
  _QWORD *v11; // r13
  int v12; // edi
  __int64 v13; // rax
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 *v17; // rbx
  __int64 v18; // r11
  int v19; // ecx
  __int64 v20; // rdx
  __int64 v21; // r8
  __int64 v22; // r9
  int v23; // ecx
  int v24; // ecx
  __int64 v25; // rax
  __int64 v26; // rax
  int v27; // ecx
  __int64 v28; // rdx
  _QWORD *v29; // rax
  _QWORD *v30; // rbx
  _QWORD *v31; // rax
  __int64 v33; // rax
  __int64 v34; // rcx
  __int64 v35; // rax
  __int64 v36; // rcx
  int v37; // [rsp+34h] [rbp-A4h]
  __int64 v38; // [rsp+38h] [rbp-A0h]
  __int64 v39; // [rsp+40h] [rbp-98h]
  __int64 v40[4]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v41; // [rsp+70h] [rbp-68h] BYREF
  __int64 v42; // [rsp+78h] [rbp-60h]
  __int64 v43; // [rsp+80h] [rbp-58h]
  __int64 v44; // [rsp+88h] [rbp-50h]

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(_QWORD *)(v3 + 24);
  v38 = v4;
  if ( v4 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) || v4 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a1 + 48) || *(_DWORD *)(a2 + 48) || *(_DWORD *)(a3 + 48) )
    nc_error("unsupported type for %s\n", "nc_lerp");
  v8 = *(_DWORD *)(a2 + 80);
  v9 = *(_DWORD *)(a1 + 80);
  if ( v8 != v9 )
    goto LABEL_7;
  if ( v8 > 0 )
  {
    if ( *(_QWORD *)(a2 + 120) == *(_QWORD *)(a1 + 120) )
    {
      v33 = 1i64;
      while ( v9 > (int)v33 )
      {
        v34 = *(_QWORD *)(a2 + 8 * v33++ + 120);
        if ( v34 != *(_QWORD *)(a1 + 8 * v33 + 112) )
          goto LABEL_7;
      }
      v10 = *(_DWORD *)(a3 + 80);
      if ( v8 != v10 )
        goto LABEL_8;
LABEL_83:
      if ( *(_QWORD *)(a3 + 120) != *(_QWORD *)(a1 + 120) )
        goto LABEL_8;
      v35 = 1i64;
      while ( v8 > (int)v35 )
      {
        v36 = *(_QWORD *)(a3 + 8 * v35++ + 120);
        if ( v36 != *(_QWORD *)(a1 + 8 * v35 + 112) )
          goto LABEL_8;
      }
LABEL_87:
      v3 = *(_QWORD *)(a1 + 40);
      goto LABEL_9;
    }
LABEL_7:
    sub_66A33D40("same_dims(b, a)", "libnc.c", 7563);
    v8 = *(_DWORD *)(a1 + 80);
    v10 = *(_DWORD *)(a3 + 80);
    if ( v10 != v8 )
    {
LABEL_8:
      sub_66A33D40("same_dims(t, a)", "libnc.c", 7564);
      v10 = *(_DWORD *)(a1 + 80);
      v3 = *(_QWORD *)(a1 + 40);
      goto LABEL_9;
    }
    if ( v10 <= 0 )
      goto LABEL_87;
    goto LABEL_83;
  }
  v10 = *(_DWORD *)(a3 + 80);
  if ( v8 != v10 )
    goto LABEL_8;
LABEL_9:
  v11 = nc_new_tensor_nz(*(_QWORD *)(v3 + 24), *(_DWORD *)(a1 + 48), v10, a1 + 120);
  v12 = *((_DWORD *)v11 + 20);
  v37 = v12;
  if ( v12 > 0 && *((_BYTE *)v11 + 73) && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) && *(_BYTE *)(a3 + 73) )
  {
    v13 = v11[15];
    if ( v12 != 1 )
    {
      if ( *((_BYTE *)v11 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *(_BYTE *)(a3 + 74) )
      {
        v13 *= v11[16];
        if ( v12 != 2 )
        {
          if ( *((_BYTE *)v11 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *(_BYTE *)(a3 + 75) )
          {
            v13 *= v11[17];
            if ( v12 != 3 )
            {
              if ( *((_BYTE *)v11 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
              {
                v13 *= v11[18];
                v37 = 4;
              }
              else
              {
                v37 = 3;
              }
            }
          }
          else
          {
            v37 = 2;
          }
        }
      }
      else
      {
        v37 = 1;
      }
    }
    v39 = (int)v13;
  }
  else
  {
    v39 = 1i64;
    v37 = 0;
  }
  v41 = 0i64;
  v14 = *(_DWORD *)(a1 + 80);
  if ( v14 <= 1 )
  {
    v16 = 0i64;
  }
  else
  {
    v15 = 1i64;
    do
      *(&v41 + v15++) = 0i64;
    while ( v14 > (int)v15 );
    v16 = v41;
  }
  v17 = &v41 + v37;
  while ( v16 != -1 )
  {
    v18 = *(_QWORD *)(a3 + 56);
    v19 = *(_DWORD *)(a3 + 80);
    if ( v19 <= 0 )
    {
      v20 = 0i64;
    }
    else
    {
      v20 = *(_QWORD *)(a3 + 88) * v16;
      if ( v19 != 1 )
      {
        v20 += *(_QWORD *)(a3 + 96) * v42;
        if ( v19 != 2 )
        {
          v20 += *(_QWORD *)(a3 + 104) * v43;
          if ( v19 != 3 )
          {
            v21 = v44;
            v22 = *(_QWORD *)(a3 + 112);
            goto LABEL_42;
          }
        }
      }
    }
    while ( 1 )
    {
      v18 += v20;
      v20 = *(unsigned int *)(a2 + 80);
      if ( (int)v20 <= 0 )
      {
        v22 = 0i64;
      }
      else
      {
        v22 = *(_QWORD *)(a2 + 88) * v16;
        if ( (_DWORD)v20 != 1 )
        {
          v22 += *(_QWORD *)(a2 + 96) * v42;
          if ( (_DWORD)v20 != 2 )
          {
            v22 += *(_QWORD *)(a2 + 104) * v43;
            if ( (_DWORD)v20 != 3 )
            {
              v21 = v44;
              if ( (_DWORD)v20 != 4 )
                goto LABEL_42;
              v22 += *(_QWORD *)(a2 + 112) * v44;
            }
          }
        }
      }
      v20 = *(unsigned int *)(a1 + 80);
      v22 += *(_QWORD *)(a2 + 56);
      if ( (int)v20 <= 0 )
      {
        v21 = 0i64;
      }
      else
      {
        v21 = *(_QWORD *)(a1 + 88) * v16;
        if ( (_DWORD)v20 != 1 )
        {
          v21 += *(_QWORD *)(a1 + 96) * v42;
          if ( (_DWORD)v20 != 2 )
          {
            v21 += *(_QWORD *)(a1 + 104) * v43;
            if ( (_DWORD)v20 != 3 )
            {
              if ( (_DWORD)v20 != 4 )
                goto LABEL_42;
              v21 += *(_QWORD *)(a1 + 112) * v44;
            }
          }
        }
      }
      v21 += *(_QWORD *)(a1 + 56);
      v23 = *((_DWORD *)v11 + 20);
      v20 = v11[7];
      if ( v23 <= 0 )
        break;
      v16 *= v11[11];
      if ( v23 == 1 )
        goto LABEL_61;
      v16 += v11[12] * v42;
      if ( v23 == 2 )
        goto LABEL_61;
      v16 += v11[13] * v43;
      if ( v23 == 3 )
        goto LABEL_61;
      if ( v23 == 4 )
      {
        v16 += v11[14] * v44;
        goto LABEL_61;
      }
LABEL_42:
      v20 += v22 * v21;
    }
    v16 = 0i64;
LABEL_61:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v38 + 304))(
      v38,
      v16 + v20,
      v21,
      v22,
      v18,
      v39);
    v24 = *(_DWORD *)(a1 + 80);
    if ( v37 >= v24 )
    {
LABEL_66:
      v41 = -1i64;
      break;
    }
    v25 = *v17 + 1;
    *v17 = v25;
    if ( *(_QWORD *)(a1 + 8 * (v37 + 12i64) + 24) == v25 )
    {
      v26 = 0i64;
      v27 = v24 - 1 - v37;
      do
      {
        v17[v26] = 0i64;
        if ( v26 == v27 )
          goto LABEL_66;
        v28 = v17[v26 + 1] + 1;
        v17[++v26] = v28;
      }
      while ( v28 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v37 + 1) + 8 * v26 + 112) );
    }
    v16 = v41;
  }
  v40[0] = a1;
  v40[1] = a2;
  v40[2] = a3;
  v29 = sub_66A15DA0(26, v11 + 3, (__int64 **)v11 + 4, 3, (__int64)v40);
  v30 = v29;
  if ( v29 )
  {
    *((_DWORD *)v29 + 10) = 3;
    v31 = aligned_malloc(0x18ui64, 0x40ui64);
    v30[6] = v31;
    ++*(_DWORD *)(a1 + 16);
    *v31 = a1;
    ++*(_DWORD *)(a2 + 16);
    v31[1] = a2;
    ++*(_DWORD *)(a3 + 16);
    v31[2] = a3;
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)a3);
  return v11;
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

