// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_mul
// Included functions: 4

// ======================================================
// Function: nc_mul @ 0x1DE70
// ======================================================

unsigned int *__fastcall nc_mul(unsigned int *ptr, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // r12
  __int64 v9; // r13
  unsigned int v10; // eax
  unsigned int *v11; // rbx
  int v12; // ecx
  int v13; // esi
  __int64 v14; // rax
  __int64 v15; // r12
  __int64 v16; // rdx
  __int64 v17; // rdi
  __int64 v18; // rsi
  void (__fastcall *v19)(__int64, __int64, __int64, _QWORD, __int64 *, __int64); // r10
  __int64 v20; // r9
  __int64 v21; // r8
  __int64 v22; // rdx
  __int64 v23; // r11
  int v24; // edx
  __int64 *v25; // rsi
  __int64 v26; // rcx
  unsigned int *v27; // r8
  __int64 v28; // rdi
  __int64 v29; // rdx
  __int64 v30; // rcx
  _QWORD *v31; // r12
  __int64 v32; // rax
  __int64 v33; // rdx
  int v34; // edx
  __int64 v35; // rdx
  int v36; // ecx
  __int64 v37; // rcx
  __int64 v38; // rcx
  int v39; // edx
  __int64 *v40; // rsi
  __int64 v41; // rcx
  unsigned int *v42; // r8
  __int64 v43; // rdi
  __int64 v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  bool v47; // zf
  _QWORD *v48; // r12
  int v50; // eax
  __int64 v51; // rdx
  int v52; // r15d
  int v53; // edx
  __int64 v54; // rax
  unsigned __int64 v55; // rdi
  __int64 v56; // rcx
  __int64 v57; // rcx
  int v58; // eax
  int v59; // esi
  __int64 *v60; // rcx
  __int64 v61; // rdx
  unsigned int *v62; // rdi
  __int64 v63; // rsi
  __int64 v64; // rax
  __int64 v65; // rdx
  int v66; // edx
  int v67; // edx
  __int64 v68; // [rsp+0h] [rbp-98h]
  __int64 *v69; // [rsp+0h] [rbp-98h]
  __int64 v70; // [rsp+8h] [rbp-90h]
  __int64 v71; // [rsp+10h] [rbp-88h]
  __int64 v72; // [rsp+10h] [rbp-88h]
  __int64 v73; // [rsp+18h] [rbp-80h]
  __int64 v74; // [rsp+20h] [rbp-78h]
  __int64 v75; // [rsp+28h] [rbp-70h] BYREF
  __int64 v76; // [rsp+30h] [rbp-68h] BYREF
  __int64 v77; // [rsp+38h] [rbp-60h]
  __int64 v78; // [rsp+40h] [rbp-58h] BYREF
  __int64 v79; // [rsp+48h] [rbp-50h]
  __int64 v80; // [rsp+50h] [rbp-48h]
  __int64 v81; // [rsp+58h] [rbp-40h]
  __int64 v82; // [rsp+60h] [rbp-38h]
  __int64 v83; // [rsp+68h] [rbp-30h]

  v9 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  v10 = ptr[12];
  if ( a2[12] != v10 || v10 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_mul");
  if ( v9 != *(_QWORD *)(*((_QWORD *)a2 + 5) + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( ptr[4] != 1 || *((_QWORD *)a2 + 4) )
    v11 = (unsigned int *)nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], ptr[20], ptr + 30);
  else
    v11 = ptr;
  v12 = ptr[20];
  v13 = a2[20];
  if ( v12 != v13 )
  {
    if ( v13 != 1 )
      goto LABEL_10;
    if ( v12 <= 0 )
      goto LABEL_168;
    if ( *((_QWORD *)a2 + 15) == *((_QWORD *)ptr + 15) )
    {
      if ( !*((_BYTE *)ptr + 73) || !*((_BYTE *)a2 + 73) )
        __assert_fail("x1->contig[0] && x2->contig[0]", "libnc.c", 0x171Bu, "nc_mul");
      v50 = sub_7F90(
              (_DWORD *)&v75 + 1,
              1,
              (__int64)v11,
              (__int64)ptr,
              0LL,
              a6,
              v68,
              *((_QWORD *)v11 + 15),
              v71,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83);
      v51 = ptr[12];
      v78 = 0LL;
      v72 = v50;
      v52 = dword_30520[v51];
      v53 = v11[20];
      if ( v53 <= 1 )
      {
        v14 = 0LL;
      }
      else
      {
        v54 = 1LL;
        do
          *(&v78 + v54++) = 0LL;
        while ( v53 > (int)v54 );
        v14 = v78;
      }
      while ( v14 != -1 )
      {
        v22 = ptr[20];
        v19 = (void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64 *, __int64))ptr[12];
        v20 = *((_QWORD *)a2 + 7);
        v69 = *(__int64 **)(v9 + 176);
        v55 = *((_QWORD *)ptr + 12);
        v18 = *((_QWORD *)ptr + 7);
        v21 = v55 >> v52;
        if ( (int)v22 <= 0 )
        {
          v56 = 0LL;
        }
        else
        {
          v56 = *((_QWORD *)ptr + 11) * v14;
          if ( (_DWORD)v22 != 1 )
          {
            v56 += v79 * v55;
            if ( (_DWORD)v22 != 2 )
            {
              v56 += *((_QWORD *)ptr + 13) * v80;
              if ( (_DWORD)v22 != 3 )
              {
                v17 = v81;
                v23 = *((_QWORD *)ptr + 14);
                if ( (_DWORD)v22 != 4 )
                  goto LABEL_86;
                v56 += v23 * v81;
              }
            }
          }
        }
        v6 = *((_QWORD *)v11 + 12);
        v17 = v11[20];
        v57 = v18 + v56;
        v23 = *((_QWORD *)v11 + 7);
        v22 = v6 >> v52;
        if ( (int)v17 <= 0 )
        {
          v14 = 0LL;
        }
        else
        {
          v14 *= *((_QWORD *)v11 + 11);
          if ( (_DWORD)v17 != 1 )
          {
            v6 *= v79;
            v14 += v6;
            if ( (_DWORD)v17 != 2 )
            {
              v14 += *((_QWORD *)v11 + 13) * v80;
              if ( (_DWORD)v17 != 3 )
              {
                v18 = v81;
                v6 = *((_QWORD *)v11 + 14);
                if ( (_DWORD)v17 != 4 )
                  goto LABEL_86;
                v14 += v6 * v81;
              }
            }
          }
        }
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64, void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64 *, __int64)))v69)(
          v9,
          v23 + v14,
          v22,
          v57,
          v21,
          v20,
          0LL,
          v70,
          v72,
          v19);
        v58 = HIDWORD(v75);
        v59 = v11[20];
        if ( SHIDWORD(v75) >= v59 )
          goto LABEL_147;
        v60 = &v78 + SHIDWORD(v75);
        v61 = *v60 + 1;
        *v60 = v61;
        if ( *(_QWORD *)&v11[2 * v58 + 30] == v61 )
        {
          v62 = &v11[2 * v58 + 2];
          v63 = (unsigned int)(~v58 + v59);
          v64 = 0LL;
          while ( 1 )
          {
            v60[v64] = 0LL;
            if ( v64 == v63 )
              break;
            v65 = v60[v64 + 1] + 1;
            v60[++v64] = v65;
            if ( v65 != *(_QWORD *)&v62[2 * v64 + 28] )
              goto LABEL_149;
          }
LABEL_147:
          v78 = -1LL;
          break;
        }
LABEL_149:
        v14 = v78;
      }
      v76 = (__int64)ptr;
      v77 = (__int64)a2;
      v31 = sub_17590(10, (__int64 *)v11 + 3, (void **)v11 + 4, &v76);
      goto LABEL_106;
    }
    goto LABEL_162;
  }
  if ( v12 > 0 )
  {
    if ( *((_QWORD *)a2 + 15) != *((_QWORD *)ptr + 15) )
    {
      if ( v13 != 1 )
      {
LABEL_10:
        if ( !v13 )
        {
          LODWORD(v14) = v11[20];
          if ( (int)v14 <= 0 )
          {
            HIDWORD(v75) = 0;
            v17 = 0LL;
            v78 = 0LL;
            v69 = (_QWORD *)(&dword_0 + 1);
            goto LABEL_29;
          }
          if ( !*((_BYTE *)v11 + 73) || !*((_BYTE *)ptr + 73) )
          {
            v69 = (_QWORD *)(&dword_0 + 1);
LABEL_25:
            HIDWORD(v75) = v13;
            v78 = 0LL;
            if ( (int)v14 <= 1 )
            {
              v17 = 0LL;
              goto LABEL_29;
            }
            goto LABEL_26;
          }
          v15 = *((_QWORD *)v11 + 15);
          if ( (_DWORD)v14 == 1 )
          {
            v13 = 1;
            goto LABEL_24;
          }
          if ( *((_BYTE *)v11 + 74) && *((_BYTE *)ptr + 74) )
          {
            v15 *= *((_QWORD *)v11 + 16);
            if ( (_DWORD)v14 == 2 )
            {
              v13 = 2;
              goto LABEL_24;
            }
            if ( *((_BYTE *)v11 + 75) && *((_BYTE *)ptr + 75) )
            {
              v15 *= *((_QWORD *)v11 + 17);
              if ( (_DWORD)v14 == 3 )
              {
                v13 = 3;
                goto LABEL_24;
              }
              if ( *((_BYTE *)v11 + 76) && *((_BYTE *)ptr + 76) )
              {
                v15 *= *((_QWORD *)v11 + 18);
                v13 = 4;
LABEL_24:
                v69 = (__int64 *)(int)v15;
                goto LABEL_25;
              }
              v66 = 3;
            }
            else
            {
              v66 = 2;
            }
          }
          else
          {
            v66 = 1;
          }
          HIDWORD(v75) = v66;
          v69 = (__int64 *)(int)v15;
          v78 = 0LL;
LABEL_26:
          v16 = 1LL;
          do
            *(&v78 + v16++) = 0LL;
          while ( (int)v14 > (int)v16 );
          v17 = v78;
LABEL_29:
          v6 = (unsigned __int64)&v78;
          while ( v17 != -1 )
          {
            v18 = ptr[20];
            v19 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64 *, __int64))(v9 + 184);
            v20 = ptr[12];
            v21 = *((_QWORD *)ptr + 7);
            if ( (int)v18 <= 0 )
            {
              v22 = 0LL;
            }
            else
            {
              v22 = *((_QWORD *)ptr + 11) * v17;
              if ( (_DWORD)v18 != 1 )
              {
                v22 += *((_QWORD *)ptr + 12) * v79;
                if ( (_DWORD)v18 != 2 )
                {
                  v22 += *((_QWORD *)ptr + 13) * v80;
                  if ( (_DWORD)v18 != 3 )
                  {
                    v23 = v81;
                    if ( (_DWORD)v18 != 4 )
                      goto LABEL_86;
                    v22 += *((_QWORD *)ptr + 14) * v81;
                  }
                }
              }
            }
            v22 += v21;
            v18 = *((_QWORD *)v11 + 7);
            if ( (int)v14 <= 0 )
            {
              v17 = 0LL;
            }
            else
            {
              v17 *= *((_QWORD *)v11 + 11);
              if ( (_DWORD)v14 != 1 )
              {
                v17 += *((_QWORD *)v11 + 12) * v79;
                if ( (_DWORD)v14 != 2 )
                {
                  v17 += *((_QWORD *)v11 + 13) * v80;
                  if ( (_DWORD)v14 != 3 )
                  {
                    v21 = v81;
                    v23 = *((_QWORD *)v11 + 14);
                    if ( (_DWORD)v14 != 4 )
                      goto LABEL_86;
                    v17 += v23 * v81;
                  }
                }
              }
            }
            v19(v9, v17 + v18, v22, *((_QWORD *)a2 + 7), v69, v20);
            v24 = HIDWORD(v75);
            LODWORD(v14) = v11[20];
            if ( SHIDWORD(v75) >= (int)v14 )
              goto LABEL_48;
            v25 = &v78 + SHIDWORD(v75);
            v26 = *v25 + 1;
            *v25 = v26;
            if ( *(_QWORD *)&v11[2 * v24 + 30] == v26 )
            {
              v27 = &v11[2 * v24 + 2];
              v28 = (unsigned int)(~v24 + v14);
              v29 = 0LL;
              while ( 1 )
              {
                v25[v29] = 0LL;
                if ( v28 == v29 )
                  break;
                v30 = v25[v29 + 1] + 1;
                v25[++v29] = v30;
                if ( v30 != *(_QWORD *)&v27[2 * v29 + 28] )
                  goto LABEL_115;
              }
LABEL_48:
              v78 = -1LL;
              break;
            }
LABEL_115:
            v17 = v78;
          }
          v76 = (__int64)ptr;
          v77 = (__int64)a2;
          v31 = sub_17590(11, (__int64 *)v11 + 3, (void **)v11 + 4, &v76);
          goto LABEL_106;
        }
LABEL_168:
        sub_18270("mul", (__int64)ptr, (__int64)a2);
      }
LABEL_162:
      __assert_fail("x1->dims[0] == x2->dims[0]", "libnc.c", 0x171Au, "nc_mul");
    }
    v32 = 1LL;
    while ( v12 > (int)v32 )
    {
      v33 = *(_QWORD *)&ptr[2 * v32++ + 30];
      if ( v33 != *(_QWORD *)&a2[2 * v32 + 28] )
        goto LABEL_10;
    }
  }
  LODWORD(v14) = v11[20];
  if ( (int)v14 <= 0 )
  {
    HIDWORD(v75) = 0;
    v6 = 1LL;
    v22 = 0LL;
    v78 = 0LL;
    goto LABEL_79;
  }
  if ( *((_BYTE *)v11 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)a2 + 73) )
  {
    v6 = *((_QWORD *)v11 + 15);
    if ( (_DWORD)v14 != 1 )
    {
      if ( *((_BYTE *)v11 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) )
      {
        v6 *= *((_QWORD *)v11 + 16);
        if ( (_DWORD)v14 == 2 )
        {
          v34 = 2;
          goto LABEL_74;
        }
        if ( *((_BYTE *)v11 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) )
        {
          v6 *= *((_QWORD *)v11 + 17);
          if ( (_DWORD)v14 == 3 )
          {
            v34 = 3;
            goto LABEL_74;
          }
          if ( *((_BYTE *)v11 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) )
          {
            v6 *= *((_QWORD *)v11 + 18);
            v34 = 4;
LABEL_74:
            v6 = (int)v6;
            goto LABEL_75;
          }
          v67 = 3;
        }
        else
        {
          v67 = 2;
        }
      }
      else
      {
        v67 = 1;
      }
      v6 = (int)v6;
      HIDWORD(v75) = v67;
      v78 = 0LL;
LABEL_76:
      v35 = 1LL;
      do
        *(&v78 + v35++) = 0LL;
      while ( (int)v14 > (int)v35 );
      v22 = v78;
      goto LABEL_79;
    }
    v34 = 1;
    goto LABEL_74;
  }
  v6 = 1LL;
  v34 = 0;
LABEL_75:
  HIDWORD(v75) = v34;
  v22 = 0LL;
  v78 = 0LL;
  if ( (int)v14 > 1 )
    goto LABEL_76;
LABEL_79:
  v69 = &v78;
  while ( 1 )
  {
    if ( v22 == -1 )
      goto LABEL_105;
    v36 = a2[20];
    v19 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64 *, __int64))(v9 + 176);
    v17 = ptr[12];
    v21 = *((_QWORD *)a2 + 7);
    if ( v36 > 0 )
    {
      v20 = *((_QWORD *)a2 + 11) * v22;
      if ( v36 != 1 )
      {
        v20 += *((_QWORD *)a2 + 12) * v79;
        if ( v36 != 2 )
        {
          v20 += *((_QWORD *)a2 + 13) * v80;
          if ( v36 != 3 )
          {
            v18 = v81;
            v23 = *((_QWORD *)a2 + 14);
            goto LABEL_86;
          }
        }
      }
      goto LABEL_87;
    }
    v18 = ptr[20];
    v20 = *((_QWORD *)a2 + 7);
    v21 = *((_QWORD *)ptr + 7);
    if ( (int)v18 > 0 )
    {
      while ( 1 )
      {
        v37 = *((_QWORD *)ptr + 11) * v22;
        if ( (_DWORD)v18 == 1 )
          break;
        v37 += *((_QWORD *)ptr + 12) * v79;
        if ( (_DWORD)v18 == 2 )
          break;
        v37 += *((_QWORD *)ptr + 13) * v80;
        if ( (_DWORD)v18 == 3 )
          break;
        v23 = v81;
        if ( (_DWORD)v18 == 4 )
        {
          v37 += *((_QWORD *)ptr + 14) * v81;
          break;
        }
LABEL_86:
        v20 += v23 * v18;
LABEL_87:
        v18 = ptr[20];
        v20 += v21;
        v21 = *((_QWORD *)ptr + 7);
        if ( (int)v18 <= 0 )
          goto LABEL_117;
      }
      v38 = v21 + v37;
      v18 = *((_QWORD *)v11 + 7);
      if ( (int)v14 <= 0 )
      {
LABEL_118:
        v22 = 0LL;
        goto LABEL_99;
      }
    }
    else
    {
LABEL_117:
      v18 = *((_QWORD *)v11 + 7);
      v38 = v21;
      if ( (int)v14 <= 0 )
        goto LABEL_118;
    }
    v22 *= *((_QWORD *)v11 + 11);
    if ( (_DWORD)v14 != 1 )
    {
      v22 += *((_QWORD *)v11 + 12) * v79;
      if ( (_DWORD)v14 != 2 )
      {
        v22 += *((_QWORD *)v11 + 13) * v80;
        if ( (_DWORD)v14 != 3 )
        {
          v21 = v81;
          v23 = *((_QWORD *)v11 + 14);
          if ( (_DWORD)v14 == 4 )
          {
            v22 += v23 * v81;
            goto LABEL_99;
          }
          goto LABEL_86;
        }
      }
    }
LABEL_99:
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, unsigned __int64, __int64, __int64))v19)(
      v9,
      v22 + v18,
      0LL,
      v38,
      0LL,
      v20,
      0LL,
      v6,
      1LL,
      v17);
    v39 = HIDWORD(v75);
    LODWORD(v14) = v11[20];
    if ( SHIDWORD(v75) >= (int)v14 )
      goto LABEL_104;
    v40 = &v69[SHIDWORD(v75)];
    v41 = *v40 + 1;
    *v40 = v41;
    if ( v41 == *(_QWORD *)&v11[2 * v39 + 30] )
      break;
LABEL_114:
    v22 = v78;
  }
  v42 = &v11[2 * v39 + 2];
  v43 = (unsigned int)(~v39 + v14);
  v44 = 0LL;
  while ( 1 )
  {
    v40[v44] = 0LL;
    if ( v43 == v44 )
      break;
    v45 = v40[v44 + 1] + 1;
    v40[++v44] = v45;
    if ( v45 != *(_QWORD *)&v42[2 * v44 + 28] )
      goto LABEL_114;
  }
LABEL_104:
  v78 = -1LL;
LABEL_105:
  v76 = (__int64)ptr;
  v77 = (__int64)a2;
  v31 = sub_17590(9, (__int64 *)v11 + 3, (void **)v11 + 4, &v76);
LABEL_106:
  if ( v31 )
  {
    *((_DWORD *)v31 + 10) = 2;
    v46 = nc_mallocz(0x10uLL);
    v47 = *((_QWORD *)ptr + 4) == 0LL;
    v31[6] = v46;
    if ( !v47 )
      *(_QWORD *)(v46 + 8) = nc_dup_tensor(a2);
    if ( *((_QWORD *)a2 + 4) )
    {
      v48 = (_QWORD *)v31[6];
      *v48 = nc_dup_tensor(ptr);
    }
  }
  if ( v11 != ptr )
    nc_free_tensor(ptr);
  nc_free_tensor(a2);
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

