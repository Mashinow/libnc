// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_matmul_add
// Included functions: 6

// ======================================================
// Function: nc_matmul_add @ 0x66A25030
// ======================================================

_QWORD *__fastcall nc_matmul_add(__int64 a1, __int64 a2, _QWORD *a3, int a4, int a5)
{
  __int64 v5; // r12
  unsigned __int64 v6; // r13
  __int64 v7; // r14
  __int64 v8; // r15
  unsigned int v9; // eax
  int v10; // r8d
  __int64 v11; // rax
  __int64 v12; // rdx
  int v13; // eax
  __int64 v14; // r9
  int v15; // edx
  __int64 v16; // rax
  __int64 v17; // r10
  __int64 v18; // rdx
  int v19; // ebx
  unsigned __int64 v20; // r8
  int v21; // ecx
  __int64 v22; // rax
  __int64 v23; // r8
  unsigned __int64 v24; // r8
  unsigned __int64 v25; // rdi
  int v26; // ecx
  __int64 v27; // r11
  unsigned __int64 v28; // rcx
  int v29; // eax
  __int64 *v30; // rcx
  __int64 v31; // rdx
  __int64 v32; // r8
  __int64 v33; // rax
  __int64 v34; // rdx
  _QWORD *v35; // rax
  _QWORD *v36; // rbx
  _QWORD *v37; // rax
  __int64 v39; // rdx
  __int64 v40; // rdx
  unsigned __int64 v41; // rdi
  unsigned __int64 v42; // rbp
  __int64 v43; // rsi
  unsigned __int64 v44; // rbx
  int v45; // edx
  __int64 v46; // [rsp+20h] [rbp-1A8h]
  __int64 v47; // [rsp+30h] [rbp-198h]
  __int64 v48; // [rsp+38h] [rbp-190h]
  __int64 v49; // [rsp+40h] [rbp-188h]
  __int64 v50; // [rsp+48h] [rbp-180h]
  __int64 v51; // [rsp+50h] [rbp-178h]
  __int64 v52; // [rsp+58h] [rbp-170h]
  __int64 v53; // [rsp+60h] [rbp-168h]
  __int64 v54; // [rsp+68h] [rbp-160h]
  __int64 v55; // [rsp+70h] [rbp-158h]
  __int64 v56; // [rsp+78h] [rbp-150h]
  __int64 v57; // [rsp+80h] [rbp-148h]
  __int64 v58; // [rsp+88h] [rbp-140h]
  __int64 v59; // [rsp+90h] [rbp-138h]
  void (__fastcall *v60)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, int, int, _DWORD, _DWORD, _DWORD, int, int); // [rsp+90h] [rbp-138h]
  __int64 v61; // [rsp+98h] [rbp-130h]
  __int64 v62; // [rsp+98h] [rbp-130h]
  __int64 v63; // [rsp+B0h] [rbp-118h]
  _QWORD *v64; // [rsp+B8h] [rbp-110h]
  __int64 v65; // [rsp+C0h] [rbp-108h]
  __int64 v66; // [rsp+C8h] [rbp-100h]
  __int64 v67; // [rsp+D0h] [rbp-F8h]
  __int64 v68; // [rsp+D8h] [rbp-F0h]
  __int64 v69; // [rsp+E0h] [rbp-E8h]
  __int64 v70; // [rsp+E8h] [rbp-E0h]
  __int64 v71; // [rsp+F0h] [rbp-D8h]
  int v72; // [rsp+F8h] [rbp-D0h]
  int v73; // [rsp+FCh] [rbp-CCh]
  __int64 v74; // [rsp+100h] [rbp-C8h]
  int v75; // [rsp+11Ch] [rbp-ACh] BYREF
  __int64 v76[4]; // [rsp+120h] [rbp-A8h] BYREF
  __int64 v77; // [rsp+140h] [rbp-88h] BYREF
  __int64 v78; // [rsp+148h] [rbp-80h]
  __int64 v79; // [rsp+150h] [rbp-78h]
  __int64 v80; // [rsp+158h] [rbp-70h]
  __int64 v81; // [rsp+160h] [rbp-68h] BYREF
  __int64 v82; // [rsp+168h] [rbp-60h]
  __int64 v83; // [rsp+170h] [rbp-58h]
  __int64 v84; // [rsp+178h] [rbp-50h]

  v74 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  if ( v74 != *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64) )
    nc_error("all operation tensors must be on the same device");
  v9 = *(_DWORD *)(a1 + 48);
  if ( v9 > 2 )
  {
    printf("unsupported type for %s\n", "nc_matmul_add");
    abort();
  }
  if ( v9 == 2 )
  {
    if ( a5 | a4 )
      sub_66A33D40("!w_trans && !x_trans", "libnc.c", 6549);
    if ( *(_DWORD *)(a2 + 48) )
      goto LABEL_106;
  }
  else if ( v9 != *(_DWORD *)(a2 + 48) )
  {
    goto LABEL_106;
  }
  v10 = *(_DWORD *)(a1 + 80);
  if ( *(_DWORD *)(a2 + 80) != v10
    || v10 <= 1
    || (v68 = a2 + 8i64 * a5, *(_QWORD *)(a1 + 8i64 * (1 - a4) + 120) != *(_QWORD *)(v68 + 120)) )
  {
LABEL_110:
    sub_66A16930("matmul", a1, a2);
  }
  if ( v10 <= 2 )
  {
    v77 = *(_QWORD *)(a1 + 8i64 * a4 + 120);
    v78 = *(_QWORD *)(a2 + 8i64 * (1 - a5) + 120);
  }
  else
  {
    if ( *(_QWORD *)(a1 + 136) != *(_QWORD *)(a2 + 136) )
      goto LABEL_110;
    v11 = 3i64;
    while ( v10 > (int)v11 )
    {
      v12 = *(_QWORD *)(a1 + 8 * v11++ + 120);
      if ( v12 != *(_QWORD *)(a2 + 8 * v11 + 112) )
        goto LABEL_110;
    }
    v79 = *(_QWORD *)(a1 + 136);
    v77 = *(_QWORD *)(a1 + 8i64 * a4 + 120);
    v78 = *(_QWORD *)(a2 + 8i64 * (1 - a5) + 120);
    if ( v10 != 3 )
      v80 = *(_QWORD *)(a1 + 144);
  }
  if ( !a3 )
  {
    a3 = nc_new_tensor(v74, *(_DWORD *)(a2 + 48), v10, (__int64)&v77);
    goto LABEL_23;
  }
  if ( *((_DWORD *)a3 + 12) != *(_DWORD *)(a2 + 48) )
LABEL_106:
    nc_error("unsupported type for %s\n", "nc_matmul_add");
  if ( a3[15] != v77 || v78 != a3[16] || v10 > 2 && (v79 != a3[17] || v10 != 3 && v80 != a3[18]) )
    goto LABEL_110;
LABEL_23:
  v64 = a3;
  if ( *((_DWORD *)a3 + 4) != 1 )
  {
    v64 = nc_new_tensor_nz(*(_QWORD *)(a3[5] + 24i64), *((_DWORD *)a3 + 12), *((_DWORD *)a3 + 20), (__int64)(a3 + 15));
    nc_tensor_copy((__int64)v64, (__int64)a3);
  }
  v13 = sub_66A05420(
          &v75,
          2,
          (__int64)v64,
          a2,
          a1,
          0i64,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v61);
  v81 = 0i64;
  v72 = v13;
  v73 = dword_66A375E0[*(unsigned int *)(a1 + 48)];
  v15 = *(_DWORD *)(a2 + 80);
  if ( v15 <= 1 )
  {
    v17 = 0i64;
  }
  else
  {
    v16 = 1i64;
    do
      *(&v81 + v16++) = 0i64;
    while ( v15 > (int)v16 );
    v17 = v81;
  }
  v18 = v17;
  while ( 2 )
  {
    if ( v18 == -1 )
      goto LABEL_58;
    v19 = *(_DWORD *)(a1 + 48);
    if ( v19 != 2 )
    {
      v60 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, int, int, _DWORD, _DWORD, _DWORD, int, int))(v74 + 440);
      v5 = *(_QWORD *)(v68 + 120);
      v6 = v64[16];
      v7 = v64[15];
      v20 = *(_QWORD *)(a2 + 104);
      v8 = v20 >> v73;
      v62 = *(_QWORD *)(a2 + 64);
      v21 = *(_DWORD *)(a2 + 80);
      v17 = *(_QWORD *)(a2 + 56);
      if ( v21 <= 0 )
      {
        v22 = 0i64;
      }
      else
      {
        v22 = *(_QWORD *)(a2 + 88) * v18;
        if ( v21 != 1 )
        {
          v22 += *(_QWORD *)(a2 + 96) * v82;
          if ( v21 != 2 )
          {
            v22 += v83 * v20;
            if ( v21 != 3 )
            {
              v23 = v84;
              v14 = *(_QWORD *)(a2 + 112);
              goto LABEL_37;
            }
          }
        }
      }
      goto LABEL_38;
    }
    v69 = v64[7];
    v22 = *((unsigned int *)v64 + 20);
    if ( (int)v22 <= 0 )
    {
      v67 = 0i64;
LABEL_76:
      v71 = *(_QWORD *)(a1 + 56);
      v22 = *(unsigned int *)(a1 + 80);
      if ( (int)v22 <= 0 )
      {
        v66 = 0i64;
      }
      else
      {
        v66 = *(_QWORD *)(a1 + 88) * v18;
        if ( (_DWORD)v22 != 1 )
        {
          v66 = *(_QWORD *)(a1 + 96) * v82 + *(_QWORD *)(a1 + 88) * v18;
          if ( (_DWORD)v22 != 2 )
          {
            v66 = *(_QWORD *)(a1 + 104) * v83 + *(_QWORD *)(a1 + 96) * v82 + *(_QWORD *)(a1 + 88) * v18;
            if ( (_DWORD)v22 != 3 )
            {
              v23 = *(_QWORD *)(a1 + 112);
              if ( (_DWORD)v22 != 4 )
                goto LABEL_37;
              v66 += v23 * v84;
            }
          }
        }
      }
      v70 = *(_QWORD *)(a2 + 56);
      v23 = *(unsigned int *)(a2 + 80);
      if ( (int)v23 <= 0 )
      {
        v65 = 0i64;
      }
      else
      {
        v39 = *(_QWORD *)(a2 + 88) * v18;
        v65 = v39;
        if ( (_DWORD)v23 != 1 )
        {
          v40 = *(_QWORD *)(a2 + 96) * v82 + v39;
          v65 = v40;
          if ( (_DWORD)v23 != 2 )
          {
            v65 = *(_QWORD *)(a2 + 104) * v83 + v40;
            if ( (_DWORD)v23 != 3 )
            {
              v22 = v84;
              v18 = *(_QWORD *)(a2 + 112);
              if ( (_DWORD)v23 != 4 )
                goto LABEL_37;
              v65 += v18 * v84;
            }
          }
        }
      }
      if ( v72 > 0 )
      {
        v63 = 0i64;
        do
        {
          v6 = *(_QWORD *)(v68 + 120);
          v5 = *(_QWORD *)(a2 + 64);
          v41 = v64[16];
          v42 = v64[15];
          v60 = (void (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, _QWORD, unsigned __int64, __int64, __int64, __int64, int, int, _DWORD, _DWORD, _DWORD, int, int))v64[8];
          v17 = v65 + v63 * (*(_QWORD *)(a2 + 104) & 0xFFFFFFFFFFFFFFFCui64);
          v43 = *(_QWORD *)(a1 + 64);
          v62 = v69 + v67 + v63 * (v64[13] & 0xFFFFFFFFFFFFFFFCui64);
          if ( v6 )
          {
            v8 = v71 + v66 + v63 * (*(_QWORD *)(a1 + 104) & 0xFFFFFFFFFFFFFFFEui64);
            v44 = 0i64;
            v7 = v70 + v17;
            do
            {
              v46 = v7;
              v45 = v6 - v44;
              if ( (int)v6 - (int)v44 > 256 )
                v45 = 256;
              v44 += 256i64;
              v7 += 1024i64;
              mat_mul1_f16(v62, (__int64)v60, v8, v43, v46, v5, v42, v41, v45);
              v8 += v43 << 9;
            }
            while ( v6 > v44 );
          }
          ++v63;
        }
        while ( v72 > (int)v63 );
        goto LABEL_51;
      }
      goto LABEL_52;
    }
    v67 = v64[11] * v18;
    if ( (_DWORD)v22 == 1 )
      goto LABEL_76;
    v67 = v64[12] * v82 + v64[11] * v18;
    if ( (_DWORD)v22 == 2 )
      goto LABEL_76;
    v67 = v64[13] * v83 + v64[12] * v82 + v64[11] * v18;
    if ( (_DWORD)v22 == 3 )
      goto LABEL_76;
    v23 = v64[14];
    if ( (_DWORD)v22 == 4 )
    {
      v67 += v23 * v84;
      goto LABEL_76;
    }
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_37:
        v22 += v14 * v23;
LABEL_38:
        v17 += v22;
        v24 = *(_QWORD *)(a1 + 104);
        v25 = v24 >> v73;
        v26 = *(_DWORD *)(a1 + 80);
        if ( v26 <= 0 )
        {
          v22 = 0i64;
          break;
        }
        v22 = *(_QWORD *)(a1 + 88) * v18;
        if ( v26 == 1 )
          break;
        v22 += *(_QWORD *)(a1 + 96) * v82;
        if ( v26 == 2 )
          break;
        v22 += v83 * v24;
        if ( v26 == 3 )
          break;
        v23 = v84;
        v14 = *(_QWORD *)(a1 + 112);
        if ( v26 == 4 )
        {
          v22 += v14 * v84;
          break;
        }
      }
      v27 = v22 + *(_QWORD *)(a1 + 56);
      v28 = v64[13];
      v14 = v28 >> v73;
      v23 = (__int64)v64;
      v22 = *((unsigned int *)v64 + 20);
      if ( (int)v22 <= 0 )
        break;
      v18 *= v64[11];
      if ( (_DWORD)v22 == 1 )
        goto LABEL_50;
      v18 += v64[12] * v82;
      if ( (_DWORD)v22 == 2 )
        goto LABEL_50;
      v18 += v83 * v28;
      if ( (_DWORD)v22 == 3 )
        goto LABEL_50;
      if ( (_DWORD)v22 == 4 )
      {
        v18 += v64[14] * v84;
        goto LABEL_50;
      }
    }
    v18 = 0i64;
LABEL_50:
    v60(v74, v64[7] + v18, v64[8], v14, v27, *(_QWORD *)(a1 + 64), v25, v17, v62, v8, a4, a5, v7, v6, v5, v72, v19);
LABEL_51:
    LODWORD(v23) = *(_DWORD *)(a2 + 80);
LABEL_52:
    v29 = v75;
    if ( v75 < (int)v23 )
    {
      v14 = v75;
      v30 = &v81 + v75;
      v31 = *v30 + 1;
      *v30 = v31;
      if ( *(_QWORD *)(a2 + 8i64 * v29 + 120) == v31 )
      {
        v14 = a2 + 8i64 * (v29 + 1);
        v32 = (unsigned int)(~v29 + v23);
        v33 = 0i64;
        do
        {
          v30[v33] = 0i64;
          if ( v32 == v33 )
            goto LABEL_57;
          v34 = v30[v33 + 1] + 1;
          v30[++v33] = v34;
        }
        while ( v34 == *(_QWORD *)(v14 + 8 * v33 + 112) );
      }
      v18 = v81;
      continue;
    }
    break;
  }
LABEL_57:
  v81 = -1i64;
LABEL_58:
  v76[0] = a1;
  v76[1] = a2;
  v76[2] = (__int64)a3;
  v35 = sub_66A15DA0(30, v64 + 3, (__int64 **)v64 + 4, 3, (__int64)v76);
  v36 = v35;
  if ( v35 )
  {
    *((_DWORD *)v35 + 10) = 2;
    v37 = aligned_malloc(0x10ui64, 0x40ui64);
    if ( v37 )
    {
      *v37 = 0i64;
      v37[1] = 0i64;
    }
    v36[6] = v37;
    if ( *(_QWORD *)(a1 + 32) )
    {
      ++*(_DWORD *)(a2 + 16);
      v37[1] = a2;
    }
    if ( *(_QWORD *)(a2 + 32) )
    {
      ++*(_DWORD *)(a1 + 16);
      *v37 = a1;
    }
    *((_DWORD *)v36 + 14) = a4;
    *((_DWORD *)v36 + 15) = a5;
  }
  if ( a3 != v64 )
    nc_free_tensor(a3);
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  return v64;
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
// Function: sub_66A15DA0 @ 0x66A15DA0
// ======================================================

_QWORD *__fastcall sub_66A15DA0(int a1, __int64 *a2, __int64 **a3, int a4, __int64 a5)
{
  _QWORD *result; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  void *v11; // r15
  __int64 v12; // rax
  __int64 v13; // r13
  _QWORD *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rax
  size_t v20; // r12
  void *v21; // rax

  if ( a4 <= 0 )
  {
    if ( !a4 )
      return 0i64;
    v20 = 8i64 * a4;
    v21 = aligned_malloc(v20, 0x40ui64);
    v13 = *a2;
    v11 = v21;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v14[4] = aligned_malloc(v20, 0x40ui64);
LABEL_13:
      v18 = *(_QWORD *)(v13 + 72);
      *(_QWORD *)(v13 + 72) = v18 + 1;
      v14[12] = v18;
      v19 = *(_QWORD *)(v13 + 32);
      *(_QWORD *)(v19 + 8) = v14;
      *v14 = v19;
      v14[1] = v13 + 32;
      *(_QWORD *)(v13 + 32) = v14;
      _aligned_free(v11);
      if ( *a3 )
        nc_free_node(*a3);
      *a3 = v14;
      return v14;
    }
LABEL_22:
    MEMORY[0x10] = 0;
    BUG();
  }
  result = *(_QWORD **)(*(_QWORD *)a5 + 32i64);
  if ( result )
    goto LABEL_7;
  v9 = 1i64;
  while ( (int)v9 < a4 )
  {
    v10 = *(_QWORD *)(a5 + 8 * v9++);
    if ( *(_QWORD *)(v10 + 32) )
      goto LABEL_7;
  }
  if ( (_DWORD)v9 != a4 )
  {
LABEL_7:
    v11 = aligned_malloc(8i64 * a4, 0x40ui64);
    v12 = 0i64;
    do
    {
      *((_QWORD *)v11 + v12) = *(_QWORD *)(*(_QWORD *)(a5 + 8 * v12) + 32i64);
      ++v12;
    }
    while ( a4 > (int)v12 );
    v13 = *a2;
    v14 = aligned_malloc(0x80ui64, 0x40ui64);
    if ( v14 )
    {
      memset(v14, 0, 0x80ui64);
      *((_DWORD *)v14 + 6) = a4;
      *((_DWORD *)v14 + 4) = 1;
      *((_DWORD *)v14 + 5) = a1;
      v15 = aligned_malloc(8i64 * a4, 0x40ui64);
      v16 = 0i64;
      v14[4] = v15;
      do
      {
        while ( 1 )
        {
          v17 = *((_QWORD *)v11 + v16);
          if ( !v17 )
            break;
          ++*(_DWORD *)(v17 + 16);
          v15[v16++] = v17;
          if ( a4 <= (int)v16 )
            goto LABEL_13;
        }
        v15[v16++] = 0i64;
      }
      while ( a4 > (int)v16 );
      goto LABEL_13;
    }
    goto LABEL_22;
  }
  return result;
}

