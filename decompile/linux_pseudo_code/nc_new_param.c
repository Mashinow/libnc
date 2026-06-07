// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_param
// Included functions: 1

// ======================================================
// Function: nc_new_param @ 0x2DC70
// ======================================================

__int64 __fastcall nc_new_param(
        __int64 a1,
        __int64 a2,
        const char *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __m128 _XMM0,
        __m128 _XMM1,
        __m128 _XMM2,
        __m128 _XMM3,
        __m128 _XMM4,
        __m128 _XMM5,
        __m128 _XMM6,
        __m128 _XMM7,
        char a15)
{
  char v15; // al
  int arg[2]; // [rsp+8h] [rbp-120h] BYREF
  char *v18; // [rsp+10h] [rbp-118h]
  char *v19; // [rsp+18h] [rbp-110h]
  char s[64]; // [rsp+20h] [rbp-108h] BYREF
  char v21; // [rsp+60h] [rbp-C8h] BYREF
  __int64 v22; // [rsp+78h] [rbp-B0h]
  __int64 v23; // [rsp+80h] [rbp-A8h]
  __int64 v24; // [rsp+88h] [rbp-A0h]

  v22 = a4;
  v23 = a5;
  v24 = a6;
  if ( v15 )
  {
    __asm
    {
      vmovaps [rsp+128h+var_98], xmm0
      vmovaps [rsp+128h+var_88], xmm1
      vmovaps [rsp+128h+var_78], xmm2
      vmovaps [rsp+128h+var_68], xmm3
      vmovaps [rsp+128h+var_58], xmm4
      vmovaps [rsp+128h+var_48], xmm5
      vmovaps [rsp+128h+var_38], xmm6
      vmovaps [rsp+128h+var_28], xmm7
    }
  }
  arg[0] = 24;
  arg[1] = 48;
  v18 = &a15;
  v19 = &v21;
  vsnprintf(s, 0x40uLL, a3, arg);
  return nc_new_param_str(a1, a2, s);
}

