// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_split
// Included functions: 1

// ======================================================
// Function: nc_split @ 0x21260
// ======================================================

void __fastcall nc_split(_QWORD *a1, _DWORD *a2, int a3, _QWORD *a4, int a5)
{
  _QWORD *v8; // rbx
  _QWORD *v9; // r12
  __int64 v10; // r15
  __int64 v11; // rbp
  void *v12; // rax
  _QWORD *v13; // rbx
  __int64 v14; // r15
  __int64 v15; // r12
  void *v16; // rax
  __int64 v17; // [rsp+8h] [rbp-50h]
  __int64 v18; // [rsp+8h] [rbp-50h]
  __int64 v19; // [rsp+10h] [rbp-48h]

  if ( a5 < 0 || a5 >= a2[20] || !a4 && *(_QWORD *)&a2[2 * a5 + 30] % (unsigned __int64)a3 )
    goto LABEL_14;
  if ( a3 == 1 )
  {
    *a1 = a2;
  }
  else
  {
    if ( a3 <= 0 )
    {
      v11 = 0LL;
      v18 = a5;
    }
    else if ( a4 )
    {
      v8 = a4;
      v9 = a1;
      v10 = 0LL;
      v17 = (__int64)&a4[(unsigned int)(a3 - 1) + 1];
      do
      {
        v11 = *v8 + v10;
        ++v9;
        v12 = (void *)nc_dup_tensor(a2);
        ++v8;
        v10 = v11;
        *(v9 - 1) = nc_slice(v12);
      }
      while ( v8 != (_QWORD *)v17 );
      v18 = a5;
    }
    else
    {
      v13 = a1;
      v14 = 0LL;
      v19 = (__int64)&a1[(unsigned int)(a3 - 1) + 1];
      v18 = a5;
      v15 = a5 + 12LL;
      do
      {
        ++v13;
        v11 = *(_QWORD *)&a2[2 * v15 + 6] / (unsigned __int64)a3 + v14;
        v16 = (void *)nc_dup_tensor(a2);
        v14 = v11;
        *(v13 - 1) = nc_slice(v16);
      }
      while ( v13 != (_QWORD *)v19 );
    }
    if ( *(_QWORD *)&a2[2 * v18 + 30] != v11 )
    {
LABEL_14:
      puts("split: output sizes does not match input size");
      abort();
    }
    nc_free_tensor(a2);
  }
}

