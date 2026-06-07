// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reshape
// Included functions: 3

// ======================================================
// Function: nc_reshape @ 0x66A1AAB0
// ======================================================

_QWORD *__fastcall nc_reshape(__int64 a1, int a2, __int64 a3)
{
  __int64 *v5; // rsi
  __int64 v6; // rdx
  int v7; // ecx
  _QWORD *v8; // rax
  __int64 v9; // r10
  __int64 v10; // rcx
  unsigned int v11; // eax
  __int64 v12; // r9
  int v13; // r11d
  unsigned int v14; // ecx
  unsigned int v15; // ebx
  int v16; // r12d
  unsigned int v19; // eax
  __int64 v48; // rax
  int v49; // r10d
  __int64 v50; // rax
  __int64 v51; // rax
  _QWORD *v52; // r12
  _QWORD *v53; // rax
  int v54; // edx
  __int64 v56; // rbx
  _QWORD *v57; // rax
  int v58; // edx
  __int64 v59; // rax
  int v60; // edx
  __int64 v61; // rax
  __int64 v62; // r14
  int v63; // eax
  __int64 v64; // rax
  int v65; // ecx
  __int64 v66; // rax
  __int64 v67; // rdx
  int v68; // r8d
  __int64 v69; // rax
  __int64 v70; // rdx
  int v71; // r10d
  __int64 v72; // rax
  int v73; // edx
  __int64 v74; // rax
  int v75; // eax
  __int64 v76; // rax
  __int64 v77; // rdx
  int v78; // r8d
  __int64 v79; // rax
  __int64 v80; // rdx
  __int64 v81; // [rsp+48h] [rbp-A0h] BYREF
  __int64 v82; // [rsp+50h] [rbp-98h] BYREF
  __int64 v83; // [rsp+58h] [rbp-90h]
  __int64 v84; // [rsp+60h] [rbp-88h]
  __int64 v85; // [rsp+68h] [rbp-80h]
  __int64 v86; // [rsp+70h] [rbp-78h] BYREF
  __int64 v87; // [rsp+78h] [rbp-70h]
  __int64 v88; // [rsp+80h] [rbp-68h]
  __int64 v89; // [rsp+88h] [rbp-60h]
  __int64 v90[11]; // [rsp+90h] [rbp-58h] BYREF

  LODWORD(v5) = a2;
  v6 = *(_QWORD *)(a1 + 40);
  v7 = *(_DWORD *)(a1 + 80);
  if ( v7 <= 0 )
  {
LABEL_58:
    v9 = 1i64;
    if ( (int)v5 <= 0 )
      goto LABEL_27;
  }
  else
  {
    v8 = (_QWORD *)(a1 + 120);
    v9 = 1i64;
    v10 = a1 + 8i64 * (unsigned int)(v7 - 1) + 128;
    do
      v9 *= *v8++;
    while ( v8 != (_QWORD *)v10 );
    if ( (int)v5 <= 0 )
    {
      v12 = 1i64;
      goto LABEL_26;
    }
  }
  v11 = -(int)((unsigned __int64)a3 >> 3) & 3;
  if ( v11 > (unsigned int)v5 )
    v11 = (unsigned int)v5;
  if ( (int)v5 <= 8 )
  {
    v11 = (unsigned int)v5;
    goto LABEL_9;
  }
  if ( v11 )
  {
LABEL_9:
    v12 = *(_QWORD *)a3;
    if ( v11 == 1 )
    {
      v13 = 1;
    }
    else
    {
      v12 *= *(_QWORD *)(a3 + 8);
      if ( v11 == 2 )
      {
        v13 = 2;
      }
      else
      {
        v12 *= *(_QWORD *)(a3 + 16);
        if ( v11 == 3 )
        {
          v13 = 3;
        }
        else
        {
          v12 *= *(_QWORD *)(a3 + 24);
          if ( v11 == 4 )
          {
            v13 = 4;
          }
          else
          {
            v12 *= *(_QWORD *)(a3 + 32);
            if ( v11 == 5 )
            {
              v13 = 5;
            }
            else
            {
              v12 *= *(_QWORD *)(a3 + 40);
              if ( v11 == 6 )
              {
                v13 = 6;
              }
              else
              {
                v12 *= *(_QWORD *)(a3 + 48);
                if ( v11 == 8 )
                {
                  v12 *= *(_QWORD *)(a3 + 56);
                  v13 = 8;
                }
                else
                {
                  v13 = 7;
                }
              }
            }
          }
        }
      }
    }
    if ( (_DWORD)v5 == v11 )
      goto LABEL_26;
    goto LABEL_18;
  }
  v13 = 0;
  v12 = 1i64;
LABEL_18:
  v14 = (_DWORD)v5 - v11;
  v15 = (((unsigned int)v5 - v11 - 4) >> 2) + 1;
  v16 = 4 * v15;
  if ( (_DWORD)v5 - 1 - v11 <= 2 )
  {
LABEL_23:
    v12 *= *(_QWORD *)(a3 + 8i64 * v13);
    if ( (int)v5 > v13 + 1 )
    {
      v12 *= *(_QWORD *)(a3 + 8i64 * (v13 + 1));
      if ( (int)v5 > v13 + 2 )
        v12 *= *(_QWORD *)(a3 + 8i64 * (v13 + 2));
    }
    goto LABEL_26;
  }
  __asm { vmovdqa ymm1, cs:ymmword_66A37C60 }
  _RDI = (__int64 *)(a3 + 8i64 * v11);
  v19 = 0;
  do
  {
    __asm
    {
      vmovdqa ymm3, ymmword ptr [rdi]
      vpsrlq  ymm0, ymm1, 20h ; ' '
    }
    ++v19;
    _RDI += 4;
    __asm
    {
      vpsrlq  ymm2, ymm3, 20h ; ' '
      vpmuludq ymm4, ymm1, ymm3
      vpmuludq ymm0, ymm0, ymm3
      vpmuludq ymm1, ymm2, ymm1
      vpaddq  ymm0, ymm0, ymm1
      vpsllq  ymm0, ymm0, 20h ; ' '
      vpaddq  ymm1, ymm4, ymm0
    }
  }
  while ( v15 > v19 );
  __asm
  {
    vpxor   xmm0, xmm0, xmm0
    vpsrlq  ymm4, ymm1, 20h ; ' '
  }
  v13 += v16;
  __asm
  {
    vperm2i128 ymm5, ymm1, ymm0, 21h ; '!'
    vpsrlq  ymm3, ymm5, 20h ; ' '
    vpmuludq ymm2, ymm5, ymm1
    vpmuludq ymm1, ymm3, ymm1
    vpmuludq ymm3, ymm4, ymm5
    vpaddq  ymm1, ymm1, ymm3
    vpsllq  ymm1, ymm1, 20h ; ' '
    vpaddq  ymm3, ymm2, ymm1
    vperm2i128 ymm0, ymm3, ymm0, 21h ; '!'
    vpsrlq  ymm4, ymm3, 20h ; ' '
    vpalignr ymm0, ymm0, ymm3, 8
    vpsrlq  ymm2, ymm0, 20h ; ' '
    vpmuludq ymm1, ymm0, ymm3
    vpmuludq ymm2, ymm2, ymm3
    vpmuludq ymm0, ymm4, ymm0
    vpaddq  ymm2, ymm2, ymm0
    vpsllq  ymm2, ymm2, 20h ; ' '
    vpaddq  ymm0, ymm1, ymm2
    vmovq   rax, xmm0
  }
  v12 *= _RAX;
  if ( v16 != v14 )
  {
    __asm { vzeroupper }
    goto LABEL_23;
  }
  __asm { vzeroupper }
LABEL_26:
  if ( v9 != v12 )
    sub_66A16930("reshape", a1, 0i64);
LABEL_27:
  if ( !*(_BYTE *)(a1 + 72) )
  {
    v56 = *(_QWORD *)(v6 + 24);
    v57 = nc_new_tensor_nz(v56, *(_DWORD *)(a1 + 48), (int)v5, a3);
    v52 = v57;
    if ( *(_BYTE *)(a1 + 72) && *((_BYTE *)v57 + 72) )
      goto LABEL_80;
    if ( (int)v5 <= 0 || *(_QWORD *)(a1 + 120) != v57[15] )
    {
      v58 = *(_DWORD *)(a1 + 80);
      v59 = 1i64;
      v86 = 0i64;
      if ( v58 > 1 )
      {
        do
          *(&v86 + v59++) = 0i64;
        while ( v58 > (int)v59 );
      }
      v60 = *((_DWORD *)v52 + 20);
      v61 = 1i64;
      v62 = 0i64;
      v82 = 0i64;
      if ( v60 > 1 )
      {
        do
          *(&v82 + v61++) = 0i64;
        while ( v60 > (int)v61 );
        v62 = v82;
      }
      v5 = nc_type_size_table;
      while ( 1 )
      {
LABEL_52:
        if ( v62 == -1 )
          goto LABEL_33;
        v63 = *((_DWORD *)v52 + 20);
        a3 = v52[7];
        if ( v63 <= 0 )
        {
          v6 = 0i64;
        }
        else
        {
          v6 = v52[11] * v62;
          if ( v63 != 1 )
          {
            v6 += v52[12] * v83;
            if ( v63 != 2 )
            {
              v6 += v52[13] * v84;
              if ( v63 != 3 )
              {
                if ( v63 != 4 )
                  goto LABEL_58;
                v6 += v52[14] * v85;
              }
            }
          }
        }
        v6 += a3;
        a3 = *(unsigned int *)(a1 + 80);
        if ( (int)a3 <= 0 )
        {
          v64 = 0i64;
        }
        else
        {
          v64 = *(_QWORD *)(a1 + 88) * v86;
          if ( (_DWORD)a3 != 1 )
          {
            v64 += *(_QWORD *)(a1 + 96) * v87;
            if ( (_DWORD)a3 != 2 )
            {
              v64 += *(_QWORD *)(a1 + 104) * v88;
              if ( (_DWORD)a3 != 3 )
              {
                if ( (_DWORD)a3 != 4 )
                  goto LABEL_58;
                v64 += *(_QWORD *)(a1 + 112) * v89;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v56 + 64))(
          v56,
          v6,
          *(_QWORD *)(a1 + 56) + v64,
          nc_type_size_table[*((unsigned int *)v52 + 12)]);
        v65 = *(_DWORD *)(a1 + 80);
        if ( v65 <= 0 )
          goto LABEL_72;
        if ( ++v86 == *(_QWORD *)(a1 + 120) )
          break;
LABEL_73:
        v68 = *((_DWORD *)v52 + 20);
        if ( v68 <= 0 )
          goto LABEL_78;
        v82 = ++v62;
        if ( v62 == v52[15] )
        {
          v69 = 1i64;
          while ( 1 )
          {
            *(&v82 + v69 - 1) = 0i64;
            if ( v68 <= (int)v69 )
              goto LABEL_78;
            v70 = *(&v82 + v69) + 1;
            *(&v82 + v69++) = v70;
            if ( v70 != v52[v69 + 14] )
            {
              v62 = v82;
              goto LABEL_52;
            }
          }
        }
      }
      v66 = 1i64;
      while ( 1 )
      {
        *(&v86 + v66 - 1) = 0i64;
        if ( v65 <= (int)v66 )
          break;
        v67 = *(&v86 + v66) + 1;
        *(&v86 + v66++) = v67;
        if ( v67 != *(_QWORD *)(a1 + 8 * v66 + 112) )
          goto LABEL_73;
      }
LABEL_72:
      v86 = -1i64;
      goto LABEL_73;
    }
    v71 = *(_DWORD *)(a1 + 80);
    if ( v71 <= 1 || *(_BYTE *)(a1 + 74) && (v71 == 2 || *(_BYTE *)(a1 + 75) && (v71 == 3 || *(_BYTE *)(a1 + 76))) )
    {
LABEL_80:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))(v56 + 64))(
        v56,
        v57[7],
        *(_QWORD *)(a1 + 56),
        *(_QWORD *)(v57[5] + 48i64));
      goto LABEL_33;
    }
    v86 = 0i64;
    v72 = 1i64;
    do
      *(&v86 + v72++) = 0i64;
    while ( v71 > (int)v72 );
    v82 = 0i64;
    v73 = *((_DWORD *)v52 + 20);
    if ( v73 <= 1 )
    {
      v6 = 0i64;
    }
    else
    {
      v74 = 1i64;
      do
        *(&v82 + v74++) = 0i64;
      while ( v73 > (int)v74 );
      v6 = v82;
    }
    v5 = nc_type_size_table;
    while ( 1 )
    {
      if ( v6 == -1 )
        goto LABEL_33;
      if ( v71 <= 0 )
      {
        a3 = 0i64;
      }
      else
      {
        a3 = *(_QWORD *)(a1 + 88) * v86;
        if ( v71 != 1 )
        {
          a3 += *(_QWORD *)(a1 + 96) * v87;
          if ( v71 != 2 )
          {
            a3 += *(_QWORD *)(a1 + 104) * v88;
            if ( v71 != 3 )
            {
              if ( v71 != 4 )
                goto LABEL_58;
              a3 += *(_QWORD *)(a1 + 112) * v89;
            }
          }
        }
      }
      v75 = *((_DWORD *)v52 + 20);
      a3 += *(_QWORD *)(a1 + 56);
      if ( v75 <= 0 )
      {
        v6 = 0i64;
      }
      else
      {
        v6 *= v52[11];
        if ( v75 != 1 )
        {
          v6 += v52[12] * v83;
          if ( v75 != 2 )
          {
            v6 += v52[13] * v84;
            if ( v75 != 3 )
            {
              if ( v75 != 4 )
                goto LABEL_58;
              v6 += v52[14] * v85;
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v56 + 64))(
        v56,
        v52[7] + v6,
        a3,
        *(_QWORD *)(a1 + 120) * nc_type_size_table[*(unsigned int *)(a1 + 48)]);
      v71 = *(_DWORD *)(a1 + 80);
      if ( v71 <= 1 )
        goto LABEL_123;
      v76 = 2i64;
      if ( *(_QWORD *)(a1 + 128) == ++v87 )
        break;
LABEL_124:
      v78 = *((_DWORD *)v52 + 20);
      if ( v78 <= 1 )
        goto LABEL_78;
      v79 = 2i64;
      if ( ++v83 == v52[16] )
      {
        while ( 1 )
        {
          *(&v82 + v79 - 1) = 0i64;
          if ( v78 <= (int)v79 )
            break;
          v80 = *(&v82 + v79) + 1;
          *(&v82 + v79++) = v80;
          if ( v80 != v52[v79 + 14] )
            goto LABEL_130;
        }
LABEL_78:
        v82 = -1i64;
        goto LABEL_33;
      }
LABEL_130:
      v6 = v82;
    }
    while ( 1 )
    {
      *(&v86 + v76 - 1) = 0i64;
      if ( v71 <= (int)v76 )
        break;
      v77 = *(&v86 + v76) + 1;
      *(&v86 + v76++) = v77;
      if ( v77 != *(_QWORD *)(a1 + 8 * v76 + 112) )
        goto LABEL_124;
    }
LABEL_123:
    v86 = -1i64;
    goto LABEL_124;
  }
  v48 = nc_type_size_table[*(unsigned int *)(a1 + 48)];
  v49 = *(_DWORD *)(a1 + 48);
  v90[0] = v48;
  if ( (int)v5 > 1 )
  {
    v50 = *(_QWORD *)a3 * v48;
    v90[1] = v50;
    if ( (_DWORD)v5 != 2 )
    {
      v51 = *(_QWORD *)(a3 + 8) * v50;
      v90[2] = v51;
      if ( (_DWORD)v5 != 3 )
        v90[3] = *(_QWORD *)(a3 + 16) * v51;
    }
  }
  v52 = nc_new_tensor_from_buffer(
          *(_QWORD *)(a1 + 24),
          v6,
          v49,
          (int)v5,
          (__int64 *)a3,
          *(_QWORD *)(a1 + 56) - *(_QWORD *)(v6 + 40),
          v90);
LABEL_33:
  v81 = a1;
  v53 = sub_66A15DA0(3, v52 + 3, (__int64 **)v52 + 4, 1, (__int64)&v81);
  if ( v53 )
  {
    v54 = *(_DWORD *)(a1 + 80);
    *((_DWORD *)v53 + 14) = v54;
    if ( v54 > 0 )
    {
      v53[8] = *(_QWORD *)(a1 + 120);
      if ( v54 != 1 )
      {
        v53[9] = *(_QWORD *)(a1 + 128);
        if ( v54 != 2 )
        {
          v53[10] = *(_QWORD *)(a1 + 136);
          if ( v54 != 3 )
            v53[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  nc_free_tensor((_DWORD *)a1);
  return v52;
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

