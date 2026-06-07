// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_dropout
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_dropout @ 0x1AC90
// ======================================================

__int64 __fastcall nc_tensor_set_dropout(__int64 a1, __int64 a2, __m128 _XMM0)
{
  __int64 v3; // r12
  int v4; // edx
  __int64 v5; // r13
  int v6; // ebp
  __int64 v7; // rax
  __int64 result; // rax
  __int64 *v9; // rbx
  __int64 v10; // rax
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // [rsp+8h] [rbp-70h]
  __int64 v16[11]; // [rsp+20h] [rbp-58h] BYREF

  __asm { vmovss  [rsp+78h+var_64], xmm0 }
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  if ( *(_DWORD *)(a1 + 48) > 1u )
    __assert_fail(
      "y->item_type == NC_TYPE_F32 || y->item_type == NC_TYPE_BF16",
      "libnc.c",
      0x146Cu,
      "nc_tensor_set_dropout");
  v4 = *(_DWORD *)(a1 + 80);
  if ( v4 <= 0 )
  {
    v16[0] = 0LL;
    v6 = 0;
    result = 0LL;
    v14 = 1LL;
    goto LABEL_16;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v14 = 1LL;
    v6 = 0;
    goto LABEL_12;
  }
  v5 = *(_QWORD *)(a1 + 120);
  if ( v4 == 1 )
  {
    v6 = 1;
    goto LABEL_11;
  }
  if ( !*(_BYTE *)(a1 + 74) )
  {
    v6 = 1;
LABEL_39:
    v16[0] = 0LL;
    v14 = (int)v5;
LABEL_13:
    v7 = 1LL;
    do
      v16[v7++] = 0LL;
    while ( v4 > (int)v7 );
    result = v16[0];
    goto LABEL_16;
  }
  v5 *= *(_QWORD *)(a1 + 128);
  if ( v4 == 2 )
  {
    v6 = 2;
    goto LABEL_11;
  }
  if ( !*(_BYTE *)(a1 + 75) )
  {
    v6 = 2;
    goto LABEL_39;
  }
  v5 *= *(_QWORD *)(a1 + 136);
  if ( v4 == 3 )
  {
    v6 = 3;
    goto LABEL_11;
  }
  if ( !*(_BYTE *)(a1 + 76) )
  {
    v6 = 3;
    goto LABEL_39;
  }
  v5 *= *(_QWORD *)(a1 + 144);
  v6 = 4;
LABEL_11:
  v14 = (int)v5;
LABEL_12:
  v16[0] = 0LL;
  if ( v4 > 1 )
    goto LABEL_13;
  result = 0LL;
LABEL_16:
  v9 = &v16[v6];
  while ( result != -1 )
  {
    if ( v4 <= 0 )
      goto LABEL_23;
    v10 = *(_QWORD *)(a1 + 88) * result;
    if ( v4 != 1 )
    {
      v10 += *(_QWORD *)(a1 + 96) * v16[1];
      if ( v4 != 2 )
      {
        v10 += *(_QWORD *)(a1 + 104) * v16[2];
        if ( v4 != 3 )
        {
          if ( v4 != 4 )
          {
LABEL_23:
            v10 = 0LL;
            goto LABEL_24;
          }
          v10 += *(_QWORD *)(a1 + 112) * v16[3];
        }
      }
    }
LABEL_24:
    __asm { vmovss  xmm0, [rsp+78h+var_64] }
    result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, double))(v3 + 480))(
               v3,
               v10 + *(_QWORD *)(a1 + 56),
               v14,
               a2,
               *(unsigned int *)(a1 + 48),
               *(double *)&_XMM0);
    v4 = *(_DWORD *)(a1 + 80);
    if ( v4 <= v6 )
      return result;
    v12 = *v9 + 1;
    *v9 = v12;
    if ( v12 == *(_QWORD *)(a1 + 8 * (v6 + 12LL) + 24) )
    {
      result = 0LL;
      do
      {
        v9[result] = 0LL;
        if ( result == v4 - 1 - v6 )
          return result;
        v13 = v9[result + 1] + 1;
        v9[++result] = v13;
      }
      while ( v13 == *(_QWORD *)(a1 + 8LL * (unsigned int)(v6 + 1) + 8 * result + 112) );
    }
    result = v16[0];
  }
  return result;
}

