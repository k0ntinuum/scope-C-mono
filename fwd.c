
f64 f(f64* p, f64 x) {
    last_in_fwd = x;
    f64 final = 0;
    for (i32 i = 0; i < H; i++) {
        u[i] = x*p[load_weight_index(i)] + p[bias_index(i)];
        v[i] = activation[0](u[i]);
        m[i] = derivative[0](u[i]);
    }
    for (i32 i = H; i < V; i++) {
        u[i] = p[bias_index(i)];
        for (i32 j = 0; j < H; j++) u[i] += p[weight_index(s_from_t_p(i,j),i)]*v[s_from_t_p(i,j)];
        v[i] = activation[layer_of(i)](u[i]);
        m[i] = derivative[layer_of(i)](u[i]);
    }
    for (i32 i = V - H; i < V; i++) {
        final += v[i]*p[drain_weight_index(i)];
    }
    last_out_fwd = final;
    return final;
}




    