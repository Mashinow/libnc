// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_f32
// Included functions: 1

// ======================================================
// Function: nc_new_f32 @ 0x66A19EF0
// ======================================================

// local variable allocation has failed, the output may be wrong!
_QWORD *__fastcall nc_new_f32(__int64 a1, double _XMM1_8)
{
  __int64 v2; // r13
  _QWORD *v5; // rbx
  __int64 v6; // rdi
  __int64 *v7; // r14
  _DWORD *v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  int v13; // eax
  unsigned int v14; // edx

  v2 = *(_QWORD *)(a1 + 16);
  __asm { vmovd   r12d, xmm1 }
  v5 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v5 )
  {
    MEMORY[0x18] = v2;
    BUG();
  }
  memset(v5, 0, 0x98ui64);
  *((_BYTE *)v5 + 72) = 1;
  v5[3] = v2;
  v6 = nc_type_size_table[0];
  *((_DWORD *)v5 + 4) = 1;
  v5[15] = 1i64;
  v7 = *(__int64 **)(a1 + 16);
  v5[8] = 1i64;
  v8 = aligned_malloc(0x38ui64, 0x40ui64);
  v8[4] = 1;
  *((_QWORD *)v8 + 3) = a1;
  v9 = (*(__int64 (__fastcall **)(__int64, _DWORD *, __int64))(a1 + 48))(a1, v8 + 10, v6);
  *((_QWORD *)v8 + 4) = v9;
  if ( !v9 )
    nc_error("not enough device memory");
  v10 = *v7;
  *((_QWORD *)v8 + 6) = v6;
  *(_QWORD *)(v10 + 8) = v8;
  *(_QWORD *)v8 = v10;
  v11 = *((_QWORD *)v8 + 5);
  *((_QWORD *)v8 + 1) = v7;
  *v7 = (__int64)v8;
  v5[7] = v11;
  v12 = *(_QWORD *)(v2 + 16);
  v5[5] = v8;
  *(_QWORD *)(v12 + 8) = v5;
  *v5 = v12;
  v5[1] = v2 + 16;
  *(_QWORD *)(v2 + 16) = v5;
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD))(a1 + 104))(a1, v5[7], 0i64, v6, 0);
  v13 = *((_DWORD *)v5 + 12);
  v14 = _R12D;
  if ( v13 )
  {
    if ( v13 != 1 )
      abort();
    v14 = (_R12D + (HIWORD(_R12D) & 1) + 0x7FFF) >> 16;
  }
  nc_tensor_set_u32((__int64)v5, v14);
  return v5;
}

