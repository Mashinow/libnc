NCTensor *nc_new_vec_f32(NCDevice *d, size_t n, float val)
{
    NCTensor *x = nc_new_tensor_1d(d, NC_TYPE_F32, n);
    nc_tensor_set_f32(x, val);
    return x;
}

NCTensor *nc_new_f32(NCDevice *d, float val)
{
    NCTensor *x = nc_new_scalar(d, NC_TYPE_F32);
    nc_tensor_set_f32(x, val);
    return x;
}
