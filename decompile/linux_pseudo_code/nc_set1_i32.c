// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set1_i32
// Included functions: 1

// ======================================================
// Function: nc_set1_i32 @ 0x18A20
// ======================================================

__int64 __fastcall nc_set1_i32(__int64 a1, int a2, _QWORD *a3, int a4)
{
  __int64 v5; // r8
  __int64 v6; // rdi
  __int64 (__fastcall *v7)(__int64, __int64, int *, __int64); // r10
  __int64 v8; // rcx
  __int64 v9; // r8
  int v11[6]; // [rsp+0h] [rbp-18h] BYREF

  v5 = *(unsigned int *)(a1 + 48);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  switch ( (_DWORD)v5 )
  {
    case 4:
      LOWORD(v11[0]) = a4;
      break;
    case 5:
      v11[0] = a4;
      break;
    case 3:
      LOBYTE(v11[0]) = a4;
      break;
    default:
      abort();
  }
  if ( *(_DWORD *)(a1 + 80) != a2 )
    __assert_fail("y->n_dims == n_dims", "libnc.c", 0x134Au, "nc_set1_i32");
  v7 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v6 + 88);
  v8 = nc_type_size_table[v5];
  if ( a2 <= 0 )
    return v7(v6, *(_QWORD *)(a1 + 56), v11, v8);
  v9 = *a3 * *(_QWORD *)(a1 + 88);
  if ( a2 != 1 )
  {
    v9 += *(_QWORD *)(a1 + 96) * a3[1];
    if ( a2 != 2 )
    {
      v9 += *(_QWORD *)(a1 + 104) * a3[2];
      if ( a2 != 3 )
        v9 += *(_QWORD *)(a1 + 112) * a3[3];
    }
  }
  return v7(v6, *(_QWORD *)(a1 + 56) + v9, v11, v8);
}

