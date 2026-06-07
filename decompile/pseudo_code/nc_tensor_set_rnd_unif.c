// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_rnd_unif
// Included functions: 3

// ======================================================
// Function: nc_tensor_set_rnd_unif @ 0x66A19510
// ======================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall nc_tensor_set_rnd_unif(__int64 a1, double _XMM1_8, double _XMM2_8, __int64 a4)
{
  __int64 v6; // rdi
  unsigned int v7; // eax
  int v12; // r8d
  int v13; // esi
  __int64 v14; // rbp
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 *v17; // rbx
  __int64 v18; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rdx
  _QWORD *v25; // rbx
  __int64 v28; // rdx
  __int64 v29; // r8
  __int64 v33[4]; // [rsp+40h] [rbp-88h] BYREF

  __asm
  {
    vmovaps [rsp+0C8h+var_68], xmm6
    vmovaps [rsp+0C8h+var_58], xmm7
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v7 = *(_DWORD *)(a1 + 48);
  __asm
  {
    vmovaps xmm6, xmm1
    vmovaps xmm7, xmm2
  }
  if ( v7 > 1 )
  {
    sub_66A33D40("y->item_type == NC_TYPE_F32 || y->item_type == NC_TYPE_BF16", "libnc.c", 5204);
    v7 = *(_DWORD *)(a1 + 48);
  }
  if ( v7 != 1 || v6 != *(_QWORD *)(*(_QWORD *)(a1 + 24) + 64i64) )
  {
    v12 = *(_DWORD *)(a1 + 80);
    if ( v12 <= 0 )
    {
      v14 = 1i64;
      v13 = 0;
      v16 = 0i64;
      v33[0] = 0i64;
      goto LABEL_18;
    }
    v13 = 0;
    v14 = 1i64;
    if ( !*(_BYTE *)(a1 + 73) )
    {
LABEL_14:
      v33[0] = 0i64;
      if ( v12 > 1 )
        goto LABEL_15;
      v16 = 0i64;
LABEL_18:
      v17 = &v33[v13];
      while ( 1 )
      {
        if ( v16 == -1 )
        {
LABEL_31:
          __asm
          {
            vmovaps xmm6, [rsp+0C8h+var_68]
            vmovaps xmm7, [rsp+0C8h+var_58]
          }
          return;
        }
        if ( v12 <= 0 )
          break;
        v18 = *(_QWORD *)(a1 + 88) * v16;
        if ( v12 != 1 )
        {
          v18 += *(_QWORD *)(a1 + 96) * v33[1];
          if ( v12 != 2 )
          {
            v18 += *(_QWORD *)(a1 + 104) * v33[2];
            if ( v12 != 3 )
            {
              if ( v12 != 4 )
                break;
              v18 += *(_QWORD *)(a1 + 112) * v33[3];
            }
          }
        }
LABEL_26:
        __asm
        {
          vmovaps xmm3, xmm6
          vmovss  [rsp+0C8h+var_A8], xmm7
        }
        (*(void (__fastcall **)(__int64, __int64, __int64))(v6 + 472))(v6, v18 + *(_QWORD *)(a1 + 56), v14);
        v12 = *(_DWORD *)(a1 + 80);
        if ( v13 >= v12 )
          goto LABEL_31;
        v20 = *v17 + 1;
        *v17 = v20;
        if ( v20 == *(_QWORD *)(a1 + 8 * (v13 + 12i64) + 24) )
        {
          v21 = 0i64;
          do
          {
            v17[v21] = 0i64;
            if ( v21 == v12 - 1 - v13 )
              goto LABEL_31;
            v22 = v17[v21 + 1] + 1;
            v17[++v21] = v22;
          }
          while ( v22 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v13 + 1) + 8 * v21 + 112) );
        }
        v16 = v33[0];
      }
      v18 = 0i64;
      goto LABEL_26;
    }
    v14 = *(_QWORD *)(a1 + 120);
    if ( v12 == 1 )
    {
      v13 = 1;
      goto LABEL_13;
    }
    if ( *(_BYTE *)(a1 + 74) )
    {
      v14 *= *(_QWORD *)(a1 + 128);
      if ( v12 == 2 )
      {
        v13 = 2;
        goto LABEL_13;
      }
      if ( *(_BYTE *)(a1 + 75) )
      {
        v14 *= *(_QWORD *)(a1 + 136);
        if ( v12 == 3 )
        {
          v13 = 3;
          goto LABEL_13;
        }
        if ( *(_BYTE *)(a1 + 76) )
        {
          v14 *= *(_QWORD *)(a1 + 144);
          v13 = 4;
LABEL_13:
          v14 = (int)v14;
          goto LABEL_14;
        }
        v13 = 3;
      }
      else
      {
        v13 = 2;
      }
    }
    else
    {
      v13 = 1;
    }
    v33[0] = 0i64;
    v14 = (int)v14;
LABEL_15:
    v15 = 1i64;
    do
      v33[v15++] = 0i64;
    while ( v12 > (int)v15 );
    v16 = v33[0];
    goto LABEL_18;
  }
  v25 = nc_new_tensor_nz(v6, 0, *(_DWORD *)(a1 + 80), a1 + 120);
  __asm
  {
    vmovaps xmm2, xmm7
    vmovaps xmm1, xmm6
  }
  nc_tensor_set_rnd_unif(v25, v28, v29, a4);
  nc_tensor_convert(a1, (__int64)v25);
  __asm
  {
    vmovaps xmm6, [rsp+0C8h+var_68]
    vmovaps xmm7, [rsp+0C8h+var_58]
  }
  nc_free_tensor(v25);
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

