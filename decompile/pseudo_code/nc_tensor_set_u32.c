// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_tensor_set_u32
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_u32 @ 0x66A16E50
// ======================================================

__int64 __fastcall nc_tensor_set_u32(__int64 a1, unsigned int a2)
{
  __int64 v2; // rdi
  int v4; // ecx
  __int64 v5; // rbp
  int v6; // esi
  __int64 v7; // rax
  __int64 result; // rax
  __int64 *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13[13]; // [rsp+30h] [rbp-68h] BYREF

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v4 = *(_DWORD *)(a1 + 80);
  if ( v4 <= 0 )
  {
    v6 = 0;
    v5 = 1i64;
    result = 0i64;
    v13[0] = 0i64;
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(a1 + 73) )
  {
    v5 = 1i64;
    v6 = 0;
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(a1 + 120);
  if ( v4 == 1 )
  {
    v6 = 1;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 74) )
  {
    v6 = 1;
LABEL_38:
    v13[0] = 0i64;
    v5 = (int)v5;
LABEL_12:
    v7 = 1i64;
    do
      v13[v7++] = 0i64;
    while ( v4 > (int)v7 );
    result = v13[0];
    goto LABEL_15;
  }
  v5 *= *(_QWORD *)(a1 + 128);
  if ( v4 == 2 )
  {
    v6 = 2;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 75) )
  {
    v6 = 2;
    goto LABEL_38;
  }
  v5 *= *(_QWORD *)(a1 + 136);
  if ( v4 == 3 )
  {
    v6 = 3;
    goto LABEL_10;
  }
  if ( !*(_BYTE *)(a1 + 76) )
  {
    v6 = 3;
    goto LABEL_38;
  }
  v5 *= *(_QWORD *)(a1 + 144);
  v6 = 4;
LABEL_10:
  v5 = (int)v5;
LABEL_11:
  v13[0] = 0i64;
  if ( v4 > 1 )
    goto LABEL_12;
  result = 0i64;
LABEL_15:
  v9 = &v13[v6];
  while ( result != -1 )
  {
    if ( v4 <= 0 )
      goto LABEL_22;
    v10 = *(_QWORD *)(a1 + 88) * result;
    if ( v4 != 1 )
    {
      v10 += *(_QWORD *)(a1 + 96) * v13[1];
      if ( v4 != 2 )
      {
        v10 += *(_QWORD *)(a1 + 104) * v13[2];
        if ( v4 != 3 )
        {
          if ( v4 != 4 )
          {
LABEL_22:
            v10 = 0i64;
            goto LABEL_23;
          }
          v10 += *(_QWORD *)(a1 + 112) * v13[3];
        }
      }
    }
LABEL_23:
    result = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, _DWORD))(v2 + 104))(
               v2,
               *(_QWORD *)(a1 + 56) + v10,
               a2,
               v5,
               dword_66A375E0[*(unsigned int *)(a1 + 48)]);
    v4 = *(_DWORD *)(a1 + 80);
    if ( v4 <= v6 )
      return result;
    v11 = *v9 + 1;
    *v9 = v11;
    if ( v11 == *(_QWORD *)(a1 + 8 * (v6 + 12i64) + 24) )
    {
      result = 0i64;
      do
      {
        v9[result] = 0i64;
        if ( result == v4 - 1 - v6 )
          return result;
        v12 = v9[result + 1] + 1;
        v9[++result] = v12;
      }
      while ( v12 == *(_QWORD *)(a1 + 8i64 * (unsigned int)(v6 + 1) + 8 * result + 112) );
    }
    result = v13[0];
  }
  return result;
}

