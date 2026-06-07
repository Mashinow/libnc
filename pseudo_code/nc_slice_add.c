// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_slice_add
// Included functions: 4

// ======================================================
// Function: nc_slice_add @ 0x66A23310
// ======================================================

_QWORD *__fastcall nc_slice_add(__int64 a1, __int64 a2, int a3, unsigned __int64 a4)
{
  _QWORD *v8; // rbx
  __int64 v9; // rsi
  __int64 v10; // rdi
  unsigned __int64 v11; // r15
  _QWORD *v12; // rsi
  __int64 v13; // rdx
  int v14; // r9d
  __int64 v15; // rax
  _QWORD *v16; // rsi
  __int64 *v18; // rax
  _QWORD *v19; // r8
  _DWORD *v20; // rax
  __int64 *v21; // r9
  _DWORD *v22; // rsi
  _QWORD *v23; // rax
  __int64 v24; // rdx
  __int64 v25; // rdx
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 *v28; // rcx
  void *Block; // [rsp+48h] [rbp-80h]
  _QWORD *Blocka; // [rsp+48h] [rbp-80h]
  __int64 *Blockb; // [rsp+48h] [rbp-80h]
  __int64 v32; // [rsp+50h] [rbp-78h]
  __int64 *v33; // [rsp+58h] [rbp-70h]
  _QWORD *v34; // [rsp+58h] [rbp-70h]
  __int64 v35; // [rsp+60h] [rbp-68h] BYREF
  __int64 v36; // [rsp+68h] [rbp-60h]
  __int64 v37; // [rsp+70h] [rbp-58h]
  __int64 v38; // [rsp+78h] [rbp-50h]

  v8 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
  {
    v8 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
    nc_tensor_copy((__int64)v8, a1);
  }
  v9 = a3;
  v10 = *(_QWORD *)(a2 + v9 * 8 + 120);
  v32 = a2 + v9 * 8;
  v11 = v10 + a4;
  Block = (void *)v8[3];
  if ( a3 >= 0 && a3 < *((_DWORD *)v8 + 20) )
  {
    if ( a4 < v11 )
      goto LABEL_6;
LABEL_23:
    v12 = &v8[v9];
    sub_66A33D40("start < end", "libnc.c", 4000);
    if ( v11 <= v12[15] )
      goto LABEL_7;
    goto LABEL_24;
  }
  sub_66A33D40("axis >= 0 && axis < x->n_dims", "libnc.c", 3999);
  if ( a4 >= v11 )
    goto LABEL_23;
LABEL_6:
  v12 = &v8[v9];
  if ( v11 <= v12[15] )
    goto LABEL_7;
LABEL_24:
  sub_66A33D40("start >= 0 && end <= x->dims[axis]", "libnc.c", 4001);
LABEL_7:
  v13 = v8[5];
  v14 = *((_DWORD *)v8 + 20);
  v15 = v12[11] * a4 + v8[7] - *(_QWORD *)(v13 + 40);
  if ( v14 <= 0 )
    goto LABEL_17;
  if ( !a3 )
  {
    v35 = v10;
    if ( v14 == 1 )
      goto LABEL_17;
LABEL_11:
    v36 = v8[16];
    if ( v14 <= 2 )
      goto LABEL_17;
    if ( a3 == 2 )
    {
      v37 = v10;
      if ( v14 == 3 )
        goto LABEL_17;
      goto LABEL_15;
    }
    goto LABEL_13;
  }
  v35 = v8[15];
  if ( v14 == 1 )
    goto LABEL_17;
  if ( a3 != 1 )
    goto LABEL_11;
  v36 = v10;
  if ( v14 == 2 )
    goto LABEL_17;
LABEL_13:
  v37 = v8[17];
  if ( v14 > 3 )
  {
    if ( a3 == 3 )
    {
LABEL_16:
      v38 = v10;
      goto LABEL_17;
    }
LABEL_15:
    v10 = v8[18];
    goto LABEL_16;
  }
LABEL_17:
  v16 = nc_new_tensor_from_buffer((__int64)Block, v13, *((_DWORD *)v8 + 12), v14, &v35, v15, v8 + 11);
  sub_66A127A0((__int64)v16, (__int64)v16, a2);
  nc_free_tensor(v16);
  if ( *(_QWORD *)(a1 + 32) || *(_QWORD *)(a2 + 32) )
  {
    v18 = (__int64 *)aligned_malloc(0x10ui64, 0x40ui64);
    v19 = (_QWORD *)v8[3];
    v33 = v18;
    *v18 = *(_QWORD *)(a1 + 32);
    Blocka = v19;
    v18[1] = *(_QWORD *)(a2 + 32);
    v20 = aligned_malloc(0x80ui64, 0x40ui64);
    v21 = v33;
    v22 = v20;
    if ( !v20 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    v34 = Blocka;
    memset(v20, 0, 0x80ui64);
    Blockb = v21;
    v20[4] = 1;
    v20[5] = 16;
    v20[6] = 2;
    v23 = aligned_malloc(0x10ui64, 0x40ui64);
    *((_QWORD *)v22 + 4) = v23;
    v24 = *Blockb;
    if ( *Blockb )
    {
      ++*(_DWORD *)(v24 + 16);
      *v23 = v24;
    }
    else
    {
      *v23 = 0i64;
    }
    v25 = Blockb[1];
    if ( v25 )
    {
      ++*(_DWORD *)(v25 + 16);
      v23[1] = v25;
    }
    else
    {
      v23[1] = 0i64;
    }
    v26 = v34[9];
    v34[9] = v26 + 1;
    *((_QWORD *)v22 + 12) = v26;
    v27 = v34[4];
    *(_QWORD *)(v27 + 8) = v22;
    *(_QWORD *)v22 = v27;
    *((_QWORD *)v22 + 1) = v34 + 4;
    v34[4] = v22;
    _aligned_free(Blockb);
    v28 = (__int64 *)v8[4];
    if ( v28 )
      nc_free_node(v28);
    v8[4] = v22;
    v22[14] = a3;
    *((_QWORD *)v22 + 8) = a4;
    *((_QWORD *)v22 + 9) = *(_QWORD *)(v32 + 120) + a4;
  }
  nc_free_tensor((_DWORD *)a2);
  if ( v8 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  return v8;
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
// Function: sub_66A127A0 @ 0x66A127A0
// ======================================================

__int64 __fastcall sub_66A127A0(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // edx
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rbx
  int v13; // eax
  __int64 v14; // rbx
  int v15; // r9d
  __int64 v16; // rbx
  int v17; // r9d
  __int64 v18; // rbx
  __int64 v19; // r9
  int v20; // r15d
  __int64 v21; // rax
  __int64 v22; // r13
  __int64 *v23; // rbx
  __int64 v24; // r12
  __int64 result; // rax
  int v26; // edx
  __int64 v27; // rcx
  __int64 v28; // rax
  __int64 v29; // r8
  __int64 v30; // r9
  int v31; // ecx
  int v32; // ecx
  __int64 v33; // rdx
  __int64 v34; // r8
  __int64 v35; // rax
  __int64 v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rcx
  __int64 v39; // [rsp+50h] [rbp-A8h]
  int v40; // [rsp+58h] [rbp-A0h]
  __int64 v41; // [rsp+68h] [rbp-90h]
  __int64 v42; // [rsp+70h] [rbp-88h]
  __int64 v43; // [rsp+80h] [rbp-78h]
  __int64 v44; // [rsp+88h] [rbp-70h]
  __int64 v45; // [rsp+90h] [rbp-68h] BYREF
  __int64 v46; // [rsp+98h] [rbp-60h]
  __int64 v47; // [rsp+A0h] [rbp-58h]
  __int64 v48; // [rsp+A8h] [rbp-50h]

  v39 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v39 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) || v39 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v6 = *(_DWORD *)(a2 + 48);
  if ( *(_DWORD *)(a3 + 48) != v6 || v6 > 1 )
    nc_error("unsupported type for %s\n", "nc_add_internal");
  v7 = *(_DWORD *)(a1 + 80);
  if ( v7 != *(_DWORD *)(a3 + 80) )
    goto LABEL_6;
  if ( v7 <= 0 )
  {
    v8 = *(_DWORD *)(a2 + 80);
    if ( v7 == v8 )
      goto LABEL_112;
    goto LABEL_7;
  }
  v34 = *(_QWORD *)(a3 + 120);
  if ( v34 == *(_QWORD *)(a1 + 120) )
  {
    v35 = 1i64;
    while ( v7 > (int)v35 )
    {
      v36 = *(_QWORD *)(a1 + 8 * v35++ + 120);
      if ( v36 != *(_QWORD *)(a3 + 8 * v35 + 112) )
        goto LABEL_6;
    }
    v8 = *(_DWORD *)(a2 + 80);
    if ( v7 != v8 )
    {
LABEL_7:
      sub_66A33D40("same_dims(y, x1)", "libnc.c", 5785);
      v8 = *(_DWORD *)(a1 + 80);
      if ( v8 > 0 )
      {
        v42 = *(_QWORD *)(a1 + 120);
        goto LABEL_9;
      }
LABEL_112:
      v43 = 1i64;
      v10 = 0i64;
LABEL_26:
      if ( v8 == (_DWORD)v10 )
        return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _DWORD))(v39 + 168))(
                 v39,
                 *(_QWORD *)(a1 + 56),
                 0i64,
                 *(_QWORD *)(a2 + 56),
                 0i64,
                 *(_QWORD *)(a3 + 56),
                 0i64,
                 v43,
                 1i64,
                 *(_DWORD *)(a2 + 48));
      goto LABEL_27;
    }
  }
  else
  {
LABEL_6:
    sub_66A33D40("same_dims(y, x2)", "libnc.c", 5784);
    v8 = *(_DWORD *)(a2 + 80);
    if ( v8 != *(_DWORD *)(a1 + 80) )
      goto LABEL_7;
    if ( v8 <= 0 )
      goto LABEL_112;
    v34 = *(_QWORD *)(a1 + 120);
  }
  v42 = *(_QWORD *)(a2 + 120);
  if ( v42 != v34 )
    goto LABEL_7;
  v37 = 1i64;
  while ( v8 > (int)v37 )
  {
    v38 = *(_QWORD *)(a1 + 8 * v37++ + 120);
    if ( v38 != *(_QWORD *)(a2 + 8 * v37 + 112) )
      goto LABEL_7;
  }
  v8 = *(_DWORD *)(a1 + 80);
LABEL_9:
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) || !*(_BYTE *)(a3 + 73) )
  {
    v40 = 1;
    v10 = 0i64;
    v43 = 1i64;
    goto LABEL_28;
  }
  v9 = *(_QWORD *)(a1 + 120);
  if ( v8 <= 1 )
  {
    v10 = 1i64;
    goto LABEL_25;
  }
  if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *(_BYTE *)(a3 + 74) )
  {
    v9 *= *(_QWORD *)(a1 + 128);
    if ( v8 == 2 )
    {
      v10 = 2i64;
      goto LABEL_25;
    }
    if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *(_BYTE *)(a3 + 75) )
    {
      v9 *= *(_QWORD *)(a1 + 136);
      if ( v8 == 3 )
      {
        v10 = 3i64;
        goto LABEL_25;
      }
      if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
      {
        v9 *= *(_QWORD *)(a1 + 144);
        v10 = 4i64;
LABEL_25:
        v43 = (int)v9;
        goto LABEL_26;
      }
      v10 = 3i64;
    }
    else
    {
      v10 = 2i64;
    }
  }
  else
  {
    v10 = 1i64;
  }
  v43 = (int)v9;
LABEL_27:
  v40 = v10 + 1;
  v42 = *(_QWORD *)(a1 + 8i64 * (int)v10 + 120);
LABEL_28:
  v11 = v40;
  if ( v8 <= v40 )
    goto LABEL_49;
  v11 = v40;
  if ( !*(_BYTE *)(a1 + v40 + 73) || !*(_BYTE *)(a2 + v40 + 73) || !*(_BYTE *)(a3 + v40 + 73) )
    goto LABEL_49;
  v12 = *(_QWORD *)(a1 + 8i64 * v40 + 120) * v42;
  v13 = v40 + 1;
  v42 = v12;
  if ( v8 <= v40 + 1 )
    goto LABEL_103;
  v11 = v13;
  if ( !*(_BYTE *)(a1 + v13 + 73) || !*(_BYTE *)(a2 + v13 + 73) || !*(_BYTE *)(a3 + v13 + 73) )
    goto LABEL_99;
  v14 = *(_QWORD *)(a1 + 8i64 * v13 + 120) * v12;
  v15 = v40 + 2;
  v42 = v14;
  if ( v8 <= v40 + 2 || !*(_BYTE *)(a1 + v15 + 73) || !*(_BYTE *)(a2 + v15 + 73) || !*(_BYTE *)(a3 + v15 + 73) )
  {
    v11 = v15;
    goto LABEL_98;
  }
  v16 = *(_QWORD *)(a1 + 8i64 * v15 + 120) * v14;
  v17 = v40 + 3;
  v11 = v40 + 3;
  v42 = v16;
  if ( v8 <= v40 + 3 )
  {
LABEL_98:
    v13 = v11;
    goto LABEL_99;
  }
  if ( !*(_BYTE *)(a1 + v17 + 73) || !*(_BYTE *)(a2 + v17 + 73) || !*(_BYTE *)(a3 + v17 + 73) )
  {
    v40 += 3;
    goto LABEL_49;
  }
  v18 = *(_QWORD *)(a1 + 8i64 * v17 + 120) * v16;
  v13 = v40 + 4;
  v42 = v18;
  if ( v8 > v40 + 4 )
  {
    v11 = v13;
    if ( *(_BYTE *)(a1 + v13 + 73) && *(_BYTE *)(a2 + v13 + 73) )
    {
      if ( *(_BYTE *)(a3 + v13 + 73) )
      {
        v40 += 5;
        v11 = v13 + 1;
        v42 = *(_QWORD *)(a1 + 8i64 * v13 + 120) * v18;
        goto LABEL_49;
      }
      goto LABEL_103;
    }
LABEL_99:
    v40 = v13;
    goto LABEL_49;
  }
LABEL_103:
  v40 = v13;
  v11 = v13;
LABEL_49:
  v19 = *(unsigned int *)(a2 + 48);
  v45 = 0i64;
  v20 = dword_66A375E0[v19];
  if ( v8 <= 1 )
  {
    v22 = 0i64;
  }
  else
  {
    v21 = 1i64;
    do
      *(&v45 + v21++) = 0i64;
    while ( v8 > (int)v21 );
    v22 = v45;
  }
  v23 = &v45 + v11;
  v24 = v10 + 8;
  result = v11 + 12;
  v44 = v11 + 12;
  while ( 2 )
  {
    if ( v22 == -1 )
      return result;
    v26 = *(_DWORD *)(a3 + 80);
    v27 = *(_QWORD *)(a3 + 56);
    if ( v26 <= 0 )
    {
      v28 = 0i64;
    }
    else
    {
      v28 = *(_QWORD *)(a3 + 88) * v22;
      if ( v26 != 1 )
      {
        v28 += *(_QWORD *)(a3 + 96) * v46;
        if ( v26 != 2 )
        {
          v28 += *(_QWORD *)(a3 + 104) * v47;
          if ( v26 != 3 )
          {
            v29 = v48;
            v30 = *(_QWORD *)(a3 + 112);
            goto LABEL_60;
          }
        }
      }
    }
    while ( 1 )
    {
      v41 = v27 + v28;
      v28 = *(unsigned int *)(a2 + 80);
      if ( (int)v28 <= 0 )
      {
        v30 = 0i64;
      }
      else
      {
        v30 = *(_QWORD *)(a2 + 88) * v22;
        if ( (_DWORD)v28 != 1 )
        {
          v30 += *(_QWORD *)(a2 + 96) * v46;
          if ( (_DWORD)v28 != 2 )
          {
            v30 += *(_QWORD *)(a2 + 104) * v47;
            if ( (_DWORD)v28 != 3 )
            {
              v27 = v48;
              v29 = *(_QWORD *)(a2 + 112);
              if ( (_DWORD)v28 != 4 )
                goto LABEL_60;
              v30 += v29 * v48;
            }
          }
        }
      }
      v28 = *(unsigned int *)(a1 + 80);
      v30 += *(_QWORD *)(a2 + 56);
      v29 = *(_QWORD *)(a1 + 8 * v24 + 24) >> v20;
      v27 = *(_QWORD *)(a1 + 56);
      if ( (int)v28 <= 0 )
        break;
      v22 *= *(_QWORD *)(a1 + 88);
      if ( (_DWORD)v28 == 1 )
        goto LABEL_73;
      v22 += *(_QWORD *)(a1 + 96) * v46;
      if ( (_DWORD)v28 == 2 )
        goto LABEL_73;
      v22 += *(_QWORD *)(a1 + 104) * v47;
      if ( (_DWORD)v28 == 3 )
        goto LABEL_73;
      if ( (_DWORD)v28 == 4 )
      {
        v22 += *(_QWORD *)(a1 + 112) * v48;
        goto LABEL_73;
      }
LABEL_60:
      v28 += v30 * v29;
    }
    v22 = 0i64;
LABEL_73:
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _DWORD))(v39 + 168))(
               v39,
               v27 + v22,
               v29,
               v30,
               *(_QWORD *)(a2 + 8 * v24 + 24) >> v20,
               v41,
               *(_QWORD *)(a3 + 8 * v24 + 24) >> v20,
               v43,
               v42,
               *(_DWORD *)(a2 + 48));
    v31 = *(_DWORD *)(a1 + 80);
    if ( v40 < v31 )
    {
      result = *v23 + 1;
      *v23 = result;
      if ( *(_QWORD *)(a1 + 8 * v44 + 24) != result )
      {
LABEL_79:
        v22 = v45;
        continue;
      }
      result = 0i64;
      v32 = v31 - 1 - v40;
      while ( 1 )
      {
        v23[result] = 0i64;
        if ( result == v32 )
          break;
        v33 = v23[result + 1] + 1;
        v23[++result] = v33;
        if ( v33 != *(_QWORD *)(a1 + 8i64 * (v40 + 1) + 8 * result + 112) )
          goto LABEL_79;
      }
    }
    return result;
  }
}

