// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_neg
// Included functions: 1

// ======================================================
// Function: nc_neg @ 0x66A1F940
// ======================================================

_QWORD *__fastcall nc_neg(__int64 a1)
{
  __int64 v1; // rdi
  _QWORD *v3; // rax
  int v4; // r15d
  _QWORD *v5; // r13
  __int64 v6; // rbp
  int v7; // edx
  __int64 v8; // rax
  __int64 v9; // rdx
  __int64 *v10; // rbx
  int v11; // ecx
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r9
  __int64 v15; // r11
  int v16; // ecx
  int v17; // ecx
  __int64 v18; // rax
  __int64 v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  __int64 *v23; // rax
  __int64 v24; // rbp
  __int64 *v25; // r14
  _QWORD *v26; // rbx
  _QWORD *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 *v31; // rcx
  __int64 v32; // [rsp+20h] [rbp-68h] BYREF
  __int64 v33; // [rsp+28h] [rbp-60h]
  __int64 v34; // [rsp+30h] [rbp-58h]
  __int64 v35; // [rsp+38h] [rbp-50h]

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( *(_DWORD *)(a1 + 48) )
    nc_error("unsupported type for %s\n", "nc_neg");
  v3 = nc_new_tensor_nz(v1, 0, *(_DWORD *)(a1 + 80), a1 + 120);
  v4 = *((_DWORD *)v3 + 20);
  v5 = v3;
  if ( v4 > 0 && *((_BYTE *)v3 + 73) && *(_BYTE *)(a1 + 73) )
  {
    v6 = v3[15];
    if ( v4 != 1 )
    {
      if ( *((_BYTE *)v3 + 74) && *(_BYTE *)(a1 + 74) )
      {
        v6 *= v3[16];
        if ( v4 != 2 )
        {
          if ( *((_BYTE *)v3 + 75) && *(_BYTE *)(a1 + 75) )
          {
            v6 *= v3[17];
            if ( v4 != 3 )
            {
              if ( *((_BYTE *)v3 + 76) && *(_BYTE *)(a1 + 76) )
              {
                v6 *= v3[18];
                v4 = 4;
              }
              else
              {
                v4 = 3;
              }
            }
          }
          else
          {
            v4 = 2;
          }
        }
      }
      else
      {
        v4 = 1;
      }
    }
    v6 = (int)v6;
  }
  else
  {
    v6 = 1i64;
    v4 = 0;
  }
  v32 = 0i64;
  v7 = *(_DWORD *)(a1 + 80);
  if ( v7 <= 1 )
  {
    v9 = 0i64;
  }
  else
  {
    v8 = 1i64;
    do
      *(&v32 + v8++) = 0i64;
    while ( v7 > (int)v8 );
    v9 = v32;
  }
  v10 = &v32 + v4;
  while ( v9 != -1 )
  {
    v11 = *(_DWORD *)(a1 + 80);
    v12 = *(_QWORD *)(a1 + 56);
    if ( v11 > 0 )
    {
      v13 = *(_QWORD *)(a1 + 88) * v9;
      if ( v11 != 1 )
      {
        v13 += *(_QWORD *)(a1 + 96) * v33;
        if ( v11 != 2 )
        {
          v13 += *(_QWORD *)(a1 + 104) * v34;
          if ( v11 != 3 )
          {
            v14 = v35;
            v15 = *(_QWORD *)(a1 + 112);
            goto LABEL_27;
          }
        }
      }
      goto LABEL_28;
    }
    v16 = *((_DWORD *)v5 + 20);
    v14 = v5[7];
    v13 = *(_QWORD *)(a1 + 56);
    if ( v16 > 0 )
    {
      while ( 1 )
      {
        v9 *= v5[11];
        if ( v16 == 1 )
          break;
        v9 += v5[12] * v33;
        if ( v16 == 2 )
          break;
        v9 += v5[13] * v34;
        if ( v16 == 3 )
          break;
        v12 = v35;
        v15 = v5[14];
        if ( v16 == 4 )
        {
          v9 += v15 * v35;
          break;
        }
LABEL_27:
        v13 += v15 * v14;
LABEL_28:
        v16 = *((_DWORD *)v5 + 20);
        v13 += v12;
        v14 = v5[7];
        if ( v16 <= 0 )
          goto LABEL_44;
      }
    }
    else
    {
LABEL_44:
      v9 = 0i64;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 192))(v1, v14 + v9, v13, v6);
    v17 = *(_DWORD *)(a1 + 80);
    if ( v4 >= v17 )
      goto LABEL_39;
    v18 = *v10 + 1;
    *v10 = v18;
    if ( v18 == *(_QWORD *)(a1 + 8 * (v4 + 12i64) + 24) )
    {
      v19 = 0i64;
      v20 = v17 - 1 - v4;
      while ( 1 )
      {
        v10[v19] = 0i64;
        if ( v20 == v19 )
          break;
        v21 = v10[v19 + 1] + 1;
        v10[++v19] = v21;
        if ( v21 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v4 + 1) + 8 * v19 + 112) )
          goto LABEL_42;
      }
LABEL_39:
      v32 = -1i64;
      break;
    }
LABEL_42:
    v9 = v32;
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v23 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v24 = v5[3];
    v25 = v23;
    *v23 = *(_QWORD *)(a1 + 32);
    v26 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v26 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v26, 0, 0x80ui64);
    *((_DWORD *)v26 + 4) = 1;
    *((_DWORD *)v26 + 5) = 8;
    *((_DWORD *)v26 + 6) = 1;
    v27 = aligned_malloc(8ui64, 0x40ui64);
    v28 = *v25;
    v26[4] = v27;
    if ( v28 )
    {
      ++*(_DWORD *)(v28 + 16);
      *v27 = v28;
    }
    else
    {
      *v27 = 0i64;
    }
    v29 = *(_QWORD *)(v24 + 72);
    *(_QWORD *)(v24 + 72) = v29 + 1;
    v26[12] = v29;
    v30 = *(_QWORD *)(v24 + 32);
    *(_QWORD *)(v30 + 8) = v26;
    *v26 = v30;
    v26[1] = v24 + 32;
    *(_QWORD *)(v24 + 32) = v26;
    _aligned_free(v25);
    v31 = (__int64 *)v5[4];
    if ( v31 )
      nc_free_node(v31);
    v5[4] = v26;
  }
  nc_free_tensor((_DWORD *)a1);
  return v5;
}

