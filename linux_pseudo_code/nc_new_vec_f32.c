// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_vec_f32
// Included functions: 1

// ======================================================
// Function: nc_new_vec_f32 @ 0x1B210
// ======================================================

__int64 __fastcall nc_new_vec_f32(__int64 a1, __int64 a2, __m128 _XMM0)
{
  __int64 v4; // rbx

  if ( !a2 )
    __assert_fail("n >= 1", "libnc.c", 0x151Cu, "nc_new_vec_f32");
  __asm
  {
    vmovss  [rsp+18h+var_C], xmm0
    vmovss  xmm0, [rsp+18h+var_C]
  }
  v4 = nc_new_tensor_nz_1d(a1, 0LL, a2);
  nc_tensor_set_f32(v4, *(double *)&_XMM0);
  return v4;
}

