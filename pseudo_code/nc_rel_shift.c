// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_rel_shift
// Included functions: 5

// ======================================================
// Function: nc_rel_shift @ 0x66A2CEE0
// ======================================================

_QWORD *__fastcall nc_rel_shift(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // r8d
  _QWORD *v5; // rsi
  int v6; // ebp
  int v7; // eax
  int v8; // edx
  __int64 v9; // rax
  __int64 v10; // rax
  unsigned __int64 v11; // r9
  unsigned __int64 v12; // r10
  int v13; // r8d
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // r13
  __int64 v16; // r12
  __int64 v17; // rcx
  __int64 v18; // r9
  __int64 v19; // r10
  unsigned __int64 v20; // r10
  unsigned __int64 v21; // r11
  int v22; // eax
  int v23; // r8d
  __int64 *v24; // rcx
  __int64 v25; // rdx
  __int64 v26; // r9
  __int64 v27; // r8
  __int64 v28; // rax
  __int64 v29; // rdx
  __int64 *v31; // rax
  __int64 v32; // r12
  __int64 *v33; // r13
  _QWORD *v34; // rbp
  _QWORD *v35; // rax
  __int64 v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rax
  __int64 *v39; // rcx
  __int64 v40; // [rsp+28h] [rbp-E0h]
  __int64 v41; // [rsp+30h] [rbp-D8h]
  __int64 v42; // [rsp+38h] [rbp-D0h]
  __int64 v43; // [rsp+40h] [rbp-C8h]
  __int64 v44; // [rsp+48h] [rbp-C0h]
  __int64 v45; // [rsp+50h] [rbp-B8h]
  __int64 v46; // [rsp+58h] [rbp-B0h]
  __int64 v47; // [rsp+60h] [rbp-A8h]
  __int64 v48; // [rsp+68h] [rbp-A0h]
  __int64 v49; // [rsp+70h] [rbp-98h]
  __int64 v50; // [rsp+70h] [rbp-98h]
  __int64 v51; // [rsp+78h] [rbp-90h]
  __int64 v52; // [rsp+80h] [rbp-88h]
  __int64 v53; // [rsp+80h] [rbp-88h]
  __int64 v54; // [rsp+88h] [rbp-80h]
  __int64 v55; // [rsp+90h] [rbp-78h]
  __int64 v56; // [rsp+98h] [rbp-70h] BYREF
  __int64 v57; // [rsp+A0h] [rbp-68h] BYREF
  __int64 v58; // [rsp+A8h] [rbp-60h]
  __int64 v59; // [rsp+B0h] [rbp-58h]
  __int64 v60; // [rsp+B8h] [rbp-50h]

  v49 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( !*(_BYTE *)(a1 + 73) )
    sub_66A33D40("x->contig[0]", "libnc.c", 7638);
  v4 = *(_DWORD *)(a1 + 80);
  if ( v4 <= 1 )
    sub_66A16930("rel_shift", a1, 0i64);
  v5 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), *(_DWORD *)(a1 + 48), v4, a1 + 120);
  v6 = dword_66A375E0[*(unsigned int *)(a1 + 48)];
  v7 = sub_66A05420(
         (_DWORD *)&v56 + 1,
         2,
         a1,
         (__int64)v5,
         0i64,
         v40,
         v41,
         v42,
         v43,
         v44,
         v45,
         v46,
         v47,
         v48,
         v49,
         v51,
         v52,
         v54,
         v55,
         v56);
  v8 = *(_DWORD *)(a1 + 80);
  v57 = 0i64;
  v53 = v7;
  if ( v8 <= 1 )
  {
    v10 = 0i64;
  }
  else
  {
    v9 = 1i64;
    do
      *(&v57 + v9++) = 0i64;
    while ( v8 > (int)v9 );
    v10 = v57;
  }
  while ( v10 != -1 )
  {
    v11 = *(_QWORD *)(a1 + 104);
    v12 = *(_QWORD *)(a1 + 96);
    v13 = *(_DWORD *)(a1 + 80);
    v14 = v11 >> v6;
    v15 = v12 >> v6;
    v16 = *(_QWORD *)(a1 + 56);
    if ( v13 <= 0 )
    {
      v17 = 0i64;
    }
    else
    {
      v17 = *(_QWORD *)(a1 + 88) * v10;
      if ( v13 != 1 )
      {
        v17 += v58 * v12;
        if ( v13 != 2 )
        {
          v17 += v59 * v11;
          if ( v13 != 3 )
          {
            v18 = v60;
            v19 = *(_QWORD *)(a1 + 112);
            goto LABEL_14;
          }
        }
      }
    }
    while ( 1 )
    {
      v16 += v17;
      v20 = v5[13];
      v21 = v5[12];
      v17 = *((unsigned int *)v5 + 20);
      v18 = v20 >> v6;
      if ( (int)v17 <= 0 )
        break;
      v10 *= v5[11];
      if ( (_DWORD)v17 == 1 )
        goto LABEL_21;
      v10 += v58 * v21;
      if ( (_DWORD)v17 == 2 )
        goto LABEL_21;
      v10 += v59 * v20;
      if ( (_DWORD)v17 == 3 )
        goto LABEL_21;
      v19 = v60;
      if ( (_DWORD)v17 == 4 )
      {
        v10 += v5[14] * v60;
        goto LABEL_21;
      }
LABEL_14:
      v17 += v19 * v18;
    }
    v10 = 0i64;
LABEL_21:
    (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, __int64, __int64, __int64, int))(v50 + 464))(
      v50,
      v5[7] + v10,
      v21 >> v6,
      v18,
      v16,
      v15,
      v14,
      *(_QWORD *)(a1 + 120),
      *(_QWORD *)(a1 + 128),
      v53,
      a2,
      a3,
      v6);
    v22 = HIDWORD(v56);
    v23 = *(_DWORD *)(a1 + 80);
    if ( SHIDWORD(v56) >= v23 )
      goto LABEL_26;
    v24 = &v57 + SHIDWORD(v56);
    v25 = *v24 + 1;
    *v24 = v25;
    if ( *(_QWORD *)(a1 + 8i64 * v22 + 120) == v25 )
    {
      v26 = a1 + 8i64 * (v22 + 1);
      v27 = (unsigned int)(~v22 + v23);
      v28 = 0i64;
      while ( 1 )
      {
        v24[v28] = 0i64;
        if ( v27 == v28 )
          break;
        v29 = v24[v28 + 1] + 1;
        v24[++v28] = v29;
        if ( v29 != *(_QWORD *)(v26 + 8 * v28 + 112) )
          goto LABEL_31;
      }
LABEL_26:
      v57 = -1i64;
      break;
    }
LABEL_31:
    v10 = v57;
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v31 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v32 = v5[3];
    v33 = v31;
    *v31 = *(_QWORD *)(a1 + 32);
    v34 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v34 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v34, 0, 0x80ui64);
    *((_DWORD *)v34 + 4) = 1;
    *((_DWORD *)v34 + 5) = 36;
    *((_DWORD *)v34 + 6) = 1;
    v35 = aligned_malloc(8ui64, 0x40ui64);
    v36 = *v33;
    v34[4] = v35;
    if ( v36 )
    {
      ++*(_DWORD *)(v36 + 16);
      *v35 = v36;
    }
    else
    {
      *v35 = 0i64;
    }
    v37 = *(_QWORD *)(v32 + 72);
    *(_QWORD *)(v32 + 72) = v37 + 1;
    v34[12] = v37;
    v38 = *(_QWORD *)(v32 + 32);
    *(_QWORD *)(v38 + 8) = v34;
    *v34 = v38;
    v34[1] = v32 + 32;
    *(_QWORD *)(v32 + 32) = v34;
    _aligned_free(v33);
    v39 = (__int64 *)v5[4];
    if ( v39 )
      nc_free_node(v39);
    v5[4] = v34;
    v34[7] = a2;
    v34[8] = a3;
  }
  if ( (_QWORD *)a1 != v5 )
    nc_free_tensor((_DWORD *)a1);
  return v5;
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
// Function: sub_66A16930 @ 0x66A16930
// ======================================================

void __fastcall __noreturn sub_66A16930(const char *a1, __int64 a2, __int64 a3)
{
  printf("dimension error for %s: ", a1);
  nc_dump_dims("x1", a2);
  if ( a3 )
  {
    printf(", ");
    nc_dump_dims("x2", a3);
  }
  putchar(10);
  abort();
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

