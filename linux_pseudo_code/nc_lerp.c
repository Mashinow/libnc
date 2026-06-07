// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_lerp
// Included functions: 2

// ======================================================
// Function: nc_lerp @ 0x27AC0
// ======================================================

__int64 __fastcall nc_lerp(_QWORD *ptr, _QWORD *a2, _QWORD *a3)
{
  __int64 v6; // rdi
  int v7; // esi
  __int64 v8; // rdx
  __int64 v9; // rdi
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // r15
  int v15; // edi
  __int64 v16; // rax
  int v17; // ecx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 *v20; // rbx
  __int64 v21; // r8
  __int64 v22; // r8
  __int64 v23; // rsi
  __int64 v24; // rcx
  __int64 v25; // rcx
  int v26; // esi
  int v27; // edi
  __int64 v28; // rax
  int v29; // ecx
  __int64 v30; // rax
  __int64 v31; // rax
  int v32; // ecx
  __int64 v33; // rdx
  _QWORD *v34; // rax
  _QWORD *v35; // rbx
  _QWORD *v36; // rax
  __int64 v37; // rbp
  __int64 v38; // rax
  __int64 v39; // rbx
  int v41; // [rsp+4h] [rbp-94h]
  __int64 v42; // [rsp+8h] [rbp-90h]
  __int64 v43; // [rsp+10h] [rbp-88h]
  __int64 v44[4]; // [rsp+20h] [rbp-78h] BYREF
  __int64 v45; // [rsp+40h] [rbp-58h] BYREF
  __int64 v46; // [rsp+48h] [rbp-50h]
  __int64 v47; // [rsp+50h] [rbp-48h]
  __int64 v48; // [rsp+58h] [rbp-40h]

  v6 = *(_QWORD *)(ptr[5] + 24LL);
  v42 = v6;
  if ( v6 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( v6 != *(_QWORD *)(a3[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( *((_DWORD *)ptr + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_lerp");
  if ( *((_DWORD *)a2 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_lerp");
  if ( *((_DWORD *)a3 + 12) )
    nc_error("unsupported type for %s\n", (char)"nc_lerp");
  v7 = *((_DWORD *)a2 + 20);
  v8 = *((unsigned int *)ptr + 20);
  if ( v7 != (_DWORD)v8 )
LABEL_9:
    __assert_fail("same_dims(b, a)", "libnc.c", 0x1D8Bu, "nc_lerp");
  if ( v7 <= 0 )
  {
LABEL_56:
    if ( (_DWORD)v8 != *((_DWORD *)a3 + 20) )
      goto LABEL_57;
  }
  else
  {
    v9 = ptr[15];
    if ( v9 != a2[15] )
      goto LABEL_9;
    v10 = 1LL;
    while ( v7 > (int)v10 )
    {
      v11 = a2[v10++ + 15];
      if ( v11 != ptr[v10 + 14] )
        goto LABEL_9;
    }
    if ( (_DWORD)v8 != *((_DWORD *)a3 + 20) || (v12 = 1LL, v9 != a3[15]) )
LABEL_57:
      __assert_fail("same_dims(t, a)", "libnc.c", 0x1D8Cu, "nc_lerp");
    while ( (int)v8 > (int)v12 )
    {
      v13 = a3[v12++ + 15];
      if ( v13 != ptr[v12 + 14] )
        goto LABEL_57;
    }
  }
  v14 = nc_new_tensor_nz(*(_QWORD *)(ptr[5] + 24LL), *((unsigned int *)ptr + 12), v8, ptr + 15);
  v41 = *(_DWORD *)(v14 + 80);
  if ( v41 > 0 && *(_BYTE *)(v14 + 73) && *((_BYTE *)ptr + 73) && *((_BYTE *)a2 + 73) && *((_BYTE *)a3 + 73) )
  {
    v15 = *(_DWORD *)(v14 + 80);
    v16 = *(_QWORD *)(v14 + 120);
    if ( v15 != 1 )
    {
      if ( *(_BYTE *)(v14 + 74) && *((_BYTE *)ptr + 74) && *((_BYTE *)a2 + 74) && *((_BYTE *)a3 + 74) )
      {
        v16 *= *(_QWORD *)(v14 + 128);
        if ( v15 != 2 )
        {
          if ( *(_BYTE *)(v14 + 75) && *((_BYTE *)ptr + 75) && *((_BYTE *)a2 + 75) && *((_BYTE *)a3 + 75) )
          {
            v16 *= *(_QWORD *)(v14 + 136);
            if ( v15 != 3 )
            {
              if ( *(_BYTE *)(v14 + 76) && *((_BYTE *)ptr + 76) && *((_BYTE *)a2 + 76) && *((_BYTE *)a3 + 76) )
              {
                v16 *= *(_QWORD *)(v14 + 144);
                v41 = 4;
              }
              else
              {
                v41 = 3;
              }
            }
          }
          else
          {
            v41 = 2;
          }
        }
      }
      else
      {
        v41 = 1;
      }
    }
    v43 = (int)v16;
  }
  else
  {
    v43 = 1LL;
    v41 = 0;
  }
  v45 = 0LL;
  v17 = *((_DWORD *)ptr + 20);
  if ( v17 <= 1 )
  {
    v19 = 0LL;
  }
  else
  {
    v18 = 1LL;
    do
      *(&v45 + v18++) = 0LL;
    while ( v17 > (int)v18 );
    v19 = v45;
  }
  v20 = &v45 + v41;
  while ( v19 != -1 )
  {
    v8 = *((unsigned int *)a3 + 20);
    if ( (int)v8 <= 0 )
    {
      v8 = *((unsigned int *)a2 + 20);
      v22 = a3[7];
      v23 = a2[7];
      if ( (int)v8 <= 0 )
        goto LABEL_90;
    }
    else
    {
      v21 = a3[11] * v19;
      if ( (_DWORD)v8 != 1 )
      {
        v21 += a3[12] * v46;
        if ( (_DWORD)v8 != 2 )
        {
          v21 += a3[13] * v47;
          if ( (_DWORD)v8 != 3 )
          {
            if ( (_DWORD)v8 != 4 )
              goto LABEL_56;
            v21 += a3[14] * v48;
          }
        }
      }
      v8 = *((unsigned int *)a2 + 20);
      v22 = a3[7] + v21;
      v23 = a2[7];
      if ( (int)v8 <= 0 )
      {
LABEL_90:
        v24 = 0LL;
        goto LABEL_65;
      }
    }
    v24 = a2[11] * v19;
    if ( (_DWORD)v8 != 1 )
    {
      v24 += a2[12] * v46;
      if ( (_DWORD)v8 != 2 )
      {
        v24 += a2[13] * v47;
        if ( (_DWORD)v8 != 3 )
        {
          if ( (_DWORD)v8 != 4 )
            goto LABEL_56;
          v24 += a2[14] * v48;
        }
      }
    }
LABEL_65:
    v25 = v23 + v24;
    v26 = *((_DWORD *)ptr + 20);
    if ( v26 <= 0 )
    {
      v8 = 0LL;
    }
    else
    {
      v8 = ptr[11] * v19;
      if ( v26 != 1 )
      {
        v8 += ptr[12] * v46;
        if ( v26 != 2 )
        {
          v8 += ptr[13] * v47;
          if ( v26 != 3 )
          {
            if ( v26 != 4 )
              goto LABEL_56;
            v8 += ptr[14] * v48;
          }
        }
      }
    }
    v8 += ptr[7];
    v27 = *(_DWORD *)(v14 + 80);
    if ( v27 <= 0 )
    {
      v28 = 0LL;
    }
    else
    {
      v28 = *(_QWORD *)(v14 + 88) * v19;
      if ( v27 != 1 )
      {
        v28 += *(_QWORD *)(v14 + 96) * v46;
        if ( v27 != 2 )
        {
          v28 += *(_QWORD *)(v14 + 104) * v47;
          if ( v27 != 3 )
          {
            if ( v27 != 4 )
              goto LABEL_56;
            v28 += *(_QWORD *)(v14 + 112) * v48;
          }
        }
      }
    }
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v42 + 304))(
      v42,
      v28 + *(_QWORD *)(v14 + 56),
      v8,
      v25,
      v22,
      v43);
    v29 = *((_DWORD *)ptr + 20);
    if ( v41 >= v29 )
      goto LABEL_82;
    v30 = *v20 + 1;
    *v20 = v30;
    if ( ptr[v41 + 15] == v30 )
    {
      v31 = 0LL;
      v32 = v29 - 1 - v41;
      while ( 1 )
      {
        v20[v31] = 0LL;
        if ( v31 == v32 )
          break;
        v33 = v20[v31 + 1] + 1;
        v20[++v31] = v33;
        if ( v33 != ptr[(unsigned int)(v41 + 1) + 14 + v31] )
          goto LABEL_86;
      }
LABEL_82:
      v45 = -1LL;
      break;
    }
LABEL_86:
    v19 = v45;
  }
  v44[0] = (__int64)ptr;
  v44[1] = (__int64)a2;
  v44[2] = (__int64)a3;
  v34 = sub_176C0(26, (__int64 *)(v14 + 24), (void **)(v14 + 32), v44);
  v35 = v34;
  if ( v34 )
  {
    *((_DWORD *)v34 + 10) = 3;
    v36 = (_QWORD *)nc_malloc(0x18uLL);
    v35[6] = v36;
    *v36 = nc_dup_tensor(ptr);
    v37 = v35[6];
    v38 = nc_dup_tensor(a2);
    v39 = v35[6];
    *(_QWORD *)(v37 + 8) = v38;
    *(_QWORD *)(v39 + 16) = nc_dup_tensor(a3);
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  nc_free_tensor(a3);
  return v14;
}

// ======================================================
// Function: sub_176C0 @ 0x176C0
// ======================================================

_QWORD *__fastcall sub_176C0(int a1, __int64 *a2, void **a3, _QWORD *a4)
{
  _QWORD *v4; // r15
  _QWORD *v8; // rax
  __int64 v9; // r13
  _QWORD *v10; // r12
  __int64 v11; // rax
  __int64 v12; // rbx
  _DWORD *v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rbp
  __int64 v16; // rax
  __int64 v17; // rax

  if ( !*(_QWORD *)(*a4 + 32LL) && !*(_QWORD *)(a4[1] + 32LL) )
  {
    v4 = *(_QWORD **)(a4[2] + 32LL);
    if ( !v4 )
      return v4;
  }
  v8 = (_QWORD *)nc_malloc(0x18uLL);
  v9 = *a2;
  v10 = v8;
  *v8 = *(_QWORD *)(*a4 + 32LL);
  v8[1] = *(_QWORD *)(a4[1] + 32LL);
  v11 = a4[2];
  v12 = 0LL;
  v10[2] = *(_QWORD *)(v11 + 32);
  v13 = (_DWORD *)nc_mallocz(0x80uLL);
  v13[4] = 1;
  v4 = v13;
  v13[5] = a1;
  v13[6] = 3;
  v14 = nc_malloc(0x18uLL);
  v4[4] = v14;
  while ( v10[v12] )
  {
    v15 = (_QWORD *)(v14 + v12 * 8);
    ++v12;
    *v15 = nc_dup_node();
    if ( v12 == 3 )
      goto LABEL_10;
LABEL_7:
    v14 = v4[4];
  }
  *(_QWORD *)(v14 + v12 * 8) = 0LL;
  if ( ++v12 != 3 )
    goto LABEL_7;
LABEL_10:
  v16 = *(_QWORD *)(v9 + 72);
  *(_QWORD *)(v9 + 72) = v16 + 1;
  v4[12] = v16;
  v17 = *(_QWORD *)(v9 + 32);
  *(_QWORD *)(v17 + 8) = v4;
  *v4 = v17;
  v4[1] = v9 + 32;
  *(_QWORD *)(v9 + 32) = v4;
  nc_free(v10);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v4;
  return v4;
}

