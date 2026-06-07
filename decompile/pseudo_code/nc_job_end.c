// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_end
// Included functions: 3

// ======================================================
// Function: nc_job_end @ 0x66A32400
// ======================================================

void __fastcall nc_job_end(void **Block)
{
  int v2; // eax
  char *v3; // rdx
  __int64 v4; // rsi
  int v5; // ebx
  __int64 v6; // rcx

  if ( Block[3] != Block + 2 )
    sub_66A33D40("list_empty(&ts->pending_jobs)", "job.c", 89);
  pthread_mutex_lock(Block + 4);
  *((_DWORD *)Block + 12) = 1;
  pthread_cond_broadcast(Block + 5);
  pthread_mutex_unlock(Block + 4);
  v2 = *(_DWORD *)Block;
  v3 = (char *)Block[1];
  if ( *(int *)Block > 0 )
  {
    v4 = 0i64;
    v5 = 0;
    do
    {
      while ( 1 )
      {
        v6 = *(_QWORD *)&v3[v4 + 8];
        if ( v6 )
          break;
        ++v5;
        v4 += 16i64;
        if ( v5 >= v2 )
          goto LABEL_8;
      }
      ++v5;
      v4 += 16i64;
      pthread_join(v6, 0i64);
      v2 = *(_DWORD *)Block;
      v3 = (char *)Block[1];
    }
    while ( v5 < *(_DWORD *)Block );
  }
LABEL_8:
  nc_free(v3);
  pthread_mutex_destroy(Block + 4);
  pthread_cond_destroy(Block + 5);
  nc_free(Block);
}

// ======================================================
// Function: sub_66A33D40 @ 0x66A33D40
// ======================================================

void __fastcall sub_66A33D40(const char *a1, const char *a2, int a3)
{
  size_t v5; // rax
  wchar_t *v6; // rsi
  size_t v7; // rax
  const wchar_t *v8; // rax
  wchar_t v9; // cx
  __int64 v10; // r9
  wchar_t *v11; // rbx
  wchar_t v12; // cx
  __int64 v13; // r9

  v5 = strlen(a1);
  v6 = (wchar_t *)malloc(2 * v5 + 2);
  v7 = strlen(a2);
  v8 = (const wchar_t *)malloc(2 * v7 + 2);
  v9 = *(unsigned __int8 *)a1;
  v10 = 0i64;
  v11 = (wchar_t *)v8;
  if ( (_BYTE)v9 )
  {
    do
    {
      v6[v10++] = v9;
      v9 = (unsigned __int8)a1[v10];
    }
    while ( (_BYTE)v9 );
    v10 *= 2i64;
  }
  v12 = *(unsigned __int8 *)a2;
  *(wchar_t *)((char *)v6 + v10) = 0;
  v13 = 0i64;
  if ( (_BYTE)v12 )
  {
    do
    {
      v8[v13++] = v12;
      v12 = (unsigned __int8)a2[v13];
    }
    while ( (_BYTE)v12 );
    v13 *= 2i64;
  }
  *(const wchar_t *)((char *)v8 + v13) = 0;
  sub_66A33C00(v6, v8, a3);
  free(v6);
  free(v11);
}

// ======================================================
// Function: sub_66A33C00 @ 0x66A33C00
// ======================================================

int __fastcall sub_66A33C00(const wchar_t *a1, const wchar_t *a2, int a3)
{
  wchar_t *v6; // rbp
  int result; // eax
  FILE *v8; // rax
  WCHAR Filename[284]; // [rsp+40h] [rbp-238h] BYREF

  v6 = (wchar_t *)malloc(0x4000ui64);
  if ( a2 )
  {
    if ( !*a2 )
      a2 = L"<unknown>";
  }
  else
  {
    a2 = L"<unknown>";
  }
  if ( a1 )
  {
    if ( !*a1 )
      a1 = L"?";
  }
  else
  {
    a1 = L"?";
  }
  if ( !GetModuleFileNameW(0i64, Filename, 0x104u) )
    wcscpy(Filename, L"<unknown>");
  snwprintf(
    v6,
    0x1FFFui64,
    L"Assertion failed!\n\nProgram: %ws\nFile: %ws, Line %u\n\nExpression: %ws",
    Filename,
    a2,
    a3,
    a1);
  if ( !unk_66A3D5B0 )
  {
    v8 = _iob_func();
    fwprintf(v8 + 2, L"%ws\n", v6);
    abort();
  }
  result = MessageBoxW(0i64, v6, L"MinGW Runtime Assertion", 0x12012u);
  if ( result == 3 )
  {
    raise(22);
    exit(3);
  }
  if ( result != 5 )
    abort();
  return result;
}

