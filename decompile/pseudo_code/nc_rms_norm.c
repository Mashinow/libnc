// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_rms_norm
// Included functions: 5

// ======================================================
// Function: nc_rms_norm @ 0x66A2B160
// ======================================================

_QWORD *__fastcall nc_rms_norm(__int64 a1, double a2)
{
  return sub_66A15F80(a1, a2, 0);
}

// ======================================================
// Function: sub_66A15F80 @ 0x66A15F80
// ======================================================

// local variable allocation has failed, the output may be wrong!
_QWORD *__fastcall sub_66A15F80(__int64 a1, double _XMM1_8, int a3)
{
  _QWORD *v6; // rbp
  _QWORD *v7; // r12
  int v8; // eax
  __int64 v9; // rdx
  __int64 v10; // r11
  __int64 *v11; // rbx
  __int64 v12; // r10
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // r8
  int v16; // eax
  __int64 v17; // r9
  int v18; // eax
  __int64 v19; // r9
  __int64 v20; // rdx
  __int64 v21; // rdx
  __int64 v22; // rcx
  _QWORD *v23; // rbx
  _QWORD *v24; // rax
  int v27; // [rsp+40h] [rbp-D8h]
  int v28; // [rsp+64h] [rbp-B4h]
  __int64 v29; // [rsp+68h] [rbp-B0h]
  __int64 v30; // [rsp+78h] [rbp-A0h]
  __int64 v31; // [rsp+98h] [rbp-80h] BYREF
  __int64 v32; // [rsp+A0h] [rbp-78h] BYREF
  __int64 v33; // [rsp+A8h] [rbp-70h]
  __int64 v34; // [rsp+B0h] [rbp-68h]
  __int64 v35; // [rsp+B8h] [rbp-60h]
  __int128 v36; // [rsp+C0h] [rbp-58h]

  __asm
  {
    vmovaps [rsp+118h+var_58], xmm6
    vmovaps xmm6, xmm1
  }
  v29 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(_DWORD *)(a1 + 48) > 1u )
    nc_error("unsupported type for %s\n", "nc_layer_norm1");
  if ( *(int *)(a1 + 80) <= 0 )
    sub_66A33D40("x->n_dims >= 1", "libnc.c", 7368);
  if ( !*(_BYTE *)(a1 + 73) )
    sub_66A33D40("x->contig[0]", "libnc.c", 7369);
  v6 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
    v6 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
  v7 = nc_new_tensor_nz(v29, 0, *(_DWORD *)(a1 + 80) - 1, a1 + 128);
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 <= 1 )
  {
    v32 = 0i64;
    v10 = 0i64;
    v30 = 1i64;
    v28 = 1;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 74) && *((_BYTE *)v6 + 74) && *((_BYTE *)v7 + 73) )
    {
      v30 = *(_QWORD *)(a1 + 128);
      if ( v8 != 2 && *(_BYTE *)(a1 + 75) && *((_BYTE *)v6 + 75) && *((_BYTE *)v7 + 74) )
      {
        v30 = *(_QWORD *)(a1 + 136) * *(_QWORD *)(a1 + 128);
        if ( v8 != 3 && *(_BYTE *)(a1 + 76) && *((_BYTE *)v6 + 76) && *((_BYTE *)v7 + 75) )
        {
          v28 = 4;
          v30 = *(_QWORD *)(a1 + 144) * *(_QWORD *)(a1 + 136) * *(_QWORD *)(a1 + 128);
        }
        else
        {
          v28 = 3;
        }
      }
      else
      {
        v28 = 2;
      }
    }
    else
    {
      v28 = 1;
      v30 = 1i64;
    }
    v9 = 1i64;
    v32 = 0i64;
    do
      *(&v32 + v9++) = 0i64;
    while ( v8 > (int)v9 );
    v10 = v32;
  }
  v11 = &v32 + v28;
  while ( v10 != -1 )
  {
    v12 = *(_QWORD *)(a1 + 56);
    if ( v8 <= 0 )
    {
      v13 = 0i64;
    }
    else
    {
      v13 = *(_QWORD *)(a1 + 88) * v10;
      if ( v8 != 1 )
      {
        v13 += *(_QWORD *)(a1 + 96) * v33;
        if ( v8 != 2 )
        {
          v13 += *(_QWORD *)(a1 + 104) * v34;
          if ( v8 != 3 )
          {
            v14 = v35;
            v15 = *(_QWORD *)(a1 + 112);
            goto LABEL_31;
          }
        }
      }
    }
    while ( 1 )
    {
      v16 = *((_DWORD *)v7 + 20);
      v12 += v13;
      v13 = v7[7];
      if ( v16 <= 0 )
      {
        v17 = 0i64;
      }
      else
      {
        v17 = v7[11] * v33;
        if ( v16 != 1 )
        {
          v17 += v7[12] * v34;
          if ( v16 != 2 )
          {
            v17 += v7[13] * v35;
            if ( v16 != 3 )
            {
              v14 = v36;
              v15 = v7[14];
              if ( v16 != 4 )
                goto LABEL_31;
              v17 += v15 * v36;
            }
          }
        }
      }
      v18 = *((_DWORD *)v6 + 20);
      v19 = v13 + v17;
      v15 = v6[8];
      v14 = v6[7];
      if ( v18 <= 0 )
        break;
      v10 *= v6[11];
      if ( v18 == 1 )
        goto LABEL_44;
      v10 += v6[12] * v33;
      if ( v18 == 2 )
        goto LABEL_44;
      v10 += v6[13] * v34;
      if ( v18 == 3 )
        goto LABEL_44;
      v13 = v6[14];
      if ( v18 == 4 )
      {
        v10 += v13 * v35;
        goto LABEL_44;
      }
LABEL_31:
      v13 += v15 * v14;
    }
    v10 = 0i64;
LABEL_44:
    __asm { vmovss  [rsp+118h+var_D8], xmm6 }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, _QWORD, _QWORD, __int64, int, int, _DWORD))(v29 + 416))(
      v29,
      v14 + v10,
      v15,
      v19,
      v12,
      *(_QWORD *)(a1 + 64),
      *(_QWORD *)(a1 + 120),
      v30,
      v27,
      a3,
      *(_DWORD *)(a1 + 48));
    v8 = *(_DWORD *)(a1 + 80);
    if ( v28 >= v8 )
    {
LABEL_49:
      v32 = -1i64;
      break;
    }
    v20 = *v11 + 1;
    *v11 = v20;
    if ( *(_QWORD *)(a1 + 8 * (v28 + 12i64) + 24) == v20 )
    {
      v21 = 0i64;
      do
      {
        v11[v21] = 0i64;
        if ( v8 - 1 - v28 == v21 )
          goto LABEL_49;
        v22 = v11[v21 + 1] + 1;
        v11[++v21] = v22;
      }
      while ( v22 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v28 + 1) + 8 * v21 + 112) );
    }
    v10 = v32;
  }
  v31 = a1;
  v23 = sub_66A15DA0(24, v6 + 3, (__int64 **)v6 + 4, 1, (__int64)&v31);
  if ( v23 )
  {
    *((_DWORD *)v23 + 10) = 2;
    *((_DWORD *)v23 + 14) = a3;
    v24 = aligned_malloc(0x10ui64, 0x40ui64);
    v23[6] = v24;
    ++*((_DWORD *)v6 + 4);
    *v24 = v6;
    ++*((_DWORD *)v7 + 4);
    v24[1] = v7;
  }
  nc_free_tensor(v7);
  if ( v6 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  __asm { vmovaps xmm6, [rsp+118h+var_58] }
  return v6;
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

