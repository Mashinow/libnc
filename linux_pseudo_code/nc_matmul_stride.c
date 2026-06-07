// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_matmul_stride
// Included functions: 2

// ======================================================
// Function: nc_matmul_stride @ 0x225C0
// ======================================================

__int64 __fastcall nc_matmul_stride(_QWORD *ptr, _QWORD *a2)
{
  __int64 v2; // r13
  __int64 v3; // r12
  int v4; // eax
  __int64 v5; // rax
  __int64 v6; // r13
  __int64 v7; // r14
  int max_threads; // eax
  __int64 v10[4]; // [rsp+0h] [rbp-68h] BYREF
  int v11; // [rsp+20h] [rbp-48h] BYREF
  _QWORD *v12; // [rsp+28h] [rbp-40h]
  __int64 v13; // [rsp+30h] [rbp-38h]
  _QWORD *v14; // [rsp+38h] [rbp-30h]

  v2 = *(_QWORD *)(ptr[5] + 24LL);
  if ( !*(_DWORD *)(v2 + 32) )
    __assert_fail("d->is_host", "libnc.c", 0x1A1Bu, "nc_matmul_stride");
  v3 = **(_QWORD **)(v2 + 24);
  if ( v2 != *(_QWORD *)(a2[5] + 24LL) )
    nc_error("all operation tensors must be on the same device", (char)a2);
  if ( (ptr[6] & 0xFFFFFFFD) != 0 )
    __assert_fail("w->item_type == NC_TYPE_F32 || w->item_type == NC_TYPE_F16", "libnc.c", 0x1A21u, "nc_matmul_stride");
  if ( *((_DWORD *)a2 + 12) )
    __assert_fail("x->item_type == NC_TYPE_F32", "libnc.c", 0x1A22u, "nc_matmul_stride");
  if ( *((_DWORD *)ptr + 20) != 3 )
    __assert_fail("w->n_dims == 3", "libnc.c", 0x1A23u, "nc_matmul_stride");
  if ( *((_DWORD *)a2 + 20) != 2 )
    __assert_fail("x->n_dims == 2", "libnc.c", 0x1A24u, "nc_matmul_stride");
  v4 = *((_DWORD *)ptr + 30) * ptr[17];
  if ( *((_DWORD *)ptr + 32) != a2[15] )
    __assert_fail("k == x->dims[0]", "libnc.c", 0x1A28u, "nc_matmul_stride");
  v10[1] = (int)a2[16];
  v10[0] = v4;
  v5 = nc_new_tensor(v2, 0LL, 2LL, v10);
  v6 = ptr[17];
  v7 = v5;
  max_threads = nc_job_get_max_threads(v3);
  v12 = ptr;
  if ( (int)v6 <= max_threads )
    max_threads = v6;
  v13 = v7;
  v14 = a2;
  v11 = max_threads;
  nc_job_exec(v3, sub_14890, &v11, (unsigned int)max_threads);
  nc_free_tensor(ptr);
  nc_free_tensor(a2);
  return v7;
}

// ======================================================
// Function: sub_14890 @ 0x14890
// ======================================================

unsigned __int64 __fastcall sub_14890(_QWORD *a1, __int64 a2, int a3)
{
  __int64 v3; // rbx
  unsigned __int64 v4; // r9
  __int64 v5; // r12
  _QWORD *v6; // r13
  __int64 v7; // rcx
  __int64 v8; // r8
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rdi
  unsigned __int64 result; // rax
  int v13; // edx
  int v14; // r14d
  int v15; // r15d
  __int64 v16; // rbp
  __int64 v17; // [rsp+8h] [rbp-50h]
  __int64 v18; // [rsp+18h] [rbp-40h]

  v3 = a1[1];
  v4 = *(int *)a1;
  v5 = a1[2];
  v6 = (_QWORD *)a1[3];
  v7 = *(_QWORD *)(v3 + 136);
  v8 = *(_QWORD *)(v3 + 120);
  v9 = v7 * a3;
  v10 = v9 + v7;
  v11 = v9 / v4;
  result = v10 / v4;
  if ( (int)(v9 / v4) < (int)(v10 / v4) )
  {
    v13 = v9 / v4;
    v14 = *(_QWORD *)(v3 + 120);
    v15 = v11 * v8;
    v16 = (int)v11 + 1LL;
    v17 = (unsigned int)(result - 1 - v11) + v16;
    v18 = (int)v8;
    while ( 1 )
    {
      if ( *(_DWORD *)(v3 + 48) == 2 )
      {
        result = mat_mul_f16(
                   *(_DWORD *)(v5 + 56) + 4 * v15,
                   *(_QWORD *)(v5 + 64),
                   *(_DWORD *)(v3 + 56) + *(_DWORD *)(v3 + 104) * v13,
                   *(_QWORD *)(v3 + 64),
                   v6[7],
                   v6[8],
                   v18,
                   *(_QWORD *)(v5 + 128),
                   v6[15]);
        v15 += v14;
        v13 = v16;
        if ( v17 == v16 )
          return result;
      }
      else
      {
        result = mat_mul(
                   0,
                   *(_DWORD *)(v5 + 56) + 4 * v15,
                   *(_QWORD *)(v5 + 64),
                   *(_DWORD *)(v3 + 56) + *(_DWORD *)(v3 + 104) * v13,
                   *(_QWORD *)(v3 + 64),
                   v6[7],
                   v6[8],
                   0,
                   0,
                   v14,
                   *(_QWORD *)(v5 + 128),
                   v6[15]);
        v15 += v14;
        v13 = v16;
        if ( v17 == v16 )
          return result;
      }
      ++v16;
    }
  }
  return result;
}

