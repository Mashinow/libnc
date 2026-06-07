// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_name_str
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_name_str @ 0x1B090
// ======================================================

__int64 __fastcall nc_tensor_set_name_str(__int64 a1)
{
  __int64 v1; // rbx

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
  {
    free(*(void **)(v1 + 104));
    *(_QWORD *)(v1 + 104) = __strdup();
  }
  return a1;
}

