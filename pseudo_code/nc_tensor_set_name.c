// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_name
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_name @ 0x66A19C90
// ======================================================

__int64 nc_tensor_set_name(__int64 a1, const char *a2, ...)
{
  __int64 v3; // rbx
  char Buffer[88]; // [rsp+30h] [rbp-58h] BYREF
  va_list ArgList; // [rsp+A0h] [rbp+18h] BYREF

  va_start(ArgList, a2);
  j__vsnprintf(Buffer, 0x40ui64, a2, ArgList);
  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 )
  {
    free(*(void **)(v3 + 104));
    *(_QWORD *)(v3 + 104) = strdup(Buffer);
  }
  return a1;
}

