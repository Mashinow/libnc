// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_slice_add
// Included functions: 3

// ======================================================
// Function: nc_slice_add @ 0x20D00
// ======================================================

_QWORD *__fastcall nc_slice_add(_QWORD *ptr, _QWORD *a2, unsigned int a3, __int64 a4)
{
  _QWORD *v6; // rbp
  void *v7; // r14
  _QWORD *v8; // rax
  __int64 v10[9]; // [rsp+10h] [rbp-48h] BYREF

  v6 = ptr;
  if ( *((_DWORD *)ptr + 4) != 1 )
  {
    v6 = (_QWORD *)nc_new_tensor_nz(
                     *(_QWORD *)(ptr[5] + 24LL),
                     *((unsigned int *)ptr + 12),
                     *((unsigned int *)ptr + 20),
                     ptr + 15);
    nc_tensor_copy(v6, ptr);
  }
  v7 = (void *)nc_slice_alias(v6, a3);
  sub_14AC0((__int64)v7, (__int64)v7, (__int64)a2);
  nc_free_tensor(v7);
  v10[0] = (__int64)ptr;
  v10[1] = (__int64)a2;
  v8 = sub_17590(16, v6 + 3, (void **)v6 + 4, v10);
  if ( v8 )
  {
    *((_DWORD *)v8 + 14) = a3;
    v8[8] = a4;
    v8[9] = a2[(int)a3 + 15] + a4;
  }
  nc_free_tensor(a2);
  if ( v6 != ptr )
    nc_free_tensor(ptr);
  return v6;
}

// ======================================================
// Function: sub_14AC0 @ 0x14AC0
// ======================================================

__int64 __fastcall sub_14AC0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // rdi
  unsigned int v7; // eax
  int v8; // edi
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rsi
  __int64 v17; // rdx
  int v18; // r11d
  __int64 v19; // rbx
  int v20; // eax
  __int64 v21; // rbx
  int v22; // ecx
  __int64 v23; // rbx
  int v24; // ecx
  __int64 v25; // rbx
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // r14
  __int64 *v29; // rbx
  __int64 v30; // r10
  __int64 result; // rax
  int v32; // eax
  __int64 v33; // r9
  int v34; // eax
  __int64 v35; // r9
  __int64 v36; // rcx
  __int64 v37; // rcx
  __int64 v38; // r14
  bool v39; // zf
  __int64 v40; // rdx
  int v41; // [rsp+Ch] [rbp-9Ch]
  __int64 v42; // [rsp+10h] [rbp-98h]
  int v43; // [rsp+20h] [rbp-88h]
  __int64 v44; // [rsp+30h] [rbp-78h]
  __int64 v45; // [rsp+38h] [rbp-70h]
  __int64 v46; // [rsp+40h] [rbp-68h]
  __int64 v47; // [rsp+48h] [rbp-60h]
  __int64 v48; // [rsp+50h] [rbp-58h] BYREF
  __int64 v49; // [rsp+58h] [rbp-50h]
  __int64 v50; // [rsp+60h] [rbp-48h]
  __int64 v51; // [rsp+68h] [rbp-40h]

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  v42 = v6;
  if ( v6 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  if ( v6 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  v7 = *(_DWORD *)(a2 + 48);
  if ( *(_DWORD *)(a3 + 48) != v7 || v7 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_add_internal");
  v8 = *(_DWORD *)(a1 + 80);
  if ( v8 != *(_DWORD *)(a3 + 80) )
LABEL_9:
    __assert_fail("same_dims(y, x2)", "libnc.c", 0x1698u, "nc_add_internal");
  if ( v8 <= 0 )
  {
LABEL_70:
    if ( v8 != *(_DWORD *)(a2 + 80) )
      goto LABEL_71;
    v46 = 1LL;
    v16 = 0LL;
    if ( v8 )
      goto LABEL_37;
    return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
             v42,
             *(_QWORD *)(a1 + 56),
             0LL,
             *(_QWORD *)(a2 + 56),
             0LL,
             *(_QWORD *)(a3 + 56),
             0LL,
             v46,
             1LL,
             *(unsigned int *)(a2 + 48));
  }
  v9 = *(_QWORD *)(a1 + 120);
  v45 = *(_QWORD *)(a3 + 120);
  if ( v45 != v9 )
    goto LABEL_9;
  v10 = 1LL;
  while ( v8 > (int)v10 )
  {
    v11 = *(_QWORD *)(a1 + 8 * v10++ + 120);
    if ( v11 != *(_QWORD *)(a3 + 8 * v10 + 112) )
      goto LABEL_9;
  }
  if ( v8 != *(_DWORD *)(a2 + 80) || (v12 = 1LL, v45 != *(_QWORD *)(a2 + 120)) )
LABEL_71:
    __assert_fail("same_dims(y, x1)", "libnc.c", 0x1699u, "nc_add_internal");
  while ( v8 > (int)v12 )
  {
    v13 = *(_QWORD *)(a1 + 8 * v12++ + 120);
    if ( v13 != *(_QWORD *)(a2 + 8 * v12 + 112) )
      goto LABEL_71;
  }
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) || !*(_BYTE *)(a3 + 73) )
  {
    v43 = 1;
    v16 = 0LL;
    v46 = 1LL;
    goto LABEL_38;
  }
  if ( v8 <= 1 )
  {
    v16 = 1LL;
  }
  else
  {
    if ( !*(_BYTE *)(a1 + 74) || !*(_BYTE *)(a2 + 74) || !*(_BYTE *)(a3 + 74) )
    {
      v16 = 1LL;
      goto LABEL_106;
    }
    v14 = *(_QWORD *)(a1 + 128) * v9;
    LODWORD(v45) = v14;
    if ( v8 == 2 )
    {
      v16 = 2LL;
    }
    else
    {
      if ( !*(_BYTE *)(a1 + 75) || !*(_BYTE *)(a2 + 75) || !*(_BYTE *)(a3 + 75) )
      {
        v16 = 2LL;
        goto LABEL_106;
      }
      v15 = *(_QWORD *)(a1 + 136) * v14;
      LODWORD(v45) = v15;
      if ( v8 != 3 )
      {
        if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 76) )
        {
          v16 = 4LL;
          v45 = *(_QWORD *)(a1 + 144) * v15;
          goto LABEL_36;
        }
        v16 = 3LL;
LABEL_106:
        v46 = (int)v45;
        goto LABEL_37;
      }
      v16 = 3LL;
    }
  }
LABEL_36:
  v46 = (int)v45;
  if ( v8 == (_DWORD)v16 )
    return (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
             v42,
             *(_QWORD *)(a1 + 56),
             0LL,
             *(_QWORD *)(a2 + 56),
             0LL,
             *(_QWORD *)(a3 + 56),
             0LL,
             v46,
             1LL,
             *(unsigned int *)(a2 + 48));
LABEL_37:
  v43 = v16 + 1;
  v45 = *(_QWORD *)(a1 + 8LL * (int)v16 + 120);
LABEL_38:
  v17 = v43;
  if ( v8 <= v43 )
    goto LABEL_59;
  v18 = v43;
  v17 = v43;
  if ( !*(_BYTE *)(a1 + v43 + 73) || !*(_BYTE *)(a2 + v43 + 73) || !*(_BYTE *)(a3 + v43 + 73) )
    goto LABEL_59;
  v19 = *(_QWORD *)(a1 + 8LL * v43 + 120) * v45;
  v20 = v43 + 1;
  v45 = v19;
  if ( v8 <= v43 + 1 )
    goto LABEL_102;
  v17 = v20;
  if ( !*(_BYTE *)(a1 + v20 + 73) || !*(_BYTE *)(a2 + v20 + 73) || !*(_BYTE *)(a3 + v20 + 73) )
    goto LABEL_100;
  v21 = *(_QWORD *)(a1 + 8LL * v20 + 120) * v19;
  v22 = v43 + 2;
  v45 = v21;
  if ( v8 <= v43 + 2 || !*(_BYTE *)(a1 + v22 + 73) || !*(_BYTE *)(a2 + v22 + 73) || !*(_BYTE *)(a3 + v22 + 73) )
  {
    v17 = v22;
    goto LABEL_99;
  }
  v23 = *(_QWORD *)(a1 + 8LL * v22 + 120) * v21;
  v24 = v43 + 3;
  v17 = v43 + 3;
  v45 = v23;
  if ( v8 <= v43 + 3 )
  {
LABEL_99:
    v20 = v17;
    goto LABEL_100;
  }
  if ( *(_BYTE *)(a1 + v24 + 73) && *(_BYTE *)(a2 + v24 + 73) && *(_BYTE *)(a3 + v24 + 73) )
  {
    v25 = *(_QWORD *)(a1 + 8LL * v24 + 120) * v23;
    v20 = v43 + 4;
    v45 = v25;
    if ( v8 > v43 + 4 )
    {
      v17 = v20;
      if ( *(_BYTE *)(a1 + v20 + 73) && *(_BYTE *)(a2 + v20 + 73) )
      {
        if ( *(_BYTE *)(a3 + v20 + 73) )
        {
          v43 += 5;
          v17 = v18 + 5;
          v45 = *(_QWORD *)(a1 + 8LL * v20 + 120) * v25;
          goto LABEL_59;
        }
        goto LABEL_102;
      }
LABEL_100:
      v43 = v20;
      goto LABEL_59;
    }
LABEL_102:
    v43 = v20;
    v17 = v20;
    goto LABEL_59;
  }
  v43 += 3;
LABEL_59:
  v26 = *(unsigned int *)(a2 + 48);
  v48 = 0LL;
  v41 = dword_30520[v26];
  if ( v8 <= 1 )
  {
    v28 = 0LL;
  }
  else
  {
    v27 = 1LL;
    do
      *(&v48 + v27++) = 0LL;
    while ( v8 > (int)v27 );
    v28 = v48;
  }
  v29 = &v48 + v17;
  v30 = v16 + 8;
  result = v17 + 12;
  v47 = v17 + 12;
  while ( v28 != -1 )
  {
    v32 = *(_DWORD *)(a3 + 80);
    if ( v32 <= 0 )
    {
      v33 = 0LL;
    }
    else
    {
      v33 = *(_QWORD *)(a3 + 88) * v28;
      if ( v32 != 1 )
      {
        v33 += *(_QWORD *)(a3 + 96) * v49;
        if ( v32 != 2 )
        {
          v33 += *(_QWORD *)(a3 + 104) * v50;
          if ( v32 != 3 )
          {
            if ( v32 != 4 )
              goto LABEL_70;
            v33 += *(_QWORD *)(a3 + 112) * v51;
          }
        }
      }
    }
    v34 = *(_DWORD *)(a2 + 80);
    v35 = *(_QWORD *)(a3 + 56) + v33;
    if ( v34 <= 0 )
    {
      v36 = 0LL;
    }
    else
    {
      v36 = *(_QWORD *)(a2 + 88) * v28;
      if ( v34 != 1 )
      {
        v36 += *(_QWORD *)(a2 + 96) * v49;
        if ( v34 != 2 )
        {
          v36 += *(_QWORD *)(a2 + 104) * v50;
          if ( v34 != 3 )
          {
            if ( v34 != 4 )
              goto LABEL_70;
            v36 += *(_QWORD *)(a2 + 112) * v51;
          }
        }
      }
    }
    v37 = *(_QWORD *)(a2 + 56) + v36;
    if ( v8 <= 0 )
    {
      v38 = 0LL;
    }
    else
    {
      v38 = *(_QWORD *)(a1 + 88) * v28;
      if ( v8 != 1 )
      {
        v38 += *(_QWORD *)(a1 + 96) * v49;
        if ( v8 != 2 )
        {
          v38 += *(_QWORD *)(a1 + 104) * v50;
          if ( v8 != 3 )
          {
            if ( v8 != 4 )
              goto LABEL_70;
            v38 += *(_QWORD *)(a1 + 112) * v51;
          }
        }
      }
    }
    v44 = v30;
    result = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64, _QWORD))(v42 + 168))(
               v42,
               v38 + *(_QWORD *)(a1 + 56),
               *(_QWORD *)(a1 + 8 * v30 + 24) >> v41,
               v37,
               *(_QWORD *)(a2 + 8 * v30 + 24) >> v41,
               v35,
               *(_QWORD *)(a3 + 8 * v30 + 24) >> v41,
               v46,
               v45,
               *(unsigned int *)(a2 + 48));
    v8 = *(_DWORD *)(a1 + 80);
    if ( v8 <= v43 )
      break;
    v30 = v44;
    result = *v29 + 1;
    v39 = result == *(_QWORD *)(a1 + 8 * v47 + 24);
    *v29 = result;
    if ( v39 )
    {
      result = 0LL;
      do
      {
        v29[result] = 0LL;
        if ( result == v8 - 1 - v43 )
          return result;
        v40 = v29[result + 1] + 1;
        v29[++result] = v40;
      }
      while ( v40 == *(_QWORD *)(a1 + 8LL * (v43 + 1) + 8 * result + 112) );
    }
    v28 = v48;
  }
  return result;
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

