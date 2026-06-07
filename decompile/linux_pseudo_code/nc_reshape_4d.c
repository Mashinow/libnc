// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_reshape_4d
// Included functions: 1

// ======================================================
// Function: nc_reshape_4d @ 0x1BE70
// ======================================================

__int64 __fastcall nc_reshape_4d(void *a1, __int64 _RSI, __int64 a3, __int64 _RCX, __int64 a5, __int64 a6, char a7)
{
  char v15[40]; // [rsp-40h] [rbp-40h] BYREF
  char *v16; // [rsp-18h] [rbp-18h]
  void *v17; // [rsp-8h] [rbp-8h]
  void *retaddr; // [rsp+0h] [rbp+0h]

  __asm { vmovq   xmm3, rsi }
  v17 = retaddr;
  __asm
  {
    vmovq   xmm2, rcx
    vpinsrq xmm0, xmm3, rdx, 1
    vpinsrq xmm1, xmm2, r8, 1
    vinserti128 ymm0, ymm0, xmm1, 1
  }
  v16 = &a7;
  _RDX = v15;
  __asm
  {
    vmovdqa ymmword ptr [rbp-30h], ymm0
    vzeroupper
  }
  return nc_reshape(a1, 4LL, (__int64)v15, _RCX, a5, a6, v15[0]);
}

