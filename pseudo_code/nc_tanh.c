// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tanh
// Included functions: 1

// ======================================================
// Function: nc_tanh @ 0x66A29230
// ======================================================

_QWORD *__fastcall nc_tanh(__int64 a1)
{
  __int64 v1; // rax
  unsigned int v2; // edx
  __int64 v3; // rbp
  _QWORD *v5; // rax
  int v6; // r14d
  _QWORD *v7; // r13
  __int64 v8; // rax
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 *v12; // rbx
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // r11
  __int64 v17; // r15
  __int64 v18; // rdx
  int v19; // ecx
  __int64 v20; // rax
  __int64 v21; // rax
  int v22; // ecx
  __int64 v23; // rdx
  __int64 *v25; // rax
  __int64 v26; // rbp
  __int64 *v27; // r14
  _QWORD *v28; // rbx
  _QWORD *v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 *v33; // rcx
  _QWORD *v34; // rax
  __int64 v35; // [rsp+38h] [rbp-70h]
  __int64 v36; // [rsp+40h] [rbp-68h] BYREF
  __int64 v37; // [rsp+48h] [rbp-60h]
  __int64 v38; // [rsp+50h] [rbp-58h]
  __int64 v39; // [rsp+58h] [rbp-50h]

  v1 = *(_QWORD *)(a1 + 40);
  v2 = *(_DWORD *)(a1 + 48);
  v3 = *(_QWORD *)(v1 + 24);
  if ( v2 > 1 )
    nc_error("unsupported type for %s\n", "nc_tanh");
  v5 = nc_new_tensor_nz(*(_QWORD *)(v1 + 24), v2, *(_DWORD *)(a1 + 80), a1 + 120);
  v6 = *((_DWORD *)v5 + 20);
  v7 = v5;
  if ( v6 > 0 && *((_BYTE *)v5 + 73) && *(_BYTE *)(a1 + 73) )
  {
    v8 = v5[15];
    if ( v6 != 1 )
    {
      if ( *((_BYTE *)v7 + 74) && *(_BYTE *)(a1 + 74) )
      {
        v8 *= v7[16];
        if ( v6 != 2 )
        {
          if ( *((_BYTE *)v7 + 75) && *(_BYTE *)(a1 + 75) )
          {
            v8 *= v7[17];
            if ( v6 != 3 )
            {
              if ( *((_BYTE *)v7 + 76) && *(_BYTE *)(a1 + 76) )
              {
                v8 *= v7[18];
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
    v35 = (int)v8;
  }
  else
  {
    v35 = 1i64;
    v6 = 0;
  }
  v36 = 0i64;
  v9 = *(_DWORD *)(a1 + 80);
  if ( v9 <= 1 )
  {
    v11 = 0i64;
  }
  else
  {
    v10 = 1i64;
    do
      *(&v36 + v10++) = 0i64;
    while ( v9 > (int)v10 );
    v11 = v36;
  }
  v12 = &v36 + v6;
  while ( v11 != -1 )
  {
    v13 = *(_DWORD *)(a1 + 80);
    v14 = *(_QWORD *)(a1 + 56);
    if ( v13 > 0 )
    {
      v15 = *(_QWORD *)(a1 + 88) * v11;
      if ( v13 != 1 )
      {
        v15 += *(_QWORD *)(a1 + 96) * v37;
        if ( v13 != 2 )
        {
          v15 += *(_QWORD *)(a1 + 104) * v38;
          if ( v13 != 3 )
          {
            v16 = v39;
            v17 = *(_QWORD *)(a1 + 112);
            goto LABEL_27;
          }
        }
      }
      goto LABEL_28;
    }
    v18 = v7[7];
    v15 = *(_QWORD *)(a1 + 56);
    v14 = *((unsigned int *)v7 + 20);
    if ( (int)v14 > 0 )
    {
      while ( 1 )
      {
        v11 *= v7[11];
        if ( (_DWORD)v14 == 1 )
          break;
        v11 += v7[12] * v37;
        if ( (_DWORD)v14 == 2 )
          break;
        v11 += v7[13] * v38;
        if ( (_DWORD)v14 == 3 )
          break;
        v16 = v39;
        v17 = v7[14];
        if ( (_DWORD)v14 == 4 )
        {
          v11 += v17 * v39;
          break;
        }
LABEL_27:
        v15 += v17 * v16;
LABEL_28:
        v15 += v14;
        v14 = *((unsigned int *)v7 + 20);
        v18 = v7[7];
        if ( (int)v14 <= 0 )
          goto LABEL_44;
      }
    }
    else
    {
LABEL_44:
      v11 = 0i64;
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _DWORD))(v3 + 240))(
      v3,
      v11 + v18,
      v15,
      v35,
      *(_DWORD *)(a1 + 48));
    v19 = *(_DWORD *)(a1 + 80);
    if ( v6 >= v19 )
      goto LABEL_39;
    v20 = *v12 + 1;
    *v12 = v20;
    if ( v20 == *(_QWORD *)(a1 + 8 * (v6 + 12i64) + 24) )
    {
      v21 = 0i64;
      v22 = v19 - 1 - v6;
      while ( 1 )
      {
        v12[v21] = 0i64;
        if ( v22 == v21 )
          break;
        v23 = v12[v21 + 1] + 1;
        v12[++v21] = v23;
        if ( v23 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v6 + 1) + 8 * v21 + 112) )
          goto LABEL_42;
      }
LABEL_39:
      v36 = -1i64;
      break;
    }
LABEL_42:
    v11 = v36;
  }
  if ( *(_QWORD *)(a1 + 32) )
  {
    v25 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v26 = v7[3];
    v27 = v25;
    *v25 = *(_QWORD *)(a1 + 32);
    v28 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v28 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v28, 0, 0x80ui64);
    *((_DWORD *)v28 + 4) = 1;
    *((_DWORD *)v28 + 5) = 21;
    *((_DWORD *)v28 + 6) = 1;
    v29 = aligned_malloc(8ui64, 0x40ui64);
    v30 = *v27;
    v28[4] = v29;
    if ( v30 )
    {
      ++*(_DWORD *)(v30 + 16);
      *v29 = v30;
    }
    else
    {
      *v29 = 0i64;
    }
    v31 = *(_QWORD *)(v26 + 72);
    *(_QWORD *)(v26 + 72) = v31 + 1;
    v28[12] = v31;
    v32 = *(_QWORD *)(v26 + 32);
    *(_QWORD *)(v32 + 8) = v28;
    *v28 = v32;
    v28[1] = v26 + 32;
    *(_QWORD *)(v26 + 32) = v28;
    _aligned_free(v27);
    v33 = (__int64 *)v7[4];
    if ( v33 )
      nc_free_node(v33);
    v7[4] = v28;
    *((_DWORD *)v28 + 10) = 1;
    v34 = aligned_malloc(8ui64, 0x40ui64);
    v28[6] = v34;
    ++*((_DWORD *)v7 + 4);
    *v34 = v7;
  }
  nc_free_tensor((_DWORD *)a1);
  return v7;
}

