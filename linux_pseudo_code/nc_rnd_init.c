// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_rnd_init
// Included functions: 1

// ======================================================
// Function: nc_rnd_init @ 0x11300
// ======================================================

__int64 __fastcall nc_rnd_init(__int64 a1, int a2)
{
  __int64 v4; // rax
  __int64 v5; // rbp
  _DWORD *v6; // r12
  __int64 v7; // rdi
  __int64 v8; // rdx
  int v9; // esi
  char *v10; // rcx
  char *v11; // r9
  __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rdi
  __int64 v15; // rdx
  int v16; // r10d
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  __int64 v22; // rax
  __int64 v23; // rsi

  v4 = nc_mallocz(0x20uLL);
  *(_QWORD *)v4 = a1;
  v5 = v4;
  *(_DWORD *)(v4 + 8) = 0x2000;
  v6 = (_DWORD *)nc_malloc((size_t)"nc_tensor_set_rnd_unif");
  v7 = *(int *)(v5 + 8);
  v8 = 4 * v7;
  v9 = a2 + 123456789;
  if ( a2 == -123456789 )
    v9 = 1;
  v10 = (char *)&v6[(unsigned __int64)v8 / 4];
  if ( (int)v7 > 0 )
  {
    v11 = &v10[v8];
    v12 = 1LL;
    v13 = (__int64)&v10[v8 + v8];
    v14 = v13 + v8;
    v15 = v13 + v8 + v8;
    do
    {
      v16 = v12;
      v17 = 1103515245 * v9 + 12347;
      v6[v12 - 1] = v17;
      v18 = 1103515245 * v17 + 12347;
      *(_DWORD *)&v10[4 * v12 - 4] = v18;
      v19 = 1103515245 * v18 + 12347;
      *(_DWORD *)&v11[4 * v12 - 4] = v19;
      v20 = 1103515245 * v19 + 12347;
      *(_DWORD *)(v13 + 4 * v12 - 4) = v20;
      v21 = 1103515245 * v20 + 12347;
      *(_DWORD *)(v14 + 4 * v12 - 4) = v21;
      v9 = 1103515245 * v21 + 12347;
      *(_DWORD *)(v15 + 4 * v12++ - 4) = v9;
    }
    while ( *(_DWORD *)(v5 + 8) > v16 );
  }
  v22 = (*(__int64 (__fastcall **)(__int64, __int64, const char *, char *))(a1 + 48))(
          a1,
          v5 + 16,
          "nc_tensor_set_rnd_unif",
          v10);
  v23 = *(_QWORD *)(v5 + 16);
  *(_QWORD *)(v5 + 24) = v22;
  (*(void (__fastcall **)(__int64, __int64, _DWORD *, const char *))(a1 + 88))(a1, v23, v6, "nc_tensor_set_rnd_unif");
  nc_free(v6);
  return v5;
}

