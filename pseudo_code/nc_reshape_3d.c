// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reshape_3d
// Included functions: 4

// ======================================================
// Function: nc_reshape_3d @ 0x66A1C2C0
// ======================================================

_QWORD *__fastcall nc_reshape_3d(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r12
  int v6; // edx
  _QWORD *v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12; // r10
  __int64 v13; // rax
  __int64 v14; // r14
  unsigned __int64 v15; // r15
  void *(__cdecl *v16)(size_t, size_t); // rbp
  _QWORD *v17; // rdx
  int v18; // eax
  __int64 v19; // r9
  bool v20; // zf
  unsigned __int64 v21; // r15
  __int64 v22; // rax
  _QWORD *v23; // r15
  __int64 *v25; // rax
  __int64 v26; // r12
  __int64 *v27; // r13
  _QWORD *v28; // rsi
  _QWORD *v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 *v33; // rcx
  int v34; // eax
  __int64 v35; // r12
  unsigned int v36; // r11d
  __int64 v37; // r10
  _QWORD *v38; // rax
  __int64 v39; // r10
  __int64 v40; // rax
  __int64 v41; // rax
  __int64 v42; // rsi
  __int64 v43; // rsi
  __int64 *v44; // rdi
  _DWORD *v45; // r13
  __int64 v46; // rax
  __int64 v47; // rax
  __int64 v48; // rax
  __int64 v49; // rax
  int v50; // edx
  __int64 v51; // rax
  int v52; // ecx
  __int64 v53; // rax
  __int64 v54; // r13
  int v55; // eax
  __int64 v56; // rdx
  int v57; // ecx
  __int64 v58; // rdx
  __int64 v59; // rax
  int v60; // r8d
  __int64 v61; // rax
  __int64 v62; // rdi
  int v63; // r8d
  __int64 v64; // rax
  __int64 v65; // rdi
  __int64 v66; // rax
  int v67; // ecx
  __int64 v68; // rax
  __int64 v69; // rax
  __int64 v70; // r8
  __int64 v71; // r8
  int v72; // ecx
  __int64 v73; // rax
  __int64 v74; // rax
  __int64 v75; // rdi
  int v76; // r8d
  __int64 v77; // rax
  __int64 v78; // rdi
  int v79; // [rsp+28h] [rbp-C0h]
  __int64 v80; // [rsp+28h] [rbp-C0h]
  unsigned int v81; // [rsp+28h] [rbp-C0h]
  __int64 v82; // [rsp+30h] [rbp-B8h]
  unsigned int v83; // [rsp+30h] [rbp-B8h]
  __int64 v84; // [rsp+30h] [rbp-B8h]
  unsigned __int64 v85; // [rsp+38h] [rbp-B0h]
  __int64 v86; // [rsp+38h] [rbp-B0h]
  __int64 v87; // [rsp+38h] [rbp-B0h]
  __int64 v88; // [rsp+40h] [rbp-A8h]
  __int64 v89; // [rsp+48h] [rbp-A0h]
  __int64 v90; // [rsp+58h] [rbp-90h]
  __int64 v91; // [rsp+60h] [rbp-88h] BYREF
  __int64 v92; // [rsp+68h] [rbp-80h]
  __int64 v93; // [rsp+70h] [rbp-78h]
  __int64 v94; // [rsp+78h] [rbp-70h]
  __int64 v95; // [rsp+80h] [rbp-68h] BYREF
  __int64 v96; // [rsp+88h] [rbp-60h]
  __int64 v97; // [rsp+90h] [rbp-58h]
  __int64 v98; // [rsp+98h] [rbp-50h]

  v4 = *(_QWORD *)(a1 + 40);
  v6 = *(_DWORD *)(a1 + 80);
  if ( v6 <= 0 )
  {
    v11 = 1i64;
  }
  else
  {
    v9 = (_QWORD *)(a1 + 120);
    v10 = a1 + 8i64 * (unsigned int)(v6 - 1) + 128;
    v11 = 1i64;
    do
      v11 *= *v9++;
    while ( (_QWORD *)v10 != v9 );
  }
  if ( v11 != a2 * a4 * a3 )
    sub_66A16930("reshape", a1, 0i64);
  if ( !*(_BYTE *)(a1 + 72) )
  {
    v35 = *(_QWORD *)(v4 + 24);
    v36 = *(_DWORD *)(a1 + 48);
    v37 = *(_QWORD *)(v35 + 16);
    if ( v36 > 5 )
    {
      v87 = a4;
      v84 = *(_QWORD *)(v35 + 16);
      v81 = *(_DWORD *)(a1 + 48);
      sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
      a4 = v87;
      v37 = v84;
      v36 = v81;
    }
    v80 = v37;
    v16 = aligned_malloc;
    v86 = a4;
    v83 = v36;
    v38 = aligned_malloc(0x98ui64, 0x40ui64);
    v39 = v80;
    v23 = v38;
    if ( !v38 )
    {
LABEL_40:
      MEMORY[0x18] = v39;
      BUG();
    }
    memset(v38, 0, 0x98ui64);
    v38[3] = v80;
    *((_DWORD *)v38 + 12) = v83;
    v40 = nc_type_size_table[v83];
    v23[16] = a3;
    v23[15] = a2;
    v23[11] = v40;
    v41 = a2 * v40;
    v23[17] = v86;
    v23[8] = a2;
    v42 = v41 * a3;
    *((_BYTE *)v23 + 73) = 1;
    *((_BYTE *)v23 + 74) = 1;
    *((_BYTE *)v23 + 75) = 1;
    v23[13] = v42;
    v43 = v86 * v42;
    *((_BYTE *)v23 + 72) = 1;
    v44 = *(__int64 **)(v35 + 16);
    *((_DWORD *)v23 + 4) = 1;
    *((_DWORD *)v23 + 20) = 3;
    v23[12] = v41;
    v45 = aligned_malloc(0x38ui64, 0x40ui64);
    v45[4] = 1;
    *((_QWORD *)v45 + 3) = v35;
    v46 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(v35 + 48))(v35, v45 + 10, v43);
    v39 = v80;
    *((_QWORD *)v45 + 4) = v46;
    if ( !v46 )
      nc_error("not enough device memory");
    v47 = *v44;
    *((_QWORD *)v45 + 6) = v43;
    *(_QWORD *)(v47 + 8) = v45;
    *(_QWORD *)v45 = v47;
    v48 = *((_QWORD *)v45 + 5);
    *((_QWORD *)v45 + 1) = v44;
    *v44 = (__int64)v45;
    v23[7] = v48;
    v49 = *(_QWORD *)(v80 + 16);
    v23[5] = v45;
    *(_QWORD *)(v49 + 8) = v23;
    *v23 = v49;
    v23[1] = v80 + 16;
    *(_QWORD *)(v80 + 16) = v23;
    if ( *(_BYTE *)(a1 + 72) && *((_BYTE *)v23 + 72) )
      goto LABEL_67;
    if ( *(_QWORD *)(a1 + 120) != v23[15] )
    {
      v50 = *(_DWORD *)(a1 + 80);
      v51 = 1i64;
      v95 = 0i64;
      if ( v50 > 1 )
      {
        do
          *(&v95 + v51++) = 0i64;
        while ( v50 > (int)v51 );
      }
      v52 = *((_DWORD *)v23 + 20);
      v53 = 1i64;
      v54 = 0i64;
      v91 = 0i64;
      if ( v52 > 1 )
      {
        do
          *(&v91 + v53++) = 0i64;
        while ( v52 > (int)v53 );
        v54 = v91;
      }
      while ( 1 )
      {
        if ( v54 == -1 )
          goto LABEL_8;
        v55 = *((_DWORD *)v23 + 20);
        if ( v55 <= 0 )
        {
          v56 = 0i64;
        }
        else
        {
          v56 = v23[11] * v54;
          if ( v55 != 1 )
          {
            v56 += v23[12] * v92;
            if ( v55 != 2 )
            {
              v56 += v23[13] * v93;
              if ( v55 != 3 )
              {
                if ( v55 != 4 )
                  goto LABEL_40;
                v56 += v23[14] * v94;
              }
            }
          }
        }
        v57 = *(_DWORD *)(a1 + 80);
        v58 = v23[7] + v56;
        v39 = *(_QWORD *)(a1 + 56);
        if ( v57 <= 0 )
        {
          v59 = 0i64;
        }
        else
        {
          v59 = *(_QWORD *)(a1 + 88) * v95;
          if ( v57 != 1 )
          {
            v59 += *(_QWORD *)(a1 + 96) * v96;
            if ( v57 != 2 )
            {
              v59 += *(_QWORD *)(a1 + 104) * v97;
              if ( v57 != 3 )
              {
                if ( v57 != 4 )
                  goto LABEL_40;
                v59 += *(_QWORD *)(a1 + 112) * v98;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v35 + 64))(
          v35,
          v58,
          v39 + v59,
          nc_type_size_table[*((unsigned int *)v23 + 12)]);
        v60 = *(_DWORD *)(a1 + 80);
        if ( v60 > 0 )
        {
          if ( ++v95 != *(_QWORD *)(a1 + 120) )
            goto LABEL_55;
          v61 = 1i64;
          while ( 1 )
          {
            *(&v95 + v61 - 1) = 0i64;
            if ( v60 <= (int)v61 )
              break;
            v62 = *(&v95 + v61);
            *(&v95 + v61++) = v62 + 1;
            if ( v62 + 1 != *(_QWORD *)(a1 + 8 * v61 + 112) )
              goto LABEL_55;
          }
        }
        v95 = -1i64;
LABEL_55:
        v63 = *((_DWORD *)v23 + 20);
        if ( v63 <= 0 )
          goto LABEL_60;
        v91 = ++v54;
        if ( v23[15] == v54 )
        {
          v64 = 1i64;
          do
          {
            *(&v91 + v64 - 1) = 0i64;
            if ( v63 <= (int)v64 )
              goto LABEL_60;
            v65 = *(&v91 + v64);
            *(&v91 + v64++) = v65 + 1;
          }
          while ( v65 + 1 == v23[v64 + 14] );
          v54 = v91;
        }
      }
    }
    v39 = *(unsigned int *)(a1 + 80);
    if ( (int)v39 <= 1
      || *(_BYTE *)(a1 + 74) && ((_DWORD)v39 == 2 || *(_BYTE *)(a1 + 75) && ((_DWORD)v39 == 3 || *(_BYTE *)(a1 + 76))) )
    {
LABEL_67:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64))(v35 + 64))(v35, v23[7], *(_QWORD *)(a1 + 56), v43);
      goto LABEL_8;
    }
    v66 = 1i64;
    v95 = 0i64;
    do
      *(&v95 + v66++) = 0i64;
    while ( (int)v39 > (int)v66 );
    v91 = 0i64;
    v67 = *((_DWORD *)v23 + 20);
    if ( v67 <= 1 )
    {
      v69 = 0i64;
    }
    else
    {
      v68 = 1i64;
      do
        *(&v91 + v68++) = 0i64;
      while ( v67 > (int)v68 );
      v69 = v91;
    }
    while ( 1 )
    {
      if ( v69 == -1 )
        goto LABEL_8;
      if ( (int)v39 <= 0 )
      {
        v70 = 0i64;
      }
      else
      {
        v70 = *(_QWORD *)(a1 + 88) * v95;
        if ( (_DWORD)v39 != 1 )
        {
          v70 += *(_QWORD *)(a1 + 96) * v96;
          if ( (_DWORD)v39 != 2 )
          {
            v70 += *(_QWORD *)(a1 + 104) * v97;
            if ( (_DWORD)v39 != 3 )
            {
              if ( (_DWORD)v39 != 4 )
                goto LABEL_40;
              v70 += *(_QWORD *)(a1 + 112) * v98;
            }
          }
        }
      }
      v71 = *(_QWORD *)(a1 + 56) + v70;
      v72 = *((_DWORD *)v23 + 20);
      v39 = v23[7];
      if ( v72 <= 0 )
      {
        v73 = 0i64;
      }
      else
      {
        v73 = v23[11] * v69;
        if ( v72 != 1 )
        {
          v73 += v23[12] * v92;
          if ( v72 != 2 )
          {
            v73 += v23[13] * v93;
            if ( v72 != 3 )
            {
              if ( v72 != 4 )
                goto LABEL_40;
              v73 += v23[14] * v94;
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v35 + 64))(
        v35,
        v39 + v73,
        v71,
        *(_QWORD *)(a1 + 120) * nc_type_size_table[*(unsigned int *)(a1 + 48)]);
      v39 = *(unsigned int *)(a1 + 80);
      if ( (int)v39 <= 1 )
        goto LABEL_96;
      v74 = 2i64;
      if ( *(_QWORD *)(a1 + 128) == ++v96 )
        break;
LABEL_97:
      v76 = *((_DWORD *)v23 + 20);
      if ( v76 <= 1 )
        goto LABEL_60;
      v77 = 2i64;
      if ( ++v92 == v23[16] )
      {
        while ( 1 )
        {
          *(&v91 + v77 - 1) = 0i64;
          if ( v76 <= (int)v77 )
            break;
          v78 = *(&v91 + v77);
          *(&v91 + v77++) = v78 + 1;
          if ( v78 + 1 != v23[v77 + 14] )
            goto LABEL_104;
        }
LABEL_60:
        v91 = -1i64;
        goto LABEL_8;
      }
LABEL_104:
      v69 = v91;
    }
    while ( 1 )
    {
      *(&v95 + v74 - 1) = 0i64;
      if ( (int)v39 <= (int)v74 )
        break;
      v75 = *(&v95 + v74);
      *(&v95 + v74++) = v75 + 1;
      if ( v75 + 1 != *(_QWORD *)(a1 + 8 * v74 + 112) )
        goto LABEL_97;
    }
LABEL_96:
    v95 = -1i64;
    goto LABEL_97;
  }
  v12 = *(unsigned int *)(a1 + 48);
  v13 = *(_QWORD *)(a1 + 56) - *(_QWORD *)(v4 + 40);
  v90 = a4;
  v79 = v12;
  v14 = *(_QWORD *)(a1 + 24);
  v15 = nc_type_size_table[v12] * a2;
  v89 = v12;
  v16 = aligned_malloc;
  v88 = nc_type_size_table[v12];
  v82 = v13;
  v85 = v15 * a3;
  v17 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v17 )
  {
    MEMORY[0x18] = v14;
    BUG();
  }
  memset(v17, 0, 0x98ui64);
  v18 = dword_66A375E0[v89];
  v17[3] = v14;
  v19 = v90;
  *((_DWORD *)v17 + 12) = v79;
  *((_DWORD *)v17 + 4) = 1;
  *((_DWORD *)v17 + 20) = 3;
  ++*(_DWORD *)(v4 + 16);
  v20 = nc_type_size_table[v89] == v88;
  v17[12] = v15;
  v21 = v15 >> v18;
  *((_BYTE *)v17 + 73) = v20;
  *((_BYTE *)v17 + 72) = v20;
  *((_BYTE *)v17 + 74) = 1;
  *((_BYTE *)v17 + 75) = 1;
  v17[7] = *(_QWORD *)(v4 + 40) + v82;
  v22 = *(_QWORD *)(v14 + 16);
  v17[8] = v21;
  v23 = v17;
  v17[5] = v4;
  v17[15] = a2;
  v17[11] = v88;
  v17[16] = a3;
  v17[17] = v19;
  v17[13] = v85;
  *(_QWORD *)(v22 + 8) = v17;
  *v17 = v22;
  v17[1] = v14 + 16;
  *(_QWORD *)(v14 + 16) = v17;
LABEL_8:
  if ( *(_QWORD *)(a1 + 32) )
  {
    v25 = (__int64 *)v16(8ui64, 0x40ui64);
    v26 = v23[3];
    v27 = v25;
    *v25 = *(_QWORD *)(a1 + 32);
    v28 = v16(0x80ui64, 0x40ui64);
    if ( !v28 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v28, 0, 0x80ui64);
    *((_DWORD *)v28 + 4) = 1;
    *((_DWORD *)v28 + 5) = 3;
    *((_DWORD *)v28 + 6) = 1;
    v29 = v16(8ui64, 0x40ui64);
    v30 = *v27;
    v28[4] = v29;
    if ( v30 )
    {
      ++*(_DWORD *)(v30 + 16);
      *v29 = v30;
    }
    else
    {
      *v29 = 0i64;
    }
    v31 = *(_QWORD *)(v26 + 72);
    *(_QWORD *)(v26 + 72) = v31 + 1;
    v28[12] = v31;
    v32 = *(_QWORD *)(v26 + 32);
    *(_QWORD *)(v32 + 8) = v28;
    *v28 = v32;
    v28[1] = v26 + 32;
    *(_QWORD *)(v26 + 32) = v28;
    _aligned_free(v27);
    v33 = (__int64 *)v23[4];
    if ( v33 )
      nc_free_node(v33);
    v34 = *(_DWORD *)(a1 + 80);
    v23[4] = v28;
    *((_DWORD *)v28 + 14) = v34;
    if ( v34 > 0 )
    {
      v28[8] = *(_QWORD *)(a1 + 120);
      if ( v34 != 1 )
      {
        v28[9] = *(_QWORD *)(a1 + 128);
        if ( v34 != 2 )
        {
          v28[10] = *(_QWORD *)(a1 + 136);
          if ( v34 != 3 )
            v28[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  nc_free_tensor((_DWORD *)a1);
  return v23;
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

