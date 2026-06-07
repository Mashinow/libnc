#include <stdio.h>
#include <string.h>

static char *nc_device_make_name(const char *kind, int device_index)
{
    char buf[64];
    if (device_index >= 0)
        snprintf(buf, sizeof(buf), "%s:%d", kind, device_index);
    else
        snprintf(buf, sizeof(buf), "%s", kind);
    size_t len = strlen(buf) + 1;
    char *name = nc_malloc(len);
    memcpy(name, buf, len);
    return name;
}

static NCDevice *nc_device_alloc(NCContext *ctx, const char *name, BOOL is_host)
{
    NCDevice *d = nc_mallocz(sizeof(*d));
    d->context = ctx;
    size_t len = strlen(name) + 1;
    d->name = nc_malloc(len);
    memcpy(d->name, name, len);
    d->is_host = is_host;
    init_list_head(&d->link);
    list_add_tail(&d->link, &ctx->devices);
    ctx->heap_size += sizeof(*d);
    return d;
}

static NCDevice *nc_device_alloc_cuda_compat(NCContext *ctx, int device_index)
{
    char *name = nc_device_make_name("cuda", device_index);
    NCDevice *d = nc_device_alloc(ctx, name, FALSE);
    nc_free(name);
    return d;
}
