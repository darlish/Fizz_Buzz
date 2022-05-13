#ifndef L1_PROJECT_C_RUBIKS_H
#define L1_PROJECT_C_RUBIKS_H
#endif //L1_PROJECT_C_RUBIKS_H
#ifndef MAIN_C_CONIO_H
#define MAIN_C_CONIO_H

#endif //MAIN_C_CONIO_H

typedef enum { FRONT, BACK, UP, DOWN, RIGHT, LEFT } T_SIDE ; // Def de enum T_SIDE comme dans le pdf

typedef enum { R, B, G, W, Y, O } T_COLOR ; // Def de enum T_COLOR comme dans le pdf

/*
* Définition de la structure du Rubik's Cube comportant 2 champs:
*   -Le tableau des case de dim 3*3 et de type énuméré T_COLOR
*   -L'identifiant de la face de type énuméré T_SIDE
*/
typedef struct{T_COLOR face[3][3]; T_SIDE Type_face;} Rubiks;

void select_color();
