// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_rel_shift
// Included functions: 4

// ======================================================
// Function: nc_rel_shift @ 0x28410
// ======================================================

__int64 __fastcall nc_rel_shift(_QWORD *ptr, __int64 a2, __int64 a3)
{
  __int64 v3; // rdx
  __int64 v5; // rbp
  __int64 v6; // r12
  __int64 v7; // r9
  int v8; // eax
  int v9; // edx
  __int64 v10; // rax
  __int64 v11; // rax
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rdi
  int v14; // edx
  unsigned __int64 v15; // r14
  unsigned __int64 v16; // r9
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // rcx
  __int64 v20; // rdi
  unsigned __int64 v21; // r11
  unsigned __int64 v22; // r10
  int v23; // eax
  int v24; // esi
  __int64 *v25; // rcx
  __int64 v26; // rdx
  char *v27; // rdi
  __int64 v28; // rsi
  __int64 v29; // rax
  __int64 v30; // rdx
  _QWORD *v31; // rax
  __int64 v33; // [rsp+0h] [rbp-98h]
  __int64 v34; // [rsp+0h] [rbp-98h]
  __int64 v35; // [rsp+8h] [rbp-90h]
  __int64 v36; // [rsp+10h] [rbp-88h]
  __int64 v38; // [rsp+18h] [rbp-80h]
  __int64 v39; // [rsp+20h] [rbp-78h]
  __int64 v40; // [rsp+20h] [rbp-78h]
  __int64 v41; // [rsp+28h] [rbp-70h]
  __int64 v42; // [rsp+30h] [rbp-68h] BYREF
  __int64 v43; // [rsp+38h] [rbp-60h] BYREF
  __int64 v44; // [rsp+40h] [rbp-58h] BYREF
  __int64 v45; // [rsp+48h] [rbp-50h]
  __int64 v46; // [rsp+50h] [rbp-48h]
  __int64 v47; // [rsp+58h] [rbp-40h]
  __int64 v48; // [rsp+60h] [rbp-38h]
  __int64 v49; // [rsp+68h] [rbp-30h]

  v33 = *(_QWORD *)(ptr[5] + 24LL);
  if ( !*((_BYTE *)ptr + 73) )
    __assert_fail("x->contig[0]", "libnc.c", 0x1DD6u, "nc_rel_shift");
  v3 = *((unsigned int *)ptr + 20);
  if ( (int)v3 <= 1 )
    sub_18270("rel_shift", (__int64)ptr, 0LL);
  v5 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v3, ptr + 15);
  v6 = (unsigned int)dword_30520[*((unsigned int *)ptr + 12)];
  v8 = sub_7F90(
         (_DWORD *)&v42 + 1,
         2,
         (__int64)ptr,
         v5,
         0LL,
         v7,
         v33,
         v35,
         a2,
         a3,
         v39,
         v41,
         v42,
         v43,
         v44,
         v45,
         v46,
         v47,
         v48,
         v49);
  v9 = *((_DWORD *)ptr + 20);
  v44 = 0LL;
  v40 = v8;
  if ( v9 <= 1 )
  {
    v11 = 0LL;
  }
  else
  {
    v10 = 1LL;
    do
      *(&v44 + v10++) = 0LL;
    while ( v9 > (int)v10 );
    v11 = v44;
  }
  while ( v11 != -1 )
  {
    v12 = ptr[13];
    v13 = ptr[12];
    v14 = *((_DWORD *)ptr + 20);
    v15 = v12 >> v6;
    v16 = v13 >> v6;
    v17 = ptr[7];
    if ( v14 <= 0 )
    {
      v18 = 0LL;
    }
    else
    {
      v18 = ptr[11] * v11;
      if ( v14 != 1 )
      {
        v18 += v45 * v13;
        if ( v14 != 2 )
        {
          v18 += v46 * v12;
          if ( v14 != 3 )
          {
            v19 = v47;
            v20 = ptr[14];
            goto LABEL_13;
          }
        }
      }
    }
    while ( 1 )
    {
      v18 += v17;
      v21 = *(_QWORD *)(v5 + 96);
      v22 = *(_QWORD *)(v5 + 104);
      v20 = *(unsigned int *)(v5 + 80);
      v19 = v22 >> v6;
      if ( (int)v20 <= 0 )
        break;
      v11 *= *(_QWORD *)(v5 + 88);
      if ( (_DWORD)v20 == 1 )
        goto LABEL_20;
      v11 += v45 * v21;
      if ( (_DWORD)v20 == 2 )
        goto LABEL_20;
      v11 += v46 * v22;
      if ( (_DWORD)v20 == 3 )
        goto LABEL_20;
      v17 = v47;
      if ( (_DWORD)v20 == 4 )
      {
        v11 += *(_QWORD *)(v5 + 112) * v47;
        goto LABEL_20;
      }
LABEL_13:
      v18 += v20 * v19;
    }
    v11 = 0LL;
LABEL_20:
    (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64))(v34 + 464))(
      v34,
      *(_QWORD *)(v5 + 56) + v11,
      v21 >> v6,
      v19,
      v18,
      v16,
      v15,
      ptr[15],
      ptr[16],
      v40,
      v36,
      v38,
      v6);
    v23 = HIDWORD(v42);
    v24 = *((_DWORD *)ptr + 20);
    if ( SHIDWORD(v42) >= v24 )
      goto LABEL_25;
    v25 = &v44 + SHIDWORD(v42);
    v26 = *v25 + 1;
    *v25 = v26;
    if ( v26 == ptr[v23 + 15] )
    {
      v27 = (char *)&ptr[v23 + 1];
      v28 = (unsigned int)(~v23 + v24);
      v29 = 0LL;
      while ( 1 )
      {
        v25[v29] = 0LL;
        if ( v28 == v29 )
          break;
        v30 = v25[v29 + 1] + 1;
        v25[++v29] = v30;
        if ( v30 != *(_QWORD *)&v27[8 * v29 + 112] )
          goto LABEL_31;
      }
LABEL_25:
      v44 = -1LL;
      break;
    }
LABEL_31:
    v11 = v44;
  }
  v43 = (__int64)ptr;
  v31 = sub_17800(36, (__int64 *)(v5 + 24), (void **)(v5 + 32), (__int64)&v43);
  if ( v31 )
  {
    v31[7] = v36;
    v31[8] = v38;
  }
  if ( ptr != (_QWORD *)v5 )
    nc_free_tensor(ptr);
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

