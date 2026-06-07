// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_soft_max_bw
// Included functions: 3

// ======================================================
// Function: nc_soft_max_bw @ 0x23450
// ======================================================

unsigned int *__fastcall nc_soft_max_bw(unsigned int *ptr, _QWORD *a2)
{
  unsigned int v4; // eax
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rcx
  unsigned int *v8; // rbp
  int v9; // eax
  int v10; // edx
  __int64 v11; // rax
  __int64 v12; // rax
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // r9
  __int64 v16; // rsi
  __int64 v17; // rdi
  int v18; // edx
  int v19; // eax
  int v20; // esi
  __int64 *v21; // rcx
  __int64 v22; // rdx
  char *v23; // rdi
  __int64 v24; // rsi
  __int64 v25; // rax
  __int64 v26; // rdx
  __int64 v28; // [rsp+0h] [rbp-98h]
  __int64 v29; // [rsp+0h] [rbp-98h]
  __int64 v30; // [rsp+8h] [rbp-90h]
  __int64 v31; // [rsp+10h] [rbp-88h]
  __int64 v32; // [rsp+10h] [rbp-88h]
  __int64 v33; // [rsp+18h] [rbp-80h]
  __int64 v34; // [rsp+20h] [rbp-78h]
  __int64 v35; // [rsp+28h] [rbp-70h] BYREF
  __int64 v36; // [rsp+30h] [rbp-68h] BYREF
  __int64 v37; // [rsp+38h] [rbp-60h]
  __int64 v38; // [rsp+40h] [rbp-58h] BYREF
  __int64 v39; // [rsp+48h] [rbp-50h]
  __int64 v40; // [rsp+50h] [rbp-48h]
  __int64 v41; // [rsp+58h] [rbp-40h]
  __int64 v42; // [rsp+60h] [rbp-38h]
  __int64 v43; // [rsp+68h] [rbp-30h]

  v28 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( v28 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v4 = ptr[12];
  if ( v4 > 1 || v4 != *((_DWORD *)a2 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_soft_max_bw");
  v5 = ptr[20];
  if ( (_DWORD)v5 != *((_DWORD *)a2 + 20) )
    goto LABEL_5;
  if ( (int)v5 <= 0 )
    __assert_fail("yg1->n_dims >= 1", "libnc.c", 0x1B01u, "nc_soft_max_bw");
  if ( a2[15] != *((_QWORD *)ptr + 15) )
LABEL_5:
    __assert_fail("same_dims(yg1, yd1)", "libnc.c", 0x1B00u, "nc_soft_max_bw");
  v6 = 1LL;
  while ( (int)v5 > (int)v6 )
  {
    v7 = *(_QWORD *)&ptr[2 * v6++ + 30];
    if ( v7 != a2[v6 + 14] )
      goto LABEL_5;
  }
  if ( !*((_BYTE *)ptr + 73) )
    __assert_fail("yg1->contig[0]", "libnc.c", 0x1B02u, "nc_soft_max_bw");
  if ( !*((_BYTE *)a2 + 73) )
    __assert_fail("yd1->contig[0]", "libnc.c", 0x1B03u, "nc_soft_max_bw");
  v8 = ptr;
  if ( ptr[4] != 1 )
    v8 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], v5, ptr + 30);
  v9 = sub_7F90(
         (_DWORD *)&v35 + 1,
         1,
         (__int64)v8,
         (__int64)ptr,
         (__int64)a2,
         0LL,
         v28,
         v30,
         v31,
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
         v43);
  v10 = ptr[20];
  v38 = 0LL;
  v32 = v9;
  if ( v10 <= 1 )
  {
    v12 = 0LL;
  }
  else
  {
    v11 = 1LL;
    do
      *(&v38 + v11++) = 0LL;
    while ( v10 > (int)v11 );
    v12 = v38;
  }
LABEL_21:
  if ( v12 != -1 )
  {
    v13 = *((_DWORD *)a2 + 20);
    v14 = a2[7];
    if ( v13 <= 0 )
    {
      v15 = 0LL;
    }
    else
    {
      v15 = a2[11] * v12;
      if ( v13 != 1 )
      {
        v15 += a2[12] * v39;
        if ( v13 != 2 )
        {
          v15 += a2[13] * v40;
          if ( v13 != 3 )
          {
            v16 = v41;
            v17 = a2[14];
            goto LABEL_27;
          }
        }
      }
    }
    while ( 1 )
    {
      v18 = ptr[20];
      v15 += v14;
      v16 = *((_QWORD *)ptr + 7);
      if ( v18 <= 0 )
      {
        v14 = 0LL;
      }
      else
      {
        v14 = *((_QWORD *)ptr + 11) * v12;
        if ( v18 != 1 )
        {
          v14 += *((_QWORD *)ptr + 12) * v39;
          if ( v18 != 2 )
          {
            v14 += *((_QWORD *)ptr + 13) * v40;
            if ( v18 != 3 )
            {
              v17 = v41;
              if ( v18 != 4 )
                goto LABEL_27;
              v14 += *((_QWORD *)ptr + 14) * v41;
            }
          }
        }
      }
      v17 = v8[20];
      v14 += v16;
      if ( (int)v17 <= 0 )
      {
        v12 = 0LL;
LABEL_40:
        (*(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, _QWORD, __int64, _QWORD))(v29 + 400))(
          v29,
          *((_QWORD *)v8 + 7) + v12,
          *((_QWORD *)v8 + 8),
          v14,
          *((_QWORD *)ptr + 8),
          v15,
          a2[8],
          *((_QWORD *)v8 + 15),
          v32,
          ptr[12]);
        v19 = HIDWORD(v35);
        v20 = ptr[20];
        if ( SHIDWORD(v35) >= v20 )
        {
LABEL_45:
          v38 = -1LL;
          break;
        }
        v21 = &v38 + SHIDWORD(v35);
        v22 = *v21 + 1;
        *v21 = v22;
        if ( *(_QWORD *)&ptr[2 * v19 + 30] == v22 )
        {
          v23 = (char *)&ptr[2 * v19 + 2];
          v24 = (unsigned int)(~v19 + v20);
          v25 = 0LL;
          do
          {
            v21[v25] = 0LL;
            if ( v24 == v25 )
              goto LABEL_45;
            v26 = v21[v25 + 1] + 1;
            v21[++v25] = v26;
          }
          while ( v26 == *(_QWORD *)&v23[8 * v25 + 112] );
        }
        v12 = v38;
        goto LABEL_21;
      }
      v12 *= *((_QWORD *)v8 + 11);
      if ( (_DWORD)v17 == 1 )
        goto LABEL_40;
      v12 += *((_QWORD *)v8 + 12) * v39;
      if ( (_DWORD)v17 == 2 )
        goto LABEL_40;
      v12 += *((_QWORD *)v8 + 13) * v40;
      if ( (_DWORD)v17 == 3 )
        goto LABEL_40;
      v16 = *((_QWORD *)v8 + 14);
      if ( (_DWORD)v17 == 4 )
      {
        v12 += v16 * v41;
        goto LABEL_40;
      }
LABEL_27:
      v15 += v17 * v16;
    }
  }
  v36 = (__int64)ptr;
  v37 = (__int64)a2;
  sub_17590(0, (__int64 *)v8 + 3, (void **)v8 + 4, &v36);
  if ( v8 != ptr )
    nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v8;
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
// Function: sub_17590 @ 0x17590
// ======================================================

_QWORD *__fastcall sub_17590(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  __int64 *v7; // rax
  __int64 v8; // r12
  __int64 *v9; // rbp
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  _QWORD *v14; // r14
  __int64 v15; // rax
  __int64 v16; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(0x10uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*a4 + 32LL);
  v7[1] = *(_QWORD *)(a4[1] + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 2;
  v12 = (_QWORD *)nc_malloc(0x10uLL);
  v13 = *v9;
  v14 = v12;
  v11[4] = v12;
  if ( !v13 )
  {
    *v12 = 0LL;
    if ( v9[1] )
      goto LABEL_6;
LABEL_11:
    v14[1] = 0LL;
    goto LABEL_7;
  }
  *v12 = nc_dup_node();
  v14 = (_QWORD *)v11[4];
  if ( !v9[1] )
    goto LABEL_11;
LABEL_6:
  v14[1] = nc_dup_node();
LABEL_7:
  v15 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v15 + 1;
  v11[12] = v15;
  v16 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v16 + 8) = v11;
  *v11 = v16;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

