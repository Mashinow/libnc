// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_find_param
// Included functions: 1

// ======================================================
// Function: nc_find_param @ 0x66A31AF0
// ======================================================

__int64 __fastcall nc_find_param(__int64 a1, const char *a2)
{
  __int64 v2; // rbx

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 == a1 )
    return 0i64;
  while ( strcmp(*(const char **)(v2 + 24), a2) )
  {
    v2 = *(_QWORD *)(v2 + 8);
    if ( v2 == a1 )
      return 0i64;
  }
  return v2;
}

