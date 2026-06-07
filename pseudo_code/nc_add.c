// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_add
// Included functions: 6

// ======================================================
// Function: nc_add @ 0x66A1EBC0
// ======================================================

__int64 __fastcall nc_add(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rbp
  unsigned int v6; // edx
  _QWORD *v7; // rax
  __int64 v8; // rbx
  int v10; // r12d
  int v11; // edx
  __int64 v12; // rax
  __int64 v13; // rax
  unsigned __int64 v14; // r8
  int v15; // edx
  __int64 v16; // rcx
  __int64 v17; // r9
  __int64 v18; // r8
  __int64 v19; // r10
  unsigned __int64 v20; // r15
  int v21; // eax
  int v22; // r8d
  __int64 *v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // r9
  __int64 v26; // r8
  __int64 v27; // rax
  __int64 v28; // rdx
  __int64 v29; // [rsp+28h] [rbp-D0h]
  __int64 v30; // [rsp+30h] [rbp-C8h]
  __int64 v31; // [rsp+38h] [rbp-C0h]
  __int64 v32; // [rsp+40h] [rbp-B8h]
  __int64 v33; // [rsp+48h] [rbp-B0h]
  __int64 v34; // [rsp+50h] [rbp-A8h]
  __int64 v35; // [rsp+58h] [rbp-A0h]
  unsigned __int64 v36; // [rsp+58h] [rbp-A0h]
  __int64 v37; // [rsp+60h] [rbp-98h]
  __int64 v38; // [rsp+60h] [rbp-98h]
  __int64 v39; // [rsp+68h] [rbp-90h]
  __int64 v40; // [rsp+70h] [rbp-88h]
  __int64 v41; // [rsp+78h] [rbp-80h] BYREF
  __int64 v42; // [rsp+80h] [rbp-78h] BYREF
  __int64 v43; // [rsp+88h] [rbp-70h]
  __int64 v44; // [rsp+90h] [rbp-68h] BYREF
  __int64 v45; // [rsp+98h] [rbp-60h]
  __int64 v46; // [rsp+A0h] [rbp-58h]
  __int64 v47; // [rsp+A8h] [rbp-50h]

  v2 = *(_QWORD *)(a1 + 40);
  v3 = *(_QWORD *)(v2 + 24);
  v6 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a2 + 48) != v6 || v6 > 1 )
    nc_error("unsupported type for %s\n", "nc_add");
  v7 = nc_new_tensor_nz(*(_QWORD *)(v2 + 24), v6, *(_DWORD *)(a1 + 80), a1 + 120);
  v8 = (__int64)v7;
  if ( *(_DWORD *)(a2 + 80) == 1 && *(int *)(a1 + 80) > 1 )
  {
    if ( v3 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
      nc_error("all operation tensors must be on the same device");
    if ( *(_QWORD *)(a1 + 120) != *(_QWORD *)(a2 + 120) )
      sub_66A33D40("x1->dims[0] == x2->dims[0]", "libnc.c", 5831);
    if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
      sub_66A33D40("x1->contig[0] && x2->contig[0]", "libnc.c", 5832);
    v38 = (int)sub_66A05420(
                 (_DWORD *)&v41 + 1,
                 1,
                 v8,
                 a1,
                 0i64,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v37,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45);
    v10 = dword_66A375E0[*(unsigned int *)(a1 + 48)];
    v11 = *(_DWORD *)(v8 + 80);
    v44 = 0i64;
    if ( v11 <= 1 )
    {
      v13 = 0i64;
    }
    else
    {
      v12 = 1i64;
      do
        *(&v44 + v12++) = 0i64;
      while ( v11 > (int)v12 );
      v13 = v44;
    }
    while ( v13 != -1 )
    {
      v14 = *(_QWORD *)(a1 + 96);
      v15 = *(_DWORD *)(a1 + 80);
      v36 = v14 >> v10;
      v16 = *(_QWORD *)(a1 + 56);
      if ( v15 <= 0 )
      {
        v17 = 0i64;
      }
      else
      {
        v17 = *(_QWORD *)(a1 + 88) * v13;
        if ( v15 != 1 )
        {
          v17 += v45 * v14;
          if ( v15 != 2 )
          {
            v17 += *(_QWORD *)(a1 + 104) * v46;
            if ( v15 != 3 )
            {
              v18 = v47;
              v19 = *(_QWORD *)(a1 + 112);
              goto LABEL_24;
            }
          }
        }
      }
      while ( 1 )
      {
        v17 += v16;
        v20 = *(_QWORD *)(v8 + 96);
        v16 = *(unsigned int *)(v8 + 80);
        v19 = *(_QWORD *)(v8 + 56);
        v18 = v20 >> v10;
        if ( (int)v16 <= 0 )
          break;
        v13 *= *(_QWORD *)(v8 + 88);
        if ( (_DWORD)v16 == 1 )
          goto LABEL_31;
        v13 += v45 * v20;
        if ( (_DWORD)v16 == 2 )
          goto LABEL_31;
        v13 += *(_QWORD *)(v8 + 104) * v46;
        if ( (_DWORD)v16 == 3 )
          goto LABEL_31;
        if ( (_DWORD)v16 == 4 )
        {
          v13 += *(_QWORD *)(v8 + 112) * v47;
          goto LABEL_31;
        }
LABEL_24:
        v17 += v19 * v18;
      }
      v13 = 0i64;
LABEL_31:
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, __int64, _DWORD))(v3 + 168))(
        v3,
        v19 + v13,
        v18,
        v17,
        v36,
        *(_QWORD *)(a2 + 56),
        0i64,
        *(_QWORD *)(v8 + 120),
        v38,
        *(_DWORD *)(a1 + 48));
      v21 = HIDWORD(v41);
      v22 = *(_DWORD *)(v8 + 80);
      if ( SHIDWORD(v41) >= v22 )
        goto LABEL_36;
      v23 = &v44 + SHIDWORD(v41);
      v24 = *v23 + 1;
      *v23 = v24;
      if ( *(_QWORD *)(v8 + 8i64 * v21 + 120) == v24 )
      {
        v25 = v8 + 8i64 * (v21 + 1);
        v26 = (unsigned int)(~v21 + v22);
        v27 = 0i64;
        while ( 1 )
        {
          v23[v27] = 0i64;
          if ( v26 == v27 )
            break;
          v28 = v23[v27 + 1] + 1;
          v23[++v27] = v28;
          if ( v28 != *(_QWORD *)(v25 + 8 * v27 + 112) )
            goto LABEL_39;
        }
LABEL_36:
        v44 = -1i64;
        break;
      }
LABEL_39:
      v13 = v44;
    }
    v42 = a1;
    v43 = a2;
    sub_66A15DA0(7, (__int64 *)(v8 + 24), (__int64 **)(v8 + 32), 2, (__int64)&v42);
  }
  else
  {
    sub_66A127A0((__int64)v7, a1, a2);
    v44 = a1;
    v45 = a2;
    sub_66A15DA0(6, (__int64 *)(v8 + 24), (__int64 **)(v8 + 32), 2, (__int64)&v44);
  }
  if ( a1 != v8 )
    nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v8;
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
// Function: sub_66A05420 @ 0x66A05420
// ======================================================

__int64 __fastcall sub_66A05420(
        _DWORD *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20)
{
  int v20; // eax
  __int64 v21; // r9
  __int64 result; // rax
  int v23; // r10d
  unsigned __int64 v24; // [rsp+58h] [rbp-F0h]
  int v25; // [rsp+6Ch] [rbp-DCh]
  __int64 v26; // [rsp+80h] [rbp-C8h]
  __int64 v27; // [rsp+88h] [rbp-C0h]
  __int64 v28; // [rsp+90h] [rbp-B8h]
  __int64 v29; // [rsp+98h] [rbp-B0h]
  __int64 v30; // [rsp+A0h] [rbp-A8h]
  __int64 v31; // [rsp+A8h] [rbp-A0h]
  __int64 v32; // [rsp+B0h] [rbp-98h]
  __int64 v33; // [rsp+B8h] [rbp-90h]
  __int64 v34; // [rsp+C0h] [rbp-88h]
  __int64 v35; // [rsp+C8h] [rbp-80h]
  __int64 v36; // [rsp+D0h] [rbp-78h]
  __int64 v37; // [rsp+D8h] [rbp-70h]
  __int64 v38; // [rsp+E0h] [rbp-68h]
  __int64 v39; // [rsp+E8h] [rbp-60h]
  __int64 v40; // [rsp+F0h] [rbp-58h]
  __int64 v41; // [rsp+F8h] [rbp-50h]

  if ( a4 )
  {
    v26 = a4;
    if ( !a5 )
    {
      v25 = 1;
      goto LABEL_20;
    }
    v27 = a5;
    if ( !a6 )
    {
      v25 = 2;
      goto LABEL_20;
    }
    v28 = a6;
    if ( !a7 )
    {
      v25 = 3;
      goto LABEL_20;
    }
    v29 = a7;
    if ( !a8 )
    {
      v25 = 4;
      goto LABEL_20;
    }
    v30 = a8;
    if ( !a9 )
    {
      v25 = 5;
      goto LABEL_20;
    }
    v31 = a9;
    if ( !a10 )
    {
      v25 = 6;
      goto LABEL_20;
    }
    v32 = a10;
    if ( !a11 )
    {
      v25 = 7;
      goto LABEL_20;
    }
    v33 = a11;
    if ( !a12 )
    {
      v25 = 8;
      goto LABEL_20;
    }
    v34 = a12;
    if ( !a13 )
    {
      v25 = 9;
      goto LABEL_20;
    }
    v35 = a13;
    if ( !a14 )
    {
      v25 = 10;
      goto LABEL_20;
    }
    v36 = a14;
    if ( !a15 )
    {
      v25 = 11;
      goto LABEL_20;
    }
    v37 = a15;
    if ( !a16 )
    {
      v25 = 12;
      goto LABEL_20;
    }
    v38 = a16;
    if ( !a17 )
    {
      v25 = 13;
      goto LABEL_20;
    }
    v39 = a17;
    if ( !a18 )
    {
      v25 = 14;
      goto LABEL_20;
    }
    v40 = a18;
    if ( !a19 )
    {
      v25 = 15;
      goto LABEL_20;
    }
    v41 = a19;
    if ( !a20 )
    {
      v25 = 16;
      goto LABEL_20;
    }
    sub_66A33D40("count < countof(tab)", "libnc.c", 4653);
  }
  v25 = 0;
LABEL_20:
  v20 = *(_DWORD *)(a3 + 80);
  if ( a2 < v20 && (v21 = a2, *(_BYTE *)(a3 + a2 + 73)) )
  {
    v24 = a2 + (unsigned __int64)(unsigned int)(v20 - 1 - a2);
    result = 1i64;
    do
    {
      v23 = v21;
      if ( v25
        && (!*(_BYTE *)(v26 + v21 + 73)
         || v25 != 1
         && (!*(_BYTE *)(v27 + v21 + 73)
          || v25 != 2
          && (!*(_BYTE *)(v28 + v21 + 73)
           || v25 != 3
           && (!*(_BYTE *)(v29 + v21 + 73)
            || v25 != 4
            && (!*(_BYTE *)(v30 + v21 + 73)
             || v25 != 5
             && (!*(_BYTE *)(v31 + v21 + 73)
              || v25 != 6
              && (!*(_BYTE *)(v32 + v21 + 73)
               || v25 != 7
               && (!*(_BYTE *)(v33 + v21 + 73)
                || v25 != 8
                && (!*(_BYTE *)(v34 + v21 + 73)
                 || v25 != 9
                 && (!*(_BYTE *)(v35 + v21 + 73)
                  || v25 != 10
                  && (!*(_BYTE *)(v36 + v21 + 73)
                   || v25 != 11
                   && (!*(_BYTE *)(v37 + v21 + 73)
                    || v25 != 12
                    && (!*(_BYTE *)(v38 + v21 + 73)
                     || v25 != 13
                     && (!*(_BYTE *)(v39 + v21 + 73)
                      || v25 != 14 && (!*(_BYTE *)(v40 + v21 + 73) || v25 == 16 && !*(_BYTE *)(v41 + v21 + 73)))))))))))))))) )
      {
        break;
      }
      v23 = v21 + 1;
      result *= *(_QWORD *)(a3 + 8 * v21 + 120);
      if ( v21 == v24 )
        break;
      ++v21;
    }
    while ( *(_BYTE *)(a3 + 1 + v21 + 72) );
    a2 = v23;
  }
  else
  {
    result = 1i64;
  }
  *a1 = a2;
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

// ======================================================
// Function: sub_66A127A0 @ 0x66A127A0
// ======================================================

__int64 __fastcall sub_66A127A0(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // edx
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rbx
  int v13; // eax
  __int64 v14; // rbx
  int v15; // r9d
  __int64 v16; // rbx
  int v17; // r9d
  __int64 v18; // rbx
  __int64 v19; // r9
  int v20; // r15d
  __int64 v21; // rax
  __int64 v22; // r13
  __int64 *v23; // rbx
  __int64 v24; // r12
  __int64 result; // rax
  int v26; // edx
  __int64 v27; // rcx
  __int64 v28; // rax
  __int64 v29; // r8
  __int64 v30; // r9
  int v31; // ecx
  int v32; // ecx
  __int64 v33; // rdx
  __int64 v34; // r8
  __int64 v35; // rax
  __int64 v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rcx
  __int64 v39; // [rsp+50h] [rbp-A8h]
  int v40; // [rsp+58h] [rbp-A0h]
  __int64 v41; // [rsp+68h] [rbp-90h]
  __int64 v42; // [rsp+70h] [rbp-88h]
  __int64 v43; // [rsp+80h] [rbp-78h]
  __int64 v44; // [rsp+88h] [rbp-70h]
  __int64 v45; // [rsp+90h] [rbp-68h] BYREF
  __int64 v46; // [rsp+98h] [rbp-60h]
  __int64 v47; // [rsp+A0h] [rbp-58h]
  __int64 v48; // [rsp+A8h] [rbp-50h]

  v39 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v39 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) || v39 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v6 = *(_DWORD *)(a2 + 48);
  if ( *(_DWORD *)(a3 + 48) != v6 || v6 > 1 )
    nc_error("unsupported type for %s\n", "nc_add_internal");
  v7 = *(_DWORD *)(a1 + 80);
  if ( v7 != *(_DWORD *)(a3 + 80) )
    goto LABEL_6;
  if ( v7 <= 0 )
  {
    v8 = *(_DWORD *)(a2 + 80);
    if ( v7 == v8 )
      goto LABEL_112;
    goto LABEL_7;
  }
  v34 = *(_QWORD *)(a3 + 120);
  if ( v34 == *(_QWORD *)(a1 + 120) )
  {
    v35 = 1i64;
    while ( v7 > (int)v35 )
    {
      v36 = *(_QWORD *)(a1 + 8 * v35++ + 120);
      if ( v36 != *(_QWORD *)(a3 + 8 * v35 + 112) )
        goto LABEL_6;
    }
    v8 = *(_DWORD *)(a2 + 80);
    if ( v7 != v8 )
    {
LABEL_7:
      sub_66A33D40("same_dims(y, x1)", "libnc.c", 5785);
      v8 = *(_DWORD *)(a1 + 80);
      if ( v8 > 0 )
      {
        v42 = *(_QWORD *)(a1 + 120);
        goto LABEL_9;
      }
LABEL_112:
      v43 = 1i64;
      v10 = 0i64;
LABEL_26:
      if ( v8 == (_DWORD)v10 )
        return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _DWORD))(v39 + 168))(
                 v39,
                 *(_QWORD *)(a1 + 56),
                 0i64,
                 *(_QWORD *)(a2 + 56),
                 0i64,
                 *(_QWORD *)(a3 + 56),
                 0i64,
                 v43,
                 1i64,
                 *(_DWORD *)(a2 + 48));
      goto LABEL_27;
    }
  }
  else
  {
LABEL_6:
    sub_66A33D40("same_dims(y, x2)", "libnc.c", 5784);
    v8 = *(_DWORD *)(a2 + 80);
    if ( v8 != *(_DWORD *)(a1 + 80) )
      goto LABEL_7;
    if ( v8 <= 0 )
      goto LABEL_112;
    v34 = *(_QWORD *)(a1 + 120);
  }
  v42 = *(_QWORD *)(a2 + 120);
  if ( v42 != v34 )
    goto LABEL_7;
  v37 = 1i64;
  while ( v8 > (int)v37 )
  {
    v38 = *(_QWORD *)(a1 + 8 * v37++ + 120);
    if ( v38 != *(_QWORD *)(a2 + 8 * v37 + 112) )
      goto LABEL_7;
  }
  v8 = *(_DWORD *)(a1 + 80);
LABEL_9:
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) || !*(_BYTE *)(a3 + 73) )
  {
    v40 = 1;
    v10 = 0i64;
    v43 = 1i64;
    goto LABEL_28;
  }
  v9 = *(_QWORD *)(a1 + 120);
  if ( v8 <= 1 )
  {
    v10 = 1i64;
    goto LABEL_25;
  }
  if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *(_BYTE *)(a3 + 74) )
  {
    v9 *= *(_QWORD *)(a1 + 128);
    if ( v8 == 2 )
    {
      v10 = 2i64;
      goto LABEL_25;
    }
    if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *(_BYTE *)(a3 + 75) )
    {
      v9 *= *(_QWORD *)(a1 + 136);
      if ( v8 == 3 )
      {
        v10 = 3i64;
        goto LABEL_25;
      }
      if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
      {
        v9 *= *(_QWORD *)(a1 + 144);
        v10 = 4i64;
LABEL_25:
        v43 = (int)v9;
        goto LABEL_26;
      }
      v10 = 3i64;
    }
    else
    {
      v10 = 2i64;
    }
  }
  else
  {
    v10 = 1i64;
  }
  v43 = (int)v9;
LABEL_27:
  v40 = v10 + 1;
  v42 = *(_QWORD *)(a1 + 8i64 * (int)v10 + 120);
LABEL_28:
  v11 = v40;
  if ( v8 <= v40 )
    goto LABEL_49;
  v11 = v40;
  if ( !*(_BYTE *)(a1 + v40 + 73) || !*(_BYTE *)(a2 + v40 + 73) || !*(_BYTE *)(a3 + v40 + 73) )
    goto LABEL_49;
  v12 = *(_QWORD *)(a1 + 8i64 * v40 + 120) * v42;
  v13 = v40 + 1;
  v42 = v12;
  if ( v8 <= v40 + 1 )
    goto LABEL_103;
  v11 = v13;
  if ( !*(_BYTE *)(a1 + v13 + 73) || !*(_BYTE *)(a2 + v13 + 73) || !*(_BYTE *)(a3 + v13 + 73) )
    goto LABEL_99;
  v14 = *(_QWORD *)(a1 + 8i64 * v13 + 120) * v12;
  v15 = v40 + 2;
  v42 = v14;
  if ( v8 <= v40 + 2 || !*(_BYTE *)(a1 + v15 + 73) || !*(_BYTE *)(a2 + v15 + 73) || !*(_BYTE *)(a3 + v15 + 73) )
  {
    v11 = v15;
    goto LABEL_98;
  }
  v16 = *(_QWORD *)(a1 + 8i64 * v15 + 120) * v14;
  v17 = v40 + 3;
  v11 = v40 + 3;
  v42 = v16;
  if ( v8 <= v40 + 3 )
  {
LABEL_98:
    v13 = v11;
    goto LABEL_99;
  }
  if ( !*(_BYTE *)(a1 + v17 + 73) || !*(_BYTE *)(a2 + v17 + 73) || !*(_BYTE *)(a3 + v17 + 73) )
  {
    v40 += 3;
    goto LABEL_49;
  }
  v18 = *(_QWORD *)(a1 + 8i64 * v17 + 120) * v16;
  v13 = v40 + 4;
  v42 = v18;
  if ( v8 > v40 + 4 )
  {
    v11 = v13;
    if ( *(_BYTE *)(a1 + v13 + 73) && *(_BYTE *)(a2 + v13 + 73) )
    {
      if ( *(_BYTE *)(a3 + v13 + 73) )
      {
        v40 += 5;
        v11 = v13 + 1;
        v42 = *(_QWORD *)(a1 + 8i64 * v13 + 120) * v18;
        goto LABEL_49;
      }
      goto LABEL_103;
    }
LABEL_99:
    v40 = v13;
    goto LABEL_49;
  }
LABEL_103:
  v40 = v13;
  v11 = v13;
LABEL_49:
  v19 = *(unsigned int *)(a2 + 48);
  v45 = 0i64;
  v20 = dword_66A375E0[v19];
  if ( v8 <= 1 )
  {
    v22 = 0i64;
  }
  else
  {
    v21 = 1i64;
    do
      *(&v45 + v21++) = 0i64;
    while ( v8 > (int)v21 );
    v22 = v45;
  }
  v23 = &v45 + v11;
  v24 = v10 + 8;
  result = v11 + 12;
  v44 = v11 + 12;
  while ( 2 )
  {
    if ( v22 == -1 )
      return result;
    v26 = *(_DWORD *)(a3 + 80);
    v27 = *(_QWORD *)(a3 + 56);
    if ( v26 <= 0 )
    {
      v28 = 0i64;
    }
    else
    {
      v28 = *(_QWORD *)(a3 + 88) * v22;
      if ( v26 != 1 )
      {
        v28 += *(_QWORD *)(a3 + 96) * v46;
        if ( v26 != 2 )
        {
          v28 += *(_QWORD *)(a3 + 104) * v47;
          if ( v26 != 3 )
          {
            v29 = v48;
            v30 = *(_QWORD *)(a3 + 112);
            goto LABEL_60;
          }
        }
      }
    }
    while ( 1 )
    {
      v41 = v27 + v28;
      v28 = *(unsigned int *)(a2 + 80);
      if ( (int)v28 <= 0 )
      {
        v30 = 0i64;
      }
      else
      {
        v30 = *(_QWORD *)(a2 + 88) * v22;
        if ( (_DWORD)v28 != 1 )
        {
          v30 += *(_QWORD *)(a2 + 96) * v46;
          if ( (_DWORD)v28 != 2 )
          {
            v30 += *(_QWORD *)(a2 + 104) * v47;
            if ( (_DWORD)v28 != 3 )
            {
              v27 = v48;
              v29 = *(_QWORD *)(a2 + 112);
              if ( (_DWORD)v28 != 4 )
                goto LABEL_60;
              v30 += v29 * v48;
            }
          }
        }
      }
      v28 = *(unsigned int *)(a1 + 80);
      v30 += *(_QWORD *)(a2 + 56);
      v29 = *(_QWORD *)(a1 + 8 * v24 + 24) >> v20;
      v27 = *(_QWORD *)(a1 + 56);
      if ( (int)v28 <= 0 )
        break;
      v22 *= *(_QWORD *)(a1 + 88);
      if ( (_DWORD)v28 == 1 )
        goto LABEL_73;
      v22 += *(_QWORD *)(a1 + 96) * v46;
      if ( (_DWORD)v28 == 2 )
        goto LABEL_73;
      v22 += *(_QWORD *)(a1 + 104) * v47;
      if ( (_DWORD)v28 == 3 )
        goto LABEL_73;
      if ( (_DWORD)v28 == 4 )
      {
        v22 += *(_QWORD *)(a1 + 112) * v48;
        goto LABEL_73;
      }
LABEL_60:
      v28 += v30 * v29;
    }
    v22 = 0i64;
LABEL_73:
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v39 + 168))(
               v39,
               v27 + v22,
               v29,
               v30,
               *(_QWORD *)(a2 + 8 * v24 + 24) >> v20,
               v41,
               *(_QWORD *)(a3 + 8 * v24 + 24) >> v20,
               v43,
               v42,
               *(_DWORD *)(a2 + 48));
    v31 = *(_DWORD *)(a1 + 80);
    if ( v40 < v31 )
    {
      result = *v23 + 1;
      *v23 = result;
      if ( *(_QWORD *)(a1 + 8 * v44 + 24) != result )
      {
LABEL_79:
        v22 = v45;
        continue;
      }
      result = 0i64;
      v32 = v31 - 1 - v40;
      while ( 1 )
      {
        v23[result] = 0i64;
        if ( result == v32 )
          break;
        v33 = v23[result + 1] + 1;
        v23[++result] = v33;
        if ( v33 != *(_QWORD *)(a1 + 8i64 * (v40 + 1) + 8 * result + 112) )
          goto LABEL_79;
      }
    }
    return result;
  }
}

