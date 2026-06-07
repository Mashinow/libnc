// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sgd_opt_end
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_end @ 0x2E560
// ======================================================

void __fastcall nc_sgd_opt_end(void **ptr)
{
  if ( ptr[2] != ptr + 1 )
    __assert_fail("list_empty(&s->var_list)", "libnc.c", 0x24E4u, "nc_sgd_opt_end");
  ((void (__fastcall *)(void *))ptr[7])(ptr[3]);
  nc_free(ptr);
}

