// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_f32
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_f32 @ 0x66A170C0
// ======================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall nc_tensor_set_f32(__int64 a1, double _XMM1_8)
{
  int v2; // eax

  v2 = *(_DWORD *)(a1 + 48);
  __asm { vmovd   edx, xmm1 }
  if ( v2 )
  {
    if ( v2 != 1 )
      abort();
    __asm { vmovd   eax, xmm1 }
    _EDX = (_EDX + (HIWORD(_EAX) & 1) + 0x7FFF) >> 16;
  }
  return nc_tensor_set_u32(a1, _EDX);
}

