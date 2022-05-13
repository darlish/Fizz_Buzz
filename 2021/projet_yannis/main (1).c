#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rubiks.c"

int main(void){
    srand(time(NULL));
    Rubiks * cube = create_rubiks();
    init_rubiks(cube);
    printf("\n====== Rubik's cube initialise ======\n");
    display_rubiks(cube);
    scramble_rubiks(cube, 100);
    printf("\n====== Rubik's cube Melange ======\n");
    display_rubiks(cube);
    free_rubiks(cube);
    return 0;
}