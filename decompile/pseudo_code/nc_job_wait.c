// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_wait
// Included functions: 1

// ======================================================
// Function: nc_job_wait @ 0x66A32600
// ======================================================

__int64 __fastcall nc_job_wait(__int64 a1)
{
  __int64 v1; // rsi
  __int64 v3; // rdi

  v1 = a1 + 48;
  v3 = a1 + 56;
  pthread_mutex_lock(a1 + 48);
  while ( *(_DWORD *)(a1 + 40) < *(_DWORD *)(a1 + 36) )
    pthread_cond_wait(v3, v1);
  return pthread_mutex_unlock(v1);
}

