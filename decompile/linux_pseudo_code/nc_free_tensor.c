// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_free_tensor
// Included functions: 1

// ======================================================
// Function: nc_free_tensor @ 0x16EB0
// ======================================================

void __fastcall nc_free_tensor(_DWORD *ptr)
{
  int v1; // eax
  int v3; // eax
  __int64 v4; // rdi
  __int64 v5; // rdx
  _QWORD *v6; // rax
  void *v7; // rdi
  _QWORD *v8; // rax

  if ( ptr )
  {
    v1 = ptr[4];
    if ( v1 <= 0 )
      __assert_fail("x->ref_count >= 1", "libnc.c", 0xF52u, "nc_free_tensor");
    v3 = v1 - 1;
    ptr[4] = v3;
    if ( v3 == 1 )
    {
      v4 = *((_QWORD *)ptr + 4);
      if ( v4 )
      {
        if ( *(_DWORD *)(v4 + 16) == 1 && *(int *)(v4 + 40) > 0 )
        {
          v8 = *(_QWORD **)(v4 + 48);
          if ( ptr == (_DWORD *)*v8 )
          {
            *v8 = 0LL;
            ptr[4] = 0;
            goto LABEL_6;
          }
        }
      }
    }
    else if ( !v3 )
    {
      v4 = *((_QWORD *)ptr + 4);
      if ( !v4 )
      {
LABEL_7:
        v5 = *(_QWORD *)ptr;
        v6 = (_QWORD *)*((_QWORD *)ptr + 1);
        v7 = (void *)*((_QWORD *)ptr + 5);
        *(_QWORD *)(v5 + 8) = v6;
        *v6 = v5;
        *(_QWORD *)ptr = 0LL;
        *((_QWORD *)ptr + 1) = 0LL;
        nc_free_tensor_buffer(v7);
        nc_free(ptr);
        return;
      }
LABEL_6:
      nc_free_node((void *)v4);
      goto LABEL_7;
    }
  }
}

