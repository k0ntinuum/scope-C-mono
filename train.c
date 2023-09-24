void train_backprop(f64* p, i32 S, f64 r) {
    for (i32 s = 0 ; s < S ; s++ ) {
        update_bg(p);
        for (i32 i = 0; i < P; i++) p[i] = filter(p[i] -r*g[i]);
    }   
}
