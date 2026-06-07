// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_topk
// Included functions: 2

// ======================================================
// Function: nc_topk @ 0x2DA20
// ======================================================

__int64 __fastcall nc_topk(
        _QWORD *a1,
        __int64 a2,
        _DWORD *a3,
        unsigned __int64 a4,
        unsigned int a5,
        __m128 _XMM0,
        __m128 a7,
        __m128 _XMM2)
{
  __int64 v12; // rax
  bool v15; // cf
  int v16; // esi
  char *v17; // r14
  __int64 v19; // rax
  __int64 result; // rax
  unsigned int v29[15]; // [rsp+1Ch] [rbp-3Ch] BYREF

  __asm { vmovss  [rsp+58h+var_50], xmm0 }
  if ( !a4 )
    __assert_fail("n_symb >= 1", "libnc.c", 0x2425u, "nc_topk");
  _R12 = a3;
  _RBX = a2;
  sub_6690(v29, a3, a4, a5, _XMM0, a7);
  __asm { vmovss  [rsp+58h+var_4C], xmm0 }
  v12 = nc_malloc(8LL * (int)v29[0]);
  __asm { vmovss  xmm0, [rsp+58h+var_4C] }
  _RDX = 0LL;
  v15 = 0;
  v16 = 0;
  v17 = (char *)v12;
  do
  {
    __asm
    {
      vmovss  xmm1, dword ptr [r12+rdx*4]
      vucomiss xmm1, xmm0
    }
    if ( !v15 )
    {
      v19 = v16++;
      _RAX = &v17[8 * v19];
      *((_DWORD *)_RAX + 1) = _RDX;
      __asm { vmovss  dword ptr [rax], xmm1 }
    }
    v15 = a4 < ++_RDX;
  }
  while ( a4 != _RDX );
  if ( v29[0] != v16 )
    __assert_fail("j == k1", "libnc.c", 0x2432u, "nc_topk");
  qsort(v17, v16, 8uLL, (__compar_fn_t)compar);
  result = a5;
  __asm { vxorpd  xmm0, xmm0, xmm0 }
  if ( (int)v29[0] <= (int)a5 )
    result = v29[0];
  if ( (int)result > 0 )
  {
    __asm
    {
      vxorpd  xmm0, xmm0, xmm0
      vxorpd  xmm2, xmm2, xmm2
      vcvtss2sd xmm2, xmm2, [rsp+58h+var_50]
      vcvtss2sd xmm0, xmm0, dword ptr [r12+rdx*4]
      vaddsd  xmm0, xmm0, cs:qword_30A88
      vucomisd xmm0, xmm2
    }
    result = 1LL;
  }
  *a1 = v17;
  __asm { vmovsd  qword ptr [rbx], xmm0 }
  return result;
}

// ======================================================
// Function: sub_6690 @ 0x6690
// ======================================================

__int64 __fastcall sub_6690(unsigned int *a1, _DWORD *a2, __int64 a3, unsigned int a4, __m128 _XMM0, __m128 _XMM1)
{
  _DWORD *v9; // rdx
  __int64 result; // rax
  unsigned int v15; // edx
  unsigned int v17; // ecx
  int s[256]; // [rsp+10h] [rbp-C38h] BYREF
  __int64 v22[263]; // [rsp+410h] [rbp-838h] BYREF

  __asm { vmovss  [rsp+0C48h+var_C3C], xmm0 }
  memset(s, 0, sizeof(s));
  memset(v22, 0, 0x800uLL);
  __asm { vmovss  xmm0, [rsp+0C48h+var_C3C] }
  if ( a3 )
  {
    v9 = &a2[a3];
    do
    {
      __asm { vxorpd  xmm1, xmm1, xmm1 }
      _RAX = (unsigned __int8)(*a2 >> 23);
      __asm { vcvtss2sd xmm1, xmm1, dword ptr [rsi] }
      ++a2;
      ++s[_RAX];
      __asm
      {
        vaddsd  xmm1, xmm1, [rsp+rax*8+0C48h+var_838]
        vmovsd  [rsp+rax*8+0C48h+var_838], xmm1
      }
    }
    while ( v9 != a2 );
  }
  __asm { vxorpd  xmm1, xmm1, xmm1 }
  result = 254LL;
  v15 = 0;
  __asm { vcvtss2sd xmm0, xmm0, xmm0 }
  do
  {
    __asm { vaddsd  xmm1, xmm1, qword ptr [r12+rax*8] }
    v17 = v15 + s[result];
    v15 = v17;
    if ( v17 >= a4 )
      goto LABEL_8;
    __asm { vucomisd xmm1, xmm0 }
    if ( v17 >= a4 )
    {
LABEL_8:
      result = (unsigned int)((_DWORD)result << 23);
      __asm { vmovd   xmm0, eax }
      goto LABEL_9;
    }
    --result;
  }
  while ( result );
  __asm { vxorps  xmm0, xmm0, xmm0 }
LABEL_9:
  *a1 = v17;
  return result;
}

