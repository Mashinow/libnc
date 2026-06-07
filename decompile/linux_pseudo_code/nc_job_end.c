// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_end
// Included functions: 1

// ======================================================
// Function: nc_job_end @ 0x2E980
// ======================================================

void __fastcall nc_job_end(char *ptr)
{
  pthread_mutex_t *v2; // rbp
  pthread_cond_t *v3; // r12
  int v4; // edx
  _QWORD *v5; // rcx
  __int64 v6; // rbx
  pthread_t v7; // rdi

  if ( *((char **)ptr + 3) != ptr + 16 )
    __assert_fail("list_empty(&ts->pending_jobs)", "job.c", 0x59u, "nc_job_end");
  v2 = (pthread_mutex_t *)(ptr + 32);
  v3 = (pthread_cond_t *)(ptr + 72);
  pthread_mutex_lock((pthread_mutex_t *)(ptr + 32));
  *((_DWORD *)ptr + 30) = 1;
  pthread_cond_broadcast((pthread_cond_t *)(ptr + 72));
  pthread_mutex_unlock((pthread_mutex_t *)(ptr + 32));
  v4 = *(_DWORD *)ptr;
  v5 = (_QWORD *)*((_QWORD *)ptr + 1);
  if ( *(int *)ptr > 0 )
  {
    v6 = 0LL;
    do
    {
      while ( 1 )
      {
        v7 = v5[2 * v6 + 1];
        if ( v7 )
          break;
        if ( (int)++v6 >= v4 )
          goto LABEL_7;
      }
      pthread_join(v7, 0LL);
      v4 = *(_DWORD *)ptr;
      ++v6;
      v5 = (_QWORD *)*((_QWORD *)ptr + 1);
    }
    while ( (int)v6 < *(_DWORD *)ptr );
  }
LABEL_7:
  nc_free(v5);
  pthread_mutex_destroy(v2);
  pthread_cond_destroy(v3);
  nc_free(ptr);
}

