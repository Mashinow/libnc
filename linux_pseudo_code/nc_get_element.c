// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_get_element
// Included functions: 2

// ======================================================
// Function: nc_get_element @ 0x22C20
// ======================================================

__int64 __fastcall nc_get_element(_QWORD *ptr, _QWORD *a2)
{
  __int64 v4; // rbx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // r15
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // r13
  __int64 v12; // rax
  int v13; // edx
  __int64 v14; // rax
  __int64 v15; // rbp
  int v16; // edx
  __int64 v17; // rsi
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rdi
  unsigned __int64 v21; // rdx
  unsigned __int64 v22; // rdx
  __int64 v23; // rdx
  int v24; // eax
  __int64 v25; // rdx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  _QWORD *v28; // rbx
  _QWORD *v29; // rax
  __int64 v31; // [rsp+8h] [rbp-70h]
  _QWORD *v32; // [rsp+18h] [rbp-60h] BYREF
  unsigned __int64 v33; // [rsp+20h] [rbp-58h] BYREF
  __int64 v34; // [rsp+28h] [rbp-50h]
  __int64 v35; // [rsp+30h] [rbp-48h]
  __int64 v36; // [rsp+38h] [rbp-40h]
  __int64 v37; // [rsp+40h] [rbp-38h]

  v4 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v4 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( *((_DWORD *)a2 + 12) != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_get_element");
  v5 = *((unsigned int *)a2 + 20);
  if ( *((_DWORD *)ptr + 20) != (_DWORD)v5 + 1 )
    __assert_fail("w->n_dims == (x->n_dims + 1)", "libnc.c", 0x1A99u, "nc_get_element");
  v6 = 0LL;
  while ( v6 != (int)v5 )
  {
    ++v6;
    if ( ptr[v6 + 15] != a2[v6 + 14] )
      __assert_fail("w->dims[i + 1] == x->dims[i]", "libnc.c", 0x1A9Bu, "nc_get_element");
  }
  v7 = nc_new_tensor_nz(v4, *((unsigned int *)ptr + 12), v5, a2 + 15);
  v8 = nc_dup_tensor(a2);
  v9 = nc_tensor_to_cpu_device(v8);
  v10 = *((unsigned int *)ptr + 12);
  v34 = 0LL;
  v11 = v9;
  v12 = nc_type_size_table[v10];
  v13 = *(_DWORD *)(v11 + 80);
  v31 = v12;
  if ( v13 <= 1 )
  {
    v15 = 0LL;
  }
  else
  {
    v14 = 1LL;
    do
      *(&v33 + ++v14) = 0LL;
    while ( v13 > (int)v14 );
LABEL_12:
    v15 = v34;
  }
  while ( v15 != -1 )
  {
    v16 = *(_DWORD *)(v11 + 80);
    v17 = *(_QWORD *)(v11 + 56);
    if ( v16 <= 0 )
    {
      v18 = 0LL;
    }
    else
    {
      v18 = *(_QWORD *)(v11 + 88) * v15;
      if ( v16 != 1 )
      {
        v18 += *(_QWORD *)(v11 + 96) * v35;
        if ( v16 != 2 )
        {
          v18 += *(_QWORD *)(v11 + 104) * v36;
          if ( v16 != 3 )
          {
            v19 = v37;
            v20 = *(_QWORD *)(v11 + 112);
            goto LABEL_19;
          }
        }
      }
    }
    while ( 1 )
    {
      v21 = *(int *)(v17 + v18);
      if ( (v21 & 0x80000000) != 0LL || v21 >= ptr[15] )
        __assert_fail("c >= 0 && c < w->dims[0]", "libnc.c", 0x1AA5u, "nc_get_element");
      v19 = *((unsigned int *)ptr + 20);
      v18 = *(_QWORD *)(v4 + 64);
      v33 = v21;
      v20 = ptr[7];
      if ( (int)v19 <= 0 )
      {
        v22 = 0LL;
      }
      else
      {
        v22 = ptr[11] * v21;
        if ( (_DWORD)v19 != 1 )
        {
          v22 += ptr[12] * v15;
          if ( (_DWORD)v19 != 2 )
          {
            v22 += ptr[13] * v35;
            if ( (_DWORD)v19 != 3 )
            {
              v17 = v36;
              if ( (_DWORD)v19 != 4 )
                goto LABEL_19;
              v22 += ptr[14] * v36;
            }
          }
        }
      }
      v19 = *(unsigned int *)(v7 + 80);
      v23 = v20 + v22;
      v20 = *(_QWORD *)(v7 + 56);
      if ( (int)v19 <= 0 )
        break;
      v17 = *(_QWORD *)(v7 + 88) * v15;
      if ( (_DWORD)v19 == 1 )
        goto LABEL_34;
      v17 += *(_QWORD *)(v7 + 96) * v35;
      if ( (_DWORD)v19 == 2 )
        goto LABEL_34;
      v17 += *(_QWORD *)(v7 + 104) * v36;
      if ( (_DWORD)v19 == 3 )
        goto LABEL_34;
      if ( (_DWORD)v19 == 4 )
      {
        v17 += *(_QWORD *)(v7 + 112) * v37;
        goto LABEL_34;
      }
LABEL_19:
      v18 += v20 * v19;
    }
    v17 = 0LL;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))v18)(v4, v20 + v17, v23, v31);
    v24 = *(_DWORD *)(v11 + 80);
    if ( v24 <= 0 )
    {
LABEL_39:
      v34 = -1LL;
      break;
    }
    v34 = ++v15;
    if ( v15 == *(_QWORD *)(v11 + 120) )
    {
      v25 = 1LL;
      while ( 1 )
      {
        *(&v33 + v25) = 0LL;
        if ( v24 <= (int)v25 )
          goto LABEL_39;
        v26 = *(&v33 + v25 + 1) + 1;
        *(&v33 + ++v25) = v26;
        if ( v26 != *(_QWORD *)(v11 + 8 * v25 + 112) )
          goto LABEL_12;
      }
    }
  }
  nc_free_tensor((void *)v11);
  v32 = ptr;
  v27 = sub_17800(33, (__int64 *)(v7 + 24), (void **)(v7 + 32), (__int64)&v32);
  v28 = v27;
  if ( v27 )
  {
    *((_DWORD *)v27 + 10) = 1;
    v29 = (_QWORD *)nc_malloc(8uLL);
    v28[6] = v29;
    *v29 = nc_dup_tensor(a2);
    v28[7] = ptr[15];
  }
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v7;
}

// ======================================================
// Function: sub_17800 @ 0x17800
// ======================================================

_QWORD *__fastcall sub_17800(int a1, __int64 *a2, void **a3, __int64 a4)
{
  __int64 *v7; // rax
  __int64 v8; // rbp
  __int64 *v9; // r14
  _DWORD *v10; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rax

  if ( !*(_QWORD *)(*(_QWORD *)a4 + 32LL) )
    return 0LL;
  v7 = (__int64 *)nc_malloc(8uLL);
  v8 = *a2;
  v9 = v7;
  *v7 = *(_QWORD *)(*(_QWORD *)a4 + 32LL);
  v10 = (_DWORD *)nc_mallocz(0x80uLL);
  v10[5] = a1;
  v11 = v10;
  v10[4] = 1;
  v10[6] = 1;
  v12 = (_QWORD *)nc_malloc(8uLL);
  v13 = *v9;
  v11[4] = v12;
  if ( v13 )
    *v12 = nc_dup_node();
  else
    *v12 = 0LL;
  v14 = *(_QWORD *)(v8 + 72);
  *(_QWORD *)(v8 + 72) = v14 + 1;
  v11[12] = v14;
  v15 = *(_QWORD *)(v8 + 32);
  *(_QWORD *)(v15 + 8) = v11;
  *v11 = v15;
  v11[1] = v8 + 32;
  *(_QWORD *)(v8 + 32) = v11;
  nc_free(v9);
  if ( *a3 )
    nc_free_node(*a3);
  *a3 = v11;
  return v11;
}

