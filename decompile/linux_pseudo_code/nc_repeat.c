// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_repeat
// Included functions: 3

// ======================================================
// Function: nc_repeat @ 0x1BED0
// ======================================================

__int64 __fastcall nc_repeat(_QWORD *ptr, int a2, __int64 *a3)
{
  __int64 v3; // rbx
  __int64 v4; // rbp
  __int64 *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  int v10; // esi
  __int64 v11; // r15
  __int64 v12; // rax
  __int64 v13; // rbp
  __int64 v14; // r12
  int v15; // eax
  int v16; // ecx
  __int64 *v17; // r13
  __int64 v18; // rax
  __int64 v19; // rsi
  int v20; // edi
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // r8
  __int64 v24; // rdx
  __int64 v25; // rsi
  void (__fastcall *v26)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64); // r11
  int v27; // eax
  int v28; // esi
  __int64 *v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // rdi
  __int64 v32; // rsi
  __int64 v33; // rax
  __int64 v34; // rdx
  _QWORD *v35; // rax
  int v37; // eax
  __int64 v38; // rax
  __int64 v39; // rax
  int v40; // eax
  __int64 *v41; // rcx
  __int64 v42; // rdx
  __int64 v43; // rdi
  __int64 v44; // rsi
  __int64 v45; // rax
  __int64 v46; // rdx
  int v47; // eax
  __int64 v48; // [rsp+0h] [rbp-98h]
  __int64 *src; // [rsp+8h] [rbp-90h]
  __int64 v50; // [rsp+10h] [rbp-88h] BYREF
  __int64 v51; // [rsp+18h] [rbp-80h] BYREF
  __int64 dest[4]; // [rsp+20h] [rbp-78h] BYREF
  __int64 v53; // [rsp+40h] [rbp-58h] BYREF
  __int64 v54; // [rsp+48h] [rbp-50h]
  __int64 v55; // [rsp+50h] [rbp-48h]
  __int64 v56; // [rsp+58h] [rbp-40h]
  __int64 v57; // [rsp+60h] [rbp-38h]
  __int64 v58; // [rsp+68h] [rbp-30h]

  v3 = *(_QWORD *)(ptr[5] + 24LL);
  if ( a2 <= 0 )
    __assert_fail("n_dims >= 1", "libnc.c", 0x15EBu, "nc_repeat");
  v4 = *((int *)ptr + 20);
  if ( a2 + (int)v4 > 4 )
    __assert_fail("n_dims1 <= N_DIMS_MAX", "libnc.c", 0x15EDu, "nc_repeat");
  v6 = a3;
  if ( (int)v4 > 0 )
  {
    src = a3;
    memcpy(dest, ptr + 15, 8LL * (unsigned int)(v4 - 1) + 8);
    v6 = src;
  }
  memcpy(&dest[v4], v6, 8LL * (unsigned int)(a2 - 1) + 8);
  v7 = nc_new_tensor_nz(v3, *((unsigned int *)ptr + 12), (unsigned int)(a2 + v4), dest);
  v10 = *((_DWORD *)ptr + 20);
  v11 = v7;
  v12 = *((unsigned int *)ptr + 12);
  v13 = (unsigned int)dword_30520[v12];
  if ( nc_type_size_table[v12] != 4LL || v10 )
  {
    if ( !*((_BYTE *)ptr + 72) )
      __assert_fail("x->is_contiguous", "libnc.c", 0x15FEu, "nc_repeat");
    if ( v10 <= 0 )
    {
      v14 = 1LL;
    }
    else
    {
      v14 = ptr[15];
      if ( !*(_BYTE *)(v11 + 73)
        || v10 != 1
        && ((v14 *= ptr[16], !*(_BYTE *)(v11 + 74))
         || v10 != 2 && ((v14 *= ptr[17], !*(_BYTE *)(v11 + 75)) || v10 != 3 && (v14 *= ptr[18], !*(_BYTE *)(v11 + 76)))) )
      {
        __assert_fail("y->contig[i]", "libnc.c", 0x1602u, "nc_repeat");
      }
    }
    v15 = sub_7F90(
            (_DWORD *)&v50 + 1,
            v10,
            v11,
            0LL,
            v8,
            v9,
            v48,
            (__int64)src,
            v50,
            v51,
            dest[0],
            dest[1],
            dest[2],
            dest[3],
            v53,
            v54,
            v55,
            v56,
            v57,
            v58);
    v16 = *(_DWORD *)(v11 + 80);
    v53 = 0LL;
    v17 = (__int64 *)v15;
    if ( v16 <= 1 )
    {
      v19 = 0LL;
    }
    else
    {
      v18 = 1LL;
      do
        *(&v53 + v18++) = 0LL;
      while ( v16 > (int)v18 );
      v19 = v53;
    }
    src = &v53;
    while ( v19 != -1 )
    {
      v20 = *(_DWORD *)(v11 + 80);
      v21 = *(_QWORD *)(v3 + 72);
      v22 = ptr[7];
      v23 = *(_QWORD *)(v11 + 56);
      v24 = *(_QWORD *)(v11 + 8LL * *((int *)ptr + 20) + 88) >> v13;
      if ( v20 <= 0 )
      {
        v25 = 0LL;
      }
      else
      {
        v25 = *(_QWORD *)(v11 + 88) * v19;
        if ( v20 != 1 )
        {
          v25 += *(_QWORD *)(v11 + 96) * v54;
          if ( v20 != 2 )
          {
            v25 += *(_QWORD *)(v11 + 104) * v55;
            if ( v20 != 3 )
            {
              v9 = v56;
              v26 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64))(v11 + 112);
LABEL_27:
              v25 += (_QWORD)v26 * v9;
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64, __int64 *, __int64))v21)(
        v3,
        v23 + v25,
        v24,
        v22,
        0LL,
        v14,
        v17,
        v13);
      v27 = HIDWORD(v50);
      v28 = *(_DWORD *)(v11 + 80);
      if ( SHIDWORD(v50) >= v28 )
        goto LABEL_33;
      v29 = &src[SHIDWORD(v50)];
      v30 = *v29 + 1;
      *v29 = v30;
      if ( v30 == *(_QWORD *)(v11 + 8LL * v27 + 120) )
      {
        v31 = v11 + 8LL * (v27 + 1);
        v32 = (unsigned int)(~v27 + v28);
        v33 = 0LL;
        do
        {
          v29[v33] = 0LL;
          if ( v33 == v32 )
            goto LABEL_33;
          v34 = v29[v33 + 1] + 1;
          v29[++v33] = v34;
        }
        while ( v34 == *(_QWORD *)(v31 + 8 * v33 + 112) );
      }
      v19 = v53;
    }
    goto LABEL_34;
  }
  v23 = *(unsigned int *)(v11 + 80);
  if ( (int)v23 <= 0 )
  {
    HIDWORD(v50) = 0;
    v14 = 1LL;
    v39 = 0LL;
    v53 = 0LL;
    goto LABEL_53;
  }
  if ( *(_BYTE *)(v11 + 73) )
  {
    v14 = *(_QWORD *)(v11 + 120);
    if ( (_DWORD)v23 == 1 )
    {
      v37 = 1;
      goto LABEL_48;
    }
    if ( *(_BYTE *)(v11 + 74) )
    {
      v14 *= *(_QWORD *)(v11 + 128);
      if ( (_DWORD)v23 == 2 )
      {
        v37 = 2;
        goto LABEL_48;
      }
      if ( *(_BYTE *)(v11 + 75) )
      {
        v14 *= *(_QWORD *)(v11 + 136);
        if ( (_DWORD)v23 == 3 )
        {
          v37 = 3;
          goto LABEL_48;
        }
        if ( *(_BYTE *)(v11 + 76) )
        {
          v14 *= *(_QWORD *)(v11 + 144);
          v37 = 4;
LABEL_48:
          v14 = (int)v14;
          goto LABEL_49;
        }
        v47 = 3;
      }
      else
      {
        v47 = 2;
      }
    }
    else
    {
      v47 = 1;
    }
    v14 = (int)v14;
    HIDWORD(v50) = v47;
    v53 = 0LL;
    goto LABEL_50;
  }
  v14 = 1LL;
  v37 = 0;
LABEL_49:
  HIDWORD(v50) = v37;
  v53 = 0LL;
  if ( (int)v23 <= 1 )
  {
    v39 = 0LL;
    goto LABEL_53;
  }
LABEL_50:
  v38 = 1LL;
  do
    *(&v53 + v38++) = 0LL;
  while ( (int)v23 > (int)v38 );
  v39 = v53;
LABEL_53:
  v17 = &v53;
  while ( v39 != -1 )
  {
    v26 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64))(v3 + 120);
    v22 = ptr[7];
    v25 = *(_QWORD *)(v11 + 56);
    if ( (int)v23 <= 0 )
    {
      v21 = 0LL;
    }
    else
    {
      v21 = *(_QWORD *)(v11 + 88) * v39;
      if ( (_DWORD)v23 != 1 )
      {
        v21 += *(_QWORD *)(v11 + 96) * v54;
        if ( (_DWORD)v23 != 2 )
        {
          v21 += *(_QWORD *)(v11 + 104) * v55;
          if ( (_DWORD)v23 != 3 )
          {
            v24 = v56;
            if ( (_DWORD)v23 != 4 )
              goto LABEL_27;
            v21 += *(_QWORD *)(v11 + 112) * v56;
          }
        }
      }
    }
    v26(v3, v21 + v25, 0LL, v22, 0LL, v14, 1LL, v13);
    v40 = HIDWORD(v50);
    v23 = *(unsigned int *)(v11 + 80);
    if ( SHIDWORD(v50) >= (int)v23 )
      goto LABEL_33;
    v41 = &v53 + SHIDWORD(v50);
    v42 = *v41 + 1;
    *v41 = v42;
    if ( v42 == *(_QWORD *)(v11 + 8LL * v40 + 120) )
    {
      v43 = v11 + 8LL * (v40 + 1);
      v44 = (unsigned int)(~v40 + v23);
      v45 = 0LL;
      while ( 1 )
      {
        v41[v45] = 0LL;
        if ( v45 == v44 )
          break;
        v46 = v41[v45 + 1] + 1;
        v41[++v45] = v46;
        if ( v46 != *(_QWORD *)(v43 + 8 * v45 + 112) )
          goto LABEL_68;
      }
LABEL_33:
      v53 = -1LL;
      break;
    }
LABEL_68:
    v39 = v53;
  }
LABEL_34:
  v51 = (__int64)ptr;
  v35 = sub_17800(4, (__int64 *)(v11 + 24), (void **)(v11 + 32), (__int64)&v51);
  if ( v35 )
    *((_DWORD *)v35 + 14) = *((_DWORD *)ptr + 20);
  nc_free_tensor(ptr);
  return v11;
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

