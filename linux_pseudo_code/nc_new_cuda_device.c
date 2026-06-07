// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_new_cuda_device
// Included functions: 1

// ======================================================
// Function: nc_new_cuda_device @ 0x16120
// ======================================================

__int64 __fastcall nc_new_cuda_device(__int64 a1, unsigned int a2)
{
  char *v2; // rax
  void *v3; // rax
  __int64 (__fastcall *v4)(__int64, _QWORD); // rax
  char v6[1024]; // [rsp+0h] [rbp-828h] BYREF
  char s[1064]; // [rsp+400h] [rbp-428h] BYREF

  if ( !dword_236520 )
  {
    if ( readlink("/proc/self/exe", &buf, 0x400uLL) < 0 )
      buf = 0;
    dword_236520 = 1;
  }
  snprintf(v6, 0x400uLL, "%s", &buf);
  v2 = strrchr(v6, 47);
  if ( v2 )
    v2[1] = 0;
  else
    v6[0] = 0;
  snprintf(s, 0x400uLL, "%slibnc_cuda.so", v6);
  if ( access(s, 4) )
  {
    fprintf(stderr, "Could not find: %s\n", s);
    goto LABEL_13;
  }
  v3 = dlopen(s, 2);
  if ( !v3 )
  {
    fprintf(stderr, "Could not load: %s\n", s);
    goto LABEL_13;
  }
  v4 = (__int64 (__fastcall *)(__int64, _QWORD))dlsym(v3, "nc_new_cuda_device_internal");
  if ( !v4 )
  {
    fprintf(stderr, "%s: could not find device function\n", s);
LABEL_13:
    exit(1);
  }
  return v4(a1, a2);
}

