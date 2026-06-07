// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_set_param
// Included functions: 1

// ======================================================
// Function: nc_set_param @ 0x1AFE0
// ======================================================

__int64 __fastcall nc_set_param(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 result; // rax

  if ( *(_QWORD *)(a1 + 32) )
    __assert_fail("!x->node", "libnc.c", 0x14E7u, "nc_set_param");
  v2 = *(_QWORD *)(a1 + 24);
  v3 = nc_mallocz(0x80uLL);
  *(_DWORD *)(v3 + 16) = 1;
  v4 = v3;
  *(_DWORD *)(v3 + 20) = 1;
  *(_DWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = nc_malloc(0LL);
  v5 = *(_QWORD *)(v2 + 72);
  *(_QWORD *)(v2 + 72) = v5 + 1;
  *(_QWORD *)(v4 + 96) = v5;
  v6 = *(_QWORD *)(v2 + 32);
  *(_QWORD *)(v6 + 8) = v4;
  *(_QWORD *)v4 = v6;
  *(_QWORD *)(v4 + 8) = v2 + 32;
  result = a1;
  *(_QWORD *)(v2 + 32) = v4;
  *(_QWORD *)(a1 + 32) = v4;
  *(_QWORD *)(v4 + 56) = a2;
  *(_DWORD *)(v4 + 64) = 0;
  return result;
}

