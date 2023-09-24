i32 H,L,V,P;
i32 D = 9;
f64 p[MAX_P] = {0};
f64 q[MAX_P] = {0};    
f64 g[MAX_P]= {0};  
f64 u[MAX_V]= {0};  
f64 v[MAX_V]= {0};  
f64 m[MAX_V]= {0};  
f64 d[MAX_V]= {0}; 
f64 data[MAX_D][2]= {0};
f64 data_y_mag = 2.0;
f64 last_in_fwd = 0.0;
f64 last_out_fwd = 0.0;
f64 last_in_ret = 0.0;
f64 rate = 0.01;
vec inp_pos, out_pos, web_pos[MAX_V];

const f64 pi = 3.14159265358979323846;
const i32 screen_width = 2000;
const i32 screen_height = 1000;
const f64 plot_x_min= -1.0;
const f64 plot_x_max= 1.0;
const f64 plot_y_min = -1.0;
const f64 plot_y_max = 1.0;
const f64 data_x_min = -1.0;
const f64 data_x_max = 1.0;
const f64 data_y_min = 0;
const f64 data_y_max = 100;

const f64 hppu = f_screen_width / (plot_x_max - plot_x_min);
const f64 vppu = f_screen_height / (plot_y_max - plot_y_min);
const color f_color = (color){.r = 200, .g = 200, .b = 200, .a = 100};
const f32 f_thickness = 12.0;
const color data_color = (color){.r = 255, .g = 255, .b = 255, .a = 100};
const color weight_color = (color){.r = 155, .g = 155, .b = 155, .a = 60};
const color vertex_color = (color){.r = 255, .g = 255, .b = 255, .a = 190};
const color act_color = (color){.r = 255, .g = 255, .b = 255, .a = 200};
const color rate_color = (color){.r = 255, .g = 255, .b = 255, .a = 200};
const i32 plot_segments = 5000;
const f64 plot_gap = (plot_x_max - plot_x_min) / (f64)plot_segments;
const f64 data_radius = 10.0;
const f64 inner_vertex_radius = 5.0;
const f64 outer_vertex_radius = 10.0;

const f64 data_spread = 1.0;
const f64 thickness_amplitude = 4.0;
const f64 thickness_min = 2.0;




