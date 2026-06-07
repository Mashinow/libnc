// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_save_coefs_0
// Included functions: 1

// ======================================================
// Function: nc_save_coefs_0 @ 0xF010
// ======================================================

int __fastcall nc_save_coefs_0(__int64 a1, const char *a2)
{
  const char *v2; // rdi
  __int64 v3; // r15
  unsigned __int64 v4; // rax
  int v5; // esi
  __int64 v6; // rbp
  int v7; // ebx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 *v10; // r14
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  FILE *s; // [rsp+0h] [rbp-A8h]
  __int64 i; // [rsp+8h] [rbp-A0h]
  int v19[2]; // [rsp+30h] [rbp-78h] BYREF
  unsigned int v20; // [rsp+38h] [rbp-70h]
  unsigned int n; // [rsp+3Ch] [rbp-6Ch]
  _DWORD n_4[4]; // [rsp+40h] [rbp-68h] BYREF
  __int64 v23[11]; // [rsp+50h] [rbp-58h] BYREF

  s = fopen(a2, "wb");
  if ( !s )
  {
    perror(a2);
    exit(1);
  }
  for ( i = *(_QWORD *)(a1 + 8); i != a1; i = *(_QWORD *)(i + 8) )
  {
    v2 = *(const char **)(i + 24);
    v3 = **(_QWORD **)(i + 16);
    v19[0] = 603238138;
    v19[1] = 0;
    v20 = *(_DWORD *)(v3 + 80);
    n = strlen(v2);
    fwrite(v19, 1uLL, 0x10uLL, s);
    v4 = *(int *)(v3 + 80);
    if ( (_DWORD)v4 )
    {
      n_4[0] = *(_QWORD *)(v3 + 120);
      if ( v4 > 1 )
      {
        n_4[1] = *(_QWORD *)(v3 + 128);
        if ( v4 != 2 )
        {
          n_4[2] = *(_QWORD *)(v3 + 136);
          if ( v4 != 3 )
            n_4[3] = *(_QWORD *)(v3 + 144);
        }
      }
    }
    fwrite(n_4, 1uLL, 4LL * v20, s);
    fwrite(*(const void **)(i + 24), 1uLL, n, s);
    v5 = *(_DWORD *)(v3 + 80);
    if ( v5 <= 0 )
    {
      v23[0] = 0LL;
      v9 = 0LL;
      v7 = 0;
      v6 = 1LL;
    }
    else
    {
      if ( *(_BYTE *)(v3 + 73) )
      {
        v6 = *(_QWORD *)(v3 + 120);
        if ( v5 == 1 )
        {
          v6 = (int)v6;
          v7 = 1;
          v9 = 0LL;
          v23[0] = 0LL;
          goto LABEL_21;
        }
        if ( *(_BYTE *)(v3 + 74) )
        {
          v6 *= *(_QWORD *)(v3 + 128);
          if ( v5 == 2 )
          {
            v7 = 2;
            goto LABEL_17;
          }
          if ( *(_BYTE *)(v3 + 75) )
          {
            v6 *= *(_QWORD *)(v3 + 136);
            if ( v5 == 3 )
            {
              v7 = 3;
              goto LABEL_17;
            }
            if ( *(_BYTE *)(v3 + 76) )
            {
              v6 *= *(_QWORD *)(v3 + 144);
              v7 = 4;
LABEL_17:
              v23[0] = 0LL;
              v6 = (int)v6;
LABEL_18:
              v8 = 1LL;
              do
                v23[v8++] = 0LL;
              while ( v5 > (int)v8 );
              v9 = v23[0];
              goto LABEL_21;
            }
            v6 = (int)v6;
            v7 = 3;
          }
          else
          {
            v6 = (int)v6;
            v7 = 2;
          }
        }
        else
        {
          v6 = (int)v6;
          v7 = 1;
        }
      }
      else
      {
        v6 = 1LL;
        v7 = 0;
      }
      v23[0] = 0LL;
      if ( v5 > 1 )
        goto LABEL_18;
      v9 = 0LL;
    }
LABEL_21:
    v10 = &v23[v7];
    while ( v9 != -1 )
    {
      if ( v5 <= 0 )
        goto LABEL_28;
      v11 = *(_QWORD *)(v3 + 88) * v9;
      if ( v5 != 1 )
      {
        v11 += *(_QWORD *)(v3 + 96) * v23[1];
        if ( v5 != 2 )
        {
          v11 += *(_QWORD *)(v3 + 104) * v23[2];
          if ( v5 != 3 )
          {
            if ( v5 != 4 )
            {
LABEL_28:
              v11 = 0LL;
              goto LABEL_29;
            }
            v11 += *(_QWORD *)(v3 + 112) * v23[3];
          }
        }
      }
LABEL_29:
      fwrite((const void *)(v11 + *(_QWORD *)(v3 + 56)), 1uLL, nc_type_size_table[*(unsigned int *)(v3 + 48)] * v6, s);
      v5 = *(_DWORD *)(v3 + 80);
      if ( v7 >= v5 )
        goto LABEL_34;
      v12 = *v10 + 1;
      *v10 = v12;
      if ( *(_QWORD *)(v3 + 8 * (v7 + 12LL) + 24) == v12 )
      {
        v13 = 0LL;
        while ( 1 )
        {
          v10[v13] = 0LL;
          if ( v5 - 1 - v7 == v13 )
            break;
          v14 = v10[v13 + 1] + 1;
          v10[++v13] = v14;
          if ( v14 != *(_QWORD *)(v3 + 8LL * (unsigned int)(v7 + 1) + 8 * v13 + 112) )
            goto LABEL_37;
        }
LABEL_34:
        v23[0] = -1LL;
        break;
      }
LABEL_37:
      v9 = v23[0];
    }
  }
  return fclose(s);
}

