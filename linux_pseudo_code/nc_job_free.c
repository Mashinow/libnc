// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_free
// Included functions: 1

// ======================================================
// Function: nc_job_free @ 0x2EBC0
// ======================================================

void __fastcall nc_job_free(char *ptr)
{
  if ( ptr )
  {
    nc_job_wait();
    pthread_mutex_destroy((pthread_mutex_t *)(ptr + 48));
    pthread_cond_destroy((pthread_cond_t *)(ptr + 88));
    nc_free(ptr);
  }
}

