// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_find_param
// Included functions: 1

// ======================================================
// Function: nc_find_param @ 0x2DDB0
// ======================================================

__int64 __fastcall nc_find_param(__int64 a1, const char *a2)
{
  __int64 v2; // rbx

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 == a1 )
    return 0LL;
  while ( strcmp(*(const char **)(v2 + 24), a2) )
  {
    v2 = *(_QWORD *)(v2 + 8);
    if ( v2 == a1 )
      return 0LL;
  }
  return v2;
}

