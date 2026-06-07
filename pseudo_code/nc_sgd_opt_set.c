// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sgd_opt_set
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_set @ 0x66A31F60
// ======================================================

void __fastcall nc_sgd_opt_set(__int64 a1, _QWORD *a2)
{
  __int64 *v2; // rbx
  _QWORD *v5; // rax
  void (__fastcall *v6)(_QWORD, __int64); // r8
  __int64 v7; // rdx
  _QWORD *v8; // rax
  _QWORD *v9; // rax
  _QWORD *v10; // rbx
  __int64 (__fastcall *v11)(_QWORD, __int64); // rax
  __int64 v12; // rax

  v2 = *(__int64 **)(a1 + 48);
  if ( v2 )
  {
    v5 = (_QWORD *)v2[2];
    if ( v5 == a2 )
      return;
    v6 = (void (__fastcall *)(_QWORD, __int64))v5[9];
    if ( v6 )
      v6(v5[3], v2[4]);
    v7 = *v2;
    v8 = (_QWORD *)v2[1];
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *v2 = 0i64;
    v2[1] = 0i64;
    _aligned_free(v2);
    *(_QWORD *)(a1 + 48) = 0i64;
  }
  if ( a2 )
  {
    v9 = aligned_malloc(0x28ui64, 0x40ui64);
    v10 = v9;
    if ( v9 )
    {
      *v9 = 0i64;
      v9[1] = 0i64;
      v9[2] = 0i64;
      v9[3] = 0i64;
      v9[4] = 0i64;
    }
    v11 = (__int64 (__fastcall *)(_QWORD, __int64))a2[8];
    if ( v11 )
      v10[4] = v11(a2[3], a1);
    v12 = a2[1];
    v10[3] = a1;
    *(_QWORD *)(a1 + 48) = v10;
    v10[2] = a2;
    *(_QWORD *)(v12 + 8) = v10;
    *v10 = v12;
    v10[1] = a2 + 1;
    a2[1] = v10;
  }
}

