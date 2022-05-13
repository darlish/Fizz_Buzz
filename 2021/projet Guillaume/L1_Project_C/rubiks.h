#ifndef L1_PROJECT_C_RUBIKS_H
#define L1_PROJECT_C_RUBIKS_H

typedef enum { FRONT, BACK, UP, DOWN, RIGHT, LEFT } T_SIDE ; //Faces du Rubik's Cube
typedef enum { R, B, G, W, Y, O, X } T_COLOR ;                  //Couleurs du Rubik's Cube

typedef struct RBK {
    T_SIDE Type_face ;
    T_COLOR Face[3][3] ;
} T_RUBIKS ;

//--------------User-Interface---------------//
void display_line() ;
void display_menu() ;

//--------------------3.1--------------------//
T_COLOR select_color(T_COLOR c) ;
char select_letter(int c) ;
int side_to_index(T_SIDE Type_face) ;

//--------------------3.2--------------------//
void create_rubiks(T_RUBIKS **Cube) ;
void init_rubiks(T_RUBIKS *Cube) ;
void display_rubiks(T_RUBIKS *Cube) ;
void blank_rubiks(T_RUBIKS *Cube) ;
void fill_rubiks(T_RUBIKS *Cube) ;
void scramble_rubiks(T_RUBIKS *Cube) ;
//void free_rubiks(T_RUBIKS **Cube) ;

//--------------------3.3--------------------//

#endif //L1_PROJECT_C_RUBIKS_H