// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_get_param_count
// Included functions: 1

// ======================================================
// Function: nc_get_param_count @ 0x66A31B40
// ======================================================

__int64 __fastcall nc_get_param_count(__int64 a1)
{
  __int64 result; // rax
  __int64 i; // r10
  __int64 *v3; // rdx
  __int64 v4; // r8
  int v5; // r9d
  _QWORD *v6; // rdx
  __int64 v7; // r9
  __int64 v8; // r8

  result = 0i64;
  for ( i = *(_QWORD *)(a1 + 8); i != a1; result += v8 )
  {
    while ( 1 )
    {
      v3 = *(__int64 **)(i + 16);
      v4 = *v3;
      v5 = *(_DWORD *)(*v3 + 80);
      if ( v5 > 0 )
        break;
      i = *(_QWORD *)(i + 8);
      ++result;
      if ( i == a1 )
        return result;
    }
    v6 = (_QWORD *)(v4 + 120);
    v7 = v4 + 8i64 * (unsigned int)(v5 - 1) + 128;
    v8 = 1i64;
    do
      v8 *= *v6++;
    while ( v6 != (_QWORD *)v7 );
    i = *(_QWORD *)(i + 8);
  }
  return result;
}

