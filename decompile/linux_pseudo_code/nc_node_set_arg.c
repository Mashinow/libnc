// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_node_set_arg
// Included functions: 1

// ======================================================
// Function: nc_node_set_arg @ 0x1AF80
// ======================================================

__int64 __fastcall nc_node_set_arg(__int64 a1, int a2, __int64 a3)
{
  __int64 *v4; // rbp
  __int64 result; // rax

  if ( a2 < 0 || a2 >= *(_DWORD *)(a1 + 40) )
    __assert_fail("arg_index >= 0 && arg_index < n->n_args", "libnc.c", 0x14BBu, "nc_node_set_arg");
  nc_free_tensor(*(void **)(*(_QWORD *)(a1 + 48) + 8LL * a2));
  v4 = (__int64 *)(*(_QWORD *)(a1 + 48) + 8LL * a2);
  result = nc_dup_tensor(a3);
  *v4 = result;
  return result;
}

