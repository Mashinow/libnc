// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_context_end
// Included functions: 1

// ======================================================
// Function: nc_context_end @ 0x162E0
// ======================================================

void __fastcall nc_context_end(char *ptr)
{
  __int64 v1; // rsi
  char *i; // rax
  char *v4; // rax
  __int64 j; // rdx
  __int64 v6; // rax
  char *v7; // rdi
  __int64 k; // rcx
  char *v9; // rbx
  char *v10; // rbp
  char *v11; // rdi

  v1 = 0LL;
  for ( i = (char *)*((_QWORD *)ptr + 1); i != ptr; v1 = (unsigned int)(v1 + 1) )
    i = (char *)*((_QWORD *)i + 1);
  v4 = (char *)*((_QWORD *)ptr + 3);
  for ( j = 0LL; v4 != ptr + 16; j = (unsigned int)(j + 1) )
    v4 = (char *)*((_QWORD *)v4 + 1);
  v6 = *((_QWORD *)ptr + 5);
  v7 = ptr + 32;
  for ( k = 0LL; (char *)v6 != v7; k = (unsigned int)(k + 1) )
    v6 = *(_QWORD *)(v6 + 8);
  if ( (unsigned int)k | (unsigned int)j | (unsigned int)v1 )
    printf("ERROR: %d leaking tensor buffer(s), %d leaking tensor(s), %d leaking node(s)\n", v1, j, k);
  v9 = (char *)*((_QWORD *)ptr + 7);
  v10 = (char *)*((_QWORD *)v9 + 1);
  if ( v9 != ptr + 48 )
  {
    while ( 1 )
    {
      (*((void (__fastcall **)(char *))v9 + 5))(v9);
      v11 = v9;
      v9 = v10;
      nc_free(v11);
      if ( ptr + 48 == v10 )
        break;
      v10 = (char *)*((_QWORD *)v10 + 1);
    }
  }
  nc_free(ptr);
}

