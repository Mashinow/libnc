// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_soft_max
// Included functions: 3

// ======================================================
// Function: nc_soft_max @ 0x23860
// ======================================================

unsigned int *__fastcall nc_soft_max(unsigned int *ptr, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // rbp
  __int64 v8; // rdx
  unsigned int *v9; // r13
  int v10; // eax
  int v11; // edx
  __int64 v12; // r12
  __int64 v13; // rax
  __int64 v14; // rax
  int v15; // edx
  __int64 v16; // rdi
  __int64 v17; // rcx
  __int64 v18; // rsi
  __int64 v19; // r14
  int v20; // eax
  int v21; // esi
  __int64 *v22; // rcx
  __int64 v23; // rdx
  char *v24; // rdi
  __int64 v25; // rsi
  __int64 v26; // rax
  __int64 v27; // rdx
  _QWORD *v28; // rax
  _QWORD *v29; // rbp
  _QWORD *v30; // rax
  __int64 v32; // [rsp+0h] [rbp-78h]
  __int64 v33; // [rsp+8h] [rbp-70h]
  __int64 v34; // [rsp+10h] [rbp-68h] BYREF
  __int64 v35; // [rsp+18h] [rbp-60h] BYREF
  __int64 v36; // [rsp+20h] [rbp-58h] BYREF
  __int64 v37; // [rsp+28h] [rbp-50h]
  __int64 v38; // [rsp+30h] [rbp-48h]
  __int64 v39; // [rsp+38h] [rbp-40h]
  __int64 v40; // [rsp+40h] [rbp-38h]
  __int64 v41; // [rsp+48h] [rbp-30h]
  __int64 v42; // [rsp+50h] [rbp-28h]
  __int64 v43; // [rsp+58h] [rbp-20h]
  __int64 v44; // [rsp+60h] [rbp-18h]
  __int64 v45; // [rsp+68h] [rbp-10h]

  v7 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( ptr[12] > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_soft_max");
  v8 = ptr[20];
  if ( (int)v8 <= 0 )
    __assert_fail("x->n_dims >= 1", "libnc.c", 0x1B27u, "nc_soft_max");
  if ( !*((_BYTE *)ptr + 73) )
    __assert_fail("x->contig[0]", "libnc.c", 0x1B28u, "nc_soft_max");
  v9 = ptr;
  if ( ptr[4] != 1 )
    v9 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], v8, ptr + 30);
  v10 = sub_7F90(
          (_DWORD *)&v34 + 1,
          1,
          (__int64)v9,
          (__int64)ptr,
          0LL,
          a6,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45);
  v11 = ptr[20];
  v36 = 0LL;
  v12 = v10;
  if ( v11 <= 1 )
  {
    v14 = 0LL;
  }
  else
  {
    v13 = 1LL;
    do
      *(&v36 + v13++) = 0LL;
    while ( v11 > (int)v13 );
    v14 = v36;
  }
  while ( v14 != -1 )
  {
    v15 = ptr[20];
    v16 = *((_QWORD *)ptr + 7);
    if ( v15 <= 0 )
    {
      v17 = 0LL;
    }
    else
    {
      v17 = *((_QWORD *)ptr + 11) * v14;
      if ( v15 != 1 )
      {
        v17 += *((_QWORD *)ptr + 12) * v37;
        if ( v15 != 2 )
        {
          v17 += *((_QWORD *)ptr + 13) * v38;
          if ( v15 != 3 )
          {
            v18 = v39;
            v19 = *((_QWORD *)ptr + 14);
            goto LABEL_17;
          }
        }
      }
    }
    while ( 1 )
    {
      v17 += v16;
      v16 = v9[20];
      v19 = *((_QWORD *)v9 + 7);
      if ( (int)v16 <= 0 )
        break;
      v14 *= *((_QWORD *)v9 + 11);
      if ( (_DWORD)v16 == 1 )
        goto LABEL_24;
      v14 += *((_QWORD *)v9 + 12) * v37;
      if ( (_DWORD)v16 == 2 )
        goto LABEL_24;
      v14 += *((_QWORD *)v9 + 13) * v38;
      if ( (_DWORD)v16 == 3 )
        goto LABEL_24;
      v18 = v39;
      if ( (_DWORD)v16 == 4 )
      {
        v14 += *((_QWORD *)v9 + 14) * v39;
        goto LABEL_24;
      }
LABEL_17:
      v17 += v19 * v18;
    }
    v14 = 0LL;
LABEL_24:
    (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD, __int64, _QWORD))(v7 + 392))(
      v7,
      v19 + v14,
      *((_QWORD *)v9 + 8),
      v17,
      *((_QWORD *)ptr + 8),
      *((_QWORD *)ptr + 15),
      v12,
      ptr[12]);
    v20 = HIDWORD(v34);
    v21 = ptr[20];
    if ( SHIDWORD(v34) >= v21 )
      goto LABEL_29;
    v22 = &v36 + SHIDWORD(v34);
    v23 = *v22 + 1;
    *v22 = v23;
    if ( *(_QWORD *)&ptr[2 * v20 + 30] == v23 )
    {
      v24 = (char *)&ptr[2 * v20 + 2];
      v25 = (unsigned int)(~v20 + v21);
      v26 = 0LL;
      while ( 1 )
      {
        v22[v26] = 0LL;
        if ( v25 == v26 )
          break;
        v27 = v22[v26 + 1] + 1;
        v22[++v26] = v27;
        if ( v27 != *(_QWORD *)&v24[8 * v26 + 112] )
          goto LABEL_35;
      }
LABEL_29:
      v36 = -1LL;
      break;
    }
LABEL_35:
    v14 = v36;
  }
  v35 = (__int64)ptr;
  v28 = sub_17800(18, (__int64 *)v9 + 3, (void **)v9 + 4, (__int64)&v35);
  v29 = v28;
  if ( v28 )
  {
    *((_DWORD *)v28 + 10) = 1;
    v30 = (_QWORD *)nc_malloc(8uLL);
    v29[6] = v30;
    *v30 = nc_dup_tensor(v9);
  }
  if ( v9 != ptr )
    nc_free_tensor(ptr);
  return v9;
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

