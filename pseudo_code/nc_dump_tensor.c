// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_dump_tensor
// Included functions: 1

// ======================================================
// Function: nc_dump_tensor @ 0x66A16990
// ======================================================

int __fastcall nc_dump_tensor(const char *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // r12
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 i; // rdi
  __int64 v14; // rdi
  __int64 v15; // rdi
  int v16; // ebp
  int v17; // edx
  __int64 v18; // rax
  __int64 v19; // r14
  int v20; // ecx
  __int64 v21; // rdx
  unsigned int v39[4]; // [rsp+30h] [rbp-78h] BYREF
  __int64 v40; // [rsp+40h] [rbp-68h] BYREF
  __int64 v41; // [rsp+48h] [rbp-60h]
  __int64 v42; // [rsp+50h] [rbp-58h]
  __int64 v43; // [rsp+58h] [rbp-50h]

  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24i64);
  printf("%s %s", (const char *)*(&nc_type_name_table + *(unsigned int *)(a2 + 48)), a1);
  if ( *(int *)(a2 + 80) > 0 )
  {
    putchar(91);
    v7 = *(_DWORD *)(a2 + 80);
    if ( v7 > 0 )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = v7 - 1 - v8++;
        printf("%d", *(_QWORD *)(a2 + 8i64 * v9 + 120));
        if ( v8 >= *(_DWORD *)(a2 + 80) )
          break;
        printf(", ");
        v7 = *(_DWORD *)(a2 + 80);
      }
    }
    putchar(93);
  }
  if ( a3 )
  {
    if ( !*(_DWORD *)(a2 + 80) )
    {
      printf("= ");
      v14 = *(unsigned int *)(a2 + 48);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, __int64))(v4 + 96))(
        v4,
        &v40,
        *(_QWORD *)(a2 + 56),
        nc_type_size_table[v14]);
      switch ( (int)v14 )
      {
        case 0:
          __asm
          {
            vxorpd  xmm0, xmm0, xmm0; jumptable 0000000066A16B62 case 0
            vcvtss2sd xmm0, xmm0, dword ptr [rsp+0A8h+var_68]
            vmovapd xmm1, xmm0
            vmovq   rdx, xmm0
          }
          printf("%8.3g", *(double *)&_XMM1);
          goto LABEL_20;
        case 1:
          _EAX = (unsigned __int16)v40 << 16;
          __asm
          {
            vmovd   xmm0, eax
            vcvtss2sd xmm0, xmm0, xmm0
            vmovapd xmm1, xmm0
            vmovq   rdx, xmm0
          }
          printf("%8.3g", *(double *)&_XMM1);
          goto LABEL_20;
        case 3:
          printf("%8d", (unsigned int)(char)v40);
          goto LABEL_20;
        case 4:
          printf("%8d", (unsigned int)(__int16)v40);
          goto LABEL_20;
        case 5:
          printf("%8d", (unsigned int)v40);
          goto LABEL_20;
        default:
          goto LABEL_33;
      }
    }
    puts("=");
    v10 = *(_DWORD *)(a2 + 80);
    v40 = 0i64;
    if ( v10 <= 1 )
    {
      v12 = 0i64;
    }
    else
    {
      v11 = 1i64;
      do
        *(&v40 + v11++) = 0i64;
      while ( v10 > (int)v11 );
      v12 = v40;
    }
    while ( 1 )
    {
      if ( v12 == -1 )
        return v12;
      if ( *(int *)(a2 + 80) <= 1 )
      {
        if ( !*(_QWORD *)(a2 + 120) )
          return v12;
      }
      else
      {
        printf("  [");
        if ( *(int *)(a2 + 80) > 1 )
        {
          for ( i = 2i64; ; ++i )
          {
            printf("%d", *((unsigned int *)&v40 + 2 * i - 2));
            if ( *(_DWORD *)(a2 + 80) <= (int)i )
              break;
            printf(", ");
          }
        }
        LODWORD(v12) = puts("] =");
        if ( !*(_QWORD *)(a2 + 120) )
          goto LABEL_41;
      }
      v15 = 0i64;
      v16 = 0;
      while ( 2 )
      {
        v40 = v15;
        if ( v16 )
          printf(", ");
        else
          printf("  ");
        if ( !a3 )
        {
          LODWORD(v12) = puts("...");
          return v12;
        }
        v17 = *(_DWORD *)(a2 + 80);
        a3 -= a3 != -1;
        if ( v17 <= 0 )
        {
          v18 = 0i64;
        }
        else
        {
          v18 = *(_QWORD *)(a2 + 88) * v15;
          if ( v17 != 1 )
          {
            v18 += *(_QWORD *)(a2 + 96) * v41;
            if ( v17 != 2 )
            {
              v18 += *(_QWORD *)(a2 + 104) * v42;
              if ( v17 != 3 )
              {
                if ( v17 != 4 )
LABEL_33:
                  abort();
                v18 += *(_QWORD *)(a2 + 112) * v43;
              }
            }
          }
        }
        v19 = *(unsigned int *)(a2 + 48);
        (*(void (__fastcall **)(__int64, unsigned int *, __int64, __int64))(v4 + 96))(
          v4,
          v39,
          v18 + *(_QWORD *)(a2 + 56),
          nc_type_size_table[v19]);
        switch ( (int)v19 )
        {
          case 0:
            __asm
            {
              vxorpd  xmm0, xmm0, xmm0; jumptable 0000000066A16C34 case 0
              vcvtss2sd xmm0, xmm0, [rsp+0A8h+var_78]
              vmovapd xmm1, xmm0
              vmovq   rdx, xmm0
            }
            LODWORD(v12) = printf("%8.3g", *(double *)&_XMM1);
            goto LABEL_37;
          case 1:
            _EAX = LOWORD(v39[0]) << 16;
            __asm
            {
              vmovd   xmm0, eax
              vcvtss2sd xmm0, xmm0, xmm0
              vmovapd xmm1, xmm0
              vmovq   rdx, xmm0
            }
            LODWORD(v12) = printf("%8.3g", *(double *)&_XMM1);
            goto LABEL_37;
          case 3:
            LODWORD(v12) = printf("%8d", (unsigned int)SLOBYTE(v39[0]));
            goto LABEL_37;
          case 4:
            ++v16;
            LODWORD(v12) = printf("%8d", (unsigned int)SLOWORD(v39[0]));
            if ( v16 == 8 )
              goto LABEL_47;
            goto LABEL_38;
          case 5:
            LODWORD(v12) = printf("%8d", v39[0]);
LABEL_37:
            if ( ++v16 == 8 )
            {
LABEL_47:
              v16 = 0;
              LODWORD(v12) = putchar(10);
            }
LABEL_38:
            if ( *(_QWORD *)(a2 + 120) > (unsigned __int64)++v15 )
              continue;
            if ( v16 )
              LODWORD(v12) = putchar(10);
            break;
          default:
            goto LABEL_33;
        }
        break;
      }
LABEL_41:
      v20 = *(_DWORD *)(a2 + 80);
      if ( v20 <= 1 )
        return v12;
      v12 = 2i64;
      if ( *(_QWORD *)(a2 + 128) == ++v41 )
      {
        do
        {
          *(&v40 + v12 - 1) = 0i64;
          if ( v20 <= (int)v12 )
            return v12;
          v21 = *(&v40 + v12) + 1;
          *(&v40 + v12++) = v21;
        }
        while ( v21 == *(_QWORD *)(a2 + 8 * v12 + 112) );
      }
      v12 = v40;
    }
  }
LABEL_20:
  LODWORD(v12) = putchar(10);
  return v12;
}

