f64 filter(f64 x) {
    return x > 1 ? 1 : (x < -1 ? -1 : x);
}

void _lrn(f64* p) {
    for (i32 i = 0; i < V; i++) {
        g[bias_index(i)] += 2*m[i]*d[i];
    }
    for (i32 i = 0; i < H; i++) {
        g[load_weight_index(i)] += 2*last_in_fwd*m[i]*d[i];
    }  
    for (i32 i = H ; i < V ; i++) {
        for (i32 j = 0; j < H; j++) {
            g[weight_index(s_from_t_p(i,j),i)] += 2*v[s_from_t_p(i,j)]*m[i]*d[i];
        }
    }
    for (i32 i = V - H; i < V; i++) {
        g[drain_weight_index(i)] += 2*v[i]*last_in_ret;
    }
}

void ret(f64* p, f64 e) {
    last_in_ret = e;
    for (i32 i = V - H; i < V; i++) {
        d[i] = e*p[drain_weight_index(i)];
    }
    for (i32 i = V - H - 1; i >= 0; i--) {
        d[i] = 0;
        for (i32 j = 0; j < H; j++) 
            d[i] += p[weight_index(i, t_from_s_p(i,j))]*d[t_from_s_p(i,j)]*m[t_from_s_p(i,j)];
    }
    _lrn(p);  
}

void lrn(f64* p, f64 r) {
    for (i32 i = 0; i < P; i++) {
        p[i] = filter(p[i] - r*g[i]); 
        g[i] = 0;
    }
}




