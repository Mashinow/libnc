// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_f32
// Included functions: 1

// ======================================================
// Function: nc_new_f32 @ 0x1B270
// ======================================================

__int64 __fastcall nc_new_f32(__int64 a1, __m128 _XMM0)
{
  __int64 v3; // rbx

  __asm
  {
    vmovss  [rsp+18h+var_C], xmm0
    vmovss  xmm0, [rsp+18h+var_C]
  }
  v3 = nc_new_scalar(a1, 0LL);
  nc_tensor_set_f32(v3, *(double *)&_XMM0);
  return v3;
}

