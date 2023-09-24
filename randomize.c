
f64 rnd() {return 1.0 - 2*( rand()/ (f64)RAND_MAX );}

void randomize(f64* p, f64 m) {
    for (i32 i = 0 ; i < P; i++) p[i] = m*rnd();
}

void randomize_data(f64 m) {
    f64 dx = (data_x_max - data_x_min)/(D + 1);
    for (i32 i = 0; i < D; i++) {
        data[i][0] = dx*(i+1) + data_x_min;
        data[i][1] = m*rnd();
    }
}

