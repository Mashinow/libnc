// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_free_tensor_buffer
// Included functions: 1

// ======================================================
// Function: nc_free_tensor_buffer @ 0x16440
// ======================================================

void __fastcall nc_free_tensor_buffer(_DWORD *ptr)
{
  int v1; // eax
  int v2; // eax
  __int64 v3; // rcx
  _QWORD *v4; // rdx
  __int64 v5; // rax
  __int64 v6; // rsi

  if ( ptr )
  {
    v1 = ptr[4];
    if ( v1 <= 0 )
      __assert_fail("b->ref_count >= 1", "libnc.c", 0xF09u, "nc_free_tensor_buffer");
    v2 = v1 - 1;
    ptr[4] = v2;
    if ( !v2 )
    {
      v3 = *(_QWORD *)ptr;
      v4 = (_QWORD *)*((_QWORD *)ptr + 1);
      v5 = *((_QWORD *)ptr + 3);
      v6 = *((_QWORD *)ptr + 4);
      *(_QWORD *)(v3 + 8) = v4;
      *v4 = v3;
      *(_QWORD *)ptr = 0LL;
      *((_QWORD *)ptr + 1) = 0LL;
      (*(void (__fastcall **)(__int64, __int64))(v5 + 56))(v5, v6);
      nc_free(ptr);
    }
  }
}

