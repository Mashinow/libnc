// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_get_data
// Included functions: 1

// ======================================================
// Function: nc_tensor_get_data @ 0x66A15360
// ======================================================

__int64 __fastcall nc_tensor_get_data(__int64 a1, __int64 a2)
{
  int v2; // r10d
  __int64 result; // rax
  __int64 v4; // r11
  _QWORD *v5; // r8
  __int64 v6; // rcx

  v2 = *(_DWORD *)(a2 + 80);
  result = a1;
  *(_DWORD *)a1 = *(_DWORD *)(a2 + 48);
  *(_QWORD *)(a1 + 8) = nc_type_size_table[*(unsigned int *)(a2 + 48)];
  *(_QWORD *)(a1 + 16) = *(_QWORD *)(a2 + 56);
  *(_QWORD *)(a1 + 24) = *(_QWORD *)(a2 + 64);
  if ( v2 <= 0 )
  {
    v6 = 1i64;
    v4 = a2 + 120;
  }
  else
  {
    v4 = a2 + 120;
    v5 = (_QWORD *)(a2 + 120);
    v6 = 1i64;
    do
      v6 *= *v5++;
    while ( v5 != (_QWORD *)(a2 + 8i64 * (unsigned int)(v2 - 1) + 128) );
  }
  *(_QWORD *)(result + 32) = v6;
  *(_DWORD *)(result + 40) = v2;
  *(_QWORD *)(result + 48) = v4;
  *(_QWORD *)(result + 56) = a2 + 88;
  return result;
}

