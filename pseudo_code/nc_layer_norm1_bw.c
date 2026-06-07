// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_layer_norm1_bw
// Included functions: 1

// ======================================================
// Function: nc_layer_norm1_bw @ 0x66A2AC70
// ======================================================

_QWORD *__fastcall nc_layer_norm1_bw(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  _QWORD *v7; // rax
  __int64 v8; // r9
  int v9; // r15d
  _QWORD *v10; // rdi
  __int64 v11; // rax
  __int64 v12; // rax
  int v13; // ecx
  __int64 v14; // rax
  __int64 v15; // rsi
  __int64 *v16; // rbx
  int v17; // edx
  __int64 v18; // rcx
  __int64 v19; // rax
  __int64 v20; // r8
  int v21; // edx
  __int64 v22; // r10
  int v23; // ecx
  __int64 v24; // rax
  __int64 v25; // rax
  int v26; // ecx
  __int64 v27; // rdx
  __int64 v29; // [rsp+68h] [rbp-B0h]
  __int64 v30; // [rsp+90h] [rbp-88h]
  __int64 v31; // [rsp+98h] [rbp-80h]
  __int64 v32; // [rsp+B0h] [rbp-68h] BYREF
  __int64 v33; // [rsp+B8h] [rbp-60h]
  __int64 v34; // [rsp+C0h] [rbp-58h]
  __int64 v35; // [rsp+C8h] [rbp-50h]
  __int64 v36; // [rsp+D0h] [rbp-48h]

  v29 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24i64);
  v7 = nc_new_tensor_nz(v29, *(_DWORD *)(a1 + 48), *(_DWORD *)(a1 + 80), a1 + 120);
  v9 = *((_DWORD *)v7 + 20);
  v10 = v7;
  if ( v9 > 1 && *((_BYTE *)v7 + 74) && *(_BYTE *)(a1 + 74) && *(_BYTE *)(a2 + 74) && *(_BYTE *)(a3 + 73) )
  {
    v11 = v7[16];
    v31 = v11;
    if ( v9 != 2 )
    {
      if ( *((_BYTE *)v10 + 75) && *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) && *(_BYTE *)(a3 + 74) )
      {
        v12 = v10[17] * v11;
        v31 = v12;
        if ( v9 != 3 )
        {
          if ( *((_BYTE *)v10 + 76) && *(_BYTE *)(a1 + 76) && *(_BYTE *)(a2 + 76) && *(_BYTE *)(a3 + 75) )
          {
            v9 = 4;
            v31 = v10[18] * v12;
          }
          else
          {
            v9 = 3;
          }
        }
      }
      else
      {
        v9 = 2;
      }
    }
  }
  else
  {
    v9 = 1;
    v31 = 1i64;
  }
  v32 = 0i64;
  v13 = *(_DWORD *)(a1 + 80);
  if ( v13 <= 1 )
  {
    v15 = 0i64;
  }
  else
  {
    v14 = 1i64;
    do
      *(&v32 + v14++) = 0i64;
    while ( v13 > (int)v14 );
    v15 = v32;
  }
  v16 = &v32 + v9;
  while ( v15 != -1 )
  {
    v17 = *(_DWORD *)(a3 + 80);
    v18 = *(_QWORD *)(a3 + 56);
    if ( v17 <= 0 )
    {
      v19 = 0i64;
    }
    else
    {
      v19 = *(_QWORD *)(a3 + 88) * v33;
      if ( v17 != 1 )
      {
        v19 += *(_QWORD *)(a3 + 96) * v34;
        if ( v17 != 2 )
        {
          v19 += *(_QWORD *)(a3 + 104) * v35;
          if ( v17 != 3 )
          {
            v20 = v36;
            v8 = *(_QWORD *)(a3 + 112);
            goto LABEL_28;
          }
        }
      }
    }
    while ( 1 )
    {
      v21 = *(_DWORD *)(a2 + 80);
      v30 = v18 + v19;
      if ( v21 <= 0 )
      {
        v19 = 0i64;
      }
      else
      {
        v19 = *(_QWORD *)(a2 + 88) * v15;
        if ( v21 != 1 )
        {
          v19 += *(_QWORD *)(a2 + 96) * v33;
          if ( v21 != 2 )
          {
            v19 += *(_QWORD *)(a2 + 104) * v34;
            if ( v21 != 3 )
            {
              v18 = v35;
              v20 = *(_QWORD *)(a2 + 112);
              if ( v21 != 4 )
                goto LABEL_28;
              v19 += v20 * v35;
            }
          }
        }
      }
      v22 = v19 + *(_QWORD *)(a2 + 56);
      v19 = *(unsigned int *)(a1 + 80);
      if ( (int)v19 <= 0 )
      {
        v8 = 0i64;
      }
      else
      {
        v8 = *(_QWORD *)(a1 + 88) * v15;
        if ( (_DWORD)v19 != 1 )
        {
          v8 += *(_QWORD *)(a1 + 96) * v33;
          if ( (_DWORD)v19 != 2 )
          {
            v8 += *(_QWORD *)(a1 + 104) * v34;
            if ( (_DWORD)v19 != 3 )
            {
              v18 = v35;
              v20 = *(_QWORD *)(a1 + 112);
              if ( (_DWORD)v19 != 4 )
                goto LABEL_28;
              v8 += v20 * v35;
            }
          }
        }
      }
      v19 = *((unsigned int *)v10 + 20);
      v8 += *(_QWORD *)(a1 + 56);
      v20 = v10[8];
      v18 = v10[7];
      if ( (int)v19 <= 0 )
        break;
      v15 *= v10[11];
      if ( (_DWORD)v19 == 1 )
        goto LABEL_47;
      v15 += v10[12] * v33;
      if ( (_DWORD)v19 == 2 )
        goto LABEL_47;
      v15 += v10[13] * v34;
      if ( (_DWORD)v19 == 3 )
        goto LABEL_47;
      if ( (_DWORD)v19 == 4 )
      {
        v15 += v10[14] * v35;
        goto LABEL_47;
      }
LABEL_28:
      v19 += v8 * v20;
    }
    v15 = 0i64;
LABEL_47:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, __int64, int, _DWORD))(v29 + 424))(
      v29,
      v18 + v15,
      v20,
      v8,
      *(_QWORD *)(a1 + 64),
      v22,
      *(_QWORD *)(a2 + 64),
      v30,
      v10[15],
      v31,
      a4,
      *(_DWORD *)(a1 + 48));
    v23 = *(_DWORD *)(a1 + 80);
    if ( v9 < v23 )
    {
      v24 = *v16 + 1;
      *v16 = v24;
      if ( v24 != *(_QWORD *)(a1 + 8 * (v9 + 12i64) + 24) )
      {
LABEL_53:
        v15 = v32;
        continue;
      }
      v25 = 0i64;
      v26 = v23 - 1 - v9;
      while ( 1 )
      {
        v16[v25] = 0i64;
        if ( v25 == v26 )
          break;
        v27 = v16[v25 + 1] + 1;
        v16[++v25] = v27;
        if ( v27 != *(_QWORD *)(a1 + 8i64 * (unsigned int)(v9 + 1) + 8 * v25 + 112) )
          goto LABEL_53;
      }
    }
    break;
  }
  nc_free_tensor((_DWORD *)a1);
  nc_free_tensor((_DWORD *)a2);
  nc_free_tensor((_DWORD *)a3);
  return v10;
}

