// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_param_list_end
// Included functions: 1

// ======================================================
// Function: nc_param_list_end @ 0x66A31A80
// ======================================================

__int64 __fastcall nc_param_list_end(__int64 a1)
{
  __int64 v1; // rbx
  __int64 v2; // rsi
  void *v4; // rcx
  __int64 result; // rax

  v1 = *(_QWORD *)(a1 + 8);
  v2 = *(_QWORD *)(v1 + 8);
  if ( v1 != a1 )
  {
    while ( 1 )
    {
      nc_free_tensor(**(_DWORD ***)(v1 + 16));
      nc_free_tensor(*(_DWORD **)(v1 + 40));
      nc_free_tensor(*(_DWORD **)(v1 + 32));
      free(*(void **)(v1 + 24));
      v4 = (void *)v1;
      v1 = v2;
      _aligned_free(v4);
      result = *(_QWORD *)(v2 + 8);
      if ( a1 == v2 )
        break;
      v2 = *(_QWORD *)(v2 + 8);
    }
  }
  return result;
}

