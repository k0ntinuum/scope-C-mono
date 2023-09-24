
f32 scaled_x(f64 x) { return (f32)(f_corner_x + hppu * (x - plot_x_min)); }
f32 scaled_y(f64 y) { return (f32)(f_corner_y + screen_height - f_screen_height - vppu*(y-plot_y_min));}

void plot_function( f64* p, color col) {
    f64 x= 0.0;
    vec last_point = (vec){scaled_x(plot_x_min), scaled_y(f(p,plot_x_min))}, this_point;
    for (i32 i = 1 ; i < plot_segments; i++) {
        x = data_x_min + i*plot_gap;
        this_point = (vec){scaled_x(x),scaled_y(f(p,x))};
        DrawLineEx(last_point, this_point, f_thickness, col);
        last_point = this_point;
    }
}


void plot_data(color col) {
    for (i32 i = 0; i < D; i++) {
        DrawCircleV((vec){scaled_x(data[i][0]),scaled_y(data[i][1])}, data_radius, col);
    }
}

void plot_web_positions(color col) {
    DrawRing(inp_pos, inner_vertex_radius, outer_vertex_radius, 0, 360, 1, col);
    DrawRing(out_pos, inner_vertex_radius, outer_vertex_radius, 0, 360, 1, col);
    for (i32 i = 0; i < V ; i++) {
        DrawRing(web_pos[i], inner_vertex_radius, outer_vertex_radius, 0, 360, 100, col);
    }
}

void plot_weights(color col) {
    vec source, target;
    f32 thickness;
    f32 scaling = 0.2;
    for (i32 i = 0; i < H; i++) {
        source = inp_pos;
        target = web_pos[i];
        thickness = thickness_amplitude*fabs(p[load_weight_index(i)]);
        if (thickness > thickness_min) {
            DrawLineEx(target, source, thickness, col);

        }
    }
    for (i32 i = H; i < V; i++) {
        target = web_pos[i];
        for (i32 j = 0; j < H; j++) {
            source = web_pos[s_from_t_p(i,j)];
            thickness = thickness_amplitude*fabs(p[weight_index(s_from_t_p(i,j),i)])/scaling;
            if (thickness > thickness_min) {
                DrawLineEx(target, source, thickness, col);

            }
            
            
        } 
    }
    for (i32 i = V - H; i < V; i++) {
        source = out_pos;
        target = web_pos[i];
        thickness = thickness_amplitude*fabs(p[drain_weight_index(i)])/scaling;
        if (thickness > thickness_min) {
            DrawLineEx(target, source, thickness, col);
        }
    }
}