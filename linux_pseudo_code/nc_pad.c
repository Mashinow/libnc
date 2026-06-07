// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_pad
// Included functions: 4

// ======================================================
// Function: nc_pad @ 0x21410
// ======================================================

char *__fastcall nc_pad(char *ptr, __int64 a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  char *v5; // rbp
  int v6; // ebx
  __int64 v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rdx
  __int64 v10; // rbx
  __int64 v11; // r13
  unsigned int v12; // r15d
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // r12
  int v16; // eax
  int v17; // edx
  __int64 v18; // rax
  __int64 v19; // rax
  int v20; // edx
  __int64 v21; // rbx
  __int64 v22; // rsi
  int v23; // edx
  __int64 v24; // r12
  unsigned __int64 v25; // r8
  __int64 v26; // r12
  __int64 v27; // rax
  bool v28; // zf
  int v29; // eax
  int v30; // esi
  __int64 *v31; // rcx
  __int64 v32; // rdx
  char *v33; // rdi
  __int64 v34; // rsi
  __int64 v35; // rax
  __int64 v36; // rdx
  __int64 v37; // r14
  _QWORD *v38; // rax
  void *v39; // rdi
  __int64 v41; // [rsp+0h] [rbp-108h]
  __int64 v43; // [rsp+8h] [rbp-100h]
  __int64 v44; // [rsp+10h] [rbp-F8h]
  __int64 v45; // [rsp+10h] [rbp-F8h]
  __int64 v46; // [rsp+18h] [rbp-F0h]
  __int64 v48; // [rsp+20h] [rbp-E8h]
  __int64 v49; // [rsp+28h] [rbp-E0h]
  __int64 v50; // [rsp+28h] [rbp-E0h]
  __int64 v51; // [rsp+30h] [rbp-D8h]
  __int64 v52; // [rsp+30h] [rbp-D8h]
  __int64 v53; // [rsp+38h] [rbp-D0h]
  __int64 v54; // [rsp+40h] [rbp-C8h]
  int v55; // [rsp+40h] [rbp-C8h]
  int v56; // [rsp+44h] [rbp-C4h]
  __int64 v57; // [rsp+48h] [rbp-C0h]
  __int64 v58; // [rsp+50h] [rbp-B8h]
  __int64 v59; // [rsp+50h] [rbp-B8h]
  __int64 v60; // [rsp+58h] [rbp-B0h]
  __int64 v61; // [rsp+58h] [rbp-B0h]
  __int64 v62; // [rsp+60h] [rbp-A8h]
  __int64 v63; // [rsp+60h] [rbp-A8h]
  __int64 v64; // [rsp+68h] [rbp-A0h]
  __int64 v65; // [rsp+68h] [rbp-A0h]
  __int64 v66; // [rsp+70h] [rbp-98h]
  int v67; // [rsp+84h] [rbp-84h] BYREF
  char *v68; // [rsp+88h] [rbp-80h] BYREF
  __int64 v69; // [rsp+90h] [rbp-78h] BYREF
  __int64 v70; // [rsp+98h] [rbp-70h] BYREF
  __int64 v71; // [rsp+B0h] [rbp-58h] BYREF
  __int64 v72; // [rsp+B8h] [rbp-50h]
  __int64 v73; // [rsp+C0h] [rbp-48h]
  __int64 v74; // [rsp+C8h] [rbp-40h]

  v5 = ptr;
  v54 = __PAIR64__(a5, a3);
  if ( !(a2 | a4) )
    return v5;
  v6 = *((_DWORD *)ptr + 20);
  if ( v6 <= 0 )
    __assert_fail("x->n_dims >= 1", "libnc.c", 0x18DEu, "nc_pad");
  if ( !ptr[73] )
    __assert_fail("x->contig[0]", "libnc.c", 0x18DFu, "nc_pad");
  v7 = *((_QWORD *)ptr + 15) + a2 + a4;
  if ( v7 <= 0 )
    sub_18270("pad", (__int64)ptr, 0LL);
  v8 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  v69 = v7;
  if ( v6 != 1 )
    memcpy(&v70, v5 + 128, 8LL * (unsigned int)(v6 - 2) + 8);
  v9 = (unsigned int)v6;
  v10 = 0LL;
  v11 = nc_new_tensor_nz(v8, *((unsigned int *)v5 + 12), v9, &v69);
  v12 = dword_30520[*(unsigned int *)(v11 + 48)];
  v13 = 0LL;
  v14 = a4;
  if ( a2 <= 0 )
    v13 = a2;
  if ( a4 > 0 )
    v14 = 0LL;
  if ( a2 >= 0 )
    v10 = a2;
  v15 = *((_QWORD *)v5 + 15) + v13 + v14 + v10;
  v16 = sub_7F90(
          &v67,
          1,
          (__int64)v5,
          v11,
          0LL,
          *((_QWORD *)v5 + 15) + v14,
          v41,
          a4,
          v44,
          -v13,
          *((_QWORD *)v5 + 15) + v13 + v14,
          *((_QWORD *)v5 + 15) + v14,
          v51,
          v8,
          v54,
          v57,
          v58,
          v60,
          v62,
          v64);
  v17 = *((_DWORD *)v5 + 20);
  v71 = 0LL;
  v45 = v16;
  v18 = 1LL;
  if ( v17 <= 1 )
  {
    v19 = 0LL;
  }
  else
  {
    do
      *(&v71 + v18++) = 0LL;
    while ( v17 > (int)v18 );
    v19 = v71;
  }
  v52 = v10 << v12;
  v65 = 4 * v49;
  v66 = 4 * v15 - 4;
  v61 = (v49 - 1) << v12;
  v59 = v15 << v12;
  v50 = v46 << v12;
  v63 = -a2;
  while ( 1 )
  {
    if ( v19 == -1 )
    {
      v37 = a2;
      goto LABEL_44;
    }
    v20 = *(_DWORD *)(v11 + 80);
    v21 = *(_QWORD *)(v11 + 56);
    if ( v20 <= 0 )
      goto LABEL_23;
    v22 = *(_QWORD *)(v11 + 88) * v19;
    if ( v20 == 1 )
      goto LABEL_24;
    v22 += *(_QWORD *)(v11 + 96) * v72;
    if ( v20 == 2 )
      goto LABEL_24;
    v22 += *(_QWORD *)(v11 + 104) * v73;
    if ( v20 == 3 )
      goto LABEL_24;
    if ( v20 != 4 )
      goto LABEL_23;
    v23 = *((_DWORD *)v5 + 20);
    v24 = *((_QWORD *)v5 + 7);
    v21 += *(_QWORD *)(v11 + 112) * v74 + v22;
    if ( v23 <= 0 )
    {
LABEL_53:
      v25 = *((_QWORD *)v5 + 12);
      v19 = 0LL;
      goto LABEL_30;
    }
    while ( 2 )
    {
      v19 *= *((_QWORD *)v5 + 11);
      v25 = *((_QWORD *)v5 + 12);
      if ( v23 != 1 )
      {
        v19 += v72 * v25;
        if ( v23 != 2 )
        {
          v19 += *((_QWORD *)v5 + 13) * v73;
          if ( v23 != 3 )
          {
            if ( v23 == 4 )
            {
              v19 += *((_QWORD *)v5 + 14) * v74;
              break;
            }
LABEL_23:
            v22 = 0LL;
LABEL_24:
            v23 = *((_DWORD *)v5 + 20);
            v21 += v22;
            v24 = *((_QWORD *)v5 + 7);
            if ( v23 <= 0 )
              goto LABEL_53;
            continue;
          }
        }
      }
      break;
    }
LABEL_30:
    v26 = v19 + v24;
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, unsigned __int64, __int64, __int64, _QWORD))(v53 + 72))(
      v53,
      v21 + v52,
      *(_QWORD *)(v11 + 96) >> v12,
      v26 + v50,
      v25 >> v12,
      v48,
      v45,
      v12);
    if ( a2 <= 0 )
    {
      if ( a2 && v55 )
      {
        if ( v55 != 1 )
          goto LABEL_51;
        if ( *((_DWORD *)v5 + 12) )
          nc_error("unsupported type for %s\n", (char)"nc_pad");
        (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v53 + 376))(
          v53,
          v21,
          *(_QWORD *)(v11 + 96) >> v12,
          v26,
          *((_QWORD *)v5 + 12) >> v12,
          v63,
          v45,
          0LL);
      }
LABEL_34:
      v27 = v43;
      v28 = v43 == 0;
      if ( v43 > 0 )
        goto LABEL_35;
      goto LABEL_56;
    }
    if ( v55 )
    {
      if ( v55 != 1 )
        goto LABEL_51;
      (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64))(v53 + 120))(
        v53,
        v21,
        *(_QWORD *)(v11 + 96) >> v12,
        v26,
        *((_QWORD *)v5 + 12) >> v12,
        a2,
        v45);
      goto LABEL_34;
    }
    (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD))(v53 + 112))(
      v53,
      v21,
      *(_QWORD *)(v11 + 96) >> v12,
      0LL,
      a2,
      v45,
      v12);
    v27 = v43;
    v28 = v43 == 0;
    if ( v43 > 0 )
    {
LABEL_35:
      if ( v56 )
      {
        if ( v56 != 1 )
          goto LABEL_51;
        (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v53 + 120))(
          v53,
          v21 + v59,
          *(_QWORD *)(v11 + 96) >> v12,
          v26 + v61,
          *((_QWORD *)v5 + 12) >> v12,
          v27,
          v45,
          v12);
      }
      else
      {
        (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD))(v53 + 112))(
          v53,
          v21 + v59,
          *(_QWORD *)(v11 + 96) >> v12,
          0LL,
          v43,
          v45,
          v12);
      }
      goto LABEL_38;
    }
LABEL_56:
    if ( !v28 && v56 )
    {
      if ( v56 != 1 )
LABEL_51:
        abort();
      if ( *((_DWORD *)v5 + 12) )
        nc_error("unsupported type for %s\n", (char)"nc_pad");
      (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v53 + 376))(
        v53,
        v21 + v66,
        *(_QWORD *)(v11 + 96) >> v12,
        v26 + v65,
        *((_QWORD *)v5 + 12) >> v12,
        -v43,
        v45,
        0LL);
    }
LABEL_38:
    v29 = v67;
    v30 = *((_DWORD *)v5 + 20);
    if ( v67 >= v30 )
      goto LABEL_43;
    v31 = &v71 + v67;
    v32 = *v31 + 1;
    *v31 = v32;
    if ( v32 == *(_QWORD *)&v5[8 * v29 + 120] )
      break;
LABEL_54:
    v19 = v71;
  }
  v33 = &v5[8 * v29 + 8];
  v34 = (unsigned int)(~v29 + v30);
  v35 = 0LL;
  while ( 1 )
  {
    v31[v35] = 0LL;
    if ( v34 == v35 )
      break;
    v36 = v31[v35 + 1] + 1;
    v31[++v35] = v36;
    if ( v36 != *(_QWORD *)&v33[8 * v35 + 112] )
      goto LABEL_54;
  }
LABEL_43:
  v71 = -1LL;
  v37 = a2;
LABEL_44:
  v68 = v5;
  v38 = sub_17800(17, (__int64 *)(v11 + 24), (void **)(v11 + 32), (__int64)&v68);
  if ( v38 )
  {
    v38[7] = v37;
    v38[8] = v43;
    *((_DWORD *)v38 + 18) = v55;
    *((_DWORD *)v38 + 19) = v56;
  }
  v39 = v5;
  v5 = (char *)v11;
  nc_free_tensor(v39);
  return v5;
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
// Function: sub_7F90 @ 0x7F90
// ======================================================

__int64 __fastcall sub_7F90(
        _DWORD *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20)
{
  int v20; // r8d
  __int64 v21; // rcx
  __int64 v22; // rax
  int v23; // esi
  __int64 result; // rax
  int v25; // r8d
  int v26; // [rsp+38h] [rbp-120h]
  __int64 v27; // [rsp+38h] [rbp-120h]
  __int64 v28; // [rsp+70h] [rbp-E8h]
  __int64 v29; // [rsp+78h] [rbp-E0h]
  __int64 v30; // [rsp+80h] [rbp-D8h]
  __int64 v31; // [rsp+88h] [rbp-D0h]
  __int64 v32; // [rsp+90h] [rbp-C8h]
  __int64 v33; // [rsp+98h] [rbp-C0h]
  __int64 v34; // [rsp+A0h] [rbp-B8h]
  __int64 v35; // [rsp+A8h] [rbp-B0h]
  __int64 v36; // [rsp+B0h] [rbp-A8h]
  __int64 v37; // [rsp+B8h] [rbp-A0h]
  __int64 v38; // [rsp+C0h] [rbp-98h]
  __int64 v39; // [rsp+C8h] [rbp-90h]
  __int64 v40; // [rsp+D0h] [rbp-88h]
  __int64 v41; // [rsp+D8h] [rbp-80h]
  __int64 v42; // [rsp+E0h] [rbp-78h]
  __int64 v43; // [rsp+E8h] [rbp-70h]

  if ( a4 )
  {
    v28 = a4;
    if ( a5 )
    {
      v29 = a5;
      if ( a6 )
      {
        v30 = a6;
        if ( a7 )
        {
          v31 = a7;
          if ( a8 )
          {
            v32 = a8;
            if ( a9 )
            {
              v33 = a9;
              if ( a10 )
              {
                v34 = a10;
                if ( a11 )
                {
                  v35 = a11;
                  if ( a12 )
                  {
                    v36 = a12;
                    if ( a13 )
                    {
                      v37 = a13;
                      if ( a14 )
                      {
                        v38 = a14;
                        if ( a15 )
                        {
                          v39 = a15;
                          if ( a16 )
                          {
                            v40 = a16;
                            if ( a17 )
                            {
                              v41 = a17;
                              if ( a18 )
                              {
                                v42 = a18;
                                if ( a19 )
                                {
                                  v43 = a19;
                                  if ( a20 )
                                    __assert_fail("count < countof(tab)", "libnc.c", 0x122Du, "get_contig_len_N");
                                  v20 = 16;
                                }
                                else
                                {
                                  v20 = 15;
                                }
                              }
                              else
                              {
                                v20 = 14;
                              }
                            }
                            else
                            {
                              v20 = 13;
                            }
                          }
                          else
                          {
                            v20 = 12;
                          }
                        }
                        else
                        {
                          v20 = 11;
                        }
                      }
                      else
                      {
                        v20 = 10;
                      }
                    }
                    else
                    {
                      v20 = 9;
                    }
                  }
                  else
                  {
                    v20 = 8;
                  }
                }
                else
                {
                  v20 = 7;
                }
              }
              else
              {
                v20 = 6;
              }
            }
            else
            {
              v20 = 5;
            }
          }
          else
          {
            v20 = 4;
          }
        }
        else
        {
          v20 = 3;
        }
      }
      else
      {
        v20 = 2;
      }
    }
    else
    {
      v20 = 1;
    }
  }
  else
  {
    v20 = 0;
  }
  v26 = *(_DWORD *)(a3 + 80);
  if ( a2 < v26 && (v21 = a2, *(_BYTE *)(a3 + a2 + 73)) )
  {
    v22 = (unsigned int)(v26 - 1 - a2);
    v23 = v20;
    v27 = v21 + v22;
    result = 1LL;
    do
    {
      v25 = v21;
      if ( v23
        && (!*(_BYTE *)(v28 + v21 + 73)
         || v23 != 1
         && (!*(_BYTE *)(v29 + v21 + 73)
          || v23 != 2
          && (!*(_BYTE *)(v30 + v21 + 73)
           || v23 != 3
           && (!*(_BYTE *)(v31 + v21 + 73)
            || v23 != 4
            && (!*(_BYTE *)(v32 + v21 + 73)
             || v23 != 5
             && (!*(_BYTE *)(v33 + v21 + 73)
              || v23 != 6
              && (!*(_BYTE *)(v34 + v21 + 73)
               || v23 != 7
               && (!*(_BYTE *)(v35 + v21 + 73)
                || v23 != 8
                && (!*(_BYTE *)(v36 + v21 + 73)
                 || v23 != 9
                 && (!*(_BYTE *)(v37 + v21 + 73)
                  || v23 != 10
                  && (!*(_BYTE *)(v38 + v21 + 73)
                   || v23 != 11
                   && (!*(_BYTE *)(v39 + v21 + 73)
                    || v23 != 12
                    && (!*(_BYTE *)(v40 + v21 + 73)
                     || v23 != 13
                     && (!*(_BYTE *)(v41 + v21 + 73)
                      || v23 != 14 && (!*(_BYTE *)(v42 + v21 + 73) || v23 == 16 && !*(_BYTE *)(v43 + v21 + 73)))))))))))))))) )
      {
        break;
      }
      v25 = v21 + 1;
      result *= *(_QWORD *)(a3 + 8 * v21 + 120);
      if ( v21 == v27 )
        break;
      ++v21;
    }
    while ( *(_BYTE *)(a3 + 1 + v21 + 72) );
    a2 = v25;
  }
  else
  {
    result = 1LL;
  }
  *a1 = a2;
  return result;
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

