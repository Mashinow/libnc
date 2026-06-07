// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_lerp_bw
// Included functions: 4

// ======================================================
// Function: nc_lerp_bw @ 0x66A2BF60
// ======================================================

_QWORD *__fastcall nc_lerp_bw(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r13
  _QWORD *v9; // rbp
  _QWORD *v10; // r12
  _QWORD *v11; // r15
  int v12; // eax
  int v13; // edx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // r8
  int v17; // ecx
  __int64 v18; // rdx
  __int64 v19; // r9
  __int64 v20; // r10
  __int64 v21; // rcx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  __int64 v25; // rcx
  int v26; // ecx
  int v27; // eax
  int v28; // r8d
  __int64 *v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // r9
  __int64 v32; // r8
  __int64 v33; // rax
  __int64 v34; // rdx
  _QWORD *result; // rax
  __int64 v36; // [rsp+50h] [rbp-B8h]
  __int64 v37; // [rsp+58h] [rbp-B0h]
  __int64 v38; // [rsp+58h] [rbp-B0h]
  __int64 v39; // [rsp+60h] [rbp-A8h]
  __int64 v40; // [rsp+68h] [rbp-A0h]
  __int64 v41; // [rsp+68h] [rbp-A0h]
  __int64 v42; // [rsp+70h] [rbp-98h]
  __int64 v43; // [rsp+70h] [rbp-98h]
  __int64 v44; // [rsp+78h] [rbp-90h]
  __int64 v45; // [rsp+78h] [rbp-90h]
  __int64 v46; // [rsp+80h] [rbp-88h]
  __int64 v47; // [rsp+80h] [rbp-88h]
  __int64 v48; // [rsp+88h] [rbp-80h]
  __int64 v49; // [rsp+90h] [rbp-78h]
  __int64 v50; // [rsp+98h] [rbp-70h] BYREF
  __int64 v51; // [rsp+A0h] [rbp-68h] BYREF
  __int64 v52; // [rsp+A8h] [rbp-60h]
  __int64 v53; // [rsp+B0h] [rbp-58h]
  __int64 v54; // [rsp+B8h] [rbp-50h]

  v6 = a2 + 120;
  v37 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  v9 = nc_new_tensor_nz(v37, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 80), a2 + 120);
  v10 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64), *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 80), v6);
  v11 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64), *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 80), v6);
  v12 = sub_66A05420(
          (_DWORD *)&v50 + 1,
          0,
          (__int64)v9,
          (__int64)v10,
          (__int64)v11,
          a2,
          a3,
          a4,
          a5,
          0i64,
          v36,
          v37,
          a5,
          v40,
          v42,
          v44,
          v46,
          v48,
          v49,
          v50);
  v13 = *(_DWORD *)(a3 + 80);
  v51 = 0i64;
  v47 = v12;
  if ( v13 <= 1 )
  {
    v15 = 0i64;
  }
  else
  {
    v14 = 1i64;
    do
      *(&v51 + v14++) = 0i64;
    while ( v13 > (int)v14 );
    v15 = v51;
  }
  while ( v15 != -1 )
  {
    v16 = *(_QWORD *)(v39 + 56);
    v17 = *(_DWORD *)(v39 + 80);
    if ( v17 <= 0 )
    {
      v18 = 0i64;
    }
    else
    {
      v18 = *(_QWORD *)(v39 + 88) * v15;
      if ( v17 != 1 )
      {
        v18 += *(_QWORD *)(v39 + 96) * v52;
        if ( v17 != 2 )
        {
          v18 += *(_QWORD *)(v39 + 104) * v53;
          if ( v17 != 3 )
          {
            v19 = v54;
            v20 = *(_QWORD *)(v39 + 112);
            goto LABEL_11;
          }
        }
      }
    }
    while ( 1 )
    {
      v21 = v16 + v18;
      v16 = *(_QWORD *)(a4 + 56);
      v45 = v21;
      v22 = *(_DWORD *)(a4 + 80);
      if ( v22 <= 0 )
      {
        v18 = 0i64;
      }
      else
      {
        v18 = *(_QWORD *)(a4 + 88) * v15;
        if ( v22 != 1 )
        {
          v18 += *(_QWORD *)(a4 + 96) * v52;
          if ( v22 != 2 )
          {
            v18 += *(_QWORD *)(a4 + 104) * v53;
            if ( v22 != 3 )
            {
              v19 = v54;
              v20 = *(_QWORD *)(a4 + 112);
              if ( v22 != 4 )
                goto LABEL_11;
              v18 += v20 * v54;
            }
          }
        }
      }
      v20 = *(_QWORD *)(a3 + 56);
      v43 = v16 + v18;
      v23 = *(_DWORD *)(a3 + 80);
      if ( v23 <= 0 )
      {
        v24 = *(_DWORD *)(a2 + 80);
        v16 = *(_QWORD *)(a2 + 56);
        if ( v24 <= 0 )
          goto LABEL_57;
      }
      else
      {
        v18 = *(_QWORD *)(a3 + 88) * v15;
        if ( v23 != 1 )
        {
          v18 += *(_QWORD *)(a3 + 96) * v52;
          if ( v23 != 2 )
          {
            v18 += *(_QWORD *)(a3 + 104) * v53;
            if ( v23 != 3 )
            {
              v16 = v54;
              v19 = *(_QWORD *)(a3 + 112);
              if ( v23 != 4 )
                goto LABEL_11;
              v18 += v19 * v54;
            }
          }
        }
        v24 = *(_DWORD *)(a2 + 80);
        v20 += v18;
        v16 = *(_QWORD *)(a2 + 56);
        if ( v24 <= 0 )
        {
LABEL_57:
          v18 = 0i64;
          goto LABEL_30;
        }
      }
      v18 = *(_QWORD *)(a2 + 88) * v15;
      if ( v24 != 1 )
      {
        v18 += *(_QWORD *)(a2 + 96) * v52;
        if ( v24 != 2 )
        {
          v18 += *(_QWORD *)(a2 + 104) * v53;
          if ( v24 != 3 )
          {
            v19 = v54;
            if ( v24 != 4 )
              goto LABEL_11;
            v18 += *(_QWORD *)(a2 + 112) * v54;
          }
        }
      }
LABEL_30:
      v25 = v16 + v18;
      v18 = *((unsigned int *)v11 + 20);
      v41 = v25;
      if ( (int)v18 <= 0 )
      {
        v19 = 0i64;
      }
      else
      {
        v19 = v11[11] * v15;
        if ( (_DWORD)v18 != 1 )
        {
          v19 += v11[12] * v52;
          if ( (_DWORD)v18 != 2 )
          {
            v19 += v11[13] * v53;
            if ( (_DWORD)v18 != 3 )
            {
              v16 = v54;
              if ( (_DWORD)v18 != 4 )
                goto LABEL_11;
              v19 += v11[14] * v54;
            }
          }
        }
      }
      v18 = *((unsigned int *)v10 + 20);
      v19 += v11[7];
      if ( (int)v18 <= 0 )
      {
        v16 = 0i64;
      }
      else
      {
        v16 = v10[11] * v15;
        if ( (_DWORD)v18 != 1 )
        {
          v16 += v10[12] * v52;
          if ( (_DWORD)v18 != 2 )
          {
            v16 += v10[13] * v53;
            if ( (_DWORD)v18 != 3 )
            {
              if ( (_DWORD)v18 != 4 )
                goto LABEL_11;
              v16 += v10[14] * v54;
            }
          }
        }
      }
      v16 += v10[7];
      v26 = *((_DWORD *)v9 + 20);
      v18 = v9[7];
      if ( v26 <= 0 )
        break;
      v15 *= v9[11];
      if ( v26 == 1 )
        goto LABEL_48;
      v15 += v9[12] * v52;
      if ( v26 == 2 )
        goto LABEL_48;
      v15 += v9[13] * v53;
      if ( v26 == 3 )
        goto LABEL_48;
      if ( v26 == 4 )
      {
        v15 += v9[14] * v54;
        goto LABEL_48;
      }
LABEL_11:
      v18 += v20 * v19;
    }
    v15 = 0i64;
LABEL_48:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v38 + 296))(
      v38,
      v15 + v18,
      v16,
      v19,
      v41,
      v20,
      v43,
      v45,
      v47);
    v27 = HIDWORD(v50);
    v28 = *(_DWORD *)(a3 + 80);
    if ( SHIDWORD(v50) < v28 )
    {
      v29 = &v51 + SHIDWORD(v50);
      v30 = *v29 + 1;
      *v29 = v30;
      if ( v30 != *(_QWORD *)(a3 + 8i64 * v27 + 120) )
      {
LABEL_54:
        v15 = v51;
        continue;
      }
      v31 = a3 + 8i64 * (v27 + 1);
      v32 = (unsigned int)(~v27 + v28);
      v33 = 0i64;
      while ( 1 )
      {
        v29[v33] = 0i64;
        if ( v32 == v33 )
          break;
        v34 = v29[v33 + 1] + 1;
        v29[++v33] = v34;
        if ( v34 != *(_QWORD *)(v31 + 8 * v33 + 112) )
          goto LABEL_54;
      }
    }
    break;
  }
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)a3);
  nc_free_tensor((_DWORD *)a4);
  nc_free_tensor((_DWORD *)v39);
  result = a1;
  *a1 = v9;
  a1[1] = v10;
  a1[2] = v11;
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

