// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_to_device
// Included functions: 1

// ======================================================
// Function: nc_tensor_to_device @ 0x19DF0
// ======================================================

_QWORD *__fastcall nc_tensor_to_device(_QWORD *ptr, __int64 a2)
{
  _QWORD *v2; // rbp

  v2 = ptr;
  if ( *(_QWORD *)(ptr[5] + 24LL) != a2 )
  {
    v2 = (_QWORD *)nc_new_tensor_nz(a2, *((unsigned int *)ptr + 12), *((unsigned int *)ptr + 20), ptr + 15);
    nc_tensor_copy(v2, ptr);
    if ( ptr[4] )
      v2[4] = nc_dup_node();
    nc_free_tensor(ptr);
  }
  return v2;
}

