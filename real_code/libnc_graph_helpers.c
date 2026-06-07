#include <string.h>

static size_t nc_node_concat_size(const size_t *tab_elem_size, int idx, size_t fallback)
{
    return tab_elem_size ? tab_elem_size[idx] : fallback;
}

void nc_combine_nodes(NCContext *m, NCNode **tab_op1, int count, int axis, int elem_size, const size_t *tab_elem_size)
{
    (void)m;
    if (!tab_op1 || count <= 0)
        return;

    size_t cursor = 0;
    for (int i = 0; i < count; i++) {
        NCNode *n = tab_op1[i];
        if (!n)
            continue;
        n->axis = axis;
        n->start = (ssize_t)cursor;
        cursor += nc_node_concat_size(tab_elem_size, i, (size_t)elem_size);
        n->end = (ssize_t)cursor;
    }
}

NCNode *nc_concat_node(NCContext *m, NCNode **inputs, int count, int axis, const size_t *tab_size)
{
    if (!m || count < 0)
        return NULL;

    NCNode *n = nc_mallocz(sizeof(*n));
    n->ref_count = 1;
    n->context = m;
    n->op = NC_OP_CONCAT;
    n->n_args = count;
    n->axis = axis;
    init_list_head(&n->link);

    if (count > 0) {
        n->args = nc_mallocz(sizeof(NCTensor *) * (size_t)count);
        size_t total = 0;
        for (int i = 0; i < count; i++) {
            if (inputs && inputs[i]) {
                n->args[i] = NULL;
                total += nc_node_concat_size(tab_size, i, 0);
            }
        }
        n->value = (ssize_t)total;
        if (tab_size) {
            size_t *saved = nc_malloc(sizeof(size_t) * (size_t)count);
            memcpy(saved, tab_size, sizeof(size_t) * (size_t)count);
            n->opaque = saved;
        }
    }

    context_track_node(m, n);
    return n;
}

void nc_concat_optimization(NCContext *m, NCNode **concat_nodes, int count)
{
    (void)m;
    if (!concat_nodes || count <= 0)
        return;

    for (int i = 0; i < count; i++) {
        NCNode *n = concat_nodes[i];
        if (!n || n->op != NC_OP_CONCAT || !n->args)
            continue;
        size_t cursor = 0;
        for (int j = 0; j < n->n_args; j++) {
            NCTensor *arg = n->args[j];
            if (!arg || !arg->node)
                continue;
            nc_node_set_parent(arg->node, j, n);
            arg->node->axis = n->axis;
            arg->node->start = (ssize_t)cursor;
            cursor += arg->dims[n->axis];
            arg->node->end = (ssize_t)cursor;
        }
    }
}
