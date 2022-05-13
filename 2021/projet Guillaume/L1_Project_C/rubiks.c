#include "rubiks.h"
#include "conio.h"
#include <stdlib.h>
#include <stdio.h>

//Affiche la ligne de tiret. Pour moins de répétitions, on en fait une fonction.
void display_line() {
    for(int i = 0; i < 3; i++) {
        printf("-----------------------") ;
    }
    printf("\n") ;
}

//Affiche le menu avec les différentes options.
void display_menu() {
    c_textcolor(7) ;
    display_line() ;
    printf("1: Scramble    2: Reset    3: Play    ") ;
    printf("4: Blank    5: Fill    6: Solve    \n") ;
    display_line() ;
    printf("Action:") ;
}

//Prend une couleur et retourne sa valeur.
T_COLOR select_color(T_COLOR c) {
    if(c == R) { return (T_COLOR) RED      ; }
    if(c == B) { return (T_COLOR) BLUE     ; }
    if(c == G) { return (T_COLOR) GREEN    ; }
    if(c == W) { return (T_COLOR) WHITE    ; }
    if(c == Y) { return (T_COLOR) YELLOW   ; }
    if(c == O) { return (T_COLOR) BROWN    ; }
    if(c == X) { return (T_COLOR) DARKGRAY ; }
}

//Prend la valeur d'une couleur et retourne la lettre correspondante.
char select_letter(int c) {
    if(c == 4)  { return 'R' ; }
    if(c == 1)  { return 'B' ; }
    if(c == 2)  { return 'G' ; }
    if(c == 15) { return 'W' ; }
    if(c == 14) { return 'Y' ; }
    if(c == 6)  { return 'O' ; }
    if(c == 8)  { return 'X' ; }
}

//Prend un nom de face et retourne sa position.
int side_to_index(T_SIDE Face) {
    if(Face == UP)    { return 0 ; }
    if(Face == LEFT)  { return 1 ; }
    if(Face == FRONT) { return 2 ; }
    if(Face == RIGHT) { return 3 ; }
    if(Face == BACK)  { return 4 ; }
    if(Face == DOWN)  { return 5 ; }
}

//Créer le cube (Tableau 3D) dynamiquement.
void create_rubiks(T_RUBIKS **Cube) {
    *Cube = (T_RUBIKS*) malloc(6*sizeof(T_RUBIKS)) ;
    for(int i = 0; i < 6; i++) {
        Cube[i] = (T_RUBIKS*) (T_RUBIKS**) malloc(sizeof(T_SIDE*) + sizeof(T_COLOR*)) ;
    }
//------------------------------USELESS-je-pense-----------------------------------------------------//
    /*for(int j = 0; j < 6; j++) {
        Cube[j] = (T_RUBIKS*) (T_RUBIKS*) malloc(sizeof(T_COLOR)) ;
    }*/
}

//Initialisation du Rubik's Cube tel qu'il est non-mélangé.
//On met dans chaque case la valeur associé à sa couleur.
void init_rubiks(T_RUBIKS *Cube) {
    Cube[0].Type_face = side_to_index(UP) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[0].Face[i][j] = select_color(W) ;
        }
    }
    Cube[1].Type_face = side_to_index(LEFT) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[1].Face[i][j] = select_color(O) ;
        }
    }
    Cube[2].Type_face = side_to_index(FRONT) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[2].Face[i][j] = select_color(G) ;
        }
    }
    Cube[3].Type_face = side_to_index(RIGHT) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[3].Face[i][j] = select_color(R) ;
        }
    }
    Cube[4].Type_face = side_to_index(BACK) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[4].Face[i][j] = select_color(B) ;
        }
    }
    Cube[5].Type_face = side_to_index(DOWN) ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[5].Face[i][j] = (select_color(Y)) ;
        }
    }
}

//Affichage 2D du Rubik's Cube sous la forme d'un patron de cube.
void display_rubiks(T_RUBIKS *Cube) {
    int i, j, k ;

    for(i = 0; i < 3; i++) {
        printf("       ");
        for (j = 0; j < 3; j++) {
            c_textcolor(Cube[0].Face[i][j]);
            printf("%c ", select_letter(Cube[0].Face[i][j]));
        }
        printf("\n") ;
    }
    printf("\n") ;
    for(i = 0; i < 3; i++) {
        for(k = 0; k < 4; k++) {
            for(j = 0; j < 3; j++) {
                c_textcolor(Cube[k+1].Face[i][j]) ;
                printf("%c ", select_letter(Cube[k+1].Face[i][j])) ;
            }
            printf(" ") ;
        }
        printf("\n") ;
    }
    printf("\n") ;
    for(i = 0; i < 3; i++) {
        printf("       ");
        for (j = 0; j < 3; j++) {
            c_textcolor(Cube[5].Face[i][j]);
            printf("%c ", select_letter(Cube[5].Face[i][j]));
        }
        printf("\n") ;
    }
    printf("\n") ;
}

//Initialisation du Rubik's Cube sans couleur.
//On met dans chaque case la valeur de la couleur grise.
void blank_rubiks(T_RUBIKS *Cube) {
    int k, i, j ;

    for(k = 0; k < 6; k++) {
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                Cube[k].Face[i][j] = select_color(X) ;
            }
        }
    }
}

//Affectation manuelle des couleurs...
void fill_rubiks(T_RUBIKS *Cube) {
    int rep, f, l, c, color ;
//---------------------FACE---------------------//
    display_line() ;
    printf("UP: 1     LEFT: 2      FRONT: 3     ") ;
    printf("RIGHT: 4      BACK: 5      DOWN:6\n") ;
    display_line() ;
    do {
        printf("Face:");
        scanf("%d", &f);
    } while(1 > f || f > 6) ;
//---------------------LIGNE--------------------//
    display_line() ;
    do {
        printf("Ligne (1 - 2 - 3):") ;
        scanf("%d", &l) ;
    } while(1 > l || l > 3) ;
//--------------------COLONNE-------------------//
    display_line() ;
    do {
        printf("Colonne (1 - 2 - 3):") ;
        scanf("%d", &c) ;
    } while(1 > c || c > 3) ;
//--------------------COULEUR-------------------//
    T_COLOR d_color[7] = {W, O, G, R, B, Y} ;
    display_line() ;
    printf("WHITE: 1     ORANGE: 2     GREEN: 3     ") ;
    printf("RED: 4     BLUE: 5     YELLOW: 6\n") ;
    do {
        scanf("%d", &color) ;
    } while(1 > color || color > 6) ;

    Cube[f-1].Face[l-1][c-1] = select_color(d_color[color-1]) ;
}

//Mélange aléatoire du Rubik's Cube.
void scramble_rubiks(T_RUBIKS *Cube) {

}

//Libération de l'espace mémoire.
/*void free_rubiks(T_RUBIKS **Cube) {
    free(*Cube) ;
    for(int i = 0; i < 6; i++) {
        free(Cube[i]) ;
    }
    for(int j = 0; j < 6; j++) {
        free(Cube[j]) ;
    }
}*/