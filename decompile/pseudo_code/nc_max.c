// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_max
// Included functions: 2

// ======================================================
// Function: nc_max @ 0x66A21830
// ======================================================

_QWORD *__fastcall nc_max(__int64 a1, __int64 a2)
{
  int v4; // r8d
  __int64 v5; // rax
  __int64 v6; // rdx
  _QWORD *v7; // rax
  _QWORD *v8; // rbp
  _QWORD *v9; // r14
  __int64 *v10; // rax
  __int64 v11; // r15
  _DWORD *v12; // rax
  _DWORD *v13; // rbx
  _QWORD *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 *v19; // rcx
  _QWORD *v20; // rax
  int v21; // eax
  int v22; // edi
  __int64 v23; // rdx
  int v24; // ecx
  __int64 v25; // rdx
  __int64 v26; // r8
  __int64 *v27; // rbx
  int v28; // edx
  __int64 v29; // rcx
  __int64 v30; // r9
  __int64 v31; // r10
  __int64 v32; // r11
  __int64 v33; // rdx
  __int64 v34; // rdx
  __int64 v35; // rdx
  __int64 v36; // r8
  __int64 v37; // rdx
  __int64 v38; // rdx
  __int64 v39; // rcx
  __int64 v41; // rdx
  __int64 v42; // [rsp+38h] [rbp-80h]
  __int64 *Block; // [rsp+40h] [rbp-78h]
  __int64 Blocka; // [rsp+40h] [rbp-78h]
  __int64 v45; // [rsp+50h] [rbp-68h] BYREF
  __int64 v46; // [rsp+58h] [rbp-60h]
  __int64 v47; // [rsp+60h] [rbp-58h]
  __int64 v48; // [rsp+68h] [rbp-50h]

  v42 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  if ( v42 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  if ( *(_DWORD *)(a1 + 48) || *(_DWORD *)(a2 + 48) )
    nc_error("unsupported type for %s\n", "nc_min_max");
  v4 = *(_DWORD *)(a1 + 80);
  if ( v4 != *(_DWORD *)(a2 + 80) )
LABEL_5:
    sub_66A16930("max", a1, a2);
  if ( v4 > 0 )
  {
    if ( *(_QWORD *)(a2 + 120) != *(_QWORD *)(a1 + 120) )
      goto LABEL_5;
    v5 = 1i64;
    while ( v4 > (int)v5 )
    {
      v6 = *(_QWORD *)(a1 + 8 * v5++ + 120);
      if ( v6 != *(_QWORD *)(a2 + 8 * v5 + 112) )
        goto LABEL_5;
    }
  }
  v7 = nc_new_tensor_nz(v42, 0, v4, a1 + 120);
  v8 = v7;
  if ( !*(_QWORD *)(a1 + 32) && !*(_QWORD *)(a2 + 32) )
  {
    v21 = *((_DWORD *)v7 + 20);
    v24 = v21;
    if ( v21 <= 0 || !*((_BYTE *)v8 + 73) || !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
    {
      Blocka = 1i64;
      v22 = 0;
      goto LABEL_109;
    }
    v41 = v8[15];
    if ( v21 == 1 )
    {
      v22 = 1;
      goto LABEL_108;
    }
    if ( *((_BYTE *)v8 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
    {
      v41 *= v8[16];
      if ( v21 == 2 )
      {
        v22 = 2;
        goto LABEL_108;
      }
      if ( *((_BYTE *)v8 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
      {
        v41 *= v8[17];
        if ( v21 == 3 )
        {
          v22 = 3;
          goto LABEL_108;
        }
        if ( *((_BYTE *)v8 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
        {
          v41 *= v8[18];
          v22 = 4;
LABEL_108:
          Blocka = (int)v41;
LABEL_109:
          v9 = 0i64;
          goto LABEL_45;
        }
        v22 = 3;
      }
      else
      {
        v22 = 2;
      }
    }
    else
    {
      v22 = 1;
    }
    v45 = 0i64;
    v9 = 0i64;
    Blocka = (int)v41;
    goto LABEL_46;
  }
  v9 = nc_new_tensor_nz(v42, 5u, *((_DWORD *)v7 + 20), (__int64)(v7 + 15));
  if ( !*(_QWORD *)(a1 + 32) && !*(_QWORD *)(a2 + 32) )
  {
    MEMORY[0x28] = 0;
    BUG();
  }
  v10 = (__int64 *)aligned_malloc(0x10ui64, 0x40ui64);
  v11 = v8[3];
  Block = v10;
  *v10 = *(_QWORD *)(a1 + 32);
  v10[1] = *(_QWORD *)(a2 + 32);
  v12 = aligned_malloc(0x80ui64, 0x40ui64);
  v13 = v12;
  if ( !v12 )
  {
    MEMORY[0x10] = 0;
    BUG();
  }
  memset(v12, 0, 0x80ui64);
  v12[4] = 1;
  v12[5] = 27;
  v12[6] = 2;
  v14 = aligned_malloc(0x10ui64, 0x40ui64);
  *((_QWORD *)v13 + 4) = v14;
  v15 = *Block;
  if ( *Block )
  {
    ++*(_DWORD *)(v15 + 16);
    *v14 = v15;
  }
  else
  {
    *v14 = 0i64;
  }
  v16 = Block[1];
  if ( v16 )
  {
    ++*(_DWORD *)(v16 + 16);
    v14[1] = v16;
  }
  else
  {
    v14[1] = 0i64;
  }
  v17 = *(_QWORD *)(v11 + 72);
  *(_QWORD *)(v11 + 72) = v17 + 1;
  *((_QWORD *)v13 + 12) = v17;
  v18 = *(_QWORD *)(v11 + 32);
  *(_QWORD *)(v18 + 8) = v13;
  *(_QWORD *)v13 = v18;
  *((_QWORD *)v13 + 1) = v11 + 32;
  *(_QWORD *)(v11 + 32) = v13;
  _aligned_free(Block);
  v19 = (__int64 *)v8[4];
  if ( v19 )
    nc_free_node(v19);
  v8[4] = v13;
  v13[10] = 1;
  v20 = aligned_malloc(8ui64, 0x40ui64);
  *((_QWORD *)v13 + 6) = v20;
  ++*((_DWORD *)v9 + 4);
  *v20 = v9;
  v21 = *((_DWORD *)v8 + 20);
  v22 = v21;
  if ( v21 > 0 && *((_BYTE *)v8 + 73) && *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) && *((_BYTE *)v9 + 73) )
  {
    v23 = v8[15];
    if ( v21 != 1 )
    {
      if ( *((_BYTE *)v8 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *((_BYTE *)v9 + 74) )
      {
        v23 *= v8[16];
        if ( v21 != 2 )
        {
          if ( *((_BYTE *)v8 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *((_BYTE *)v9 + 75) )
          {
            v23 *= v8[17];
            if ( v21 != 3 )
            {
              if ( *((_BYTE *)v8 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *((_BYTE *)v9 + 76) )
              {
                v23 *= v8[18];
                v22 = 4;
              }
              else
              {
                v22 = 3;
              }
            }
          }
          else
          {
            v22 = 2;
          }
        }
      }
      else
      {
        v22 = 1;
      }
    }
    Blocka = (int)v23;
  }
  else
  {
    Blocka = 1i64;
    v22 = 0;
  }
  v24 = *((_DWORD *)v8 + 20);
LABEL_45:
  v45 = 0i64;
  if ( v24 <= 1 )
  {
    v26 = 0i64;
    goto LABEL_49;
  }
LABEL_46:
  v25 = 1i64;
  do
    *(&v45 + v25++) = 0i64;
  while ( v24 > (int)v25 );
  v26 = v45;
LABEL_49:
  v27 = &v45 + v22;
  while ( 2 )
  {
    if ( v26 == -1 )
      goto LABEL_82;
    v28 = *(_DWORD *)(a1 + 80);
    v29 = *(_QWORD *)(a1 + 56);
    if ( v28 > 0 )
    {
      v30 = *(_QWORD *)(a1 + 88) * v26;
      if ( v28 != 1 )
      {
        v30 += *(_QWORD *)(a1 + 96) * v46;
        if ( v28 != 2 )
        {
          v30 += *(_QWORD *)(a1 + 104) * v47;
          if ( v28 != 3 )
          {
            v31 = v48;
            v32 = *(_QWORD *)(a1 + 112);
            goto LABEL_56;
          }
        }
      }
      goto LABEL_57;
    }
    v31 = *(_QWORD *)(a2 + 56);
    v30 = *(_QWORD *)(a1 + 56);
    v29 = *(unsigned int *)(a2 + 80);
    if ( (int)v29 <= 0 )
    {
LABEL_87:
      v33 = 0i64;
      goto LABEL_63;
    }
    while ( 1 )
    {
      v33 = *(_QWORD *)(a2 + 88) * v26;
      if ( (_DWORD)v29 != 1 )
      {
        v33 += *(_QWORD *)(a2 + 96) * v46;
        if ( (_DWORD)v29 != 2 )
        {
          v33 += *(_QWORD *)(a2 + 104) * v47;
          if ( (_DWORD)v29 != 3 )
          {
            v32 = v48;
            if ( (_DWORD)v29 != 4 )
              goto LABEL_56;
            v33 += *(_QWORD *)(a2 + 112) * v48;
          }
        }
      }
LABEL_63:
      v29 = v31 + v33;
      v31 = v8[7];
      if ( v21 <= 0 )
        break;
      v34 = v8[11] * v26;
      if ( v21 != 1 )
      {
        v34 += v8[12] * v46;
        if ( v21 != 2 )
        {
          v34 += v8[13] * v47;
          if ( v21 != 3 )
          {
            v32 = v48;
            if ( v21 != 4 )
              goto LABEL_56;
            v34 += v8[14] * v48;
          }
        }
      }
      v35 = v31 + v34;
      if ( !v9 )
        goto LABEL_85;
LABEL_70:
      v21 = *((_DWORD *)v9 + 20);
      v31 = v9[7];
      if ( v21 <= 0 )
      {
        v26 = 0i64;
        goto LABEL_76;
      }
      v26 *= v9[11];
      if ( v21 == 1 )
        goto LABEL_76;
      v26 += v9[12] * v46;
      if ( v21 == 2 )
        goto LABEL_76;
      v26 += v9[13] * v47;
      if ( v21 == 3 )
        goto LABEL_76;
      v32 = v48;
      if ( v21 == 4 )
      {
        v26 += v9[14] * v48;
LABEL_76:
        v36 = v31 + v26;
        goto LABEL_77;
      }
LABEL_56:
      v30 += v32 * v31;
LABEL_57:
      v30 += v29;
      v29 = *(unsigned int *)(a2 + 80);
      v31 = *(_QWORD *)(a2 + 56);
      if ( (int)v29 <= 0 )
        goto LABEL_87;
    }
    v35 = v8[7];
    if ( v9 )
      goto LABEL_70;
LABEL_85:
    v36 = 0i64;
LABEL_77:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v42 + 320))(
      v42,
      v35,
      v36,
      v30,
      v29,
      Blocka);
    v21 = *((_DWORD *)v8 + 20);
    if ( v22 >= v21 )
      goto LABEL_82;
    v37 = *v27 + 1;
    *v27 = v37;
    if ( v8[v22 + 15] != v37 )
    {
LABEL_83:
      v26 = v45;
      continue;
    }
    break;
  }
  v38 = 0i64;
  while ( 1 )
  {
    v27[v38] = 0i64;
    if ( v21 - 1 - v22 == v38 )
      break;
    v39 = v27[v38 + 1] + 1;
    v27[++v38] = v39;
    if ( v39 != v8[(unsigned int)(v22 + 1) + 14 + v38] )
      goto LABEL_83;
  }
LABEL_82:
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor(v9);
  return v8;
}

// ======================================================
// Function: sub_66A16930 @ 0x66A16930
// ======================================================

void __fastcall __noreturn sub_66A16930(const char *a1, __int64 a2, __int64 a3)
{
  printf("dimension error for %s: ", a1);
  nc_dump_dims("x1", a2);
  if ( a3 )
  {
    printf(", ");
    nc_dump_dims("x2", a3);
  }
  putchar(10);
  abort();
}

