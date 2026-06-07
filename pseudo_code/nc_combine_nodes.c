// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_combine_nodes
// Included functions: 3

// ======================================================
// Function: nc_combine_nodes @ 0x66A2D4B0
// ======================================================

__int64 __fastcall nc_combine_nodes(__int64 a1, unsigned __int64 a2, int a3, int a4, int a5, unsigned __int64 a6)
{
  unsigned __int64 v11; // rbp
  unsigned int v15; // eax
  __int64 v16; // rsi
  int v17; // edx
  int v18; // r8d
  unsigned int v19; // r9d
  unsigned int v20; // ecx
  int v21; // r10d
  unsigned __int64 v22; // r8
  unsigned int v23; // eax
  int v32; // eax
  int v33; // edx
  _QWORD *v34; // rbx
  unsigned int v35; // ecx
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // r9d
  unsigned int v40; // r8d
  int v41; // r10d
  __int64 v42; // r9
  unsigned int v44; // r11d
  int v48; // eax
  int v49; // edx
  __int64 v50; // r15
  int v51; // eax
  __int64 v52; // rdi
  _QWORD *v53; // r15
  __int64 v54; // rax
  __int64 v55; // rdx
  __int64 v56; // rcx
  __int64 v57; // rax
  __int64 v58; // rax
  __int64 v59; // rax
  __int64 v60; // rdx
  __int64 j; // rax
  __int64 v62; // rax
  __int64 v63; // r13
  __int64 v64; // rbx
  __int64 v65; // r15
  __int64 v66; // rbp
  int v67; // esi
  __int64 *v68; // rcx
  __int64 v69; // rbp
  int v70; // esi
  int v71; // eax
  _DWORD *v72; // rcx
  bool v73; // zf
  __int64 *v74; // rax
  __int64 v75; // rcx
  int v76; // edx
  _QWORD *v77; // r8
  __int64 v78; // rcx
  _QWORD *v79; // r9
  __int64 v80; // rax
  __int64 v81; // rdx
  _QWORD *v82; // rax
  _DWORD *v83; // rax
  void *v84; // r9
  _QWORD *v85; // rax
  __int64 v86; // rax
  __int64 v87; // rax
  _QWORD *v88; // rax
  _DWORD *v90; // rax
  _QWORD *v91; // r15
  _QWORD *v92; // rax
  __int64 v93; // rdx
  _QWORD *v94; // r8
  __int64 v95; // r9
  __int64 v96; // rdx
  __int64 *v97; // rax
  __int64 *v98; // r10
  __int64 i; // rax
  __int64 v100; // rdx
  _QWORD *v101; // rax
  _DWORD *v102; // rax
  _QWORD *v103; // rax
  __int64 v104; // rax
  __int64 v105; // rax
  __int64 *v106; // rax
  __int64 v107; // rdi
  _QWORD *v108; // rax
  __int64 *v109; // rdi
  _QWORD *v110; // rax
  int v111; // ecx
  int v112; // r8d
  __int64 v113; // rdx
  bool v114; // cc
  __int64 v115; // rax
  size_t v116; // r8
  unsigned __int64 v117; // rax
  unsigned int v118; // edx
  int v119; // ecx
  unsigned int v120; // r10d
  unsigned int v121; // r8d
  int v122; // r11d
  unsigned int v125; // edx
  __int64 v127; // rax
  __int64 v128; // rax
  void *(__cdecl *v129)(size_t, size_t); // [rsp+20h] [rbp-A8h]
  __int64 Size; // [rsp+28h] [rbp-A0h]
  size_t Sizea; // [rsp+28h] [rbp-A0h]
  _DWORD *Sizeb; // [rsp+28h] [rbp-A0h]
  size_t Sizec; // [rsp+28h] [rbp-A0h]
  __int64 *v134; // [rsp+30h] [rbp-98h]
  __int64 v135; // [rsp+30h] [rbp-98h]
  __int64 v137; // [rsp+40h] [rbp-88h]
  unsigned __int64 v138; // [rsp+40h] [rbp-88h]
  _DWORD *v139; // [rsp+40h] [rbp-88h]
  _DWORD *v140; // [rsp+40h] [rbp-88h]
  unsigned __int64 v141; // [rsp+48h] [rbp-80h]
  void (__cdecl *Block)(void *); // [rsp+50h] [rbp-78h]
  void *Blocka; // [rsp+50h] [rbp-78h]
  _DWORD *Blockb; // [rsp+50h] [rbp-78h]
  _DWORD *Blockc; // [rsp+50h] [rbp-78h]
  __int64 *Blocke; // [rsp+50h] [rbp-78h]
  _DWORD *Blockd; // [rsp+50h] [rbp-78h]
  _QWORD *v148; // [rsp+58h] [rbp-70h]
  void *v149; // [rsp+58h] [rbp-70h]
  _DWORD *v150; // [rsp+58h] [rbp-70h]
  _DWORD *v151; // [rsp+58h] [rbp-70h]
  __int64 *v152; // [rsp+60h] [rbp-68h]
  _DWORD *v153; // [rsp+60h] [rbp-68h]
  __int64 *v154; // [rsp+68h] [rbp-60h]
  __int64 v155; // [rsp+78h] [rbp-50h] BYREF

  _RBX = a5;
  v11 = a6;
  if ( a3 <= 0 )
  {
    sub_66A33D40("count >= 1", "libnc.c", 7738);
    if ( a6 )
    {
      v16 = 0i64;
      Size = 8i64 * a3;
      v129 = aligned_malloc;
      v141 = 0i64;
      v34 = aligned_malloc(Size, 0x40ui64);
      if ( !v34 )
        goto LABEL_46;
    }
    else
    {
      Size = 8i64 * a3;
      v129 = aligned_malloc;
      v11 = (unsigned __int64)aligned_malloc(Size, 0x40ui64);
      v141 = v11;
      v16 = 0i64;
      v34 = aligned_malloc(Size, 0x40ui64);
      if ( !v34 )
        goto LABEL_46;
    }
LABEL_27:
    memset(v34, 0, Size);
    if ( a3 <= 0 )
      goto LABEL_46;
    goto LABEL_28;
  }
  Size = 8i64 * a3;
  if ( a6 )
  {
    v141 = 0i64;
    v129 = aligned_malloc;
    goto LABEL_4;
  }
  v129 = aligned_malloc;
  v117 = (unsigned __int64)aligned_malloc(8i64 * a3, 0x40ui64);
  v118 = -(int)(v117 >> 3) & 3;
  if ( v118 > a3 )
    v118 = a3;
  if ( a3 > 6 )
  {
    if ( !v118 )
    {
      v119 = 0;
      goto LABEL_155;
    }
  }
  else
  {
    v118 = a3;
  }
  *(_QWORD *)v117 = a5;
  if ( v118 == 1 )
  {
    v119 = 1;
  }
  else
  {
    *(_QWORD *)(v117 + 8) = a5;
    if ( v118 == 2 )
    {
      v119 = 2;
    }
    else
    {
      *(_QWORD *)(v117 + 16) = a5;
      if ( v118 == 3 )
      {
        v119 = 3;
      }
      else
      {
        *(_QWORD *)(v117 + 24) = a5;
        if ( v118 == 4 )
        {
          v119 = 4;
        }
        else
        {
          *(_QWORD *)(v117 + 32) = a5;
          if ( v118 == 6 )
          {
            *(_QWORD *)(v117 + 40) = a5;
            v119 = 6;
          }
          else
          {
            v119 = 5;
          }
        }
      }
    }
  }
  if ( a3 != v118 )
  {
LABEL_155:
    v120 = a3 - v118;
    v121 = ((a3 - v118 - 4) >> 2) + 1;
    v122 = 4 * v121;
    if ( a3 - 1 - v118 <= 2 )
      goto LABEL_182;
    __asm { vmovq   xmm3, rbx }
    _R9 = (_QWORD *)(v117 + 8i64 * v118);
    v125 = 0;
    __asm { vpbroadcastq ymm0, xmm3 }
    do
    {
      ++v125;
      __asm { vmovdqa ymmword ptr [r9], ymm0 }
      _R9 += 4;
    }
    while ( v121 > v125 );
    v119 += v122;
    if ( v120 != v122 )
    {
LABEL_182:
      *(_QWORD *)(v117 + 8i64 * v119) = a5;
      if ( a3 > v119 + 1 )
      {
        *(_QWORD *)(v117 + 8i64 * (v119 + 1)) = a5;
        if ( a3 > v119 + 2 )
          *(_QWORD *)(v117 + 8i64 * (v119 + 2)) = a5;
      }
    }
  }
  v141 = v117;
  v11 = v117;
LABEL_4:
  v15 = -(int)(v11 >> 3) & 3;
  if ( v15 > a3 )
    v15 = a3;
  if ( a3 <= 8 )
  {
    v15 = a3;
    goto LABEL_8;
  }
  if ( v15 )
  {
LABEL_8:
    v16 = *(_QWORD *)v11;
    if ( v15 == 1 )
    {
      v17 = 1;
    }
    else
    {
      v16 += *(_QWORD *)(v11 + 8);
      if ( v15 == 2 )
      {
        v17 = 2;
      }
      else
      {
        v16 += *(_QWORD *)(v11 + 16);
        if ( v15 == 3 )
        {
          v17 = 3;
        }
        else
        {
          v16 += *(_QWORD *)(v11 + 24);
          if ( v15 == 4 )
          {
            v17 = 4;
          }
          else
          {
            v16 += *(_QWORD *)(v11 + 32);
            if ( v15 == 5 )
            {
              v17 = 5;
            }
            else
            {
              v16 += *(_QWORD *)(v11 + 40);
              if ( v15 == 6 )
              {
                v17 = 6;
              }
              else
              {
                v16 += *(_QWORD *)(v11 + 48);
                if ( v15 == 8 )
                {
                  v16 += *(_QWORD *)(v11 + 56);
                  v17 = 8;
                }
                else
                {
                  v17 = 7;
                }
              }
            }
          }
        }
      }
    }
    if ( a3 == v15 )
      goto LABEL_26;
    goto LABEL_17;
  }
  v17 = 0;
  v16 = 0i64;
LABEL_17:
  v18 = a3 - 1;
  v19 = a3 - v15;
  v20 = ((a3 - v15 - 4) >> 2) + 1;
  if ( a3 <= 0 )
    v18 = 0;
  v21 = 4 * v20;
  if ( v18 - v15 <= 2 )
    goto LABEL_183;
  v22 = v11 + 8i64 * v15;
  v23 = 0;
  __asm { vpxor   xmm1, xmm1, xmm1 }
  do
  {
    ++v23;
    __asm { vpaddq  ymm1, ymm1, ymmword ptr [r8] }
    v22 += 32i64;
  }
  while ( v20 > v23 );
  __asm { vpxor   xmm2, xmm2, xmm2 }
  v17 += v21;
  __asm
  {
    vperm2i128 ymm0, ymm1, ymm2, 21h ; '!'
    vpaddq  ymm0, ymm0, ymm1
    vperm2i128 ymm2, ymm0, ymm2, 21h ; '!'
    vpalignr ymm2, ymm2, ymm0, 8
    vpaddq  ymm0, ymm0, ymm2
    vmovq   rax, xmm0
  }
  v16 += _RAX;
  if ( v21 != v19 )
  {
LABEL_183:
    v16 += *(_QWORD *)(v11 + 8i64 * v17);
    v32 = v17 + 1;
    if ( a3 > v17 + 1 )
    {
      v33 = v17 + 2;
      v16 += *(_QWORD *)(v11 + 8i64 * v32);
      if ( a3 > v33 )
        v16 += *(_QWORD *)(v11 + 8i64 * v33);
    }
  }
LABEL_26:
  __asm { vzeroupper }
  v34 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
  if ( v34 )
    goto LABEL_27;
LABEL_28:
  v35 = 1;
  if ( a3 > 0 )
    v35 = a3;
  if ( (a2 >= (unsigned __int64)(v34 + 4) || (unsigned __int64)v34 >= a2 + 32) && v35 > 0xC )
  {
    v36 = 0;
    v37 = -(int)(a2 >> 3) & 3;
    if ( v37 )
    {
      *v34 = *(_QWORD *)a2;
      v36 = 1;
      if ( v37 != 1 )
      {
        v34[1] = *(_QWORD *)(a2 + 8);
        v36 = 2;
        if ( v37 == 3 )
        {
          v34[2] = *(_QWORD *)(a2 + 16);
          v36 = 3;
        }
      }
    }
    v38 = v35 - v37;
    v39 = a3 - 1;
    v40 = ((v38 - 4) >> 2) + 1;
    if ( a3 <= 0 )
      v39 = 0;
    v41 = 4 * v40;
    if ( v39 - v37 <= 2 )
      goto LABEL_43;
    v42 = v37;
    _RAX = 0i64;
    v44 = 0;
    _RDI = a2 + v42 * 8;
    _R9 = &v34[v42];
    do
    {
      __asm { vmovdqa ymm0, ymmword ptr [rdi+rax] }
      ++v44;
      __asm { vmovdqu ymmword ptr [r9+rax], ymm0 }
      _RAX += 32i64;
    }
    while ( v40 > v44 );
    v36 += v41;
    if ( v41 != v38 )
    {
      __asm { vzeroupper }
LABEL_43:
      v34[v36] = *(_QWORD *)(a2 + 8i64 * v36);
      v48 = v36 + 1;
      if ( a3 > v36 + 1 )
      {
        v49 = v36 + 2;
        v34[v48] = *(_QWORD *)(a2 + 8i64 * v48);
        if ( a3 > v49 )
          v34[v49] = *(_QWORD *)(a2 + 8i64 * v49);
      }
      goto LABEL_46;
    }
    __asm { vzeroupper }
  }
  else
  {
    v115 = 0i64;
    do
    {
      v34[v115] = *(_QWORD *)(a2 + 8 * v115);
      ++v115;
    }
    while ( a3 > (int)v115 );
  }
LABEL_46:
  v155 = 0i64;
  v134 = &v155;
  v137 = a1 + 32;
LABEL_47:
  do
  {
    v50 = *v34;
    v51 = *(_DWORD *)(*v34 + 20i64);
    if ( (unsigned int)(v51 - 30) > 1 && v51 != 7 )
      break;
    if ( a3 > 0 )
    {
      v75 = *v34;
      v76 = 1;
      while ( v51 != 30 )
      {
        if ( v51 != 31 )
        {
          if ( v51 != 7 )
            goto LABEL_78;
          if ( *(_QWORD *)(*(_QWORD *)(v75 + 32) + 8i64) != *(_QWORD *)(*(_QWORD *)(v50 + 32) + 8i64) )
            goto LABEL_49;
LABEL_84:
          if ( a3 <= v76 )
            goto LABEL_99;
          goto LABEL_85;
        }
        if ( **(_QWORD **)(v75 + 32) != **(_QWORD **)(v50 + 32) )
          goto LABEL_49;
        if ( a3 <= v76 )
        {
          v79 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
          if ( !v79 )
          {
LABEL_92:
            v80 = 0i64;
            do
            {
              v81 = **(_QWORD **)(v34[v80] + 48i64);
              ++*(_DWORD *)(v81 + 16);
              v79[v80++] = v81;
            }
            while ( a3 > (int)v80 );
            goto LABEL_94;
          }
LABEL_130:
          v116 = Size;
          Sizec = (size_t)v79;
          memset(v79, 0, v116);
          v79 = (_QWORD *)Sizec;
LABEL_131:
          if ( a3 > 0 )
            goto LABEL_92;
LABEL_94:
          Blocka = v79;
          v82 = nc_concat(v79, a3, 0);
          Sizeb = nc_stop_grad((__int64)v82);
          v139 = **(_DWORD ***)(v50 + 32);
          v83 = (_DWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(128i64, 64i64);
          v84 = Blocka;
          if ( v83 )
          {
            v149 = Blocka;
            memset(v83, 0, 0x80ui64);
            Blockb = v139;
            v83[4] = 1;
            v83[5] = 31;
            v83[6] = 1;
            v140 = v83;
            v85 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, _DWORD *, void *))v129)(8i64, 64i64, v83, v84);
            *((_QWORD *)v140 + 4) = v85;
            if ( Blockb )
            {
              ++Blockb[4];
              *v85 = Blockb;
            }
            else
            {
              *v85 = 0i64;
            }
            v86 = *(_QWORD *)(a1 + 72);
            *(_QWORD *)(a1 + 72) = v86 + 1;
            *((_QWORD *)v140 + 12) = v86;
            v87 = *(_QWORD *)(a1 + 32);
            *(_QWORD *)(v87 + 8) = v140;
            *(_QWORD *)v140 = v87;
            *((_QWORD *)v140 + 1) = a1 + 32;
            *(_QWORD *)(a1 + 32) = v140;
            v140[10] = 1;
            v88 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(8i64, 64i64);
            *((_QWORD *)v140 + 6) = v88;
            ++Sizeb[4];
            *v88 = Sizeb;
            *((_QWORD *)v140 + 7) = *(_QWORD *)(v50 + 56);
            nc_free_tensor(Sizeb);
            Block = _aligned_free;
            _aligned_free(v149);
            *v134 = (__int64)v140;
            v52 = v155;
            if ( !v155 )
              goto LABEL_98;
            goto LABEL_61;
          }
LABEL_125:
          MEMORY[0x10] = 0;
          BUG();
        }
LABEL_85:
        v78 = v76++;
        v75 = v34[v78];
        if ( v51 != *(_DWORD *)(v75 + 20) )
          goto LABEL_49;
      }
      v77 = *(_QWORD **)(v75 + 32);
      if ( *v77 != **(_QWORD **)(v50 + 32)
        || v77[2]
        || *(_DWORD *)(v75 + 56) != *(_DWORD *)(v50 + 56)
        || *(_DWORD *)(v75 + 60)
        || !*(_QWORD *)(*(_QWORD *)(v75 + 48) + 8i64) )
      {
        break;
      }
      goto LABEL_84;
    }
LABEL_99:
    switch ( v51 )
    {
      case 30:
        v97 = (__int64 *)((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
        v98 = v97;
        if ( v97 )
        {
          Blocke = v97;
          memset(v97, 0, Size);
          v98 = Blocke;
        }
        for ( i = 0i64; a3 > (int)i; ++i )
        {
          v100 = *(_QWORD *)(*(_QWORD *)(v34[i] + 48i64) + 8i64);
          ++*(_DWORD *)(v100 + 16);
          v98[i] = v100;
        }
        v152 = v98;
        v101 = nc_concat(v98, a3, 1);
        Blockd = nc_stop_grad((__int64)v101);
        v150 = **(_DWORD ***)(v50 + 32);
        v102 = (_DWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(128i64, 64i64);
        if ( !v102 )
          goto LABEL_125;
        v154 = v152;
        memset(v102, 0, 0x80ui64);
        v153 = v150;
        v102[4] = 1;
        v102[5] = 30;
        v102[6] = 3;
        v151 = v102;
        v103 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(24i64, 64i64);
        *((_QWORD *)v151 + 4) = v103;
        if ( v153 )
        {
          ++v153[4];
          *v103 = v153;
        }
        else
        {
          *v103 = 0i64;
        }
        v103[1] = 0i64;
        v103[2] = 0i64;
        v104 = *(_QWORD *)(a1 + 72);
        *(_QWORD *)(a1 + 72) = v104 + 1;
        *((_QWORD *)v151 + 12) = v104;
        v105 = *(_QWORD *)(a1 + 32);
        *(_QWORD *)(v105 + 8) = v151;
        *(_QWORD *)v151 = v105;
        *((_QWORD *)v151 + 1) = v137;
        v106 = *(__int64 **)(v50 + 48);
        *(_QWORD *)(a1 + 32) = v151;
        v107 = *v106;
        v151[10] = 2;
        v108 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(16i64, 64i64);
        *((_QWORD *)v151 + 6) = v108;
        ++*(_DWORD *)(v107 + 16);
        *v108 = v107;
        ++Blockd[4];
        v108[1] = Blockd;
        v151[14] = *(_DWORD *)(v50 + 56);
        v151[15] = *(_DWORD *)(v50 + 60);
        nc_free_tensor(Blockd);
        _aligned_free(v154);
        v94 = v151;
        v95 = 1i64;
        v92 = (_QWORD *)*((_QWORD *)v151 + 4);
        break;
      case 31:
        v79 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
        if ( v79 )
          goto LABEL_130;
        goto LABEL_131;
      case 7:
        Blockc = *(_DWORD **)(*(_QWORD *)(v50 + 32) + 8i64);
        v90 = (_DWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(128i64, 64i64);
        v91 = v90;
        if ( !v90 )
          goto LABEL_125;
        memset(v90, 0, 0x80ui64);
        v90[4] = 1;
        v90[5] = 7;
        v90[6] = 2;
        v92 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(16i64, 64i64);
        v91[4] = v92;
        *v92 = 0i64;
        if ( Blockc )
        {
          ++Blockc[4];
          v92[1] = Blockc;
        }
        else
        {
          v92[1] = 0i64;
        }
        v93 = *(_QWORD *)(a1 + 72);
        v94 = v91;
        v95 = 0i64;
        *(_QWORD *)(a1 + 72) = v93 + 1;
        v91[12] = v93;
        v96 = *(_QWORD *)(a1 + 32);
        *(_QWORD *)(v96 + 8) = v91;
        *v91 = v96;
        v91[1] = v137;
        *(_QWORD *)(a1 + 32) = v91;
        break;
      default:
LABEL_78:
        abort();
    }
    v109 = v134;
    v134 = &v92[v95];
    *v109 = (__int64)v94;
    if ( a3 <= 0 )
      goto LABEL_47;
    v110 = v34;
    v111 = 1;
    v112 = 0;
    while ( 1 )
    {
      v113 = *(_QWORD *)(*(_QWORD *)(*v110 + 32i64) + v95 * 8);
      v114 = *(_DWORD *)(v113 + 16) <= 1;
      *v110 = v113;
      if ( v114 )
        break;
      if ( a3 <= v111 )
        goto LABEL_49;
      v112 = 1;
LABEL_120:
      ++v110;
      ++v111;
    }
    if ( a3 > v111 )
      goto LABEL_120;
  }
  while ( !v112 );
LABEL_49:
  v52 = v155;
  if ( !v155 )
  {
    Block = _aligned_free;
    goto LABEL_98;
  }
  if ( v134 )
  {
    v53 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v129)(128i64, 64i64);
    if ( !v53 )
      goto LABEL_125;
    memset(v53, 0, 0x80ui64);
    *((_DWORD *)v53 + 4) = 1;
    *((_DWORD *)v53 + 5) = 14;
    *((_DWORD *)v53 + 6) = a3;
    v54 = ((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
    v53[4] = v54;
    if ( a3 <= 0 )
    {
      v127 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = v127 + 1;
      v53[12] = v127;
      v128 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(v128 + 8) = v53;
      *v53 = v128;
      v53[1] = a1 + 32;
      *(_QWORD *)(a1 + 32) = v53;
      *((_DWORD *)v53 + 16) = a4;
      v53[7] = ((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
    }
    else
    {
      v55 = 0i64;
      do
      {
        while ( 1 )
        {
          v56 = v34[v55];
          if ( !v56 )
            break;
          ++*(_DWORD *)(v56 + 16);
          *(_QWORD *)(v54 + 8 * v55++) = v56;
          if ( a3 <= (int)v55 )
            goto LABEL_56;
        }
        *(_QWORD *)(v54 + 8 * v55++) = 0i64;
      }
      while ( a3 > (int)v55 );
LABEL_56:
      v57 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = v57 + 1;
      v53[12] = v57;
      v58 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(v58 + 8) = v53;
      *v53 = v58;
      v53[1] = a1 + 32;
      *(_QWORD *)(a1 + 32) = v53;
      *((_DWORD *)v53 + 16) = a4;
      v59 = ((__int64 (__fastcall *)(__int64, __int64))v129)(Size, 64i64);
      v53[7] = v59;
      v60 = v59;
      for ( j = 0i64; ; j += 8i64 )
      {
        *(_QWORD *)(v60 + j) = *(_QWORD *)(v11 + j);
        if ( j == 8i64 * (unsigned int)(a3 - 1) )
          break;
        v60 = v53[7];
      }
    }
    *v134 = (__int64)v53;
    v52 = v155;
  }
  Block = _aligned_free;
LABEL_61:
  if ( a3 > 0 )
  {
    v62 = (unsigned int)(a3 - 1);
    v135 = v16;
    v63 = 0i64;
    v138 = v11;
    Sizea = v62 + 1;
    v148 = v34;
    v64 = 0i64;
    do
    {
      v65 = *(_QWORD *)(a2 + 8 * v64);
      v66 = 0i64;
      v67 = 0;
      while ( v67 < *(_DWORD *)(v65 + 24) )
      {
        ++v67;
        v68 = *(__int64 **)(*(_QWORD *)(v65 + 32) + v66);
        v66 += 8i64;
        nc_free_node(v68);
      }
      v69 = 0i64;
      v70 = 0;
      ((void (__fastcall *)(_QWORD))Block)(*(_QWORD *)(v65 + 32));
      v71 = *(_DWORD *)(v65 + 40);
      *(_QWORD *)(v65 + 32) = 0i64;
      *(_DWORD *)(v65 + 24) = 0;
      if ( v71 > 0 )
      {
        do
        {
          ++v70;
          v72 = *(_DWORD **)(*(_QWORD *)(v65 + 48) + v69);
          v69 += 8i64;
          nc_free_tensor(v72);
        }
        while ( v70 < *(_DWORD *)(v65 + 40) );
      }
      ((void (__fastcall *)(_QWORD))Block)(*(_QWORD *)(v65 + 48));
      v73 = *(_DWORD *)(v65 + 20) == 14;
      *(_QWORD *)(v65 + 48) = 0i64;
      *(_DWORD *)(v65 + 40) = 0;
      if ( v73 )
        ((void (__fastcall *)(_QWORD))Block)(*(_QWORD *)(v65 + 56));
      free(*(void **)(v65 + 104));
      *(_QWORD *)(v65 + 104) = 0i64;
      *(_DWORD *)(v65 + 20) = 15;
      *(_DWORD *)(v65 + 24) = 1;
      v74 = (__int64 *)((__int64 (__fastcall *)(__int64, __int64))v129)(8i64, 64i64);
      if ( !v74 )
      {
        *(_QWORD *)(v65 + 32) = 0i64;
        ++*(_DWORD *)(v52 + 16);
        MEMORY[0] = v52;
        BUG();
      }
      *v74 = 0i64;
      *(_QWORD *)(v65 + 32) = v74;
      ++*(_DWORD *)(v52 + 16);
      *v74 = v52;
      *(_QWORD *)(v65 + 64) = v63;
      *(_DWORD *)(v65 + 56) = a4;
      *(_QWORD *)(v65 + 72) = v135;
      v63 += *(_QWORD *)(v138 + 8 * v64++);
    }
    while ( v64 != Sizea );
    v34 = v148;
  }
  nc_free_node((__int64 *)v52);
LABEL_98:
  ((void (__fastcall *)(_QWORD *))Block)(v34);
  return ((__int64 (__fastcall *)(unsigned __int64))Block)(v141);
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

