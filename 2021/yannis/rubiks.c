#include <string.h>
#include <aclapi.h>
#include "rubiks.h"
#include <stdio.h>
#include <stdlib.h>
int select_color (char * color){return strchr(COLOR_STRING, color[0]) - COLOR_STRING;}

int side_to_index(char * face){return strchr(SIDE_STRING, face[0]) - SIDE_STRING;}

Rubiks * create_rubiks(void){
    Rubiks * cube = (Rubiks*) malloc(6*sizeof(Rubiks));
    for (int i = 0; i < 6; i++)
    {
        cube[i].Type_face = (T_SIDE*) malloc(sizeof(T_SIDE));
        cube[i].face = (T_COLOR **) malloc(3*sizeof(T_COLOR*));
        for (int j = 0; j < 3; j++) cube[i].face[j] = (T_COLOR *) malloc(3*sizeof(T_COLOR));
    }
    return cube;
}

void init_rubiks(Rubiks * cube){
    for (int i = 0; i < 6; i++)
    {
        *(cube[i].Type_face) = i;
        for (int j = 0; j < 3; j++)
        {
            for(int k = 0; k<3; k++){
                switch (*(cube[i].Type_face))
                {
                    case 0:
                        cube[i].face[j][k] = W;
                        break;
                    case 1:
                        cube[i].face[j][k] = Y;
                        break;
                    case 2:
                        cube[i].face[j][k] = B;
                        break;
                    case 3:
                        cube[i].face[j][k] = G;
                        break;
                    case 4:
                        cube[i].face[j][k] = R;
                        break;
                    default:
                        cube[i].face[j][k] = O;
                        break;
                }
            }
        }
    }
}

void display_rubiks(Rubiks * cube){
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 3; j++) printf("%d", cube[UP].face[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) printf("%d", cube[LEFT].face[i][j]);
        printf(" ");
        for (int j = 0; j < 3; j++) printf("%d", cube[FRONT].face[i][j]);
        printf(" ");
        for (int j = 0; j < 3; j++) printf("%d", cube[RIGHT].face[i][j]);
        printf(" ");
        for (int j = 0; j < 3; j++) printf("%d", cube[BACK].face[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 3; j++) printf("%d", cube[DOWN].face[i][j]);
        printf("\n");
    }
}

void blank_rubiks(Rubiks * cube){
    for (int i = 0; i < 6; i++)
    {
        *(cube[i].Type_face) = i;
        for (int j = 0; j < 3; j++)
        {
            for(int k = 0; k<3; k++)    cube[i].face[j][k] = LG;
        }
    }
}

void free_rubiks(Rubiks * cube){
    for (int i = 0; i < 6; i++)
    {
        free(cube[i].Type_face);
        cube[i].Type_face = NULL;
        for (int j = 0; j < 3; j++){
            free(cube[i].face[j]);
            cube[i].face[j] = NULL;
        }
        free(cube[i].face);
        cube[i].face = NULL;
    }
    free(cube);
    cube = NULL;
}

void self_rotate(T_COLOR ** face, bool clockwise, bool type){
    T_COLOR ** tmp = (T_COLOR**) malloc(4*sizeof(T_COLOR*));
    for (int i = 0; i < 4; i++) tmp[i] = (T_COLOR*) malloc(3*sizeof(T_COLOR));
    for (int i = 0; i < type; i++){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) tmp[i][j] = clockwise?face[2-j][i]:face[j][2-i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) face[i][j] = tmp[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        free(tmp[i]);
        tmp[i] = NULL;
    }
    free(tmp);
    tmp = NULL;
}

void FRONT_clockwise(Rubiks * cube, int type){
    self_rotate(cube[FRONT].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2][i];
            tmp[1] = cube[RIGHT].face[i][0];
            tmp[2] = cube[DOWN].face[0][2-i];
            tmp[3] = cube[LEFT].face[2-i][2];

            cube[UP].face[2][i]     = tmp[3];
            cube[RIGHT].face[i][0]  = tmp[0];
            cube[DOWN].face[0][2-i] = tmp[1];
            cube[LEFT].face[2-i][2] = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void FRONT_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[FRONT].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2][i];
            tmp[1] = cube[RIGHT].face[i][0];
            tmp[2] = cube[DOWN].face[0][2-i];
            tmp[3] = cube[LEFT].face[2-i][2];

            cube[UP].face[2][i]     = tmp[1];
            cube[RIGHT].face[i][0]  = tmp[2];
            cube[DOWN].face[0][2-i] = tmp[3];
            cube[LEFT].face[2-i][2] = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

/*
********    Prooposition d'une fonction FRONT_rotation gérant les deux sens de rotation     ***********
                                (Généralisable à toutes les faces)

void FRONT_clockwise(Rubiks * cube, bool clockwise, bool type){
    self_rotate(cube[FRONT].face, clockwise, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2][i];
            tmp[1] = cube[RIGHT].face[i][0];
            tmp[2] = cube[DOWN].face[0][2-i];
            tmp[3] = cube[LEFT].face[2-i][2];

            cube[UP].face[2][i]     = clockwise?tmp[3]:tmp[1];
            cube[RIGHT].face[i][0]  = clockwise?tmp[0]:tmp[2];
            cube[DOWN].face[0][2-i] = clockwise?tmp[1]:tmp[3];
            cube[LEFT].face[2-i][2] = clockwise?tmp[2]:tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

*/

void RIGHT_clockwise(Rubiks * cube, bool type){
    self_rotate(cube[RIGHT].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2-i][0];
            tmp[1] = cube[BACK].face[i][2];
            tmp[2] = cube[DOWN].face[2-i][0];
            tmp[3] = cube[FRONT].face[2-i][0];

            cube[UP].face[2-i][2]    = tmp[3];
            cube[BACK].face[i][0]    = tmp[0];
            cube[DOWN].face[2-i][2]  = tmp[1];
            cube[FRONT].face[2-i][2] = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void RIGHT_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[RIGHT].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2-i][0];
            tmp[1] = cube[BACK].face[i][2];
            tmp[2] = cube[DOWN].face[2-i][0];
            tmp[3] = cube[FRONT].face[2-i][0];

            cube[UP].face[2-i][2]    = tmp[1];
            cube[BACK].face[i][0]    = tmp[2];
            cube[DOWN].face[2-i][2]  = tmp[3];
            cube[FRONT].face[2-i][2] = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

void BACK_clockwise(Rubiks * cube, bool type){
    self_rotate(cube[BACK].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[0][2-i];
            tmp[1] = cube[LEFT].face[i][0];
            tmp[2] = cube[DOWN].face[2][2-i];
            tmp[3] = cube[RIGHT].face[2-i][2];

            cube[UP].face[0][2-i]    = tmp[3];
            cube[LEFT].face[i][0]    = tmp[0];
            cube[DOWN].face[2][2-i]  = tmp[1];
            cube[RIGHT].face[2-i][2] = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void BACK_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[BACK].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[0][2-i];
            tmp[1] = cube[LEFT].face[i][0];
            tmp[2] = cube[DOWN].face[2][2-i];
            tmp[3] = cube[RIGHT].face[2-i][2];

            cube[UP].face[0][2-i]    = tmp[1];
            cube[LEFT].face[i][0]    = tmp[2];
            cube[DOWN].face[2][2-i]  = tmp[3];
            cube[RIGHT].face[2-i][2] = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

void LEFT_clockwise(Rubiks * cube, bool type){
    self_rotate(cube[LEFT].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2-i][0];
            tmp[1] = cube[FRONT].face[2-i][0];
            tmp[2] = cube[DOWN].face[i][0];
            tmp[3] = cube[BACK].face[2-i][2];

            cube[UP].face[2-i][0]    = tmp[3];
            cube[FRONT].face[2-i][0] = tmp[0];
            cube[DOWN].face[i][0]    = tmp[1];
            cube[BACK].face[2-i][2]  = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void LEFT_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[LEFT].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[UP].face[2-i][0];
            tmp[1] = cube[FRONT].face[2-i][0];
            tmp[2] = cube[DOWN].face[i][0];
            tmp[3] = cube[BACK].face[2-i][2];

            cube[UP].face[2-i][0]    = tmp[1];
            cube[FRONT].face[2-i][0] = tmp[2];
            cube[DOWN].face[i][0]    = tmp[3];
            cube[BACK].face[2-i][2]  = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

void UP_clockwise(Rubiks * cube, bool type){
    self_rotate(cube[UP].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[BACK].face[0][2-i];
            tmp[1] = cube[RIGHT].face[0][2-i];
            tmp[2] = cube[FRONT].face[0][2-i];
            tmp[3] = cube[LEFT].face[0][2-i];

            cube[BACK].face[0][2-i]  = tmp[3];
            cube[RIGHT].face[0][2-i] = tmp[0];
            cube[FRONT].face[0][2-i] = tmp[1];
            cube[LEFT].face[0][2-i]  = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void UP_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[UP].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[BACK].face[0][2-i];
            tmp[1] = cube[RIGHT].face[0][2-i];
            tmp[2] = cube[FRONT].face[0][2-i];
            tmp[3] = cube[LEFT].face[0][2-i];

            cube[BACK].face[0][2-i]  = tmp[1];
            cube[RIGHT].face[0][2-i] = tmp[2];
            cube[FRONT].face[0][2-i] = tmp[3];
            cube[LEFT].face[0][2-i]  = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

void DOWN_clockwise(Rubiks * cube, bool type){
    self_rotate(cube[DOWN].face, 1, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[FRONT].face[2][i];
            tmp[1] = cube[RIGHT].face[2][i];
            tmp[2] = cube[BACK].face[2][i];
            tmp[3] = cube[LEFT].face[2][i];

            cube[FRONT].face[2][i] = tmp[3];
            cube[RIGHT].face[2][i] = tmp[0];
            cube[BACK].face[2][i]  = tmp[1];
            cube[LEFT].face[2][i]  = tmp[2];
        }
    }
    free(tmp);
    tmp = NULL;
}

void DOWN_anticlockwise(Rubiks * cube, bool type){
    self_rotate(cube[DOWN].face, 0, type);
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR));
    for (int k = 0; k < type; k++)
    {
        for (int i = 0; i < 3; i++){
            tmp[0] = cube[FRONT].face[2][i];
            tmp[1] = cube[RIGHT].face[2][i];
            tmp[2] = cube[BACK].face[2][i];
            tmp[3] = cube[LEFT].face[2][i];

            cube[FRONT].face[2][i] = tmp[1];
            cube[RIGHT].face[2][i] = tmp[2];
            cube[BACK].face[2][i]  = tmp[3];
            cube[LEFT].face[2][i]  = tmp[0];
        }
    }
    free(tmp);
    tmp = NULL;
}

void scramble_rubiks(Rubiks * cube, int move){
    for (int i = 0; i < move; i++)
    {
        int move = rand()%6+1;
        int turn = rand()%4+1;
        switch (move%4)
        {
            case 1:
                FRONT_clockwise(cube, turn);
                break;
            case 2:
                RIGHT_clockwise(cube, turn);
                break;
            case 3:
                BACK_clockwise(cube, turn);
                break;
            case 4:
                LEFT_clockwise(cube, turn);
                break;
            case 5:
                UP_clockwise(cube, turn);
                break;
            case 6:
                DOWN_clockwise(cube, turn);
                break;
            default:
                break;
        }
    }

}

void horizontal_rotation(Rubiks * cube){
    T_COLOR ** tmp = cube[FRONT].face;
    cube[FRONT].face = cube[BACK].face;
    cube[BACK].face = tmp;
    tmp = cube[RIGHT].face;
    cube[RIGHT].face = cube[LEFT].face;
    cube[LEFT].face = tmp;

    self_rotate(cube[UP].face, 1, 2);
    self_rotate(cube[DOWN].face, 1, 2);
}

void vertical_rotation(Rubiks * cube){
    T_COLOR ** tmp = cube[UP].face;
    cube[UP].face = cube[DOWN].face;
    cube[DOWN].face = tmp;
    tmp = cube[FRONT].face;
    cube[FRONT].face = cube[BACK].face;
    cube[BACK].face = tmp;

    self_rotate(cube[LEFT].face, 1, 2);
    self_rotate(cube[RIGHT].face, 1, 2);
}