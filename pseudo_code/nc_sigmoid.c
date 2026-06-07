// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sigmoid
// Included functions: 1

// ======================================================
// Function: nc_sigmoid @ 0x66A28980
// ======================================================

_QWORD *__fastcall nc_sigmoid(__int64 a1)
{
  __int64 v1; // rax
  unsigned int v2; // edx
  __int64 v3; // rbp
  _QWORD *v5; // r13
  int v6; // r14d
  __int64 v7; // rax
  int v8; // ecx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 *v11; // rbx
  int v12; // edx
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // r11
  __int64 v16; // r15
  __int64 v17; // rdx
  int v18; // ecx
  __int64 v19; // rax
  __int64 v20; // rax
  int v21; // ecx
  __int64 v22; // rdx
  __int64 *v24; // rax
  __int64 v25; // rbp
  __int64 *v26; // r14
  _QWORD *v27; // rbx
  _QWORD *v28; // rax
  __int64 v29; // rdx
  __int64 v30; // rax
  __int64 v31; // rax
  __int64 *v32; // rcx
  _QWORD *v33; // rax
  __int64 v34; // [rsp+38h] [rbp-70h]
  __int64 v35; // [rsp+40h] [rbp-68h] BYREF
  __int64 v36; // [rsp+48h] [rbp-60h]
  __int64 v37; // [rsp+50h] [rbp-58h]
  __int64 v38; // [rsp+58h] [rbp-50h]

  v1 = *(_QWORD *)(a1 + 40);
  v2 = *(_DWORD *)(a1 + 48);
  v3 = *(_QWORD *)(v1 + 24);
  if ( v2 > 1 )
    nc_error("unsupported type for %s\n", "nc_sigmoid");
  v5 = (_QWORD *)a1;
  if ( *(_DWORD *)(a1 + 16) != 1 )
    v5 = nc_new_tensor_nz(*(_QWORD *)(v1 + 24), v2, *(_DWORD *)(a1 + 80), a1 + 120);
  v6 = *((_DWORD *)v5 + 20);
  if ( v6 > 0 && *((_BYTE *)v5 + 73) && *(_BYTE *)(a1 + 73) )
  {
    v7 = v5[15];
    if ( v6 != 1 )
    {
      if ( *((_BYTE *)v5 + 74) && *(_BYTE *)(a1 + 74) )
      {
        v7 *= v5[16];
        if ( v6 != 2 )
        {
          if ( *((_BYTE *)v5 + 75) && *(_BYTE *)(a1 + 75) )
          {
            v7 *= v5[17];
            if ( v6 != 3 )
            {
              if ( *((_BYTE *)v5 + 76) && *(_BYTE *)(a1 + 76) )
              {
                v7 *= v5[18];
                v6 = 4;
              }
              else
              {
                v6 = 3;
              }
            }
          }
          else
          {
            v6 = 2;
          }
        }
      }
      else
      {
        v6 = 1;
      }
    }
    v34 = (int)v7;
  }
  else
  {
    v34 = 1i64;
    v6 = 0;
  }
  v35 = 0i64;
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 <= 1 )
  {
    v10 = 0i64;
  }
  else
  {
    v9 = 1i64;
    do
      *(&v35 + v9++) = 0i64;
    while ( v8 > (int)v9 );
    v10 = v35;
  }
  v11 = &v35 + v6;
  while ( v10 != -1 )
  {
    v12 = *(_DWORD *)(a1 + 80);
    v13 = *(_QWORD *)(a1 + 56);
    if ( v12 > 0 )
    {
      v14 = *(_QWORD *)(a1 + 88) * v10;
      if ( v12 != 1 )
      {
        v14 += *(_QWORD *)(a1 + 96) * v36;
        if ( v12 != 2 )
        {
          v14 += *(_QWORD *)(a1 + 104) * v37;
          if ( v12 != 3 )
          {
            v15 = v38;
            v16 = *(_QWORD *)(a1 + 112);
            goto LABEL_29;
          }
        }
      }
      goto LABEL_30;
    }
    v17 = v5[7];
    v14 = *(_QWORD *)(a1 + 56);
    v13 = *((unsigned int *)v5 + 20);
    if ( (int)v13 > 0 )
    {
      while ( 1 )
      {
        v10 *= v5[11];
        if ( (_DWORD)v13 == 1 )
          break;
        v10 += v5[12] * v36;
        if ( (_DWORD)v13 == 2 )
          break;
        v10 += v5[13] * v37;
        if ( (_DWORD)v13 == 3 )
          break;
        v15 = v38;
        v16 = v5[14];
        if ( (_DWORD)v13 == 4 )
        {
          v10 += v16 * v38;
          break;
        }
LABEL_29:
        v14 += v16 * v15;
LABEL_30:
        v14 += v13;
        v13 = *((unsigned int *)v5 + 20);
        v17 = v5[7];
        if ( (int)v13 <= 0 )
          goto LABEL_48;
      }
    }
    else
    {
LABEL_48:
      v10 = 0i64;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _DWORD))(v3 + 224))(
      v3,
      v10 + v17,
      v14,
      v34,
      *(_DWORD *)(a1 + 48));
    v18 = *(_DWORD *)(a1 + 80);
    if ( v6 >= v18 )
      goto LABEL_41;
    v19 = *v11 + 1;
    *v11 = v19;
    if ( *(_QWORD *)(a1 + 8 * (v6 + 12i64) + 24) == v19 )
    {
      v20 = 0i64;
      v21 = v18 - 1 - v6;
      while ( 1 )
      {
        v11[v20] = 0i64;
        if ( v20 == v21 )
          break;
        v22 = v11[v20 + 1] + 1;
        v11[++v20] = v22;
        if ( v22 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v6 + 1) + 8 * v20 + 112) )
          goto LABEL_46;
      }
LABEL_41:
      v35 = -1i64;
      break;
    }
LABEL_46:
    v10 = v35;
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v24 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v25 = v5[3];
    v26 = v24;
    *v24 = *(_QWORD *)(a1 + 32);
    v27 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v27 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v27, 0, 0x80ui64);
    *((_DWORD *)v27 + 4) = 1;
    *((_DWORD *)v27 + 5) = 20;
    *((_DWORD *)v27 + 6) = 1;
    v28 = aligned_malloc(8ui64, 0x40ui64);
    v29 = *v26;
    v27[4] = v28;
    if ( v29 )
    {
      ++*(_DWORD *)(v29 + 16);
      *v28 = v29;
    }
    else
    {
      *v28 = 0i64;
    }
    v30 = *(_QWORD *)(v25 + 72);
    *(_QWORD *)(v25 + 72) = v30 + 1;
    v27[12] = v30;
    v31 = *(_QWORD *)(v25 + 32);
    *(_QWORD *)(v31 + 8) = v27;
    *v27 = v31;
    v27[1] = v25 + 32;
    *(_QWORD *)(v25 + 32) = v27;
    _aligned_free(v26);
    v32 = (__int64 *)v5[4];
    if ( v32 )
      nc_free_node(v32);
    v5[4] = v27;
    *((_DWORD *)v27 + 10) = 1;
    v33 = aligned_malloc(8ui64, 0x40ui64);
    v27[6] = v33;
    ++*((_DWORD *)v5 + 4);
    *v33 = v5;
  }
  if ( v5 != (_QWORD *)a1 )
    nc_free_tensor((_DWORD *)a1);
  return v5;
}

