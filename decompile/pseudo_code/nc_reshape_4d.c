// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reshape_4d
// Included functions: 4

// ======================================================
// Function: nc_reshape_4d @ 0x66A1CC40
// ======================================================

_QWORD *__fastcall nc_reshape_4d(__int64 a1, __int64 _RDX, __int64 a3, __int64 _R9, __int64 a5)
{
  __int64 v5; // r11
  __int64 v6; // r13
  __int64 v8; // r12
  int v10; // edx
  _QWORD *v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rdx
  void *(__cdecl *v19)(size_t, size_t); // r14
  __int64 v23; // r12
  __int64 v25; // rbp
  _QWORD *v27; // rbx
  __int64 v28; // r10
  unsigned __int64 v29; // rdx
  __int64 v30; // rcx
  bool v31; // zf
  bool v32; // r8
  __int64 v33; // rdx
  __int64 v34; // rax
  __int64 *v36; // rax
  __int64 v37; // r12
  __int64 *v38; // r13
  _QWORD *v39; // rbp
  _QWORD *v40; // rax
  __int64 v41; // rdx
  __int64 v42; // rax
  __int64 v43; // rax
  __int64 *v44; // rcx
  int v45; // eax
  __int64 v46; // r13
  unsigned int v47; // r10d
  __int64 v48; // r15
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rbp
  __int64 *v52; // r9
  __int64 v53; // rbp
  _DWORD *v54; // r12
  __int64 v55; // rax
  __int64 v56; // rdx
  __int64 v57; // r8
  __int64 v58; // rax
  __int64 v59; // rax
  __int64 v60; // rax
  int v61; // edx
  __int64 v62; // rax
  int v63; // edx
  __int64 v64; // rax
  int v65; // eax
  __int64 v66; // rdx
  int v67; // ecx
  __int64 v68; // rdx
  __int64 v69; // rax
  int v70; // ecx
  __int64 v71; // rax
  __int64 v72; // rdx
  int v73; // r8d
  __int64 v74; // rax
  __int64 v75; // rdx
  int v76; // r10d
  __int64 v77; // rax
  int v78; // edx
  __int64 v79; // rax
  __int64 v80; // rdx
  __int64 v81; // r8
  int v82; // ecx
  __int64 v83; // r8
  __int64 v84; // rdx
  __int64 v85; // rax
  __int64 v86; // rdx
  int v87; // r8d
  __int64 v88; // rax
  __int64 v89; // rdx
  __int64 *v90; // [rsp+28h] [rbp-E0h]
  unsigned int v91; // [rsp+28h] [rbp-E0h]
  __int64 *v92; // [rsp+28h] [rbp-E0h]
  unsigned int v93; // [rsp+28h] [rbp-E0h]
  int v94; // [rsp+30h] [rbp-D8h]
  __int64 v95; // [rsp+30h] [rbp-D8h]
  __int64 v96; // [rsp+30h] [rbp-D8h]
  __int64 v97; // [rsp+38h] [rbp-D0h]
  __int128 v98; // [rsp+40h] [rbp-C8h]
  __int128 v99; // [rsp+50h] [rbp-B8h]
  __int64 v100; // [rsp+60h] [rbp-A8h] BYREF
  __int64 v101; // [rsp+68h] [rbp-A0h]
  __int64 v102; // [rsp+70h] [rbp-98h]
  __int64 v103; // [rsp+78h] [rbp-90h]
  __int64 v104; // [rsp+80h] [rbp-88h] BYREF
  __int64 v105; // [rsp+88h] [rbp-80h]
  __int64 v106; // [rsp+90h] [rbp-78h]
  __int64 v107; // [rsp+98h] [rbp-70h]
  __int128 v108; // [rsp+A0h] [rbp-68h]
  __int128 v109; // [rsp+B0h] [rbp-58h]

  v5 = a5;
  v6 = *(_QWORD *)(a1 + 40);
  __asm { vmovq   xmm1, rdx }
  v8 = _RDX;
  __asm { vmovq   xmm2, r9 }
  v10 = *(_DWORD *)(a1 + 80);
  __asm
  {
    vpinsrq xmm0, xmm1, r8, 1
    vmovaps [rsp+108h+var_C8], xmm0
    vpinsrq xmm0, xmm2, r11, 1
    vmovaps [rsp+108h+var_B8], xmm0
  }
  if ( v10 <= 0 )
  {
    v17 = 1i64;
  }
  else
  {
    v15 = (_QWORD *)(a1 + 120);
    v16 = a1 + 8i64 * (unsigned int)(v10 - 1) + 128;
    v17 = 1i64;
    do
      v17 *= *v15++;
    while ( v15 != (_QWORD *)v16 );
  }
  if ( v17 != v8 * a3 * a5 * _R9 )
    sub_66A16930("reshape", a1, 0i64);
  if ( !*(_BYTE *)(a1 + 72) )
  {
    v46 = *(_QWORD *)(v6 + 24);
    v47 = *(_DWORD *)(a1 + 48);
    v48 = *(_QWORD *)(v46 + 16);
    if ( v47 > 5 )
    {
      v96 = _R9;
      v93 = *(_DWORD *)(a1 + 48);
      sub_66A33D40("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 3865);
      v5 = a5;
      _R9 = v96;
      v47 = v93;
    }
    v97 = v5;
    v19 = aligned_malloc;
    v95 = _R9;
    v91 = v47;
    v27 = aligned_malloc(0x98ui64, 0x40ui64);
    if ( !v27 )
    {
LABEL_40:
      MEMORY[0x18] = v48;
      BUG();
    }
    memset(v27, 0, 0x98ui64);
    *((_BYTE *)v27 + 73) = 1;
    v27[16] = a3;
    v27[17] = v95;
    v27[18] = v97;
    *((_BYTE *)v27 + 74) = 1;
    v49 = nc_type_size_table[v91];
    *((_BYTE *)v27 + 75) = 1;
    *((_BYTE *)v27 + 76) = 1;
    v27[11] = v49;
    v50 = v8 * v49;
    *((_BYTE *)v27 + 72) = 1;
    *((_DWORD *)v27 + 12) = v91;
    v51 = v50 * a3;
    v27[15] = v8;
    v27[8] = v8;
    v27[3] = v48;
    v27[13] = v51;
    *((_DWORD *)v27 + 4) = 1;
    *((_DWORD *)v27 + 20) = 4;
    v27[14] = v51 * v95;
    v52 = *(__int64 **)(v46 + 16);
    v27[12] = v50;
    v92 = v52;
    v53 = v51 * v95 * v97;
    v54 = aligned_malloc(0x38ui64, 0x40ui64);
    v54[4] = 1;
    *((_QWORD *)v54 + 3) = v46;
    v55 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(v46 + 48))(v46, v54 + 10, v53);
    *((_QWORD *)v54 + 4) = v55;
    if ( !v55 )
      nc_error("not enough device memory", v56, v57, v92);
    v58 = *v92;
    *((_QWORD *)v54 + 6) = v53;
    *(_QWORD *)(v58 + 8) = v54;
    *(_QWORD *)v54 = v58;
    v59 = *((_QWORD *)v54 + 5);
    *((_QWORD *)v54 + 1) = v92;
    *v92 = (__int64)v54;
    v27[7] = v59;
    v60 = *(_QWORD *)(v48 + 16);
    v27[5] = v54;
    *(_QWORD *)(v60 + 8) = v27;
    *v27 = v60;
    v27[1] = v48 + 16;
    *(_QWORD *)(v48 + 16) = v27;
    if ( *(_BYTE *)(a1 + 72) && *((_BYTE *)v27 + 72) )
      goto LABEL_67;
    if ( *(_QWORD *)(a1 + 120) != v27[15] )
    {
      v61 = *(_DWORD *)(a1 + 80);
      v62 = 1i64;
      v104 = 0i64;
      if ( v61 > 1 )
      {
        do
          *(&v104 + v62++) = 0i64;
        while ( v61 > (int)v62 );
      }
      v63 = *((_DWORD *)v27 + 20);
      v64 = 1i64;
      v48 = 0i64;
      v100 = 0i64;
      if ( v63 > 1 )
      {
        do
          *(&v100 + v64++) = 0i64;
        while ( v63 > (int)v64 );
        v48 = v100;
      }
      while ( 1 )
      {
        if ( v48 == -1 )
          goto LABEL_8;
        v65 = *((_DWORD *)v27 + 20);
        if ( v65 <= 0 )
        {
          v66 = 0i64;
        }
        else
        {
          v66 = v27[11] * v48;
          if ( v65 != 1 )
          {
            v66 += v27[12] * v101;
            if ( v65 != 2 )
            {
              v66 += v27[13] * v102;
              if ( v65 != 3 )
              {
                if ( v65 != 4 )
                  goto LABEL_40;
                v66 += v27[14] * v103;
              }
            }
          }
        }
        v67 = *(_DWORD *)(a1 + 80);
        v68 = v27[7] + v66;
        if ( v67 <= 0 )
        {
          v69 = 0i64;
        }
        else
        {
          v69 = *(_QWORD *)(a1 + 88) * v104;
          if ( v67 != 1 )
          {
            v69 += *(_QWORD *)(a1 + 96) * v105;
            if ( v67 != 2 )
            {
              v69 += *(_QWORD *)(a1 + 104) * v106;
              if ( v67 != 3 )
              {
                if ( v67 != 4 )
                  goto LABEL_40;
                v69 += *(_QWORD *)(a1 + 112) * v107;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v46 + 64))(
          v46,
          v68,
          *(_QWORD *)(a1 + 56) + v69,
          nc_type_size_table[*((unsigned int *)v27 + 12)]);
        v70 = *(_DWORD *)(a1 + 80);
        if ( v70 > 0 )
        {
          if ( *(_QWORD *)(a1 + 120) != ++v104 )
            goto LABEL_55;
          v71 = 1i64;
          while ( 1 )
          {
            *(&v104 + v71 - 1) = 0i64;
            if ( v70 <= (int)v71 )
              break;
            v72 = *(&v104 + v71) + 1;
            *(&v104 + v71++) = v72;
            if ( v72 != *(_QWORD *)(a1 + 8 * v71 + 112) )
              goto LABEL_55;
          }
        }
        v104 = -1i64;
LABEL_55:
        v73 = *((_DWORD *)v27 + 20);
        if ( v73 <= 0 )
          goto LABEL_60;
        v100 = ++v48;
        if ( v48 == v27[15] )
        {
          v74 = 1i64;
          do
          {
            *(&v100 + v74 - 1) = 0i64;
            if ( v73 <= (int)v74 )
              goto LABEL_60;
            v75 = *(&v100 + v74) + 1;
            *(&v100 + v74++) = v75;
          }
          while ( v75 == v27[v74 + 14] );
          v48 = v100;
        }
      }
    }
    v76 = *(_DWORD *)(a1 + 80);
    if ( v76 <= 1 || *(_BYTE *)(a1 + 74) && (v76 == 2 || *(_BYTE *)(a1 + 75) && (v76 == 3 || *(_BYTE *)(a1 + 76))) )
    {
LABEL_67:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64))(v46 + 64))(v46, v27[7], *(_QWORD *)(a1 + 56), v53);
      goto LABEL_8;
    }
    v77 = 1i64;
    v104 = 0i64;
    do
      *(&v104 + v77++) = 0i64;
    while ( v76 > (int)v77 );
    v100 = 0i64;
    v78 = *((_DWORD *)v27 + 20);
    if ( v78 <= 1 )
    {
      v80 = 0i64;
    }
    else
    {
      v79 = 1i64;
      do
        *(&v100 + v79++) = 0i64;
      while ( v78 > (int)v79 );
      v80 = v100;
    }
    while ( 1 )
    {
      if ( v80 == -1 )
        goto LABEL_8;
      if ( v76 <= 0 )
      {
        v81 = 0i64;
      }
      else
      {
        v81 = *(_QWORD *)(a1 + 88) * v104;
        if ( v76 != 1 )
        {
          v81 += *(_QWORD *)(a1 + 96) * v105;
          if ( v76 != 2 )
          {
            v81 += *(_QWORD *)(a1 + 104) * v106;
            if ( v76 != 3 )
            {
              v48 = *(_QWORD *)(a1 + 112);
              if ( v76 != 4 )
                goto LABEL_40;
              v81 += v48 * v107;
            }
          }
        }
      }
      v82 = *((_DWORD *)v27 + 20);
      v83 = *(_QWORD *)(a1 + 56) + v81;
      if ( v82 <= 0 )
      {
        v84 = 0i64;
      }
      else
      {
        v84 = v27[11] * v80;
        if ( v82 != 1 )
        {
          v84 += v27[12] * v101;
          if ( v82 != 2 )
          {
            v84 += v27[13] * v102;
            if ( v82 != 3 )
            {
              v48 = v27[14];
              if ( v82 != 4 )
                goto LABEL_40;
              v84 += v48 * v103;
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v46 + 64))(
        v46,
        v27[7] + v84,
        v83,
        *(_QWORD *)(a1 + 120) * nc_type_size_table[*(unsigned int *)(a1 + 48)]);
      v76 = *(_DWORD *)(a1 + 80);
      if ( v76 <= 1 )
        goto LABEL_96;
      v85 = 2i64;
      if ( ++v105 == *(_QWORD *)(a1 + 128) )
        break;
LABEL_97:
      v87 = *((_DWORD *)v27 + 20);
      if ( v87 <= 1 )
        goto LABEL_60;
      v88 = 2i64;
      if ( v27[16] == ++v101 )
      {
        while ( 1 )
        {
          *(&v100 + v88 - 1) = 0i64;
          if ( v87 <= (int)v88 )
            break;
          v89 = *(&v100 + v88) + 1;
          *(&v100 + v88++) = v89;
          if ( v89 != v27[v88 + 14] )
            goto LABEL_104;
        }
LABEL_60:
        v100 = -1i64;
        goto LABEL_8;
      }
LABEL_104:
      v80 = v100;
    }
    while ( 1 )
    {
      *(&v104 + v85 - 1) = 0i64;
      if ( v76 <= (int)v85 )
        break;
      v86 = *(&v104 + v85) + 1;
      *(&v104 + v85++) = v86;
      if ( v86 != *(_QWORD *)(a1 + 8 * v85 + 112) )
        goto LABEL_97;
    }
LABEL_96:
    v104 = -1i64;
    goto LABEL_97;
  }
  _R15 = *(unsigned int *)(a1 + 48);
  v90 = nc_type_size_table;
  v19 = aligned_malloc;
  __asm { vmovq   xmm3, qword ptr [r8+r15*8] }
  v94 = *(_DWORD *)(a1 + 48);
  _RBP = nc_type_size_table[_R15] * v8 * a3;
  __asm { vpinsrq xmm0, xmm3, r12, 1 }
  v23 = *(_QWORD *)(a1 + 56) - *(_QWORD *)(v6 + 40);
  __asm
  {
    vmovaps [rsp+108h+var_68], xmm0
    vmovq   xmm4, rbp
  }
  v25 = *(_QWORD *)(a1 + 24);
  __asm
  {
    vpinsrq xmm0, xmm4, r9, 1
    vmovaps [rsp+108h+var_58], xmm0
  }
  v27 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v27 )
  {
    MEMORY[0x18] = v25;
    BUG();
  }
  memset(v27, 0, 0x98ui64);
  v27[3] = v25;
  *((_DWORD *)v27 + 4) = 1;
  *((_DWORD *)v27 + 12) = v94;
  *((_DWORD *)v27 + 20) = 4;
  ++*(_DWORD *)(v6 + 16);
  v27[15] = v98;
  v27[5] = v6;
  v27[16] = *((_QWORD *)&v98 + 1);
  *(_OWORD *)(v27 + 17) = v99;
  v28 = v108;
  v27[11] = v108;
  v29 = *((_QWORD *)&v108 + 1);
  v27[12] = *((_QWORD *)&v108 + 1);
  v30 = v109;
  *(_OWORD *)(v27 + 13) = v109;
  v31 = v28 == nc_type_size_table[_R15];
  v27[8] = v29 >> dword_66A375E0[_R15];
  *((_BYTE *)v27 + 73) = v31;
  v32 = v28 * (_QWORD)v98 == v29;
  v33 = v27[16] * v29;
  *((_BYTE *)v27 + 74) = v32;
  LOBYTE(v33) = v33 == v30;
  *((_BYTE *)v27 + 75) = v33;
  LOBYTE(v30) = v27[17] * v30 == v27[14];
  *((_BYTE *)v27 + 76) = v30;
  *((_BYTE *)v27 + 72) = v33 & v32 & v30 & v31;
  v27[7] = *(_QWORD *)(v6 + 40) + v23;
  v34 = *(_QWORD *)(v25 + 16);
  *(_QWORD *)(v34 + 8) = v27;
  *v27 = v34;
  v27[1] = v25 + 16;
  *(_QWORD *)(v25 + 16) = v27;
LABEL_8:
  if ( *(_QWORD *)(a1 + 32) )
  {
    v36 = (__int64 *)v19(8ui64, 0x40ui64);
    v37 = v27[3];
    v38 = v36;
    *v36 = *(_QWORD *)(a1 + 32);
    v39 = v19(0x80ui64, 0x40ui64);
    if ( !v39 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v39, 0, 0x80ui64);
    *((_DWORD *)v39 + 4) = 1;
    *((_DWORD *)v39 + 5) = 3;
    *((_DWORD *)v39 + 6) = 1;
    v40 = v19(8ui64, 0x40ui64);
    v41 = *v38;
    v39[4] = v40;
    if ( v41 )
    {
      ++*(_DWORD *)(v41 + 16);
      *v40 = v41;
    }
    else
    {
      *v40 = 0i64;
    }
    v42 = *(_QWORD *)(v37 + 72);
    *(_QWORD *)(v37 + 72) = v42 + 1;
    v39[12] = v42;
    v43 = *(_QWORD *)(v37 + 32);
    *(_QWORD *)(v43 + 8) = v39;
    *v39 = v43;
    v39[1] = v37 + 32;
    *(_QWORD *)(v37 + 32) = v39;
    _aligned_free(v38);
    v44 = (__int64 *)v27[4];
    if ( v44 )
      nc_free_node(v44);
    v45 = *(_DWORD *)(a1 + 80);
    v27[4] = v39;
    *((_DWORD *)v39 + 14) = v45;
    if ( v45 > 0 )
    {
      v39[8] = *(_QWORD *)(a1 + 120);
      if ( v45 != 1 )
      {
        v39[9] = *(_QWORD *)(a1 + 128);
        if ( v45 != 2 )
        {
          v39[10] = *(_QWORD *)(a1 + 136);
          if ( v45 != 3 )
            v39[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  nc_free_tensor((_DWORD *)a1);
  return v27;
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

