// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_backward
// Included functions: 8

// ======================================================
// Function: nc_backward @ 0x66A2FDC0
// ======================================================

void __fastcall nc_backward(__int64 a1, __int64 a2, void (__fastcall *a3)(_QWORD, _QWORD), char a4)
{
  __int64 v7; // rdi
  __int64 v8; // r8
  char *v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // r9
  char *v13; // rax
  char *v14; // r10
  __int64 v15; // r8
  __int64 v16; // r8
  __int64 v17; // r14
  char *v18; // r15
  __int64 v19; // r13
  __int64 v20; // rax
  _QWORD *v21; // rbp
  _DWORD *col; // rax
  __int64 v23; // rax
  __int64 v24; // rdx
  __int64 v25; // rsi
  _QWORD *v26; // r8
  __int64 v27; // rbx
  _QWORD *v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rbx
  __int64 v32; // r8
  __int64 v33; // rdx
  _QWORD *v34; // rax
  __int64 v35; // rax
  int v36; // esi
  int v37; // ebx
  __int64 *v38; // rax
  __int64 v39; // rdi
  __int64 *v40; // rax
  _QWORD *v41; // r8
  __int64 v42; // rcx
  _QWORD *v43; // rax
  __int64 v44; // rdi
  _QWORD *v45; // r8
  __int64 v46; // rcx
  _QWORD *v47; // rax
  int v48; // edx
  int v49; // r9d
  __int64 v50; // rdx
  __int64 v52; // rdx
  _DWORD *v53; // rax
  __int64 v54; // rdx
  _DWORD *v55; // rax
  __int64 *v56; // rdx
  __int64 v57; // rbx
  __int64 v58; // rax
  __int64 v59; // r9
  __int64 v60; // r8
  _DWORD *v61; // rdx
  __int64 v62; // rcx
  __int64 *v63; // rax
  __int64 v64; // rbx
  __int64 v65; // rcx
  __int64 v66; // rdx
  __int64 v67; // r9
  __int64 v68; // r8
  _DWORD *v69; // rdx
  __int64 v70; // rcx
  __int64 *v71; // rax
  int v72; // r9d
  __int64 v73; // r8
  __int64 v74; // rdx
  __int64 *v75; // rax
  __int64 v76; // r8
  __int64 v77; // rdx
  __int64 v78; // rdx
  __int64 v79; // rdx
  __int64 v80; // rdx
  __int64 v81; // rax
  __int64 v82; // r10
  __int64 v83; // rax
  unsigned int v84; // eax
  _QWORD *v85; // rax
  __int64 v86; // r10
  _QWORD *v87; // r12
  int v88; // edx
  __int64 v89; // rax
  __int64 v90; // rdi
  __int64 *v91; // rbx
  int v92; // edx
  __int64 v93; // rax
  __int64 v94; // rdx
  __int64 v95; // rbx
  _QWORD *v96; // rcx
  __int64 v97; // rbx
  char *v98; // rax
  __int64 v99; // rdx
  char *v100; // rsi
  int v101; // ebp
  __int64 v102; // rdx
  __int64 v103; // rdi
  __int64 v104; // rcx
  __int64 v105; // rcx
  _QWORD *v106; // rax
  __int64 v107; // rcx
  _QWORD *v108; // rax
  _QWORD *v109; // rax
  _QWORD *v110; // rax
  __int64 *v111; // rax
  _QWORD *v112; // rax
  __int64 v113; // rdx
  _QWORD *v114; // rax
  __int64 v115; // rbx
  __int64 v116; // rcx
  _QWORD *v117; // rax
  int v118; // r8d
  __int64 *v119; // rax
  __int64 v120; // rbx
  __int64 v121; // rax
  __int64 *v122; // rax
  __int64 *v123; // rax
  __int64 v124; // rbx
  __int64 v125; // rax
  int v126; // esi
  unsigned __int64 v128; // rax
  __int64 v129; // rdi
  unsigned __int64 v130; // r12
  unsigned int v133; // r9d
  unsigned int v134; // ecx
  int v135; // edx
  __int64 v139; // rcx
  int v140; // r8d
  int v141; // edx
  unsigned int v144; // r9d
  unsigned int v145; // ecx
  int v146; // edx
  int v150; // ecx
  int v151; // edx
  _QWORD *v152; // rsi
  __int64 v153; // rcx
  int v154; // edx
  __int64 v155; // rax
  __int64 v156; // r10
  int v157; // eax
  __int64 v158; // r9
  int v159; // eax
  __int64 v160; // r9
  __int64 v161; // rdi
  int v162; // ecx
  __int64 v163; // rax
  __int64 v164; // rax
  int v165; // ecx
  __int64 v166; // rdi
  _DWORD *v167; // r10
  __int64 v168; // rcx
  int v169; // eax
  int v170; // edx
  _QWORD *v171; // rax
  __int64 v172; // rcx
  __int64 v173; // rdx
  __int64 v174; // rax
  unsigned __int64 v175; // rdx
  unsigned __int64 v176; // rdx
  unsigned __int64 v177; // rax
  unsigned __int64 v178; // rdx
  _QWORD *v179; // rax
  __int64 v180; // r12
  _QWORD *v181; // rax
  _QWORD *v182; // rsi
  __int64 v183; // rdi
  __int64 v184; // rdi
  __int64 v185; // rdi
  __int64 *v186; // r9
  _DWORD *v187; // r12
  __int64 v188; // rax
  __int64 v189; // rdx
  __int64 v190; // r8
  __int64 v191; // rax
  __int64 v192; // rax
  __int64 v193; // rax
  __int64 v194; // [rsp+58h] [rbp-120h]
  __int64 v195; // [rsp+58h] [rbp-120h]
  int v196; // [rsp+58h] [rbp-120h]
  _QWORD *v197; // [rsp+58h] [rbp-120h]
  _DWORD *v198; // [rsp+58h] [rbp-120h]
  __int64 v199; // [rsp+58h] [rbp-120h]
  __int64 *v200; // [rsp+58h] [rbp-120h]
  __int64 v201; // [rsp+60h] [rbp-118h]
  __int64 v202; // [rsp+60h] [rbp-118h]
  __int64 v203; // [rsp+68h] [rbp-110h]
  __int64 v204; // [rsp+78h] [rbp-100h]
  __int64 v205; // [rsp+80h] [rbp-F8h]
  __int64 v206; // [rsp+A0h] [rbp-D8h]
  __int64 v207; // [rsp+A8h] [rbp-D0h]
  char *v208; // [rsp+B0h] [rbp-C8h]
  __int64 v209; // [rsp+B8h] [rbp-C0h]
  __int64 v210; // [rsp+C0h] [rbp-B8h]
  int v211; // [rsp+C8h] [rbp-B0h]
  int v212; // [rsp+CCh] [rbp-ACh]
  __int64 v213; // [rsp+D8h] [rbp-A0h]
  void *Block; // [rsp+F0h] [rbp-88h] BYREF
  __int64 v215; // [rsp+F8h] [rbp-80h]
  __int64 v216; // [rsp+100h] [rbp-78h]
  __int64 v217; // [rsp+110h] [rbp-68h] BYREF
  __int64 v218; // [rsp+118h] [rbp-60h]
  __int64 v219; // [rsp+120h] [rbp-58h]
  __int64 v220; // [rsp+128h] [rbp-50h]
  __int64 v221; // [rsp+130h] [rbp-48h]

  v210 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v211 = a4 & 1;
  if ( v210 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
LABEL_244:
    nc_error("all operation tensors must be on the same device");
  v7 = *(_QWORD *)(a1 + 32);
  if ( !v7 )
    nc_error("tensor has no attached node");
  Block = 0i64;
  v215 = 0i64;
  v216 = 0i64;
  sub_66A12F00((__int64)&Block, v7);
  v8 = v215;
  v9 = (char *)Block;
  v10 = 0i64;
  if ( v215 )
  {
    while ( 1 )
    {
      v11 = *(_QWORD *)&v9[8 * v10];
      *(_BYTE *)(v11 + 120) = 0;
      *(_DWORD *)(v11 + 124) = v10;
      if ( v10 + 1 == v8 )
        break;
      ++v10;
    }
    if ( v7 == *(_QWORD *)&v9[8 * v8 - 8] )
    {
      v12 = 8 * v8;
      v13 = v9;
      v14 = &v9[8 * v8];
      while ( 1 )
      {
        v15 = *(_QWORD *)v13;
        if ( *(_DWORD *)(*(_QWORD *)v13 + 20i64) == 30
          && !*(_QWORD *)(v15 + 56)
          && (v16 = **(_QWORD **)(v15 + 32)) != 0
          && *(_DWORD *)(v16 + 20) == 1 )
        {
          v13 += 8;
          ++*(_DWORD *)(v16 + 64);
          if ( v13 == v14 )
          {
LABEL_15:
            *(_QWORD *)(v7 + 112) = a2;
            v17 = v10;
            v212 = a4 & 2;
            v18 = (char *)(v12 - 8);
            while ( 1 )
            {
              v19 = *(_QWORD *)&v18[(_QWORD)v9];
              if ( v19 )
              {
                v20 = *(unsigned int *)(v19 + 20);
                v21 = *(_QWORD **)(v19 + 112);
                *(_QWORD *)(v19 + 112) = 1i64;
                switch ( (int)v20 )
                {
                  case 0:
                    v168 = v20;
                    goto LABEL_189;
                  case 1:
                    v126 = *(_DWORD *)(v19 + 64);
                    if ( v126 > 1 )
                    {
                      if ( *(_DWORD *)(v19 + 40) != 2 * v126 )
                        sub_66A33D40("n->n_args == 2 * l", "libnc.c", 8721);
                      _RBX = (__int64 *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(8i64 * v126, 64i64);
                      v128 = *(_QWORD *)(v19 + 48);
                      v129 = 16i64 * v126;
                      v130 = (unsigned __int64)&_RBX[v126];
                      if ( (v130 <= v128 || (unsigned __int64)_RBX >= v128 + v129) && (unsigned int)v126 > 0x14 )
                      {
                        _R10 = _RBX;
                        _R8 = *(_QWORD *)(v19 + 48);
                        v133 = 0;
                        v134 = ((unsigned int)(v126 - 5) >> 2) + 1;
                        v135 = 4 * v134;
                        do
                        {
                          __asm { vmovdqu ymm0, ymmword ptr [r8] }
                          ++v133;
                          _R10 += 4;
                          _R8 += 64i64;
                          __asm
                          {
                            vpunpcklqdq ymm0, ymm0, ymmword ptr [r8-20h]
                            vpermq  ymm0, ymm0, 0D8h
                            vmovdqu ymmword ptr [r10-20h], ymm0
                          }
                        }
                        while ( v134 > v133 );
                        if ( v135 == v126 )
                          goto LABEL_202;
                        v139 = 8i64 * (int)(8 * v134);
                        _RBX[v135] = *(_QWORD *)(v128 + v139);
                        if ( v126 <= v135 + 1
                          || (_RBX[v135 + 1] = *(_QWORD *)(v128 + v139 + 16), v126 <= v135 + 2)
                          || (_RBX[v135 + 2] = *(_QWORD *)(v128 + v139 + 32), v135 + 3 >= v126)
                          || (_RBX[v135 + 3] = *(_QWORD *)(v128 + v139 + 48), v126 <= v135 + 4)
                          || (_RBX[v135 + 4] = *(_QWORD *)(v128 + v139 + 64), v140 = v135 + 5, v126 <= v135 + 5)
                          || (v141 = v135 + 6, _RBX[v140] = *(_QWORD *)(v128 + v139 + 80), v126 <= v141) )
                        {
LABEL_202:
                          __asm { vzeroupper }
                        }
                        else
                        {
                          _RBX[v141] = *(_QWORD *)(v128 + v139 + 96);
                          __asm { vzeroupper }
                        }
                      }
                      else
                      {
                        v175 = 0i64;
                        do
                        {
                          _RBX[v175 / 8] = *(_QWORD *)(v128 + 2 * v175);
                          v175 += 8i64;
                        }
                        while ( v175 != 8i64 * (unsigned int)(v126 - 1) + 8 );
                      }
                      v197 = nc_concat(_RBX, v126, 1);
                      _RAX = *(_QWORD *)(v19 + 48);
                      if ( (v130 <= _RAX + 8 || (unsigned __int64)_RBX >= _RAX + v129 + 8) && (unsigned int)v126 > 0x14 )
                      {
                        _R8 = 0i64;
                        v144 = 0;
                        v145 = ((unsigned int)(v126 - 5) >> 2) + 1;
                        v146 = 4 * v145;
                        do
                        {
                          __asm
                          {
                            vmovdqu ymm0, ymmword ptr [rax+r8*2+8]
                            vpunpcklqdq ymm0, ymm0, ymmword ptr [rax+r8*2+28h]
                          }
                          ++v144;
                          __asm
                          {
                            vpermq  ymm0, ymm0, 0D8h
                            vmovdqu ymmword ptr [rbx+r8], ymm0
                          }
                          _R8 += 32i64;
                        }
                        while ( v145 > v144 );
                        if ( v126 == v146 )
                          goto LABEL_203;
                        _RBX[4 * v145] = *(_QWORD *)(_RAX + 8i64 * (int)(8 * v145) + 8);
                        if ( v126 <= v146 + 1
                          || (_RBX[v146 + 1] = *(_QWORD *)(_RAX + 16i64 * (v146 + 1) + 8), v126 <= v146 + 2)
                          || (_RBX[v146 + 2] = *(_QWORD *)(_RAX + 16i64 * (v146 + 2) + 8), v126 <= v146 + 3)
                          || (_RBX[v146 + 3] = *(_QWORD *)(_RAX + 16i64 * (v146 + 3) + 8), v126 <= v146 + 4)
                          || (_RBX[v146 + 4] = *(_QWORD *)(_RAX + 16i64 * (v146 + 4) + 8),
                              v150 = v146 + 5,
                              v126 <= v146 + 5)
                          || (v151 = v146 + 6, _RBX[v150] = *(_QWORD *)(_RAX + 16i64 * v150 + 8), v151 >= v126) )
                        {
LABEL_203:
                          __asm { vzeroupper }
                        }
                        else
                        {
                          _RBX[v151] = *(_QWORD *)(_RAX + 16i64 * v151 + 8);
                          __asm { vzeroupper }
                        }
                      }
                      else
                      {
                        v176 = 0i64;
                        do
                        {
                          _RBX[v176 / 8] = *(_QWORD *)(_RAX + 2 * v176 + 8);
                          v176 += 8i64;
                        }
                        while ( v176 != 8i64 * (unsigned int)(v126 - 1) + 8 );
                      }
                      v152 = nc_concat(_RBX, v126, 1);
                      ((void (__fastcall *)(__int64 *))_aligned_free)(_RBX);
                      ((void (__fastcall *)(_QWORD))_aligned_free)(*(_QWORD *)(v19 + 48));
                      *(_QWORD *)(v19 + 48) = 0i64;
                      *(_DWORD *)(v19 + 40) = 0;
                      v21 = nc_matmul_add((__int64)v197, (__int64)v152, v21, 0, 1);
                    }
                    v153 = *(_QWORD *)(v19 + 56);
                    *(_DWORD *)(v19 + 64) = 0;
                    ((void (__fastcall *)(__int64, _QWORD *, _QWORD))a3)(v153, v21, 0i64);
                    v9 = (char *)Block;
                    goto LABEL_21;
                  case 2:
                    col = nc_convert((__int64)v21, *(_DWORD *)(v19 + 56));
                    goto LABEL_19;
                  case 3:
                    col = nc_reshape((__int64)v21, *(_DWORD *)(v19 + 56), v19 + 64);
                    goto LABEL_19;
                  case 4:
                    v124 = **(_QWORD **)(v19 + 32);
                    if ( !v124 )
                      goto LABEL_196;
                    v125 = nc_reduce_sum(*(_QWORD **)(v124 + 112), (__int64)v21, *(_DWORD *)(v19 + 56));
                    v9 = (char *)Block;
                    *(_QWORD *)(v124 + 112) = v125;
                    goto LABEL_21;
                  case 5:
                    v123 = *(__int64 **)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*v123, v21);
                    v55 = nc_repeat((__int64)v21, *(_DWORD *)(v19 + 56), (const void *)(v19 + 64));
                    goto LABEL_53;
                  case 6:
                    v122 = *(__int64 **)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*v122, v21);
                    sub_66A1F600(*(_QWORD *)(*(_QWORD *)(v19 + 32) + 8i64), v21);
                    v9 = (char *)Block;
                    goto LABEL_21;
                  case 7:
                    v119 = *(__int64 **)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*v119, v21);
                    v120 = *(_QWORD *)(*(_QWORD *)(v19 + 32) + 8i64);
                    if ( !v120 )
                      goto LABEL_196;
                    v121 = sub_66A1F640(*(_QWORD **)(v120 + 112), (__int64)v21);
                    v9 = (char *)Block;
                    *(_QWORD *)(v120 + 112) = v121;
                    goto LABEL_21;
                  case 8:
                    col = nc_neg((__int64)v21);
                    goto LABEL_19;
                  case 9:
                  case 10:
                  case 11:
                    v112 = *(_QWORD **)(v19 + 32);
                    if ( *v112 )
                    {
                      v113 = *(_QWORD *)(*(_QWORD *)(v19 + 48) + 8i64);
                      ++*(_DWORD *)(v113 + 16);
                      ++*((_DWORD *)v21 + 4);
                      v114 = nc_mul((__int64)v21, v113);
                      if ( !v211 )
                        v114 = nc_stop_grad((__int64)v114);
                      sub_66A1F600(**(_QWORD **)(v19 + 32), v114);
                      v112 = *(_QWORD **)(v19 + 32);
                    }
                    v115 = v112[1];
                    if ( !v115 )
                      goto LABEL_196;
                    v116 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v116 + 16);
                    v117 = nc_mul(v116, (__int64)v21);
                    if ( !v211 )
                      v117 = nc_stop_grad((__int64)v117);
                    v118 = *(_DWORD *)(v19 + 20);
                    if ( v118 == 11 )
                    {
                      v179 = nc_sum_0((__int64)v117);
                      sub_66A1F600(v115, v179);
                      v9 = (char *)Block;
                    }
                    else if ( v118 == 10 )
                    {
                      v174 = sub_66A1F640(*(_QWORD **)(v115 + 112), (__int64)v117);
                      v9 = (char *)Block;
                      *(_QWORD *)(v115 + 112) = v174;
                    }
                    else
                    {
                      sub_66A1F600(v115, v117);
                      v9 = (char *)Block;
                    }
                    goto LABEL_21;
                  case 12:
                    v107 = **(_QWORD **)(v19 + 48);
                    *(_DWORD *)(v107 + 16) += 2;
                    v108 = nc_mul(v107, v107);
                    v109 = nc_recip((__int64)v108);
                    v110 = nc_neg((__int64)v109);
                    col = nc_mul((__int64)v110, (__int64)v21);
                    goto LABEL_19;
                  case 13:
                    v105 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v105 + 16);
                    v106 = nc_recip(v105);
                    col = nc_mul((__int64)v106, (__int64)v21);
                    goto LABEL_19;
                  case 14:
                    v97 = 0i64;
                    v98 = (char *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(
                                    8i64 * *(int *)(v19 + 24),
                                    64i64);
                    v99 = (__int64)v21;
                    v100 = v98;
                    v101 = 0;
                    nc_split(v98, v99, *(_DWORD *)(v19 + 24), *(_QWORD *)(v19 + 56), *(_DWORD *)(v19 + 64));
                    if ( *(int *)(v19 + 24) <= 0 )
                      goto LABEL_110;
                    while ( 2 )
                    {
                      while ( 1 )
                      {
                        v102 = *(_QWORD *)&v100[v97];
                        v103 = *(_QWORD *)(*(_QWORD *)(v19 + 32) + v97);
                        if ( !v103 )
                          break;
                        v104 = *(_QWORD *)(v103 + 112);
                        if ( v104 )
                        {
                          *(_QWORD *)(v103 + 112) = nc_add(v104, v102);
                          goto LABEL_106;
                        }
                        *(_QWORD *)(v103 + 112) = v102;
                        ++v101;
                        v97 += 8i64;
                        if ( *(_DWORD *)(v19 + 24) <= v101 )
                        {
LABEL_110:
                          _aligned_free(v100);
                          v9 = (char *)Block;
                          goto LABEL_21;
                        }
                      }
                      nc_free_tensor(*(_DWORD **)&v100[v97]);
LABEL_106:
                      ++v101;
                      v97 += 8i64;
                      if ( *(_DWORD *)(v19 + 24) <= v101 )
                        goto LABEL_110;
                      continue;
                    }
                  case 15:
                    v95 = **(_QWORD **)(v19 + 32);
                    if ( v95 )
                    {
                      v96 = *(_QWORD **)(v95 + 112);
                      if ( !v96 )
                      {
                        v177 = *((int *)v21 + 20);
                        if ( (_DWORD)v177 )
                        {
                          v217 = v21[15];
                          if ( v177 > 1 )
                          {
                            v218 = v21[16];
                            if ( v177 != 2 )
                            {
                              v219 = v21[17];
                              if ( v177 != 3 )
                                v220 = v21[18];
                            }
                          }
                        }
                        *(&v217 + *(int *)(v19 + 56)) = *(_QWORD *)(v19 + 72);
                        v96 = nc_new_tensor(v210, *((_DWORD *)v21 + 12), v177, (__int64)&v217);
                      }
                      *(_QWORD *)(v95 + 112) = nc_slice_add(
                                                 (__int64)v96,
                                                 (__int64)v21,
                                                 *(_DWORD *)(v19 + 56),
                                                 *(_QWORD *)(v19 + 64));
                    }
                    else
                    {
LABEL_196:
                      nc_free_tensor(v21);
                    }
                    goto LABEL_20;
                  case 16:
                    v111 = *(__int64 **)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*v111, v21);
                    v55 = (_DWORD *)nc_slice(
                                      (__int64)v21,
                                      *(_DWORD *)(v19 + 56),
                                      *(_QWORD *)(v19 + 64),
                                      *(_QWORD *)(v19 + 72));
                    goto LABEL_53;
                  case 17:
                    col = (_DWORD *)nc_pad(
                                      (__int64)v21,
                                      -*(_QWORD *)(v19 + 56),
                                      *(_DWORD *)(v19 + 72),
                                      -*(_QWORD *)(v19 + 64),
                                      *(_DWORD *)(v19 + 76));
                    goto LABEL_19;
                  case 18:
                    goto LABEL_99;
                  case 19:
                    v213 = **(_QWORD **)(v19 + 32);
                    if ( *(_DWORD *)(v213 + 20) != 18 )
                      nc_error("only nc_indexed_log(nc_soft_max()) is supported");
                    v81 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v81 + 16);
                    v209 = v81;
                    v82 = **(_QWORD **)(v213 + 48);
                    v83 = *(_QWORD *)(v21[5] + 24i64);
                    ++*(_DWORD *)(v82 + 16);
                    v201 = v83;
                    v84 = *(_DWORD *)(v82 + 48);
                    if ( v84 > 1 || v84 != *((_DWORD *)v21 + 12) )
                      nc_error("unsupported type for %s\n", "nc_indexed_log_soft_max_bw");
                    if ( *(_DWORD *)(v209 + 48) != 5 )
                    {
                      v194 = v82;
                      sub_66A33D40("eout->item_type == NC_TYPE_I32", "libnc.c", 6993);
                      v82 = v194;
                    }
                    if ( v201 != *(_QWORD *)(*(_QWORD *)(v82 + 40) + 24i64)
                      || v201 != *(_QWORD *)(*(_QWORD *)(v209 + 40) + 24i64) )
                    {
                      goto LABEL_244;
                    }
                    v195 = v82;
                    v85 = nc_new_tensor_nz(v201, *(_DWORD *)(v82 + 48), *(_DWORD *)(v82 + 80), v82 + 120);
                    v86 = v195;
                    v87 = v85;
                    v196 = *(_DWORD *)(v195 + 80);
                    if ( v196 > 1
                      && *(_BYTE *)(v86 + 74)
                      && *((_BYTE *)v85 + 74)
                      && *((_BYTE *)v21 + 73)
                      && *(_BYTE *)(v209 + 73) )
                    {
                      v205 = *(_QWORD *)(v86 + 128);
                      if ( v196 != 2 )
                      {
                        if ( *(_BYTE *)(v86 + 75)
                          && *((_BYTE *)v85 + 75)
                          && *((_BYTE *)v21 + 74)
                          && *(_BYTE *)(v209 + 74) )
                        {
                          v205 = *(_QWORD *)(v86 + 136) * *(_QWORD *)(v86 + 128);
                          if ( v196 != 3 )
                          {
                            if ( *(_BYTE *)(v86 + 76)
                              && *((_BYTE *)v85 + 76)
                              && *((_BYTE *)v21 + 75)
                              && *(_BYTE *)(v209 + 75) )
                            {
                              v196 = 4;
                              v205 = *(_QWORD *)(v86 + 144) * *(_QWORD *)(v86 + 136) * *(_QWORD *)(v86 + 128);
                            }
                            else
                            {
                              v196 = 3;
                            }
                          }
                        }
                        else
                        {
                          v196 = 2;
                        }
                      }
                    }
                    else
                    {
                      v205 = 1i64;
                      v196 = 1;
                    }
                    v88 = *((_DWORD *)v85 + 20);
                    v217 = 0i64;
                    if ( v88 <= 1 )
                    {
                      v90 = 0i64;
                    }
                    else
                    {
                      v89 = 1i64;
                      do
                        *(&v217 + v89++) = 0i64;
                      while ( v88 > (int)v89 );
                      v90 = v217;
                    }
                    v208 = v18;
                    v207 = v17;
                    v17 = v209;
                    v206 = v19;
                    v19 = v86;
                    v91 = &v217 + v196;
                    while ( v90 != -1 )
                    {
                      v92 = *(_DWORD *)(v209 + 80);
                      v18 = *(char **)(v201 + 408);
                      if ( v92 <= 0 )
                      {
                        v93 = 0i64;
                      }
                      else
                      {
                        v93 = *(_QWORD *)(v209 + 88) * v218;
                        if ( v92 != 1 )
                        {
                          v93 += *(_QWORD *)(v209 + 96) * v219;
                          if ( v92 != 2 )
                          {
                            v93 += *(_QWORD *)(v209 + 104) * v220;
                            if ( v92 != 3 )
                            {
                              if ( v92 != 4 )
                                goto LABEL_99;
                              v93 += *(_QWORD *)(v209 + 112) * v221;
                            }
                          }
                        }
                      }
                      v154 = *((_DWORD *)v21 + 20);
                      v204 = *(_QWORD *)(v209 + 56) + v93;
                      if ( v154 <= 0 )
                      {
                        v155 = 0i64;
                      }
                      else
                      {
                        v155 = v21[11] * v218;
                        if ( v154 != 1 )
                        {
                          v155 += v21[12] * v219;
                          if ( v154 != 2 )
                          {
                            v155 += v21[13] * v220;
                            if ( v154 != 3 )
                            {
                              if ( v154 != 4 )
                                goto LABEL_99;
                              v155 += v21[14] * v221;
                            }
                          }
                        }
                      }
                      v156 = v155 + v21[7];
                      v157 = *(_DWORD *)(v19 + 80);
                      if ( v157 <= 0 )
                      {
                        v158 = 0i64;
                      }
                      else
                      {
                        v158 = *(_QWORD *)(v19 + 88) * v90;
                        if ( v157 != 1 )
                        {
                          v158 += *(_QWORD *)(v19 + 96) * v218;
                          if ( v157 != 2 )
                          {
                            v158 += *(_QWORD *)(v19 + 104) * v219;
                            if ( v157 != 3 )
                            {
                              if ( v157 != 4 )
                                goto LABEL_99;
                              v158 += *(_QWORD *)(v19 + 112) * v220;
                            }
                          }
                        }
                      }
                      v159 = *((_DWORD *)v87 + 20);
                      v160 = *(_QWORD *)(v19 + 56) + v158;
                      if ( v159 <= 0 )
                      {
                        v161 = 0i64;
                      }
                      else
                      {
                        v161 = v87[11] * v90;
                        if ( v159 != 1 )
                        {
                          v161 += v87[12] * v218;
                          if ( v159 != 2 )
                          {
                            v161 += v87[13] * v219;
                            if ( v159 != 3 )
                            {
                              if ( v159 != 4 )
                              {
LABEL_99:
                                v94 = **(_QWORD **)(v19 + 48);
                                ++*(_DWORD *)(v94 + 16);
                                col = nc_soft_max_bw((__int64)v21, v94);
LABEL_19:
                                sub_66A1F600(**(_QWORD **)(v19 + 32), col);
LABEL_20:
                                v9 = (char *)Block;
                                goto LABEL_21;
                              }
                              v161 += v87[14] * v220;
                            }
                          }
                        }
                      }
                      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _DWORD))v18)(
                        v201,
                        v87[7] + v161,
                        v87[8],
                        v160,
                        *(_QWORD *)(v19 + 64),
                        v156,
                        v204,
                        v87[15],
                        v205,
                        *(_DWORD *)(v19 + 48));
                      v162 = *((_DWORD *)v87 + 20);
                      if ( v162 > v196 )
                      {
                        v163 = *v91 + 1;
                        *v91 = v163;
                        if ( v163 != v87[v196 + 15] )
                        {
LABEL_190:
                          v90 = v217;
                          continue;
                        }
                        v164 = 0i64;
                        v165 = v162 - 1 - v196;
                        while ( 1 )
                        {
                          v91[v164] = 0i64;
                          if ( v164 == v165 )
                            break;
                          v166 = v91[v164 + 1];
                          v91[++v164] = v166 + 1;
                          if ( v166 + 1 != v87[(unsigned int)(v196 + 1) + 14 + v164] )
                            goto LABEL_190;
                        }
                      }
                      break;
                    }
                    v167 = (_DWORD *)v19;
                    v19 = v206;
                    v17 = v207;
                    v198 = v167;
                    v18 = v208;
                    nc_free_tensor(v21);
                    nc_free_tensor(v198);
                    nc_free_tensor((_DWORD *)v209);
                    sub_66A1F600(**(_QWORD **)(v213 + 32), v87);
                    v9 = (char *)Block;
                    *((_QWORD *)Block + *(int *)(v213 + 124)) = 0i64;
                    goto LABEL_21;
                  case 20:
                    v80 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v80 + 16);
                    col = nc_sigmoid_bw((__int64)v21, v80);
                    goto LABEL_19;
                  case 21:
                    v79 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v79 + 16);
                    col = nc_tanh_bw((__int64)v21, v79);
                    goto LABEL_19;
                  case 22:
                    v78 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v78 + 16);
                    col = nc_relu_bw((__int64)v21, v78);
                    goto LABEL_19;
                  case 23:
                    v75 = *(__int64 **)(v19 + 48);
                    v76 = v75[1];
                    v77 = *v75;
                    ++*(_DWORD *)(v76 + 16);
                    ++*(_DWORD *)(v77 + 16);
                    col = nc_gelu_bw((__int64)v21, v77, v76);
                    goto LABEL_19;
                  case 24:
                    v71 = *(__int64 **)(v19 + 48);
                    v72 = *(_DWORD *)(v19 + 56);
                    v73 = v71[1];
                    v74 = *v71;
                    ++*(_DWORD *)(v73 + 16);
                    ++*(_DWORD *)(v74 + 16);
                    col = nc_layer_norm1_bw((__int64)v21, v74, v73, v72);
                    goto LABEL_19;
                  case 25:
                    v63 = *(__int64 **)(v19 + 48);
                    v64 = 0i64;
                    v65 = v63[3];
                    v66 = v63[2];
                    v67 = v63[1];
                    v68 = *v63;
                    ++*(_DWORD *)(v65 + 16);
                    ++*(_DWORD *)(v66 + 16);
                    ++*(_DWORD *)(v67 + 16);
                    ++*(_DWORD *)(v68 + 16);
                    nc_lstm_clamped_bw(&v217, (__int64)v21, v68, v67, v66, v65);
                    do
                    {
                      v69 = *(_DWORD **)((char *)&v217 + v64);
                      v70 = *(_QWORD *)(*(_QWORD *)(v19 + 32) + v64);
                      v64 += 8i64;
                      sub_66A1F600(v70, v69);
                    }
                    while ( v64 != 32 );
                    goto LABEL_20;
                  case 26:
                    v56 = *(__int64 **)(v19 + 48);
                    v57 = 0i64;
                    v58 = v56[2];
                    v59 = v56[1];
                    v60 = *v56;
                    ++*(_DWORD *)(v58 + 16);
                    ++*(_DWORD *)(v59 + 16);
                    ++*(_DWORD *)(v60 + 16);
                    nc_lerp_bw(&v217, (__int64)v21, v60, v59, v58);
                    do
                    {
                      v61 = *(_DWORD **)((char *)&v217 + v57);
                      v62 = *(_QWORD *)(*(_QWORD *)(v19 + 32) + v57);
                      v57 += 8i64;
                      sub_66A1F600(v62, v61);
                    }
                    while ( v57 != 24 );
                    goto LABEL_20;
                  case 27:
                    __asm { vxorps  xmm2, xmm2, xmm2 }
                    v52 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v52 + 16);
                    ++*((_DWORD *)v21 + 4);
                    v53 = (_DWORD *)nc_masked_fill((__int64)v21, v52, *(double *)&_XMM2, 0);
                    sub_66A1F600(**(_QWORD **)(v19 + 32), v53);
                    __asm { vxorps  xmm2, xmm2, xmm2 }
                    v54 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v54 + 16);
                    v55 = (_DWORD *)nc_masked_fill((__int64)v21, v54, *(double *)&_XMM2, 1);
LABEL_53:
                    sub_66A1F600(*(_QWORD *)(*(_QWORD *)(v19 + 32) + 8i64), v55);
                    v9 = (char *)Block;
                    goto LABEL_21;
                  case 28:
                    v49 = *(_DWORD *)(v19 + 56);
                    __asm { vxorps  xmm2, xmm2, xmm2 }
                    v50 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v50 + 16);
                    col = (_DWORD *)nc_masked_fill((__int64)v21, v50, *(double *)&_XMM2, v49);
                    goto LABEL_19;
                  case 29:
                    v48 = *(_DWORD *)(v19 + 56);
                    if ( v48 > 0 )
                    {
                      *((_DWORD *)&v217 + *(int *)(v19 + 60)) = 0;
                      if ( v48 != 1 )
                      {
                        *((_DWORD *)&v217 + *(int *)(v19 + 64)) = 1;
                        if ( v48 != 2 )
                        {
                          *((_DWORD *)&v217 + *(int *)(v19 + 68)) = 2;
                          if ( v48 != 3 )
                            *((_DWORD *)&v217 + *(int *)(v19 + 72)) = 3;
                        }
                      }
                    }
                    col = nc_permute((__int64)v21, v48, (int *)&v217);
                    goto LABEL_19;
                  case 30:
                    v35 = *(_QWORD *)(v19 + 32);
                    v36 = *(_DWORD *)(v19 + 56);
                    v37 = *(_DWORD *)(v19 + 60);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*(_QWORD *)(v35 + 16), v21);
                    v38 = *(__int64 **)(v19 + 32);
                    v39 = v38[1];
                    if ( !v39 )
                      goto LABEL_39;
                    v40 = *(__int64 **)(v19 + 48);
                    v41 = *(_QWORD **)(v39 + 112);
                    v42 = *v40;
                    ++*(_DWORD *)(*v40 + 16);
                    ++*((_DWORD *)v21 + 4);
                    if ( v37 )
                    {
                      v43 = nc_matmul_add((__int64)v21, v42, v41, 1, v36);
                      if ( v211 )
                        goto LABEL_38;
                    }
                    else
                    {
                      v43 = nc_matmul_add(v42, (__int64)v21, v41, v36 == 0, 0);
                      if ( v211 )
                        goto LABEL_38;
                    }
                    v43 = nc_stop_grad((__int64)v43);
LABEL_38:
                    *(_QWORD *)(v39 + 112) = v43;
                    v38 = *(__int64 **)(v19 + 32);
LABEL_39:
                    v44 = *v38;
                    if ( !*v38 )
                      goto LABEL_44;
                    if ( *(_DWORD *)(v44 + 20) != 1 || (v169 = *(_DWORD *)(v44 + 64), v169 <= 1) || v37 | v36 )
                    {
                      v45 = *(_QWORD **)(v44 + 112);
                      v46 = *(_QWORD *)(*(_QWORD *)(v19 + 48) + 8i64);
                      ++*(_DWORD *)(v46 + 16);
                      ++*((_DWORD *)v21 + 4);
                      if ( v36 )
                      {
                        v47 = nc_matmul_add(v46, (__int64)v21, v45, v37, 1);
                        if ( v211 )
                          goto LABEL_43;
                      }
                      else
                      {
                        v47 = nc_matmul_add((__int64)v21, v46, v45, 0, v37 == 0);
                        if ( v211 )
                        {
LABEL_43:
                          *(_QWORD *)(v44 + 112) = v47;
                          goto LABEL_44;
                        }
                      }
                      v47 = nc_stop_grad((__int64)v47);
                      goto LABEL_43;
                    }
                    v170 = *(_DWORD *)(v44 + 40);
                    if ( v170 )
                    {
                      v171 = *(_QWORD **)(v44 + 48);
                    }
                    else
                    {
                      v171 = nc_mallocz(16i64 * v169);
                      v170 = *(_DWORD *)(v44 + 40);
                      *(_QWORD *)(v44 + 48) = v171;
                    }
                    v172 = v170;
                    ++*((_DWORD *)v21 + 4);
                    v171[v170] = v21;
                    *(_DWORD *)(v44 + 40) = v170 + 2;
                    v173 = *(_QWORD *)(*(_QWORD *)(v19 + 48) + 8i64);
                    ++*(_DWORD *)(v173 + 16);
                    v171[v172 + 1] = v173;
LABEL_44:
                    nc_free_tensor(v21);
                    v9 = (char *)Block;
LABEL_21:
                    *(_QWORD *)(v19 + 112) = 0i64;
                    break;
                  case 31:
                    v31 = **(_QWORD **)(v19 + 32);
                    if ( !v31 )
                      goto LABEL_44;
                    if ( v212 && *(_DWORD *)(v31 + 20) == 1 )
                    {
                      ++*(_DWORD *)(**(_QWORD **)(v19 + 48) + 16i64);
                      a3(*(_QWORD *)(v31 + 56), v21);
                      v9 = (char *)Block;
                      *((_QWORD *)Block + *(int *)(v31 + 124)) = 0i64;
                    }
                    else
                    {
                      v32 = *(_QWORD *)(v31 + 112);
                      if ( !v32 )
                      {
                        v180 = v21[15];
                        v203 = *(_QWORD *)(v19 + 56);
                        v199 = *(_QWORD *)(v210 + 16);
                        v181 = aligned_malloc(0x98ui64, 0x40ui64);
                        v182 = v181;
                        if ( !v181 )
                        {
                          MEMORY[0x18] = v199;
                          BUG();
                        }
                        v202 = v199;
                        memset(v181, 0, 0x98ui64);
                        *((_BYTE *)v181 + 73) = 1;
                        v181[16] = v203;
                        v183 = nc_type_size_table[0];
                        *((_BYTE *)v181 + 74) = 1;
                        *((_BYTE *)v181 + 72) = 1;
                        v181[11] = v183;
                        v184 = v180 * v183;
                        v181[3] = v199;
                        v181[15] = v180;
                        v181[12] = v184;
                        v185 = v203 * v184;
                        v186 = *(__int64 **)(v210 + 16);
                        v181[8] = v180;
                        v200 = v186;
                        *((_DWORD *)v181 + 4) = 1;
                        *((_DWORD *)v181 + 20) = 2;
                        v187 = aligned_malloc(0x38ui64, 0x40ui64);
                        v187[4] = 1;
                        *((_QWORD *)v187 + 3) = v210;
                        v188 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(v210 + 48))(
                                 v210,
                                 v187 + 10,
                                 v185);
                        *((_QWORD *)v187 + 4) = v188;
                        if ( !v188 )
                          nc_error("not enough device memory", v189, v190, v200);
                        v191 = *v200;
                        *((_QWORD *)v187 + 6) = v185;
                        *(_QWORD *)(v191 + 8) = v187;
                        *(_QWORD *)v187 = v191;
                        v192 = *((_QWORD *)v187 + 5);
                        *((_QWORD *)v187 + 1) = v200;
                        *v200 = (__int64)v187;
                        v182[7] = v192;
                        v193 = *(_QWORD *)(v202 + 16);
                        v182[5] = v187;
                        *(_QWORD *)(v193 + 8) = v182;
                        *v182 = v193;
                        v182[1] = v202 + 16;
                        *(_QWORD *)(v202 + 16) = v182;
                        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(v210 + 104))(
                          v210,
                          v182[7],
                          0i64,
                          v185,
                          0);
                        v32 = (__int64)v182;
                      }
                      v33 = **(_QWORD **)(v19 + 48);
                      ++*(_DWORD *)(v33 + 16);
                      v34 = nc_add_col((__int64)v21, v33, v32);
                      v9 = (char *)Block;
                      *(_QWORD *)(v31 + 112) = v34;
                    }
                    goto LABEL_21;
                  case 32:
                    v29 = *(_QWORD *)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*(_QWORD *)(v29 + 8), v21);
                    v30 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v30 + 16);
                    col = nc_get_col((__int64)v21, v30);
                    goto LABEL_19;
                  case 33:
                    v25 = **(_QWORD **)(v19 + 32);
                    if ( !v25 )
                      goto LABEL_44;
                    v26 = *(_QWORD **)(v25 + 112);
                    v27 = **(_QWORD **)(v19 + 48);
                    if ( !v26 )
                    {
                      v178 = *(int *)(v27 + 80);
                      if ( (_DWORD)v178 )
                      {
                        v218 = *(_QWORD *)(v27 + 120);
                        if ( v178 > 1 )
                        {
                          v219 = *(_QWORD *)(v27 + 128);
                          if ( v178 != 2 )
                            v220 = *(_QWORD *)(v27 + 136);
                        }
                      }
                      v217 = *(_QWORD *)(v19 + 56);
                      v26 = nc_new_tensor(v210, 0, (int)v178 + 1, (__int64)&v217);
                    }
                    ++*(_DWORD *)(v27 + 16);
                    v28 = nc_add_element((__int64)v21, v27, (__int64)v26);
                    v9 = (char *)Block;
                    *(_QWORD *)(v25 + 112) = v28;
                    goto LABEL_21;
                  case 34:
                    v23 = *(_QWORD *)(v19 + 32);
                    ++*((_DWORD *)v21 + 4);
                    sub_66A1F600(*(_QWORD *)(v23 + 8), v21);
                    v24 = **(_QWORD **)(v19 + 48);
                    ++*(_DWORD *)(v24 + 16);
                    col = nc_get_element((__int64)v21, v24);
                    goto LABEL_19;
                  case 35:
                    __asm { vxorps  xmm2, xmm2, xmm2 }
                    col = nc_slt_mat_set((__int64)v21, *(_QWORD *)(v19 + 56), *(double *)&_XMM2);
                    goto LABEL_19;
                  case 36:
                    col = nc_rel_shift((__int64)v21, -*(_QWORD *)(v19 + 56), -*(_QWORD *)(v19 + 64));
                    goto LABEL_19;
                  default:
                    v168 = (unsigned int)v20;
LABEL_189:
                    nc_error("opcode %s has no backward implementation", off_66A37080[v168]);
                }
              }
              --v17;
              v18 -= 8;
              if ( v17 == -1 )
                goto LABEL_23;
            }
          }
        }
        else
        {
          v13 += 8;
          if ( v13 == v14 )
            goto LABEL_15;
        }
      }
    }
LABEL_245:
    nc_error("inconsistent node graph");
  }
  if ( v7 != *((_QWORD *)Block - 1) )
    goto LABEL_245;
  *(_QWORD *)(v7 + 112) = a2;
LABEL_23:
  _aligned_free(v9);
}

// ======================================================
// Function: sub_66A12F00 @ 0x66A12F00
// ======================================================

void __fastcall sub_66A12F00(__int64 a1, __int64 a2)
{
  int v3; // eax
  int v4; // eax
  __int64 v5; // rax
  int v6; // eax
  __int64 v7; // rax
  int v8; // eax
  __int64 v9; // rax
  int v10; // eax
  __int64 v11; // rax
  int v12; // eax
  __int64 v13; // rax
  int v14; // eax
  __int64 v15; // rax
  int v16; // eax
  __int64 v17; // r12
  __int64 v18; // rdi
  int v19; // eax
  int v20; // eax
  __int64 v21; // rsi
  unsigned __int64 v22; // rbp
  __int64 v23; // r13
  int v24; // eax
  int v25; // eax
  __int64 v26; // rbx
  unsigned __int64 v27; // r14
  __int64 v28; // rdx
  __int64 v29; // rcx
  unsigned __int64 v30; // rax
  unsigned __int64 v31; // rdx
  unsigned __int64 v32; // rbx
  _QWORD *v33; // rax
  __int64 v34; // rcx
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // rdx
  unsigned __int64 v37; // rbx
  _QWORD *v38; // rax
  __int64 v39; // rcx
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // rdx
  unsigned __int64 v42; // rbx
  _QWORD *v43; // rax
  __int64 v44; // rcx
  unsigned __int64 v45; // rax
  unsigned __int64 v46; // rdx
  unsigned __int64 v47; // rbx
  _QWORD *v48; // rax
  __int64 v49; // rcx
  unsigned __int64 v50; // rax
  unsigned __int64 v51; // rdx
  unsigned __int64 v52; // rbx
  _QWORD *v53; // rax
  __int64 v54; // rcx
  unsigned __int64 v55; // rax
  unsigned __int64 v56; // rdx
  unsigned __int64 v57; // rbx
  _QWORD *v58; // rax
  __int64 v59; // rcx
  unsigned __int64 v60; // rax
  unsigned __int64 v61; // rdx
  unsigned __int64 v62; // rbx
  _QWORD *v63; // rax
  __int64 v64; // rcx
  unsigned __int64 v65; // rax
  unsigned __int64 v66; // rdx
  unsigned __int64 v67; // rbx
  _QWORD *v68; // rax
  __int64 v69; // rcx
  unsigned __int64 v70; // rax
  unsigned __int64 v71; // rdx
  unsigned __int64 v72; // rbx
  _QWORD *v73; // rax
  __int64 v74; // [rsp+28h] [rbp-E0h]
  unsigned __int64 v75; // [rsp+30h] [rbp-D8h]
  __int64 v76; // [rsp+38h] [rbp-D0h]
  __int64 v77; // [rsp+40h] [rbp-C8h]
  unsigned __int64 v78; // [rsp+48h] [rbp-C0h]
  __int64 v79; // [rsp+50h] [rbp-B8h]
  __int64 v80; // [rsp+58h] [rbp-B0h]
  __int64 v81; // [rsp+60h] [rbp-A8h]
  __int64 v82; // [rsp+68h] [rbp-A0h]
  __int64 v83; // [rsp+70h] [rbp-98h]
  __int64 v84; // [rsp+78h] [rbp-90h]
  __int64 v85; // [rsp+80h] [rbp-88h]
  __int64 v86; // [rsp+88h] [rbp-80h]
  __int64 v87; // [rsp+90h] [rbp-78h]
  unsigned __int64 v88; // [rsp+98h] [rbp-70h]
  unsigned __int64 v89; // [rsp+A0h] [rbp-68h]
  unsigned __int64 v90; // [rsp+A8h] [rbp-60h]
  unsigned __int64 v91; // [rsp+B0h] [rbp-58h]
  unsigned __int64 v92; // [rsp+B8h] [rbp-50h]

  if ( a2 && !*(_BYTE *)(a2 + 120) )
  {
    if ( *(_BYTE *)(a2 + 121) )
LABEL_123:
      nc_error("cycle found in graph");
    v3 = *(_DWORD *)(a2 + 24);
    *(_BYTE *)(a2 + 121) = 1;
    v4 = v3 - 1;
    if ( v4 >= 0 )
    {
      v79 = 8i64 * v4;
      v88 = 8 * (v4 - (unsigned __int64)(unsigned int)v4) - 8;
      do
      {
        v5 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + v79);
        v84 = v5;
        if ( v5 && !*(_BYTE *)(v5 + 120) )
        {
          if ( *(_BYTE *)(v5 + 121) )
            goto LABEL_123;
          *(_BYTE *)(v5 + 121) = 1;
          v6 = *(_DWORD *)(v5 + 24) - 1;
          if ( v6 >= 0 )
          {
            v80 = 8i64 * v6;
            v89 = 8 * (v6 - (unsigned __int64)(unsigned int)v6) - 8;
            do
            {
              v7 = *(_QWORD *)(*(_QWORD *)(v84 + 32) + v80);
              v85 = v7;
              if ( v7 && !*(_BYTE *)(v7 + 120) )
              {
                if ( *(_BYTE *)(v7 + 121) )
                  goto LABEL_123;
                *(_BYTE *)(v7 + 121) = 1;
                v8 = *(_DWORD *)(v7 + 24) - 1;
                if ( v8 >= 0 )
                {
                  v81 = 8i64 * v8;
                  v90 = 8 * (v8 - (unsigned __int64)(unsigned int)v8) - 8;
                  do
                  {
                    v9 = *(_QWORD *)(*(_QWORD *)(v85 + 32) + v81);
                    v86 = v9;
                    if ( v9 && !*(_BYTE *)(v9 + 120) )
                    {
                      if ( *(_BYTE *)(v9 + 121) )
                        goto LABEL_123;
                      *(_BYTE *)(v9 + 121) = 1;
                      v10 = *(_DWORD *)(v9 + 24) - 1;
                      if ( v10 >= 0 )
                      {
                        v82 = 8i64 * v10;
                        v91 = 8 * (v10 - (unsigned __int64)(unsigned int)v10) - 8;
                        do
                        {
                          v11 = *(_QWORD *)(*(_QWORD *)(v86 + 32) + v82);
                          v87 = v11;
                          if ( v11 && !*(_BYTE *)(v11 + 120) )
                          {
                            if ( *(_BYTE *)(v11 + 121) )
                              goto LABEL_123;
                            *(_BYTE *)(v11 + 121) = 1;
                            v12 = *(_DWORD *)(v11 + 24) - 1;
                            if ( v12 >= 0 )
                            {
                              v83 = 8i64 * v12;
                              v92 = 8 * (v12 - (unsigned __int64)(unsigned int)v12) - 8;
                              do
                              {
                                v13 = *(_QWORD *)(*(_QWORD *)(v87 + 32) + v83);
                                v77 = v13;
                                if ( v13 && !*(_BYTE *)(v13 + 120) )
                                {
                                  if ( *(_BYTE *)(v13 + 121) )
                                    goto LABEL_123;
                                  *(_BYTE *)(v13 + 121) = 1;
                                  v14 = *(_DWORD *)(v13 + 24) - 1;
                                  if ( v14 >= 0 )
                                  {
                                    v76 = 8i64 * v14;
                                    v78 = 8 * (v14 - (unsigned __int64)(unsigned int)v14) - 8;
                                    do
                                    {
                                      v15 = *(_QWORD *)(*(_QWORD *)(v77 + 32) + v76);
                                      v74 = v15;
                                      if ( v15 && !*(_BYTE *)(v15 + 120) )
                                      {
                                        if ( *(_BYTE *)(v15 + 121) )
                                          goto LABEL_123;
                                        *(_BYTE *)(v15 + 121) = 1;
                                        v16 = *(_DWORD *)(v15 + 24) - 1;
                                        if ( v16 >= 0 )
                                        {
                                          v17 = 8i64 * v16;
                                          v75 = 8 * (v16 - (unsigned __int64)(unsigned int)v16) - 8;
                                          do
                                          {
                                            v18 = *(_QWORD *)(*(_QWORD *)(v74 + 32) + v17);
                                            if ( v18 && !*(_BYTE *)(v18 + 120) )
                                            {
                                              if ( *(_BYTE *)(v18 + 121) )
                                                goto LABEL_123;
                                              v19 = *(_DWORD *)(v18 + 24);
                                              *(_BYTE *)(v18 + 121) = 1;
                                              v20 = v19 - 1;
                                              if ( v20 >= 0 )
                                              {
                                                v21 = 8i64 * v20;
                                                v22 = 8 * (v20 - (unsigned __int64)(unsigned int)v20) - 8;
                                                do
                                                {
                                                  v23 = *(_QWORD *)(*(_QWORD *)(v18 + 32) + v21);
                                                  if ( v23 && !*(_BYTE *)(v23 + 120) )
                                                  {
                                                    if ( *(_BYTE *)(v23 + 121) )
                                                      goto LABEL_123;
                                                    v24 = *(_DWORD *)(v23 + 24);
                                                    *(_BYTE *)(v23 + 121) = 1;
                                                    v25 = v24 - 1;
                                                    if ( v25 >= 0 )
                                                    {
                                                      v26 = 8i64 * v25;
                                                      v27 = 8 * (v25 - (unsigned __int64)(unsigned int)v25) - 8;
                                                      do
                                                      {
                                                        v28 = *(_QWORD *)(*(_QWORD *)(v23 + 32) + v26);
                                                        v26 -= 8i64;
                                                        sub_66A12F00(a1, v28);
                                                      }
                                                      while ( v27 != v26 );
                                                    }
                                                    *(_BYTE *)(v23 + 121) = 0;
                                                    *(_BYTE *)(v23 + 120) = 1;
                                                    v29 = *(_QWORD *)(a1 + 8);
                                                    v30 = *(_QWORD *)(a1 + 16);
                                                    v31 = v29 + 1;
                                                    if ( v29 + 1 <= v30 )
                                                    {
                                                      v33 = *(_QWORD **)a1;
                                                    }
                                                    else
                                                    {
                                                      v32 = v30 + (v30 >> 1);
                                                      if ( v31 < 0x10 )
                                                        v31 = 16i64;
                                                      if ( v32 < v31 )
                                                        v32 = v31;
                                                      v33 = realloc(*(void **)a1, 8 * v32);
                                                      v29 = *(_QWORD *)(a1 + 8);
                                                      *(_QWORD *)(a1 + 16) = v32;
                                                      *(_QWORD *)a1 = v33;
                                                      v31 = v29 + 1;
                                                    }
                                                    *(_QWORD *)(a1 + 8) = v31;
                                                    v33[v29] = v23;
                                                  }
                                                  v21 -= 8i64;
                                                }
                                                while ( v22 != v21 );
                                              }
                                              *(_BYTE *)(v18 + 121) = 0;
                                              *(_BYTE *)(v18 + 120) = 1;
                                              v34 = *(_QWORD *)(a1 + 8);
                                              v35 = *(_QWORD *)(a1 + 16);
                                              v36 = v34 + 1;
                                              if ( v34 + 1 <= v35 )
                                              {
                                                v38 = *(_QWORD **)a1;
                                              }
                                              else
                                              {
                                                v37 = v35 + (v35 >> 1);
                                                if ( v36 < 0x10 )
                                                  v36 = 16i64;
                                                if ( v37 < v36 )
                                                  v37 = v36;
                                                v38 = realloc(*(void **)a1, 8 * v37);
                                                v34 = *(_QWORD *)(a1 + 8);
                                                *(_QWORD *)(a1 + 16) = v37;
                                                *(_QWORD *)a1 = v38;
                                                v36 = v34 + 1;
                                              }
                                              *(_QWORD *)(a1 + 8) = v36;
                                              v38[v34] = v18;
                                            }
                                            v17 -= 8i64;
                                          }
                                          while ( v75 != v17 );
                                        }
                                        *(_BYTE *)(v74 + 121) = 0;
                                        *(_BYTE *)(v74 + 120) = 1;
                                        v39 = *(_QWORD *)(a1 + 8);
                                        v40 = *(_QWORD *)(a1 + 16);
                                        v41 = v39 + 1;
                                        if ( v39 + 1 <= v40 )
                                        {
                                          v43 = *(_QWORD **)a1;
                                        }
                                        else
                                        {
                                          v42 = v40 + (v40 >> 1);
                                          if ( v41 < 0x10 )
                                            v41 = 16i64;
                                          if ( v42 < v41 )
                                            v42 = v41;
                                          v43 = realloc(*(void **)a1, 8 * v42);
                                          v39 = *(_QWORD *)(a1 + 8);
                                          *(_QWORD *)(a1 + 16) = v42;
                                          *(_QWORD *)a1 = v43;
                                          v41 = v39 + 1;
                                        }
                                        *(_QWORD *)(a1 + 8) = v41;
                                        v43[v39] = v74;
                                      }
                                      v76 -= 8i64;
                                    }
                                    while ( v78 != v76 );
                                  }
                                  *(_BYTE *)(v77 + 121) = 0;
                                  *(_BYTE *)(v77 + 120) = 1;
                                  v44 = *(_QWORD *)(a1 + 8);
                                  v45 = *(_QWORD *)(a1 + 16);
                                  v46 = v44 + 1;
                                  if ( v44 + 1 <= v45 )
                                  {
                                    v48 = *(_QWORD **)a1;
                                  }
                                  else
                                  {
                                    v47 = v45 + (v45 >> 1);
                                    if ( v46 < 0x10 )
                                      v46 = 16i64;
                                    if ( v47 < v46 )
                                      v47 = v46;
                                    v48 = realloc(*(void **)a1, 8 * v47);
                                    v44 = *(_QWORD *)(a1 + 8);
                                    *(_QWORD *)(a1 + 16) = v47;
                                    *(_QWORD *)a1 = v48;
                                    v46 = v44 + 1;
                                  }
                                  *(_QWORD *)(a1 + 8) = v46;
                                  v48[v44] = v77;
                                }
                                v83 -= 8i64;
                              }
                              while ( v92 != v83 );
                            }
                            *(_BYTE *)(v87 + 121) = 0;
                            *(_BYTE *)(v87 + 120) = 1;
                            v49 = *(_QWORD *)(a1 + 8);
                            v50 = *(_QWORD *)(a1 + 16);
                            v51 = v49 + 1;
                            if ( v49 + 1 <= v50 )
                            {
                              v53 = *(_QWORD **)a1;
                            }
                            else
                            {
                              v52 = v50 + (v50 >> 1);
                              if ( v51 < 0x10 )
                                v51 = 16i64;
                              if ( v52 < v51 )
                                v52 = v51;
                              v53 = realloc(*(void **)a1, 8 * v52);
                              v49 = *(_QWORD *)(a1 + 8);
                              *(_QWORD *)(a1 + 16) = v52;
                              *(_QWORD *)a1 = v53;
                              v51 = v49 + 1;
                            }
                            *(_QWORD *)(a1 + 8) = v51;
                            v53[v49] = v87;
                          }
                          v82 -= 8i64;
                        }
                        while ( v91 != v82 );
                      }
                      *(_BYTE *)(v86 + 121) = 0;
                      *(_BYTE *)(v86 + 120) = 1;
                      v54 = *(_QWORD *)(a1 + 8);
                      v55 = *(_QWORD *)(a1 + 16);
                      v56 = v54 + 1;
                      if ( v54 + 1 <= v55 )
                      {
                        v58 = *(_QWORD **)a1;
                      }
                      else
                      {
                        v57 = v55 + (v55 >> 1);
                        if ( v56 < 0x10 )
                          v56 = 16i64;
                        if ( v57 < v56 )
                          v57 = v56;
                        v58 = realloc(*(void **)a1, 8 * v57);
                        v54 = *(_QWORD *)(a1 + 8);
                        *(_QWORD *)(a1 + 16) = v57;
                        *(_QWORD *)a1 = v58;
                        v56 = v54 + 1;
                      }
                      *(_QWORD *)(a1 + 8) = v56;
                      v58[v54] = v86;
                    }
                    v81 -= 8i64;
                  }
                  while ( v90 != v81 );
                }
                *(_BYTE *)(v85 + 121) = 0;
                *(_BYTE *)(v85 + 120) = 1;
                v59 = *(_QWORD *)(a1 + 8);
                v60 = *(_QWORD *)(a1 + 16);
                v61 = v59 + 1;
                if ( v59 + 1 <= v60 )
                {
                  v63 = *(_QWORD **)a1;
                }
                else
                {
                  v62 = v60 + (v60 >> 1);
                  if ( v61 < 0x10 )
                    v61 = 16i64;
                  if ( v62 < v61 )
                    v62 = v61;
                  v63 = realloc(*(void **)a1, 8 * v62);
                  v59 = *(_QWORD *)(a1 + 8);
                  *(_QWORD *)(a1 + 16) = v62;
                  *(_QWORD *)a1 = v63;
                  v61 = v59 + 1;
                }
                *(_QWORD *)(a1 + 8) = v61;
                v63[v59] = v85;
              }
              v80 -= 8i64;
            }
            while ( v89 != v80 );
          }
          *(_BYTE *)(v84 + 121) = 0;
          *(_BYTE *)(v84 + 120) = 1;
          v64 = *(_QWORD *)(a1 + 8);
          v65 = *(_QWORD *)(a1 + 16);
          v66 = v64 + 1;
          if ( v64 + 1 <= v65 )
          {
            v68 = *(_QWORD **)a1;
          }
          else
          {
            v67 = v65 + (v65 >> 1);
            if ( v66 < 0x10 )
              v66 = 16i64;
            if ( v67 < v66 )
              v67 = v66;
            v68 = realloc(*(void **)a1, 8 * v67);
            v64 = *(_QWORD *)(a1 + 8);
            *(_QWORD *)(a1 + 16) = v67;
            *(_QWORD *)a1 = v68;
            v66 = v64 + 1;
          }
          *(_QWORD *)(a1 + 8) = v66;
          v68[v64] = v84;
        }
        v79 -= 8i64;
      }
      while ( v88 != v79 );
    }
    *(_BYTE *)(a2 + 121) = 0;
    *(_BYTE *)(a2 + 120) = 1;
    v69 = *(_QWORD *)(a1 + 8);
    v70 = *(_QWORD *)(a1 + 16);
    v71 = v69 + 1;
    if ( v69 + 1 <= v70 )
    {
      v73 = *(_QWORD **)a1;
    }
    else
    {
      v72 = v70 + (v70 >> 1);
      if ( v71 < 0x10 )
        v71 = 16i64;
      if ( v72 < v71 )
        v72 = v71;
      v73 = realloc(*(void **)a1, 8 * v72);
      v69 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(a1 + 16) = v72;
      *(_QWORD *)a1 = v73;
      v71 = v69 + 1;
    }
    *(_QWORD *)(a1 + 8) = v71;
    v73[v69] = a2;
  }
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
// Function: sub_66A1F600 @ 0x66A1F600
// ======================================================

void __fastcall sub_66A1F600(__int64 a1, _DWORD *a2)
{
  __int64 v3; // rcx

  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 112);
    if ( v3 )
      *(_QWORD *)(a1 + 112) = nc_add(v3, (__int64)a2);
    else
      *(_QWORD *)(a1 + 112) = a2;
  }
  else
  {
    nc_free_tensor(a2);
  }
}

// ======================================================
// Function: sub_66A1F640 @ 0x66A1F640
// ======================================================

__int64 __fastcall sub_66A1F640(_QWORD *a1, __int64 a2)
{
  __int64 v2; // r13
  unsigned int v5; // edx
  int v6; // edi
  _QWORD *v7; // rbp
  __int64 v9; // r14
  int v10; // eax
  __int64 v11; // r12
  int v12; // edx
  unsigned int v13; // edx
  _QWORD *v14; // rax
  __int64 v15[9]; // [rsp+40h] [rbp-48h] BYREF

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( *(int *)(a2 + 80) <= 0 )
    sub_66A33D40("n_dims1 <= x->n_dims", "libnc.c", 5667);
  v5 = *(_DWORD *)(a2 + 48);
  if ( v5 > 1 )
    nc_error("unsupported type for %s\n", "nc_reduce_sum");
  v6 = *(_DWORD *)(a2 + 80) - 1;
  if ( *(_DWORD *)(a2 + 80) == 1 )
  {
    v7 = (_QWORD *)a2;
    if ( a1 )
      return nc_add((__int64)a1, a2);
    return (__int64)v7;
  }
  if ( a1 )
  {
    if ( v2 != *(_QWORD *)(a1[5] + 24i64) )
      nc_error("all operation tensors must be on the same device");
  }
  else
  {
    a1 = sub_66A137B0(v2, v5, (__int64 *)(a2 + 120));
    nc_tensor_set_u32((__int64)a1, 0);
    v5 = *(_DWORD *)(a2 + 48);
  }
  if ( v5 )
  {
    ++*((_DWORD *)a1 + 4);
    v7 = nc_convert((__int64)a1, 0);
  }
  else
  {
    v7 = a1;
    if ( *((_DWORD *)a1 + 4) != 1 )
    {
      v7 = nc_new_tensor_nz(*(_QWORD *)(a1[5] + 24i64), *((_DWORD *)a1 + 12), *((_DWORD *)a1 + 20), (__int64)(a1 + 15));
      nc_tensor_copy((__int64)v7, (__int64)a1);
    }
  }
  if ( *(_BYTE *)(a2 + 73) && *((_BYTE *)v7 + 73) )
  {
    v9 = *(_QWORD *)(a2 + 120);
  }
  else
  {
    v9 = 1i64;
    sub_66A33D40("first_axis == n_dims1", "libnc.c", 5709);
  }
  v10 = *(_DWORD *)(a2 + 80);
  if ( v10 <= 1 )
  {
    v11 = 1i64;
    v12 = 1;
  }
  else
  {
    if ( !*(_BYTE *)(a2 + 74) )
    {
      v11 = 1i64;
      goto LABEL_36;
    }
    v11 = *(_QWORD *)(a2 + 128);
    if ( v10 == 2 )
    {
      v12 = 2;
    }
    else
    {
      if ( !*(_BYTE *)(a2 + 75) )
        goto LABEL_36;
      v11 *= *(_QWORD *)(a2 + 136);
      if ( v10 != 3 )
      {
        if ( *(_BYTE *)(a2 + 76) )
        {
          v11 *= *(_QWORD *)(a2 + 144);
          v12 = 4;
          goto LABEL_23;
        }
LABEL_36:
        sub_66A33D40("axis1 == x->n_dims", "libnc.c", 5716);
        goto LABEL_24;
      }
      v12 = 3;
    }
  }
LABEL_23:
  if ( v12 != v10 )
    goto LABEL_36;
LABEL_24:
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _DWORD))(v2 + 368))(
    v2,
    v7[7],
    *(_QWORD *)(a2 + 56),
    *(_QWORD *)(a2 + 96) >> dword_66A375E0[*(unsigned int *)(a2 + 48)],
    v9,
    v11,
    *(_DWORD *)(a2 + 48));
  v13 = *(_DWORD *)(a2 + 48);
  if ( v13 )
    v7 = nc_convert((__int64)v7, v13);
  v15[0] = (__int64)a1;
  v15[1] = a2;
  v14 = sub_66A15DA0(5, v7 + 3, (__int64 **)v7 + 4, 2, (__int64)v15);
  if ( v14 )
  {
    *((_DWORD *)v14 + 14) = v6;
    if ( v6 > 0 )
    {
      v14[8] = *(_QWORD *)(a2 + 128);
      if ( v6 != 1 )
      {
        v14[9] = *(_QWORD *)(a2 + 136);
        if ( v6 != 2 )
        {
          v14[10] = *(_QWORD *)(a2 + 144);
          if ( v6 != 3 )
            v14[11] = *(_QWORD *)(a2 + 152);
        }
      }
    }
  }
  if ( a1 != v7 )
    nc_free_tensor(a1);
  nc_free_tensor((_DWORD *)a2);
  return (__int64)v7;
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

