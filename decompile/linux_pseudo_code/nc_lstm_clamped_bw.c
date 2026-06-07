// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_lstm_clamped_bw
// Included functions: 2

// ======================================================
// Function: nc_lstm_clamped_bw @ 0x265B0
// ======================================================

__int64 *__fastcall nc_lstm_clamped_bw(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v10; // rax
  __int64 v11; // rsi
  void *v12; // rax
  int v13; // eax
  __int64 v14; // r8
  int v15; // edx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r11
  int v19; // ecx
  __int64 v20; // rsi
  __int64 v21; // rdx
  __int64 v22; // rdi
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  __int64 v26; // rsi
  __int64 v27; // r9
  __int64 v28; // r9
  __int64 v29; // rcx
  int v30; // eax
  int v31; // esi
  __int64 *v32; // rcx
  __int64 v33; // rdx
  bool v34; // zf
  __int64 v35; // rdi
  __int64 v36; // rsi
  __int64 v37; // rax
  __int64 v38; // rdx
  __int64 *result; // rax
  void *ptr; // [rsp+0h] [rbp-E8h]
  void (__fastcall **ptra)(void *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD); // [rsp+0h] [rbp-E8h]
  __int64 v43; // [rsp+8h] [rbp-E0h]
  __int64 v44; // [rsp+10h] [rbp-D8h]
  __int64 v45; // [rsp+18h] [rbp-D0h]
  __int64 v46; // [rsp+18h] [rbp-D0h]
  __int64 v47; // [rsp+20h] [rbp-C8h]
  __int64 v48; // [rsp+20h] [rbp-C8h]
  __int64 v49; // [rsp+28h] [rbp-C0h]
  __int64 v50; // [rsp+28h] [rbp-C0h]
  __int64 v51; // [rsp+30h] [rbp-B8h]
  __int64 v52; // [rsp+30h] [rbp-B8h]
  __int64 v53; // [rsp+38h] [rbp-B0h]
  __int64 v54; // [rsp+38h] [rbp-B0h]
  __int64 v55; // [rsp+40h] [rbp-A8h]
  __int64 v56; // [rsp+48h] [rbp-A0h]
  __int64 v57; // [rsp+50h] [rbp-98h]
  __int64 v58; // [rsp+58h] [rbp-90h]
  __int64 v59; // [rsp+68h] [rbp-80h]
  __int64 v60; // [rsp+70h] [rbp-78h]
  int v62; // [rsp+8Ch] [rbp-5Ch] BYREF
  __int64 v63; // [rsp+90h] [rbp-58h] BYREF
  __int64 v64; // [rsp+98h] [rbp-50h]
  __int64 v65; // [rsp+A0h] [rbp-48h]
  __int64 v66; // [rsp+A8h] [rbp-40h]

  v10 = *(_QWORD *)(a2 + 40);
  v11 = *(unsigned int *)(a3 + 48);
  v12 = *(void **)(v10 + 24);
  ptr = v12;
  if ( (_DWORD)v11 != *(_DWORD *)(a2 + 48)
    || (_DWORD)v11 != *(_DWORD *)(a4 + 48)
    || (_DWORD)v11 != *(_DWORD *)(a5 + 48)
    || *(_DWORD *)(a6 + 48) != (_DWORD)v11
    || (unsigned int)v11 > 1 )
  {
    nc_error("unsupported type for %s\n", (char)"nc_lstm_clamped_bw");
  }
  v59 = nc_new_tensor_nz(v12, v11, *(unsigned int *)(a2 + 80), a2 + 120);
  v56 = nc_new_tensor_nz(
          *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL),
          *(unsigned int *)(a2 + 48),
          *(unsigned int *)(a2 + 80),
          a2 + 120);
  v57 = nc_new_tensor_nz(
          *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL),
          *(unsigned int *)(a2 + 48),
          *(unsigned int *)(a2 + 80),
          a2 + 120);
  v60 = nc_new_tensor_nz(
          *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL),
          *(unsigned int *)(a2 + 48),
          *(unsigned int *)(a2 + 80),
          a2 + 120);
  v13 = sub_7F90(&v62, 0, v59, v56, v57, v60, a2, a3, a4, a5, a6, 0LL, (__int64)ptr, a6, v44, v45, v47, v49, v51, v53);
  v15 = *(_DWORD *)(a3 + 80);
  v63 = 0LL;
  v58 = v13;
  if ( v15 <= 1 )
  {
    v17 = 0LL;
  }
  else
  {
    v16 = 1LL;
    do
      *(&v63 + v16++) = 0LL;
    while ( v15 > (int)v16 );
    v17 = v63;
  }
  v18 = v60;
  while ( v17 != -1 )
  {
    v19 = *(_DWORD *)(v43 + 80);
    v20 = *(_QWORD *)(v43 + 56);
    if ( v19 <= 0 )
    {
      v21 = 0LL;
    }
    else
    {
      v21 = *(_QWORD *)(v43 + 88) * v17;
      if ( v19 != 1 )
      {
        v21 += *(_QWORD *)(v43 + 96) * v64;
        if ( v19 != 2 )
        {
          v21 += *(_QWORD *)(v43 + 104) * v65;
          if ( v19 != 3 )
          {
            v22 = v66;
            v14 = *(_QWORD *)(v43 + 112);
            goto LABEL_14;
          }
        }
      }
    }
    while ( 1 )
    {
      v23 = *(_DWORD *)(a5 + 80);
      v54 = v21 + v20;
      v20 = *(_QWORD *)(a5 + 56);
      if ( v23 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *(_QWORD *)(a5 + 88) * v17;
        if ( v23 != 1 )
        {
          v21 += *(_QWORD *)(a5 + 96) * v64;
          if ( v23 != 2 )
          {
            v21 += *(_QWORD *)(a5 + 104) * v65;
            if ( v23 != 3 )
            {
              v22 = v66;
              v14 = *(_QWORD *)(a5 + 112);
              if ( v23 != 4 )
                goto LABEL_14;
              v21 += v14 * v66;
            }
          }
        }
      }
      v24 = *(_DWORD *)(a4 + 80);
      v52 = v21 + v20;
      v20 = *(_QWORD *)(a4 + 56);
      if ( v24 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *(_QWORD *)(a4 + 88) * v17;
        if ( v24 != 1 )
        {
          v21 += *(_QWORD *)(a4 + 96) * v64;
          if ( v24 != 2 )
          {
            v21 += *(_QWORD *)(a4 + 104) * v65;
            if ( v24 != 3 )
            {
              v22 = v66;
              v14 = *(_QWORD *)(a4 + 112);
              if ( v24 != 4 )
                goto LABEL_14;
              v21 += v14 * v66;
            }
          }
        }
      }
      v25 = *(_DWORD *)(a3 + 80);
      v50 = v21 + v20;
      v20 = *(_QWORD *)(a3 + 56);
      if ( v25 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *(_QWORD *)(a3 + 88) * v17;
        if ( v25 != 1 )
        {
          v21 += *(_QWORD *)(a3 + 96) * v64;
          if ( v25 != 2 )
          {
            v21 += *(_QWORD *)(a3 + 104) * v65;
            if ( v25 != 3 )
            {
              v22 = v66;
              v14 = *(_QWORD *)(a3 + 112);
              if ( v25 != 4 )
                goto LABEL_14;
              v21 += v14 * v66;
            }
          }
        }
      }
      v26 = v21 + v20;
      v21 = *(unsigned int *)(a2 + 80);
      v48 = v26;
      if ( (int)v21 <= 0 )
      {
        v27 = 0LL;
      }
      else
      {
        v27 = *(_QWORD *)(a2 + 88) * v17;
        if ( (_DWORD)v21 != 1 )
        {
          v27 += *(_QWORD *)(a2 + 96) * v64;
          if ( (_DWORD)v21 != 2 )
          {
            v27 += *(_QWORD *)(a2 + 104) * v65;
            if ( (_DWORD)v21 != 3 )
            {
              v20 = v66;
              v22 = *(_QWORD *)(a2 + 112);
              if ( (_DWORD)v21 != 4 )
                goto LABEL_14;
              v27 += v22 * v66;
            }
          }
        }
      }
      v21 = *(unsigned int *)(v18 + 80);
      v28 = *(_QWORD *)(a2 + 56) + v27;
      if ( (int)v21 <= 0 )
      {
        v14 = 0LL;
      }
      else
      {
        v14 = *(_QWORD *)(v18 + 88) * v17;
        if ( (_DWORD)v21 != 1 )
        {
          v14 += *(_QWORD *)(v18 + 96) * v64;
          if ( (_DWORD)v21 != 2 )
          {
            v14 += *(_QWORD *)(v18 + 104) * v65;
            if ( (_DWORD)v21 != 3 )
            {
              v20 = v66;
              v22 = *(_QWORD *)(v18 + 112);
              if ( (_DWORD)v21 != 4 )
                goto LABEL_14;
              v14 += v22 * v66;
            }
          }
        }
      }
      v14 += *(_QWORD *)(v18 + 56);
      v21 = *(unsigned int *)(v57 + 80);
      v20 = *(_QWORD *)(v57 + 56);
      if ( (int)v21 <= 0 )
      {
        v29 = 0LL;
      }
      else
      {
        v29 = *(_QWORD *)(v57 + 88) * v17;
        if ( (_DWORD)v21 != 1 )
        {
          v29 += *(_QWORD *)(v57 + 96) * v64;
          if ( (_DWORD)v21 != 2 )
          {
            v29 += *(_QWORD *)(v57 + 104) * v65;
            if ( (_DWORD)v21 != 3 )
            {
              v22 = v66;
              if ( (_DWORD)v21 != 4 )
                goto LABEL_14;
              v29 += *(_QWORD *)(v57 + 112) * v66;
            }
          }
        }
      }
      v46 = v29 + v20;
      v20 = *(unsigned int *)(v56 + 80);
      v22 = *(_QWORD *)(v56 + 56);
      if ( (int)v20 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *(_QWORD *)(v56 + 88) * v17;
        if ( (_DWORD)v20 != 1 )
        {
          v21 += *(_QWORD *)(v56 + 96) * v64;
          if ( (_DWORD)v20 != 2 )
          {
            v21 += *(_QWORD *)(v56 + 104) * v65;
            if ( (_DWORD)v20 != 3 )
            {
              if ( (_DWORD)v20 != 4 )
                goto LABEL_14;
              v21 += *(_QWORD *)(v56 + 112) * v66;
            }
          }
        }
      }
      v21 += v22;
      v22 = *(unsigned int *)(v59 + 80);
      v20 = *(_QWORD *)(v59 + 56);
      if ( (int)v22 <= 0 )
        break;
      v17 *= *(_QWORD *)(v59 + 88);
      if ( (_DWORD)v22 == 1 )
        goto LABEL_63;
      v17 += *(_QWORD *)(v59 + 96) * v64;
      if ( (_DWORD)v22 == 2 )
        goto LABEL_63;
      v17 += *(_QWORD *)(v59 + 104) * v65;
      if ( (_DWORD)v22 == 3 )
        goto LABEL_63;
      if ( (_DWORD)v22 == 4 )
      {
        v17 += *(_QWORD *)(v59 + 112) * v66;
        goto LABEL_63;
      }
LABEL_14:
      v21 += v14 * v22;
    }
    v17 = 0LL;
LABEL_63:
    v55 = v18;
    ptra[35](ptra, v17 + v20, v21, v46, v14, v28, v48, v50, v52, v54, v58, *(unsigned int *)(a2 + 48));
    v30 = v62;
    v31 = *(_DWORD *)(a3 + 80);
    if ( v62 < v31 )
    {
      v18 = v55;
      v32 = &v63 + v62;
      v33 = *v32 + 1;
      v34 = *(_QWORD *)(a3 + 8LL * v62 + 120) == v33;
      *v32 = v33;
      if ( !v34 )
      {
LABEL_69:
        v17 = v63;
        continue;
      }
      v35 = a3 + 8LL * (v30 + 1);
      v36 = (unsigned int)(~v30 + v31);
      v37 = 0LL;
      while ( 1 )
      {
        v32[v37] = 0LL;
        if ( v36 == v37 )
          break;
        v38 = v32[v37 + 1] + 1;
        v32[++v37] = v38;
        if ( v38 != *(_QWORD *)(v35 + 8 * v37 + 112) )
          goto LABEL_69;
      }
    }
    break;
  }
  nc_free_tensor((void *)a2);
  nc_free_tensor((void *)a3);
  nc_free_tensor((void *)a4);
  nc_free_tensor((void *)a5);
  nc_free_tensor((void *)v43);
  result = a1;
  *a1 = v59;
  a1[1] = v56;
  a1[2] = v57;
  a1[3] = v60;
  return result;
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

