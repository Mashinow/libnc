#include <stdio.h>
#include <stdlib.h>
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

static int nc_cuda_path_is_sep(char c)
{
    return c == '\\' || c == '/';
}

static char *nc_cuda_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *copy = nc_malloc(len);
    memcpy(copy, s, len);
    return copy;
}

#ifdef _WIN32
static int nc_cuda_file_exists(const char *path)
{
    DWORD attr = GetFileAttributesA(path);
    return attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY);
}

static void nc_cuda_join_path(char *dst, size_t dst_size, const char *dir, const char *leaf)
{
    size_t len = 0;
    if (dir && *dir) {
        len = strlen(dir);
        if (len >= dst_size)
            len = dst_size - 1;
        memcpy(dst, dir, len);
        if (len > 0 && !nc_cuda_path_is_sep(dst[len - 1]) && len + 1 < dst_size)
            dst[len++] = '\\';
    }
    if (leaf && *leaf) {
        size_t leaf_len = strlen(leaf);
        if (len + leaf_len >= dst_size)
            leaf_len = dst_size - len - 1;
        memcpy(dst + len, leaf, leaf_len);
        len += leaf_len;
    }
    dst[len] = '\0';
}

static void nc_cuda_copy_dirname(char *dst, size_t dst_size, const char *path)
{
    size_t len = strlen(path);
    while (len > 0 && nc_cuda_path_is_sep(path[len - 1]))
        len--;
    if (len >= dst_size)
        len = dst_size - 1;
    memcpy(dst, path, len);
    dst[len] = '\0';
}

static void nc_cuda_try_preload_pattern_in_dir(const char *dir, const char *pattern)
{
    char search[1024];
    char file[1024];
    WIN32_FIND_DATAA fd;
    HANDLE h;

    if (!dir || !*dir)
        return;

    nc_cuda_join_path(search, sizeof(search), dir, pattern);
    h = FindFirstFileA(search, &fd);
    if (h == INVALID_HANDLE_VALUE)
        return;

    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;
        nc_cuda_join_path(file, sizeof(file), dir, fd.cFileName);
        LoadLibraryA(file);
    } while (FindNextFileA(h, &fd));
    FindClose(h);
}

static void nc_cuda_preload_runtime_dir(const char *dir)
{
    nc_cuda_try_preload_pattern_in_dir(dir, "cudart*.dll");
    nc_cuda_try_preload_pattern_in_dir(dir, "cublas*.dll");
    nc_cuda_try_preload_pattern_in_dir(dir, "cublasLt*.dll");
}

static void nc_cuda_try_backend_file(const char *path)
{
    HMODULE mod;

    if (!path || !*path)
        return;
    if (!nc_cuda_file_exists(path))
        return;

    mod = LoadLibraryA(path);
    if (!mod)
        return;

    nc_cuda_new_device_internal =
        (NCCudaNewDeviceInternalFn)GetProcAddress(mod, "nc_new_cuda_device_internal");
    if (nc_cuda_new_device_internal) {
        nc_cuda_loader_state = 1;
        return;
    }
    FreeLibrary(mod);
}

static void nc_cuda_try_backend_from_dir(const char *dir)
{
    char path[1024];
    HMODULE mod;

    if (!dir || !*dir)
        return;

    nc_cuda_preload_runtime_dir(dir);
    nc_cuda_join_path(path, sizeof(path), dir, "libnc_cuda.dll");
    nc_cuda_try_backend_file(path);
    if (nc_cuda_new_device_internal)
        return;
    nc_cuda_try_backend_file("libnc_cuda.dll");
}

static void nc_cuda_try_backend_from_env_path(const char *env_name)
{
    const char *value = getenv(env_name);
    if (!value || !*value)
        return;
    if (nc_cuda_file_exists(value)) {
        nc_cuda_try_backend_file(value);
        return;
    }
    nc_cuda_try_backend_from_dir(value);
}

static void nc_cuda_scan_env_dirs(void)
{
    const char *path_env = getenv("PATH");
    if (path_env) {
        char *tmp = nc_cuda_strdup(path_env);
        char *cursor = tmp;
        while (cursor && *cursor) {
            char *next = cursor;
            while (*next && *next != ';')
                next++;
            if (next != cursor) {
                char saved = *next;
                *next = '\0';
                nc_cuda_try_backend_from_dir(cursor);
                *next = saved;
                if (nc_cuda_new_device_internal)
                    break;
            }
            cursor = *next ? next + 1 : next;
        }
        nc_free(tmp);
        if (nc_cuda_new_device_internal)
            return;
    }

    {
        const char *override_envs[] = {
            "LIBNC_CUDA_DLL",
            "LIBNC_CUDA_DIR",
            "LIBNC_CUDA_HOME",
            "CUDA_PATH",
            NULL
        };
        for (size_t i = 0; override_envs[i]; i++) {
            const char *value = getenv(override_envs[i]);
            if (!value || !*value)
                continue;
            if (nc_cuda_file_exists(value))
                nc_cuda_try_backend_file(value);
            else
                nc_cuda_try_backend_from_dir(value);
            if (nc_cuda_new_device_internal)
                return;
            if (strcmp(override_envs[i], "CUDA_PATH") == 0) {
                char bin_dir[1024];
                nc_cuda_join_path(bin_dir, sizeof(bin_dir), value, "bin");
                nc_cuda_try_backend_from_dir(bin_dir);
                if (nc_cuda_new_device_internal)
                    return;
            }
        }
    }

    {
        LPCH env = GetEnvironmentStringsA();
        if (!env)
            return;
        for (LPCH p = env; *p; ) {
            char *eq = strchr(p, '=');
            if (eq) {
                size_t key_len = (size_t)(eq - p);
                if (key_len >= 9 && !strncmp(p, "CUDA_PATH", 9)) {
                    const char *value = eq + 1;
                    if (*value) {
                        if (nc_cuda_file_exists(value))
                            nc_cuda_try_backend_file(value);
                        else {
                            char bin_dir[1024];
                            nc_cuda_join_path(bin_dir, sizeof(bin_dir), value, "bin");
                            nc_cuda_try_backend_from_dir(bin_dir);
                            if (nc_cuda_new_device_internal) {
                                FreeEnvironmentStringsA(env);
                                return;
                            }
                            nc_cuda_try_backend_from_dir(value);
                        }
                        if (nc_cuda_new_device_internal) {
                            FreeEnvironmentStringsA(env);
                            return;
                        }
                    }
                }
            }
            p += strlen(p) + 1;
        }
        FreeEnvironmentStringsA(env);
    }
}
#endif

static void nc_cuda_loader_init(void)
{
    if (nc_cuda_loader_state != 0)
        return;

#ifdef _WIN32
    {
        nc_cuda_try_backend_from_env_path("LIBNC_CUDA_DLL");
        if (nc_cuda_new_device_internal) {
            nc_cuda_loader_state = 1;
            return;
        }
        nc_cuda_try_backend_from_env_path("LIBNC_CUDA_DIR");
        if (nc_cuda_new_device_internal) {
            nc_cuda_loader_state = 1;
            return;
        }
        nc_cuda_try_backend_from_env_path("LIBNC_CUDA_HOME");
        if (nc_cuda_new_device_internal) {
            nc_cuda_loader_state = 1;
            return;
        }

        char exe_path[1024];
        DWORD len = GetModuleFileNameA(NULL, exe_path, sizeof(exe_path));
        if (len > 0 && len < sizeof(exe_path)) {
            char dir[1024];
            nc_cuda_copy_dirname(dir, sizeof(dir), exe_path);
            nc_cuda_try_backend_from_dir(dir);
            if (nc_cuda_new_device_internal) {
                nc_cuda_loader_state = 1;
                return;
            }
        }
    }
    nc_cuda_try_backend_from_dir(".");
    if (nc_cuda_new_device_internal) {
        nc_cuda_loader_state = 1;
        return;
    }
    nc_cuda_scan_env_dirs();
#else
    {
        char exe_path[1024];
        ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
        if (len > 0) {
            exe_path[len] = '\0';
            char dir[1024];
            nc_cuda_copy_dirname(dir, sizeof(dir), exe_path);
            {
                char so_path[1024];
                snprintf(so_path, sizeof(so_path), "%s/%s", dir, "libnc_cuda.so");
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
