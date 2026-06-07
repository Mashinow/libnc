// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_init
// Included functions: 2

// ======================================================
// Function: nc_job_init @ 0x66A32310
// ======================================================

int *__fastcall nc_job_init(int a1)
{
  int *v2; // rbx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  int v5; // ecx
  _QWORD *v6; // r9
  _QWORD *v7; // rdx
  __int64 v8; // rdi
  int v9; // esi
  unsigned int v10; // r12d
  FILE *v12; // rax

  v2 = (int *)nc_mallocz(0x38ui64);
  if ( a1 <= 0 )
    a1 = 1;
  *v2 = a1;
  pthread_mutex_init(v2 + 8, 0i64);
  pthread_cond_init(v2 + 10, 0i64);
  v3 = *v2;
  *((_QWORD *)v2 + 2) = v2 + 4;
  *((_QWORD *)v2 + 3) = v2 + 4;
  v4 = nc_mallocz(16 * v3);
  v5 = *v2;
  v6 = v4;
  *((_QWORD *)v2 + 1) = v4;
  if ( v5 > 0 )
  {
    v7 = &v4[2 * (unsigned int)(v5 - 1) + 2];
    do
    {
      *v4 = v2;
      v4 += 2;
    }
    while ( v7 != v4 );
    if ( v5 != 1 )
    {
      v8 = 0i64;
      v9 = 0;
      while ( 1 )
      {
        v10 = pthread_create(&v6[v8 + 1], 0i64, sub_66A321E0);
        if ( v10 )
        {
          v12 = __iob_func();
          fprintf(v12 + 2, "pthread_create: ret=%d\n", v10);
          abort();
        }
        ++v9;
        v8 += 2i64;
        if ( *v2 <= v9 )
          break;
        v6 = (_QWORD *)*((_QWORD *)v2 + 1);
      }
    }
  }
  return v2;
}

// ======================================================
// Function: sub_66A321E0 @ 0x66A321E0
// ======================================================

__int64 __fastcall sub_66A321E0(__int64 *a1)
{
  __int64 v1; // rsi
  unsigned __int64 v2; // r13
  __int64 v3; // r14
  __int64 *v4; // rbp
  __int64 *v6; // rbx
  unsigned int v7; // ebp
  bool v8; // zf
  int v9; // eax
  __int64 v10; // rdx
  _QWORD *v11; // rax

  v1 = *a1;
  v2 = ((unsigned __int64)a1 - *(_QWORD *)(*a1 + 8)) >> 4;
  _mm_setcsr(0x9FC0u);
  v3 = *a1 + 16;
  while ( 1 )
  {
    pthread_mutex_lock(v1 + 32);
    v4 = *(__int64 **)(v1 + 24);
    if ( v4 == (__int64 *)v3 )
      break;
    v6 = *(__int64 **)(v1 + 24);
LABEL_7:
    if ( *(_DWORD *)(v1 + 48) )
      goto LABEL_6;
    v7 = *((_DWORD *)v6 + 8);
    v8 = v7 + 1 == *((_DWORD *)v6 + 9);
    *((_DWORD *)v6 + 8) = v7 + 1;
    if ( v8 )
    {
      v10 = *v6;
      v11 = (_QWORD *)v6[1];
      *(_QWORD *)(v10 + 8) = v11;
      *v11 = v10;
      *v6 = 0i64;
      v6[1] = 0i64;
    }
    pthread_mutex_unlock(v1 + 32);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))v6[2])(v6[3], (unsigned int)v2, v7);
    pthread_mutex_lock(v6 + 6);
    v9 = *((_DWORD *)v6 + 10) + 1;
    v8 = v9 == *((_DWORD *)v6 + 9);
    *((_DWORD *)v6 + 10) = v9;
    if ( v8 )
      pthread_cond_signal(v6 + 7);
    pthread_mutex_unlock(v6 + 6);
  }
  while ( !*(_DWORD *)(v1 + 48) )
  {
    pthread_cond_wait(v1 + 40, v1 + 32);
    v6 = *(__int64 **)(v1 + 24);
    if ( v6 != v4 )
      goto LABEL_7;
  }
LABEL_6:
  pthread_mutex_unlock(v1 + 32);
  return 0i64;
}

