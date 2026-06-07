// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set1_f32
// Included functions: 1

// ======================================================
// Function: nc_set1_f32 @ 0x18B10
// ======================================================

__int64 __fastcall nc_set1_f32(__int64 a1, int a2, _QWORD *a3, __m128 _XMM0)
{
  __int64 v5; // rdi
  __int64 v6; // rcx
  __int64 (__fastcall *v9)(__int64, __int64, _WORD *, __int64); // r10
  __int64 v10; // rcx
  __int64 v11; // r8
  _WORD v13[12]; // [rsp+0h] [rbp-18h] BYREF

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  v6 = *(unsigned int *)(a1 + 48);
  if ( (_DWORD)v6 )
  {
    if ( (_DWORD)v6 != 1 )
      abort();
    __asm
    {
      vmovd   r9d, xmm0
      vmovd   r8d, xmm0
    }
    v13[0] = (unsigned int)(_R8D + (HIWORD(_R9D) & 1) + 0x7FFF) >> 16;
  }
  else
  {
    __asm { vmovss  dword ptr [rsp+18h+var_18], xmm0 }
  }
  if ( *(_DWORD *)(a1 + 80) != a2 )
    __assert_fail("y->n_dims == n_dims", "libnc.c", 0x135Fu, "nc_set1_f32");
  v9 = *(__int64 (__fastcall **)(__int64, __int64, _WORD *, __int64))(v5 + 88);
  v10 = nc_type_size_table[v6];
  if ( a2 <= 0 )
    return v9(v5, *(_QWORD *)(a1 + 56), v13, v10);
  v11 = *a3 * *(_QWORD *)(a1 + 88);
  if ( a2 != 1 )
  {
    v11 += *(_QWORD *)(a1 + 96) * a3[1];
    if ( a2 != 2 )
    {
      v11 += *(_QWORD *)(a1 + 104) * a3[2];
      if ( a2 != 3 )
        v11 += *(_QWORD *)(a1 + 112) * a3[3];
    }
  }
  return v9(v5, *(_QWORD *)(a1 + 56) + v11, v13, v10);
}

