// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_buffer
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_buffer @ 0x66A13F90
// ======================================================

_DWORD *__fastcall nc_new_tensor_buffer(__int64 a1, __int64 a2)
{
  __int64 *v2; // rdi
  _DWORD *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  _DWORD *result; // rax

  v2 = *(__int64 **)(a1 + 16);
  v5 = aligned_malloc(0x38ui64, 0x40ui64);
  v5[4] = 1;
  *((_QWORD *)v5 + 3) = a1;
  v6 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v5 + 10, a2);
  *((_QWORD *)v5 + 4) = v6;
  if ( !v6 )
    nc_error("not enough device memory");
  v7 = *v2;
  *((_QWORD *)v5 + 6) = a2;
  *(_QWORD *)(v7 + 8) = v5;
  *(_QWORD *)v5 = v7;
  result = v5;
  *((_QWORD *)v5 + 1) = v2;
  *v2 = (__int64)v5;
  return result;
}

