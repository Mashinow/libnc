// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sgd_opt_init
// Included functions: 12

// ======================================================
// Function: nc_sgd_opt_init @ 0x2E360
// ======================================================

_QWORD *__fastcall nc_sgd_opt_init(__int64 a1, int *a2)
{
  int v3; // eax
  _QWORD *v4; // rbx
  _QWORD *result; // rax
  _QWORD *v6; // rbx
  _QWORD *v9; // rbx

  _RBP = a2;
  v3 = *a2;
  if ( *a2 == 1 )
  {
    v9 = (_QWORD *)nc_mallocz(0x60uLL);
    *v9 = a1;
    v9[1] = v9 + 1;
    v9[2] = v9 + 1;
    _RAX = (_QWORD *)nc_mallocz(0x40uLL);
    __asm { vmovss  xmm2, cs:dword_30A60 }
    *_RAX = *(_QWORD *)a2;
    __asm { vmovss  xmm1, dword ptr [rax+4] }
    _RAX[1] = *((_QWORD *)a2 + 1);
    __asm { vmovss  xmm0, dword ptr [rax+8] }
    _RAX[2] = *((_QWORD *)a2 + 2);
    __asm
    {
      vmovss  xmm3, dword ptr [rbp+14h]
      vmovss  dword ptr [rax+2Ch], xmm0
      vsubss  xmm0, xmm2, xmm0
      vsubss  xmm2, xmm2, xmm1
      vmovss  dword ptr [rax+28h], xmm1
      vmovss  dword ptr [rax+18h], xmm3
      vsqrtss xmm0, xmm0, xmm0
    }
    _RAX[4] = 0LL;
    __asm
    {
      vdivss  xmm1, xmm0, xmm2
      vmulss  xmm0, xmm0, dword ptr [rax+0Ch]
      vmulss  xmm0, xmm0, xmm0
      vmovss  dword ptr [rax+38h], xmm0
      vmovss  dword ptr [rax+30h], xmm1
      vmulss  xmm1, xmm3, xmm1
      vmovss  dword ptr [rax+34h], xmm1
    }
    v9[4] = sub_1C760;
    v9[5] = sub_16F90;
    v9[6] = sub_10330;
    v9[7] = j__nc_free_1;
    v9[8] = sub_16B40;
    v9[3] = _RAX;
    result = v9;
    v9[9] = sub_16F70;
    v9[10] = sub_102F0;
    v9[11] = sub_6680;
  }
  else if ( v3 )
  {
    if ( v3 != 2 )
      abort();
    v4 = (_QWORD *)nc_mallocz(0x60uLL);
    *v4 = a1;
    v4[1] = v4 + 1;
    v4[2] = v4 + 1;
    v4[3] = nc_mallocz(4uLL);
    result = v4;
    v4[4] = sub_17570;
    v4[7] = j__nc_free;
    v4[8] = sub_11280;
    v4[9] = sub_17550;
  }
  else
  {
    v6 = (_QWORD *)nc_mallocz(0x60uLL);
    *v6 = a1;
    v6[1] = v6 + 1;
    v6[2] = v6 + 1;
    _RAX = (_QWORD *)nc_mallocz(0x1CuLL);
    *_RAX = *(_QWORD *)a2;
    _RAX[1] = *((_QWORD *)a2 + 1);
    _RAX[2] = *((_QWORD *)a2 + 2);
    __asm
    {
      vmovss  xmm0, dword ptr [rbp+14h]
      vmovss  dword ptr [rax+18h], xmm0
    }
    v6[4] = sub_5FE0;
    v6[6] = nullsub_1;
    v6[3] = _RAX;
    result = v6;
    v6[7] = j__nc_free_0;
  }
  return result;
}

// ======================================================
// Function: sub_1C760 @ 0x1C760
// ======================================================

__int64 __fastcall sub_1C760(
        __int64 _RDI,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __m128 _XMM0,
        double a6,
        double a7,
        double a8,
        double a9,
        __m128 _XMM5,
        __m128 _XMM6)
{
  __int64 v11; // r12
  __int64 v12; // r15
  unsigned int v13; // eax
  _BYTE *v19; // rdx
  int v20; // edi
  _BYTE *v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 *v25; // rbx
  int v28; // esi
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 v31; // rdx
  void (__fastcall *v32)(__int64, __int64, __int64, __int64, __int64, __int64, double, double, double, double, double); // r10
  __int64 v33; // rsi
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rdx
  _QWORD *v41; // rdx
  __int64 v43; // r9
  __int64 v44; // rdx
  int v45; // esi
  __int64 v46; // r11
  int v47; // esi
  void *v49; // rax
  void *v50; // rbx
  char v55; // cf
  char v56; // zf
  __int64 v58; // [rsp+8h] [rbp-80h]
  int v60; // [rsp+10h] [rbp-78h]
  __int64 v64; // [rsp+30h] [rbp-58h] BYREF
  __int64 v65; // [rsp+38h] [rbp-50h]
  __int64 v66; // [rsp+40h] [rbp-48h]
  __int64 v67; // [rsp+48h] [rbp-40h]

  v11 = **(_QWORD **)(a3 + 16);
  v12 = *(_QWORD *)(*(_QWORD *)(v11 + 40) + 24LL);
  v13 = *(_DWORD *)(a4 + 48);
  if ( *(_DWORD *)(v11 + 48) != v13 || v13 > 1 )
    __assert_fail(
      "yg->item_type == y->item_type && (yg->item_type == NC_TYPE_F32 || yg->item_type == NC_TYPE_BF16)",
      "libnc.c",
      0x2624u,
      "adam_update_var");
  __asm
  {
    vmovss  xmm2, dword ptr [rdi+10h]
    vxorps  xmm6, xmm6, xmm6
  }
  _R14 = _RDI;
  __asm
  {
    vmovss  xmm1, cs:dword_30A60
    vucomiss xmm2, xmm6
  }
  if ( !__SETP__(v13, 1) && v13 == 1 )
    goto LABEL_5;
  if ( !*(_DWORD *)(a4 + 80) )
    goto LABEL_5;
  __asm
  {
    vmovss  dword ptr [rsp+88h+var_70], xmm1
    vmovss  dword ptr [rsp+88h+var_80], xmm2
  }
  v49 = (void *)nc_dup_tensor(a4);
  v50 = (void *)nc_reduce_sum_sqr(v49);
  *(double *)_XMM0.m128_u64 = nc_get_scalar_f32(v50);
  __asm { vmovss  [rsp+88h+var_78], xmm0 }
  nc_free_tensor(v50);
  __asm
  {
    vmovss  xmm0, [rsp+88h+var_78]
    vmovss  xmm2, dword ptr [rsp+88h+var_80]
    vmovss  xmm1, dword ptr [rsp+88h+var_70]
    vsqrtss xmm0, xmm0, xmm0
    vdivss  xmm7, xmm2, xmm0
    vucomiss xmm7, xmm1
    vmovss  [rsp+88h+var_74], xmm7
  }
  if ( !(v55 | v56) )
LABEL_5:
    __asm { vmovss  [rsp+88h+var_74], xmm1 }
  v19 = (_BYTE *)a2[1];
  if ( v19 )
  {
    v20 = *(_DWORD *)(v11 + 80);
    v21 = (_BYTE *)*a2;
    if ( v20 > 0 && *(_BYTE *)(v11 + 73) && *(_BYTE *)(a4 + 73) && v21[73] && v19[73] )
    {
      v22 = *(_QWORD *)(v11 + 120);
      if ( v20 != 1 )
      {
        if ( *(_BYTE *)(v11 + 74) && *(_BYTE *)(a4 + 74) && v21[74] && v19[74] )
        {
          v22 *= *(_QWORD *)(v11 + 128);
          if ( v20 != 2 )
          {
            if ( *(_BYTE *)(v11 + 75) && *(_BYTE *)(a4 + 75) && v21[75] && v19[75] )
            {
              v22 *= *(_QWORD *)(v11 + 136);
              if ( v20 != 3 )
              {
                if ( *(_BYTE *)(v11 + 76) && *(_BYTE *)(a4 + 76) && v21[76] )
                  goto LABEL_26;
                goto LABEL_105;
              }
LABEL_113:
              v60 = 3;
LABEL_28:
              v64 = 0LL;
              v58 = (int)v22;
              if ( v20 > 1 )
                goto LABEL_29;
LABEL_107:
              v24 = 0LL;
              goto LABEL_32;
            }
            goto LABEL_108;
          }
          goto LABEL_111;
        }
        goto LABEL_110;
      }
      goto LABEL_112;
    }
  }
  else
  {
    v20 = *(_DWORD *)(v11 + 80);
    v19 = (_BYTE *)*a2;
    if ( v20 > 0 && *(_BYTE *)(v11 + 73) && *(_BYTE *)(a4 + 73) && v19[73] )
    {
      v22 = *(_QWORD *)(v11 + 120);
      if ( v20 != 1 )
      {
        if ( *(_BYTE *)(v11 + 74) && *(_BYTE *)(a4 + 74) && v19[74] )
        {
          v22 *= *(_QWORD *)(v11 + 128);
          if ( v20 != 2 )
          {
            if ( *(_BYTE *)(v11 + 75) && *(_BYTE *)(a4 + 75) && v19[75] )
            {
              v22 *= *(_QWORD *)(v11 + 136);
              if ( v20 != 3 )
              {
                if ( *(_BYTE *)(v11 + 76) && *(_BYTE *)(a4 + 76) )
                {
LABEL_26:
                  if ( v19[76] )
                  {
                    v22 *= *(_QWORD *)(v11 + 144);
                    v60 = 4;
                    goto LABEL_28;
                  }
                }
LABEL_105:
                v60 = 3;
LABEL_109:
                v64 = 0LL;
                v58 = (int)v22;
                goto LABEL_29;
              }
              goto LABEL_113;
            }
LABEL_108:
            v60 = 2;
            goto LABEL_109;
          }
LABEL_111:
          v60 = 2;
          goto LABEL_28;
        }
LABEL_110:
        v60 = 1;
        goto LABEL_109;
      }
LABEL_112:
      v60 = 1;
      goto LABEL_28;
    }
  }
  v58 = 1LL;
  v60 = 0;
  v64 = 0LL;
  if ( v20 <= 1 )
    goto LABEL_107;
LABEL_29:
  v23 = 1LL;
  do
    *(&v64 + v23++) = 0LL;
  while ( v20 > (int)v23 );
  v24 = v64;
LABEL_32:
  v25 = &v64 + v60;
  while ( 2 )
  {
    if ( v24 == -1 )
      return nc_free_tensor((void *)a4);
    __asm
    {
      vmovss  xmm1, dword ptr [r14+4]
      vxorps  xmm5, xmm5, xmm5
      vucomiss xmm1, xmm5
    }
    if ( *(_DWORD *)(a4 + 48) )
      __assert_fail("yg->item_type == NC_TYPE_F32", "libnc.c", 0x2642u, "adam_update_var");
    v32 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, double, double, double, double, double))(v12 + 360);
    __asm
    {
      vmovss  xmm3, dword ptr [r14+38h]
      vmovss  xmm2, dword ptr [r14+8]
    }
    v41 = (_QWORD *)*a2;
    __asm { vmovss  xmm0, dword ptr [r14+34h] }
    v29 = *(unsigned int *)(*a2 + 80LL);
    v43 = *(_QWORD *)(*a2 + 56LL);
    if ( (int)v29 <= 0 )
    {
      v30 = 0LL;
    }
    else
    {
      v30 = v41[11] * v24;
      if ( (_DWORD)v29 != 1 )
      {
        v30 += v41[12] * v65;
        if ( (_DWORD)v29 != 2 )
        {
          v30 += v41[13] * v66;
          if ( (_DWORD)v29 != 3 )
          {
            v31 = v41[14];
            if ( (_DWORD)v29 != 4 )
              goto LABEL_35;
            v30 += v31 * v67;
          }
        }
      }
    }
    v30 += v43;
    v44 = a2[1];
    v45 = *(_DWORD *)(v44 + 80);
    v46 = *(_QWORD *)(v44 + 56);
    if ( v45 <= 0 )
    {
      v29 = 0LL;
    }
    else
    {
      v29 = *(_QWORD *)(v44 + 88) * v24;
      if ( v45 != 1 )
      {
        v29 += *(_QWORD *)(v44 + 96) * v65;
        if ( v45 != 2 )
        {
          v29 += *(_QWORD *)(v44 + 104) * v66;
          if ( v45 != 3 )
          {
            v43 = v67;
            v31 = *(_QWORD *)(v44 + 112);
            if ( v45 != 4 )
              goto LABEL_35;
            v29 += v31 * v67;
          }
        }
      }
    }
    v47 = *(_DWORD *)(a4 + 80);
    v29 += v46;
    v43 = *(_QWORD *)(a4 + 56);
    if ( v47 <= 0 )
    {
      v31 = 0LL;
    }
    else
    {
      v31 = *(_QWORD *)(a4 + 88) * v24;
      if ( v47 != 1 )
      {
        v31 += *(_QWORD *)(a4 + 96) * v65;
        if ( v47 != 2 )
        {
          v31 += *(_QWORD *)(a4 + 104) * v66;
          if ( v47 != 3 )
          {
            if ( v47 != 4 )
              goto LABEL_35;
            v31 += *(_QWORD *)(a4 + 112) * v67;
          }
        }
      }
    }
    v31 += v43;
    if ( v20 <= 0 )
    {
      v24 = 0LL;
      goto LABEL_79;
    }
    v24 *= *(_QWORD *)(v11 + 88);
    if ( v20 == 1 )
      goto LABEL_79;
    v24 += *(_QWORD *)(v11 + 96) * v65;
    if ( v20 == 2 )
      goto LABEL_79;
    v24 += *(_QWORD *)(v11 + 104) * v66;
    if ( v20 == 3 )
      goto LABEL_79;
    v43 = *(_QWORD *)(v11 + 112);
    if ( v20 == 4 )
    {
      v24 += v67 * v43;
LABEL_79:
      __asm { vmovss  xmm4, [rsp+88h+var_74] }
      v32(
        v12,
        v24 + *(_QWORD *)(v11 + 56),
        v31,
        v29,
        v30,
        v58,
        *(double *)&_XMM0,
        *(double *)&_XMM1,
        *(double *)&_XMM2,
        *(double *)&_XMM3,
        *(double *)&_XMM4);
      goto LABEL_48;
    }
LABEL_35:
    while ( 1 )
    {
      v28 = *(_DWORD *)(a4 + 80);
      v29 += (__int64)v32 + v31 * v30;
      v30 = *(_QWORD *)(a4 + 56);
      if ( v28 <= 0 )
        break;
      v31 = *(_QWORD *)(a4 + 88) * v24;
      if ( v28 == 1 || (v31 += *(_QWORD *)(a4 + 96) * v65, v28 == 2) || (v31 += *(_QWORD *)(a4 + 104) * v66, v28 == 3) )
      {
LABEL_41:
        v31 += v30;
        v33 = *(_QWORD *)(v11 + 56);
        if ( v20 <= 0 )
          goto LABEL_86;
LABEL_42:
        v24 *= *(_QWORD *)(v11 + 88);
        if ( v20 == 1 )
          goto LABEL_47;
        v24 += *(_QWORD *)(v11 + 96) * v65;
        if ( v20 == 2 )
          goto LABEL_47;
        v24 += *(_QWORD *)(v11 + 104) * v66;
        if ( v20 == 3 )
          goto LABEL_47;
        v32 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, double, double, double, double, double))v67;
        v30 = *(_QWORD *)(v11 + 112);
        if ( v20 == 4 )
        {
          v24 += v67 * v30;
          goto LABEL_47;
        }
      }
      else
      {
        v32 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, double, double, double, double, double))v67;
        if ( v28 == 4 )
        {
          v31 += *(_QWORD *)(a4 + 112) * v67;
          goto LABEL_41;
        }
      }
    }
    v33 = *(_QWORD *)(v11 + 56);
    v31 = *(_QWORD *)(a4 + 56);
    if ( v20 > 0 )
      goto LABEL_42;
LABEL_86:
    v24 = 0LL;
LABEL_47:
    __asm { vmovss  xmm3, [rsp+88h+var_74] }
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, double, double, double, double))v43)(
      v12,
      v24 + v33,
      v31,
      v29,
      v58,
      *(double *)&_XMM0,
      *(double *)&_XMM1,
      *(double *)&_XMM2,
      *(double *)&_XMM3);
LABEL_48:
    v20 = *(_DWORD *)(v11 + 80);
    if ( v20 > v60 )
    {
      v35 = *v25 + 1;
      *v25 = v35;
      if ( *(_QWORD *)(v11 + 8 * (v60 + 12LL) + 24) == v35 )
      {
        v36 = 0LL;
        do
        {
          v25[v36] = 0LL;
          if ( v20 - 1 - v60 == v36 )
            return nc_free_tensor((void *)a4);
          v37 = v25[v36 + 1] + 1;
          v25[++v36] = v37;
        }
        while ( v37 == *(_QWORD *)(v11 + 8LL * (unsigned int)(v60 + 1) + 8 * v36 + 112) );
      }
      v24 = v64;
      continue;
    }
    return nc_free_tensor((void *)a4);
  }
}

// ======================================================
// Function: sub_16F90 @ 0x16F90
// ======================================================

__int64 __fastcall sub_16F90(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        _QWORD *a4,
        _QWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __m128 _XMM6)
{
  __int64 v13; // r13
  unsigned __int64 v14; // r12
  __int64 v16; // rax
  _DWORD *v17; // r14
  unsigned __int64 v18; // rdi
  unsigned __int64 v19; // rax
  __int64 v20; // rdx
  _DWORD *v21; // rcx
  unsigned __int64 v22; // r13
  unsigned __int64 v23; // r11
  unsigned __int64 v24; // r11
  __int64 v25; // rdi
  __int64 v27; // r8
  __int64 v28; // rsi
  __int64 v29; // rdx
  unsigned __int64 v45; // r9
  __int64 v65; // rdx
  unsigned __int64 v66; // rax
  int *v73; // rax
  __int64 v74; // rdx
  __int64 v75; // rax
  __int64 v76; // rdx
  __int64 v77; // rdi
  __int64 v78; // rsi
  __int64 v93; // [rsp-98h] [rbp-A0h]
  _QWORD *v94; // [rsp-90h] [rbp-98h]
  unsigned __int64 v96; // [rsp-80h] [rbp-88h]
  __int64 v98; // [rsp-70h] [rbp-78h]
  unsigned __int64 v99; // [rsp-70h] [rbp-78h]
  unsigned __int64 v100; // [rsp-70h] [rbp-78h]
  __int64 v101; // [rsp-58h] [rbp-60h]
  unsigned __int64 v102; // [rsp-50h] [rbp-58h]
  __int64 v103; // [rsp-48h] [rbp-50h]

  v13 = a5[15];
  v94 = **(_QWORD ***)(a3 + 16);
  v14 = v94[15];
  v93 = *(_QWORD *)(a4[5] + 24LL);
  v103 = v94[16];
  _RBX = nc_malloc(4 * v14);
  v16 = nc_malloc(4 * (v13 + v103));
  v17 = (_DWORD *)v16;
  if ( v103 )
    memset((void *)(v16 + 4 * v13), 255, 4 * v103);
  v18 = a5[15];
  v19 = v18 - 1;
  v20 = 4 * v18 - 4;
  if ( v18 )
  {
    do
    {
      v21 = &v17[v13 + *(int *)(a5[7] + v20)];
      *(_DWORD *)((char *)v17 + v20) = *v21;
      v20 -= 4LL;
      *v21 = v19--;
    }
    while ( v19 != -1LL );
    v22 = -(int)(_RBX >> 2) & 7;
    if ( v22 > v14 )
      v22 = v14;
    v23 = 0LL;
    v102 = ((v14 - v22 - 8) >> 3) + 1;
    v101 = 8 * v102;
    do
    {
      v98 = 4 * v23;
      if ( v17[v23] != -2 )
      {
        v96 = v23;
        memcpy((void *)_RBX, (const void *)(a4[7] + v23 * 4LL * a4[8]), 4 * v14);
        v24 = v96;
        v25 = (int)v17[v96];
        if ( (_DWORD)v25 != -1 )
        {
          _R10 = _RBX + 4 * v22;
          v27 = 4LL * a4[8];
          do
          {
            v28 = a4[7];
            v29 = v27 * v25;
            if ( v14 )
            {
              _RAX = 0LL;
              if ( (v28 + v29 >= _RBX + 32 || _RBX >= v28 + v29 + 32) && v14 > 0xB )
              {
                if ( v22 )
                {
                  __asm
                  {
                    vmovss  xmm0, dword ptr [rbx]
                    vaddss  xmm0, xmm0, dword ptr [rcx]
                    vmovss  dword ptr [rbx], xmm0
                  }
                  if ( v22 == 1 )
                  {
                    _RAX = 1LL;
                  }
                  else
                  {
                    __asm
                    {
                      vmovss  xmm0, dword ptr [rbx+4]
                      vaddss  xmm0, xmm0, dword ptr [rsi+rdx+4]
                      vmovss  dword ptr [rbx+4], xmm0
                    }
                    if ( v22 == 2 )
                    {
                      _RAX = 2LL;
                    }
                    else
                    {
                      __asm
                      {
                        vmovss  xmm0, dword ptr [rbx+8]
                        vaddss  xmm0, xmm0, dword ptr [rsi+rdx+8]
                        vmovss  dword ptr [rbx+8], xmm0
                      }
                      if ( v22 == 3 )
                      {
                        _RAX = 3LL;
                      }
                      else
                      {
                        __asm
                        {
                          vmovss  xmm0, dword ptr [rbx+0Ch]
                          vaddss  xmm0, xmm0, dword ptr [rsi+rdx+0Ch]
                          vmovss  dword ptr [rbx+0Ch], xmm0
                        }
                        if ( v22 == 4 )
                        {
                          _RAX = 4LL;
                        }
                        else
                        {
                          __asm
                          {
                            vmovss  xmm0, dword ptr [rbx+10h]
                            vaddss  xmm0, xmm0, dword ptr [rsi+rdx+10h]
                            vmovss  dword ptr [rbx+10h], xmm0
                          }
                          if ( v22 == 5 )
                          {
                            _RAX = 5LL;
                          }
                          else
                          {
                            __asm
                            {
                              vmovss  xmm0, dword ptr [rbx+14h]
                              vaddss  xmm0, xmm0, dword ptr [rsi+rdx+14h]
                              vmovss  dword ptr [rbx+14h], xmm0
                            }
                            if ( v22 == 7 )
                            {
                              __asm
                              {
                                vmovss  xmm0, dword ptr [rbx+18h]
                                vaddss  xmm0, xmm0, dword ptr [rsi+rdx+18h]
                              }
                              _RAX = 7LL;
                              __asm { vmovss  dword ptr [rbx+18h], xmm0 }
                            }
                            else
                            {
                              _RAX = 6LL;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                if ( v14 - 1 - v22 <= 6 )
                  goto LABEL_51;
                v45 = 0LL;
                _RDX = v28 + 4 * v22 + v29;
                _RSI = 0LL;
                do
                {
                  __asm
                  {
                    vmovups ymm0, ymmword ptr [rdx+rsi]
                    vaddps  ymm0, ymm0, ymmword ptr [r10+rsi]
                  }
                  ++v45;
                  __asm { vmovaps ymmword ptr [r10+rsi], ymm0 }
                  _RSI += 32LL;
                }
                while ( v102 > v45 );
                _RAX += v101;
                if ( v101 != v14 - v22 )
                {
LABEL_51:
                  _RDX = _RBX + 4 * _RAX;
                  __asm
                  {
                    vmovss  xmm0, dword ptr [rdx]
                    vaddss  xmm0, xmm0, dword ptr [rcx+rsi]
                    vmovss  dword ptr [rdx], xmm0
                  }
                  if ( _RAX + 1 < v14 )
                  {
                    _RSI = _RBX + 4 * (_RAX + 1);
                    __asm
                    {
                      vmovss  xmm0, dword ptr [rsi]
                      vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                      vmovss  dword ptr [rsi], xmm0
                    }
                    if ( v14 > _RAX + 2 )
                    {
                      _RSI = _RBX + 4 * (_RAX + 2);
                      __asm
                      {
                        vmovss  xmm0, dword ptr [rsi]
                        vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                        vmovss  dword ptr [rsi], xmm0
                      }
                      if ( v14 > _RAX + 3 )
                      {
                        _RSI = _RBX + 4 * (_RAX + 3);
                        __asm
                        {
                          vmovss  xmm0, dword ptr [rsi]
                          vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                          vmovss  dword ptr [rsi], xmm0
                        }
                        if ( v14 > _RAX + 4 )
                        {
                          _RSI = _RBX + 4 * (_RAX + 4);
                          __asm
                          {
                            vmovss  xmm0, dword ptr [rsi]
                            vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                            vmovss  dword ptr [rsi], xmm0
                          }
                          if ( v14 > _RAX + 5 )
                          {
                            v65 = 4 * (_RAX + 5);
                            v66 = _RAX + 6;
                            _RSI = _RBX + v65;
                            __asm
                            {
                              vmovss  xmm0, dword ptr [rsi]
                              vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                              vmovss  dword ptr [rsi], xmm0
                            }
                            if ( v14 > v66 )
                            {
                              _RDX = _RBX + 4 * v66;
                              __asm
                              {
                                vmovss  xmm0, dword ptr [rdx]
                                vaddss  xmm0, xmm0, dword ptr [rcx+rax]
                                vmovss  dword ptr [rdx], xmm0
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else
              {
                do
                {
                  __asm
                  {
                    vmovss  xmm0, dword ptr [rbx+rax*4]
                    vaddss  xmm0, xmm0, dword ptr [rcx+rax*4]
                    vmovss  dword ptr [rbx+rax*4], xmm0
                  }
                  ++_RAX;
                }
                while ( v14 != _RAX );
              }
            }
            v73 = &v17[v25];
            v25 = *v73;
            *v73 = -2;
          }
          while ( (_DWORD)v25 != -1 );
          v24 = v96;
          __asm { vzeroupper }
        }
        __asm { vxorps  xmm6, xmm6, xmm6 }
        v74 = *(int *)(a5[7] + v98);
        v75 = v74 * 4LL * v94[8];
        v76 = v94[12] * v74;
        v77 = *(_QWORD *)(*a2 + 56LL) + v75;
        v78 = v94[7] + v76;
        _RCX = a1;
        __asm
        {
          vmovss  xmm1, dword ptr [rcx+4]
          vmovss  xmm5, dword ptr [rcx+8]
          vmovss  xmm0, dword ptr [rcx+34h]
          vmovss  xmm2, dword ptr [rcx+38h]
          vucomiss xmm1, xmm6
        }
        if ( __SETP__(v78, 0LL) || v94[7] + v76 )
        {
          v99 = v24;
          __asm
          {
            vmovaps xmm3, xmm2
            vmovss  xmm4, cs:dword_30A60
            vmovaps xmm2, xmm5
          }
          (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, __int64, unsigned __int64, double, double, double, double, double))(v93 + 360))(
            v93,
            v78,
            _RBX,
            *(_QWORD *)(a2[1] + 56LL) + v75,
            v77,
            v14,
            *(double *)&_XMM0,
            *(double *)&_XMM1,
            *(double *)&_XMM2,
            *(double *)&_XMM3,
            *(double *)&_XMM4);
          v23 = v99;
          v18 = a5[15];
        }
        else
        {
          v100 = v24;
          __asm
          {
            vmovaps xmm1, xmm5
            vmovss  xmm3, cs:dword_30A60
          }
          (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, unsigned __int64, double, double, double, double))(v93 + 344))(
            v93,
            v78,
            _RBX,
            v77,
            v14,
            *(double *)&_XMM0,
            *(double *)&_XMM1,
            *(double *)&_XMM2,
            *(double *)&_XMM3);
          v23 = v100;
          v18 = a5[15];
        }
      }
      ++v23;
    }
    while ( v23 < v18 );
  }
  nc_free(v17);
  nc_free((void *)_RBX);
  nc_free_tensor(a4);
  return nc_free_tensor(a5);
}

// ======================================================
// Function: sub_10330 @ 0x10330
// ======================================================

void __fastcall sub_10330(__int64 _RDI)
{
  __asm
  {
    vmovss  xmm0, dword ptr [rdi+2Ch]
    vmulss  xmm0, xmm0, dword ptr [rdi+8]
    vmovss  xmm1, dword ptr [rdi+28h]
    vmulss  xmm2, xmm1, dword ptr [rdi+4]
    vmovss  xmm1, cs:dword_30A60
  }
  ++*(_QWORD *)(_RDI + 32);
  __asm
  {
    vmovss  dword ptr [rdi+2Ch], xmm0
    vsubss  xmm0, xmm1, xmm0
    vsubss  xmm1, xmm1, xmm2
    vmovss  dword ptr [rdi+28h], xmm2
    vsqrtss xmm0, xmm0, xmm0
    vdivss  xmm1, xmm0, xmm1
    vmulss  xmm0, xmm0, dword ptr [rdi+0Ch]
    vmulss  xmm0, xmm0, xmm0
    vmovss  dword ptr [rdi+38h], xmm0
    vmovss  dword ptr [rdi+30h], xmm1
    vmulss  xmm1, xmm1, dword ptr [rdi+18h]
    vmovss  dword ptr [rdi+34h], xmm1
  }
}

// ======================================================
// Function: sub_16B40 @ 0x16B40
// ======================================================

_QWORD *__fastcall sub_16B40(__int64 a1, __int64 a2, __m128 _XMM0)
{
  __int64 v4; // rbp
  _QWORD *v5; // rbx
  char v7; // zf
  char v8; // pf

  _R12 = a1;
  v4 = **(_QWORD **)(a2 + 16);
  v5 = (_QWORD *)nc_mallocz(0x10uLL);
  __asm { vxorps  xmm0, xmm0, xmm0 }
  *v5 = nc_new_tensor_from_tensor(v4);
  __asm { vucomiss xmm0, dword ptr [r12+4] }
  if ( !v8 && v7 )
    return v5;
  v5[1] = nc_new_tensor_from_tensor(v4);
  return v5;
}

// ======================================================
// Function: sub_16F70 @ 0x16F70
// ======================================================

void __fastcall sub_16F70(__int64 a1, void **a2)
{
  nc_free_tensor(*a2);
  nc_free_tensor(a2[1]);
  nc_free(a2);
}

// ======================================================
// Function: sub_102F0 @ 0x102F0
// ======================================================

void __fastcall sub_102F0(__int64 _RDI, __m128 _XMM0)
{
  __asm
  {
    vmovss  xmm3, cs:dword_30A60
    vsubss  xmm1, xmm3, dword ptr [rdi+2Ch]
    vmovss  dword ptr [rdi+18h], xmm0
    vsubss  xmm3, xmm3, dword ptr [rdi+28h]
    vsqrtss xmm1, xmm1, xmm1
    vdivss  xmm2, xmm1, xmm3
    vmulss  xmm0, xmm0, xmm2
    vmovss  dword ptr [rdi+30h], xmm2
    vmovss  dword ptr [rdi+34h], xmm0
    vmulss  xmm0, xmm1, dword ptr [rdi+0Ch]
    vmulss  xmm0, xmm0, xmm0
    vmovss  dword ptr [rdi+38h], xmm0
  }
}

// ======================================================
// Function: sub_6680 @ 0x6680
// ======================================================

__int128 __usercall sub_6680@<xmm0>(__int64 _RDI@<rdi>)
{
  __int128 result; // xmm0

  __asm { vmovss  xmm0, dword ptr [rdi+18h] }
  return result;
}

// ======================================================
// Function: sub_17570 @ 0x17570
// ======================================================

__int64 __fastcall sub_17570(__int64 a1, void **a2, __int64 a3, void *a4)
{
  __int64 result; // rax

  result = nc_free_tensor(*a2);
  *a2 = a4;
  return result;
}

// ======================================================
// Function: sub_11280 @ 0x11280
// ======================================================

__int64 sub_11280()
{
  return nc_mallocz(8uLL);
}

// ======================================================
// Function: sub_17550 @ 0x17550
// ======================================================

void __fastcall sub_17550(__int64 a1, void **a2)
{
  nc_free_tensor(*a2);
  nc_free(a2);
}

// ======================================================
// Function: sub_5FE0 @ 0x5FE0
// ======================================================

__int64 *__fastcall sub_5FE0(__int64 _RDI, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, char a7)
{
  __int64 *v7; // rax
  __int64 v9; // r14
  int v10; // r13d
  __int64 v11; // rax
  __int64 v12; // rax
  _QWORD *v13; // rdx
  int v15; // esi
  int v18; // r12d
  __int64 *result; // rax
  __int64 v20; // r15
  __int64 v21; // rbx
  __int64 v22; // rsi
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rdi
  __int64 v29; // rdi
  __int64 v30; // rcx
  __int64 v51; // r9
  unsigned __int64 v52; // r9
  __int64 v53; // rcx
  __int64 v54; // r9
  __int64 v55; // rcx
  unsigned __int64 v58; // rcx
  __int64 v62; // rcx
  __int64 v67; // rcx
  __int64 v68; // r9
  unsigned __int64 v86; // rdi
  __int64 v90; // rdi
  __int64 v91; // rdx
  __int64 v96; // rdi
  __int64 v97; // rdx
  __int64 v98; // rcx
  __int64 v99; // rsi
  __int64 v100; // rcx
  __int64 v104; // [rsp-48h] [rbp-48h]
  char *v105; // [rsp-38h] [rbp-38h]
  _QWORD v106[2]; // [rsp-10h] [rbp-10h] BYREF
  void *retaddr; // [rsp+0h] [rbp+0h]

  v106[1] = retaddr;
  v105 = &a7;
  v7 = *(__int64 **)(a3 + 16);
  __asm { vmovss  xmm0, dword ptr [rdi+18h] }
  v9 = *v7;
  v10 = *(_DWORD *)(*v7 + 80);
  if ( v10 <= 0 )
  {
    v106[-10] = 0LL;
    _R8 = 0LL;
    v13 = &v106[-10];
    v106[-11] = 1LL;
    HIDWORD(v106[-12]) = 0;
    goto LABEL_19;
  }
  if ( !*(_BYTE *)(v9 + 73) || !*(_BYTE *)(a4 + 73) )
  {
    v106[-11] = 1LL;
    HIDWORD(v106[-12]) = 0;
    goto LABEL_15;
  }
  v11 = *(_QWORD *)(v9 + 120);
  if ( v10 == 1 )
  {
    HIDWORD(v106[-12]) = 1;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v9 + 74) || !*(_BYTE *)(a4 + 74) )
  {
    HIDWORD(v106[-12]) = 1;
LABEL_76:
    v106[-10] = 0LL;
    v106[-11] = (int)v11;
LABEL_16:
    v12 = 1LL;
    v13 = &v106[-10];
    do
      v13[v12++] = 0LL;
    while ( v10 > (int)v12 );
    _R8 = v106[-10];
    goto LABEL_19;
  }
  v11 *= *(_QWORD *)(v9 + 128);
  if ( v10 == 2 )
  {
    HIDWORD(v106[-12]) = 2;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v9 + 75) || !*(_BYTE *)(a4 + 75) )
  {
    HIDWORD(v106[-12]) = 2;
    goto LABEL_76;
  }
  v11 *= *(_QWORD *)(v9 + 136);
  if ( v10 == 3 )
  {
    HIDWORD(v106[-12]) = 3;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v9 + 76) || !*(_BYTE *)(a4 + 76) )
  {
    HIDWORD(v106[-12]) = 3;
    goto LABEL_76;
  }
  v11 *= *(_QWORD *)(v9 + 144);
  HIDWORD(v106[-12]) = 4;
LABEL_14:
  v106[-11] = (int)v11;
LABEL_15:
  v106[-10] = 0LL;
  if ( v10 > 1 )
    goto LABEL_16;
  _R8 = 0LL;
  v13 = &v106[-10];
LABEL_19:
  v15 = HIDWORD(v106[-12]);
  __asm { vbroadcastss ymm2, xmm0 }
  v18 = v10;
  result = &v13[v15];
  v106[-19] = v106[-11] - 1LL;
  v20 = v9 + 8LL * (unsigned int)(v15 + 1);
  v106[-14] = v15 + 12LL;
  v21 = (unsigned int)(v10 - 1 - v15);
  while ( _R8 != -1 )
  {
    v22 = *(_QWORD *)(v9 + 56);
    if ( v18 <= 0 )
    {
      v23 = 0LL;
    }
    else
    {
      v23 = *(_QWORD *)(v9 + 88) * _R8;
      if ( v18 != 1 )
      {
        v23 += *(_QWORD *)(v9 + 96) * v106[-9];
        if ( v18 != 2 )
        {
          v23 += *(_QWORD *)(v9 + 104) * v106[-8];
          if ( v18 != 3 )
          {
            v24 = v104;
            v25 = *(_QWORD *)(v9 + 112);
            goto LABEL_26;
          }
        }
      }
    }
    while ( 1 )
    {
      v24 = *(unsigned int *)(a4 + 80);
      _R13 = *(_QWORD *)(a4 + 56);
      if ( (int)v24 <= 0 )
        break;
      _R8 *= *(_QWORD *)(a4 + 88);
      if ( (_DWORD)v24 == 1 )
        goto LABEL_33;
      _R8 += *(_QWORD *)(a4 + 96) * v106[-9];
      if ( (_DWORD)v24 == 2 )
        goto LABEL_33;
      _R8 += *(_QWORD *)(a4 + 104) * v106[-8];
      if ( (_DWORD)v24 == 3 )
        goto LABEL_33;
      v25 = *(_QWORD *)(a4 + 112);
      if ( (_DWORD)v24 == 4 )
      {
        _R8 += v104 * v25;
        goto LABEL_33;
      }
LABEL_26:
      v23 += v25 * v24;
    }
    _R8 = 0LL;
LABEL_33:
    if ( v106[-11] )
    {
      _R10 = _R13 + _R8;
      _R9 = v22 + v23;
      if ( (v22 + v23 >= (unsigned __int64)(_R13 + _R8 + 32) || _R13 + _R8 >= (unsigned __int64)(v22 + v23 + 32))
        && v106[-11] > 0xAuLL )
      {
        v29 = 0LL;
        v30 = -(int)(_R9 >> 2) & 7;
        if ( (-(int)(_R9 >> 2) & 7) != 0 )
        {
          __asm
          {
            vmovss  xmm1, dword ptr [r10]
            vfnmadd213ss xmm1, xmm0, dword ptr [r9]
            vmovss  dword ptr [r9], xmm1
          }
          if ( v30 == 1 )
          {
            v29 = 1LL;
          }
          else
          {
            _RDI = v22 + v23 + 4;
            __asm
            {
              vmovss  xmm1, dword ptr [r13+r8+4]
              vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
              vmovss  dword ptr [rdi], xmm1
            }
            if ( v30 == 2 )
            {
              v29 = 2LL;
            }
            else
            {
              _RDI = v22 + v23 + 8;
              __asm
              {
                vmovss  xmm1, dword ptr [r13+r8+8]
                vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
                vmovss  dword ptr [rdi], xmm1
              }
              if ( v30 == 3 )
              {
                v29 = 3LL;
              }
              else
              {
                _RDI = v22 + v23 + 12;
                __asm
                {
                  vmovss  xmm1, dword ptr [r13+r8+0Ch]
                  vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
                  vmovss  dword ptr [rdi], xmm1
                }
                if ( v30 == 4 )
                {
                  v29 = 4LL;
                }
                else
                {
                  _RDI = v22 + v23 + 16;
                  __asm
                  {
                    vmovss  xmm1, dword ptr [r13+r8+10h]
                    vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
                    vmovss  dword ptr [rdi], xmm1
                  }
                  if ( v30 == 5 )
                  {
                    v29 = 5LL;
                  }
                  else
                  {
                    _RDI = v22 + v23 + 20;
                    __asm
                    {
                      vmovss  xmm1, dword ptr [r13+r8+14h]
                      vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
                      vmovss  dword ptr [rdi], xmm1
                    }
                    if ( v30 == 7 )
                    {
                      _RDI = v22 + v23 + 24;
                      __asm
                      {
                        vmovss  xmm1, dword ptr [r13+r8+18h]
                        vfnmadd213ss xmm1, xmm0, dword ptr [rdi]
                        vmovss  dword ptr [rdi], xmm1
                      }
                      v29 = 7LL;
                    }
                    else
                    {
                      v29 = 6LL;
                    }
                  }
                }
              }
            }
          }
        }
        v51 = v106[-11] - v30;
        v106[-16] = v51;
        v52 = ((unsigned __int64)(v51 - 8) >> 3) + 1;
        v106[-13] = v52;
        v106[-15] = 8 * v52;
        if ( (unsigned __int64)(v106[-19] - v30) <= 6 )
          goto LABEL_48;
        v53 = 4 * v30;
        v106[-20] = _R13;
        v54 = v53 + v23;
        v55 = _R13 + _R8 + v53;
        v106[-18] = v22 + v54;
        _R13 = v106[-18];
        _R9 = 0LL;
        v106[-17] = v55;
        v58 = 0LL;
        v106[-18] = result;
        _RAX = v106[-17];
        do
        {
          __asm
          {
            vmovups ymm1, ymmword ptr [rax+r9]
            vfnmadd213ps ymm1, ymm2, ymmword ptr [r13+r9+0]
          }
          ++v58;
          __asm { vmovaps ymmword ptr [r13+r9+0], ymm1 }
          _R9 += 32LL;
        }
        while ( v106[-13] > v58 );
        v62 = v106[-15];
        _R13 = v106[-20];
        result = (__int64 *)v106[-18];
        v29 += v62;
        if ( v62 != v106[-16] )
        {
LABEL_48:
          _R9 = _R13 + 4 * v29;
          _RCX = v22 + 4 * v29 + v23;
          __asm
          {
            vmovss  xmm1, dword ptr [r9+r8]
            vfnmadd213ss xmm1, xmm0, dword ptr [rcx]
            vmovss  dword ptr [rcx], xmm1
          }
          if ( (unsigned __int64)(v29 + 1) < v106[-11] )
          {
            v67 = 4 * (v29 + 1);
            v68 = v67 + v23;
            _RCX = _R13 + v67;
            _R9 = v22 + v68;
            __asm
            {
              vmovss  xmm1, dword ptr [rcx+r8]
              vfnmadd213ss xmm1, xmm0, dword ptr [r9]
              vmovss  dword ptr [r9], xmm1
            }
            if ( v106[-11] > (unsigned __int64)(v29 + 2) )
            {
              _RCX = 4 * (v29 + 2);
              __asm { vmovss  xmm1, dword ptr [r10+rcx] }
              _R9 = v22 + v23 + _RCX;
              __asm
              {
                vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                vmovss  dword ptr [r9], xmm1
              }
              if ( v106[-11] > (unsigned __int64)(v29 + 3) )
              {
                _RCX = 4 * (v29 + 3);
                __asm { vmovss  xmm1, dword ptr [r10+rcx] }
                _R9 = v22 + v23 + _RCX;
                __asm
                {
                  vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                  vmovss  dword ptr [r9], xmm1
                }
                if ( v106[-11] > (unsigned __int64)(v29 + 4) )
                {
                  _RCX = 4 * (v29 + 4);
                  __asm { vmovss  xmm1, dword ptr [r10+rcx] }
                  _R9 = v22 + v23 + _RCX;
                  __asm
                  {
                    vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                    vmovss  dword ptr [r9], xmm1
                  }
                  if ( v106[-11] > (unsigned __int64)(v29 + 5) )
                  {
                    _RCX = 4 * (v29 + 5);
                    v86 = v29 + 6;
                    __asm { vmovss  xmm1, dword ptr [r10+rcx] }
                    _R9 = v22 + v23 + _RCX;
                    __asm
                    {
                      vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                      vmovss  dword ptr [r9], xmm1
                    }
                    if ( v106[-11] > v86 )
                    {
                      v90 = 4 * v86;
                      v91 = v90 + v23;
                      _RDI = _R13 + v90;
                      _RDX = v22 + v91;
                      __asm
                      {
                        vmovss  xmm1, dword ptr [rdi+r8]
                        vfnmadd213ss xmm1, xmm0, dword ptr [rdx]
                        vmovss  dword ptr [rdx], xmm1
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v100 = v106[-11];
        _RDX = 0LL;
        do
        {
          __asm
          {
            vmovss  xmm1, dword ptr [r10+rdx*4]
            vfnmadd213ss xmm1, xmm0, dword ptr [r9+rdx*4]
            vmovss  dword ptr [r9+rdx*4], xmm1
          }
          ++_RDX;
        }
        while ( v100 != _RDX );
      }
    }
    if ( v18 <= SHIDWORD(v106[-12]) )
      break;
    v96 = v106[-14];
    v97 = 0LL;
    v98 = *result + 1;
    *result = v98;
    if ( v98 == *(_QWORD *)(v9 + 8 * v96 + 24) )
    {
      do
      {
        result[v97] = 0LL;
        if ( v97 == v21 )
          goto LABEL_60;
        v99 = result[v97 + 1];
        result[++v97] = v99 + 1;
      }
      while ( v99 + 1 == *(_QWORD *)(v20 + 8 * v97 + 112) );
    }
    _R8 = v106[-10];
  }
LABEL_60:
  __asm { vzeroupper }
  return result;
}

