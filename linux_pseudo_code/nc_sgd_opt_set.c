// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_sgd_opt_set
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_set @ 0x2E600
// ======================================================

void __fastcall nc_sgd_opt_set(__int64 a1, _QWORD *a2)
{
  __int64 *v2; // rbp
  _QWORD *v3; // rax
  void (__fastcall *v4)(_QWORD, __int64); // rdx
  __int64 v5; // rdx
  _QWORD *v6; // rax
  _QWORD *v7; // rbp
  __int64 (__fastcall *v8)(_QWORD, __int64); // rax
  __int64 v9; // rax

  v2 = *(__int64 **)(a1 + 48);
  if ( v2 )
  {
    v3 = (_QWORD *)v2[2];
    if ( v3 == a2 )
      return;
    v4 = (void (__fastcall *)(_QWORD, __int64))v3[9];
    if ( v4 )
      v4(v3[3], v2[4]);
    v5 = *v2;
    v6 = (_QWORD *)v2[1];
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v2 = 0LL;
    v2[1] = 0LL;
    nc_free(v2);
    *(_QWORD *)(a1 + 48) = 0LL;
  }
  if ( a2 )
  {
    v7 = (_QWORD *)nc_mallocz(0x28uLL);
    v8 = (__int64 (__fastcall *)(_QWORD, __int64))a2[8];
    if ( v8 )
      v7[4] = v8(a2[3], a1);
    v9 = a2[1];
    v7[3] = a1;
    *(_QWORD *)(a1 + 48) = v7;
    v7[2] = a2;
    *(_QWORD *)(v9 + 8) = v7;
    *v7 = v9;
    v7[1] = a2 + 1;
    a2[1] = v7;
  }
}

