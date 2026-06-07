// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sgd_opt_update
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_update @ 0x2E5E0
// ======================================================

__int64 (__fastcall *__fastcall nc_sgd_opt_update(__int64 a1))(_QWORD)
{
  __int64 (__fastcall *result)(_QWORD); // rax

  result = *(__int64 (__fastcall **)(_QWORD))(a1 + 48);
  if ( result )
    return (__int64 (__fastcall *)(_QWORD))result(*(_QWORD *)(a1 + 24));
  return result;
}

