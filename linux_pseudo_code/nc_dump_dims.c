// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dump_dims
// Included functions: 1

// ======================================================
// Function: nc_dump_dims @ 0x181D0
// ======================================================

int __fastcall nc_dump_dims(const char *a1, __int64 a2)
{
  int result; // eax
  int v3; // eax
  int v4; // ebx
  int v5; // eax

  printf("%s %s", nc_type_name_table[*(unsigned int *)(a2 + 48)], a1);
  result = *(_DWORD *)(a2 + 80);
  if ( result > 0 )
  {
    putchar(91);
    v3 = *(_DWORD *)(a2 + 80);
    if ( v3 > 0 )
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = v3 - 1 - v4++;
        printf("%d", *(_QWORD *)(a2 + 8LL * v5 + 120));
        if ( v4 >= *(_DWORD *)(a2 + 80) )
          break;
        printf(", ");
        v3 = *(_DWORD *)(a2 + 80);
      }
    }
    return putchar(93);
  }
  return result;
}

