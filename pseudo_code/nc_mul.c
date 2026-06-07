// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_mul
// Included functions: 6

// ======================================================
// Function: nc_mul @ 0x66A1FD20
// ======================================================

_QWORD *__fastcall nc_mul(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // r14
  __int64 v3; // rbp
  unsigned int v6; // edx
  _QWORD *v7; // rbx
  int v8; // ecx
  int v9; // r8d
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rdx
  unsigned __int64 v15; // r11
  __int64 v16; // r13
  __int64 v17; // r10
  __int64 v18; // r8
  int v19; // edx
  __int64 *v20; // r8
  __int64 v21; // rcx
  _QWORD *v22; // r10
  __int64 v23; // r9
  __int64 v24; // rdx
  __int64 v25; // rcx
  _QWORD *v26; // rdi
  __int64 v27; // rax
  __int64 v28; // rdx
  int v29; // edx
  __int64 v30; // rdx
  int v31; // r9d
  __int64 v32; // r9
  __int64 v33; // r9
  int v34; // edx
  __int64 *v35; // r8
  __int64 v36; // rcx
  _QWORD *v37; // r10
  __int64 v38; // r9
  __int64 v39; // rdx
  __int64 v40; // rcx
  _QWORD *v41; // rax
  bool v42; // zf
  int v44; // eax
  __int64 v45; // rdx
  int v46; // r15d
  int v47; // edx
  __int64 v48; // rax
  unsigned __int64 v49; // r8
  __int64 v50; // r9
  __int64 v51; // r9
  int v52; // eax
  int v53; // r8d
  __int64 *v54; // rcx
  __int64 v55; // rdx
  _QWORD *v56; // r9
  __int64 v57; // r8
  __int64 v58; // rax
  __int64 v59; // rdx
  int v60; // edx
  int v61; // edx
  __int64 v62; // [rsp+28h] [rbp-D0h]
  __int64 v63; // [rsp+30h] [rbp-C8h]
  __int64 v64; // [rsp+38h] [rbp-C0h]
  __int64 v65; // [rsp+40h] [rbp-B8h]
  __int64 v66; // [rsp+48h] [rbp-B0h]
  __int64 v67; // [rsp+50h] [rbp-A8h]
  __int64 *v68; // [rsp+50h] [rbp-A8h]
  __int64 v69; // [rsp+58h] [rbp-A0h]
  __int64 v70; // [rsp+60h] [rbp-98h]
  __int64 v71; // [rsp+60h] [rbp-98h]
  __int64 v72; // [rsp+68h] [rbp-90h]
  __int64 v73; // [rsp+70h] [rbp-88h]
  __int64 v74; // [rsp+78h] [rbp-80h] BYREF
  __int64 v75; // [rsp+80h] [rbp-78h] BYREF
  __int64 v76; // [rsp+88h] [rbp-70h]
  __int64 v77; // [rsp+90h] [rbp-68h] BYREF
  __int64 v78; // [rsp+98h] [rbp-60h]
  __int64 v79; // [rsp+A0h] [rbp-58h]
  unsigned __int64 v80; // [rsp+A8h] [rbp-50h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v6 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a2 + 48) != v6 || v6 > 1 )
    nc_error("unsupported type for %s\n", "nc_mul");
  if ( v3 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a1 + 16) != 1 || *(_QWORD *)(a2 + 32) )
    v7 = nc_new_tensor_nz(v3, v6, *(_DWORD *)(a1 + 80), a1 + 120);
  else
    v7 = (_QWORD *)a1;
  v8 = *(_DWORD *)(a1 + 80);
  v9 = *(_DWORD *)(a2 + 80);
  if ( v8 != v9 )
  {
    if ( v9 != 1 )
      goto LABEL_8;
    if ( v8 <= 0 )
      goto LABEL_172;
    if ( *(_QWORD *)(a2 + 120) == *(_QWORD *)(a1 + 120) )
    {
LABEL_122:
      if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
        sub_66A33D40("x1->contig[0] && x2->contig[0]", "libnc.c", 5915);
      v44 = sub_66A05420(
              (_DWORD *)&v74 + 1,
              1,
              (__int64)v7,
              a1,
              0i64,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v7[15],
              v70,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78);
      v45 = *(unsigned int *)(a1 + 48);
      v77 = 0i64;
      v71 = v44;
      v46 = dword_66A375E0[v45];
      v47 = *((_DWORD *)v7 + 20);
      if ( v47 <= 1 )
      {
        v10 = 0i64;
      }
      else
      {
        v48 = 1i64;
        do
          *(&v77 + v48++) = 0i64;
        while ( v47 > (int)v48 );
        v10 = v77;
      }
      while ( v10 != -1 )
      {
        v49 = *(_QWORD *)(a1 + 96);
        v14 = *(unsigned int *)(a1 + 80);
        v16 = *(unsigned int *)(a1 + 48);
        v68 = *(__int64 **)(v3 + 176);
        v15 = v49 >> v46;
        v11 = *(_QWORD *)(a2 + 56);
        v13 = *(_QWORD *)(a1 + 56);
        if ( (int)v14 <= 0 )
        {
          v50 = 0i64;
        }
        else
        {
          v50 = *(_QWORD *)(a1 + 88) * v10;
          if ( (_DWORD)v14 != 1 )
          {
            v50 += v78 * v49;
            if ( (_DWORD)v14 != 2 )
            {
              v50 += *(_QWORD *)(a1 + 104) * v79;
              if ( (_DWORD)v14 != 3 )
              {
                v18 = v80;
                v17 = *(_QWORD *)(a1 + 112);
                if ( (_DWORD)v14 != 4 )
                  goto LABEL_84;
                v50 += v17 * v80;
              }
            }
          }
        }
        v51 = v13 + v50;
        v2 = v7[12];
        v13 = *((unsigned int *)v7 + 20);
        v17 = v7[7];
        v18 = v2 >> v46;
        if ( (int)v13 <= 0 )
        {
          v10 = 0i64;
        }
        else
        {
          v10 *= v7[11];
          if ( (_DWORD)v13 != 1 )
          {
            v2 *= v78;
            v10 += v2;
            if ( (_DWORD)v13 != 2 )
            {
              v10 += v7[13] * v79;
              if ( (_DWORD)v13 != 3 )
              {
                v14 = v80;
                v2 = v7[14];
                if ( (_DWORD)v13 != 4 )
                  goto LABEL_84;
                v10 += v2 * v80;
              }
            }
          }
        }
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, unsigned __int64, __int64, _QWORD, __int64, __int64, _DWORD))v68)(
          v3,
          v17 + v10,
          v18,
          v51,
          v15,
          v11,
          0i64,
          v69,
          v71,
          v16);
        v52 = HIDWORD(v74);
        v53 = *((_DWORD *)v7 + 20);
        if ( SHIDWORD(v74) >= v53 )
          goto LABEL_146;
        v54 = &v77 + SHIDWORD(v74);
        v55 = *v54 + 1;
        *v54 = v55;
        if ( v7[v52 + 15] == v55 )
        {
          v56 = &v7[v52 + 1];
          v57 = (unsigned int)(~v52 + v53);
          v58 = 0i64;
          while ( 1 )
          {
            v54[v58] = 0i64;
            if ( v58 == v57 )
              break;
            v59 = v54[v58 + 1] + 1;
            v54[++v58] = v59;
            if ( v59 != v56[v58 + 14] )
              goto LABEL_149;
          }
LABEL_146:
          v77 = -1i64;
          break;
        }
LABEL_149:
        v10 = v77;
      }
      v75 = a1;
      v76 = a2;
      v26 = sub_66A15DA0(10, v7 + 3, (__int64 **)v7 + 4, 2, (__int64)&v75);
      goto LABEL_104;
    }
LABEL_121:
    sub_66A33D40("x1->dims[0] == x2->dims[0]", "libnc.c", 5914);
    goto LABEL_122;
  }
  if ( v8 > 0 )
  {
    if ( *(_QWORD *)(a2 + 120) != *(_QWORD *)(a1 + 120) )
    {
      if ( v9 != 1 )
      {
LABEL_8:
        if ( !v9 )
        {
          LODWORD(v10) = *((_DWORD *)v7 + 20);
          if ( (int)v10 <= 0 )
          {
            HIDWORD(v74) = 0;
            v11 = 1i64;
            v13 = 0i64;
            v77 = 0i64;
            goto LABEL_27;
          }
          if ( !*((_BYTE *)v7 + 73) || !*(_BYTE *)(a1 + 73) )
          {
            v11 = 1i64;
LABEL_23:
            HIDWORD(v74) = v9;
            v77 = 0i64;
            if ( (int)v10 <= 1 )
            {
              v13 = 0i64;
              goto LABEL_27;
            }
            goto LABEL_24;
          }
          v11 = v7[15];
          if ( (_DWORD)v10 == 1 )
          {
            v9 = 1;
            goto LABEL_22;
          }
          if ( *((_BYTE *)v7 + 74) && *(_BYTE *)(a1 + 74) )
          {
            v11 *= v7[16];
            if ( (_DWORD)v10 == 2 )
            {
              v9 = 2;
              goto LABEL_22;
            }
            if ( *((_BYTE *)v7 + 75) && *(_BYTE *)(a1 + 75) )
            {
              v11 *= v7[17];
              if ( (_DWORD)v10 == 3 )
              {
                v9 = 3;
                goto LABEL_22;
              }
              if ( *((_BYTE *)v7 + 76) && *(_BYTE *)(a1 + 76) )
              {
                v11 *= v7[18];
                v9 = 4;
LABEL_22:
                v11 = (int)v11;
                goto LABEL_23;
              }
              v60 = 3;
            }
            else
            {
              v60 = 2;
            }
          }
          else
          {
            v60 = 1;
          }
          v11 = (int)v11;
          HIDWORD(v74) = v60;
          v77 = 0i64;
LABEL_24:
          v12 = 1i64;
          do
            *(&v77 + v12++) = 0i64;
          while ( (int)v10 > (int)v12 );
          v13 = v77;
LABEL_27:
          v68 = &v77;
          while ( v13 != -1 )
          {
            v14 = *(unsigned int *)(a1 + 80);
            v15 = *(_QWORD *)(v3 + 184);
            v16 = *(unsigned int *)(a1 + 48);
            v17 = *(_QWORD *)(a1 + 56);
            if ( (int)v14 <= 0 )
            {
              v18 = 0i64;
            }
            else
            {
              v18 = *(_QWORD *)(a1 + 88) * v13;
              if ( (_DWORD)v14 != 1 )
              {
                v18 += *(_QWORD *)(a1 + 96) * v78;
                if ( (_DWORD)v14 != 2 )
                {
                  v18 += *(_QWORD *)(a1 + 104) * v79;
                  if ( (_DWORD)v14 != 3 )
                  {
                    v2 = v80;
                    if ( (_DWORD)v14 != 4 )
                      goto LABEL_84;
                    v18 += *(_QWORD *)(a1 + 112) * v80;
                  }
                }
              }
            }
            v18 += v17;
            v14 = v7[7];
            if ( (int)v10 <= 0 )
            {
              v13 = 0i64;
            }
            else
            {
              v13 *= v7[11];
              if ( (_DWORD)v10 != 1 )
              {
                v13 += v7[12] * v78;
                if ( (_DWORD)v10 != 2 )
                {
                  v13 += v7[13] * v79;
                  if ( (_DWORD)v10 != 3 )
                  {
                    v17 = v80;
                    v2 = v7[14];
                    if ( (_DWORD)v10 != 4 )
                      goto LABEL_84;
                    v13 += v2 * v80;
                  }
                }
              }
            }
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _DWORD))v15)(
              v3,
              v13 + v14,
              v18,
              *(_QWORD *)(a2 + 56),
              v11,
              *(_DWORD *)(a1 + 48));
            v19 = HIDWORD(v74);
            LODWORD(v10) = *((_DWORD *)v7 + 20);
            if ( SHIDWORD(v74) >= (int)v10 )
              goto LABEL_46;
            v20 = &v77 + SHIDWORD(v74);
            v21 = *v20 + 1;
            *v20 = v21;
            if ( v21 == v7[v19 + 15] )
            {
              v22 = &v7[v19 + 1];
              v23 = (unsigned int)(~v19 + v10);
              v24 = 0i64;
              while ( 1 )
              {
                v20[v24] = 0i64;
                if ( v23 == v24 )
                  break;
                v25 = v20[v24 + 1] + 1;
                v20[++v24] = v25;
                if ( v25 != v22[v24 + 14] )
                  goto LABEL_113;
              }
LABEL_46:
              v77 = -1i64;
              break;
            }
LABEL_113:
            v13 = v77;
          }
          v75 = a1;
          v76 = a2;
          v26 = sub_66A15DA0(11, v7 + 3, (__int64 **)v7 + 4, 2, (__int64)&v75);
          goto LABEL_104;
        }
LABEL_172:
        sub_66A16930("mul", a1, a2);
      }
      goto LABEL_121;
    }
    v27 = 1i64;
    while ( v8 > (int)v27 )
    {
      v28 = *(_QWORD *)(a1 + 8 * v27++ + 120);
      if ( v28 != *(_QWORD *)(a2 + 8 * v27 + 112) )
        goto LABEL_8;
    }
  }
  LODWORD(v10) = *((_DWORD *)v7 + 20);
  if ( (int)v10 <= 0 )
  {
    HIDWORD(v74) = 0;
    v11 = 1i64;
    v13 = 0i64;
    v77 = 0i64;
    goto LABEL_77;
  }
  if ( !*((_BYTE *)v7 + 73) || !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
  {
    v11 = 1i64;
    v29 = 0;
LABEL_73:
    HIDWORD(v74) = v29;
    v13 = 0i64;
    v77 = 0i64;
    if ( (int)v10 <= 1 )
      goto LABEL_77;
    goto LABEL_74;
  }
  v11 = v7[15];
  if ( (_DWORD)v10 == 1 )
  {
    v29 = 1;
    goto LABEL_72;
  }
  if ( *((_BYTE *)v7 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
  {
    v11 *= v7[16];
    if ( (_DWORD)v10 == 2 )
    {
      v29 = 2;
      goto LABEL_72;
    }
    if ( *((_BYTE *)v7 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
    {
      v11 *= v7[17];
      if ( (_DWORD)v10 == 3 )
      {
        v29 = 3;
        goto LABEL_72;
      }
      if ( *((_BYTE *)v7 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
      {
        v11 *= v7[18];
        v29 = 4;
LABEL_72:
        v11 = (int)v11;
        goto LABEL_73;
      }
      v61 = 3;
    }
    else
    {
      v61 = 2;
    }
  }
  else
  {
    v61 = 1;
  }
  v11 = (int)v11;
  HIDWORD(v74) = v61;
  v77 = 0i64;
LABEL_74:
  v30 = 1i64;
  do
    *(&v77 + v30++) = 0i64;
  while ( (int)v10 > (int)v30 );
  v13 = v77;
LABEL_77:
  v68 = &v77;
  while ( 2 )
  {
    if ( v13 == -1 )
      goto LABEL_103;
    v31 = *(_DWORD *)(a2 + 80);
    v17 = *(_QWORD *)(v3 + 176);
    LODWORD(v15) = *(_DWORD *)(a1 + 48);
    v18 = *(_QWORD *)(a2 + 56);
    if ( v31 > 0 )
    {
      v14 = *(_QWORD *)(a2 + 88) * v13;
      if ( v31 != 1 )
      {
        v14 += *(_QWORD *)(a2 + 96) * v78;
        if ( v31 != 2 )
        {
          v14 += *(_QWORD *)(a2 + 104) * v79;
          if ( v31 != 3 )
          {
            v16 = v80;
            v2 = *(_QWORD *)(a2 + 112);
            goto LABEL_84;
          }
        }
      }
      goto LABEL_85;
    }
    v16 = *(_QWORD *)(a1 + 56);
    v14 = *(unsigned int *)(a1 + 80);
    if ( (int)v14 <= 0 )
    {
LABEL_116:
      v32 = 0i64;
      goto LABEL_91;
    }
    while ( 1 )
    {
      v32 = *(_QWORD *)(a1 + 88) * v13;
      if ( (_DWORD)v14 != 1 )
      {
        v32 += *(_QWORD *)(a1 + 96) * v78;
        if ( (_DWORD)v14 != 2 )
        {
          v32 += *(_QWORD *)(a1 + 104) * v79;
          if ( (_DWORD)v14 != 3 )
          {
            v2 = v80;
            if ( (_DWORD)v14 != 4 )
              goto LABEL_84;
            v32 += *(_QWORD *)(a1 + 112) * v80;
          }
        }
      }
LABEL_91:
      v33 = v16 + v32;
      v14 = v7[7];
      if ( (int)v10 <= 0 )
        break;
      v13 *= v7[11];
      if ( (_DWORD)v10 == 1 )
        goto LABEL_97;
      v13 += v7[12] * v78;
      if ( (_DWORD)v10 == 2 )
        goto LABEL_97;
      v13 += v7[13] * v79;
      if ( (_DWORD)v10 == 3 )
        goto LABEL_97;
      v16 = v80;
      v2 = v7[14];
      if ( (_DWORD)v10 == 4 )
      {
        v13 += v2 * v80;
        goto LABEL_97;
      }
LABEL_84:
      v14 += v2 * v16;
LABEL_85:
      v18 += v14;
      v14 = *(unsigned int *)(a1 + 80);
      v16 = *(_QWORD *)(a1 + 56);
      if ( (int)v14 <= 0 )
        goto LABEL_116;
    }
    v13 = 0i64;
LABEL_97:
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))v17)(
      v3,
      v13 + v14,
      0i64,
      v33,
      0i64,
      v18,
      0i64,
      v11,
      1i64,
      v15);
    v34 = HIDWORD(v74);
    LODWORD(v10) = *((_DWORD *)v7 + 20);
    if ( SHIDWORD(v74) >= (int)v10 )
      goto LABEL_102;
    v35 = &v68[SHIDWORD(v74)];
    v36 = *v35 + 1;
    *v35 = v36;
    if ( v36 != v7[v34 + 15] )
    {
LABEL_112:
      v13 = v77;
      continue;
    }
    break;
  }
  v37 = &v7[v34 + 1];
  v38 = (unsigned int)(~v34 + v10);
  v39 = 0i64;
  while ( 1 )
  {
    v35[v39] = 0i64;
    if ( v38 == v39 )
      break;
    v40 = v35[v39 + 1] + 1;
    v35[++v39] = v40;
    if ( v40 != v37[v39 + 14] )
      goto LABEL_112;
  }
LABEL_102:
  v77 = -1i64;
LABEL_103:
  v75 = a1;
  v76 = a2;
  v26 = sub_66A15DA0(9, v7 + 3, (__int64 **)v7 + 4, 2, (__int64)&v75);
LABEL_104:
  if ( v26 )
  {
    *((_DWORD *)v26 + 10) = 2;
    v41 = nc_mallocz(0x10ui64);
    v42 = *(_QWORD *)(a1 + 32) == 0i64;
    v26[6] = v41;
    if ( !v42 )
    {
      ++*(_DWORD *)(a2 + 16);
      v41[1] = a2;
    }
    if ( *(_QWORD *)(a2 + 32) )
    {
      ++*(_DWORD *)(a1 + 16);
      *v41 = a1;
    }
  }
  if ( v7 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v7;
}

// ======================================================
// Function: sub_66A33D40 @ 0x66A33D40
// ======================================================

void __fastcall sub_66A33D40(const char *a1, const char *a2, int a3)
{
  size_t v5; // rax
  wchar_t *v6; // rsi
  size_t v7; // rax
  const wchar_t *v8; // rax
  wchar_t v9; // cx
  __int64 v10; // r9
  wchar_t *v11; // rbx
  wchar_t v12; // cx
  __int64 v13; // r9

  v5 = strlen(a1);
  v6 = (wchar_t *)malloc(2 * v5 + 2);
  v7 = strlen(a2);
  v8 = (const wchar_t *)malloc(2 * v7 + 2);
  v9 = *(unsigned __int8 *)a1;
  v10 = 0i64;
  v11 = (wchar_t *)v8;
  if ( (_BYTE)v9 )
  {
    do
    {
      v6[v10++] = v9;
      v9 = (unsigned __int8)a1[v10];
    }
    while ( (_BYTE)v9 );
    v10 *= 2i64;
  }
  v12 = *(unsigned __int8 *)a2;
  *(wchar_t *)((char *)v6 + v10) = 0;
  v13 = 0i64;
  if ( (_BYTE)v12 )
  {
    do
    {
      v8[v13++] = v12;
      v12 = (unsigned __int8)a2[v13];
    }
    while ( (_BYTE)v12 );
    v13 *= 2i64;
  }
  *(const wchar_t *)((char *)v8 + v13) = 0;
  sub_66A33C00(v6, v8, a3);
  free(v6);
  free(v11);
}

// ======================================================
// Function: sub_66A33C00 @ 0x66A33C00
// ======================================================

int __fastcall sub_66A33C00(const wchar_t *a1, const wchar_t *a2, int a3)
{
  wchar_t *v6; // rbp
  int result; // eax
  FILE *v8; // rax
  WCHAR Filename[284]; // [rsp+40h] [rbp-238h] BYREF

  v6 = (wchar_t *)malloc(0x4000ui64);
  if ( a2 )
  {
    if ( !*a2 )
      a2 = L"<unknown>";
  }
  else
  {
    a2 = L"<unknown>";
  }
  if ( a1 )
  {
    if ( !*a1 )
      a1 = L"?";
  }
  else
  {
    a1 = L"?";
  }
  if ( !GetModuleFileNameW(0i64, Filename, 0x104u) )
    wcscpy(Filename, L"<unknown>");
  snwprintf(
    v6,
    0x1FFFui64,
    L"Assertion failed!\n\nProgram: %ws\nFile: %ws, Line %u\n\nExpression: %ws",
    Filename,
    a2,
    a3,
    a1);
  if ( !unk_66A3D5B0 )
  {
    v8 = _iob_func();
    fwprintf(v8 + 2, L"%ws\n", v6);
    abort();
  }
  result = MessageBoxW(0i64, v6, L"MinGW Runtime Assertion", 0x12012u);
  if ( result == 3 )
  {
    raise(22);
    exit(3);
  }
  if ( result != 5 )
    abort();
  return result;
}

// ======================================================
// Function: sub_66A05420 @ 0x66A05420
// ======================================================

__int64 __fastcall sub_66A05420(
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
  int v20; // eax
  __int64 v21; // r9
  __int64 result; // rax
  int v23; // r10d
  unsigned __int64 v24; // [rsp+58h] [rbp-F0h]
  int v25; // [rsp+6Ch] [rbp-DCh]
  __int64 v26; // [rsp+80h] [rbp-C8h]
  __int64 v27; // [rsp+88h] [rbp-C0h]
  __int64 v28; // [rsp+90h] [rbp-B8h]
  __int64 v29; // [rsp+98h] [rbp-B0h]
  __int64 v30; // [rsp+A0h] [rbp-A8h]
  __int64 v31; // [rsp+A8h] [rbp-A0h]
  __int64 v32; // [rsp+B0h] [rbp-98h]
  __int64 v33; // [rsp+B8h] [rbp-90h]
  __int64 v34; // [rsp+C0h] [rbp-88h]
  __int64 v35; // [rsp+C8h] [rbp-80h]
  __int64 v36; // [rsp+D0h] [rbp-78h]
  __int64 v37; // [rsp+D8h] [rbp-70h]
  __int64 v38; // [rsp+E0h] [rbp-68h]
  __int64 v39; // [rsp+E8h] [rbp-60h]
  __int64 v40; // [rsp+F0h] [rbp-58h]
  __int64 v41; // [rsp+F8h] [rbp-50h]

  if ( a4 )
  {
    v26 = a4;
    if ( !a5 )
    {
      v25 = 1;
      goto LABEL_20;
    }
    v27 = a5;
    if ( !a6 )
    {
      v25 = 2;
      goto LABEL_20;
    }
    v28 = a6;
    if ( !a7 )
    {
      v25 = 3;
      goto LABEL_20;
    }
    v29 = a7;
    if ( !a8 )
    {
      v25 = 4;
      goto LABEL_20;
    }
    v30 = a8;
    if ( !a9 )
    {
      v25 = 5;
      goto LABEL_20;
    }
    v31 = a9;
    if ( !a10 )
    {
      v25 = 6;
      goto LABEL_20;
    }
    v32 = a10;
    if ( !a11 )
    {
      v25 = 7;
      goto LABEL_20;
    }
    v33 = a11;
    if ( !a12 )
    {
      v25 = 8;
      goto LABEL_20;
    }
    v34 = a12;
    if ( !a13 )
    {
      v25 = 9;
      goto LABEL_20;
    }
    v35 = a13;
    if ( !a14 )
    {
      v25 = 10;
      goto LABEL_20;
    }
    v36 = a14;
    if ( !a15 )
    {
      v25 = 11;
      goto LABEL_20;
    }
    v37 = a15;
    if ( !a16 )
    {
      v25 = 12;
      goto LABEL_20;
    }
    v38 = a16;
    if ( !a17 )
    {
      v25 = 13;
      goto LABEL_20;
    }
    v39 = a17;
    if ( !a18 )
    {
      v25 = 14;
      goto LABEL_20;
    }
    v40 = a18;
    if ( !a19 )
    {
      v25 = 15;
      goto LABEL_20;
    }
    v41 = a19;
    if ( !a20 )
    {
      v25 = 16;
      goto LABEL_20;
    }
    sub_66A33D40("count < countof(tab)", "libnc.c", 4653);
  }
  v25 = 0;
LABEL_20:
  v20 = *(_DWORD *)(a3 + 80);
  if ( a2 < v20 && (v21 = a2, *(_BYTE *)(a3 + a2 + 73)) )
  {
    v24 = a2 + (unsigned __int64)(unsigned int)(v20 - 1 - a2);
    result = 1i64;
    do
    {
      v23 = v21;
      if ( v25
        && (!*(_BYTE *)(v26 + v21 + 73)
         || v25 != 1
         && (!*(_BYTE *)(v27 + v21 + 73)
          || v25 != 2
          && (!*(_BYTE *)(v28 + v21 + 73)
           || v25 != 3
           && (!*(_BYTE *)(v29 + v21 + 73)
            || v25 != 4
            && (!*(_BYTE *)(v30 + v21 + 73)
             || v25 != 5
             && (!*(_BYTE *)(v31 + v21 + 73)
              || v25 != 6
              && (!*(_BYTE *)(v32 + v21 + 73)
               || v25 != 7
               && (!*(_BYTE *)(v33 + v21 + 73)
                || v25 != 8
                && (!*(_BYTE *)(v34 + v21 + 73)
                 || v25 != 9
                 && (!*(_BYTE *)(v35 + v21 + 73)
                  || v25 != 10
                  && (!*(_BYTE *)(v36 + v21 + 73)
                   || v25 != 11
                   && (!*(_BYTE *)(v37 + v21 + 73)
                    || v25 != 12
                    && (!*(_BYTE *)(v38 + v21 + 73)
                     || v25 != 13
                     && (!*(_BYTE *)(v39 + v21 + 73)
                      || v25 != 14 && (!*(_BYTE *)(v40 + v21 + 73) || v25 == 16 && !*(_BYTE *)(v41 + v21 + 73)))))))))))))))) )
      {
        break;
      }
      v23 = v21 + 1;
      result *= *(_QWORD *)(a3 + 8 * v21 + 120);
      if ( v21 == v24 )
        break;
      ++v21;
    }
    while ( *(_BYTE *)(a3 + 1 + v21 + 72) );
    a2 = v23;
  }
  else
  {
    result = 1i64;
  }
  *a1 = a2;
  return result;
}

// ======================================================
// Function: sub_66A15DA0 @ 0x66A15DA0
// ======================================================

_QWORD *__fastcall sub_66A15DA0(int a1, __int64 *a2, __int64 **a3, int a4, __int64 a5)
{
  _QWORD *result; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  void *v11; // r15
  __int64 v12; // rax
  __int64 v13; // r13
  _QWORD *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rax
  size_t v20; // r12
  void *v21; // rax

  if ( a4 <= 0 )
  {
    if ( !a4 )
      return 0i64;
    v20 = 8i64 * a4;
    v21 = aligned_malloc(v20, 0x40ui64);
    v13 = *a2;
    v11 = v21;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v14[4] = aligned_malloc(v20, 0x40ui64);
LABEL_13:
      v18 = *(_QWORD *)(v13 + 72);
      *(_QWORD *)(v13 + 72) = v18 + 1;
      v14[12] = v18;
      v19 = *(_QWORD *)(v13 + 32);
      *(_QWORD *)(v19 + 8) = v14;
      *v14 = v19;
      v14[1] = v13 + 32;
      *(_QWORD *)(v13 + 32) = v14;
      _aligned_free(v11);
      if ( *a3 )
        nc_free_node(*a3);
      *a3 = v14;
      return v14;
    }
LABEL_22:
    MEMORY[0x10] = 0;
    BUG();
  }
  result = *(_QWORD **)(*(_QWORD *)a5 + 32i64);
  if ( result )
    goto LABEL_7;
  v9 = 1i64;
  while ( (int)v9 < a4 )
  {
    v10 = *(_QWORD *)(a5 + 8 * v9++);
    if ( *(_QWORD *)(v10 + 32) )
      goto LABEL_7;
  }
  if ( (_DWORD)v9 != a4 )
  {
LABEL_7:
    v11 = aligned_malloc(8i64 * a4, 0x40ui64);
    v12 = 0i64;
    do
    {
      *((_QWORD *)v11 + v12) = *(_QWORD *)(*(_QWORD *)(a5 + 8 * v12) + 32i64);
      ++v12;
    }
    while ( a4 > (int)v12 );
    v13 = *a2;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v15 = aligned_malloc(8i64 * a4, 0x40ui64);
      v16 = 0i64;
      v14[4] = v15;
      do
      {
        while ( 1 )
        {
          v17 = *((_QWORD *)v11 + v16);
          if ( !v17 )
            break;
          ++*(_DWORD *)(v17 + 16);
          v15[v16++] = v17;
          if ( a4 <= (int)v16 )
            goto LABEL_13;
        }
        v15[v16++] = 0i64;
      }
      while ( a4 > (int)v16 );
      goto LABEL_13;
    }
    goto LABEL_22;
  }
  return result;
}

// ======================================================
// Function: sub_66A16930 @ 0x66A16930
// ======================================================

void __fastcall __noreturn sub_66A16930(const char *a1, __int64 a2, __int64 a3)
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

