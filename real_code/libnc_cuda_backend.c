#include "libnc.h"
#include "libnc_internal.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifndef _WIN32
#error "libnc_cuda_backend.c currently targets Windows loader/runtime discovery"
#endif

#ifndef LIBNC_CUDA_API
#define LIBNC_CUDA_API __declspec(dllexport)
#endif

typedef int CUresult;
typedef int CUdevice;
typedef void *CUcontext;
typedef void *CUmodule;
typedef void *CUfunction;
typedef unsigned long long CUdeviceptr;

typedef int cublasStatus_t;
typedef void *cublasHandle_t;

typedef int nvrtcResult;
typedef void *nvrtcProgram;

enum {
    CUDA_SUCCESS = 0,
    CUBLAS_OP_N = 0,
    CUBLAS_OP_T = 1,
};

typedef CUresult (WINAPI *p_cuInit)(unsigned int);
typedef CUresult (WINAPI *p_cuDeviceGetCount)(int *);
typedef CUresult (WINAPI *p_cuDeviceGet)(CUdevice *, int);
typedef CUresult (WINAPI *p_cuCtxCreate_v2)(CUcontext *, unsigned int, CUdevice);
typedef CUresult (WINAPI *p_cuCtxSetCurrent)(CUcontext);
typedef CUresult (WINAPI *p_cuCtxDestroy_v2)(CUcontext);
typedef CUresult (WINAPI *p_cuCtxSynchronize)(void);
typedef CUresult (WINAPI *p_cuMemAlloc_v2)(CUdeviceptr *, size_t);
typedef CUresult (WINAPI *p_cuMemFree_v2)(CUdeviceptr);
typedef CUresult (WINAPI *p_cuMemcpyHtoD_v2)(CUdeviceptr, const void *, size_t);
typedef CUresult (WINAPI *p_cuMemcpyDtoH_v2)(void *, CUdeviceptr, size_t);
typedef CUresult (WINAPI *p_cuModuleLoadData)(CUmodule *, const void *);
typedef CUresult (WINAPI *p_cuModuleUnload)(CUmodule);
typedef CUresult (WINAPI *p_cuModuleGetFunction)(CUfunction *, CUmodule, const char *);
typedef CUresult (WINAPI *p_cuLaunchKernel)(
    CUfunction,
    unsigned int, unsigned int, unsigned int,
    unsigned int, unsigned int, unsigned int,
    unsigned int, void *, void **, void **);

typedef cublasStatus_t (WINAPI *p_cublasCreate_v2)(cublasHandle_t *);
typedef cublasStatus_t (WINAPI *p_cublasDestroy_v2)(cublasHandle_t);
typedef cublasStatus_t (WINAPI *p_cublasSgemm)(
    cublasHandle_t, int, int, int, int, int,
    const float *, const float *, int,
    const float *, int,
    const float *, float *, int);

typedef nvrtcResult (WINAPI *p_nvrtcVersion)(int *, int *);
typedef nvrtcResult (WINAPI *p_nvrtcCreateProgram)(
    nvrtcProgram *, const char *, const char *, int, const char *const *, const char *const *);
typedef nvrtcResult (WINAPI *p_nvrtcCompileProgram)(nvrtcProgram, int, const char *const *);
typedef nvrtcResult (WINAPI *p_nvrtcGetPTXSize)(nvrtcProgram, size_t *);
typedef nvrtcResult (WINAPI *p_nvrtcGetPTX)(nvrtcProgram, char *);
typedef nvrtcResult (WINAPI *p_nvrtcGetProgramLogSize)(nvrtcProgram, size_t *);
typedef nvrtcResult (WINAPI *p_nvrtcGetProgramLog)(nvrtcProgram, char *);
typedef nvrtcResult (WINAPI *p_nvrtcDestroyProgram)(nvrtcProgram *);
typedef const char * (WINAPI *p_nvrtcGetErrorString)(nvrtcResult);

typedef struct NCCudaFns {
    HMODULE nvcuda;
    HMODULE cublas;
    HMODULE nvrtc;
    p_cuInit cuInit;
    p_cuDeviceGetCount cuDeviceGetCount;
    p_cuDeviceGet cuDeviceGet;
    p_cuCtxCreate_v2 cuCtxCreate_v2;
    p_cuCtxSetCurrent cuCtxSetCurrent;
    p_cuCtxDestroy_v2 cuCtxDestroy_v2;
    p_cuCtxSynchronize cuCtxSynchronize;
    p_cuMemAlloc_v2 cuMemAlloc_v2;
    p_cuMemFree_v2 cuMemFree_v2;
    p_cuMemcpyHtoD_v2 cuMemcpyHtoD_v2;
    p_cuMemcpyDtoH_v2 cuMemcpyDtoH_v2;
    p_cuModuleLoadData cuModuleLoadData;
    p_cuModuleUnload cuModuleUnload;
    p_cuModuleGetFunction cuModuleGetFunction;
    p_cuLaunchKernel cuLaunchKernel;
    p_cublasCreate_v2 cublasCreate_v2;
    p_cublasDestroy_v2 cublasDestroy_v2;
    p_cublasSgemm cublasSgemm;
    p_nvrtcVersion nvrtcVersion;
    p_nvrtcCreateProgram nvrtcCreateProgram;
    p_nvrtcCompileProgram nvrtcCompileProgram;
    p_nvrtcGetPTXSize nvrtcGetPTXSize;
    p_nvrtcGetPTX nvrtcGetPTX;
    p_nvrtcGetProgramLogSize nvrtcGetProgramLogSize;
    p_nvrtcGetProgramLog nvrtcGetProgramLog;
    p_nvrtcDestroyProgram nvrtcDestroyProgram;
    p_nvrtcGetErrorString nvrtcGetErrorString;
} NCCudaFns;

typedef struct NCCudaState {
    NCCudaFns fns;
    CUcontext ctx;
    CUdevice device;
    cublasHandle_t blas;
    CUmodule module;
    CUfunction binary_fn;
    CUfunction unary_fn;
    CUfunction matmul_fn;
    CUfunction convert_fn;
    CUfunction masked_fill_fn;
    CUfunction rnd_unif_fn;
    CUfunction rnd_dropout_fn;
    CUfunction reduce_sum_fn;
    CUfunction reduce_sum_sqr_fn;
    CUfunction softmax_fn;
    CUfunction layer_norm_fn;
    CUdeviceptr scratch_a;
    CUdeviceptr scratch_b;
    CUdeviceptr scratch_c;
    size_t scratch_bytes;
    int device_index;
} NCCudaState;

static int cuda_path_is_sep(char c)
{
    return c == '\\' || c == '/';
}

static char *cuda_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *p = nc_malloc(len);
    memcpy(p, s, len);
    return p;
}

static void path_join(char *dst, size_t dst_size, const char *dir, const char *leaf)
{
    size_t len = 0;
    if (dir && *dir) {
        len = strlen(dir);
        if (len >= dst_size)
            len = dst_size - 1;
        memcpy(dst, dir, len);
        if (len > 0 && !cuda_path_is_sep(dst[len - 1]) && len + 1 < dst_size)
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

static void copy_dirname(char *dst, size_t dst_size, const char *path)
{
    size_t len = strlen(path);
    while (len > 0 && cuda_path_is_sep(path[len - 1]))
        len--;
    if (len >= dst_size)
        len = dst_size - 1;
    memcpy(dst, path, len);
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
    path_join(search, sizeof(search), dir, pattern);
    h = FindFirstFileA(search, &fd);
    if (h == INVALID_HANDLE_VALUE)
        return NULL;
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;
        path_join(path, sizeof(path), dir, fd.cFileName);
        HMODULE mod = LoadLibraryA(path);
        if (mod) {
            FindClose(h);
            return mod;
        }
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    return NULL;
}

static HMODULE load_dll_from_search_paths(const char *patterns[])
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

    {
        LPCH env = GetEnvironmentStringsA();
        if (env) {
            for (LPCH cur = env; *cur; cur += strlen(cur) + 1) {
                const char *eq = strchr(cur, '=');
                if (!eq)
                    continue;
                size_t key_len = (size_t)(eq - cur);
                if (key_len < 9 || strncmp(cur, "CUDA_PATH", 9) != 0)
                    continue;
                const char *base = eq + 1;
                if (!base || !*base)
                    continue;
                char bin_dir[1024];
                path_join(bin_dir, sizeof(bin_dir), base, "bin");
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
    }

    return NULL;
}

static void *load_sym(HMODULE mod, const char *name)
{
    void *p = (void *)GetProcAddress(mod, name);
    if (!p) {
        fprintf(stderr, "libnc_cuda: missing symbol %s\n", name);
    }
    return p;
}

static int cuda_load_fns(NCCudaFns *f)
{
    const char *nvcuda_patterns[] = { "nvcuda.dll", NULL };
    const char *cublas_patterns[] = { "cublas64_*.dll", "cublas.dll", NULL };
    const char *nvrtc_patterns[] = { "nvrtc64_*.dll", "nvrtc.dll", NULL };

    memset(f, 0, sizeof(*f));
    f->nvcuda = load_dll_from_search_paths(nvcuda_patterns);
    f->cublas = load_dll_from_search_paths(cublas_patterns);
    f->nvrtc = load_dll_from_search_paths(nvrtc_patterns);
    if (!f->nvcuda || !f->nvrtc)
        return 0;

    f->cuInit = (p_cuInit)load_sym(f->nvcuda, "cuInit");
    f->cuDeviceGetCount = (p_cuDeviceGetCount)load_sym(f->nvcuda, "cuDeviceGetCount");
    f->cuDeviceGet = (p_cuDeviceGet)load_sym(f->nvcuda, "cuDeviceGet");
    f->cuCtxCreate_v2 = (p_cuCtxCreate_v2)load_sym(f->nvcuda, "cuCtxCreate_v2");
    f->cuCtxSetCurrent = (p_cuCtxSetCurrent)load_sym(f->nvcuda, "cuCtxSetCurrent");
    f->cuCtxDestroy_v2 = (p_cuCtxDestroy_v2)load_sym(f->nvcuda, "cuCtxDestroy_v2");
    f->cuCtxSynchronize = (p_cuCtxSynchronize)load_sym(f->nvcuda, "cuCtxSynchronize");
    f->cuMemAlloc_v2 = (p_cuMemAlloc_v2)load_sym(f->nvcuda, "cuMemAlloc_v2");
    f->cuMemFree_v2 = (p_cuMemFree_v2)load_sym(f->nvcuda, "cuMemFree_v2");
    f->cuMemcpyHtoD_v2 = (p_cuMemcpyHtoD_v2)load_sym(f->nvcuda, "cuMemcpyHtoD_v2");
    f->cuMemcpyDtoH_v2 = (p_cuMemcpyDtoH_v2)load_sym(f->nvcuda, "cuMemcpyDtoH_v2");
    f->cuModuleLoadData = (p_cuModuleLoadData)load_sym(f->nvcuda, "cuModuleLoadData");
    f->cuModuleUnload = (p_cuModuleUnload)load_sym(f->nvcuda, "cuModuleUnload");
    f->cuModuleGetFunction = (p_cuModuleGetFunction)load_sym(f->nvcuda, "cuModuleGetFunction");
    f->cuLaunchKernel = (p_cuLaunchKernel)load_sym(f->nvcuda, "cuLaunchKernel");
    if (f->cublas) {
        f->cublasCreate_v2 = (p_cublasCreate_v2)load_sym(f->cublas, "cublasCreate_v2");
        f->cublasDestroy_v2 = (p_cublasDestroy_v2)load_sym(f->cublas, "cublasDestroy_v2");
        f->cublasSgemm = (p_cublasSgemm)load_sym(f->cublas, "cublasSgemm");
    }
    f->nvrtcVersion = (p_nvrtcVersion)load_sym(f->nvrtc, "nvrtcVersion");
    f->nvrtcCreateProgram = (p_nvrtcCreateProgram)load_sym(f->nvrtc, "nvrtcCreateProgram");
    f->nvrtcCompileProgram = (p_nvrtcCompileProgram)load_sym(f->nvrtc, "nvrtcCompileProgram");
    f->nvrtcGetPTXSize = (p_nvrtcGetPTXSize)load_sym(f->nvrtc, "nvrtcGetPTXSize");
    f->nvrtcGetPTX = (p_nvrtcGetPTX)load_sym(f->nvrtc, "nvrtcGetPTX");
    f->nvrtcGetProgramLogSize = (p_nvrtcGetProgramLogSize)load_sym(f->nvrtc, "nvrtcGetProgramLogSize");
    f->nvrtcGetProgramLog = (p_nvrtcGetProgramLog)load_sym(f->nvrtc, "nvrtcGetProgramLog");
    f->nvrtcDestroyProgram = (p_nvrtcDestroyProgram)load_sym(f->nvrtc, "nvrtcDestroyProgram");
    f->nvrtcGetErrorString = (p_nvrtcGetErrorString)load_sym(f->nvrtc, "nvrtcGetErrorString");

    if (!f->cuInit || !f->cuDeviceGetCount || !f->cuDeviceGet || !f->cuCtxCreate_v2 ||
        !f->cuCtxSetCurrent || !f->cuCtxDestroy_v2 || !f->cuCtxSynchronize || !f->cuMemAlloc_v2 || !f->cuMemFree_v2 ||
        !f->cuMemcpyHtoD_v2 || !f->cuMemcpyDtoH_v2 || !f->cuModuleLoadData || !f->cuModuleUnload ||
        !f->cuModuleGetFunction || !f->cuLaunchKernel || !f->nvrtcVersion || !f->nvrtcCreateProgram || !f->nvrtcCompileProgram ||
        !f->nvrtcGetPTXSize || !f->nvrtcGetPTX || !f->nvrtcGetProgramLogSize ||
        !f->nvrtcGetProgramLog || !f->nvrtcDestroyProgram || !f->nvrtcGetErrorString) {
        return 0;
    }
    return 1;
}

static const char *cuda_kernel_source =
"extern \"C\" __global__ void nc_cuda_binary_f32(int op, const float *a, const float *b, float *y, size_t n)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    float av = a[i];\n"
"    float bv = b[i];\n"
"    float rv = 0.0f;\n"
"    switch (op) {\n"
"    case 3: rv = av + bv; break;\n"
"    case 4: rv = av - bv; break;\n"
"    case 5: rv = av * bv; break;\n"
"    case 6: rv = av / bv; break;\n"
"    case 9: rv = av < bv ? av : bv; break;\n"
"    case 10: rv = av > bv ? av : bv; break;\n"
"    default: rv = av + bv; break;\n"
"    }\n"
"    y[i] = rv;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_unary_f32(int op, const float *x, float *y, size_t n)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    float v = x[i];\n"
"    switch (op) {\n"
"    case 7: v = -v; break;\n"
"    case 8: v = 1.0f / v; break;\n"
"    case 13: v = 1.0f / (1.0f + expf(-v)); break;\n"
"    case 14: v = tanhf(v); break;\n"
"    case 15: v = v > 0.0f ? v : 0.0f; break;\n"
"    case 16: v = 0.5f * v * (1.0f + tanhf(0.7978845608f * (v + 0.044715f * v * v * v))); break;\n"
"    case 17: v = logf(v); break;\n"
"    default: break;\n"
"    }\n"
"    y[i] = v;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_matmul_f32(int use_colmajor, const float *w, const float *x, const float *y0, float *y, int wm, int wk, int xn)\n"
"{\n"
"    int col = (int)blockIdx.x * (int)blockDim.x + (int)threadIdx.x;\n"
"    int row = (int)blockIdx.y * (int)blockDim.y + (int)threadIdx.y;\n"
"    if (use_colmajor) {\n"
"        if (row >= wm || col >= xn)\n"
"            return;\n"
"        float acc = y0 ? y0[row + col * wm] : 0.0f;\n"
"        for (int k = 0; k < wk; k++) {\n"
"            float a = w[row + k * wm];\n"
"            float b = x[k + col * wk];\n"
"            acc += a * b;\n"
"        }\n"
"        y[row + col * wm] = acc;\n"
"    } else {\n"
"        if (row >= wm || col >= xn)\n"
"            return;\n"
"        float acc = y0 ? y0[row * xn + col] : 0.0f;\n"
"        for (int k = 0; k < wk; k++) {\n"
"            float a = w[row * wk + k];\n"
"            float b = x[k * xn + col];\n"
"            acc += a * b;\n"
"        }\n"
"        y[row * xn + col] = acc;\n"
"    }\n"
"}\n"
"__device__ __forceinline__ unsigned short nc_cuda_f32_to_bf16(float v)\n"
"{\n"
"    unsigned int u = __float_as_uint(v);\n"
"    u += 0x7fffu + ((u >> 16) & 1u);\n"
"    return (unsigned short)(u >> 16);\n"
"}\n"
"__device__ __forceinline__ float nc_cuda_bf16_to_f32(unsigned short h)\n"
"{\n"
"    return __uint_as_float((unsigned int)h << 16);\n"
"}\n"
"__device__ __forceinline__ float nc_cuda_load_f32(const void *ptr, int type)\n"
"{\n"
"    switch (type) {\n"
"    case 0: return *(const float *)ptr;\n"
"    case 1: return nc_cuda_bf16_to_f32(*(const unsigned short *)ptr);\n"
"    case 2: {\n"
"        unsigned short h = *(const unsigned short *)ptr;\n"
"        unsigned int s = (h >> 15) & 1u;\n"
"        unsigned int e = (h >> 10) & 0x1fu;\n"
"        unsigned int m = h & 0x3ffu;\n"
"        unsigned int f;\n"
"        if (e == 0) {\n"
"            if (m == 0) {\n"
"                f = s << 31;\n"
"            } else {\n"
"                e = 1;\n"
"                while ((m & 0x400u) == 0) {\n"
"                    m <<= 1;\n"
"                    e--;\n"
"                }\n"
"                m &= 0x3ffu;\n"
"                f = (s << 31) | ((e + 127u - 15u) << 23) | (m << 13);\n"
"            }\n"
"        } else if (e == 31u) {\n"
"            f = (s << 31) | 0x7f800000u | (m << 13);\n"
"        } else {\n"
"            f = (s << 31) | ((e + 127u - 15u) << 23) | (m << 13);\n"
"        }\n"
"        return __uint_as_float(f);\n"
"    }\n"
"    case 3: return (float)*(const signed char *)ptr;\n"
"    case 4: return (float)*(const short *)ptr;\n"
"    case 5: return (float)*(const int *)ptr;\n"
"    default: return 0.0f;\n"
"    }\n"
"}\n"
"__device__ __forceinline__ void nc_cuda_store_f32(void *ptr, int type, float v)\n"
"{\n"
"    switch (type) {\n"
"    case 0:\n"
"        *(float *)ptr = v;\n"
"        break;\n"
"    case 1:\n"
"        *(unsigned short *)ptr = nc_cuda_f32_to_bf16(v);\n"
"        break;\n"
"    case 2: {\n"
"        unsigned int x = __float_as_uint(v);\n"
"        unsigned int sign = (x >> 16) & 0x8000u;\n"
"        int exp = (int)((x >> 23) & 0xffu) - 127 + 15;\n"
"        unsigned int mant = x & 0x7fffffu;\n"
"        unsigned short out;\n"
"        if (exp <= 0) {\n"
"            if (exp < -10) {\n"
"                out = (unsigned short)sign;\n"
"            } else {\n"
"                mant = (mant | 0x800000u) >> (1 - exp);\n"
"                out = (unsigned short)(sign | ((mant + 0x1000u) >> 13));\n"
"            }\n"
"        } else if (exp >= 31) {\n"
"            out = (unsigned short)(sign | 0x7c00u | (mant ? 0x200u : 0));\n"
"        } else {\n"
"            out = (unsigned short)(sign | ((unsigned int)exp << 10) | ((mant + 0x1000u) >> 13));\n"
"        }\n"
"        *(unsigned short *)ptr = out;\n"
"        break;\n"
"    }\n"
"    case 3:\n"
"        *(signed char *)ptr = (signed char)lrintf(v);\n"
"        break;\n"
"    case 4:\n"
"        *(short *)ptr = (short)lrintf(v);\n"
"        break;\n"
"    case 5:\n"
"        *(int *)ptr = (int)lrintf(v);\n"
"        break;\n"
"    }\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_convert(const void *src, void *dst, int src_type, int dst_type, size_t n)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    size_t ss = (src_type == 0) ? 4 : (src_type == 1) ? 2 : (src_type == 2) ? 2 : (src_type == 3) ? 1 : (src_type == 4) ? 2 : 4;\n"
"    size_t ds = (dst_type == 0) ? 4 : (dst_type == 1) ? 2 : (dst_type == 2) ? 2 : (dst_type == 3) ? 1 : (dst_type == 4) ? 2 : 4;\n"
"    float v = nc_cuda_load_f32((const unsigned char *)src + i * ss, src_type);\n"
"    nc_cuda_store_f32((unsigned char *)dst + i * ds, dst_type, v);\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_masked_fill(const float *x, const float *mask, float *y, size_t n, float c, int mask_inv)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    float m = mask[i];\n"
"    float v = x[i];\n"
"    int pred = mask_inv ? (m == 0.0f) : (m != 0.0f);\n"
"    y[i] = pred ? c : v;\n"
"}\n"
"__device__ __forceinline__ unsigned int nc_cuda_hash_u32(unsigned int x)\n"
"{\n"
"    x ^= x >> 16;\n"
"    x *= 0x7feb352du;\n"
"    x ^= x >> 15;\n"
"    x *= 0x846ca68bu;\n"
"    x ^= x >> 16;\n"
"    return x;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_rnd_unif(float *y, size_t n, unsigned int seed, float avg, float range)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    unsigned int h = nc_cuda_hash_u32(seed ^ (unsigned int)i);\n"
"    float u = (float)((h >> 8) & 0x00ffffffu) * (1.0f / 16777216.0f);\n"
"    y[i] = avg + (u * 2.0f - 1.0f) * range;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_rnd_dropout(float *y, size_t n, unsigned int seed, float prob, float scale)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    unsigned int h = nc_cuda_hash_u32(seed ^ (unsigned int)(i * 0x9e3779b9u));\n"
"    float u = (float)((h >> 8) & 0x00ffffffu) * (1.0f / 16777216.0f);\n"
"    float v = y[i];\n"
"    y[i] = (u < prob) ? 0.0f : v * scale;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_reduce_sum(const float *x, float *y, size_t y_total, size_t collapse)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= y_total)\n"
"        return;\n"
"    float acc = y[i];\n"
"    const float *src = x + i * collapse;\n"
"    for (size_t j = 0; j < collapse; j++)\n"
"        acc += src[j];\n"
"    y[i] = acc;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_reduce_sum_sqr(const float *x, float *y, size_t n)\n"
"{\n"
"    size_t i = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;\n"
"    if (i >= n)\n"
"        return;\n"
"    float v = x[i];\n"
"    y[i] += v * v;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_softmax(const float *x, float *y, size_t outer, size_t inner)\n"
"{\n"
"    size_t row = (size_t)blockIdx.x;\n"
"    if (row >= outer)\n"
"        return;\n"
"    __shared__ float sh[256];\n"
"    float maxv = -3.402823466e+38f;\n"
"    for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x) {\n"
"        float v = x[row * inner + i];\n"
"        maxv = fmaxf(maxv, v);\n"
"    }\n"
"    sh[threadIdx.x] = maxv;\n"
"    __syncthreads();\n"
"    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {\n"
"        if (threadIdx.x < s)\n"
"            sh[threadIdx.x] = fmaxf(sh[threadIdx.x], sh[threadIdx.x + s]);\n"
"        __syncthreads();\n"
"    }\n"
"    float row_max = sh[0];\n"
"    float sum = 0.0f;\n"
"    for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x) {\n"
"        float e = expf(x[row * inner + i] - row_max);\n"
"        y[row * inner + i] = e;\n"
"        sum += e;\n"
"    }\n"
"    sh[threadIdx.x] = sum;\n"
"    __syncthreads();\n"
"    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {\n"
"        if (threadIdx.x < s)\n"
"            sh[threadIdx.x] += sh[threadIdx.x + s];\n"
"        __syncthreads();\n"
"    }\n"
"    float row_sum = sh[0];\n"
"    for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x)\n"
"        y[row * inner + i] /= row_sum;\n"
"}\n"
"extern \"C\" __global__ void nc_cuda_layer_norm(const float *x, float *y, size_t outer, size_t inner, float eps, int rms)\n"
"{\n"
"    size_t row = (size_t)blockIdx.x;\n"
"    if (row >= outer)\n"
"        return;\n"
"    __shared__ float sh[256];\n"
"    float sum = 0.0f;\n"
"    float sqsum = 0.0f;\n"
"    for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x) {\n"
"        float v = x[row * inner + i];\n"
"        sum += v;\n"
"        sqsum += v * v;\n"
"    }\n"
"    sh[threadIdx.x] = sum;\n"
"    __syncthreads();\n"
"    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {\n"
"        if (threadIdx.x < s)\n"
"            sh[threadIdx.x] += sh[threadIdx.x + s];\n"
"        __syncthreads();\n"
"    }\n"
"    float mean = sh[0] / (float)inner;\n"
"    sh[threadIdx.x] = sqsum;\n"
"    __syncthreads();\n"
"    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {\n"
"        if (threadIdx.x < s)\n"
"            sh[threadIdx.x] += sh[threadIdx.x + s];\n"
"        __syncthreads();\n"
"    }\n"
"    float var = sh[0] / (float)inner;\n"
"    if (!rms) {\n"
"        float adj = 0.0f;\n"
"        for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x) {\n"
"            float d = x[row * inner + i] - mean;\n"
"            adj += d * d;\n"
"        }\n"
"        sh[threadIdx.x] = adj;\n"
"        __syncthreads();\n"
"        for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {\n"
"            if (threadIdx.x < s)\n"
"                sh[threadIdx.x] += sh[threadIdx.x + s];\n"
"            __syncthreads();\n"
"        }\n"
"        var = sh[0] / (float)inner;\n"
"    }\n"
"    float invstd = rsqrtf(var + eps);\n"
"    for (size_t i = (size_t)threadIdx.x; i < inner; i += (size_t)blockDim.x) {\n"
"        float v = x[row * inner + i];\n"
"        if (!rms)\n"
"            v -= mean;\n"
"        y[row * inner + i] = v * invstd;\n"
"    }\n"
"}\n";

static int cuda_compile_kernels(NCCudaState *s)
{
    nvrtcProgram prog = NULL;
    const char *opts[] = { "--std=c++11", "--gpu-architecture=compute_52" };
    char logbuf[8192];
    size_t log_size = 0;
    size_t ptx_size = 0;
    char *ptx = NULL;

    if (s->fns.nvrtcCreateProgram(&prog, cuda_kernel_source, "libnc_cuda_kernels.cu", 0, NULL, NULL) != 0)
        return 0;
    if (s->fns.nvrtcCompileProgram(prog, 2, opts) != 0) {
        if (s->fns.nvrtcGetProgramLogSize(prog, &log_size) == 0 && log_size > 1) {
            if (log_size > sizeof(logbuf))
                log_size = sizeof(logbuf);
            s->fns.nvrtcGetProgramLog(prog, logbuf);
            fprintf(stderr, "libnc_cuda: nvrtc compile log:\n%.*s\n", (int)log_size, logbuf);
        }
        s->fns.nvrtcDestroyProgram(&prog);
        return 0;
    }
    if (s->fns.nvrtcGetPTXSize(prog, &ptx_size) != 0 || ptx_size == 0) {
        s->fns.nvrtcDestroyProgram(&prog);
        return 0;
    }
    ptx = (char *)malloc(ptx_size);
    if (!ptx) {
        s->fns.nvrtcDestroyProgram(&prog);
        return 0;
    }
    if (s->fns.nvrtcGetPTX(prog, ptx) != 0) {
        free(ptx);
        s->fns.nvrtcDestroyProgram(&prog);
        return 0;
    }
    s->fns.nvrtcDestroyProgram(&prog);
    if (s->fns.cuModuleLoadData(&s->module, ptx) != CUDA_SUCCESS) {
        free(ptx);
        return 0;
    }
    free(ptx);
    if (s->fns.cuModuleGetFunction(&s->binary_fn, s->module, "nc_cuda_binary_f32") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->unary_fn, s->module, "nc_cuda_unary_f32") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->matmul_fn, s->module, "nc_cuda_matmul_f32") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->convert_fn, s->module, "nc_cuda_convert") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->masked_fill_fn, s->module, "nc_cuda_masked_fill") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->rnd_unif_fn, s->module, "nc_cuda_rnd_unif") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->rnd_dropout_fn, s->module, "nc_cuda_rnd_dropout") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->reduce_sum_fn, s->module, "nc_cuda_reduce_sum") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->reduce_sum_sqr_fn, s->module, "nc_cuda_reduce_sum_sqr") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->softmax_fn, s->module, "nc_cuda_softmax") != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuModuleGetFunction(&s->layer_norm_fn, s->module, "nc_cuda_layer_norm") != CUDA_SUCCESS)
        return 0;
    return 1;
}

static int cuda_ensure_scratch(NCCudaState *s, size_t bytes)
{
    if (bytes <= s->scratch_bytes)
        return 1;
    if (s->scratch_a)
        s->fns.cuMemFree_v2(s->scratch_a);
    if (s->scratch_b)
        s->fns.cuMemFree_v2(s->scratch_b);
    if (s->scratch_c)
        s->fns.cuMemFree_v2(s->scratch_c);
    s->scratch_a = 0;
    s->scratch_b = 0;
    s->scratch_c = 0;
    if (s->fns.cuMemAlloc_v2(&s->scratch_a, bytes) != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuMemAlloc_v2(&s->scratch_b, bytes) != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuMemAlloc_v2(&s->scratch_c, bytes) != CUDA_SUCCESS)
        return 0;
    s->scratch_bytes = bytes;
    return 1;
}

static int cuda_copy_host_tensor_to_scratch(NCCudaState *s, CUdeviceptr dst, const NCTensor *x)
{
    size_t bytes = x->n_elems * x->item_size;
    return s->fns.cuMemcpyHtoD_v2(dst, (const uint8_t *)x->buffer->data + x->byte_offset, bytes) == CUDA_SUCCESS;
}

static void cuda_store_host_f32(void *ptr, NCTypeEnum type, float value);

static void cuda_write_float_back(NCTensor *y, const float *tmp, size_t n)
{
    uint8_t *base = (uint8_t *)y->buffer->data + y->byte_offset;
    for (size_t i = 0; i < n; i++)
        cuda_store_host_f32(base + i * y->item_size, y->item_type, tmp[i]);
}

static void cuda_store_host_f32(void *ptr, NCTypeEnum type, float value)
{
    switch (type) {
    case NC_TYPE_F32:
        *(float *)ptr = value;
        break;
    case NC_TYPE_BF16: {
        uint32_t u;
        memcpy(&u, &value, sizeof(u));
        u += 0x7fff + ((u >> 16) & 1);
        *(uint16_t *)ptr = (uint16_t)(u >> 16);
        break;
    }
    case NC_TYPE_F16: {
        uint32_t x;
        memcpy(&x, &value, sizeof(x));
        uint32_t sign = (x >> 16) & 0x8000u;
        int32_t exp = (int32_t)((x >> 23) & 0xffu) - 127 + 15;
        uint32_t mant = x & 0x7fffffu;
        uint16_t out;
        if (exp <= 0) {
            if (exp < -10) {
                out = (uint16_t)sign;
            } else {
                mant = (mant | 0x800000u) >> (1 - exp);
                out = (uint16_t)(sign | ((mant + 0x1000u) >> 13));
            }
        } else if (exp >= 31) {
            out = (uint16_t)(sign | 0x7c00u | (mant ? 0x200u : 0));
        } else {
            out = (uint16_t)(sign | ((uint32_t)exp << 10) | ((mant + 0x1000u) >> 13));
        }
        *(uint16_t *)ptr = out;
        break;
    }
    case NC_TYPE_I8:
        *(int8_t *)ptr = (int8_t)lrintf(value);
        break;
    case NC_TYPE_I16:
        *(int16_t *)ptr = (int16_t)lrintf(value);
        break;
    case NC_TYPE_I32:
        *(int32_t *)ptr = (int32_t)lrintf(value);
        break;
    default:
        break;
    }
}

static NCTensor *cuda_backend_binary_same_shape(NCDevice *device, NCOp op, NCTensor *x1, NCTensor *x2)
{
    NCCudaState *s = device->backend;
    size_t n = x1->n_elems;
    size_t bytes = n * sizeof(float);
    float *h1 = (float *)((uint8_t *)x1->buffer->data + x1->byte_offset);
    float *h2 = (float *)((uint8_t *)x2->buffer->data + x2->byte_offset);
    NCTensor *y = nc_new_tensor(device, x1->item_type, x1->n_dims, x1->dims);
    float *hy = (float *)((uint8_t *)y->buffer->data + y->byte_offset);
    if (x1->item_type != NC_TYPE_F32 || x2->item_type != NC_TYPE_F32)
        return NULL;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuMemcpyHtoD_v2(s->scratch_a, h1, bytes) != CUDA_SUCCESS ||
        s->fns.cuMemcpyHtoD_v2(s->scratch_b, h2, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    void *params[] = { &op, &s->scratch_a, &s->scratch_b, &s->scratch_c, &n };
    unsigned int block = 256;
    unsigned int grid = (unsigned int)((n + block - 1) / block);
    if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
        s->fns.cuLaunchKernel(s->binary_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2(hy, s->scratch_c, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static NCTensor *cuda_backend_unary(NCDevice *device, NCOp op, NCTensor *x)
{
    NCCudaState *s = device->backend;
    size_t n = x->n_elems;
    size_t bytes = n * sizeof(float);
    float *hx = (float *)((uint8_t *)x->buffer->data + x->byte_offset);
    NCTensor *y = nc_new_tensor(device, x->item_type, x->n_dims, x->dims);
    float *hy = (float *)((uint8_t *)y->buffer->data + y->byte_offset);
    if (x->item_type != NC_TYPE_F32)
        return NULL;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuMemcpyHtoD_v2(s->scratch_a, hx, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    void *params[] = { &op, &s->scratch_a, &s->scratch_c, &n };
    unsigned int block = 256;
    unsigned int grid = (unsigned int)((n + block - 1) / block);
    if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
        s->fns.cuLaunchKernel(s->unary_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2(hy, s->scratch_c, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static NCTensor *cuda_backend_matmul(NCDevice *device, NCTensor *w, NCTensor *x, NCTensor *y0, BOOL w_trans, BOOL x_trans)
{
    NCCudaState *s = device->backend;
    if (w->item_type != NC_TYPE_F32 || x->item_type != NC_TYPE_F32)
        return NULL;
    if (w->n_dims != 2 || x->n_dims != 2)
        return NULL;
    if (w_trans || x_trans)
        return NULL;

    BOOL use_colmajor = FALSE;
    size_t wm, wk, xn;
    {
        size_t cm_wm = w->dims[1];
        size_t cm_wk = w->dims[0];
        size_t cm_xk = x->dims[1];
        size_t cm_xn = x->dims[0];
        if (cm_wk == cm_xk) {
            use_colmajor = TRUE;
            wm = cm_wm;
            wk = cm_wk;
            xn = cm_xn;
        } else {
            wm = w->dims[0];
            wk = w->dims[1];
            xn = x->dims[1];
            if (wk != x->dims[0])
                return NULL;
        }
    }

    size_t out_dims[2];
    size_t w_bytes = w->n_elems * sizeof(float);
    size_t x_bytes = x->n_elems * sizeof(float);
    size_t y_bytes;
    if (use_colmajor) {
        out_dims[0] = xn;
        out_dims[1] = wm;
        y_bytes = wm * xn * sizeof(float);
    } else {
        out_dims[0] = wm;
        out_dims[1] = xn;
        y_bytes = wm * xn * sizeof(float);
    }
    NCTensor *y = y0 ? nc_new_tensor_from_tensor(y0) : nc_new_tensor(device, NC_TYPE_F32, 2, out_dims);
    if (!y)
        return NULL;
    uint8_t *hy = (uint8_t *)y->buffer->data + y->byte_offset;
    uint8_t *hw = (uint8_t *)w->buffer->data + w->byte_offset;
    uint8_t *hx = (uint8_t *)x->buffer->data + x->byte_offset;
    if (!cuda_ensure_scratch(s, w_bytes > x_bytes ? (w_bytes > y_bytes ? w_bytes : y_bytes)
                                                  : (x_bytes > y_bytes ? x_bytes : y_bytes))) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuMemcpyHtoD_v2(s->scratch_a, hw, w_bytes) != CUDA_SUCCESS ||
        s->fns.cuMemcpyHtoD_v2(s->scratch_b, hx, x_bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (y0 && s->fns.cuMemcpyHtoD_v2(s->scratch_c, hy, y_bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        int use_col = use_colmajor ? 1 : 0;
        void *y0_ptr = y0 ? (void *)(uintptr_t)s->scratch_c : NULL;
        void *params[] = {
            &use_col,
            &s->scratch_a,
            &s->scratch_b,
            &y0_ptr,
            &s->scratch_c,
            &wm,
            &wk,
            &xn,
        };
        unsigned int grid_x = (unsigned int)((xn + 15) / 16);
        unsigned int grid_y = (unsigned int)((wm + 15) / 16);
        unsigned int grid_z = 1;
        unsigned int block_x = 16;
        unsigned int block_y = 16;
        unsigned int block_z = 1;
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->matmul_fn, grid_x, grid_y, grid_z,
                                  block_x, block_y, block_z,
                                  0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2(hy, s->scratch_c, y_bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static NCTensor *cuda_backend_convert(NCDevice *device, NCTensor *x, NCTypeEnum new_type)
{
    NCCudaState *s = device->backend;
    size_t src_bytes = x->n_elems * x->item_size;
    size_t dst_bytes = x->n_elems * nc_type_size_table[new_type];
    size_t bytes = src_bytes > dst_bytes ? src_bytes : dst_bytes;
    NCTensor *y = nc_new_tensor(device, new_type, x->n_dims, x->dims);
    if (!y)
        return NULL;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x)) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        int src_type = (int)x->item_type;
        int dst_type = (int)new_type;
        void *params[] = { &s->scratch_a, &s->scratch_c, &src_type, &dst_type, &x->n_elems };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((x->n_elems + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->convert_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (new_type == NC_TYPE_F32) {
        if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, dst_bytes) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    } else {
        if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, dst_bytes) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    return y;
}

static NCTensor *cuda_backend_masked_fill(NCDevice *device, NCTensor *x, NCTensor *mask, float c, BOOL mask_inv)
{
    NCCudaState *s = device->backend;
    size_t bytes = x->n_elems * x->item_size;
    NCTensor *y = nc_new_tensor(device, x->item_type, x->n_dims, x->dims);
    if (!y)
        return NULL;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x) ||
        !cuda_copy_host_tensor_to_scratch(s, s->scratch_b, mask)) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        int mask_i = mask_inv ? 1 : 0;
        size_t n = x->n_elems;
        void *params[] = { &s->scratch_a, &s->scratch_b, &s->scratch_c, &n, &c, &mask_i };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((n + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->masked_fill_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static void cuda_backend_tensor_set_rnd_unif(NCDevice *device, NCTensor *y, float avg, float range, NCRNDState *rnd_state)
{
    NCCudaState *s = device->backend;
    size_t bytes = y->n_elems * y->item_size;
    if (!cuda_ensure_scratch(s, bytes))
        return;
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, y))
        return;
    {
        unsigned int seed = rnd_state ? rnd_state->state : 0x12345678u;
        size_t n = y->n_elems;
        void *params[] = { &s->scratch_a, &n, &seed, &avg, &range };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((n + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->rnd_unif_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS)
            return;
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS)
        return;
    if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_a, bytes) != CUDA_SUCCESS)
        return;
    if (rnd_state)
        rnd_state->state ^= (uint32_t)(y->n_elems * 2654435761u);
}

static void cuda_backend_tensor_set_dropout(NCDevice *device, NCTensor *y, float prob, NCRNDState *rnd_state)
{
    NCCudaState *s = device->backend;
    size_t bytes = y->n_elems * y->item_size;
    if (!cuda_ensure_scratch(s, bytes))
        return;
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, y))
        return;
    {
        unsigned int seed = rnd_state ? rnd_state->state : 0x87654321u;
        float scale = prob < 1.0f ? 1.0f / (1.0f - prob) : 0.0f;
        size_t n = y->n_elems;
        void *params[] = { &s->scratch_a, &n, &seed, &prob, &scale };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((n + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->rnd_dropout_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS)
            return;
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS)
        return;
    if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_a, bytes) != CUDA_SUCCESS)
        return;
    if (rnd_state)
        rnd_state->state ^= (uint32_t)(y->n_elems * 2654435761u);
}

static NCTensor *cuda_backend_reduce_sum(NCDevice *device, NCTensor *y0, NCTensor *x, int n_dims)
{
    NCCudaState *s = device->backend;
    size_t y_dims[NC_N_DIMS_MAX] = {0};
    for (int i = 0; i < n_dims; i++)
        y_dims[i] = x->dims[i];
    NCTensor *y = y0 ? y0 : nc_new_tensor(device, x->item_type, n_dims, y_dims);
    if (!y)
        return NULL;
    size_t y_total = y->n_elems;
    size_t collapse = 1;
    for (int i = n_dims; i < x->n_dims; i++)
        collapse *= x->dims[i];
    size_t x_bytes = x->n_elems * x->item_size;
    size_t y_bytes = y->n_elems * y->item_size;
    size_t bytes = x_bytes > y_bytes ? x_bytes : y_bytes;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (y0) {
        if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_c, y0)) {
            nc_free_tensor(y);
            return NULL;
        }
    } else {
        uint8_t *zero = nc_mallocz(y_bytes ? y_bytes : 1);
        if (!zero) {
            nc_free_tensor(y);
            return NULL;
        }
        if (s->fns.cuMemcpyHtoD_v2(s->scratch_c, zero, y_bytes) != CUDA_SUCCESS) {
            nc_free(zero);
            nc_free_tensor(y);
            return NULL;
        }
        nc_free(zero);
    }
    {
        void *params[] = { &s->scratch_a, &s->scratch_c, &y_total, &collapse };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((y_total + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->reduce_sum_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (x->item_type == NC_TYPE_F32 && y->item_type == NC_TYPE_F32) {
        if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, y_bytes) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    } else {
        float *tmp = nc_malloc(sizeof(float) * y_total);
        if (!tmp) {
            nc_free_tensor(y);
            return NULL;
        }
        if (s->fns.cuMemcpyDtoH_v2(tmp, s->scratch_c, y_total * sizeof(float)) != CUDA_SUCCESS) {
            nc_free(tmp);
            nc_free_tensor(y);
            return NULL;
        }
        cuda_write_float_back(y, tmp, y_total);
        nc_free(tmp);
    }
    return y;
}

static NCTensor *cuda_backend_reduce_sum_sqr(NCDevice *device, NCTensor *x)
{
    NCCudaState *s = device->backend;
    NCTensor *y = nc_new_scalar(device, x->item_type);
    if (!y)
        return NULL;
    size_t bytes = x->n_elems * x->item_size;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x)) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        uint8_t *zero = nc_mallocz(sizeof(float));
        if (!zero) {
            nc_free_tensor(y);
            return NULL;
        }
        if (s->fns.cuMemcpyHtoD_v2(s->scratch_c, zero, sizeof(float)) != CUDA_SUCCESS) {
            nc_free(zero);
            nc_free_tensor(y);
            return NULL;
        }
        nc_free(zero);
    }
    {
        size_t n = x->n_elems;
        void *params[] = { &s->scratch_a, &s->scratch_c, &n };
        unsigned int block = 256;
        unsigned int grid = (unsigned int)((n + block - 1) / block);
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->reduce_sum_sqr_fn, grid, 1, 1, block, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    if (s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, sizeof(float)) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static NCTensor *cuda_backend_soft_max(NCDevice *device, NCTensor *x)
{
    NCCudaState *s = device->backend;
    NCTensor *y = nc_new_tensor(device, x->item_type, x->n_dims, x->dims);
    if (!y)
        return NULL;
    size_t bytes = x->n_elems * x->item_size;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x)) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        int axis = x->n_dims - 1;
        size_t outer = 1;
        for (int i = 0; i < axis; i++)
            outer *= x->dims[i];
        size_t inner = x->dims[axis];
        void *params[] = { &s->scratch_a, &s->scratch_c, &outer, &inner };
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->softmax_fn, (unsigned int)outer, 1, 1, 256, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static NCTensor *cuda_backend_layer_norm(NCDevice *device, NCTensor *x, float eps, BOOL rms)
{
    NCCudaState *s = device->backend;
    NCTensor *y = nc_new_tensor(device, x->item_type, x->n_dims, x->dims);
    if (!y)
        return NULL;
    size_t bytes = x->n_elems * x->item_size;
    if (!cuda_ensure_scratch(s, bytes)) {
        nc_free_tensor(y);
        return NULL;
    }
    if (!cuda_copy_host_tensor_to_scratch(s, s->scratch_a, x)) {
        nc_free_tensor(y);
        return NULL;
    }
    {
        int axis = x->n_dims - 1;
        size_t outer = 1;
        for (int i = 0; i < axis; i++)
            outer *= x->dims[i];
        size_t inner = x->dims[axis];
        int rms_i = rms ? 1 : 0;
        void *params[] = { &s->scratch_a, &s->scratch_c, &outer, &inner, &eps, &rms_i };
        if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS ||
            s->fns.cuLaunchKernel(s->layer_norm_fn, (unsigned int)outer, 1, 1, 256, 1, 1, 0, NULL, params, NULL) != CUDA_SUCCESS) {
            nc_free_tensor(y);
            return NULL;
        }
    }
    if (s->fns.cuCtxSynchronize() != CUDA_SUCCESS ||
        s->fns.cuMemcpyDtoH_v2((uint8_t *)y->buffer->data + y->byte_offset, s->scratch_c, bytes) != CUDA_SUCCESS) {
        nc_free_tensor(y);
        return NULL;
    }
    return y;
}

static void cuda_backend_sync(NCDevice *device)
{
    NCCudaState *s = device->backend;
    if (s && s->fns.cuCtxSynchronize)
        s->fns.cuCtxSynchronize();
}

static void cuda_backend_destroy(NCDevice *device)
{
    NCCudaState *s = device ? device->backend : NULL;
    if (!s)
        return;
    if (s->fns.cuCtxSynchronize)
        s->fns.cuCtxSynchronize();
    if (s->scratch_a)
        s->fns.cuMemFree_v2(s->scratch_a);
    if (s->scratch_b)
        s->fns.cuMemFree_v2(s->scratch_b);
    if (s->scratch_c)
        s->fns.cuMemFree_v2(s->scratch_c);
    if (s->module && s->fns.cuModuleUnload)
        s->fns.cuModuleUnload(s->module);
    if (s->blas && s->fns.cublasDestroy_v2)
        s->fns.cublasDestroy_v2(s->blas);
    if (s->ctx && s->fns.cuCtxDestroy_v2)
        s->fns.cuCtxDestroy_v2(s->ctx);
    if (s->fns.nvcuda)
        FreeLibrary(s->fns.nvcuda);
    if (s->fns.cublas)
        FreeLibrary(s->fns.cublas);
    if (s->fns.nvrtc)
        FreeLibrary(s->fns.nvrtc);
    nc_free(s);
    device->backend = NULL;
}

static const NCBackendOps cuda_backend_ops = {
    .binary_same_shape = cuda_backend_binary_same_shape,
    .unary = cuda_backend_unary,
    .matmul = cuda_backend_matmul,
    .convert = cuda_backend_convert,
    .masked_fill = cuda_backend_masked_fill,
    .tensor_set_rnd_unif = cuda_backend_tensor_set_rnd_unif,
    .tensor_set_dropout = cuda_backend_tensor_set_dropout,
    .reduce_sum = cuda_backend_reduce_sum,
    .reduce_sum_sqr = cuda_backend_reduce_sum_sqr,
    .soft_max = cuda_backend_soft_max,
    .layer_norm = cuda_backend_layer_norm,
    .synchronize = cuda_backend_sync,
    .destroy = cuda_backend_destroy,
};

static int cuda_backend_init_state(NCCudaState *s)
{
    int ndev = 0;
    if (s->fns.cuInit(0) != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuDeviceGetCount(&ndev) != CUDA_SUCCESS || ndev <= 0) {
        fprintf(stderr, "No CUDA device available\n");
        return 0;
    }
    if (s->device_index < 0 || s->device_index >= ndev)
        s->device_index = 0;
    if (s->fns.cuDeviceGet(&s->device, s->device_index) != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuCtxCreate_v2(&s->ctx, 0, s->device) != CUDA_SUCCESS)
        return 0;
    if (s->fns.cuCtxSetCurrent(s->ctx) != CUDA_SUCCESS)
        return 0;
    if (!cuda_compile_kernels(s))
        return 0;
    return 1;
}

static NCDevice *cuda_device_alloc(NCContext *ctx, int device_index, NCCudaState *state)
{
    char namebuf[64];
    if (device_index >= 0)
        snprintf(namebuf, sizeof(namebuf), "cuda:%d", device_index);
    else
        snprintf(namebuf, sizeof(namebuf), "cuda");
    NCDevice *d = nc_mallocz(sizeof(*d));
    d->context = ctx;
    d->name = cuda_strdup(namebuf);
    d->is_host = FALSE;
    d->ops = &cuda_backend_ops;
    d->backend = state;
    init_list_head(&d->link);
    list_add_tail(&d->link, &ctx->devices);
    ctx->heap_size += sizeof(*d);
    return d;
}

LIBNC_CUDA_API NCDevice *nc_new_cuda_device_internal(NCContext *ctx, unsigned int device_index)
{
    NCCudaState *state;
    if (!ctx)
        return NULL;
    state = nc_mallocz(sizeof(*state));
    if (!state)
        return NULL;
    state->device_index = (int)device_index;
    if (!cuda_load_fns(&state->fns) || !cuda_backend_init_state(state)) {
        if (state->fns.nvcuda)
            FreeLibrary(state->fns.nvcuda);
        if (state->fns.cublas)
            FreeLibrary(state->fns.cublas);
        if (state->fns.nvrtc)
            FreeLibrary(state->fns.nvrtc);
        nc_free(state);
        return NULL;
    }
    return cuda_device_alloc(ctx, (int)device_index, state);
}
