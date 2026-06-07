// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_add_element
// Included functions: 2

// ======================================================
// Function: nc_add_element @ 0x22FD0
// ======================================================

__int64 __fastcall nc_add_element(_QWORD *ptr, __int64 a2, __int64 a3)
{
  __int64 v5; // rbx
  unsigned int v6; // eax
  int v7; // esi
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // r14
  __int64 v13; // rax
  __int64 v14; // rax
  int v15; // edx
  __int64 v16; // r15
  __int64 v17; // rax
  __int64 v18; // rbp
  int v19; // edx
  unsigned __int64 v20; // rsi
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // rdi
  unsigned __int64 v24; // rsi
  int v25; // edx
  int v26; // eax
  __int64 v27; // rdx
  __int64 v28; // rcx
  _QWORD *v29; // rax
  _QWORD *v30; // rbx
  _QWORD *v31; // rax
  __int64 v34[2]; // [rsp+10h] [rbp-68h] BYREF
  unsigned __int64 v35; // [rsp+20h] [rbp-58h] BYREF
  __int64 v36; // [rsp+28h] [rbp-50h]
  __int64 v37; // [rsp+30h] [rbp-48h]
  __int64 v38; // [rsp+38h] [rbp-40h]
  __int64 v39; // [rsp+40h] [rbp-38h]

  v5 = *(_QWORD *)(ptr[5] + 24LL);
  if ( v5 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  if ( v5 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  v6 = *((_DWORD *)ptr + 12);
  if ( *(_DWORD *)(a3 + 48) != v6 || v6 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_add_element");
  if ( *(_DWORD *)(a2 + 48) != 5 )
    nc_error("unsupported type for %s\n", (char)"nc_add_element");
  v7 = *(_DWORD *)(a2 + 80);
  v8 = *(unsigned int *)(a3 + 80);
  if ( (_DWORD)v8 != v7 + 1 )
    __assert_fail("w->n_dims == (x->n_dims + 1)", "libnc.c", 0x1ACAu, "nc_add_element");
  v9 = 0LL;
  while ( v9 != v7 )
  {
    ++v9;
    if ( *(_QWORD *)(a3 + 8 * v9 + 120) != *(_QWORD *)(a2 + 8 * v9 + 112) )
      __assert_fail("w->dims[i + 1] == x->dims[i]", "libnc.c", 0x1ACCu, "nc_add_element");
  }
  if ( v7 != *((_DWORD *)ptr + 20) )
LABEL_15:
    __assert_fail("same_dims(z, x)", "libnc.c", 0x1ACEu, "nc_add_element");
  if ( v7 > 0 )
  {
    if ( ptr[15] != *(_QWORD *)(a2 + 120) )
      goto LABEL_15;
    v10 = 1LL;
    while ( v7 > (int)v10 )
    {
      v11 = ptr[v10++ + 15];
      if ( v11 != *(_QWORD *)(a2 + 8 * v10 + 112) )
        goto LABEL_15;
    }
  }
  v12 = a3;
  if ( *(_DWORD *)(a3 + 16) != 1 )
  {
    v12 = nc_new_tensor_nz(v5, *(unsigned int *)(a3 + 48), v8, a3 + 120);
    nc_tensor_copy(v12, a3);
  }
  v13 = nc_dup_tensor(a2);
  v14 = nc_tensor_to_cpu_device(v13);
  v36 = 0LL;
  v15 = *(_DWORD *)(v14 + 80);
  v16 = v14;
  if ( v15 <= 1 )
  {
    v18 = 0LL;
  }
  else
  {
    v17 = 1LL;
    do
      *(&v35 + ++v17) = 0LL;
    while ( v15 > (int)v17 );
LABEL_26:
    v18 = v36;
  }
LABEL_27:
  if ( v18 != -1 )
  {
    v19 = *(_DWORD *)(v16 + 80);
    v20 = *(_QWORD *)(v16 + 56);
    if ( v19 <= 0 )
    {
      v21 = 0LL;
    }
    else
    {
      v21 = *(_QWORD *)(v16 + 88) * v18;
      if ( v19 != 1 )
      {
        v21 += *(_QWORD *)(v16 + 96) * v37;
        if ( v19 != 2 )
        {
          v21 += *(_QWORD *)(v16 + 104) * v38;
          if ( v19 != 3 )
          {
            v22 = v39;
            v23 = *(_QWORD *)(v16 + 112);
            goto LABEL_33;
          }
        }
      }
    }
    while ( 1 )
    {
      v24 = *(int *)(v20 + v21);
      if ( (v24 & 0x80000000) != 0LL || v24 >= *(_QWORD *)(v12 + 120) )
        __assert_fail("c >= 0 && c < y->dims[0]", "libnc.c", 0x1ADCu, "nc_add_element");
      v21 = *(unsigned int *)(v12 + 80);
      v22 = *(_QWORD *)(v12 + 56);
      v35 = v24;
      if ( (int)v21 <= 0 )
      {
        v20 = 0LL;
      }
      else
      {
        v20 = *(_QWORD *)(v12 + 88) * v24;
        if ( (_DWORD)v21 != 1 )
        {
          v20 += *(_QWORD *)(v12 + 96) * v18;
          if ( (_DWORD)v21 != 2 )
          {
            v20 += *(_QWORD *)(v12 + 104) * v37;
            if ( (_DWORD)v21 != 3 )
            {
              v23 = *(_QWORD *)(v12 + 112);
              if ( (_DWORD)v21 != 4 )
                goto LABEL_33;
              v20 += v23 * v38;
            }
          }
        }
      }
      v25 = *((_DWORD *)ptr + 20);
      v20 += v22;
      v23 = ptr[7];
      if ( v25 <= 0 )
      {
        v21 = 0LL;
LABEL_48:
        (*(void (__fastcall **)(__int64, unsigned __int64, _QWORD, unsigned __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v5 + 168))(
          v5,
          v20,
          0LL,
          v20,
          0LL,
          v23 + v21,
          0LL,
          1LL,
          1LL,
          *((unsigned int *)ptr + 12));
        v26 = *(_DWORD *)(v16 + 80);
        if ( v26 <= 0 )
        {
LABEL_53:
          v36 = -1LL;
          break;
        }
        v36 = ++v18;
        if ( v18 == *(_QWORD *)(v16 + 120) )
        {
          v27 = 1LL;
          while ( 1 )
          {
            *(&v35 + v27) = 0LL;
            if ( v26 <= (int)v27 )
              goto LABEL_53;
            v28 = *(&v35 + v27 + 1) + 1;
            *(&v35 + ++v27) = v28;
            if ( v28 != *(_QWORD *)(v16 + 8 * v27 + 112) )
              goto LABEL_26;
          }
        }
        goto LABEL_27;
      }
      v21 = ptr[11] * v18;
      if ( v25 == 1 )
        goto LABEL_48;
      v21 += ptr[12] * v37;
      if ( v25 == 2 )
        goto LABEL_48;
      v21 += ptr[13] * v38;
      if ( v25 == 3 )
        goto LABEL_48;
      v22 = v39;
      if ( v25 == 4 )
      {
        v21 += ptr[14] * v39;
        goto LABEL_48;
      }
LABEL_33:
      v21 += v23 * v22;
    }
  }
  nc_free_tensor((void *)v16);
  v34[0] = (__int64)ptr;
  v34[1] = a3;
  v29 = sub_17590(34, (__int64 *)(v12 + 24), (void **)(v12 + 32), v34);
  v30 = v29;
  if ( v29 )
  {
    *((_DWORD *)v29 + 10) = 1;
    v31 = (_QWORD *)nc_malloc(8uLL);
    v30[6] = v31;
    *v31 = nc_dup_tensor(a2);
  }
  nc_free_tensor(ptr);
  nc_free_tensor((void *)a2);
  if ( v12 != a3 )
    nc_free_tensor((void *)a3);
  return v12;
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

