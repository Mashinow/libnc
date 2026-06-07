// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_get_element
// Included functions: 4

// ======================================================
// Function: nc_get_element @ 0x66A27230
// ======================================================

_QWORD *__fastcall nc_get_element(__int64 a1, __int64 a2)
{
  __int64 v2; // rdi
  int v5; // r8d
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rbx
  _QWORD *v9; // rax
  _QWORD *v10; // r15
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // r12
  int v15; // edx
  __int64 v16; // rax
  __int64 v17; // rsi
  int v18; // edx
  __int64 v19; // r8
  __int64 v20; // rax
  __int64 v21; // rcx
  __int64 v22; // r9
  int v23; // r8d
  __int64 v24; // r13
  int v25; // edx
  __int64 v26; // rdx
  int v27; // r8d
  __int64 v28; // rax
  __int64 v29; // rdx
  _QWORD *v30; // rax
  _QWORD *v31; // rbx
  _QWORD *v32; // rax
  __int64 v34; // [rsp+38h] [rbp-70h] BYREF
  __int64 v35; // [rsp+40h] [rbp-68h] BYREF
  __int64 v36; // [rsp+48h] [rbp-60h]
  __int64 v37; // [rsp+50h] [rbp-58h]
  __int64 v38; // [rsp+58h] [rbp-50h]
  __int64 v39; // [rsp+60h] [rbp-48h]

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v2 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a2 + 48) != 5 )
    nc_error("unsupported type for %s\n", "nc_get_element");
  v5 = *(_DWORD *)(a2 + 80);
  if ( *(_DWORD *)(a1 + 80) != v5 + 1 )
  {
    sub_66A33D40("w->n_dims == (x->n_dims + 1)", "libnc.c", 6809);
    v5 = *(_DWORD *)(a2 + 80);
  }
  v6 = 0i64;
  v7 = v5;
  while ( v6 < v7 )
  {
    while ( 1 )
    {
      ++v6;
      if ( *(_QWORD *)(a1 + 8 * v6 + 120) == *(_QWORD *)(a2 + 8 * v6 + 112) )
        break;
      sub_66A33D40("w->dims[i + 1] == x->dims[i]", "libnc.c", 6811);
      v7 = *(int *)(a2 + 80);
      v5 = *(_DWORD *)(a2 + 80);
      if ( v6 >= v7 )
        goto LABEL_9;
    }
  }
LABEL_9:
  v8 = (_QWORD *)a2;
  v9 = nc_new_tensor_nz(v2, *(_DWORD *)(a1 + 48), v5, a2 + 120);
  ++*(_DWORD *)(a2 + 16);
  v10 = v9;
  v11 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 64i64);
  if ( v11 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
  {
    v8 = nc_new_tensor_nz(v11, *(_DWORD *)(a2 + 48), *(_DWORD *)(a2 + 80), a2 + 120);
    nc_tensor_copy((__int64)v8, a2);
    v12 = *(_QWORD *)(a2 + 32);
    if ( v12 )
    {
      ++*(_DWORD *)(v12 + 16);
      v8[4] = v12;
    }
    nc_free_tensor((_DWORD *)a2);
  }
  v13 = *(unsigned int *)(a1 + 48);
  v36 = 0i64;
  v14 = nc_type_size_table[v13];
  v15 = *((_DWORD *)v8 + 20);
  if ( v15 <= 1 )
  {
    v17 = 0i64;
  }
  else
  {
    v16 = 1i64;
    do
      *(&v35 + ++v16) = 0i64;
    while ( v15 > (int)v16 );
LABEL_16:
    v17 = v36;
  }
LABEL_17:
  if ( v17 != -1 )
  {
    v18 = *((_DWORD *)v8 + 20);
    v19 = v8[7];
    if ( v18 <= 0 )
    {
      v20 = 0i64;
    }
    else
    {
      v20 = v8[11] * v17;
      if ( v18 != 1 )
      {
        v20 += v8[12] * v37;
        if ( v18 != 2 )
        {
          v20 += v8[13] * v38;
          if ( v18 != 3 )
          {
            v21 = v39;
            v22 = v8[14];
            goto LABEL_23;
          }
        }
      }
    }
    while ( 1 )
    {
      v23 = *(_DWORD *)(v19 + v20);
      v24 = v23;
      if ( v23 < 0 || (unsigned __int64)v23 >= *(_QWORD *)(a1 + 120) )
        sub_66A33D40("c >= 0 && c < w->dims[0]", "libnc.c", 6821);
      v25 = *(_DWORD *)(a1 + 80);
      v20 = *(_QWORD *)(v2 + 64);
      v35 = v24;
      v22 = *(_QWORD *)(a1 + 56);
      if ( v25 <= 0 )
      {
        v19 = 0i64;
      }
      else
      {
        v19 = *(_QWORD *)(a1 + 88) * v24;
        if ( v25 != 1 )
        {
          v19 += *(_QWORD *)(a1 + 96) * v17;
          if ( v25 != 2 )
          {
            v19 += *(_QWORD *)(a1 + 104) * v37;
            if ( v25 != 3 )
            {
              v21 = v38;
              if ( v25 != 4 )
                goto LABEL_23;
              v19 += *(_QWORD *)(a1 + 112) * v38;
            }
          }
        }
      }
      v21 = *((unsigned int *)v10 + 20);
      v19 += v22;
      v22 = v10[7];
      if ( (int)v21 <= 0 )
      {
        v26 = 0i64;
LABEL_39:
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))v20)(v2, v22 + v26, v19, v14);
        v27 = *((_DWORD *)v8 + 20);
        if ( v27 <= 0 )
        {
LABEL_44:
          v36 = -1i64;
          break;
        }
        v36 = ++v17;
        if ( v8[15] == v17 )
        {
          v28 = 1i64;
          while ( 1 )
          {
            *(&v35 + v28) = 0i64;
            if ( v27 <= (int)v28 )
              goto LABEL_44;
            v29 = *(&v35 + v28 + 1) + 1;
            *(&v35 + ++v28) = v29;
            if ( v29 != v8[v28 + 14] )
              goto LABEL_16;
          }
        }
        goto LABEL_17;
      }
      v26 = v10[11] * v17;
      if ( (_DWORD)v21 == 1 )
        goto LABEL_39;
      v26 += v10[12] * v37;
      if ( (_DWORD)v21 == 2 )
        goto LABEL_39;
      v26 += v10[13] * v38;
      if ( (_DWORD)v21 == 3 )
        goto LABEL_39;
      if ( (_DWORD)v21 == 4 )
      {
        v26 += v10[14] * v39;
        goto LABEL_39;
      }
LABEL_23:
      v20 += v22 * v21;
    }
  }
  nc_free_tensor(v8);
  v34 = a1;
  v30 = sub_66A15DA0(33, v10 + 3, (__int64 **)v10 + 4, 1, (__int64)&v34);
  v31 = v30;
  if ( v30 )
  {
    *((_DWORD *)v30 + 10) = 1;
    v32 = aligned_malloc(8ui64, 0x40ui64);
    v31[6] = v32;
    ++*(_DWORD *)(a2 + 16);
    *v32 = a2;
    v31[7] = *(_QWORD *)(a1 + 120);
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
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

