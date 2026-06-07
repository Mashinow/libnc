// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_error
// Included functions: 1

// ======================================================
// Function: nc_error @ 0x149E0
// ======================================================

void __fastcall __noreturn nc_error(
        char *format,
        __int64 a2,
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
  int arg[2]; // [rsp+8h] [rbp-E0h] BYREF
  char *v17; // [rsp+10h] [rbp-D8h]
  char *v18; // [rsp+18h] [rbp-D0h]
  char v19; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v20; // [rsp+28h] [rbp-C0h]
  __int64 v21; // [rsp+30h] [rbp-B8h]
  __int64 v22; // [rsp+38h] [rbp-B0h]
  __int64 v23; // [rsp+40h] [rbp-A8h]
  __int64 v24; // [rsp+48h] [rbp-A0h]

  v20 = a2;
  v21 = a3;
  v22 = a4;
  v23 = a5;
  v24 = a6;
  if ( v15 )
  {
    __asm
    {
      vmovaps [rsp+0E8h+var_98], xmm0
      vmovaps [rsp+0E8h+var_88], xmm1
      vmovaps [rsp+0E8h+var_78], xmm2
      vmovaps [rsp+0E8h+var_68], xmm3
      vmovaps [rsp+0E8h+var_58], xmm4
      vmovaps [rsp+0E8h+var_48], xmm5
      vmovaps [rsp+0E8h+var_38], xmm6
      vmovaps [rsp+0E8h+var_28], xmm7
    }
  }
  v17 = &a15;
  arg[0] = 8;
  arg[1] = 48;
  v18 = &v19;
  fwrite("ERROR: ", 1uLL, 7uLL, stderr);
  vfprintf(stderr, format, arg);
  fputc(10, stderr);
  abort();
}

