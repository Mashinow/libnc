// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dump_graph
// Included functions: 2

// ======================================================
// Function: nc_dump_graph @ 0x17EF0
// ======================================================

void __fastcall nc_dump_graph(__int64 a1)
{
  __int64 v1; // rsi
  unsigned __int64 v2; // rsi
  _QWORD *v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rdx
  unsigned __int64 v6; // rax
  __int64 v7; // rbp
  __int64 v8; // r12
  int v9; // ebx
  __int64 v10; // r15
  unsigned int v11; // eax
  bool v12; // cc
  const char *v13; // rsi
  __int64 v14; // r12
  int v15; // ebx
  __int64 v16; // rbx
  unsigned __int64 v17; // [rsp+8h] [rbp-60h]
  void *ptr; // [rsp+10h] [rbp-58h] BYREF
  unsigned __int64 v19; // [rsp+18h] [rbp-50h]
  __int64 v20; // [rsp+20h] [rbp-48h]

  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
  {
    puts("No graph available");
    return;
  }
  ptr = 0LL;
  v19 = 0LL;
  v20 = 0LL;
  sub_151D0((__int64)&ptr, v1);
  v2 = v19;
  if ( !v19 )
    goto LABEL_35;
  v3 = ptr;
  v4 = 0LL;
  do
  {
    v5 = v3[v4];
    *(_DWORD *)(v5 + 124) = v4++;
    *(_BYTE *)(v5 + 120) = 0;
  }
  while ( v4 != v2 );
  v17 = 0LL;
  v6 = 0LL;
  while ( 2 )
  {
    v7 = v3[v6];
    printf("n%lu", *(_QWORD *)(v7 + 96));
    printf(" = [%d] %s", *(unsigned int *)(v7 + 16), off_235C20[*(unsigned int *)(v7 + 20)]);
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
        v14 = 0LL;
        v15 = 0;
        while ( 1 )
        {
          ++v15;
          printf("%d", *(_QWORD *)(*(_QWORD *)(v7 + 56) + v14));
          if ( v15 >= *(_DWORD *)(v7 + 24) )
            break;
          v14 += 8LL;
          printf(", ");
        }
      }
LABEL_33:
      putchar(93);
      goto LABEL_16;
    }
    v8 = 0LL;
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
        v8 += 8LL;
        printf("n%lu", *(_QWORD *)(v10 + 96));
        if ( *(_DWORD *)(v7 + 24) <= v9 )
          goto LABEL_11;
      }
      putchar(32);
      if ( v10 )
        goto LABEL_10;
LABEL_21:
      ++v9;
      v8 += 8LL;
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
    putchar(10);
    v6 = ++v17;
    if ( v19 > v17 )
    {
      v3 = ptr;
      continue;
    }
    break;
  }
LABEL_35:
  nc_free(ptr);
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

