// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_rnd_end
// Included functions: 1

// ======================================================
// Function: nc_rnd_end @ 0x11420
// ======================================================

void __fastcall nc_rnd_end(_QWORD *ptr)
{
  (*(void (__fastcall **)(_QWORD, _QWORD))(*ptr + 56LL))(*ptr, ptr[3]);
  nc_free(ptr);
}

