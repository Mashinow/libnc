// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_name_str
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_name_str @ 0x66A19C50
// ======================================================

__int64 __fastcall nc_tensor_set_name_str(__int64 a1, const char *a2)
{
  __int64 v2; // rbx

  v2 = *(_QWORD *)(a1 + 32);
  if ( v2 )
  {
    free(*(void **)(v2 + 104));
    *(_QWORD *)(v2 + 104) = strdup(a2);
  }
  return a1;
}

