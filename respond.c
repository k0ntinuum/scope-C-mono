void respond() {
    if (IsKeyDown(KEY_Q)) exit(0);
    if (IsKeyReleased(KEY_RIGHT)) rate = 0.02;
    if (IsKeyReleased(KEY_LEFT)) rate = 0.01;
    if (IsKeyReleased(KEY_UP)) rate = 0.05;
     if (IsKeyReleased(KEY_DOWN)) rate = 0.0;
    if (IsKeyReleased(KEY_D)) randomize_data(1.0);
    if (IsKeyReleased(KEY_W)) randomize(p,0.6);
    if (IsKeyReleased(KEY_L)) {
        L++;if (L >= MAX_L) L = 1;
        build_height_layers(H,L);
        randomize(p,0.6);
    }
    if (IsKeyReleased(KEY_H)) {
        H++;if (H >= MAX_H) H = 2;
        build_height_layers(H,L);
        randomize(p,0.6);
    }
    if (IsKeyReleased(KEY_N)) {
        D--;if (D <= 0) D = MAX_D;
        randomize_data(data_spread);
    }
    if (IsKeyReleased(KEY_M)) {
        D++;if (D > MAX_D) D = 1;
        randomize_data(data_spread);
    }
    if (IsKeyReleased(KEY_S)) {
        for (int i = 0 ; i < MAX_L; i++) act_code[i] = 1;
        update_activations();
    }
    if (IsKeyReleased(KEY_T)) {
        for (int i = 0 ; i < MAX_L; i++) act_code[i] = 0;
        update_activations();
    }
    if (IsKeyReleased(KEY_I)) {
        for (int i = 0 ; i < MAX_L; i++) act_code[i] = 2;
        update_activations();
    }
    if (IsKeyReleased(KEY_Z)) {
        for (int i = 0 ; i < MAX_L; i++) act_code[i] = i%2;
        //alternate sine and tanh
        update_activations();
    }
   



}