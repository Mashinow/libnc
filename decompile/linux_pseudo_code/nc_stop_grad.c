// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_stop_grad
// Included functions: 1

// ======================================================
// Function: nc_stop_grad @ 0x1B190
// ======================================================

unsigned int *__fastcall nc_stop_grad(unsigned int *ptr)
{
  __int64 v1; // rbp

  if ( !*((_QWORD *)ptr + 4) )
    return ptr;
  if ( ptr[4] == 1 )
  {
    nc_free_node(*((void **)ptr + 4));
    *((_QWORD *)ptr + 4) = 0LL;
    return ptr;
  }
  else
  {
    v1 = nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL), ptr[12], ptr[20], ptr + 30);
    nc_tensor_copy(v1, ptr);
    nc_free_tensor(ptr);
    return (unsigned int *)v1;
  }
}

