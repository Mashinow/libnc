// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_free_node
// Included functions: 1

// ======================================================
// Function: nc_free_node @ 0x16D80
// ======================================================

void __fastcall nc_free_node(__int64 *ptr)
{
  int v1; // eax
  int v3; // eax
  __int64 v4; // r12
  int v5; // ebp
  void *v6; // rdi
  __int64 v7; // r12
  int v8; // ebp
  void *v9; // rdi
  __int64 v10; // rdx
  _QWORD *v11; // rax
  __int64 v12; // rax

  if ( ptr )
  {
    v1 = *((_DWORD *)ptr + 4);
    if ( v1 <= 0 )
      __assert_fail("n->ref_count >= 1", "libnc.c", 0x10AEu, "nc_free_node");
    v3 = v1 - 1;
    *((_DWORD *)ptr + 4) = v3;
    if ( v3 == 1 )
    {
      if ( *((int *)ptr + 10) <= 0 )
        return;
      v12 = *(_QWORD *)ptr[6];
      if ( !v12 || ptr != *(__int64 **)(v12 + 32) || *(_DWORD *)(v12 + 16) != 1 )
        return;
      *(_QWORD *)(v12 + 32) = 0LL;
      *((_DWORD *)ptr + 4) = 0;
    }
    else if ( v3 )
    {
      return;
    }
    v4 = 0LL;
    v5 = 0;
    while ( v5 < *((_DWORD *)ptr + 6) )
    {
      ++v5;
      v6 = *(void **)(ptr[4] + v4);
      v4 += 8LL;
      nc_free_node(v6);
    }
    v7 = 0LL;
    v8 = 0;
    nc_free((void *)ptr[4]);
    if ( *((int *)ptr + 10) > 0 )
    {
      do
      {
        ++v8;
        v9 = *(void **)(ptr[6] + v7);
        v7 += 8LL;
        nc_free_tensor(v9);
      }
      while ( v8 < *((_DWORD *)ptr + 10) );
    }
    if ( *((_DWORD *)ptr + 5) == 14 )
      nc_free((void *)ptr[7]);
    nc_free((void *)ptr[6]);
    free((void *)ptr[13]);
    v10 = *ptr;
    v11 = (_QWORD *)ptr[1];
    *(_QWORD *)(v10 + 8) = v11;
    *v11 = v10;
    *ptr = 0LL;
    ptr[1] = 0LL;
    nc_free(ptr);
  }
}

