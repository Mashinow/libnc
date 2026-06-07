// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_free
// Included functions: 1

// ======================================================
// Function: nc_job_free @ 0x66A32650
// ======================================================

void __fastcall nc_job_free(char *Block)
{
  char *v2; // rsi

  if ( Block )
  {
    v2 = Block + 48;
    pthread_mutex_lock(Block + 48);
    while ( *((_DWORD *)Block + 10) < *((_DWORD *)Block + 9) )
      pthread_cond_wait(Block + 56, v2);
    pthread_mutex_unlock(v2);
    pthread_mutex_destroy(v2);
    pthread_cond_destroy(Block + 56);
    nc_free(Block);
  }
}

