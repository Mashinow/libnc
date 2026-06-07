// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_load_coefs_0
// Included functions: 1

// ======================================================
// Function: nc_load_coefs_0 @ 0x2DE00
// ======================================================

int __fastcall nc_load_coefs_0(__int64 a1, const char *a2)
{
  __int64 param; // rax
  __int64 *v3; // rax
  __int64 v4; // r13
  __int64 v5; // rcx
  int v6; // esi
  __int64 v7; // rbp
  __int64 v8; // rcx
  __int64 v9; // r8
  int v10; // ebx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 *v13; // r15
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rdx
  FILE *stream; // [rsp+0h] [rbp-4A8h]
  int v20; // [rsp+30h] [rbp-478h] BYREF
  unsigned int v21; // [rsp+34h] [rbp-474h]
  unsigned int v22; // [rsp+38h] [rbp-470h]
  unsigned int n; // [rsp+3Ch] [rbp-46Ch]
  unsigned int n_4; // [rsp+40h] [rbp-468h] BYREF
  unsigned int v25; // [rsp+44h] [rbp-464h]
  unsigned int v26; // [rsp+48h] [rbp-460h]
  unsigned int v27; // [rsp+4Ch] [rbp-45Ch]
  __int64 v28[4]; // [rsp+50h] [rbp-458h] BYREF
  char v29[1080]; // [rsp+70h] [rbp-438h] BYREF

  stream = fopen(a2, "rb");
  if ( !stream )
  {
    perror(a2);
    exit(1);
  }
LABEL_2:
  if ( fread(&v20, 1uLL, 0x10uLL, stream) == 16 )
  {
    if ( v20 == 603238138 )
    {
      if ( v22 <= 4 )
      {
        if ( n > 0x3FF )
        {
          fprintf(stderr, "name too long (%d)\n");
          goto LABEL_68;
        }
        fread(&n_4, 1uLL, 4LL * v22, stream);
        fread(v29, 1uLL, n, stream);
        v29[n] = 0;
        param = nc_find_param();
        if ( !param )
        {
          fprintf(stderr, "Could not find variable '%s'\n", v29);
          exit(1);
        }
        v3 = *(__int64 **)(param + 16);
        v4 = *v3;
        v5 = *(unsigned int *)(*v3 + 48);
        if ( (_DWORD)v5 != v21 )
        {
          fprintf(stderr, "Unexpected type: %d (%d)\n", v21, v5);
          exit(1);
        }
        v6 = *(_DWORD *)(v4 + 80);
        if ( v6 == v22 )
        {
          if ( v6 )
          {
            v7 = *(_QWORD *)(v4 + 120);
            v8 = n_4;
            if ( v7 != n_4 )
            {
              v9 = *(_QWORD *)(v4 + 120);
              goto LABEL_62;
            }
            if ( (unsigned __int64)v6 <= 1 )
            {
              if ( v6 <= 0 )
              {
                v28[0] = 0LL;
                v12 = 0LL;
                v10 = 0;
                v7 = 1LL;
                goto LABEL_28;
              }
              if ( !*(_BYTE *)(v4 + 73) )
                goto LABEL_57;
            }
            else
            {
              v9 = *(_QWORD *)(v4 + 128);
              v8 = v25;
              if ( v9 != v25 )
                goto LABEL_62;
              if ( v6 != 2LL )
              {
                v9 = *(_QWORD *)(v4 + 136);
                v8 = v26;
                if ( v9 == v26 )
                {
                  if ( v6 == 3LL || (v9 = *(_QWORD *)(v4 + 144), v8 = v27, v9 == v27) )
                  {
                    if ( *(_BYTE *)(v4 + 73) )
                      goto LABEL_18;
LABEL_57:
                    v7 = 1LL;
                    v10 = 0;
                    goto LABEL_51;
                  }
                }
LABEL_62:
                fprintf(stderr, "%s: invalid dimension size (%d %d)\n", v29, v8, v9);
                exit(1);
              }
              if ( !*(_BYTE *)(v4 + 73) )
              {
                v28[0] = 0LL;
                v10 = 0;
                v7 = 1LL;
                goto LABEL_25;
              }
            }
            if ( v6 != 1 )
            {
LABEL_18:
              if ( *(_BYTE *)(v4 + 74) )
              {
                v7 *= *(_QWORD *)(v4 + 128);
                if ( v6 == 2 )
                {
                  v10 = 2;
                  goto LABEL_24;
                }
                if ( *(_BYTE *)(v4 + 75) )
                {
                  v7 *= *(_QWORD *)(v4 + 136);
                  if ( v6 == 3 )
                  {
                    v10 = 3;
                    goto LABEL_24;
                  }
                  if ( *(_BYTE *)(v4 + 76) )
                  {
                    v7 *= *(_QWORD *)(v4 + 144);
                    v10 = 4;
LABEL_24:
                    v28[0] = 0LL;
                    v7 = (int)v7;
                    goto LABEL_25;
                  }
                  v7 = (int)v7;
                  v10 = 3;
                }
                else
                {
                  v7 = (int)v7;
                  v10 = 2;
                }
              }
              else
              {
                v7 = (int)v7;
                v10 = 1;
              }
LABEL_51:
              v28[0] = 0LL;
              if ( v6 <= 1 )
              {
                v12 = 0LL;
                goto LABEL_28;
              }
LABEL_25:
              v11 = 1LL;
              do
                v28[v11++] = 0LL;
              while ( v6 > (int)v11 );
              v12 = v28[0];
              goto LABEL_28;
            }
            v7 = (int)v7;
          }
          else
          {
            v7 = 1LL;
          }
          v28[0] = 0LL;
          v10 = v6;
          v12 = 0LL;
LABEL_28:
          v13 = &v28[v10];
          while ( 1 )
          {
            if ( v12 == -1 )
              goto LABEL_2;
            if ( v6 <= 0 )
              break;
            v14 = *(_QWORD *)(v4 + 88) * v12;
            if ( v6 != 1 )
            {
              v14 += *(_QWORD *)(v4 + 96) * v28[1];
              if ( v6 != 2 )
              {
                v14 += *(_QWORD *)(v4 + 104) * v28[2];
                if ( v6 != 3 )
                {
                  if ( v6 != 4 )
                    break;
                  v14 += *(_QWORD *)(v4 + 112) * v28[3];
                }
              }
            }
LABEL_36:
            fread(
              (void *)(v14 + *(_QWORD *)(v4 + 56)),
              1uLL,
              nc_type_size_table[*(unsigned int *)(v4 + 48)] * v7,
              stream);
            v6 = *(_DWORD *)(v4 + 80);
            if ( v10 >= v6 )
              goto LABEL_41;
            v15 = *v13 + 1;
            *v13 = v15;
            if ( *(_QWORD *)(v4 + 8 * (v10 + 12LL) + 24) == v15 )
            {
              v16 = 0LL;
              while ( 1 )
              {
                v13[v16] = 0LL;
                if ( v6 - 1 - v10 == v16 )
                  break;
                v17 = v13[v16 + 1] + 1;
                v13[++v16] = v17;
                if ( v17 != *(_QWORD *)(v4 + 8LL * (unsigned int)(v10 + 1) + 8 * v16 + 112) )
                  goto LABEL_42;
              }
LABEL_41:
              v28[0] = -1LL;
              goto LABEL_2;
            }
LABEL_42:
            v12 = v28[0];
          }
          v14 = 0LL;
          goto LABEL_36;
        }
      }
      fprintf(stderr, "Invalid number of dimensions (%d)\n");
    }
    else
    {
      fprintf(stderr, "Invalid magic 0x%08x\n");
    }
LABEL_68:
    exit(1);
  }
  return fclose(stream);
}

