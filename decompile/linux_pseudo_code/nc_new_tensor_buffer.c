// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_buffer
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_buffer @ 0x163B0
// ======================================================

_QWORD *__fastcall nc_new_tensor_buffer(__int64 a1, __int64 a2)
{
  __int64 *v3; // r12
  __int64 v4; // rax
  _QWORD *v6; // rbx
  char v7; // si
  __int64 v8; // rax
  __int64 v9; // rax
  _QWORD *result; // rax

  v3 = *(__int64 **)(a1 + 16);
  v4 = nc_malloc(0x38uLL);
  v6 = (_QWORD *)v4;
  *(_DWORD *)(v4 + 16) = 1;
  v7 = v4 + 40;
  *(_QWORD *)(v4 + 24) = a1;
  v8 = (*(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 48))(a1, v4 + 40, a2);
  v6[4] = v8;
  if ( !v8 )
    nc_error("not enough device memory", v7);
  v9 = *v3;
  v6[6] = a2;
  *(_QWORD *)(v9 + 8) = v6;
  *v6 = v9;
  result = v6;
  v6[1] = v3;
  *v3 = (__int64)v6;
  return result;
}

