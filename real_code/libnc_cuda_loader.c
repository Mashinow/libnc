#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#endif

typedef NCDevice *(*NCCudaNewDeviceInternalFn)(NCContext *ctx, unsigned int device_index);

static NCCudaNewDeviceInternalFn nc_cuda_new_device_internal = NULL;
static int nc_cuda_loader_state = 0;

static void nc_cuda_loader_init(void)
{
    if (nc_cuda_loader_state != 0)
        return;

#ifdef _WIN32
    char exe_path[1024];
    char dll_path[1024];
    DWORD len = GetModuleFileNameA(NULL, exe_path, sizeof(exe_path));
    if (len > 0 && len < sizeof(exe_path)) {
        char *slash = strrchr(exe_path, '\\');
        char *fslash = strrchr(exe_path, '/');
        if (!slash || (fslash && fslash > slash))
            slash = fslash;
        if (slash) {
            size_t dir_len = (size_t)(slash - exe_path + 1);
            if (dir_len + strlen("libnc_cuda.dll") < sizeof(dll_path)) {
                memcpy(dll_path, exe_path, dir_len);
                memcpy(dll_path + dir_len, "libnc_cuda.dll", strlen("libnc_cuda.dll") + 1);
                HMODULE mod = LoadLibraryA(dll_path);
                if (!mod)
                    mod = LoadLibraryA("libnc_cuda.dll");
                if (mod) {
                    nc_cuda_new_device_internal = (NCCudaNewDeviceInternalFn)GetProcAddress(mod, "nc_new_cuda_device_internal");
                    if (!nc_cuda_new_device_internal) {
                        FreeLibrary(mod);
                    } else {
                        nc_cuda_loader_state = 1;
                        return;
                    }
                }
            }
        }
    }
    {
        HMODULE mod = LoadLibraryA("libnc_cuda.dll");
        if (mod) {
            nc_cuda_new_device_internal = (NCCudaNewDeviceInternalFn)GetProcAddress(mod, "nc_new_cuda_device_internal");
            if (!nc_cuda_new_device_internal)
                FreeLibrary(mod);
            else {
                nc_cuda_loader_state = 1;
                return;
            }
        }
    }
#else
    {
        char exe_path[1024];
        ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
        if (len > 0) {
            exe_path[len] = '\0';
            char *slash = strrchr(exe_path, '/');
            if (slash) {
                size_t dir_len = (size_t)(slash - exe_path + 1);
                char so_path[1024];
                if (dir_len + strlen("libnc_cuda.so") < sizeof(so_path)) {
                    memcpy(so_path, exe_path, dir_len);
                    memcpy(so_path + dir_len, "libnc_cuda.so", strlen("libnc_cuda.so") + 1);
                    void *mod = dlopen(so_path, RTLD_NOW);
                    if (!mod)
                        mod = dlopen("libnc_cuda.so", RTLD_NOW);
                    if (mod) {
                        nc_cuda_new_device_internal = (NCCudaNewDeviceInternalFn)dlsym(mod, "nc_new_cuda_device_internal");
                        if (nc_cuda_new_device_internal) {
                            nc_cuda_loader_state = 1;
                            return;
                        }
                        dlclose(mod);
                    }
                }
            }
        }
    }
    {
        void *mod = dlopen("libnc_cuda.so", RTLD_NOW);
        if (mod) {
            nc_cuda_new_device_internal = (NCCudaNewDeviceInternalFn)dlsym(mod, "nc_new_cuda_device_internal");
            if (nc_cuda_new_device_internal) {
                nc_cuda_loader_state = 1;
                return;
            }
            dlclose(mod);
        }
    }
#endif

    nc_cuda_loader_state = -1;
}

static NCDevice *nc_cuda_backend_create(NCContext *ctx, int device_index)
{
    nc_cuda_loader_init();
    if (!nc_cuda_new_device_internal)
        return NULL;
    return nc_cuda_new_device_internal(ctx, (unsigned int)device_index);
}
