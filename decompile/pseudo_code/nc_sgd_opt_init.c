// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sgd_opt_init
// Included functions: 14

// ======================================================
// Function: nc_sgd_opt_init @ 0x66A31BB0
// ======================================================

_QWORD *__fastcall nc_sgd_opt_init(__int64 a1, _DWORD *a2)
{
  int v2; // eax
  _QWORD *v5; // rbx
  _DWORD *v6; // rax
  _QWORD *result; // rax
  _QWORD *v8; // rbx
  _QWORD *v11; // rax
  _QWORD *v12; // rbx
  _QWORD *v13; // rax

  v2 = *a2;
  _RSI = a2;
  if ( *a2 == 1 )
  {
    v11 = aligned_malloc(0x60ui64, 0x40ui64);
    v12 = v11;
    if ( !v11 )
      goto LABEL_9;
    memset(v11, 0, 0x60ui64);
    *v11 = a1;
    v11[1] = v11 + 1;
    v11[2] = v11 + 1;
    v13 = aligned_malloc(0x40ui64, 0x40ui64);
    _RDX = v13;
    if ( v13 )
    {
      __asm { vmovss  xmm2, cs:dword_66A377C0 }
      memset(v13, 0, 0x40ui64);
      *v13 = *_RSI;
      __asm { vmovss  xmm1, dword ptr [rdx+4] }
      v13[1] = _RSI[1];
      __asm { vmovss  xmm0, dword ptr [rdx+8] }
      v13[2] = _RSI[2];
      __asm
      {
        vmovss  xmm3, dword ptr [rsi+14h]
        vmovss  dword ptr [rdx+2Ch], xmm0
        vsubss  xmm0, xmm2, xmm0
        vsubss  xmm2, xmm2, xmm1
        vmovss  dword ptr [rdx+28h], xmm1
        vmovss  dword ptr [rdx+18h], xmm3
        vsqrtss xmm0, xmm0, xmm0
      }
      v13[4] = 0i64;
      __asm
      {
        vdivss  xmm1, xmm0, xmm2
        vmulss  xmm0, xmm0, dword ptr [rdx+0Ch]
        vmulss  xmm0, xmm0, xmm0
        vmovss  dword ptr [rdx+38h], xmm0
        vmovss  dword ptr [rdx+30h], xmm1
        vmulss  xmm1, xmm3, xmm1
        vmovss  dword ptr [rdx+34h], xmm1
      }
      v12[4] = sub_66A1E140;
      v12[5] = sub_66A15700;
      v12[6] = sub_66A0EDE0;
      v12[7] = aligned_free;
      v12[8] = sub_66A14340;
      v12[9] = sub_66A156D0;
      v12[10] = sub_66A0EDA0;
      v12[11] = sub_66A03000;
      result = v12;
      v12[3] = _RDX;
      return result;
    }
LABEL_13:
    MEMORY[0] = *_RSI;
    MEMORY[8] = _RSI[1];
    MEMORY[0x10] = _RSI[2];
    BUG();
  }
  if ( !v2 )
  {
    v8 = aligned_malloc(0x60ui64, 0x40ui64);
    if ( !v8 )
      goto LABEL_9;
    memset(v8, 0, 0x60ui64);
    *v8 = a1;
    v8[1] = v8 + 1;
    v8[2] = v8 + 1;
    _RAX = aligned_malloc(0x1Cui64, 0x40ui64);
    if ( _RAX )
    {
      *_RAX = 0i64;
      _RAX[1] = 0i64;
      _RAX[2] = 0i64;
      *((_DWORD *)_RAX + 6) = 0;
      *_RAX = *_RSI;
      _RAX[1] = _RSI[1];
      _RAX[2] = _RSI[2];
      __asm
      {
        vmovss  xmm0, dword ptr [rsi+14h]
        vmovss  dword ptr [rax+18h], xmm0
      }
      v8[4] = sub_66A02980;
      v8[6] = nullsub_1;
      v8[3] = _RAX;
      result = v8;
      v8[7] = aligned_free_0;
      return result;
    }
    goto LABEL_13;
  }
  if ( v2 != 2 )
    abort();
  v5 = aligned_malloc(0x60ui64, 0x40ui64);
  if ( !v5 )
  {
LABEL_9:
    MEMORY[8] = 8i64;
    BUG();
  }
  memset(v5, 0, 0x60ui64);
  *v5 = a1;
  v5[1] = v5 + 1;
  v5[2] = v5 + 1;
  v6 = aligned_malloc(4ui64, 0x40ui64);
  if ( v6 )
    *v6 = 0;
  v5[3] = v6;
  result = v5;
  v5[4] = sub_66A15D80;
  v5[7] = aligned_free_1;
  v5[8] = sub_66A103E0;
  v5[9] = sub_66A15D60;
  return result;
}

// ======================================================
// Function: sub_66A1E140 @ 0x66A1E140
// ======================================================

void __fastcall sub_66A1E140(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  void (__fastcall *v4)(__int64, __int64, __int64, __int64, int, int, int, int, __int64); // r14
  __int64 v9; // rbp
  unsigned int v12; // eax
  bool v13; // zf
  bool v14; // pf
  _BYTE *v19; // rcx
  _BYTE *v20; // r8
  int v21; // eax
  __int64 v22; // rdx
  int v23; // r15d
  __int64 v24; // rdx
  __int64 v25; // rsi
  __int64 *v26; // rbx
  __int64 v28; // r9
  __int64 v29; // rdx
  __int64 v30; // r9
  __int64 v31; // r8
  __int64 v32; // r10
  int v33; // eax
  __int64 v34; // rdx
  __int64 v35; // rdx
  __int64 v36; // rcx
  _QWORD *v44; // rax
  __int64 v45; // rax
  __int64 v46; // rcx
  __int64 v47; // rax
  __int64 v48; // r11
  _QWORD *v49; // rbx
  char v53; // cf
  int v54; // [rsp+20h] [rbp-118h]
  int v55; // [rsp+28h] [rbp-110h]
  int v56; // [rsp+28h] [rbp-110h]
  int v57; // [rsp+30h] [rbp-108h]
  int v58; // [rsp+30h] [rbp-108h]
  int v59; // [rsp+38h] [rbp-100h]
  int v60; // [rsp+38h] [rbp-100h]
  __int64 v61; // [rsp+40h] [rbp-F8h]
  __int64 v62; // [rsp+48h] [rbp-F0h]
  __int64 v63; // [rsp+60h] [rbp-D8h]
  __int64 v65; // [rsp+70h] [rbp-C8h]
  __int64 v66; // [rsp+90h] [rbp-A8h] BYREF
  __int64 v67; // [rsp+98h] [rbp-A0h]
  __int64 v68; // [rsp+A0h] [rbp-98h]
  __int64 v69; // [rsp+A8h] [rbp-90h]

  __asm
  {
    vmovaps [rsp+138h+var_88], xmm6
    vmovaps [rsp+138h+var_78], xmm7
    vmovaps [rsp+138h+var_68], xmm8
    vmovaps [rsp+138h+var_58], xmm9
  }
  v9 = **(_QWORD **)(a3 + 16);
  _R13 = a1;
  v63 = *(_QWORD *)(*(_QWORD *)(v9 + 40) + 24i64);
  v12 = *(_DWORD *)(a4 + 48);
  if ( *(_DWORD *)(v9 + 48) != v12 || (v13 = v12 == 1, v14 = __SETP__(v12, 1), v12 > 1) )
    sub_66A33D40(
      "yg->item_type == y->item_type && (yg->item_type == NC_TYPE_F32 || yg->item_type == NC_TYPE_BF16)",
      "libnc.c",
      9764);
  __asm
  {
    vmovss  xmm6, dword ptr [r13+10h]
    vxorps  xmm7, xmm7, xmm7
    vmovss  xmm8, cs:dword_66A377C0
    vucomiss xmm6, xmm7
  }
  if ( !v14 && v13 )
    goto LABEL_6;
  if ( !*(_DWORD *)(a4 + 80) )
    goto LABEL_6;
  ++*(_DWORD *)(a4 + 16);
  v49 = nc_reduce_sum_sqr(a4);
  _XMM0 = nc_get1_f32((__int64)v49, 0, 0i64);
  __asm { vmovaps xmm9, xmm0 }
  nc_free_tensor(v49);
  __asm
  {
    vsqrtss xmm0, xmm0, xmm9
    vdivss  xmm6, xmm6, xmm0
    vucomiss xmm6, xmm8
  }
  if ( !(v53 | v13) )
LABEL_6:
    __asm { vmovaps xmm6, xmm8 }
  v19 = (_BYTE *)a2[1];
  if ( v19 )
  {
    v20 = (_BYTE *)*a2;
    v21 = *(_DWORD *)(v9 + 80);
    if ( v21 > 0 && *(_BYTE *)(v9 + 73) && *(_BYTE *)(a4 + 73) && v20[73] && v19[73] )
    {
      v22 = *(_QWORD *)(v9 + 120);
      if ( v21 != 1 )
      {
        if ( *(_BYTE *)(v9 + 74) && *(_BYTE *)(a4 + 74) && v20[74] && v19[74] )
        {
          v22 *= *(_QWORD *)(v9 + 128);
          if ( v21 != 2 )
          {
            if ( *(_BYTE *)(v9 + 75) && *(_BYTE *)(a4 + 75) && v20[75] && v19[75] )
            {
              v22 *= *(_QWORD *)(v9 + 136);
              if ( v21 != 3 )
              {
                if ( *(_BYTE *)(v9 + 76) && *(_BYTE *)(a4 + 76) && v20[76] )
                  goto LABEL_27;
                goto LABEL_108;
              }
              goto LABEL_116;
            }
            goto LABEL_111;
          }
          goto LABEL_114;
        }
        goto LABEL_113;
      }
      goto LABEL_115;
    }
  }
  else
  {
    v19 = (_BYTE *)*a2;
    v21 = *(_DWORD *)(v9 + 80);
    if ( v21 > 0 && *(_BYTE *)(v9 + 73) && *(_BYTE *)(a4 + 73) && v19[73] )
    {
      v22 = *(_QWORD *)(v9 + 120);
      if ( v21 != 1 )
      {
        if ( *(_BYTE *)(v9 + 74) && *(_BYTE *)(a4 + 74) && v19[74] )
        {
          v22 *= *(_QWORD *)(v9 + 128);
          if ( v21 != 2 )
          {
            if ( *(_BYTE *)(v9 + 75) && *(_BYTE *)(a4 + 75) && v19[75] )
            {
              v22 *= *(_QWORD *)(v9 + 136);
              if ( v21 != 3 )
              {
                if ( *(_BYTE *)(v9 + 76) && *(_BYTE *)(a4 + 76) )
                {
LABEL_27:
                  if ( v19[76] )
                  {
                    v22 *= *(_QWORD *)(v9 + 144);
                    v23 = 4;
LABEL_29:
                    v65 = (int)v22;
                    goto LABEL_30;
                  }
                }
LABEL_108:
                v23 = 3;
LABEL_112:
                v66 = 0i64;
                v65 = (int)v22;
                goto LABEL_31;
              }
LABEL_116:
              v23 = 3;
              goto LABEL_29;
            }
LABEL_111:
            v23 = 2;
            goto LABEL_112;
          }
LABEL_114:
          v23 = 2;
          goto LABEL_29;
        }
LABEL_113:
        v23 = 1;
        goto LABEL_112;
      }
LABEL_115:
      v23 = 1;
      goto LABEL_29;
    }
  }
  v65 = 1i64;
  v23 = 0;
LABEL_30:
  v66 = 0i64;
  if ( v21 <= 1 )
  {
    v25 = 0i64;
    goto LABEL_34;
  }
LABEL_31:
  v24 = 1i64;
  do
    *(&v66 + v24++) = 0i64;
  while ( v21 > (int)v24 );
  v25 = v66;
LABEL_34:
  v26 = &v66 + v23;
  while ( v25 != -1 )
  {
    __asm
    {
      vmovss  xmm0, dword ptr [r13+4]
      vucomiss xmm0, xmm7
    }
    if ( *(_DWORD *)(a4 + 48) )
    {
      sub_66A33D40("yg->item_type == NC_TYPE_F32", "libnc.c", 9794);
      __asm { vmovss  xmm0, dword ptr [r13+4] }
    }
    __asm
    {
      vmovss  xmm3, dword ptr [r13+38h]
      vmovss  xmm2, dword ptr [r13+8]
      vmovss  xmm1, dword ptr [r13+34h]
    }
    v32 = *(_QWORD *)(v63 + 360);
    v44 = (_QWORD *)*a2;
    v31 = *(unsigned int *)(*a2 + 80i64);
    if ( (int)v31 <= 0 )
    {
      v29 = 0i64;
    }
    else
    {
      v29 = v44[11] * v25;
      if ( (_DWORD)v31 != 1 )
      {
        v29 += v44[12] * v67;
        if ( (_DWORD)v31 != 2 )
        {
          v29 += v44[13] * v68;
          if ( (_DWORD)v31 != 3 )
          {
            v30 = v69;
            v45 = v44[14];
            if ( (_DWORD)v31 != 4 )
              goto LABEL_37;
            v29 += v45 * v69;
          }
        }
      }
    }
    v46 = v29 + *(_QWORD *)(*a2 + 56i64);
    v47 = a2[1];
    v29 = *(unsigned int *)(v47 + 80);
    v48 = *(_QWORD *)(v47 + 56);
    if ( (int)v29 <= 0 )
    {
      v30 = 0i64;
    }
    else
    {
      v30 = *(_QWORD *)(v47 + 88) * v25;
      if ( (_DWORD)v29 != 1 )
      {
        v30 += *(_QWORD *)(v47 + 96) * v67;
        if ( (_DWORD)v29 != 2 )
        {
          v30 += *(_QWORD *)(v47 + 104) * v68;
          if ( (_DWORD)v29 != 3 )
          {
            v31 = v69;
            v45 = *(_QWORD *)(v47 + 112);
            if ( (_DWORD)v29 != 4 )
              goto LABEL_37;
            v30 += v45 * v69;
          }
        }
      }
    }
    LODWORD(v45) = *(_DWORD *)(a4 + 80);
    v30 += v48;
    v29 = *(_QWORD *)(a4 + 56);
    if ( (int)v45 <= 0 )
    {
      v31 = 0i64;
    }
    else
    {
      v31 = *(_QWORD *)(a4 + 88) * v25;
      if ( (_DWORD)v45 != 1 )
      {
        v31 += *(_QWORD *)(a4 + 96) * v67;
        if ( (_DWORD)v45 != 2 )
        {
          v31 += *(_QWORD *)(a4 + 104) * v68;
          if ( (_DWORD)v45 != 3 )
          {
            v4 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, int, int, int, int, __int64))(a4 + 112);
            if ( (_DWORD)v45 != 4 )
              goto LABEL_37;
            v31 += (_QWORD)v4 * v69;
          }
        }
      }
    }
    LODWORD(v45) = *(_DWORD *)(v9 + 80);
    v31 += v29;
    v29 = *(_QWORD *)(v9 + 56);
    if ( (int)v45 <= 0 )
    {
      v25 = 0i64;
      goto LABEL_82;
    }
    v25 *= *(_QWORD *)(v9 + 88);
    if ( (_DWORD)v45 == 1 )
      goto LABEL_82;
    v25 += *(_QWORD *)(v9 + 96) * v67;
    if ( (_DWORD)v45 == 2 )
      goto LABEL_82;
    v25 += *(_QWORD *)(v9 + 104) * v68;
    if ( (_DWORD)v45 == 3 )
      goto LABEL_82;
    v4 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, int, int, int, int, __int64))(v9 + 112);
    if ( (_DWORD)v45 == 4 )
    {
      v25 += (_QWORD)v4 * v69;
LABEL_82:
      __asm
      {
        vmovss  dword ptr [rsp+138h+var_F0], xmm6
        vmovss  dword ptr [rsp+138h+var_F8], xmm3
        vmovss  [rsp+138h+var_100], xmm2
        vmovss  [rsp+138h+var_108], xmm0
        vmovss  [rsp+138h+var_110], xmm1
      }
      ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, int, int, int, __int64, __int64, __int64))v32)(
        v63,
        v25 + v29,
        v31,
        v30,
        v46,
        v56,
        v58,
        v60,
        v61,
        v62,
        v65);
      goto LABEL_50;
    }
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_37:
        v28 = v29 * v31 + v30;
        v29 = *(unsigned int *)(a4 + 80);
        v30 = v32 + v28;
        if ( (int)v29 <= 0 )
        {
          v31 = 0i64;
          break;
        }
        v31 = *(_QWORD *)(a4 + 88) * v25;
        if ( (_DWORD)v29 == 1 )
          break;
        v31 += *(_QWORD *)(a4 + 96) * v67;
        if ( (_DWORD)v29 == 2 )
          break;
        v31 += *(_QWORD *)(a4 + 104) * v68;
        if ( (_DWORD)v29 == 3 )
          break;
        v32 = v69;
        if ( (_DWORD)v29 == 4 )
        {
          v31 += *(_QWORD *)(a4 + 112) * v69;
          break;
        }
      }
      v31 += *(_QWORD *)(a4 + 56);
      v29 = *(_QWORD *)(v9 + 56);
      if ( (int)v45 <= 0 )
        break;
      v25 *= *(_QWORD *)(v9 + 88);
      if ( (_DWORD)v45 == 1 )
        goto LABEL_49;
      v25 += *(_QWORD *)(v9 + 96) * v67;
      if ( (_DWORD)v45 == 2 )
        goto LABEL_49;
      v25 += *(_QWORD *)(v9 + 104) * v68;
      if ( (_DWORD)v45 == 3 )
        goto LABEL_49;
      v32 = *(_QWORD *)(v9 + 112);
      if ( (_DWORD)v45 == 4 )
      {
        v25 += v32 * v69;
        goto LABEL_49;
      }
    }
    v25 = 0i64;
LABEL_49:
    __asm
    {
      vmovss  [rsp+138h+var_100], xmm6
      vmovss  [rsp+138h+var_108], xmm2
      vmovss  [rsp+138h+var_110], xmm1
      vmovss  dword ptr [rsp+138h+var_118], xmm0
    }
    v4(v63, v25 + v29, v31, v30, v54, v55, v57, v59, v65);
LABEL_50:
    v33 = *(_DWORD *)(v9 + 80);
    if ( v33 > v23 )
    {
      v34 = *v26 + 1;
      *v26 = v34;
      if ( *(_QWORD *)(v9 + 8 * (v23 + 12i64) + 24) == v34 )
      {
        v35 = 0i64;
        do
        {
          v26[v35] = 0i64;
          if ( v33 - 1 - v23 == v35 )
            goto LABEL_55;
          v36 = v26[v35 + 1] + 1;
          v26[++v35] = v36;
        }
        while ( v36 == *(_QWORD *)(v9 + 8i64 * (unsigned int)(v23 + 1) + 8 * v35 + 112) );
      }
      v25 = v66;
      continue;
    }
    break;
  }
LABEL_55:
  __asm
  {
    vmovaps xmm6, [rsp+138h+var_88]
    vmovaps xmm7, [rsp+138h+var_78]
    vmovaps xmm8, [rsp+138h+var_68]
    vmovaps xmm9, [rsp+138h+var_58]
  }
  nc_free_tensor((_DWORD *)a4);
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
// Function: sub_66A15700 @ 0x66A15700
// ======================================================

void __fastcall sub_66A15700(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // rdi
  unsigned __int64 v10; // rsi
  __int64 v11; // r13
  char *v13; // rax
  _DWORD *v14; // rbp
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // rax
  __int64 v17; // rdx
  _DWORD *v18; // rcx
  unsigned __int64 v21; // rdi
  unsigned __int64 v23; // r13
  __int64 v25; // r9
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // rdx
  unsigned __int64 v44; // r11
  __int64 v64; // rdx
  unsigned __int64 v65; // rax
  int *v72; // rax
  __int64 v73; // rdx
  __int64 v74; // rax
  __int64 v75; // rdx
  int v86; // [rsp+20h] [rbp-128h]
  int v87; // [rsp+28h] [rbp-120h]
  int v88; // [rsp+28h] [rbp-120h]
  int v89; // [rsp+30h] [rbp-118h]
  int v90; // [rsp+30h] [rbp-118h]
  int v91; // [rsp+38h] [rbp-110h]
  int v92; // [rsp+38h] [rbp-110h]
  __int64 v93; // [rsp+40h] [rbp-108h]
  int v94; // [rsp+48h] [rbp-100h]
  unsigned __int64 v95; // [rsp+70h] [rbp-D8h]
  _QWORD *v97; // [rsp+A8h] [rbp-A0h]
  __int64 v98; // [rsp+B0h] [rbp-98h]
  __int64 v99; // [rsp+C0h] [rbp-88h]

  __asm
  {
    vmovaps [rsp+148h+var_78], xmm6
    vmovaps [rsp+148h+var_68], xmm7
    vmovaps [rsp+148h+var_58], xmm8
  }
  v8 = *(_QWORD *)(a5 + 120);
  v97 = **(_QWORD ***)(a3 + 16);
  v98 = *(_QWORD *)(*(_QWORD *)(a4 + 40) + 24i64);
  v10 = v97[15];
  v11 = v97[16];
  _RBX = (unsigned __int64)aligned_malloc(4 * v10, 0x40ui64);
  v13 = (char *)aligned_malloc(4 * (v8 + v11), 0x40ui64);
  v14 = v13;
  if ( v11 )
    memset(&v13[4 * v8], 255, 4 * v11);
  v15 = *(_QWORD *)(a5 + 120);
  v16 = v15 - 1;
  v17 = 4 * v15 - 4;
  if ( v15 )
  {
    do
    {
      v18 = &v14[v8 + *(int *)(*(_QWORD *)(a5 + 56) + v17)];
      *(_DWORD *)((char *)v14 + v17) = *v18;
      v17 -= 4i64;
      *v18 = v16--;
    }
    while ( v16 != -1i64 );
    __asm
    {
      vxorps  xmm6, xmm6, xmm6
      vmovss  xmm7, cs:dword_66A377C0
    }
    v21 = -(int)(_RBX >> 2) & 7;
    __asm { vmovaps xmm8, xmm7 }
    if ( v21 > v10 )
      v21 = v10;
    v23 = 0i64;
    v95 = ((v10 - v21 - 8) >> 3) + 1;
    v99 = 8 * v95;
    _R14 = _RBX + 4 * v21;
    do
    {
      if ( v14[v23] != -2 )
      {
        memcpy((void *)_RBX, (const void *)(*(_QWORD *)(a4 + 56) + v23 * 4i64 * *(_QWORD *)(a4 + 64)), 4 * v10);
        v25 = (int)v14[v23];
        if ( (_DWORD)v25 != -1 )
        {
          v26 = 4i64 * *(_QWORD *)(a4 + 64);
          do
          {
            v27 = *(_QWORD *)(a4 + 56);
            v28 = v26 * v25;
            if ( v10 )
            {
              _RAX = 0i64;
              if ( (v27 + v28 >= _RBX + 32 || _RBX >= v27 + v28 + 32) && v10 > 0xB )
              {
                if ( v21 )
                {
                  __asm
                  {
                    vmovss  xmm0, dword ptr [rbx]
                    vaddss  xmm0, xmm0, dword ptr [rcx]
                    vmovss  dword ptr [rbx], xmm0
                  }
                  if ( v21 == 1 )
                  {
                    _RAX = 1i64;
                  }
                  else
                  {
                    __asm
                    {
                      vmovss  xmm0, dword ptr [rbx+4]
                      vaddss  xmm0, xmm0, dword ptr [r8+rdx+4]
                      vmovss  dword ptr [rbx+4], xmm0
                    }
                    if ( v21 == 2 )
                    {
                      _RAX = 2i64;
                    }
                    else
                    {
                      __asm
                      {
                        vmovss  xmm0, dword ptr [rbx+8]
                        vaddss  xmm0, xmm0, dword ptr [r8+rdx+8]
                        vmovss  dword ptr [rbx+8], xmm0
                      }
                      if ( v21 == 3 )
                      {
                        _RAX = 3i64;
                      }
                      else
                      {
                        __asm
                        {
                          vmovss  xmm0, dword ptr [rbx+0Ch]
                          vaddss  xmm0, xmm0, dword ptr [r8+rdx+0Ch]
                          vmovss  dword ptr [rbx+0Ch], xmm0
                        }
                        if ( v21 == 4 )
                        {
                          _RAX = 4i64;
                        }
                        else
                        {
                          __asm
                          {
                            vmovss  xmm0, dword ptr [rbx+10h]
                            vaddss  xmm0, xmm0, dword ptr [r8+rdx+10h]
                            vmovss  dword ptr [rbx+10h], xmm0
                          }
                          if ( v21 == 5 )
                          {
                            _RAX = 5i64;
                          }
                          else
                          {
                            __asm
                            {
                              vmovss  xmm0, dword ptr [rbx+14h]
                              vaddss  xmm0, xmm0, dword ptr [r8+rdx+14h]
                              vmovss  dword ptr [rbx+14h], xmm0
                            }
                            if ( v21 == 7 )
                            {
                              __asm
                              {
                                vmovss  xmm0, dword ptr [rbx+18h]
                                vaddss  xmm0, xmm0, dword ptr [r8+rdx+18h]
                              }
                              _RAX = 7i64;
                              __asm { vmovss  dword ptr [rbx+18h], xmm0 }
                            }
                            else
                            {
                              _RAX = 6i64;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                if ( v10 - 1 - v21 <= 6 )
                  goto LABEL_50;
                v44 = 0i64;
                _RDX = v27 + 4 * v21 + v28;
                _R8 = 0i64;
                do
                {
                  __asm
                  {
                    vmovups ymm0, ymmword ptr [rdx+r8]
                    vaddps  ymm0, ymm0, ymmword ptr [r14+r8]
                  }
                  ++v44;
                  __asm { vmovaps ymmword ptr [r14+r8], ymm0 }
                  _R8 += 32i64;
                }
                while ( v95 > v44 );
                _RAX += v99;
                if ( v99 != v10 - v21 )
                {
LABEL_50:
                  _RDX = _RBX + 4 * _RAX;
                  __asm
                  {
                    vmovss  xmm0, dword ptr [rdx]
                    vaddss  xmm0, xmm0, dword ptr [rcx+r8]
                    vmovss  dword ptr [rdx], xmm0
                  }
                  if ( _RAX + 1 < v10 )
                  {
                    _R8 = _RBX + 4 * (_RAX + 1);
                    __asm
                    {
                      vmovss  xmm0, dword ptr [r8]
                      vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                      vmovss  dword ptr [r8], xmm0
                    }
                    if ( v10 > _RAX + 2 )
                    {
                      _R8 = _RBX + 4 * (_RAX + 2);
                      __asm
                      {
                        vmovss  xmm0, dword ptr [r8]
                        vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                        vmovss  dword ptr [r8], xmm0
                      }
                      if ( v10 > _RAX + 3 )
                      {
                        _R8 = _RBX + 4 * (_RAX + 3);
                        __asm
                        {
                          vmovss  xmm0, dword ptr [r8]
                          vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                          vmovss  dword ptr [r8], xmm0
                        }
                        if ( v10 > _RAX + 4 )
                        {
                          _R8 = _RBX + 4 * (_RAX + 4);
                          __asm
                          {
                            vmovss  xmm0, dword ptr [r8]
                            vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                            vmovss  dword ptr [r8], xmm0
                          }
                          if ( v10 > _RAX + 5 )
                          {
                            v64 = 4 * (_RAX + 5);
                            v65 = _RAX + 6;
                            _R8 = _RBX + v64;
                            __asm
                            {
                              vmovss  xmm0, dword ptr [r8]
                              vaddss  xmm0, xmm0, dword ptr [rcx+rdx]
                              vmovss  dword ptr [r8], xmm0
                            }
                            if ( v10 > v65 )
                            {
                              _RDX = _RBX + 4 * v65;
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
                while ( v10 != _RAX );
              }
            }
            v72 = &v14[v25];
            v25 = *v72;
            *v72 = -2;
          }
          while ( (_DWORD)v25 != -1 );
        }
        v73 = *(int *)(*(_QWORD *)(a5 + 56) + 4 * v23);
        v74 = v73 * 4i64 * v97[8];
        v75 = v97[7] + v97[12] * v73;
        _R10 = a1;
        __asm
        {
          vmovss  xmm0, dword ptr [r10+4]
          vmovss  xmm2, dword ptr [r10+8]
          vmovss  xmm1, dword ptr [r10+34h]
          vmovss  xmm3, dword ptr [r10+38h]
          vucomiss xmm0, xmm6
        }
        if ( __SETP__(*(_QWORD *)(*a2 + 56i64) + v74, 0i64) || *(_QWORD *)(*a2 + 56i64) + v74 )
        {
          __asm
          {
            vmovss  [rsp+148h+var_100], xmm7
            vmovss  dword ptr [rsp+148h+var_108], xmm3
            vmovss  [rsp+148h+var_110], xmm2
            vmovss  [rsp+148h+var_118], xmm0
            vmovss  [rsp+148h+var_120], xmm1
          }
          (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, __int64, int, int, int, __int64, int, unsigned __int64))(v98 + 360))(
            v98,
            v75,
            _RBX,
            *(_QWORD *)(a2[1] + 56i64) + v74,
            *(_QWORD *)(*a2 + 56i64) + v74,
            v87,
            v89,
            v91,
            v93,
            v94,
            v10);
          v15 = *(_QWORD *)(a5 + 120);
        }
        else
        {
          __asm
          {
            vmovss  [rsp+148h+var_110], xmm8
            vmovss  [rsp+148h+var_118], xmm3
            vmovss  [rsp+148h+var_120], xmm2
            vmovss  dword ptr [rsp+148h+var_128], xmm1
          }
          (*(void (__fastcall **)(__int64, __int64, unsigned __int64, __int64, int, int, int, int, unsigned __int64))(v98 + 344))(
            v98,
            v75,
            _RBX,
            *(_QWORD *)(*a2 + 56i64) + v74,
            v86,
            v88,
            v90,
            v92,
            v10);
          v15 = *(_QWORD *)(a5 + 120);
        }
      }
      ++v23;
    }
    while ( v23 < v15 );
  }
  _aligned_free(v14);
  _aligned_free((void *)_RBX);
  nc_free_tensor((_DWORD *)a4);
  __asm
  {
    vmovaps xmm6, [rsp+148h+var_78]
    vmovaps xmm7, [rsp+148h+var_68]
    vmovaps xmm8, [rsp+148h+var_58]
  }
  nc_free_tensor((_DWORD *)a5);
}

// ======================================================
// Function: sub_66A0EDE0 @ 0x66A0EDE0
// ======================================================

void __fastcall sub_66A0EDE0(__int64 _RCX)
{
  __asm
  {
    vmovss  xmm0, dword ptr [rcx+2Ch]
    vmulss  xmm0, xmm0, dword ptr [rcx+8]
    vmovss  xmm1, dword ptr [rcx+28h]
    vmulss  xmm2, xmm1, dword ptr [rcx+4]
    vmovss  xmm1, cs:dword_66A377C0
  }
  ++*(_QWORD *)(_RCX + 32);
  __asm
  {
    vmovss  dword ptr [rcx+2Ch], xmm0
    vsubss  xmm0, xmm1, xmm0
    vsubss  xmm1, xmm1, xmm2
    vmovss  dword ptr [rcx+28h], xmm2
    vsqrtss xmm0, xmm0, xmm0
    vdivss  xmm1, xmm0, xmm1
    vmulss  xmm0, xmm0, dword ptr [rcx+0Ch]
    vmulss  xmm0, xmm0, xmm0
    vmovss  dword ptr [rcx+38h], xmm0
    vmovss  dword ptr [rcx+30h], xmm1
    vmulss  xmm1, xmm1, dword ptr [rcx+18h]
    vmovss  dword ptr [rcx+34h], xmm1
  }
}

// ======================================================
// Function: sub_66A14340 @ 0x66A14340
// ======================================================

_QWORD *__fastcall sub_66A14340(__int64 a1, __int64 a2)
{
  __int64 v3; // rbx
  _QWORD *v5; // rax
  _QWORD *v6; // rsi
  __int64 v7; // rbp
  _QWORD *v8; // rdi
  char v9; // zf
  char v11; // pf
  _QWORD *result; // rax
  __int64 v13; // rsi
  _QWORD *v14; // rbx
  __int64 v15; // rdi
  _QWORD *v16; // rbx

  v3 = **(_QWORD **)(a2 + 16);
  _R13 = a1;
  v5 = aligned_malloc(0x10ui64, 0x40ui64);
  v6 = v5;
  if ( !v5 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 24i64);
    v14 = nc_new_tensor_nz(v13, *(_DWORD *)(v3 + 48), *(_DWORD *)(v3 + 80), v3 + 120);
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(v13 + 104))(
      v13,
      v14[7],
      0i64,
      *(_QWORD *)(v14[5] + 48i64),
      0);
    MEMORY[0] = v14;
    BUG();
  }
  *v5 = 0i64;
  v5[1] = 0i64;
  v7 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 24i64);
  v8 = nc_new_tensor_nz(v7, *(_DWORD *)(v3 + 48), *(_DWORD *)(v3 + 80), v3 + 120);
  *(double *)&_XMM0 = (*(double (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(v7 + 104))(
                        v7,
                        v8[7],
                        0i64,
                        *(_QWORD *)(v8[5] + 48i64),
                        0);
  *v6 = v8;
  __asm
  {
    vxorps  xmm0, xmm0, xmm0
    vucomiss xmm0, dword ptr [r13+4]
  }
  if ( !v11 && v9 )
    return v6;
  v15 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 24i64);
  v16 = nc_new_tensor_nz(v15, *(_DWORD *)(v3 + 48), *(_DWORD *)(v3 + 80), v3 + 120);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(v15 + 104))(
    v15,
    v16[7],
    0i64,
    *(_QWORD *)(v16[5] + 48i64),
    0);
  result = v6;
  v6[1] = v16;
  return result;
}

// ======================================================
// Function: sub_66A156D0 @ 0x66A156D0
// ======================================================

void __fastcall sub_66A156D0(__int64 a1, _DWORD **a2)
{
  nc_free_tensor(*a2);
  nc_free_tensor(a2[1]);
  _aligned_free(a2);
}

// ======================================================
// Function: sub_66A0EDA0 @ 0x66A0EDA0
// ======================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall sub_66A0EDA0(__int64 _RCX, double _XMM1_8)
{
  __asm
  {
    vmovss  xmm3, cs:dword_66A377C0
    vsubss  xmm0, xmm3, dword ptr [rcx+2Ch]
    vsubss  xmm3, xmm3, dword ptr [rcx+28h]
    vsqrtss xmm0, xmm0, xmm0
    vmovss  dword ptr [rcx+18h], xmm1
    vdivss  xmm2, xmm0, xmm3
    vmulss  xmm0, xmm0, dword ptr [rcx+0Ch]
    vmulss  xmm0, xmm0, xmm0
    vmovss  dword ptr [rcx+38h], xmm0
    vmulss  xmm1, xmm1, xmm2
    vmovss  dword ptr [rcx+30h], xmm2
    vmovss  dword ptr [rcx+34h], xmm1
  }
}

// ======================================================
// Function: sub_66A03000 @ 0x66A03000
// ======================================================

__m128 __fastcall sub_66A03000(__int64 _RCX)
{
  __m128 result; // xmm0

  __asm { vmovss  xmm0, dword ptr [rcx+18h] }
  return result;
}

// ======================================================
// Function: sub_66A02980 @ 0x66A02980
// ======================================================

__int64 *__fastcall sub_66A02980(__int64 _RCX, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v4; // rax
  __int64 v6; // r14
  int v7; // r13d
  __int64 v9; // rax
  __int64 v10; // r15
  __int64 v11; // rax
  __int64 *result; // rax
  __int64 v15; // rbx
  __int64 v16; // rdi
  _QWORD *v17; // r15
  unsigned __int64 v18; // r14
  __int64 v19; // r8
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // r9
  __int64 v26; // r9
  __int64 v27; // rcx
  __int64 v48; // rcx
  __int64 v49; // rsi
  __int64 v50; // rcx
  unsigned __int64 v53; // rcx
  __int64 v61; // rcx
  __int64 v62; // rsi
  unsigned __int64 v80; // r9
  __int64 v84; // r9
  __int64 v85; // rdx
  __int64 v90; // rdx
  __int64 v91; // rcx
  __int64 v92; // rcx
  int v96; // [rsp+Ch] [rbp-ACh]
  unsigned __int64 v97; // [rsp+10h] [rbp-A8h]
  __int64 v98; // [rsp+20h] [rbp-98h]
  __int64 v99; // [rsp+28h] [rbp-90h]
  __int64 v100; // [rsp+30h] [rbp-88h]
  __int64 *v101; // [rsp+38h] [rbp-80h]
  __int64 v102; // [rsp+40h] [rbp-78h]
  __int64 v103; // [rsp+48h] [rbp-70h]
  __int64 v104; // [rsp+50h] [rbp-68h] BYREF
  __int64 v105; // [rsp+58h] [rbp-60h]
  __int64 v106; // [rsp+60h] [rbp-58h]
  __int64 v107; // [rsp+68h] [rbp-50h]

  v4 = *(__int64 **)(a3 + 16);
  __asm { vmovss  xmm0, dword ptr [rcx+18h] }
  v6 = *v4;
  v7 = *(_DWORD *)(*v4 + 80);
  if ( v7 <= 0 )
  {
    v10 = 1i64;
    v96 = 0;
    _R10 = 0i64;
    v104 = 0i64;
    goto LABEL_19;
  }
  if ( !*(_BYTE *)(v6 + 73) || !*(_BYTE *)(a4 + 73) )
  {
    v10 = 1i64;
    v96 = 0;
    goto LABEL_15;
  }
  v9 = *(_QWORD *)(v6 + 120);
  if ( v7 == 1 )
  {
    v96 = 1;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v6 + 74) || !*(_BYTE *)(a4 + 74) )
  {
    v96 = 1;
LABEL_76:
    v104 = 0i64;
    v10 = (int)v9;
LABEL_16:
    v11 = 1i64;
    do
      *(&v104 + v11++) = 0i64;
    while ( v7 > (int)v11 );
    _R10 = v104;
    goto LABEL_19;
  }
  v9 *= *(_QWORD *)(v6 + 128);
  if ( v7 == 2 )
  {
    v96 = 2;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v6 + 75) || !*(_BYTE *)(a4 + 75) )
  {
    v96 = 2;
    goto LABEL_76;
  }
  v9 *= *(_QWORD *)(v6 + 136);
  if ( v7 == 3 )
  {
    v96 = 3;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(v6 + 76) || !*(_BYTE *)(a4 + 76) )
  {
    v96 = 3;
    goto LABEL_76;
  }
  v9 *= *(_QWORD *)(v6 + 144);
  v96 = 4;
LABEL_14:
  v10 = (int)v9;
LABEL_15:
  v104 = 0i64;
  if ( v7 > 1 )
    goto LABEL_16;
  _R10 = 0i64;
LABEL_19:
  __asm { vbroadcastss ymm2, xmm0 }
  v102 = v10 - 1;
  result = &v104 + v96;
  v15 = v6 + 8i64 * (unsigned int)(v96 + 1);
  v16 = v10;
  v17 = (_QWORD *)v6;
  v18 = v16;
  while ( _R10 != -1 )
  {
    v19 = v17[7];
    if ( v7 <= 0 )
    {
      v20 = 0i64;
    }
    else
    {
      v20 = v17[11] * _R10;
      if ( v7 != 1 )
      {
        v20 += v17[12] * v105;
        if ( v7 != 2 )
        {
          v20 += v17[13] * v106;
          if ( v7 != 3 )
          {
            v21 = v107;
            v22 = v17[14];
            goto LABEL_26;
          }
        }
      }
    }
    while ( 1 )
    {
      v21 = *(unsigned int *)(a4 + 80);
      _RDI = *(_QWORD *)(a4 + 56);
      if ( (int)v21 <= 0 )
        break;
      _R10 *= *(_QWORD *)(a4 + 88);
      if ( (_DWORD)v21 == 1 )
        goto LABEL_33;
      _R10 += *(_QWORD *)(a4 + 96) * v105;
      if ( (_DWORD)v21 == 2 )
        goto LABEL_33;
      _R10 += *(_QWORD *)(a4 + 104) * v106;
      if ( (_DWORD)v21 == 3 )
        goto LABEL_33;
      v22 = v107;
      if ( (_DWORD)v21 == 4 )
      {
        _R10 += *(_QWORD *)(a4 + 112) * v107;
        goto LABEL_33;
      }
LABEL_26:
      v20 += v22 * v21;
    }
    _R10 = 0i64;
LABEL_33:
    if ( v18 )
    {
      _R11 = _RDI + _R10;
      _RSI = v19 + v20;
      if ( (v19 + v20 >= (unsigned __int64)(_RDI + _R10 + 32) || _RDI + _R10 >= (unsigned __int64)(v19 + v20 + 32))
        && v18 > 0xA )
      {
        v26 = 0i64;
        v27 = -(int)(_RSI >> 2) & 7;
        if ( (-(int)(_RSI >> 2) & 7) != 0 )
        {
          __asm
          {
            vmovss  xmm1, dword ptr [r11]
            vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
            vmovss  dword ptr [rsi], xmm1
          }
          if ( v27 == 1 )
          {
            v26 = 1i64;
          }
          else
          {
            _R9 = v19 + v20 + 4;
            __asm
            {
              vmovss  xmm1, dword ptr [rdi+r10+4]
              vfnmadd213ss xmm1, xmm0, dword ptr [r9]
              vmovss  dword ptr [r9], xmm1
            }
            if ( v27 == 2 )
            {
              v26 = 2i64;
            }
            else
            {
              _R9 = v19 + v20 + 8;
              __asm
              {
                vmovss  xmm1, dword ptr [rdi+r10+8]
                vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                vmovss  dword ptr [r9], xmm1
              }
              if ( v27 == 3 )
              {
                v26 = 3i64;
              }
              else
              {
                _R9 = v19 + v20 + 12;
                __asm
                {
                  vmovss  xmm1, dword ptr [rdi+r10+0Ch]
                  vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                  vmovss  dword ptr [r9], xmm1
                }
                if ( v27 == 4 )
                {
                  v26 = 4i64;
                }
                else
                {
                  _R9 = v19 + v20 + 16;
                  __asm
                  {
                    vmovss  xmm1, dword ptr [rdi+r10+10h]
                    vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                    vmovss  dword ptr [r9], xmm1
                  }
                  if ( v27 == 5 )
                  {
                    v26 = 5i64;
                  }
                  else
                  {
                    _R9 = v19 + v20 + 20;
                    __asm
                    {
                      vmovss  xmm1, dword ptr [rdi+r10+14h]
                      vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                      vmovss  dword ptr [r9], xmm1
                    }
                    if ( v27 == 7 )
                    {
                      _R9 = v19 + v20 + 24;
                      __asm
                      {
                        vmovss  xmm1, dword ptr [rdi+r10+18h]
                        vfnmadd213ss xmm1, xmm0, dword ptr [r9]
                        vmovss  dword ptr [r9], xmm1
                      }
                      v26 = 7i64;
                    }
                    else
                    {
                      v26 = 6i64;
                    }
                  }
                }
              }
            }
          }
        }
        v99 = v18 - v27;
        v97 = ((v18 - v27 - 8) >> 3) + 1;
        v98 = 8 * v97;
        if ( (unsigned __int64)(v102 - v27) <= 6 )
          goto LABEL_48;
        v48 = 4 * v27;
        v103 = _RDI;
        v49 = v48 + v20;
        v50 = _RDI + _R10 + v48;
        _RDI = v19 + v49;
        _RSI = 0i64;
        v100 = v50;
        v53 = 0i64;
        v101 = result;
        _RAX = v100;
        do
        {
          __asm
          {
            vmovups ymm1, ymmword ptr [rax+rsi]
            vfnmadd213ps ymm1, ymm2, ymmword ptr [rdi+rsi]
          }
          ++v53;
          __asm { vmovaps ymmword ptr [rdi+rsi], ymm1 }
          _RSI += 32i64;
        }
        while ( v97 > v53 );
        _RDI = v103;
        result = v101;
        v26 += v98;
        if ( v98 != v99 )
        {
LABEL_48:
          _RSI = _RDI + 4 * v26;
          _RCX = v19 + 4 * v26 + v20;
          __asm
          {
            vmovss  xmm1, dword ptr [rsi+r10]
            vfnmadd213ss xmm1, xmm0, dword ptr [rcx]
            vmovss  dword ptr [rcx], xmm1
          }
          if ( v26 + 1 < v18 )
          {
            v61 = 4 * (v26 + 1);
            v62 = v61 + v20;
            _RCX = _RDI + v61;
            _RSI = v19 + v62;
            __asm
            {
              vmovss  xmm1, dword ptr [rcx+r10]
              vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
              vmovss  dword ptr [rsi], xmm1
            }
            if ( v18 > v26 + 2 )
            {
              _RCX = 4 * (v26 + 2);
              __asm { vmovss  xmm1, dword ptr [r11+rcx] }
              _RSI = v19 + v20 + _RCX;
              __asm
              {
                vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
                vmovss  dword ptr [rsi], xmm1
              }
              if ( v18 > v26 + 3 )
              {
                _RCX = 4 * (v26 + 3);
                __asm { vmovss  xmm1, dword ptr [r11+rcx] }
                _RSI = v19 + v20 + _RCX;
                __asm
                {
                  vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
                  vmovss  dword ptr [rsi], xmm1
                }
                if ( v18 > v26 + 4 )
                {
                  _RCX = 4 * (v26 + 4);
                  __asm { vmovss  xmm1, dword ptr [r11+rcx] }
                  _RSI = v19 + v20 + _RCX;
                  __asm
                  {
                    vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
                    vmovss  dword ptr [rsi], xmm1
                  }
                  if ( v18 > v26 + 5 )
                  {
                    _RCX = 4 * (v26 + 5);
                    v80 = v26 + 6;
                    __asm { vmovss  xmm1, dword ptr [r11+rcx] }
                    _RSI = v19 + v20 + _RCX;
                    __asm
                    {
                      vfnmadd213ss xmm1, xmm0, dword ptr [rsi]
                      vmovss  dword ptr [rsi], xmm1
                    }
                    if ( v18 > v80 )
                    {
                      v84 = 4 * v80;
                      v85 = v84 + v20;
                      _R9 = _RDI + v84;
                      _R8 = v85 + v19;
                      __asm
                      {
                        vmovss  xmm1, dword ptr [r9+r10]
                        vfnmadd213ss xmm1, xmm0, dword ptr [r8]
                        vmovss  dword ptr [r8], xmm1
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
        for ( _RDX = 0i64; _RDX != v18; ++_RDX )
        {
          __asm
          {
            vmovss  xmm1, dword ptr [r11+rdx*4]
            vfnmadd213ss xmm1, xmm0, dword ptr [rsi+rdx*4]
            vmovss  dword ptr [rsi+rdx*4], xmm1
          }
        }
      }
    }
    if ( v7 <= v96 )
      break;
    v90 = 0i64;
    v91 = *result + 1;
    *result = v91;
    if ( v91 == v17[v96 + 15] )
    {
      do
      {
        result[v90] = 0i64;
        if ( v90 == v7 - 1 - v96 )
          goto LABEL_60;
        v92 = result[v90 + 1] + 1;
        result[++v90] = v92;
      }
      while ( v92 == *(_QWORD *)(v15 + 8 * v90 + 112) );
    }
    _R10 = v104;
  }
LABEL_60:
  __asm { vzeroupper }
  return result;
}

// ======================================================
// Function: sub_66A15D80 @ 0x66A15D80
// ======================================================

void __fastcall sub_66A15D80(__int64 a1, _DWORD **a2, __int64 a3, _DWORD *a4)
{
  nc_free_tensor(*a2);
  *a2 = a4;
}

// ======================================================
// Function: sub_66A103E0 @ 0x66A103E0
// ======================================================

_QWORD *sub_66A103E0()
{
  _QWORD *result; // rax

  result = aligned_malloc(8ui64, 0x40ui64);
  if ( result )
    *result = 0i64;
  return result;
}

// ======================================================
// Function: sub_66A15D60 @ 0x66A15D60
// ======================================================

void __fastcall sub_66A15D60(__int64 a1, _DWORD **a2)
{
  nc_free_tensor(*a2);
  _aligned_free(a2);
}

