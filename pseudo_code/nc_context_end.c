// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_context_end
// Included functions: 1

// ======================================================
// Function: nc_context_end @ 0x66A13EC0
// ======================================================

void __fastcall nc_context_end(_QWORD *a1)
{
  __int64 v1; // rdx
  _QWORD *i; // rax
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  __int64 j; // r8
  _QWORD *v7; // rax
  __int64 k; // r9
  _QWORD *v9; // rbx
  _QWORD *v10; // rsi
  void *v11; // rcx

  v1 = 0i64;
  for ( i = (_QWORD *)a1[1]; i != a1; v1 = (unsigned int)(v1 + 1) )
    i = (_QWORD *)i[1];
  v4 = (_QWORD *)a1[3];
  v5 = a1 + 2;
  for ( j = 0i64; v4 != v5; j = (unsigned int)(j + 1) )
    v4 = (_QWORD *)v4[1];
  v7 = (_QWORD *)a1[5];
  for ( k = 0i64; v7 != a1 + 4; k = (unsigned int)(k + 1) )
    v7 = (_QWORD *)v7[1];
  if ( (unsigned int)k | (unsigned int)j | (unsigned int)v1 )
    printf("ERROR: %d leaking tensor buffer(s), %d leaking tensor(s), %d leaking node(s)\n", v1, j, k);
  v9 = (_QWORD *)a1[7];
  v10 = (_QWORD *)v9[1];
  if ( v9 != a1 + 6 )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(_QWORD *))v9[5])(v9);
      v11 = v9;
      v9 = v10;
      _aligned_free(v11);
      if ( a1 + 6 == v10 )
        break;
      v10 = (_QWORD *)v10[1];
    }
  }
  _aligned_free(a1);
}

