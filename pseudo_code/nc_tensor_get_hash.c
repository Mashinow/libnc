// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_get_hash
// Included functions: 1

// ======================================================
// Function: nc_tensor_get_hash @ 0x66A188D0
// ======================================================

__int64 __fastcall nc_tensor_get_hash(__int64 a1)
{
  __int64 v1; // rax
  __int64 v3; // rcx
  _QWORD *v4; // rdi
  __int64 v5; // rax
  int v6; // ebp
  __int64 v7; // r13
  int v8; // r14d
  __int64 v9; // rax
  __int64 v10; // rcx
  unsigned int v11; // ebx
  __int64 *v12; // rdx
  __int64 v13; // rax
  __int64 v14; // r8
  __int64 v15; // rcx
  _BYTE *v16; // r9
  _BYTE *v17; // r8
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v24[13]; // [rsp+30h] [rbp-68h] BYREF

  v1 = *(_QWORD *)(a1 + 24);
  ++*(_DWORD *)(a1 + 16);
  v3 = *(_QWORD *)(v1 + 64);
  v4 = (_QWORD *)a1;
  if ( v3 != *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64) )
  {
    v4 = nc_new_tensor_nz(v3, *(_DWORD *)(a1 + 48), *(_DWORD *)(a1 + 80), a1 + 120);
    nc_tensor_copy((__int64)v4, a1);
    v5 = *(_QWORD *)(a1 + 32);
    if ( v5 )
    {
      ++*(_DWORD *)(v5 + 16);
      v4[4] = v5;
    }
    nc_free_tensor((_DWORD *)a1);
  }
  v6 = *((_DWORD *)v4 + 20);
  if ( v6 <= 0 )
  {
    v7 = 1i64;
    v8 = 0;
    v10 = 0i64;
    v24[0] = 0i64;
    goto LABEL_19;
  }
  if ( !*((_BYTE *)v4 + 73) )
  {
    v7 = 1i64;
    v8 = 0;
    goto LABEL_15;
  }
  v7 = v4[15];
  if ( v6 == 1 )
  {
    v8 = 1;
    goto LABEL_14;
  }
  if ( !*((_BYTE *)v4 + 74) )
  {
    v8 = 1;
LABEL_45:
    v24[0] = 0i64;
    v7 = (int)v7;
LABEL_16:
    v9 = 1i64;
    do
      v24[v9++] = 0i64;
    while ( v6 > (int)v9 );
    v10 = v24[0];
    goto LABEL_19;
  }
  v7 *= v4[16];
  if ( v6 == 2 )
  {
    v8 = 2;
    goto LABEL_14;
  }
  if ( !*((_BYTE *)v4 + 75) )
  {
    v8 = 2;
    goto LABEL_45;
  }
  v7 *= v4[17];
  if ( v6 == 3 )
  {
    v8 = 3;
    goto LABEL_14;
  }
  if ( !*((_BYTE *)v4 + 76) )
  {
    v8 = 3;
    goto LABEL_45;
  }
  v7 *= v4[18];
  v8 = 4;
LABEL_14:
  v7 = (int)v7;
LABEL_15:
  v24[0] = 0i64;
  if ( v6 > 1 )
    goto LABEL_16;
  v10 = 0i64;
LABEL_19:
  v11 = -1;
  v12 = &v24[v8];
  while ( v10 != -1 )
  {
    v13 = nc_type_size_table[*((unsigned int *)v4 + 12)] * v7;
    v14 = v4[7];
    if ( v6 <= 0 )
      goto LABEL_26;
    v15 = v4[11] * v10;
    if ( v6 != 1 )
    {
      v15 += v4[12] * v24[1];
      if ( v6 != 2 )
      {
        v15 += v4[13] * v24[2];
        if ( v6 != 3 )
        {
          if ( v6 != 4 )
          {
LABEL_26:
            v15 = 0i64;
            goto LABEL_27;
          }
          v15 += v4[14] * v24[3];
        }
      }
    }
LABEL_27:
    if ( v13 )
    {
      v16 = (_BYTE *)(v14 + v15);
      v17 = (_BYTE *)(v15 + v13 + v14);
      do
      {
        v18 = v11;
        v19 = *v16++ ^ HIBYTE(v11);
        v11 = dword_66A371C0[v19] ^ (v18 << 8);
      }
      while ( v17 != v16 );
    }
    if ( v6 <= v8 )
      break;
    v20 = *v12 + 1;
    v21 = 0i64;
    *v12 = v20;
    if ( v20 == v4[v8 + 15] )
    {
      do
      {
        v12[v21] = 0i64;
        if ( v21 == v6 - 1 - v8 )
          goto LABEL_35;
        v22 = v12[v21 + 1] + 1;
        v12[++v21] = v22;
      }
      while ( v22 == v4[(unsigned int)(v8 + 1) + 14 + v21] );
    }
    v10 = v24[0];
  }
LABEL_35:
  nc_free_tensor(v4);
  return v11;
}

