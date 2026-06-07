// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_wait
// Included functions: 1

// ======================================================
// Function: nc_job_wait @ 0x2EB80
// ======================================================

int __fastcall nc_job_wait(__int64 a1)
{
  pthread_mutex_t *v1; // rbp

  v1 = (pthread_mutex_t *)(a1 + 48);
  pthread_mutex_lock((pthread_mutex_t *)(a1 + 48));
  while ( *(_DWORD *)(a1 + 40) < *(_DWORD *)(a1 + 36) )
    pthread_cond_wait((pthread_cond_t *)(a1 + 88), v1);
  return pthread_mutex_unlock(v1);
}

