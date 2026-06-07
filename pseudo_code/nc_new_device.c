// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_device
// Included functions: 1

// ======================================================
// Function: nc_new_device @ 0x66A13E80
// ======================================================

__int64 __fastcall nc_new_device(__int64 a1, const char *a2)
{
  if ( !strcmp(a2, "cpu") )
    return *(_QWORD *)(a1 + 64);
  else
    return 0i64;
}

