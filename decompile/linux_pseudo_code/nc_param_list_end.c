// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_param_list_end
// Included functions: 1

// ======================================================
// Function: nc_param_list_end @ 0x2DD40
// ======================================================

__int64 __fastcall nc_param_list_end(__int64 a1)
{
  __int64 v2; // rbx
  __int64 v3; // rbp
  void *v4; // rdi
  __int64 result; // rax

  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(v2 + 8);
  if ( v2 != a1 )
  {
    while ( 1 )
    {
      nc_free_tensor(**(void ***)(v2 + 16));
      nc_free_tensor(*(void **)(v2 + 40));
      nc_free_tensor(*(void **)(v2 + 32));
      free(*(void **)(v2 + 24));
      v4 = (void *)v2;
      v2 = v3;
      nc_free(v4);
      result = *(_QWORD *)(v3 + 8);
      if ( a1 == v3 )
        break;
      v3 = *(_QWORD *)(v3 + 8);
    }
  }
  return result;
}

