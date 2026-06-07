// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_param_str
// Included functions: 1

// ======================================================
// Function: nc_new_param_str @ 0x2DBC0
// ======================================================

_QWORD *__fastcall nc_new_param_str(__int64 *a1, _QWORD *a2, __int64 a3)
{
  __int64 v4; // rax
  _QWORD *v5; // rbx
  __int64 v6; // rax
  _QWORD *result; // rax
  __int64 v8; // r14
  __int64 v9; // rax

  v4 = nc_mallocz(0x38uLL);
  *(_QWORD *)(v4 + 16) = a2;
  v5 = (_QWORD *)v4;
  *(_QWORD *)(v4 + 24) = __strdup();
  if ( *((_DWORD *)a1 + 4) )
  {
    v8 = *a2;
    nc_set_param(*a2, v5);
    nc_tensor_set_name_str(*a2, a3);
    if ( *(_DWORD *)(v8 + 48) == 1 )
    {
      v9 = nc_new_tensor_nz(*(_QWORD *)(*(_QWORD *)(v8 + 40) + 24LL), 1LL, *(unsigned int *)(v8 + 80), v8 + 120);
      v5[4] = v9;
      nc_tensor_set_u32(v9, 0x8000LL);
    }
  }
  v6 = *a1;
  *(_QWORD *)(v6 + 8) = v5;
  *v5 = v6;
  result = v5;
  v5[1] = a1;
  *a1 = (__int64)v5;
  return result;
}

