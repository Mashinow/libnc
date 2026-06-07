#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void param_io_write_tensor(FILE *f, const char *name, const NCTensor *t)
{
    uint32_t header[4];
    header[0] = 603238138u;
    header[1] = (uint32_t)t->item_type;
    header[2] = (uint32_t)t->n_dims;
    header[3] = (uint32_t)strlen(name ? name : "");
    fwrite(header, sizeof(uint32_t), 4, f);

    uint32_t dims[NC_N_DIMS_MAX] = {0};
    for (int i = 0; i < t->n_dims; i++)
        dims[i] = (uint32_t)t->dims[i];
    fwrite(dims, sizeof(uint32_t), (size_t)t->n_dims, f);

    if (name)
        fwrite(name, 1, strlen(name), f);

    const NCTensor *src = t;
    NCTensor *tmp = NULL;
    if (!t->is_contiguous) {
        tmp = nc_new_tensor_from_tensor(t);
        src = tmp;
    }
    fwrite(tensor_const_data_ptr(src), 1, tensor_numel(src) * src->item_size, f);
    if (tmp)
        nc_free_tensor(tmp);
}

static void param_io_load_tensor(FILE *f, NCParamList *pl)
{
    uint32_t header[4];
    if (fread(header, sizeof(uint32_t), 4, f) != 4)
        return;

    if (header[0] != 603238138u)
        nc_error("invalid magic 0x%08x", header[0]);

    uint32_t type = header[1];
    uint32_t n_dims = header[2];
    uint32_t name_len = header[3];

    if (n_dims > NC_N_DIMS_MAX)
        nc_error("invalid number of dimensions (%u)", n_dims);
    if (name_len > 0x3ffu)
        nc_error("name too long (%u)", name_len);

    uint32_t dims32[NC_N_DIMS_MAX] = {0};
    if (n_dims > 0 && fread(dims32, sizeof(uint32_t), n_dims, f) != n_dims)
        nc_error("unexpected end of file");

    char name_buf[1024];
    if (name_len > 0 && fread(name_buf, 1, name_len, f) != name_len)
        nc_error("unexpected end of file");
    name_buf[name_len] = '\0';

    NCParam *p = nc_find_param(pl, name_buf);
    if (!p)
        nc_error("Could not find variable '%s'", name_buf);
    if (!p->pval || !*p->pval)
        nc_error("parameter '%s' is not initialized", name_buf);

    NCTensor *dst = *p->pval;
    if ((uint32_t)dst->item_type != type)
        nc_error("Unexpected type: %u (%d)", type, (int)dst->item_type);
    if ((uint32_t)dst->n_dims != n_dims)
        nc_error("Invalid number of dimensions (%u)", n_dims);
    for (uint32_t i = 0; i < n_dims; i++)
        if (dst->dims[i] != (size_t)dims32[i])
            nc_error("%s: invalid dimension size (%u %zu)", name_buf, dims32[i], dst->dims[i]);

    NCTensor *tmp = dst;
    if (!dst->is_contiguous) {
        tmp = nc_make_contiguous(dst);
        *p->pval = tmp;
    }
    if (fread(tensor_data_ptr(tmp), 1, tensor_numel(tmp) * tmp->item_size, f) != tensor_numel(tmp) * tmp->item_size)
        nc_error("unexpected end of file");

    if (dst->item_type == NC_TYPE_BF16) {
        if (!p->low_part || p->low_part->item_type != NC_TYPE_F32 ||
            p->low_part->n_dims != dst->n_dims || memcmp(p->low_part->dims, dst->dims, sizeof(size_t) * (size_t)dst->n_dims) != 0) {
            if (p->low_part) {
                nc_free_tensor(p->low_part);
                p->low_part = NULL;
            }
            p->low_part = nc_convert(nc_dup_tensor(dst), NC_TYPE_F32);
        } else {
            nc_tensor_convert(p->low_part, dst);
        }
    } else if (p->low_part) {
        nc_free_tensor(p->low_part);
        p->low_part = NULL;
    }
}

static void param_io_save_all(NCParamList *pl, const char *filename)
{
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror(filename);
        exit(1);
    }

    struct list_head *el;
    list_for_each(el, &pl->param_list) {
        NCParam *p = list_entry(el, NCParam, link);
        if (!p->pval || !*p->pval)
            continue;
        param_io_write_tensor(f, p->name, *p->pval);
    }
    fclose(f);
}

static void param_io_load_all(NCParamList *pl, const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror(filename);
        exit(1);
    }

    while (1) {
        long pos = ftell(f);
        uint32_t magic;
        if (fread(&magic, sizeof(magic), 1, f) != 1)
            break;
        fseek(f, pos, SEEK_SET);
        param_io_load_tensor(f, pl);
    }
    fclose(f);
}

void nc_save_coefs(NCParamList *pl, const char *filename)
{
    param_io_save_all(pl, filename);
}

void nc_load_coefs(NCParamList *pl, const char *filename)
{
    param_io_load_all(pl, filename);
}

void nc_save_state(NCParamList *pl, const char *filename)
{
    nc_save_coefs(pl, filename);
}

void nc_load_state(NCParamList *pl, const char *filename)
{
    nc_load_coefs(pl, filename);
}
