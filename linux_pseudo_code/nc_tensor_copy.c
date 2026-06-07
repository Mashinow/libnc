// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_copy
// Included functions: 1

// ======================================================
// Function: nc_tensor_copy @ 0x18C80
// ======================================================

__int64 __fastcall nc_tensor_copy(__int64 a1, __int64 a2)
{
  __int64 v2; // r10
  __int64 v4; // rdi
  __int64 v5; // rbp
  __int64 v6; // rsi
  __int64 result; // rax
  __int64 v8; // r12
  __int64 *v9; // r14
  __int64 v10; // r9
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rbx
  __int64 v14; // rdx
  __int64 v15; // rdi
  unsigned __int64 v16; // r15
  __int64 v17; // rsi
  __int64 *v18; // rbx
  unsigned __int64 v19; // r8
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // r11
  int v23; // eax
  __int64 v24; // rdx
  __int64 v25; // rdx
  __int64 v26; // rcx
  __int64 v27; // rdx
  __int64 v28; // rdx
  __int64 v29; // rsi
  int v30; // eax
  __int64 v31; // rdx
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // r9
  __int64 v35; // r9
  int v36; // eax
  __int64 v37; // rcx
  unsigned int v38; // r11d
  __int64 v39; // r8
  __int64 v40; // rdx
  int v41; // r14d
  __int64 v42; // rbx
  __int64 v43; // rbx
  __int64 v44; // rbx
  __int64 v45; // rbx
  __int64 v46; // rbx
  __int64 v47; // rax
  __int64 v48; // r9
  __int64 v49; // r9
  __int64 v50; // rdx
  __int64 v51; // rax
  __int64 v52; // rcx
  int v53; // r12d
  __int64 v54; // r14
  __int64 v55; // rdi
  int v56; // eax
  __int64 v57; // rax
  __int64 v58; // r10
  __int64 v59; // rax
  __int64 v60; // rax
  __int64 v61; // rax
  __int64 v62; // rdx
  __int64 v63; // rax
  __int64 v64; // rax
  __int64 v65; // rdx
  int v66; // eax
  __int64 v67; // rdi
  __int64 v68; // r9
  __int64 v69; // rcx
  __int64 i; // rdx
  __int16 v71; // cx
  __int64 v72; // [rsp-8h] [rbp-E0h]
  __int64 v73; // [rsp+8h] [rbp-D0h]
  __int64 v74; // [rsp+10h] [rbp-C8h]
  __int64 v75; // [rsp+18h] [rbp-C0h]
  __int64 v76; // [rsp+20h] [rbp-B8h]
  __int64 v77; // [rsp+30h] [rbp-A8h]
  __int64 v78; // [rsp+38h] [rbp-A0h]
  __int64 v79; // [rsp+38h] [rbp-A0h]
  __int64 v80; // [rsp+40h] [rbp-98h]
  __int64 v81; // [rsp+48h] [rbp-90h]
  __int64 v82; // [rsp+50h] [rbp-88h]
  __int64 v83; // [rsp+58h] [rbp-80h]
  __int64 v84; // [rsp+60h] [rbp-78h] BYREF
  __int64 v85; // [rsp+68h] [rbp-70h]
  __int64 v86; // [rsp+70h] [rbp-68h]
  __int64 v87; // [rsp+78h] [rbp-60h]
  __int64 *v88; // [rsp+80h] [rbp-58h] BYREF
  __int64 v89; // [rsp+88h] [rbp-50h]
  __int64 v90; // [rsp+90h] [rbp-48h]
  __int64 v91; // [rsp+98h] [rbp-40h]

  v4 = *(unsigned int *)(a1 + 48);
  if ( (_DWORD)v4 != *(_DWORD *)(a2 + 48) )
    __assert_fail("dst->item_type == src->item_type", "libnc.c", 0x13F0u, "nc_tensor_copy");
  v5 = a2;
  v6 = *(unsigned int *)(a1 + 80);
  result = *(unsigned int *)(v5 + 80);
  v8 = (unsigned int)v6;
  if ( (_DWORD)result != (_DWORD)v6 )
LABEL_3:
    __assert_fail("same_dims(dst, src)", "libnc.c", 0x13F1u, "nc_tensor_copy");
  v9 = *(__int64 **)(*(_QWORD *)(a1 + 40) + 24LL);
  v73 = *(_QWORD *)(*(_QWORD *)(v5 + 40) + 24LL);
  if ( (int)result <= 0 )
  {
    if ( v9 != (__int64 *)v73 )
      goto LABEL_10;
    v74 = 1LL;
    v36 = 0;
    goto LABEL_107;
  }
  v10 = *(_QWORD *)(a1 + 120);
  v74 = *(_QWORD *)(v5 + 120);
  if ( v10 != v74 )
    goto LABEL_3;
  v11 = 1LL;
  while ( (int)v6 > (int)v11 )
  {
    v12 = *(_QWORD *)(a1 + 8 * v11++ + 120);
    if ( v12 != *(_QWORD *)(v5 + 8 * v11 + 112) )
      goto LABEL_3;
  }
  if ( v9 != (__int64 *)v73 )
  {
LABEL_10:
    if ( *((_DWORD *)v9 + 8) )
    {
      if ( (int)v6 <= 0 || !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(v5 + 73) )
      {
        v13 = 1LL;
        LODWORD(v8) = 0;
LABEL_25:
        v84 = 0LL;
        if ( (int)result <= 1 )
        {
          v15 = 0LL;
          goto LABEL_29;
        }
LABEL_26:
        v14 = 1LL;
        do
          *(&v84 + v14++) = 0LL;
        while ( (int)result > (int)v14 );
        v15 = v84;
LABEL_29:
        v9 = &v84 + (int)v8;
        v16 = v5 + 8LL * (unsigned int)(v8 + 1);
        v74 = (int)v8 + 12LL;
        v17 = v5;
        v5 = v13;
        v18 = (__int64 *)(unsigned int)v8;
        v8 = v17;
        while ( v15 != -1 )
        {
          v19 = *(_QWORD *)(v73 + 96);
          v20 = nc_type_size_table[*(unsigned int *)(v8 + 48)] * v5;
          v6 = *(_QWORD *)(v8 + 56);
          if ( (int)result <= 0 )
          {
            v21 = 0LL;
          }
          else
          {
            v21 = *(_QWORD *)(v8 + 88) * v15;
            if ( (_DWORD)result != 1 )
            {
              v21 += *(_QWORD *)(v8 + 96) * v85;
              if ( (_DWORD)result != 2 )
              {
                v21 += *(_QWORD *)(v8 + 104) * v86;
                if ( (_DWORD)result != 3 )
                {
                  v2 = v87;
                  v22 = *(_QWORD *)(v8 + 112);
                  if ( (_DWORD)result != 4 )
                    goto LABEL_75;
                  v21 += v22 * v87;
                }
              }
            }
          }
          v23 = *(_DWORD *)(a1 + 80);
          v21 += v6;
          v6 = *(_QWORD *)(a1 + 56);
          if ( v23 <= 0 )
          {
            v15 = 0LL;
          }
          else
          {
            v15 *= *(_QWORD *)(a1 + 88);
            if ( v23 != 1 )
            {
              v15 += *(_QWORD *)(a1 + 96) * v85;
              if ( v23 != 2 )
              {
                v15 += *(_QWORD *)(a1 + 104) * v86;
                if ( v23 != 3 )
                {
                  v2 = v87;
                  v22 = *(_QWORD *)(a1 + 112);
                  if ( v23 != 4 )
                    goto LABEL_75;
                  v15 += v22 * v87;
                }
              }
            }
          }
          ((void (__fastcall *)(__int64, __int64, __int64, __int64))v19)(v73, v15 + v6, v21, v20);
          result = *(unsigned int *)(v8 + 80);
          if ( (int)v18 >= (int)result )
            break;
          v24 = *v9 + 1;
          *v9 = v24;
          if ( *(_QWORD *)(v8 + 8 * v74 + 24) == v24 )
          {
            v25 = 0LL;
            do
            {
              v9[v25] = 0LL;
              if ( (_DWORD)result - 1 - (_DWORD)v18 == v25 )
                return result;
              v26 = v9[v25 + 1] + 1;
              v9[++v25] = v26;
            }
            while ( v26 == *(_QWORD *)(v16 + 8 * v25 + 112) );
          }
          v15 = v84;
        }
        return result;
      }
      v13 = *(_QWORD *)(a1 + 120);
      if ( (_DWORD)v6 != 1 )
      {
        if ( !*(_BYTE *)(a1 + 74) || !*(_BYTE *)(v5 + 74) )
        {
          LODWORD(v8) = 1;
          goto LABEL_154;
        }
        v13 *= *(_QWORD *)(a1 + 128);
        if ( (_DWORD)v6 != 2 )
        {
          if ( !*(_BYTE *)(a1 + 75) || !*(_BYTE *)(v5 + 75) )
          {
            LODWORD(v8) = 2;
            goto LABEL_154;
          }
          v13 *= *(_QWORD *)(a1 + 136);
          if ( (_DWORD)v6 != 3 )
          {
            if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(v5 + 76) )
            {
              v13 *= *(_QWORD *)(a1 + 144);
              LODWORD(v8) = 4;
              goto LABEL_24;
            }
            LODWORD(v8) = 3;
LABEL_154:
            v84 = 0LL;
            v13 = (int)v13;
            goto LABEL_26;
          }
        }
      }
LABEL_24:
      v13 = (int)v13;
      goto LABEL_25;
    }
    if ( !*(_DWORD *)(v73 + 32) )
LABEL_239:
      abort();
    if ( (int)v6 <= 0 || !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(v5 + 73) )
    {
      v73 = 1LL;
      LODWORD(v8) = 0;
LABEL_64:
      v84 = 0LL;
      if ( (int)result <= 1 )
      {
        v15 = 0LL;
LABEL_68:
        v18 = &v84 + (int)v8;
        v16 = v5 + 8LL * (unsigned int)(v8 + 1);
        v74 = (int)v8 + 12LL;
        v29 = v5;
        LODWORD(v5) = v8;
        v8 = v29;
        goto LABEL_69;
      }
LABEL_65:
      v28 = 1LL;
      do
        *(&v84 + v28++) = 0LL;
      while ( (int)result > (int)v28 );
      v15 = v84;
      goto LABEL_68;
    }
    v27 = *(_QWORD *)(a1 + 120);
    if ( (_DWORD)v6 != 1 )
    {
      if ( !*(_BYTE *)(a1 + 74) || !*(_BYTE *)(v5 + 74) )
      {
        LODWORD(v8) = 1;
        goto LABEL_156;
      }
      v27 *= *(_QWORD *)(a1 + 128);
      if ( (_DWORD)v6 != 2 )
      {
        if ( !*(_BYTE *)(a1 + 75) || !*(_BYTE *)(v5 + 75) )
        {
          LODWORD(v8) = 2;
          goto LABEL_156;
        }
        v27 *= *(_QWORD *)(a1 + 136);
        if ( (_DWORD)v6 != 3 )
        {
          if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(v5 + 76) )
          {
            v27 *= *(_QWORD *)(a1 + 144);
            LODWORD(v8) = 4;
            goto LABEL_63;
          }
          LODWORD(v8) = 3;
LABEL_156:
          v84 = 0LL;
          v73 = (int)v27;
          goto LABEL_65;
        }
      }
    }
LABEL_63:
    v73 = (int)v27;
    goto LABEL_64;
  }
  if ( *(_BYTE *)(a1 + 73) && *(_BYTE *)(v5 + 73) )
  {
    if ( (_DWORD)v6 != 1 && *(_BYTE *)(a1 + 74) && *(_BYTE *)(v5 + 74) )
    {
      v34 = *(_QWORD *)(a1 + 128) * v10;
      v74 = v34;
      if ( (_DWORD)v6 != 2 && *(_BYTE *)(a1 + 75) && *(_BYTE *)(v5 + 75) )
      {
        v35 = *(_QWORD *)(a1 + 136) * v34;
        v74 = v35;
        if ( (_DWORD)v6 != 3 && *(_BYTE *)(a1 + 76) && *(_BYTE *)(v5 + 76) )
        {
          v74 = *(_QWORD *)(a1 + 144) * v35;
          v36 = 4;
        }
        else
        {
          v36 = 3;
        }
      }
      else
      {
        v36 = 2;
      }
    }
    else
    {
      v36 = 1;
    }
LABEL_107:
    v37 = nc_type_size_table[v4];
    v38 = dword_30520[v4];
    v39 = (int)v37;
    if ( (_DWORD)v6 == v36 )
      return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _QWORD))(v73 + 64))(
               v73,
               *(_QWORD *)(a1 + 56),
               *(_QWORD *)(v5 + 56),
               v74 * (int)v37,
               (int)v37);
    goto LABEL_108;
  }
  v74 = 1LL;
  v37 = nc_type_size_table[v4];
  v38 = dword_30520[v4];
  v36 = 0;
  v39 = (int)v37;
LABEL_108:
  v40 = v36;
  v41 = v36 + 1;
  v76 = a1 + 8LL * v36;
  v75 = *(_QWORD *)(v76 + 120);
  if ( (int)v6 <= v36 + 1 )
    goto LABEL_124;
  if ( *(_BYTE *)(a1 + v41 + 73) && *(_BYTE *)(v5 + v41 + 73) )
  {
    v42 = *(_QWORD *)(a1 + 8LL * v41 + 120) * *(_QWORD *)(v76 + 120);
    v41 = v36 + 2;
    v75 = v42;
    if ( (int)v6 <= v36 + 2 )
      goto LABEL_124;
    if ( *(_BYTE *)(a1 + v41 + 73) && *(_BYTE *)(v5 + v41 + 73) )
    {
      v43 = *(_QWORD *)(a1 + 8LL * v41 + 120) * v42;
      v41 = v36 + 3;
      v75 = v43;
      if ( (int)v6 <= v36 + 3 )
        goto LABEL_124;
      if ( *(_BYTE *)(a1 + v41 + 73) && *(_BYTE *)(v5 + v41 + 73) )
      {
        v44 = *(_QWORD *)(a1 + 8LL * v41 + 120) * v43;
        v41 = v36 + 4;
        v75 = v44;
        if ( (int)v6 <= v36 + 4 )
          goto LABEL_124;
        if ( *(_BYTE *)(a1 + v41 + 73) && *(_BYTE *)(v5 + v41 + 73) )
        {
          v45 = *(_QWORD *)(a1 + 8LL * v41 + 120) * v44;
          v41 = v36 + 5;
          v75 = v45;
          if ( (int)v6 <= v36 + 5 )
            goto LABEL_124;
          if ( *(_BYTE *)(a1 + v41 + 73) && *(_BYTE *)(v5 + v41 + 73) )
          {
            v46 = *(_QWORD *)(a1 + 8LL * v41 + 120) * v45;
            v41 = v36 + 6;
            v75 = v46;
LABEL_124:
            v47 = 1LL;
            v48 = 0LL;
            v88 = 0LL;
            if ( (int)v6 > 1 )
            {
              do
                (&v88)[v47++] = 0LL;
              while ( (int)v6 > (int)v47 );
              v48 = (__int64)v88;
            }
            v18 = (__int64 *)&(&v88)[v41];
            v8 = a1 + 8LL * (v41 + 1);
            result = v41 + 12LL;
            v78 = v40 + 8;
            v16 = (unsigned int)v41;
            v77 = result;
            v9 = (__int64 *)v38;
            while ( v48 != -1 )
            {
              v21 = *(unsigned int *)(v5 + 80);
              v2 = *(_QWORD *)(v5 + 56);
              v19 = *(_QWORD *)(v5 + 8 * v78 + 24) >> (char)v9;
              if ( (int)v21 <= 0 )
              {
                v20 = 0LL;
              }
              else
              {
                v20 = *(_QWORD *)(v5 + 88) * v48;
                if ( (_DWORD)v21 != 1 )
                {
                  v20 += *(_QWORD *)(v5 + 96) * v89;
                  if ( (_DWORD)v21 != 2 )
                  {
                    v20 += *(_QWORD *)(v5 + 104) * v90;
                    if ( (_DWORD)v21 != 3 )
                    {
                      v15 = v91;
                      v22 = *(_QWORD *)(v5 + 112);
                      if ( (_DWORD)v21 != 4 )
                        goto LABEL_75;
                      v20 += v22 * v91;
                    }
                  }
                }
              }
              v20 += v2;
              v2 = *(_QWORD *)(a1 + 56);
              v21 = *(_QWORD *)(v76 + 88) >> (char)v9;
              if ( (int)v6 <= 0 )
              {
                v49 = 0LL;
              }
              else
              {
                v49 = *(_QWORD *)(a1 + 88) * v48;
                if ( (_DWORD)v6 != 1 )
                {
                  v49 += *(_QWORD *)(a1 + 96) * v89;
                  if ( (_DWORD)v6 != 2 )
                  {
                    v49 += *(_QWORD *)(a1 + 104) * v90;
                    if ( (_DWORD)v6 != 3 )
                    {
                      v15 = v91;
                      v22 = *(_QWORD *)(a1 + 112);
                      if ( (_DWORD)v6 != 4 )
                        goto LABEL_75;
                      v49 += v22 * v91;
                    }
                  }
                }
              }
              result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, unsigned __int64, __int64, __int64, __int64 *))(v73 + 72))(
                         v73,
                         v2 + v49,
                         v21,
                         v20,
                         v19,
                         v74,
                         v75,
                         v9);
              v6 = *(unsigned int *)(a1 + 80);
              if ( (int)v6 <= (int)v16 )
                break;
              result = *v18 + 1;
              *v18 = result;
              if ( *(_QWORD *)(a1 + 8 * v77 + 24) == result )
              {
                result = 0LL;
                do
                {
                  v18[result] = 0LL;
                  if ( result == (_DWORD)v6 - 1 - (_DWORD)v16 )
                    return result;
                  v50 = v18[result + 1] + 1;
                  v18[++result] = v50;
                }
                while ( v50 == *(_QWORD *)(v8 + 8 * result + 112) );
              }
              v48 = (__int64)v88;
            }
            return result;
          }
        }
      }
    }
  }
  if ( (int)v6 <= 1 )
  {
    v52 = v41;
    v53 = v41 + 1;
    v79 = a1 + 8LL * v41;
    v54 = *(_QWORD *)(v79 + 120);
    if ( (int)v6 <= v53 )
    {
      v58 = 0LL;
      v55 = v53;
      v88 = 0LL;
      goto LABEL_182;
    }
  }
  else
  {
    v51 = *(_QWORD *)(a1 + 88);
    if ( v51 == v39 && v51 == *(_QWORD *)(v5 + 96) && (((_DWORD)v37 - 2) & 0xFFFFFFFD) == 0 )
    {
      result = 1LL;
      v16 = (unsigned __int64)&v88;
      v88 = 0LL;
      do
        (&v88)[result++] = 0LL;
      while ( (int)v6 > (int)result );
      v9 = v88;
      v18 = (__int64 *)v38;
      while ( 1 )
      {
        if ( v9 == (__int64 *)-1LL )
          return result;
        if ( (_DWORD)v18 != 1 )
        {
          if ( (_DWORD)v18 != 2 )
            goto LABEL_239;
          v21 = *(unsigned int *)(v5 + 80);
          v15 = *(_QWORD *)(a1 + 128);
          v2 = *(_QWORD *)(v73 + 432);
          v20 = *(_QWORD *)(v5 + 56);
          v19 = *(_QWORD *)(v5 + 88) >> 2;
          if ( (int)v21 <= 0 )
          {
            v63 = 0LL;
          }
          else
          {
            v63 = (_QWORD)v9 * *(_QWORD *)(v5 + 88);
            if ( (_DWORD)v21 != 1 )
            {
              v63 += *(_QWORD *)(v5 + 96) * v89;
              if ( (_DWORD)v21 != 2 )
              {
                v63 += *(_QWORD *)(v5 + 104) * v90;
                if ( (_DWORD)v21 != 3 )
                {
                  v22 = *(_QWORD *)(v5 + 112) * v91;
                  v63 += v22;
                  if ( (_DWORD)v21 != 4 )
                    goto LABEL_75;
                }
              }
            }
          }
          v20 += v63;
          v8 = *(_QWORD *)(a1 + 56);
          v21 = *(_QWORD *)(a1 + 96) >> 2;
          v64 = v89 * *(_QWORD *)(a1 + 96) + *(_QWORD *)(a1 + 88) * (_QWORD)v9;
          if ( (_DWORD)v6 != 2 )
          {
            v64 += *(_QWORD *)(a1 + 104) * v90;
            if ( (_DWORD)v6 != 3 )
            {
              v22 = *(_QWORD *)(a1 + 112) * v91;
              v64 += v22;
              if ( (_DWORD)v6 != 4 )
                goto LABEL_75;
            }
          }
          result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, unsigned __int64, _QWORD, _QWORD))v2)(
                     v73,
                     v8 + v64,
                     v21,
                     v20,
                     v19,
                     *(_QWORD *)(a1 + 120),
                     *(_QWORD *)(a1 + 128));
          v6 = *(unsigned int *)(a1 + 80);
          v2 = v72;
          goto LABEL_226;
        }
        v66 = *(_DWORD *)(v5 + 80);
        v19 = *(_QWORD *)(a1 + 128);
        v22 = *(_QWORD *)(a1 + 120);
        v15 = *(_QWORD *)(v5 + 56);
        v8 = *(_QWORD *)(v5 + 88) >> 1;
        if ( v66 > 0 )
          break;
        v21 = 0LL;
LABEL_247:
        v74 = *(_QWORD *)(a1 + 56);
        result = v89 * *(_QWORD *)(a1 + 96) + *(_QWORD *)(a1 + 88) * (_QWORD)v9;
        if ( (_DWORD)v6 == 2 )
        {
          if ( !v19 )
            return result;
        }
        else
        {
          v20 = v90;
          v2 = *(_QWORD *)(a1 + 104) * v90;
          result += v2;
          if ( (_DWORD)v6 != 3 )
          {
            v2 = *(_QWORD *)(a1 + 112) * v91;
            result += v2;
            if ( (_DWORD)v6 != 4 )
              goto LABEL_75;
          }
          if ( !v19 )
            goto LABEL_228;
        }
        if ( v22 )
        {
          v67 = v21 + v15;
          v68 = 2LL * (*(_QWORD *)(a1 + 96) >> 1);
          result += v74;
          v8 *= 2LL;
          v69 = 0LL;
          do
          {
            v74 = v69;
            v2 = v67;
            for ( i = 0LL; i != v22; ++i )
            {
              v71 = *(_WORD *)v2;
              v2 += v8;
              *(_WORD *)(result + 2 * i) = v71;
            }
            v67 += 2LL;
            result += v68;
            v69 = v74 + 1;
          }
          while ( v19 > v74 + 1 );
        }
LABEL_226:
        if ( (int)v6 <= 2 )
          return result;
        v20 = v90;
LABEL_228:
        v90 = v20 + 1;
        if ( v20 + 1 == *(_QWORD *)(a1 + 136) )
        {
          result = 3LL;
          do
          {
            (&v88)[result - 1] = 0LL;
            if ( (int)v6 <= (int)result )
              return result;
            v65 = (__int64)(&v88)[result] + 1;
            (&v88)[result++] = (__int64 *)v65;
          }
          while ( v65 == *(_QWORD *)(a1 + 8 * result + 112) );
          v9 = v88;
        }
      }
      v21 = (_QWORD)v9 * *(_QWORD *)(v5 + 88);
      if ( v66 == 1 )
        goto LABEL_247;
      v21 += *(_QWORD *)(v5 + 96) * v89;
      if ( v66 == 2 )
        goto LABEL_247;
      v21 += *(_QWORD *)(v5 + 104) * v90;
      if ( v66 == 3 )
        goto LABEL_247;
      v20 = *(_QWORD *)(v5 + 112) * v91;
      v21 += v20;
      if ( v66 == 4 )
        goto LABEL_247;
LABEL_75:
      while ( 2 )
      {
        v21 += v22 * v2;
        while ( 1 )
        {
          v30 = *(_DWORD *)(a1 + 80);
          v21 += v6;
          v6 = *(_QWORD *)(a1 + 56);
          if ( v30 > 0 )
            break;
          while ( 1 )
          {
            v15 = 0LL;
LABEL_82:
            ((void (__fastcall *)(__int64 *, __int64, __int64, __int64))v19)(v9, v15 + v6, v21, v20);
            result = *(unsigned int *)(v8 + 80);
            if ( (int)result <= (int)v5 )
              return result;
            v31 = *v18 + 1;
            *v18 = v31;
            if ( v31 == *(_QWORD *)(v8 + 8 * v74 + 24) )
            {
              v32 = 0LL;
              do
              {
                v18[v32] = 0LL;
                if ( (_DWORD)result - 1 - (_DWORD)v5 == v32 )
                  return result;
                v33 = v18[v32 + 1] + 1;
                v18[++v32] = v33;
              }
              while ( v33 == *(_QWORD *)(v16 + 8 * v32 + 112) );
            }
            v15 = v84;
LABEL_69:
            if ( v15 == -1 )
              return result;
            v19 = v9[11];
            v20 = nc_type_size_table[*(unsigned int *)(v8 + 48)] * v73;
            v6 = *(_QWORD *)(v8 + 56);
            if ( (int)result > 0 )
              break;
            v30 = *(_DWORD *)(a1 + 80);
            v21 = *(_QWORD *)(v8 + 56);
            v6 = *(_QWORD *)(a1 + 56);
            if ( v30 > 0 )
              goto LABEL_77;
          }
          v21 = *(_QWORD *)(v8 + 88) * v15;
          if ( (_DWORD)result != 1 )
          {
            v21 += *(_QWORD *)(v8 + 96) * v85;
            if ( (_DWORD)result != 2 )
            {
              v21 += *(_QWORD *)(v8 + 104) * v86;
              if ( (_DWORD)result != 3 )
              {
                v2 = v87;
                v22 = *(_QWORD *)(v8 + 112);
                goto LABEL_75;
              }
            }
          }
        }
LABEL_77:
        v15 *= *(_QWORD *)(a1 + 88);
        if ( v30 != 1 )
        {
          v15 += *(_QWORD *)(a1 + 96) * v85;
          if ( v30 != 2 )
          {
            v15 += *(_QWORD *)(a1 + 104) * v86;
            if ( v30 != 3 )
            {
              v2 = v87;
              v22 = *(_QWORD *)(a1 + 112);
              if ( v30 == 4 )
              {
                v15 += v22 * v87;
                goto LABEL_82;
              }
              continue;
            }
          }
        }
        goto LABEL_82;
      }
    }
    v52 = v41;
    v53 = v41 + 1;
    v79 = a1 + 8LL * v41;
    v54 = *(_QWORD *)(v79 + 120);
    if ( (int)v6 <= v53 )
    {
      v88 = 0LL;
      v55 = v53;
      goto LABEL_179;
    }
  }
  v55 = v53;
  if ( *(_BYTE *)(a1 + v53 + 73) && *(_BYTE *)(v5 + v53 + 73) )
  {
    v54 *= *(_QWORD *)(a1 + 8LL * v53 + 120);
    v56 = v53 + 1;
    if ( (int)v6 > v53 + 1 )
    {
      if ( *(_BYTE *)(a1 + v56 + 73) )
      {
        if ( *(_BYTE *)(v5 + v56 + 73) )
        {
          v54 *= *(_QWORD *)(a1 + 8LL * v56 + 120);
          v56 = v53 + 2;
          if ( (int)v6 > v53 + 2 )
          {
            if ( *(_BYTE *)(a1 + v56 + 73) )
            {
              if ( *(_BYTE *)(v5 + v56 + 73) )
              {
                v54 *= *(_QWORD *)(a1 + 8LL * v56 + 120);
                v56 = v53 + 3;
                if ( (int)v6 > v53 + 3 )
                {
                  if ( *(_BYTE *)(a1 + v56 + 73) )
                  {
                    if ( *(_BYTE *)(v5 + v56 + 73) )
                    {
                      v54 *= *(_QWORD *)(a1 + 8LL * v56 + 120);
                      v56 = v53 + 4;
                      if ( (int)v6 > v53 + 4 && *(_BYTE *)(a1 + v56 + 73) && *(_BYTE *)(v5 + v56 + 73) )
                      {
                        v54 *= *(_QWORD *)(a1 + 8LL * v56 + 120);
                        v56 = v53 + 5;
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
    v55 = v56;
    v53 = v56;
  }
  v88 = 0LL;
  if ( (int)v6 <= 1 )
  {
    v58 = 0LL;
    goto LABEL_182;
  }
LABEL_179:
  v57 = 1LL;
  do
    (&v88)[v57++] = 0LL;
  while ( (int)v6 > (int)v57 );
  v58 = (__int64)v88;
LABEL_182:
  v18 = (__int64 *)&(&v88)[v55];
  v83 = v54;
  v9 = (__int64 *)(unsigned int)v53;
  v59 = v53 + 1;
  v8 = v38;
  v16 = a1 + 8 * v59;
  v80 = v52 + 8;
  v81 = v40 + 8;
  v82 = v55 + 12;
  for ( result = v58; result != -1; result = (__int64)v88 )
  {
    v21 = *(unsigned int *)(v5 + 80);
    v2 = *(_QWORD *)(v5 + 56);
    v22 = *(_QWORD *)(v73 + 80);
    if ( (int)v21 <= 0 )
    {
      v19 = 0LL;
    }
    else
    {
      v19 = *(_QWORD *)(v5 + 88) * result;
      if ( (_DWORD)v21 != 1 )
      {
        v19 += *(_QWORD *)(v5 + 96) * v89;
        if ( (_DWORD)v21 != 2 )
        {
          v19 += *(_QWORD *)(v5 + 104) * v90;
          if ( (_DWORD)v21 != 3 )
          {
            v20 = v91;
            v15 = *(_QWORD *)(v5 + 112);
            if ( (_DWORD)v21 != 4 )
              goto LABEL_75;
            v19 += v15 * v91;
          }
        }
      }
    }
    v19 += v2;
    v2 = *(_QWORD *)(a1 + 56);
    v20 = *(_QWORD *)(v79 + 88) >> v8;
    v21 = *(_QWORD *)(v76 + 88) >> v8;
    if ( (int)v6 <= 0 )
    {
      v60 = 0LL;
    }
    else
    {
      v60 = *(_QWORD *)(a1 + 88) * result;
      if ( (_DWORD)v6 != 1 )
      {
        v60 += *(_QWORD *)(a1 + 96) * v89;
        if ( (_DWORD)v6 != 2 )
        {
          v60 += *(_QWORD *)(a1 + 104) * v90;
          if ( (_DWORD)v6 != 3 )
          {
            v15 = *(_QWORD *)(a1 + 112);
            if ( (_DWORD)v6 != 4 )
              goto LABEL_75;
            v60 += v15 * v91;
          }
        }
      }
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, unsigned __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64))v22)(
               v73,
               v2 + v60,
               v21,
               v20,
               v19,
               *(_QWORD *)(v5 + 8 * v81 + 24) >> v8,
               *(_QWORD *)(v5 + 8 * v80 + 24) >> v8,
               v74,
               v75,
               v83,
               v8);
    v6 = *(unsigned int *)(a1 + 80);
    if ( (int)v6 <= (int)v9 )
      break;
    v61 = *v18 + 1;
    *v18 = v61;
    if ( v61 == *(_QWORD *)(a1 + 8 * v82 + 24) )
    {
      result = 0LL;
      do
      {
        v18[result] = 0LL;
        if ( (_DWORD)v6 - 1 - (_DWORD)v9 == result )
          return result;
        v62 = v18[result + 1] + 1;
        v18[++result] = v62;
      }
      while ( v62 == *(_QWORD *)(v16 + 8 * result + 112) );
    }
  }
  return result;
}

