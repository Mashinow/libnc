// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_name
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_name @ 0x1B0C0
// ======================================================

__int64 __fastcall nc_tensor_set_name(
        __int64 a1,
        const char *a2,
        __int64 a3,
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
  __int64 v22; // [rsp+70h] [rbp-B8h]
  __int64 v23; // [rsp+78h] [rbp-B0h]
  __int64 v24; // [rsp+80h] [rbp-A8h]
  __int64 v25; // [rsp+88h] [rbp-A0h]

  v22 = a3;
  v23 = a4;
  v24 = a5;
  v25 = a6;
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
  v18 = &a15;
  arg[0] = 16;
  arg[1] = 48;
  v19 = &v21;
  vsnprintf(s, 0x40uLL, a2, arg);
  return nc_tensor_set_name_str(a1, s);
}

