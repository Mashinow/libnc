// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_set_rnd_unif
// Included functions: 1

// ======================================================
// Function: nc_tensor_set_rnd_unif @ 0x1A990
// ======================================================

__int64 __fastcall nc_tensor_set_rnd_unif(__int64 a1, __int64 a2, __m128 _XMM0, __m128 _XMM1)
{
  __int64 v4; // r12
  int v5; // edx
  __int64 v6; // rax
  int v7; // ebp
  __int64 v8; // rax
  __int64 result; // rax
  __int64 *v10; // rbx
  __int64 v11; // rax
  __int64 v14; // rax
  __int64 v15; // rcx
  void *v18; // rbx
  __int64 v19; // [rsp+8h] [rbp-70h]
  __int64 v22[11]; // [rsp+20h] [rbp-58h] BYREF

  __asm
  {
    vmovss  [rsp+78h+var_68], xmm0
    vmovss  [rsp+78h+var_64], xmm1
  }
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  if ( *(_DWORD *)(a1 + 48) > 1u )
    __assert_fail(
      "y->item_type == NC_TYPE_F32 || y->item_type == NC_TYPE_BF16",
      "libnc.c",
      0x1454u,
      "nc_tensor_set_rnd_unif");
  if ( *(_DWORD *)(a1 + 48) != 1 || v4 != *(_QWORD *)(*(_QWORD *)(a1 + 24) + 64LL) )
  {
    v5 = *(_DWORD *)(a1 + 80);
    if ( v5 <= 0 )
    {
      v22[0] = 0LL;
      v7 = 0;
      result = 0LL;
      v19 = 1LL;
      goto LABEL_17;
    }
    if ( !*(_BYTE *)(a1 + 73) )
    {
      v19 = 1LL;
      v7 = 0;
      goto LABEL_13;
    }
    v6 = *(_QWORD *)(a1 + 120);
    if ( v5 == 1 )
    {
      v7 = 1;
      goto LABEL_12;
    }
    if ( *(_BYTE *)(a1 + 74) )
    {
      v6 *= *(_QWORD *)(a1 + 128);
      if ( v5 == 2 )
      {
        v7 = 2;
        goto LABEL_12;
      }
      if ( *(_BYTE *)(a1 + 75) )
      {
        v6 *= *(_QWORD *)(a1 + 136);
        if ( v5 == 3 )
        {
          v7 = 3;
          goto LABEL_12;
        }
        if ( *(_BYTE *)(a1 + 76) )
        {
          v6 *= *(_QWORD *)(a1 + 144);
          v7 = 4;
LABEL_12:
          v19 = (int)v6;
LABEL_13:
          v22[0] = 0LL;
          if ( v5 > 1 )
            goto LABEL_14;
          result = 0LL;
LABEL_17:
          v10 = &v22[v7];
          while ( 1 )
          {
            if ( result == -1 )
              return result;
            if ( v5 <= 0 )
              break;
            v11 = *(_QWORD *)(a1 + 88) * result;
            if ( v5 != 1 )
            {
              v11 += *(_QWORD *)(a1 + 96) * v22[1];
              if ( v5 != 2 )
              {
                v11 += *(_QWORD *)(a1 + 104) * v22[2];
                if ( v5 != 3 )
                {
                  if ( v5 != 4 )
                    break;
                  v11 += *(_QWORD *)(a1 + 112) * v22[3];
                }
              }
            }
LABEL_25:
            __asm
            {
              vmovss  xmm1, [rsp+78h+var_64]
              vmovss  xmm0, [rsp+78h+var_68]
            }
            result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, double, double))(v4 + 472))(
                       v4,
                       v11 + *(_QWORD *)(a1 + 56),
                       v19,
                       a2,
                       *(unsigned int *)(a1 + 48),
                       *(double *)&_XMM0,
                       *(double *)&_XMM1);
            v5 = *(_DWORD *)(a1 + 80);
            if ( v5 <= v7 )
              return result;
            v14 = *v10 + 1;
            *v10 = v14;
            if ( v14 == *(_QWORD *)(a1 + 8 * (v7 + 12LL) + 24) )
            {
              result = 0LL;
              do
              {
                v10[result] = 0LL;
                if ( result == v5 - 1 - v7 )
                  return result;
                v15 = v10[result + 1] + 1;
                v10[++result] = v15;
              }
              while ( v15 == *(_QWORD *)(a1 + 8LL * (unsigned int)(v7 + 1) + 8 * result + 112) );
            }
            result = v22[0];
          }
          v11 = 0LL;
          goto LABEL_25;
        }
        v7 = 3;
      }
      else
      {
        v7 = 2;
      }
    }
    else
    {
      v7 = 1;
    }
    v22[0] = 0LL;
    v19 = (int)v6;
LABEL_14:
    v8 = 1LL;
    do
      v22[v8++] = 0LL;
    while ( v5 > (int)v8 );
    result = v22[0];
    goto LABEL_17;
  }
  __asm
  {
    vmovss  xmm1, [rsp+78h+var_64]
    vmovss  xmm0, [rsp+78h+var_68]
  }
  v18 = (void *)nc_new_tensor_nz(v4, 0LL, *(unsigned int *)(a1 + 80), a1 + 120);
  nc_tensor_set_rnd_unif(v18, a2, *(double *)&_XMM0, *(double *)&_XMM1);
  nc_tensor_convert(a1, v18);
  return nc_free_tensor(v18);
}

