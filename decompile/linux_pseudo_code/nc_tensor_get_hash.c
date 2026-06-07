// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_get_hash
// Included functions: 1

// ======================================================
// Function: nc_tensor_get_hash @ 0x19E60
// ======================================================

__int64 __fastcall nc_tensor_get_hash(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rax
  int v3; // r11d
  __int64 v4; // rdi
  __int64 v5; // rbp
  int v6; // r12d
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // ebx
  __int64 *v10; // rcx
  __int64 v11; // rsi
  __int64 v12; // r15
  __int64 v13; // rax
  _BYTE *v14; // rdx
  _BYTE *v15; // r14
  unsigned int v16; // esi
  unsigned __int8 v17; // bl
  __int64 v18; // rdx
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v22[11]; // [rsp+0h] [rbp-58h] BYREF

  v1 = nc_dup_tensor(a1);
  v2 = nc_tensor_to_cpu_device(v1);
  v3 = *(_DWORD *)(v2 + 80);
  v4 = v2;
  if ( v3 <= 0 )
  {
    v22[0] = 0LL;
    v6 = 0;
    v8 = 0LL;
    v5 = 1LL;
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(v2 + 73) )
  {
    v5 = 1LL;
    v6 = 0;
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(v2 + 120);
  if ( v3 == 1 )
  {
    v6 = 1;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(v2 + 74) )
  {
    v6 = 1;
LABEL_41:
    v5 = (int)v5;
    v22[0] = 0LL;
LABEL_12:
    v7 = 1LL;
    do
      v22[v7++] = 0LL;
    while ( v3 > (int)v7 );
    v8 = v22[0];
    goto LABEL_15;
  }
  v5 *= *(_QWORD *)(v2 + 128);
  if ( v3 == 2 )
  {
    v6 = 2;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(v2 + 75) )
  {
    v6 = 2;
    goto LABEL_41;
  }
  v5 *= *(_QWORD *)(v2 + 136);
  if ( v3 == 3 )
  {
    v6 = 3;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(v2 + 76) )
  {
    v6 = 3;
    goto LABEL_41;
  }
  v5 *= *(_QWORD *)(v2 + 144);
  v6 = 4;
LABEL_10:
  v5 = (int)v5;
LABEL_11:
  v22[0] = 0LL;
  if ( v3 > 1 )
    goto LABEL_12;
  v8 = 0LL;
LABEL_15:
  v9 = -1;
  v10 = &v22[v6];
  while ( v8 != -1 )
  {
    v11 = nc_type_size_table[*(unsigned int *)(v4 + 48)] * v5;
    v12 = *(_QWORD *)(v4 + 56);
    if ( v3 <= 0 )
      goto LABEL_22;
    v13 = *(_QWORD *)(v4 + 88) * v8;
    if ( v3 != 1 )
    {
      v13 += *(_QWORD *)(v4 + 96) * v22[1];
      if ( v3 != 2 )
      {
        v13 += *(_QWORD *)(v4 + 104) * v22[2];
        if ( v3 != 3 )
        {
          if ( v3 != 4 )
          {
LABEL_22:
            v13 = 0LL;
            goto LABEL_23;
          }
          v13 += *(_QWORD *)(v4 + 112) * v22[3];
        }
      }
    }
LABEL_23:
    if ( v11 )
    {
      v14 = (_BYTE *)(v12 + v13);
      v15 = (_BYTE *)(v12 + v11 + v13);
      do
      {
        v16 = v9;
        v17 = *v14++ ^ HIBYTE(v9);
        v9 = dword_30120[v17] ^ (v16 << 8);
      }
      while ( v15 != v14 );
    }
    if ( v3 <= v6 )
      break;
    v18 = 0LL;
    v19 = *v10 + 1;
    *v10 = v19;
    if ( v19 == *(_QWORD *)(v4 + 8 * (v6 + 12LL) + 24) )
    {
      do
      {
        v10[v18] = 0LL;
        if ( v18 == v3 - 1 - v6 )
          goto LABEL_31;
        v20 = v10[v18 + 1] + 1;
        v10[++v18] = v20;
      }
      while ( v20 == *(_QWORD *)(v4 + 8LL * (unsigned int)(v6 + 1) + 8 * v18 + 112) );
    }
    v8 = v22[0];
  }
LABEL_31:
  nc_free_tensor((void *)v4);
  return v9;
}

