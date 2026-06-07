// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_combine_nodes
// Included functions: 1

// ======================================================
// Function: nc_combine_nodes @ 0x28870
// ======================================================

void __fastcall nc_combine_nodes(
        __int64 a1,
        unsigned __int64 a2,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6,
        __m128 _XMM0,
        __m128 _XMM1,
        __m128 _XMM2,
        char a10)
{
  unsigned int v12; // r13d
  unsigned int v13; // eax
  __int64 v14; // rbx
  int v15; // esi
  unsigned int v16; // edi
  unsigned int v17; // ecx
  int v18; // r8d
  _QWORD *v19; // r10
  unsigned int v20; // eax
  unsigned __int64 v29; // rax
  int v30; // edx
  unsigned __int64 v31; // r9
  __int64 *v32; // r15
  int v33; // ecx
  unsigned int v34; // eax
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  __int64 v38; // rax
  unsigned int v41; // esi
  int v42; // r11d
  int v44; // ecx
  int v45; // eax
  int v46; // ecx
  int v47; // ebx
  __int64 v48; // r14
  int v49; // eax
  int v50; // edx
  _QWORD *v51; // r14
  __int64 v52; // rbx
  _DWORD *v53; // rax
  _DWORD *v54; // r13
  __int64 v55; // r12
  unsigned __int64 v56; // rbx
  __int64 v57; // r14
  __int64 v58; // rdi
  __int64 v59; // rax
  __int64 v60; // rax
  __int64 v61; // rax
  __int64 v62; // rdx
  __int64 i; // rax
  __int64 v64; // r13
  __int64 *v65; // r12
  __int64 v66; // r15
  __int64 v67; // r14
  int v68; // ebx
  void *v69; // rdi
  __int64 v70; // r14
  int v71; // ebx
  int v72; // eax
  void *v73; // rdi
  bool v74; // zf
  _QWORD *v75; // rax
  __int64 v76; // rsi
  int v77; // ecx
  _QWORD *v78; // rdi
  _QWORD *v79; // rdx
  __int64 v80; // rdx
  _QWORD *v81; // r13
  __int64 *v82; // rbx
  __int64 v83; // rax
  void *v84; // rax
  void *v85; // r12
  _DWORD *v86; // rax
  _DWORD *v87; // r13
  _QWORD *v88; // rax
  __int64 v89; // rax
  __int64 v90; // rax
  _QWORD *v91; // rax
  __int64 v92; // r14
  _DWORD *v93; // rax
  _DWORD *v94; // r13
  _QWORD *v95; // rax
  __int64 v96; // rcx
  __int64 v97; // rdi
  __int64 v98; // rcx
  void **v99; // rcx
  int v100; // esi
  int v101; // r8d
  __int64 *v102; // rax
  __int64 v103; // rdx
  bool v104; // cc
  __int64 v105; // rax
  __int64 *v106; // r12
  _QWORD *v107; // rbx
  __int64 v108; // rax
  int v109; // ebx
  void *v110; // rax
  __int64 v111; // rax
  __int64 *v112; // rax
  _DWORD *v113; // rax
  __int64 v114; // rax
  __int64 v115; // r12
  __int64 v116; // rbx
  _QWORD *v117; // r12
  __int64 v118; // rdi
  __int64 v119; // rax
  __int64 v120; // rax
  __int64 *v121; // rax
  __int64 v122; // rax
  _QWORD *v123; // rax
  __int64 v124; // r12
  unsigned __int64 v125; // rax
  unsigned int v127; // eax
  int v128; // ecx
  unsigned int v129; // edi
  unsigned int v130; // esi
  int v131; // r9d
  unsigned int v135; // eax
  int v136; // eax
  int v137; // ecx
  __int64 v138; // [rsp-F0h] [rbp-F8h]
  unsigned int v139; // [rsp-E8h] [rbp-F0h]
  void *v140; // [rsp-E8h] [rbp-F0h]
  _QWORD *v141; // [rsp-E0h] [rbp-E8h]
  __int64 v142; // [rsp-D8h] [rbp-E0h]
  __int64 v143; // [rsp-D0h] [rbp-D8h]
  _QWORD *v144; // [rsp-C8h] [rbp-D0h]
  __int64 v145; // [rsp-C0h] [rbp-C8h]
  __int64 *v146; // [rsp-B8h] [rbp-C0h]
  unsigned __int64 v147; // [rsp-B8h] [rbp-C0h]
  int v148; // [rsp-B0h] [rbp-B8h]
  _QWORD *v150; // [rsp-A8h] [rbp-B0h]
  unsigned __int64 v151; // [rsp-A0h] [rbp-A8h]
  _QWORD *v152; // [rsp-A0h] [rbp-A8h]
  __int64 v153; // [rsp-A0h] [rbp-A8h]
  void **v154; // [rsp-98h] [rbp-A0h]
  unsigned __int64 v155; // [rsp-90h] [rbp-98h]
  unsigned __int64 v156; // [rsp-90h] [rbp-98h]
  int v157; // [rsp-90h] [rbp-98h]
  __int64 v158; // [rsp-90h] [rbp-98h]
  __int64 *v159; // [rsp-90h] [rbp-98h]
  unsigned int v160; // [rsp-90h] [rbp-98h]
  int v162; // [rsp-88h] [rbp-90h]
  __int64 v163; // [rsp-88h] [rbp-90h]
  void *v164; // [rsp-88h] [rbp-90h]
  __int64 v165; // [rsp-88h] [rbp-90h]
  int v166; // [rsp-88h] [rbp-90h]
  size_t v167; // [rsp-80h] [rbp-88h]
  __int64 v168; // [rsp-80h] [rbp-88h]
  _QWORD *v169; // [rsp-80h] [rbp-88h]
  __int64 *v171; // [rsp-78h] [rbp-80h]
  void *v172; // [rsp-68h] [rbp-70h] BYREF
  __int64 v173; // [rsp-60h] [rbp-68h]
  __int64 v174; // [rsp-58h] [rbp-60h]
  __int64 v175; // [rsp-50h] [rbp-58h]
  char *v176; // [rsp-28h] [rbp-30h]
  void *v177; // [rsp-8h] [rbp-10h]
  void *retaddr; // [rsp+8h] [rbp+0h]

  v177 = retaddr;
  v176 = &a10;
  if ( a3 <= 0 )
    __assert_fail("count >= 1", "libnc.c", 0x1E3Au, "nc_combine_nodes");
  if ( a6 )
  {
    v12 = a3 - 1;
    v144 = 0LL;
    v167 = 8LL * a3;
    goto LABEL_4;
  }
  v166 = a3;
  v167 = 8LL * a3;
  v125 = nc_malloc(v167);
  a3 = v166;
  _R8 = a5;
  v144 = (_QWORD *)v125;
  v127 = -(int)(v125 >> 3) & 3;
  if ( v127 > v166 )
    v127 = v166;
  if ( v166 > 6 )
  {
    if ( !v127 )
    {
      v128 = 0;
      goto LABEL_126;
    }
  }
  else
  {
    v127 = v166;
  }
  *v144 = a5;
  if ( v127 == 1 )
  {
    v128 = 1;
  }
  else
  {
    v144[1] = a5;
    if ( v127 == 2 )
    {
      v128 = 2;
    }
    else
    {
      v144[2] = a5;
      if ( v127 == 3 )
      {
        v128 = 3;
      }
      else
      {
        v144[3] = a5;
        if ( v127 == 4 )
        {
          v128 = 4;
        }
        else
        {
          v144[4] = a5;
          if ( v127 == 6 )
          {
            v144[5] = a5;
            v128 = 6;
          }
          else
          {
            v128 = 5;
          }
        }
      }
    }
  }
  v12 = v166 - 1;
  if ( v166 != v127 )
  {
LABEL_126:
    v12 = v166 - 1;
    v129 = v166 - v127;
    v130 = ((v166 - v127 - 4) >> 2) + 1;
    v131 = 4 * v130;
    if ( v166 - 1 - v127 <= 2 )
      goto LABEL_146;
    __asm
    {
      vmovq   xmm3, r8
      vpbroadcastq ymm0, xmm3
    }
    _R10 = &v144[v127];
    v135 = 0;
    do
    {
      ++v135;
      __asm { vmovdqa ymmword ptr [r10], ymm0 }
      _R10 += 4;
    }
    while ( v130 > v135 );
    v128 += v131;
    if ( v129 != v131 )
    {
LABEL_146:
      v144[v128] = a5;
      v136 = v128 + 1;
      if ( v166 > v128 + 1 )
      {
        v137 = v128 + 2;
        v144[v136] = a5;
        if ( v166 > v137 )
          v144[v137] = a5;
      }
    }
  }
  a6 = (unsigned __int64)v144;
LABEL_4:
  v150 = (_QWORD *)a6;
  v13 = -(int)(a6 >> 3) & 3;
  if ( v13 > a3 )
    v13 = a3;
  if ( a3 <= 8 )
  {
    v13 = a3;
    goto LABEL_8;
  }
  if ( v13 )
  {
LABEL_8:
    v14 = *(_QWORD *)a6;
    if ( v13 == 1 )
    {
      v15 = 1;
    }
    else
    {
      v14 += *(_QWORD *)(a6 + 8);
      if ( v13 == 2 )
      {
        v15 = 2;
      }
      else
      {
        v14 += *(_QWORD *)(a6 + 16);
        if ( v13 == 3 )
        {
          v15 = 3;
        }
        else
        {
          v14 += *(_QWORD *)(a6 + 24);
          if ( v13 == 4 )
          {
            v15 = 4;
          }
          else
          {
            v14 += *(_QWORD *)(a6 + 32);
            if ( v13 == 5 )
            {
              v15 = 5;
            }
            else
            {
              v14 += *(_QWORD *)(a6 + 40);
              if ( v13 == 6 )
              {
                v15 = 6;
              }
              else
              {
                v14 += *(_QWORD *)(a6 + 48);
                if ( v13 == 8 )
                {
                  v14 += *(_QWORD *)(a6 + 56);
                  v15 = 8;
                }
                else
                {
                  v15 = 7;
                }
              }
            }
          }
        }
      }
    }
    if ( a3 == v13 )
      goto LABEL_24;
    goto LABEL_17;
  }
  v15 = 0;
  v14 = 0LL;
LABEL_17:
  v16 = a3 - v13;
  v17 = ((a3 - v13 - 4) >> 2) + 1;
  v18 = 4 * v17;
  if ( v12 - v13 <= 2 )
    goto LABEL_147;
  v19 = (_QWORD *)(a6 + 8LL * v13);
  v20 = 0;
  __asm { vpxor   xmm1, xmm1, xmm1 }
  do
  {
    ++v20;
    __asm { vpaddq  ymm1, ymm1, ymmword ptr [r10] }
    v19 += 4;
  }
  while ( v17 > v20 );
  __asm { vpxor   xmm2, xmm2, xmm2 }
  v15 += v18;
  __asm
  {
    vperm2i128 ymm0, ymm1, ymm2, 21h ; '!'
    vpaddq  ymm0, ymm0, ymm1
    vperm2i128 ymm2, ymm0, ymm2, 21h ; '!'
    vpalignr ymm2, ymm2, ymm0, 8
    vpaddq  ymm0, ymm0, ymm2
    vmovq   rcx, xmm0
  }
  v14 += _RCX;
  if ( v18 != v16 )
  {
LABEL_147:
    v14 += *(_QWORD *)(a6 + 8LL * v15);
    if ( a3 > v15 + 1 )
    {
      v14 += *(_QWORD *)(a6 + 8LL * (v15 + 1));
      if ( a3 > v15 + 2 )
        v14 += *(_QWORD *)(a6 + 8LL * (v15 + 2));
    }
  }
LABEL_24:
  v155 = a6;
  v162 = a3;
  __asm { vzeroupper }
  v29 = nc_mallocz(v167);
  v30 = v162;
  v31 = v155;
  v32 = (__int64 *)v29;
  if ( (v29 >= a2 + 32 || a2 >= v29 + 32) && (unsigned int)v162 > 0xC )
  {
    v33 = 0;
    v34 = -(int)(a2 >> 3) & 3;
    if ( v34 )
    {
      *v32 = *(_QWORD *)a2;
      v33 = 1;
      if ( v34 != 1 )
      {
        v32[1] = *(_QWORD *)(a2 + 8);
        v33 = 2;
        if ( v34 == 3 )
        {
          v32[2] = *(_QWORD *)(a2 + 16);
          v33 = 3;
        }
      }
    }
    _RDI = 0LL;
    v36 = 0;
    v37 = v162 - v34;
    v38 = v34;
    _R12 = a2 + v38 * 8;
    _RAX = &v32[v38];
    v41 = ((v37 - 4) >> 2) + 1;
    v42 = 4 * v41;
    do
    {
      __asm { vmovdqa ymm0, ymmword ptr [r12+rdi] }
      ++v36;
      __asm { vmovdqu ymmword ptr [rax+rdi], ymm0 }
      _RDI += 32LL;
    }
    while ( v41 > v36 );
    v44 = v42 + v33;
    if ( v42 == v37
      || (v32[v44] = *(_QWORD *)(a2 + 8LL * v44), v45 = v44 + 1, v162 <= v44 + 1)
      || (v46 = v44 + 2, v32[v45] = *(_QWORD *)(a2 + 8LL * v45), v162 <= v46) )
    {
      __asm { vzeroupper }
    }
    else
    {
      v32[v46] = *(_QWORD *)(a2 + 8LL * v46);
      __asm { vzeroupper }
    }
  }
  else
  {
    v105 = 0LL;
    do
    {
      v32[v105] = *(_QWORD *)(a2 + 8 * v105);
      ++v105;
    }
    while ( v162 > (int)v105 );
  }
  v172 = 0LL;
  v142 = v12;
  v143 = 8LL * v12 + 8;
  v146 = (__int64 *)((char *)v32 + v143);
  v154 = &v172;
  v156 = a2;
  v151 = v31;
  v145 = a1 + 32;
  v163 = v14;
  v47 = v30;
LABEL_37:
  v48 = *v32;
  v49 = *(_DWORD *)(*v32 + 20);
  if ( (unsigned int)(v49 - 30) > 1 && v49 != 7 )
    goto LABEL_39;
  v76 = *v32;
  v77 = 1;
  while ( v49 == 30 )
  {
    v78 = *(_QWORD **)(v48 + 32);
    v79 = *(_QWORD **)(v76 + 32);
    if ( *v79 != *v78
      || v79[2]
      || *(_DWORD *)(v76 + 56) != *(_DWORD *)(v48 + 56)
      || *(_DWORD *)(v76 + 60)
      || !*(_QWORD *)(*(_QWORD *)(v76 + 48) + 8LL) )
    {
      goto LABEL_39;
    }
LABEL_69:
    if ( v47 <= v77 )
    {
      if ( v49 == 30 )
      {
        v106 = v32;
        v139 = v47;
        v141 = (_QWORD *)nc_mallocz(v167);
        v107 = v141;
        do
        {
          v108 = *v106++;
          *v107++ = nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v108 + 48) + 8LL));
        }
        while ( v106 != v146 );
        v109 = v139;
        v110 = (void *)nc_hconcat(v141, v139);
        v111 = nc_stop_grad(v110);
        v174 = 0LL;
        v140 = (void *)v111;
        v112 = *(__int64 **)(v48 + 32);
        v175 = 0LL;
        v173 = *v112;
        v113 = (_DWORD *)nc_mallocz(0x80uLL);
        v113[4] = 1;
        v94 = v113;
        v113[5] = 30;
        v113[6] = 3;
        v114 = nc_malloc(0x18uLL);
        *((_QWORD *)v94 + 4) = v114;
        v115 = v114;
        v148 = v109;
        v116 = 0LL;
        while ( 1 )
        {
          v118 = *(__int64 *)((char *)&v173 + v116);
          if ( v118 )
          {
            v117 = (_QWORD *)(v116 + v115);
            v116 += 8LL;
            *v117 = nc_dup_node(v118);
            if ( v116 == 24 )
              goto LABEL_107;
          }
          else
          {
            *(_QWORD *)(v115 + v116) = 0LL;
            v116 += 8LL;
            if ( v116 == 24 )
            {
LABEL_107:
              v47 = v148;
              v119 = *(_QWORD *)(a1 + 72);
              *(_QWORD *)(a1 + 72) = v119 + 1;
              *((_QWORD *)v94 + 12) = v119;
              v120 = *(_QWORD *)(a1 + 32);
              *(_QWORD *)(v120 + 8) = v94;
              *(_QWORD *)v94 = v120;
              *((_QWORD *)v94 + 1) = v145;
              v121 = *(__int64 **)(v48 + 48);
              *(_QWORD *)(a1 + 32) = v94;
              v122 = *v121;
              v94[10] = 2;
              v138 = v122;
              v123 = (_QWORD *)nc_malloc(0x10uLL);
              *((_QWORD *)v94 + 6) = v123;
              *v123 = nc_dup_tensor(v138);
              v124 = *((_QWORD *)v94 + 6);
              *(_QWORD *)(v124 + 8) = nc_dup_tensor(v140);
              v94[14] = *(_DWORD *)(v48 + 56);
              v94[15] = *(_DWORD *)(v48 + 60);
              nc_free_tensor(v140);
              nc_free(v141);
              v95 = (_QWORD *)*((_QWORD *)v94 + 4);
              v97 = 1LL;
              goto LABEL_86;
            }
          }
          v115 = *((_QWORD *)v94 + 4);
        }
      }
      v92 = v78[1];
      v173 = 0LL;
      v174 = v92;
      v93 = (_DWORD *)nc_mallocz(0x80uLL);
      v93[4] = 1;
      v94 = v93;
      v93[5] = 7;
      v93[6] = 2;
      v95 = (_QWORD *)nc_malloc(0x10uLL);
      *((_QWORD *)v94 + 4) = v95;
      *v95 = 0LL;
      if ( v92 )
      {
        v95[1] = nc_dup_node(v92);
        v95 = (_QWORD *)*((_QWORD *)v94 + 4);
      }
      else
      {
        v95[1] = 0LL;
      }
      v96 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = v96 + 1;
      v97 = 0LL;
      *((_QWORD *)v94 + 12) = v96;
      v98 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(v98 + 8) = v94;
      *(_QWORD *)v94 = v98;
      *((_QWORD *)v94 + 1) = v145;
      *(_QWORD *)(a1 + 32) = v94;
LABEL_86:
      v99 = v154;
      v100 = 1;
      v101 = 0;
      v154 = (void **)&v95[v97];
      v102 = v32;
      *v99 = v94;
      while ( 1 )
      {
        v103 = *(_QWORD *)(*(_QWORD *)(*v102 + 32) + v97 * 8);
        v104 = *(_DWORD *)(v103 + 16) <= 1;
        *v102 = v103;
        if ( v104 )
        {
          if ( v47 <= v100 )
          {
            if ( v101 )
              goto LABEL_39;
            goto LABEL_37;
          }
        }
        else
        {
          if ( v100 >= v47 )
            goto LABEL_39;
          v101 = 1;
        }
        ++v102;
        ++v100;
      }
    }
LABEL_70:
    v80 = v77++;
    v76 = v32[v80];
    if ( v49 != *(_DWORD *)(v76 + 20) )
      goto LABEL_39;
  }
  if ( v49 != 31 )
  {
    if ( v49 != 7 )
      abort();
    v78 = *(_QWORD **)(v48 + 32);
    if ( *(_QWORD *)(*(_QWORD *)(v76 + 32) + 8LL) != v78[1] )
      goto LABEL_39;
    goto LABEL_69;
  }
  if ( **(_QWORD **)(v76 + 32) == **(_QWORD **)(v48 + 32) )
  {
    if ( v47 <= v77 )
    {
      v153 = *v32;
      v51 = (_QWORD *)v156;
      v160 = v47;
      v169 = (_QWORD *)nc_mallocz(v167);
      v81 = v169;
      v82 = v32;
      do
      {
        v83 = *v82++;
        *v81++ = nc_dup_tensor(**(_QWORD **)(v83 + 48));
      }
      while ( v82 != v146 );
      v52 = v163;
      v84 = (void *)nc_vconcat(v169, v160);
      v85 = (void *)nc_stop_grad(v84);
      v173 = **(_QWORD **)(v153 + 32);
      v165 = v173;
      v86 = (_DWORD *)nc_mallocz(0x80uLL);
      v86[4] = 1;
      v87 = v86;
      v86[5] = 31;
      v86[6] = 1;
      v88 = (_QWORD *)nc_malloc(8uLL);
      *((_QWORD *)v87 + 4) = v88;
      if ( v165 )
        *v88 = nc_dup_node(v165);
      else
        *v88 = 0LL;
      v89 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = v89 + 1;
      *((_QWORD *)v87 + 12) = v89;
      v90 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(v90 + 8) = v87;
      *(_QWORD *)v87 = v90;
      *((_QWORD *)v87 + 1) = a1 + 32;
      *(_QWORD *)(a1 + 32) = v87;
      v87[10] = 1;
      v91 = (_QWORD *)nc_malloc(8uLL);
      *((_QWORD *)v87 + 6) = v91;
      *v91 = nc_dup_tensor(v85);
      *((_QWORD *)v87 + 7) = *(_QWORD *)(v153 + 56);
      nc_free_tensor(v85);
      nc_free(v169);
      *v154 = v87;
      v164 = v172;
      if ( v172 )
        goto LABEL_50;
      goto LABEL_81;
    }
    goto LABEL_70;
  }
LABEL_39:
  v50 = v47;
  v51 = (_QWORD *)v156;
  v52 = v163;
  v157 = v50;
  v147 = v151;
  v164 = v172;
  if ( v172 )
  {
    if ( v154 )
    {
      v53 = (_DWORD *)nc_mallocz(0x80uLL);
      v53[4] = 1;
      v54 = v53;
      v53[6] = v157;
      v53[5] = 14;
      v158 = v52;
      v152 = v51;
      v55 = nc_malloc(v167);
      v56 = 0LL;
      *((_QWORD *)v54 + 4) = v55;
      v57 = 8 * v142;
      while ( 1 )
      {
        v58 = v32[v56 / 8];
        if ( v58 )
        {
          *(_QWORD *)(v56 + v55) = nc_dup_node(v58);
          if ( v56 == v57 )
            goto LABEL_46;
        }
        else
        {
          *(_QWORD *)(v55 + v56) = 0LL;
          if ( v56 == v57 )
          {
LABEL_46:
            v52 = v158;
            v59 = *(_QWORD *)(a1 + 72);
            v51 = v152;
            *(_QWORD *)(a1 + 72) = v59 + 1;
            *((_QWORD *)v54 + 12) = v59;
            v60 = *(_QWORD *)(a1 + 32);
            *(_QWORD *)(v60 + 8) = v54;
            *(_QWORD *)v54 = v60;
            *((_QWORD *)v54 + 1) = a1 + 32;
            *(_QWORD *)(a1 + 32) = v54;
            v54[16] = a4;
            v61 = nc_malloc(v167);
            *((_QWORD *)v54 + 7) = v61;
            v62 = v61;
            for ( i = 0LL; ; i += 8LL )
            {
              *(_QWORD *)(v62 + i) = *(_QWORD *)(v147 + i);
              if ( i == 8 * v142 )
                break;
              v62 = *((_QWORD *)v54 + 7);
            }
            *v154 = v54;
            v164 = v172;
            break;
          }
        }
        v55 = *((_QWORD *)v54 + 4);
        v56 += 8LL;
      }
    }
LABEL_50:
    v159 = v32;
    v64 = 0LL;
    v65 = v51;
    v168 = v52;
    v171 = (_QWORD *)((char *)v51 + v143);
    do
    {
      v66 = *v65;
      v67 = 0LL;
      v68 = 0;
      while ( v68 < *(_DWORD *)(v66 + 24) )
      {
        ++v68;
        v69 = *(void **)(*(_QWORD *)(v66 + 32) + v67);
        v67 += 8LL;
        nc_free_node(v69);
      }
      v70 = 0LL;
      v71 = 0;
      nc_free(*(void **)(v66 + 32));
      v72 = *(_DWORD *)(v66 + 40);
      *(_QWORD *)(v66 + 32) = 0LL;
      *(_DWORD *)(v66 + 24) = 0;
      if ( v72 > 0 )
      {
        do
        {
          ++v71;
          v73 = *(void **)(*(_QWORD *)(v66 + 48) + v70);
          v70 += 8LL;
          nc_free_tensor(v73);
        }
        while ( v71 < *(_DWORD *)(v66 + 40) );
      }
      nc_free(*(void **)(v66 + 48));
      v74 = *(_DWORD *)(v66 + 20) == 14;
      *(_QWORD *)(v66 + 48) = 0LL;
      *(_DWORD *)(v66 + 40) = 0;
      if ( v74 )
        nc_free(*(void **)(v66 + 56));
      ++v65;
      free(*(void **)(v66 + 104));
      *(_QWORD *)(v66 + 104) = 0LL;
      *(_DWORD *)(v66 + 20) = 15;
      *(_DWORD *)(v66 + 24) = 1;
      v75 = (_QWORD *)nc_mallocz(8uLL);
      *(_QWORD *)(v66 + 32) = v75;
      *v75 = nc_dup_node(v164);
      *(_QWORD *)(v66 + 64) = v64;
      *(_DWORD *)(v66 + 56) = a4;
      *(_QWORD *)(v66 + 72) = v168;
      v64 += *v150++;
    }
    while ( v65 != v171 );
    v32 = v159;
    nc_free_node(v164);
  }
LABEL_81:
  nc_free(v32);
  nc_free(v144);
}

