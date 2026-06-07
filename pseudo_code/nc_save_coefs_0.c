// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_save_coefs_0
// Included functions: 1

// ======================================================
// Function: nc_save_coefs_0 @ 0x66A0CA60
// ======================================================

int __fastcall nc_save_coefs_0(__int64 a1, const char *a2)
{
  const char *v3; // rcx
  __int64 v4; // r12
  unsigned __int64 v5; // rax
  int v6; // edx
  __int64 v7; // rdi
  int v8; // esi
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 *v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rcx
  FILE *Stream; // [rsp+20h] [rbp-A8h]
  __int64 i; // [rsp+28h] [rbp-A0h]
  int v19[2]; // [rsp+40h] [rbp-88h] BYREF
  unsigned int v20; // [rsp+48h] [rbp-80h]
  unsigned int ElementCount; // [rsp+4Ch] [rbp-7Ch]
  _DWORD ElementCount_4[4]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v23[13]; // [rsp+60h] [rbp-68h] BYREF

  Stream = fopen(a2, "wb");
  if ( !Stream )
  {
    perror(a2);
    exit(1);
  }
  for ( i = *(_QWORD *)(a1 + 8); i != a1; i = *(_QWORD *)(i + 8) )
  {
    v3 = *(const char **)(i + 24);
    v4 = **(_QWORD **)(i + 16);
    v19[0] = 603238138;
    v19[1] = 0;
    v20 = *(_DWORD *)(v4 + 80);
    ElementCount = strlen(v3);
    fwrite(v19, 1ui64, 0x10ui64, Stream);
    v5 = *(int *)(v4 + 80);
    if ( (_DWORD)v5 )
    {
      ElementCount_4[0] = *(_QWORD *)(v4 + 120);
      if ( v5 > 1 )
      {
        ElementCount_4[1] = *(_QWORD *)(v4 + 128);
        if ( v5 != 2 )
        {
          ElementCount_4[2] = *(_QWORD *)(v4 + 136);
          if ( v5 != 3 )
            ElementCount_4[3] = *(_QWORD *)(v4 + 144);
        }
      }
    }
    fwrite(ElementCount_4, 1ui64, 4i64 * v20, Stream);
    fwrite(*(const void **)(i + 24), 1ui64, ElementCount, Stream);
    v6 = *(_DWORD *)(v4 + 80);
    if ( v6 <= 0 )
    {
      v23[0] = 0i64;
      v10 = 0i64;
      v8 = 0;
      v7 = 1i64;
    }
    else
    {
      if ( *(_BYTE *)(v4 + 73) )
      {
        v7 = *(_QWORD *)(v4 + 120);
        if ( v6 == 1 )
        {
          v7 = (int)v7;
          v8 = 1;
          v10 = 0i64;
          v23[0] = 0i64;
          goto LABEL_21;
        }
        if ( *(_BYTE *)(v4 + 74) )
        {
          v7 *= *(_QWORD *)(v4 + 128);
          if ( v6 == 2 )
          {
            v8 = 2;
            goto LABEL_17;
          }
          if ( *(_BYTE *)(v4 + 75) )
          {
            v7 *= *(_QWORD *)(v4 + 136);
            if ( v6 == 3 )
            {
              v8 = 3;
              goto LABEL_17;
            }
            if ( *(_BYTE *)(v4 + 76) )
            {
              v7 *= *(_QWORD *)(v4 + 144);
              v8 = 4;
LABEL_17:
              v23[0] = 0i64;
              v7 = (int)v7;
LABEL_18:
              v9 = 1i64;
              do
                v23[v9++] = 0i64;
              while ( v6 > (int)v9 );
              v10 = v23[0];
              goto LABEL_21;
            }
            v7 = (int)v7;
            v8 = 3;
          }
          else
          {
            v7 = (int)v7;
            v8 = 2;
          }
        }
        else
        {
          v7 = (int)v7;
          v8 = 1;
        }
      }
      else
      {
        v7 = 1i64;
        v8 = 0;
      }
      v23[0] = 0i64;
      if ( v6 > 1 )
        goto LABEL_18;
      v10 = 0i64;
    }
LABEL_21:
    v11 = &v23[v8];
    while ( v10 != -1 )
    {
      if ( v6 <= 0 )
        goto LABEL_28;
      v12 = *(_QWORD *)(v4 + 88) * v10;
      if ( v6 != 1 )
      {
        v12 += *(_QWORD *)(v4 + 96) * v23[1];
        if ( v6 != 2 )
        {
          v12 += *(_QWORD *)(v4 + 104) * v23[2];
          if ( v6 != 3 )
          {
            if ( v6 != 4 )
            {
LABEL_28:
              v12 = 0i64;
              goto LABEL_29;
            }
            v12 += *(_QWORD *)(v4 + 112) * v23[3];
          }
        }
      }
LABEL_29:
      fwrite(
        (const void *)(v12 + *(_QWORD *)(v4 + 56)),
        1ui64,
        nc_type_size_table[*(unsigned int *)(v4 + 48)] * v7,
        Stream);
      v6 = *(_DWORD *)(v4 + 80);
      if ( v8 >= v6 )
        goto LABEL_34;
      v13 = *v11 + 1;
      *v11 = v13;
      if ( *(_QWORD *)(v4 + 8 * (v8 + 12i64) + 24) == v13 )
      {
        v14 = 0i64;
        while ( 1 )
        {
          v11[v14] = 0i64;
          if ( v6 - 1 - v8 == v14 )
            break;
          v15 = v11[v14 + 1] + 1;
          v11[++v14] = v15;
          if ( v15 != *(_QWORD *)(v4 + 8i64 * (unsigned int)(v8 + 1) + 8 * v14 + 112) )
            goto LABEL_37;
        }
LABEL_34:
        v23[0] = -1i64;
        break;
      }
LABEL_37:
      v10 = v23[0];
    }
  }
  return fclose(Stream);
}

