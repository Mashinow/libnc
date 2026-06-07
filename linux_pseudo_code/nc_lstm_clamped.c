// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_lstm_clamped
// Included functions: 2

// ======================================================
// Function: nc_lstm_clamped @ 0x26D00
// ======================================================

__int64 __fastcall nc_lstm_clamped(
        unsigned int *ptr,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7)
{
  __int64 v7; // rbx
  __int64 v8; // rbp
  __int64 v9; // r12
  __int64 v10; // r13
  __int64 v11; // r14
  __int64 v12; // r15
  __int64 v16; // r10
  __int64 v18; // r12
  unsigned int v19; // eax
  int v20; // esi
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rcx
  __int64 v24; // rsi
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rcx
  __int64 v29; // rax
  int v30; // eax
  int v31; // edx
  __int64 v32; // r10
  __int64 v33; // rax
  __int64 v34; // rax
  __int64 v35; // r14
  __int64 v36; // r9
  __int64 v37; // r8
  __int64 v38; // r8
  __int64 v39; // rcx
  __int64 v40; // rcx
  int v41; // esi
  int v42; // edi
  __int64 v43; // rax
  int v44; // eax
  int v45; // esi
  __int64 *v46; // rcx
  __int64 v47; // rdx
  unsigned int *v48; // rdi
  __int64 v49; // rsi
  __int64 v50; // rax
  __int64 v51; // rdx
  void *v52; // r10
  _QWORD *v60; // r14
  _DWORD *v61; // rax
  _DWORD *v62; // r13
  __int64 v63; // rax
  __int64 v64; // r12
  __int64 v65; // rbx
  _QWORD *v66; // r12
  __int64 v67; // rdi
  __int64 v68; // rax
  __int64 v69; // rax
  __int64 v70; // rax
  void *v71; // r10
  void *v72; // rdi
  _QWORD *v73; // rax
  __int64 v74; // r12
  __int64 v75; // r12
  __int64 v76; // r12
  __int64 v77; // rax
  __int64 v78; // [rsp-E0h] [rbp-E0h]
  __int64 v79; // [rsp-D8h] [rbp-D8h]
  __int64 v80; // [rsp-D0h] [rbp-D0h]
  __int64 v81; // [rsp-C8h] [rbp-C8h]
  __int64 v82; // [rsp-C0h] [rbp-C0h]
  __int64 *v83; // [rsp-B8h] [rbp-B8h]
  __int64 v84; // [rsp-B0h] [rbp-B0h]
  __int64 v85; // [rsp-A8h] [rbp-A8h]
  void *v86; // [rsp-A8h] [rbp-A8h]
  __int64 v87; // [rsp-A0h] [rbp-A0h]
  unsigned int *v88; // [rsp-A0h] [rbp-A0h]
  __int64 v89; // [rsp-98h] [rbp-98h]
  __int64 v90; // [rsp-98h] [rbp-98h]
  __int64 v91; // [rsp-98h] [rbp-98h]
  void *v92; // [rsp-98h] [rbp-98h]
  __int64 v93; // [rsp-98h] [rbp-98h]
  void *v94; // [rsp-98h] [rbp-98h]
  __int64 v95; // [rsp-90h] [rbp-90h]
  __int64 v96; // [rsp-88h] [rbp-88h] BYREF
  __int64 v97; // [rsp-78h] [rbp-78h]
  __int64 v98; // [rsp-70h] [rbp-70h]
  __int64 v99; // [rsp-68h] [rbp-68h]
  __int64 v100; // [rsp-60h] [rbp-60h] BYREF
  __int64 v101; // [rsp-58h] [rbp-58h]
  __int64 v102; // [rsp-50h] [rbp-50h]
  __int64 v103; // [rsp-48h] [rbp-48h]
  __int64 v104; // [rsp-40h] [rbp-40h]
  char *v105; // [rsp-38h] [rbp-38h]
  __int64 v106; // [rsp-30h] [rbp-30h]
  __int64 v107; // [rsp-28h] [rbp-28h]
  __int64 v108; // [rsp-20h] [rbp-20h]
  __int64 v109; // [rsp-18h] [rbp-18h]
  _QWORD v110[2]; // [rsp-10h] [rbp-10h] BYREF
  void *retaddr; // [rsp+0h] [rbp+0h]

  v110[1] = retaddr;
  v110[0] = v8;
  _RBP = v110;
  v109 = v12;
  _R15 = a3;
  v108 = v11;
  v107 = v10;
  v106 = v9;
  v105 = &a7;
  v16 = a2;
  v104 = v7;
  _RBX = ptr;
  v82 = a4;
  v18 = *(_QWORD *)(*((_QWORD *)ptr + 5) + 24LL);
  if ( v18 != *(_QWORD *)(*(_QWORD *)(a2 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  if ( v18 != *(_QWORD *)(*(_QWORD *)(a3 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  if ( v18 != *(_QWORD *)(*(_QWORD *)(a4 + 40) + 24LL) )
    nc_error("all operation tensors must be on the same device", a2);
  v19 = *(_DWORD *)(a2 + 48);
  if ( v19 != ptr[12] || v19 != *(_DWORD *)(a3 + 48) || *(_DWORD *)(a4 + 48) != v19 || v19 > 1 )
    nc_error("unsupported type for %s\n", (char)"nc_lstm_clamped");
  v20 = *(_DWORD *)(a2 + 80);
  v21 = ptr[20];
  if ( v20 != (_DWORD)v21 )
LABEL_10:
    __assert_fail("same_dims(in1, cp1)", "libnc.c", 0x1D41u, "nc_lstm_clamped");
  if ( v20 <= 0 )
  {
LABEL_39:
    if ( (_DWORD)v21 != *(_DWORD *)(_R15 + 80) )
      goto LABEL_40;
    if ( (_DWORD)v21 == *(_DWORD *)(v82 + 80) )
      goto LABEL_30;
LABEL_42:
    __assert_fail("same_dims(ig1, cp1)", "libnc.c", 0x1D43u, "nc_lstm_clamped");
  }
  if ( *(_QWORD *)(v16 + 120) != *((_QWORD *)ptr + 15) )
    goto LABEL_10;
  v22 = 1LL;
  while ( v20 > (int)v22 )
  {
    v23 = *(_QWORD *)(v16 + 8 * v22++ + 120);
    if ( v23 != *(_QWORD *)&ptr[2 * v22 + 28] )
      goto LABEL_10;
  }
  if ( (_DWORD)v21 != *(_DWORD *)(_R15 + 80) || (v24 = *((_QWORD *)ptr + 15), v25 = 1LL, v24 != *(_QWORD *)(_R15 + 120)) )
LABEL_40:
    __assert_fail("same_dims(fg1, cp1)", "libnc.c", 0x1D42u, "nc_lstm_clamped");
  while ( (int)v21 > (int)v25 )
  {
    v26 = *(_QWORD *)(_R15 + 8 * v25++ + 120);
    if ( v26 != *(_QWORD *)&ptr[2 * v25 + 28] )
      goto LABEL_40;
  }
  if ( (_DWORD)v21 != *(_DWORD *)(v82 + 80) )
    goto LABEL_42;
  v27 = 1LL;
  if ( v24 != *(_QWORD *)(v82 + 120) )
    goto LABEL_42;
  while ( (int)v21 > (int)v27 )
  {
    v28 = *(_QWORD *)(v82 + 8 * v27++ + 120);
    if ( v28 != *(_QWORD *)&ptr[2 * v27 + 28] )
      goto LABEL_42;
  }
LABEL_30:
  v89 = v16;
  v29 = nc_new_tensor_nz(*(_QWORD *)(*((_QWORD *)_RBX + 5) + 24LL), _RBX[12], v21, _RBX + 30);
  v30 = sub_7F90(
          (_DWORD *)&v96 + 1,
          0,
          v29,
          (__int64)_RBX,
          v89,
          _R15,
          v82,
          0LL,
          v78,
          v79,
          v80,
          v29,
          v82,
          (__int64)v83,
          v84,
          v85,
          v87,
          v89,
          v95,
          v96);
  v31 = _RBX[20];
  v100 = 0LL;
  v32 = v90;
  v84 = v30;
  v33 = 1LL;
  if ( v31 <= 1 )
  {
    v34 = 0LL;
  }
  else
  {
    do
      *(&v100 + v33++) = 0LL;
    while ( v31 > (int)v33 );
    v34 = v100;
  }
  v91 = v18;
  v35 = v32;
  v83 = &v100;
  v18 = v82;
  if ( v34 == -1 )
  {
LABEL_81:
    v52 = (void *)v35;
  }
  else
  {
    while ( 1 )
    {
      v21 = *(unsigned int *)(v82 + 80);
      v16 = *(_QWORD *)(v91 + 288);
      LODWORD(v87) = _RBX[12];
      if ( (int)v21 <= 0 )
      {
        v36 = 0LL;
      }
      else
      {
        v36 = *(_QWORD *)(v82 + 88) * v34;
        if ( (_DWORD)v21 != 1 )
        {
          v36 += *(_QWORD *)(v82 + 96) * v101;
          if ( (_DWORD)v21 != 2 )
          {
            v36 += *(_QWORD *)(v82 + 104) * v102;
            if ( (_DWORD)v21 != 3 )
            {
              if ( (_DWORD)v21 != 4 )
                goto LABEL_39;
              v36 += *(_QWORD *)(v82 + 112) * v103;
            }
          }
        }
      }
      v21 = *(unsigned int *)(_R15 + 80);
      v85 = *(_QWORD *)(v82 + 56) + v36;
      if ( (int)v21 <= 0 )
      {
        v37 = 0LL;
      }
      else
      {
        v37 = *(_QWORD *)(_R15 + 88) * v34;
        if ( (_DWORD)v21 != 1 )
        {
          v37 += *(_QWORD *)(_R15 + 96) * v101;
          if ( (_DWORD)v21 != 2 )
          {
            v37 += *(_QWORD *)(_R15 + 104) * v102;
            if ( (_DWORD)v21 != 3 )
            {
              if ( (_DWORD)v21 != 4 )
                goto LABEL_39;
              v37 += *(_QWORD *)(_R15 + 112) * v103;
            }
          }
        }
      }
      v21 = *(unsigned int *)(v35 + 80);
      v38 = *(_QWORD *)(_R15 + 56) + v37;
      if ( (int)v21 <= 0 )
      {
        v39 = 0LL;
      }
      else
      {
        v39 = *(_QWORD *)(v35 + 88) * v34;
        if ( (_DWORD)v21 != 1 )
        {
          v39 += *(_QWORD *)(v35 + 96) * v101;
          if ( (_DWORD)v21 != 2 )
          {
            v39 += *(_QWORD *)(v35 + 104) * v102;
            if ( (_DWORD)v21 != 3 )
            {
              if ( (_DWORD)v21 != 4 )
                goto LABEL_39;
              v39 += *(_QWORD *)(v35 + 112) * v103;
            }
          }
        }
      }
      v40 = *(_QWORD *)(v35 + 56) + v39;
      v41 = _RBX[20];
      if ( v41 <= 0 )
      {
        v21 = 0LL;
      }
      else
      {
        v21 = *((_QWORD *)_RBX + 11) * v34;
        if ( v41 != 1 )
        {
          v21 += *((_QWORD *)_RBX + 12) * v101;
          if ( v41 != 2 )
          {
            v21 += *((_QWORD *)_RBX + 13) * v102;
            if ( v41 != 3 )
            {
              if ( v41 != 4 )
                goto LABEL_39;
              v21 += *((_QWORD *)_RBX + 14) * v103;
            }
          }
        }
      }
      v21 += *((_QWORD *)_RBX + 7);
      v42 = *(_DWORD *)(v81 + 80);
      if ( v42 <= 0 )
      {
        v43 = 0LL;
      }
      else
      {
        v43 = *(_QWORD *)(v81 + 88) * v34;
        if ( v42 != 1 )
        {
          v43 += *(_QWORD *)(v81 + 96) * v101;
          if ( v42 != 2 )
          {
            v43 += *(_QWORD *)(v81 + 104) * v102;
            if ( v42 != 3 )
            {
              if ( v42 != 4 )
                goto LABEL_39;
              v43 += *(_QWORD *)(v81 + 112) * v103;
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD))v16)(
        v91,
        v43 + *(_QWORD *)(v81 + 56),
        v21,
        v40,
        v38,
        v85,
        v84,
        (unsigned int)v87);
      v44 = HIDWORD(v96);
      v45 = _RBX[20];
      if ( SHIDWORD(v96) >= v45 )
        break;
      v46 = &v100 + SHIDWORD(v96);
      v47 = *v46 + 1;
      *v46 = v47;
      if ( v47 == *(_QWORD *)&_RBX[2 * v44 + 30] )
      {
        v48 = &_RBX[2 * v44 + 2];
        v49 = (unsigned int)(~v44 + v45);
        v50 = 0LL;
        do
        {
          v46[v50] = 0LL;
          if ( v50 == v49 )
            goto LABEL_73;
          v51 = v46[v50 + 1] + 1;
          v46[++v50] = v51;
        }
        while ( v51 == *(_QWORD *)&v48[2 * v50 + 28] );
      }
      v34 = v100;
      if ( v100 == -1 )
        goto LABEL_81;
    }
LABEL_73:
    v100 = -1LL;
    v52 = (void *)v35;
  }
  __asm
  {
    vmovq   xmm2, rbx
    vmovq   xmm3, r15
    vpinsrq xmm0, xmm3, qword ptr [rbp-0B0h], 1
    vpinsrq xmm1, xmm2, r10, 1
    vinserti128 ymm1, ymm1, xmm0, 1
    vmovq   r12, xmm1
    vmovdqa ymmword ptr [rbp-70h], ymm1
  }
  if ( !*(_QWORD *)(_R12 + 32) && !*(_QWORD *)(v97 + 32) && !*(_QWORD *)(v98 + 32) && !*(_QWORD *)(v99 + 32) )
  {
    __asm { vzeroupper }
    goto LABEL_79;
  }
  v86 = v52;
  __asm { vzeroupper }
  v60 = (_QWORD *)nc_malloc(0x20uLL);
  *v60 = *(_QWORD *)(_R12 + 32);
  v60[1] = *(_QWORD *)(v97 + 32);
  v60[2] = *(_QWORD *)(v98 + 32);
  v60[3] = *(_QWORD *)(v99 + 32);
  v93 = *(_QWORD *)(v81 + 24);
  v61 = (_DWORD *)nc_mallocz(0x80uLL);
  v61[4] = 1;
  v62 = v61;
  v61[5] = 25;
  v61[6] = 4;
  v63 = nc_malloc(0x20uLL);
  v88 = _RBX;
  *((_QWORD *)v62 + 4) = v63;
  v64 = v63;
  v65 = 0LL;
  while ( 1 )
  {
    v67 = v60[v65];
    if ( !v67 )
      break;
    v66 = (_QWORD *)(v65 * 8 + v64);
    ++v65;
    *v66 = nc_dup_node(v67);
    if ( v65 == 4 )
      goto LABEL_92;
LABEL_89:
    v64 = *((_QWORD *)v62 + 4);
  }
  *(_QWORD *)(v64 + v65 * 8) = 0LL;
  if ( ++v65 != 4 )
    goto LABEL_89;
LABEL_92:
  _RBX = v88;
  v68 = *(_QWORD *)(v93 + 72);
  *(_QWORD *)(v93 + 72) = v68 + 1;
  *((_QWORD *)v62 + 12) = v68;
  v69 = *(_QWORD *)(v93 + 32);
  *(_QWORD *)(v69 + 8) = v62;
  *(_QWORD *)v62 = v69;
  *((_QWORD *)v62 + 1) = v93 + 32;
  *(_QWORD *)(v93 + 32) = v62;
  nc_free(v60);
  v70 = v81;
  v71 = v86;
  v72 = *(void **)(v81 + 32);
  if ( v72 )
  {
    nc_free_node(v72);
    v71 = v86;
    v70 = v81;
  }
  *(_QWORD *)(v70 + 32) = v62;
  v62[10] = 4;
  v94 = v71;
  v73 = (_QWORD *)nc_malloc(0x20uLL);
  *((_QWORD *)v62 + 6) = v73;
  *v73 = nc_dup_tensor(v88);
  v74 = *((_QWORD *)v62 + 6);
  *(_QWORD *)(v74 + 8) = nc_dup_tensor(v94);
  v75 = *((_QWORD *)v62 + 6);
  *(_QWORD *)(v75 + 16) = nc_dup_tensor(_R15);
  v76 = *((_QWORD *)v62 + 6);
  v77 = nc_dup_tensor(v82);
  v52 = v94;
  *(_QWORD *)(v76 + 24) = v77;
LABEL_79:
  v92 = v52;
  nc_free_tensor(_RBX);
  nc_free_tensor(v92);
  nc_free_tensor((void *)_R15);
  nc_free_tensor((void *)v82);
  return v81;
}

// ======================================================
// Function: sub_7F90 @ 0x7F90
// ======================================================

__int64 __fastcall sub_7F90(
        _DWORD *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20)
{
  int v20; // r8d
  __int64 v21; // rcx
  __int64 v22; // rax
  int v23; // esi
  __int64 result; // rax
  int v25; // r8d
  int v26; // [rsp+38h] [rbp-120h]
  __int64 v27; // [rsp+38h] [rbp-120h]
  __int64 v28; // [rsp+70h] [rbp-E8h]
  __int64 v29; // [rsp+78h] [rbp-E0h]
  __int64 v30; // [rsp+80h] [rbp-D8h]
  __int64 v31; // [rsp+88h] [rbp-D0h]
  __int64 v32; // [rsp+90h] [rbp-C8h]
  __int64 v33; // [rsp+98h] [rbp-C0h]
  __int64 v34; // [rsp+A0h] [rbp-B8h]
  __int64 v35; // [rsp+A8h] [rbp-B0h]
  __int64 v36; // [rsp+B0h] [rbp-A8h]
  __int64 v37; // [rsp+B8h] [rbp-A0h]
  __int64 v38; // [rsp+C0h] [rbp-98h]
  __int64 v39; // [rsp+C8h] [rbp-90h]
  __int64 v40; // [rsp+D0h] [rbp-88h]
  __int64 v41; // [rsp+D8h] [rbp-80h]
  __int64 v42; // [rsp+E0h] [rbp-78h]
  __int64 v43; // [rsp+E8h] [rbp-70h]

  if ( a4 )
  {
    v28 = a4;
    if ( a5 )
    {
      v29 = a5;
      if ( a6 )
      {
        v30 = a6;
        if ( a7 )
        {
          v31 = a7;
          if ( a8 )
          {
            v32 = a8;
            if ( a9 )
            {
              v33 = a9;
              if ( a10 )
              {
                v34 = a10;
                if ( a11 )
                {
                  v35 = a11;
                  if ( a12 )
                  {
                    v36 = a12;
                    if ( a13 )
                    {
                      v37 = a13;
                      if ( a14 )
                      {
                        v38 = a14;
                        if ( a15 )
                        {
                          v39 = a15;
                          if ( a16 )
                          {
                            v40 = a16;
                            if ( a17 )
                            {
                              v41 = a17;
                              if ( a18 )
                              {
                                v42 = a18;
                                if ( a19 )
                                {
                                  v43 = a19;
                                  if ( a20 )
                                    __assert_fail("count < countof(tab)", "libnc.c", 0x122Du, "get_contig_len_N");
                                  v20 = 16;
                                }
                                else
                                {
                                  v20 = 15;
                                }
                              }
                              else
                              {
                                v20 = 14;
                              }
                            }
                            else
                            {
                              v20 = 13;
                            }
                          }
                          else
                          {
                            v20 = 12;
                          }
                        }
                        else
                        {
                          v20 = 11;
                        }
                      }
                      else
                      {
                        v20 = 10;
                      }
                    }
                    else
                    {
                      v20 = 9;
                    }
                  }
                  else
                  {
                    v20 = 8;
                  }
                }
                else
                {
                  v20 = 7;
                }
              }
              else
              {
                v20 = 6;
              }
            }
            else
            {
              v20 = 5;
            }
          }
          else
          {
            v20 = 4;
          }
        }
        else
        {
          v20 = 3;
        }
      }
      else
      {
        v20 = 2;
      }
    }
    else
    {
      v20 = 1;
    }
  }
  else
  {
    v20 = 0;
  }
  v26 = *(_DWORD *)(a3 + 80);
  if ( a2 < v26 && (v21 = a2, *(_BYTE *)(a3 + a2 + 73)) )
  {
    v22 = (unsigned int)(v26 - 1 - a2);
    v23 = v20;
    v27 = v21 + v22;
    result = 1LL;
    do
    {
      v25 = v21;
      if ( v23
        && (!*(_BYTE *)(v28 + v21 + 73)
         || v23 != 1
         && (!*(_BYTE *)(v29 + v21 + 73)
          || v23 != 2
          && (!*(_BYTE *)(v30 + v21 + 73)
           || v23 != 3
           && (!*(_BYTE *)(v31 + v21 + 73)
            || v23 != 4
            && (!*(_BYTE *)(v32 + v21 + 73)
             || v23 != 5
             && (!*(_BYTE *)(v33 + v21 + 73)
              || v23 != 6
              && (!*(_BYTE *)(v34 + v21 + 73)
               || v23 != 7
               && (!*(_BYTE *)(v35 + v21 + 73)
                || v23 != 8
                && (!*(_BYTE *)(v36 + v21 + 73)
                 || v23 != 9
                 && (!*(_BYTE *)(v37 + v21 + 73)
                  || v23 != 10
                  && (!*(_BYTE *)(v38 + v21 + 73)
                   || v23 != 11
                   && (!*(_BYTE *)(v39 + v21 + 73)
                    || v23 != 12
                    && (!*(_BYTE *)(v40 + v21 + 73)
                     || v23 != 13
                     && (!*(_BYTE *)(v41 + v21 + 73)
                      || v23 != 14 && (!*(_BYTE *)(v42 + v21 + 73) || v23 == 16 && !*(_BYTE *)(v43 + v21 + 73)))))))))))))))) )
      {
        break;
      }
      v25 = v21 + 1;
      result *= *(_QWORD *)(a3 + 8 * v21 + 120);
      if ( v21 == v27 )
        break;
      ++v21;
    }
    while ( *(_BYTE *)(a3 + 1 + v21 + 72) );
    a2 = v25;
  }
  else
  {
    result = 1LL;
  }
  *a1 = a2;
  return result;
}

