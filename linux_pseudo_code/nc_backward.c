// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_backward
// Included functions: 2

// ======================================================
// Function: nc_backward @ 0x2BF50
// ======================================================

void __fastcall nc_backward(
        __int64 a1,
        __int64 a2,
        void (__fastcall *a3)(__int64, __int64, __int64),
        char a4,
        __m128 _XMM0,
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
  __int64 v16; // rsi
  __int64 v17; // r13
  __int64 v18; // r9
  __int64 v19; // rcx
  _QWORD *v20; // rdi
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // r8
  _QWORD *v24; // rax
  __int64 v25; // rsi
  __int64 v26; // rdx
  __int64 v27; // rdx
  __int64 v28; // r14
  __int64 v29; // r13
  __int64 v30; // rax
  __int64 v31; // r15
  void *col; // rax
  __int64 v33; // rbx
  void *v34; // rdi
  void *v35; // rax
  __int64 v36; // rbx
  void *v37; // rdi
  void *v38; // rax
  __int64 v39; // r8
  void *v40; // rax
  __int64 v41; // rbx
  void *v42; // rdi
  void *v43; // rax
  void *v44; // r12
  void *v45; // rax
  int v46; // ebx
  void *v47; // rax
  __int64 *v48; // rdx
  __int64 v49; // r12
  void *v50; // rdi
  __int64 v51; // r12
  void *v52; // rax
  void *v53; // rax
  __int64 v54; // r12
  int v55; // eax
  __int64 v56; // rdx
  __int64 v57; // rax
  __int64 *v58; // rbx
  __int64 v59; // rax
  __int64 v60; // rdx
  __int64 v61; // rax
  int v62; // ecx
  _QWORD *v63; // rbx
  __int64 v64; // rax
  void *v65; // rax
  __int64 v66; // rbx
  void *v67; // rdi
  void *v68; // rax
  void *v69; // rbx
  void *v70; // rax
  void *v72; // rax
  __int64 v73; // rbx
  void *v74; // rdi
  void *v75; // rax
  __int64 v76; // rbx
  __int64 v77; // r12
  void *v78; // rdi
  __int64 v79; // rbx
  __int64 v80; // r12
  void *v81; // rdi
  void *v82; // rbx
  void *v83; // rax
  void *v84; // rax
  unsigned int v85; // eax
  __int64 v86; // r10
  int v87; // esi
  int v88; // edx
  __int64 v89; // rax
  __int64 v90; // r12
  __int64 *v91; // rbx
  __int64 v92; // rax
  __int64 v93; // r11
  int v94; // ecx
  __int64 v95; // rdx
  void *v96; // rax
  void *v97; // rax
  void *v98; // rax
  void *v99; // rax
  void *v100; // rax
  __int64 v101; // rbx
  void *v102; // rdi
  __int64 v103; // rbx
  void *v104; // rdi
  __int64 v105; // rax
  __int64 v106; // r12
  _QWORD *v107; // rbx
  int v108; // eax
  __int64 v109; // r15
  void *v110; // rdi
  void *v111; // rax
  void *v112; // rax
  void *v113; // rbx
  void *v114; // rax
  void *v115; // rax
  void *v116; // rax
  void *v117; // rax
  __int64 *v118; // rdx
  __int64 v119; // rbx
  void *v120; // rdi
  void *v121; // rdi
  void *v122; // rax
  __int64 v123; // rbx
  void *v124; // rdi
  int v125; // r12d
  unsigned __int64 v127; // rax
  unsigned int v130; // edi
  unsigned int v131; // esi
  int v132; // edx
  __int64 v136; // rcx
  int v137; // esi
  int v138; // edx
  _QWORD *v139; // rdx
  void *v140; // rbx
  void *v141; // rax
  void *v142; // rax
  __int64 *v143; // rdx
  __int64 v144; // rbx
  void *v145; // rdi
  __int64 v146; // rax
  void *v147; // rax
  int v148; // edx
  void *v149; // rax
  __int64 *v150; // rdx
  __int64 v151; // rbx
  void *v152; // rdi
  __int64 v153; // rbx
  __int64 v154; // rax
  unsigned int v157; // edi
  unsigned int v158; // esi
  int v159; // edx
  void *v163; // r12
  __int64 v164; // rdi
  __int64 v165; // rdi
  int v166; // edx
  __int64 v167; // r9
  int v168; // edx
  __int64 v169; // r9
  __int64 v170; // rcx
  int v171; // edi
  __int64 v172; // rcx
  __int64 v173; // r12
  __int64 v174; // rdx
  __int64 v175; // rdx
  __int64 v176; // rcx
  void *v177; // r10
  __int64 v178; // rbx
  void *v179; // rdi
  void *v180; // rax
  void *v181; // rax
  void *v182; // rax
  void *v183; // rax
  int v184; // ecx
  int v185; // edx
  unsigned __int64 v186; // rdx
  unsigned __int64 v187; // rdx
  unsigned __int64 v188; // rax
  __int64 v189; // rsi
  unsigned __int64 v190; // rdx
  __int64 v191; // rax
  __int64 v192; // [rsp-120h] [rbp-120h]
  int v193; // [rsp-114h] [rbp-114h]
  __int64 v195; // [rsp-108h] [rbp-108h]
  __int64 v196; // [rsp-100h] [rbp-100h]
  __int64 v197; // [rsp-F8h] [rbp-F8h]
  __int64 v198; // [rsp-E8h] [rbp-E8h]
  __int64 v199; // [rsp-E0h] [rbp-E0h]
  __int64 v200; // [rsp-D0h] [rbp-D0h]
  __int64 v201; // [rsp-C8h] [rbp-C8h]
  __int64 v202; // [rsp-C0h] [rbp-C0h]
  __int64 v203; // [rsp-B8h] [rbp-B8h]
  unsigned int v204; // [rsp-A8h] [rbp-A8h]
  void *v205; // [rsp-98h] [rbp-98h]
  __int64 v206; // [rsp-98h] [rbp-98h]
  unsigned __int64 v207; // [rsp-98h] [rbp-98h]
  void *v208; // [rsp-98h] [rbp-98h]
  int v209; // [rsp-90h] [rbp-90h]
  int v210; // [rsp-90h] [rbp-90h]
  size_t v211; // [rsp-90h] [rbp-90h]
  void *v212; // [rsp-90h] [rbp-90h]
  void *v213; // [rsp-90h] [rbp-90h]
  __int64 v214; // [rsp-90h] [rbp-90h]
  __int64 v215; // [rsp-88h] [rbp-88h]
  _QWORD *v216; // [rsp-80h] [rbp-80h] BYREF
  __int64 v217; // [rsp-78h] [rbp-78h]
  __int64 v218; // [rsp-70h] [rbp-70h]
  __int64 v219; // [rsp-60h] [rbp-60h] BYREF
  __int64 v220; // [rsp-58h] [rbp-58h]
  __int64 v221; // [rsp-50h] [rbp-50h]
  __int64 v222; // [rsp-48h] [rbp-48h]
  __int64 v223; // [rsp-40h] [rbp-40h]
  char *v224; // [rsp-38h] [rbp-38h]
  __int64 v225; // [rsp-30h] [rbp-30h]
  __int64 v226; // [rsp-28h] [rbp-28h]
  __int64 v227; // [rsp-20h] [rbp-20h]
  __int64 v228; // [rsp-18h] [rbp-18h]
  __int64 v229; // [rsp-10h] [rbp-10h]
  void *v230; // [rsp-8h] [rbp-8h]
  void *retaddr; // [rsp+0h] [rbp+0h]

  v230 = retaddr;
  v229 = v9;
  v228 = v13;
  v227 = v12;
  v226 = v11;
  v225 = v10;
  v224 = &a8;
  v223 = v8;
  v16 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  v192 = v16;
  v204 = a4 & 1;
  if ( v16 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", v16);
  v17 = *(_QWORD *)(a1 + 32);
  if ( !v17 )
    nc_error("tensor has no attached node", v16);
  v216 = 0LL;
  v217 = 0LL;
  v218 = 0LL;
  sub_151D0((__int64)&v216, v17);
  v19 = v217;
  v20 = v216;
  v21 = 0LL;
  if ( v217 )
  {
    do
    {
      v22 = v20[v21];
      *(_DWORD *)(v22 + 124) = v21++;
      *(_BYTE *)(v22 + 120) = 0;
    }
    while ( v21 != v19 );
    if ( v17 != v20[v19 - 1] )
LABEL_7:
      nc_error("inconsistent node graph", v17);
    v23 = 8 * v19;
    v24 = v20;
    v25 = (__int64)&v20[v19];
    do
    {
      while ( 1 )
      {
        v26 = *v24;
        if ( *(_DWORD *)(*v24 + 20LL) == 30 && !*(_QWORD *)(v26 + 56) )
        {
          v27 = **(_QWORD **)(v26 + 32);
          if ( v27 )
          {
            if ( *(_DWORD *)(v27 + 20) == 1 )
              break;
          }
        }
        if ( ++v24 == (_QWORD *)v25 )
          goto LABEL_15;
      }
      ++v24;
      ++*(_DWORD *)(v27 + 64);
    }
    while ( v24 != (_QWORD *)v25 );
LABEL_15:
    *(_QWORD *)(v17 + 112) = a2;
    v193 = a4 & 2;
    v215 = v19 - 1;
    v28 = v23 - 8;
    while ( 1 )
    {
      v29 = *(_QWORD *)((char *)v20 + v28);
      if ( !v29 )
        goto LABEL_24;
      v30 = *(unsigned int *)(v29 + 20);
      v31 = *(_QWORD *)(v29 + 112);
      *(_QWORD *)(v29 + 112) = 1LL;
      switch ( (int)v30 )
      {
        case 1:
          v125 = *(_DWORD *)(v29 + 64);
          if ( v125 > 1 )
          {
            if ( *(_DWORD *)(v29 + 40) != 2 * v125 )
              __assert_fail("n->n_args == 2 * l", "libnc.c", 0x2211u, "nc_backward");
            v211 = v125;
            _RBX = (_QWORD *)nc_malloc(v211 * 8);
            v127 = *(_QWORD *)(v29 + 48);
            if ( ((unsigned __int64)&_RBX[v211] <= v127 || (unsigned __int64)_RBX >= v127 + 16LL * v125)
              && (unsigned int)v125 > 0x14 )
            {
              _R8 = _RBX;
              _RCX = *(_QWORD *)(v29 + 48);
              v130 = 0;
              v131 = ((unsigned int)(v125 - 5) >> 2) + 1;
              v132 = 4 * v131;
              do
              {
                __asm
                {
                  vmovdqu ymm0, ymmword ptr [rcx]
                  vpunpcklqdq ymm0, ymm0, ymmword ptr [rcx+20h]
                }
                ++v130;
                _R8 += 4;
                _RCX += 64LL;
                __asm
                {
                  vpermq  ymm0, ymm0, 0D8h
                  vmovdqu ymmword ptr [r8-20h], ymm0
                }
              }
              while ( v131 > v130 );
              if ( v132 == v125 )
                goto LABEL_213;
              v136 = 8LL * (int)(8 * v131);
              _RBX[v132] = *(_QWORD *)(v127 + v136);
              if ( v125 <= v132 + 1
                || (_RBX[v132 + 1] = *(_QWORD *)(v127 + v136 + 16), v125 <= v132 + 2)
                || (_RBX[v132 + 2] = *(_QWORD *)(v127 + v136 + 32), v125 <= v132 + 3)
                || (_RBX[v132 + 3] = *(_QWORD *)(v127 + v136 + 48), v132 + 4 >= v125)
                || (_RBX[v132 + 4] = *(_QWORD *)(v127 + v136 + 64), v137 = v132 + 5, v125 <= v132 + 5)
                || (v138 = v132 + 6, _RBX[v137] = *(_QWORD *)(v127 + v136 + 80), v125 <= v138) )
              {
LABEL_213:
                __asm { vzeroupper }
              }
              else
              {
                _RBX[v138] = *(_QWORD *)(v127 + v136 + 96);
                __asm { vzeroupper }
              }
            }
            else
            {
              v187 = 0LL;
              do
              {
                _RBX[v187 / 8] = *(_QWORD *)(v127 + 2 * v187);
                v187 += 8LL;
              }
              while ( v187 != 8LL * (unsigned int)(v125 - 1) + 8 );
            }
            v207 = (unsigned __int64)&_RBX[v211];
            v212 = (void *)nc_hconcat(_RBX, (unsigned int)v125);
            _RAX = *(_QWORD *)(v29 + 48);
            if ( (v207 <= _RAX + 8 || (unsigned __int64)_RBX >= _RAX + 16LL * v125 + 8) && (unsigned int)v125 > 0x14 )
            {
              _RCX = 0LL;
              v157 = 0;
              v158 = ((unsigned int)(v125 - 5) >> 2) + 1;
              v159 = 4 * v158;
              do
              {
                __asm
                {
                  vmovdqu ymm0, ymmword ptr [rax+rcx*2+8]
                  vpunpcklqdq ymm0, ymm0, ymmword ptr [rax+rcx*2+28h]
                }
                ++v157;
                __asm
                {
                  vpermq  ymm0, ymm0, 0D8h
                  vmovdqu ymmword ptr [rbx+rcx], ymm0
                }
                _RCX += 32LL;
              }
              while ( v158 > v157 );
              if ( v125 == v159 )
                goto LABEL_219;
              _RBX[4 * v158] = *(_QWORD *)(_RAX + 8LL * (int)(8 * v158) + 8);
              if ( v125 <= v159 + 1
                || (_RBX[v159 + 1] = *(_QWORD *)(_RAX + 16LL * (v159 + 1) + 8), v125 <= v159 + 2)
                || (_RBX[v159 + 2] = *(_QWORD *)(_RAX + 16LL * (v159 + 2) + 8), v125 <= v159 + 3)
                || (_RBX[v159 + 3] = *(_QWORD *)(_RAX + 16LL * (v159 + 3) + 8), v125 <= v159 + 4)
                || (_RBX[v159 + 4] = *(_QWORD *)(_RAX + 16LL * (v159 + 4) + 8), v184 = v159 + 5, v125 <= v159 + 5)
                || (v185 = v159 + 6, _RBX[v184] = *(_QWORD *)(_RAX + 16LL * v184 + 8), v185 >= v125) )
              {
LABEL_219:
                __asm { vzeroupper }
              }
              else
              {
                _RBX[v185] = *(_QWORD *)(_RAX + 16LL * v185 + 8);
                __asm { vzeroupper }
              }
            }
            else
            {
              v186 = 0LL;
              do
              {
                _RBX[v186 / 8] = *(_QWORD *)(_RAX + 2 * v186 + 8);
                v186 += 8LL;
              }
              while ( v186 != 8LL * (unsigned int)(v125 - 1) + 8 );
            }
            v163 = (void *)nc_hconcat(_RBX, (unsigned int)v125);
            nc_free(_RBX);
            nc_free(*(void **)(v29 + 48));
            *(_QWORD *)(v29 + 48) = 0LL;
            *(_DWORD *)(v29 + 40) = 0;
            v31 = nc_matmul_add(v212, v163);
          }
          v164 = *(_QWORD *)(v29 + 56);
          LOBYTE(v25) = v31;
          *(_DWORD *)(v29 + 64) = 0;
          a3(v164, v31, 0LL);
          v20 = v216;
          goto LABEL_23;
        case 2:
          LODWORD(v25) = *(_DWORD *)(v29 + 56);
          col = (void *)nc_convert((void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 3:
          v25 = *(unsigned int *)(v29 + 56);
          col = (void *)nc_reshape((void *)v31, v25, v29 + 64, v19, v23, v18, v192);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 4:
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_62;
          LOBYTE(v25) = v31;
          col = (void *)nc_reduce_sum(*(void **)(v33 + 112), (void *)v31);
          goto LABEL_22;
        case 5:
          v122 = (void *)nc_dup_tensor(v31);
          v123 = **(_QWORD **)(v29 + 32);
          if ( v123 )
          {
            v124 = *(void **)(v123 + 112);
            if ( v124 )
              *(_QWORD *)(v123 + 112) = nc_add(v124, v122);
            else
              *(_QWORD *)(v123 + 112) = v122;
          }
          else
          {
            nc_free_tensor(v122);
          }
          LODWORD(v25) = *(_DWORD *)(v29 + 56);
          col = (void *)nc_repeat((void *)v31);
          v33 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8LL);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 6:
          v117 = (void *)nc_dup_tensor(v31);
          v118 = *(__int64 **)(v29 + 32);
          v119 = *v118;
          if ( *v118 )
          {
            v120 = *(void **)(v119 + 112);
            if ( v120 )
            {
              LOBYTE(v25) = (_BYTE)v117;
              v117 = (void *)nc_add(v120, v117);
              v118 = *(__int64 **)(v29 + 32);
            }
            *(_QWORD *)(v119 + 112) = v117;
          }
          else
          {
            nc_free_tensor(v117);
            v118 = *(__int64 **)(v29 + 32);
          }
          v33 = v118[1];
          if ( !v33 )
            goto LABEL_62;
          v121 = *(void **)(v33 + 112);
          if ( v121 )
          {
            LOBYTE(v25) = v31;
            col = (void *)nc_add(v121, (void *)v31);
            goto LABEL_22;
          }
          *(_QWORD *)(v33 + 112) = v31;
          v20 = v216;
          goto LABEL_23;
        case 7:
          v149 = (void *)nc_dup_tensor(v31);
          v150 = *(__int64 **)(v29 + 32);
          v151 = *v150;
          if ( *v150 )
          {
            v152 = *(void **)(v151 + 112);
            if ( v152 )
            {
              LOBYTE(v25) = (_BYTE)v149;
              v149 = (void *)nc_add(v152, v149);
              v150 = *(__int64 **)(v29 + 32);
            }
            *(_QWORD *)(v151 + 112) = v149;
          }
          else
          {
            nc_free_tensor(v149);
            v150 = *(__int64 **)(v29 + 32);
          }
          v153 = v150[1];
          if ( !v153 )
            goto LABEL_62;
          LOBYTE(v25) = v31;
          v154 = nc_reduce_sum(*(void **)(v153 + 112), (void *)v31);
          v20 = v216;
          *(_QWORD *)(v153 + 112) = v154;
          goto LABEL_23;
        case 8:
          col = (void *)nc_neg((void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 9:
        case 10:
        case 11:
          v139 = *(_QWORD **)(v29 + 32);
          if ( !*v139 )
            goto LABEL_200;
          v140 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
          v141 = (void *)nc_dup_tensor(v31);
          LOBYTE(v25) = (_BYTE)v140;
          v142 = (void *)nc_mul(v141, v140);
          if ( !v204 )
            v142 = (void *)nc_stop_grad(v142);
          v143 = *(__int64 **)(v29 + 32);
          v144 = *v143;
          if ( !*v143 )
          {
            nc_free_tensor(v142);
            v139 = *(_QWORD **)(v29 + 32);
LABEL_200:
            v33 = v139[1];
            if ( !v33 )
              goto LABEL_62;
            goto LABEL_201;
          }
          v145 = *(void **)(v144 + 112);
          if ( v145 )
          {
            LOBYTE(v25) = (_BYTE)v142;
            v146 = nc_add(v145, v142);
            v139 = *(_QWORD **)(v29 + 32);
            *(_QWORD *)(v144 + 112) = v146;
            goto LABEL_200;
          }
          *(_QWORD *)(v144 + 112) = v142;
          v33 = v143[1];
          if ( !v33 )
            goto LABEL_62;
LABEL_201:
          v147 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = v31;
          col = (void *)nc_mul(v147, (void *)v31);
          v18 = v204;
          if ( !v204 )
            col = (void *)nc_stop_grad(col);
          v148 = *(_DWORD *)(v29 + 20);
          if ( v148 == 11 )
          {
            col = (void *)nc_sum(col);
            v34 = *(void **)(v33 + 112);
            if ( v34 )
              goto LABEL_21;
          }
          else
          {
            v34 = *(void **)(v33 + 112);
            if ( v148 != 10 )
              goto LABEL_20;
            LOBYTE(v25) = (_BYTE)col;
            col = (void *)nc_reduce_sum(v34, col);
          }
          goto LABEL_22;
        case 12:
          v113 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v114 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v115 = (void *)nc_mul(v114, v113);
          v116 = (void *)nc_recip(v115);
          v112 = (void *)nc_neg(v116);
          goto LABEL_157;
        case 13:
          v111 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v112 = (void *)nc_recip(v111);
LABEL_157:
          LOBYTE(v25) = v31;
          col = (void *)nc_mul(v112, (void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 14:
          v106 = 1LL;
          LOBYTE(v25) = v31;
          v107 = (_QWORD *)nc_malloc(8LL * *(int *)(v29 + 24));
          nc_split();
          if ( *(int *)(v29 + 24) > 0 )
          {
            do
            {
              v25 = v107[v106 - 1];
              v109 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8 * v106 - 8);
              if ( v109 )
              {
                v110 = *(void **)(v109 + 112);
                if ( v110 )
                  *(_QWORD *)(v109 + 112) = nc_add(v110, (void *)v25);
                else
                  *(_QWORD *)(v109 + 112) = v25;
              }
              else
              {
                nc_free_tensor((void *)v107[v106 - 1]);
              }
              v108 = v106++;
            }
            while ( *(_DWORD *)(v29 + 24) > v108 );
          }
          nc_free(v107);
          v20 = v216;
          goto LABEL_23;
        case 15:
          v103 = **(_QWORD **)(v29 + 32);
          if ( !v103 )
          {
            nc_free_tensor((void *)v31);
            goto LABEL_71;
          }
          v104 = *(void **)(v103 + 112);
          if ( !v104 )
          {
            v188 = *(int *)(v31 + 80);
            if ( (_DWORD)v188 )
            {
              v219 = *(_QWORD *)(v31 + 120);
              if ( v188 > 1 )
              {
                v220 = *(_QWORD *)(v31 + 128);
                if ( v188 != 2 )
                {
                  v221 = *(_QWORD *)(v31 + 136);
                  if ( v188 != 3 )
                    v222 = *(_QWORD *)(v31 + 144);
                }
              }
            }
            v189 = *(unsigned int *)(v31 + 48);
            *(&v219 + *(int *)(v29 + 56)) = *(_QWORD *)(v29 + 72);
            v104 = (void *)nc_new_tensor(v192, v189, v188, &v219);
          }
          LOBYTE(v25) = v31;
          v105 = nc_slice_add(v104, (void *)v31);
          v20 = v216;
          *(_QWORD *)(v103 + 112) = v105;
          goto LABEL_23;
        case 16:
          v100 = (void *)nc_dup_tensor(v31);
          v101 = **(_QWORD **)(v29 + 32);
          if ( v101 )
          {
            v102 = *(void **)(v101 + 112);
            if ( v102 )
              *(_QWORD *)(v101 + 112) = nc_add(v102, v100);
            else
              *(_QWORD *)(v101 + 112) = v100;
          }
          else
          {
            nc_free_tensor(v100);
          }
          LODWORD(v25) = *(_DWORD *)(v29 + 56);
          col = (void *)nc_slice((void *)v31);
          v33 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8LL);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 17:
          v25 = -*(_QWORD *)(v29 + 56);
          col = (void *)nc_pad((void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 18:
          goto LABEL_131;
        case 19:
          v195 = **(_QWORD **)(v29 + 32);
          if ( *(_DWORD *)(v195 + 20) != 18 )
            nc_error("only nc_indexed_log(nc_soft_max()) is supported", v25);
          v197 = nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v196 = nc_dup_tensor(**(_QWORD **)(v195 + 48));
          v206 = *(_QWORD *)(*(_QWORD *)(v31 + 40) + 24LL);
          v85 = *(_DWORD *)(v196 + 48);
          if ( v85 > 1 || v85 != *(_DWORD *)(v31 + 48) )
            nc_error("unsupported type for %s\n", (char)"nc_indexed_log_soft_max_bw");
          if ( *(_DWORD *)(v197 + 48) != 5 )
            __assert_fail("eout->item_type == NC_TYPE_I32", "libnc.c", 0x1B51u, "nc_indexed_log_soft_max_bw");
          if ( v206 != *(_QWORD *)(*(_QWORD *)(v196 + 40) + 24LL) )
            nc_error("all operation tensors must be on the same device", v25);
          if ( v206 != *(_QWORD *)(*(_QWORD *)(v197 + 40) + 24LL) )
            nc_error("all operation tensors must be on the same device", v25);
          v86 = nc_new_tensor_nz(
                  *(_QWORD *)(*(_QWORD *)(v196 + 40) + 24LL),
                  *(unsigned int *)(v196 + 48),
                  *(unsigned int *)(v196 + 80),
                  v196 + 120);
          v87 = *(_DWORD *)(v196 + 80);
          v210 = v87;
          if ( v87 > 1 && *(_BYTE *)(v196 + 74) && *(_BYTE *)(v86 + 74) && *(_BYTE *)(v31 + 73) && *(_BYTE *)(v197 + 73) )
          {
            v200 = *(_QWORD *)(v196 + 128);
            if ( v87 != 2 )
            {
              if ( *(_BYTE *)(v196 + 75) && *(_BYTE *)(v86 + 75) && *(_BYTE *)(v31 + 74) && *(_BYTE *)(v197 + 74) )
              {
                v200 = *(_QWORD *)(v196 + 136) * *(_QWORD *)(v196 + 128);
                if ( v87 != 3 )
                {
                  if ( *(_BYTE *)(v196 + 76) && *(_BYTE *)(v86 + 76) && *(_BYTE *)(v31 + 75) && *(_BYTE *)(v197 + 75) )
                  {
                    v210 = 4;
                    v200 = *(_QWORD *)(v196 + 144) * *(_QWORD *)(v196 + 136) * *(_QWORD *)(v196 + 128);
                  }
                  else
                  {
                    v210 = 3;
                  }
                }
              }
              else
              {
                v210 = 2;
              }
            }
          }
          else
          {
            v200 = 1LL;
            v210 = 1;
          }
          v88 = *(_DWORD *)(v86 + 80);
          v219 = 0LL;
          if ( v88 <= 1 )
          {
            v90 = 0LL;
          }
          else
          {
            v89 = 1LL;
            do
              *(&v219 + v89++) = 0LL;
            while ( v88 > (int)v89 );
            v90 = v219;
          }
          LOBYTE(v25) = v210;
          v198 = v28;
          v199 = v29;
          v29 = v86;
          v91 = &v219 + v210;
          v28 = v86 + 8LL * (unsigned int)(v210 + 1);
          v92 = v31;
          v93 = v197;
          v31 = v196;
          while ( 2 )
          {
            if ( v90 == -1 )
              goto LABEL_247;
            v94 = *(_DWORD *)(v93 + 80);
            if ( v94 <= 0 )
            {
              v95 = 0LL;
            }
            else
            {
              v95 = *(_QWORD *)(v93 + 88) * v220;
              if ( v94 != 1 )
              {
                v95 += *(_QWORD *)(v93 + 96) * v221;
                if ( v94 != 2 )
                {
                  v95 += *(_QWORD *)(v93 + 104) * v222;
                  if ( v94 != 3 )
                  {
                    if ( v94 != 4 )
                      break;
                    v95 += *(_QWORD *)(v93 + 112) * v223;
                  }
                }
              }
            }
            v165 = *(_QWORD *)(v93 + 56) + v95;
            v166 = *(_DWORD *)(v92 + 80);
            v203 = v165;
            if ( v166 <= 0 )
            {
              v167 = 0LL;
            }
            else
            {
              v167 = *(_QWORD *)(v92 + 88) * v220;
              if ( v166 != 1 )
              {
                v167 += *(_QWORD *)(v92 + 96) * v221;
                if ( v166 != 2 )
                {
                  v167 += *(_QWORD *)(v92 + 104) * v222;
                  if ( v166 != 3 )
                  {
                    if ( v166 != 4 )
                      break;
                    v167 += *(_QWORD *)(v92 + 112) * v223;
                  }
                }
              }
            }
            v168 = *(_DWORD *)(v196 + 80);
            v169 = *(_QWORD *)(v92 + 56) + v167;
            if ( v168 <= 0 )
            {
              v170 = 0LL;
            }
            else
            {
              v170 = *(_QWORD *)(v196 + 88) * v90;
              if ( v168 != 1 )
              {
                v170 += *(_QWORD *)(v196 + 96) * v220;
                if ( v168 != 2 )
                {
                  v170 += *(_QWORD *)(v196 + 104) * v221;
                  if ( v168 != 3 )
                  {
                    if ( v168 != 4 )
                      break;
                    v170 += *(_QWORD *)(v196 + 112) * v222;
                  }
                }
              }
            }
            v171 = *(_DWORD *)(v29 + 80);
            v172 = *(_QWORD *)(v196 + 56) + v170;
            if ( v171 <= 0 )
            {
              v173 = 0LL;
              goto LABEL_242;
            }
            v173 = *(_QWORD *)(v29 + 88) * v90;
            if ( v171 == 1 )
              goto LABEL_242;
            v173 += *(_QWORD *)(v29 + 96) * v220;
            if ( v171 == 2 )
              goto LABEL_242;
            v173 += *(_QWORD *)(v29 + 104) * v221;
            if ( v171 == 3 )
              goto LABEL_242;
            if ( v171 == 4 )
            {
              v173 += v222 * *(_QWORD *)(v29 + 112);
LABEL_242:
              v202 = v92;
              v201 = v93;
              (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD))(v206 + 408))(
                v206,
                *(_QWORD *)(v29 + 56) + v173,
                *(_QWORD *)(v29 + 64),
                v172,
                *(_QWORD *)(v196 + 64),
                v169,
                v203,
                *(_QWORD *)(v29 + 120),
                v200,
                *(unsigned int *)(v196 + 48));
              LODWORD(v25) = *(_DWORD *)(v29 + 80);
              v92 = v202;
              if ( (int)v25 > v210 )
              {
                v93 = v201;
                v174 = *v91 + 1;
                *v91 = v174;
                if ( *(_QWORD *)(v29 + 8 * (v210 + 12LL) + 24) != v174 )
                {
LABEL_253:
                  v90 = v219;
                  continue;
                }
                v175 = 0LL;
                LODWORD(v25) = v25 - 1 - v210;
                while ( 1 )
                {
                  v91[v175] = 0LL;
                  if ( v175 == (unsigned int)v25 )
                    break;
                  v176 = v91[v175 + 1] + 1;
                  v91[++v175] = v176;
                  if ( v176 != *(_QWORD *)(v28 + 8 * v175 + 112) )
                    goto LABEL_253;
                }
              }
LABEL_247:
              v177 = (void *)v29;
              v29 = v199;
              v28 = v198;
              v213 = v177;
              nc_free_tensor((void *)v92);
              nc_free_tensor((void *)v196);
              nc_free_tensor((void *)v197);
              v178 = **(_QWORD **)(v195 + 32);
              if ( v178 )
              {
                v179 = *(void **)(v178 + 112);
                if ( v179 )
                {
                  LOBYTE(v25) = (_BYTE)v213;
                  *(_QWORD *)(v178 + 112) = nc_add(v179, v213);
                }
                else
                {
                  *(_QWORD *)(v178 + 112) = v213;
                }
              }
              else
              {
                nc_free_tensor(v213);
              }
              v20 = v216;
              v216[*(int *)(v195 + 124)] = 0LL;
              goto LABEL_23;
            }
            break;
          }
LABEL_131:
          v96 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v96;
          col = (void *)nc_soft_max_bw((void *)v31, v96);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
          {
LABEL_30:
            nc_free_tensor(col);
            v20 = v216;
            goto LABEL_23;
          }
LABEL_19:
          v34 = *(void **)(v33 + 112);
LABEL_20:
          if ( v34 )
          {
LABEL_21:
            LOBYTE(v25) = (_BYTE)col;
            col = (void *)nc_add(v34, col);
          }
LABEL_22:
          *(_QWORD *)(v33 + 112) = col;
          v20 = v216;
LABEL_23:
          *(_QWORD *)(v29 + 112) = 0LL;
LABEL_24:
          --v215;
          v28 -= 8LL;
          if ( v215 == -1 )
            goto LABEL_25;
          break;
        case 20:
          v84 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v84;
          col = (void *)nc_sigmoid_bw((void *)v31, v84);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 21:
          v98 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v98;
          col = (void *)nc_tanh_bw((void *)v31, v98);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 22:
          v97 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v97;
          col = (void *)nc_relu_bw((void *)v31, v97);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 23:
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
          v99 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v99;
          col = (void *)nc_gelu_bw((void *)v31, v99);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 24:
          v82 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
          v83 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v83;
          col = (void *)nc_layer_norm1_bw((void *)v31, v83, v82);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 25:
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 24LL));
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 16LL));
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
          nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v79 = 0LL;
          nc_lstm_clamped_bw();
          do
          {
            v25 = *(__int64 *)((char *)&v219 + v79);
            v80 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + v79);
            if ( v80 )
            {
              v81 = *(void **)(v80 + 112);
              if ( v81 )
                *(_QWORD *)(v80 + 112) = nc_add(v81, (void *)v25);
              else
                *(_QWORD *)(v80 + 112) = v25;
            }
            else
            {
              nc_free_tensor(*(void **)((char *)&v219 + v79));
            }
            v79 += 8LL;
          }
          while ( v79 != 32 );
          goto LABEL_71;
        case 26:
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 16LL));
          nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
          nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v76 = 0LL;
          nc_lerp_bw();
          do
          {
            v25 = *(__int64 *)((char *)&v219 + v76);
            v77 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + v76);
            if ( v77 )
            {
              v78 = *(void **)(v77 + 112);
              if ( v78 )
                *(_QWORD *)(v77 + 112) = nc_add(v78, (void *)v25);
              else
                *(_QWORD *)(v77 + 112) = v25;
            }
            else
            {
              nc_free_tensor(*(void **)((char *)&v219 + v76));
            }
            v76 += 8LL;
          }
          while ( v76 != 24 );
          goto LABEL_71;
        case 27:
          v69 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          v70 = (void *)nc_dup_tensor(v31);
          __asm { vxorps  xmm0, xmm0, xmm0 }
          v72 = (void *)nc_masked_fill(v70, v69);
          v73 = **(_QWORD **)(v29 + 32);
          if ( v73 )
          {
            v74 = *(void **)(v73 + 112);
            if ( v74 )
              *(_QWORD *)(v73 + 112) = nc_add(v74, v72);
            else
              *(_QWORD *)(v73 + 112) = v72;
          }
          else
          {
            nc_free_tensor(v72);
          }
          v75 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          __asm { vxorps  xmm0, xmm0, xmm0 }
          LOBYTE(v25) = (_BYTE)v75;
          col = (void *)nc_masked_fill((void *)v31, v75);
          v33 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8LL);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 28:
          v68 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          __asm { vxorps  xmm0, xmm0, xmm0 }
          LOBYTE(v25) = (_BYTE)v68;
          col = (void *)nc_masked_fill((void *)v31, v68);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 29:
          v25 = *(unsigned int *)(v29 + 56);
          if ( (int)v25 > 0 )
          {
            *((_DWORD *)&v219 + *(int *)(v29 + 60)) = 0;
            if ( (_DWORD)v25 != 1 )
            {
              *((_DWORD *)&v219 + *(int *)(v29 + 64)) = 1;
              if ( (_DWORD)v25 != 2 )
              {
                *((_DWORD *)&v219 + *(int *)(v29 + 68)) = 2;
                if ( (_DWORD)v25 != 3 )
                  *((_DWORD *)&v219 + *(int *)(v29 + 72)) = 3;
              }
            }
          }
          v65 = (void *)nc_permute(v31, v25, &v219);
          v66 = **(_QWORD **)(v29 + 32);
          if ( !v66 )
          {
            nc_free_tensor(v65);
            goto LABEL_71;
          }
          v67 = *(void **)(v66 + 112);
          if ( v67 )
          {
            LOBYTE(v25) = (_BYTE)v65;
            *(_QWORD *)(v66 + 112) = nc_add(v67, v65);
LABEL_71:
            v20 = v216;
            goto LABEL_23;
          }
          *(_QWORD *)(v66 + 112) = v65;
          v20 = v216;
          goto LABEL_23;
        case 30:
          v46 = *(_DWORD *)(v29 + 56);
          v209 = *(_DWORD *)(v29 + 60);
          v47 = (void *)nc_dup_tensor(v31);
          v48 = *(__int64 **)(v29 + 32);
          v49 = v48[2];
          if ( v49 )
          {
            v50 = *(void **)(v49 + 112);
            if ( v50 )
            {
              LOBYTE(v25) = (_BYTE)v47;
              v47 = (void *)nc_add(v50, v47);
              v48 = *(__int64 **)(v29 + 32);
            }
            *(_QWORD *)(v49 + 112) = v47;
          }
          else
          {
            nc_free_tensor(v47);
            v48 = *(__int64 **)(v29 + 32);
          }
          v51 = v48[1];
          if ( !v51 )
            goto LABEL_55;
          v205 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          if ( v209 )
          {
            v183 = (void *)nc_dup_tensor(v31);
            v53 = (void *)nc_matmul_add(v183, v205);
            LOBYTE(v25) = v204;
            if ( v204 )
              goto LABEL_54;
          }
          else
          {
            v52 = (void *)nc_dup_tensor(v31);
            v53 = (void *)nc_matmul_add(v205, v52);
            LOBYTE(v25) = v204;
            if ( v204 )
              goto LABEL_54;
          }
          v53 = (void *)nc_stop_grad(v53);
LABEL_54:
          *(_QWORD *)(v51 + 112) = v53;
          v48 = *(__int64 **)(v29 + 32);
LABEL_55:
          v54 = *v48;
          if ( !*v48 )
            goto LABEL_62;
          if ( *(_DWORD *)(v54 + 20) != 1
            || (v55 = *(_DWORD *)(v54 + 64), v55 <= 1)
            || (LOBYTE(v25) = v46 | v209, v46 | v209) )
          {
            v208 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v29 + 48) + 8LL));
            if ( v46 )
            {
              v182 = (void *)nc_dup_tensor(v31);
              LOBYTE(v25) = (_BYTE)v182;
              v181 = (void *)nc_matmul_add(v208, v182);
              if ( v204 )
                goto LABEL_260;
            }
            else
            {
              v180 = (void *)nc_dup_tensor(v31);
              LOBYTE(v25) = (_BYTE)v208;
              v181 = (void *)nc_matmul_add(v180, v208);
              if ( v204 )
              {
LABEL_260:
                *(_QWORD *)(v54 + 112) = v181;
                nc_free_tensor((void *)v31);
                v20 = v216;
                goto LABEL_23;
              }
            }
            v181 = (void *)nc_stop_grad(v181);
            goto LABEL_260;
          }
          v56 = *(int *)(v54 + 40);
          if ( (_DWORD)v56 )
          {
            v57 = *(_QWORD *)(v54 + 48);
          }
          else
          {
            v57 = nc_mallocz(16LL * v55);
            v56 = *(int *)(v54 + 40);
            *(_QWORD *)(v54 + 48) = v57;
          }
          v58 = (__int64 *)(v57 + 8 * v56);
          *(_DWORD *)(v54 + 40) = v56 + 1;
          v59 = nc_dup_tensor(v31);
          v60 = *(_QWORD *)(v54 + 48);
          *v58 = v59;
          v61 = *(int *)(v54 + 40);
          v62 = v61 + 1;
          v63 = (_QWORD *)(v60 + 8 * v61);
          v64 = *(_QWORD *)(v29 + 48);
          *(_DWORD *)(v54 + 40) = v62;
          *v63 = nc_dup_tensor(*(_QWORD *)(v64 + 8));
LABEL_62:
          nc_free_tensor((void *)v31);
          v20 = v216;
          goto LABEL_23;
        case 31:
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_62;
          if ( v193 && *(_DWORD *)(v33 + 20) == 1 )
          {
            v191 = nc_dup_tensor(**(_QWORD **)(v29 + 48));
            LOBYTE(v25) = v31;
            a3(*(_QWORD *)(v33 + 56), v31, v191);
            v20 = v216;
            v216[*(int *)(v33 + 124)] = 0LL;
            goto LABEL_23;
          }
          v44 = *(void **)(v33 + 112);
          if ( !v44 )
            v44 = (void *)nc_new_tensor_2d(v192, 0LL, *(_QWORD *)(v31 + 120), *(_QWORD *)(v29 + 56));
          v45 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v45;
          col = (void *)nc_add_col((void *)v31, v45, v44);
          goto LABEL_22;
        case 32:
          v40 = (void *)nc_dup_tensor(v31);
          v41 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8LL);
          if ( v41 )
          {
            v42 = *(void **)(v41 + 112);
            if ( v42 )
              *(_QWORD *)(v41 + 112) = nc_add(v42, v40);
            else
              *(_QWORD *)(v41 + 112) = v40;
          }
          else
          {
            nc_free_tensor(v40);
          }
          v43 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v43;
          col = (void *)nc_get_col((void *)v31, v43);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 33:
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_62;
          v39 = **(_QWORD **)(v29 + 48);
          if ( !*(_QWORD *)(v33 + 112) )
          {
            v190 = *(int *)(v39 + 80);
            if ( (_DWORD)v190 )
            {
              v220 = *(_QWORD *)(v39 + 120);
              if ( v190 > 1 )
              {
                v221 = *(_QWORD *)(v39 + 128);
                if ( v190 != 2 )
                  v222 = *(_QWORD *)(v39 + 136);
              }
            }
            v214 = v39;
            v219 = *(_QWORD *)(v29 + 56);
            nc_new_tensor(v192, 0LL, (unsigned int)(v190 + 1), &v219);
            v39 = v214;
          }
          LOBYTE(v25) = nc_dup_tensor(v39);
          col = (void *)nc_add_element((void *)v31);
          goto LABEL_22;
        case 34:
          v35 = (void *)nc_dup_tensor(v31);
          v36 = *(_QWORD *)(*(_QWORD *)(v29 + 32) + 8LL);
          if ( v36 )
          {
            v37 = *(void **)(v36 + 112);
            if ( v37 )
              *(_QWORD *)(v36 + 112) = nc_add(v37, v35);
            else
              *(_QWORD *)(v36 + 112) = v35;
          }
          else
          {
            nc_free_tensor(v35);
          }
          v38 = (void *)nc_dup_tensor(**(_QWORD **)(v29 + 48));
          LOBYTE(v25) = (_BYTE)v38;
          col = (void *)nc_get_element((void *)v31, v38);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 35:
          v25 = *(_QWORD *)(v29 + 56);
          __asm { vxorps  xmm0, xmm0, xmm0 }
          col = (void *)nc_slt_mat_set((void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( !v33 )
            goto LABEL_30;
          goto LABEL_19;
        case 36:
          v25 = -*(_QWORD *)(v29 + 56);
          col = (void *)nc_rel_shift((void *)v31);
          v33 = **(_QWORD **)(v29 + 32);
          if ( v33 )
            goto LABEL_19;
          goto LABEL_30;
        default:
          nc_error("opcode %s has no backward implementation", (char)off_235C20[v30]);
      }
    }
  }
  if ( v17 != *(v216 - 1) )
    goto LABEL_7;
  *(_QWORD *)(v17 + 112) = a2;
LABEL_25:
  nc_free(v20);
}

// ======================================================
// Function: sub_151D0 @ 0x151D0
// ======================================================

void __fastcall sub_151D0(__int64 a1, __int64 a2)
{
  int v2; // eax
  __int64 v3; // rax
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
  __int64 v15; // r12
  int v16; // eax
  int v17; // eax
  __int64 v18; // rbp
  __int64 v19; // r14
  int v20; // eax
  int v21; // eax
  __int64 v22; // rbx
  unsigned __int64 v23; // r13
  __int64 v24; // rsi
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rcx
  unsigned __int64 v27; // rbx
  _QWORD *v28; // rax
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
  unsigned __int64 v69; // [rsp+0h] [rbp-E8h]
  __int64 v70; // [rsp+8h] [rbp-E0h]
  __int64 v71; // [rsp+10h] [rbp-D8h]
  unsigned __int64 v72; // [rsp+18h] [rbp-D0h]
  __int64 v73; // [rsp+20h] [rbp-C8h]
  __int64 v74; // [rsp+28h] [rbp-C0h]
  unsigned __int64 v75; // [rsp+30h] [rbp-B8h]
  __int64 v76; // [rsp+38h] [rbp-B0h]
  __int64 v77; // [rsp+40h] [rbp-A8h]
  __int64 v78; // [rsp+48h] [rbp-A0h]
  __int64 v79; // [rsp+50h] [rbp-98h]
  __int64 v80; // [rsp+58h] [rbp-90h]
  __int64 v81; // [rsp+60h] [rbp-88h]
  __int64 v82; // [rsp+68h] [rbp-80h]
  __int64 v83; // [rsp+70h] [rbp-78h]
  __int64 v84; // [rsp+78h] [rbp-70h]
  __int64 v85; // [rsp+80h] [rbp-68h]
  unsigned __int64 v86; // [rsp+88h] [rbp-60h]
  unsigned __int64 v87; // [rsp+90h] [rbp-58h]
  unsigned __int64 v88; // [rsp+98h] [rbp-50h]
  unsigned __int64 v89; // [rsp+A0h] [rbp-48h]
  unsigned __int64 v90; // [rsp+A8h] [rbp-40h]

  if ( a2 && !*(_BYTE *)(a2 + 120) )
  {
    v85 = a2;
    if ( *(_BYTE *)(a2 + 121) )
      nc_error("cycle found in graph", a2);
    *(_BYTE *)(a2 + 121) = 1;
    v2 = *(_DWORD *)(a2 + 24) - 1;
    if ( v2 >= 0 )
    {
      v80 = 8LL * v2;
      v86 = 8 * (v2 - (unsigned __int64)(unsigned int)v2) - 8;
      do
      {
        v3 = *(_QWORD *)(*(_QWORD *)(v85 + 32) + v80);
        v76 = v3;
        if ( v3 && !*(_BYTE *)(v3 + 120) )
        {
          if ( *(_BYTE *)(v3 + 121) )
            nc_error("cycle found in graph", a2);
          *(_BYTE *)(v3 + 121) = 1;
          v4 = *(_DWORD *)(v3 + 24) - 1;
          if ( v4 >= 0 )
          {
            v81 = 8LL * v4;
            v87 = 8 * (v4 - (unsigned __int64)(unsigned int)v4) - 8;
            do
            {
              v5 = *(_QWORD *)(*(_QWORD *)(v76 + 32) + v81);
              v77 = v5;
              if ( v5 && !*(_BYTE *)(v5 + 120) )
              {
                if ( *(_BYTE *)(v5 + 121) )
                  nc_error("cycle found in graph", a2);
                *(_BYTE *)(v5 + 121) = 1;
                v6 = *(_DWORD *)(v5 + 24) - 1;
                if ( v6 >= 0 )
                {
                  v82 = 8LL * v6;
                  v88 = 8 * (v6 - (unsigned __int64)(unsigned int)v6) - 8;
                  do
                  {
                    v7 = *(_QWORD *)(*(_QWORD *)(v77 + 32) + v82);
                    v78 = v7;
                    if ( v7 && !*(_BYTE *)(v7 + 120) )
                    {
                      if ( *(_BYTE *)(v7 + 121) )
                        nc_error("cycle found in graph", a2);
                      *(_BYTE *)(v7 + 121) = 1;
                      v8 = *(_DWORD *)(v7 + 24) - 1;
                      if ( v8 >= 0 )
                      {
                        v83 = 8LL * v8;
                        v89 = 8 * (v8 - (unsigned __int64)(unsigned int)v8) - 8;
                        do
                        {
                          v9 = *(_QWORD *)(*(_QWORD *)(v78 + 32) + v83);
                          v79 = v9;
                          if ( v9 && !*(_BYTE *)(v9 + 120) )
                          {
                            if ( *(_BYTE *)(v9 + 121) )
                              nc_error("cycle found in graph", a2);
                            *(_BYTE *)(v9 + 121) = 1;
                            v10 = *(_DWORD *)(v9 + 24) - 1;
                            if ( v10 >= 0 )
                            {
                              v84 = 8LL * v10;
                              v90 = 8 * (v10 - (unsigned __int64)(unsigned int)v10) - 8;
                              do
                              {
                                v11 = *(_QWORD *)(*(_QWORD *)(v79 + 32) + v84);
                                v74 = v11;
                                if ( v11 && !*(_BYTE *)(v11 + 120) )
                                {
                                  if ( *(_BYTE *)(v11 + 121) )
                                    nc_error("cycle found in graph", a2);
                                  *(_BYTE *)(v11 + 121) = 1;
                                  v12 = *(_DWORD *)(v11 + 24) - 1;
                                  if ( v12 >= 0 )
                                  {
                                    v73 = 8LL * v12;
                                    v75 = 8 * (v12 - (unsigned __int64)(unsigned int)v12) - 8;
                                    do
                                    {
                                      v13 = *(_QWORD *)(*(_QWORD *)(v74 + 32) + v73);
                                      v71 = v13;
                                      if ( v13 && !*(_BYTE *)(v13 + 120) )
                                      {
                                        if ( *(_BYTE *)(v13 + 121) )
                                          nc_error("cycle found in graph", a2);
                                        *(_BYTE *)(v13 + 121) = 1;
                                        v14 = *(_DWORD *)(v13 + 24) - 1;
                                        if ( v14 >= 0 )
                                        {
                                          v70 = 8LL * v14;
                                          v72 = 8 * (v14 - (unsigned __int64)(unsigned int)v14) - 8;
                                          do
                                          {
                                            v15 = *(_QWORD *)(*(_QWORD *)(v71 + 32) + v70);
                                            if ( v15 && !*(_BYTE *)(v15 + 120) )
                                            {
                                              if ( *(_BYTE *)(v15 + 121) )
                                                nc_error("cycle found in graph", a2);
                                              v16 = *(_DWORD *)(v15 + 24);
                                              *(_BYTE *)(v15 + 121) = 1;
                                              v17 = v16 - 1;
                                              if ( v17 >= 0 )
                                              {
                                                v18 = 8LL * v17;
                                                v69 = 8 * (v17 - (unsigned __int64)(unsigned int)v17) - 8;
                                                do
                                                {
                                                  v19 = *(_QWORD *)(*(_QWORD *)(v15 + 32) + v18);
                                                  if ( v19 && !*(_BYTE *)(v19 + 120) )
                                                  {
                                                    if ( *(_BYTE *)(v19 + 121) )
                                                      nc_error("cycle found in graph", a2);
                                                    v20 = *(_DWORD *)(v19 + 24);
                                                    *(_BYTE *)(v19 + 121) = 1;
                                                    v21 = v20 - 1;
                                                    if ( v21 >= 0 )
                                                    {
                                                      v22 = 8LL * v21;
                                                      v23 = 8 * (v21 - (unsigned __int64)(unsigned int)v21) - 8;
                                                      do
                                                      {
                                                        v24 = *(_QWORD *)(*(_QWORD *)(v19 + 32) + v22);
                                                        v22 -= 8LL;
                                                        sub_151D0(a1, v24);
                                                      }
                                                      while ( v22 != v23 );
                                                    }
                                                    *(_BYTE *)(v19 + 121) = 0;
                                                    *(_BYTE *)(v19 + 120) = 1;
                                                    a2 = *(_QWORD *)(a1 + 8);
                                                    v25 = *(_QWORD *)(a1 + 16);
                                                    v26 = a2 + 1;
                                                    if ( a2 + 1 <= v25 )
                                                    {
                                                      v28 = *(_QWORD **)a1;
                                                    }
                                                    else
                                                    {
                                                      v27 = v25 + (v25 >> 1);
                                                      if ( v26 < 0x10 )
                                                        v26 = 16LL;
                                                      if ( v27 < v26 )
                                                        v27 = v26;
                                                      v28 = realloc(*(void **)a1, 8 * v27);
                                                      a2 = *(_QWORD *)(a1 + 8);
                                                      *(_QWORD *)(a1 + 16) = v27;
                                                      *(_QWORD *)a1 = v28;
                                                      v26 = a2 + 1;
                                                    }
                                                    *(_QWORD *)(a1 + 8) = v26;
                                                    v28[a2] = v19;
                                                  }
                                                  v18 -= 8LL;
                                                }
                                                while ( v69 != v18 );
                                              }
                                              *(_BYTE *)(v15 + 121) = 0;
                                              *(_BYTE *)(v15 + 120) = 1;
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
                                                  v31 = 16LL;
                                                if ( v32 < v31 )
                                                  v32 = v31;
                                                LOBYTE(a2) = 8 * v32;
                                                v33 = realloc(*(void **)a1, 8 * v32);
                                                v29 = *(_QWORD *)(a1 + 8);
                                                *(_QWORD *)(a1 + 16) = v32;
                                                *(_QWORD *)a1 = v33;
                                                v31 = v29 + 1;
                                              }
                                              *(_QWORD *)(a1 + 8) = v31;
                                              v33[v29] = v15;
                                            }
                                            v70 -= 8LL;
                                          }
                                          while ( v72 != v70 );
                                        }
                                        *(_BYTE *)(v71 + 121) = 0;
                                        *(_BYTE *)(v71 + 120) = 1;
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
                                            v36 = 16LL;
                                          if ( v37 < v36 )
                                            v37 = v36;
                                          LOBYTE(a2) = 8 * v37;
                                          v38 = realloc(*(void **)a1, 8 * v37);
                                          v34 = *(_QWORD *)(a1 + 8);
                                          *(_QWORD *)(a1 + 16) = v37;
                                          *(_QWORD *)a1 = v38;
                                          v36 = v34 + 1;
                                        }
                                        *(_QWORD *)(a1 + 8) = v36;
                                        v38[v34] = v71;
                                      }
                                      v73 -= 8LL;
                                    }
                                    while ( v75 != v73 );
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
                                      v41 = 16LL;
                                    if ( v42 < v41 )
                                      v42 = v41;
                                    LOBYTE(a2) = 8 * v42;
                                    v43 = realloc(*(void **)a1, 8 * v42);
                                    v39 = *(_QWORD *)(a1 + 8);
                                    *(_QWORD *)(a1 + 16) = v42;
                                    *(_QWORD *)a1 = v43;
                                    v41 = v39 + 1;
                                  }
                                  *(_QWORD *)(a1 + 8) = v41;
                                  v43[v39] = v74;
                                }
                                v84 -= 8LL;
                              }
                              while ( v90 != v84 );
                            }
                            *(_BYTE *)(v79 + 121) = 0;
                            *(_BYTE *)(v79 + 120) = 1;
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
                                v46 = 16LL;
                              if ( v47 < v46 )
                                v47 = v46;
                              LOBYTE(a2) = 8 * v47;
                              v48 = realloc(*(void **)a1, 8 * v47);
                              v44 = *(_QWORD *)(a1 + 8);
                              *(_QWORD *)(a1 + 16) = v47;
                              *(_QWORD *)a1 = v48;
                              v46 = v44 + 1;
                            }
                            *(_QWORD *)(a1 + 8) = v46;
                            v48[v44] = v79;
                          }
                          v83 -= 8LL;
                        }
                        while ( v89 != v83 );
                      }
                      *(_BYTE *)(v78 + 121) = 0;
                      *(_BYTE *)(v78 + 120) = 1;
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
                          v51 = 16LL;
                        if ( v52 < v51 )
                          v52 = v51;
                        LOBYTE(a2) = 8 * v52;
                        v53 = realloc(*(void **)a1, 8 * v52);
                        v49 = *(_QWORD *)(a1 + 8);
                        *(_QWORD *)(a1 + 16) = v52;
                        *(_QWORD *)a1 = v53;
                        v51 = v49 + 1;
                      }
                      *(_QWORD *)(a1 + 8) = v51;
                      v53[v49] = v78;
                    }
                    v82 -= 8LL;
                  }
                  while ( v88 != v82 );
                }
                *(_BYTE *)(v77 + 121) = 0;
                *(_BYTE *)(v77 + 120) = 1;
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
                    v56 = 16LL;
                  if ( v57 < v56 )
                    v57 = v56;
                  LOBYTE(a2) = 8 * v57;
                  v58 = realloc(*(void **)a1, 8 * v57);
                  v54 = *(_QWORD *)(a1 + 8);
                  *(_QWORD *)(a1 + 16) = v57;
                  *(_QWORD *)a1 = v58;
                  v56 = v54 + 1;
                }
                *(_QWORD *)(a1 + 8) = v56;
                v58[v54] = v77;
              }
              v81 -= 8LL;
            }
            while ( v87 != v81 );
          }
          *(_BYTE *)(v76 + 121) = 0;
          *(_BYTE *)(v76 + 120) = 1;
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
              v61 = 16LL;
            if ( v62 < v61 )
              v62 = v61;
            LOBYTE(a2) = 8 * v62;
            v63 = realloc(*(void **)a1, 8 * v62);
            v59 = *(_QWORD *)(a1 + 8);
            *(_QWORD *)(a1 + 16) = v62;
            *(_QWORD *)a1 = v63;
            v61 = v59 + 1;
          }
          *(_QWORD *)(a1 + 8) = v61;
          v63[v59] = v76;
        }
        v80 -= 8LL;
      }
      while ( v86 != v80 );
    }
    *(_BYTE *)(v85 + 121) = 0;
    *(_BYTE *)(v85 + 120) = 1;
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
        v66 = 16LL;
      if ( v67 < v66 )
        v67 = v66;
      v68 = realloc(*(void **)a1, 8 * v67);
      v64 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(a1 + 16) = v67;
      *(_QWORD *)a1 = v68;
      v66 = v64 + 1;
    }
    *(_QWORD *)(a1 + 8) = v66;
    v68[v64] = v85;
  }
}

