// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_soft_max_bw
// Included functions: 5

// ======================================================
// Function: nc_soft_max_bw @ 0x66A27AC0
// ======================================================

_QWORD *__fastcall nc_soft_max_bw(__int64 a1, __int64 a2)
{
  unsigned int v4; // eax
  int v5; // ecx
  _QWORD *v6; // rsi
  int v7; // eax
  int v8; // edx
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // ecx
  __int64 v12; // r8
  __int64 v13; // rdx
  __int64 v14; // r9
  __int64 v15; // r10
  __int64 v16; // r15
  int v17; // ecx
  int v18; // eax
  int v19; // r8d
  __int64 *v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // r9
  __int64 v23; // r8
  __int64 v24; // rax
  __int64 v25; // rdx
  __int64 v27; // rax
  __int64 v28; // rdx
  __int64 v29; // [rsp+30h] [rbp-C8h]
  __int64 v30; // [rsp+38h] [rbp-C0h]
  __int64 v31; // [rsp+40h] [rbp-B8h]
  __int64 v32; // [rsp+48h] [rbp-B0h]
  __int64 v33; // [rsp+50h] [rbp-A8h]
  __int64 v34; // [rsp+50h] [rbp-A8h]
  __int64 v35; // [rsp+58h] [rbp-A0h]
  __int64 v36; // [rsp+60h] [rbp-98h]
  __int64 v37; // [rsp+60h] [rbp-98h]
  __int64 v38; // [rsp+68h] [rbp-90h]
  __int64 v39; // [rsp+70h] [rbp-88h]
  __int64 v40; // [rsp+78h] [rbp-80h] BYREF
  __int64 v41; // [rsp+80h] [rbp-78h] BYREF
  __int64 v42; // [rsp+88h] [rbp-70h]
  __int64 v43; // [rsp+90h] [rbp-68h] BYREF
  __int64 v44; // [rsp+98h] [rbp-60h]
  __int64 v45; // [rsp+A0h] [rbp-58h]
  __int64 v46; // [rsp+A8h] [rbp-50h]

  v33 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v33 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v4 = *(_DWORD *)(a1 + 48);
  if ( v4 > 1 || v4 != *(_DWORD *)(a2 + 48) )
    nc_error("unsupported type for %s\n", "nc_soft_max_bw");
  v5 = *(_DWORD *)(a1 + 80);
  if ( v5 != *(_DWORD *)(a2 + 80) )
    goto LABEL_5;
  if ( v5 <= 0 )
  {
LABEL_54:
    sub_66A33D40("yg1->n_dims >= 1", "libnc.c", 6913);
    goto LABEL_6;
  }
  if ( *(_QWORD *)(a1 + 120) != *(_QWORD *)(a2 + 120) )
  {
LABEL_5:
    sub_66A33D40("same_dims(yg1, yd1)", "libnc.c", 6912);
    if ( *(int *)(a1 + 80) > 0 )
      goto LABEL_6;
    goto LABEL_54;
  }
  v27 = 1i64;
  while ( v5 > (int)v27 )
  {
    v28 = *(_QWORD *)(a1 + 8 * v27++ + 120);
    if ( v28 != *(_QWORD *)(a2 + 8 * v27 + 112) )
      goto LABEL_5;
  }
LABEL_6:
  if ( !*(_BYTE *)(a1 + 73) )
  {
    sub_66A33D40("yg1->contig[0]", "libnc.c", 6914);
    if ( *(_BYTE *)(a2 + 73) )
      goto LABEL_8;
LABEL_47:
    sub_66A33D40("yd1->contig[0]", "libnc.c", 6915);
    goto LABEL_8;
  }
  if ( !*(_BYTE *)(a2 + 73) )
    goto LABEL_47;
LABEL_8:
  v6 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
    v6 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
  v7 = sub_66A05420(
         (_DWORD *)&v40 + 1,
         1,
         (__int64)v6,
         a1,
         a2,
         0i64,
         v29,
         v30,
         v31,
         v32,
         v33,
         v35,
         v36,
         v38,
         v39,
         v40,
         v41,
         v42,
         v43,
         v44);
  v8 = *(_DWORD *)(a1 + 80);
  v43 = 0i64;
  v37 = v7;
  if ( v8 <= 1 )
  {
    v10 = 0i64;
  }
  else
  {
    v9 = 1i64;
    do
      *(&v43 + v9++) = 0i64;
    while ( v8 > (int)v9 );
    v10 = v43;
  }
  while ( v10 != -1 )
  {
    v11 = *(_DWORD *)(a2 + 80);
    v12 = *(_QWORD *)(a2 + 56);
    if ( v11 <= 0 )
    {
      v13 = 0i64;
    }
    else
    {
      v13 = *(_QWORD *)(a2 + 88) * v10;
      if ( v11 != 1 )
      {
        v13 += *(_QWORD *)(a2 + 96) * v44;
        if ( v11 != 2 )
        {
          v13 += *(_QWORD *)(a2 + 104) * v45;
          if ( v11 != 3 )
          {
            v14 = v46;
            v15 = *(_QWORD *)(a2 + 112);
            goto LABEL_20;
          }
        }
      }
    }
    while ( 1 )
    {
      v16 = v12 + v13;
      v13 = *(unsigned int *)(a1 + 80);
      if ( (int)v13 <= 0 )
      {
        v14 = 0i64;
      }
      else
      {
        v14 = *(_QWORD *)(a1 + 88) * v10;
        if ( (_DWORD)v13 != 1 )
        {
          v14 += *(_QWORD *)(a1 + 96) * v44;
          if ( (_DWORD)v13 != 2 )
          {
            v14 += *(_QWORD *)(a1 + 104) * v45;
            if ( (_DWORD)v13 != 3 )
            {
              v12 = v46;
              v15 = *(_QWORD *)(a1 + 112);
              if ( (_DWORD)v13 != 4 )
                goto LABEL_20;
              v14 += v15 * v46;
            }
          }
        }
      }
      v14 += *(_QWORD *)(a1 + 56);
      v17 = *((_DWORD *)v6 + 20);
      v12 = v6[8];
      v15 = v6[7];
      if ( v17 <= 0 )
        break;
      v10 *= v6[11];
      if ( v17 == 1 )
        goto LABEL_33;
      v10 += v6[12] * v44;
      if ( v17 == 2 )
        goto LABEL_33;
      v10 += v6[13] * v45;
      if ( v17 == 3 )
        goto LABEL_33;
      v13 = v6[14];
      if ( v17 == 4 )
      {
        v10 += v13 * v46;
        goto LABEL_33;
      }
LABEL_20:
      v13 += v15 * v14;
    }
    v10 = 0i64;
LABEL_33:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD, __int64, _DWORD))(v34 + 400))(
      v34,
      v15 + v10,
      v12,
      v14,
      *(_QWORD *)(a1 + 64),
      v16,
      *(_QWORD *)(a2 + 64),
      v6[15],
      v37,
      *(_DWORD *)(a1 + 48));
    v18 = HIDWORD(v40);
    v19 = *(_DWORD *)(a1 + 80);
    if ( SHIDWORD(v40) >= v19 )
    {
LABEL_38:
      v43 = -1i64;
      break;
    }
    v20 = &v43 + SHIDWORD(v40);
    v21 = *v20 + 1;
    *v20 = v21;
    if ( *(_QWORD *)(a1 + 8i64 * v18 + 120) == v21 )
    {
      v22 = a1 + 8i64 * (v18 + 1);
      v23 = (unsigned int)(~v18 + v19);
      v24 = 0i64;
      do
      {
        v20[v24] = 0i64;
        if ( v23 == v24 )
          goto LABEL_38;
        v25 = v20[v24 + 1] + 1;
        v20[++v24] = v25;
      }
      while ( v25 == *(_QWORD *)(v22 + 8 * v24 + 112) );
    }
    v10 = v43;
  }
  v41 = a1;
  v42 = a2;
  sub_66A15DA0(0, v6 + 3, (__int64 **)v6 + 4, 2, (__int64)&v41);
  if ( v6 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v6;
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

