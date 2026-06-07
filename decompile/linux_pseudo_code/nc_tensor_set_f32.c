// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_f32
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_f32 @ 0x189E0
// ======================================================

__int64 __fastcall nc_tensor_set_f32(__int64 a1, __int64 _RSI, __m128 _XMM0)
{
  int v3; // eax

  v3 = *(_DWORD *)(a1 + 48);
  __asm { vmovd   esi, xmm0 }
  if ( v3 )
  {
    if ( v3 != 1 )
      abort();
    __asm { vmovd   eax, xmm0 }
    _RSI = ((unsigned int)_RSI + (HIWORD(_EAX) & 1) + 0x7FFF) >> 16;
  }
  return nc_tensor_set_u32(a1, _RSI);
}

