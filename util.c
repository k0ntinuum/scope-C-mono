
i32 s_from_p_index(i32 i) {
    if (i < V) return -2;
    if (i < V + H) return -1;
    if (i > P - 1 - H) return (i - (P - 1-H)) + (V-H - 1) ;
    return (i-V-H)/H;
}

i32 t_from_p_index(i32 i) {
    if (i < V) return i;
    if (i < V + H) return i - V;
    if (i > P -1 - H) return -1;
    return ((i-V-H)/(H*H)+1)*H + (i -V-H)%H;
}

i32 weight_index(i32 s, i32 t) {
    assert(s >= 0 && s < V - H && t >= H && t < V);
    return H*H*(s/H) + (s%H)*H + t%H +V+H;
}

i32 bias_index(i32 s) {
    assert(s >= 0 && s < V);
    return s;
}

i32 load_weight_index(i32 t) {
    assert(t >= 0 && t < V);
    return V + t;
}

i32 drain_weight_index(i32 s) {
    assert(V - H <= s  && s <= V);
    return P  + s - V;
}

i32 t_from_s_p(i32 s, i32 p) {
    assert(s >= 0 && s <= V -H && p >= 0 && p < H);
    return (s/H + 1)*H + p;
}

i32 s_from_t_p(i32 t, i32 p) {
    assert(t >= 0 && t <= V && p >= 0 && p < H);
    return (t/H - 1)*H + p;
}
i32 pos_of(i32 i) {return i%H;}
i32 layer_of(i32 i) {return i/H;}

void load_web_positions(f64 web_width, f64 web_height, f64 corner_x, f64 corner_y) {
    f64 dy = web_height/(H-1);
    f64 dx = web_width/(L+1);
    f64 middle = web_height/2.0;
    inp_pos = (vec){corner_x, corner_y+web_height/2};
    out_pos = (vec){corner_x + web_width,corner_y+web_height/2};
    for (i32 i = 0; i < V ; i++) {
        web_pos[i] = (vec){corner_x + (layer_of(i) + 1)*dx, corner_y + (pos_of(i)%H)*dy};
    }
}
void load_default_positions() {
    load_web_positions(default_web_width, default_web_height, default_corner_x, default_corner_y);
}

void build_height_layers(i32 h, i32 l) {
    H = h; 
    L = l;
    V = L*H;
    P = V+2*H+(L-1)*H*H;
    load_default_positions();
}






