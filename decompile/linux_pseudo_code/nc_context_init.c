// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_context_init
// Included functions: 1

// ======================================================
// Function: nc_context_init @ 0x15B30
// ======================================================

void nc_context_init()
{
  unsigned int v5; // esi

  _RAX = 0LL;
  __asm { cpuid }
  if ( (_DWORD)_RAX )
  {
    v5 = _RAX;
    _RAX = 1LL;
    __asm { cpuid }
    if ( (_RCX & 0x8000000) != 0 )
      __asm { xgetbv }
    if ( v5 > 6 )
    {
      _RAX = 7LL;
      __asm { cpuid }
    }
  }
  fwrite("Your CPU does not support AVX2+FMA - exiting\n", 1uLL, 0x2DuLL, stderr);
  exit(1);
}

