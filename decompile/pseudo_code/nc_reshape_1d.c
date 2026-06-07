// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reshape_1d
// Included functions: 5

// ======================================================
// Function: nc_reshape_1d @ 0x66A1B360
// ======================================================

_QWORD *__fastcall nc_reshape_1d(__int64 a1, __int64 a2)
{
  __int64 v2; // rsi
  int v4; // ecx
  _QWORD *v5; // rax
  __int64 v6; // r8
  __int64 v7; // rcx
  __int64 v8; // r13
  __int64 v9; // rbp
  __int64 v10; // r14
  _QWORD *v11; // rbx
  __int64 v12; // rax
  bool v13; // zf
  __int64 v14; // rax
  __int64 *v16; // rax
  __int64 v17; // rbp
  __int64 *v18; // r14
  _QWORD *v19; // rsi
  _QWORD *v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 *v24; // rcx
  int v25; // eax
  _QWORD *v26; // rax
  int v27; // edx
  __int64 v28; // rax
  int v29; // edx
  __int64 v30; // rax
  __int64 v31; // r14
  int v32; // eax
  int v33; // ecx
  __int64 v34; // rax
  int v35; // ecx
  __int64 v36; // rax
  __int64 v37; // rdx
  int v38; // r8d
  __int64 v39; // rax
  __int64 v40; // rdx
  int v41; // r10d
  __int64 v42; // rax
  int v43; // edx
  __int64 v44; // rax
  __int64 v45; // r8
  int v46; // eax
  __int64 v47; // r8
  __int64 v48; // rax
  __int64 v49; // rdx
  int v50; // r8d
  __int64 v51; // rax
  __int64 v52; // rdx
  int v53; // [rsp+2Ch] [rbp-9Ch]
  __int64 v54; // [rsp+30h] [rbp-98h] BYREF
  __int64 v55; // [rsp+40h] [rbp-88h] BYREF
  __int64 v56; // [rsp+48h] [rbp-80h]
  __int64 v57; // [rsp+50h] [rbp-78h]
  __int64 v58; // [rsp+58h] [rbp-70h]
  __int64 v59; // [rsp+60h] [rbp-68h] BYREF
  __int64 v60; // [rsp+68h] [rbp-60h]
  __int64 v61; // [rsp+70h] [rbp-58h]
  __int64 v62; // [rsp+78h] [rbp-50h]

  v2 = *(_QWORD *)(a1 + 40);
  v4 = *(_DWORD *)(a1 + 80);
  v54 = a2;
  if ( v4 <= 0 )
  {
LABEL_36:
    v7 = 1i64;
  }
  else
  {
    v5 = (_QWORD *)(a1 + 120);
    v6 = a1 + 8i64 * (unsigned int)(v4 - 1) + 128;
    v7 = 1i64;
    do
      v7 *= *v5++;
    while ( (_QWORD *)v6 != v5 );
  }
  if ( a2 != v7 )
    sub_66A16930("reshape", a1, 0i64);
  if ( !*(_BYTE *)(a1 + 72) )
  {
    v2 = *(_QWORD *)(v2 + 24);
    v26 = sub_66A137B0(v2, *(_DWORD *)(a1 + 48), &v54);
    v11 = v26;
    if ( *(_BYTE *)(a1 + 72) && *((_BYTE *)v26 + 72) )
      goto LABEL_62;
    if ( *(_QWORD *)(a1 + 120) != v26[15] )
    {
      v27 = *(_DWORD *)(a1 + 80);
      v28 = 1i64;
      v59 = 0i64;
      if ( v27 > 1 )
      {
        do
          *(&v59 + v28++) = 0i64;
        while ( v27 > (int)v28 );
      }
      v29 = *((_DWORD *)v11 + 20);
      v30 = 1i64;
      v31 = 0i64;
      v55 = 0i64;
      if ( v29 > 1 )
      {
        do
          *(&v55 + v30++) = 0i64;
        while ( v29 > (int)v30 );
        v31 = v55;
      }
      while ( 1 )
      {
LABEL_30:
        if ( v31 == -1 )
          goto LABEL_8;
        v32 = *((_DWORD *)v11 + 20);
        if ( v32 <= 0 )
        {
          a2 = 0i64;
        }
        else
        {
          a2 = v11[11] * v31;
          if ( v32 != 1 )
          {
            a2 += v11[12] * v56;
            if ( v32 != 2 )
            {
              a2 += v11[13] * v57;
              if ( v32 != 3 )
              {
                if ( v32 != 4 )
                  goto LABEL_36;
                a2 += v11[14] * v58;
              }
            }
          }
        }
        v33 = *(_DWORD *)(a1 + 80);
        a2 += v11[7];
        if ( v33 <= 0 )
        {
          v34 = 0i64;
        }
        else
        {
          v34 = *(_QWORD *)(a1 + 88) * v59;
          if ( v33 != 1 )
          {
            v34 += *(_QWORD *)(a1 + 96) * v60;
            if ( v33 != 2 )
            {
              v34 += *(_QWORD *)(a1 + 104) * v61;
              if ( v33 != 3 )
              {
                if ( v33 != 4 )
                  goto LABEL_36;
                v34 += *(_QWORD *)(a1 + 112) * v62;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v2 + 64))(
          v2,
          a2,
          *(_QWORD *)(a1 + 56) + v34,
          nc_type_size_table[*((unsigned int *)v11 + 12)]);
        v35 = *(_DWORD *)(a1 + 80);
        if ( v35 <= 0 )
          goto LABEL_49;
        if ( *(_QWORD *)(a1 + 120) == ++v59 )
          break;
LABEL_50:
        v38 = *((_DWORD *)v11 + 20);
        if ( v38 <= 0 )
          goto LABEL_55;
        v55 = ++v31;
        if ( v11[15] == v31 )
        {
          v39 = 1i64;
          while ( 1 )
          {
            *(&v55 + v39 - 1) = 0i64;
            if ( v38 <= (int)v39 )
              goto LABEL_55;
            v40 = *(&v55 + v39) + 1;
            *(&v55 + v39++) = v40;
            if ( v40 != v11[v39 + 14] )
            {
              v31 = v55;
              goto LABEL_30;
            }
          }
        }
      }
      v36 = 1i64;
      while ( 1 )
      {
        *(&v59 + v36 - 1) = 0i64;
        if ( v35 <= (int)v36 )
          break;
        v37 = *(&v59 + v36) + 1;
        *(&v59 + v36++) = v37;
        if ( v37 != *(_QWORD *)(a1 + 8 * v36 + 112) )
          goto LABEL_50;
      }
LABEL_49:
      v59 = -1i64;
      goto LABEL_50;
    }
    v41 = *(_DWORD *)(a1 + 80);
    if ( v41 <= 1 || *(_BYTE *)(a1 + 74) && (v41 == 2 || *(_BYTE *)(a1 + 75) && (v41 == 3 || *(_BYTE *)(a1 + 76))) )
    {
LABEL_62:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))(v2 + 64))(
        v2,
        v26[7],
        *(_QWORD *)(a1 + 56),
        *(_QWORD *)(v26[5] + 48i64));
      goto LABEL_8;
    }
    v59 = 0i64;
    v42 = 1i64;
    do
      *(&v59 + v42++) = 0i64;
    while ( v41 > (int)v42 );
    v55 = 0i64;
    v43 = *((_DWORD *)v11 + 20);
    if ( v43 <= 1 )
    {
      a2 = 0i64;
    }
    else
    {
      v44 = 1i64;
      do
        *(&v55 + v44++) = 0i64;
      while ( v43 > (int)v44 );
      a2 = v55;
    }
    while ( 1 )
    {
      if ( a2 == -1 )
        goto LABEL_8;
      if ( v41 <= 0 )
      {
        v45 = 0i64;
      }
      else
      {
        v45 = *(_QWORD *)(a1 + 88) * v59;
        if ( v41 != 1 )
        {
          v45 += *(_QWORD *)(a1 + 96) * v60;
          if ( v41 != 2 )
          {
            v45 += *(_QWORD *)(a1 + 104) * v61;
            if ( v41 != 3 )
            {
              if ( v41 != 4 )
                goto LABEL_36;
              v45 += *(_QWORD *)(a1 + 112) * v62;
            }
          }
        }
      }
      v46 = *((_DWORD *)v11 + 20);
      v47 = *(_QWORD *)(a1 + 56) + v45;
      if ( v46 <= 0 )
      {
        a2 = 0i64;
      }
      else
      {
        a2 *= v11[11];
        if ( v46 != 1 )
        {
          a2 += v11[12] * v56;
          if ( v46 != 2 )
          {
            a2 += v11[13] * v57;
            if ( v46 != 3 )
            {
              if ( v46 != 4 )
                goto LABEL_36;
              a2 += v11[14] * v58;
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v2 + 64))(
        v2,
        v11[7] + a2,
        v47,
        *(_QWORD *)(a1 + 120) * nc_type_size_table[*(unsigned int *)(a1 + 48)]);
      v41 = *(_DWORD *)(a1 + 80);
      if ( v41 <= 1 )
        goto LABEL_91;
      v48 = 2i64;
      if ( *(_QWORD *)(a1 + 128) == ++v60 )
        break;
LABEL_92:
      v50 = *((_DWORD *)v11 + 20);
      if ( v50 <= 1 )
        goto LABEL_55;
      v51 = 2i64;
      if ( ++v56 == v11[16] )
      {
        while ( 1 )
        {
          *(&v55 + v51 - 1) = 0i64;
          if ( v50 <= (int)v51 )
            break;
          v52 = *(&v55 + v51) + 1;
          *(&v55 + v51++) = v52;
          if ( v52 != v11[v51 + 14] )
            goto LABEL_99;
        }
LABEL_55:
        v55 = -1i64;
        goto LABEL_8;
      }
LABEL_99:
      a2 = v55;
    }
    while ( 1 )
    {
      *(&v59 + v48 - 1) = 0i64;
      if ( v41 <= (int)v48 )
        break;
      v49 = *(&v59 + v48) + 1;
      *(&v59 + v48++) = v49;
      if ( v49 != *(_QWORD *)(a1 + 8 * v48 + 112) )
        goto LABEL_92;
    }
LABEL_91:
    v59 = -1i64;
    goto LABEL_92;
  }
  v8 = *(_QWORD *)(a1 + 56) - *(_QWORD *)(v2 + 40);
  v9 = *(_QWORD *)(a1 + 24);
  v53 = *(_DWORD *)(a1 + 48);
  v10 = nc_type_size_table[v53];
  v11 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v11 )
  {
    MEMORY[0x18] = v9;
    BUG();
  }
  memset(v11, 0, 0x98ui64);
  v11[3] = v9;
  *((_DWORD *)v11 + 4) = 1;
  v12 = v54;
  *((_DWORD *)v11 + 12) = v53;
  *((_DWORD *)v11 + 20) = 1;
  ++*(_DWORD *)(v2 + 16);
  v13 = nc_type_size_table[v53] == v10;
  v11[15] = v12;
  v11[8] = v12;
  *((_BYTE *)v11 + 73) = v13;
  *((_BYTE *)v11 + 72) = v13;
  v11[7] = *(_QWORD *)(v2 + 40) + v8;
  v14 = *(_QWORD *)(v9 + 16);
  v11[5] = v2;
  v11[11] = v10;
  *(_QWORD *)(v14 + 8) = v11;
  *v11 = v14;
  v11[1] = v9 + 16;
  *(_QWORD *)(v9 + 16) = v11;
LABEL_8:
  if ( *(_QWORD *)(a1 + 32) )
  {
    v16 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v17 = v11[3];
    v18 = v16;
    *v16 = *(_QWORD *)(a1 + 32);
    v19 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v19 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v19, 0, 0x80ui64);
    *((_DWORD *)v19 + 4) = 1;
    *((_DWORD *)v19 + 5) = 3;
    *((_DWORD *)v19 + 6) = 1;
    v20 = aligned_malloc(8ui64, 0x40ui64);
    v21 = *v18;
    v19[4] = v20;
    if ( v21 )
    {
      ++*(_DWORD *)(v21 + 16);
      *v20 = v21;
    }
    else
    {
      *v20 = 0i64;
    }
    v22 = *(_QWORD *)(v17 + 72);
    *(_QWORD *)(v17 + 72) = v22 + 1;
    v19[12] = v22;
    v23 = *(_QWORD *)(v17 + 32);
    *(_QWORD *)(v23 + 8) = v19;
    *v19 = v23;
    v19[1] = v17 + 32;
    *(_QWORD *)(v17 + 32) = v19;
    _aligned_free(v18);
    v24 = (__int64 *)v11[4];
    if ( v24 )
      nc_free_node(v24);
    v25 = *(_DWORD *)(a1 + 80);
    v11[4] = v19;
    *((_DWORD *)v19 + 14) = v25;
    if ( v25 > 0 )
    {
      v19[8] = *(_QWORD *)(a1 + 120);
      if ( v25 != 1 )
      {
        v19[9] = *(_QWORD *)(a1 + 128);
        if ( v25 != 2 )
        {
          v19[10] = *(_QWORD *)(a1 + 136);
          if ( v25 != 3 )
            v19[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  nc_free_tensor((_DWORD *)a1);
  return v11;
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
// Function: sub_66A137B0 @ 0x66A137B0
// ======================================================

_QWORD *__fastcall sub_66A137B0(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 v3; // r12
  __int64 v4; // rsi
  _QWORD *v7; // rbx
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 *v10; // rdi
  __int64 v11; // r13
  _DWORD *v12; // rsi
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  _QWORD *result; // rax

  v3 = *(_QWORD *)(a1 + 16);
  v4 = a2;
  if ( a2 > 5 )
    sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
  v7 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v7 )
  {
    MEMORY[0x18] = v3;
    BUG();
  }
  memset(v7, 0, 0x98ui64);
  *((_DWORD *)v7 + 12) = v4;
  v7[3] = v3;
  v8 = nc_type_size_table[v4];
  v9 = *a3;
  *((_DWORD *)v7 + 4) = 1;
  *((_BYTE *)v7 + 73) = 1;
  v7[11] = v8;
  *((_BYTE *)v7 + 72) = 1;
  v10 = *(__int64 **)(a1 + 16);
  *((_DWORD *)v7 + 20) = 1;
  v11 = v9 * v8;
  v7[15] = v9;
  v7[8] = v9;
  v12 = aligned_malloc(0x38ui64, 0x40ui64);
  v12[4] = 1;
  *((_QWORD *)v12 + 3) = a1;
  v13 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v12 + 10, v11);
  *((_QWORD *)v12 + 4) = v13;
  if ( !v13 )
    nc_error("not enough device memory");
  v14 = *v10;
  *((_QWORD *)v12 + 6) = v11;
  *(_QWORD *)(v14 + 8) = v12;
  *(_QWORD *)v12 = v14;
  v15 = *((_QWORD *)v12 + 5);
  *((_QWORD *)v12 + 1) = v10;
  *v10 = (__int64)v12;
  v7[7] = v15;
  v16 = *(_QWORD *)(v3 + 16);
  v7[5] = v12;
  *(_QWORD *)(v16 + 8) = v7;
  *v7 = v16;
  v7[1] = v3 + 16;
  result = v7;
  *(_QWORD *)(v3 + 16) = v7;
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

