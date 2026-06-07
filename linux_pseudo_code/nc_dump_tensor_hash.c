// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dump_tensor_hash
// Included functions: 1

// ======================================================
// Function: nc_dump_tensor_hash @ 0x1A0F0
// ======================================================

int __fastcall nc_dump_tensor_hash(const char *a1, __int64 a2)
{
  unsigned int hash; // eax

  hash = nc_tensor_get_hash(a2);
  return printf("%s: 0x%08x\n", a1, hash);
}

