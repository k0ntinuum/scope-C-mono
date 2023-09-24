typedef double f64;
typedef float f32;
typedef int i32;
typedef Color color;
typedef Vector2 vec;
//typedef struct {f64 r; f64 d;} d64;
const i32 MAX_H = 10; 
const i32 MAX_L = 10; 
const i32 MAX_V = MAX_L*MAX_H; 
const i32 MAX_P = MAX_V+2*MAX_H+(MAX_L-1)*MAX_H*MAX_H; 
const i32 MAX_D = 25; 

const f32 f_screen_width = 800;
const f32 f_screen_height = 600;
const f32 f_corner_x = 920;
const f32 f_corner_y = 400;
const f64 default_web_width = 800;
const f64 default_web_height = 550;
const f64 default_corner_x = 20;
const f64 default_corner_y = 200;

f64 (*activation[MAX_L+1]) (f64 x);
f64 (*derivative[MAX_L+1]) (f64 x);
int act_code[MAX_L+1] = {0};















