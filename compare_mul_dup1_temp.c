#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libnc.h"

typedef NCContext *(*fn_nc_context_init)(int);
typedef void (*fn_nc_context_end)(NCContext *);
typedef NCDevice *(*fn_nc_new_device)(NCContext *, const char *);
typedef NCTensor *(*fn_nc_new_tensor)(NCDevice *, NCTypeEnum, int, const size_t *);
typedef void (*fn_nc_free_tensor)(NCTensor *);
typedef NCRNDState *(*fn_nc_rnd_init)(NCDevice *, uint32_t);
typedef void (*fn_nc_rnd_end)(NCRNDState *);
typedef void (*fn_nc_tensor_set_rnd_unif)(NCTensor *, float, float, NCRNDState *);
typedef void (*fn_nc_set1_f32)(NCTensor *, int, const size_t *, float);
typedef float (*fn_nc_get1_f32)(const NCTensor *, int, const size_t *);
typedef NCTensor *(*fn_nc_dup_tensor)(const NCTensor *);
typedef NCTensor *(*fn_nc_mul)(NCTensor *, NCTensor *);
typedef NCTensor *(*fn_nc_sum)(NCTensor *);
typedef NCTensor *(*fn_nc_new_f32)(NCDevice *, float);
typedef void (*fn_nc_backward)(const NCTensor *, NCTensor *, NCParamUpdateFunc *, int);
typedef void (*fn_nc_param_list_init)(NCParamList *);
typedef NCParam *(*fn_nc_new_param)(NCParamList *, NCTensor **, const char *, ...);
typedef void (*fn_nc_param_list_end)(NCParamList *);
typedef NCTensorData *(*fn_nc_tensor_get_data)(NCTensorData *, const NCTensor *);

typedef struct LibApi {
    HMODULE h;
    fn_nc_context_init nc_context_init;
    fn_nc_context_end nc_context_end;
    fn_nc_new_device nc_new_device;
    fn_nc_new_tensor nc_new_tensor;
    fn_nc_free_tensor nc_free_tensor;
    fn_nc_rnd_init nc_rnd_init;
    fn_nc_rnd_end nc_rnd_end;
    fn_nc_tensor_set_rnd_unif nc_tensor_set_rnd_unif;
    fn_nc_set1_f32 nc_set1_f32;
    fn_nc_get1_f32 nc_get1_f32;
    fn_nc_dup_tensor nc_dup_tensor;
    fn_nc_mul nc_mul;
    fn_nc_sum nc_sum;
    fn_nc_new_f32 nc_new_f32;
    fn_nc_backward nc_backward;
    fn_nc_param_list_init nc_param_list_init;
    fn_nc_new_param nc_new_param;
    fn_nc_param_list_end nc_param_list_end;
    fn_nc_tensor_get_data nc_tensor_get_data;
} LibApi;

static void *load_sym(HMODULE h, const char *name)
{
    void *p = (void *)GetProcAddress(h, name);
    if (!p) {
        fprintf(stderr, "missing symbol %s\n", name);
        exit(1);
    }
    return p;
}

static LibApi load_lib(const char *path)
{
    LibApi a;
    memset(&a, 0, sizeof(a));
    a.h = LoadLibraryA(path);
    if (!a.h) {
        fprintf(stderr, "cannot load %s\n", path);
        exit(1);
    }
    a.nc_context_init = (fn_nc_context_init)load_sym(a.h, "nc_context_init");
    a.nc_context_end = (fn_nc_context_end)load_sym(a.h, "nc_context_end");
    a.nc_new_device = (fn_nc_new_device)load_sym(a.h, "nc_new_device");
    a.nc_new_tensor = (fn_nc_new_tensor)load_sym(a.h, "nc_new_tensor");
    a.nc_free_tensor = (fn_nc_free_tensor)load_sym(a.h, "nc_free_tensor");
    a.nc_rnd_init = (fn_nc_rnd_init)load_sym(a.h, "nc_rnd_init");
    a.nc_rnd_end = (fn_nc_rnd_end)load_sym(a.h, "nc_rnd_end");
    a.nc_tensor_set_rnd_unif = (fn_nc_tensor_set_rnd_unif)load_sym(a.h, "nc_tensor_set_rnd_unif");
    a.nc_set1_f32 = (fn_nc_set1_f32)load_sym(a.h, "nc_set1_f32");
    a.nc_get1_f32 = (fn_nc_get1_f32)load_sym(a.h, "nc_get1_f32");
    a.nc_dup_tensor = (fn_nc_dup_tensor)load_sym(a.h, "nc_dup_tensor");
    a.nc_mul = (fn_nc_mul)load_sym(a.h, "nc_mul");
    a.nc_sum = (fn_nc_sum)load_sym(a.h, "nc_sum");
    a.nc_new_f32 = (fn_nc_new_f32)load_sym(a.h, "nc_new_f32");
    a.nc_backward = (fn_nc_backward)load_sym(a.h, "nc_backward");
    a.nc_param_list_init = (fn_nc_param_list_init)load_sym(a.h, "nc_param_list_init");
    a.nc_new_param = (fn_nc_new_param)load_sym(a.h, "nc_new_param");
    a.nc_param_list_end = (fn_nc_param_list_end)load_sym(a.h, "nc_param_list_end");
    a.nc_tensor_get_data = (fn_nc_tensor_get_data)load_sym(a.h, "nc_tensor_get_data");
    return a;
}

typedef struct Result {
    float loss_base;
    float loss_plus;
    float loss_minus;
    float g0;
    float g1;
} Result;

static void save_grad(void *opaque, NCTensor *grad, NCTensor *idx)
{
    (void)idx;
    NCParam *p = opaque;
    p->saved_grad = grad;
}

static Result run_case(const LibApi *lib, const float *x0v, const float *x1v)
{
    Result r = {0};
    const size_t d0[2] = {4, 3};
    const size_t d1[1] = {4};
    NCContext *ctx = lib->nc_context_init(1);
    NCDevice *dev = lib->nc_new_device(ctx, "cpu");
    NCParamList pl;
    lib->nc_param_list_init(&pl);
    NCTensor *x0 = lib->nc_new_tensor(dev, NC_TYPE_F32, 2, d0);
    NCTensor *x1 = lib->nc_new_tensor(dev, NC_TYPE_F32, 1, d1);
    NCParam *p0 = lib->nc_new_param(&pl, &x0, "x0");
    NCParam *p1 = lib->nc_new_param(&pl, &x1, "x1");
    (void)p0;
    (void)p1;
    for (size_t i = 0; i < 12; i++) {
        size_t idx[2] = { i / 3, i % 3 };
        lib->nc_set1_f32(x0, 2, idx, x0v[i]);
    }
    for (size_t i = 0; i < 4; i++) {
        size_t idx[1] = { i };
        lib->nc_set1_f32(x1, 1, idx, x1v[i]);
    }
    NCTensor *y = lib->nc_mul(lib->nc_dup_tensor(x0), lib->nc_dup_tensor(x1));
    NCTensor *loss = lib->nc_sum(y);
    r.loss_base = lib->nc_get1_f32(loss, 0, NULL);
    NCTensor *grad0 = lib->nc_new_f32(dev, 1.0f);
    lib->nc_backward(loss, grad0, save_grad, 0);
    r.g0 = lib->nc_get1_f32(p0->saved_grad, 2, (size_t[]){0,0});
    r.g1 = lib->nc_get1_f32(p1->saved_grad, 1, (size_t[]){0});
    lib->nc_free_tensor(p0->saved_grad);
    lib->nc_free_tensor(p1->saved_grad);
    p0->saved_grad = NULL;
    p1->saved_grad = NULL;
    lib->nc_free_tensor(loss);
    lib->nc_free_tensor(grad0);

    size_t idx0[2] = {0,0};
    float orig = x0v[0];
    lib->nc_set1_f32(x0, 2, idx0, orig + 1e-3f);
    y = lib->nc_mul(lib->nc_dup_tensor(x0), lib->nc_dup_tensor(x1));
    loss = lib->nc_sum(y);
    r.loss_plus = lib->nc_get1_f32(loss, 0, NULL);
    lib->nc_free_tensor(loss);
    lib->nc_set1_f32(x0, 2, idx0, orig - 1e-3f);
    y = lib->nc_mul(lib->nc_dup_tensor(x0), lib->nc_dup_tensor(x1));
    loss = lib->nc_sum(y);
    r.loss_minus = lib->nc_get1_f32(loss, 0, NULL);
    lib->nc_free_tensor(loss);

    lib->nc_free_tensor(x0);
    lib->nc_free_tensor(x1);
    lib->nc_param_list_end(&pl);
    lib->nc_context_end(ctx);
    return r;
}

int main(void)
{
    LibApi cur = load_lib("libnc.dll");
    LibApi eta = load_lib("etalon_libnc.dll");
    const size_t d0[2] = {4, 3};
    const size_t d1[1] = {4};
    float x0v[12];
    float x1v[4];
    NCContext *ctx = cur.nc_context_init(1);
    NCDevice *dev = cur.nc_new_device(ctx, "cpu");
    NCRNDState *rnd = cur.nc_rnd_init(dev, 1234);
    NCTensor *x0 = cur.nc_new_tensor(dev, NC_TYPE_F32, 2, d0);
    NCTensor *x1 = cur.nc_new_tensor(dev, NC_TYPE_F32, 1, d1);
    cur.nc_tensor_set_rnd_unif(x0, 0.0f, 1.0f, rnd);
    cur.nc_tensor_set_rnd_unif(x1, 0.0f, 1.0f, rnd);
    for (size_t i = 0; i < 12; i++) {
        size_t idx[2] = { i / 3, i % 3 };
        x0v[i] = cur.nc_get1_f32(x0, 2, idx);
    }
    for (size_t i = 0; i < 4; i++) {
        size_t idx[1] = { i };
        x1v[i] = cur.nc_get1_f32(x1, 1, idx);
    }
    cur.nc_free_tensor(x0);
    cur.nc_free_tensor(x1);
    cur.nc_rnd_end(rnd);
    cur.nc_context_end(ctx);

    Result a = run_case(&cur, x0v, x1v);
    Result b = run_case(&eta, x0v, x1v);
    printf("cur loss base=%.9g plus=%.9g minus=%.9g g0=%.9g g1=%.9g\n",
           a.loss_base, a.loss_plus, a.loss_minus, a.g0, a.g1);
    printf("eta loss base=%.9g plus=%.9g minus=%.9g g0=%.9g g1=%.9g\n",
           b.loss_base, b.loss_plus, b.loss_minus, b.g0, b.g1);
    printf("cur approx=%.9g eta approx=%.9g\n",
           (a.loss_plus - a.loss_minus) * 500.0f,
           (b.loss_plus - b.loss_minus) * 500.0f);
    return 0;
}
