// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_error
// Included functions: 1

// ======================================================
// Function: nc_error @ 0x66A12720
// ======================================================

void __noreturn nc_error(char *Format, ...)
{
  FILE *v2; // rax
  FILE *v3; // rax
  FILE *v4; // rax
  va_list va; // [rsp+58h] [rbp+10h] BYREF

  va_start(va, Format);
  v2 = __iob_func();
  fwrite("ERROR: ", 1ui64, 7ui64, v2 + 2);
  v3 = __iob_func();
  vfprintf(v3 + 2, Format, va);
  v4 = __iob_func();
  fputc(10, v4 + 2);
  abort();
}

