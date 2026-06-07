#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef int cudaError_t;
typedef int cublasStatus_t;
typedef void *cublasHandle_t;

enum {
    CUDA_SUCCESS = 0,
    CUDART_MEMCPY_HOST_TO_DEVICE = 1,
    CUDART_MEMCPY_DEVICE_TO_HOST = 2,
};

typedef cudaError_t (WINAPI *cudaGetDeviceCountFn)(int *);
typedef cudaError_t (WINAPI *cudaSetDeviceFn)(int);
typedef cudaError_t (WINAPI *cudaMallocFn)(void **, size_t);
typedef cudaError_t (WINAPI *cudaMemcpyFn)(void *, const void *, size_t, int);
typedef cudaError_t (WINAPI *cudaFreeFn)(void *);
typedef cudaError_t (WINAPI *cudaDeviceSynchronizeFn)(void);

typedef cublasStatus_t (WINAPI *cublasCreate_v2Fn)(cublasHandle_t *);
typedef cublasStatus_t (WINAPI *cublasDestroy_v2Fn)(cublasHandle_t);
typedef cublasStatus_t (WINAPI *cublasSaxpy_v2Fn)(cublasHandle_t, int, const float *, const float *, int, float *, int);

static void fail(const char *msg)
{
    fprintf(stderr, "CUDA smoke fail: %s\n", msg);
    exit(1);
}

static void *get_proc(HMODULE mod, const char *name)
{
    void *p = (void *)GetProcAddress(mod, name);
    if (!p) {
        fprintf(stderr, "missing symbol: %s\n", name);
        exit(1);
    }
    return p;
}

static int path_is_sep(char c)
{
    return c == '\\' || c == '/';
}

static void copy_dirname(char *dst, size_t dst_size, const char *path)
{
    size_t len = strlen(path);
    while (len > 0 && path_is_sep(path[len - 1]))
        len--;
    if (len >= dst_size)
        len = dst_size - 1;
    memcpy(dst, path, len);
    dst[len] = '\0';
}

static void join_path(char *dst, size_t dst_size, const char *dir, const char *leaf)
{
    size_t len = 0;
    if (dir && *dir) {
        len = strlen(dir);
        if (len >= dst_size)
            len = dst_size - 1;
        memcpy(dst, dir, len);
        if (len > 0 && !path_is_sep(dst[len - 1]) && len + 1 < dst_size)
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

static HMODULE load_first_dll_matching_dir(const char *dir, const char *pattern)
{
    char search[1024];
    char path[1024];
    WIN32_FIND_DATAA fd;
    HANDLE h;
    if (!dir || !*dir)
        return NULL;
    join_path(search, sizeof(search), dir, pattern);
    h = FindFirstFileA(search, &fd);
    if (h == INVALID_HANDLE_VALUE)
        return NULL;
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;
        join_path(path, sizeof(path), dir, fd.cFileName);
        HMODULE mod = LoadLibraryA(path);
        if (mod) {
            FindClose(h);
            return mod;
        }
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    return NULL;
}

static HMODULE load_dll_from_paths(const char *name, const char *patterns[])
{
    char exe_path[1024];
    DWORD len = GetModuleFileNameA(NULL, exe_path, sizeof(exe_path));
    if (len > 0 && len < sizeof(exe_path)) {
        char dir[1024];
        copy_dirname(dir, sizeof(dir), exe_path);
        for (size_t i = 0; patterns[i]; i++) {
            HMODULE mod = load_first_dll_matching_dir(dir, patterns[i]);
            if (mod)
                return mod;
        }
    }

    for (size_t i = 0; patterns[i]; i++) {
        HMODULE mod = load_first_dll_matching_dir(".", patterns[i]);
        if (mod)
            return mod;
    }

    const char *path_env = getenv("PATH");
    if (path_env) {
        size_t len_env = strlen(path_env) + 1;
        char *tmp = (char *)malloc(len_env);
        memcpy(tmp, path_env, len_env);
        char *cursor = tmp;
        while (cursor && *cursor) {
            char *next = cursor;
            while (*next && *next != ';')
                next++;
            char saved = *next;
            *next = '\0';
            for (size_t i = 0; patterns[i]; i++) {
                HMODULE mod = load_first_dll_matching_dir(cursor, patterns[i]);
                if (mod) {
                    free(tmp);
                    return mod;
                }
            }
            *next = saved;
            cursor = *next ? next + 1 : next;
        }
        free(tmp);
    }

    LPCH env = GetEnvironmentStringsA();
    if (env) {
        for (LPCH cur = env; *cur; cur += strlen(cur) + 1) {
            const char *eq = strchr(cur, '=');
            if (!eq)
                continue;
            size_t key_len = (size_t)(eq - cur);
            if (key_len < 9)
                continue;
            if (strncmp(cur, "CUDA_PATH", 9) != 0)
                continue;
            if (key_len > 9) {
                char ch = cur[9];
                if (ch != '_' && ch != '\0')
                    continue;
            }
            const char *base = eq + 1;
            if (!base || !*base)
                continue;
            char bin_dir[1024];
            join_path(bin_dir, sizeof(bin_dir), base, "bin");
            for (size_t i = 0; patterns[i]; i++) {
                HMODULE mod = load_first_dll_matching_dir(bin_dir, patterns[i]);
                if (mod) {
                    FreeEnvironmentStringsA(env);
                    return mod;
                }
            }
        }
        FreeEnvironmentStringsA(env);
    }

    (void)name;
    return NULL;
}

static double qpc_now(void)
{
    LARGE_INTEGER freq, cur;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cur);
    return (double)cur.QuadPart / (double)freq.QuadPart;
}

int main(void)
{
    const char *cudart_patterns[] = { "cudart*.dll", NULL };
    const char *cublas_patterns[] = { "cublas*.dll", NULL };
    HMODULE cudart = load_dll_from_paths("cudart", cudart_patterns);
    HMODULE cublas = load_dll_from_paths("cublas", cublas_patterns);
    if (!cudart || !cublas)
        fail("could not locate cudart/cublas DLLs");

    cudaGetDeviceCountFn cudaGetDeviceCount = (cudaGetDeviceCountFn)get_proc(cudart, "cudaGetDeviceCount");
    cudaSetDeviceFn cudaSetDevice = (cudaSetDeviceFn)get_proc(cudart, "cudaSetDevice");
    cudaMallocFn cudaMalloc = (cudaMallocFn)get_proc(cudart, "cudaMalloc");
    cudaMemcpyFn cudaMemcpy = (cudaMemcpyFn)get_proc(cudart, "cudaMemcpy");
    cudaFreeFn cudaFree = (cudaFreeFn)get_proc(cudart, "cudaFree");
    cudaDeviceSynchronizeFn cudaDeviceSynchronize = (cudaDeviceSynchronizeFn)get_proc(cudart, "cudaDeviceSynchronize");

    cublasCreate_v2Fn cublasCreate_v2 = (cublasCreate_v2Fn)get_proc(cublas, "cublasCreate_v2");
    cublasDestroy_v2Fn cublasDestroy_v2 = (cublasDestroy_v2Fn)get_proc(cublas, "cublasDestroy_v2");
    cublasSaxpy_v2Fn cublasSaxpy_v2 = (cublasSaxpy_v2Fn)get_proc(cublas, "cublasSaxpy_v2");

    int ndev = 0;
    if (cudaGetDeviceCount(&ndev) != CUDA_SUCCESS)
        fail("cudaGetDeviceCount");
    if (ndev <= 0)
        fail("no CUDA devices detected");
    if (cudaSetDevice(0) != CUDA_SUCCESS)
        fail("cudaSetDevice");

    const int n = 1 << 22;
    const int reps = 64;
    const size_t bytes = (size_t)n * sizeof(float);

    float *ha = (float *)malloc(bytes);
    float *hy = (float *)malloc(bytes);
    float *href = (float *)malloc(bytes);
    if (!ha || !hy || !href)
        fail("host alloc");

    for (int i = 0; i < n; i++) {
        ha[i] = 1.0f + 0.001f * (float)i;
        hy[i] = 2.0f - 0.0005f * (float)i;
        href[i] = hy[i];
    }

    float *da = NULL;
    float *dy = NULL;
    if (cudaMalloc((void **)&da, bytes) != CUDA_SUCCESS)
        fail("cudaMalloc a");
    if (cudaMalloc((void **)&dy, bytes) != CUDA_SUCCESS)
        fail("cudaMalloc y");
    if (cudaMemcpy(da, ha, bytes, CUDART_MEMCPY_HOST_TO_DEVICE) != CUDA_SUCCESS)
        fail("cudaMemcpy a");
    if (cudaMemcpy(dy, hy, bytes, CUDART_MEMCPY_HOST_TO_DEVICE) != CUDA_SUCCESS)
        fail("cudaMemcpy y");

    cublasHandle_t h = NULL;
    if (cublasCreate_v2(&h) != 0)
        fail("cublasCreate_v2");

    float alpha = 0.5f;
    double t0 = qpc_now();
    for (int i = 0; i < reps; i++) {
        if (cublasSaxpy_v2(h, n, &alpha, da, 1, dy, 1) != 0)
            fail("cublasSaxpy_v2");
    }
    if (cudaDeviceSynchronize() != CUDA_SUCCESS)
        fail("cudaDeviceSynchronize");
    double t1 = qpc_now();

    if (cudaMemcpy(hy, dy, bytes, CUDART_MEMCPY_DEVICE_TO_HOST) != CUDA_SUCCESS)
        fail("cudaMemcpy back");

    double cpu_t0 = qpc_now();
    for (int rep = 0; rep < reps; rep++) {
        for (int i = 0; i < n; i++)
            href[i] += alpha * ha[i];
    }
    double cpu_t1 = qpc_now();

    double max_err = 0.0;
    for (int i = 0; i < n; i++) {
        double err = fabs((double)hy[i] - (double)href[i]);
        if (err > max_err)
            max_err = err;
    }

    printf("CUDA smoke success: devices=%d max_err=%g\n", ndev, max_err);
    printf("CUDA saxpy time: gpu=%0.6f s cpu=%0.6f s\n", t1 - t0, cpu_t1 - cpu_t0);
    if ((t1 - t0) > 0.0)
        printf("speed ratio cpu/gpu=%0.3f\n", (cpu_t1 - cpu_t0) / (t1 - t0));

    cublasDestroy_v2(h);
    cudaFree(dy);
    cudaFree(da);
    free(href);
    free(hy);
    free(ha);
    return 0;
}
