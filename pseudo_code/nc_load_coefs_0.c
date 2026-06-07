// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_load_coefs_0
// Included functions: 1

// ======================================================
// Function: nc_load_coefs_0 @ 0x66A0CE30
// ======================================================

int __fastcall nc_load_coefs_0(__int64 a1, const char *a2)
{
  unsigned int v3; // ebx
  unsigned int v4; // ebx
  unsigned int v5; // esi
  __int64 v6; // rbx
  int v7; // r12d
  __int64 *v8; // rax
  unsigned int v9; // esi
  __int64 v10; // r15
  unsigned int v11; // ebx
  int v12; // edx
  __int64 v13; // rdi
  unsigned int v14; // ebx
  __int64 v15; // rsi
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 *v18; // rbx
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rcx
  FILE *v23; // rax
  FILE *v25; // rax
  FILE *v26; // rax
  FILE *v27; // rax
  FILE *v28; // rax
  FILE *v29; // rax
  FILE *Stream; // [rsp+30h] [rbp-4A8h]
  unsigned int v31; // [rsp+50h] [rbp-488h] BYREF
  unsigned int v32; // [rsp+54h] [rbp-484h]
  unsigned int v33; // [rsp+58h] [rbp-480h]
  unsigned int ElementCount; // [rsp+5Ch] [rbp-47Ch]
  unsigned int ElementCount_4; // [rsp+60h] [rbp-478h] BYREF
  unsigned int v36; // [rsp+64h] [rbp-474h]
  unsigned int v37; // [rsp+68h] [rbp-470h]
  unsigned int v38; // [rsp+6Ch] [rbp-46Ch]
  __int64 v39[4]; // [rsp+70h] [rbp-468h] BYREF
  char v40[1096]; // [rsp+90h] [rbp-448h] BYREF

  Stream = fopen(a2, "rb");
  if ( !Stream )
  {
    perror(a2);
    exit(1);
  }
LABEL_2:
  if ( fread(&v31, 1ui64, 0x10ui64, Stream) == 16 )
  {
    v3 = v31;
    if ( v31 != 603238138 )
    {
      v29 = __iob_func();
      fprintf(v29 + 2, "Invalid magic 0x%08x\n", v3);
      exit(1);
    }
    v4 = v33;
    if ( v33 > 4 )
      goto LABEL_71;
    v5 = ElementCount;
    if ( ElementCount > 0x3FF )
    {
      v27 = __iob_func();
      fprintf(v27 + 2, "name too long (%d)\n", v5);
      exit(1);
    }
    fread(&ElementCount_4, 1ui64, 4i64 * v33, Stream);
    fread(v40, 1ui64, ElementCount, Stream);
    v40[ElementCount] = 0;
    v6 = *(_QWORD *)(a1 + 8);
    if ( v6 == a1 )
    {
LABEL_52:
      v23 = __iob_func();
      fprintf(v23 + 2, "Could not find variable '%s'\n", v40);
      exit(1);
    }
    while ( strcmp(*(const char **)(v6 + 24), v40) )
    {
      v6 = *(_QWORD *)(v6 + 8);
      if ( v6 == a1 )
        goto LABEL_52;
    }
    v7 = 0;
    v8 = *(__int64 **)(v6 + 16);
    v9 = v32;
    v10 = *v8;
    v11 = *(_DWORD *)(*v8 + 48);
    if ( v11 != v32 )
    {
      v26 = __iob_func();
      fprintf(v26 + 2, "Unexpected type: %d (%d)\n", v9, v11);
      exit(1);
    }
    v12 = *(_DWORD *)(v10 + 80);
    v4 = v33;
    if ( v12 != v33 )
    {
LABEL_71:
      v28 = __iob_func();
      fprintf(v28 + 2, "Invalid number of dimensions (%d)\n", v4);
      exit(1);
    }
    if ( v12 )
    {
      v13 = *(_QWORD *)(v10 + 120);
      v14 = ElementCount_4;
      if ( v13 != ElementCount_4 )
      {
        v15 = *(_QWORD *)(v10 + 120);
        goto LABEL_66;
      }
      if ( (unsigned __int64)v12 <= 1 )
      {
        if ( v12 <= 0 )
        {
          v39[0] = 0i64;
          v17 = 0i64;
          v13 = 1i64;
          goto LABEL_31;
        }
        if ( !*(_BYTE *)(v10 + 73) )
          goto LABEL_61;
      }
      else
      {
        v15 = *(_QWORD *)(v10 + 128);
        v14 = v36;
        if ( v15 != v36 )
          goto LABEL_66;
        if ( v12 != 2i64 )
        {
          v15 = *(_QWORD *)(v10 + 136);
          v14 = v37;
          if ( v15 == v37 )
          {
            if ( v12 == 3i64 || (v15 = *(_QWORD *)(v10 + 144), v14 = v38, v15 == v38) )
            {
              if ( *(_BYTE *)(v10 + 73) )
                goto LABEL_21;
LABEL_61:
              v13 = 1i64;
              goto LABEL_55;
            }
          }
LABEL_66:
          v25 = __iob_func();
          fprintf(v25 + 2, "%s: invalid dimension size (%d %d)\n", v40, v14, v15);
          exit(1);
        }
        if ( !*(_BYTE *)(v10 + 73) )
        {
          v39[0] = 0i64;
          v13 = 1i64;
          goto LABEL_28;
        }
      }
      if ( v12 != 1 )
      {
LABEL_21:
        if ( *(_BYTE *)(v10 + 74) )
        {
          v13 *= *(_QWORD *)(v10 + 128);
          if ( v12 == 2 )
          {
            v7 = 2;
            goto LABEL_27;
          }
          if ( *(_BYTE *)(v10 + 75) )
          {
            v13 *= *(_QWORD *)(v10 + 136);
            if ( v12 == 3 )
            {
              v7 = 3;
              goto LABEL_27;
            }
            if ( *(_BYTE *)(v10 + 76) )
            {
              v13 *= *(_QWORD *)(v10 + 144);
              v7 = 4;
LABEL_27:
              v39[0] = 0i64;
              v13 = (int)v13;
              goto LABEL_28;
            }
            v13 = (int)v13;
            v7 = 3;
          }
          else
          {
            v13 = (int)v13;
            v7 = 2;
          }
        }
        else
        {
          v13 = (int)v13;
          v7 = 1;
        }
LABEL_55:
        v39[0] = 0i64;
        if ( v12 <= 1 )
        {
          v17 = 0i64;
          goto LABEL_31;
        }
LABEL_28:
        v16 = 1i64;
        do
          v39[v16++] = 0i64;
        while ( v12 > (int)v16 );
        v17 = v39[0];
        goto LABEL_31;
      }
      v13 = (int)v13;
    }
    else
    {
      v13 = 1i64;
    }
    v39[0] = 0i64;
    v7 = v12;
    v17 = 0i64;
LABEL_31:
    v18 = &v39[v7];
    while ( 1 )
    {
      if ( v17 == -1 )
        goto LABEL_2;
      if ( v12 <= 0 )
        break;
      v19 = *(_QWORD *)(v10 + 88) * v17;
      if ( v12 != 1 )
      {
        v19 += *(_QWORD *)(v10 + 96) * v39[1];
        if ( v12 != 2 )
        {
          v19 += *(_QWORD *)(v10 + 104) * v39[2];
          if ( v12 != 3 )
          {
            if ( v12 != 4 )
              break;
            v19 += *(_QWORD *)(v10 + 112) * v39[3];
          }
        }
      }
LABEL_39:
      fread((void *)(v19 + *(_QWORD *)(v10 + 56)), 1ui64, nc_type_size_table[*(unsigned int *)(v10 + 48)] * v13, Stream);
      v12 = *(_DWORD *)(v10 + 80);
      if ( v7 >= v12 )
        goto LABEL_44;
      v20 = *v18 + 1;
      *v18 = v20;
      if ( *(_QWORD *)(v10 + 8 * (v7 + 12i64) + 24) == v20 )
      {
        v21 = 0i64;
        while ( 1 )
        {
          v18[v21] = 0i64;
          if ( v21 == v12 - 1 - v7 )
            break;
          v22 = v18[v21 + 1] + 1;
          v18[++v21] = v22;
          if ( v22 != *(_QWORD *)(v10 + 8i64 * (unsigned int)(v7 + 1) + 8 * v21 + 112) )
            goto LABEL_45;
        }
LABEL_44:
        v39[0] = -1i64;
        goto LABEL_2;
      }
LABEL_45:
      v17 = v39[0];
    }
    v19 = 0i64;
    goto LABEL_39;
  }
  return fclose(Stream);
}

