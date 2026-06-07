// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_dump_graph
// Included functions: 2

// ======================================================
// Function: nc_dump_graph @ 0x66A165F0
// ======================================================

void __fastcall nc_dump_graph(__int64 a1)
{
  __int64 v1; // rdx
  unsigned __int64 v2; // r8
  _QWORD *v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rdx
  unsigned __int64 v6; // r13
  __int64 v7; // rsi
  __int64 v8; // rdi
  int v9; // ebx
  __int64 v10; // r15
  unsigned int v11; // eax
  bool v12; // cc
  const char *v13; // rdx
  __int64 v14; // rdi
  int v15; // ebx
  __int64 v16; // rbx
  void *Block; // [rsp+20h] [rbp-68h] BYREF
  unsigned __int64 v18; // [rsp+28h] [rbp-60h]
  __int64 v19; // [rsp+30h] [rbp-58h]

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
  {
    Block = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    sub_66A12F00((__int64)&Block, v1);
    v2 = v18;
    v3 = Block;
    if ( !v18 )
      goto LABEL_19;
    v4 = 0i64;
    do
    {
      v5 = v3[v4];
      *(_DWORD *)(v5 + 124) = v4++;
      *(_BYTE *)(v5 + 120) = 0;
    }
    while ( v4 != v2 );
    v6 = 0i64;
    while ( 1 )
    {
      v7 = v3[v6];
      printf("n%I64u", *(_QWORD *)(v7 + 96));
      printf(" = [%d] %s", *(unsigned int *)(v7 + 16), off_66A37080[*(unsigned int *)(v7 + 20)]);
      if ( *(int *)(v7 + 24) <= 0 )
      {
LABEL_11:
        v11 = *(_DWORD *)(v7 + 20);
        v12 = v11 <= 0xE;
        if ( v11 != 14 )
          goto LABEL_12;
LABEL_23:
        printf(", axis=%d, size=[", *(unsigned int *)(v7 + 64));
        if ( *(int *)(v7 + 24) > 0 )
        {
          v14 = 0i64;
          v15 = 0;
          while ( 1 )
          {
            ++v15;
            printf("%d", *(_QWORD *)(*(_QWORD *)(v7 + 56) + v14));
            if ( v15 >= *(_DWORD *)(v7 + 24) )
              break;
            v14 += 8i64;
            printf(", ");
          }
        }
LABEL_33:
        putchar(93);
        goto LABEL_16;
      }
      v8 = 0i64;
      v9 = 0;
      do
      {
        while ( 1 )
        {
          v10 = *(_QWORD *)(*(_QWORD *)(v7 + 32) + v8);
          if ( !v9 )
            break;
          printf(", ");
          if ( !v10 )
            goto LABEL_21;
LABEL_10:
          ++v9;
          v8 += 8i64;
          printf("n%I64u", *(_QWORD *)(v10 + 96));
          if ( *(_DWORD *)(v7 + 24) <= v9 )
            goto LABEL_11;
        }
        putchar(32);
        if ( v10 )
          goto LABEL_10;
LABEL_21:
        ++v9;
        v8 += 8i64;
        printf("<null>");
      }
      while ( v9 < *(_DWORD *)(v7 + 24) );
      v11 = *(_DWORD *)(v7 + 20);
      v12 = v11 <= 0xE;
      if ( v11 == 14 )
        goto LABEL_23;
LABEL_12:
      if ( v12 )
      {
        if ( v11 != 3 )
          goto LABEL_16;
        printf(", dims=[");
        LODWORD(v16) = *(_DWORD *)(v7 + 56) - 1;
        if ( (int)v16 >= 0 )
        {
          v16 = (int)v16;
          do
          {
            printf("%d", *(unsigned int *)(v7 + 8 * v16 + 64));
            if ( !(_DWORD)v16 )
              break;
            --v16;
            printf(", ");
          }
          while ( (int)v16 >= 0 );
        }
        goto LABEL_33;
      }
      if ( v11 == 15 )
      {
        printf(
          ", axis=%d, pos=%d, n=%d",
          *(unsigned int *)(v7 + 56),
          *(unsigned int *)(v7 + 64),
          *(unsigned int *)(v7 + 72));
      }
      else if ( v11 == 30 )
      {
        printf(", a_trans=%d, b_trans=%d", *(unsigned int *)(v7 + 56), *(unsigned int *)(v7 + 60));
      }
LABEL_16:
      v13 = *(const char **)(v7 + 104);
      if ( v13 )
        printf(" (%s)", v13);
      ++v6;
      putchar(10);
      v3 = Block;
      if ( v18 <= v6 )
      {
LABEL_19:
        _aligned_free(v3);
        return;
      }
    }
  }
  puts("No graph available");
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

