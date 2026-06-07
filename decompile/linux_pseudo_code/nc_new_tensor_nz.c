// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_nz
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_nz @ 0x164C0
// ======================================================

__int64 __fastcall nc_new_tensor_nz(__int64 a1, unsigned int a2, int a3, __int64 *a4)
{
  __int64 v4; // r14
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rbx
  __int64 v11; // rsi
  __int64 v12; // rax
  __int64 v13; // rsi
  __int64 v14; // rsi
  int v15; // ebp
  unsigned int v16; // ebp
  unsigned int i; // eax
  __int64 v18; // rdi
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 result; // rax

  v4 = *(_QWORD *)(a1 + 16);
  if ( a2 > 5 )
    __assert_fail("type >= 0 && type < NC_TYPE_COUNT", "libnc.c", 0xF19u, "nc_new_tensor_nz");
  if ( a3 < 0 )
    __assert_fail("n_dims >= 0", "libnc.c", 0xF1Au, "nc_new_tensor_nz");
  if ( a3 > 4 )
    __assert_fail("n_dims <= N_DIMS_MAX", "libnc.c", 0xF1Bu, "nc_new_tensor_nz");
  v10 = nc_mallocz(0x98uLL);
  *(_QWORD *)(v10 + 24) = v4;
  *(_DWORD *)(v10 + 16) = 1;
  *(_DWORD *)(v10 + 48) = a2;
  *(_DWORD *)(v10 + 80) = a3;
  v11 = nc_type_size_table[a2];
  if ( a3 )
  {
    v12 = *a4;
    *(_QWORD *)(v10 + 120) = *a4;
    if ( a3 == 1 )
    {
      *(_QWORD *)(v10 + 88) = v11;
      v15 = 0;
      v11 *= *(_QWORD *)(v10 + 120);
      *(_QWORD *)(v10 + 64) = v12;
    }
    else
    {
      *(_QWORD *)(v10 + 128) = a4[1];
      if ( a3 == 2 )
      {
        *(_QWORD *)(v10 + 88) = v11;
        v14 = *(_QWORD *)(v10 + 120) * v11;
        *(_QWORD *)(v10 + 96) = v14;
      }
      else
      {
        *(_QWORD *)(v10 + 136) = a4[2];
        if ( a3 == 4 )
          *(_QWORD *)(v10 + 144) = a4[3];
        *(_QWORD *)(v10 + 88) = v11;
        v13 = *(_QWORD *)(v10 + 120) * v11;
        *(_QWORD *)(v10 + 96) = v13;
        v14 = *(_QWORD *)(v10 + 128) * v13;
        *(_QWORD *)(v10 + 104) = v14;
        if ( a3 == 4 )
        {
          v14 *= *(_QWORD *)(v10 + 136);
          *(_QWORD *)(v10 + 112) = v14;
        }
      }
      v15 = a3 - 1;
      *(_QWORD *)(v10 + 64) = *(_QWORD *)(v10 + 120);
      v11 = *(_QWORD *)(v10 + 8LL * v15 + 120) * v14;
    }
    v16 = v15 + 1;
    v8 = v10 + 73;
    v9 = v16;
    if ( v16 )
    {
      for ( i = 0; i < v16; ++i )
      {
        v18 = i;
        *(_BYTE *)(v8 + v18) = 1;
      }
    }
  }
  else
  {
    *(_QWORD *)(v10 + 120) = 1LL;
    *(_QWORD *)(v10 + 64) = 1LL;
  }
  *(_BYTE *)(v10 + 72) = 1;
  v19 = nc_new_tensor_buffer(a1, v11, v8, v9);
  *(_QWORD *)(v10 + 40) = v19;
  *(_QWORD *)(v10 + 56) = *(_QWORD *)(v19 + 40);
  v20 = *(_QWORD *)(v4 + 16);
  *(_QWORD *)(v20 + 8) = v10;
  *(_QWORD *)v10 = v20;
  *(_QWORD *)(v10 + 8) = v4 + 16;
  result = v10;
  *(_QWORD *)(v4 + 16) = v10;
  return result;
}

