// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_get1_f32
// Included functions: 1

// ======================================================
// Function: nc_get1_f32 @ 0x1B380
// ======================================================

__int128 __usercall nc_get1_f32@<xmm0>(__int64 a1@<rdi>, int a2@<esi>, _QWORD *a3@<rdx>)
{
  int v4; // r8d
  __int64 v5; // rdi
  __int64 v6; // rax
  __int128 result; // xmm0
  int v8[3]; // [rsp+Ch] [rbp-Ch] BYREF

  v4 = *(_DWORD *)(a1 + 80);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  if ( v4 != a2 )
    __assert_fail("x->n_dims == n_dims", "libnc.c", 0x153Au, "nc_get1_f32");
  if ( *(_DWORD *)(a1 + 48) )
    __assert_fail("x->item_type == NC_TYPE_F32", "libnc.c", 0x153Bu, "nc_get1_f32");
  if ( v4 <= 0 )
  {
    v6 = 0LL;
  }
  else
  {
    v6 = *a3 * *(_QWORD *)(a1 + 88);
    if ( v4 != 1 )
    {
      v6 += *(_QWORD *)(a1 + 96) * a3[1];
      if ( v4 != 2 )
      {
        v6 += *(_QWORD *)(a1 + 104) * a3[2];
        if ( v4 != 3 )
          v6 += *(_QWORD *)(a1 + 112) * a3[3];
      }
    }
  }
  (*(void (__fastcall **)(__int64, int *, __int64, __int64))(v5 + 96))(v5, v8, *(_QWORD *)(a1 + 56) + v6, 4LL);
  __asm { vmovss  xmm0, [rsp+18h+var_C] }
  return result;
}

