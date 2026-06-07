// Auto-generated from libnc_cuda.so_pseudocode.c
// Root function: nc_new_cuda_device_internal
// Included functions: 31

// ======================================================
// Function: nc_new_cuda_device_internal @ 0x6480
// ======================================================

__int64 __fastcall nc_new_cuda_device_internal(__int64 a1, unsigned int a2)
{
  __int64 *v2; // rbx
  const char *v3; // rbp
  __int64 v4; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  int v7; // esi
  __m128i v8; // xmm3
  __int64 v9; // rdx
  __m128i si128; // xmm1
  __m128i v11; // xmm5
  __m128i v12; // xmm3
  __m128i v13; // xmm2
  __m128i v14; // xmm0
  signed int v15; // edx
  __m128i v16; // xmm0
  __m128i v17; // xmm0
  __m128i v18; // xmm0
  __m128i v19; // xmm0
  __m128i v20; // xmm0
  int v21; // ecx
  int v22; // edx
  __m128i v23; // xmm0
  __m128i v24; // xmm0
  __m128i v25; // xmm0
  __m128i v26; // xmm0
  __int64 result; // rax
  __m128i v28; // xmm0
  __m128i v29; // [rsp+0h] [rbp-68h] BYREF
  __m128i v30; // [rsp+18h] [rbp-50h] BYREF
  int v31; // [rsp+28h] [rbp-40h] BYREF
  unsigned int v32; // [rsp+2Ch] [rbp-3Ch] BYREF
  char v33[8]; // [rsp+30h] [rbp-38h] BYREF
  __int64 v34[6]; // [rsp+38h] [rbp-30h] BYREF

  cuInit(0LL);
  cuDeviceGetCount((__int64)&v31);
  if ( !v31 )
  {
    fwrite("No CUDA device available\n", 1uLL, 0x19uLL, stderr);
    exit(1);
  }
  cuDeviceGet((__int64)&v32, a2);
  cuCtxCreate_v2((__int64)v33, 0LL, v32);
  if ( (unsigned int)cuModuleLoadData((__int64)v34, (__int64)&nc_cuda_ops_fatbin) )
  {
    fwrite("Could not load cuda module data\n", 1uLL, 0x20uLL, stderr);
    exit(1);
  }
  v2 = (__int64 *)&off_23C8A0;
  do
  {
    v3 = (const char *)v2[1];
    if ( (unsigned int)cuModuleGetFunction(*v2, v34[0], (__int64)v3) )
    {
      fprintf(stderr, "could not resolve function: %s\n", v3);
      exit(1);
    }
    v2 += 2;
  }
  while ( &off_23C8A0 + 168 != (void **)v2 );
  v4 = nc_mallocz(64LL);
  *(_DWORD *)(v4 + 8) = 21;
  v5 = v4;
  v6 = nc_malloc(336LL);
  v7 = *(_DWORD *)(v5 + 8);
  *(_QWORD *)(v5 + 16) = v6;
  if ( v7 > 0 )
  {
    if ( (unsigned int)(v7 - 1) <= 6 )
    {
      v15 = 0;
    }
    else
    {
      v29.m128i_i64[0] = v6;
      v8 = _mm_loadl_epi64(&v29);
      v9 = v6;
      si128 = _mm_load_si128((const __m128i *)&xmmword_73B0);
      v11 = _mm_load_si128((const __m128i *)&xmmword_73C0);
      v12 = _mm_unpacklo_epi64(v8, v8);
      do
      {
        v9 += 32LL;
        v13 = _mm_cmpgt_epi32((__m128i)0LL, si128);
        *(__m128i *)(v9 - 32) = _mm_add_epi64(_mm_slli_epi64(_mm_unpacklo_epi32(si128, v13), 4u), v12);
        v14 = si128;
        si128 = _mm_add_epi32(si128, v11);
        *(__m128i *)(v9 - 16) = _mm_add_epi64(_mm_slli_epi64(_mm_unpackhi_epi32(v14, v13), 4u), v12);
      }
      while ( v6 + 32LL * ((unsigned int)v7 >> 1) != v9 );
      v15 = v7 & 0xFFFFFFFE;
      if ( v7 == (v7 & 0xFFFFFFFE) )
        goto LABEL_18;
    }
    v29.m128i_i64[0] = v6 + 16LL * v15;
    v16 = _mm_loadl_epi64(&v29);
    *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v16, v16);
    if ( v15 + 1 < v7 )
    {
      v29.m128i_i64[0] = v6 + 16LL * (v15 + 1);
      v17 = _mm_loadl_epi64(&v29);
      *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v17, v17);
      if ( v7 > v15 + 2 )
      {
        v29.m128i_i64[0] = v6 + 16LL * (v15 + 2);
        v18 = _mm_loadl_epi64(&v29);
        *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v18, v18);
        if ( v7 > v15 + 3 )
        {
          v29.m128i_i64[0] = v6 + 16LL * (v15 + 3);
          v19 = _mm_loadl_epi64(&v29);
          *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v19, v19);
          if ( v7 > v15 + 4 )
          {
            v29.m128i_i64[0] = v6 + 16LL * (v15 + 4);
            v20 = _mm_loadl_epi64(&v29);
            *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v20, v20);
            v21 = v15 + 5;
            if ( v7 > v15 + 5 )
            {
              v22 = v15 + 6;
              v29.m128i_i64[0] = v6 + 16LL * v21;
              v23 = _mm_loadl_epi64(&v29);
              *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v23, v23);
              if ( v7 > v22 )
              {
                v29.m128i_i64[0] = 16LL * v22 + v6;
                v24 = _mm_loadl_epi64(&v29);
                *(__m128i *)v29.m128i_i64[0] = _mm_unpacklo_epi64(v24, v24);
              }
            }
          }
        }
      }
    }
  }
LABEL_18:
  *(_QWORD *)(v5 + 56) = 0LL;
  v29.m128i_i64[0] = v5 + 40;
  v30.m128i_i64[0] = v5 + 24;
  v25 = _mm_loadl_epi64(&v30);
  *(__m128i *)(v5 + 24) = _mm_unpacklo_epi64(v25, v25);
  v26 = _mm_loadl_epi64(&v29);
  *(__m128i *)(v5 + 40) = _mm_unpacklo_epi64(v26, v26);
  if ( (unsigned int)cublasCreate_v2(v5) )
  {
    fwrite("cublas init error\n", 1uLL, 0x12uLL, stderr);
    exit(1);
  }
  v29.m128i_i64[0] = v5;
  v29 = (__m128i)_mm_loadh_ps((const double *)v29.m128i_i64);
  result = nc_mallocz(488LL);
  v28 = _mm_load_si128(&v29);
  *(_QWORD *)(result + 128) = sub_3570;
  *(__m128i *)(result + 16) = v28;
  v29.m128i_i64[0] = (__int64)sub_3BD0;
  *(__m128 *)(result + 48) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_2CE0;
  *(__m128 *)(result + 64) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_35B0;
  *(__m128 *)(result + 80) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_3B80;
  *(__m128 *)(result + 96) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_2990;
  *(__m128 *)(result + 112) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_2850;
  *(__m128 *)(result + 152) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_3150;
  *(__m128 *)(result + 168) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_60D0;
  *(__m128 *)(result + 184) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_6230;
  *(__m128 *)(result + 200) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_62E0;
  *(__m128 *)(result + 216) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_63B0;
  *(__m128 *)(result + 232) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_5600;
  *(__m128 *)(result + 248) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_56D0;
  *(__m128 *)(result + 264) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_2E00;
  *(__m128 *)(result + 280) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_5E00;
  *(__m128 *)(result + 296) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_5FE0;
  *(__m128 *)(result + 312) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_26F0;
  *(__m128 *)(result + 328) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_2490;
  *(__m128 *)(result + 344) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_4430;
  *(__m128 *)(result + 368) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_4460;
  *(__m128 *)(result + 384) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_3A30;
  *(__m128 *)(result + 400) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_4E30;
  *(__m128 *)(result + 416) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_33F0;
  *(__m128 *)(result + 432) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_3E70;
  *(__m128 *)(result + 448) = _mm_loadh_ps((const double *)v29.m128i_i64);
  v29.m128i_i64[0] = (__int64)sub_3900;
  *(_QWORD *)(result + 480) = sub_2110;
  *(__m128 *)(result + 464) = _mm_loadh_ps((const double *)v29.m128i_i64);
  return result;
}

// ======================================================
// Function: sub_3570 @ 0x3570
// ======================================================

__int64 sub_3570()
{
  return cuStreamSynchronize();
}

// ======================================================
// Function: sub_3BD0 @ 0x3BD0
// ======================================================

void __fastcall sub_3BD0(__int64 a1, __m128 *a2)
{
  _QWORD *v2; // r14
  __int64 v3; // rdx
  _QWORD *v4; // r12
  __int64 v5; // rax
  __int64 v6; // rbx
  __int64 v7; // rbp
  __int64 *v8; // rdi
  __int64 v9; // rdx
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rdx
  _QWORD *v13; // rax
  __int64 v14; // rdx
  _QWORD *v15; // rax
  __int64 *v16; // rdi
  unsigned __int64 v17; // rax
  __int64 v18; // rdx
  _QWORD *v19; // rax
  _QWORD *v20; // rax
  __int64 v21; // rdx
  __int64 *v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rax
  __m128i v25; // xmm0
  __m128i v26[3]; // [rsp+0h] [rbp-30h] BYREF

  if ( a2 )
  {
    v2 = *(_QWORD **)(a1 + 24);
    if ( a2[3].m128_i32[2] != 1 )
      __assert_fail("b->state == NC_BLOCK_STATE_ALLOCATED", "libnc_cuda.c", 0x134u, "cuda_free");
    v3 = v2[5];
    v4 = v2 + 5;
    v5 = v2[7] + a2[3].m128_u64[0];
    a2[3].m128_i32[2] = 2;
    v26[0].m128i_i64[0] = (__int64)(v2 + 5);
    v2[7] = v5;
    *(_QWORD *)(v3 + 8) = a2 + 1;
    a2[1] = _mm_loadh_ps((const double *)v26[0].m128i_i64);
    v2[5] = a2 + 1;
    if ( v5 > 0xFFFFFFF )
    {
      cuStreamSynchronize();
      v6 = v2[6];
      v7 = *(_QWORD *)(v6 + 8);
      if ( v4 != (_QWORD *)v6 )
      {
        if ( *(_DWORD *)(v6 + 40) != 2 )
LABEL_22:
          __assert_fail("b->state == NC_BLOCK_STATE_PENDING_FREE", "libnc_cuda.c", 0x123u, "cuda_free_pending_blocks");
        while ( 1 )
        {
          v8 = *(__int64 **)(v6 - 16);
          v9 = *(_QWORD *)(v6 + 16) + 16LL;
          if ( v8 != (__int64 *)v9 && !*((_DWORD *)v8 + 14) )
          {
            v10 = v8[5];
            v11 = v8[6];
            if ( v10 + v11 != *(_QWORD *)(v6 + 24) )
              __assert_fail("b1->addr + b1->size == b->addr", "libnc_cuda.c", 0x103u, "cuda_free_internal");
            *(_QWORD *)(v6 + 24) = v10;
            v12 = *v8;
            *(_QWORD *)(v6 + 32) += v11;
            v13 = (_QWORD *)v8[1];
            *(_QWORD *)(v12 + 8) = v13;
            *v13 = v12;
            v14 = v8[2];
            v15 = (_QWORD *)v8[3];
            *v8 = 0LL;
            v8[1] = 0LL;
            *(_QWORD *)(v14 + 8) = v15;
            *v15 = v14;
            v8[2] = 0LL;
            v8[3] = 0LL;
            nc_free();
            v9 = *(_QWORD *)(v6 + 16) + 16LL;
          }
          v16 = *(__int64 **)(v6 - 8);
          v17 = *(_QWORD *)(v6 + 32);
          if ( v16 != (__int64 *)v9 && !*((_DWORD *)v16 + 14) )
          {
            if ( v16[5] != v17 + *(_QWORD *)(v6 + 24) )
              __assert_fail("b1->addr == b->addr + b->size", "libnc_cuda.c", 0x10Fu, "cuda_free_internal");
            v18 = *v16;
            *(_QWORD *)(v6 + 32) = v16[6] + v17;
            v19 = (_QWORD *)v16[1];
            *(_QWORD *)(v18 + 8) = v19;
            *v19 = v18;
            v20 = (_QWORD *)v16[3];
            v21 = v16[2];
            *v16 = 0LL;
            v16[1] = 0LL;
            *(_QWORD *)(v21 + 8) = v20;
            *v20 = v21;
            v16[2] = 0LL;
            v16[3] = 0LL;
            nc_free();
            v17 = *(_QWORD *)(v6 + 32);
          }
          *(_DWORD *)(v6 + 40) = 0;
          v22 = (__int64 *)v2[2];
          if ( v17 > 9 )
          {
            _BitScanReverse64(&v17, v17);
            v22 += 2 * (int)(54 - (v17 ^ 0x3F));
          }
          v23 = *v22;
          *(_QWORD *)(v23 + 8) = v6;
          *(_QWORD *)v6 = v23;
          *(_QWORD *)(v6 + 8) = v22;
          v24 = *(_QWORD *)(v7 + 8);
          *v22 = v6;
          if ( v4 == (_QWORD *)v7 )
            break;
          v6 = v7;
          if ( *(_DWORD *)(v7 + 40) != 2 )
            goto LABEL_22;
          v7 = v24;
        }
      }
      v26[0].m128i_i64[0] = (__int64)(v2 + 5);
      v25 = _mm_loadl_epi64(v26);
      v2[7] = 0LL;
      *(__m128i *)(v2 + 5) = _mm_unpacklo_epi64(v25, v25);
    }
  }
}

// ======================================================
// Function: sub_2CE0 @ 0x2CE0
// ======================================================

__int64 __fastcall sub_2CE0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __m128 v7; // xmm0
  __m128i v8; // xmm0
  __m128i v10; // [rsp+0h] [rbp-68h] BYREF
  __int64 v11[2]; // [rsp+10h] [rbp-58h] BYREF
  __int64 v12[2]; // [rsp+20h] [rbp-48h] BYREF
  __m128 v13; // [rsp+30h] [rbp-38h]
  __m128 v14; // [rsp+40h] [rbp-28h]
  __m128i v15; // [rsp+50h] [rbp-18h]

  v12[1] = a2;
  v12[0] = a3;
  v11[1] = a4;
  v11[0] = a5;
  v10.m128i_i64[1] = a6;
  v10.m128i_i64[0] = (__int64)v12;
  v13 = _mm_loadh_ps((const double *)v10.m128i_i64);
  v10.m128i_i64[0] = (__int64)v11;
  v7 = _mm_loadh_ps((const double *)v10.m128i_i64);
  v10.m128i_i64[0] = (__int64)&v10.m128i_i64[1];
  v14 = v7;
  v8 = _mm_loadl_epi64(&v10);
  v10.m128i_i64[0] = (__int64)&a7;
  v15 = _mm_unpacklo_epi64(v8, _mm_loadl_epi64(&v10));
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_35B0 @ 0x35B0
// ======================================================

__int64 sub_35B0()
{
  return cuMemcpyHtoD_v2();
}

// ======================================================
// Function: sub_3B80 @ 0x3B80
// ======================================================

__int64 __fastcall sub_3B80(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  if ( a5 == 1 )
    return cuMemsetD16Async();
  if ( a5 == 2 )
    return cuMemsetD32Async();
  if ( a5 )
    abort();
  return cuMemsetD8Async();
}

// ======================================================
// Function: sub_2990 @ 0x2990
// ======================================================

__int64 __fastcall sub_2990(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __m128 v7; // xmm0
  __m128i v8; // xmm0
  __m128i v10; // [rsp+0h] [rbp-68h] BYREF
  __int64 v11[2]; // [rsp+10h] [rbp-58h] BYREF
  __int64 v12[2]; // [rsp+20h] [rbp-48h] BYREF
  __m128 v13; // [rsp+30h] [rbp-38h]
  __m128 v14; // [rsp+40h] [rbp-28h]
  __m128i v15; // [rsp+50h] [rbp-18h]

  v12[1] = a2;
  v12[0] = a3;
  v11[1] = a4;
  v11[0] = a5;
  v10.m128i_i64[0] = (__int64)v12;
  v10.m128i_i64[1] = a6;
  v13 = _mm_loadh_ps((const double *)v10.m128i_i64);
  v10.m128i_i64[0] = (__int64)v11;
  v7 = _mm_loadh_ps((const double *)v10.m128i_i64);
  v10.m128i_i64[0] = (__int64)&v10.m128i_i64[1];
  v14 = v7;
  v8 = _mm_loadl_epi64(&v10);
  v10.m128i_i64[0] = (__int64)&a7;
  v15 = _mm_unpacklo_epi64(v8, _mm_loadl_epi64(&v10));
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_2850 @ 0x2850
// ======================================================

__int64 __fastcall sub_2850(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __m128 v4; // xmm0
  __int64 *v6; // [rsp+0h] [rbp-48h] BYREF
  __int64 v7; // [rsp+8h] [rbp-40h] BYREF
  __int64 v8[2]; // [rsp+10h] [rbp-38h] BYREF
  __m128 v9; // [rsp+20h] [rbp-28h]
  __int64 *v10; // [rsp+30h] [rbp-18h]

  v8[1] = a2;
  v6 = v8;
  v10 = &v7;
  v8[0] = a3;
  v4 = _mm_loadh_ps((const double *)&v6);
  v7 = a4;
  v9 = v4;
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_3150 @ 0x3150
// ======================================================

__int64 __fastcall sub_3150(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7,
        __int64 a8,
        __int64 a9,
        unsigned int a10)
{
  __m128 v10; // xmm0
  __m128i v11; // xmm0
  __m128i v13; // [rsp+0h] [rbp-78h] BYREF
  __int64 v14[2]; // [rsp+10h] [rbp-68h] BYREF
  __int64 v15[2]; // [rsp+20h] [rbp-58h] BYREF
  __m128 v16; // [rsp+30h] [rbp-48h]
  __m128 v17; // [rsp+40h] [rbp-38h]
  __m128i v18; // [rsp+50h] [rbp-28h]
  __m128 v19; // [rsp+60h] [rbp-18h]

  v14[1] = a4;
  v15[1] = a2;
  v15[0] = a3;
  v14[0] = a5;
  v13.m128i_i64[1] = a6;
  if ( a10 > 1 )
    abort();
  v13.m128i_i64[0] = (__int64)v15;
  v16 = _mm_loadh_ps((const double *)v13.m128i_i64);
  v13.m128i_i64[0] = (__int64)v14;
  v10 = _mm_loadh_ps((const double *)v13.m128i_i64);
  v13.m128i_i64[0] = (__int64)&v13.m128i_i64[1];
  v17 = v10;
  v11 = _mm_loadl_epi64(&v13);
  v13.m128i_i64[0] = (__int64)&a7;
  v18 = _mm_unpacklo_epi64(v11, _mm_loadl_epi64(&v13));
  v13.m128i_i64[0] = (__int64)&a9;
  v19 = _mm_loadh_ps((const double *)v13.m128i_i64);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_60D0 @ 0x60D0
// ======================================================

__int64 __fastcall sub_60D0(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v5[3]; // [rsp+0h] [rbp-C8h] BYREF
  int v6; // [rsp+1Ch] [rbp-ACh] BYREF
  __int128 v7[2]; // [rsp+20h] [rbp-A8h] BYREF
  int *v8; // [rsp+40h] [rbp-88h]

  v5[0] = a3;
  v5[1] = a2;
  v6 = a4;
  v7[0] = (__int128)_mm_loadh_ps((const double *)v5);
  v5[0] = (__int64)v7 + 8;
  v8 = &v6;
  v7[1] = (__int128)_mm_loadh_ps((const double *)v5);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_6230 @ 0x6230
// ======================================================

__int64 __fastcall sub_6230(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v5[3]; // [rsp+0h] [rbp-C8h] BYREF
  int v6; // [rsp+1Ch] [rbp-ACh] BYREF
  __int128 v7[2]; // [rsp+20h] [rbp-A8h] BYREF
  int *v8; // [rsp+40h] [rbp-88h]

  v5[0] = a3;
  v5[1] = a2;
  v6 = a4;
  v7[0] = (__int128)_mm_loadh_ps((const double *)v5);
  v5[0] = (__int64)v7 + 8;
  v8 = &v6;
  v7[1] = (__int128)_mm_loadh_ps((const double *)v5);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_62E0 @ 0x62E0
// ======================================================

__int64 __fastcall sub_62E0(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v6[3]; // [rsp+0h] [rbp-C8h] BYREF
  int v7; // [rsp+1Ch] [rbp-ACh] BYREF
  __int128 v8[2]; // [rsp+20h] [rbp-A8h] BYREF
  int *v9; // [rsp+40h] [rbp-88h]

  v6[0] = a3;
  if ( a5 > 1 )
    abort();
  v6[1] = a2;
  v7 = a4;
  v8[0] = (__int128)_mm_loadh_ps((const double *)v6);
  v6[0] = (__int64)v8 + 8;
  v9 = &v7;
  v8[1] = (__int128)_mm_loadh_ps((const double *)v6);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_63B0 @ 0x63B0
// ======================================================

__int64 __fastcall sub_63B0(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v6[3]; // [rsp+0h] [rbp-C8h] BYREF
  int v7; // [rsp+1Ch] [rbp-ACh] BYREF
  __int128 v8[2]; // [rsp+20h] [rbp-A8h] BYREF
  int *v9; // [rsp+40h] [rbp-88h]

  v6[0] = a3;
  if ( a5 > 1 )
    abort();
  v6[1] = a2;
  v7 = a4;
  v8[0] = (__int128)_mm_loadh_ps((const double *)v6);
  v6[0] = (__int64)v8 + 8;
  v9 = &v7;
  v8[1] = (__int128)_mm_loadh_ps((const double *)v6);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_5600 @ 0x5600
// ======================================================

__int64 __fastcall sub_5600(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v6[3]; // [rsp+0h] [rbp-C8h] BYREF
  int v7; // [rsp+1Ch] [rbp-ACh] BYREF
  __int128 v8[2]; // [rsp+20h] [rbp-A8h] BYREF
  int *v9; // [rsp+40h] [rbp-88h]

  v6[0] = a3;
  if ( a5 > 1 )
    abort();
  v6[1] = a2;
  v7 = a4;
  v8[0] = (__int128)_mm_loadh_ps((const double *)v6);
  v6[0] = (__int64)v8 + 8;
  v9 = &v7;
  v8[1] = (__int128)_mm_loadh_ps((const double *)v6);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_56D0 @ 0x56D0
// ======================================================

__int64 __fastcall sub_56D0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5, unsigned int a6)
{
  __int64 v7[3]; // [rsp+0h] [rbp-D8h] BYREF
  int v8; // [rsp+1Ch] [rbp-BCh] BYREF
  __m128 v9; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v10; // [rsp+30h] [rbp-A8h]
  __m128 v11; // [rsp+40h] [rbp-98h]
  __m128 v12; // [rsp+50h] [rbp-88h]

  v7[0] = a3;
  if ( a6 > 1 )
    abort();
  v7[1] = a2;
  v10 = a4;
  v9 = _mm_loadh_ps((const double *)v7);
  v7[0] = (__int64)&v9.m128_i64[1];
  v8 = a5;
  v11 = _mm_loadh_ps((const double *)v7);
  v7[0] = (__int64)&v8;
  v12 = _mm_loadh_ps((const double *)v7);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_2E00 @ 0x2E00
// ======================================================

__int64 __fastcall sub_2E00(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8)
{
  __m128 v8; // xmm0
  __m128i v9; // xmm0
  __m128i v11; // [rsp+0h] [rbp-68h] BYREF
  __int64 v12[2]; // [rsp+10h] [rbp-58h] BYREF
  __int64 v13[2]; // [rsp+20h] [rbp-48h] BYREF
  __m128 v14; // [rsp+30h] [rbp-38h]
  __m128 v15; // [rsp+40h] [rbp-28h]
  __m128i v16; // [rsp+50h] [rbp-18h]

  v13[1] = a2;
  v13[0] = a3;
  v12[1] = a4;
  v12[0] = a5;
  v11.m128i_i64[1] = a6;
  if ( a8 > 1 )
    start();
  v11.m128i_i64[0] = (__int64)v13;
  v14 = _mm_loadh_ps((const double *)v11.m128i_i64);
  v11.m128i_i64[0] = (__int64)v12;
  v8 = _mm_loadh_ps((const double *)v11.m128i_i64);
  v11.m128i_i64[0] = (__int64)&v11.m128i_i64[1];
  v15 = v8;
  v9 = _mm_loadl_epi64(&v11);
  v11.m128i_i64[0] = (__int64)&a7;
  v16 = _mm_unpacklo_epi64(v9, _mm_loadl_epi64(&v11));
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_5E00 @ 0x5E00
// ======================================================

__int64 __fastcall sub_5E00(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  __m128 v6; // xmm0
  __m128 *v8; // [rsp+8h] [rbp-E0h] BYREF
  __int64 v9[3]; // [rsp+10h] [rbp-D8h] BYREF
  int v10; // [rsp+2Ch] [rbp-BCh] BYREF
  __m128 v11; // [rsp+30h] [rbp-B8h] BYREF
  __int128 v12[3]; // [rsp+40h] [rbp-A8h] BYREF
  int *v13; // [rsp+70h] [rbp-78h]

  v8 = (__m128 *)a3;
  v9[1] = a2;
  v9[0] = a5;
  v11 = _mm_loadh_ps((const double *)&v8);
  v8 = &v11;
  v6 = _mm_loadh_ps((const double *)v9);
  v10 = a6;
  v12[0] = (__int128)v6;
  v8 = (__m128 *)&v11.m128_f32[2];
  v12[1] = (__int128)_mm_loadh_ps((const double *)&v8);
  v8 = (__m128 *)((char *)v12 + 8);
  v13 = &v10;
  v12[2] = (__int128)_mm_loadh_ps((const double *)&v8);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_5FE0 @ 0x5FE0
// ======================================================

__int64 __fastcall sub_5FE0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  __m128 v6; // xmm0
  __m128 *v8; // [rsp+8h] [rbp-E0h] BYREF
  __int64 v9[3]; // [rsp+10h] [rbp-D8h] BYREF
  int v10; // [rsp+2Ch] [rbp-BCh] BYREF
  __m128 v11; // [rsp+30h] [rbp-B8h] BYREF
  __int128 v12[3]; // [rsp+40h] [rbp-A8h] BYREF
  int *v13; // [rsp+70h] [rbp-78h]

  v8 = (__m128 *)a3;
  v9[1] = a2;
  v9[0] = a5;
  v11 = _mm_loadh_ps((const double *)&v8);
  v8 = &v11;
  v6 = _mm_loadh_ps((const double *)v9);
  v10 = a6;
  v12[0] = (__int128)v6;
  v8 = (__m128 *)&v11.m128_f32[2];
  v12[1] = (__int128)_mm_loadh_ps((const double *)&v8);
  v8 = (__m128 *)((char *)v12 + 8);
  v13 = &v10;
  v12[2] = (__int128)_mm_loadh_ps((const double *)&v8);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_26F0 @ 0x26F0
// ======================================================

__int64 __fastcall sub_26F0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7,
        __int64 a8,
        __int64 a9,
        char a10,
        char a11)
{
  __m128 v11; // xmm0
  __m128i v12; // xmm0
  __m128i v14; // [rsp+0h] [rbp-88h] BYREF
  __int64 v15[2]; // [rsp+10h] [rbp-78h] BYREF
  __int64 v16[2]; // [rsp+20h] [rbp-68h] BYREF
  __m128 v17; // [rsp+30h] [rbp-58h]
  __m128 v18; // [rsp+40h] [rbp-48h]
  __m128i v19; // [rsp+50h] [rbp-38h]
  __m128 v20; // [rsp+60h] [rbp-28h]
  __m128 v21; // [rsp+70h] [rbp-18h]

  v16[1] = a2;
  v15[1] = a4;
  v15[0] = a5;
  v14.m128i_i64[1] = a6;
  v16[0] = a3;
  v14.m128i_i64[0] = (__int64)v16;
  v17 = _mm_loadh_ps((const double *)v14.m128i_i64);
  v14.m128i_i64[0] = (__int64)v15;
  v11 = _mm_loadh_ps((const double *)v14.m128i_i64);
  v14.m128i_i64[0] = (__int64)&v14.m128i_i64[1];
  v18 = v11;
  v12 = _mm_loadl_epi64(&v14);
  v14.m128i_i64[0] = (__int64)&a7;
  v19 = _mm_unpacklo_epi64(v12, _mm_loadl_epi64(&v14));
  v14.m128i_i64[0] = (__int64)&a9;
  v20 = _mm_loadh_ps((const double *)v14.m128i_i64);
  v14.m128i_i64[0] = (__int64)&a11;
  v21 = _mm_loadh_ps((const double *)v14.m128i_i64);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_2490 @ 0x2490
// ======================================================

__int64 __fastcall sub_2490(
        float a1,
        float a2,
        float a3,
        float a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        int a10)
{
  __m128 v10; // xmm0
  __int64 *v12; // [rsp+8h] [rbp-A0h] BYREF
  int v13[2]; // [rsp+10h] [rbp-98h] BYREF
  int v14[2]; // [rsp+18h] [rbp-90h] BYREF
  __int64 v15[2]; // [rsp+20h] [rbp-88h] BYREF
  __int64 v16[3]; // [rsp+30h] [rbp-78h] BYREF
  int v17; // [rsp+4Ch] [rbp-5Ch] BYREF
  __m128 v18; // [rsp+50h] [rbp-58h]
  __m128 v19; // [rsp+60h] [rbp-48h]
  __m128 v20; // [rsp+70h] [rbp-38h]
  __m128 v21; // [rsp+80h] [rbp-28h]
  int *v22; // [rsp+90h] [rbp-18h]

  *(float *)&v14[1] = a1;
  v12 = v16;
  v16[1] = a6;
  v16[0] = a7;
  v18 = _mm_loadh_ps((const double *)&v12);
  v12 = v15;
  v15[1] = a8;
  v15[0] = a9;
  v19 = _mm_loadh_ps((const double *)&v12);
  v12 = (__int64 *)v14;
  *(float *)v14 = a2;
  *(float *)&v13[1] = a3;
  v20 = _mm_loadh_ps((const double *)&v12);
  v12 = (__int64 *)v13;
  *(float *)v13 = a4;
  v17 = a10;
  v10 = _mm_loadh_ps((const double *)&v12);
  v22 = &v17;
  v21 = v10;
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_4430 @ 0x4430
// ======================================================

void __fastcall sub_4430(__int64 a1, __int64 a2, int a3, __int64 a4, int a5, int a6, __int64 a7, int a8)
{
  sub_4130(a1, 0, a2, a3, a4, a5, a6, a7, 1, a8);
}

// ======================================================
// Function: sub_4130 @ 0x4130
// ======================================================

void __fastcall sub_4130(__int64 a1, int a2, __int64 a3, int a4, __int64 a5, int a6, int a7, int a8, int a9, int a10)
{
  __int64 v10; // r11
  __m128 *v11; // r12
  unsigned __int64 v13; // rax
  int v14; // r8d
  __int64 v15; // rbp
  __m128 *v16; // r13
  __m128 v17; // xmm1
  int v18; // ecx
  __int64 *v19; // rax
  int *v20; // [rsp+28h] [rbp-E0h] BYREF
  int *v21; // [rsp+30h] [rbp-D8h] BYREF
  int *v22; // [rsp+38h] [rbp-D0h] BYREF
  __int64 v23; // [rsp+40h] [rbp-C8h]
  __int64 v24; // [rsp+48h] [rbp-C0h]
  __int64 v25; // [rsp+50h] [rbp-B8h]
  int v26; // [rsp+58h] [rbp-B0h]
  int v27; // [rsp+5Ch] [rbp-ACh]
  int v28; // [rsp+64h] [rbp-A4h] BYREF
  int i; // [rsp+68h] [rbp-A0h] BYREF
  int v30; // [rsp+6Ch] [rbp-9Ch] BYREF
  __int64 v31; // [rsp+70h] [rbp-98h] BYREF
  __int64 v32; // [rsp+78h] [rbp-90h]
  __m128 v33; // [rsp+80h] [rbp-88h]
  __m128 v34; // [rsp+90h] [rbp-78h]
  __m128 v35; // [rsp+A0h] [rbp-68h]
  __m128 v36; // [rsp+B0h] [rbp-58h]
  int *v37; // [rsp+C0h] [rbp-48h]

  v25 = a3;
  v27 = a4;
  if ( a2 == 1 )
  {
    v10 = qword_23D1D8;
    v23 = qword_23D1D8;
    if ( a10 )
      v10 = qword_23D1D0;
  }
  else
  {
    v23 = qword_23D1E8;
    v10 = qword_23D1E8;
    if ( a10 )
      v10 = qword_23D1E0;
  }
  v32 = a5;
  v11 = 0LL;
  v20 = &i;
  v22 = &v30;
  v21 = &a8;
  for ( i = a6; ; i = v30 )
  {
    if ( a7 > 127 )
    {
      if ( a7 <= 1024 )
      {
        _BitScanReverse64(&v13, a7 - 1LL);
        v14 = 1 << (63 - (v13 ^ 0x3F));
        a7 = ((2 << (63 - (v13 ^ 0x3F))) + a7 - 1) / (2 << (63 - (v13 ^ 0x3F)));
        goto LABEL_7;
      }
      v14 = 512;
      v18 = 1024;
    }
    else
    {
      v14 = 64;
      v18 = 128;
    }
    a7 = (a7 + v18 - 1) / v18;
    if ( a7 > 511 )
    {
      a7 = 512;
      v15 = 512LL;
      goto LABEL_15;
    }
LABEL_7:
    v15 = a7;
    if ( a7 == 1LL )
    {
      a7 = 1;
      v16 = 0LL;
      v31 = v25;
      v30 = v27;
      v28 = a9;
      goto LABEL_9;
    }
LABEL_15:
    v24 = v10;
    v26 = v14;
    v19 = sub_35D0(a1, &v31, 4 * v15 * a8);
    v30 = a7;
    v16 = (__m128 *)v19;
    v28 = 0;
LABEL_9:
    v37 = &v28;
    v17 = _mm_loadh_ps((const double *)&v22);
    v34 = _mm_loadh_ps((const double *)&v20);
    v35 = v34;
    v33 = v17;
    v36 = _mm_loadh_ps((const double *)&v21);
    cuLaunchKernel();
    sub_3BD0(a1, v11);
    if ( v15 == 1 )
      break;
    v11 = v16;
    v10 = v23;
    v32 = v31;
  }
}

// ======================================================
// Function: sub_35D0 @ 0x35D0
// ======================================================

__int64 *__fastcall sub_35D0(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v4; // r13
  unsigned __int64 v5; // rbp
  int v6; // r12d
  int v7; // eax
  __int64 *v8; // r8
  __int64 v9; // rsi
  __int64 *v10; // rdx
  unsigned __int64 v11; // rsi
  __int64 *v12; // rbx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  __m128i *v18; // rbx
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  unsigned __int64 v22; // rsi
  __m128i v23; // xmm3
  __int64 v24; // rdi
  __int64 v25; // rdx
  __int64 *v26; // rdx
  __int64 v27; // rdi
  __int64 v28; // rsi
  __m128i v29; // xmm0
  __int64 v30; // rax
  __m128i v31; // xmm1
  __m128i v32; // xmm0
  __int64 v33; // rdx
  __int64 *v34; // rdx
  unsigned __int64 v35; // rsi
  __int64 *v36; // rdx
  __int64 v37; // rdi
  unsigned __int64 v38; // rax
  __m128i v39; // [rsp+0h] [rbp-68h] BYREF
  _QWORD *v40; // [rsp+10h] [rbp-58h]
  __int64 *v41; // [rsp+18h] [rbp-50h]
  __int64 v42; // [rsp+28h] [rbp-40h] BYREF

  v4 = *(_QWORD *)(a1 + 24);
  if ( a3 )
  {
    v5 = (a3 + 511) & 0xFFFFFFFFFFFFFE00LL;
    if ( v5 > 9 )
    {
      _BitScanReverse64(&v38, v5);
      v6 = 54 - (v38 ^ 0x3F);
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = 0;
    v5 = 512LL;
  }
  v7 = *(_DWORD *)(v4 + 8);
  if ( v7 <= v6 )
    __assert_fail("free_idx1 < s->free_list_len", "libnc_cuda.c", 0xD8u, "cuda_malloc");
  v8 = &v42;
  while ( v6 >= v7 )
  {
LABEL_15:
    v40 = a2;
    v39.m128i_i64[0] = (__int64)v8;
    if ( (unsigned int)cuMemAlloc_v2() )
      __assert_fail("cuMemAlloc(&ptr, DEFAULT_ARENA_SIZE) == CUDA_SUCCESS", "libnc_cuda.c", 0xBBu, "cuda_new_arena");
    if ( (v42 & 0x1FF) != 0 )
      __assert_fail("((uint64_t)ptr & (NC_MEM_ALIGN - 1)) == 0", "libnc_cuda.c", 0xBCu, "cuda_new_arena");
    v41 = (__int64 *)v39.m128i_i64[0];
    v18 = (__m128i *)nc_mallocz(48LL);
    v19 = v42;
    v18[2].m128i_i64[1] = 0x20000000LL;
    v18[2].m128i_i64[0] = v19;
    v20 = *(_QWORD *)(v4 + 24);
    v39.m128i_i64[0] = (__int64)v18[1].m128i_i64;
    *(_QWORD *)(v20 + 8) = v18;
    v18->m128i_i64[0] = v20;
    v18->m128i_i64[1] = v4 + 24;
    *(_QWORD *)(v4 + 24) = v18;
    v18[1].m128i_i64[0] = (__int64)v18[1].m128i_i64;
    v18[1].m128i_i64[1] = (__int64)v18[1].m128i_i64;
    v21 = nc_malloc(64LL);
    v22 = v18[2].m128i_u64[1];
    v23 = _mm_loadu_si128(v18 + 2);
    v24 = v18[1].m128i_i64[0];
    v25 = v39.m128i_i64[0];
    *(_DWORD *)(v21 + 56) = 0;
    *(_QWORD *)(v21 + 32) = v18;
    a2 = v40;
    *(__m128i *)(v21 + 40) = v23;
    v8 = v41;
    *(_QWORD *)(v24 + 8) = v21;
    *(_QWORD *)(v21 + 8) = v25;
    v26 = *(__int64 **)(v4 + 16);
    *(_QWORD *)v21 = v24;
    v18[1].m128i_i64[0] = v21;
    if ( v22 > 9 )
    {
      _BitScanReverse64(&v22, v22);
      v26 += 2 * (int)(54 - (v22 ^ 0x3F));
    }
    v27 = *v26;
    v28 = v21 + 16;
    *(_QWORD *)(v27 + 8) = v21 + 16;
    *(_QWORD *)(v21 + 16) = v27;
    *(_QWORD *)(v21 + 24) = v26;
    v7 = *(_DWORD *)(v4 + 8);
    *v26 = v28;
  }
  v9 = *(_QWORD *)(v4 + 16);
  v10 = (__int64 *)(v9 + 16LL * v6);
  v11 = v9 + 16 * (v6 + (unsigned __int64)(unsigned int)(~v6 + v7)) + 16;
  while ( 1 )
  {
    v12 = (__int64 *)v10[1];
    if ( v12 != v10 )
      break;
LABEL_14:
    v10 += 2;
    if ( (__int64 *)v11 == v10 )
      goto LABEL_15;
  }
  while ( 1 )
  {
    v13 = v12[4];
    if ( v13 >= v5 )
      break;
    v12 = (__int64 *)v12[1];
    if ( v12 == v10 )
      goto LABEL_14;
  }
  if ( v13 > v5 )
  {
    v39.m128i_i64[0] = v5;
    v29 = _mm_loadl_epi64(&v39);
    v40 = a2;
    v39 = _mm_unpacklo_epi64(v29, v29);
    v30 = nc_malloc(64LL);
    v31 = _mm_loadu_si128((const __m128i *)(v12 + 3));
    v32 = _mm_load_si128(&v39);
    v33 = v12[2];
    *(_DWORD *)(v30 + 56) = 0;
    a2 = v40;
    *(_QWORD *)(v30 + 32) = v33;
    v34 = (__int64 *)*(v12 - 1);
    *(__m128d *)(v30 + 40) = _mm_shuffle_pd((__m128d)_mm_add_epi64(v31, v32), (__m128d)_mm_sub_epi64(v31, v32), 2);
    v12[4] = v5;
    v35 = *(_QWORD *)(v30 + 48);
    *(v12 - 1) = v30;
    *(_QWORD *)(v30 + 8) = v34;
    *(_QWORD *)v30 = v12 - 2;
    *v34 = v30;
    v36 = *(__int64 **)(v4 + 16);
    if ( v35 > 9 )
    {
      _BitScanReverse64(&v35, v35);
      v36 += 2 * (int)(54 - (v35 ^ 0x3F));
    }
    v37 = *v36;
    *(_QWORD *)(v37 + 8) = v30 + 16;
    *(_QWORD *)(v30 + 16) = v37;
    *(_QWORD *)(v30 + 24) = v36;
    *v36 = v30 + 16;
  }
  v14 = (_QWORD *)v12[1];
  v15 = *v12;
  *((_DWORD *)v12 + 10) = 1;
  *(_QWORD *)(v15 + 8) = v14;
  *v14 = v15;
  v16 = v12[3];
  *(_OWORD *)v12 = 0LL;
  *a2 = v16;
  return v12 - 2;
}

// ======================================================
// Function: sub_4460 @ 0x4460
// ======================================================

void __fastcall sub_4460(__int64 a1, __int64 a2, int a3, __int64 a4, int a5, int a6, __int64 a7, int a8)
{
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 *v11; // r12
  __m128i v12; // xmm1
  __m128i v13; // xmm0
  __m128i v14; // xmm2
  __m128i v15; // xmm3
  __m128i v16; // xmm4
  __m128i v17; // [rsp+0h] [rbp-F8h] BYREF
  __m128i v18; // [rsp+10h] [rbp-E8h] BYREF
  __m128i v19; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v20; // [rsp+30h] [rbp-C8h]
  __int64 v21; // [rsp+38h] [rbp-C0h]
  int v22; // [rsp+48h] [rbp-B0h] BYREF
  int v23; // [rsp+4Ch] [rbp-ACh] BYREF
  int v24; // [rsp+50h] [rbp-A8h] BYREF
  int v25; // [rsp+54h] [rbp-A4h] BYREF
  __int64 v26; // [rsp+58h] [rbp-A0h] BYREF
  __m128i v27; // [rsp+60h] [rbp-98h]
  __m128i v28; // [rsp+70h] [rbp-88h]
  int *v29; // [rsp+80h] [rbp-78h]
  __m128i v30; // [rsp+90h] [rbp-68h]
  __m128i v31; // [rsp+A0h] [rbp-58h]
  __m128i v32; // [rsp+B0h] [rbp-48h]
  int *v33; // [rsp+C0h] [rbp-38h]

  v20 = a4;
  v17.m128i_i64[0] = (__int64)&v22;
  v21 = a2;
  v22 = a3;
  v8 = _mm_loadh_ps((const double *)v17.m128i_i64);
  v17.m128i_i64[0] = (__int64)&v23;
  v18 = (__m128i)v8;
  v23 = a5;
  v9 = _mm_loadh_ps((const double *)v17.m128i_i64);
  v17.m128i_i64[0] = (__int64)&v24;
  v19 = (__m128i)v9;
  v24 = a6;
  v10 = _mm_loadh_ps((const double *)v17.m128i_i64);
  v25 = a7;
  v17 = (__m128i)v10;
  v11 = (__m128 *)sub_35D0(a1, &v26, 4LL * (int)a7);
  sub_4130(a1, 1, v26, 1, v20, v23, v24, v25, 0, a8);
  v12 = _mm_load_si128(&v18);
  v13 = _mm_load_si128(&v19);
  v14 = _mm_load_si128(&v17);
  v33 = &v25;
  v30 = v12;
  v31 = v13;
  v32 = v14;
  cuLaunchKernel();
  sub_4130(a1, 0, v26, 1, v21, v22, v24, v25, 0, a8);
  v15 = _mm_load_si128(&v18);
  v16 = _mm_load_si128(&v17);
  v29 = &v25;
  v27 = v15;
  v28 = v16;
  cuLaunchKernel();
  sub_3BD0(a1, v11);
}

// ======================================================
// Function: sub_3A30 @ 0x3A30
// ======================================================

__int64 __fastcall sub_3A30(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7,
        __int64 a8,
        __int64 a9,
        int a10)
{
  __m128 v10; // xmm0
  __m128i v11; // xmm0
  __m128i v13; // [rsp+0h] [rbp-78h] BYREF
  __int64 v14[2]; // [rsp+10h] [rbp-68h] BYREF
  __int64 v15[2]; // [rsp+20h] [rbp-58h] BYREF
  __m128 v16; // [rsp+30h] [rbp-48h]
  __m128 v17; // [rsp+40h] [rbp-38h]
  __m128i v18; // [rsp+50h] [rbp-28h]
  __m128 v19; // [rsp+60h] [rbp-18h]

  v15[1] = a2;
  v15[0] = a3;
  v14[1] = a4;
  v14[0] = a5;
  v13.m128i_i64[1] = a6;
  if ( a10 )
    __assert_fail("type == NC_TYPE_F32", "libnc_cuda.c", 0x49Fu, "cuda_indexed_log_soft_max_bw");
  v13.m128i_i64[0] = (__int64)v15;
  v16 = _mm_loadh_ps((const double *)v13.m128i_i64);
  v13.m128i_i64[0] = (__int64)v14;
  v10 = _mm_loadh_ps((const double *)v13.m128i_i64);
  v13.m128i_i64[0] = (__int64)&v13.m128i_i64[1];
  v17 = v10;
  v11 = _mm_loadl_epi64(&v13);
  v13.m128i_i64[0] = (__int64)&a7;
  v18 = _mm_unpacklo_epi64(v11, _mm_loadl_epi64(&v13));
  v13.m128i_i64[0] = (__int64)&a9;
  v19 = _mm_loadh_ps((const double *)v13.m128i_i64);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_4E30 @ 0x4E30
// ======================================================

void __fastcall sub_4E30(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        char a8,
        __int64 a9,
        __int64 a10,
        int a11,
        int a12)
{
  int v12; // r13d
  __m128 *v13; // r12
  __m128 *v14; // rbp
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128i v17; // xmm2
  __m128i v18; // xmm5
  __m128 v19; // xmm1
  __m128i v20; // xmm4
  __m128i v21; // xmm3
  __m128i v22; // xmm2
  __m128i v23; // xmm1
  __m128i si128; // xmm0
  __m128 v25; // [rsp+0h] [rbp-128h] BYREF
  __m128i v26; // [rsp+10h] [rbp-118h] BYREF
  __m128i v27; // [rsp+20h] [rbp-108h] BYREF
  __m128i v28; // [rsp+30h] [rbp-F8h] BYREF
  __m128i v29; // [rsp+40h] [rbp-E8h] BYREF
  __int64 v30; // [rsp+58h] [rbp-D0h] BYREF
  __int64 v31; // [rsp+60h] [rbp-C8h] BYREF
  __int64 v32; // [rsp+68h] [rbp-C0h]
  __int64 v33[2]; // [rsp+70h] [rbp-B8h] BYREF
  __int64 v34; // [rsp+80h] [rbp-A8h] BYREF
  __int64 v35; // [rsp+88h] [rbp-A0h] BYREF
  __m128i v36; // [rsp+90h] [rbp-98h]
  __m128i v37; // [rsp+A0h] [rbp-88h]
  __m128i v38; // [rsp+B0h] [rbp-78h]
  __m128i v39; // [rsp+C0h] [rbp-68h]
  __m128i v40; // [rsp+D0h] [rbp-58h]
  __int64 *v41; // [rsp+E0h] [rbp-48h]

  v33[1] = a2;
  v33[0] = a3;
  v12 = a12;
  v32 = a4;
  v31 = a5;
  v30 = a6;
  v13 = (__m128 *)sub_35D0(a1, &v34, 4 * a10);
  v14 = (__m128 *)sub_35D0(a1, &v35, 4 * a10);
  if ( a11 )
    sub_4130(a1, 0, v34, 1, v32, v31, a9, a10, 0, v12);
  else
    cuMemsetD32Async();
  v25.m128_u64[0] = (unsigned __int64)v33;
  v15 = _mm_loadh_ps((const double *)v25.m128_u64);
  v25.m128_u64[0] = (unsigned __int64)&v31;
  v29 = (__m128i)v15;
  v16 = _mm_loadh_ps((const double *)v25.m128_u64);
  v25.m128_u64[0] = (unsigned __int64)&v30;
  v17 = _mm_loadl_epi64((const __m128i *)&v25);
  v25.m128_u64[0] = (unsigned __int64)&a7;
  v18 = _mm_loadl_epi64((const __m128i *)&v25);
  v25.m128_u64[0] = (unsigned __int64)&v34;
  v28 = (__m128i)v16;
  v27 = _mm_unpacklo_epi64(v17, v18);
  v19 = _mm_loadh_ps((const double *)v25.m128_u64);
  v25.m128_u64[0] = (unsigned __int64)&a9;
  v26 = (__m128i)v19;
  v25 = _mm_loadh_ps((const double *)v25.m128_u64);
  sub_4AB0(a1, v35, 1, v32, v30, a7, a9, a10, 0, v12);
  v20 = _mm_load_si128(&v29);
  v21 = _mm_load_si128(&v28);
  v22 = _mm_load_si128(&v27);
  v41 = &a10;
  v23 = _mm_load_si128(&v26);
  si128 = _mm_load_si128((const __m128i *)&v25);
  v36 = v20;
  v37 = v21;
  v38 = v22;
  v39 = v23;
  v40 = si128;
  cuLaunchKernel();
  sub_3BD0(a1, v13);
  sub_3BD0(a1, v14);
}

// ======================================================
// Function: sub_4AB0 @ 0x4AB0
// ======================================================

void __fastcall sub_4AB0(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  int v10; // ebx
  __int64 v11; // rax
  __m128 *v12; // r12
  __m128 v13; // xmm2
  unsigned __int64 v14; // rax
  int v15; // esi
  int v16; // r8d
  int v17; // eax
  __int64 v18; // r14
  int v19; // r13d
  __m128 *v20; // rbp
  __m128i v21; // xmm1
  __m128 v22; // xmm0
  __int64 *v23; // rax
  __int64 *v24; // [rsp+8h] [rbp-110h] BYREF
  __int64 v25; // [rsp+10h] [rbp-108h]
  __m128 *v26; // [rsp+18h] [rbp-100h]
  int *v27; // [rsp+20h] [rbp-F8h] BYREF
  int *v28; // [rsp+28h] [rbp-F0h] BYREF
  __m128i v29; // [rsp+30h] [rbp-E8h] BYREF
  int *v30; // [rsp+40h] [rbp-D8h] BYREF
  __int64 v31; // [rsp+48h] [rbp-D0h]
  __int64 v32; // [rsp+50h] [rbp-C8h]
  int v33; // [rsp+58h] [rbp-C0h]
  int v34; // [rsp+5Ch] [rbp-BCh] BYREF
  __int64 v35[2]; // [rsp+60h] [rbp-B8h] BYREF
  int v36; // [rsp+74h] [rbp-A4h] BYREF
  int v37; // [rsp+78h] [rbp-A0h] BYREF
  int v38; // [rsp+7Ch] [rbp-9Ch] BYREF
  __int64 v39; // [rsp+80h] [rbp-98h]
  __int64 v40; // [rsp+88h] [rbp-90h] BYREF
  __m128 v41; // [rsp+90h] [rbp-88h] BYREF
  __m128 v42; // [rsp+A0h] [rbp-78h]
  __m128 v43; // [rsp+B0h] [rbp-68h]
  __m128 v44; // [rsp+C0h] [rbp-58h]
  int *v45; // [rsp+D0h] [rbp-48h]

  v25 = a1;
  v31 = a2;
  v10 = a7;
  v11 = qword_23D1C8;
  v33 = a3;
  if ( a10 )
    v11 = qword_23D1C0;
  v35[1] = a4;
  v12 = 0LL;
  v35[0] = a5;
  v32 = v11;
  v27 = &v38;
  v28 = &a8;
  v26 = &v41;
  v24 = (__int64 *)&v37;
  v34 = a6;
  v39 = 0LL;
  v13 = _mm_loadh_ps((const double *)&v24);
  v37 = 0;
  v29 = (__m128i)v13;
  v30 = &v34;
  while ( 1 )
  {
    if ( v10 > 127 )
    {
      if ( v10 > 1024 )
      {
        v16 = 512;
        v15 = 1024;
      }
      else
      {
        _BitScanReverse64(&v14, v10 - 1LL);
        LOBYTE(v14) = v14 ^ 0x3F;
        v15 = 2 << (63 - v14);
        v16 = 1 << (63 - v14);
      }
    }
    else
    {
      v16 = 64;
      v15 = 128;
    }
    v17 = (v10 + v15 - 1) / v15;
    v18 = v17;
    v19 = v17;
    v10 = v17;
    if ( v17 == 1LL )
    {
      v20 = 0LL;
      v40 = v31;
      v38 = v33;
      v36 = a9;
    }
    else
    {
      LODWORD(v24) = v16;
      v23 = sub_35D0(v25, &v40, 4 * v17 * (__int64)a8);
      v38 = v18;
      v20 = (__m128 *)v23;
      v36 = 0;
    }
    v41 = _mm_loadh_ps((const double *)&v27);
    if ( !v39 )
      break;
    v21 = _mm_load_si128(&v29);
    v45 = &v36;
    v24 = (__int64 *)&a7;
    v42 = (__m128)v21;
    v22 = _mm_loadh_ps((const double *)&v28);
    v43 = (__m128)v21;
    v44 = v22;
    cuLaunchKernel();
    sub_3BD0(v25, v12);
    if ( v18 == 1 )
      return;
LABEL_10:
    a7 = v19;
    v12 = v20;
    v39 = v40;
    v37 = v38;
  }
  v45 = &v36;
  v24 = v35;
  v42 = _mm_loadh_ps((const double *)&v30);
  v24 = (__int64 *)&a7;
  v43 = _mm_loadh_ps((const double *)&v30);
  v44 = _mm_loadh_ps((const double *)&v28);
  cuLaunchKernel();
  if ( v18 != 1 )
    goto LABEL_10;
}

// ======================================================
// Function: sub_33F0 @ 0x33F0
// ======================================================

__int64 __fastcall sub_33F0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        unsigned int a9,
        __int64 a10,
        int a11,
        int a12,
        unsigned int a13,
        unsigned int a14,
        unsigned int a15,
        unsigned int a16,
        unsigned int a17)
{
  __int64 *v19; // rdi
  __int64 v20; // rax
  __int64 v21; // rbp
  __int64 v22; // rdi
  __int64 v23; // rdx
  __int64 v24; // rsi
  int v26; // [rsp+8h] [rbp-20h] BYREF
  int v27[7]; // [rsp+Ch] [rbp-1Ch] BYREF

  v19 = *(__int64 **)(a1 + 24);
  v20 = a17;
  v26 = 1065353216;
  v27[0] = 1065353216;
  if ( a17 )
  {
    if ( a17 != 1 )
      abort();
    v20 = 14LL;
    v21 = 68LL;
  }
  else
  {
    v21 = 75LL;
  }
  v22 = *v19;
  v23 = a12 != 0;
  v24 = a11 != 0;
  if ( a16 == 1 )
    return cublasGemmEx(
             v22,
             v24,
             v23,
             a13,
             a14,
             a15,
             (__int64)&v26,
             a5,
             v20,
             a6,
             a8,
             v20,
             a9,
             (__int64)v27,
             a2,
             v20,
             a3,
             v21,
             -1LL);
  else
    return cublasGemmStridedBatchedEx(
             v22,
             v24,
             v23,
             a13,
             a14,
             a15,
             (__int64)&v26,
             a5,
             v20,
             a6,
             a7,
             a8,
             v20,
             a9,
             a10,
             (__int64)v27,
             a2,
             v20,
             a3,
             a4,
             a16,
             v21,
             -1LL);
}

// ======================================================
// Function: sub_3E70 @ 0x3E70
// ======================================================

void __fastcall sub_3E70(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9)
{
  __int64 v10; // rbp
  __int64 v11; // r12
  __int64 v12; // r15
  __int64 v13; // rbx
  void *v14; // r13
  char *v15; // rax
  char *v16; // r12
  __int64 v17; // r14
  __int64 v18; // rax
  int v19; // r10d
  __int64 v20; // rdx
  char *v21; // rsi
  __int64 v22; // rdx
  __int64 v23; // rdx
  __m128 *v24; // r14
  __m128 v25; // xmm0
  __int64 *v26; // [rsp+8h] [rbp-D0h] BYREF
  __int64 v27; // [rsp+10h] [rbp-C8h]
  size_t n; // [rsp+18h] [rbp-C0h]
  __int64 v29[2]; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v30[3]; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v31; // [rsp+48h] [rbp-90h] BYREF
  __int64 v32[2]; // [rsp+50h] [rbp-88h] BYREF
  __m128 v33; // [rsp+60h] [rbp-78h]
  __m128 v34; // [rsp+70h] [rbp-68h]
  __m128 v35; // [rsp+80h] [rbp-58h]
  __m128 v36; // [rsp+90h] [rbp-48h]

  v10 = a9;
  v29[1] = a5;
  v29[0] = a6;
  v11 = 3LL * a9;
  v30[1] = a2;
  v30[0] = a3;
  v27 = 4LL * a9;
  v12 = nc_malloc(v27);
  cuStreamSynchronize();
  cuMemcpyDtoH_v2();
  v26 = (__int64 *)(4 * v11);
  v13 = nc_malloc(4 * v11);
  n = 4 * a4;
  v14 = (void *)(v13 + 8LL * a9);
  v15 = (char *)nc_malloc(4 * a4);
  v16 = v15;
  if ( a4 )
    memset(v15, 255, 4 * a4);
  if ( a9 > 0 )
  {
    v17 = (unsigned int)(a9 - 1);
    memset(v14, 255, 4 * v17 + 4);
    v18 = 0LL;
    v19 = 0;
    while ( 1 )
    {
      v21 = &v16[4 * *(int *)(v12 + 4 * v18)];
      v22 = *(int *)v21;
      if ( (_DWORD)v22 == -1 )
      {
        v23 = v19++;
        *(_DWORD *)(v13 + 4 * v23) = *(_DWORD *)(v12 + 4 * v18);
        *(_DWORD *)(v13 + 4 * (v10 + v23)) = v18;
        v20 = v18 + 1;
        *(_DWORD *)v21 = v18;
        if ( v18 == v17 )
          break;
      }
      else
      {
        *((_DWORD *)v14 + v22) = v18;
        v20 = v18 + 1;
        *(_DWORD *)v21 = v18;
        if ( v18 == v17 )
          break;
      }
      v18 = v20;
    }
  }
  n = (size_t)&v31;
  v24 = (__m128 *)sub_35D0(a1, &v31, (__int64)v26);
  v32[0] = v31 + v27;
  v32[1] = v31 + v27 + v27;
  cuMemcpyHtoD_v2();
  nc_free();
  nc_free();
  nc_free();
  v26 = v30;
  v33 = _mm_loadh_ps((const double *)&v26);
  v26 = v29;
  v25 = _mm_loadh_ps((const double *)&v26);
  v26 = v32;
  v34 = v25;
  v35 = _mm_loadh_ps((const double *)&v26);
  v26 = (__int64 *)&a8;
  v36 = _mm_loadh_ps((const double *)&v26);
  cuLaunchKernel();
  sub_3BD0(a1, v24);
}

// ======================================================
// Function: sub_3900 @ 0x3900
// ======================================================

__int64 __fastcall sub_3900(float a1, float a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // edx
  __int64 *v8; // [rsp+8h] [rbp-60h] BYREF
  __int64 v9[3]; // [rsp+10h] [rbp-58h] BYREF
  float v10; // [rsp+28h] [rbp-40h]
  float v11; // [rsp+2Ch] [rbp-3Ch] BYREF
  __m128 v12; // [rsp+30h] [rbp-38h]
  __m128 v13; // [rsp+40h] [rbp-28h]
  __m128 v14; // [rsp+50h] [rbp-18h]

  v9[0] = a5;
  v6 = *(_DWORD *)(a6 + 8);
  v9[1] = a4;
  if ( (_BYTE)v6 )
    __assert_fail("(s->n_context % BLOCK_SIZE) == 0", "libnc_cuda.c", 0x5ABu, "cuda_rnd_unif");
  v11 = a1 - a2;
  v10 = a2 + a2;
  v8 = v9;
  v12 = _mm_loadh_ps((const double *)&v8);
  v8 = (__int64 *)&v11;
  v13 = _mm_loadh_ps((const double *)&v8);
  v8 = (__int64 *)(a6 + 8);
  v14 = _mm_loadh_ps((const double *)&v8);
  return cuLaunchKernel();
}

// ======================================================
// Function: sub_2110 @ 0x2110
// ======================================================

__int64 __fastcall sub_2110(float a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // edx
  __int64 *v7; // [rsp+8h] [rbp-60h] BYREF
  __int64 v8[3]; // [rsp+10h] [rbp-58h] BYREF
  float v9; // [rsp+28h] [rbp-40h]
  int v10; // [rsp+2Ch] [rbp-3Ch] BYREF
  __m128 v11; // [rsp+30h] [rbp-38h]
  __m128 v12; // [rsp+40h] [rbp-28h]
  __m128 v13; // [rsp+50h] [rbp-18h]

  v8[0] = a4;
  v5 = *(_DWORD *)(a5 + 8);
  v8[1] = a3;
  if ( (_BYTE)v5 )
    __assert_fail("(s->n_context % BLOCK_SIZE) == 0", "libnc_cuda.c", 0x5C4u, "cuda_rnd_dropout");
  v10 = (int)(float)(a1 * 4294967300.0);
  v7 = v8;
  v9 = 1.0 / (float)(1.0 - a1);
  v11 = _mm_loadh_ps((const double *)&v7);
  v7 = (__int64 *)&v10;
  v12 = _mm_loadh_ps((const double *)&v7);
  v7 = (__int64 *)(a5 + 8);
  v13 = _mm_loadh_ps((const double *)&v7);
  return cuLaunchKernel();
}

