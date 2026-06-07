// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_soft_max
// Included functions: 4

// ======================================================
// Function: nc_soft_max @ 0x66A27F50
// ======================================================

_QWORD *__fastcall nc_soft_max(__int64 a1)
{
  __int64 v1; // rdi
  _QWORD *v3; // rsi
  int v4; // eax
  int v5; // edx
  __int64 v6; // rbp
  __int64 v7; // rax
  __int64 v8; // rax
  int v9; // edx
  __int64 v10; // r8
  __int64 v11; // r9
  __int64 v12; // rcx
  __int64 v13; // r10
  int v14; // eax
  int v15; // r8d
  __int64 *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r9
  __int64 v19; // r8
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 *v23; // rax
  __int64 v24; // r12
  __int64 *v25; // r14
  _QWORD *v26; // rbp
  _QWORD *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 *v31; // rcx
  _QWORD *v32; // rax
  __int64 v33; // [rsp+28h] [rbp-A0h]
  __int64 v34; // [rsp+30h] [rbp-98h]
  __int64 v35; // [rsp+38h] [rbp-90h]
  __int64 v36; // [rsp+40h] [rbp-88h]
  __int64 v37; // [rsp+48h] [rbp-80h]
  __int64 v38; // [rsp+50h] [rbp-78h]
  __int64 v39; // [rsp+58h] [rbp-70h] BYREF
  __int64 v40; // [rsp+60h] [rbp-68h] BYREF
  __int64 v41; // [rsp+68h] [rbp-60h]
  __int64 v42; // [rsp+70h] [rbp-58h]
  __int64 v43; // [rsp+78h] [rbp-50h]
  __int64 v44; // [rsp+80h] [rbp-48h]
  __int64 v45; // [rsp+88h] [rbp-40h]
  __int64 v46; // [rsp+90h] [rbp-38h]
  __int64 v47; // [rsp+98h] [rbp-30h]

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(_DWORD *)(a1 + 48) > 1u )
    nc_error("unsupported type for %s\n", "nc_soft_max");
  if ( *(int *)(a1 + 80) <= 0 )
    sub_66A33D40("x->n_dims >= 1", "libnc.c", 6951);
  if ( !*(_BYTE *)(a1 + 73) )
    sub_66A33D40("x->contig[0]", "libnc.c", 6952);
  v3 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
    v3 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
  v4 = sub_66A05420(
         (_DWORD *)&v39 + 1,
         1,
         (__int64)v3,
         a1,
         0i64,
         v33,
         v34,
         v35,
         v36,
         v37,
         v38,
         v39,
         v40,
         v41,
         v42,
         v43,
         v44,
         v45,
         v46,
         v47);
  v5 = *(_DWORD *)(a1 + 80);
  v40 = 0i64;
  v6 = v4;
  if ( v5 <= 1 )
  {
    v8 = 0i64;
  }
  else
  {
    v7 = 1i64;
    do
      *(&v40 + v7++) = 0i64;
    while ( v5 > (int)v7 );
    v8 = v40;
  }
  while ( v8 != -1 )
  {
    v9 = *(_DWORD *)(a1 + 80);
    v10 = *(_QWORD *)(a1 + 56);
    if ( v9 <= 0 )
    {
      v11 = 0i64;
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 88) * v8;
      if ( v9 != 1 )
      {
        v11 += *(_QWORD *)(a1 + 96) * v41;
        if ( v9 != 2 )
        {
          v11 += *(_QWORD *)(a1 + 104) * v42;
          if ( v9 != 3 )
          {
            v12 = v43;
            v13 = *(_QWORD *)(a1 + 112);
            goto LABEL_18;
          }
        }
      }
    }
    while ( 1 )
    {
      v12 = *((unsigned int *)v3 + 20);
      v11 += v10;
      v13 = v3[7];
      v10 = v3[8];
      if ( (int)v12 <= 0 )
        break;
      v8 *= v3[11];
      if ( (_DWORD)v12 == 1 )
        goto LABEL_25;
      v8 += v3[12] * v41;
      if ( (_DWORD)v12 == 2 )
        goto LABEL_25;
      v8 += v3[13] * v42;
      if ( (_DWORD)v12 == 3 )
        goto LABEL_25;
      if ( (_DWORD)v12 == 4 )
      {
        v8 += v3[14] * v43;
        goto LABEL_25;
      }
LABEL_18:
      v11 += v13 * v12;
    }
    v8 = 0i64;
LABEL_25:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, __int64, _DWORD))(v1 + 392))(
      v1,
      v13 + v8,
      v10,
      v11,
      *(_QWORD *)(a1 + 64),
      *(_QWORD *)(a1 + 120),
      v6,
      *(_DWORD *)(a1 + 48));
    v14 = HIDWORD(v39);
    v15 = *(_DWORD *)(a1 + 80);
    if ( SHIDWORD(v39) >= v15 )
      goto LABEL_30;
    v16 = &v40 + SHIDWORD(v39);
    v17 = *v16 + 1;
    *v16 = v17;
    if ( *(_QWORD *)(a1 + 8i64 * v14 + 120) == v17 )
    {
      v18 = a1 + 8i64 * (v14 + 1);
      v19 = (unsigned int)(~v14 + v15);
      v20 = 0i64;
      while ( 1 )
      {
        v16[v20] = 0i64;
        if ( v19 == v20 )
          break;
        v21 = v16[v20 + 1] + 1;
        v16[++v20] = v21;
        if ( v21 != *(_QWORD *)(v18 + 8 * v20 + 112) )
          goto LABEL_35;
      }
LABEL_30:
      v40 = -1i64;
      break;
    }
LABEL_35:
    v8 = v40;
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v23 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v24 = v3[3];
    v25 = v23;
    *v23 = *(_QWORD *)(a1 + 32);
    v26 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v26 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v26, 0, 0x80ui64);
    *((_DWORD *)v26 + 4) = 1;
    *((_DWORD *)v26 + 5) = 18;
    *((_DWORD *)v26 + 6) = 1;
    v27 = aligned_malloc(8ui64, 0x40ui64);
    v28 = *v25;
    v26[4] = v27;
    if ( v28 )
    {
      ++*(_DWORD *)(v28 + 16);
      *v27 = v28;
    }
    else
    {
      *v27 = 0i64;
    }
    v29 = *(_QWORD *)(v24 + 72);
    *(_QWORD *)(v24 + 72) = v29 + 1;
    v26[12] = v29;
    v30 = *(_QWORD *)(v24 + 32);
    *(_QWORD *)(v30 + 8) = v26;
    *v26 = v30;
    v26[1] = v24 + 32;
    *(_QWORD *)(v24 + 32) = v26;
    _aligned_free(v25);
    v31 = (__int64 *)v3[4];
    if ( v31 )
      nc_free_node(v31);
    v3[4] = v26;
    *((_DWORD *)v26 + 10) = 1;
    v32 = aligned_malloc(8ui64, 0x40ui64);
    v26[6] = v32;
    ++*((_DWORD *)v3 + 4);
    *v32 = v3;
  }
  if ( v3 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  return v3;
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

