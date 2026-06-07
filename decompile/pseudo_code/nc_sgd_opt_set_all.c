// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_sgd_opt_set_all
// Included functions: 1

// ======================================================
// Function: nc_sgd_opt_set_all @ 0x66A32050
// ======================================================

void __fastcall nc_sgd_opt_set_all(__int64 a1, _QWORD *a2)
{
  __int64 v2; // rsi
  _QWORD *v5; // r12
  __int64 *v6; // rbx
  _QWORD *v7; // rax
  void (__fastcall *v8)(_QWORD, __int64); // r8
  __int64 v9; // rdx
  _QWORD *v10; // rax
  _QWORD *v11; // rax
  _QWORD *v12; // rbx
  __int64 (__fastcall *v13)(_QWORD, __int64); // rax
  __int64 v14; // rax

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 != a1 )
  {
    v5 = a2 + 1;
    while ( 1 )
    {
      v6 = *(__int64 **)(v2 + 48);
      if ( !v6 )
        goto LABEL_8;
      v7 = (_QWORD *)v6[2];
      if ( a2 != v7 )
        break;
LABEL_14:
      v2 = *(_QWORD *)(v2 + 8);
      if ( v2 == a1 )
        return;
    }
    v8 = (void (__fastcall *)(_QWORD, __int64))v7[9];
    if ( v8 )
      v8(v7[3], v6[4]);
    v9 = *v6;
    v10 = (_QWORD *)v6[1];
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    *v6 = 0i64;
    v6[1] = 0i64;
    _aligned_free(v6);
    *(_QWORD *)(v2 + 48) = 0i64;
LABEL_8:
    if ( a2 )
    {
      v11 = aligned_malloc(0x28ui64, 0x40ui64);
      v12 = v11;
      if ( v11 )
      {
        *v11 = 0i64;
        v11[1] = 0i64;
        v11[2] = 0i64;
        v11[3] = 0i64;
        v11[4] = 0i64;
      }
      v13 = (__int64 (__fastcall *)(_QWORD, __int64))a2[8];
      if ( v13 )
        v12[4] = v13(a2[3], v2);
      v14 = a2[1];
      v12[3] = v2;
      *(_QWORD *)(v2 + 48) = v12;
      v12[2] = a2;
      *(_QWORD *)(v14 + 8) = v12;
      *v12 = v14;
      v12[1] = v5;
      a2[1] = v12;
    }
    goto LABEL_14;
  }
}

