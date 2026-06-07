// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_copy
// Included functions: 3

// ======================================================
// Function: nc_tensor_copy @ 0x66A17640
// ======================================================

__int64 __fastcall nc_tensor_copy(__int64 a1, __int64 a2)
{
  __int64 v2; // r12
  __int64 v4; // rbp
  __int64 result; // rax
  int v7; // r8d
  __int64 v8; // r14
  int v9; // ecx
  __int64 v10; // rax
  __int64 *v11; // rbx
  __int64 v12; // r13
  unsigned __int64 v13; // r10
  __int64 v14; // r9
  int v15; // edx
  __int64 v16; // rcx
  __int64 v17; // r8
  unsigned __int64 v18; // r11
  __int64 v19; // r15
  int v20; // ecx
  __int64 v21; // rax
  int v22; // ecx
  __int64 v23; // rdx
  int v24; // ecx
  __int64 v25; // rax
  int v26; // edx
  int v27; // ecx
  __int64 v28; // rax
  int v29; // ecx
  __int64 v30; // rdx
  __int64 v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // rdx
  __int64 v34; // r9
  __int64 v35; // rcx
  int v36; // r10d
  int v37; // r9d
  __int64 v38; // rcx
  __int64 v39; // rcx
  __int64 v40; // r12
  __int64 v41; // r10
  __int64 v42; // rdx
  __int64 v43; // rdx
  __int64 v44; // rdx
  __int64 v45; // rdx
  __int64 v46; // rcx
  __int64 v47; // rcx
  __int64 v48; // r11
  int v49; // r9d
  __int64 v50; // r9
  __int64 v51; // r14
  __int64 v52; // r10
  __int64 v53; // rcx
  __int64 v54; // rdx
  __int64 v55; // rdx
  __int64 v56; // rdx
  __int64 v57; // rdx
  __int64 v58; // rcx
  __int64 v59; // rdx
  __int64 v60; // rdx
  __int64 v61; // rdx
  __int64 v62; // rdx
  __int64 v63; // rcx
  __int64 v64; // rdx
  __int16 *v65; // r9
  unsigned __int64 v66; // rcx
  __int16 *v67; // r8
  __int64 i; // rdx
  __int16 v69; // ax
  __int64 v70; // rcx
  __int64 v71; // [rsp+60h] [rbp-D8h]
  __int64 v72; // [rsp+68h] [rbp-D0h]
  unsigned int v73; // [rsp+68h] [rbp-D0h]
  __int64 v74; // [rsp+70h] [rbp-C8h]
  __int64 v75; // [rsp+90h] [rbp-A8h]
  __int64 v76; // [rsp+A0h] [rbp-98h]
  __int64 v77; // [rsp+A8h] [rbp-90h]
  __int64 v78; // [rsp+B0h] [rbp-88h] BYREF
  __int64 v79; // [rsp+B8h] [rbp-80h]
  __int64 v80; // [rsp+C0h] [rbp-78h]
  unsigned __int64 v81; // [rsp+C8h] [rbp-70h]
  __int64 v82; // [rsp+D0h] [rbp-68h] BYREF
  __int64 v83; // [rsp+D8h] [rbp-60h]
  __int64 v84; // [rsp+E0h] [rbp-58h]
  __int64 v85; // [rsp+E8h] [rbp-50h]

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( *(_DWORD *)(a1 + 48) != *(_DWORD *)(a2 + 48) )
    sub_66A33D40("dst->item_type == src->item_type", "libnc.c", 5104);
  result = *(unsigned int *)(a1 + 80);
  v7 = *(_DWORD *)(a2 + 80);
  if ( v7 == (_DWORD)result )
  {
    if ( v7 <= 0 )
    {
      if ( v2 != v4 )
        goto LABEL_5;
      v72 = 1i64;
      v33 = 0i64;
      v71 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
      goto LABEL_108;
    }
    v12 = *(_QWORD *)(a2 + 120);
    if ( v12 == *(_QWORD *)(a1 + 120) )
    {
      v31 = 1i64;
      while ( (int)result > (int)v31 )
      {
        v32 = *(_QWORD *)(a1 + 8 * v31++ + 120);
        if ( v32 != *(_QWORD *)(a2 + 8 * v31 + 112) )
          goto LABEL_4;
      }
      if ( v2 != v4 )
        goto LABEL_5;
      v71 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
      goto LABEL_96;
    }
  }
LABEL_4:
  sub_66A33D40("same_dims(dst, src)", "libnc.c", 5105);
  if ( v2 == v4 )
  {
    v71 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
    result = *(unsigned int *)(a1 + 80);
    v7 = result;
    if ( (int)result <= 0 )
    {
      v72 = 1i64;
      v33 = 0i64;
      goto LABEL_108;
    }
    v12 = *(_QWORD *)(a1 + 120);
LABEL_96:
    if ( *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
    {
      v72 = *(_QWORD *)(a1 + 120);
      if ( v7 <= 1 )
      {
        v33 = 1i64;
        goto LABEL_108;
      }
      if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
      {
        v72 = *(_QWORD *)(a1 + 128) * *(_QWORD *)(a1 + 120);
        if ( v7 == 2 )
        {
          v33 = 2i64;
          goto LABEL_108;
        }
        if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
        {
          v72 = *(_QWORD *)(a1 + 136) * *(_QWORD *)(a1 + 128) * *(_QWORD *)(a1 + 120);
          if ( v7 == 3 )
          {
            v33 = 3i64;
            goto LABEL_108;
          }
          if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
          {
            v33 = 4i64;
            v72 = *(_QWORD *)(a1 + 144) * *(_QWORD *)(a1 + 136) * *(_QWORD *)(a1 + 128) * *(_QWORD *)(a1 + 120);
LABEL_108:
            v34 = *(unsigned int *)(a1 + 48);
            v35 = nc_type_size_table[v34];
            v36 = v35;
            if ( (_DWORD)v33 == v7 )
              return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, __int64))(v71 + 64))(
                       v71,
                       *(_QWORD *)(a1 + 56),
                       *(_QWORD *)(a2 + 56),
                       (int)v35 * v72);
            v19 = (unsigned int)dword_66A375E0[v34];
            v37 = v33 + 1;
            v12 = *(_QWORD *)(a1 + 8i64 * (int)v33 + 120);
LABEL_110:
            if ( v37 >= v7 )
            {
              LODWORD(v8) = v37;
LABEL_126:
              v82 = 0i64;
              if ( v7 > 1 )
                goto LABEL_127;
LABEL_171:
              v40 = 0i64;
              goto LABEL_130;
            }
            v38 = v37;
            if ( *(_BYTE *)(a1 + v37 + 73) )
            {
              if ( *(_BYTE *)(a2 + v37 + 73) )
              {
                v12 *= *(_QWORD *)(a1 + 8i64 * v37 + 120);
                LODWORD(v8) = v37 + 1;
                if ( v7 <= v37 + 1 )
                  goto LABEL_126;
                if ( *(_BYTE *)(a1 + (int)v8 + 73) && *(_BYTE *)(a2 + (int)v8 + 73) )
                {
                  v12 *= *(_QWORD *)(a1 + 8i64 * (int)v8 + 120);
                  LODWORD(v8) = v37 + 2;
                  if ( v37 + 2 >= v7 )
                    goto LABEL_126;
                  if ( *(_BYTE *)(a1 + (int)v8 + 73) && *(_BYTE *)(a2 + (int)v8 + 73) )
                  {
                    v12 *= *(_QWORD *)(a1 + 8i64 * (int)v8 + 120);
                    LODWORD(v8) = v37 + 3;
                    if ( v37 + 3 >= v7 )
                      goto LABEL_126;
                    if ( *(_BYTE *)(a1 + (int)v8 + 73) && *(_BYTE *)(a2 + (int)v8 + 73) )
                    {
                      v12 *= *(_QWORD *)(a1 + 8i64 * (int)v8 + 120);
                      LODWORD(v8) = v37 + 4;
                      if ( v37 + 4 >= v7 )
                        goto LABEL_126;
                      if ( *(_BYTE *)(a1 + (int)v8 + 73) && *(_BYTE *)(a2 + (int)v8 + 73) )
                      {
                        v12 *= *(_QWORD *)(a1 + 8i64 * (int)v8 + 120);
                        LODWORD(v8) = v37 + 5;
                        goto LABEL_126;
                      }
                    }
                  }
                }
                v37 = v8;
                if ( v7 <= 1 )
                {
                  v38 = (int)v8;
                  if ( (int)v8 >= v7 )
                  {
                    v82 = 0i64;
                    goto LABEL_171;
                  }
LABEL_219:
                  v2 = (unsigned int)(v37 + 1);
                  v75 = a1 + 8 * v38;
                  v48 = *(_QWORD *)(v75 + 120);
                  if ( (int)v2 >= v7 )
                  {
                    v52 = (int)v2;
                    v51 = 0i64;
                    v82 = 0i64;
                    v74 = (int)v2;
                    goto LABEL_196;
                  }
                  goto LABEL_176;
                }
              }
              else if ( v7 <= 1 )
              {
                goto LABEL_219;
              }
              v47 = *(_QWORD *)(a1 + 88);
              v18 = v36;
              if ( v47 != v36 || v47 != *(_QWORD *)(a2 + 96) )
              {
LABEL_174:
                v38 = v37;
                if ( v37 >= v7 )
                {
                  v82 = 0i64;
                  LODWORD(v8) = v37;
LABEL_127:
                  v39 = 1i64;
                  do
                    *(&v82 + v39++) = 0i64;
                  while ( v7 > (int)v39 );
                  v40 = v82;
LABEL_130:
                  v41 = v33 + 8;
                  v42 = v40;
                  v11 = &v82 + (int)v8;
                  v2 = v41;
                  while ( v42 != -1 )
                  {
                    v17 = *(unsigned int *)(a2 + 80);
                    v13 = *(_QWORD *)(a2 + 8 * v2 + 24) >> v19;
                    v18 = *(_QWORD *)(a2 + 56);
                    if ( (int)v17 <= 0 )
                    {
                      v16 = 0i64;
                    }
                    else
                    {
                      v16 = *(_QWORD *)(a2 + 88) * v42;
                      if ( (_DWORD)v17 != 1 )
                      {
                        v16 += *(_QWORD *)(a2 + 96) * v83;
                        if ( (_DWORD)v17 != 2 )
                        {
                          v16 += *(_QWORD *)(a2 + 104) * v84;
                          if ( (_DWORD)v17 != 3 )
                          {
                            v14 = v85;
                            v4 = *(_QWORD *)(a2 + 112);
                            if ( (_DWORD)v17 != 4 )
                              goto LABEL_70;
                            v16 += v4 * v85;
                          }
                        }
                      }
                    }
                    v14 = v18 + v16;
                    v17 = *(_QWORD *)(a1 + 8 * v2 + 24) >> v19;
                    v18 = *(_QWORD *)(a1 + 56);
                    if ( (int)result <= 0 )
                    {
                      v43 = 0i64;
                    }
                    else
                    {
                      v43 = *(_QWORD *)(a1 + 88) * v42;
                      if ( (_DWORD)result != 1 )
                      {
                        v43 += *(_QWORD *)(a1 + 96) * v83;
                        if ( (_DWORD)result != 2 )
                        {
                          v43 += *(_QWORD *)(a1 + 104) * v84;
                          if ( (_DWORD)result != 3 )
                          {
                            v16 = v85;
                            v4 = *(_QWORD *)(a1 + 112);
                            if ( (_DWORD)result != 4 )
                              goto LABEL_70;
                            v43 += v4 * v85;
                          }
                        }
                      }
                    }
                    (*(void (__fastcall **)(__int64, unsigned __int64, __int64, __int64, unsigned __int64, __int64, __int64, _DWORD))(v71 + 72))(
                      v71,
                      v18 + v43,
                      v17,
                      v14,
                      v13,
                      v72,
                      v12,
                      v19);
                    result = *(unsigned int *)(a1 + 80);
                    if ( (int)v8 >= (int)result )
                      break;
                    v44 = *v11 + 1;
                    *v11 = v44;
                    if ( v44 == *(_QWORD *)(a1 + 8 * ((int)v8 + 12i64) + 24) )
                    {
                      v45 = 0i64;
                      do
                      {
                        v11[v45] = 0i64;
                        if ( v45 == (_DWORD)result - 1 - (_DWORD)v8 )
                          return result;
                        v46 = v11[v45 + 1] + 1;
                        v11[++v45] = v46;
                      }
                      while ( v46 == *(_QWORD *)(a1 + 8i64 * ((int)v8 + 1) + 8 * v45 + 112) );
                    }
                    v42 = v82;
                  }
                  return result;
                }
                goto LABEL_175;
              }
            }
            else
            {
              if ( v7 <= 1 )
                goto LABEL_219;
              v18 = v36;
              if ( v36 != *(_QWORD *)(a1 + 88) || v36 != *(_QWORD *)(a2 + 96) )
              {
LABEL_175:
                v2 = (unsigned int)(v37 + 1);
                v75 = a1 + 8 * v38;
                v48 = *(_QWORD *)(v75 + 120);
                if ( (int)v2 >= v7 )
                {
                  v74 = (int)v2;
LABEL_192:
                  v82 = 0i64;
                  if ( v7 <= 1 )
                  {
                    v51 = 0i64;
                    v52 = v74;
                  }
                  else
                  {
                    v50 = 1i64;
                    do
                      *(&v82 + v50++) = 0i64;
                    while ( v7 > (int)v50 );
                    v51 = v82;
                    v52 = v74;
                  }
LABEL_196:
                  v77 = v12;
                  v11 = &v82 + v52;
                  v76 = v38 + 8;
                  v53 = v33 + 8;
                  v54 = v51;
                  v8 = v48;
                  v12 = v53;
                  while ( v54 != -1 )
                  {
                    v17 = *(unsigned int *)(a2 + 80);
                    v18 = *(_QWORD *)(a2 + 56);
                    v13 = *(_QWORD *)(a2 + 8 * v76 + 24) >> v19;
                    if ( (int)v17 <= 0 )
                    {
                      v16 = 0i64;
                    }
                    else
                    {
                      v16 = *(_QWORD *)(a2 + 88) * v54;
                      if ( (_DWORD)v17 != 1 )
                      {
                        v16 += *(_QWORD *)(a2 + 96) * v83;
                        if ( (_DWORD)v17 != 2 )
                        {
                          v16 += *(_QWORD *)(a2 + 104) * v84;
                          if ( (_DWORD)v17 != 3 )
                          {
                            v14 = v85;
                            v4 = *(_QWORD *)(a2 + 112);
                            if ( (_DWORD)v17 != 4 )
                              goto LABEL_70;
                            v16 += v4 * v85;
                          }
                        }
                      }
                    }
                    v18 += v16;
                    v17 = *(_QWORD *)(a1 + 8 * v12 + 24) >> v19;
                    v14 = *(_QWORD *)(v75 + 88) >> v19;
                    if ( (int)result <= 0 )
                    {
                      v55 = 0i64;
                    }
                    else
                    {
                      v55 = *(_QWORD *)(a1 + 88) * v54;
                      if ( (_DWORD)result != 1 )
                      {
                        v55 += *(_QWORD *)(a1 + 96) * v83;
                        if ( (_DWORD)result != 2 )
                        {
                          v55 += *(_QWORD *)(a1 + 104) * v84;
                          if ( (_DWORD)result != 3 )
                          {
                            v16 = v85;
                            v4 = *(_QWORD *)(a1 + 112);
                            if ( (_DWORD)result != 4 )
                              goto LABEL_70;
                            v55 += v4 * v85;
                          }
                        }
                      }
                    }
                    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, unsigned __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _DWORD))(v71 + 80))(
                      v71,
                      *(_QWORD *)(a1 + 56) + v55,
                      v17,
                      v14,
                      v18,
                      *(_QWORD *)(a2 + 8 * v12 + 24) >> v19,
                      v13,
                      v72,
                      v77,
                      v8,
                      v19);
                    result = *(unsigned int *)(a1 + 80);
                    if ( (int)v2 >= (int)result )
                      break;
                    v56 = *v11 + 1;
                    *v11 = v56;
                    if ( v56 == *(_QWORD *)(a1 + 8 * v74 + 120) )
                    {
                      v57 = 0i64;
                      do
                      {
                        v11[v57] = 0i64;
                        if ( (_DWORD)result - 1 - (_DWORD)v2 == v57 )
                          return result;
                        v58 = v11[v57 + 1] + 1;
                        v11[++v57] = v58;
                      }
                      while ( v58 == *(_QWORD *)(a1 + 8i64 * ((int)v2 + 1) + 8 * v57 + 112) );
                    }
                    v54 = v82;
                  }
                  return result;
                }
LABEL_176:
                v74 = (int)v2;
                if ( *(_BYTE *)(a1 + (int)v2 + 73) && *(_BYTE *)(a2 + (int)v2 + 73) )
                {
                  v48 *= *(_QWORD *)(a1 + 8i64 * (int)v2 + 120);
                  v49 = v2 + 1;
                  if ( (int)v2 + 1 < v7 )
                  {
                    if ( *(_BYTE *)(a1 + v49 + 73) )
                    {
                      if ( *(_BYTE *)(a2 + v49 + 73) )
                      {
                        v48 *= *(_QWORD *)(a1 + 8i64 * v49 + 120);
                        v49 = v2 + 2;
                        if ( v7 > (int)v2 + 2 )
                        {
                          if ( *(_BYTE *)(a1 + v49 + 73) )
                          {
                            if ( *(_BYTE *)(a2 + v49 + 73) )
                            {
                              v48 *= *(_QWORD *)(a1 + 8i64 * v49 + 120);
                              v49 = v2 + 3;
                              if ( v7 > (int)v2 + 3 )
                              {
                                if ( *(_BYTE *)(a1 + v49 + 73) )
                                {
                                  if ( *(_BYTE *)(a2 + v49 + 73) )
                                  {
                                    v48 *= *(_QWORD *)(a1 + 8i64 * v49 + 120);
                                    v49 = v2 + 4;
                                    if ( (int)v2 + 4 < v7 && *(_BYTE *)(a1 + v49 + 73) && *(_BYTE *)(a2 + v49 + 73) )
                                    {
                                      v48 *= *(_QWORD *)(a1 + 8i64 * v49 + 120);
                                      v49 = v2 + 5;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  v74 = v49;
                  v2 = v49;
                }
                goto LABEL_192;
              }
            }
            v13 = (v36 - 2) & 0xFFFFFFFD;
            if ( !(_DWORD)v13 )
            {
              v59 = 1i64;
              v11 = &v82;
              v82 = 0i64;
              do
                *(&v82 + v59++) = 0i64;
              while ( v7 > (int)v59 );
LABEL_225:
              v8 = v82;
              while ( 1 )
              {
                if ( v8 == -1 )
                  return result;
                if ( (_DWORD)v19 == 1 )
                {
                  v18 = *(_QWORD *)(a1 + 128);
                  v12 = *(_QWORD *)(a1 + 120);
                  v14 = *(_QWORD *)(a2 + 56);
                  v16 = *(unsigned int *)(a2 + 80);
                  if ( (int)v16 <= 0 )
                  {
                    v64 = 0i64;
                  }
                  else
                  {
                    v64 = v8 * *(_QWORD *)(a2 + 88);
                    if ( (_DWORD)v16 != 1 )
                    {
                      v64 += *(_QWORD *)(a2 + 96) * v83;
                      if ( (_DWORD)v16 != 2 )
                      {
                        v64 += *(_QWORD *)(a2 + 104) * v84;
                        if ( (_DWORD)v16 != 3 )
                        {
                          v17 = *(_QWORD *)(a2 + 112) * v85;
                          v64 += v17;
                          if ( (_DWORD)v16 != 4 )
                          {
LABEL_70:
                            v17 += v19 * v18;
                            while ( 1 )
                            {
                              v17 += v16;
                              v16 = *(unsigned int *)(a1 + 80);
                              if ( (int)v16 <= 0 )
                              {
                                result = 0i64;
                              }
                              else
                              {
                                result *= *(_QWORD *)(a1 + 88);
                                if ( (_DWORD)v16 != 1 )
                                {
                                  result += *(_QWORD *)(a1 + 96) * v79;
                                  if ( (_DWORD)v16 != 2 )
                                  {
                                    result += *(_QWORD *)(a1 + 104) * v80;
                                    if ( (_DWORD)v16 != 3 )
                                    {
                                      v18 = v81;
                                      v19 = *(_QWORD *)(a1 + 112);
                                      if ( (_DWORD)v16 != 4 )
                                        goto LABEL_70;
                                      result += v19 * v81;
                                    }
                                  }
                                }
                              }
                              result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))v13)(
                                         v4,
                                         result + *(_QWORD *)(a1 + 56),
                                         v17,
                                         v14);
                              v27 = *(_DWORD *)(a2 + 80);
                              if ( v27 <= (int)v8 )
                                return result;
                              v28 = *v11 + 1;
                              *v11 = v28;
                              if ( v28 == *(_QWORD *)(a2 + 8 * v71 + 24) )
                              {
                                result = 0i64;
                                v29 = v27 - 1 - v8;
                                do
                                {
                                  v11[result] = 0i64;
                                  if ( result == v29 )
                                    return result;
                                  v30 = v11[result + 1] + 1;
                                  v11[++result] = v30;
                                }
                                while ( v30 == *(_QWORD *)(v12 + 8 * result + 112) );
                              }
                              result = v78;
LABEL_64:
                              if ( result == -1 )
                                return result;
                              v13 = *(_QWORD *)(v4 + 96);
                              v14 = nc_type_size_table[*(unsigned int *)(a2 + 48)] * v2;
                              v26 = *(_DWORD *)(a2 + 80);
                              v16 = *(_QWORD *)(a2 + 56);
                              if ( v26 <= 0 )
                              {
                                v17 = 0i64;
                              }
                              else
                              {
                                v17 = *(_QWORD *)(a2 + 88) * result;
                                if ( v26 != 1 )
                                {
                                  v17 += *(_QWORD *)(a2 + 96) * v79;
                                  if ( v26 != 2 )
                                  {
                                    v17 += *(_QWORD *)(a2 + 104) * v80;
                                    if ( v26 != 3 )
                                    {
                                      v18 = v81;
                                      v19 = *(_QWORD *)(a2 + 112);
                                      goto LABEL_70;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  v13 = *(_QWORD *)(a1 + 56);
                  v4 = *(_QWORD *)(a1 + 96) >> 1;
                  if ( (int)result <= 0 )
                  {
                    if ( !v18 )
                      return result;
                    v16 = 0i64;
                  }
                  else
                  {
                    v16 = *(_QWORD *)(a1 + 88) * v8;
                    if ( (_DWORD)result == 1 || (v16 += v83 * *(_QWORD *)(a1 + 96), (_DWORD)result == 2) )
                    {
                      if ( !v18 )
                        return result;
                    }
                    else
                    {
                      v17 = v84;
                      v2 = *(_QWORD *)(a1 + 104) * v84;
                      v16 += v2;
                      if ( (_DWORD)result != 3 )
                      {
                        v2 = *(_QWORD *)(a1 + 112) * v85;
                        v16 += v2;
                        if ( (_DWORD)result != 4 )
                          goto LABEL_70;
                      }
                      if ( !v18 )
                        goto LABEL_242;
                    }
                  }
                  if ( v12 )
                  {
                    v13 += v16;
                    v65 = (__int16 *)(v64 + v14);
                    v4 *= 2i64;
                    v66 = 0i64;
                    v2 = 2i64 * (*(_QWORD *)(a2 + 88) >> 1);
                    do
                    {
                      v73 = result;
                      v67 = v65;
                      for ( i = 0i64; i != v12; ++i )
                      {
                        v69 = *v67;
                        v67 = (__int16 *)((char *)v67 + v2);
                        *(_WORD *)(v13 + 2 * i) = v69;
                      }
                      ++v66;
                      result = v73;
                      ++v65;
                      v13 += v4;
                    }
                    while ( v18 > v66 );
                  }
                }
                else
                {
                  if ( (_DWORD)v19 != 2 )
                    goto LABEL_277;
                  v12 = *(_QWORD *)(a1 + 128);
                  v2 = *(_QWORD *)(a1 + 120);
                  v13 = *(_QWORD *)(v71 + 432);
                  v16 = *(unsigned int *)(a2 + 80);
                  v4 = *(_QWORD *)(a2 + 88) >> 2;
                  v14 = *(_QWORD *)(a2 + 56);
                  if ( (int)v16 <= 0 )
                  {
                    v60 = 0i64;
                  }
                  else
                  {
                    v60 = v8 * *(_QWORD *)(a2 + 88);
                    if ( (_DWORD)v16 != 1 )
                    {
                      v60 += *(_QWORD *)(a2 + 96) * v83;
                      if ( (_DWORD)v16 != 2 )
                      {
                        v60 += *(_QWORD *)(a2 + 104) * v84;
                        if ( (_DWORD)v16 != 3 )
                        {
                          v17 = *(_QWORD *)(a2 + 112) * v85;
                          v60 += v17;
                          if ( (_DWORD)v16 != 4 )
                            goto LABEL_70;
                        }
                      }
                    }
                  }
                  v14 += v60;
                  v18 = *(_QWORD *)(a1 + 56);
                  v17 = *(_QWORD *)(a1 + 96) >> 2;
                  if ( (int)result <= 0 )
                  {
                    v61 = 0i64;
                  }
                  else
                  {
                    v61 = *(_QWORD *)(a1 + 88) * v8;
                    if ( (_DWORD)result != 1 )
                    {
                      v61 += v83 * *(_QWORD *)(a1 + 96);
                      if ( (_DWORD)result != 2 )
                      {
                        v61 += *(_QWORD *)(a1 + 104) * v84;
                        if ( (_DWORD)result != 3 )
                        {
                          v16 = *(_QWORD *)(a1 + 112) * v85;
                          v61 += v16;
                          if ( (_DWORD)result != 4 )
                            goto LABEL_70;
                        }
                      }
                    }
                  }
                  ((void (__fastcall *)(__int64, unsigned __int64, __int64, __int64, __int64, __int64, _QWORD))v13)(
                    v71,
                    v18 + v61,
                    v17,
                    v14,
                    v4,
                    v2,
                    *(_QWORD *)(a1 + 128));
                  result = *(unsigned int *)(a1 + 80);
                }
                if ( (int)result <= 2 )
                  return result;
                v17 = v84;
LABEL_242:
                v84 = v17 + 1;
                if ( v17 + 1 == *(_QWORD *)(a1 + 136) )
                {
                  v62 = 3i64;
                  while ( 1 )
                  {
                    *(&v82 + v62 - 1) = 0i64;
                    if ( (int)result <= (int)v62 )
                      return result;
                    v63 = *(&v82 + v62) + 1;
                    *(&v82 + v62++) = v63;
                    if ( v63 != *(_QWORD *)(a1 + 8 * v62 + 112) )
                      goto LABEL_225;
                  }
                }
              }
            }
            goto LABEL_174;
          }
          v33 = 3i64;
        }
        else
        {
          v33 = 2i64;
        }
      }
      else
      {
        v33 = 1i64;
      }
      v37 = v33 + 1;
      v12 = *(_QWORD *)(a1 + 8i64 * (int)v33 + 120);
    }
    else
    {
      v72 = 1i64;
      v37 = 1;
      v33 = 0i64;
    }
    v70 = *(unsigned int *)(a1 + 48);
    v36 = nc_type_size_table[v70];
    v19 = (unsigned int)dword_66A375E0[v70];
    goto LABEL_110;
  }
LABEL_5:
  if ( *(_DWORD *)(v2 + 32) )
  {
    LODWORD(v8) = *(_DWORD *)(a1 + 80);
    if ( (int)v8 > 0 && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
    {
      v2 = *(_QWORD *)(a1 + 120);
      if ( (_DWORD)v8 != 1 )
      {
        if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
        {
          v2 *= *(_QWORD *)(a1 + 128);
          if ( (_DWORD)v8 != 2 )
          {
            if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
            {
              v2 *= *(_QWORD *)(a1 + 136);
              if ( (_DWORD)v8 != 3 )
              {
                if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
                {
                  v2 *= *(_QWORD *)(a1 + 144);
                  LODWORD(v8) = 4;
                }
                else
                {
                  LODWORD(v8) = 3;
                }
              }
            }
            else
            {
              LODWORD(v8) = 2;
            }
          }
        }
        else
        {
          LODWORD(v8) = 1;
        }
      }
      v2 = (int)v2;
    }
    else
    {
      v2 = 1i64;
      LODWORD(v8) = 0;
    }
    v78 = 0i64;
    v24 = *(_DWORD *)(a2 + 80);
    if ( v24 <= 1 )
    {
      result = 0i64;
    }
    else
    {
      v25 = 1i64;
      do
        *(&v78 + v25++) = 0i64;
      while ( v24 > (int)v25 );
      result = v78;
    }
    v11 = &v78 + (int)v8;
    v71 = (int)v8 + 12i64;
    v12 = a2 + 8i64 * (unsigned int)(v8 + 1);
    goto LABEL_64;
  }
  if ( !*(_DWORD *)(v4 + 32) )
LABEL_277:
    abort();
  LODWORD(v8) = *(_DWORD *)(a1 + 80);
  if ( (int)v8 > 0 && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
  {
    v4 = *(_QWORD *)(a1 + 120);
    if ( (_DWORD)v8 != 1 )
    {
      if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
      {
        v4 *= *(_QWORD *)(a1 + 128);
        if ( (_DWORD)v8 != 2 )
        {
          if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
          {
            v4 *= *(_QWORD *)(a1 + 136);
            if ( (_DWORD)v8 != 3 )
            {
              if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
              {
                v4 *= *(_QWORD *)(a1 + 144);
                LODWORD(v8) = 4;
              }
              else
              {
                LODWORD(v8) = 3;
              }
            }
          }
          else
          {
            LODWORD(v8) = 2;
          }
        }
      }
      else
      {
        LODWORD(v8) = 1;
      }
    }
    v4 = (int)v4;
  }
  else
  {
    v4 = 1i64;
    LODWORD(v8) = 0;
  }
  v78 = 0i64;
  v9 = *(_DWORD *)(a2 + 80);
  if ( v9 <= 1 )
  {
    result = 0i64;
  }
  else
  {
    v10 = 1i64;
    do
      *(&v78 + v10++) = 0i64;
    while ( v9 > (int)v10 );
    result = v78;
  }
  v11 = &v78 + (int)v8;
  v71 = (int)v8 + 12i64;
  v12 = a2 + 8i64 * (unsigned int)(v8 + 1);
  while ( result != -1 )
  {
    v13 = *(_QWORD *)(v2 + 88);
    v14 = nc_type_size_table[*(unsigned int *)(a2 + 48)] * v4;
    v15 = *(_DWORD *)(a2 + 80);
    v16 = *(_QWORD *)(a2 + 56);
    if ( v15 <= 0 )
    {
      v17 = 0i64;
    }
    else
    {
      v17 = *(_QWORD *)(a2 + 88) * result;
      if ( v15 != 1 )
      {
        v17 += *(_QWORD *)(a2 + 96) * v79;
        if ( v15 != 2 )
        {
          v17 += *(_QWORD *)(a2 + 104) * v80;
          if ( v15 != 3 )
          {
            v18 = v81;
            v19 = *(_QWORD *)(a2 + 112);
            if ( v15 != 4 )
              goto LABEL_70;
            v17 += v19 * v81;
          }
        }
      }
    }
    v17 += v16;
    v16 = *(unsigned int *)(a1 + 80);
    if ( (int)v16 <= 0 )
    {
      result = 0i64;
    }
    else
    {
      result *= *(_QWORD *)(a1 + 88);
      if ( (_DWORD)v16 != 1 )
      {
        result += *(_QWORD *)(a1 + 96) * v79;
        if ( (_DWORD)v16 != 2 )
        {
          result += *(_QWORD *)(a1 + 104) * v80;
          if ( (_DWORD)v16 != 3 )
          {
            v18 = v81;
            v19 = *(_QWORD *)(a1 + 112);
            if ( (_DWORD)v16 != 4 )
              goto LABEL_70;
            result += v19 * v81;
          }
        }
      }
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))v13)(
               v2,
               result + *(_QWORD *)(a1 + 56),
               v17,
               v14);
    v20 = *(_DWORD *)(a2 + 80);
    if ( (int)v8 >= v20 )
      break;
    v21 = *v11 + 1;
    *v11 = v21;
    if ( v21 == *(_QWORD *)(a2 + 8 * v71 + 24) )
    {
      result = 0i64;
      v22 = v20 - 1 - v8;
      do
      {
        v11[result] = 0i64;
        if ( v22 == result )
          return result;
        v23 = v11[result + 1] + 1;
        v11[++result] = v23;
      }
      while ( v23 == *(_QWORD *)(v12 + 8 * result + 112) );
    }
    result = v78;
  }
  return result;
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

