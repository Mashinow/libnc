// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_add
// Included functions: 4

// ======================================================
// Function: nc_add @ 0x1D110
// ======================================================

__int64 __fastcall nc_add(_QWORD *ptr, _DWORD *a2)
{
  __int64 v4; // rax
  __int64 v5; // rsi
  __int64 v6; // r15
  __int64 v7; // rax
  __int64 v8; // r9
  __int64 v9; // rbx
  int v11; // r13d
  int v12; // edx
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned __int64 v15; // rdi
  int v16; // edx
  unsigned __int64 v17; // r8
  __int64 v18; // rsi
  __int64 v19; // rcx
  __int64 v20; // rdi
  __int64 v21; // r11
  unsigned __int64 v22; // r14
  int v23; // eax
  int v24; // esi
  __int64 *v25; // rcx
  __int64 v26; // rdx
  __int64 v27; // rdi
  __int64 v28; // rsi
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // [rsp+0h] [rbp-98h]
  __int64 v32; // [rsp+8h] [rbp-90h]
  __int64 v33; // [rsp+10h] [rbp-88h]
  __int64 v34; // [rsp+10h] [rbp-88h]
  __int64 v35; // [rsp+18h] [rbp-80h]
  __int64 v36; // [rsp+20h] [rbp-78h]
  __int64 v37; // [rsp+28h] [rbp-70h] BYREF
  __int64 v38; // [rsp+30h] [rbp-68h] BYREF
  __int64 v39; // [rsp+38h] [rbp-60h]
  __int64 v40; // [rsp+40h] [rbp-58h] BYREF
  __int64 v41; // [rsp+48h] [rbp-50h]
  __int64 v42; // [rsp+50h] [rbp-48h]
  __int64 v43; // [rsp+58h] [rbp-40h]
  __int64 v44; // [rsp+60h] [rbp-38h]
  __int64 v45; // [rsp+68h] [rbp-30h]

  v4 = ptr[5];
  v5 = *((unsigned int *)ptr + 12);
  v6 = *(_QWORD *)(v4 + 24);
  if ( a2[12] != (_DWORD)v5 || (unsigned int)v5 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_add");
  v7 = nc_new_tensor_nz(*(_QWORD *)(v4 + 24), v5, *((unsigned int *)ptr + 20), ptr + 15);
  v9 = v7;
  if ( a2[20] == 1 && *((int *)ptr + 20) > 1 )
  {
    if ( v6 != *(_QWORD *)(*((_QWORD *)a2 + 5) + 24LL) )
      nc_error("all operation tensors must be on the same device", v5);
    if ( ptr[15] != *((_QWORD *)a2 + 15) )
      __assert_fail("x1->dims[0] == x2->dims[0]", "libnc.c", 0x16C7u, "nc_add");
    if ( !*((_BYTE *)ptr + 73) || !*((_BYTE *)a2 + 73) )
      __assert_fail("x1->contig[0] && x2->contig[0]", "libnc.c", 0x16C8u, "nc_add");
    v34 = (int)sub_7F90(
                 (_DWORD *)&v37 + 1,
                 1,
                 v7,
                 (__int64)ptr,
                 0LL,
                 v8,
                 v31,
                 v32,
                 v33,
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
    v11 = dword_30520[*((unsigned int *)ptr + 12)];
    v12 = *(_DWORD *)(v9 + 80);
    v40 = 0LL;
    if ( v12 <= 1 )
    {
      v14 = 0LL;
    }
    else
    {
      v13 = 1LL;
      do
        *(&v40 + v13++) = 0LL;
      while ( v12 > (int)v13 );
      v14 = v40;
    }
    while ( v14 != -1 )
    {
      v15 = ptr[12];
      v16 = *((_DWORD *)ptr + 20);
      v17 = v15 >> v11;
      v18 = ptr[7];
      if ( v16 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = ptr[11] * v14;
        if ( v16 != 1 )
        {
          v19 += v41 * v15;
          if ( v16 != 2 )
          {
            v19 += ptr[13] * v42;
            if ( v16 != 3 )
            {
              v20 = v43;
              v21 = ptr[14];
              goto LABEL_25;
            }
          }
        }
      }
      while ( 1 )
      {
        v22 = *(_QWORD *)(v9 + 96);
        v20 = *(unsigned int *)(v9 + 80);
        v19 += v18;
        v21 = *(_QWORD *)(v9 + 56);
        if ( (int)v20 <= 0 )
          break;
        v14 *= *(_QWORD *)(v9 + 88);
        if ( (_DWORD)v20 == 1 )
          goto LABEL_32;
        v14 += v41 * v22;
        if ( (_DWORD)v20 == 2 )
          goto LABEL_32;
        v14 += *(_QWORD *)(v9 + 104) * v42;
        if ( (_DWORD)v20 == 3 )
          goto LABEL_32;
        v18 = v43;
        if ( (_DWORD)v20 == 4 )
        {
          v14 += *(_QWORD *)(v9 + 112) * v43;
          goto LABEL_32;
        }
LABEL_25:
        v19 += v21 * v20;
      }
      v14 = 0LL;
LABEL_32:
      (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))(v6 + 168))(
        v6,
        v21 + v14,
        v22 >> v11,
        v19,
        v17,
        *((_QWORD *)a2 + 7),
        0LL,
        *(_QWORD *)(v9 + 120),
        v34,
        *((unsigned int *)ptr + 12));
      v23 = HIDWORD(v37);
      v24 = *(_DWORD *)(v9 + 80);
      if ( SHIDWORD(v37) >= v24 )
        goto LABEL_37;
      v25 = &v40 + SHIDWORD(v37);
      v26 = *v25 + 1;
      *v25 = v26;
      if ( *(_QWORD *)(v9 + 8LL * v23 + 120) == v26 )
      {
        v27 = v9 + 8LL * (v23 + 1);
        v28 = (unsigned int)(~v23 + v24);
        v29 = 0LL;
        while ( 1 )
        {
          v25[v29] = 0LL;
          if ( v28 == v29 )
            break;
          v30 = v25[v29 + 1] + 1;
          v25[++v29] = v30;
          if ( v30 != *(_QWORD *)(v27 + 8 * v29 + 112) )
            goto LABEL_39;
        }
LABEL_37:
        v40 = -1LL;
        break;
      }
LABEL_39:
      v14 = v40;
    }
    v38 = (__int64)ptr;
    v39 = (__int64)a2;
    sub_17590(7, (__int64 *)(v9 + 24), (void **)(v9 + 32), &v38);
  }
  else
  {
    sub_14AC0(v7, (__int64)ptr, (__int64)a2);
    v40 = (__int64)ptr;
    v41 = (__int64)a2;
    sub_17590(6, (__int64 *)(v9 + 24), (void **)(v9 + 32), &v40);
  }
  if ( ptr != (_QWORD *)v9 )
    nc_free_tensor(ptr);
  nc_free_tensor(a2);
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

// ======================================================
// Function: sub_14AC0 @ 0x14AC0
// ======================================================

__int64 __fastcall sub_14AC0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // rdi
  unsigned int v7; // eax
  int v8; // edi
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rsi
  __int64 v17; // rdx
  int v18; // r11d
  __int64 v19; // rbx
  int v20; // eax
  __int64 v21; // rbx
  int v22; // ecx
  __int64 v23; // rbx
  int v24; // ecx
  __int64 v25; // rbx
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // r14
  __int64 *v29; // rbx
  __int64 v30; // r10
  __int64 result; // rax
  int v32; // eax
  __int64 v33; // r9
  int v34; // eax
  __int64 v35; // r9
  __int64 v36; // rcx
  __int64 v37; // rcx
  __int64 v38; // r14
  bool v39; // zf
  __int64 v40; // rdx
  int v41; // [rsp+Ch] [rbp-9Ch]
  __int64 v42; // [rsp+10h] [rbp-98h]
  int v43; // [rsp+20h] [rbp-88h]
  __int64 v44; // [rsp+30h] [rbp-78h]
  __int64 v45; // [rsp+38h] [rbp-70h]
  __int64 v46; // [rsp+40h] [rbp-68h]
  __int64 v47; // [rsp+48h] [rbp-60h]
  __int64 v48; // [rsp+50h] [rbp-58h] BYREF
  __int64 v49; // [rsp+58h] [rbp-50h]
  __int64 v50; // [rsp+60h] [rbp-48h]
  __int64 v51; // [rsp+68h] [rbp-40h]

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  v42 = v6;
  if ( v6 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  if ( v6 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  v7 = *(_DWORD *)(a2 + 48);
  if ( *(_DWORD *)(a3 + 48) != v7 || v7 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_add_internal");
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 != *(_DWORD *)(a3 + 80) )
LABEL_9:
    __assert_fail("same_dims(y, x2)", "libnc.c", 0x1698u, "nc_add_internal");
  if ( v8 <= 0 )
  {
LABEL_70:
    if ( v8 != *(_DWORD *)(a2 + 80) )
      goto LABEL_71;
    v46 = 1LL;
    v16 = 0LL;
    if ( v8 )
      goto LABEL_37;
    return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
             v42,
             *(_QWORD *)(a1 + 56),
             0LL,
             *(_QWORD *)(a2 + 56),
             0LL,
             *(_QWORD *)(a3 + 56),
             0LL,
             v46,
             1LL,
             *(unsigned int *)(a2 + 48));
  }
  v9 = *(_QWORD *)(a1 + 120);
  v45 = *(_QWORD *)(a3 + 120);
  if ( v45 != v9 )
    goto LABEL_9;
  v10 = 1LL;
  while ( v8 > (int)v10 )
  {
    v11 = *(_QWORD *)(a1 + 8 * v10++ + 120);
    if ( v11 != *(_QWORD *)(a3 + 8 * v10 + 112) )
      goto LABEL_9;
  }
  if ( v8 != *(_DWORD *)(a2 + 80) || (v12 = 1LL, v45 != *(_QWORD *)(a2 + 120)) )
LABEL_71:
    __assert_fail("same_dims(y, x1)", "libnc.c", 0x1699u, "nc_add_internal");
  while ( v8 > (int)v12 )
  {
    v13 = *(_QWORD *)(a1 + 8 * v12++ + 120);
    if ( v13 != *(_QWORD *)(a2 + 8 * v12 + 112) )
      goto LABEL_71;
  }
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) || !*(_BYTE *)(a3 + 73) )
  {
    v43 = 1;
    v16 = 0LL;
    v46 = 1LL;
    goto LABEL_38;
  }
  if ( v8 <= 1 )
  {
    v16 = 1LL;
  }
  else
  {
    if ( !*(_BYTE *)(a1 + 74) || !*(_BYTE *)(a2 + 74) || !*(_BYTE *)(a3 + 74) )
    {
      v16 = 1LL;
      goto LABEL_106;
    }
    v14 = *(_QWORD *)(a1 + 128) * v9;
    LODWORD(v45) = v14;
    if ( v8 == 2 )
    {
      v16 = 2LL;
    }
    else
    {
      if ( !*(_BYTE *)(a1 + 75) || !*(_BYTE *)(a2 + 75) || !*(_BYTE *)(a3 + 75) )
      {
        v16 = 2LL;
        goto LABEL_106;
      }
      v15 = *(_QWORD *)(a1 + 136) * v14;
      LODWORD(v45) = v15;
      if ( v8 != 3 )
      {
        if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
        {
          v16 = 4LL;
          v45 = *(_QWORD *)(a1 + 144) * v15;
          goto LABEL_36;
        }
        v16 = 3LL;
LABEL_106:
        v46 = (int)v45;
        goto LABEL_37;
      }
      v16 = 3LL;
    }
  }
LABEL_36:
  v46 = (int)v45;
  if ( v8 == (_DWORD)v16 )
    return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
             v42,
             *(_QWORD *)(a1 + 56),
             0LL,
             *(_QWORD *)(a2 + 56),
             0LL,
             *(_QWORD *)(a3 + 56),
             0LL,
             v46,
             1LL,
             *(unsigned int *)(a2 + 48));
LABEL_37:
  v43 = v16 + 1;
  v45 = *(_QWORD *)(a1 + 8LL * (int)v16 + 120);
LABEL_38:
  v17 = v43;
  if ( v8 <= v43 )
    goto LABEL_59;
  v18 = v43;
  v17 = v43;
  if ( !*(_BYTE *)(a1 + v43 + 73) || !*(_BYTE *)(a2 + v43 + 73) || !*(_BYTE *)(a3 + v43 + 73) )
    goto LABEL_59;
  v19 = *(_QWORD *)(a1 + 8LL * v43 + 120) * v45;
  v20 = v43 + 1;
  v45 = v19;
  if ( v8 <= v43 + 1 )
    goto LABEL_102;
  v17 = v20;
  if ( !*(_BYTE *)(a1 + v20 + 73) || !*(_BYTE *)(a2 + v20 + 73) || !*(_BYTE *)(a3 + v20 + 73) )
    goto LABEL_100;
  v21 = *(_QWORD *)(a1 + 8LL * v20 + 120) * v19;
  v22 = v43 + 2;
  v45 = v21;
  if ( v8 <= v43 + 2 || !*(_BYTE *)(a1 + v22 + 73) || !*(_BYTE *)(a2 + v22 + 73) || !*(_BYTE *)(a3 + v22 + 73) )
  {
    v17 = v22;
    goto LABEL_99;
  }
  v23 = *(_QWORD *)(a1 + 8LL * v22 + 120) * v21;
  v24 = v43 + 3;
  v17 = v43 + 3;
  v45 = v23;
  if ( v8 <= v43 + 3 )
  {
LABEL_99:
    v20 = v17;
    goto LABEL_100;
  }
  if ( *(_BYTE *)(a1 + v24 + 73) && *(_BYTE *)(a2 + v24 + 73) && *(_BYTE *)(a3 + v24 + 73) )
  {
    v25 = *(_QWORD *)(a1 + 8LL * v24 + 120) * v23;
    v20 = v43 + 4;
    v45 = v25;
    if ( v8 > v43 + 4 )
    {
      v17 = v20;
      if ( *(_BYTE *)(a1 + v20 + 73) && *(_BYTE *)(a2 + v20 + 73) )
      {
        if ( *(_BYTE *)(a3 + v20 + 73) )
        {
          v43 += 5;
          v17 = v18 + 5;
          v45 = *(_QWORD *)(a1 + 8LL * v20 + 120) * v25;
          goto LABEL_59;
        }
        goto LABEL_102;
      }
LABEL_100:
      v43 = v20;
      goto LABEL_59;
    }
LABEL_102:
    v43 = v20;
    v17 = v20;
    goto LABEL_59;
  }
  v43 += 3;
LABEL_59:
  v26 = *(unsigned int *)(a2 + 48);
  v48 = 0LL;
  v41 = dword_30520[v26];
  if ( v8 <= 1 )
  {
    v28 = 0LL;
  }
  else
  {
    v27 = 1LL;
    do
      *(&v48 + v27++) = 0LL;
    while ( v8 > (int)v27 );
    v28 = v48;
  }
  v29 = &v48 + v17;
  v30 = v16 + 8;
  result = v17 + 12;
  v47 = v17 + 12;
  while ( v28 != -1 )
  {
    v32 = *(_DWORD *)(a3 + 80);
    if ( v32 <= 0 )
    {
      v33 = 0LL;
    }
    else
    {
      v33 = *(_QWORD *)(a3 + 88) * v28;
      if ( v32 != 1 )
      {
        v33 += *(_QWORD *)(a3 + 96) * v49;
        if ( v32 != 2 )
        {
          v33 += *(_QWORD *)(a3 + 104) * v50;
          if ( v32 != 3 )
          {
            if ( v32 != 4 )
              goto LABEL_70;
            v33 += *(_QWORD *)(a3 + 112) * v51;
          }
        }
      }
    }
    v34 = *(_DWORD *)(a2 + 80);
    v35 = *(_QWORD *)(a3 + 56) + v33;
    if ( v34 <= 0 )
    {
      v36 = 0LL;
    }
    else
    {
      v36 = *(_QWORD *)(a2 + 88) * v28;
      if ( v34 != 1 )
      {
        v36 += *(_QWORD *)(a2 + 96) * v49;
        if ( v34 != 2 )
        {
          v36 += *(_QWORD *)(a2 + 104) * v50;
          if ( v34 != 3 )
          {
            if ( v34 != 4 )
              goto LABEL_70;
            v36 += *(_QWORD *)(a2 + 112) * v51;
          }
        }
      }
    }
    v37 = *(_QWORD *)(a2 + 56) + v36;
    if ( v8 <= 0 )
    {
      v38 = 0LL;
    }
    else
    {
      v38 = *(_QWORD *)(a1 + 88) * v28;
      if ( v8 != 1 )
      {
        v38 += *(_QWORD *)(a1 + 96) * v49;
        if ( v8 != 2 )
        {
          v38 += *(_QWORD *)(a1 + 104) * v50;
          if ( v8 != 3 )
          {
            if ( v8 != 4 )
              goto LABEL_70;
            v38 += *(_QWORD *)(a1 + 112) * v51;
          }
        }
      }
    }
    v44 = v30;
    result = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
               v42,
               v38 + *(_QWORD *)(a1 + 56),
               *(_QWORD *)(a1 + 8 * v30 + 24) >> v41,
               v37,
               *(_QWORD *)(a2 + 8 * v30 + 24) >> v41,
               v35,
               *(_QWORD *)(a3 + 8 * v30 + 24) >> v41,
               v46,
               v45,
               *(unsigned int *)(a2 + 48));
    v8 = *(_DWORD *)(a1 + 80);
    if ( v8 <= v43 )
      break;
    v30 = v44;
    result = *v29 + 1;
    v39 = result == *(_QWORD *)(a1 + 8 * v47 + 24);
    *v29 = result;
    if ( v39 )
    {
      result = 0LL;
      do
      {
        v29[result] = 0LL;
        if ( result == v8 - 1 - v43 )
          return result;
        v40 = v29[result + 1] + 1;
        v29[++result] = v40;
      }
      while ( v40 == *(_QWORD *)(a1 + 8LL * (v43 + 1) + 8 * result + 112) );
    }
    v28 = v48;
  }
  return result;
}

