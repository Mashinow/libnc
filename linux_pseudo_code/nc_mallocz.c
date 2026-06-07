// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_mallocz
// Included functions: 1

// ======================================================
// Function: nc_mallocz @ 0x11250
// ======================================================

void *__fastcall nc_mallocz(size_t n)
{
  void *v1; // rax
  void *v2; // rbx

  v1 = (void *)nc_malloc(n);
  v2 = v1;
  if ( v1 )
    memset(v1, 0, n);
  return v2;
}

