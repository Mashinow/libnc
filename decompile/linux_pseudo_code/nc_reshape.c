// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_reshape
// Included functions: 3

// ======================================================
// Function: nc_reshape @ 0x1B570
// ======================================================

__int64 __fastcall nc_reshape(
        _DWORD *ptr,
        int a2,
        __int64 *a3,
        __m128 _XMM0,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        char a8)
{
  __int64 v8; // rbx
  __int64 v9; // rbp
  __int64 v10; // r12
  __int64 v11; // r13
  __int64 v12; // r14
  __int64 v13; // r15
  __int64 *v14; // r8
  int v16; // edx
  __int64 v17; // rsi
  char *v18; // rax
  __int64 v19; // rcx
  char *v20; // rdx
  unsigned int v21; // eax
  __int64 v22; // rdi
  int v23; // r9d
  int v24; // edx
  unsigned int v25; // r10d
  int v26; // r14d
  unsigned int v29; // eax
  __int64 v58; // rax
  int v59; // edx
  __int64 v60; // rax
  __int64 v61; // rax
  __int64 v62; // r14
  _QWORD *v63; // rax
  int v64; // edx
  __int64 v66; // rbx
  __int64 v67; // rax
  int v68; // edx
  __int64 v69; // rax
  int v70; // edx
  __int64 v71; // rax
  int v72; // eax
  int v73; // ecx
  __int64 v74; // rdx
  int v75; // ecx
  __int64 v76; // rax
  __int64 v77; // rdx
  int v78; // esi
  __int64 v79; // rax
  __int64 v80; // rdx
  __int64 v81; // rax
  int v82; // edx
  __int64 v83; // rax
  __int64 v84; // r9
  __int64 v85; // rdx
  int v86; // eax
  __int64 v87; // rdx
  __int64 v88; // rax
  __int64 v89; // rdx
  int v90; // edi
  __int64 v91; // rax
  __int64 v92; // rdx
  _DWORD *v93; // [rsp-A8h] [rbp-A8h] BYREF
  __int64 v94; // [rsp-A0h] [rbp-A0h] BYREF
  __int64 v95; // [rsp-98h] [rbp-98h]
  __int64 v96; // [rsp-90h] [rbp-90h]
  __int64 v97; // [rsp-88h] [rbp-88h]
  __int64 v98; // [rsp-80h] [rbp-80h] BYREF
  __int64 v99; // [rsp-78h] [rbp-78h]
  __int64 v100; // [rsp-70h] [rbp-70h]
  __int64 v101; // [rsp-68h] [rbp-68h]
  _QWORD v102[12]; // [rsp-60h] [rbp-60h] BYREF
  void *retaddr; // [rsp+0h] [rbp+0h]

  v14 = a3;
  v102[11] = retaddr;
  v102[10] = v9;
  v102[9] = v13;
  v102[8] = v12;
  v102[7] = v11;
  v102[6] = v10;
  LODWORD(v10) = a2;
  v102[5] = &a8;
  v102[4] = v8;
  v16 = ptr[20];
  v17 = *((_QWORD *)ptr + 5);
  if ( v16 <= 0 )
  {
LABEL_57:
    v19 = 1LL;
    if ( (int)v10 <= 0 )
      goto LABEL_27;
  }
  else
  {
    v18 = (char *)(ptr + 30);
    v19 = 1LL;
    v20 = (char *)&ptr[2 * (v16 - 1) + 32];
    do
    {
      v19 *= *(_QWORD *)v18;
      v18 += 8;
    }
    while ( v18 != v20 );
    if ( (int)v10 <= 0 )
    {
      v22 = 1LL;
      goto LABEL_26;
    }
  }
  v21 = -(int)((unsigned __int64)v14 >> 3) & 3;
  if ( v21 > (unsigned int)v10 )
    v21 = v10;
  if ( (int)v10 <= 8 )
  {
    v21 = v10;
    goto LABEL_9;
  }
  if ( v21 )
  {
LABEL_9:
    v22 = *v14;
    if ( v21 == 1 )
    {
      v23 = 1;
    }
    else
    {
      v22 *= v14[1];
      if ( v21 == 2 )
      {
        v23 = 2;
      }
      else
      {
        v22 *= v14[2];
        if ( v21 == 3 )
        {
          v23 = 3;
        }
        else
        {
          v22 *= v14[3];
          if ( v21 == 4 )
          {
            v23 = 4;
          }
          else
          {
            v22 *= v14[4];
            if ( v21 == 5 )
            {
              v23 = 5;
            }
            else
            {
              v22 *= v14[5];
              if ( v21 == 6 )
              {
                v23 = 6;
              }
              else
              {
                v22 *= v14[6];
                if ( v21 == 8 )
                {
                  v22 *= v14[7];
                  v23 = 8;
                }
                else
                {
                  v23 = 7;
                }
              }
            }
          }
        }
      }
    }
    if ( (_DWORD)v10 == v21 )
      goto LABEL_26;
    goto LABEL_18;
  }
  v23 = 0;
  v22 = 1LL;
LABEL_18:
  v24 = v10 - v21;
  v25 = (((unsigned int)v10 - v21 - 4) >> 2) + 1;
  v26 = 4 * v25;
  if ( (_DWORD)v10 - 1 - v21 <= 2 )
  {
LABEL_23:
    v22 *= v14[v23];
    if ( (int)v10 > v23 + 1 )
    {
      v22 *= v14[v23 + 1];
      if ( (int)v10 > v23 + 2 )
        v22 *= v14[v23 + 2];
    }
    goto LABEL_26;
  }
  __asm { vmovdqa ymm1, cs:ymmword_30A40 }
  _R11 = &v14[v21];
  v29 = 0;
  do
  {
    __asm
    {
      vmovdqa ymm3, ymmword ptr [r11]
      vpsrlq  ymm0, ymm1, 20h ; ' '
    }
    ++v29;
    _R11 += 4;
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
  while ( v25 > v29 );
  __asm
  {
    vpxor   xmm0, xmm0, xmm0
    vpsrlq  ymm4, ymm1, 20h ; ' '
  }
  v23 += v26;
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
  v22 *= _RAX;
  if ( v26 != v24 )
  {
    __asm { vzeroupper }
    goto LABEL_23;
  }
  __asm { vzeroupper }
LABEL_26:
  if ( v19 != v22 )
    sub_18270("reshape", (__int64)ptr, 0LL);
LABEL_27:
  if ( !*((_BYTE *)ptr + 72) )
  {
    v66 = *(_QWORD *)(v17 + 24);
    v67 = nc_new_tensor_nz(v66, (unsigned int)ptr[12], (unsigned int)v10, v14);
    v62 = v67;
    if ( *((_BYTE *)ptr + 72) && *(_BYTE *)(v67 + 72) )
      goto LABEL_79;
    if ( (int)v10 <= 0 || *((_QWORD *)ptr + 15) != *(_QWORD *)(v67 + 120) )
    {
      v68 = ptr[20];
      v98 = 0LL;
      v69 = 1LL;
      if ( v68 > 1 )
      {
        do
          *(&v98 + v69++) = 0LL;
        while ( v68 > (int)v69 );
      }
      v70 = *(_DWORD *)(v62 + 80);
      v71 = 1LL;
      v10 = 0LL;
      v94 = 0LL;
      if ( v70 > 1 )
      {
        do
          *(&v94 + v71++) = 0LL;
        while ( v70 > (int)v71 );
LABEL_50:
        v10 = v94;
      }
      while ( 1 )
      {
        if ( v10 == -1 )
          goto LABEL_33;
        v72 = *(_DWORD *)(v62 + 80);
        if ( v72 <= 0 )
        {
          v17 = 0LL;
        }
        else
        {
          v17 = *(_QWORD *)(v62 + 88) * v10;
          if ( v72 != 1 )
          {
            v17 += *(_QWORD *)(v62 + 96) * v95;
            if ( v72 != 2 )
            {
              v17 += *(_QWORD *)(v62 + 104) * v96;
              if ( v72 != 3 )
              {
                if ( v72 != 4 )
                  goto LABEL_57;
                v17 += *(_QWORD *)(v62 + 112) * v97;
              }
            }
          }
        }
        v17 += *(_QWORD *)(v62 + 56);
        v73 = ptr[20];
        if ( v73 <= 0 )
        {
          v74 = 0LL;
        }
        else
        {
          v74 = *((_QWORD *)ptr + 11) * v98;
          if ( v73 != 1 )
          {
            v74 += *((_QWORD *)ptr + 12) * v99;
            if ( v73 != 2 )
            {
              v74 += *((_QWORD *)ptr + 13) * v100;
              if ( v73 != 3 )
              {
                if ( v73 != 4 )
                  goto LABEL_57;
                v74 += *((_QWORD *)ptr + 14) * v101;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD))(v66 + 64))(
          v66,
          v17,
          *((_QWORD *)ptr + 7) + v74,
          nc_type_size_table[*(unsigned int *)(v62 + 48)]);
        v75 = ptr[20];
        if ( v75 <= 0 )
          goto LABEL_71;
        if ( ++v98 == *((_QWORD *)ptr + 15) )
          break;
LABEL_72:
        v78 = *(_DWORD *)(v62 + 80);
        if ( v78 <= 0 )
          goto LABEL_77;
        v94 = ++v10;
        if ( v10 == *(_QWORD *)(v62 + 120) )
        {
          v79 = 1LL;
          while ( 1 )
          {
            *(&v94 + v79 - 1) = 0LL;
            if ( v78 <= (int)v79 )
              goto LABEL_77;
            v80 = *(&v94 + v79) + 1;
            *(&v94 + v79++) = v80;
            if ( v80 != *(_QWORD *)(v62 + 8 * v79 + 112) )
              goto LABEL_50;
          }
        }
      }
      v76 = 1LL;
      while ( 1 )
      {
        *(&v98 + v76 - 1) = 0LL;
        if ( v75 <= (int)v76 )
          break;
        v77 = *(&v98 + v76) + 1;
        *(&v98 + v76++) = v77;
        if ( v77 != *(_QWORD *)&ptr[2 * v76 + 28] )
          goto LABEL_72;
      }
LABEL_71:
      v98 = -1LL;
      goto LABEL_72;
    }
    v17 = (unsigned int)ptr[20];
    if ( (int)v17 <= 1
      || *((_BYTE *)ptr + 74)
      && ((_DWORD)v17 == 2 || *((_BYTE *)ptr + 75) && ((_DWORD)v17 == 3 || *((_BYTE *)ptr + 76))) )
    {
LABEL_79:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))(v66 + 64))(
        v66,
        *(_QWORD *)(v67 + 56),
        *((_QWORD *)ptr + 7),
        *(_QWORD *)(*(_QWORD *)(v67 + 40) + 48LL));
      goto LABEL_33;
    }
    v98 = 0LL;
    v81 = 1LL;
    do
      *(&v98 + v81++) = 0LL;
    while ( (int)v17 > (int)v81 );
    v94 = 0LL;
    v82 = *(_DWORD *)(v62 + 80);
    if ( v82 <= 1 )
    {
      v84 = 0LL;
    }
    else
    {
      v83 = 1LL;
      do
        *(&v94 + v83++) = 0LL;
      while ( v82 > (int)v83 );
      v84 = v94;
    }
    LODWORD(v10) = -1;
    while ( 1 )
    {
      if ( v84 == -1 )
        goto LABEL_33;
      v14 = *(__int64 **)(v66 + 64);
      if ( (int)v17 <= 0 )
      {
        v85 = 0LL;
      }
      else
      {
        v85 = *((_QWORD *)ptr + 11) * v98;
        if ( (_DWORD)v17 != 1 )
        {
          v85 += *((_QWORD *)ptr + 12) * v99;
          if ( (_DWORD)v17 != 2 )
          {
            v85 += *((_QWORD *)ptr + 13) * v100;
            if ( (_DWORD)v17 != 3 )
            {
              if ( (_DWORD)v17 != 4 )
                goto LABEL_57;
              v85 += *((_QWORD *)ptr + 14) * v101;
            }
          }
        }
      }
      v86 = *(_DWORD *)(v62 + 80);
      v87 = *((_QWORD *)ptr + 7) + v85;
      if ( v86 <= 0 )
      {
        v17 = 0LL;
      }
      else
      {
        v17 = *(_QWORD *)(v62 + 88) * v84;
        if ( v86 != 1 )
        {
          v17 += *(_QWORD *)(v62 + 96) * v95;
          if ( v86 != 2 )
          {
            v17 += *(_QWORD *)(v62 + 104) * v96;
            if ( v86 != 3 )
            {
              if ( v86 != 4 )
                goto LABEL_57;
              v17 += *(_QWORD *)(v62 + 112) * v97;
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v14)(
        v66,
        *(_QWORD *)(v62 + 56) + v17,
        v87,
        *((_QWORD *)ptr + 15) * nc_type_size_table[ptr[12]]);
      v17 = (unsigned int)ptr[20];
      if ( (int)v17 <= 1 )
        goto LABEL_121;
      v88 = 2LL;
      if ( *((_QWORD *)ptr + 16) == ++v99 )
        break;
LABEL_122:
      v90 = *(_DWORD *)(v62 + 80);
      if ( v90 <= 1 )
        goto LABEL_77;
      v91 = 2LL;
      if ( ++v95 == *(_QWORD *)(v62 + 128) )
      {
        while ( 1 )
        {
          *(&v94 + v91 - 1) = 0LL;
          if ( v90 <= (int)v91 )
            break;
          v92 = *(&v94 + v91) + 1;
          *(&v94 + v91++) = v92;
          if ( v92 != *(_QWORD *)(v62 + 8 * v91 + 112) )
            goto LABEL_128;
        }
LABEL_77:
        v94 = -1LL;
        goto LABEL_33;
      }
LABEL_128:
      v84 = v94;
    }
    while ( 1 )
    {
      *(&v98 + v88 - 1) = 0LL;
      if ( (int)v17 <= (int)v88 )
        break;
      v89 = *(&v98 + v88) + 1;
      *(&v98 + v88++) = v89;
      if ( v89 != *(_QWORD *)&ptr[2 * v88 + 28] )
        goto LABEL_122;
    }
LABEL_121:
    v98 = -1LL;
    goto LABEL_122;
  }
  v58 = nc_type_size_table[ptr[12]];
  v59 = ptr[12];
  v102[0] = v58;
  if ( (int)v10 > 1 )
  {
    v60 = *v14 * v58;
    v102[1] = v60;
    if ( (_DWORD)v10 != 2 )
    {
      v61 = v14[1] * v60;
      v102[2] = v61;
      if ( (_DWORD)v10 != 3 )
        v102[3] = v14[2] * v61;
    }
  }
  v62 = nc_new_tensor_from_buffer(
          *((_QWORD *)ptr + 3),
          v17,
          v59,
          v10,
          (int)v14,
          ptr[14] - *(_DWORD *)(v17 + 40),
          (__int64)v102);
LABEL_33:
  v93 = ptr;
  v63 = sub_17800(3, (__int64 *)(v62 + 24), (void **)(v62 + 32), (__int64)&v93);
  if ( v63 )
  {
    v64 = ptr[20];
    *((_DWORD *)v63 + 14) = v64;
    if ( v64 > 0 )
    {
      v63[8] = *((_QWORD *)ptr + 15);
      if ( v64 != 1 )
      {
        v63[9] = *((_QWORD *)ptr + 16);
        if ( v64 != 2 )
        {
          v63[10] = *((_QWORD *)ptr + 17);
          if ( v64 != 3 )
            v63[11] = *((_QWORD *)ptr + 18);
        }
      }
    }
  }
  nc_free_tensor(ptr);
  return v62;
}

// ======================================================
// Function: sub_18270 @ 0x18270
// ======================================================

void __fastcall __noreturn sub_18270(const char *a1, __int64 a2, __int64 a3)
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
// Function: sub_17800 @ 0x17800
// ======================================================

_QWORD *__fastcall sub_17800(int a1, __int64 *a2, void **a3, __int64 a4)
{
  __int64 *v7; // rax
  __int64 v8; // rbp
  __int64 *v9; // r14
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rax

  if ( !*(_QWORD *)(*(_QWORD *)a4 + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(8uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*(_QWORD *)a4 + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 1;
  v12 = (_QWORD *)nc_malloc(8uLL);
  v13 = *v9;
  v11[4] = v12;
  if ( v13 )
    *v12 = nc_dup_node();
  else
    *v12 = 0LL;
  v14 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v14 + 1;
  v11[12] = v14;
  v15 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v15 + 8) = v11;
  *v11 = v15;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

