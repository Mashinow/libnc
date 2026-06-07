// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_pad
// Included functions: 6

// ======================================================
// Function: nc_pad @ 0x66A24120
// ======================================================

__int64 __fastcall nc_pad(__int64 a1, __int64 a2, int a3, __int64 a4, int a5)
{
  __int64 v5; // rbx
  __int64 v8; // r14
  int v9; // esi
  __int64 v10; // rdi
  _QWORD *v11; // rbp
  int v12; // r12d
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rsi
  int v16; // eax
  int v17; // edx
  __int64 v18; // r10
  __int64 v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rdi
  int v23; // r14d
  int v24; // r8d
  __int64 v25; // rsi
  __int64 v26; // rdx
  int v27; // edx
  __int64 v28; // r12
  unsigned __int64 v29; // r9
  __int64 v30; // r12
  bool v31; // zf
  int v32; // edx
  int v33; // r9d
  __int64 *v34; // r8
  __int64 v35; // rcx
  __int64 v36; // r10
  __int64 v37; // r9
  __int64 v38; // rdx
  __int64 v39; // rax
  _QWORD *v40; // rax
  _DWORD *v41; // rcx
  __int64 v43; // [rsp+28h] [rbp-110h]
  __int64 v44; // [rsp+30h] [rbp-108h]
  __int64 v45; // [rsp+38h] [rbp-100h]
  __int64 v46; // [rsp+40h] [rbp-F8h]
  __int64 v47; // [rsp+48h] [rbp-F0h]
  __int64 v48; // [rsp+48h] [rbp-F0h]
  __int64 v49; // [rsp+50h] [rbp-E8h]
  __int64 v50; // [rsp+58h] [rbp-E0h]
  __int64 v51; // [rsp+58h] [rbp-E0h]
  __int64 v52; // [rsp+60h] [rbp-D8h]
  __int64 v53; // [rsp+60h] [rbp-D8h]
  __int64 v54; // [rsp+68h] [rbp-D0h]
  __int64 v55; // [rsp+70h] [rbp-C8h]
  __int64 v56; // [rsp+70h] [rbp-C8h]
  __int64 v57; // [rsp+78h] [rbp-C0h]
  __int64 v58; // [rsp+78h] [rbp-C0h]
  __int64 v59; // [rsp+80h] [rbp-B8h]
  __int64 v60; // [rsp+88h] [rbp-B0h]
  __int64 v61; // [rsp+88h] [rbp-B0h]
  __int64 v62; // [rsp+90h] [rbp-A8h]
  __int64 v63; // [rsp+90h] [rbp-A8h]
  __int64 v64; // [rsp+98h] [rbp-A0h]
  int v65; // [rsp+A4h] [rbp-94h] BYREF
  __int64 v66; // [rsp+A8h] [rbp-90h] BYREF
  __int64 v67; // [rsp+B0h] [rbp-88h] BYREF
  __int64 v68; // [rsp+B8h] [rbp-80h] BYREF
  __int64 v69; // [rsp+D0h] [rbp-68h] BYREF
  __int64 v70; // [rsp+D8h] [rbp-60h]
  __int64 v71; // [rsp+E0h] [rbp-58h]
  __int64 v72; // [rsp+E8h] [rbp-50h]

  v5 = a1;
  if ( !(a4 | a2) )
    return v5;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(int *)(a1 + 80) <= 0 )
    sub_66A33D40("x->n_dims >= 1", "libnc.c", 6366);
  if ( !*(_BYTE *)(v5 + 73) )
    sub_66A33D40("x->contig[0]", "libnc.c", 6367);
  if ( *(_QWORD *)(v5 + 120) + a2 + a4 <= 0 )
    sub_66A16930("pad", v5, 0i64);
  v9 = *(_DWORD *)(v5 + 80);
  v67 = *(_QWORD *)(v5 + 120) + a2 + a4;
  if ( v9 > 1 )
    memcpy(&v68, (const void *)(v5 + 128), 8i64 * (unsigned int)(v9 - 2) + 8);
  v10 = 0i64;
  v11 = nc_new_tensor_nz(v8, *(_DWORD *)(v5 + 48), v9, (__int64)&v67);
  v12 = dword_66A375E0[*((unsigned int *)v11 + 12)];
  v13 = 0i64;
  v14 = 0i64;
  if ( a2 <= 0 )
    v13 = a2;
  if ( a4 <= 0 )
    v14 = a4;
  if ( a2 >= 0 )
    v10 = a2;
  v15 = v10 + *(_QWORD *)(v5 + 120) + v13 + v14;
  v16 = sub_66A05420(
          &v65,
          1,
          v5,
          (__int64)v11,
          0i64,
          v43,
          v44,
          v45,
          v46,
          v47,
          *(_QWORD *)(v5 + 120) + v13 + v14,
          -v13,
          *(_QWORD *)(v5 + 120) + v14,
          v54,
          v55,
          v57,
          v59,
          v60,
          v62,
          v64);
  v17 = *(_DWORD *)(v5 + 80);
  v18 = v52;
  v69 = 0i64;
  v48 = v16;
  v19 = 1i64;
  if ( v17 <= 1 )
  {
    v20 = 0i64;
  }
  else
  {
    do
      *(&v69 + v19++) = 0i64;
    while ( v17 > (int)v19 );
    v20 = v69;
  }
  v51 = v50 << v12;
  v21 = v10 << v12;
  v22 = v8;
  v53 = v21;
  v23 = v12;
  v61 = 4 * v18;
  v63 = 4 * v15 - 4;
  v58 = (v18 - 1) << v12;
  v56 = v15 << v12;
  while ( 1 )
  {
    if ( v20 == -1 )
      goto LABEL_46;
    v24 = *((_DWORD *)v11 + 20);
    v25 = v11[7];
    if ( v24 <= 0 )
      goto LABEL_25;
    v26 = v11[11] * v20;
    if ( v24 == 1 )
      goto LABEL_26;
    v26 += v11[12] * v70;
    if ( v24 == 2 )
      goto LABEL_26;
    v26 += v11[13] * v71;
    if ( v24 == 3 )
      goto LABEL_26;
    if ( v24 != 4 )
      goto LABEL_25;
    v28 = *(_QWORD *)(v5 + 56);
    v25 += v11[14] * v72 + v26;
    v27 = *(_DWORD *)(v5 + 80);
    if ( v27 <= 0 )
    {
LABEL_55:
      v29 = *(_QWORD *)(v5 + 96);
      v20 = 0i64;
      goto LABEL_32;
    }
    while ( 2 )
    {
      v20 *= *(_QWORD *)(v5 + 88);
      v29 = *(_QWORD *)(v5 + 96);
      if ( v27 != 1 )
      {
        v20 += v70 * v29;
        if ( v27 != 2 )
        {
          v20 += *(_QWORD *)(v5 + 104) * v71;
          if ( v27 != 3 )
          {
            if ( v27 == 4 )
            {
              v20 += *(_QWORD *)(v5 + 112) * v72;
              break;
            }
LABEL_25:
            v26 = 0i64;
LABEL_26:
            v25 += v26;
            v27 = *(_DWORD *)(v5 + 80);
            v28 = *(_QWORD *)(v5 + 56);
            if ( v27 <= 0 )
              goto LABEL_55;
            continue;
          }
        }
      }
      break;
    }
LABEL_32:
    v30 = v20 + v28;
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, unsigned __int64, __int64, __int64, int))(v22 + 72))(
      v22,
      v25 + v53,
      v11[12] >> v23,
      v30 + v51,
      v29 >> v23,
      v49,
      v48,
      v23);
    if ( a2 <= 0 )
    {
      if ( a2 && a3 )
      {
        if ( a3 != 1 )
          goto LABEL_53;
        if ( *(_DWORD *)(v5 + 48) )
          goto LABEL_68;
        (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v22 + 376))(
          v22,
          v25,
          v11[12] >> v23,
          v30,
          *(_QWORD *)(v5 + 96) >> v23,
          -a2,
          v48,
          0);
      }
LABEL_36:
      v31 = a4 == 0;
      if ( a4 > 0 )
        goto LABEL_37;
      goto LABEL_58;
    }
    if ( a3 )
    {
      if ( a3 != 1 )
        goto LABEL_53;
      (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, int))(v22 + 120))(
        v22,
        v25,
        v11[12] >> v23,
        v30,
        *(_QWORD *)(v5 + 96) >> v23,
        a2,
        v48,
        v23);
      goto LABEL_36;
    }
    (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, int))(v22 + 112))(
      v22,
      v25,
      v11[12] >> v23,
      0i64,
      a2,
      v48,
      v23);
    v31 = a4 == 0;
    if ( a4 > 0 )
    {
LABEL_37:
      if ( a5 )
      {
        if ( a5 != 1 )
          goto LABEL_53;
        (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, int))(v22 + 120))(
          v22,
          v25 + v56,
          v11[12] >> v23,
          v30 + v58,
          *(_QWORD *)(v5 + 96) >> v23,
          a4,
          v48,
          v23);
      }
      else
      {
        (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, int))(v22 + 112))(
          v22,
          v25 + v56,
          v11[12] >> v23,
          0i64,
          a4,
          v48,
          v23);
      }
      goto LABEL_40;
    }
LABEL_58:
    if ( !v31 && a5 )
    {
      if ( a5 != 1 )
LABEL_53:
        abort();
      if ( *(_DWORD *)(v5 + 48) )
LABEL_68:
        nc_error("unsupported type for %s\n", "nc_pad");
      (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v22 + 376))(
        v22,
        v25 + v63,
        v11[12] >> v23,
        v30 + v61,
        *(_QWORD *)(v5 + 96) >> v23,
        -a4,
        v48,
        0);
    }
LABEL_40:
    v32 = v65;
    v33 = *(_DWORD *)(v5 + 80);
    if ( v65 >= v33 )
      goto LABEL_45;
    v34 = &v69 + v65;
    v35 = *v34 + 1;
    *v34 = v35;
    if ( *(_QWORD *)(v5 + 8i64 * v32 + 120) == v35 )
      break;
LABEL_56:
    v20 = v69;
  }
  v36 = v5 + 8i64 * (v32 + 1);
  v37 = (unsigned int)(~v32 + v33);
  v38 = 0i64;
  while ( 1 )
  {
    v34[v38] = 0i64;
    if ( v37 == v38 )
      break;
    v39 = v34[v38 + 1] + 1;
    v34[++v38] = v39;
    if ( v39 != *(_QWORD *)(v36 + 8 * v38 + 112) )
      goto LABEL_56;
  }
LABEL_45:
  v69 = -1i64;
LABEL_46:
  v66 = v5;
  v40 = sub_66A15DA0(17, v11 + 3, (__int64 **)v11 + 4, 1, (__int64)&v66);
  if ( v40 )
  {
    v40[7] = a2;
    v40[8] = a4;
    *((_DWORD *)v40 + 18) = a3;
    *((_DWORD *)v40 + 19) = a5;
  }
  v41 = (_DWORD *)v5;
  v5 = (__int64)v11;
  nc_free_tensor(v41);
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

