// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_init
// Included functions: 1

// ======================================================
// Function: nc_job_init @ 0x2E890
// ======================================================

int *__fastcall nc_job_init(int a1)
{
  int v1; // ebp
  int *v2; // rbx
  __int64 v3; // rdi
  int **v4; // rax
  int v5; // esi
  int **v6; // rcx
  int **v7; // rdx
  __int64 v8; // r12
  int v9; // ebp
  unsigned int v10; // eax

  v1 = a1;
  v2 = (int *)nc_mallocz(0x80uLL);
  if ( a1 <= 0 )
    v1 = 1;
  *v2 = v1;
  pthread_mutex_init((pthread_mutex_t *)(v2 + 8), 0LL);
  pthread_cond_init((pthread_cond_t *)(v2 + 18), 0LL);
  v3 = *v2;
  *((_QWORD *)v2 + 2) = v2 + 4;
  *((_QWORD *)v2 + 3) = v2 + 4;
  v4 = (int **)nc_mallocz(16 * v3);
  v5 = *v2;
  *((_QWORD *)v2 + 1) = v4;
  if ( v5 > 0 )
  {
    v6 = v4;
    v7 = &v4[2 * (unsigned int)(v5 - 1) + 2];
    do
    {
      *v4 = v2;
      v4 += 2;
    }
    while ( v7 != v4 );
    if ( v5 != 1 )
    {
      v8 = 0LL;
      v9 = 0;
      while ( 1 )
      {
        v10 = pthread_create((pthread_t *)&v6[v8 + 1], 0LL, (void *(*)(void *))start_routine, &v6[v8]);
        if ( v10 )
        {
          fprintf(stderr, "pthread_create: ret=%d\n", v10);
          abort();
        }
        ++v9;
        v8 += 2LL;
        if ( *v2 <= v9 )
          break;
        v6 = (int **)*((_QWORD *)v2 + 1);
      }
    }
  }
  return v2;
}

