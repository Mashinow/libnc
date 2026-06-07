// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_layer_norm1_bw
// Included functions: 1

// ======================================================
// Function: nc_layer_norm1_bw @ 0x26120
// ======================================================

__int64 __fastcall nc_layer_norm1_bw(_QWORD *ptr, _BYTE *a2, _BYTE *a3, unsigned int a4)
{
  __int64 v7; // r8
  __int64 v8; // r15
  int v9; // eax
  int v10; // ecx
  __int64 v11; // rax
  __int64 v12; // rbp
  __int64 *v13; // rbx
  _BYTE *v14; // rax
  char *v15; // r12
  int v16; // ecx
  __int64 v17; // rsi
  __int64 v18; // rdx
  __int64 v19; // rdi
  __int64 v20; // rsi
  __int64 v21; // r9
  __int64 v22; // r9
  __int64 v23; // rcx
  __int64 v24; // rcx
  int v25; // esi
  __int64 v26; // rdx
  __int64 v27; // rdx
  int v28; // esi
  __int64 v29; // rcx
  void *v30; // r12
  int v32; // [rsp+Ch] [rbp-9Ch]
  __int64 v33; // [rsp+10h] [rbp-98h]
  __int64 v34; // [rsp+28h] [rbp-80h]
  _BYTE *v35; // [rsp+30h] [rbp-78h]
  __int64 v36; // [rsp+38h] [rbp-70h]
  __int64 v38; // [rsp+50h] [rbp-58h] BYREF
  __int64 v39; // [rsp+58h] [rbp-50h]
  __int64 v40; // [rsp+60h] [rbp-48h]
  __int64 v41; // [rsp+68h] [rbp-40h]
  __int64 v42; // [rsp+70h] [rbp-38h]

  v33 = *(_QWORD *)(ptr[5] + 24LL);
  v8 = nc_new_tensor_nz(v33, *((unsigned int *)ptr + 12), *((unsigned int *)ptr + 20), ptr + 15);
  v9 = *(_DWORD *)(v8 + 80);
  v32 = v9;
  if ( v9 > 1 && *(_BYTE *)(v8 + 74) && *((_BYTE *)ptr + 74) && a2[74] && a3[73] )
  {
    v36 = *(_QWORD *)(v8 + 128);
    if ( v9 != 2 )
    {
      if ( *(_BYTE *)(v8 + 75) && *((_BYTE *)ptr + 75) && a2[75] && a3[74] )
      {
        v36 = *(_QWORD *)(v8 + 136) * *(_QWORD *)(v8 + 128);
        if ( v9 != 3 )
        {
          if ( *(_BYTE *)(v8 + 76) && *((_BYTE *)ptr + 76) && a2[76] && a3[75] )
          {
            v32 = 4;
            v36 = *(_QWORD *)(v8 + 144) * *(_QWORD *)(v8 + 136) * *(_QWORD *)(v8 + 128);
          }
          else
          {
            v32 = 3;
          }
        }
      }
      else
      {
        v32 = 2;
      }
    }
  }
  else
  {
    v32 = 1;
    v36 = 1LL;
  }
  v38 = 0LL;
  v10 = *((_DWORD *)ptr + 20);
  if ( v10 <= 1 )
  {
    v12 = 0LL;
  }
  else
  {
    v11 = 1LL;
    do
      *(&v38 + v11++) = 0LL;
    while ( v10 > (int)v11 );
    v12 = v38;
  }
  v13 = &v38 + v32;
  v14 = a3;
  v15 = (char *)&ptr[v32 + 1];
  while ( v12 != -1 )
  {
    v16 = *((_DWORD *)v14 + 20);
    v17 = *((_QWORD *)v14 + 7);
    if ( v16 <= 0 )
    {
      v18 = 0LL;
    }
    else
    {
      v18 = *((_QWORD *)v14 + 11) * v39;
      if ( v16 != 1 )
      {
        v18 += *((_QWORD *)v14 + 12) * v40;
        if ( v16 != 2 )
        {
          v18 += *((_QWORD *)v14 + 13) * v41;
          if ( v16 != 3 )
          {
            v19 = v42;
            v7 = *((_QWORD *)v14 + 14);
            goto LABEL_28;
          }
        }
      }
    }
    while ( 1 )
    {
      v20 = v18 + v17;
      v18 = *((unsigned int *)a2 + 20);
      v34 = v20;
      if ( (int)v18 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *((_QWORD *)a2 + 11) * v12;
        if ( (_DWORD)v18 != 1 )
        {
          v21 += *((_QWORD *)a2 + 12) * v39;
          if ( (_DWORD)v18 != 2 )
          {
            v21 += *((_QWORD *)a2 + 13) * v40;
            if ( (_DWORD)v18 != 3 )
            {
              v17 = v41;
              v19 = *((_QWORD *)a2 + 14);
              if ( (_DWORD)v18 != 4 )
                goto LABEL_28;
              v21 += v19 * v41;
            }
          }
        }
      }
      v18 = *((unsigned int *)ptr + 20);
      v22 = *((_QWORD *)a2 + 7) + v21;
      v7 = ptr[8];
      v17 = ptr[7];
      if ( (int)v18 <= 0 )
      {
        v23 = 0LL;
      }
      else
      {
        v23 = ptr[11] * v12;
        if ( (_DWORD)v18 != 1 )
        {
          v23 += ptr[12] * v39;
          if ( (_DWORD)v18 != 2 )
          {
            v23 += ptr[13] * v40;
            if ( (_DWORD)v18 != 3 )
            {
              v19 = v41;
              if ( (_DWORD)v18 != 4 )
                goto LABEL_28;
              v23 += ptr[14] * v41;
            }
          }
        }
      }
      v19 = *(unsigned int *)(v8 + 80);
      v24 = v17 + v23;
      v18 = *(_QWORD *)(v8 + 64);
      if ( (int)v19 <= 0 )
        break;
      v12 *= *(_QWORD *)(v8 + 88);
      if ( (_DWORD)v19 == 1 )
        goto LABEL_47;
      v12 += *(_QWORD *)(v8 + 96) * v39;
      if ( (_DWORD)v19 == 2 )
        goto LABEL_47;
      v12 += *(_QWORD *)(v8 + 104) * v40;
      if ( (_DWORD)v19 == 3 )
        goto LABEL_47;
      v17 = *(_QWORD *)(v8 + 112);
      if ( (_DWORD)v19 == 4 )
      {
        v12 += v41 * v17;
        goto LABEL_47;
      }
LABEL_28:
      v18 += v7 * v19;
    }
    v12 = 0LL;
LABEL_47:
    v35 = v14;
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64, _QWORD, _QWORD))(v33 + 424))(
      v33,
      *(_QWORD *)(v8 + 56) + v12,
      v18,
      v24,
      v7,
      v22,
      *((_QWORD *)a2 + 8),
      v34,
      *(_QWORD *)(v8 + 120),
      v36,
      a4,
      *((unsigned int *)ptr + 12));
    v25 = *((_DWORD *)ptr + 20);
    v14 = v35;
    if ( v32 < v25 )
    {
      v26 = *v13 + 1;
      *v13 = v26;
      if ( v26 != ptr[v32 + 15] )
      {
LABEL_53:
        v12 = v38;
        continue;
      }
      v27 = 0LL;
      v28 = v25 - 1 - v32;
      while ( 1 )
      {
        v13[v27] = 0LL;
        if ( v27 == v28 )
          break;
        v29 = v13[v27 + 1] + 1;
        v13[++v27] = v29;
        if ( v29 != *(_QWORD *)&v15[8 * v27 + 112] )
          goto LABEL_53;
      }
    }
    break;
  }
  v30 = v14;
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  nc_free_tensor(v30);
  return v8;
}

