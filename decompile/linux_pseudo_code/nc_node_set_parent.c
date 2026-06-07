// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_node_set_parent
// Included functions: 1

// ======================================================
// Function: nc_node_set_parent @ 0x1AF20
// ======================================================

__int64 __fastcall nc_node_set_parent(__int64 a1, int a2, __int64 a3)
{
  __int64 *v4; // rbp
  __int64 result; // rax

  if ( a2 < 0 || a2 >= *(_DWORD *)(a1 + 24) )
    __assert_fail("arg_index >= 0 && arg_index < n->n_parents", "libnc.c", 0x14B4u, "nc_node_set_parent");
  nc_free_node(*(void **)(*(_QWORD *)(a1 + 32) + 8LL * a2));
  v4 = (__int64 *)(*(_QWORD *)(a1 + 32) + 8LL * a2);
  result = nc_dup_node(a3);
  *v4 = result;
  return result;
}

