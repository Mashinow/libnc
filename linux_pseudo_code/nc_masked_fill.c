// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_masked_fill
// Included functions: 3

// ======================================================
// Function: nc_masked_fill @ 0x20490
// ======================================================

unsigned int *__fastcall nc_masked_fill(
        unsigned int *ptr,
        int *a2,
        int a3,
        __m128 _XMM0,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // rbx
  __int64 v8; // rbp
  void (__fastcall *v9)(__int64, __int64, unsigned __int64, __int64, __int64, __int64, _QWORD, __int64 *, __int64, _QWORD, _QWORD, __int64); // r10
  __int64 v10; // r12
  __int64 v14; // r12
  int v15; // esi
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rcx
  unsigned int *v19; // rbp
  __int64 v20; // rsi
  __int64 v21; // r14
  __int64 v22; // rax
  int v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rsi
  int v30; // edx
  __int64 v31; // r9
  __int64 v32; // rdi
  __int64 v33; // rcx
  __int64 v34; // r11
  __int64 v35; // r15
  unsigned __int64 v36; // rdx
  unsigned __int64 v37; // rdx
  int v38; // eax
  int v39; // esi
  __int64 *v40; // rcx
  __int64 v41; // rdx
  char *v42; // rdi
  __int64 v43; // rsi
  __int64 v44; // rax
  __int64 v45; // rdx
  _QWORD *v46; // rax
  _QWORD *v47; // r12
  _QWORD *v48; // rax
  int v50; // ecx
  __int64 v51; // rax
  int v52; // edx
  int v53; // edx
  int v54; // edx
  int v55; // eax
  int v56; // esi
  __int64 *v57; // rcx
  __int64 v58; // rdx
  char *v59; // rdi
  __int64 v60; // rsi
  __int64 v61; // rax
  __int64 v62; // rdx
  __int64 v63; // [rsp+0h] [rbp-88h]
  __int64 v64; // [rsp+8h] [rbp-80h]
  __int64 *v65; // [rsp+8h] [rbp-80h]
  __int64 v66; // [rsp+10h] [rbp-78h]
  __int64 *v67; // [rsp+18h] [rbp-70h]
  __int64 v68; // [rsp+20h] [rbp-68h] BYREF
  __int64 v69; // [rsp+28h] [rbp-60h] BYREF
  __int64 v70; // [rsp+30h] [rbp-58h] BYREF
  __int64 v71; // [rsp+38h] [rbp-50h]
  __int64 v72; // [rsp+40h] [rbp-48h]
  __int64 v73; // [rsp+48h] [rbp-40h]
  __int64 v74; // [rsp+50h] [rbp-38h]
  __int64 v75; // [rsp+58h] [rbp-30h]
  __int64 v76; // [rsp+60h] [rbp-28h]
  __int64 v77; // [rsp+68h] [rbp-20h]

  __asm { vmovd   r15d, xmm0 }
  v77 = v10;
  v76 = v8;
  v75 = v7;
  LODWORD(v63) = a3;
  v14 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( v14 != *(_QWORD *)(*((_QWORD *)a2 + 5) + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( ptr[12] > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_masked_fill");
  if ( a2[12] != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_masked_fill");
  v15 = a2[20];
  v16 = ptr[20];
  if ( v15 > (int)v16 )
    __assert_fail("mask->n_dims <= x->n_dims", "libnc.c", 0x17EDu, "nc_masked_fill");
  if ( v15 > 0 )
  {
    if ( *((_QWORD *)a2 + 15) != *((_QWORD *)ptr + 15) )
LABEL_125:
      __assert_fail("mask->dims[i] == x->dims[i]", "libnc.c", 0x17EFu, "nc_masked_fill");
    v17 = 1LL;
    while ( v15 > (int)v17 )
    {
      v18 = *(_QWORD *)&a2[2 * v17++ + 30];
      if ( v18 != *(_QWORD *)&ptr[2 * v17 + 28] )
        goto LABEL_125;
    }
  }
  v19 = ptr;
  v20 = ptr[12];
  v21 = (unsigned int)dword_30520[v20];
  if ( ptr[4] != 1 )
  {
    v22 = nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), v20, v16, ptr + 30);
    LODWORD(v20) = ptr[12];
    v19 = (unsigned int *)v22;
  }
  if ( (_DWORD)v20 )
  {
    if ( (_DWORD)v20 != 1 )
      abort();
    _R15D = (_R15D + (HIWORD(_R15D) & 1) + 0x7FFF) >> 16;
  }
  v23 = v19[20];
  v24 = a2[20];
  HIDWORD(v63) = _R15D;
  if ( v23 != v24 )
  {
    if ( !*((_BYTE *)a2 + 72) )
      __assert_fail("mask->is_contiguous", "libnc.c", 0x1802u, "nc_masked_fill");
    if ( v24 <= 0 )
    {
      v25 = sub_7F90(
              (_DWORD *)&v68 + 1,
              v24,
              (__int64)v19,
              (__int64)ptr,
              0LL,
              a7,
              v63,
              1LL,
              v66,
              (__int64)v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77);
      goto LABEL_34;
    }
    if ( *((_BYTE *)ptr + 73) )
    {
      if ( !*((_BYTE *)v19 + 73) )
        goto LABEL_126;
      v64 = *((_QWORD *)a2 + 15);
      if ( v24 == 1 )
        goto LABEL_33;
      if ( !*((_BYTE *)ptr + 74) )
        goto LABEL_127;
      if ( !*((_BYTE *)v19 + 74) )
        goto LABEL_126;
      v64 = *((_QWORD *)a2 + 16) * *((_QWORD *)a2 + 15);
      if ( v24 == 2 )
        goto LABEL_33;
      if ( !*((_BYTE *)ptr + 75) )
        goto LABEL_127;
      if ( !*((_BYTE *)v19 + 75) )
        goto LABEL_126;
      v64 = *((_QWORD *)a2 + 17) * *((_QWORD *)a2 + 16) * *((_QWORD *)a2 + 15);
      if ( v24 == 3 )
      {
LABEL_33:
        v25 = sub_7F90(
                (_DWORD *)&v68 + 1,
                v24,
                (__int64)v19,
                (__int64)ptr,
                0LL,
                a7,
                v63,
                v64,
                v66,
                (__int64)v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77);
LABEL_34:
        v26 = ptr[20];
        v70 = 0LL;
        v66 = v25;
        if ( v26 <= 1 )
        {
          v28 = 0LL;
        }
        else
        {
          v27 = 1LL;
          do
            *(&v70 + v27++) = 0LL;
          while ( v26 > (int)v27 );
          v28 = v70;
        }
        v67 = &v70;
        goto LABEL_39;
      }
      if ( *((_BYTE *)ptr + 76) )
      {
        if ( *((_BYTE *)v19 + 76) )
        {
          v64 = *((_QWORD *)a2 + 18) * *((_QWORD *)a2 + 17) * *((_QWORD *)a2 + 16) * *((_QWORD *)a2 + 15);
          goto LABEL_33;
        }
LABEL_126:
        __assert_fail("y->contig[i]", "libnc.c", 0x1806u, "nc_masked_fill");
      }
    }
LABEL_127:
    __assert_fail("x->contig[i]", "libnc.c", 0x1805u, "nc_masked_fill");
  }
  if ( v23 > 0 && *((_BYTE *)v19 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)a2 + 73) )
  {
    v35 = *((_QWORD *)v19 + 15);
    if ( v23 != 1 )
    {
      if ( *((_BYTE *)v19 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) )
      {
        v35 *= *((_QWORD *)v19 + 16);
        if ( v23 != 2 )
        {
          if ( *((_BYTE *)v19 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) )
          {
            v35 *= *((_QWORD *)v19 + 17);
            if ( v23 != 3 )
            {
              if ( *((_BYTE *)v19 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) )
              {
                v35 *= *((_QWORD *)v19 + 18);
                v23 = 4;
              }
              else
              {
                v23 = 3;
              }
            }
          }
          else
          {
            v23 = 2;
          }
        }
      }
      else
      {
        v23 = 1;
      }
    }
    v35 = (int)v35;
  }
  else
  {
    v35 = 1LL;
    v23 = 0;
  }
  v50 = ptr[20];
  HIDWORD(v68) = v23;
  v70 = 0LL;
  if ( v50 <= 1 )
  {
    v28 = 0LL;
  }
  else
  {
    v51 = 1LL;
    do
      *(&v70 + v51++) = 0LL;
    while ( v50 > (int)v51 );
    v28 = v70;
  }
  v65 = &v70;
  while ( v28 != -1 )
  {
    v52 = a2[20];
    v34 = *(_QWORD *)(v14 + 336);
    v29 = *((_QWORD *)a2 + 7);
    if ( v52 <= 0 )
    {
      v31 = 0LL;
    }
    else
    {
      v31 = *((_QWORD *)a2 + 11) * v28;
      if ( v52 != 1 )
      {
        v31 += *((_QWORD *)a2 + 12) * v71;
        if ( v52 != 2 )
        {
          v31 += *((_QWORD *)a2 + 13) * v72;
          if ( v52 != 3 )
          {
            v33 = v73;
            v32 = *((_QWORD *)a2 + 14);
            if ( v52 != 4 )
              goto LABEL_45;
            v31 += v32 * v73;
          }
        }
      }
    }
    v53 = ptr[20];
    v31 += v29;
    v29 = *((_QWORD *)ptr + 7);
    if ( v53 <= 0 )
    {
      v33 = 0LL;
    }
    else
    {
      v33 = *((_QWORD *)ptr + 11) * v28;
      if ( v53 != 1 )
      {
        v33 += *((_QWORD *)ptr + 12) * v71;
        if ( v53 != 2 )
        {
          v33 += *((_QWORD *)ptr + 13) * v72;
          if ( v53 != 3 )
          {
            v32 = v73;
            a6 = *((_QWORD *)ptr + 14);
            if ( v53 != 4 )
              goto LABEL_45;
            v33 += a6 * v73;
          }
        }
      }
    }
    v54 = v19[20];
    v33 += v29;
    v29 = *((_QWORD *)v19 + 7);
    if ( v54 <= 0 )
    {
      v28 = 0LL;
    }
    else
    {
      v28 *= *((_QWORD *)v19 + 11);
      if ( v54 != 1 )
      {
        v28 += *((_QWORD *)v19 + 12) * v71;
        if ( v54 != 2 )
        {
          v28 += *((_QWORD *)v19 + 13) * v72;
          if ( v54 != 3 )
          {
            v32 = v73;
            a6 = *((_QWORD *)v19 + 14);
            if ( v54 != 4 )
            {
LABEL_45:
              v33 += v35 * v34;
              while ( 1 )
              {
                v36 = *(_QWORD *)&v19[2 * v29 + 22];
                v33 += v32;
                v32 = v19[20];
                v29 = *((_QWORD *)v19 + 7);
                v37 = v36 >> v21;
                if ( (int)v32 <= 0 )
                {
                  v28 = 0LL;
                }
                else
                {
                  v28 *= *((_QWORD *)v19 + 11);
                  if ( (_DWORD)v32 != 1 )
                  {
                    v28 += *((_QWORD *)v19 + 12) * v71;
                    if ( (_DWORD)v32 != 2 )
                    {
                      v28 += *((_QWORD *)v19 + 13) * v72;
                      if ( (_DWORD)v32 != 3 )
                      {
                        v34 = v73;
                        v35 = *((_QWORD *)v19 + 14);
                        if ( (_DWORD)v32 != 4 )
                          goto LABEL_45;
                        v28 += v35 * v73;
                      }
                    }
                  }
                }
                v9(v14, v28 + v29, v37, v33, a6, v31, 0LL, v65, v66, HIDWORD(v63), (unsigned int)v63, v21);
                v38 = HIDWORD(v68);
                v39 = ptr[20];
                if ( SHIDWORD(v68) >= v39 )
                  goto LABEL_57;
                v40 = &v67[SHIDWORD(v68)];
                v41 = *v40 + 1;
                *v40 = v41;
                if ( *(_QWORD *)&ptr[2 * v38 + 30] == v41 )
                {
                  v42 = (char *)&ptr[2 * v38 + 2];
                  v43 = (unsigned int)(~v38 + v39);
                  v44 = 0LL;
                  do
                  {
                    v40[v44] = 0LL;
                    if ( v43 == v44 )
                      goto LABEL_57;
                    v45 = v40[v44 + 1] + 1;
                    v40[++v44] = v45;
                  }
                  while ( v45 == *(_QWORD *)&v42[8 * v44 + 112] );
                }
                v28 = v70;
LABEL_39:
                if ( v28 == -1 )
                  goto LABEL_58;
                v29 = a2[20];
                v30 = ptr[20];
                v9 = *(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, __int64, __int64, _QWORD, __int64 *, __int64, _QWORD, _QWORD, __int64))(v14 + 336);
                v31 = *((_QWORD *)a2 + 7);
                a6 = *(_QWORD *)&ptr[2 * v29 + 22] >> v21;
                v32 = *((_QWORD *)ptr + 7);
                if ( v30 <= 0 )
                {
                  v33 = 0LL;
                }
                else
                {
                  v33 = *((_QWORD *)ptr + 11) * v28;
                  if ( v30 != 1 )
                  {
                    v33 += *((_QWORD *)ptr + 12) * v71;
                    if ( v30 != 2 )
                    {
                      v33 += *((_QWORD *)ptr + 13) * v72;
                      if ( v30 != 3 )
                      {
                        v34 = v73;
                        v35 = *((_QWORD *)ptr + 14);
                        goto LABEL_45;
                      }
                    }
                  }
                }
              }
            }
            v28 += a6 * v73;
          }
        }
      }
    }
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, __int64))v34)(
      v14,
      v28 + v29,
      0LL,
      v33,
      0LL,
      v31,
      0LL,
      v35,
      1LL,
      HIDWORD(v63),
      (unsigned int)v63,
      v21);
    v55 = HIDWORD(v68);
    v56 = ptr[20];
    if ( SHIDWORD(v68) >= v56 )
      goto LABEL_57;
    v57 = &v70 + SHIDWORD(v68);
    v58 = *v57 + 1;
    *v57 = v58;
    if ( v58 == *(_QWORD *)&ptr[2 * v55 + 30] )
    {
      v59 = (char *)&ptr[2 * v55 + 2];
      v60 = (unsigned int)(~v55 + v56);
      v61 = 0LL;
      while ( 1 )
      {
        v57[v61] = 0LL;
        if ( v61 == v60 )
          break;
        v62 = v57[v61 + 1] + 1;
        v57[++v61] = v62;
        if ( v62 != *(_QWORD *)&v59[8 * v61 + 112] )
          goto LABEL_114;
      }
LABEL_57:
      v70 = -1LL;
      break;
    }
LABEL_114:
    v28 = v70;
  }
LABEL_58:
  v69 = (__int64)ptr;
  v46 = sub_17800(28, (__int64 *)v19 + 3, (void **)v19 + 4, (__int64)&v69);
  v47 = v46;
  if ( v46 )
  {
    *((_DWORD *)v46 + 10) = 1;
    v48 = (_QWORD *)nc_malloc(8uLL);
    v47[6] = v48;
    *v48 = nc_dup_tensor(a2);
    *((_DWORD *)v47 + 14) = v63;
  }
  if ( v19 != ptr )
    nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v19;
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

