#include "rubiks.h"
#include "conio.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
    T_COLOR color[6] = {W, O, G, R, B, Y} ;
    for(k = 0; k < 6; k++) {
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                Cube[k].Face[i][j] = select_color(X) ;
            }
        }
        Cube[k].Face[1][1] = select_color(color[k]) ;
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
        printf("Ligne   (1 - 2 - 3) :") ;
        scanf("%d", &l) ;
    } while(1 > l || l > 3) ;
//--------------------COLONNE-------------------//
    display_line() ;
    do {
        printf("Colonne (1 - 2 - 3) :") ;
        scanf("%d", &c) ;
    } while(1 > c || c > 3) ;
//--------------------COULEUR-------------------//
    T_COLOR d_color[7] = {W, O, G, R, B, Y} ;
    display_line() ;
    printf("WHITE: 1    ORANGE: 2    GREEN: 3     ") ;
    printf("RED: 4     BLUE: 5    YELLOW: 6\n") ;
    display_line() ;
    printf("Couleur:") ;
    do {
        scanf("%d", &color) ;
    } while(1 > color || color > 6) ;
    color = select_color((d_color[color-1])) ;

    if(forbidden_rubiks(Cube, f-1, l-1, c-1, color)) {
        Cube[f-1].Face[l-1][c-1] = color ;
    } else {
        c_textcolor(4) ;
        display_line() ;
        printf("Il n'est pas possible de mettre cette couleur ici.\n") ;
    }
}

//Vérification des valeurs interdites.
bool forbidden_rubiks(T_RUBIKS *Cube, int f, int l, int c, int color) {
    int i, j, occ = 0 ;
//--------------------CENTRE--------------------//
    if(l == 1 && c == 1) { return false ; }
//---------------------COIN---------------------//
    if(l != 1 && c != 1) {
        for(i = 0; i < 6; i++) {
            for(j = 0; j < 2; j++) {
                if(Cube[i].Face[j*2][0] == color) { occ++ ; }
                if(Cube[i].Face[j*2][2] == color) { occ++ ; }
            }
        }
        if(occ >= 4) { return false ; }
    }
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 2; j++) {
            if(Cube[i].Face[j][j+1] == color) { occ++ ; }
            if(Cube[i].Face[j+1][j] == color) { occ++ ; }
        }
        if(occ >= 4) { return false ; }
    }

//--------------------ARRETE--------------------//

}

//Mélange aléatoire du Rubik's Cube.
void scramble_rubiks(T_RUBIKS *Cube, int move) {
    for (int i = 0; i < move; i++) {
        int face = rand()%6+1 ;
        int turn = rand()%3+1 ;
        switch (face) {
            case 1:
                FRONT_clockwise(Cube, turn) ;
                break ;
            case 2:
                RIGHT_clockwise(Cube, turn) ;
                break ;
            case 3:
                BACK_clockwise(Cube, turn) ;
                break ;
            case 4:
                LEFT_clockwise(Cube, turn) ;
                break ;
            case 5:
                UP_clockwise(Cube, turn) ;
                break ;
            case 6:
                DOWN_clockwise(Cube, turn) ;
                break ;
            default:
                break ;
        }
    }
}

//Libération de l'espace mémoire.
void free_rubiks(T_RUBIKS **Cube) {
    free(*Cube) ;
    for(int i = 0; i < 6; i++) {
        free(Cube[i]) ;
    }
    for(int j = 0; j < 6; j++) {
        free(Cube[j]) ;
    }
}

void self_rotate(T_COLOR Face[3][3], int clockwise, int type) {
    T_COLOR ** tmp = (T_COLOR**) malloc(4*sizeof(T_COLOR*)) ;
    for (int i = 0; i < 4; i++) tmp[i] = (T_COLOR*) malloc(3*sizeof(T_COLOR)) ;
    for (int i = 0; i < type; i++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) tmp[i][j] = clockwise?Face[2-j][i]:Face[j][2-i] ;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) Face[i][j] = tmp[i][j] ;
        }
    }
    for (int i = 0; i < 3; i++) {
        free(tmp[i]) ;
        tmp[i] = NULL ;
    }
    free(tmp) ;
    tmp = NULL ;
}

void UP_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[UP].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[BACK].Face[0][2-i]  ;
            tmp[1] = Cube[RIGHT].Face[0][2-i] ;
            tmp[2] = Cube[FRONT].Face[0][2-i] ;
            tmp[3] = Cube[LEFT].Face[0][2-i]  ;

            Cube[BACK].Face[0][2-i]  = tmp[3] ;
            Cube[RIGHT].Face[0][2-i] = tmp[0] ;
            Cube[FRONT].Face[0][2-i] = tmp[1] ;
            Cube[LEFT].Face[0][2-i]  = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void UP_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[UP].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[BACK].Face[0][2-i]  ;
            tmp[1] = Cube[RIGHT].Face[0][2-i] ;
            tmp[2] = Cube[FRONT].Face[0][2-i] ;
            tmp[3] = Cube[LEFT].Face[0][2-i]  ;

            Cube[BACK].Face[0][2-i]  = tmp[1] ;
            Cube[RIGHT].Face[0][2-i] = tmp[2] ;
            Cube[FRONT].Face[0][2-i] = tmp[3] ;
            Cube[LEFT].Face[0][2-i]  = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void LEFT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[LEFT].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[2-i][0]    ;
            tmp[1] = Cube[FRONT].Face[2-i][0] ;
            tmp[2] = Cube[DOWN].Face[i][0]    ;
            tmp[3] = Cube[BACK].Face[2-i][2]  ;

            Cube[UP].Face[2-i][0]    = tmp[3] ;
            Cube[FRONT].Face[2-i][0] = tmp[0] ;
            Cube[DOWN].Face[i][0]    = tmp[1] ;
            Cube[BACK].Face[2-i][2]  = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void LEFT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[LEFT].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[2-i][0]    ;
            tmp[1] = Cube[FRONT].Face[2-i][0] ;
            tmp[2] = Cube[DOWN].Face[i][0]    ;
            tmp[3] = Cube[BACK].Face[2-i][2]  ;

            Cube[UP].Face[2-i][0]    = tmp[1] ;
            Cube[FRONT].Face[2-i][0] = tmp[2] ;
            Cube[DOWN].Face[i][0]    = tmp[3] ;
            Cube[BACK].Face[2-i][2]  = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void FRONT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[FRONT].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[2][i]     ;
            tmp[1] = Cube[RIGHT].Face[i][0]  ;
            tmp[2] = Cube[DOWN].Face[0][2-i] ;
            tmp[3] = Cube[LEFT].Face[2-i][2] ;

            Cube[UP].Face[2][i]     = tmp[3] ;
            Cube[RIGHT].Face[i][0]  = tmp[0] ;
            Cube[DOWN].Face[0][2-i] = tmp[1] ;
            Cube[LEFT].Face[2-i][2] = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void FRONT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[FRONT].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[2][i]     ;
            tmp[1] = Cube[RIGHT].Face[i][0]  ;
            tmp[2] = Cube[DOWN].Face[0][2-i] ;
            tmp[3] = Cube[LEFT].Face[2-i][2] ;

            Cube[UP].Face[2][i]     = tmp[1] ;
            Cube[RIGHT].Face[i][0]  = tmp[2] ;
            Cube[DOWN].Face[0][2-i] = tmp[3] ;
            Cube[LEFT].Face[2-i][2] = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void RIGHT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[RIGHT].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[2-i][0]    ;
            tmp[1] = Cube[BACK].Face[i][2]    ;
            tmp[2] = Cube[DOWN].Face[2-i][0]  ;
            tmp[3] = Cube[FRONT].Face[2-i][0] ;

            Cube[UP].Face[2-i][2]    = tmp[3] ;
            Cube[BACK].Face[i][0]    = tmp[0] ;
            Cube[DOWN].Face[2-i][2]  = tmp[1] ;
            Cube[FRONT].Face[2-i][2] = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void RIGHT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[RIGHT].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++){
            tmp[0] = Cube[UP].Face[2-i][0]    ;
            tmp[1] = Cube[BACK].Face[i][2]    ;
            tmp[2] = Cube[DOWN].Face[2-i][0]  ;
            tmp[3] = Cube[FRONT].Face[2-i][0] ;

            Cube[UP].Face[2-i][2]    = tmp[1] ;
            Cube[BACK].Face[i][0]    = tmp[2] ;
            Cube[DOWN].Face[2-i][2]  = tmp[3] ;
            Cube[FRONT].Face[2-i][2] = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void BACK_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[BACK].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[0][2-i]    ;
            tmp[1] = Cube[LEFT].Face[i][0]    ;
            tmp[2] = Cube[DOWN].Face[2][2-i]  ;
            tmp[3] = Cube[RIGHT].Face[2-i][2] ;

            Cube[UP].Face[0][2-i]    = tmp[3] ;
            Cube[LEFT].Face[i][0]    = tmp[0] ;
            Cube[DOWN].Face[2][2-i]  = tmp[1] ;
            Cube[RIGHT].Face[2-i][2] = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void BACK_anticlockwise(T_RUBIKS * Cube, int move) {
    self_rotate(Cube[BACK].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[UP].Face[0][2-i]    ;
            tmp[1] = Cube[LEFT].Face[i][0]    ;
            tmp[2] = Cube[DOWN].Face[2][2-i]  ;
            tmp[3] = Cube[RIGHT].Face[2-i][2] ;

            Cube[UP].Face[0][2-i]    = tmp[1] ;
            Cube[LEFT].Face[i][0]    = tmp[2] ;
            Cube[DOWN].Face[2][2-i]  = tmp[3] ;
            Cube[RIGHT].Face[2-i][2] = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void DOWN_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[DOWN].Face, 1, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[FRONT].Face[2][i] ;
            tmp[1] = Cube[RIGHT].Face[2][i] ;
            tmp[2] = Cube[BACK].Face[2][i]  ;
            tmp[3] = Cube[LEFT].Face[2][i]  ;

            Cube[FRONT].Face[2][i] = tmp[3] ;
            Cube[RIGHT].Face[2][i] = tmp[0] ;
            Cube[BACK].Face[2][i]  = tmp[1] ;
            Cube[LEFT].Face[2][i]  = tmp[2] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}
void DOWN_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[DOWN].Face, 0, move) ;
    T_COLOR * tmp = (T_COLOR*) malloc(4*sizeof(T_COLOR)) ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[FRONT].Face[2][i] ;
            tmp[1] = Cube[RIGHT].Face[2][i] ;
            tmp[2] = Cube[BACK].Face[2][i]  ;
            tmp[3] = Cube[LEFT].Face[2][i]  ;

            Cube[FRONT].Face[2][i] = tmp[1] ;
            Cube[RIGHT].Face[2][i] = tmp[2] ;
            Cube[BACK].Face[2][i]  = tmp[3] ;
            Cube[LEFT].Face[2][i]  = tmp[0] ;
        }
    }
    free(tmp) ;
    tmp = NULL ;
}

void horizontal_rotation(T_RUBIKS *Cube) {
    T_COLOR tmp ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[RIGHT].Face[i] [j] ;
            Cube[RIGHT].Face[i] [j]= Cube[LEFT].Face[i] [j] ;
            Cube[LEFT].Face[i] [j] = tmp ;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[FRONT].Face[i] [j] ;
            Cube[FRONT].Face[i] [j]= Cube[BACK].Face[i] [j] ;
            Cube[BACK].Face[i] [j] = tmp ;
        }
    }
    self_rotate(Cube[UP].Face, 1, 2) ;
    self_rotate(Cube[DOWN].Face, 1, 2) ;
}
void vertical_rotation(T_RUBIKS *Cube) {
    T_COLOR tmp ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[UP].Face[i] [j] ;
            Cube[UP].Face[i] [j]= Cube[DOWN].Face[i] [j] ;
            Cube[DOWN].Face[i] [j] = tmp ;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[FRONT].Face[i] [j] ;
            Cube[FRONT].Face[i] [j]= Cube[BACK].Face[i] [j] ;
            Cube[BACK].Face[i] [j] = tmp ;
        }
    }
    self_rotate(Cube[RIGHT].Face, 1, 2) ;
    self_rotate(Cube[LEFT].Face, 1, 2) ;
}