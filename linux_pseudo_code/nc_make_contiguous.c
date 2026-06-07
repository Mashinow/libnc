// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_make_contiguous
// Included functions: 1

// ======================================================
// Function: nc_make_contiguous @ 0x1B500
// ======================================================

_BYTE *__fastcall nc_make_contiguous(_BYTE *ptr)
{
  __int64 v3; // rbp
  __int64 v4; // rdi

  if ( ptr[72] )
    return ptr;
  v3 = nc_new_tensor_nz(
         *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL),
         *((unsigned int *)ptr + 12),
         *((unsigned int *)ptr + 20),
         ptr + 120);
  nc_tensor_copy(v3, ptr);
  v4 = *((_QWORD *)ptr + 4);
  if ( v4 )
    *(_QWORD *)(v3 + 32) = nc_dup_node(v4);
  nc_free_tensor(ptr);
  return (_BYTE *)v3;
}

