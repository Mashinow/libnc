// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_concat_optimization
// Included functions: 7

// ======================================================
// Function: nc_concat_optimization @ 0x66A2E3A0
// ======================================================

void __fastcall nc_concat_optimization(__int64 a1, __int64 *a2, int a3)
{
  __int64 *v3; // rbp
  char *v4; // rcx
  unsigned __int64 v5; // rbx
  __int64 v6; // rsi
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r9
  char *v9; // rax
  __int64 v10; // r8
  char *v11; // r8
  __int64 v12; // r12
  unsigned __int64 v13; // rdi
  char *v14; // r15
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rdx
  __int64 *v17; // r13
  __int64 v18; // r12
  __int64 v19; // r14
  int v20; // ebx
  unsigned __int64 v21; // rsi
  int v22; // ecx
  int i; // r11d
  char *v24; // rsi
  __int64 v25; // r9
  _QWORD *v26; // r10
  _QWORD *v27; // r8
  __int64 v28; // rax
  __int64 v29; // rdx
  _QWORD *v30; // rsi
  __int64 *v31; // rax
  __int64 v33; // rbp
  _QWORD *v34; // r12
  int v35; // edi
  __int64 *v37; // rcx
  int v38; // r8d
  __int64 v39; // r10
  __int64 *v40; // r11
  __int64 *v41; // rax
  __int64 v42; // rdx
  int v43; // r13d
  __int64 *v44; // rbp
  __int64 *v45; // rax
  int v46; // eax
  __int64 *v47; // rcx
  __int64 v48; // rcx
  unsigned __int64 v49; // rbx
  char *v50; // rax
  char *v51; // rax
  __int64 v52; // rax
  __int64 v53; // rcx
  __int64 v54; // rdx
  __int64 v55; // r9
  _QWORD *v56; // r8
  __int64 v57; // rax
  __int64 v58; // r11
  __int64 *v59; // rax
  __int64 v60; // rdx
  __int64 v61; // rcx
  __int64 *v62; // rax
  __int64 *v64; // rax
  __int64 *v65; // rdx
  __int64 v66; // r9
  __int64 v67; // rcx
  _QWORD *v68; // rax
  _DWORD *v69; // rdi
  _QWORD *v70; // rax
  __int64 *v71; // rax
  __int64 v72; // r11
  __int64 *v73; // rax
  _DWORD *v74; // rdx
  _QWORD *v75; // r8
  int v76; // eax
  _QWORD *v77; // r8
  _DWORD *v78; // rdx
  int v79; // r13d
  __int64 *v80; // rax
  __int64 v81; // r8
  __int64 v82; // rdx
  unsigned __int64 v83; // rdi
  unsigned __int64 v84; // r12
  unsigned __int64 v85; // rsi
  unsigned __int64 v86; // rax
  char *v87; // rax
  __int64 *v88; // rax
  __int64 v89; // rdx
  __int64 v90; // r15
  __int64 *v91; // r14
  __int64 *v92; // r13
  __int64 v93; // rbp
  __int64 *v94; // rsi
  __int64 v95; // rbx
  __int64 v96; // rcx
  __int64 v97; // rcx
  void *(__cdecl *v98)(size_t, size_t); // rbp
  __int64 v99; // rdx
  __int64 v100; // r15
  __int64 v101; // rbp
  __int64 v102; // rbx
  __int64 v103; // rcx
  __int64 v104; // rcx
  __int64 v105; // rdx
  void *(__cdecl *v106)(size_t, size_t); // rbp
  __int64 v107; // rsi
  __int64 *v108; // r13
  __int64 v109; // rax
  __int64 v110; // rcx
  __int64 *v111; // rax
  __int64 v112; // rdx
  __int64 v113; // rdx
  __int64 *v114; // rax
  int v116; // r9d
  int v117; // ecx
  __int64 *v118; // rdx
  __int64 *v119; // rax
  __int64 v120; // r8
  __int64 v121; // r8
  __int64 *v122; // rax
  _DWORD *v124; // r13
  __int64 *v125; // rax
  _QWORD *v126; // rdx
  __int64 v127; // rdx
  __int64 *v128; // rbp
  __int64 v129; // rax
  __int64 v130; // rax
  __int64 v131; // rdx
  __int64 v132; // rcx
  __int64 v133; // r8
  __int64 *v134; // rdx
  __int64 *v135; // rax
  __int64 v136; // r10
  __int64 v137; // rcx
  __int64 *v138; // rbp
  __int64 v139; // rax
  __int64 v140; // rdx
  __int64 *v141; // rsi
  __int64 v142; // rdx
  int v143; // r13d
  int v144; // ebp
  __int64 *v145; // rsi
  void *v146; // r14
  __int64 v147; // r8
  __int64 v148; // rax
  __int64 *v149; // rax
  void *(__cdecl *v150)(size_t, size_t); // rbp
  _QWORD *v151; // r14
  __int64 *v152; // r15
  _DWORD *v153; // r12
  __int64 *v154; // rax
  __int64 **v155; // rdx
  __int64 *v156; // rdx
  __int64 v157; // rdi
  _QWORD *v158; // rax
  _DWORD *v159; // rsi
  _QWORD *v160; // rax
  __int64 *v161; // rcx
  _DWORD *v162; // r15
  _DWORD *v163; // r12
  __int64 *v164; // rax
  int v165; // edx
  _QWORD *v166; // rax
  __int64 *v167; // rcx
  __int64 *v168; // rcx
  __int64 *v169; // rax
  _DWORD *v170; // rsi
  _QWORD *v171; // rax
  __int64 *v172; // rcx
  _QWORD *v173; // rax
  __int64 *v174; // rax
  int v175; // edx
  _QWORD *v176; // rax
  __int64 v177; // rdx
  __int64 v178; // rcx
  __int64 v179; // rax
  __int64 *v180; // rdx
  __int64 v181; // r8
  __int64 v182; // r8
  void *v183; // rax
  __int64 v184; // rdx
  __int64 v185; // rax
  __int64 v186; // rax
  __int64 v187; // r9
  __int64 v188; // r8
  __int64 v189; // rdx
  __int64 v190; // r8
  __int64 v191; // rdi
  __int64 *v192; // rdx
  __int64 v193; // r8
  _QWORD *v194; // rdx
  _DWORD *v195; // rax
  _QWORD *v196; // rdx
  _DWORD *v197; // rax
  _QWORD *v198; // rax
  _DWORD *v199; // rdx
  __int64 *v200; // rdx
  __int64 v201; // r9
  __int64 v202; // rdx
  __int64 v203; // r13
  _DWORD *v204; // rbp
  __int64 v205; // rsi
  __int64 v206; // rbx
  __int64 v207; // rcx
  __int64 v208; // [rsp+38h] [rbp-D0h]
  __int64 *v209; // [rsp+58h] [rbp-B0h] BYREF
  void *Block; // [rsp+60h] [rbp-A8h] BYREF
  unsigned __int64 v211; // [rsp+68h] [rbp-A0h]
  unsigned __int64 v212; // [rsp+70h] [rbp-98h]
  void *v213; // [rsp+80h] [rbp-88h]
  unsigned __int64 v214; // [rsp+88h] [rbp-80h]
  unsigned __int64 v215; // [rsp+90h] [rbp-78h]
  __int64 *v216; // [rsp+A0h] [rbp-68h] BYREF
  __int64 *v217; // [rsp+A8h] [rbp-60h]
  __int64 v218; // [rsp+B0h] [rbp-58h]
  __int64 v219; // [rsp+B8h] [rbp-50h]

  Block = 0i64;
  v211 = 0i64;
  v212 = 0i64;
  v213 = 0i64;
  v214 = 0i64;
  v215 = 0i64;
  if ( a3 <= 0 )
  {
    v7 = 0i64;
  }
  else
  {
    v3 = a2;
    v4 = 0i64;
    v5 = 0i64;
    v6 = (__int64)&a2[(unsigned int)(a3 - 1) + 1];
    v7 = 0i64;
    do
    {
      v8 = v7 + 1;
      v12 = *v3;
      if ( v7 + 1 > v5 )
      {
        v5 += v5 >> 1;
        if ( v8 < 0x10 )
          v8 = 16i64;
        if ( v5 < v8 )
          v5 = v8;
        v9 = (char *)realloc(v4, 16 * v5);
        v10 = v211;
        v212 = v5;
        Block = v9;
        v4 = v9;
        v7 = v211 + 1;
      }
      else
      {
        v10 = v7++;
      }
      ++v3;
      v11 = &v4[16 * v10];
      *(_QWORD *)v11 = v12;
      *((_QWORD *)v11 + 1) = 0i64;
      v211 = v7;
    }
    while ( v3 != (__int64 *)v6 );
  }
  while ( 1 )
  {
LABEL_12:
    if ( v7 )
    {
      v211 = v7 - 1;
      v31 = (__int64 *)((char *)Block + 16 * v7 - 16);
      _RBX = *v31;
      v33 = v31[1];
      if ( *(_DWORD *)(*v31 + 20) != 14 )
        sub_66A33D40("concat_node->opcode == OP_concat", "libnc.c", 7949);
      v34 = *(_QWORD **)(_RBX + 32);
      v35 = *(_DWORD *)(_RBX + 24);
      _RSI = (_DWORD *)*v34;
      if ( v35 <= 0 )
      {
        switch ( _RSI[5] )
        {
          case 2:
            goto LABEL_203;
          case 3:
            v143 = _RSI[14];
            v144 = v143 - 1;
            if ( v143 - 1 > 0 )
              goto LABEL_226;
            v145 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v183 = aligned_malloc(8i64 * v35, 0x40ui64);
            v180 = 0i64;
            v178 = v144;
            v146 = v183;
            goto LABEL_235;
          case 6:
            goto LABEL_190;
          case 7:
LABEL_249:
            v138 = (__int64 *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(8i64 * v35, 64i64);
            if ( v35 <= 0 )
              goto LABEL_185;
            goto LABEL_183;
          case 0xA:
          case 0xB:
            v124 = (_DWORD *)**((_QWORD **)_RSI + 6);
            v128 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v91 = (__int64 *)nc_mallocz(8i64 * v35);
            if ( v124 )
              goto LABEL_219;
            goto LABEL_220;
          case 0xF:
LABEL_148:
            v116 = _RSI[14];
            v117 = *(_DWORD *)(_RBX + 64);
            if ( v116 != v117 )
            {
              if ( v35 > 0 )
              {
                v118 = v34 + 1;
                v119 = v34 + 1;
                while ( &v34[(unsigned int)(v35 - 1) + 1] != v119 )
                {
                  v120 = *v119;
                  if ( v116 == *(_DWORD *)(*v119 + 56) && *(_QWORD *)(v120 + 64) == *((_QWORD *)_RSI + 8) )
                  {
                    ++v119;
                    if ( *(_QWORD *)(v120 + 72) == *((_QWORD *)_RSI + 9) )
                      continue;
                  }
                  goto LABEL_51;
                }
                if ( _RSI[4] != 1 )
                  goto LABEL_110;
                while ( v119 != v118 )
                {
                  v121 = *v118++;
                  if ( *(_DWORD *)(v121 + 16) != 1 )
                    goto LABEL_110;
                }
              }
              v122 = sub_66A10410(a1, (__int64)v34, v35, 0, v117, *(_QWORD *)(_RBX + 56));
              ++_RSI[4];
              v209 = v122;
              sub_66A164C0(_RBX, 15, 1, (__int64)&v209);
              *(_DWORD *)(_RBX + 56) = _RSI[14];
              __asm
              {
                vmovdqu xmm0, xmmword ptr [rsi+40h]
                vmovups xmmword ptr [rbx+40h], xmm0
              }
              goto LABEL_73;
            }
            v186 = **((_QWORD **)_RSI + 4);
            if ( v35 <= 0 )
              goto LABEL_262;
            if ( *((_QWORD *)_RSI + 8) )
              goto LABEL_51;
            v187 = (unsigned int)(v35 - 1);
            v188 = 0i64;
            v189 = 0i64;
            while ( 1 )
            {
              v191 = *(_QWORD *)(*(_QWORD *)(_RBX + 56) + v189 * 8) + v188;
              if ( v187 == v189 )
                break;
              v190 = v34[++v189];
              if ( **(_QWORD **)(v190 + 32) == v186 && v117 == *(_DWORD *)(v190 + 56) )
              {
                v188 = *(_QWORD *)(v190 + 64);
                if ( v188 == v191 )
                  continue;
              }
              goto LABEL_51;
            }
            if ( _RSI[4] == 1 )
            {
              v192 = v34 + 1;
              do
              {
                if ( &v34[v187 + 1] == v192 )
                {
LABEL_262:
                  ++*(_DWORD *)(v186 + 16);
                  v216 = (__int64 *)v186;
                  v217 = 0i64;
                  sub_66A164C0(_RBX, 6, 2, (__int64)&v216);
                  nc_free_node(v216);
                  v7 = v211;
                  goto LABEL_12;
                }
                v193 = *v192++;
              }
              while ( *(_DWORD *)(v193 + 16) == 1 );
            }
            goto LABEL_110;
          case 0x11:
            goto LABEL_147;
          case 0x12:
            v106 = aligned_malloc;
            v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v108 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            goto LABEL_217;
          case 0x17:
            v98 = aligned_malloc;
            v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v92 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v94 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            goto LABEL_215;
          case 0x18:
            v98 = aligned_malloc;
            v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v92 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v94 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            goto LABEL_211;
          case 0x1C:
            v79 = _RSI[14];
            goto LABEL_209;
          case 0x1D:
            v43 = _RSI[*(int *)(_RBX + 64) + 15];
            v44 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
LABEL_44:
            v45 = nc_concat_node(a1, (__int64)v44, v35, v43, *(_QWORD *)(_RBX + 56));
            ++_RSI[4];
            v209 = v45;
            sub_66A164C0(_RBX, 29, 1, (__int64)&v209);
            *(_DWORD *)(_RBX + 56) = _RSI[14];
            v46 = _RSI[14];
            if ( v46 > 0 )
            {
              *(_DWORD *)(_RBX + 60) = _RSI[15];
              if ( v46 != 1 )
              {
                *(_DWORD *)(_RBX + 64) = _RSI[16];
                if ( v46 != 2 )
                {
                  *(_DWORD *)(_RBX + 68) = _RSI[17];
                  if ( v46 != 3 )
                    *(_DWORD *)(_RBX + 72) = _RSI[18];
                }
              }
            }
            nc_free_node((__int64 *)_RSI);
            nc_free_node(v209);
            v47 = v44;
            goto LABEL_50;
          case 0x1E:
            v150 = aligned_malloc;
            v151 = aligned_malloc(8i64 * v35, 0x40ui64);
            v152 = (__int64 *)nc_mallocz(8i64 * v35);
            goto LABEL_207;
          case 0x1F:
LABEL_74:
            if ( *(_DWORD *)(_RBX + 64) != 1 )
              goto LABEL_51;
            if ( v35 <= 0 )
              goto LABEL_83;
            v64 = v34 + 1;
            v65 = v34 + 1;
            while ( v65 != &v34[(unsigned int)(v35 - 1) + 1] )
            {
              v66 = *v65++;
              if ( **(_QWORD **)(v66 + 32) != **((_QWORD **)_RSI + 4) )
                goto LABEL_51;
            }
            if ( _RSI[4] == 1 )
            {
              do
              {
                if ( v64 == v65 )
                {
LABEL_83:
                  v68 = sub_66A23AB0(*(_QWORD *)(_RBX + 32), v35, 0);
                  ++_RSI[4];
                  v69 = v68;
                  sub_66A164C0(_RBX, 31, 1, *((_QWORD *)_RSI + 4));
                  *(_DWORD *)(_RBX + 40) = 1;
                  v70 = aligned_malloc(8ui64, 0x40ui64);
                  *(_QWORD *)(_RBX + 48) = v70;
                  ++v69[4];
                  *v70 = v69;
                  *(_QWORD *)(_RBX + 56) = *((_QWORD *)_RSI + 7);
                  nc_free_node((__int64 *)_RSI);
                  nc_free_tensor(v69);
                  v7 = v211;
                  goto LABEL_12;
                }
                v67 = *v64++;
              }
              while ( *(_DWORD *)(v67 + 16) == 1 );
            }
            goto LABEL_110;
          case 0x24:
LABEL_62:
            if ( *(_DWORD *)(_RBX + 64) != 1 )
              goto LABEL_51;
            if ( v35 <= 0 )
              goto LABEL_72;
            v52 = *((_QWORD *)_RSI + 7);
            v53 = (unsigned int)(v35 - 1);
            v54 = v52 + 1;
            v55 = v52 + v53 + 1;
            v56 = &v34[-v52];
            break;
          default:
            goto LABEL_51;
        }
        while ( v54 != v55 )
        {
          v57 = v56[v54];
          if ( *((_QWORD *)_RSI + 8) == *(_QWORD *)(v57 + 64) )
          {
            v58 = v54++;
            if ( *(_QWORD *)(v57 + 56) == v58 )
              continue;
          }
          goto LABEL_51;
        }
        if ( _RSI[4] == 1 )
        {
          v59 = v34 + 1;
          v60 = (__int64)&v34[v53 + 1];
          do
          {
            if ( v59 == (__int64 *)v60 )
            {
LABEL_72:
              v62 = sub_66A10410(a1, *(_QWORD *)(_RBX + 32), v35, 0, 1, *(_QWORD *)(_RBX + 56));
              ++_RSI[4];
              v209 = v62;
              sub_66A164C0(_RBX, 36, 1, (__int64)&v209);
              __asm
              {
                vmovdqu xmm0, xmmword ptr [rsi+38h]
                vmovups xmmword ptr [rbx+38h], xmm0
              }
LABEL_73:
              nc_free_node((__int64 *)_RSI);
              nc_free_node(v209);
              sub_66A074B0(&Block, (__int64)v209, *(_QWORD *)(_RBX + 32));
              v7 = v211;
              goto LABEL_12;
            }
            v61 = *v59++;
          }
          while ( *(_DWORD *)(v61 + 16) == 1 );
        }
LABEL_110:
        v83 = v214;
        v84 = v214 + 1;
        if ( v214 + 1 <= v215 )
        {
          v87 = (char *)v213;
        }
        else
        {
          v85 = v215 + (v215 >> 1);
          v86 = 16i64;
          if ( v84 >= 0x10 )
            v86 = v214 + 1;
          if ( v85 < v86 )
            v85 = v86;
          v87 = (char *)realloc(v213, 16 * v85);
          v215 = v85;
          v213 = v87;
        }
        v214 = v84;
        v7 = v211;
        v88 = (__int64 *)&v87[16 * v83];
        *v88 = _RBX;
        v88[1] = v33;
        continue;
      }
      if ( !_RSI )
      {
LABEL_51:
        v7 = v211;
        continue;
      }
      v37 = v34 + 1;
      v38 = _RSI[5];
      v39 = (unsigned int)(v35 - 1);
      v40 = v34 + 1;
      v41 = v34 + 1;
      while ( v41 != &v34[v39 + 1] )
      {
        v42 = *v41;
        if ( *v41 )
        {
          ++v41;
          if ( *(_DWORD *)(v42 + 20) == v38 )
            continue;
        }
        goto LABEL_51;
      }
      switch ( v38 )
      {
        case 2:
          while ( v37 != v41 )
          {
            v147 = *v37++;
            if ( _RSI[14] != *(_DWORD *)(v147 + 56) )
              goto LABEL_51;
          }
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          while ( v40 != v37 )
          {
            v148 = *v40++;
            if ( *(_DWORD *)(v148 + 16) != 1 )
              goto LABEL_110;
          }
LABEL_203:
          v149 = sub_66A10410(a1, *(_QWORD *)(_RBX + 32), v35, 0, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
          ++_RSI[4];
          v209 = v149;
          sub_66A164C0(_RBX, 2, 1, (__int64)&v209);
          *(_DWORD *)(_RBX + 56) = _RSI[14];
          goto LABEL_73;
        case 3:
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          while ( &v34[v39 + 1] != v37 )
          {
            v142 = *v37++;
            if ( *(_DWORD *)(v142 + 16) != 1 )
              goto LABEL_110;
          }
          v143 = _RSI[14];
          v144 = v143 - 1;
          if ( v143 - 1 > 0 )
          {
LABEL_226:
            v216 = (__int64 *)*((_QWORD *)_RSI + 8);
            if ( v144 != 1 )
            {
              v217 = (__int64 *)*((_QWORD *)_RSI + 9);
              if ( v144 != 2 )
              {
                v218 = *((_QWORD *)_RSI + 10);
                if ( v144 != 3 )
                  v219 = *((_QWORD *)_RSI + 11);
              }
            }
            v145 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v146 = aligned_malloc(8i64 * v35, 0x40ui64);
            if ( v35 <= 0 )
            {
              (&v216)[v144] = 0i64;
              v209 = nc_concat_node(a1, (__int64)v145, v35, v144, (__int64)v146);
              sub_66A164C0(_RBX, 3, 1, (__int64)&v209);
              *(_DWORD *)(_RBX + 56) = v143;
              *(_QWORD *)(_RBX + 64) = v216;
LABEL_237:
              *(_QWORD *)(_RBX + 72) = v217;
              if ( v144 != 1 )
              {
                *(_QWORD *)(_RBX + 80) = v218;
                if ( v144 != 2 )
                  *(_QWORD *)(_RBX + 88) = v219;
              }
LABEL_240:
              nc_free_node(v209);
              _aligned_free(v146);
              v47 = v145;
LABEL_50:
              _aligned_free(v47);
              sub_66A074B0(&Block, (__int64)v209, *(_QWORD *)(_RBX + 32));
              goto LABEL_51;
            }
          }
          else
          {
            v145 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v146 = aligned_malloc(8i64 * v35, 0x40ui64);
          }
          v178 = v144;
          v179 = 0i64;
          v180 = 0i64;
          do
          {
            v181 = v34[v179];
            v145[v179] = **(_QWORD **)(v181 + 32);
            v182 = *(_QWORD *)(v181 + 8 * (v144 + 4i64) + 32);
            *((_QWORD *)v146 + v179++) = v182;
            v180 = (__int64 *)((char *)v180 + v182);
          }
          while ( v35 > (int)v179 );
LABEL_235:
          (&v216)[v178] = v180;
          v209 = nc_concat_node(a1, (__int64)v145, v35, v144, (__int64)v146);
          sub_66A164C0(_RBX, 3, 1, (__int64)&v209);
          *(_DWORD *)(_RBX + 56) = v143;
          if ( v144 < 0 )
            goto LABEL_240;
          *(_QWORD *)(_RBX + 64) = v216;
          if ( !v144 )
            goto LABEL_240;
          goto LABEL_237;
        case 6:
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          do
          {
            if ( &v34[v39 + 1] == v37 )
            {
LABEL_190:
              v209 = sub_66A10410(a1, *(_QWORD *)(_RBX + 32), v35, 0, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
              v141 = sub_66A10410(a1, (__int64)v34, v35, 1, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
              v217 = v141;
              v216 = v209;
              sub_66A164C0(_RBX, 6, 2, (__int64)&v216);
              nc_free_node(v209);
              nc_free_node(v141);
              sub_66A074B0(&Block, (__int64)v209, *(_QWORD *)(_RBX + 32));
              sub_66A074B0(&Block, (__int64)v141, *(_QWORD *)(_RBX + 32) + 8i64);
              v7 = v211;
              goto LABEL_12;
            }
            v140 = *v37++;
          }
          while ( *(_DWORD *)(v140 + 16) == 1 );
          goto LABEL_110;
        case 7:
          if ( v35 <= 1 )
            goto LABEL_249;
          v132 = v34[1];
          v133 = *(_QWORD *)(*((_QWORD *)_RSI + 4) + 8i64);
          if ( v133 != *(_QWORD *)(*(_QWORD *)(v132 + 32) + 8i64) )
            goto LABEL_51;
          v134 = v34 + 2;
          v135 = v34 + 2;
          while ( &v34[(unsigned int)(v35 - 2) + 2] != v135 )
          {
            v136 = *v135++;
            if ( *(_QWORD *)(*(_QWORD *)(v136 + 32) + 8i64) != v133 )
              goto LABEL_51;
          }
          if ( *(_DWORD *)(v132 + 16) != 1 )
            goto LABEL_110;
          if ( v135 == v134 )
          {
LABEL_182:
            v138 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
LABEL_183:
            v139 = 0i64;
            do
            {
              v138[v139] = **(_QWORD **)(v34[v139] + 32i64);
              ++v139;
            }
            while ( v35 > (int)v139 );
LABEL_185:
            v216 = nc_concat_node(a1, (__int64)v138, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
            v209 = v216;
            v217 = *(__int64 **)(*((_QWORD *)_RSI + 4) + 8i64);
            sub_66A164C0(_RBX, 7, 2, (__int64)&v216);
            nc_free_node(v209);
            v47 = v138;
            goto LABEL_50;
          }
          while ( 1 )
          {
            v137 = *v134++;
            if ( *(_DWORD *)(v137 + 16) != 1 )
              goto LABEL_110;
            if ( v135 == v134 )
              goto LABEL_182;
          }
        case 10:
        case 11:
          v124 = (_DWORD *)**((_QWORD **)_RSI + 6);
          v125 = v34 + 1;
          while ( &v34[v39 + 1] != v125 )
          {
            if ( *(_QWORD *)(*(_QWORD *)(*v125 + 32) + 8i64) == *(_QWORD *)(*((_QWORD *)_RSI + 4) + 8i64) )
            {
              v126 = *(_QWORD **)(*v125++ + 48);
              if ( (*v126 != 0i64) == (v124 != 0i64) )
                continue;
            }
            goto LABEL_51;
          }
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          if ( v125 == v37 )
          {
LABEL_168:
            v128 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
            v91 = (__int64 *)nc_mallocz(8i64 * v35);
            v129 = 0i64;
            do
            {
              v128[v129] = **(_QWORD **)(v34[v129] + 32i64);
              ++v129;
            }
            while ( v35 > (int)v129 );
            v130 = 0i64;
            if ( v124 )
            {
              do
              {
                v131 = **(_QWORD **)(v34[v130] + 48i64);
                ++*(_DWORD *)(v131 + 16);
                v91[v130++] = v131;
              }
              while ( v35 > (int)v130 );
LABEL_219:
              v173 = nc_concat(v91, v35, 1);
              v124 = nc_stop_grad((__int64)v173);
            }
LABEL_220:
            v174 = nc_concat_node(a1, (__int64)v128, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
            ++_RSI[4];
            v175 = _RSI[5];
            v216 = v174;
            v209 = v174;
            v217 = *(__int64 **)(*((_QWORD *)_RSI + 4) + 8i64);
            sub_66A164C0(_RBX, v175, 2, (__int64)&v216);
            *(_DWORD *)(_RBX + 40) = 2;
            v176 = nc_mallocz(0x10ui64);
            *(_QWORD *)(_RBX + 48) = v176;
            if ( v124 )
            {
              ++v124[4];
              *v176 = v124;
            }
            v177 = *(_QWORD *)(*((_QWORD *)_RSI + 6) + 8i64);
            if ( v177 )
            {
              ++*(_DWORD *)(v177 + 16);
              v176[1] = v177;
            }
            nc_free_node((__int64 *)_RSI);
            nc_free_node(v209);
            nc_free_tensor(v124);
            v168 = v128;
LABEL_213:
            _aligned_free(v168);
            v47 = v91;
            goto LABEL_50;
          }
          while ( 1 )
          {
            v127 = *v37++;
            if ( *(_DWORD *)(v127 + 16) != 1 )
              goto LABEL_110;
            if ( v125 == v37 )
              goto LABEL_168;
          }
        case 15:
          goto LABEL_148;
        case 17:
          v111 = v34 + 1;
          while ( v111 != &v34[v39 + 1] )
          {
            v112 = *v111;
            if ( *(_QWORD *)(*v111 + 56) == *((_QWORD *)_RSI + 7) && *(_QWORD *)(v112 + 64) == *((_QWORD *)_RSI + 8) )
            {
              ++v111;
              if ( *(_QWORD *)(v112 + 72) == *((_QWORD *)_RSI + 9) )
                continue;
            }
            goto LABEL_51;
          }
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          while ( v111 != v37 )
          {
            v113 = *v37++;
            if ( *(_DWORD *)(v113 + 16) != 1 )
              goto LABEL_110;
          }
LABEL_147:
          v114 = sub_66A10410(a1, *(_QWORD *)(_RBX + 32), v35, 0, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
          ++_RSI[4];
          v209 = v114;
          sub_66A164C0(_RBX, 17, 1, (__int64)&v209);
          __asm
          {
            vmovdqu xmm0, xmmword ptr [rsi+38h]
            vmovups xmmword ptr [rbx+38h], xmm0
          }
          *(_DWORD *)(_RBX + 72) = _RSI[18];
          *(_DWORD *)(_RBX + 76) = _RSI[19];
          goto LABEL_73;
        case 18:
          if ( _RSI[4] != 2 )
            goto LABEL_110;
          while ( &v34[v39 + 1] != v37 )
          {
            v105 = *v37++;
            if ( *(_DWORD *)(v105 + 16) != 2 )
              goto LABEL_110;
          }
          v106 = aligned_malloc;
          v107 = 0i64;
          v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v108 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          do
          {
            v109 = v34[v107];
            v110 = **(_QWORD **)(v109 + 48);
            v91[v107] = **(_QWORD **)(v109 + 32);
            ++*(_DWORD *)(v110 + 16);
            v108[v107++] = (__int64)nc_stop_grad(v110);
          }
          while ( v35 > (int)v107 );
LABEL_217:
          v170 = nc_concat(v108, v35, *(_DWORD *)(_RBX + 64));
          v209 = nc_concat_node(a1, (__int64)v91, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
          sub_66A164C0(_RBX, 18, 1, (__int64)&v209);
          *(_DWORD *)(_RBX + 40) = 1;
          v171 = v106(8ui64, 0x40ui64);
          v172 = v209;
          *(_QWORD *)(_RBX + 48) = v171;
          ++v170[4];
          *v171 = v170;
          nc_free_node(v172);
          nc_free_tensor(v170);
          v168 = v108;
          goto LABEL_213;
        case 23:
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          while ( &v34[v39 + 1] != v37 )
          {
            v99 = *v37++;
            if ( *(_DWORD *)(v99 + 16) != 1 )
              goto LABEL_110;
          }
          v100 = 0i64;
          v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v92 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v101 = _RBX;
          v94 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          do
          {
            v102 = v34[v100];
            v91[v100] = **(_QWORD **)(v102 + 32);
            v103 = **(_QWORD **)(v102 + 48);
            ++*(_DWORD *)(v103 + 16);
            v92[v100] = (__int64)nc_stop_grad(v103);
            v104 = *(_QWORD *)(*(_QWORD *)(v102 + 48) + 8i64);
            ++*(_DWORD *)(v104 + 16);
            v94[v100++] = (__int64)nc_stop_grad(v104);
          }
          while ( v35 > (int)v100 );
          _RBX = v101;
          v98 = aligned_malloc;
LABEL_215:
          v162 = nc_concat(v92, v35, *(_DWORD *)(_RBX + 64));
          v163 = nc_concat(v94, v35, *(_DWORD *)(_RBX + 64));
          v169 = nc_concat_node(a1, (__int64)v91, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
          v165 = 23;
          v209 = v169;
          goto LABEL_212;
        case 24:
          if ( _RSI[4] != 2 )
            goto LABEL_110;
          while ( &v34[v39 + 1] != v37 )
          {
            v89 = *v37++;
            if ( *(_DWORD *)(v89 + 16) != 2 )
              goto LABEL_110;
          }
          v90 = 0i64;
          v91 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v92 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v93 = _RBX;
          v94 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          do
          {
            v95 = v34[v90];
            v91[v90] = **(_QWORD **)(v95 + 32);
            v96 = **(_QWORD **)(v95 + 48);
            ++*(_DWORD *)(v96 + 16);
            v92[v90] = (__int64)nc_stop_grad(v96);
            v97 = *(_QWORD *)(*(_QWORD *)(v95 + 48) + 8i64);
            ++*(_DWORD *)(v97 + 16);
            v94[v90++] = (__int64)nc_stop_grad(v97);
          }
          while ( v35 > (int)v90 );
          _RBX = v93;
          v98 = aligned_malloc;
LABEL_211:
          v162 = nc_concat(v92, v35, *(_DWORD *)(_RBX + 64));
          v163 = nc_concat(v94, v35, *(_DWORD *)(_RBX + 64) - 1);
          v164 = nc_concat_node(a1, (__int64)v91, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
          v165 = 24;
          v209 = v164;
LABEL_212:
          sub_66A164C0(_RBX, v165, 1, (__int64)&v209);
          *(_DWORD *)(_RBX + 40) = 2;
          v166 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))v98)(16i64, 64i64);
          v167 = v209;
          *(_QWORD *)(_RBX + 48) = v166;
          ++v162[4];
          *v166 = v162;
          ++v163[4];
          v166[1] = v163;
          nc_free_node(v167);
          nc_free_tensor(v162);
          nc_free_tensor(v163);
          _aligned_free(v92);
          v168 = v94;
          goto LABEL_213;
        case 28:
          v79 = _RSI[14];
          v80 = v34 + 1;
          while ( v80 != &v34[v39 + 1] )
          {
            v81 = *v80++;
            if ( *(_DWORD *)(v81 + 56) != v79 )
              goto LABEL_51;
          }
          if ( _RSI[4] == 1 )
          {
            do
            {
              if ( v80 == v37 )
              {
LABEL_209:
                v159 = sub_66A23AB0(*(_QWORD *)(_RBX + 32), v35, *(_DWORD *)(_RBX + 64));
                v209 = sub_66A10410(a1, (__int64)v34, v35, 0, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
                sub_66A164C0(_RBX, 28, 1, (__int64)&v209);
                *(_DWORD *)(_RBX + 40) = 1;
                v160 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64))aligned_malloc)(8i64, 64i64);
                v161 = v209;
                *(_QWORD *)(_RBX + 48) = v160;
                ++v159[4];
                *v160 = v159;
                *(_DWORD *)(_RBX + 56) = v79;
                nc_free_node(v161);
                nc_free_tensor(v159);
                sub_66A074B0(&Block, (__int64)v209, *(_QWORD *)(_RBX + 32));
                v7 = v211;
                goto LABEL_12;
              }
              v82 = *v37++;
            }
            while ( *(_DWORD *)(v82 + 16) == 1 );
          }
          goto LABEL_110;
        case 29:
          v76 = _RSI[14];
          if ( v76 <= 0 )
          {
            v200 = v34 + 1;
            while ( v200 != &v34[(unsigned int)v39 + 1] )
            {
              v201 = *v200++;
              if ( *(_DWORD *)(v201 + 56) != v76 )
              {
                v7 = v211;
                goto LABEL_12;
              }
            }
          }
          else
          {
            switch ( v76 )
            {
              case 1:
                v198 = v34 + 1;
                v199 = (_DWORD *)*v34;
                while ( 1 )
                {
                  if ( v199[15] != _RSI[15] )
                    goto LABEL_51;
                  if ( v198 == &v34[(unsigned int)v39 + 1] )
                    break;
                  v199 = (_DWORD *)*v198++;
                  if ( v199[14] != 1 )
                  {
                    v7 = v211;
                    goto LABEL_12;
                  }
                }
                break;
              case 4:
                v196 = v34 + 1;
                v197 = (_DWORD *)*v34;
                while ( 1 )
                {
                  if ( _RSI[15] != v197[15] || _RSI[16] != v197[16] || _RSI[17] != v197[17] || _RSI[18] != v197[18] )
                    goto LABEL_51;
                  if ( v196 == &v34[(unsigned int)v39 + 1] )
                    break;
                  v197 = (_DWORD *)*v196++;
                  if ( v197[14] != 4 )
                  {
                    v7 = v211;
                    goto LABEL_12;
                  }
                }
                break;
              case 3:
                v194 = v34 + 1;
                v195 = (_DWORD *)*v34;
                while ( 1 )
                {
                  if ( _RSI[15] != v195[15] || _RSI[16] != v195[16] || _RSI[17] != v195[17] )
                    goto LABEL_51;
                  if ( v194 == &v34[(unsigned int)v39 + 1] )
                    break;
                  v195 = (_DWORD *)*v194++;
                  if ( v195[14] != 3 )
                  {
                    v7 = v211;
                    goto LABEL_12;
                  }
                }
                break;
              default:
                v77 = v34 + 1;
                v78 = (_DWORD *)*v34;
                while ( 1 )
                {
                  if ( v78[15] != _RSI[15] || v78[16] != _RSI[16] || v76 != 2 )
                    goto LABEL_51;
                  if ( v77 == &v34[(unsigned int)v39 + 1] )
                    break;
                  v78 = (_DWORD *)*v77++;
                  if ( v78[14] != 2 )
                  {
                    v7 = v211;
                    goto LABEL_12;
                  }
                }
                break;
            }
          }
          if ( _RSI[4] != 1 )
            goto LABEL_110;
          while ( &v34[v39 + 1] != v37 )
          {
            v184 = *v37++;
            if ( *(_DWORD *)(v184 + 16) != 1 )
              goto LABEL_110;
          }
          v43 = _RSI[*(int *)(_RBX + 64) + 15];
          v44 = (__int64 *)aligned_malloc(8i64 * v35, 0x40ui64);
          v185 = 0i64;
          do
          {
            v44[v185] = **(_QWORD **)(v34[v185] + 32i64);
            ++v185;
          }
          while ( v35 > (int)v185 );
          goto LABEL_44;
        case 30:
          v71 = (__int64 *)*((_QWORD *)_RSI + 4);
          v72 = *v71;
          if ( v71[2] )
            goto LABEL_51;
          v73 = v34 + 1;
          v74 = (_DWORD *)*v34;
          while ( 1 )
          {
            if ( v74[15] )
            {
              v7 = v211;
              goto LABEL_12;
            }
            if ( !*(_QWORD *)(*((_QWORD *)v74 + 6) + 8i64) )
              goto LABEL_51;
            if ( v73 == &v34[v39 + 1] )
              break;
            v74 = (_DWORD *)*v73;
            v75 = *(_QWORD **)(*v73 + 32);
            if ( *v75 == v72 && !v75[2] )
            {
              ++v73;
              if ( v74[14] == _RSI[14] )
                continue;
            }
            goto LABEL_51;
          }
          if ( _RSI[4] == 1 )
          {
            do
            {
              if ( v37 == v73 )
              {
                v203 = 0i64;
                v151 = aligned_malloc(8i64 * v35, 0x40ui64);
                v204 = _RSI;
                v205 = _RBX;
                v152 = (__int64 *)nc_mallocz(8i64 * v35);
                do
                {
                  v206 = v34[v203];
                  v207 = *(_QWORD *)(*(_QWORD *)(v206 + 48) + 8i64);
                  ++*(_DWORD *)(v207 + 16);
                  v152[v203] = (__int64)nc_stop_grad(v207);
                  v151[v203++] = *(_QWORD *)(*(_QWORD *)(v206 + 32) + 8i64);
                }
                while ( v35 > (int)v203 );
                _RBX = v205;
                _RSI = v204;
                v150 = aligned_malloc;
LABEL_207:
                v153 = nc_concat(v152, v35, 1);
                v154 = nc_concat_node(a1, (__int64)v151, v35, *(_DWORD *)(_RBX + 64), *(_QWORD *)(_RBX + 56));
                v155 = (__int64 **)*((_QWORD *)_RSI + 4);
                ++_RSI[4];
                v209 = v154;
                v156 = *v155;
                v217 = v154;
                v218 = 0i64;
                v216 = v156;
                sub_66A164C0(_RBX, 30, 3, (__int64)&v216);
                v157 = **((_QWORD **)_RSI + 6);
                *(_DWORD *)(_RBX + 40) = 2;
                v158 = v150(0x10ui64, 0x40ui64);
                *(_QWORD *)(_RBX + 48) = v158;
                ++*(_DWORD *)(v157 + 16);
                *v158 = v157;
                ++v153[4];
                v158[1] = v153;
                *(_DWORD *)(_RBX + 56) = _RSI[14];
                *(_DWORD *)(_RBX + 60) = _RSI[15];
                nc_free_node((__int64 *)_RSI);
                nc_free_node(v209);
                nc_free_tensor(v153);
                _aligned_free(v151);
                _aligned_free(v152);
                sub_66A074B0(&Block, (__int64)v209, *(_QWORD *)(_RBX + 32) + 8i64);
                v7 = v211;
                goto LABEL_12;
              }
              v202 = *v37++;
            }
            while ( *(_DWORD *)(v202 + 16) == 1 );
          }
          goto LABEL_110;
        case 31:
          goto LABEL_74;
        case 36:
          goto LABEL_62;
        default:
          goto LABEL_51;
      }
    }
    v13 = v214;
    if ( v214 <= 1 )
      break;
    v14 = (char *)v213;
    v15 = 1i64;
    v16 = v214 - 1;
    v17 = (__int64 *)v213;
    while ( 1 )
    {
      v18 = *v17;
      v19 = v17[1];
      v20 = v15;
      v21 = v15;
      if ( v13 > v15 )
        break;
LABEL_32:
      ++v15;
      v17 += 2;
      if ( v16 <= v15 - 1 )
        goto LABEL_33;
    }
    v22 = *(_DWORD *)(v18 + 24);
    for ( i = 0; ; i = 1 )
    {
      while ( 1 )
      {
        v24 = &v14[16 * v21];
        v25 = *(_QWORD *)v24;
        if ( *(_DWORD *)(*(_QWORD *)v24 + 24i64) != v22 || *(_DWORD *)(v25 + 64) != *(_DWORD *)(v18 + 64) )
          goto LABEL_17;
        if ( v22 <= 0 )
          break;
        v26 = *(_QWORD **)(v18 + 32);
        v27 = *(_QWORD **)(v25 + 32);
        if ( *v27 == *v26 )
        {
          v28 = 1i64;
          while ( v22 > (int)v28 )
          {
            v29 = v27[v28++];
            if ( v29 != v26[v28 - 1] )
              goto LABEL_17;
          }
          break;
        }
LABEL_17:
        ++v20;
        v13 = v214;
        v21 = v20;
        if ( v20 >= v214 )
        {
          if ( i )
            goto LABEL_53;
          v16 = v214 - 1;
          goto LABEL_32;
        }
      }
      if ( *(int *)(v25 + 16) > 1 )
        goto LABEL_17;
      v30 = (_QWORD *)*((_QWORD *)v24 + 1);
      if ( !v30 )
      {
        v208 = v25;
        sub_66A33D40("pparent1 != NULL", "libnc.c", 8576);
        v25 = v208;
      }
      nc_free_node((__int64 *)v25);
      ++*(_DWORD *)(v18 + 16);
      *v30 = v18;
      v21 = v20;
      if ( v20 >= v13 - 1 )
        break;
      memmove(&v14[16 * v20], &v14[16 * v20 + 16], 16 * (v13 - v20) - 16);
      v22 = *(_DWORD *)(v18 + 24);
      v214 = --v13;
    }
    v214 = v13 - 1;
LABEL_53:
    v48 = v211;
    v7 = v211 + 1;
    if ( v211 + 1 <= v212 )
    {
      v50 = (char *)Block;
    }
    else
    {
      v49 = v212 + (v212 >> 1);
      if ( v7 < 0x10 )
        v7 = 16i64;
      if ( v49 < v7 )
        v49 = v7;
      v50 = (char *)realloc(Block, 16 * v49);
      v48 = v211;
      v212 = v49;
      Block = v50;
      v7 = v211 + 1;
    }
    v51 = &v50[16 * v48];
    *(_QWORD *)v51 = v18;
    *((_QWORD *)v51 + 1) = v19;
    v211 = v7;
  }
  v14 = (char *)v213;
LABEL_33:
  _aligned_free(Block);
  _aligned_free(v14);
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
// Function: sub_66A10410 @ 0x66A10410
// ======================================================

_QWORD *__fastcall sub_66A10410(__int64 a1, __int64 a2, int a3, int a4, int a5, __int64 a6)
{
  size_t v10; // rbp
  _QWORD *v11; // r13
  __int64 v12; // rax
  _QWORD *v13; // rsi
  _QWORD *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rax
  __int64 v18; // rax
  char *v19; // rax
  __int64 v20; // rdx
  __int64 v22; // rax
  __int64 v23; // rax

  v10 = 8i64 * a3;
  v11 = aligned_malloc(v10, 0x40ui64);
  if ( a3 <= 0 )
  {
    v13 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v13 )
    {
      memset(v13, 0, 0x80ui64);
      *((_DWORD *)v13 + 4) = 1;
      *((_DWORD *)v13 + 5) = 14;
      *((_DWORD *)v13 + 6) = a3;
      v13[4] = aligned_malloc(v10, 0x40ui64);
      v22 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = v22 + 1;
      v13[12] = v22;
      v23 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(v23 + 8) = v13;
      *v13 = v23;
      v13[1] = a1 + 32;
      *(_QWORD *)(a1 + 32) = v13;
      *((_DWORD *)v13 + 16) = a5;
      v13[7] = aligned_malloc(v10, 0x40ui64);
      goto LABEL_11;
    }
LABEL_14:
    MEMORY[0x10] = 0;
    BUG();
  }
  v12 = 0i64;
  do
  {
    v11[v12] = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 8 * v12) + 32i64) + 8i64 * a4);
    ++v12;
  }
  while ( a3 > (int)v12 );
  v13 = aligned_malloc(0x80ui64, 0x40ui64);
  if ( !v13 )
    goto LABEL_14;
  memset(v13, 0, 0x80ui64);
  *((_DWORD *)v13 + 4) = 1;
  *((_DWORD *)v13 + 5) = 14;
  *((_DWORD *)v13 + 6) = a3;
  v14 = aligned_malloc(v10, 0x40ui64);
  v15 = 0i64;
  v13[4] = v14;
  do
  {
    while ( 1 )
    {
      v16 = v11[v15];
      if ( !v16 )
        break;
      ++*(_DWORD *)(v16 + 16);
      v14[v15++] = v16;
      if ( a3 <= (int)v15 )
        goto LABEL_8;
    }
    v14[v15++] = 0i64;
  }
  while ( a3 > (int)v15 );
LABEL_8:
  v17 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 72) = v17 + 1;
  v13[12] = v17;
  v18 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(v18 + 8) = v13;
  *v13 = v18;
  v13[1] = a1 + 32;
  *(_QWORD *)(a1 + 32) = v13;
  *((_DWORD *)v13 + 16) = a5;
  v19 = (char *)aligned_malloc(v10, 0x40ui64);
  v20 = 0i64;
  v13[7] = v19;
  while ( 1 )
  {
    *(_QWORD *)&v19[v20] = *(_QWORD *)(a6 + v20);
    if ( 8i64 * (unsigned int)(a3 - 1) == v20 )
      break;
    v19 = (char *)v13[7];
    v20 += 8i64;
  }
LABEL_11:
  _aligned_free(v11);
  return v13;
}

// ======================================================
// Function: sub_66A164C0 @ 0x66A164C0
// ======================================================

_QWORD *__fastcall sub_66A164C0(__int64 a1, int a2, int a3, __int64 a4)
{
  __int64 v4; // rdi
  int v5; // esi
  __int64 *v10; // rcx
  __int64 v11; // rdi
  int v12; // esi
  int v13; // eax
  _DWORD *v14; // rcx
  bool v15; // zf
  _QWORD *result; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx

  v4 = 0i64;
  v5 = 0;
  while ( v5 < *(_DWORD *)(a1 + 24) )
  {
    ++v5;
    v10 = *(__int64 **)(*(_QWORD *)(a1 + 32) + v4);
    v4 += 8i64;
    nc_free_node(v10);
  }
  v11 = 0i64;
  v12 = 0;
  _aligned_free(*(void **)(a1 + 32));
  v13 = *(_DWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 32) = 0i64;
  *(_DWORD *)(a1 + 24) = 0;
  if ( v13 > 0 )
  {
    do
    {
      ++v12;
      v14 = *(_DWORD **)(*(_QWORD *)(a1 + 48) + v11);
      v11 += 8i64;
      nc_free_tensor(v14);
    }
    while ( v12 < *(_DWORD *)(a1 + 40) );
  }
  _aligned_free(*(void **)(a1 + 48));
  v15 = *(_DWORD *)(a1 + 20) == 14;
  *(_QWORD *)(a1 + 48) = 0i64;
  *(_DWORD *)(a1 + 40) = 0;
  if ( v15 )
    _aligned_free(*(void **)(a1 + 56));
  free(*(void **)(a1 + 104));
  *(_DWORD *)(a1 + 24) = a3;
  *(_QWORD *)(a1 + 104) = 0i64;
  *(_DWORD *)(a1 + 20) = a2;
  result = aligned_malloc(8i64 * a3, 0x40ui64);
  *(_QWORD *)(a1 + 32) = result;
  if ( a3 > 0 )
  {
    v17 = 0i64;
    do
    {
      while ( 1 )
      {
        v18 = *(_QWORD *)(a4 + 8 * v17);
        if ( !v18 )
          break;
        ++*(_DWORD *)(v18 + 16);
        result[v17++] = v18;
        if ( a3 <= (int)v17 )
          return result;
      }
      result[v17++] = 0i64;
    }
    while ( a3 > (int)v17 );
  }
  return result;
}

// ======================================================
// Function: sub_66A23AB0 @ 0x66A23AB0
// ======================================================

_QWORD *__fastcall sub_66A23AB0(__int64 a1, int a2, int a3)
{
  size_t v6; // rbx
  __int64 *v7; // rax
  __int64 *v8; // rdi
  __int64 v9; // rsi
  __int64 v10; // rbp
  _QWORD *v11; // r15
  __int64 v12; // rbx
  __int64 *v13; // rcx
  int v14; // eax
  _QWORD *v15; // rbx

  v6 = 8i64 * a2;
  v7 = (__int64 *)aligned_malloc(v6, 0x40ui64);
  v8 = v7;
  if ( v7 )
    memset(v7, 0, v6);
  if ( a2 > 0 )
  {
    v9 = 0i64;
    v10 = (unsigned int)(a2 - 1) + 1i64;
    while ( 1 )
    {
      v12 = **(_QWORD **)(*(_QWORD *)(a1 + 8 * v9) + 48i64);
      v13 = *(__int64 **)(v12 + 32);
      v14 = *(_DWORD *)(v12 + 16) + 1;
      *(_DWORD *)(v12 + 16) = v14;
      if ( !v13 )
        break;
      if ( v14 == 1 )
      {
        nc_free_node(v13);
        *(_QWORD *)(v12 + 32) = 0i64;
        v8[v9++] = v12;
        if ( v10 == v9 )
          goto LABEL_10;
      }
      else
      {
        v11 = nc_new_tensor_nz(
                *(_QWORD *)(*(_QWORD *)(v12 + 40) + 24i64),
                *(_DWORD *)(v12 + 48),
                *(_DWORD *)(v12 + 80),
                v12 + 120);
        nc_tensor_copy((__int64)v11, v12);
        nc_free_tensor((_DWORD *)v12);
LABEL_6:
        v8[v9++] = (__int64)v11;
        if ( v10 == v9 )
          goto LABEL_10;
      }
    }
    v11 = (_QWORD *)v12;
    goto LABEL_6;
  }
LABEL_10:
  v15 = nc_concat(v8, a2, a3);
  _aligned_free(v8);
  return v15;
}

// ======================================================
// Function: sub_66A074B0 @ 0x66A074B0
// ======================================================

char *__fastcall sub_66A074B0(void **a1, __int64 a2, __int64 a3)
{
  char *v4; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rsi
  char *v10; // rax
  char *result; // rax

  v4 = (char *)a1[1];
  v7 = (unsigned __int64)a1[2];
  v8 = (unsigned __int64)(v4 + 1);
  if ( (unsigned __int64)(v4 + 1) <= v7 )
  {
    v10 = (char *)*a1;
  }
  else
  {
    v9 = v7 + (v7 >> 1);
    if ( v8 < 0x10 )
      v8 = 16i64;
    if ( v9 < v8 )
      v9 = v8;
    v10 = (char *)realloc(*a1, 16 * v9);
    v4 = (char *)a1[1];
    a1[2] = (void *)v9;
    *a1 = v10;
    v8 = (unsigned __int64)(v4 + 1);
  }
  result = &v10[16 * (_QWORD)v4];
  *(_QWORD *)result = a2;
  *((_QWORD *)result + 1) = a3;
  a1[1] = (void *)v8;
  return result;
}

