// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_concat_node
// Included functions: 1

// ======================================================
// Function: nc_concat_node @ 0x66A2D330
// ======================================================

_QWORD *__fastcall nc_concat_node(__int64 a1, __int64 a2, int a3, int a4, __int64 a5)
{
  _QWORD *v9; // rbx
  _QWORD *v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  char *v15; // rax
  __int64 v16; // rdx
  __int64 v18; // rax
  __int64 v19; // rax

  v9 = aligned_malloc(0x80ui64, 0x40ui64);
  if ( !v9 )
  {
    MEMORY[0x10] = 0;
    BUG();
  }
  memset(v9, 0, 0x80ui64);
  *((_DWORD *)v9 + 4) = 1;
  *((_DWORD *)v9 + 5) = 14;
  *((_DWORD *)v9 + 6) = a3;
  v10 = aligned_malloc(8i64 * a3, 0x40ui64);
  v9[4] = v10;
  if ( a3 <= 0 )
  {
    v18 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 72) = v18 + 1;
    v9[12] = v18;
    v19 = *(_QWORD *)(a1 + 32);
    *(_QWORD *)(v19 + 8) = v9;
    *v9 = v19;
    v9[1] = a1 + 32;
    *(_QWORD *)(a1 + 32) = v9;
    *((_DWORD *)v9 + 16) = a4;
    v9[7] = aligned_malloc(8i64 * a3, 0x40ui64);
  }
  else
  {
    v11 = 0i64;
    do
    {
      while ( 1 )
      {
        v12 = *(_QWORD *)(a2 + 8 * v11);
        if ( !v12 )
          break;
        ++*(_DWORD *)(v12 + 16);
        v10[v11++] = v12;
        if ( a3 <= (int)v11 )
          goto LABEL_6;
      }
      v10[v11++] = 0i64;
    }
    while ( a3 > (int)v11 );
LABEL_6:
    v13 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 72) = v13 + 1;
    v9[12] = v13;
    v14 = *(_QWORD *)(a1 + 32);
    *(_QWORD *)(v14 + 8) = v9;
    *v9 = v14;
    v9[1] = a1 + 32;
    *(_QWORD *)(a1 + 32) = v9;
    *((_DWORD *)v9 + 16) = a4;
    v15 = (char *)aligned_malloc(8i64 * a3, 0x40ui64);
    v16 = 0i64;
    v9[7] = v15;
    while ( 1 )
    {
      *(_QWORD *)&v15[v16] = *(_QWORD *)(a5 + v16);
      if ( 8i64 * (unsigned int)(a3 - 1) == v16 )
        break;
      v15 = (char *)v9[7];
      v16 += 8i64;
    }
  }
  return v9;
}

