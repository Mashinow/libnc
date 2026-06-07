// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_split
// Included functions: 3

// ======================================================
// Function: nc_split @ 0x66A23BF0
// ======================================================

void __fastcall nc_split(_QWORD *a1, __int64 a2, int a3, __int64 a4, int a5)
{
  _DWORD *v5; // r13
  int v6; // ecx
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r12
  __int64 v10; // r13
  __int64 v11; // rdx
  int v12; // r9d
  __int64 v13; // rcx
  unsigned __int64 v14; // rdi
  _QWORD *v15; // rax
  __int64 v16; // rbx
  __int64 v17; // rbx
  _DWORD *v18; // rax
  _DWORD *v19; // r15
  _QWORD *v20; // rax
  __int64 v21; // rdx
  __int64 *v22; // rcx
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 *v25; // rcx
  _QWORD *v26; // rdi
  __int64 v27; // rdx
  _DWORD *v28; // rcx
  __int64 v29; // rax
  unsigned __int64 v30; // [rsp+48h] [rbp-A0h]
  __int64 *Block; // [rsp+50h] [rbp-98h]
  __int64 v32; // [rsp+58h] [rbp-90h]
  __int64 v33; // [rsp+60h] [rbp-88h]
  __int64 *v34; // [rsp+68h] [rbp-80h]
  unsigned __int64 v35; // [rsp+80h] [rbp-68h] BYREF
  unsigned __int64 v36; // [rsp+88h] [rbp-60h]
  unsigned __int64 v37; // [rsp+90h] [rbp-58h]
  unsigned __int64 v38; // [rsp+98h] [rbp-50h]

  v5 = (_DWORD *)a2;
  if ( a5 < 0 )
    goto LABEL_53;
  v6 = *(_DWORD *)(a2 + 80);
  if ( a5 >= v6 || !a4 && *(_QWORD *)(a2 + 8i64 * a5 + 120) % (unsigned __int64)a3 )
    goto LABEL_53;
  if ( a3 == 1 )
  {
    *a1 = a2;
  }
  else
  {
    if ( a3 > 0 )
    {
      v8 = 0i64;
      v34 = (__int64 *)(a2 + 88);
      v9 = 0i64;
      v33 = 8i64 * (unsigned int)(a3 - 1);
      v10 = a2 + 8i64 * a5;
      while ( 1 )
      {
        if ( a4 )
          v14 = *(_QWORD *)(a4 + v9);
        else
          v14 = *(_QWORD *)(a2 + 8i64 * a5 + 120) / (unsigned __int64)a3;
        ++*(_DWORD *)(a2 + 16);
        v17 = *(_QWORD *)(a2 + 24);
        v30 = v14 + v8;
        if ( a5 >= v6 )
          sub_66A33D40("axis >= 0 && axis < x->n_dims", "libnc.c", 3999);
        if ( v30 > v8 )
        {
          if ( v14 + v8 <= *(_QWORD *)(v10 + 120) )
            goto LABEL_8;
        }
        else
        {
          sub_66A33D40("start < end", "libnc.c", 4000);
          if ( v14 + v8 <= *(_QWORD *)(v10 + 120) )
            goto LABEL_8;
        }
        sub_66A33D40("start >= 0 && end <= x->dims[axis]", "libnc.c", 4001);
LABEL_8:
        v11 = *(_QWORD *)(a2 + 40);
        v12 = *(_DWORD *)(a2 + 80);
        v13 = *(_QWORD *)(v10 + 88) * v8 + *(_QWORD *)(a2 + 56) - *(_QWORD *)(v11 + 40);
        if ( v12 <= 0 )
          goto LABEL_17;
        if ( a5 )
        {
          v35 = *(_QWORD *)(a2 + 120);
          if ( v12 == 1 )
            goto LABEL_17;
          if ( a5 == 1 )
          {
            v36 = v14;
            if ( v12 != 2 )
            {
              v37 = *(_QWORD *)(a2 + 136);
              if ( v12 != 3 )
                goto LABEL_15;
            }
            goto LABEL_17;
          }
          v36 = *(_QWORD *)(a2 + 128);
          if ( v12 == 2 )
            goto LABEL_17;
          if ( a5 == 2 )
          {
            v37 = v14;
            if ( v12 == 3 )
              goto LABEL_17;
LABEL_15:
            v14 = *(_QWORD *)(a2 + 144);
LABEL_16:
            v38 = v14;
            goto LABEL_17;
          }
        }
        else
        {
          v35 = v14;
          if ( v12 == 1 )
            goto LABEL_17;
          v36 = *(_QWORD *)(a2 + 128);
          if ( v12 == 2 )
            goto LABEL_17;
        }
        v37 = *(_QWORD *)(a2 + 136);
        if ( v12 != 3 )
        {
          if ( a5 != 3 )
            goto LABEL_15;
          goto LABEL_16;
        }
LABEL_17:
        v15 = nc_new_tensor_from_buffer(v17, v11, *(_DWORD *)(a2 + 48), v12, (__int64 *)&v35, v13, v34);
        v16 = (__int64)v15;
        if ( !*((_BYTE *)v15 + 72) )
        {
          v26 = nc_new_tensor_nz(
                  *(_QWORD *)(v15[5] + 24i64),
                  *((_DWORD *)v15 + 12),
                  *((_DWORD *)v15 + 20),
                  (__int64)(v15 + 15));
          nc_tensor_copy((__int64)v26, v16);
          v27 = *(_QWORD *)(v16 + 32);
          if ( v27 )
          {
            ++*(_DWORD *)(v27 + 16);
            v26[4] = v27;
          }
          v28 = (_DWORD *)v16;
          v16 = (__int64)v26;
          nc_free_tensor(v28);
        }
        if ( *(_QWORD *)(a2 + 32) )
        {
          Block = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
          v32 = *(_QWORD *)(v16 + 24);
          *Block = *(_QWORD *)(a2 + 32);
          v18 = aligned_malloc(0x80ui64, 0x40ui64);
          v19 = v18;
          if ( !v18 )
          {
            MEMORY[0x10] = 0;
            BUG();
          }
          memset(v18, 0, 0x80ui64);
          v18[4] = 1;
          v18[5] = 15;
          v18[6] = 1;
          v20 = aligned_malloc(8ui64, 0x40ui64);
          *((_QWORD *)v19 + 4) = v20;
          v21 = *Block;
          if ( *Block )
          {
            ++*(_DWORD *)(v21 + 16);
            v22 = Block;
            *v20 = v21;
          }
          else
          {
            *v20 = 0i64;
            v22 = Block;
          }
          v23 = *(_QWORD *)(v32 + 72);
          *(_QWORD *)(v32 + 72) = v23 + 1;
          *((_QWORD *)v19 + 12) = v23;
          v24 = *(_QWORD *)(v32 + 32);
          *(_QWORD *)(v24 + 8) = v19;
          *(_QWORD *)v19 = v24;
          *((_QWORD *)v19 + 1) = v32 + 32;
          *(_QWORD *)(v32 + 32) = v19;
          _aligned_free(v22);
          v25 = *(__int64 **)(v16 + 32);
          if ( v25 )
            nc_free_node(v25);
          *(_QWORD *)(v16 + 32) = v19;
          v19[14] = a5;
          *((_QWORD *)v19 + 8) = v8;
          *((_QWORD *)v19 + 9) = *(_QWORD *)(v10 + 120);
        }
        nc_free_tensor((_DWORD *)a2);
        a1[v9 / 8] = v16;
        if ( v9 == v33 )
        {
          v29 = a5;
          v5 = (_DWORD *)a2;
          goto LABEL_49;
        }
        v6 = *(_DWORD *)(a2 + 80);
        v8 = v30;
        v9 += 8i64;
      }
    }
    v30 = 0i64;
    v29 = a5;
LABEL_49:
    if ( *(_QWORD *)&v5[2 * v29 + 30] != v30 )
    {
LABEL_53:
      puts("split: output sizes does not match input size");
      abort();
    }
    nc_free_tensor(v5);
  }
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

