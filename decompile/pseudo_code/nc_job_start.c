// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_job_start
// Included functions: 3

// ======================================================
// Function: nc_job_start @ 0x66A324D0
// ======================================================

__int64 __fastcall nc_job_start(__int64 a1, void (__fastcall *a2)(__int64, _QWORD, __int64), __int64 a3, int a4)
{
  char *v8; // rax
  __int64 v9; // rbx
  bool v10; // cc
  __int64 v11; // rax
  bool v12; // zf
  __int64 v13; // rcx
  __int64 result; // rax
  unsigned int v15; // esi
  __int64 v16; // r8

  if ( a4 <= 0 )
    sub_66A33D40("count >= 1", "job.c", 153);
  v8 = (char *)nc_mallocz(0x40ui64);
  v9 = (__int64)v8;
  if ( !v8 )
    return v9;
  pthread_mutex_init(v8 + 48, 0i64);
  pthread_cond_init(v9 + 56, 0i64);
  v10 = *(_DWORD *)a1 <= 1;
  *(_QWORD *)(v9 + 16) = a2;
  *(_QWORD *)(v9 + 24) = a3;
  *(_DWORD *)(v9 + 32) = 0;
  *(_DWORD *)(v9 + 36) = a4;
  if ( !v10 )
  {
    *(_DWORD *)(v9 + 40) = 0;
    pthread_mutex_lock(a1 + 32);
    v11 = *(_QWORD *)(a1 + 16);
    v12 = *(_DWORD *)(v9 + 36) == 1;
    v13 = a1 + 40;
    *(_QWORD *)(v11 + 8) = v9;
    *(_QWORD *)v9 = v11;
    *(_QWORD *)(v9 + 8) = a1 + 16;
    *(_QWORD *)(a1 + 16) = v9;
    if ( v12 )
      pthread_cond_signal(v13);
    else
      pthread_cond_broadcast(v13);
    pthread_mutex_unlock(a1 + 32);
    return v9;
  }
  if ( a4 > 0 )
  {
    v15 = 0;
    while ( 1 )
    {
      v16 = v15++;
      a2(a3, 0i64, v16);
      if ( a4 == v15 )
        break;
      a2 = *(void (__fastcall **)(__int64, _QWORD, __int64))(v9 + 16);
      a3 = *(_QWORD *)(v9 + 24);
    }
  }
  result = v9;
  *(_DWORD *)(v9 + 40) = 1;
  return result;
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

