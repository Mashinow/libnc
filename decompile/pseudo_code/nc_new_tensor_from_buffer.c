// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_new_tensor_from_buffer
// Included functions: 1

// ======================================================
// Function: nc_new_tensor_from_buffer @ 0x66A14490
// ======================================================

_QWORD *__fastcall nc_new_tensor_from_buffer(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        __int64 *a5,
        __int64 a6,
        __int64 *a7)
{
  _QWORD *v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rax
  unsigned __int64 v14; // r10
  bool v15; // r8
  bool v16; // cl
  bool v17; // al
  bool v18; // cl
  bool v19; // al
  int v20; // r8d
  bool v21; // al
  char v22; // al
  int v23; // ecx
  bool v24; // r9
  int v25; // r8d
  bool v26; // cl
  __int64 v27; // rax
  _QWORD *result; // rax

  v11 = aligned_malloc(0x98ui64, 0x40ui64);
  if ( !v11 )
  {
    MEMORY[0x18] = a1;
    BUG();
  }
  memset(v11, 0, 0x98ui64);
  v11[3] = a1;
  *((_DWORD *)v11 + 4) = 1;
  *((_DWORD *)v11 + 12) = a3;
  *((_DWORD *)v11 + 20) = a4;
  ++*(_DWORD *)(a2 + 16);
  v11[5] = a2;
  if ( a4 <= 0 )
  {
    if ( a4 )
      v11[8] = v11[12] >> dword_66A375E0[a3];
    else
      v11[8] = 1i64;
    v22 = 1;
  }
  else
  {
    v12 = *a5;
    v11[15] = *a5;
    v13 = *a7;
    v11[11] = *a7;
    if ( a4 == 1 )
    {
      v11[8] = v12;
      v22 = v13 == nc_type_size_table[a3];
      *((_BYTE *)v11 + 73) = v22;
    }
    else
    {
      v11[16] = a5[1];
      v11[12] = a7[1];
      if ( a4 != 2 )
      {
        v11[17] = a5[2];
        v11[13] = a7[2];
        if ( a4 != 3 )
        {
          v11[18] = a5[3];
          v11[14] = a7[3];
        }
      }
      v14 = v11[12];
      v11[8] = v14 >> dword_66A375E0[a3];
      v15 = v11[11] == nc_type_size_table[a3];
      v16 = v15;
      *((_BYTE *)v11 + 73) = v15;
      if ( a4 <= 3 )
      {
        v20 = 1;
      }
      else
      {
        v17 = v11[11] * v11[15] == v14;
        v18 = v11[16] * v14 == v11[13];
        *((_BYTE *)v11 + 74) = v17;
        v19 = v15 && v17;
        v20 = 3;
        *((_BYTE *)v11 + 75) = v18;
        v16 = v18 && v19;
      }
      v21 = v11[v20 + 10] * v11[v20 + 14] == v11[v20 + 11];
      *((_BYTE *)v11 + v20 + 73) = v21;
      v22 = v16 && v21;
      v23 = v20 + 1;
      if ( a4 > v20 + 1 )
      {
        v24 = v11[v23 + 10] * v11[v23 + 14] == v11[v23 + 11];
        v25 = v20 + 2;
        *((_BYTE *)v11 + v23 + 73) = v24;
        v22 &= v24;
        if ( a4 > v25 )
        {
          v26 = v11[v25 + 10] * v11[v25 + 14] == v11[v25 + 11];
          *((_BYTE *)v11 + v25 + 73) = v26;
          v22 &= v26;
        }
      }
    }
  }
  *((_BYTE *)v11 + 72) = v22;
  v11[7] = *(_QWORD *)(a2 + 40) + a6;
  v27 = *(_QWORD *)(a1 + 16);
  *(_QWORD *)(v27 + 8) = v11;
  *v11 = v27;
  v11[1] = a1 + 16;
  result = v11;
  *(_QWORD *)(a1 + 16) = v11;
  return result;
}

