// Auto-generated from libnc.so_pseudocode.c
// Root function: nc_job_exec
// Included functions: 1

// ======================================================
// Function: nc_job_exec @ 0x2EC20
// ======================================================

__int64 nc_job_exec()
{
  void *v0; // rax

  v0 = (void *)nc_job_start();
  return nc_job_free(v0);
}

