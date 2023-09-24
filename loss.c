f64 _loss(f64* p, i32 i) { 
    f64 err = f(p, data[i][0]) - data[i][1]; 
    return err*err; 
}
f64 loss(f64* p) { 
    f64 l = 0.0;
    for (i32 i = 0; i < D; i++) l += _loss(p,i); 
    return l;
}

