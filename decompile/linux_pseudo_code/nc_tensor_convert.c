// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_tensor_convert
// Included functions: 1

// ======================================================
// Function: nc_tensor_convert @ 0x1A110
// ======================================================

__int64 __fastcall nc_tensor_convert(__int64 a1, __int64 a2)
{
  int v2; // r12d
  _QWORD *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rsi
  __int64 *v14; // r13
  __int64 result; // rax
  __int64 *v16; // rbx
  int v17; // ecx
  __int64 v18; // r10
  __int64 v19; // rdx
  __int64 v20; // rdi
  __int64 v21; // r11
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  __int64 v25; // rdx
  int v26; // ecx
  __int64 v27; // rax
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  __int64 v32; // rdx
  int v33; // ecx
  __int64 v34; // rax
  int v35; // ecx
  int v36; // ecx
  __int64 v37; // rdx
  int v38; // ecx
  int v39; // ecx
  __int64 v40; // rdx
  int v41; // ecx
  __int64 v42; // rax
  int v43; // ecx
  int v44; // ecx
  __int64 v45; // rdx
  int v46; // ecx
  int v47; // ecx
  __int64 v48; // rdx
  __int64 v49; // [rsp+0h] [rbp-68h]
  __int64 v50; // [rsp+8h] [rbp-60h]
  __int64 v51; // [rsp+10h] [rbp-58h] BYREF
  __int64 v52; // [rsp+18h] [rbp-50h]
  __int64 v53; // [rsp+20h] [rbp-48h]
  __int64 v54; // [rsp+28h] [rbp-40h]

  v2 = *(_DWORD *)(a1 + 80);
  if ( v2 != *(_DWORD *)(a2 + 80) )
LABEL_2:
    __assert_fail("same_dims(dst, src)", "libnc.c", 0x1423u, "nc_tensor_convert");
  v5 = *(_QWORD **)(*(_QWORD *)(a1 + 40) + 24LL);
  if ( v2 <= 0 )
  {
    if ( v5 == *(_QWORD **)(*(_QWORD *)(a2 + 40) + 24LL) )
    {
LABEL_55:
      v49 = 1LL;
      v2 = 0;
      goto LABEL_22;
    }
LABEL_54:
    nc_error("all operation tensors must be on the same device", a2);
  }
  if ( *(_QWORD *)(a1 + 120) != *(_QWORD *)(a2 + 120) )
    goto LABEL_2;
  v6 = 1LL;
  while ( v2 > (int)v6 )
  {
    v7 = *(_QWORD *)(a1 + 8 * v6++ + 120);
    if ( v7 != *(_QWORD *)(a2 + 8 * v6 + 112) )
      goto LABEL_2;
  }
  if ( v5 != *(_QWORD **)(*(_QWORD *)(a2 + 40) + 24LL) )
    goto LABEL_54;
  if ( !*(_BYTE *)(a1 + 73) || !*(_BYTE *)(a2 + 73) )
    goto LABEL_55;
  v8 = *(_QWORD *)(a1 + 120);
  if ( v2 != 1 )
  {
    if ( *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) )
    {
      v8 *= *(_QWORD *)(a1 + 128);
      if ( v2 != 2 )
      {
        if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
        {
          v8 *= *(_QWORD *)(a1 + 136);
          if ( v2 != 3 )
          {
            if ( *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) )
            {
              v8 *= *(_QWORD *)(a1 + 144);
              v2 = 4;
            }
            else
            {
              v2 = 3;
            }
          }
        }
        else
        {
          v2 = 2;
        }
      }
    }
    else
    {
      v2 = 1;
    }
  }
  v49 = (int)v8;
LABEL_22:
  v9 = *(_DWORD *)(a1 + 48);
  if ( v9 == 2 )
  {
    if ( *(_DWORD *)(a2 + 48) )
      goto LABEL_58;
    v51 = 0LL;
    v26 = *(_DWORD *)(a2 + 80);
    if ( v26 <= 1 )
    {
      v13 = 0LL;
    }
    else
    {
      v27 = 1LL;
      do
        *(&v51 + v27++) = 0LL;
      while ( v26 > (int)v27 );
      v13 = v51;
    }
    v16 = (__int64 *)(a2 + 8LL * (unsigned int)(v2 + 1));
    result = v2 + 12LL;
    v50 = result;
    v14 = &v51 + v2;
    while ( v13 != -1 )
    {
      v28 = *(_DWORD *)(a2 + 80);
      result = v5[17];
      v18 = *(_QWORD *)(a2 + 56);
      if ( v28 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = *(_QWORD *)(a2 + 88) * v13;
        if ( v28 != 1 )
        {
          v19 += *(_QWORD *)(a2 + 96) * v52;
          if ( v28 != 2 )
          {
            v19 += *(_QWORD *)(a2 + 104) * v53;
            if ( v28 != 3 )
            {
              v20 = v54;
              v21 = *(_QWORD *)(a2 + 112);
              if ( v28 != 4 )
                goto LABEL_37;
              v19 += v21 * v54;
            }
          }
        }
      }
      v29 = *(_DWORD *)(a1 + 80);
      v19 += v18;
      v20 = *(_QWORD *)(a1 + 56);
      if ( v29 <= 0 )
      {
        v13 = 0LL;
      }
      else
      {
        v13 *= *(_QWORD *)(a1 + 88);
        if ( v29 != 1 )
        {
          v13 += *(_QWORD *)(a1 + 96) * v52;
          if ( v29 != 2 )
          {
            v13 += *(_QWORD *)(a1 + 104) * v53;
            if ( v29 != 3 )
            {
              v18 = v54;
              v21 = *(_QWORD *)(a1 + 112);
              if ( v29 != 4 )
              {
LABEL_37:
                v19 += v21 * v20;
                while ( 1 )
                {
                  v22 = *(_DWORD *)(a1 + 80);
                  v19 += v18;
                  v20 = *(_QWORD *)(a1 + 56);
                  if ( v22 <= 0 )
                  {
                    v13 = 0LL;
                  }
                  else
                  {
                    v13 *= *(_QWORD *)(a1 + 88);
                    if ( v22 != 1 )
                    {
                      v13 += *(_QWORD *)(a1 + 96) * v52;
                      if ( v22 != 2 )
                      {
                        v13 += *(_QWORD *)(a1 + 104) * v53;
                        if ( v22 != 3 )
                        {
                          v18 = v54;
                          v21 = *(_QWORD *)(a1 + 112);
                          if ( v22 != 4 )
                            goto LABEL_37;
                          v13 += v21 * v54;
                        }
                      }
                    }
                  }
                  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(
                             v5,
                             v20 + v13,
                             v19,
                             v49);
                  v23 = *(_DWORD *)(a2 + 80);
                  if ( v23 <= v2 )
                    return result;
                  result = *v16 + 1;
                  *v16 = result;
                  if ( *(_QWORD *)(a2 + 8 * v50 + 24) == result )
                  {
                    result = 0LL;
                    v24 = v23 - 1 - v2;
                    do
                    {
                      v16[result] = 0LL;
                      if ( v24 == result )
                        return result;
                      v25 = v16[result + 1] + 1;
                      v16[++result] = v25;
                    }
                    while ( v25 == v14[result + 14] );
                  }
                  v13 = v51;
LABEL_31:
                  if ( v13 == -1 )
                    return result;
                  v17 = *(_DWORD *)(a2 + 80);
                  result = v5[20];
                  v18 = *(_QWORD *)(a2 + 56);
                  if ( v17 <= 0 )
                  {
                    v19 = 0LL;
                  }
                  else
                  {
                    v19 = *(_QWORD *)(a2 + 88) * v13;
                    if ( v17 != 1 )
                    {
                      v19 += *(_QWORD *)(a2 + 96) * v52;
                      if ( v17 != 2 )
                      {
                        v19 += *(_QWORD *)(a2 + 104) * v53;
                        if ( v17 != 3 )
                        {
                          v20 = v54;
                          v21 = *(_QWORD *)(a2 + 112);
                          goto LABEL_37;
                        }
                      }
                    }
                  }
                }
              }
              v13 += v21 * v54;
            }
          }
        }
      }
      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(v5, v20 + v13, v19, v49);
      v30 = *(_DWORD *)(a2 + 80);
      if ( v30 <= v2 )
        return result;
      result = *v14 + 1;
      *v14 = result;
      if ( result == *(_QWORD *)(a2 + 8 * v50 + 24) )
      {
        result = 0LL;
        v31 = v30 - 1 - v2;
        do
        {
          v14[result] = 0LL;
          if ( result == v31 )
            return result;
          v32 = v14[result + 1] + 1;
          v14[++result] = v32;
        }
        while ( v32 == v16[result + 14] );
      }
      v13 = v51;
    }
  }
  else if ( v9 )
  {
    if ( v9 != 1 || *(_DWORD *)(a2 + 48) )
      goto LABEL_58;
    v51 = 0LL;
    v41 = *(_DWORD *)(a2 + 80);
    if ( v41 <= 1 )
    {
      result = 0LL;
    }
    else
    {
      v42 = 1LL;
      do
        *(&v51 + v42++) = 0LL;
      while ( v41 > (int)v42 );
      result = v51;
    }
    v14 = &v51 + v2;
    v50 = v2 + 12LL;
    v16 = (__int64 *)(a2 + 8LL * (unsigned int)(v2 + 1));
    while ( result != -1 )
    {
      v43 = *(_DWORD *)(a2 + 80);
      v18 = v5[19];
      v20 = *(_QWORD *)(a2 + 56);
      if ( v43 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = *(_QWORD *)(a2 + 88) * result;
        if ( v43 != 1 )
        {
          v19 += *(_QWORD *)(a2 + 96) * v52;
          if ( v43 != 2 )
          {
            v19 += *(_QWORD *)(a2 + 104) * v53;
            if ( v43 != 3 )
            {
              v13 = v54;
              v21 = *(_QWORD *)(a2 + 112);
              if ( v43 != 4 )
                goto LABEL_37;
              v19 += v21 * v54;
            }
          }
        }
      }
      v44 = *(_DWORD *)(a1 + 80);
      v19 += v20;
      v13 = *(_QWORD *)(a1 + 56);
      if ( v44 <= 0 )
      {
        result = 0LL;
      }
      else
      {
        result *= *(_QWORD *)(a1 + 88);
        if ( v44 != 1 )
        {
          result += *(_QWORD *)(a1 + 96) * v52;
          if ( v44 != 2 )
          {
            result += *(_QWORD *)(a1 + 104) * v53;
            if ( v44 != 3 )
            {
              v20 = v54;
              v21 = *(_QWORD *)(a1 + 112);
              if ( v44 != 4 )
                goto LABEL_37;
              result += v21 * v54;
            }
          }
        }
      }
      ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v18)(v5, result + v13, v19, v49);
      result = *(unsigned int *)(a2 + 80);
      if ( (int)result <= v2 )
        break;
      v45 = *v14 + 1;
      *v14 = v45;
      if ( v45 == *(_QWORD *)(a2 + 8 * v50 + 24) )
      {
        v46 = result - 1;
        result = 0LL;
        v47 = v46 - v2;
        do
        {
          v14[result] = 0LL;
          if ( result == v47 )
            return result;
          v48 = v14[result + 1] + 1;
          v14[++result] = v48;
        }
        while ( v48 == v16[result + 14] );
      }
      result = v51;
    }
  }
  else
  {
    v10 = *(_DWORD *)(a2 + 48);
    if ( v10 != 2 )
    {
      if ( v10 == 1 )
      {
        v51 = 0LL;
        v11 = *(_DWORD *)(a2 + 80);
        if ( v11 <= 1 )
        {
          v13 = 0LL;
        }
        else
        {
          v12 = 1LL;
          do
            *(&v51 + v12++) = 0LL;
          while ( v11 > (int)v12 );
          v13 = v51;
        }
        v14 = (__int64 *)(a2 + 8LL * (unsigned int)(v2 + 1));
        result = v2 + 12LL;
        v50 = result;
        v16 = &v51 + v2;
        goto LABEL_31;
      }
LABEL_58:
      abort();
    }
    v51 = 0LL;
    v33 = *(_DWORD *)(a2 + 80);
    if ( v33 <= 1 )
    {
      v13 = 0LL;
    }
    else
    {
      v34 = 1LL;
      do
        *(&v51 + v34++) = 0LL;
      while ( v33 > (int)v34 );
      v13 = v51;
    }
    v16 = (__int64 *)(a2 + 8LL * (unsigned int)(v2 + 1));
    result = v2 + 12LL;
    v50 = result;
    v14 = &v51 + v2;
    while ( v13 != -1 )
    {
      v35 = *(_DWORD *)(a2 + 80);
      result = v5[18];
      v18 = *(_QWORD *)(a2 + 56);
      if ( v35 <= 0 )
      {
        v19 = 0LL;
      }
      else
      {
        v19 = *(_QWORD *)(a2 + 88) * v13;
        if ( v35 != 1 )
        {
          v19 += *(_QWORD *)(a2 + 96) * v52;
          if ( v35 != 2 )
          {
            v19 += *(_QWORD *)(a2 + 104) * v53;
            if ( v35 != 3 )
            {
              v20 = v54;
              v21 = *(_QWORD *)(a2 + 112);
              if ( v35 != 4 )
                goto LABEL_37;
              v19 += v21 * v54;
            }
          }
        }
      }
      v36 = *(_DWORD *)(a1 + 80);
      v19 += v18;
      v20 = *(_QWORD *)(a1 + 56);
      if ( v36 <= 0 )
      {
        v13 = 0LL;
      }
      else
      {
        v13 *= *(_QWORD *)(a1 + 88);
        if ( v36 != 1 )
        {
          v13 += *(_QWORD *)(a1 + 96) * v52;
          if ( v36 != 2 )
          {
            v13 += *(_QWORD *)(a1 + 104) * v53;
            if ( v36 != 3 )
            {
              v18 = v54;
              v21 = *(_QWORD *)(a1 + 112);
              if ( v36 != 4 )
                goto LABEL_37;
              v13 += v21 * v54;
            }
          }
        }
      }
      ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))result)(v5, v20 + v13, v19, v49);
      result = *(unsigned int *)(a2 + 80);
      if ( (int)result <= v2 )
        break;
      v37 = *v14 + 1;
      *v14 = v37;
      if ( v37 == *(_QWORD *)(a2 + 8 * v50 + 24) )
      {
        v38 = result - 1;
        result = 0LL;
        v39 = v38 - v2;
        do
        {
          v14[result] = 0LL;
          if ( v39 == result )
            return result;
          v40 = v14[result + 1] + 1;
          v14[++result] = v40;
        }
        while ( v40 == v16[result + 14] );
      }
      v13 = v51;
    }
  }
  return result;
}

