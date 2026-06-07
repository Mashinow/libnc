// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_masked_fill
// Included functions: 5

// ======================================================
// Function: nc_masked_fill @ 0x66A22610
// ======================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall nc_masked_fill(__int64 a1, __int64 a2, double _XMM2_8, int a4)
{
  __int64 v4; // rdi
  int v8; // eax
  __int64 v9; // rsi
  const char *v10; // r14
  int v11; // edx
  __int64 v12; // rsi
  __int64 v13; // rdx
  int v14; // r12d
  _QWORD *v15; // rax
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rcx
  int v23; // edx
  void (__fastcall *v24)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64, _DWORD, int, int); // r10
  __int64 v25; // r13
  __int64 v26; // r11
  __int64 v27; // r8
  __int64 v28; // r9
  __int64 *v29; // r15
  unsigned __int64 v30; // r8
  int v31; // eax
  int v32; // r8d
  __int64 *v33; // rcx
  __int64 v34; // rdx
  __int64 v35; // r9
  __int64 v36; // r8
  __int64 v37; // rax
  __int64 v38; // rdx
  _QWORD *v39; // rax
  _QWORD *v40; // rdi
  _QWORD *v41; // rax
  int v43; // ecx
  __int64 v44; // rax
  __int64 v45; // rdx
  int v46; // edx
  int v47; // eax
  int v48; // r8d
  __int64 *v49; // rcx
  __int64 v50; // rdx
  __int64 v51; // r9
  __int64 v52; // r8
  __int64 v53; // rax
  __int64 v54; // rdx
  __int64 v55; // [rsp+28h] [rbp-D0h]
  __int64 v56; // [rsp+30h] [rbp-C8h]
  __int64 v57; // [rsp+38h] [rbp-C0h]
  __int64 v58; // [rsp+40h] [rbp-B8h]
  __int64 v59; // [rsp+48h] [rbp-B0h]
  __int64 v60; // [rsp+50h] [rbp-A8h]
  __int64 v61; // [rsp+58h] [rbp-A0h]
  __int64 v62; // [rsp+60h] [rbp-98h]
  __int64 v63; // [rsp+60h] [rbp-98h]
  __int64 v64; // [rsp+68h] [rbp-90h]
  __int64 v65; // [rsp+70h] [rbp-88h]
  __int64 *v66; // [rsp+78h] [rbp-80h]
  __int64 v67; // [rsp+80h] [rbp-78h] BYREF
  __int64 v68; // [rsp+88h] [rbp-70h] BYREF
  __int64 v69; // [rsp+90h] [rbp-68h] BYREF
  __int64 v70; // [rsp+98h] [rbp-60h]
  __int64 v71; // [rsp+A0h] [rbp-58h]
  __int64 v72; // [rsp+A8h] [rbp-50h]

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  __asm { vmovd   r13d, xmm2 }
  if ( v4 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a1 + 48) > 1u || *(_DWORD *)(a2 + 48) != 5 )
    nc_error("unsupported type for %s\n", "nc_masked_fill");
  v8 = *(_DWORD *)(a2 + 80);
  if ( v8 > *(_DWORD *)(a1 + 80) )
  {
    sub_66A33D40("mask->n_dims <= x->n_dims", "libnc.c", 6125);
    v8 = *(_DWORD *)(a2 + 80);
  }
  v9 = 1i64;
  v10 = "libnc.c";
  if ( v8 > 0 )
  {
    do
    {
      if ( *(_QWORD *)(a2 + 8 * v9 + 112) != *(_QWORD *)(a1 + 8 * v9 + 112) )
      {
        sub_66A33D40("mask->dims[i] == x->dims[i]", "libnc.c", 6127);
        v8 = *(_DWORD *)(a2 + 80);
      }
      v11 = v9++;
    }
    while ( v11 < v8 );
  }
  v12 = a1;
  v13 = *(unsigned int *)(a1 + 48);
  v14 = dword_66A375E0[v13];
  if ( *(_DWORD *)(a1 + 16) != 1 )
  {
    v15 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), v13, *(_DWORD *)(a1 + 80), a1 + 120);
    LODWORD(v13) = *(_DWORD *)(a1 + 48);
    v12 = (__int64)v15;
  }
  if ( (_DWORD)v13 )
  {
    if ( (_DWORD)v13 != 1 )
      abort();
    v16 = *(_DWORD *)(a2 + 80);
    HIDWORD(v64) = (_R13D + (HIWORD(_R13D) & 1) + 0x7FFF) >> 16;
    if ( *(_DWORD *)(v12 + 80) != v16 )
    {
LABEL_14:
      if ( *(_BYTE *)(a2 + 72) )
      {
        if ( v16 > 0 )
          goto LABEL_16;
      }
      else
      {
        sub_66A33D40("mask->is_contiguous", "libnc.c", 6146);
        v16 = *(_DWORD *)(a2 + 80);
        if ( v16 > 0 )
        {
LABEL_16:
          if ( *(_BYTE *)(a1 + 73) )
          {
            if ( *(_BYTE *)(v12 + 73) )
              goto LABEL_18;
          }
          else
          {
            sub_66A33D40("x->contig[i]", "libnc.c", 6149);
            if ( *(_BYTE *)(v12 + 73) )
              goto LABEL_18;
          }
          sub_66A33D40("y->contig[i]", "libnc.c", 6150);
LABEL_18:
          v17 = *(_DWORD *)(a2 + 80);
          v63 = *(_QWORD *)(a2 + 120);
          if ( v17 <= 1 )
            goto LABEL_28;
          if ( *(_BYTE *)(a1 + 74) )
          {
            if ( *(_BYTE *)(v12 + 74) )
              goto LABEL_21;
          }
          else
          {
            sub_66A33D40("x->contig[i]", "libnc.c", 6149);
            if ( *(_BYTE *)(v12 + 74) )
              goto LABEL_21;
          }
          sub_66A33D40("y->contig[i]", "libnc.c", 6150);
LABEL_21:
          v17 = *(_DWORD *)(a2 + 80);
          v63 *= *(_QWORD *)(a2 + 128);
          if ( v17 <= 2 )
            goto LABEL_28;
          if ( *(_BYTE *)(a1 + 75) )
          {
            if ( *(_BYTE *)(v12 + 75) )
              goto LABEL_24;
          }
          else
          {
            sub_66A33D40("x->contig[i]", "libnc.c", 6149);
            if ( *(_BYTE *)(v12 + 75) )
              goto LABEL_24;
          }
          sub_66A33D40("y->contig[i]", "libnc.c", 6150);
LABEL_24:
          v17 = *(_DWORD *)(a2 + 80);
          v63 *= *(_QWORD *)(a2 + 136);
          if ( v17 > 3 )
          {
            if ( *(_BYTE *)(a1 + 76) )
            {
              if ( *(_BYTE *)(v12 + 76) )
              {
LABEL_27:
                v17 = *(_DWORD *)(a2 + 80);
                v63 *= *(_QWORD *)(a2 + 144);
                goto LABEL_28;
              }
            }
            else
            {
              sub_66A33D40("x->contig[i]", "libnc.c", 6149);
              if ( *(_BYTE *)(v12 + 76) )
                goto LABEL_27;
            }
            sub_66A33D40("y->contig[i]", "libnc.c", 6150);
            goto LABEL_27;
          }
LABEL_28:
          v18 = sub_66A05420(
                  (_DWORD *)&v67 + 1,
                  v17,
                  v12,
                  a1,
                  0i64,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v63,
                  v64,
                  v65,
                  (__int64)v66,
                  v67,
                  v68,
                  v69,
                  v70);
LABEL_29:
          v19 = *(_DWORD *)(a1 + 80);
          v69 = 0i64;
          v65 = v18;
          if ( v19 <= 1 )
          {
            v21 = 0i64;
          }
          else
          {
            v20 = 1i64;
            do
              *(&v69 + v20++) = 0i64;
            while ( v19 > (int)v20 );
            v21 = v69;
          }
          v66 = &v69;
          goto LABEL_34;
        }
      }
      v18 = sub_66A05420(
              (_DWORD *)&v67 + 1,
              v16,
              v12,
              a1,
              0i64,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              1i64,
              v64,
              v65,
              (__int64)v66,
              v67,
              v68,
              v69,
              v70);
      goto LABEL_29;
    }
  }
  else
  {
    HIDWORD(v64) = _R13D;
    v16 = *(_DWORD *)(a2 + 80);
    if ( *(_DWORD *)(v12 + 80) != v16 )
      goto LABEL_14;
  }
  if ( v16 > 0 && *(_BYTE *)(v12 + 73) && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
  {
    v25 = *(_QWORD *)(v12 + 120);
    if ( v16 != 1 )
    {
      if ( *(_BYTE *)(v12 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
      {
        v25 *= *(_QWORD *)(v12 + 128);
        if ( v16 != 2 )
        {
          if ( *(_BYTE *)(v12 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
          {
            v25 *= *(_QWORD *)(v12 + 136);
            if ( v16 != 3 )
            {
              if ( *(_BYTE *)(v12 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
              {
                v25 *= *(_QWORD *)(v12 + 144);
                v16 = 4;
              }
              else
              {
                v16 = 3;
              }
            }
          }
          else
          {
            v16 = 2;
          }
        }
      }
      else
      {
        v16 = 1;
      }
    }
    v25 = (int)v25;
  }
  else
  {
    v25 = 1i64;
    v16 = 0;
  }
  v43 = *(_DWORD *)(a1 + 80);
  HIDWORD(v67) = v16;
  v69 = 0i64;
  if ( v43 <= 1 )
  {
    v21 = 0i64;
  }
  else
  {
    v44 = 1i64;
    do
      *(&v69 + v44++) = 0i64;
    while ( v43 > (int)v44 );
    v21 = v69;
  }
  v29 = &v69;
  while ( v21 != -1 )
  {
    v22 = *(unsigned int *)(a2 + 80);
    v24 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64, _DWORD, int, int))(v4 + 336);
    v27 = *(_QWORD *)(a2 + 56);
    if ( (int)v22 <= 0 )
    {
      v45 = 0i64;
    }
    else
    {
      v45 = *(_QWORD *)(a2 + 88) * v21;
      if ( (_DWORD)v22 != 1 )
      {
        v45 += *(_QWORD *)(a2 + 96) * v70;
        if ( (_DWORD)v22 != 2 )
        {
          v45 += *(_QWORD *)(a2 + 104) * v71;
          if ( (_DWORD)v22 != 3 )
          {
            v28 = v72;
            v26 = *(_QWORD *)(a2 + 112);
            if ( (_DWORD)v22 != 4 )
              goto LABEL_40;
            v45 += v26 * v72;
          }
        }
      }
    }
    v27 += v45;
    v46 = *(_DWORD *)(a1 + 80);
    v22 = *(_QWORD *)(a1 + 56);
    if ( v46 <= 0 )
    {
      v28 = 0i64;
    }
    else
    {
      v28 = *(_QWORD *)(a1 + 88) * v21;
      if ( v46 != 1 )
      {
        v28 += *(_QWORD *)(a1 + 96) * v70;
        if ( v46 != 2 )
        {
          v28 += *(_QWORD *)(a1 + 104) * v71;
          if ( v46 != 3 )
          {
            v26 = v72;
            v10 = *(const char **)(a1 + 112);
            if ( v46 != 4 )
              goto LABEL_40;
            v28 += (_QWORD)v10 * v72;
          }
        }
      }
    }
    v28 += v22;
    v22 = *(unsigned int *)(v12 + 80);
    if ( (int)v22 <= 0 )
    {
      v21 = 0i64;
    }
    else
    {
      v21 *= *(_QWORD *)(v12 + 88);
      if ( (_DWORD)v22 != 1 )
      {
        v21 += *(_QWORD *)(v12 + 96) * v70;
        if ( (_DWORD)v22 != 2 )
        {
          v21 += *(_QWORD *)(v12 + 104) * v71;
          if ( (_DWORD)v22 != 3 )
          {
            v26 = v72;
            v10 = *(const char **)(v12 + 112);
            if ( (_DWORD)v22 != 4 )
            {
LABEL_40:
              v28 += (_QWORD)v29 * (_QWORD)v10;
              while ( 1 )
              {
                v28 += v27;
                v30 = *(_QWORD *)(v12 + 8 * v22 + 88);
                v22 = *(unsigned int *)(v12 + 80);
                v27 = v30 >> v14;
                if ( (int)v22 <= 0 )
                {
                  v21 = 0i64;
                }
                else
                {
                  v21 *= *(_QWORD *)(v12 + 88);
                  if ( (_DWORD)v22 != 1 )
                  {
                    v21 += *(_QWORD *)(v12 + 96) * v70;
                    if ( (_DWORD)v22 != 2 )
                    {
                      v21 += *(_QWORD *)(v12 + 104) * v71;
                      if ( (_DWORD)v22 != 3 )
                      {
                        v10 = (const char *)v72;
                        v29 = *(__int64 **)(v12 + 112);
                        if ( (_DWORD)v22 != 4 )
                          goto LABEL_40;
                        v21 += (_QWORD)v29 * v72;
                      }
                    }
                  }
                }
                v24(v4, v21 + *(_QWORD *)(v12 + 56), v27, v28, v26, v25, 0i64, v62, v65, HIDWORD(v64), a4, v14);
                v31 = HIDWORD(v67);
                v32 = *(_DWORD *)(a1 + 80);
                if ( SHIDWORD(v67) >= v32 )
                  goto LABEL_52;
                v33 = &v66[SHIDWORD(v67)];
                v34 = *v33 + 1;
                *v33 = v34;
                if ( v34 == *(_QWORD *)(a1 + 8i64 * v31 + 120) )
                {
                  v35 = a1 + 8i64 * (v31 + 1);
                  v36 = (unsigned int)(~v31 + v32);
                  v37 = 0i64;
                  do
                  {
                    v33[v37] = 0i64;
                    if ( v37 == v36 )
                      goto LABEL_52;
                    v38 = v33[v37 + 1] + 1;
                    v33[++v37] = v38;
                  }
                  while ( v38 == *(_QWORD *)(v35 + 8 * v37 + 112) );
                }
                v21 = v69;
LABEL_34:
                if ( v21 == -1 )
                  goto LABEL_53;
                v22 = *(int *)(a2 + 80);
                v23 = *(_DWORD *)(a1 + 80);
                v24 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64, _DWORD, int, int))(v4 + 336);
                v25 = *(_QWORD *)(a2 + 56);
                v26 = *(_QWORD *)(a1 + 8 * v22 + 88) >> v14;
                v27 = *(_QWORD *)(a1 + 56);
                if ( v23 <= 0 )
                {
                  v28 = 0i64;
                }
                else
                {
                  v28 = *(_QWORD *)(a1 + 88) * v21;
                  if ( v23 != 1 )
                  {
                    v28 += *(_QWORD *)(a1 + 96) * v70;
                    if ( v23 != 2 )
                    {
                      v28 += *(_QWORD *)(a1 + 104) * v71;
                      if ( v23 != 3 )
                      {
                        v10 = (const char *)v72;
                        v29 = *(__int64 **)(a1 + 112);
                        goto LABEL_40;
                      }
                    }
                  }
                }
              }
            }
            v21 += (_QWORD)v10 * v72;
          }
        }
      }
    }
    v24(v4, v21 + *(_QWORD *)(v12 + 56), 0i64, v28, 0i64, v27, 0i64, v25, 1i64, HIDWORD(v64), a4, v14);
    v47 = HIDWORD(v67);
    v48 = *(_DWORD *)(a1 + 80);
    if ( SHIDWORD(v67) >= v48 )
      goto LABEL_52;
    v49 = &v69 + SHIDWORD(v67);
    v50 = *v49 + 1;
    *v49 = v50;
    if ( v50 == *(_QWORD *)(a1 + 8i64 * v47 + 120) )
    {
      v51 = a1 + 8i64 * (v47 + 1);
      v52 = (unsigned int)(~v47 + v48);
      v53 = 0i64;
      while ( 1 )
      {
        v49[v53] = 0i64;
        if ( v53 == v52 )
          break;
        v54 = v49[v53 + 1] + 1;
        v49[++v53] = v54;
        if ( v54 != *(_QWORD *)(v51 + 8 * v53 + 112) )
          goto LABEL_111;
      }
LABEL_52:
      v69 = -1i64;
      break;
    }
LABEL_111:
    v21 = v69;
  }
LABEL_53:
  v68 = a1;
  v39 = sub_66A15DA0(28, (__int64 *)(v12 + 24), (__int64 **)(v12 + 32), 1, (__int64)&v68);
  v40 = v39;
  if ( v39 )
  {
    *((_DWORD *)v39 + 10) = 1;
    v41 = aligned_malloc(8ui64, 0x40ui64);
    v40[6] = v41;
    ++*(_DWORD *)(a2 + 16);
    *v41 = a2;
    *((_DWORD *)v40 + 14) = a4;
  }
  if ( v12 != a1 )
    nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v12;
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

