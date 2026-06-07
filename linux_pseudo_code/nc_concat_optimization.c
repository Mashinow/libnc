// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_concat_optimization
// Included functions: 3

// ======================================================
// Function: nc_concat_optimization @ 0x295C0
// ======================================================

void __fastcall nc_concat_optimization(__int64 a1, __int64 *a2, int a3)
{
  __int64 *v3; // r12
  char *v4; // rdi
  unsigned __int64 v5; // rbx
  __int64 v6; // r15
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // rax
  char *v9; // rax
  __int64 v10; // rdx
  char *v11; // rax
  __int64 v12; // r13
  char *v13; // r12
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  __int64 *v17; // r15
  __int64 v18; // rbp
  void *v19; // r8
  int v20; // r13d
  unsigned __int64 v21; // rbx
  int v22; // edx
  int v23; // r9d
  char *v24; // rbx
  __int64 v25; // rdi
  _QWORD *v26; // r10
  _QWORD *v27; // r11
  __int64 v28; // rax
  __int64 v29; // rsi
  __int64 *v30; // rbx
  __int64 v31; // rax
  char *v32; // rcx
  __int64 *v33; // rax
  void *v35; // r9
  _QWORD *v36; // r10
  int v37; // ebx
  _DWORD *v38; // r15
  __int64 *v39; // rax
  int v40; // edi
  __int64 v41; // rsi
  __int64 *v42; // r11
  __int64 *v43; // rdx
  __int64 v44; // rcx
  __int64 v45; // r13
  __int64 v46; // rdx
  unsigned __int64 v47; // rbx
  char *v48; // rax
  char *v49; // rax
  _QWORD *v50; // r12
  void *v51; // rbp
  __int64 v52; // rax
  __int64 v53; // rdx
  int v54; // ebx
  _DWORD *v55; // rdi
  __int64 v56; // r15
  __int64 v57; // rax
  int v58; // r11d
  __int64 v59; // r14
  void *v60; // rax
  void *v61; // rdi
  __int64 v62; // r15
  int v63; // ebx
  int v64; // r10d
  void *v65; // rdi
  bool v66; // zf
  __int64 v67; // r15
  __int64 v68; // rax
  __int64 i; // rbx
  __int64 v70; // rdi
  _QWORD *v71; // rbx
  unsigned int v72; // ebp
  _QWORD *v73; // r12
  _DWORD *v74; // rbx
  int v75; // eax
  _QWORD *v76; // r12
  _QWORD *v77; // rbp
  void *v78; // r15
  __int64 v79; // rax
  __int64 v80; // rdx
  void *v81; // r14
  int v82; // ebx
  void *v83; // rax
  int v84; // edi
  size_t v85; // rax
  int v86; // ebx
  int v87; // esi
  size_t v88; // rax
  _QWORD *v89; // rax
  void *v90; // rdi
  _QWORD *v91; // rax
  __int64 v92; // rbx
  __int64 v93; // rax
  void *v94; // rdi
  __int64 v95; // rdx
  __int64 v96; // rbp
  void *v97; // r12
  unsigned __int64 v98; // rbx
  char *v99; // rax
  char *v100; // rax
  __int64 v101; // rax
  __int64 v102; // rdx
  int v103; // ebx
  void *v104; // rax
  int v105; // ecx
  size_t v106; // rax
  int v107; // ebx
  int v108; // edx
  size_t v109; // rax
  int v110; // r12d
  unsigned int v111; // ebp
  void *v112; // r14
  void *v113; // rbp
  __int64 v114; // r14
  _QWORD *v115; // r15
  __int64 v116; // r8
  __int64 v117; // r14
  void *v118; // rbx
  int v119; // r15d
  int v120; // ebx
  void *v121; // rdi
  __int64 v122; // r14
  int v123; // ebx
  int v124; // r11d
  void *v125; // rdi
  _QWORD *v126; // rax
  void *v127; // rdi
  __int64 v128; // rax
  _QWORD *v129; // rbx
  __int64 v130; // rax
  void *v131; // rdi
  __int64 v132; // rbx
  __int64 v133; // rax
  _QWORD *v134; // r15
  __int64 v135; // rax
  __int64 v136; // rbx
  __int64 v137; // rdx
  void *v138; // r12
  __int64 v139; // rbx
  unsigned __int64 v140; // rbp
  char *v141; // rax
  char *v142; // rax
  _QWORD *v143; // r12
  _QWORD *v144; // rbp
  __int64 v145; // r14
  __int64 v146; // rax
  __int64 v147; // rdx
  void *v148; // r15
  int v149; // ebx
  void *v150; // rdi
  __int64 v151; // r14
  int v152; // ebx
  int v153; // eax
  void *v154; // rdi
  _QWORD *v155; // rax
  void *v156; // rdi
  __int64 v157; // rax
  _QWORD *v158; // rbx
  __int64 v159; // rax
  void *v160; // rdi
  __int64 v161; // r12
  unsigned int v162; // ebp
  _QWORD *v163; // r14
  __int64 v164; // r8
  __int64 v165; // rcx
  __int64 v166; // r12
  int v167; // ebp
  void *v168; // rbx
  void *v170; // rdi
  __int64 v171; // r12
  int v172; // ebp
  int v173; // r9d
  void *v174; // rdi
  _QWORD *v175; // rax
  void *v176; // rdi
  void *v178; // rdi
  void *v179; // rbp
  _QWORD *v180; // r12
  void *v181; // rax
  _QWORD *v182; // rsi
  __int64 v183; // rax
  void *v184; // r14
  __int64 v185; // rdx
  _QWORD *v186; // rbx
  __int64 v187; // r15
  int v188; // eax
  int v189; // r8d
  __int64 v190; // rdx
  int v191; // eax
  __int64 *v192; // rax
  __int64 v193; // rax
  __int64 *v194; // r14
  _QWORD *v195; // r14
  __int64 v196; // rdi
  __int64 v197; // r14
  __int64 v198; // rax
  _QWORD *v199; // r10
  _QWORD *v200; // rbp
  __int64 v201; // rax
  __int64 v202; // rdx
  __int64 v203; // r14
  int v204; // ebx
  void *v205; // r12
  __int64 v206; // r15
  void *v207; // rdi
  __int64 v208; // r14
  int v209; // ebx
  int v210; // eax
  void *v211; // rdi
  _QWORD *v212; // rax
  _QWORD *v213; // rbx
  __int64 v214; // r14
  unsigned int v215; // r15d
  void *v216; // r12
  void *v217; // r14
  unsigned int v218; // r12d
  __int64 v219; // r14
  __int64 v220; // rbp
  __int64 v221; // r8
  __int64 v222; // r14
  __int64 v223; // rax
  void *v224; // rdi
  int v225; // ebp
  void *v226; // rbx
  void *v227; // r12
  void *v228; // rdi
  __int64 v229; // r14
  int v230; // ebp
  int v231; // eax
  void *v232; // rdi
  _QWORD *v233; // rax
  _QWORD *v234; // rbp
  __int64 v235; // rdx
  unsigned __int64 v236; // r12
  void *v237; // rcx
  void *v238; // r15
  unsigned __int64 v239; // r14
  char *v240; // rax
  __int64 v241; // rbp
  char *v242; // rdi
  __int64 v243; // rax
  unsigned __int64 v244; // rdx
  __int64 v245; // rbp
  char *v246; // rax
  unsigned __int64 v247; // r12
  char *v248; // rax
  unsigned __int64 v249; // rax
  char *v250; // rdi
  __int64 v251; // r12
  unsigned int v252; // ebp
  _QWORD *v253; // r14
  __int64 v254; // rcx
  __int64 v255; // rbp
  void *v256; // rbx
  int v257; // ebx
  __int64 v258; // r12
  void *v259; // rdi
  __int64 v260; // rbp
  int v261; // ebx
  int v262; // eax
  void *v263; // rdi
  _QWORD *v264; // rax
  void *v265; // rdi
  int v266; // ebp
  _QWORD *v267; // r14
  __int64 v268; // rax
  size_t v269; // r10
  _QWORD *v270; // r12
  __int64 v271; // rcx
  __int64 v272; // rax
  char *v273; // rdx
  __int64 v274; // rsi
  __int64 v275; // rsi
  __int64 v276; // rax
  __int64 v277; // r15
  __int64 v278; // rdx
  int v279; // ebx
  void *v280; // rdi
  __int64 v281; // r15
  int v282; // ebx
  int v283; // eax
  void *v284; // rdi
  _QWORD *v285; // rax
  void *v286; // rdi
  __int64 v287; // rax
  __int64 v288; // rcx
  __int64 v289; // rdx
  __int64 v290; // rdi
  _QWORD *v291; // rsi
  __int64 v292; // rax
  __int64 v293; // r11
  __int64 *v294; // rax
  __int64 v295; // rdx
  __int64 v296; // rcx
  unsigned __int64 v297; // rbp
  unsigned __int64 v298; // r12
  unsigned __int64 v299; // rbx
  unsigned __int64 v300; // rax
  char *v301; // rax
  __int64 *v302; // rax
  __int64 v303; // rbp
  _QWORD *v304; // r12
  __int64 v305; // rax
  void *v306; // rbx
  __int64 *v309; // rdx
  __int64 *v310; // rax
  __int64 v311; // rdi
  __int64 v312; // rcx
  __int64 v313; // rbp
  __int64 v314; // r12
  void *v315; // rax
  __int64 *v316; // rdx
  __int64 v317; // rdi
  __int64 v318; // r11
  __int64 *v319; // rdx
  _DWORD *v320; // rcx
  _QWORD *v321; // rsi
  __int64 v322; // rcx
  int v323; // ebp
  __int64 v324; // rax
  _QWORD *v325; // r10
  __int64 v326; // r14
  __int64 v327; // r15
  _QWORD *v328; // r13
  __int64 v329; // rbx
  void *v330; // rax
  __int64 v331; // rax
  int v332; // esi
  unsigned int v333; // r12d
  __int64 *v334; // rdx
  __int64 *v335; // rax
  __int64 v336; // rcx
  __int64 v337; // rcx
  __int64 v338; // rbp
  _QWORD *v339; // r14
  __int64 v340; // rax
  __int64 v341; // rcx
  __int64 v342; // r14
  __int64 v343; // rax
  size_t v344; // r10
  __int64 v345; // r15
  void *v346; // rax
  void *v347; // rax
  __int64 v348; // rax
  __int64 v349; // rcx
  __int64 v350; // r14
  __int64 v351; // rax
  __int64 v352; // rdi
  void *v353; // rax
  __int64 v354; // rsi
  __int64 *v355; // rdx
  __int64 v356; // rcx
  __int64 v357; // rcx
  __int64 v358; // rax
  __int64 v359; // rcx
  __int64 v360; // rax
  int v361; // edx
  _QWORD *v362; // rdi
  _DWORD *v363; // rcx
  _QWORD *v364; // rcx
  _DWORD *v365; // rdx
  _QWORD *v366; // rdx
  _DWORD *v367; // rcx
  __int64 *v368; // rcx
  __int64 v369; // r8
  _QWORD *v370; // rcx
  _DWORD *v371; // rdx
  __int64 v372; // rcx
  __int64 v373; // rcx
  __int64 v374; // rsi
  __int64 *v375; // rdx
  __int64 *v376; // rax
  __int64 v377; // r8
  __int64 v378; // rcx
  __int64 v379; // rax
  __int64 v380; // rcx
  __int64 v381; // r14
  __int64 v382; // rax
  size_t v383; // r10
  __int64 v384; // r15
  void *v385; // rax
  void *v386; // rax
  __int64 v387; // rax
  __int64 v388; // r14
  __int64 v389; // rax
  void *v390; // rdi
  int v391; // r12d
  void *v392; // rbp
  _QWORD *v393; // rbx
  __int64 *v394; // r15
  void *v395; // rdi
  __int64 v396; // r14
  int v397; // r12d
  int v398; // edi
  void *v399; // rdi
  _QWORD *v400; // rax
  __int64 v401; // rdi
  _QWORD *v402; // rax
  __int64 *v403; // rbp
  __int64 v404; // rdx
  __int64 v405; // rdx
  __int64 v406; // rax
  _QWORD *v407; // r10
  void *v408; // r15
  __int64 *v409; // rcx
  __int64 *v410; // r14
  __int64 v411; // rax
  void *v412; // rax
  __int64 v413; // rax
  __int64 v414; // rax
  __int64 v415; // r8
  __int64 v416; // rcx
  __int64 v417; // r12
  int v418; // ebp
  void *v419; // rbx
  void *v421; // rdi
  __int64 v422; // r12
  int v423; // ebp
  int v424; // ecx
  void *v425; // rdi
  _QWORD *v426; // rax
  void *v427; // rdi
  __int64 v429; // rdi
  __int64 v430; // rcx
  __int64 v431; // rdx
  __int64 v432; // rax
  __int64 v433; // rdx
  __int64 v434; // r11
  __int64 *v435; // rax
  __int64 v436; // rdx
  __int64 v437; // rcx
  __int64 v438; // rsi
  __int64 *v439; // rdx
  __int64 v440; // rcx
  __int64 v441; // rcx
  __int64 v442; // rax
  __int64 v443; // r14
  __int64 v444; // rcx
  __int64 v445; // r15
  unsigned int v446; // r12d
  _QWORD *v447; // r14
  __int64 v448; // rax
  void *v449; // r12
  __int64 v450; // rax
  __int64 v451; // rax
  __int64 v452; // rsi
  __int64 v453; // rdx
  __int64 v454; // rax
  char *v455; // [rsp+0h] [rbp-E8h]
  void *v456; // [rsp+0h] [rbp-E8h]
  void *v457; // [rsp+0h] [rbp-E8h]
  void *v458; // [rsp+0h] [rbp-E8h]
  _QWORD *v459; // [rsp+0h] [rbp-E8h]
  unsigned int v460; // [rsp+0h] [rbp-E8h]
  _QWORD *v461; // [rsp+0h] [rbp-E8h]
  _QWORD *v462; // [rsp+0h] [rbp-E8h]
  void *v463; // [rsp+0h] [rbp-E8h]
  int v464; // [rsp+0h] [rbp-E8h]
  void *v465; // [rsp+0h] [rbp-E8h]
  _QWORD *v466; // [rsp+0h] [rbp-E8h]
  _QWORD *v467; // [rsp+0h] [rbp-E8h]
  _QWORD *v468; // [rsp+0h] [rbp-E8h]
  _DWORD *v469; // [rsp+0h] [rbp-E8h]
  _QWORD *v470; // [rsp+0h] [rbp-E8h]
  _QWORD *v471; // [rsp+0h] [rbp-E8h]
  _QWORD *v472; // [rsp+0h] [rbp-E8h]
  _QWORD *v473; // [rsp+0h] [rbp-E8h]
  unsigned int v474; // [rsp+0h] [rbp-E8h]
  _QWORD *v475; // [rsp+0h] [rbp-E8h]
  _QWORD *v476; // [rsp+0h] [rbp-E8h]
  _QWORD *v477; // [rsp+0h] [rbp-E8h]
  size_t sizeb; // [rsp+8h] [rbp-E0h]
  size_t sizec; // [rsp+8h] [rbp-E0h]
  size_t sized; // [rsp+8h] [rbp-E0h]
  size_t sizee; // [rsp+8h] [rbp-E0h]
  size_t sizef; // [rsp+8h] [rbp-E0h]
  size_t sizeg; // [rsp+8h] [rbp-E0h]
  int size; // [rsp+8h] [rbp-E0h]
  __int64 *sizeh; // [rsp+8h] [rbp-E0h]
  size_t sizei; // [rsp+8h] [rbp-E0h]
  size_t sizej; // [rsp+8h] [rbp-E0h]
  size_t sizek; // [rsp+8h] [rbp-E0h]
  size_t sizel; // [rsp+8h] [rbp-E0h]
  size_t sizem; // [rsp+8h] [rbp-E0h]
  size_t sizen; // [rsp+8h] [rbp-E0h]
  size_t sizeo; // [rsp+8h] [rbp-E0h]
  size_t sizea; // [rsp+8h] [rbp-E0h]
  __int64 v495; // [rsp+30h] [rbp-B8h]
  __int64 v496; // [rsp+30h] [rbp-B8h]
  _QWORD *v497; // [rsp+30h] [rbp-B8h]
  _QWORD *v498; // [rsp+30h] [rbp-B8h]
  int v499; // [rsp+38h] [rbp-B0h]
  int v500; // [rsp+38h] [rbp-B0h]
  __int64 *v501; // [rsp+38h] [rbp-B0h]
  void *v502; // [rsp+48h] [rbp-A0h] BYREF
  void *ptr; // [rsp+50h] [rbp-98h] BYREF
  unsigned __int64 v504; // [rsp+58h] [rbp-90h]
  unsigned __int64 v505; // [rsp+60h] [rbp-88h]
  void *v506; // [rsp+70h] [rbp-78h]
  unsigned __int64 v507; // [rsp+78h] [rbp-70h]
  unsigned __int64 v508; // [rsp+80h] [rbp-68h]
  void *v509; // [rsp+90h] [rbp-58h] BYREF
  void *v510; // [rsp+98h] [rbp-50h]
  __int64 v511; // [rsp+A0h] [rbp-48h]
  __int64 v512; // [rsp+A8h] [rbp-40h]

  ptr = 0LL;
  v504 = 0LL;
  v505 = 0LL;
  v506 = 0LL;
  v507 = 0LL;
  v508 = 0LL;
  if ( a3 <= 0 )
  {
    v7 = 0LL;
  }
  else
  {
    v3 = a2;
    v4 = 0LL;
    v5 = 0LL;
    v6 = (__int64)&a2[(unsigned int)(a3 - 1) + 1];
    v7 = 0LL;
    do
    {
      v8 = v7 + 1;
      v12 = *v3;
      if ( v7 + 1 > v5 )
      {
        v5 += v5 >> 1;
        if ( v8 < 0x10 )
          v8 = 16LL;
        if ( v5 < v8 )
          v5 = v8;
        v9 = (char *)realloc(v4, 16 * v5);
        v10 = v504;
        v505 = v5;
        ptr = v9;
        v4 = v9;
        v7 = v504 + 1;
      }
      else
      {
        v10 = v7++;
      }
      ++v3;
      v11 = &v4[16 * v10];
      *(_QWORD *)v11 = v12;
      *((_QWORD *)v11 + 1) = 0LL;
      v504 = v7;
    }
    while ( (__int64 *)v6 != v3 );
  }
  while ( 1 )
  {
LABEL_12:
    if ( v7 )
    {
      v504 = --v7;
      v33 = (__int64 *)((char *)ptr + 16 * v7);
      _R13 = *v33;
      v35 = (void *)v33[1];
      if ( *(_DWORD *)(*v33 + 20) != 14 )
        __assert_fail("concat_node->opcode == OP_concat", "libnc.c", 0x1F0Du, "nc_concat_optimization1");
      v36 = *(_QWORD **)(_R13 + 32);
      v37 = *(_DWORD *)(_R13 + 24);
      v38 = (_DWORD *)*v36;
      if ( v37 > 0 )
      {
        if ( !v38 )
          continue;
        v39 = v36 + 1;
        v40 = v38[5];
        v41 = (unsigned int)(v37 - 1);
        v42 = v36 + 1;
        v43 = v36 + 1;
        while ( &v36[v41 + 1] != v43 )
        {
          v44 = *v43;
          if ( *v43 )
          {
            ++v43;
            if ( *(_DWORD *)(v44 + 20) == v40 )
              continue;
          }
          goto LABEL_12;
        }
        switch ( v40 )
        {
          case 2:
            while ( v39 != v43 )
            {
              v452 = *v39++;
              if ( *(_DWORD *)(v452 + 56) != v38[14] )
                goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v42 != v39 )
            {
              v453 = *v42++;
              if ( *(_DWORD *)(v453 + 16) != 1 )
                goto LABEL_246;
            }
            v251 = *(_QWORD *)(_R13 + 56);
            v252 = *(_DWORD *)(_R13 + 64);
            v477 = *(_QWORD **)(_R13 + 32);
            v253 = (_QWORD *)nc_malloc(8LL * v37);
            v454 = 0LL;
            do
            {
              v253[v454] = **(_QWORD **)(v477[v454] + 32LL);
              ++v454;
            }
            while ( v37 > (int)v454 );
LABEL_202:
            v254 = v252;
            v255 = 0LL;
            v256 = (void *)nc_concat_node(a1, v253, (unsigned int)v37, v254, v251);
            nc_free(v253);
            v502 = v256;
            v257 = 0;
            v258 = nc_dup_node(v38);
            while ( v257 < *(_DWORD *)(_R13 + 24) )
            {
              ++v257;
              v259 = *(void **)(*(_QWORD *)(_R13 + 32) + v255);
              v255 += 8LL;
              nc_free_node(v259);
            }
            v260 = 0LL;
            v261 = 0;
            nc_free(*(void **)(_R13 + 32));
            v262 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v262 > 0 )
            {
              do
              {
                ++v261;
                v263 = *(void **)(*(_QWORD *)(_R13 + 48) + v260);
                v260 += 8LL;
                nc_free_tensor(v263);
              }
              while ( v261 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 2;
            *(_DWORD *)(_R13 + 24) = 1;
            v264 = (_QWORD *)nc_malloc(8uLL);
            v265 = v502;
            *(_QWORD *)(_R13 + 32) = v264;
            if ( v265 )
              *v264 = nc_dup_node(v265);
            else
              *v264 = 0LL;
            v178 = (void *)v258;
            *(_DWORD *)(_R13 + 56) = *(_DWORD *)(v258 + 56);
            goto LABEL_140;
          case 3:
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v39 != &v36[v41 + 1] )
            {
              v359 = *v39++;
              if ( *(_DWORD *)(v359 + 16) != 1 )
                goto LABEL_246;
            }
            v266 = v38[14] - 1;
            v464 = v38[14];
            if ( v266 > 0 )
            {
LABEL_212:
              v509 = (void *)*((_QWORD *)v38 + 8);
              if ( v266 != 1 )
              {
                v510 = (void *)*((_QWORD *)v38 + 9);
                if ( v266 != 2 )
                {
                  v511 = *((_QWORD *)v38 + 10);
                  if ( v266 != 3 )
                    v512 = *((_QWORD *)v38 + 11);
                }
              }
              sizei = (size_t)v36;
              v267 = (_QWORD *)nc_malloc(8LL * v37);
              v268 = nc_malloc(8LL * v37);
              v269 = sizei;
              v270 = (_QWORD *)v268;
              if ( v37 <= 0 )
              {
                v273 = 0LL;
                v271 = v266;
                goto LABEL_221;
              }
            }
            else
            {
              sizem = *(_QWORD *)(_R13 + 32);
              v267 = (_QWORD *)nc_malloc(8LL * v37);
              v360 = nc_malloc(8LL * v37);
              v269 = sizem;
              v270 = (_QWORD *)v360;
            }
            v271 = v266;
            v272 = 0LL;
            v273 = 0LL;
            do
            {
              v274 = *(_QWORD *)(v269 + 8 * v272);
              v267[v272] = **(_QWORD **)(v274 + 32);
              v275 = *(_QWORD *)(v274 + 8 * (v266 + 4LL) + 32);
              v270[v272++] = v275;
              v273 += v275;
            }
            while ( v37 > (int)v272 );
LABEL_221:
            v277 = 0LL;
            *(&v509 + v271) = v273;
            v278 = (unsigned int)v37;
            v279 = 0;
            v502 = (void *)nc_concat_node(a1, v267, v278, (unsigned int)v266, v270);
            while ( v279 < *(_DWORD *)(_R13 + 24) )
            {
              ++v279;
              v280 = *(void **)(*(_QWORD *)(_R13 + 32) + v277);
              v277 += 8LL;
              nc_free_node(v280);
            }
            v281 = 0LL;
            v282 = 0;
            nc_free(*(void **)(_R13 + 32));
            v283 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v283 > 0 )
            {
              do
              {
                ++v282;
                v284 = *(void **)(*(_QWORD *)(_R13 + 48) + v281);
                v281 += 8LL;
                nc_free_tensor(v284);
              }
              while ( v282 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 3;
            *(_DWORD *)(_R13 + 24) = 1;
            v285 = (_QWORD *)nc_malloc(8uLL);
            v286 = v502;
            *(_QWORD *)(_R13 + 32) = v285;
            if ( v286 )
              *v285 = nc_dup_node(v286);
            else
              *v285 = 0LL;
            *(_DWORD *)(_R13 + 56) = v464;
            if ( v266 >= 0 )
            {
              *(_QWORD *)(_R13 + 64) = v509;
              if ( v266 )
              {
                *(_QWORD *)(_R13 + 72) = v510;
                if ( v266 != 1 )
                {
                  *(_QWORD *)(_R13 + 80) = v511;
                  if ( v266 != 2 )
                    *(_QWORD *)(_R13 + 88) = v512;
                }
              }
            }
            nc_free_node(v502);
            nc_free(v270);
            nc_free(v267);
            goto LABEL_83;
          case 6:
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( &v36[v41 + 1] != v39 )
            {
              v444 = *v39++;
              if ( *(_DWORD *)(v444 + 16) != 1 )
                goto LABEL_246;
            }
            v445 = *(_QWORD *)(_R13 + 56);
            v446 = *(_DWORD *)(_R13 + 64);
            v475 = *(_QWORD **)(_R13 + 32);
            v447 = (_QWORD *)nc_malloc(8LL * v37);
            v448 = 0LL;
            do
            {
              v447[v448] = **(_QWORD **)(v475[v448] + 32LL);
              ++v448;
            }
            while ( v37 > (int)v448 );
            v449 = (void *)nc_concat_node(a1, v447, (unsigned int)v37, v446, v445);
            nc_free(v447);
            v502 = v449;
            v219 = *(_QWORD *)(_R13 + 56);
            v218 = *(_DWORD *)(_R13 + 64);
            v220 = nc_malloc(8LL * v37);
            v450 = 0LL;
            do
            {
              *(_QWORD *)(v220 + 8 * v450) = *(_QWORD *)(*(_QWORD *)(v475[v450] + 32LL) + 8LL);
              ++v450;
            }
            while ( v37 > (int)v450 );
LABEL_178:
            v221 = v219;
            v222 = 0LL;
            v223 = nc_concat_node(a1, v220, (unsigned int)v37, v218, v221);
            v224 = (void *)v220;
            v225 = 0;
            v226 = (void *)v223;
            nc_free(v224);
            v227 = v502;
            if ( *(int *)(_R13 + 24) > 0 )
            {
              do
              {
                ++v225;
                v228 = *(void **)(*(_QWORD *)(_R13 + 32) + v222);
                v222 += 8LL;
                nc_free_node(v228);
              }
              while ( v225 < *(_DWORD *)(_R13 + 24) );
            }
            v229 = 0LL;
            v230 = 0;
            nc_free(*(void **)(_R13 + 32));
            v231 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v231 > 0 )
            {
              do
              {
                ++v230;
                v232 = *(void **)(*(_QWORD *)(_R13 + 48) + v229);
                v229 += 8LL;
                nc_free_tensor(v232);
              }
              while ( v230 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 6;
            *(_DWORD *)(_R13 + 24) = 2;
            v233 = (_QWORD *)nc_malloc(0x10uLL);
            v234 = v233;
            *(_QWORD *)(_R13 + 32) = v233;
            if ( v227 )
            {
              *v233 = nc_dup_node(v227);
              v234 = *(_QWORD **)(_R13 + 32);
            }
            else
            {
              *v233 = 0LL;
            }
            if ( v226 )
              v234[1] = nc_dup_node(v226);
            else
              v234[1] = 0LL;
            nc_free_node(v502);
            nc_free_node(v226);
            v235 = v504;
            v236 = v505;
            v237 = *(void **)(_R13 + 32);
            v238 = v502;
            v239 = v504 + 1;
            if ( v504 + 1 <= v505 )
            {
              v242 = (char *)ptr;
              v241 = *(_QWORD *)(_R13 + 32);
            }
            else
            {
              v463 = *(void **)(_R13 + 32);
              if ( v239 < 0x10 )
                v239 = 16LL;
              if ( v505 + (v505 >> 1) >= v239 )
                v239 = v505 + (v505 >> 1);
              v236 = v239;
              v240 = (char *)realloc(ptr, 16 * v239);
              v235 = v504;
              v241 = *(_QWORD *)(_R13 + 32);
              v505 = v239;
              ptr = v240;
              v237 = v463;
              v242 = v240;
              v239 = v504 + 1;
            }
            v243 = v235;
            v244 = v235 + 2;
            v245 = v241 + 8;
            v246 = &v242[16 * v243];
            *(_QWORD *)v246 = v238;
            *((_QWORD *)v246 + 1) = v237;
            v504 = v239;
            if ( v244 > v236 )
            {
              v247 = (v236 >> 1) + v236;
              if ( v244 < 0x10 )
                v244 = 16LL;
              if ( v247 < v244 )
                v247 = v244;
              v248 = (char *)realloc(v242, 16 * v247);
              v505 = v247;
              v239 = v504;
              ptr = v248;
              v242 = v248;
            }
            v249 = v239;
            v7 = v239 + 1;
            v250 = &v242[16 * v249];
            *(_QWORD *)v250 = v226;
            *((_QWORD *)v250 + 1) = v245;
            v504 = v7;
            continue;
          case 7:
            if ( v37 <= 1 )
              goto LABEL_161;
            v373 = v36[1];
            v374 = *(_QWORD *)(*(_QWORD *)(v373 + 32) + 8LL);
            if ( v374 != *(_QWORD *)(*((_QWORD *)v38 + 4) + 8LL) )
              continue;
            v375 = v36 + 2;
            v376 = v36 + 2;
            while ( &v36[(unsigned int)(v37 - 2) + 2] != v376 )
            {
              v377 = *v376++;
              if ( *(_QWORD *)(*(_QWORD *)(v377 + 32) + 8LL) != v374 )
                goto LABEL_12;
            }
            if ( *(_DWORD *)(v373 + 16) != 1 )
              goto LABEL_246;
            if ( v376 == v375 )
            {
LABEL_387:
              v473 = *(_QWORD **)(_R13 + 32);
              v379 = nc_malloc(8LL * v37);
              v199 = v473;
              v200 = (_QWORD *)v379;
LABEL_162:
              v201 = 0LL;
              do
              {
                v200[v201] = **(_QWORD **)(v199[v201] + 32LL);
                ++v201;
              }
              while ( v37 > (int)v201 );
LABEL_164:
              v202 = (unsigned int)v37;
              v203 = 0LL;
              v204 = 0;
              v205 = (void *)nc_concat_node(a1, v200, v202, *(unsigned int *)(_R13 + 64), *(_QWORD *)(_R13 + 56));
              v502 = v205;
              v206 = *(_QWORD *)(*((_QWORD *)v38 + 4) + 8LL);
              while ( v204 < *(_DWORD *)(_R13 + 24) )
              {
                ++v204;
                v207 = *(void **)(*(_QWORD *)(_R13 + 32) + v203);
                v203 += 8LL;
                nc_free_node(v207);
              }
              v208 = 0LL;
              v209 = 0;
              nc_free(*(void **)(_R13 + 32));
              v210 = *(_DWORD *)(_R13 + 40);
              *(_QWORD *)(_R13 + 32) = 0LL;
              *(_DWORD *)(_R13 + 24) = 0;
              if ( v210 > 0 )
              {
                do
                {
                  ++v209;
                  v211 = *(void **)(*(_QWORD *)(_R13 + 48) + v208);
                  v208 += 8LL;
                  nc_free_tensor(v211);
                }
                while ( v209 < *(_DWORD *)(_R13 + 40) );
              }
              nc_free(*(void **)(_R13 + 48));
              v66 = *(_DWORD *)(_R13 + 20) == 14;
              *(_QWORD *)(_R13 + 48) = 0LL;
              *(_DWORD *)(_R13 + 40) = 0;
              if ( v66 )
                nc_free(*(void **)(_R13 + 56));
              free(*(void **)(_R13 + 104));
              *(_QWORD *)(_R13 + 104) = 0LL;
              *(_DWORD *)(_R13 + 20) = 7;
              *(_DWORD *)(_R13 + 24) = 2;
              v212 = (_QWORD *)nc_malloc(0x10uLL);
              v213 = v212;
              *(_QWORD *)(_R13 + 32) = v212;
              if ( v205 )
              {
                *v212 = nc_dup_node(v205);
                v213 = *(_QWORD **)(_R13 + 32);
              }
              else
              {
                *v212 = 0LL;
              }
              if ( v206 )
                v213[1] = nc_dup_node(v206);
              else
                v213[1] = 0LL;
              nc_free_node(v502);
              nc_free(v200);
              goto LABEL_83;
            }
            while ( 1 )
            {
              v378 = *v375++;
              if ( *(_DWORD *)(v378 + 16) != 1 )
                goto LABEL_246;
              if ( v376 == v375 )
                goto LABEL_387;
            }
          case 10:
          case 11:
            v438 = (__int64)&v36[v41 + 1];
            v179 = (void *)**((_QWORD **)v38 + 6);
            v439 = v36 + 1;
            while ( (__int64 *)v438 != v439 )
            {
              v440 = *v439;
              if ( *(_QWORD *)(*(_QWORD *)(*v439 + 32) + 8LL) == *(_QWORD *)(*((_QWORD *)v38 + 4) + 8LL) )
              {
                ++v439;
                if ( (**(_QWORD **)(v440 + 48) != 0LL) == (v179 != 0LL) )
                  continue;
              }
              goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v439 != v39 )
            {
              v441 = *v39++;
              if ( *(_DWORD *)(v441 + 16) != 1 )
                goto LABEL_246;
            }
            sizea = *(_QWORD *)(_R13 + 32);
            v461 = (_QWORD *)nc_malloc(8LL * v37);
            v182 = v461;
            v180 = (_QWORD *)nc_mallocz(8LL * v37);
            v442 = 0LL;
            do
            {
              v461[v442] = **(_QWORD **)(*(_QWORD *)(sizea + 8 * v442) + 32LL);
              ++v442;
            }
            while ( v37 > (int)v442 );
            v443 = 0LL;
            if ( v179 )
            {
              do
              {
                v180[v443] = nc_dup_tensor(**(_QWORD **)(*(_QWORD *)(sizea + 8 * v443) + 48LL));
                ++v443;
              }
              while ( v37 > (int)v443 );
LABEL_144:
              v181 = (void *)nc_hconcat(v180, (unsigned int)v37);
              v179 = (void *)nc_stop_grad(v181);
LABEL_145:
              v182 = v461;
            }
            v502 = (void *)nc_concat_node(
                             a1,
                             v182,
                             (unsigned int)v37,
                             *(unsigned int *)(_R13 + 64),
                             *(_QWORD *)(_R13 + 56));
            v183 = nc_dup_node(v38);
            v184 = v502;
            v185 = 0LL;
            v186 = (_QWORD *)v183;
            v187 = *(_QWORD *)(*(_QWORD *)(v183 + 32) + 8LL);
            size = *(_DWORD *)(v183 + 20);
            v188 = 0;
            if ( *(int *)(_R13 + 24) > 0 )
            {
              do
              {
                v499 = v188;
                v495 = v185;
                nc_free_node(*(void **)(*(_QWORD *)(_R13 + 32) + v185));
                v188 = v499 + 1;
                v185 = v495 + 8;
              }
              while ( v499 + 1 < *(_DWORD *)(_R13 + 24) );
            }
            nc_free(*(void **)(_R13 + 32));
            v189 = *(_DWORD *)(_R13 + 40);
            v190 = 0LL;
            v191 = 0;
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v189 > 0 )
            {
              do
              {
                v500 = v191;
                v496 = v190;
                nc_free_tensor(*(void **)(*(_QWORD *)(_R13 + 48) + v190));
                v191 = v500 + 1;
                v190 = v496 + 8;
              }
              while ( v500 + 1 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 24) = 2;
            *(_DWORD *)(_R13 + 20) = size;
            v192 = (__int64 *)nc_malloc(0x10uLL);
            *(_QWORD *)(_R13 + 32) = v192;
            if ( v184 )
            {
              sizeh = v192;
              v193 = nc_dup_node(v184);
              v194 = *(__int64 **)(_R13 + 32);
              *sizeh = v193;
            }
            else
            {
              *v192 = 0LL;
              v194 = v192;
            }
            if ( v187 )
              v194[1] = nc_dup_node(v187);
            else
              v194[1] = 0LL;
            *(_DWORD *)(_R13 + 40) = 2;
            v195 = (_QWORD *)nc_mallocz(0x10uLL);
            *(_QWORD *)(_R13 + 48) = v195;
            if ( v179 )
              *v195 = nc_dup_tensor(v179);
            v196 = *(_QWORD *)(v186[6] + 8LL);
            if ( v196 )
            {
              v197 = *(_QWORD *)(_R13 + 48);
              *(_QWORD *)(v197 + 8) = nc_dup_tensor(v196);
            }
            nc_free_node(v186);
            nc_free_node(v502);
            nc_free_tensor(v179);
            nc_free(v461);
            nc_free(v180);
            goto LABEL_83;
          case 15:
            goto LABEL_293;
          case 17:
            v354 = (__int64)&v36[v41 + 1];
            v355 = v36 + 1;
            while ( (__int64 *)v354 != v355 )
            {
              v356 = *v355;
              if ( *(_QWORD *)(*v355 + 56) == *((_QWORD *)v38 + 7) && *(_QWORD *)(v356 + 64) == *((_QWORD *)v38 + 8) )
              {
                ++v355;
                if ( *(_QWORD *)(v356 + 72) == *((_QWORD *)v38 + 9) )
                  continue;
              }
              goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v355 != v39 )
            {
              v357 = *v39++;
              if ( *(_DWORD *)(v357 + 16) != 1 )
                goto LABEL_246;
            }
            v161 = *(_QWORD *)(_R13 + 56);
            v162 = *(_DWORD *)(_R13 + 64);
            v472 = *(_QWORD **)(_R13 + 32);
            v163 = (_QWORD *)nc_malloc(8LL * v37);
            v358 = 0LL;
            do
            {
              v163[v358] = **(_QWORD **)(v472[v358] + 32LL);
              ++v358;
            }
            while ( v37 > (int)v358 );
LABEL_131:
            v164 = v161;
            v165 = v162;
            v166 = 0LL;
            v167 = 0;
            v168 = (void *)nc_concat_node(a1, v163, (unsigned int)v37, v165, v164);
            nc_free(v163);
            v502 = v168;
            _RBX = nc_dup_node(v38);
            if ( *(int *)(_R13 + 24) > 0 )
            {
              do
              {
                ++v167;
                v170 = *(void **)(*(_QWORD *)(_R13 + 32) + v166);
                v166 += 8LL;
                nc_free_node(v170);
              }
              while ( v167 < *(_DWORD *)(_R13 + 24) );
            }
            v171 = 0LL;
            v172 = 0;
            nc_free(*(void **)(_R13 + 32));
            v173 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v173 > 0 )
            {
              do
              {
                ++v172;
                v174 = *(void **)(*(_QWORD *)(_R13 + 48) + v171);
                v171 += 8LL;
                nc_free_tensor(v174);
              }
              while ( v172 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 17;
            *(_DWORD *)(_R13 + 24) = 1;
            v175 = (_QWORD *)nc_malloc(8uLL);
            v176 = v502;
            *(_QWORD *)(_R13 + 32) = v175;
            if ( v176 )
              *v175 = nc_dup_node(v176);
            else
              *v175 = 0LL;
            __asm { vmovdqu xmm0, xmmword ptr [rbx+38h] }
            v178 = (void *)_RBX;
            __asm { vmovups xmmword ptr [r13+38h], xmm0 }
            *(_DWORD *)(_R13 + 72) = *(_DWORD *)(_RBX + 72);
            *(_DWORD *)(_R13 + 76) = *(_DWORD *)(_RBX + 76);
            goto LABEL_140;
          case 18:
            if ( v38[4] != 2 )
              goto LABEL_246;
            while ( &v36[v41 + 1] != v39 )
            {
              v349 = *v39++;
              if ( *(_DWORD *)(v349 + 16) != 2 )
                goto LABEL_246;
            }
            v471 = *(_QWORD **)(_R13 + 32);
            v350 = 0LL;
            v143 = (_QWORD *)nc_malloc(8LL * v37);
            v144 = (_QWORD *)nc_malloc(8LL * v37);
            do
            {
              v351 = v471[v350];
              v352 = **(_QWORD **)(v351 + 48);
              v143[v350] = **(_QWORD **)(v351 + 32);
              v353 = (void *)nc_dup_tensor(v352);
              v144[v350++] = nc_stop_grad(v353);
            }
            while ( v37 > (int)v350 );
LABEL_121:
            v145 = 0LL;
            v146 = nc_concat(v144, (unsigned int)v37, *(unsigned int *)(_R13 + 64));
            v147 = (unsigned int)v37;
            v148 = (void *)v146;
            v149 = 0;
            v502 = (void *)nc_concat_node(a1, v143, v147, *(unsigned int *)(_R13 + 64), *(_QWORD *)(_R13 + 56));
            while ( v149 < *(_DWORD *)(_R13 + 24) )
            {
              ++v149;
              v150 = *(void **)(*(_QWORD *)(_R13 + 32) + v145);
              v145 += 8LL;
              nc_free_node(v150);
            }
            v151 = 0LL;
            v152 = 0;
            nc_free(*(void **)(_R13 + 32));
            v153 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v153 > 0 )
            {
              do
              {
                ++v152;
                v154 = *(void **)(*(_QWORD *)(_R13 + 48) + v151);
                v151 += 8LL;
                nc_free_tensor(v154);
              }
              while ( v152 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 18;
            *(_DWORD *)(_R13 + 24) = 1;
            v155 = (_QWORD *)nc_malloc(8uLL);
            v156 = v502;
            *(_QWORD *)(_R13 + 32) = v155;
            if ( v156 )
              *v155 = nc_dup_node(v156);
            else
              *v155 = 0LL;
            *(_DWORD *)(_R13 + 40) = 1;
            v157 = nc_malloc(8uLL);
            *(_QWORD *)(_R13 + 48) = v157;
            v158 = (_QWORD *)v157;
            v159 = nc_dup_tensor(v148);
            v160 = v502;
            *v158 = v159;
            nc_free_node(v160);
            nc_free_tensor(v148);
            nc_free(v144);
            nc_free(v143);
            goto LABEL_83;
          case 23:
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( &v36[v41 + 1] != v39 )
            {
              v380 = *v39++;
              if ( *(_DWORD *)(v380 + 16) != 1 )
                goto LABEL_246;
            }
            sizen = *(_QWORD *)(_R13 + 32);
            v381 = 0LL;
            v459 = (_QWORD *)nc_malloc(8LL * v37);
            v76 = (_QWORD *)nc_malloc(8LL * v37);
            v382 = nc_malloc(8LL * v37);
            v383 = sizen;
            v77 = (_QWORD *)v382;
            do
            {
              v384 = *(_QWORD *)(v383 + 8 * v381);
              sizeo = v383;
              v459[v381] = **(_QWORD **)(v384 + 32);
              v385 = (void *)nc_dup_tensor(**(_QWORD **)(v384 + 48));
              v76[v381] = nc_stop_grad(v385);
              v386 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v384 + 48) + 8LL));
              v387 = nc_stop_grad(v386);
              v383 = sizeo;
              v77[v381++] = v387;
            }
            while ( v37 > (int)v381 );
LABEL_91:
            v78 = (void *)nc_concat(v76, (unsigned int)v37, *(unsigned int *)(_R13 + 64));
            v101 = nc_concat(v77, (unsigned int)v37, *(unsigned int *)(_R13 + 64));
            v102 = (unsigned int)v37;
            v81 = (void *)v101;
            v103 = 0;
            v104 = (void *)nc_concat_node(a1, v459, v102, *(unsigned int *)(_R13 + 64), *(_QWORD *)(_R13 + 56));
            v105 = *(_DWORD *)(_R13 + 24);
            v502 = v104;
            v106 = 0LL;
            if ( v105 > 0 )
            {
              do
              {
                sizef = v106;
                ++v103;
                nc_free_node(*(void **)(*(_QWORD *)(_R13 + 32) + v106));
                v106 = sizef + 8;
              }
              while ( v103 < *(_DWORD *)(_R13 + 24) );
            }
            v107 = 0;
            nc_free(*(void **)(_R13 + 32));
            v108 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            v109 = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v108 > 0 )
            {
              do
              {
                sizeg = v109;
                ++v107;
                nc_free_tensor(*(void **)(*(_QWORD *)(_R13 + 48) + v109));
                v109 = sizeg + 8;
              }
              while ( v107 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 23;
            goto LABEL_80;
          case 24:
            if ( v38[4] != 2 )
              goto LABEL_246;
            while ( &v36[v41 + 1] != v39 )
            {
              v341 = *v39++;
              if ( *(_DWORD *)(v341 + 16) != 2 )
                goto LABEL_246;
            }
            sizek = *(_QWORD *)(_R13 + 32);
            v342 = 0LL;
            v459 = (_QWORD *)nc_malloc(8LL * v37);
            v76 = (_QWORD *)nc_malloc(8LL * v37);
            v343 = nc_malloc(8LL * v37);
            v344 = sizek;
            v77 = (_QWORD *)v343;
            do
            {
              v345 = *(_QWORD *)(v344 + 8 * v342);
              sizel = v344;
              v459[v342] = **(_QWORD **)(v345 + 32);
              v346 = (void *)nc_dup_tensor(**(_QWORD **)(v345 + 48));
              v76[v342] = nc_stop_grad(v346);
              v347 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v345 + 48) + 8LL));
              v348 = nc_stop_grad(v347);
              v344 = sizel;
              v77[v342++] = v348;
            }
            while ( v37 > (int)v342 );
LABEL_73:
            v78 = (void *)nc_concat(v76, (unsigned int)v37, *(unsigned int *)(_R13 + 64));
            v79 = nc_concat(v77, (unsigned int)v37, (unsigned int)(*(_DWORD *)(_R13 + 64) - 1));
            v80 = (unsigned int)v37;
            v81 = (void *)v79;
            v82 = 0;
            v83 = (void *)nc_concat_node(a1, v459, v80, *(unsigned int *)(_R13 + 64), *(_QWORD *)(_R13 + 56));
            v84 = *(_DWORD *)(_R13 + 24);
            v502 = v83;
            v85 = 0LL;
            if ( v84 > 0 )
            {
              do
              {
                sized = v85;
                ++v82;
                nc_free_node(*(void **)(*(_QWORD *)(_R13 + 32) + v85));
                v85 = sized + 8;
              }
              while ( v82 < *(_DWORD *)(_R13 + 24) );
            }
            v86 = 0;
            nc_free(*(void **)(_R13 + 32));
            v87 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            v88 = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v87 > 0 )
            {
              do
              {
                sizee = v88;
                ++v86;
                nc_free_tensor(*(void **)(*(_QWORD *)(_R13 + 48) + v88));
                v88 = sizee + 8;
              }
              while ( v86 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 24;
LABEL_80:
            *(_DWORD *)(_R13 + 24) = 1;
            v89 = (_QWORD *)nc_malloc(8uLL);
            v90 = v502;
            *(_QWORD *)(_R13 + 32) = v89;
            if ( v90 )
              *v89 = nc_dup_node(v90);
            else
              *v89 = 0LL;
            *(_DWORD *)(_R13 + 40) = 2;
            v91 = (_QWORD *)nc_malloc(0x10uLL);
            *(_QWORD *)(_R13 + 48) = v91;
            *v91 = nc_dup_tensor(v78);
            v92 = *(_QWORD *)(_R13 + 48);
            v93 = nc_dup_tensor(v81);
            v94 = v502;
            *(_QWORD *)(v92 + 8) = v93;
            nc_free_node(v94);
            nc_free_tensor(v78);
            nc_free_tensor(v81);
            nc_free(v76);
            nc_free(v77);
            nc_free(v459);
            goto LABEL_83;
          case 28:
            v110 = v38[14];
            v403 = v36 + 1;
            while ( &v36[v41 + 1] != v39 )
            {
              v404 = *v39++;
              if ( *(_DWORD *)(v404 + 56) != v110 )
                goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v39 != v403 )
            {
              v405 = *v403++;
              if ( *(_DWORD *)(v405 + 16) != 1 )
                goto LABEL_246;
            }
            v497 = *(_QWORD **)(_R13 + 32);
            v474 = *(_DWORD *)(_R13 + 64);
            v406 = nc_mallocz(8LL * v37);
            v407 = v497;
            v408 = (void *)v406;
            v409 = (__int64 *)v406;
            v410 = v497;
            do
            {
              v411 = *v410;
              v501 = v409;
              ++v410;
              v498 = v407;
              v412 = (void *)nc_dup_tensor(**(_QWORD **)(v411 + 48));
              v413 = nc_stop_grad(v412);
              v407 = v498;
              *v501 = v413;
              v409 = v501 + 1;
            }
            while ( v403 != v410 );
            v113 = (void *)nc_concat(v408, (unsigned int)v37, v474);
            nc_free(v408);
            v114 = *(_QWORD *)(_R13 + 56);
            v460 = *(_DWORD *)(_R13 + 64);
            v115 = (_QWORD *)nc_malloc(8LL * v37);
            v414 = 0LL;
            do
            {
              v115[v414] = **(_QWORD **)(v498[v414] + 32LL);
              ++v414;
            }
            while ( v37 > (int)v414 );
LABEL_101:
            v116 = v114;
            v117 = 0LL;
            v118 = (void *)nc_concat_node(a1, v115, (unsigned int)v37, v460, v116);
            nc_free(v115);
            v119 = *(_DWORD *)(_R13 + 24);
            v502 = v118;
            v120 = 0;
            if ( v119 > 0 )
            {
              do
              {
                ++v120;
                v121 = *(void **)(*(_QWORD *)(_R13 + 32) + v117);
                v117 += 8LL;
                nc_free_node(v121);
              }
              while ( v120 < *(_DWORD *)(_R13 + 24) );
            }
            v122 = 0LL;
            v123 = 0;
            nc_free(*(void **)(_R13 + 32));
            v124 = *(_DWORD *)(_R13 + 40);
            *(_QWORD *)(_R13 + 32) = 0LL;
            *(_DWORD *)(_R13 + 24) = 0;
            if ( v124 > 0 )
            {
              do
              {
                ++v123;
                v125 = *(void **)(*(_QWORD *)(_R13 + 48) + v122);
                v122 += 8LL;
                nc_free_tensor(v125);
              }
              while ( v123 < *(_DWORD *)(_R13 + 40) );
            }
            nc_free(*(void **)(_R13 + 48));
            v66 = *(_DWORD *)(_R13 + 20) == 14;
            *(_QWORD *)(_R13 + 48) = 0LL;
            *(_DWORD *)(_R13 + 40) = 0;
            if ( v66 )
              nc_free(*(void **)(_R13 + 56));
            free(*(void **)(_R13 + 104));
            *(_QWORD *)(_R13 + 104) = 0LL;
            *(_DWORD *)(_R13 + 20) = 28;
            *(_DWORD *)(_R13 + 24) = 1;
            v126 = (_QWORD *)nc_malloc(8uLL);
            v127 = v502;
            *(_QWORD *)(_R13 + 32) = v126;
            if ( v127 )
              *v126 = nc_dup_node(v127);
            else
              *v126 = 0LL;
            *(_DWORD *)(_R13 + 40) = 1;
            v128 = nc_malloc(8uLL);
            *(_QWORD *)(_R13 + 48) = v128;
            v129 = (_QWORD *)v128;
            v130 = nc_dup_tensor(v113);
            v131 = v502;
            *v129 = v130;
            *(_DWORD *)(_R13 + 56) = v110;
            nc_free_node(v131);
            nc_free_tensor(v113);
            goto LABEL_83;
          case 29:
            v361 = v38[14];
            if ( v361 <= 0 )
            {
              v368 = v36 + 1;
              while ( &v36[(unsigned int)v41 + 1] != v368 )
              {
                v369 = *v368++;
                if ( *(_DWORD *)(v369 + 56) != v361 )
                  goto LABEL_12;
              }
            }
            else
            {
              switch ( v361 )
              {
                case 1:
                  v366 = v36 + 1;
                  v367 = (_DWORD *)*v36;
                  while ( 1 )
                  {
                    if ( v38[15] != v367[15] )
                      goto LABEL_12;
                    if ( &v36[(unsigned int)v41 + 1] == v366 )
                      break;
                    v367 = (_DWORD *)*v366++;
                    if ( v367[14] != 1 )
                      goto LABEL_12;
                  }
                  break;
                case 4:
                  v370 = v36 + 1;
                  v371 = (_DWORD *)*v36;
                  while ( 1 )
                  {
                    if ( v371[15] != v38[15] || v38[16] != v371[16] || v38[17] != v371[17] || v371[18] != v38[18] )
                      goto LABEL_12;
                    if ( &v36[(unsigned int)v41 + 1] == v370 )
                      break;
                    v371 = (_DWORD *)*v370++;
                    if ( v371[14] != 4 )
                      goto LABEL_12;
                  }
                  break;
                case 3:
                  v364 = v36 + 1;
                  v365 = (_DWORD *)*v36;
                  while ( 1 )
                  {
                    if ( v365[15] != v38[15] || v38[16] != v365[16] || v365[17] != v38[17] )
                      goto LABEL_12;
                    if ( &v36[(unsigned int)v41 + 1] == v364 )
                      break;
                    v365 = (_DWORD *)*v364++;
                    if ( v365[14] != 3 )
                      goto LABEL_12;
                  }
                  break;
                default:
                  v362 = v36 + 1;
                  v363 = (_DWORD *)*v36;
                  while ( 1 )
                  {
                    if ( v363[15] != v38[15] || v363[16] != v38[16] || v361 != 2 )
                      goto LABEL_12;
                    if ( &v36[(unsigned int)v41 + 1] == v362 )
                      break;
                    v363 = (_DWORD *)*v362++;
                    if ( v363[14] != 2 )
                      goto LABEL_12;
                  }
                  break;
              }
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( &v36[v41 + 1] != v39 )
            {
              v372 = *v39++;
              if ( *(_DWORD *)(v372 + 16) != 1 )
                goto LABEL_246;
            }
            v476 = *(_QWORD **)(_R13 + 32);
            v72 = v38[*(int *)(_R13 + 64) + 15];
            v73 = (_QWORD *)nc_malloc(8LL * v37);
            v451 = 0LL;
            do
            {
              v73[v451] = **(_QWORD **)(v476[v451] + 32LL);
              ++v451;
            }
            while ( v37 > (int)v451 );
            goto LABEL_65;
          case 30:
            v316 = (__int64 *)*((_QWORD *)v38 + 4);
            v317 = *v316;
            if ( v316[2] )
              continue;
            v318 = (__int64)&v36[v41 + 1];
            v319 = v36 + 1;
            v320 = (_DWORD *)*v36;
            break;
          case 31:
            goto LABEL_266;
          case 36:
            goto LABEL_236;
          default:
            continue;
        }
        while ( 1 )
        {
          if ( v320[15] || !*(_QWORD *)(*((_QWORD *)v320 + 6) + 8LL) )
            goto LABEL_12;
          if ( (__int64 *)v318 == v319 )
            break;
          v320 = (_DWORD *)*v319;
          v321 = *(_QWORD **)(*v319 + 32);
          if ( *v321 == v317 && !v321[2] )
          {
            ++v319;
            if ( v320[14] == v38[14] )
              continue;
          }
          goto LABEL_12;
        }
        if ( v38[4] == 1 )
        {
          do
          {
            if ( v319 == v39 )
            {
              v468 = *(_QWORD **)(_R13 + 32);
              v323 = *(_DWORD *)(_R13 + 24);
              v50 = (_QWORD *)nc_malloc(8LL * v37);
              v324 = nc_mallocz(8LL * v37);
              v325 = v468;
              v469 = v38;
              v326 = 0LL;
              v327 = _R13;
              v328 = (_QWORD *)v324;
              do
              {
                v329 = v325[v326];
                sizej = (size_t)v325;
                v330 = (void *)nc_dup_tensor(*(_QWORD *)(*(_QWORD *)(v329 + 48) + 8LL));
                v331 = nc_stop_grad(v330);
                v325 = (_QWORD *)sizej;
                v328[v326] = v331;
                v50[v326++] = *(_QWORD *)(*(_QWORD *)(v329 + 32) + 8LL);
              }
              while ( v323 > (int)v326 );
              v37 = v323;
              v51 = v328;
              _R13 = v327;
              v38 = v469;
LABEL_54:
              v52 = nc_hconcat(v51, (unsigned int)v37);
              v53 = (unsigned int)v37;
              v458 = (void *)v52;
              v54 = 0;
              v55 = v38;
              v56 = 0LL;
              v502 = (void *)nc_concat_node(a1, v50, v53, *(unsigned int *)(_R13 + 64), *(_QWORD *)(_R13 + 56));
              v57 = nc_dup_node(v55);
              v58 = *(_DWORD *)(_R13 + 24);
              v59 = v57;
              v60 = **(void ***)(v57 + 32);
              v511 = 0LL;
              v509 = v60;
              v510 = v502;
              if ( v58 > 0 )
              {
                do
                {
                  ++v54;
                  v61 = *(void **)(*(_QWORD *)(_R13 + 32) + v56);
                  v56 += 8LL;
                  nc_free_node(v61);
                }
                while ( v54 < *(_DWORD *)(_R13 + 24) );
              }
              v62 = 0LL;
              v63 = 0;
              nc_free(*(void **)(_R13 + 32));
              v64 = *(_DWORD *)(_R13 + 40);
              *(_QWORD *)(_R13 + 32) = 0LL;
              *(_DWORD *)(_R13 + 24) = 0;
              if ( v64 > 0 )
              {
                do
                {
                  ++v63;
                  v65 = *(void **)(*(_QWORD *)(_R13 + 48) + v62);
                  v62 += 8LL;
                  nc_free_tensor(v65);
                }
                while ( v63 < *(_DWORD *)(_R13 + 40) );
              }
              nc_free(*(void **)(_R13 + 48));
              v66 = *(_DWORD *)(_R13 + 20) == 14;
              *(_QWORD *)(_R13 + 48) = 0LL;
              *(_DWORD *)(_R13 + 40) = 0;
              if ( v66 )
                nc_free(*(void **)(_R13 + 56));
              v67 = 0LL;
              free(*(void **)(_R13 + 104));
              *(_QWORD *)(_R13 + 104) = 0LL;
              *(_DWORD *)(_R13 + 20) = 30;
              *(_DWORD *)(_R13 + 24) = 3;
              v68 = nc_malloc(0x18uLL);
              *(_QWORD *)(_R13 + 32) = v68;
              for ( i = v68; ; i = *(_QWORD *)(_R13 + 32) )
              {
                v70 = *(__int64 *)((char *)&v509 + v67);
                if ( v70 )
                {
                  v71 = (_QWORD *)(v67 + i);
                  v67 += 8LL;
                  *v71 = nc_dup_node(v70);
                  if ( v67 == 24 )
                    goto LABEL_111;
                }
                else
                {
                  *(_QWORD *)(i + v67) = 0LL;
                  v67 += 8LL;
                  if ( v67 == 24 )
                  {
LABEL_111:
                    v132 = **(_QWORD **)(v59 + 48);
                    *(_DWORD *)(_R13 + 40) = 2;
                    v133 = nc_malloc(0x10uLL);
                    *(_QWORD *)(_R13 + 48) = v133;
                    v134 = (_QWORD *)v133;
                    v135 = nc_dup_tensor(v132);
                    v136 = *(_QWORD *)(_R13 + 48);
                    *v134 = v135;
                    *(_QWORD *)(v136 + 8) = nc_dup_tensor(v458);
                    *(_DWORD *)(_R13 + 56) = *(_DWORD *)(v59 + 56);
                    *(_DWORD *)(_R13 + 60) = *(_DWORD *)(v59 + 60);
                    nc_free_node((void *)v59);
                    nc_free_node(v502);
                    nc_free_tensor(v458);
                    nc_free(v50);
                    nc_free(v51);
                    v137 = v504;
                    v138 = v502;
                    v7 = v504 + 1;
                    v139 = *(_QWORD *)(_R13 + 32) + 8LL;
                    if ( v504 + 1 <= v505 )
                    {
                      v141 = (char *)ptr;
                    }
                    else
                    {
                      v140 = v505 + (v505 >> 1);
                      if ( v7 < 0x10 )
                        v7 = 16LL;
                      if ( v140 < v7 )
                        v140 = v7;
                      v141 = (char *)realloc(ptr, 16 * v140);
                      v137 = v504;
                      v505 = v140;
                      ptr = v141;
                      v7 = v504 + 1;
                    }
                    v142 = &v141[16 * v137];
                    *(_QWORD *)v142 = v138;
                    *((_QWORD *)v142 + 1) = v139;
                    v504 = v7;
                    goto LABEL_12;
                  }
                }
              }
            }
            v322 = *v39++;
          }
          while ( *(_DWORD *)(v322 + 16) == 1 );
        }
LABEL_246:
        v297 = v507;
        v298 = v507 + 1;
        if ( v507 + 1 <= v508 )
        {
          v301 = (char *)v506;
        }
        else
        {
          v465 = v35;
          v299 = v508 + (v508 >> 1);
          v300 = 16LL;
          if ( v298 >= 0x10 )
            v300 = v507 + 1;
          if ( v299 < v300 )
            v299 = v300;
          v301 = (char *)realloc(v506, 16 * v299);
          v508 = v299;
          v35 = v465;
          v506 = v301;
        }
        v507 = v298;
        v302 = (__int64 *)&v301[16 * v297];
        *v302 = _R13;
        v302[1] = (__int64)v35;
        continue;
      }
      switch ( v38[5] )
      {
        case 2:
          v251 = *(_QWORD *)(_R13 + 56);
          v252 = *(_DWORD *)(_R13 + 64);
          v253 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_202;
        case 3:
          v266 = v38[14] - 1;
          v464 = v38[14];
          if ( v266 > 0 )
            goto LABEL_212;
          v267 = (_QWORD *)nc_malloc(8LL * v37);
          v276 = nc_malloc(8LL * v37);
          v273 = 0LL;
          v271 = v266;
          v270 = (_QWORD *)v276;
          goto LABEL_221;
        case 6:
          v214 = *(_QWORD *)(_R13 + 56);
          v215 = *(_DWORD *)(_R13 + 64);
          v216 = (void *)nc_malloc(8LL * v37);
          v217 = (void *)nc_concat_node(a1, v216, (unsigned int)v37, v215, v214);
          nc_free(v216);
          v502 = v217;
          v218 = *(_DWORD *)(_R13 + 64);
          v219 = *(_QWORD *)(_R13 + 56);
          v220 = nc_malloc(8LL * v37);
          goto LABEL_178;
        case 7:
LABEL_161:
          v462 = *(_QWORD **)(_R13 + 32);
          v198 = nc_malloc(8LL * v37);
          v199 = v462;
          v200 = (_QWORD *)v198;
          if ( v37 > 0 )
            goto LABEL_162;
          goto LABEL_164;
        case 0xA:
        case 0xB:
          v179 = (void *)**((_QWORD **)v38 + 6);
          v461 = (_QWORD *)nc_malloc(8LL * v37);
          v180 = (_QWORD *)nc_mallocz(8LL * v37);
          if ( v179 )
            goto LABEL_144;
          goto LABEL_145;
        case 0xF:
LABEL_293:
          v332 = v38[14];
          v333 = *(_DWORD *)(_R13 + 64);
          if ( v332 == v333 )
          {
            v429 = **((_QWORD **)v38 + 4);
            if ( v37 > 0 )
            {
              if ( *((_QWORD *)v38 + 8) )
                continue;
              v430 = (unsigned int)(v37 - 1);
              v431 = 0LL;
              v432 = 0LL;
              while ( 1 )
              {
                v434 = *(_QWORD *)(*(_QWORD *)(_R13 + 56) + v432 * 8) + v431;
                if ( v432 == v430 )
                  break;
                v433 = v36[++v432];
                if ( **(_QWORD **)(v433 + 32) == v429 && v333 == *(_DWORD *)(v433 + 56) )
                {
                  v431 = *(_QWORD *)(v433 + 64);
                  if ( v431 == v434 )
                    continue;
                }
                goto LABEL_12;
              }
              if ( v38[4] != 1 )
                goto LABEL_246;
              v435 = v36 + 1;
              v436 = (__int64)&v36[v430 + 1];
              while ( (__int64 *)v436 != v435 )
              {
                v437 = *v435++;
                if ( *(_DWORD *)(v437 + 16) != 1 )
                  goto LABEL_246;
              }
            }
            v509 = (void *)nc_dup_node(v429);
            v510 = 0LL;
            sub_17DC0(_R13, 6, 2, (__int64)&v509);
            nc_free_node(v509);
            v7 = v504;
            continue;
          }
          if ( v37 <= 0 )
          {
            v338 = *(_QWORD *)(_R13 + 56);
            v339 = (_QWORD *)nc_malloc(8LL * v37);
          }
          else
          {
            v334 = v36 + 1;
            v335 = v36 + 1;
            while ( &v36[(unsigned int)(v37 - 1) + 1] != v335 )
            {
              v336 = *v335;
              if ( v332 == *(_DWORD *)(*v335 + 56) && *(_QWORD *)(v336 + 64) == *((_QWORD *)v38 + 8) )
              {
                ++v335;
                if ( *(_QWORD *)(v336 + 72) == *((_QWORD *)v38 + 9) )
                  continue;
              }
              goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v335 != v334 )
            {
              v337 = *v334++;
              if ( *(_DWORD *)(v337 + 16) != 1 )
                goto LABEL_246;
            }
            v470 = *(_QWORD **)(_R13 + 32);
            v338 = *(_QWORD *)(_R13 + 56);
            v339 = (_QWORD *)nc_malloc(8LL * v37);
            v340 = 0LL;
            do
            {
              v339[v340] = **(_QWORD **)(v470[v340] + 32LL);
              ++v340;
            }
            while ( v37 > (int)v340 );
          }
          v415 = v338;
          v416 = v333;
          v417 = 0LL;
          v418 = 0;
          v419 = (void *)nc_concat_node(a1, v339, (unsigned int)v37, v416, v415);
          nc_free(v339);
          v502 = v419;
          _RBX = nc_dup_node(v38);
          if ( *(int *)(_R13 + 24) > 0 )
          {
            do
            {
              ++v418;
              v421 = *(void **)(*(_QWORD *)(_R13 + 32) + v417);
              v417 += 8LL;
              nc_free_node(v421);
            }
            while ( v418 < *(_DWORD *)(_R13 + 24) );
          }
          v422 = 0LL;
          v423 = 0;
          nc_free(*(void **)(_R13 + 32));
          v424 = *(_DWORD *)(_R13 + 40);
          *(_QWORD *)(_R13 + 32) = 0LL;
          *(_DWORD *)(_R13 + 24) = 0;
          if ( v424 > 0 )
          {
            do
            {
              ++v423;
              v425 = *(void **)(*(_QWORD *)(_R13 + 48) + v422);
              v422 += 8LL;
              nc_free_tensor(v425);
            }
            while ( v423 < *(_DWORD *)(_R13 + 40) );
          }
          nc_free(*(void **)(_R13 + 48));
          v66 = *(_DWORD *)(_R13 + 20) == 14;
          *(_QWORD *)(_R13 + 48) = 0LL;
          *(_DWORD *)(_R13 + 40) = 0;
          if ( v66 )
            nc_free(*(void **)(_R13 + 56));
          free(*(void **)(_R13 + 104));
          *(_QWORD *)(_R13 + 104) = 0LL;
          *(_DWORD *)(_R13 + 20) = 15;
          *(_DWORD *)(_R13 + 24) = 1;
          v426 = (_QWORD *)nc_malloc(8uLL);
          v427 = v502;
          *(_QWORD *)(_R13 + 32) = v426;
          if ( v427 )
            *v426 = nc_dup_node(v427);
          else
            *v426 = 0LL;
          v178 = (void *)_RBX;
          *(_DWORD *)(_R13 + 56) = *(_DWORD *)(_RBX + 56);
          __asm
          {
            vmovdqu xmm0, xmmword ptr [rbx+40h]
            vmovups xmmword ptr [r13+40h], xmm0
          }
LABEL_140:
          nc_free_node(v178);
          nc_free_node(v502);
LABEL_83:
          v95 = v504;
          v96 = *(_QWORD *)(_R13 + 32);
          v97 = v502;
          v7 = v504 + 1;
          if ( v504 + 1 <= v505 )
          {
            v99 = (char *)ptr;
          }
          else
          {
            v98 = v505 + (v505 >> 1);
            if ( v7 < 0x10 )
              v7 = 16LL;
            if ( v98 < v7 )
              v98 = v7;
            v99 = (char *)realloc(ptr, 16 * v98);
            v95 = v504;
            v505 = v98;
            ptr = v99;
            v7 = v504 + 1;
          }
          v100 = &v99[16 * v95];
          *(_QWORD *)v100 = v97;
          *((_QWORD *)v100 + 1) = v96;
          v504 = v7;
          continue;
        case 0x11:
          v161 = *(_QWORD *)(_R13 + 56);
          v162 = *(_DWORD *)(_R13 + 64);
          v163 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_131;
        case 0x12:
          v143 = (_QWORD *)nc_malloc(8LL * v37);
          v144 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_121;
        case 0x17:
          v459 = (_QWORD *)nc_malloc(8LL * v37);
          v76 = (_QWORD *)nc_malloc(8LL * v37);
          v77 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_91;
        case 0x18:
          v459 = (_QWORD *)nc_malloc(8LL * v37);
          v76 = (_QWORD *)nc_malloc(8LL * v37);
          v77 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_73;
        case 0x1C:
          v110 = v38[14];
          v111 = *(_DWORD *)(_R13 + 64);
          v112 = (void *)nc_mallocz(8LL * v37);
          v113 = (void *)nc_concat(v112, (unsigned int)v37, v111);
          nc_free(v112);
          v114 = *(_QWORD *)(_R13 + 56);
          v460 = *(_DWORD *)(_R13 + 64);
          v115 = (_QWORD *)nc_malloc(8LL * v37);
          goto LABEL_101;
        case 0x1D:
          v72 = v38[*(int *)(_R13 + 64) + 15];
          v73 = (_QWORD *)nc_malloc(8LL * v37);
LABEL_65:
          v502 = (void *)nc_concat_node(a1, v73, (unsigned int)v37, v72, *(_QWORD *)(_R13 + 56));
          v74 = (_DWORD *)nc_dup_node(v38);
          sub_17DC0(_R13, 29, 1, (__int64)&v502);
          *(_DWORD *)(_R13 + 56) = v74[14];
          v75 = v74[14];
          if ( v75 > 0 )
          {
            *(_DWORD *)(_R13 + 60) = v74[15];
            if ( v75 != 1 )
            {
              *(_DWORD *)(_R13 + 64) = v74[16];
              if ( v75 != 2 )
              {
                *(_DWORD *)(_R13 + 68) = v74[17];
                if ( v75 != 3 )
                  *(_DWORD *)(_R13 + 72) = v74[18];
              }
            }
          }
          nc_free_node(v74);
          nc_free_node(v502);
          nc_free(v73);
          goto LABEL_71;
        case 0x1E:
          v50 = (_QWORD *)nc_malloc(8LL * v37);
          v51 = (void *)nc_mallocz(8LL * v37);
          goto LABEL_54;
        case 0x1F:
LABEL_266:
          if ( *(_DWORD *)(_R13 + 64) != 1 )
            continue;
          if ( v37 <= 0 )
          {
            v314 = nc_mallocz(8LL * v37);
          }
          else
          {
            v309 = v36 + 1;
            v310 = v36 + 1;
            while ( &v36[(unsigned int)(v37 - 1) + 1] != v310 )
            {
              v311 = *v310++;
              if ( **(_QWORD **)(v311 + 32) != **((_QWORD **)v38 + 4) )
                goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            while ( v310 != v309 )
            {
              v312 = *v309++;
              if ( *(_DWORD *)(v312 + 16) != 1 )
                goto LABEL_246;
            }
            v467 = *(_QWORD **)(_R13 + 32);
            v313 = 0LL;
            v314 = nc_mallocz(8LL * v37);
            do
            {
              v315 = (void *)nc_dup_tensor(**(_QWORD **)(v467[v313] + 48LL));
              *(_QWORD *)(v314 + 8 * v313++) = nc_stop_grad(v315);
            }
            while ( v37 > (int)v313 );
          }
          v388 = 0LL;
          v389 = nc_concat(v314, (unsigned int)v37, 0LL);
          v390 = (void *)v314;
          v391 = 0;
          v392 = (void *)v389;
          nc_free(v390);
          v393 = (_QWORD *)nc_dup_node(v38);
          v394 = (__int64 *)v393[4];
          if ( *(int *)(_R13 + 24) > 0 )
          {
            do
            {
              ++v391;
              v395 = *(void **)(*(_QWORD *)(_R13 + 32) + v388);
              v388 += 8LL;
              nc_free_node(v395);
            }
            while ( v391 < *(_DWORD *)(_R13 + 24) );
          }
          v396 = 0LL;
          v397 = 0;
          nc_free(*(void **)(_R13 + 32));
          v398 = *(_DWORD *)(_R13 + 40);
          *(_QWORD *)(_R13 + 32) = 0LL;
          *(_DWORD *)(_R13 + 24) = 0;
          if ( v398 > 0 )
          {
            do
            {
              ++v397;
              v399 = *(void **)(*(_QWORD *)(_R13 + 48) + v396);
              v396 += 8LL;
              nc_free_tensor(v399);
            }
            while ( v397 < *(_DWORD *)(_R13 + 40) );
          }
          nc_free(*(void **)(_R13 + 48));
          v66 = *(_DWORD *)(_R13 + 20) == 14;
          *(_QWORD *)(_R13 + 48) = 0LL;
          *(_DWORD *)(_R13 + 40) = 0;
          if ( v66 )
            nc_free(*(void **)(_R13 + 56));
          free(*(void **)(_R13 + 104));
          *(_QWORD *)(_R13 + 104) = 0LL;
          *(_DWORD *)(_R13 + 20) = 31;
          *(_DWORD *)(_R13 + 24) = 1;
          v400 = (_QWORD *)nc_malloc(8uLL);
          v401 = *v394;
          *(_QWORD *)(_R13 + 32) = v400;
          if ( v401 )
            *v400 = nc_dup_node(v401);
          else
            *v400 = 0LL;
          *(_DWORD *)(_R13 + 40) = 1;
          v402 = (_QWORD *)nc_malloc(8uLL);
          *(_QWORD *)(_R13 + 48) = v402;
          *v402 = nc_dup_tensor(v392);
          *(_QWORD *)(_R13 + 56) = v393[7];
          nc_free_node(v393);
          nc_free_tensor(v392);
          v7 = v504;
          continue;
        case 0x24:
LABEL_236:
          if ( *(_DWORD *)(_R13 + 64) != 1 )
            continue;
          if ( v37 <= 0 )
          {
            v303 = *(_QWORD *)(_R13 + 56);
            v304 = (_QWORD *)nc_malloc(8LL * v37);
          }
          else
          {
            v287 = *((_QWORD *)v38 + 7);
            v288 = (unsigned int)(v37 - 1);
            v289 = v287 + 1;
            v290 = v288 + v287 + 1;
            v291 = &v36[-v287];
            while ( v290 != v289 )
            {
              v292 = v291[v289];
              if ( *(_QWORD *)(v292 + 64) == *((_QWORD *)v38 + 8) )
              {
                v293 = v289++;
                if ( *(_QWORD *)(v292 + 56) == v293 )
                  continue;
              }
              goto LABEL_12;
            }
            if ( v38[4] != 1 )
              goto LABEL_246;
            v294 = v36 + 1;
            v295 = (__int64)&v36[v288 + 1];
            while ( (__int64 *)v295 != v294 )
            {
              v296 = *v294++;
              if ( *(_DWORD *)(v296 + 16) != 1 )
                goto LABEL_246;
            }
            v466 = *(_QWORD **)(_R13 + 32);
            v303 = *(_QWORD *)(_R13 + 56);
            v304 = (_QWORD *)nc_malloc(8LL * v37);
            v305 = 0LL;
            do
            {
              v304[v305] = **(_QWORD **)(v466[v305] + 32LL);
              ++v305;
            }
            while ( v37 > (int)v305 );
          }
          v306 = (void *)nc_concat_node(a1, v304, (unsigned int)v37, 1LL, v303);
          nc_free(v304);
          v502 = v306;
          _RBX = (void *)nc_dup_node(v38);
          sub_17DC0(_R13, 36, 1, (__int64)&v502);
          __asm
          {
            vmovdqu xmm0, xmmword ptr [rbx+38h]
            vmovups xmmword ptr [r13+38h], xmm0
          }
          nc_free_node(_RBX);
          nc_free_node(v502);
LABEL_71:
          sub_9980(&ptr, (__int64)v502, *(_QWORD *)(_R13 + 32));
          v7 = v504;
          continue;
        default:
          continue;
      }
    }
    if ( v507 <= 1 )
    {
      v13 = (char *)v506;
      goto LABEL_32;
    }
    v13 = (char *)v506;
    v14 = 1LL;
    v15 = v507 - 1;
    v16 = v507;
    v17 = (__int64 *)v506;
LABEL_15:
    v18 = *v17;
    v19 = (void *)v17[1];
    v20 = v14;
    v21 = v14;
    if ( v16 <= v14 )
      goto LABEL_31;
    v22 = *(_DWORD *)(v18 + 24);
    v23 = 0;
    do
    {
      while ( 1 )
      {
        v24 = &v13[16 * v21];
        v25 = *(_QWORD *)v24;
        if ( *(_DWORD *)(*(_QWORD *)v24 + 24LL) != v22 || *(_DWORD *)(v25 + 64) != *(_DWORD *)(v18 + 64) )
          break;
        if ( v22 > 0 )
        {
          v26 = *(_QWORD **)(v25 + 32);
          v27 = *(_QWORD **)(v18 + 32);
          if ( *v27 != *v26 )
            break;
          v28 = 1LL;
          while ( v22 > (int)v28 )
          {
            v29 = v26[v28++];
            if ( v29 != v27[v28 - 1] )
              goto LABEL_17;
          }
        }
        if ( *(int *)(v25 + 16) > 1 )
          break;
        v30 = (__int64 *)*((_QWORD *)v24 + 1);
        if ( !v30 )
          __assert_fail("pparent1 != NULL", "libnc.c", 0x2180u, "nc_merge_duplicate_concat_nodes");
        sizeb = (size_t)v19;
        v455 = (char *)v16;
        nc_free_node((void *)v25);
        v31 = nc_dup_node(v18);
        v32 = v455;
        v19 = (void *)sizeb;
        *v30 = v31;
        v21 = v20;
        if ( (unsigned __int64)(v455 - 1) <= v20 )
        {
          v507 = (unsigned __int64)(v455 - 1);
          v45 = v18;
          goto LABEL_42;
        }
        sizec = (size_t)(v455 - 1);
        v456 = v19;
        memmove(&v13[16 * v20], &v13[16 * v20 + 16], 16LL * (_QWORD)&v32[-v20] - 16);
        v22 = *(_DWORD *)(v18 + 24);
        v23 = 1;
        v19 = v456;
        v507 = sizec;
        v16 = sizec;
      }
LABEL_17:
      ++v20;
      v16 = v507;
      v21 = v20;
    }
    while ( v20 < v507 );
    if ( !v23 )
      break;
    v45 = v18;
LABEL_42:
    v46 = v504;
    v7 = v504 + 1;
    if ( v504 + 1 <= v505 )
    {
      v48 = (char *)ptr;
    }
    else
    {
      v457 = v19;
      v47 = v505 + (v505 >> 1);
      if ( v7 < 0x10 )
        v7 = 16LL;
      if ( v47 < v7 )
        v47 = v7;
      v48 = (char *)realloc(ptr, 16 * v47);
      v46 = v504;
      v505 = v47;
      ptr = v48;
      v19 = v457;
      v7 = v504 + 1;
    }
    v49 = &v48[16 * v46];
    *(_QWORD *)v49 = v45;
    *((_QWORD *)v49 + 1) = v19;
    v504 = v7;
  }
  v15 = v507 - 1;
LABEL_31:
  ++v14;
  v17 += 2;
  if ( v15 > v14 - 1 )
    goto LABEL_15;
LABEL_32:
  nc_free(ptr);
  nc_free(v13);
}

// ======================================================
// Function: sub_17DC0 @ 0x17DC0
// ======================================================

__int64 __fastcall sub_17DC0(__int64 a1, int a2, int a3, __int64 a4)
{
  __int64 v6; // r12
  int v7; // ebp
  void *v9; // rdi
  __int64 v10; // r12
  int v11; // ebp
  int v12; // eax
  void *v13; // rdi
  bool v14; // zf
  __int64 result; // rax
  __int64 v16; // rbp
  __int64 v17; // r13
  __int64 *v18; // r12

  v6 = 0LL;
  v7 = 0;
  while ( v7 < *(_DWORD *)(a1 + 24) )
  {
    ++v7;
    v9 = *(void **)(*(_QWORD *)(a1 + 32) + v6);
    v6 += 8LL;
    nc_free_node(v9);
  }
  v10 = 0LL;
  v11 = 0;
  nc_free(*(void **)(a1 + 32));
  v12 = *(_DWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 32) = 0LL;
  *(_DWORD *)(a1 + 24) = 0;
  if ( v12 > 0 )
  {
    do
    {
      ++v11;
      v13 = *(void **)(*(_QWORD *)(a1 + 48) + v10);
      v10 += 8LL;
      nc_free_tensor(v13);
    }
    while ( v11 < *(_DWORD *)(a1 + 40) );
  }
  nc_free(*(void **)(a1 + 48));
  v14 = *(_DWORD *)(a1 + 20) == 14;
  *(_QWORD *)(a1 + 48) = 0LL;
  *(_DWORD *)(a1 + 40) = 0;
  if ( v14 )
    nc_free(*(void **)(a1 + 56));
  free(*(void **)(a1 + 104));
  *(_QWORD *)(a1 + 104) = 0LL;
  *(_DWORD *)(a1 + 20) = a2;
  *(_DWORD *)(a1 + 24) = a3;
  result = nc_malloc(8LL * a3);
  *(_QWORD *)(a1 + 32) = result;
  if ( a3 > 0 )
  {
    v16 = 0LL;
    v17 = 8LL * (unsigned int)(a3 - 1);
    while ( 1 )
    {
      if ( *(_QWORD *)(a4 + v16) )
      {
        v18 = (__int64 *)(result + v16);
        result = nc_dup_node();
        *v18 = result;
        if ( v17 == v16 )
          return result;
      }
      else
      {
        *(_QWORD *)(result + v16) = 0LL;
        if ( v17 == v16 )
          return result;
      }
      result = *(_QWORD *)(a1 + 32);
      v16 += 8LL;
    }
  }
  return result;
}

// ======================================================
// Function: sub_9980 @ 0x9980
// ======================================================

char *__fastcall sub_9980(void **a1, __int64 a2, __int64 a3)
{
  void *v6; // rsi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rcx
  void *v9; // rdi
  unsigned __int64 v10; // rbp
  char *v11; // rax
  char *result; // rax

  v6 = a1[1];
  v7 = (unsigned __int64)a1[2];
  v8 = (unsigned __int64)v6 + 1;
  if ( (unsigned __int64)v6 + 1 <= v7 )
  {
    v11 = (char *)*a1;
  }
  else
  {
    v9 = *a1;
    v10 = v7 + (v7 >> 1);
    if ( v8 < 0x10 )
      v8 = 16LL;
    if ( v10 < v8 )
      v10 = v8;
    v11 = (char *)realloc(v9, 16 * v10);
    v6 = a1[1];
    a1[2] = (void *)v10;
    *a1 = v11;
    v8 = (unsigned __int64)v6 + 1;
  }
  result = &v11[16 * (_QWORD)v6];
  *(_QWORD *)result = a2;
  *((_QWORD *)result + 1) = a3;
  a1[1] = (void *)v8;
  return result;
}

