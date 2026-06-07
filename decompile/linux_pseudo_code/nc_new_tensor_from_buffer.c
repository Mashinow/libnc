// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_tensor_from_buffer
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_from_buffer @ 0x166C0
// ======================================================

__int64 __fastcall nc_new_tensor_from_buffer(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        __int64 *a5,
        __int64 a6,
        _QWORD *a7)
{
  __int64 v7; // r15
  __int64 v12; // rax
  __int64 v13; // rbx
  __int64 v14; // rax
  int v15; // esi
  bool v16; // al
  bool v17; // cl
  char v18; // dl
  int v19; // edx
  __int64 v20; // rdx
  bool v21; // cl
  bool v22; // al
  bool v23; // al
  char v24; // al
  int v25; // ecx
  bool v26; // di
  int v27; // edx
  bool v28; // cl
  __int64 v29; // rax
  __int64 result; // rax

  v7 = a3;
  v12 = nc_mallocz(0x98uLL);
  *(_QWORD *)(v12 + 24) = a1;
  v13 = v12;
  *(_DWORD *)(v12 + 16) = 1;
  *(_DWORD *)(v12 + 48) = v7;
  *(_DWORD *)(v12 + 80) = a4;
  *(_QWORD *)(v12 + 40) = nc_dup_tensor_buffer(a2);
  if ( a4 > 0 )
  {
    v14 = *a5;
    *(_QWORD *)(v13 + 120) = *a5;
    *(_QWORD *)(v13 + 88) = *a7;
    if ( a4 == 1 )
      goto LABEL_7;
    *(_QWORD *)(v13 + 128) = a5[1];
    *(_QWORD *)(v13 + 96) = a7[1];
    if ( a4 != 2 )
    {
      *(_QWORD *)(v13 + 136) = a5[2];
      *(_QWORD *)(v13 + 104) = a7[2];
      if ( a4 != 3 )
      {
        *(_QWORD *)(v13 + 144) = a5[3];
        *(_QWORD *)(v13 + 112) = a7[3];
      }
    }
LABEL_6:
    v14 = *(_QWORD *)(v13 + 96) >> dword_30520[v7];
LABEL_7:
    v15 = *(_DWORD *)(v13 + 80);
    *(_QWORD *)(v13 + 64) = v14;
    if ( v15 > 0 )
      goto LABEL_8;
LABEL_18:
    v18 = 1;
    goto LABEL_15;
  }
  if ( a4 )
    goto LABEL_6;
  v15 = *(_DWORD *)(v13 + 80);
  *(_QWORD *)(v13 + 64) = 1LL;
  if ( v15 <= 0 )
    goto LABEL_18;
LABEL_8:
  v16 = nc_type_size_table[*(unsigned int *)(v13 + 48)] == *(_QWORD *)(v13 + 88);
  v17 = v16;
  *(_BYTE *)(v13 + 73) = v16;
  v18 = v16;
  if ( v15 != 1 )
  {
    v19 = 1;
    if ( v15 > 3 )
    {
      v20 = *(_QWORD *)(v13 + 96);
      v21 = *(_QWORD *)(v13 + 88) * *(_QWORD *)(v13 + 120) == v20;
      LOBYTE(v20) = *(_QWORD *)(v13 + 128) * v20 == *(_QWORD *)(v13 + 104);
      *(_BYTE *)(v13 + 74) = v21;
      v22 = v20 & (v21 && v16);
      *(_BYTE *)(v13 + 75) = v20;
      v19 = 3;
      v17 = v22;
    }
    v23 = *(_QWORD *)(v13 + 8LL * v19 + 80) * *(_QWORD *)(v13 + 8LL * v19 + 112) == *(_QWORD *)(v13 + 8LL * v19 + 88);
    *(_BYTE *)(v13 + v19 + 73) = v23;
    v24 = v17 && v23;
    v25 = v19 + 1;
    if ( v15 > v19 + 1 )
    {
      v26 = *(_QWORD *)(v13 + 8LL * v25 + 80) * *(_QWORD *)(v13 + 8LL * v25 + 112) == *(_QWORD *)(v13 + 8LL * v25 + 88);
      v27 = v19 + 2;
      *(_BYTE *)(v13 + v25 + 73) = v26;
      v24 &= v26;
      if ( v15 > v27 )
      {
        v28 = *(_QWORD *)(v13 + 8LL * v27 + 80) * *(_QWORD *)(v13 + 8LL * v27 + 112) == *(_QWORD *)(v13 + 8LL * v27 + 88);
        *(_BYTE *)(v13 + v27 + 73) = v28;
        v24 &= v28;
      }
    }
    v18 = v24;
  }
LABEL_15:
  *(_BYTE *)(v13 + 72) = v18;
  *(_QWORD *)(v13 + 56) = *(_QWORD *)(a2 + 40) + a6;
  v29 = *(_QWORD *)(a1 + 16);
  *(_QWORD *)(v29 + 8) = v13;
  *(_QWORD *)v13 = v29;
  *(_QWORD *)(v13 + 8) = a1 + 16;
  result = v13;
  *(_QWORD *)(a1 + 16) = v13;
  return result;
}

