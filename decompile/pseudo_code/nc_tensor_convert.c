// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_convert
// Included functions: 3

// ======================================================
// Function: nc_tensor_convert @ 0x66A18C90
// ======================================================

__int64 __fastcall nc_tensor_convert(__int64 a1, __int64 a2)
{
  int v2; // r15d
  _QWORD *v3; // rdi
  int v5; // ecx
  __int64 v7; // rbp
  int v8; // eax
  int v9; // eax
  int v10; // edx
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 result; // rax
  __int64 v14; // rbx
  __int64 *v15; // r14
  __int64 v16; // r12
  int v17; // ecx
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r9
  __int64 v21; // r11
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  __int64 v25; // rdx
  int v26; // edx
  __int64 v27; // rax
  int v28; // ecx
  __int64 v29; // rcx
  __int64 v30; // rdx
  int v31; // ecx
  int v32; // ecx
  __int64 v33; // rdx
  __int64 v34; // rax
  __int64 v35; // rdx
  int v36; // edx
  __int64 v37; // rax
  int v38; // ecx
  int v39; // ecx
  int v40; // ecx
  int v41; // ecx
  __int64 v42; // rdx
  int v43; // edx
  __int64 v44; // rax
  int v45; // ecx
  int v46; // ecx
  __int64 v47; // rdx
  int v48; // ecx
  int v49; // ecx
  __int64 v50; // rdx
  __int64 v51; // [rsp+20h] [rbp-68h] BYREF
  __int64 v52; // [rsp+28h] [rbp-60h]
  __int64 v53; // [rsp+30h] [rbp-58h]
  __int64 v54; // [rsp+38h] [rbp-50h]

  v2 = *(_DWORD *)(a2 + 80);
  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 40) + 24i64);
  v5 = *(_DWORD *)(a1 + 80);
  if ( v2 != v5 )
    goto LABEL_2;
  if ( v2 <= 0 )
  {
    if ( v3 == *(_QWORD **)(*(_QWORD *)(a2 + 40) + 24i64) )
      goto LABEL_140;
    goto LABEL_147;
  }
  if ( *(_QWORD *)(a2 + 120) != *(_QWORD *)(a1 + 120) )
  {
LABEL_2:
    sub_66A33D40("same_dims(dst, src)", "libnc.c", 5155);
    if ( v3 == *(_QWORD **)(*(_QWORD *)(a2 + 40) + 24i64) )
    {
      v2 = *(_DWORD *)(a1 + 80);
      if ( v2 > 0 )
        goto LABEL_4;
LABEL_140:
      v7 = 1i64;
      v2 = 0;
      goto LABEL_17;
    }
LABEL_147:
    nc_error("all operation tensors must be on the same device");
  }
  v34 = 1i64;
  while ( v5 > (int)v34 )
  {
    v35 = *(_QWORD *)(a1 + 8 * v34++ + 120);
    if ( v35 != *(_QWORD *)(a2 + 8 * v34 + 112) )
      goto LABEL_2;
  }
  if ( v3 != *(_QWORD **)(*(_QWORD *)(a2 + 40) + 24i64) )
    goto LABEL_147;
LABEL_4:
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
    goto LABEL_140;
  v7 = *(_QWORD *)(a1 + 120);
  if ( v2 > 1 && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
  {
    v7 *= *(_QWORD *)(a1 + 128);
    if ( v2 != 2 )
    {
      if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
      {
        v7 *= *(_QWORD *)(a1 + 136);
        if ( v2 != 3 )
        {
          if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
          {
            v7 *= *(_QWORD *)(a1 + 144);
            v2 = 4;
          }
          else
          {
            v2 = 3;
          }
        }
      }
      else
      {
        v2 = 2;
      }
    }
  }
  else
  {
    v2 = 1;
  }
  v7 = (int)v7;
LABEL_17:
  v8 = *(_DWORD *)(a1 + 48);
  if ( v8 != 2 )
  {
    if ( !v8 )
    {
      v9 = *(_DWORD *)(a2 + 48);
      if ( v9 != 2 )
      {
        if ( v9 == 1 )
        {
          v51 = 0i64;
          v10 = *(_DWORD *)(a2 + 80);
          if ( v10 <= 1 )
          {
            v12 = 0i64;
          }
          else
          {
            v11 = 1i64;
            do
              *(&v51 + v11++) = 0i64;
            while ( v10 > (int)v11 );
            v12 = v51;
          }
          result = (unsigned int)(v2 + 1);
          v14 = (__int64)(&v51 + v2);
          v15 = (__int64 *)(a2 + 8 * result);
          v16 = v2 + 12i64;
          goto LABEL_26;
        }
LABEL_144:
        abort();
      }
      v51 = 0i64;
      v43 = *(_DWORD *)(a2 + 80);
      if ( v43 <= 1 )
      {
        v12 = 0i64;
      }
      else
      {
        v44 = 1i64;
        do
          *(&v51 + v44++) = 0i64;
        while ( v43 > (int)v44 );
        v12 = v51;
      }
      result = (unsigned int)(v2 + 1);
      v15 = &v51 + v2;
      v16 = a2 + 8 * result;
      v14 = v2 + 12i64;
      while ( 1 )
      {
        if ( v12 == -1 )
          return result;
        v45 = *(_DWORD *)(a2 + 80);
        result = v3[18];
        v18 = *(_QWORD *)(a2 + 56);
        if ( v45 <= 0 )
        {
          v19 = 0i64;
        }
        else
        {
          v19 = *(_QWORD *)(a2 + 88) * v12;
          if ( v45 != 1 )
          {
            v19 += *(_QWORD *)(a2 + 96) * v52;
            if ( v45 != 2 )
            {
              v19 += *(_QWORD *)(a2 + 104) * v53;
              if ( v45 != 3 )
              {
                v20 = v54;
                v21 = *(_QWORD *)(a2 + 112);
                if ( v45 != 4 )
                  goto LABEL_32;
                v19 += v21 * v54;
              }
            }
          }
        }
        v46 = *(_DWORD *)(a1 + 80);
        v19 += v18;
        v20 = *(_QWORD *)(a1 + 56);
        if ( v46 <= 0 )
        {
          v12 = 0i64;
        }
        else
        {
          v12 *= *(_QWORD *)(a1 + 88);
          if ( v46 != 1 )
          {
            v12 += *(_QWORD *)(a1 + 96) * v52;
            if ( v46 != 2 )
            {
              v12 += *(_QWORD *)(a1 + 104) * v53;
              if ( v46 != 3 )
              {
                v18 = v54;
                v21 = *(_QWORD *)(a1 + 112);
                if ( v46 == 4 )
                {
                  v12 += v21 * v54;
                  goto LABEL_130;
                }
LABEL_32:
                while ( 2 )
                {
                  v19 += v21 * v20;
                  while ( 1 )
                  {
                    v22 = *(_DWORD *)(a1 + 80);
                    v19 += v18;
                    v20 = *(_QWORD *)(a1 + 56);
                    if ( v22 > 0 )
                      break;
                    while ( 1 )
                    {
                      v12 = 0i64;
LABEL_39:
                      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(
                                 v3,
                                 v20 + v12,
                                 v19,
                                 v7);
                      v23 = *(_DWORD *)(a2 + 80);
                      if ( v2 >= v23 )
                        return result;
                      result = *(_QWORD *)v14 + 1i64;
                      *(_QWORD *)v14 = result;
                      if ( result == *(_QWORD *)(a2 + 8 * v16 + 24) )
                      {
                        result = 0i64;
                        v24 = v23 - 1 - v2;
                        do
                        {
                          *(_QWORD *)(v14 + 8 * result) = 0i64;
                          if ( v24 == result )
                            return result;
                          v25 = *(_QWORD *)(v14 + 8 * result + 8) + 1i64;
                          *(_QWORD *)(v14 + 8 * result++ + 8) = v25;
                        }
                        while ( v25 == v15[result + 14] );
                      }
                      v12 = v51;
LABEL_26:
                      if ( v12 == -1 )
                        return result;
                      v17 = *(_DWORD *)(a2 + 80);
                      result = v3[20];
                      v18 = *(_QWORD *)(a2 + 56);
                      if ( v17 > 0 )
                        break;
                      v22 = *(_DWORD *)(a1 + 80);
                      v20 = *(_QWORD *)(a1 + 56);
                      v19 = *(_QWORD *)(a2 + 56);
                      if ( v22 > 0 )
                        goto LABEL_34;
                    }
                    v19 = *(_QWORD *)(a2 + 88) * v12;
                    if ( v17 != 1 )
                    {
                      v19 += *(_QWORD *)(a2 + 96) * v52;
                      if ( v17 != 2 )
                      {
                        v19 += *(_QWORD *)(a2 + 104) * v53;
                        if ( v17 != 3 )
                        {
                          v20 = v54;
                          v21 = *(_QWORD *)(a2 + 112);
                          goto LABEL_32;
                        }
                      }
                    }
                  }
LABEL_34:
                  v12 *= *(_QWORD *)(a1 + 88);
                  if ( v22 != 1 )
                  {
                    v12 += *(_QWORD *)(a1 + 96) * v52;
                    if ( v22 != 2 )
                    {
                      v12 += *(_QWORD *)(a1 + 104) * v53;
                      if ( v22 != 3 )
                      {
                        v18 = v54;
                        v21 = *(_QWORD *)(a1 + 112);
                        if ( v22 == 4 )
                        {
                          v12 += v21 * v54;
                          goto LABEL_39;
                        }
                        continue;
                      }
                    }
                  }
                  goto LABEL_39;
                }
              }
            }
          }
        }
LABEL_130:
        ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(v3, v20 + v12, v19, v7);
        result = *(unsigned int *)(a2 + 80);
        if ( v2 >= (int)result )
          return result;
        v47 = *v15 + 1;
        *v15 = v47;
        if ( *(_QWORD *)(a2 + 8 * v14 + 24) == v47 )
        {
          v48 = result - 1;
          result = 0i64;
          v49 = v48 - v2;
          do
          {
            v15[result] = 0i64;
            if ( v49 == result )
              return result;
            v50 = v15[result + 1] + 1;
            v15[++result] = v50;
          }
          while ( v50 == *(_QWORD *)(v16 + 8 * result + 112) );
        }
        v12 = v51;
      }
    }
    if ( v8 != 1 || *(_DWORD *)(a2 + 48) )
      goto LABEL_144;
    v51 = 0i64;
    v26 = *(_DWORD *)(a2 + 80);
    if ( v26 <= 1 )
    {
      result = 0i64;
    }
    else
    {
      v27 = 1i64;
      do
        *(&v51 + v27++) = 0i64;
      while ( v26 > (int)v27 );
      result = v51;
    }
    v15 = &v51 + v2;
    v16 = a2 + 8i64 * (unsigned int)(v2 + 1);
    v14 = v2 + 12i64;
    while ( 1 )
    {
      if ( result == -1 )
        return result;
      v28 = *(_DWORD *)(a2 + 80);
      v18 = v3[19];
      v19 = *(_QWORD *)(a2 + 56);
      if ( v28 <= 0 )
      {
        v29 = *(_QWORD *)(a1 + 56);
        v12 = *(unsigned int *)(a1 + 80);
        if ( (int)v12 <= 0 )
          goto LABEL_111;
      }
      else
      {
        v12 = *(_QWORD *)(a2 + 88) * result;
        if ( v28 != 1 )
        {
          v12 += *(_QWORD *)(a2 + 96) * v52;
          if ( v28 != 2 )
          {
            v12 += *(_QWORD *)(a2 + 104) * v53;
            if ( v28 != 3 )
            {
              v20 = v54;
              v21 = *(_QWORD *)(a2 + 112);
              if ( v28 != 4 )
                goto LABEL_32;
              v12 += v21 * v54;
            }
          }
        }
        v19 += v12;
        v12 = *(unsigned int *)(a1 + 80);
        v29 = *(_QWORD *)(a1 + 56);
        if ( (int)v12 <= 0 )
        {
LABEL_111:
          result = 0i64;
          goto LABEL_65;
        }
      }
      result *= *(_QWORD *)(a1 + 88);
      if ( (_DWORD)v12 != 1 )
      {
        result += *(_QWORD *)(a1 + 96) * v52;
        if ( (_DWORD)v12 != 2 )
        {
          result += *(_QWORD *)(a1 + 104) * v53;
          if ( (_DWORD)v12 != 3 )
          {
            v20 = v54;
            v21 = *(_QWORD *)(a1 + 112);
            if ( (_DWORD)v12 != 4 )
              goto LABEL_32;
            result += v21 * v54;
          }
        }
      }
LABEL_65:
      ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v18)(v3, v29 + result, v19, v7);
      result = *(unsigned int *)(a2 + 80);
      if ( v2 >= (int)result )
        return result;
      v30 = *v15 + 1;
      *v15 = v30;
      if ( v30 == *(_QWORD *)(a2 + 8 * v14 + 24) )
      {
        v31 = result - 1;
        result = 0i64;
        v32 = v31 - v2;
        do
        {
          v15[result] = 0i64;
          if ( result == v32 )
            return result;
          v33 = v15[result + 1] + 1;
          v15[++result] = v33;
        }
        while ( v33 == *(_QWORD *)(v16 + 8 * result + 112) );
      }
      result = v51;
    }
  }
  if ( *(_DWORD *)(a2 + 48) )
    goto LABEL_144;
  v51 = 0i64;
  v36 = *(_DWORD *)(a2 + 80);
  if ( v36 <= 1 )
  {
    v12 = 0i64;
  }
  else
  {
    v37 = 1i64;
    do
      *(&v51 + v37++) = 0i64;
    while ( v36 > (int)v37 );
    v12 = v51;
  }
  result = (unsigned int)(v2 + 1);
  v15 = &v51 + v2;
  v16 = a2 + 8 * result;
  v14 = v2 + 12i64;
  while ( v12 != -1 )
  {
    v38 = *(_DWORD *)(a2 + 80);
    result = v3[17];
    v18 = *(_QWORD *)(a2 + 56);
    if ( v38 <= 0 )
    {
      v19 = 0i64;
    }
    else
    {
      v19 = *(_QWORD *)(a2 + 88) * v12;
      if ( v38 != 1 )
      {
        v19 += *(_QWORD *)(a2 + 96) * v52;
        if ( v38 != 2 )
        {
          v19 += *(_QWORD *)(a2 + 104) * v53;
          if ( v38 != 3 )
          {
            v20 = v54;
            v21 = *(_QWORD *)(a2 + 112);
            if ( v38 != 4 )
              goto LABEL_32;
            v19 += v21 * v54;
          }
        }
      }
    }
    v39 = *(_DWORD *)(a1 + 80);
    v19 += v18;
    v20 = *(_QWORD *)(a1 + 56);
    if ( v39 <= 0 )
    {
      v12 = 0i64;
    }
    else
    {
      v12 *= *(_QWORD *)(a1 + 88);
      if ( v39 != 1 )
      {
        v12 += *(_QWORD *)(a1 + 96) * v52;
        if ( v39 != 2 )
        {
          v12 += *(_QWORD *)(a1 + 104) * v53;
          if ( v39 != 3 )
          {
            v18 = v54;
            v21 = *(_QWORD *)(a1 + 112);
            if ( v39 != 4 )
              goto LABEL_32;
            v12 += v21 * v54;
          }
        }
      }
    }
    result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(v3, v20 + v12, v19, v7);
    v40 = *(_DWORD *)(a2 + 80);
    if ( v40 <= v2 )
      break;
    result = *v15 + 1;
    *v15 = result;
    if ( result == *(_QWORD *)(a2 + 8 * v14 + 24) )
    {
      result = 0i64;
      v41 = v40 - 1 - v2;
      do
      {
        v15[result] = 0i64;
        if ( result == v41 )
          return result;
        v42 = v15[result + 1] + 1;
        v15[++result] = v42;
      }
      while ( v42 == *(_QWORD *)(v16 + 8 * result + 112) );
    }
    v12 = v51;
  }
  return result;
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

