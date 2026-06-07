// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_start
// Included functions: 1

// ======================================================
// Function: nc_job_start @ 0x2EA60
// ======================================================

__int64 __fastcall nc_job_start(__int64 a1, void (__fastcall *a2)(__int64, _QWORD, __int64), __int64 a3, int a4)
{
  void (__fastcall *v5)(__int64, _QWORD, __int64); // r12
  __int64 v8; // rax
  __int64 v9; // rbx
  bool v10; // cc
  __int64 v11; // rax
  bool v12; // zf
  pthread_cond_t *v13; // rdi
  unsigned int v15; // ebp
  __int64 v16; // rdx

  if ( a4 <= 0 )
    __assert_fail("count >= 1", "job.c", 0x99u, "nc_job_start");
  v5 = a2;
  v8 = nc_mallocz(0x88uLL);
  v9 = v8;
  if ( !v8 )
    return v9;
  pthread_mutex_init((pthread_mutex_t *)(v8 + 48), 0LL);
  pthread_cond_init((pthread_cond_t *)(v9 + 88), 0LL);
  v10 = *(_DWORD *)a1 <= 1;
  *(_QWORD *)(v9 + 16) = a2;
  *(_QWORD *)(v9 + 24) = a3;
  *(_DWORD *)(v9 + 32) = 0;
  *(_DWORD *)(v9 + 36) = a4;
  if ( !v10 )
  {
    *(_DWORD *)(v9 + 40) = 0;
    pthread_mutex_lock((pthread_mutex_t *)(a1 + 32));
    v11 = *(_QWORD *)(a1 + 16);
    v12 = *(_DWORD *)(v9 + 36) == 1;
    v13 = (pthread_cond_t *)(a1 + 72);
    *(_QWORD *)(v11 + 8) = v9;
    *(_QWORD *)v9 = v11;
    *(_QWORD *)(v9 + 8) = a1 + 16;
    *(_QWORD *)(a1 + 16) = v9;
    if ( v12 )
      pthread_cond_signal(v13);
    else
      pthread_cond_broadcast(v13);
    pthread_mutex_unlock((pthread_mutex_t *)(a1 + 32));
    return v9;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = v15++;
    v5(a3, 0LL, v16);
    if ( a4 == v15 )
      break;
    v5 = *(void (__fastcall **)(__int64, _QWORD, __int64))(v9 + 16);
    a3 = *(_QWORD *)(v9 + 24);
  }
  *(_DWORD *)(v9 + 40) = 1;
  return v9;
}

