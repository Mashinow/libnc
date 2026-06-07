// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_matmul_add
// Included functions: 4

// ======================================================
// Function: nc_matmul_add @ 0x21CC0
// ======================================================

__int64 __fastcall nc_matmul_add(unsigned int *ptr, _QWORD *a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  _QWORD *v5; // r13
  unsigned int v7; // eax
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // r14
  __int64 v12; // rdi
  __int64 v13; // rsi
  int v14; // eax
  unsigned __int64 v15; // rcx
  void (__fastcall *v16)(__int64, __int64, _QWORD, unsigned __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64); // r10
  __int64 v17; // rdx
  int v18; // eax
  int v19; // edx
  __int64 v20; // rax
  __int64 v21; // rbx
  __int64 v22; // rbp
  unsigned __int64 v23; // rcx
  int v24; // edx
  __int64 v25; // rax
  unsigned __int64 v26; // rdx
  __int64 v27; // r8
  unsigned __int64 v28; // rdi
  __int64 v29; // r8
  int v30; // eax
  __int64 v31; // rdx
  __int64 v32; // rax
  __int64 v33; // rdx
  _QWORD *v34; // rax
  _QWORD *v35; // rbx
  __int64 v36; // rax
  bool v37; // zf
  _QWORD *v38; // rbp
  __int64 v40; // r15
  __int64 v41; // rbp
  _QWORD *v42; // rbx
  _QWORD *v43; // r13
  int v44; // r14d
  __int64 v45; // r15
  unsigned __int64 v46; // rdi
  unsigned __int64 v47; // rdx
  __int64 v48; // r8
  __int64 v49; // [rsp+0h] [rbp-108h]
  __int64 v50; // [rsp+0h] [rbp-108h]
  char *v51; // [rsp+8h] [rbp-100h]
  __int64 v52; // [rsp+8h] [rbp-100h]
  __int64 v53; // [rsp+10h] [rbp-F8h]
  __int64 v54; // [rsp+10h] [rbp-F8h]
  __int64 v55; // [rsp+18h] [rbp-F0h]
  __int64 v56; // [rsp+18h] [rbp-F0h]
  __int64 v57; // [rsp+18h] [rbp-F0h]
  __int64 v58; // [rsp+20h] [rbp-E8h]
  __int64 v59; // [rsp+20h] [rbp-E8h]
  __int64 v60; // [rsp+28h] [rbp-E0h]
  int v61; // [rsp+28h] [rbp-E0h]
  char v62; // [rsp+2Ch] [rbp-DCh]
  __int64 v63; // [rsp+30h] [rbp-D8h]
  __int64 v64; // [rsp+30h] [rbp-D8h]
  __int64 v65; // [rsp+38h] [rbp-D0h]
  __int64 v66; // [rsp+38h] [rbp-D0h]
  __int64 v67; // [rsp+40h] [rbp-C8h]
  __int64 v68; // [rsp+40h] [rbp-C8h]
  __int64 v69; // [rsp+48h] [rbp-C0h]
  __int64 v70; // [rsp+48h] [rbp-C0h]
  __int64 v71; // [rsp+50h] [rbp-B8h]
  void *ptrb; // [rsp+58h] [rbp-B0h]
  __int64 v74; // [rsp+60h] [rbp-A8h]
  __int64 v75; // [rsp+68h] [rbp-A0h] BYREF
  __int64 v76[4]; // [rsp+70h] [rbp-98h] BYREF
  __int64 v77; // [rsp+90h] [rbp-78h] BYREF
  __int64 v78; // [rsp+98h] [rbp-70h]
  __int64 v79; // [rsp+A0h] [rbp-68h]
  __int64 v80; // [rsp+A8h] [rbp-60h]
  __int64 v81; // [rsp+B0h] [rbp-58h] BYREF
  __int64 v82; // [rsp+B8h] [rbp-50h]
  __int64 v83; // [rsp+C0h] [rbp-48h]
  unsigned __int64 v84; // [rsp+C8h] [rbp-40h]

  v5 = ptr;
  v69 = __PAIR64__(a5, a4);
  v63 = *(_QWORD *)(a2[5] + 24LL);
  if ( v63 != *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  v7 = ptr[12];
  if ( v7 > 2 )
  {
    printf("unsupported type for %s\n", "nc_matmul_add");
    abort();
  }
  if ( v7 == 2 )
  {
    if ( __PAIR64__(a5, a4) )
      __assert_fail("!w_trans && !x_trans", "libnc.c", 0x1995u, "nc_matmul_add");
    if ( *((_DWORD *)a2 + 12) )
LABEL_6:
      nc_error("unsupported type for %s\n", (char)"nc_matmul_add");
  }
  else if ( v7 != *((_DWORD *)a2 + 12) )
  {
    goto LABEL_6;
  }
  v8 = ptr[20];
  if ( *((_DWORD *)a2 + 20) != (_DWORD)v8 )
    goto LABEL_103;
  if ( (int)v8 <= 1 )
    goto LABEL_103;
  v51 = (char *)&a2[a5];
  if ( *(_QWORD *)&ptr[2 * (1 - a4) + 30] != *((_QWORD *)v51 + 15) )
    goto LABEL_103;
  if ( (_DWORD)v8 == 2 )
  {
    v77 = *(_QWORD *)&ptr[2 * a4 + 30];
    v78 = a2[(int)(1 - a5) + 15];
  }
  else
  {
    if ( *((_QWORD *)ptr + 17) != a2[17] )
      goto LABEL_103;
    v9 = 3LL;
    while ( (int)v8 > (int)v9 )
    {
      v10 = *(_QWORD *)&ptr[2 * v9++ + 30];
      if ( v10 != a2[v9 + 14] )
        goto LABEL_103;
    }
    v79 = *((_QWORD *)ptr + 17);
    v77 = *(_QWORD *)&ptr[2 * (int)v69 + 30];
    v78 = a2[1 - HIDWORD(v69) + 15];
    if ( (_DWORD)v8 != 3 )
      v80 = *((_QWORD *)ptr + 18);
  }
  if ( !a3 )
  {
    a3 = nc_new_tensor(v63, *((unsigned int *)a2 + 12), v8, &v77);
    goto LABEL_26;
  }
  if ( *(_DWORD *)(a3 + 48) != *((_DWORD *)a2 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_matmul_add");
  if ( *(_QWORD *)(a3 + 120) != v77
    || *(_QWORD *)(a3 + 128) != v78
    || (_DWORD)v8 != 2 && (v79 != *(_QWORD *)(a3 + 136) || (_DWORD)v8 != 3 && v80 != *(_QWORD *)(a3 + 144)) )
  {
LABEL_103:
    sub_18270("matmul", (__int64)ptr, (__int64)a2);
  }
LABEL_26:
  v11 = a3;
  if ( *(_DWORD *)(a3 + 16) != 1 )
  {
    v11 = nc_new_tensor_nz(
            *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL),
            *(unsigned int *)(a3 + 48),
            *(unsigned int *)(a3 + 80),
            a3 + 120);
    nc_tensor_copy(v11, a3);
  }
  v12 = (__int64)&v75 + 4;
  v13 = 2LL;
  v14 = sub_7F90(
          (_DWORD *)&v75 + 1,
          2,
          v11,
          (__int64)a2,
          (__int64)v5,
          0LL,
          v49,
          (__int64)v51,
          v53,
          v55,
          v58,
          v60,
          v63,
          v65,
          v67,
          v69,
          v71,
          a3,
          v74,
          v75);
  v17 = *((unsigned int *)v5 + 12);
  v81 = 0LL;
  v61 = v14;
  v18 = dword_30520[v17];
  v19 = *((_DWORD *)a2 + 20);
  v62 = v18;
  if ( v19 <= 1 )
  {
    v21 = 0LL;
  }
  else
  {
    v20 = 1LL;
    v15 = (unsigned __int64)&v81;
    do
      *(&v81 + v20++) = 0LL;
    while ( v19 > (int)v20 );
    v21 = v81;
  }
  while ( 2 )
  {
    if ( v21 == -1 )
      goto LABEL_59;
    v22 = *((unsigned int *)v5 + 12);
    if ( (_DWORD)v22 != 2 )
    {
      v23 = a2[13];
      v24 = *((_DWORD *)a2 + 20);
      v12 = a2[7];
      v16 = *(void (__fastcall **)(__int64, __int64, _QWORD, unsigned __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64))(v64 + 440);
      v59 = *(_QWORD *)(v52 + 120);
      v66 = *(_QWORD *)(v11 + 128);
      v68 = *(_QWORD *)(v11 + 120);
      v50 = v23 >> v62;
      v54 = a2[8];
      if ( v24 <= 0 )
      {
        v25 = 0LL;
      }
      else
      {
        v25 = a2[11] * v21;
        if ( v24 != 1 )
        {
          v25 += a2[12] * v82;
          if ( v24 != 2 )
          {
            v25 += v83 * v23;
            if ( v24 != 3 )
            {
              v15 = v84;
              v13 = a2[14];
              goto LABEL_39;
            }
          }
        }
      }
      goto LABEL_40;
    }
    v57 = *(_QWORD *)(v11 + 56);
    v25 = *(unsigned int *)(v11 + 80);
    if ( (int)v25 <= 0 )
    {
      LODWORD(v40) = 0;
      goto LABEL_75;
    }
    v40 = *(_QWORD *)(v11 + 88) * v21;
    if ( (_DWORD)v25 == 1 )
      goto LABEL_75;
    v40 += *(_QWORD *)(v11 + 96) * v82;
    if ( (_DWORD)v25 == 2 )
      goto LABEL_75;
    v40 += *(_QWORD *)(v11 + 104) * v83;
    if ( (_DWORD)v25 == 3 )
      goto LABEL_75;
    v15 = *(_QWORD *)(v11 + 112);
    if ( (_DWORD)v25 == 4 )
    {
      LODWORD(v40) = v15 * v84 + v40;
LABEL_75:
      v54 = v5[7];
      v25 = *((unsigned int *)v5 + 20);
      if ( (int)v25 <= 0 )
      {
        v50 = 0LL;
      }
      else
      {
        v50 = v5[11] * v21;
        if ( (_DWORD)v25 != 1 )
        {
          v50 = v5[12] * v82 + v5[11] * v21;
          if ( (_DWORD)v25 != 2 )
          {
            v13 = v5[13] * v83 + v5[12] * v82 + v5[11] * v21;
            v50 = v13;
            if ( (_DWORD)v25 != 3 )
            {
              v15 = v5[14];
              if ( (_DWORD)v25 != 4 )
                goto LABEL_39;
              v50 = v15 * v84 + v13;
            }
          }
        }
      }
      v13 = *((unsigned int *)a2 + 20);
      v12 = a2[7];
      if ( (int)v13 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 *= a2[11];
        if ( (_DWORD)v13 != 1 )
        {
          v21 += a2[12] * v82;
          if ( (_DWORD)v13 != 2 )
          {
            v21 += a2[13] * v83;
            if ( (_DWORD)v13 != 3 )
            {
              v25 = v84;
              if ( (_DWORD)v13 != 4 )
                goto LABEL_39;
              v21 += a2[14] * v84;
            }
          }
        }
      }
      if ( v61 > 0 )
      {
        v59 = v21;
        v41 = 0LL;
        v42 = v5;
        v43 = (_QWORD *)v11;
        v44 = v40;
        v45 = a2[7];
        do
        {
          v46 = v41 * (v43[13] & 0xFFFFFFFFFFFFFFFCLL);
          v47 = v50 + v41 * (v42[13] & 0xFFFFFFFFFFFFFFFELL);
          v48 = v45 + v59 + v41 * (a2[13] & 0xFFFFFFFFFFFFFFFCLL);
          ++v41;
          mat_mul_f16(v57 + v44 + v46, v43[8], v54 + v47, v42[8], v48, a2[8], v43[15], v43[16], *(_QWORD *)(v52 + 120));
        }
        while ( v61 > (int)v41 );
        v11 = (__int64)v43;
        v13 = *((unsigned int *)a2 + 20);
        v5 = v42;
      }
      goto LABEL_53;
    }
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_39:
        v25 += v13 * v15;
LABEL_40:
        v26 = v5[13];
        v56 = v12 + v25;
        v13 = v5[7];
        v25 = *((unsigned int *)v5 + 20);
        if ( (int)v25 <= 0 )
        {
          v27 = 0LL;
          break;
        }
        v27 = v5[11] * v21;
        if ( (_DWORD)v25 == 1 )
          break;
        v27 += v5[12] * v82;
        if ( (_DWORD)v25 == 2 )
          break;
        v27 += v83 * v26;
        if ( (_DWORD)v25 == 3 )
          break;
        v15 = v5[14];
        if ( (_DWORD)v25 == 4 )
        {
          v27 += v15 * v84;
          break;
        }
      }
      v28 = *(_QWORD *)(v11 + 104);
      v29 = v13 + v27;
      v13 = *(_QWORD *)(v11 + 56);
      v15 = v28 >> v62;
      v25 = *(unsigned int *)(v11 + 80);
      if ( (int)v25 <= 0 )
        break;
      v21 *= *(_QWORD *)(v11 + 88);
      if ( (_DWORD)v25 == 1 )
        goto LABEL_52;
      v21 += *(_QWORD *)(v11 + 96) * v82;
      if ( (_DWORD)v25 == 2 )
        goto LABEL_52;
      v21 += v83 * v28;
      if ( (_DWORD)v25 == 3 )
        goto LABEL_52;
      v12 = v84;
      if ( (_DWORD)v25 == 4 )
      {
        v21 += *(_QWORD *)(v11 + 112) * v84;
        goto LABEL_52;
      }
    }
    v21 = 0LL;
LABEL_52:
    v16(
      v64,
      v21 + v13,
      *(_QWORD *)(v11 + 64),
      v15,
      v29,
      v5[8],
      v26 >> v62,
      v56,
      v54,
      v50,
      (unsigned int)v70,
      HIDWORD(v70),
      (unsigned int)v68,
      (unsigned int)v66,
      (unsigned int)v59,
      (unsigned int)v61,
      v22);
    v13 = *((unsigned int *)a2 + 20);
LABEL_53:
    v30 = HIDWORD(v75);
    if ( SHIDWORD(v75) < (int)v13 )
    {
      v12 = SHIDWORD(v75);
      v15 = (unsigned __int64)(&v81 + SHIDWORD(v75));
      v31 = *(_QWORD *)v15 + 1LL;
      *(_QWORD *)v15 = v31;
      if ( a2[v30 + 15] == v31 )
      {
        v12 = (__int64)&a2[v30 + 1];
        v13 = (unsigned int)(~v30 + v13);
        v32 = 0LL;
        do
        {
          *(_QWORD *)(v15 + 8 * v32) = 0LL;
          if ( v32 == v13 )
            goto LABEL_58;
          v33 = *(_QWORD *)(v15 + 8 * v32 + 8) + 1LL;
          *(_QWORD *)(v15 + 8 * v32++ + 8) = v33;
        }
        while ( v33 == *(_QWORD *)(v12 + 8 * v32 + 112) );
      }
      v21 = v81;
      continue;
    }
    break;
  }
LABEL_58:
  v81 = -1LL;
LABEL_59:
  v76[0] = (__int64)v5;
  v76[1] = (__int64)a2;
  v76[2] = (__int64)ptrb;
  v34 = sub_176C0(30, (__int64 *)(v11 + 24), (void **)(v11 + 32), v76);
  v35 = v34;
  if ( v34 )
  {
    *((_DWORD *)v34 + 10) = 2;
    v36 = nc_mallocz(0x10uLL);
    v37 = v5[4] == 0LL;
    v35[6] = v36;
    if ( !v37 )
      *(_QWORD *)(v36 + 8) = nc_dup_tensor(a2);
    if ( a2[4] )
    {
      v38 = (_QWORD *)v35[6];
      *v38 = nc_dup_tensor(v5);
    }
    v35[7] = v70;
  }
  if ( ptrb != (void *)v11 )
    nc_free_tensor(ptrb);
  nc_free_tensor(v5);
  nc_free_tensor(a2);
  return v11;
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
// Function: sub_176C0 @ 0x176C0
// ======================================================

_QWORD *__fastcall sub_176C0(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  _QWORD *v4; // r15
  _QWORD *v8; // rax
  __int64 v9; // r13
  _QWORD *v10; // r12
  __int64 v11; // rax
  __int64 v12; // rbx
  _DWORD *v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rbp
  __int64 v16; // rax
  __int64 v17; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
  {
    v4 = *(_QWORD **)(a4[2] + 32LL);
    if ( !v4 )
      return v4;
  }
  v8 = (_QWORD *)nc_malloc(0x18uLL);
  v9 = *a2;
  v10 = v8;
  *v8 = *(_QWORD *)(*a4 + 32LL);
  v8[1] = *(_QWORD *)(a4[1] + 32LL);
  v11 = a4[2];
  v12 = 0LL;
  v10[2] = *(_QWORD *)(v11 + 32);
  v13 = (_DWORD *)nc_mallocz(0x80uLL);
  v13[4] = 1;
  v4 = v13;
  v13[5] = a1;
  v13[6] = 3;
  v14 = nc_malloc(0x18uLL);
  v4[4] = v14;
  while ( v10[v12] )
  {
    v15 = (_QWORD *)(v14 + v12 * 8);
    ++v12;
    *v15 = nc_dup_node();
    if ( v12 == 3 )
      goto LABEL_10;
LABEL_7:
    v14 = v4[4];
  }
  *(_QWORD *)(v14 + v12 * 8) = 0LL;
  if ( ++v12 != 3 )
    goto LABEL_7;
LABEL_10:
  v16 = *(_QWORD *)(v9 + 72);
  *(_QWORD *)(v9 + 72) = v16 + 1;
  v4[12] = v16;
  v17 = *(_QWORD *)(v9 + 32);
  *(_QWORD *)(v17 + 8) = v4;
  *v4 = v17;
  v4[1] = v9 + 32;
  *(_QWORD *)(v9 + 32) = v4;
  nc_free(v10);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v4;
  return v4;
}

