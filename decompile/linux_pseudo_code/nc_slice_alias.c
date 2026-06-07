// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_slice_alias
// Included functions: 1

// ======================================================
// Function: nc_slice_alias @ 0x168D0
// ======================================================

__int64 __fastcall nc_slice_alias(__int64 a1, int a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 v5; // rdi
  int v6; // r10d
  __int64 v8; // r11
  __int64 v9; // rsi
  __int64 v10; // r9
  __int64 v11; // rdx
  unsigned __int64 v13; // [rsp+0h] [rbp-28h] BYREF
  unsigned __int64 v14; // [rsp+8h] [rbp-20h]
  unsigned __int64 v15; // [rsp+10h] [rbp-18h]
  __int64 v16; // [rsp+18h] [rbp-10h]

  v5 = *(_QWORD *)(a1 + 24);
  if ( a2 < 0 || (v6 = *(_DWORD *)(a1 + 80), a2 >= v6) )
    __assert_fail("axis >= 0 && axis < x->n_dims", "libnc.c", 0xF9Fu, "nc_slice_alias");
  if ( a3 >= a4 )
    __assert_fail("start < end", "libnc.c", 0xFA0u, "nc_slice_alias");
  v8 = a1 + 8LL * a2;
  if ( a4 > *(_QWORD *)(v8 + 120) )
    __assert_fail("start >= 0 && end <= x->dims[axis]", "libnc.c", 0xFA1u, "nc_slice_alias");
  v9 = *(_QWORD *)(a1 + 40);
  v10 = *(_QWORD *)(v8 + 88) * a3 + *(_QWORD *)(a1 + 56) - *(_QWORD *)(v9 + 40);
  if ( v6 <= 0 )
    return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
  if ( !a2 )
  {
    v13 = a4 - a3;
    if ( v6 == 1 )
      return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
LABEL_9:
    v14 = *(_QWORD *)(a1 + 128);
    if ( v6 <= 2 )
      return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
    if ( a2 == 2 )
    {
      v15 = a4 - a3;
      if ( v6 == 3 )
        return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
      goto LABEL_13;
    }
    goto LABEL_11;
  }
  v13 = *(_QWORD *)(a1 + 120);
  if ( v6 == 1 )
    return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
  if ( a2 != 1 )
    goto LABEL_9;
  v14 = a4 - a3;
  if ( v6 == 2 )
    return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
LABEL_11:
  v15 = *(_QWORD *)(a1 + 136);
  if ( v6 > 3 )
  {
    if ( a2 == 3 )
    {
      v11 = a4 - a3;
      goto LABEL_14;
    }
LABEL_13:
    v11 = *(_QWORD *)(a1 + 144);
LABEL_14:
    v16 = v11;
  }
  return nc_new_tensor_from_buffer(v5, v9, *(_DWORD *)(a1 + 48), v6, (int)&v13, v10, a1 + 88);
}

