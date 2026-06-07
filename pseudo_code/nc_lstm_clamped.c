// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_lstm_clamped
// Included functions: 5

// ======================================================
// Function: nc_lstm_clamped @ 0x66A2B900
// ======================================================

_QWORD *__fastcall nc_lstm_clamped(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v8; // eax
  int v9; // edx
  int v10; // r8d
  int v11; // ecx
  int v12; // r8d
  _QWORD *v13; // r13
  int v14; // eax
  int v15; // edx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // r11
  int v19; // ecx
  __int64 v20; // rdx
  __int64 v21; // r8
  __int64 v22; // r9
  int v23; // ecx
  __int64 v24; // rcx
  int v25; // ecx
  int v26; // eax
  int v27; // r8d
  __int64 *v28; // rcx
  __int64 v29; // rdx
  __int64 v30; // r9
  __int64 v31; // r8
  __int64 v32; // rax
  __int64 v33; // rdx
  _QWORD *v38; // rax
  _QWORD *v39; // r12
  _QWORD *v40; // rax
  __int64 v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rax
  __int64 v45; // r8
  __int64 v46; // rax
  __int64 v47; // rdx
  __int64 v48; // [rsp+40h] [rbp-B8h]
  __int64 v49; // [rsp+40h] [rbp-B8h]
  __int64 v50; // [rsp+48h] [rbp-B0h]
  __int64 v51; // [rsp+48h] [rbp-B0h]
  __int64 v52; // [rsp+50h] [rbp-A8h]
  __int64 v53; // [rsp+50h] [rbp-A8h]
  __int64 v54; // [rsp+58h] [rbp-A0h]
  __int64 v55; // [rsp+60h] [rbp-98h]
  __int64 v56; // [rsp+68h] [rbp-90h] BYREF
  __int64 v57; // [rsp+70h] [rbp-88h] BYREF
  __int64 v58; // [rsp+78h] [rbp-80h]
  __int64 v59; // [rsp+80h] [rbp-78h]
  __int64 v60; // [rsp+88h] [rbp-70h]
  __int128 v61[6]; // [rsp+90h] [rbp-68h] BYREF

  _RBX = a1;
  v48 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  _RBP = a3;
  if ( v48 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64)
    || v48 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64)
    || v48 != *(_QWORD *)(*(_QWORD *)(a4 + 40) + 24i64) )
  {
    nc_error("all operation tensors must be on the same device");
  }
  v8 = *(_DWORD *)(a2 + 48);
  if ( v8 != *(_DWORD *)(a1 + 48) || v8 != *(_DWORD *)(a3 + 48) || *(_DWORD *)(a4 + 48) != v8 || v8 > 1 )
    nc_error("unsupported type for %s\n", "nc_lstm_clamped");
  v9 = *(_DWORD *)(a2 + 80);
  v10 = *(_DWORD *)(a1 + 80);
  if ( v9 != v10 )
  {
LABEL_9:
    sub_66A33D40("same_dims(in1, cp1)", "libnc.c", 7489);
    v9 = *(_DWORD *)(_RBX + 80);
    goto LABEL_10;
  }
  if ( v9 > 0 )
  {
    if ( *(_QWORD *)(a2 + 120) == *(_QWORD *)(a1 + 120) )
    {
      v42 = 1i64;
      while ( v10 > (int)v42 )
      {
        v43 = *(_QWORD *)(a2 + 8 * v42++ + 120);
        if ( v43 != *(_QWORD *)(_RBX + 8 * v42 + 112) )
          goto LABEL_9;
      }
      v11 = *(_DWORD *)(_RBP + 80);
      if ( v9 != v11 )
        goto LABEL_11;
      goto LABEL_69;
    }
    goto LABEL_9;
  }
LABEL_10:
  v11 = *(_DWORD *)(_RBP + 80);
  if ( v9 != v11 )
    goto LABEL_11;
LABEL_69:
  if ( v9 <= 0 )
  {
    v12 = *(_DWORD *)(a4 + 80);
    if ( v12 == v9 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( *(_QWORD *)(_RBP + 120) == *(_QWORD *)(_RBX + 120) )
  {
    v44 = 1i64;
    while ( v9 > (int)v44 )
    {
      v45 = *(_QWORD *)(_RBP + 8 * v44++ + 120);
      if ( v45 != *(_QWORD *)(_RBX + 8 * v44 + 112) )
        goto LABEL_11;
    }
    v12 = *(_DWORD *)(a4 + 80);
    if ( v11 != v12 )
      goto LABEL_12;
LABEL_77:
    if ( *(_QWORD *)(_RBX + 120) == *(_QWORD *)(a4 + 120) )
    {
      v46 = 1i64;
      while ( v11 > (int)v46 )
      {
        v47 = *(_QWORD *)(a4 + 8 * v46++ + 120);
        if ( v47 != *(_QWORD *)(_RBX + 8 * v46 + 112) )
          goto LABEL_12;
      }
      goto LABEL_13;
    }
    goto LABEL_12;
  }
LABEL_11:
  sub_66A33D40("same_dims(fg1, cp1)", "libnc.c", 7490);
  v11 = *(_DWORD *)(_RBX + 80);
  v12 = *(_DWORD *)(a4 + 80);
  if ( v11 == v12 )
  {
    if ( v11 <= 0 )
      goto LABEL_13;
    goto LABEL_77;
  }
LABEL_12:
  sub_66A33D40("same_dims(ig1, cp1)", "libnc.c", 7491);
  v12 = *(_DWORD *)(_RBX + 80);
LABEL_13:
  v13 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(_RBX + 40) + 24i64), *(_DWORD *)(_RBX + 48), v12, _RBX + 120);
  v14 = sub_66A05420(
          (_DWORD *)&v56 + 1,
          0,
          (__int64)v13,
          _RBX,
          a2,
          _RBP,
          a4,
          0i64,
          v48,
          v50,
          v52,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          *(__int64 *)&v61[0],
          *((__int64 *)&v61[0] + 1));
  v15 = *(_DWORD *)(_RBX + 80);
  v57 = 0i64;
  v53 = v14;
  if ( v15 <= 1 )
  {
    v17 = 0i64;
  }
  else
  {
    v16 = 1i64;
    do
      *(&v57 + v16++) = 0i64;
    while ( v15 > (int)v16 );
    v17 = v57;
  }
  while ( 2 )
  {
    if ( v17 == -1 )
      goto LABEL_54;
    v18 = *(_QWORD *)(a4 + 56);
    v19 = *(_DWORD *)(a4 + 80);
    if ( v19 > 0 )
    {
      v20 = *(_QWORD *)(a4 + 88) * v17;
      if ( v19 != 1 )
      {
        v20 += *(_QWORD *)(a4 + 96) * v58;
        if ( v19 != 2 )
        {
          v20 += *(_QWORD *)(a4 + 104) * v59;
          if ( v19 != 3 )
          {
            v21 = v60;
            v22 = *(_QWORD *)(a4 + 112);
            goto LABEL_23;
          }
        }
      }
      goto LABEL_24;
    }
    v23 = *(_DWORD *)(_RBP + 80);
    v21 = *(_QWORD *)(_RBP + 56);
    if ( v23 <= 0 )
    {
LABEL_62:
      v20 = 0i64;
      goto LABEL_30;
    }
    while ( 1 )
    {
      v20 = *(_QWORD *)(_RBP + 88) * v17;
      if ( v23 != 1 )
      {
        v20 += *(_QWORD *)(_RBP + 96) * v58;
        if ( v23 != 2 )
        {
          v20 += *(_QWORD *)(_RBP + 104) * v59;
          if ( v23 != 3 )
          {
            v22 = v60;
            if ( v23 != 4 )
              goto LABEL_23;
            v20 += *(_QWORD *)(_RBP + 112) * v60;
          }
        }
      }
LABEL_30:
      v24 = v21 + v20;
      v20 = *(unsigned int *)(a2 + 80);
      v51 = v24;
      if ( (int)v20 <= 0 )
      {
        v22 = 0i64;
      }
      else
      {
        v22 = *(_QWORD *)(a2 + 88) * v17;
        if ( (_DWORD)v20 != 1 )
        {
          v22 += *(_QWORD *)(a2 + 96) * v58;
          if ( (_DWORD)v20 != 2 )
          {
            v22 += *(_QWORD *)(a2 + 104) * v59;
            if ( (_DWORD)v20 != 3 )
            {
              v21 = v60;
              if ( (_DWORD)v20 != 4 )
                goto LABEL_23;
              v22 += *(_QWORD *)(a2 + 112) * v60;
            }
          }
        }
      }
      v20 = *(unsigned int *)(_RBX + 80);
      v22 += *(_QWORD *)(a2 + 56);
      if ( (int)v20 <= 0 )
      {
        v21 = 0i64;
      }
      else
      {
        v21 = *(_QWORD *)(_RBX + 88) * v17;
        if ( (_DWORD)v20 != 1 )
        {
          v21 += *(_QWORD *)(_RBX + 96) * v58;
          if ( (_DWORD)v20 != 2 )
          {
            v21 += *(_QWORD *)(_RBX + 104) * v59;
            if ( (_DWORD)v20 != 3 )
            {
              if ( (_DWORD)v20 != 4 )
                goto LABEL_23;
              v21 += *(_QWORD *)(_RBX + 112) * v60;
            }
          }
        }
      }
      v21 += *(_QWORD *)(_RBX + 56);
      v25 = *((_DWORD *)v13 + 20);
      v20 = v13[7];
      if ( v25 <= 0 )
        break;
      v17 *= v13[11];
      if ( v25 == 1 )
        goto LABEL_48;
      v17 += v13[12] * v58;
      if ( v25 == 2 )
        goto LABEL_48;
      v17 += v13[13] * v59;
      if ( v25 == 3 )
        goto LABEL_48;
      if ( v25 == 4 )
      {
        v17 += v13[14] * v60;
        goto LABEL_48;
      }
LABEL_23:
      v20 += v22 * v21;
LABEL_24:
      v23 = *(_DWORD *)(_RBP + 80);
      v18 += v20;
      v21 = *(_QWORD *)(_RBP + 56);
      if ( v23 <= 0 )
        goto LABEL_62;
    }
    v17 = 0i64;
LABEL_48:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, _DWORD))(v49 + 288))(
      v49,
      v17 + v20,
      v21,
      v22,
      v51,
      v18,
      v53,
      *(_DWORD *)(_RBX + 48));
    v26 = HIDWORD(v56);
    v27 = *(_DWORD *)(_RBX + 80);
    if ( v27 <= SHIDWORD(v56) )
      goto LABEL_53;
    v28 = &v57 + SHIDWORD(v56);
    v29 = *v28 + 1;
    *v28 = v29;
    if ( *(_QWORD *)(_RBX + 8i64 * v26 + 120) != v29 )
    {
LABEL_57:
      v17 = v57;
      continue;
    }
    break;
  }
  v30 = _RBX + 8i64 * (v26 + 1);
  v31 = (unsigned int)(~v26 + v27);
  v32 = 0i64;
  while ( 1 )
  {
    v28[v32] = 0i64;
    if ( v32 == v31 )
      break;
    v33 = v28[v32 + 1] + 1;
    v28[++v32] = v33;
    if ( v33 != *(_QWORD *)(v30 + 8 * v32 + 112) )
      goto LABEL_57;
  }
LABEL_53:
  v57 = -1i64;
LABEL_54:
  __asm
  {
    vmovq   xmm1, rbx
    vmovq   xmm2, rbp
    vpinsrq xmm0, xmm1, rdi, 1
    vmovaps [rsp+0F8h+var_68], xmm0
    vpinsrq xmm0, xmm2, rsi, 1
    vmovaps [rsp+0F8h+var_58], xmm0
  }
  v38 = sub_66A15DA0(25, v13 + 3, (__int64 **)v13 + 4, 4, (__int64)v61);
  v39 = v38;
  if ( v38 )
  {
    *((_DWORD *)v38 + 10) = 4;
    v40 = aligned_malloc(0x20ui64, 0x40ui64);
    v39[6] = v40;
    ++*(_DWORD *)(_RBX + 16);
    *v40 = _RBX;
    ++*(_DWORD *)(a2 + 16);
    v40[1] = a2;
    ++*(_DWORD *)(_RBP + 16);
    v40[2] = _RBP;
    ++*(_DWORD *)(a4 + 16);
    v40[3] = a4;
  }
  nc_free_tensor((_DWORD *)_RBX);
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)_RBP);
  nc_free_tensor((_DWORD *)a4);
  return v13;
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

