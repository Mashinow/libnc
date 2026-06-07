#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "libnc.h"
#include "real_code/libnc_internal.h"

typedef NCContext *(*fn_nc_context_init)(int);
typedef void (*fn_nc_context_end)(NCContext *);
typedef NCDevice *(*fn_nc_new_device)(NCContext *, const char *);
typedef NCTensor *(*fn_nc_new_tensor)(NCDevice *, NCTypeEnum, int, const size_t *);
typedef void (*fn_nc_free_tensor)(NCTensor *);
typedef NCRNDState *(*fn_nc_rnd_init)(NCDevice *, uint32_t);
typedef void (*fn_nc_rnd_end)(NCRNDState *);
typedef void (*fn_nc_tensor_set_rnd_unif)(NCTensor *, float, float, NCRNDState *);
typedef float (*fn_nc_get1_f32)(const NCTensor *, int, const size_t *);
typedef NCTensor *(*fn_nc_dup_tensor)(const NCTensor *);
typedef NCTensor *(*fn_nc_convert)(NCTensor *, NCTypeEnum);
typedef NCTensor *(*fn_nc_layer_norm)(NCTensor *, float);
typedef void (*fn_nc_set1_f32)(NCTensor *, int, const size_t *, float);

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
    fn_nc_get1_f32 nc_get1_f32;
    fn_nc_dup_tensor nc_dup_tensor;
    fn_nc_convert nc_convert;
    fn_nc_layer_norm nc_layer_norm;
    fn_nc_set1_f32 nc_set1_f32;
} LibApi;

static void *load_sym(HMODULE h, const char *name)
{
    void *p = (void *)GetProcAddress(h, name);
    if (!p) {
        fprintf(stderr, "missing symbol %s\n", name);
        ExitProcess(1);
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
        ExitProcess(1);
    }
    a.nc_context_init = (fn_nc_context_init)load_sym(a.h, "nc_context_init");
    a.nc_context_end = (fn_nc_context_end)load_sym(a.h, "nc_context_end");
    a.nc_new_device = (fn_nc_new_device)load_sym(a.h, "nc_new_device");
    a.nc_new_tensor = (fn_nc_new_tensor)load_sym(a.h, "nc_new_tensor");
    a.nc_free_tensor = (fn_nc_free_tensor)load_sym(a.h, "nc_free_tensor");
    a.nc_rnd_init = (fn_nc_rnd_init)load_sym(a.h, "nc_rnd_init");
    a.nc_rnd_end = (fn_nc_rnd_end)load_sym(a.h, "nc_rnd_end");
    a.nc_tensor_set_rnd_unif = (fn_nc_tensor_set_rnd_unif)load_sym(a.h, "nc_tensor_set_rnd_unif");
    a.nc_get1_f32 = (fn_nc_get1_f32)load_sym(a.h, "nc_get1_f32");
    a.nc_dup_tensor = (fn_nc_dup_tensor)load_sym(a.h, "nc_dup_tensor");
    a.nc_convert = (fn_nc_convert)load_sym(a.h, "nc_convert");
    a.nc_layer_norm = (fn_nc_layer_norm)load_sym(a.h, "nc_layer_norm");
    a.nc_set1_f32 = (fn_nc_set1_f32)load_sym(a.h, "nc_set1_f32");
    return a;
}

static void dump_aux(const char *tag, NCTensor *y)
{
    NCNode *n = y->node;
    NCTensor *aux = n && n->n_args > 1 ? n->args[1] : NULL;
    printf("%s out0=%g aux0=%g\n",
           tag,
           nc_get1_f32(y, 1, (size_t[]){0}),
           aux ? nc_get1_f32(aux, aux->n_dims, aux->n_dims ? (size_t[]){0} : NULL) : 0.0f);
}

int main(void)
{
    const size_t dims[1] = { 10 };
    LibApi cur = load_lib("libnc.dll");
    LibApi eta = load_lib("etalon_libnc.dll");

    NCContext *ctx = cur.nc_context_init(1);
    NCDevice *dev = cur.nc_new_device(ctx, "cpu");
    NCRNDState *rnd = cur.nc_rnd_init(dev, 1234);
    NCTensor *x = cur.nc_new_tensor(dev, NC_TYPE_F32, 1, dims);
    cur.nc_tensor_set_rnd_unif(x, 0.0f, 1.0f, rnd);
    float xv[10];
    for (size_t i = 0; i < 10; i++)
        xv[i] = cur.nc_get1_f32(x, 1, &i);
    cur.nc_free_tensor(x);
    cur.nc_rnd_end(rnd);
    cur.nc_context_end(ctx);

    float mean = 0.0f, sq = 0.0f;
    for (size_t i = 0; i < 10; i++) {
        mean += xv[i];
        sq += xv[i] * xv[i];
    }
    mean /= 10.0f;
    float invstd = 1.0f / sqrtf(sq / 10.0f - mean * mean + 1e-5f);
    printf("input mean=%g invstd=%g\n", mean, invstd);

    for (int lib_idx = 0; lib_idx < 2; lib_idx++) {
        const LibApi *lib = lib_idx == 0 ? &cur : &eta;
        NCContext *c = lib->nc_context_init(1);
        NCDevice *d = lib->nc_new_device(c, "cpu");
        NCTensor *x2 = lib->nc_new_tensor(d, NC_TYPE_F32, 1, dims);
        for (size_t i = 0; i < 10; i++)
            lib->nc_set1_f32(x2, 1, &i, xv[i]);
        NCTensor *xb = lib->nc_convert(x2, NC_TYPE_BF16);
        NCTensor *y = lib->nc_layer_norm(lib->nc_dup_tensor(xb), 1e-5f);
        dump_aux(lib_idx == 0 ? "cur" : "eta", y);
        lib->nc_free_tensor(y);
        lib->nc_free_tensor(xb);
        lib->nc_context_end(c);
    }
    return 0;
}
