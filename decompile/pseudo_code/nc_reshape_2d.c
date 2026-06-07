// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_reshape_2d
// Included functions: 2

// ======================================================
// Function: nc_reshape_2d @ 0x66A1BAF0
// ======================================================

_QWORD *__fastcall nc_reshape_2d(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rbp
  int v5; // ecx
  _QWORD *v6; // rax
  __int64 v7; // r9
  __int64 v8; // rcx
  __int64 v9; // r15
  __int64 v10; // r13
  __int64 v11; // r14
  unsigned __int64 v12; // rsi
  _QWORD *v13; // rbx
  __int64 v14; // rdx
  __int64 v15; // rax
  bool v16; // zf
  __int64 v17; // rax
  __int64 *v19; // rax
  __int64 v20; // rbp
  __int64 *v21; // r14
  _QWORD *v22; // rsi
  _QWORD *v23; // rax
  __int64 v24; // rdx
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 *v27; // rcx
  int v28; // eax
  __int64 v29; // rsi
  _QWORD *v30; // rax
  int v31; // edx
  __int64 v32; // rax
  int v33; // edx
  __int64 v34; // rax
  __int64 v35; // r14
  int v36; // eax
  int v37; // ecx
  __int64 v38; // rax
  int v39; // ecx
  __int64 v40; // rax
  __int64 v41; // rdx
  int v42; // r8d
  __int64 v43; // rax
  __int64 v44; // rdx
  int v45; // r10d
  __int64 v46; // rax
  int v47; // edx
  __int64 v48; // rax
  int v49; // eax
  __int64 v50; // rax
  __int64 v51; // rdx
  int v52; // r8d
  __int64 v53; // rax
  __int64 v54; // rdx
  int v55; // [rsp+3Ch] [rbp-9Ch]
  __int64 v56; // [rsp+40h] [rbp-98h] BYREF
  __int64 v57; // [rsp+48h] [rbp-90h]
  __int64 v58; // [rsp+50h] [rbp-88h] BYREF
  __int64 v59; // [rsp+58h] [rbp-80h]
  __int64 v60; // [rsp+60h] [rbp-78h]
  __int64 v61; // [rsp+68h] [rbp-70h]
  __int64 v62; // [rsp+70h] [rbp-68h] BYREF
  __int64 v63; // [rsp+78h] [rbp-60h]
  __int64 v64; // [rsp+80h] [rbp-58h]
  __int64 v65; // [rsp+88h] [rbp-50h]

  v3 = *(_QWORD *)(a1 + 40);
  v5 = *(_DWORD *)(a1 + 80);
  v56 = a2;
  v57 = a3;
  if ( v5 <= 0 )
  {
LABEL_37:
    v8 = 1i64;
  }
  else
  {
    v6 = (_QWORD *)(a1 + 120);
    v7 = a1 + 8i64 * (unsigned int)(v5 - 1) + 128;
    v8 = 1i64;
    do
      v8 *= *v6++;
    while ( (_QWORD *)v7 != v6 );
  }
  if ( v8 != a2 * a3 )
    sub_66A16930("reshape", a1, 0i64);
  if ( !*(_BYTE *)(a1 + 72) )
  {
    v29 = *(_QWORD *)(v3 + 24);
    v30 = nc_new_tensor_nz(v29, *(_DWORD *)(a1 + 48), 2, (__int64)&v56);
    v13 = v30;
    if ( *(_BYTE *)(a1 + 72) && *((_BYTE *)v30 + 72) )
      goto LABEL_63;
    if ( *(_QWORD *)(a1 + 120) != v30[15] )
    {
      v31 = *(_DWORD *)(a1 + 80);
      v32 = 1i64;
      v62 = 0i64;
      if ( v31 > 1 )
      {
        do
          *(&v62 + v32++) = 0i64;
        while ( v31 > (int)v32 );
      }
      v33 = *((_DWORD *)v13 + 20);
      v34 = 1i64;
      v35 = 0i64;
      v58 = 0i64;
      if ( v33 > 1 )
      {
        do
          *(&v58 + v34++) = 0i64;
        while ( v33 > (int)v34 );
        v35 = v58;
      }
      v3 = -1i64;
      while ( 1 )
      {
LABEL_31:
        if ( v35 == -1 )
          goto LABEL_8;
        v36 = *((_DWORD *)v13 + 20);
        a3 = v13[7];
        if ( v36 <= 0 )
        {
          a2 = 0i64;
        }
        else
        {
          a2 = v13[11] * v35;
          if ( v36 != 1 )
          {
            a2 += v13[12] * v59;
            if ( v36 != 2 )
            {
              a2 += v13[13] * v60;
              if ( v36 != 3 )
              {
                if ( v36 != 4 )
                  goto LABEL_37;
                a2 += v13[14] * v61;
              }
            }
          }
        }
        v37 = *(_DWORD *)(a1 + 80);
        a2 += a3;
        if ( v37 <= 0 )
        {
          v38 = 0i64;
        }
        else
        {
          v38 = *(_QWORD *)(a1 + 88) * v62;
          if ( v37 != 1 )
          {
            v38 += *(_QWORD *)(a1 + 96) * v63;
            if ( v37 != 2 )
            {
              v38 += *(_QWORD *)(a1 + 104) * v64;
              if ( v37 != 3 )
              {
                a3 = v65;
                if ( v37 != 4 )
                  goto LABEL_37;
                v38 += *(_QWORD *)(a1 + 112) * v65;
              }
            }
          }
        }
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v29 + 64))(
          v29,
          a2,
          *(_QWORD *)(a1 + 56) + v38,
          nc_type_size_table[*((unsigned int *)v13 + 12)]);
        v39 = *(_DWORD *)(a1 + 80);
        if ( v39 <= 0 )
          goto LABEL_50;
        if ( *(_QWORD *)(a1 + 120) == ++v62 )
          break;
LABEL_51:
        v42 = *((_DWORD *)v13 + 20);
        if ( v42 <= 0 )
          goto LABEL_56;
        v58 = ++v35;
        if ( v35 == v13[15] )
        {
          v43 = 1i64;
          while ( 1 )
          {
            *(&v58 + v43 - 1) = 0i64;
            if ( v42 <= (int)v43 )
              goto LABEL_56;
            v44 = *(&v58 + v43) + 1;
            *(&v58 + v43++) = v44;
            if ( v44 != v13[v43 + 14] )
            {
              v35 = v58;
              goto LABEL_31;
            }
          }
        }
      }
      v40 = 1i64;
      while ( 1 )
      {
        *(&v62 + v40 - 1) = 0i64;
        if ( v39 <= (int)v40 )
          break;
        v41 = *(&v62 + v40) + 1;
        *(&v62 + v40++) = v41;
        if ( v41 != *(_QWORD *)(a1 + 8 * v40 + 112) )
          goto LABEL_51;
      }
LABEL_50:
      v62 = -1i64;
      goto LABEL_51;
    }
    v45 = *(_DWORD *)(a1 + 80);
    if ( v45 <= 1 || *(_BYTE *)(a1 + 74) && (v45 == 2 || *(_BYTE *)(a1 + 75) && (v45 == 3 || *(_BYTE *)(a1 + 76))) )
    {
LABEL_63:
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD))(v29 + 64))(
        v29,
        v30[7],
        *(_QWORD *)(a1 + 56),
        *(_QWORD *)(v30[5] + 48i64));
      goto LABEL_8;
    }
    v62 = 0i64;
    v46 = 1i64;
    do
      *(&v62 + v46++) = 0i64;
    while ( v45 > (int)v46 );
    v58 = 0i64;
    v47 = *((_DWORD *)v13 + 20);
    if ( v47 <= 1 )
    {
      a2 = 0i64;
    }
    else
    {
      v48 = 1i64;
      do
        *(&v58 + v48++) = 0i64;
      while ( v47 > (int)v48 );
      a2 = v58;
    }
    v3 = -1i64;
    while ( 1 )
    {
      if ( a2 == -1 )
        goto LABEL_8;
      if ( v45 <= 0 )
      {
        a3 = 0i64;
      }
      else
      {
        a3 = *(_QWORD *)(a1 + 88) * v62;
        if ( v45 != 1 )
        {
          a3 += *(_QWORD *)(a1 + 96) * v63;
          if ( v45 != 2 )
          {
            a3 += *(_QWORD *)(a1 + 104) * v64;
            if ( v45 != 3 )
            {
              if ( v45 != 4 )
                goto LABEL_37;
              a3 += *(_QWORD *)(a1 + 112) * v65;
            }
          }
        }
      }
      v49 = *((_DWORD *)v13 + 20);
      a3 += *(_QWORD *)(a1 + 56);
      if ( v49 <= 0 )
      {
        a2 = 0i64;
      }
      else
      {
        a2 *= v13[11];
        if ( v49 != 1 )
        {
          a2 += v13[12] * v59;
          if ( v49 != 2 )
          {
            a2 += v13[13] * v60;
            if ( v49 != 3 )
            {
              if ( v49 != 4 )
                goto LABEL_37;
              a2 += v13[14] * v61;
            }
          }
        }
      }
      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v29 + 64))(
        v29,
        v13[7] + a2,
        a3,
        *(_QWORD *)(a1 + 120) * nc_type_size_table[*(unsigned int *)(a1 + 48)]);
      v45 = *(_DWORD *)(a1 + 80);
      if ( v45 <= 1 )
        goto LABEL_93;
      v50 = 2i64;
      if ( ++v63 == *(_QWORD *)(a1 + 128) )
        break;
LABEL_94:
      v52 = *((_DWORD *)v13 + 20);
      if ( v52 <= 1 )
        goto LABEL_56;
      v53 = 2i64;
      if ( ++v59 == v13[16] )
      {
        while ( 1 )
        {
          *(&v58 + v53 - 1) = 0i64;
          if ( v52 <= (int)v53 )
            break;
          v54 = *(&v58 + v53) + 1;
          *(&v58 + v53++) = v54;
          if ( v54 != v13[v53 + 14] )
            goto LABEL_101;
        }
LABEL_56:
        v58 = -1i64;
        goto LABEL_8;
      }
LABEL_101:
      a2 = v58;
    }
    while ( 1 )
    {
      *(&v62 + v50 - 1) = 0i64;
      if ( v45 <= (int)v50 )
        break;
      v51 = *(&v62 + v50) + 1;
      *(&v62 + v50++) = v51;
      if ( v51 != *(_QWORD *)(a1 + 8 * v50 + 112) )
        goto LABEL_94;
    }
LABEL_93:
    v62 = -1i64;
    goto LABEL_94;
  }
  v9 = *(_QWORD *)(a1 + 56) - *(_QWORD *)(v3 + 40);
  v10 = nc_type_size_table[*(unsigned int *)(a1 + 48)];
  v11 = *(_QWORD *)(a1 + 24);
  v55 = *(_DWORD *)(a1 + 48);
  v12 = v10 * a2;
  v13 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v13 )
  {
    MEMORY[0x18] = v11;
    BUG();
  }
  memset(v13, 0, 0x98ui64);
  v13[3] = v11;
  *((_DWORD *)v13 + 4) = 1;
  v14 = v57;
  v15 = v56;
  *((_DWORD *)v13 + 12) = v55;
  *((_DWORD *)v13 + 20) = 2;
  ++*(_DWORD *)(v3 + 16);
  v16 = nc_type_size_table[v55] == v10;
  v13[16] = v14;
  LODWORD(v14) = dword_66A375E0[v55];
  v13[15] = v15;
  v13[5] = v3;
  v13[8] = v12 >> v14;
  *((_BYTE *)v13 + 73) = v16;
  v13[11] = v10;
  v13[12] = v12;
  LOBYTE(v15) = v10 * v15 == v12;
  *((_BYTE *)v13 + 74) = v15;
  *((_BYTE *)v13 + 72) = v15 & v16;
  v13[7] = *(_QWORD *)(v3 + 40) + v9;
  v17 = *(_QWORD *)(v11 + 16);
  *(_QWORD *)(v17 + 8) = v13;
  *v13 = v17;
  v13[1] = v11 + 16;
  *(_QWORD *)(v11 + 16) = v13;
LABEL_8:
  if ( *(_QWORD *)(a1 + 32) )
  {
    v19 = (__int64 *)aligned_malloc(8ui64, 0x40ui64);
    v20 = v13[3];
    v21 = v19;
    *v19 = *(_QWORD *)(a1 + 32);
    v22 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v22 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v22, 0, 0x80ui64);
    *((_DWORD *)v22 + 4) = 1;
    *((_DWORD *)v22 + 5) = 3;
    *((_DWORD *)v22 + 6) = 1;
    v23 = aligned_malloc(8ui64, 0x40ui64);
    v24 = *v21;
    v22[4] = v23;
    if ( v24 )
    {
      ++*(_DWORD *)(v24 + 16);
      *v23 = v24;
    }
    else
    {
      *v23 = 0i64;
    }
    v25 = *(_QWORD *)(v20 + 72);
    *(_QWORD *)(v20 + 72) = v25 + 1;
    v22[12] = v25;
    v26 = *(_QWORD *)(v20 + 32);
    *(_QWORD *)(v26 + 8) = v22;
    *v22 = v26;
    v22[1] = v20 + 32;
    *(_QWORD *)(v20 + 32) = v22;
    _aligned_free(v21);
    v27 = (__int64 *)v13[4];
    if ( v27 )
      nc_free_node(v27);
    v28 = *(_DWORD *)(a1 + 80);
    v13[4] = v22;
    *((_DWORD *)v22 + 14) = v28;
    if ( v28 > 0 )
    {
      v22[8] = *(_QWORD *)(a1 + 120);
      if ( v28 != 1 )
      {
        v22[9] = *(_QWORD *)(a1 + 128);
        if ( v28 != 2 )
        {
          v22[10] = *(_QWORD *)(a1 + 136);
          if ( v28 != 3 )
            v22[11] = *(_QWORD *)(a1 + 144);
        }
      }
    }
  }
  nc_free_tensor((_DWORD *)a1);
  return v13;
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

