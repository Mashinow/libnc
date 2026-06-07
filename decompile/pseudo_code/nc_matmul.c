// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_matmul
// Included functions: 5

// ======================================================
// Function: nc_matmul @ 0x66A25C90
// ======================================================

_QWORD *__fastcall nc_matmul(__int64 a1, __int64 a2)
{
  __int64 v2; // r12
  unsigned __int64 v3; // r13
  __int64 v4; // r14
  __int64 v5; // r15
  unsigned int v6; // eax
  unsigned int v7; // edx
  int v8; // r8d
  __int64 v9; // rax
  __int64 v10; // rcx
  _QWORD *v11; // rsi
  int v12; // eax
  __int64 v13; // r9
  int v14; // edx
  __int64 v15; // rax
  __int64 v16; // r10
  __int64 v17; // rdx
  int v18; // ebx
  unsigned __int64 v19; // r8
  int v20; // ecx
  __int64 v21; // rax
  __int64 v22; // r8
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rdi
  int v25; // ecx
  __int64 v26; // r11
  unsigned __int64 v27; // rcx
  int v28; // eax
  __int64 *v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // r8
  __int64 v32; // rax
  __int64 v33; // rdx
  _DWORD *v34; // rax
  __int64 v36; // rdx
  __int64 v37; // rdx
  unsigned __int64 v38; // rdi
  unsigned __int64 v39; // rbp
  __int64 v40; // rsi
  unsigned __int64 v41; // rbx
  int v42; // edx
  __int64 *v43; // rsi
  __int64 v44; // r12
  _QWORD *v45; // rbx
  _QWORD *v46; // rax
  __int64 v47; // rdx
  __int64 v48; // rdx
  __int64 v49; // rdx
  __int64 v50; // rax
  __int64 v51; // rax
  _QWORD *v52; // rax
  __int64 *v53; // rcx
  _QWORD *v54; // rax
  __int64 v55; // [rsp+20h] [rbp-188h]
  __int64 v56; // [rsp+30h] [rbp-178h]
  __int64 v57; // [rsp+38h] [rbp-170h]
  __int64 v58; // [rsp+40h] [rbp-168h]
  __int64 v59; // [rsp+48h] [rbp-160h]
  __int64 v60; // [rsp+50h] [rbp-158h]
  __int64 v61; // [rsp+58h] [rbp-150h]
  __int64 v62; // [rsp+60h] [rbp-148h]
  __int64 v63; // [rsp+68h] [rbp-140h]
  __int64 v64; // [rsp+70h] [rbp-138h]
  __int64 v65; // [rsp+78h] [rbp-130h]
  __int64 v66; // [rsp+80h] [rbp-128h]
  __int64 v67; // [rsp+88h] [rbp-120h]
  __int64 v68; // [rsp+90h] [rbp-118h]
  void (__fastcall *v69)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int); // [rsp+90h] [rbp-118h]
  __int64 v70; // [rsp+98h] [rbp-110h]
  __int64 v71; // [rsp+98h] [rbp-110h]
  __int64 v72; // [rsp+B0h] [rbp-F8h]
  _QWORD *v73; // [rsp+B8h] [rbp-F0h]
  __int64 v74; // [rsp+C0h] [rbp-E8h]
  __int64 v75; // [rsp+C8h] [rbp-E0h]
  __int64 v76; // [rsp+D0h] [rbp-D8h]
  __int64 v77; // [rsp+D8h] [rbp-D0h]
  __int64 v78; // [rsp+E0h] [rbp-C8h]
  __int64 v79; // [rsp+E8h] [rbp-C0h]
  int v80; // [rsp+F0h] [rbp-B8h]
  int v81; // [rsp+F4h] [rbp-B4h]
  __int64 v82; // [rsp+F8h] [rbp-B0h]
  _QWORD *v83; // [rsp+108h] [rbp-A0h]
  int v84; // [rsp+11Ch] [rbp-8Ch] BYREF
  __int64 v85; // [rsp+120h] [rbp-88h] BYREF
  __int64 v86; // [rsp+128h] [rbp-80h]
  __int64 v87; // [rsp+130h] [rbp-78h]
  __int64 v88; // [rsp+138h] [rbp-70h]
  __int64 v89; // [rsp+140h] [rbp-68h] BYREF
  __int64 v90; // [rsp+148h] [rbp-60h]
  __int64 v91; // [rsp+150h] [rbp-58h]
  __int64 v92; // [rsp+158h] [rbp-50h]

  v82 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( v82 != *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v6 = *(_DWORD *)(a1 + 48);
  if ( v6 > 2 )
  {
    printf("unsupported type for %s\n", "nc_matmul_add");
    abort();
  }
  if ( v6 == 2 )
  {
    v7 = *(_DWORD *)(a2 + 48);
    if ( !v7 )
      goto LABEL_5;
LABEL_107:
    nc_error("unsupported type for %s\n", "nc_matmul_add");
  }
  v7 = *(_DWORD *)(a2 + 48);
  if ( v6 != v7 )
    goto LABEL_107;
LABEL_5:
  v8 = *(_DWORD *)(a1 + 80);
  if ( *(_DWORD *)(a2 + 80) != v8 || v8 <= 1 || *(_QWORD *)(a1 + 128) != *(_QWORD *)(a2 + 120) )
    goto LABEL_115;
  if ( v8 != 2 )
  {
    if ( *(_QWORD *)(a2 + 136) == *(_QWORD *)(a1 + 136) )
    {
      v9 = 3i64;
      while ( v8 > (int)v9 )
      {
        v10 = *(_QWORD *)(a1 + 8 * v9++ + 120);
        if ( v10 != *(_QWORD *)(a2 + 8 * v9 + 112) )
          goto LABEL_115;
      }
      v87 = *(_QWORD *)(a2 + 136);
      v85 = *(_QWORD *)(a1 + 120);
      v86 = *(_QWORD *)(a2 + 128);
      if ( v8 != 3 )
        v88 = *(_QWORD *)(a1 + 144);
      goto LABEL_15;
    }
LABEL_115:
    sub_66A16930("matmul", a1, a2);
  }
  v85 = *(_QWORD *)(a1 + 120);
  v86 = *(_QWORD *)(a2 + 128);
LABEL_15:
  v11 = nc_new_tensor_nz(v82, v7, v8, (__int64)&v85);
  v83 = v11;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))(v82 + 104))(
    v82,
    v11[7],
    0i64,
    *(_QWORD *)(v11[5] + 48i64),
    0);
  v73 = v11;
  if ( *((_DWORD *)v11 + 4) != 1 )
  {
    v73 = nc_new_tensor_nz(
            *(_QWORD *)(v11[5] + 24i64),
            *((_DWORD *)v11 + 12),
            *((_DWORD *)v11 + 20),
            (__int64)(v11 + 15));
    nc_tensor_copy((__int64)v73, (__int64)v11);
  }
  v12 = sub_66A05420(
          &v84,
          2,
          (__int64)v73,
          a2,
          a1,
          0i64,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v70);
  v89 = 0i64;
  v80 = v12;
  v81 = dword_66A375E0[*(unsigned int *)(a1 + 48)];
  v14 = *(_DWORD *)(a2 + 80);
  if ( v14 <= 1 )
  {
    v16 = 0i64;
  }
  else
  {
    v15 = 1i64;
    do
      *(&v89 + v15++) = 0i64;
    while ( v14 > (int)v15 );
    v16 = v89;
  }
  v17 = v16;
  while ( 2 )
  {
    if ( v17 == -1 )
      goto LABEL_50;
    v18 = *(_DWORD *)(a1 + 48);
    if ( v18 != 2 )
    {
      v69 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))(v82 + 440);
      v2 = *(_QWORD *)(a2 + 120);
      v3 = v73[16];
      v4 = v73[15];
      v19 = *(_QWORD *)(a2 + 104);
      v5 = v19 >> v81;
      v71 = *(_QWORD *)(a2 + 64);
      v20 = *(_DWORD *)(a2 + 80);
      v16 = *(_QWORD *)(a2 + 56);
      if ( v20 <= 0 )
      {
        v21 = 0i64;
      }
      else
      {
        v21 = *(_QWORD *)(a2 + 88) * v17;
        if ( v20 != 1 )
        {
          v21 += *(_QWORD *)(a2 + 96) * v90;
          if ( v20 != 2 )
          {
            v21 += v91 * v19;
            if ( v20 != 3 )
            {
              v22 = v92;
              v13 = *(_QWORD *)(a2 + 112);
              goto LABEL_29;
            }
          }
        }
      }
      goto LABEL_30;
    }
    v77 = v73[7];
    v21 = *((unsigned int *)v73 + 20);
    if ( (int)v21 <= 0 )
    {
      v76 = 0i64;
LABEL_63:
      v78 = *(_QWORD *)(a1 + 56);
      v21 = *(unsigned int *)(a1 + 80);
      if ( (int)v21 <= 0 )
      {
        v75 = 0i64;
      }
      else
      {
        v75 = *(_QWORD *)(a1 + 88) * v17;
        if ( (_DWORD)v21 != 1 )
        {
          v75 = *(_QWORD *)(a1 + 96) * v90 + *(_QWORD *)(a1 + 88) * v17;
          if ( (_DWORD)v21 != 2 )
          {
            v75 = *(_QWORD *)(a1 + 104) * v91 + *(_QWORD *)(a1 + 96) * v90 + *(_QWORD *)(a1 + 88) * v17;
            if ( (_DWORD)v21 != 3 )
            {
              v22 = *(_QWORD *)(a1 + 112);
              if ( (_DWORD)v21 != 4 )
                goto LABEL_29;
              v75 += v22 * v92;
            }
          }
        }
      }
      v79 = *(_QWORD *)(a2 + 56);
      v22 = *(unsigned int *)(a2 + 80);
      if ( (int)v22 <= 0 )
      {
        v74 = 0i64;
      }
      else
      {
        v36 = *(_QWORD *)(a2 + 88) * v17;
        v74 = v36;
        if ( (_DWORD)v22 != 1 )
        {
          v37 = *(_QWORD *)(a2 + 96) * v90 + v36;
          v74 = v37;
          if ( (_DWORD)v22 != 2 )
          {
            v74 = *(_QWORD *)(a2 + 104) * v91 + v37;
            if ( (_DWORD)v22 != 3 )
            {
              v21 = v92;
              v17 = *(_QWORD *)(a2 + 112);
              if ( (_DWORD)v22 != 4 )
                goto LABEL_29;
              v74 += v17 * v92;
            }
          }
        }
      }
      if ( v80 > 0 )
      {
        v72 = 0i64;
        do
        {
          v3 = *(_QWORD *)(a2 + 120);
          v2 = *(_QWORD *)(a2 + 64);
          v38 = v73[16];
          v39 = v73[15];
          v69 = (void (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))v73[8];
          v16 = v74 + v72 * (*(_QWORD *)(a2 + 104) & 0xFFFFFFFFFFFFFFFCui64);
          v40 = *(_QWORD *)(a1 + 64);
          v71 = v77 + v76 + v72 * (v73[13] & 0xFFFFFFFFFFFFFFFCui64);
          if ( v3 )
          {
            v5 = v78 + v75 + v72 * (*(_QWORD *)(a1 + 104) & 0xFFFFFFFFFFFFFFFEui64);
            v41 = 0i64;
            v4 = v79 + v16;
            do
            {
              v55 = v4;
              v42 = v3 - v41;
              if ( (int)v3 - (int)v41 > 256 )
                v42 = 256;
              v41 += 256i64;
              v4 += 1024i64;
              mat_mul1_f16(v71, (__int64)v69, v5, v40, v55, v2, v39, v38, v42);
              v5 += v40 << 9;
            }
            while ( v3 > v41 );
          }
          ++v72;
        }
        while ( v80 > (int)v72 );
        goto LABEL_43;
      }
      goto LABEL_44;
    }
    v76 = v73[11] * v17;
    if ( (_DWORD)v21 == 1 )
      goto LABEL_63;
    v76 = v73[12] * v90 + v73[11] * v17;
    if ( (_DWORD)v21 == 2 )
      goto LABEL_63;
    v76 = v73[13] * v91 + v73[12] * v90 + v73[11] * v17;
    if ( (_DWORD)v21 == 3 )
      goto LABEL_63;
    v22 = v73[14];
    if ( (_DWORD)v21 == 4 )
    {
      v76 += v22 * v92;
      goto LABEL_63;
    }
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_29:
        v21 += v13 * v22;
LABEL_30:
        v16 += v21;
        v23 = *(_QWORD *)(a1 + 104);
        v24 = v23 >> v81;
        v25 = *(_DWORD *)(a1 + 80);
        if ( v25 <= 0 )
        {
          v21 = 0i64;
          break;
        }
        v21 = *(_QWORD *)(a1 + 88) * v17;
        if ( v25 == 1 )
          break;
        v21 += *(_QWORD *)(a1 + 96) * v90;
        if ( v25 == 2 )
          break;
        v21 += v91 * v23;
        if ( v25 == 3 )
          break;
        v22 = v92;
        v13 = *(_QWORD *)(a1 + 112);
        if ( v25 == 4 )
        {
          v21 += v13 * v92;
          break;
        }
      }
      v26 = v21 + *(_QWORD *)(a1 + 56);
      v27 = v73[13];
      v13 = v27 >> v81;
      v22 = (__int64)v73;
      v21 = *((unsigned int *)v73 + 20);
      if ( (int)v21 <= 0 )
        break;
      v17 *= v73[11];
      if ( (_DWORD)v21 == 1 )
        goto LABEL_42;
      v17 += v73[12] * v90;
      if ( (_DWORD)v21 == 2 )
        goto LABEL_42;
      v17 += v91 * v27;
      if ( (_DWORD)v21 == 3 )
        goto LABEL_42;
      if ( (_DWORD)v21 == 4 )
      {
        v17 += v73[14] * v92;
        goto LABEL_42;
      }
    }
    v17 = 0i64;
LABEL_42:
    v69(v82, v73[7] + v17, v73[8], v13, v26, *(_QWORD *)(a1 + 64), v24, v16, v71, v5, 0, 0, v4, v3, v2, v80, v18);
LABEL_43:
    LODWORD(v22) = *(_DWORD *)(a2 + 80);
LABEL_44:
    v28 = v84;
    if ( v84 < (int)v22 )
    {
      v13 = v84;
      v29 = &v89 + v84;
      v30 = *v29 + 1;
      *v29 = v30;
      if ( v30 == *(_QWORD *)(a2 + 8i64 * v28 + 120) )
      {
        v13 = a2 + 8i64 * (v28 + 1);
        v31 = (unsigned int)(~v28 + v22);
        v32 = 0i64;
        do
        {
          v29[v32] = 0i64;
          if ( v32 == v31 )
            goto LABEL_49;
          v33 = v29[v32 + 1] + 1;
          v29[++v32] = v33;
        }
        while ( v33 == *(_QWORD *)(v13 + 8 * v32 + 112) );
      }
      v17 = v89;
      continue;
    }
    break;
  }
LABEL_49:
  v89 = -1i64;
LABEL_50:
  if ( *(_QWORD *)(a1 + 32) || *(_QWORD *)(a2 + 32) || (v34 = v83, v83[4]) )
  {
    v43 = (__int64 *)aligned_malloc(0x18ui64, 0x40ui64);
    *v43 = *(_QWORD *)(a1 + 32);
    v43[1] = *(_QWORD *)(a2 + 32);
    v43[2] = v83[4];
    v44 = v73[3];
    v45 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( !v45 )
    {
      MEMORY[0x10] = 0;
      BUG();
    }
    memset(v45, 0, 0x80ui64);
    *((_DWORD *)v45 + 4) = 1;
    *((_DWORD *)v45 + 5) = 30;
    *((_DWORD *)v45 + 6) = 3;
    v46 = aligned_malloc(0x18ui64, 0x40ui64);
    v47 = *v43;
    v45[4] = v46;
    if ( v47 )
    {
      ++*(_DWORD *)(v47 + 16);
      *v46 = v47;
      v48 = v43[1];
      if ( v48 )
      {
LABEL_90:
        ++*(_DWORD *)(v48 + 16);
        v46[1] = v48;
LABEL_91:
        v49 = v43[2];
        if ( v49 )
        {
          ++*(_DWORD *)(v49 + 16);
          v46[2] = v49;
        }
        else
        {
          v46[2] = 0i64;
        }
        v50 = *(_QWORD *)(v44 + 72);
        *(_QWORD *)(v44 + 72) = v50 + 1;
        v45[12] = v50;
        v51 = *(_QWORD *)(v44 + 32);
        *(_QWORD *)(v51 + 8) = v45;
        *v45 = v51;
        v45[1] = v44 + 32;
        *(_QWORD *)(v44 + 32) = v45;
        _aligned_free(v43);
        v52 = v73;
        v53 = (__int64 *)v73[4];
        if ( v53 )
        {
          nc_free_node(v53);
          v52 = v73;
        }
        v52[4] = v45;
        *((_DWORD *)v45 + 10) = 2;
        v54 = aligned_malloc(0x10ui64, 0x40ui64);
        if ( v54 )
        {
          *v54 = 0i64;
          v54[1] = 0i64;
        }
        v45[6] = v54;
        if ( *(_QWORD *)(a1 + 32) )
        {
          ++*(_DWORD *)(a2 + 16);
          v54[1] = a2;
        }
        if ( *(_QWORD *)(a2 + 32) )
        {
          ++*(_DWORD *)(a1 + 16);
          *v54 = a1;
        }
        *((_DWORD *)v45 + 14) = 0;
        v34 = v83;
        *((_DWORD *)v45 + 15) = 0;
        goto LABEL_53;
      }
    }
    else
    {
      *v46 = 0i64;
      v48 = v43[1];
      if ( v48 )
        goto LABEL_90;
    }
    v46[1] = 0i64;
    goto LABEL_91;
  }
LABEL_53:
  if ( v73 != (_QWORD *)v34 )
    nc_free_tensor(v34);
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v73;
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

// ======================================================
// Function: sub_66A05420 @ 0x66A05420
// ======================================================

__int64 __fastcall sub_66A05420(
        _DWORD *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20)
{
  int v20; // eax
  __int64 v21; // r9
  __int64 result; // rax
  int v23; // r10d
  unsigned __int64 v24; // [rsp+58h] [rbp-F0h]
  int v25; // [rsp+6Ch] [rbp-DCh]
  __int64 v26; // [rsp+80h] [rbp-C8h]
  __int64 v27; // [rsp+88h] [rbp-C0h]
  __int64 v28; // [rsp+90h] [rbp-B8h]
  __int64 v29; // [rsp+98h] [rbp-B0h]
  __int64 v30; // [rsp+A0h] [rbp-A8h]
  __int64 v31; // [rsp+A8h] [rbp-A0h]
  __int64 v32; // [rsp+B0h] [rbp-98h]
  __int64 v33; // [rsp+B8h] [rbp-90h]
  __int64 v34; // [rsp+C0h] [rbp-88h]
  __int64 v35; // [rsp+C8h] [rbp-80h]
  __int64 v36; // [rsp+D0h] [rbp-78h]
  __int64 v37; // [rsp+D8h] [rbp-70h]
  __int64 v38; // [rsp+E0h] [rbp-68h]
  __int64 v39; // [rsp+E8h] [rbp-60h]
  __int64 v40; // [rsp+F0h] [rbp-58h]
  __int64 v41; // [rsp+F8h] [rbp-50h]

  if ( a4 )
  {
    v26 = a4;
    if ( !a5 )
    {
      v25 = 1;
      goto LABEL_20;
    }
    v27 = a5;
    if ( !a6 )
    {
      v25 = 2;
      goto LABEL_20;
    }
    v28 = a6;
    if ( !a7 )
    {
      v25 = 3;
      goto LABEL_20;
    }
    v29 = a7;
    if ( !a8 )
    {
      v25 = 4;
      goto LABEL_20;
    }
    v30 = a8;
    if ( !a9 )
    {
      v25 = 5;
      goto LABEL_20;
    }
    v31 = a9;
    if ( !a10 )
    {
      v25 = 6;
      goto LABEL_20;
    }
    v32 = a10;
    if ( !a11 )
    {
      v25 = 7;
      goto LABEL_20;
    }
    v33 = a11;
    if ( !a12 )
    {
      v25 = 8;
      goto LABEL_20;
    }
    v34 = a12;
    if ( !a13 )
    {
      v25 = 9;
      goto LABEL_20;
    }
    v35 = a13;
    if ( !a14 )
    {
      v25 = 10;
      goto LABEL_20;
    }
    v36 = a14;
    if ( !a15 )
    {
      v25 = 11;
      goto LABEL_20;
    }
    v37 = a15;
    if ( !a16 )
    {
      v25 = 12;
      goto LABEL_20;
    }
    v38 = a16;
    if ( !a17 )
    {
      v25 = 13;
      goto LABEL_20;
    }
    v39 = a17;
    if ( !a18 )
    {
      v25 = 14;
      goto LABEL_20;
    }
    v40 = a18;
    if ( !a19 )
    {
      v25 = 15;
      goto LABEL_20;
    }
    v41 = a19;
    if ( !a20 )
    {
      v25 = 16;
      goto LABEL_20;
    }
    sub_66A33D40("count < countof(tab)", "libnc.c", 4653);
  }
  v25 = 0;
LABEL_20:
  v20 = *(_DWORD *)(a3 + 80);
  if ( a2 < v20 && (v21 = a2, *(_BYTE *)(a3 + a2 + 73)) )
  {
    v24 = a2 + (unsigned __int64)(unsigned int)(v20 - 1 - a2);
    result = 1i64;
    do
    {
      v23 = v21;
      if ( v25
        && (!*(_BYTE *)(v26 + v21 + 73)
         || v25 != 1
         && (!*(_BYTE *)(v27 + v21 + 73)
          || v25 != 2
          && (!*(_BYTE *)(v28 + v21 + 73)
           || v25 != 3
           && (!*(_BYTE *)(v29 + v21 + 73)
            || v25 != 4
            && (!*(_BYTE *)(v30 + v21 + 73)
             || v25 != 5
             && (!*(_BYTE *)(v31 + v21 + 73)
              || v25 != 6
              && (!*(_BYTE *)(v32 + v21 + 73)
               || v25 != 7
               && (!*(_BYTE *)(v33 + v21 + 73)
                || v25 != 8
                && (!*(_BYTE *)(v34 + v21 + 73)
                 || v25 != 9
                 && (!*(_BYTE *)(v35 + v21 + 73)
                  || v25 != 10
                  && (!*(_BYTE *)(v36 + v21 + 73)
                   || v25 != 11
                   && (!*(_BYTE *)(v37 + v21 + 73)
                    || v25 != 12
                    && (!*(_BYTE *)(v38 + v21 + 73)
                     || v25 != 13
                     && (!*(_BYTE *)(v39 + v21 + 73)
                      || v25 != 14 && (!*(_BYTE *)(v40 + v21 + 73) || v25 == 16 && !*(_BYTE *)(v41 + v21 + 73)))))))))))))))) )
      {
        break;
      }
      v23 = v21 + 1;
      result *= *(_QWORD *)(a3 + 8 * v21 + 120);
      if ( v21 == v24 )
        break;
      ++v21;
    }
    while ( *(_BYTE *)(a3 + 1 + v21 + 72) );
    a2 = v23;
  }
  else
  {
    result = 1i64;
  }
  *a1 = a2;
  return result;
}

// ======================================================
// Function: sub_66A33D40 @ 0x66A33D40
// ======================================================

void __fastcall sub_66A33D40(const char *a1, const char *a2, int a3)
{
  size_t v5; // rax
  wchar_t *v6; // rsi
  size_t v7; // rax
  const wchar_t *v8; // rax
  wchar_t v9; // cx
  __int64 v10; // r9
  wchar_t *v11; // rbx
  wchar_t v12; // cx
  __int64 v13; // r9

  v5 = strlen(a1);
  v6 = (wchar_t *)malloc(2 * v5 + 2);
  v7 = strlen(a2);
  v8 = (const wchar_t *)malloc(2 * v7 + 2);
  v9 = *(unsigned __int8 *)a1;
  v10 = 0i64;
  v11 = (wchar_t *)v8;
  if ( (_BYTE)v9 )
  {
    do
    {
      v6[v10++] = v9;
      v9 = (unsigned __int8)a1[v10];
    }
    while ( (_BYTE)v9 );
    v10 *= 2i64;
  }
  v12 = *(unsigned __int8 *)a2;
  *(wchar_t *)((char *)v6 + v10) = 0;
  v13 = 0i64;
  if ( (_BYTE)v12 )
  {
    do
    {
      v8[v13++] = v12;
      v12 = (unsigned __int8)a2[v13];
    }
    while ( (_BYTE)v12 );
    v13 *= 2i64;
  }
  *(const wchar_t *)((char *)v8 + v13) = 0;
  sub_66A33C00(v6, v8, a3);
  free(v6);
  free(v11);
}

// ======================================================
// Function: sub_66A33C00 @ 0x66A33C00
// ======================================================

int __fastcall sub_66A33C00(const wchar_t *a1, const wchar_t *a2, int a3)
{
  wchar_t *v6; // rbp
  int result; // eax
  FILE *v8; // rax
  WCHAR Filename[284]; // [rsp+40h] [rbp-238h] BYREF

  v6 = (wchar_t *)malloc(0x4000ui64);
  if ( a2 )
  {
    if ( !*a2 )
      a2 = L"<unknown>";
  }
  else
  {
    a2 = L"<unknown>";
  }
  if ( a1 )
  {
    if ( !*a1 )
      a1 = L"?";
  }
  else
  {
    a1 = L"?";
  }
  if ( !GetModuleFileNameW(0i64, Filename, 0x104u) )
    wcscpy(Filename, L"<unknown>");
  snwprintf(
    v6,
    0x1FFFui64,
    L"Assertion failed!\n\nProgram: %ws\nFile: %ws, Line %u\n\nExpression: %ws",
    Filename,
    a2,
    a3,
    a1);
  if ( !unk_66A3D5B0 )
  {
    v8 = _iob_func();
    fwprintf(v8 + 2, L"%ws\n", v6);
    abort();
  }
  result = MessageBoxW(0i64, v6, L"MinGW Runtime Assertion", 0x12012u);
  if ( result == 3 )
  {
    raise(22);
    exit(3);
  }
  if ( result != 5 )
    abort();
  return result;
}

