// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_rnd_init
// Included functions: 1

// ======================================================
// Function: nc_rnd_init @ 0x66A10680
// ======================================================

_QWORD *__fastcall nc_rnd_init(__int64 a1, int a2)
{
  _QWORD *v4; // rax
  _QWORD *v5; // rbx
  _DWORD *v6; // rsi
  __int64 v7; // r9
  __int64 v8; // rcx
  int v9; // edx
  char *v10; // r8
  __int64 v11; // rax
  char *v12; // r11
  __int64 v13; // r10
  __int64 v14; // r9
  __int64 v15; // rcx
  int v16; // ebp
  int v17; // edx
  int v18; // edx
  int v19; // edx
  int v20; // edx
  int v21; // edx
  __int64 v22; // rax
  __int64 v23; // rdx

  v4 = aligned_malloc(0x20ui64, 0x40ui64);
  v5 = v4;
  if ( !v4 )
  {
    MEMORY[0] = a1;
    BUG();
  }
  v4[1] = 0i64;
  v4[2] = 0i64;
  v4[3] = 0i64;
  *v4 = a1;
  *((_DWORD *)v4 + 2) = 0x2000;
  v6 = aligned_malloc(0x30000ui64, 0x40ui64);
  v7 = *((int *)v5 + 2);
  v8 = 4 * v7;
  v9 = a2 + 123456789;
  if ( a2 == -123456789 )
    v9 = 1;
  v10 = (char *)&v6[(unsigned __int64)v8 / 4];
  v11 = 1i64;
  if ( (int)v7 > 0 )
  {
    v12 = &v10[v8];
    v13 = (__int64)&v10[v8 + v8];
    v14 = v13 + v8;
    v15 = v13 + v8 + v8;
    do
    {
      v16 = v11;
      v17 = 1103515245 * v9 + 12347;
      v6[v11 - 1] = v17;
      v18 = 1103515245 * v17 + 12347;
      *(_DWORD *)&v10[4 * v11 - 4] = v18;
      v19 = 1103515245 * v18 + 12347;
      *(_DWORD *)&v12[4 * v11 - 4] = v19;
      v20 = 1103515245 * v19 + 12347;
      *(_DWORD *)(v13 + 4 * v11 - 4) = v20;
      v21 = 1103515245 * v20 + 12347;
      *(_DWORD *)(v14 + 4 * v11 - 4) = v21;
      v9 = 1103515245 * v21 + 12347;
      *(_DWORD *)(v15 + 4 * v11++ - 4) = v9;
    }
    while ( *((_DWORD *)v5 + 2) > v16 );
  }
  v22 = (*(__int64 (__fastcall **)(__int64, _QWORD *, __int64))(a1 + 48))(a1, v5 + 2, 196608i64);
  v23 = v5[2];
  v5[3] = v22;
  (*(void (__fastcall **)(__int64, __int64, _DWORD *, __int64))(a1 + 88))(a1, v23, v6, 196608i64);
  _aligned_free(v6);
  return v5;
}

