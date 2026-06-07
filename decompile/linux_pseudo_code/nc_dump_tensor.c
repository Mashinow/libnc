// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_dump_tensor
// Included functions: 1

// ======================================================
// Function: nc_dump_tensor @ 0x182D0
// ======================================================

int __fastcall nc_dump_tensor(__int64 a1, __int64 a2, __int64 a3, __m128 _XMM0)
{
  __int64 v5; // r13
  int v6; // edx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 i; // rbp
  __int64 v10; // rbp
  __int64 v11; // rbp
  int v12; // r12d
  int v13; // eax
  __int64 v14; // rdx
  int v15; // ecx
  __int64 v16; // rdx
  int v26; // [rsp+4h] [rbp-74h]
  unsigned int v27[4]; // [rsp+10h] [rbp-68h] BYREF
  __int64 v28; // [rsp+20h] [rbp-58h] BYREF
  __int64 v29; // [rsp+28h] [rbp-50h]
  __int64 v30; // [rsp+30h] [rbp-48h]
  __int64 v31; // [rsp+38h] [rbp-40h]

  v5 = *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL);
  nc_dump_dims(a1, a2);
  if ( a3 )
  {
    if ( !*(_DWORD *)(a2 + 80) )
    {
      printf("= ");
      v10 = *(unsigned int *)(a2 + 48);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(v5 + 96))(
        v5,
        &v28,
        *(_QWORD *)(a2 + 56),
        nc_type_size_table[v10]);
      switch ( (int)v10 )
      {
        case 0:
          __asm
          {
            vxorpd  xmm0, xmm0, xmm0; jumptable 0000000000018444 case 0
            vcvtss2sd xmm0, xmm0, dword ptr [rsp+78h+var_58]
          }
          printf("%8.3g", *(double *)&_XMM0);
          goto LABEL_14;
        case 1:
          _EAX = (unsigned __int16)v28 << 16;
          __asm
          {
            vmovd   xmm0, eax
            vcvtss2sd xmm0, xmm0, xmm0
          }
          printf("%8.3g", *(double *)&_XMM0);
          goto LABEL_14;
        case 3:
          printf("%8d", (unsigned int)(char)v28);
          goto LABEL_14;
        case 4:
          printf("%8d", (unsigned int)(__int16)v28);
          goto LABEL_14;
        case 5:
          printf("%8d", (unsigned int)v28);
          goto LABEL_14;
        default:
          goto LABEL_27;
      }
    }
    puts("=");
    v6 = *(_DWORD *)(a2 + 80);
    v28 = 0LL;
    if ( v6 <= 1 )
    {
      v8 = 0LL;
    }
    else
    {
      v7 = 1LL;
      do
        *(&v28 + v7++) = 0LL;
      while ( v6 > (int)v7 );
      v8 = v28;
    }
    while ( 1 )
    {
      if ( v8 == -1 )
        return v8;
      if ( *(int *)(a2 + 80) <= 1 )
      {
        if ( !*(_QWORD *)(a2 + 120) )
          return v8;
      }
      else
      {
        printf("  [");
        if ( *(int *)(a2 + 80) > 1 )
        {
          for ( i = 2LL; ; ++i )
          {
            printf("%d", *((unsigned int *)&v28 + 2 * i - 2));
            if ( *(_DWORD *)(a2 + 80) <= (int)i )
              break;
            printf(", ");
          }
        }
        LODWORD(v8) = puts("] =");
        if ( !*(_QWORD *)(a2 + 120) )
          goto LABEL_35;
      }
      v11 = 0LL;
      v12 = 0;
      while ( 2 )
      {
        v28 = v11;
        if ( v12 )
          printf(", ");
        else
          printf("  ");
        if ( !a3 )
        {
          LODWORD(v8) = puts("...");
          return v8;
        }
        a3 -= a3 != -1;
        v13 = *(_DWORD *)(a2 + 80);
        if ( v13 <= 0 )
        {
          v14 = 0LL;
        }
        else
        {
          v14 = *(_QWORD *)(a2 + 88) * v11;
          if ( v13 != 1 )
          {
            v14 += *(_QWORD *)(a2 + 96) * v29;
            if ( v13 != 2 )
            {
              v14 += *(_QWORD *)(a2 + 104) * v30;
              if ( v13 != 3 )
              {
                if ( v13 != 4 )
LABEL_27:
                  abort();
                v14 += *(_QWORD *)(a2 + 112) * v31;
              }
            }
          }
        }
        v26 = *(_DWORD *)(a2 + 48);
        (*(void (__fastcall **)(__int64, unsigned int *, __int64, _QWORD))(v5 + 96))(
          v5,
          v27,
          *(_QWORD *)(a2 + 56) + v14,
          nc_type_size_table[v26]);
        switch ( v26 )
        {
          case 0:
            __asm
            {
              vxorpd  xmm0, xmm0, xmm0; jumptable 000000000001853B case 0
              vcvtss2sd xmm0, xmm0, [rsp+78h+var_68]
            }
            LODWORD(v8) = printf("%8.3g", *(double *)_XMM0.m128_u64);
            goto LABEL_31;
          case 1:
            _EAX = LOWORD(v27[0]) << 16;
            __asm
            {
              vmovd   xmm0, eax
              vcvtss2sd xmm0, xmm0, xmm0
            }
            LODWORD(v8) = printf("%8.3g", *(double *)_XMM0.m128_u64);
            goto LABEL_31;
          case 3:
            LODWORD(v8) = printf("%8d", (unsigned int)SLOBYTE(v27[0]));
            goto LABEL_31;
          case 4:
            ++v12;
            LODWORD(v8) = printf("%8d", (unsigned int)SLOWORD(v27[0]));
            if ( v12 == 8 )
              goto LABEL_41;
            goto LABEL_32;
          case 5:
            LODWORD(v8) = printf("%8d", v27[0]);
LABEL_31:
            if ( ++v12 == 8 )
            {
LABEL_41:
              v12 = 0;
              LODWORD(v8) = putchar(10);
            }
LABEL_32:
            if ( *(_QWORD *)(a2 + 120) > (unsigned __int64)++v11 )
              continue;
            if ( v12 )
              LODWORD(v8) = putchar(10);
            break;
          default:
            goto LABEL_27;
        }
        break;
      }
LABEL_35:
      v15 = *(_DWORD *)(a2 + 80);
      if ( v15 <= 1 )
        return v8;
      v8 = 2LL;
      if ( *(_QWORD *)(a2 + 128) == ++v29 )
      {
        do
        {
          *(&v28 + v8 - 1) = 0LL;
          if ( v15 <= (int)v8 )
            return v8;
          v16 = *(&v28 + v8) + 1;
          *(&v28 + v8++) = v16;
        }
        while ( v16 == *(_QWORD *)(a2 + 8 * v8 + 112) );
      }
      v8 = v28;
    }
  }
LABEL_14:
  LODWORD(v8) = putchar(10);
  return v8;
}

