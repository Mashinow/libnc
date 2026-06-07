// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_repeat
// Included functions: 5

// ======================================================
// Function: nc_repeat @ 0x66A1D660
// ======================================================

_QWORD *__fastcall nc_repeat(__int64 a1, int a2, const void *a3)
{
  __int64 v3; // r15
  __int64 v4; // rbx
  __int64 v8; // rsi
  unsigned __int64 v9; // r12
  _QWORD *v10; // r13
  __int64 v11; // rax
  int v12; // esi
  int v13; // edx
  __int64 v14; // rdi
  int v15; // eax
  int v16; // ecx
  __int64 *v17; // rbp
  __int64 v18; // rax
  __int64 v19; // rdx
  void (__fastcall *v20)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64 *, int); // r10
  __int64 v21; // r9
  __int64 v22; // rcx
  int v23; // eax
  __int64 v24; // r8
  __int64 v25; // rdx
  __int64 v26; // r11
  int v27; // eax
  int v28; // r8d
  __int64 *v29; // rcx
  __int64 v30; // rdx
  _QWORD *v31; // r9
  __int64 v32; // r8
  __int64 v33; // rax
  __int64 v34; // rdx
  _QWORD *v35; // rax
  int v37; // eax
  __int64 v38; // rax
  __int64 v39; // rax
  __int64 v40; // rax
  int v41; // eax
  __int64 *v42; // rcx
  __int64 v43; // rdx
  _QWORD *v44; // r9
  __int64 v45; // r8
  __int64 v46; // rax
  __int64 v47; // rdx
  int v48; // eax
  __int64 v49; // [rsp+20h] [rbp-B8h]
  __int64 v50; // [rsp+28h] [rbp-B0h]
  __int64 v51; // [rsp+30h] [rbp-A8h]
  __int64 v52; // [rsp+38h] [rbp-A0h]
  __int64 v53; // [rsp+40h] [rbp-98h] BYREF
  __int64 v54; // [rsp+48h] [rbp-90h] BYREF
  __int64 v55[4]; // [rsp+50h] [rbp-88h] BYREF
  __int64 v56; // [rsp+70h] [rbp-68h] BYREF
  __int64 v57; // [rsp+78h] [rbp-60h]
  __int64 v58; // [rsp+80h] [rbp-58h]
  __int64 v59; // [rsp+88h] [rbp-50h]
  __int64 v60; // [rsp+90h] [rbp-48h]
  __int64 v61; // [rsp+98h] [rbp-40h]

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( a2 <= 0 )
    sub_66A33D40("n_dims >= 1", "libnc.c", 5611);
  v8 = *(int *)(a1 + 80);
  v9 = (unsigned int)(a2 + v8);
  if ( (int)v9 > 4 )
  {
    sub_66A33D40("n_dims1 <= N_DIMS_MAX", "libnc.c", 5613);
    v8 = *(int *)(a1 + 80);
  }
  if ( (int)v8 > 0 )
    memcpy(v55, (const void *)(a1 + 120), 8i64 * (unsigned int)(v8 - 1) + 8);
  if ( a2 > 0 )
    memcpy(&v55[v8], a3, 8i64 * (unsigned int)(a2 - 1) + 8);
  v10 = nc_new_tensor_nz(v4, *(_DWORD *)(a1 + 48), v9, (__int64)v55);
  v11 = *(unsigned int *)(a1 + 48);
  v12 = dword_66A375E0[v11];
  v13 = *(_DWORD *)(a1 + 80);
  if ( nc_type_size_table[v11] != 4 || v13 )
  {
    if ( *(_BYTE *)(a1 + 72) )
    {
      if ( v13 > 0 )
      {
LABEL_13:
        v14 = *(_QWORD *)(a1 + 120);
        if ( !*((_BYTE *)v10 + 73) )
        {
          sub_66A33D40("y->contig[i]", "libnc.c", 5634);
          v13 = *(_DWORD *)(a1 + 80);
        }
        if ( v13 > 1 )
        {
          v14 *= *(_QWORD *)(a1 + 128);
          if ( !*((_BYTE *)v10 + 74) )
          {
            sub_66A33D40("y->contig[i]", "libnc.c", 5634);
            v13 = *(_DWORD *)(a1 + 80);
          }
          if ( v13 > 2 )
          {
            v14 *= *(_QWORD *)(a1 + 136);
            if ( !*((_BYTE *)v10 + 75) )
            {
              sub_66A33D40("y->contig[i]", "libnc.c", 5634);
              v13 = *(_DWORD *)(a1 + 80);
            }
            if ( v13 > 3 )
            {
              v14 *= *(_QWORD *)(a1 + 144);
              if ( !*((_BYTE *)v10 + 76) )
              {
                sub_66A33D40("y->contig[i]", "libnc.c", 5634);
                v13 = *(_DWORD *)(a1 + 80);
              }
            }
          }
        }
LABEL_24:
        v15 = sub_66A05420(
                (_DWORD *)&v53 + 1,
                v13,
                (__int64)v10,
                0i64,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55[0],
                v55[1],
                v55[2],
                v55[3],
                v56,
                v57,
                v58,
                v59,
                v60,
                v61);
        v16 = *((_DWORD *)v10 + 20);
        v56 = 0i64;
        v17 = (__int64 *)v15;
        if ( v16 <= 1 )
        {
          v19 = 0i64;
        }
        else
        {
          v18 = 1i64;
          do
            *(&v56 + v18++) = 0i64;
          while ( v16 > (int)v18 );
          v19 = v56;
        }
        v9 = (unsigned __int64)&v56;
        while ( v19 != -1 )
        {
          v20 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64 *, int))(v4 + 72);
          v21 = *(_QWORD *)(a1 + 56);
          v22 = v10[7];
          v23 = *((_DWORD *)v10 + 20);
          v24 = v10[*(int *)(a1 + 80) + 11] >> v12;
          if ( v23 <= 0 )
          {
            v25 = 0i64;
          }
          else
          {
            v25 = v10[11] * v19;
            if ( v23 != 1 )
            {
              v25 += v10[12] * v57;
              if ( v23 != 2 )
              {
                v25 += v10[13] * v58;
                if ( v23 != 3 )
                {
                  v26 = v59;
                  v3 = v10[14];
LABEL_35:
                  v25 += v3 * v26;
                }
              }
            }
          }
          v20(v4, v22 + v25, v24, v21, 0i64, v14, v17, v12);
          v27 = HIDWORD(v53);
          v28 = *((_DWORD *)v10 + 20);
          if ( SHIDWORD(v53) >= v28 )
            goto LABEL_41;
          v29 = (__int64 *)(v9 + 8i64 * SHIDWORD(v53));
          v30 = *v29 + 1;
          *v29 = v30;
          if ( v30 == v10[v27 + 15] )
          {
            v31 = &v10[v27 + 1];
            v32 = (unsigned int)(~v27 + v28);
            v33 = 0i64;
            do
            {
              v29[v33] = 0i64;
              if ( v33 == v32 )
                goto LABEL_41;
              v34 = v29[v33 + 1] + 1;
              v29[++v33] = v34;
            }
            while ( v34 == v31[v33 + 14] );
          }
          v19 = v56;
        }
        goto LABEL_42;
      }
    }
    else
    {
      sub_66A33D40("x->is_contiguous", "libnc.c", 5630);
      v13 = *(_DWORD *)(a1 + 80);
      if ( v13 > 0 )
        goto LABEL_13;
    }
    v14 = 1i64;
    goto LABEL_24;
  }
  v20 = (void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64 *, int))*((unsigned int *)v10
                                                                                                  + 20);
  if ( (int)v20 <= 0 )
  {
    HIDWORD(v53) = 0;
    v14 = 1i64;
    v39 = 0i64;
    v56 = 0i64;
    goto LABEL_61;
  }
  if ( *((_BYTE *)v10 + 73) )
  {
    v14 = v10[15];
    if ( (_DWORD)v20 != 1 )
    {
      if ( *((_BYTE *)v10 + 74) )
      {
        v14 *= v10[16];
        if ( (_DWORD)v20 == 2 )
        {
          v37 = 2;
          goto LABEL_56;
        }
        if ( *((_BYTE *)v10 + 75) )
        {
          v14 *= v10[17];
          if ( (_DWORD)v20 == 3 )
          {
            v37 = 3;
            goto LABEL_56;
          }
          if ( *((_BYTE *)v10 + 76) )
          {
            v14 *= v10[18];
            v37 = 4;
LABEL_56:
            v14 = (int)v14;
            goto LABEL_57;
          }
          v48 = 3;
        }
        else
        {
          v48 = 2;
        }
      }
      else
      {
        v48 = 1;
      }
      v14 = (int)v14;
      HIDWORD(v53) = v48;
      v56 = 0i64;
      goto LABEL_58;
    }
    v37 = 1;
    goto LABEL_56;
  }
  v14 = 1i64;
  v37 = 0;
LABEL_57:
  HIDWORD(v53) = v37;
  v56 = 0i64;
  if ( (int)v20 <= 1 )
  {
    v39 = 0i64;
    goto LABEL_61;
  }
LABEL_58:
  v38 = 1i64;
  do
    *(&v56 + v38++) = 0i64;
  while ( (int)v20 > (int)v38 );
  v39 = v56;
LABEL_61:
  v17 = &v56;
  while ( v39 != -1 )
  {
    v26 = *(_QWORD *)(v4 + 120);
    v21 = *(_QWORD *)(a1 + 56);
    v25 = v10[7];
    if ( (int)v20 <= 0 )
    {
      v40 = 0i64;
    }
    else
    {
      v40 = v10[11] * v39;
      if ( (_DWORD)v20 != 1 )
      {
        v40 += v10[12] * v57;
        if ( (_DWORD)v20 != 2 )
        {
          v40 += v10[13] * v58;
          if ( (_DWORD)v20 != 3 )
          {
            v22 = v59;
            v24 = v10[14];
            if ( (_DWORD)v20 != 4 )
              goto LABEL_35;
            v40 += v24 * v59;
          }
        }
      }
    }
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, int))v26)(
      v4,
      v40 + v25,
      0i64,
      v21,
      0i64,
      v14,
      1i64,
      v12);
    v41 = HIDWORD(v53);
    v20 = (void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64 *, int))*((unsigned int *)v10 + 20);
    if ( SHIDWORD(v53) >= (int)v20 )
      goto LABEL_41;
    v42 = &v56 + SHIDWORD(v53);
    v43 = *v42 + 1;
    *v42 = v43;
    if ( v43 == v10[v41 + 15] )
    {
      v44 = &v10[v41 + 1];
      v45 = (unsigned int)(~v41 + (_DWORD)v20);
      v46 = 0i64;
      while ( 1 )
      {
        v42[v46] = 0i64;
        if ( v45 == v46 )
          break;
        v47 = v42[v46 + 1] + 1;
        v42[++v46] = v47;
        if ( v47 != v44[v46 + 14] )
          goto LABEL_77;
      }
LABEL_41:
      v56 = -1i64;
      break;
    }
LABEL_77:
    v39 = v56;
  }
LABEL_42:
  v54 = a1;
  v35 = sub_66A15DA0(4, v10 + 3, (__int64 **)v10 + 4, 1, (__int64)&v54);
  if ( v35 )
    *((_DWORD *)v35 + 14) = *(_DWORD *)(a1 + 80);
  nc_free_tensor((_DWORD *)a1);
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

