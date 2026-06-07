// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_context_init
// Included functions: 1

// ======================================================
// Function: nc_context_init @ 0x66A13900
// ======================================================

void nc_context_init()
{
  unsigned int v5; // r8d
  FILE *v16; // rax

  _RAX = 0i64;
  __asm { cpuid }
  v5 = _RAX;
  if ( (_DWORD)_RAX )
  {
    _RAX = 1i64;
    __asm { cpuid }
    if ( (_RCX & 0x8000000) != 0 )
      __asm { xgetbv }
    if ( v5 > 6 )
    {
      _RAX = 7i64;
      __asm { cpuid }
    }
  }
  v16 = __iob_func();
  fwrite("Your CPU does not support AVX2+FMA - exiting\n", 1ui64, 0x2Dui64, v16 + 2);
  exit(1);
}

