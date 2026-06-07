// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_concat_node
// Included functions: 1

// ======================================================
// Function: nc_concat_node @ 0x28710
// ======================================================

__int64 __fastcall nc_concat_node(__int64 a1, __int64 a2, int a3, int a4, __int64 a5)
{
  __int64 v7; // r15
  __int64 v8; // rax
  __int64 v9; // rbx
  __int64 v10; // r13
  __int64 v11; // rbp
  __int64 v12; // rdi
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 size; // [rsp+8h] [rbp-50h]

  v7 = nc_mallocz(0x80uLL);
  *(_DWORD *)(v7 + 16) = 1;
  *(_DWORD *)(v7 + 20) = 14;
  *(_DWORD *)(v7 + 24) = a3;
  size = 8LL * a3;
  v8 = nc_malloc(size);
  *(_QWORD *)(v7 + 32) = v8;
  if ( a3 <= 0 )
  {
    v18 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 72) = v18 + 1;
    *(_QWORD *)(v7 + 96) = v18;
    v19 = *(_QWORD *)(a1 + 32);
    *(_QWORD *)(v19 + 8) = v7;
    *(_QWORD *)v7 = v19;
    *(_QWORD *)(v7 + 8) = a1 + 32;
    *(_QWORD *)(a1 + 32) = v7;
    *(_DWORD *)(v7 + 64) = a4;
    *(_QWORD *)(v7 + 56) = nc_malloc(size);
    return v7;
  }
  v9 = v8;
  v10 = 0LL;
  v11 = 8LL * (unsigned int)(a3 - 1);
  while ( 1 )
  {
    v12 = *(_QWORD *)(a2 + v10);
    if ( !v12 )
      break;
    *(_QWORD *)(v10 + v9) = nc_dup_node(v12);
    if ( v11 == v10 )
      goto LABEL_7;
LABEL_4:
    v9 = *(_QWORD *)(v7 + 32);
    v10 += 8LL;
  }
  *(_QWORD *)(v9 + v10) = 0LL;
  if ( v11 != v10 )
    goto LABEL_4;
LABEL_7:
  v13 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 72) = v13 + 1;
  *(_QWORD *)(v7 + 96) = v13;
  v14 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(v14 + 8) = v7;
  *(_QWORD *)v7 = v14;
  *(_QWORD *)(v7 + 8) = a1 + 32;
  *(_QWORD *)(a1 + 32) = v7;
  *(_DWORD *)(v7 + 64) = a4;
  v15 = nc_malloc(size);
  v16 = 0LL;
  *(_QWORD *)(v7 + 56) = v15;
  while ( 1 )
  {
    *(_QWORD *)(v15 + v16) = *(_QWORD *)(a5 + v16);
    if ( v11 == v16 )
      break;
    v15 = *(_QWORD *)(v7 + 56);
    v16 += 8LL;
  }
  return v7;
}

