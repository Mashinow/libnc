// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_dump_dims
// Included functions: 1

// ======================================================
// Function: nc_dump_dims @ 0x66A16890
// ======================================================

int __fastcall nc_dump_dims(const char *a1, __int64 a2)
{
  int result; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // eax

  printf("%s %s", (const char *)*(&nc_type_name_table + *(unsigned int *)(a2 + 48)), a1);
  result = *(_DWORD *)(a2 + 80);
  if ( result > 0 )
  {
    putchar(91);
    v4 = *(_DWORD *)(a2 + 80);
    if ( v4 > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = v4 - 1 - v5++;
        printf("%d", *(_QWORD *)(a2 + 8i64 * v6 + 120));
        if ( v5 >= *(_DWORD *)(a2 + 80) )
          break;
        printf(", ");
        v4 = *(_DWORD *)(a2 + 80);
      }
    }
    return putchar(93);
  }
  return result;
}

