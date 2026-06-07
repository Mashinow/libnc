// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_get_param_count
// Included functions: 1

// ======================================================
// Function: nc_get_param_count @ 0x2E2F0
// ======================================================

__int64 __fastcall nc_get_param_count(__int64 a1)
{
  __int64 v1; // r8
  __int64 result; // rax
  __int64 *v3; // rdx
  __int64 v4; // rcx
  int v5; // esi
  _QWORD *v6; // rdx
  __int64 v7; // rsi
  __int64 v8; // rcx

  v1 = *(_QWORD *)(a1 + 8);
  for ( result = 0LL; v1 != a1; result += v8 )
  {
    while ( 1 )
    {
      v3 = *(__int64 **)(v1 + 16);
      v4 = *v3;
      v5 = *(_DWORD *)(*v3 + 80);
      if ( v5 > 0 )
        break;
      v1 = *(_QWORD *)(v1 + 8);
      ++result;
      if ( v1 == a1 )
        return result;
    }
    v6 = (_QWORD *)(v4 + 120);
    v7 = v4 + 8LL * (unsigned int)(v5 - 1) + 128;
    v8 = 1LL;
    do
      v8 *= *v6++;
    while ( v6 != (_QWORD *)v7 );
    v1 = *(_QWORD *)(v1 + 8);
  }
  return result;
}

