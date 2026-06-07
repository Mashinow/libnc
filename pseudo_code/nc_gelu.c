// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_gelu
// Included functions: 2

// ======================================================
// Function: nc_gelu @ 0x66A2A590
// ======================================================

_QWORD *__fastcall nc_gelu(__int64 a1)
{
  unsigned int v1; // edx
  __int64 v2; // rax
  _QWORD *v4; // rdi
  _QWORD *v5; // rax
  __int64 v6; // r15
  __int64 v7; // r12
  __int64 v8; // rax
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 *v12; // rsi
  __int64 v13; // rbp
  int v14; // edx
  int v15; // r11d
  void (__fastcall *v16)(__int64, __int64, __int64, __int64, __int64, int); // r10
  __int64 v17; // rcx
  __int64 v18; // r9
  __int64 v19; // r8
  __int64 v20; // r13
  int v21; // edx
  int v22; // ecx
  __int64 v23; // rax
  __int64 v24; // rax
  int v25; // ecx
  __int64 v26; // rdx
  _QWORD *v27; // rsi
  _QWORD *v28; // rax
  int v30; // r14d
  int v31; // ecx
  __int64 v32; // rax
  int v33; // edx
  int v34; // ecx
  __int64 v35; // rax
  __int64 v36; // rax
  int v37; // ecx
  __int64 v38; // rdx
  __int64 v39; // [rsp+38h] [rbp-90h]
  __int64 v40; // [rsp+40h] [rbp-88h]
  __int64 v41; // [rsp+48h] [rbp-80h]
  __int64 v42; // [rsp+58h] [rbp-70h] BYREF
  __int64 v43; // [rsp+60h] [rbp-68h] BYREF
  __int64 v44; // [rsp+68h] [rbp-60h]
  __int64 v45; // [rsp+70h] [rbp-58h]
  __int64 v46; // [rsp+78h] [rbp-50h]

  v1 = *(_DWORD *)(a1 + 48);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v39 = v2;
  if ( v1 > 1 )
    nc_error("unsupported type for %s\n", "nc_gelu");
  if ( *(_QWORD *)(a1 + 32) )
  {
    v4 = nc_new_tensor_nz(v2, v1, *(_DWORD *)(a1 + 80), a1 + 120);
    v5 = nc_new_tensor_nz(
           *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64),
           *(_DWORD *)(a1 + 48),
           *(_DWORD *)(a1 + 80),
           a1 + 120);
    LODWORD(v6) = *((_DWORD *)v4 + 20);
    v7 = (__int64)v5;
    if ( (int)v6 > 0 && *((_BYTE *)v4 + 73) && *((_BYTE *)v5 + 73) && *(_BYTE *)(a1 + 73) )
    {
      v8 = v4[15];
      if ( (_DWORD)v6 != 1 )
      {
        if ( *((_BYTE *)v4 + 74) && *(_BYTE *)(v7 + 74) && *(_BYTE *)(a1 + 74) )
        {
          v8 *= v4[16];
          if ( (_DWORD)v6 != 2 )
          {
            if ( *((_BYTE *)v4 + 75) && *(_BYTE *)(v7 + 75) && *(_BYTE *)(a1 + 75) )
            {
              v8 *= v4[17];
              if ( (_DWORD)v6 != 3 )
              {
                if ( *((_BYTE *)v4 + 76) && *(_BYTE *)(v7 + 76) && *(_BYTE *)(a1 + 76) )
                {
                  v8 *= v4[18];
                  LODWORD(v6) = 4;
                }
                else
                {
                  LODWORD(v6) = 3;
                }
              }
            }
            else
            {
              LODWORD(v6) = 2;
            }
          }
        }
        else
        {
          LODWORD(v6) = 1;
        }
      }
      v40 = (int)v8;
    }
    else
    {
      v40 = 1i64;
      LODWORD(v6) = 0;
    }
    v43 = 0i64;
    v9 = *(_DWORD *)(a1 + 80);
    if ( v9 <= 1 )
    {
      v11 = 0i64;
    }
    else
    {
      v10 = 1i64;
      do
        *(&v43 + v10++) = 0i64;
      while ( v9 > (int)v10 );
      v11 = v43;
    }
    v12 = &v43 + (int)v6;
    v41 = (int)v6 + 12i64;
    v13 = a1 + 8i64 * (unsigned int)(v6 + 1);
    goto LABEL_26;
  }
  v4 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
    v4 = nc_new_tensor_nz(v2, v1, *(_DWORD *)(a1 + 80), a1 + 120);
  v30 = *((_DWORD *)v4 + 20);
  if ( v30 > 0 && *((_BYTE *)v4 + 73) && *(_BYTE *)(a1 + 73) )
  {
    v13 = v4[15];
    if ( v30 != 1 )
    {
      if ( *((_BYTE *)v4 + 74) && *(_BYTE *)(a1 + 74) )
      {
        v13 *= v4[16];
        if ( v30 != 2 )
        {
          if ( *((_BYTE *)v4 + 75) && *(_BYTE *)(a1 + 75) )
          {
            v13 *= v4[17];
            if ( v30 != 3 )
            {
              if ( *((_BYTE *)v4 + 76) && *(_BYTE *)(a1 + 76) )
              {
                v13 *= v4[18];
                v30 = 4;
              }
              else
              {
                v30 = 3;
              }
            }
          }
          else
          {
            v30 = 2;
          }
        }
      }
      else
      {
        v30 = 1;
      }
    }
    v13 = (int)v13;
  }
  else
  {
    v13 = 1i64;
    v30 = 0;
  }
  v43 = 0i64;
  v31 = *(_DWORD *)(a1 + 80);
  if ( v31 <= 1 )
  {
    v11 = 0i64;
  }
  else
  {
    v32 = 1i64;
    do
      *(&v43 + v32++) = 0i64;
    while ( v31 > (int)v32 );
    v11 = v43;
  }
  v12 = &v43 + v30;
  v7 = v30 + 12i64;
  v20 = a1 + 8i64 * (unsigned int)(v30 + 1);
  while ( 1 )
  {
    if ( v11 == -1 )
      goto LABEL_96;
    v33 = *(_DWORD *)(a1 + 80);
    v19 = *(unsigned int *)(a1 + 48);
    v16 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, int))(v39 + 272);
    v17 = *(_QWORD *)(a1 + 56);
    if ( v33 <= 0 )
    {
      v18 = 0i64;
    }
    else
    {
      v18 = *(_QWORD *)(a1 + 88) * v11;
      if ( v33 != 1 )
      {
        v18 += *(_QWORD *)(a1 + 96) * v44;
        if ( v33 != 2 )
        {
          v18 += *(_QWORD *)(a1 + 104) * v45;
          if ( v33 != 3 )
          {
            v15 = v46;
            v6 = *(_QWORD *)(a1 + 112);
            if ( v33 != 4 )
              goto LABEL_32;
            v18 += v6 * v46;
          }
        }
      }
    }
    v18 += v17;
    v17 = *((unsigned int *)v4 + 20);
    if ( (int)v17 <= 0 )
    {
      v11 = 0i64;
      goto LABEL_90;
    }
    v11 *= v4[11];
    if ( (_DWORD)v17 != 1 )
    {
      v11 += v4[12] * v44;
      if ( (_DWORD)v17 != 2 )
      {
        v11 += v4[13] * v45;
        if ( (_DWORD)v17 != 3 )
          break;
      }
    }
LABEL_90:
    v16(v39, v11 + v4[7], 0i64, v18, v13, v19);
    v34 = *(_DWORD *)(a1 + 80);
    if ( v30 >= v34 )
      goto LABEL_95;
    v35 = *v12 + 1;
    *v12 = v35;
    if ( *(_QWORD *)(a1 + 8 * v7 + 24) == v35 )
    {
      v36 = 0i64;
      v37 = v34 - 1 - v30;
      while ( 1 )
      {
        v12[v36] = 0i64;
        if ( v37 == v36 )
          break;
        v38 = v12[v36 + 1] + 1;
        v12[++v36] = v38;
        if ( v38 != *(_QWORD *)(v20 + 8 * v36 + 112) )
          goto LABEL_98;
      }
LABEL_95:
      v43 = -1i64;
LABEL_96:
      if ( v4 != (_QWORD *)a1 )
        nc_free_tensor((_DWORD *)a1);
      return v4;
    }
LABEL_98:
    v11 = v43;
  }
  v15 = v46;
  v6 = v4[14];
  if ( (_DWORD)v17 == 4 )
  {
    v11 += v6 * v46;
    goto LABEL_90;
  }
LABEL_32:
  v18 += v20 * v19;
  while ( 1 )
  {
    v21 = *(_DWORD *)(v7 + 80);
    v18 += v17;
    v17 = *(_QWORD *)(v7 + 56);
    if ( v21 <= 0 )
    {
      v19 = 0i64;
    }
    else
    {
      v19 = *(_QWORD *)(v7 + 88) * v11;
      if ( v21 != 1 )
      {
        v19 += *(_QWORD *)(v7 + 96) * v44;
        if ( v21 != 2 )
        {
          v19 += *(_QWORD *)(v7 + 104) * v45;
          if ( v21 != 3 )
          {
            v20 = v46;
            if ( v21 != 4 )
              goto LABEL_32;
            v19 += *(_QWORD *)(v7 + 112) * v46;
          }
        }
      }
    }
    v19 += v17;
    v17 = *((unsigned int *)v4 + 20);
    if ( (int)v17 <= 0 )
    {
      v11 = 0i64;
    }
    else
    {
      v11 *= v4[11];
      if ( (_DWORD)v17 != 1 )
      {
        v11 += v4[12] * v44;
        if ( (_DWORD)v17 != 2 )
        {
          v11 += v4[13] * v45;
          if ( (_DWORD)v17 != 3 )
          {
            v20 = v46;
            if ( (_DWORD)v17 != 4 )
              goto LABEL_32;
            v11 += v4[14] * v46;
          }
        }
      }
    }
    v16(v39, v11 + v4[7], v19, v18, v40, v15);
    v22 = *(_DWORD *)(a1 + 80);
    if ( v22 <= (int)v6 )
      break;
    v23 = *v12 + 1;
    *v12 = v23;
    if ( *(_QWORD *)(a1 + 8 * v41 + 24) == v23 )
    {
      v24 = 0i64;
      v25 = v22 - 1 - v6;
      do
      {
        v12[v24] = 0i64;
        if ( v25 == v24 )
          goto LABEL_50;
        v26 = v12[v24 + 1] + 1;
        v12[++v24] = v26;
      }
      while ( v26 == *(_QWORD *)(v13 + 8 * v24 + 112) );
    }
    v11 = v43;
LABEL_26:
    if ( v11 == -1 )
      break;
    v14 = *(_DWORD *)(a1 + 80);
    v15 = *(_DWORD *)(a1 + 48);
    v16 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, int))(v39 + 272);
    v17 = *(_QWORD *)(a1 + 56);
    if ( v14 <= 0 )
    {
      v18 = 0i64;
    }
    else
    {
      v18 = *(_QWORD *)(a1 + 88) * v11;
      if ( v14 != 1 )
      {
        v18 += *(_QWORD *)(a1 + 96) * v44;
        if ( v14 != 2 )
        {
          v18 += *(_QWORD *)(a1 + 104) * v45;
          if ( v14 != 3 )
          {
            v19 = v46;
            v20 = *(_QWORD *)(a1 + 112);
            goto LABEL_32;
          }
        }
      }
    }
  }
LABEL_50:
  v42 = a1;
  v27 = sub_66A15DA0(23, v4 + 3, (__int64 **)v4 + 4, 1, (__int64)&v42);
  *((_DWORD *)v27 + 10) = 2;
  v28 = aligned_malloc(0x10ui64, 0x40ui64);
  v27[6] = v28;
  ++*(_DWORD *)(a1 + 16);
  *v28 = a1;
  ++*(_DWORD *)(v7 + 16);
  v28[1] = v7;
  nc_free_tensor((_DWORD *)v7);
  nc_free_tensor((_DWORD *)a1);
  return v4;
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

