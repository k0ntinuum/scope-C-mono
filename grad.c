void update_bg(f64* p) {
    f64 l = 0.0;
    for (i32 i = 0; i < P; i++) g[i] = 0;
    for (i32 i = 0; i < D; i++) {
        ret(p, f(p, data[i][0]) - data[i][1]);
    }
}




