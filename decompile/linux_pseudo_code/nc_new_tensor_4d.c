// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_4d
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_4d @ 0x16C40
// ======================================================

__int64 __fastcall nc_new_tensor_4d(__int64 a1, __int64 a2, __int64 _RDX, __int64 a4, __int64 _R8, __int64 a6, char a7)
{
  _QWORD v15[8]; // [rsp-40h] [rbp-40h] BYREF
  void *retaddr; // [rsp+0h] [rbp+0h]

  __asm { vmovq   xmm3, rdx }
  v15[7] = retaddr;
  __asm
  {
    vmovq   xmm2, r8
    vpinsrq xmm0, xmm3, rcx, 1
    vpinsrq xmm1, xmm2, r9, 1
    vinserti128 ymm0, ymm0, xmm1, 1
  }
  v15[5] = &a7;
  _RCX = v15;
  __asm
  {
    vmovdqa ymmword ptr [rbp-30h], ymm0
    vzeroupper
  }
  return nc_new_tensor(a1, a2, 4LL, v15);
}

