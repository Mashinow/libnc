// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_max
// Included functions: 3

// ======================================================
// Function: nc_max @ 0x1F700
// ======================================================

__int64 __fastcall nc_max(_QWORD *ptr, _QWORD *a2)
{
  __int64 v4; // rsi
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // r12
  __int64 v10; // r15
  _QWORD *v11; // rax
  _QWORD *v12; // rbp
  int v13; // eax
  __int64 v14; // rdx
  int v15; // r10d
  _QWORD *v16; // rdi
  __int64 v17; // rdx
  __int64 *v18; // rbx
  __int64 v19; // rbp
  int v20; // edx
  __int64 v21; // rsi
  __int64 v22; // rcx
  __int64 v23; // r8
  __int64 v24; // r9
  char *v25; // rdx
  __int64 v26; // rdx
  __int64 v27; // rdx
  __int64 v28; // rcx
  __int64 v30; // rdx
  _QWORD *v31; // [rsp+0h] [rbp-78h]
  int v32; // [rsp+0h] [rbp-78h]
  __int64 v33; // [rsp+8h] [rbp-70h]
  __int64 v34; // [rsp+10h] [rbp-68h]
  __int64 v35; // [rsp+18h] [rbp-60h]
  _QWORD *v36; // [rsp+20h] [rbp-58h] BYREF
  __int64 v37; // [rsp+28h] [rbp-50h]
  __int64 v38; // [rsp+30h] [rbp-48h]
  __int64 v39; // [rsp+38h] [rbp-40h]

  v4 = *(_QWORD *)(ptr[5] + 24LL);
  v34 = v4;
  if ( v4 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", v4);
  if ( *((_DWORD *)ptr + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_min_max");
  if ( *((_DWORD *)a2 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_min_max");
  v5 = *((unsigned int *)ptr + 20);
  if ( (_DWORD)v5 != *((_DWORD *)a2 + 20) )
LABEL_6:
    sub_18270("max", (__int64)ptr, (__int64)a2);
  if ( (int)v5 > 0 )
  {
    if ( a2[15] != ptr[15] )
      goto LABEL_6;
    v6 = 1LL;
    while ( (int)v5 > (int)v6 )
    {
      v7 = ptr[v6++ + 15];
      if ( v7 != a2[v6 + 14] )
        goto LABEL_6;
    }
  }
  v8 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v5, ptr + 15);
  v9 = v8;
  if ( ptr[4] || a2[4] )
  {
    v10 = nc_new_tensor_nz(v4, 5LL, *(unsigned int *)(v8 + 80), v8 + 120);
    v36 = ptr;
    v37 = (__int64)a2;
    v11 = sub_17590(27, (__int64 *)(v9 + 24), (void **)(v9 + 32), &v36);
    *((_DWORD *)v11 + 10) = 1;
    v31 = v11;
    v12 = (_QWORD *)nc_malloc(8uLL);
    v31[6] = v12;
    *v12 = nc_dup_tensor(v10);
    v13 = *(_DWORD *)(v9 + 80);
    if ( v13 <= 0 || !*(_BYTE *)(v9 + 73) || !*((_BYTE *)ptr + 73) || !*((_BYTE *)a2 + 73) || !*(_BYTE *)(v10 + 73) )
    {
      v33 = 1LL;
      v15 = 0;
LABEL_37:
      v36 = 0LL;
      v16 = 0LL;
      if ( v13 <= 1 )
        goto LABEL_41;
      goto LABEL_38;
    }
    v14 = *(_QWORD *)(v9 + 120);
    if ( v13 != 1 )
    {
      if ( *(_BYTE *)(v9 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) && *(_BYTE *)(v10 + 74) )
      {
        v14 *= *(_QWORD *)(v9 + 128);
        if ( v13 == 2 )
        {
          v15 = 2;
          goto LABEL_36;
        }
        if ( *(_BYTE *)(v9 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) && *(_BYTE *)(v10 + 75) )
        {
          v14 *= *(_QWORD *)(v9 + 136);
          if ( v13 == 3 )
          {
            v15 = 3;
            goto LABEL_36;
          }
          if ( *(_BYTE *)(v9 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) && *(_BYTE *)(v10 + 76) )
          {
            v14 *= *(_QWORD *)(v9 + 144);
            v15 = 4;
LABEL_36:
            v33 = (int)v14;
            goto LABEL_37;
          }
          v15 = 3;
        }
        else
        {
          v15 = 2;
        }
      }
      else
      {
        v15 = 1;
      }
      v36 = 0LL;
      v33 = (int)v14;
      goto LABEL_38;
    }
    v15 = 1;
    goto LABEL_36;
  }
  v13 = *(_DWORD *)(v8 + 80);
  if ( v13 <= 0 || !*(_BYTE *)(v9 + 73) || !*((_BYTE *)ptr + 73) || !*((_BYTE *)a2 + 73) )
  {
    v33 = 1LL;
    v15 = 0;
    goto LABEL_100;
  }
  v30 = *(_QWORD *)(v9 + 120);
  if ( v13 == 1 )
  {
    v15 = 1;
    goto LABEL_99;
  }
  if ( !*(_BYTE *)(v9 + 74) )
    goto LABEL_120;
  if ( !*((_BYTE *)ptr + 74) )
  {
    v15 = 1;
    goto LABEL_110;
  }
  if ( !*((_BYTE *)a2 + 74) )
  {
LABEL_120:
    v15 = 1;
    goto LABEL_114;
  }
  v30 *= *(_QWORD *)(v9 + 128);
  if ( v13 == 2 )
  {
    v15 = 2;
    goto LABEL_99;
  }
  if ( !*(_BYTE *)(v9 + 75) )
    goto LABEL_117;
  if ( !*((_BYTE *)ptr + 75) )
  {
    v15 = 2;
    goto LABEL_110;
  }
  if ( !*((_BYTE *)a2 + 75) )
  {
LABEL_117:
    v15 = 2;
    goto LABEL_114;
  }
  v30 *= *(_QWORD *)(v9 + 136);
  if ( v13 == 3 )
  {
    v15 = 3;
    goto LABEL_99;
  }
  if ( !*(_BYTE *)(v9 + 76) )
    goto LABEL_113;
  if ( *((_BYTE *)ptr + 76) )
  {
    if ( *((_BYTE *)a2 + 76) )
    {
      v30 *= *(_QWORD *)(v9 + 144);
      v15 = 4;
LABEL_99:
      v33 = (int)v30;
LABEL_100:
      v10 = 0LL;
      goto LABEL_37;
    }
LABEL_113:
    v15 = 3;
LABEL_114:
    v33 = (int)v30;
    goto LABEL_111;
  }
  v15 = 3;
LABEL_110:
  v33 = (int)v30;
LABEL_111:
  v36 = 0LL;
  v10 = 0LL;
LABEL_38:
  v17 = 1LL;
  do
    (&v36)[v17++] = 0LL;
  while ( v13 > (int)v17 );
  v16 = v36;
LABEL_41:
  v18 = (__int64 *)&(&v36)[v15];
  v35 = v15 + 12LL;
  v19 = v9 + 8LL * (unsigned int)(v15 + 1);
  while ( v16 != (_QWORD *)-1LL )
  {
    v20 = *((_DWORD *)ptr + 20);
    v21 = ptr[7];
    if ( v20 <= 0 )
    {
      v22 = 0LL;
    }
    else
    {
      v22 = ptr[11] * (_QWORD)v16;
      if ( v20 != 1 )
      {
        v22 += ptr[12] * v37;
        if ( v20 != 2 )
        {
          v22 += ptr[13] * v38;
          if ( v20 != 3 )
          {
            v23 = v39;
            v24 = ptr[14];
            goto LABEL_48;
          }
        }
      }
    }
    while ( 1 )
    {
      v22 += v21;
      v21 = *((unsigned int *)a2 + 20);
      if ( (int)v21 <= 0 )
      {
        v23 = 0LL;
      }
      else
      {
        v23 = a2[11] * (_QWORD)v16;
        if ( (_DWORD)v21 != 1 )
        {
          v23 += a2[12] * v37;
          if ( (_DWORD)v21 != 2 )
          {
            v23 += a2[13] * v38;
            if ( (_DWORD)v21 != 3 )
            {
              v24 = v39;
              if ( (_DWORD)v21 != 4 )
                goto LABEL_48;
              v23 += a2[14] * v39;
            }
          }
        }
      }
      v23 += a2[7];
      if ( v13 <= 0 )
        break;
      v21 = *(_QWORD *)(v9 + 88) * (_QWORD)v16;
      if ( v13 != 1 )
      {
        v21 += *(_QWORD *)(v9 + 96) * v37;
        if ( v13 != 2 )
        {
          v21 += *(_QWORD *)(v9 + 104) * v38;
          if ( v13 != 3 )
          {
            v24 = v39;
            if ( v13 != 4 )
              goto LABEL_48;
            v21 += *(_QWORD *)(v9 + 112) * v39;
          }
        }
      }
      v21 += *(_QWORD *)(v9 + 56);
      if ( !v10 )
        goto LABEL_77;
LABEL_62:
      v13 = *(_DWORD *)(v10 + 80);
      if ( v13 <= 0 )
      {
        v16 = 0LL;
        goto LABEL_68;
      }
      v16 = (_QWORD *)(*(_QWORD *)(v10 + 88) * (_QWORD)v16);
      if ( v13 == 1 )
        goto LABEL_68;
      v16 = (_QWORD *)((char *)v16 + *(_QWORD *)(v10 + 96) * v37);
      if ( v13 == 2 )
        goto LABEL_68;
      v16 = (_QWORD *)((char *)v16 + *(_QWORD *)(v10 + 104) * v38);
      if ( v13 == 3 )
        goto LABEL_68;
      v24 = v39;
      if ( v13 == 4 )
      {
        v16 = (_QWORD *)((char *)v16 + *(_QWORD *)(v10 + 112) * v39);
LABEL_68:
        v25 = (char *)v16 + *(_QWORD *)(v10 + 56);
        goto LABEL_69;
      }
LABEL_48:
      v22 += v24 * v23;
    }
    v21 = *(_QWORD *)(v9 + 56);
    if ( v10 )
      goto LABEL_62;
LABEL_77:
    v25 = 0LL;
LABEL_69:
    v32 = v15;
    (*(void (__fastcall **)(__int64, __int64, char *, __int64, __int64, __int64))(v34 + 320))(
      v34,
      v21,
      v25,
      v22,
      v23,
      v33);
    v13 = *(_DWORD *)(v9 + 80);
    v15 = v32;
    if ( v32 < v13 )
    {
      v26 = *v18 + 1;
      *v18 = v26;
      if ( v26 != *(_QWORD *)(v9 + 8 * v35 + 24) )
      {
LABEL_75:
        v16 = v36;
        continue;
      }
      v27 = 0LL;
      while ( 1 )
      {
        v18[v27] = 0LL;
        if ( v13 - 1 - v32 == v27 )
          break;
        v28 = v18[v27 + 1] + 1;
        v18[++v27] = v28;
        if ( v28 != *(_QWORD *)(v19 + 8 * v27 + 112) )
          goto LABEL_75;
      }
    }
    break;
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  nc_free_tensor((void *)v10);
  return v9;
}

// ======================================================
// Function: sub_18270 @ 0x18270
// ======================================================

void __fastcall __noreturn sub_18270(const char *a1, __int64 a2, __int64 a3)
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

// ======================================================
// Function: sub_17590 @ 0x17590
// ======================================================

_QWORD *__fastcall sub_17590(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  __int64 *v7; // rax
  __int64 v8; // r12
  __int64 *v9; // rbp
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  _QWORD *v14; // r14
  __int64 v15; // rax
  __int64 v16; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(0x10uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*a4 + 32LL);
  v7[1] = *(_QWORD *)(a4[1] + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 2;
  v12 = (_QWORD *)nc_malloc(0x10uLL);
  v13 = *v9;
  v14 = v12;
  v11[4] = v12;
  if ( !v13 )
  {
    *v12 = 0LL;
    if ( v9[1] )
      goto LABEL_6;
LABEL_11:
    v14[1] = 0LL;
    goto LABEL_7;
  }
  *v12 = nc_dup_node();
  v14 = (_QWORD *)v11[4];
  if ( !v9[1] )
    goto LABEL_11;
LABEL_6:
  v14[1] = nc_dup_node();
LABEL_7:
  v15 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v15 + 1;
  v11[12] = v15;
  v16 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v16 + 8) = v11;
  *v11 = v16;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

