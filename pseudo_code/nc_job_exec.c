// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_exec
// Included functions: 1

// ======================================================
// Function: nc_job_exec @ 0x66A326F0
// ======================================================

void __fastcall nc_job_exec(__int64 a1, void (__fastcall *a2)(__int64, _QWORD, __int64), __int64 a3, int a4)
{
  __int64 v4; // rax
  _DWORD *v5; // rbx
  __int64 v6; // rsi

  v4 = nc_job_start(a1, a2, a3, a4);
  v5 = (_DWORD *)v4;
  if ( v4 )
  {
    v6 = v4 + 48;
    pthread_mutex_lock(v4 + 48);
    while ( v5[10] < v5[9] )
      pthread_cond_wait(v5 + 14, v6);
    pthread_mutex_unlock(v6);
    pthread_mutex_destroy(v6);
    pthread_cond_destroy(v5 + 14);
    nc_free(v5);
  }
}

