// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_gelu_bw
// Included functions: 4

// ======================================================
// Function: nc_gelu_bw @ 0x66A29F10
// ======================================================

_QWORD *__fastcall nc_gelu_bw(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rdi
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // r8d
  _QWORD *v10; // r15
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // r14
  __int64 *v15; // rbx
  int v16; // edx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // r8
  __int64 v20; // r9
  int v21; // ecx
  __int64 v22; // rax
  __int64 v23; // rax
  int v24; // ecx
  __int64 v25; // rdx
  __int64 v27; // r9
  __int64 v28; // rax
  __int64 v29; // rdx
  __int64 v30; // rax
  __int64 v31; // rdx
  int v32; // [rsp+4Ch] [rbp-ACh]
  __int64 v33; // [rsp+60h] [rbp-98h]
  __int64 v34[4]; // [rsp+70h] [rbp-88h] BYREF
  __int64 v35; // [rsp+90h] [rbp-68h] BYREF
  __int64 v36; // [rsp+98h] [rbp-60h]
  __int64 v37; // [rsp+A0h] [rbp-58h]
  __int64 v38; // [rsp+A8h] [rbp-50h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v3 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) || v3 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v7 = *(_DWORD *)(a1 + 48);
  if ( v7 > 1 || v7 != *(_DWORD *)(a2 + 48) || v7 != *(_DWORD *)(a3 + 48) )
    nc_error("unsupported type for %s\n", "nc_gelu_bw");
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 == *(_DWORD *)(a2 + 80) )
  {
    if ( v8 <= 0 )
    {
      v9 = *(_DWORD *)(a3 + 80);
      if ( v8 != v9 )
        goto LABEL_8;
      goto LABEL_98;
    }
    v27 = *(_QWORD *)(a2 + 120);
    if ( v27 == *(_QWORD *)(a1 + 120) )
    {
      v28 = 1i64;
      while ( v8 > (int)v28 )
      {
        v29 = *(_QWORD *)(a1 + 8 * v28++ + 120);
        if ( v29 != *(_QWORD *)(a2 + 8 * v28 + 112) )
          goto LABEL_7;
      }
      v9 = *(_DWORD *)(a3 + 80);
      if ( v8 != v9 )
        goto LABEL_8;
      goto LABEL_86;
    }
  }
LABEL_7:
  sub_66A33D40("same_dims(yg, x)", "libnc.c", 7251);
  v9 = *(_DWORD *)(a3 + 80);
  if ( v9 != *(_DWORD *)(a1 + 80) )
    goto LABEL_8;
  if ( v9 > 0 )
  {
    v27 = *(_QWORD *)(a1 + 120);
LABEL_86:
    if ( v27 == *(_QWORD *)(a3 + 120) )
    {
      v30 = 1i64;
      while ( v9 > (int)v30 )
      {
        v31 = *(_QWORD *)(a1 + 8 * v30++ + 120);
        if ( v31 != *(_QWORD *)(a3 + 8 * v30 + 112) )
          goto LABEL_8;
      }
      if ( *(_DWORD *)(a1 + 16) == 1 )
      {
        v10 = (_QWORD *)a1;
        v32 = *(_DWORD *)(a1 + 80);
        v11 = v32;
LABEL_12:
        if ( *((_BYTE *)v10 + 73) && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) && *(_BYTE *)(a3 + 73) )
        {
          v12 = v10[15];
          if ( v32 > 1 && *((_BYTE *)v10 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *(_BYTE *)(a3 + 74) )
          {
            v12 *= v10[16];
            if ( v32 != 2 )
            {
              if ( *((_BYTE *)v10 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *(_BYTE *)(a3 + 75) )
              {
                v12 *= v10[17];
                if ( v32 != 3 )
                {
                  if ( *((_BYTE *)v10 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
                  {
                    v12 *= v10[18];
                    v32 = 4;
                  }
                  else
                  {
                    v32 = 3;
                  }
                }
              }
              else
              {
                v32 = 2;
              }
            }
          }
          else
          {
            v32 = 1;
          }
          v33 = (int)v12;
          goto LABEL_33;
        }
LABEL_92:
        v33 = 1i64;
        v32 = 0;
LABEL_33:
        v35 = 0i64;
        if ( v11 <= 1 )
        {
          v14 = 0i64;
        }
        else
        {
          v13 = 1i64;
          do
            *(&v35 + v13++) = 0i64;
          while ( v11 > (int)v13 );
          v14 = v35;
        }
        goto LABEL_37;
      }
LABEL_9:
      v9 = *(_DWORD *)(a1 + 80);
LABEL_10:
      v10 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64), *(_DWORD *)(a1 + 48), v9, a1 + 120);
LABEL_11:
      v11 = *(_DWORD *)(a1 + 80);
      v32 = *((_DWORD *)v10 + 20);
      if ( v32 <= 0 )
        goto LABEL_92;
      goto LABEL_12;
    }
LABEL_8:
    v10 = (_QWORD *)a1;
    sub_66A33D40("same_dims(yg, z)", "libnc.c", 7252);
    if ( *(_DWORD *)(a1 + 16) == 1 )
      goto LABEL_11;
    goto LABEL_9;
  }
LABEL_98:
  if ( *(_DWORD *)(a1 + 16) != 1 )
    goto LABEL_10;
  v10 = (_QWORD *)a1;
  v14 = 0i64;
  v35 = 0i64;
  v32 = 0;
  v33 = 1i64;
LABEL_37:
  v15 = &v35 + v32;
  while ( v14 != -1 )
  {
    v16 = *(_DWORD *)(a3 + 80);
    v17 = *(_QWORD *)(a3 + 56);
    if ( v16 <= 0 )
    {
      v18 = 0i64;
    }
    else
    {
      v18 = *(_QWORD *)(a3 + 88) * v14;
      if ( v16 != 1 )
      {
        v18 += *(_QWORD *)(a3 + 96) * v36;
        if ( v16 != 2 )
        {
          v18 += *(_QWORD *)(a3 + 104) * v37;
          if ( v16 != 3 )
          {
            v19 = v38;
            v20 = *(_QWORD *)(a3 + 112);
            goto LABEL_44;
          }
        }
      }
    }
    while ( 1 )
    {
      v17 += v18;
      v18 = *(unsigned int *)(a2 + 80);
      if ( (int)v18 <= 0 )
      {
        v20 = 0i64;
      }
      else
      {
        v20 = *(_QWORD *)(a2 + 88) * v14;
        if ( (_DWORD)v18 != 1 )
        {
          v20 += *(_QWORD *)(a2 + 96) * v36;
          if ( (_DWORD)v18 != 2 )
          {
            v20 += *(_QWORD *)(a2 + 104) * v37;
            if ( (_DWORD)v18 != 3 )
            {
              v19 = v38;
              if ( (_DWORD)v18 != 4 )
                goto LABEL_44;
              v20 += *(_QWORD *)(a2 + 112) * v38;
            }
          }
        }
      }
      v18 = *(unsigned int *)(a1 + 80);
      v20 += *(_QWORD *)(a2 + 56);
      if ( (int)v18 <= 0 )
      {
        v19 = 0i64;
      }
      else
      {
        v19 = *(_QWORD *)(a1 + 88) * v14;
        if ( (_DWORD)v18 != 1 )
        {
          v19 += *(_QWORD *)(a1 + 96) * v36;
          if ( (_DWORD)v18 != 2 )
          {
            v19 += *(_QWORD *)(a1 + 104) * v37;
            if ( (_DWORD)v18 != 3 )
            {
              if ( (_DWORD)v18 != 4 )
                goto LABEL_44;
              v19 += *(_QWORD *)(a1 + 112) * v38;
            }
          }
        }
      }
      v18 = *((unsigned int *)v10 + 20);
      v19 += *(_QWORD *)(a1 + 56);
      if ( (int)v18 <= 0 )
        break;
      v14 *= v10[11];
      if ( (_DWORD)v18 == 1 )
        goto LABEL_63;
      v14 += v10[12] * v36;
      if ( (_DWORD)v18 == 2 )
        goto LABEL_63;
      v14 += v10[13] * v37;
      if ( (_DWORD)v18 == 3 )
        goto LABEL_63;
      if ( (_DWORD)v18 == 4 )
      {
        v14 += v10[14] * v38;
        goto LABEL_63;
      }
LABEL_44:
      v18 += v20 * v19;
    }
    v14 = 0i64;
LABEL_63:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _DWORD))(v3 + 264))(
      v3,
      v14 + v10[7],
      v19,
      v20,
      v17,
      v33,
      *(_DWORD *)(a1 + 48));
    v21 = *(_DWORD *)(a1 + 80);
    if ( v21 <= v32 )
    {
LABEL_68:
      v35 = -1i64;
      break;
    }
    v22 = *v15 + 1;
    *v15 = v22;
    if ( *(_QWORD *)(a1 + 8 * (v32 + 12i64) + 24) == v22 )
    {
      v23 = 0i64;
      v24 = v21 - 1 - v32;
      do
      {
        v15[v23] = 0i64;
        if ( v24 == v23 )
          goto LABEL_68;
        v25 = v15[v23 + 1] + 1;
        v15[++v23] = v25;
      }
      while ( v25 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v32 + 1) + 8 * v23 + 112) );
    }
    v14 = v35;
  }
  v34[0] = a1;
  v34[1] = a2;
  v34[2] = a3;
  sub_66A15DA0(0, v10 + 3, (__int64 **)v10 + 4, 3, (__int64)v34);
  if ( (_QWORD *)a1 != v10 )
    nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)a3);
  return v10;
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

