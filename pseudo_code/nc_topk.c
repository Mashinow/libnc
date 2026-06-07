// Auto-generated from libnc.dll_pseudocode.c
// Root function: nc_topk
// Included functions: 4

// ======================================================
// Function: nc_topk @ 0x66A31500
// ======================================================

__int64 __fastcall nc_topk(_QWORD *a1, __int64 a2, _DWORD *a3, unsigned __int64 a4, unsigned int a5, int a6)
{
  char *v16; // rax
  bool v18; // cf
  signed int v19; // edx
  char *v20; // r12
  __int64 v22; // rax
  __int64 result; // rax
  char *v32; // rax
  int v35; // [rsp+3Ch] [rbp-5Ch] BYREF

  __asm
  {
    vmovaps [rsp+98h+var_58], xmm6
    vmovaps [rsp+98h+var_48], xmm7
    vmovss  xmm6, [rsp+98h+arg_28]
  }
  _RDI = a2;
  _RBX = a3;
  if ( a4 )
  {
    __asm { vmovss  [rsp+98h+var_78], xmm6 }
    sub_66A03030((unsigned int *)&v35, a3, a4, a5);
    __asm { vmovaps xmm7, xmm0 }
    v16 = (char *)aligned_malloc(8i64 * v35, 0x40ui64);
    _RCX = 0i64;
    v18 = 0;
    v19 = 0;
    v20 = v16;
    do
    {
      __asm
      {
        vmovss  xmm1, dword ptr [rbx+rcx*4]
        vucomiss xmm1, xmm7
      }
      if ( !v18 )
      {
        v22 = v19++;
        _RAX = &v20[8 * v22];
        *((_DWORD *)_RAX + 1) = _RCX;
        __asm { vmovss  dword ptr [rax], xmm1 }
      }
      v18 = a4 < ++_RCX;
    }
    while ( a4 != _RCX );
  }
  else
  {
    sub_66A33D40("n_symb >= 1", "libnc.c", 9253);
    __asm { vmovss  [rsp+98h+var_78], xmm6 }
    sub_66A03030((unsigned int *)&v35, _RBX, 0i64, a5);
    v32 = (char *)aligned_malloc(8i64 * v35, 0x40ui64);
    v19 = 0;
    v20 = v32;
  }
  if ( v35 != v19 )
  {
    sub_66A33D40("j == k1", "libnc.c", 9266);
    v19 = v35;
  }
  qsort(v20, v19, 8ui64, (_CoreCrtNonSecureSearchSortCompareFunction)CompareFunction);
  result = a5;
  if ( v35 <= (int)a5 )
    result = (unsigned int)v35;
  __asm { vxorpd  xmm0, xmm0, xmm0 }
  if ( (int)result > 0 )
  {
    __asm
    {
      vxorpd  xmm0, xmm0, xmm0
      vxorpd  xmm2, xmm2, xmm2
      vcvtss2sd xmm2, xmm2, xmm6
      vcvtss2sd xmm0, xmm0, dword ptr [rbx+rdx*4]
      vaddsd  xmm0, xmm0, cs:qword_66A379A0
      vucomisd xmm0, xmm2
    }
    result = 1i64;
  }
  __asm
  {
    vmovaps xmm6, [rsp+98h+var_58]
    vmovaps xmm7, [rsp+98h+var_48]
  }
  *a1 = v20;
  __asm { vmovsd  qword ptr [rdi], xmm0 }
  return result;
}

// ======================================================
// Function: sub_66A03030 @ 0x66A03030
// ======================================================

__int64 __fastcall sub_66A03030(unsigned int *a1, _DWORD *a2, __int64 a3, unsigned int a4)
{
  _DWORD *v10; // rdx
  __int64 result; // rax
  unsigned int v17; // edx
  unsigned int v19; // ecx
  int v22[256]; // [rsp+20h] [rbp-C38h] BYREF
  __int64 v23[263]; // [rsp+420h] [rbp-838h] BYREF

  memset(v22, 0, sizeof(v22));
  memset(v23, 0, 0x800ui64);
  if ( a3 )
  {
    v10 = a2;
    do
    {
      __asm { vxorpd  xmm0, xmm0, xmm0 }
      _RAX = (unsigned __int8)(*v10 >> 23);
      __asm { vcvtss2sd xmm0, xmm0, dword ptr [rdx] }
      ++v10;
      ++v22[_RAX];
      __asm
      {
        vaddsd  xmm0, xmm0, [rsp+rax*8+0C58h+var_838]
        vmovsd  [rsp+rax*8+0C58h+var_838], xmm0
      }
    }
    while ( &a2[a3] != v10 );
  }
  __asm
  {
    vxorpd  xmm1, xmm1, xmm1
    vxorpd  xmm0, xmm0, xmm0
  }
  result = 254i64;
  v17 = 0;
  __asm { vcvtss2sd xmm1, xmm1, [rsp+0C58h+arg_20] }
  do
  {
    __asm { vaddsd  xmm0, xmm0, qword ptr [rdi+rax*8] }
    v19 = v17 + v22[result];
    v17 = v19;
    if ( v19 >= a4 )
      goto LABEL_8;
    __asm { vucomisd xmm0, xmm1 }
    if ( v19 >= a4 )
    {
LABEL_8:
      result = (unsigned int)((_DWORD)result << 23);
      __asm { vmovd   xmm0, eax }
      goto LABEL_9;
    }
    --result;
  }
  while ( result );
  __asm { vxorps  xmm0, xmm0, xmm0 }
LABEL_9:
  *a1 = v19;
  return result;
}

// ======================================================
// Function: sub_66A33D40 @ 0x66A33D40
// ======================================================

void __fastcall sub_66A33D40(const char *a1, const char *a2, int a3)
{
  size_t v5; // rax
  wchar_t *v6; // rsi
  size_t v7; // rax
  const wchar_t *v8; // rax
  wchar_t v9; // cx
  __int64 v10; // r9
  wchar_t *v11; // rbx
  wchar_t v12; // cx
  __int64 v13; // r9

  v5 = strlen(a1);
  v6 = (wchar_t *)malloc(2 * v5 + 2);
  v7 = strlen(a2);
  v8 = (const wchar_t *)malloc(2 * v7 + 2);
  v9 = *(unsigned __int8 *)a1;
  v10 = 0i64;
  v11 = (wchar_t *)v8;
  if ( (_BYTE)v9 )
  {
    do
    {
      v6[v10++] = v9;
      v9 = (unsigned __int8)a1[v10];
    }
    while ( (_BYTE)v9 );
    v10 *= 2i64;
  }
  v12 = *(unsigned __int8 *)a2;
  *(wchar_t *)((char *)v6 + v10) = 0;
  v13 = 0i64;
  if ( (_BYTE)v12 )
  {
    do
    {
      v8[v13++] = v12;
      v12 = (unsigned __int8)a2[v13];
    }
    while ( (_BYTE)v12 );
    v13 *= 2i64;
  }
  *(const wchar_t *)((char *)v8 + v13) = 0;
  sub_66A33C00(v6, v8, a3);
  free(v6);
  free(v11);
}

// ======================================================
// Function: sub_66A33C00 @ 0x66A33C00
// ======================================================

int __fastcall sub_66A33C00(const wchar_t *a1, const wchar_t *a2, int a3)
{
  wchar_t *v6; // rbp
  int result; // eax
  FILE *v8; // rax
  WCHAR Filename[284]; // [rsp+40h] [rbp-238h] BYREF

  v6 = (wchar_t *)malloc(0x4000ui64);
  if ( a2 )
  {
    if ( !*a2 )
      a2 = L"<unknown>";
  }
  else
  {
    a2 = L"<unknown>";
  }
  if ( a1 )
  {
    if ( !*a1 )
      a1 = L"?";
  }
  else
  {
    a1 = L"?";
  }
  if ( !GetModuleFileNameW(0i64, Filename, 0x104u) )
    wcscpy(Filename, L"<unknown>");
  snwprintf(
    v6,
    0x1FFFui64,
    L"Assertion failed!\n\nProgram: %ws\nFile: %ws, Line %u\n\nExpression: %ws",
    Filename,
    a2,
    a3,
    a1);
  if ( !unk_66A3D5B0 )
  {
    v8 = _iob_func();
    fwprintf(v8 + 2, L"%ws\n", v6);
    abort();
  }
  result = MessageBoxW(0i64, v6, L"MinGW Runtime Assertion", 0x12012u);
  if ( result == 3 )
  {
    raise(22);
    exit(3);
  }
  if ( result != 5 )
    abort();
  return result;
}

