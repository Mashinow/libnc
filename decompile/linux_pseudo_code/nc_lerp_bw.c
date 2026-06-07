// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_lerp_bw
// Included functions: 2

// ======================================================
// Function: nc_lerp_bw @ 0x27570
// ======================================================

_QWORD *__fastcall nc_lerp_bw(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // r15
  int v10; // eax
  __int64 v11; // r8
  int v12; // edx
  __int64 v13; // rax
  __int64 v14; // rax
  void *v15; // r11
  __int64 v16; // r13
  int v17; // ecx
  __int64 v18; // rdi
  __int64 v19; // rdx
  __int64 v20; // rsi
  int v21; // ecx
  __int64 v22; // rdi
  __int64 v23; // r9
  __int64 v24; // r9
  __int64 v25; // rcx
  __int64 v26; // rcx
  __int64 v27; // rdi
  int v28; // eax
  int v29; // esi
  __int64 *v30; // rcx
  __int64 v31; // rdx
  bool v32; // zf
  __int64 v33; // rdi
  __int64 v34; // rsi
  __int64 v35; // rax
  __int64 v36; // rdx
  _QWORD *result; // rax
  __int64 v38; // [rsp+0h] [rbp-B8h]
  __int64 v39; // [rsp+0h] [rbp-B8h]
  __int64 v40; // [rsp+8h] [rbp-B0h]
  __int64 v41; // [rsp+8h] [rbp-B0h]
  __int64 v42; // [rsp+10h] [rbp-A8h]
  __int64 v43; // [rsp+10h] [rbp-A8h]
  __int64 v44; // [rsp+18h] [rbp-A0h]
  __int64 v45; // [rsp+18h] [rbp-A0h]
  __int64 v46; // [rsp+20h] [rbp-98h]
  __int64 v47; // [rsp+20h] [rbp-98h]
  __int64 v48; // [rsp+28h] [rbp-90h]
  void *v49; // [rsp+28h] [rbp-90h]
  __int64 v50; // [rsp+30h] [rbp-88h]
  __int64 v51; // [rsp+30h] [rbp-88h]
  __int64 v52; // [rsp+38h] [rbp-80h]
  void *ptr; // [rsp+40h] [rbp-78h]
  _QWORD *v55; // [rsp+48h] [rbp-70h]
  int v56; // [rsp+5Ch] [rbp-5Ch] BYREF
  __int64 v57; // [rsp+60h] [rbp-58h] BYREF
  __int64 v58; // [rsp+68h] [rbp-50h]
  __int64 v59; // [rsp+70h] [rbp-48h]
  __int64 v60; // [rsp+78h] [rbp-40h]

  v38 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL);
  v44 = nc_new_tensor_nz(v38, *(unsigned int *)(a2 + 48), *(unsigned int *)(a2 + 80), a2 + 120);
  v40 = nc_new_tensor_nz(
          *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL),
          *(unsigned int *)(a2 + 48),
          *(unsigned int *)(a2 + 80),
          a2 + 120);
  v9 = nc_new_tensor_nz(
         *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL),
         *(unsigned int *)(a2 + 48),
         *(unsigned int *)(a2 + 80),
         a2 + 120);
  v10 = sub_7F90(&v56, 0, v44, v40, v9, a2, a3, a4, a5, 0LL, v38, v44, v40, v44, v46, v48, v50, v52, a4, a1);
  v12 = *(_DWORD *)(a3 + 80);
  v57 = 0LL;
  v51 = v10;
  if ( v12 <= 1 )
  {
    v14 = 0LL;
  }
  else
  {
    v13 = 1LL;
    do
      *(&v57 + v13++) = 0LL;
    while ( v12 > (int)v13 );
    v14 = v57;
  }
  v15 = ptr;
  v16 = v42;
  while ( v14 != -1 )
  {
    v17 = *(_DWORD *)(a5 + 80);
    v18 = *(_QWORD *)(a5 + 56);
    if ( v17 <= 0 )
    {
      v19 = 0LL;
    }
    else
    {
      v19 = *(_QWORD *)(a5 + 88) * v14;
      if ( v17 != 1 )
      {
        v19 += *(_QWORD *)(a5 + 96) * v58;
        if ( v17 != 2 )
        {
          v19 += *(_QWORD *)(a5 + 104) * v59;
          if ( v17 != 3 )
          {
            v20 = v60;
            v11 = *(_QWORD *)(a5 + 112);
            goto LABEL_12;
          }
        }
      }
    }
    while ( 1 )
    {
      v21 = *((_DWORD *)v15 + 20);
      v20 = *((_QWORD *)v15 + 7);
      v47 = v19 + v18;
      if ( v21 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = *((_QWORD *)v15 + 11) * v14;
        if ( v21 != 1 )
        {
          v19 += *((_QWORD *)v15 + 12) * v58;
          if ( v21 != 2 )
          {
            v19 += *((_QWORD *)v15 + 13) * v59;
            if ( v21 != 3 )
            {
              v18 = v60;
              v11 = *((_QWORD *)v15 + 14);
              if ( v21 != 4 )
                goto LABEL_12;
              v19 += v11 * v60;
            }
          }
        }
      }
      v22 = v20 + v19;
      v19 = *(unsigned int *)(a3 + 80);
      v45 = v22;
      if ( (int)v19 <= 0 )
      {
        v19 = *(unsigned int *)(a2 + 80);
        v24 = *(_QWORD *)(a3 + 56);
        v25 = *(_QWORD *)(a2 + 56);
        if ( (int)v19 <= 0 )
          goto LABEL_58;
      }
      else
      {
        v23 = *(_QWORD *)(a3 + 88) * v14;
        if ( (_DWORD)v19 != 1 )
        {
          v23 += *(_QWORD *)(a3 + 96) * v58;
          if ( (_DWORD)v19 != 2 )
          {
            v23 += *(_QWORD *)(a3 + 104) * v59;
            if ( (_DWORD)v19 != 3 )
            {
              v20 = v60;
              v18 = *(_QWORD *)(a3 + 112);
              if ( (_DWORD)v19 != 4 )
                goto LABEL_12;
              v23 += v18 * v60;
            }
          }
        }
        v19 = *(unsigned int *)(a2 + 80);
        v24 = *(_QWORD *)(a3 + 56) + v23;
        v25 = *(_QWORD *)(a2 + 56);
        if ( (int)v19 <= 0 )
        {
LABEL_58:
          v19 = *(unsigned int *)(v9 + 80);
          v20 = *(_QWORD *)(v9 + 56);
          v11 = v25;
          if ( (int)v19 <= 0 )
            goto LABEL_59;
          goto LABEL_32;
        }
      }
      v11 = *(_QWORD *)(a2 + 88) * v14;
      if ( (_DWORD)v19 != 1 )
      {
        v11 += *(_QWORD *)(a2 + 96) * v58;
        if ( (_DWORD)v19 != 2 )
        {
          v11 += *(_QWORD *)(a2 + 104) * v59;
          if ( (_DWORD)v19 != 3 )
          {
            v20 = v60;
            v18 = *(_QWORD *)(a2 + 112);
            if ( (_DWORD)v19 != 4 )
              goto LABEL_12;
            v11 += v18 * v60;
          }
        }
      }
      v19 = *(unsigned int *)(v9 + 80);
      v11 += v25;
      v20 = *(_QWORD *)(v9 + 56);
      if ( (int)v19 <= 0 )
      {
LABEL_59:
        v26 = 0LL;
        goto LABEL_37;
      }
LABEL_32:
      v26 = *(_QWORD *)(v9 + 88) * v14;
      if ( (_DWORD)v19 != 1 )
      {
        v26 += *(_QWORD *)(v9 + 96) * v58;
        if ( (_DWORD)v19 != 2 )
        {
          v26 += *(_QWORD *)(v9 + 104) * v59;
          if ( (_DWORD)v19 != 3 )
          {
            v18 = v60;
            if ( (_DWORD)v19 != 4 )
              goto LABEL_12;
            v26 += *(_QWORD *)(v9 + 112) * v60;
          }
        }
      }
LABEL_37:
      v27 = v26 + v20;
      v20 = *(unsigned int *)(v16 + 80);
      v43 = v27;
      v18 = *(_QWORD *)(v16 + 56);
      if ( (int)v20 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = *(_QWORD *)(v16 + 88) * v14;
        if ( (_DWORD)v20 != 1 )
        {
          v19 += *(_QWORD *)(v16 + 96) * v58;
          if ( (_DWORD)v20 != 2 )
          {
            v19 += *(_QWORD *)(v16 + 104) * v59;
            if ( (_DWORD)v20 != 3 )
            {
              if ( (_DWORD)v20 != 4 )
                goto LABEL_12;
              v19 += *(_QWORD *)(v16 + 112) * v60;
            }
          }
        }
      }
      v19 += v18;
      v18 = *(unsigned int *)(v41 + 80);
      v20 = *(_QWORD *)(v41 + 56);
      if ( (int)v18 <= 0 )
        break;
      v14 *= *(_QWORD *)(v41 + 88);
      if ( (_DWORD)v18 == 1 )
        goto LABEL_49;
      v14 += *(_QWORD *)(v41 + 96) * v58;
      if ( (_DWORD)v18 == 2 )
        goto LABEL_49;
      v14 += *(_QWORD *)(v41 + 104) * v59;
      if ( (_DWORD)v18 == 3 )
        goto LABEL_49;
      if ( (_DWORD)v18 == 4 )
      {
        v14 += *(_QWORD *)(v41 + 112) * v60;
        goto LABEL_49;
      }
LABEL_12:
      v19 += v11 * v20;
    }
    v14 = 0LL;
LABEL_49:
    v49 = v15;
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v39 + 296))(
      v39,
      v14 + v20,
      v19,
      v43,
      v11,
      v24,
      v45,
      v47,
      v51);
    v28 = v56;
    v29 = *(_DWORD *)(a3 + 80);
    if ( v56 < v29 )
    {
      v15 = v49;
      v30 = &v57 + v56;
      v31 = *v30 + 1;
      v32 = v31 == *(_QWORD *)(a3 + 8LL * v56 + 120);
      *v30 = v31;
      if ( !v32 )
      {
LABEL_55:
        v14 = v57;
        continue;
      }
      v33 = a3 + 8LL * (v28 + 1);
      v34 = (unsigned int)(~v28 + v29);
      v35 = 0LL;
      while ( 1 )
      {
        v30[v35] = 0LL;
        if ( v34 == v35 )
          break;
        v36 = v30[v35 + 1] + 1;
        v30[++v35] = v36;
        if ( v36 != *(_QWORD *)(v33 + 8 * v35 + 112) )
          goto LABEL_55;
      }
    }
    break;
  }
  nc_free_tensor((void *)a2);
  nc_free_tensor((void *)a3);
  nc_free_tensor(ptr);
  nc_free_tensor((void *)a5);
  result = v55;
  *v55 = v41;
  v55[1] = v16;
  v55[2] = v9;
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

