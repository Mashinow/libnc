// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_u32
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_u32 @ 0x18770
// ======================================================

__int64 __fastcall nc_tensor_set_u32(__int64 a1, unsigned int a2)
{
  int v2; // edx
  __int64 v3; // r12
  __int64 v4; // r13
  int v5; // ebp
  __int64 v6; // rax
  __int64 result; // rax
  __int64 *v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // [rsp+0h] [rbp-68h]
  __int64 v13[11]; // [rsp+10h] [rbp-58h] BYREF

  v2 = *(_DWORD *)(a1 + 80);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  if ( v2 <= 0 )
  {
    v13[0] = 0LL;
    v5 = 0;
    result = 0LL;
    v12 = 1LL;
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v12 = 1LL;
    v5 = 0;
    goto LABEL_11;
  }
  v4 = *(_QWORD *)(a1 + 120);
  if ( v2 == 1 )
  {
    v5 = 1;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 74) )
  {
    v5 = 1;
LABEL_38:
    v13[0] = 0LL;
    v12 = (int)v4;
LABEL_12:
    v6 = 1LL;
    do
      v13[v6++] = 0LL;
    while ( v2 > (int)v6 );
    result = v13[0];
    goto LABEL_15;
  }
  v4 *= *(_QWORD *)(a1 + 128);
  if ( v2 == 2 )
  {
    v5 = 2;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 75) )
  {
    v5 = 2;
    goto LABEL_38;
  }
  v4 *= *(_QWORD *)(a1 + 136);
  if ( v2 == 3 )
  {
    v5 = 3;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 76) )
  {
    v5 = 3;
    goto LABEL_38;
  }
  v4 *= *(_QWORD *)(a1 + 144);
  v5 = 4;
LABEL_10:
  v12 = (int)v4;
LABEL_11:
  v13[0] = 0LL;
  if ( v2 > 1 )
    goto LABEL_12;
  result = 0LL;
LABEL_15:
  v8 = &v13[v5];
  while ( result != -1 )
  {
    if ( v2 <= 0 )
      goto LABEL_22;
    v9 = *(_QWORD *)(a1 + 88) * result;
    if ( v2 != 1 )
    {
      v9 += *(_QWORD *)(a1 + 96) * v13[1];
      if ( v2 != 2 )
      {
        v9 += *(_QWORD *)(a1 + 104) * v13[2];
        if ( v2 != 3 )
        {
          if ( v2 != 4 )
          {
LABEL_22:
            v9 = 0LL;
            goto LABEL_23;
          }
          v9 += *(_QWORD *)(a1 + 112) * v13[3];
        }
      }
    }
LABEL_23:
    result = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD))(v3 + 104))(
               v3,
               v9 + *(_QWORD *)(a1 + 56),
               a2,
               v12,
               (unsigned int)dword_30520[*(unsigned int *)(a1 + 48)]);
    v2 = *(_DWORD *)(a1 + 80);
    if ( v2 <= v5 )
      return result;
    v10 = *v8 + 1;
    *v8 = v10;
    if ( v10 == *(_QWORD *)(a1 + 8 * (v5 + 12LL) + 24) )
    {
      result = 0LL;
      do
      {
        v8[result] = 0LL;
        if ( result == v2 - 1 - v5 )
          return result;
        v11 = v8[result + 1] + 1;
        v8[++result] = v11;
      }
      while ( v11 == *(_QWORD *)(a1 + 8LL * (unsigned int)(v5 + 1) + 8 * result + 112) );
    }
    result = v13[0];
  }
  return result;
}

