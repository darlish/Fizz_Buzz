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
int select_color(T_COLOR c) {
    if(c == R) { return RED      ; }
    if(c == B) { return BLUE     ; }
    if(c == G) { return GREEN    ; }
    if(c == W) { return WHITE    ; }
    if(c == Y) { return YELLOW   ; }
    if(c == O) { return BROWN    ; }
    if(c == X) { return DARKGRAY ; }
}
//Prend la valeur d'une couleur et retourne la lettre correspondante.
char select_letter(T_COLOR c) {
    if(c == R) { return 'R' ; }
    if(c == B) { return 'B' ; }
    if(c == G) { return 'G' ; }
    if(c == W) { return 'W' ; }
    if(c == Y) { return 'Y' ; }
    if(c == O) { return 'O' ; }
    if(c == X) { return 'X' ; }
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
}

//Initialisation du Rubik's Cube tel qu'il est non-mélangé.
//On met dans chaque case la valeur associé à sa couleur.
void init_rubiks(T_RUBIKS *Cube) {
    Cube[0].Type_face = UP ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[0].Face[i][j] = W ;
        }
    }
    Cube[1].Type_face = LEFT ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[1].Face[i][j] = O ;
        }
    }
    Cube[2].Type_face = FRONT ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[2].Face[i][j] = G ;
        }
    }
    Cube[3].Type_face = RIGHT ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[3].Face[i][j] = R ;
        }
    }
    Cube[4].Type_face = BACK ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[4].Face[i][j] = B ;
        }
    }
    Cube[5].Type_face = DOWN ;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            Cube[5].Face[i][j] = Y ;
        }
    }
}

//Affichage 2D du Rubik's Cube sous la forme d'un patron de cube.
void display_rubiks(T_RUBIKS *Cube) {
    int i, j, k ;

    for(i = 0; i < 3; i++) {
        printf("       ");
        for (j = 0; j < 3; j++) {
            c_textcolor(select_color(Cube[0].Face[i][j])) ;
            printf("%c ", select_letter(Cube[0].Face[i][j])) ;
        }
        printf("\n") ;
    }
    printf("\n") ;
    for(i = 0; i < 3; i++) {
        for(k = 0; k < 4; k++) {
            for(j = 0; j < 3; j++) {
                c_textcolor(select_color(Cube[k+1].Face[i][j])) ;
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
            c_textcolor(select_color(Cube[5].Face[i][j])) ;
            printf("%c ", select_letter(Cube[5].Face[i][j])) ;
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
                Cube[k].Face[i][j] = X ;
            }
        }
        Cube[k].Face[1][1] = color[k] ;
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
        printf("Ligne   (1 ; 2 ; 3) :") ;
        scanf("%d", &l) ;
    } while(1 > l || l > 3) ;
//--------------------COLONNE-------------------//
    display_line() ;
    do {
        printf("Colonne (1 ; 2 ; 3) :") ;
        scanf("%d", &c) ;
    } while(1 > c || c > 3) ;
//--------------------COULEUR-------------------//
    T_COLOR d_color[6] = {W, O, G, R, B, Y} ;
    display_line() ;
    printf("WHITE: 1    ORANGE: 2    GREEN: 3     ") ;
    printf("RED: 4     BLUE: 5    YELLOW: 6\n") ;
    display_line() ;
    printf("Couleur:") ;
    do {
        scanf("%d", &color) ;
    } while(1 > color || color > 6) ;
    color = d_color[color-1] ;

    if(forbidden_rubiks(Cube, f-1, l-1, c-1, color)) {
        Cube[f-1].Face[l-1][c-1] = color ;
    } else {
        c_textcolor(4) ;
        display_line() ;
        printf("Il n'est pas possible de mettre cette couleur ici.\n") ;
    }
}

//Vérification des valeurs interdites.
// à finir ---------------------------------------------------------------------------------------
bool forbidden_rubiks(T_RUBIKS *Cube, int f, int l, int c, T_COLOR color) {
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
// à tester --------------------------------------------------------------------------------------
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
    *Cube = NULL ;
}

//Choix de l'utilisateur pour le mouvement du Rubik's Cube
void move_rubiks(T_RUBIKS *Cube) {
    int rep, face, sens, move ;

    display_line();
    printf("1: Move a face                               2: Move the Rubik's Cube\n") ;
    display_line() ;
    do {
        printf("Action:") ;
        scanf("%d", &rep) ;
    } while(rep != 1 && rep != 2) ;

    if(rep == 1) {
        display_line();
        printf("UP: 1     LEFT: 2      FRONT: 3     ");
        printf("RIGHT: 4      BACK: 5      DOWN:6\n");
        do {
            display_line();
            printf("Face to move:");
            scanf("%d", &face);
        } while (1 > face || face > 6);
        do {
            display_line();
            printf("|           CLOCKWISE: 1          ");
            printf("        ANTICLOCKWISE: 2          |\n");
            display_line();
            printf("Direction:");
            scanf("%d", &sens);
        } while (sens != 1 && sens != 2);
        do {
            display_line();
            printf("Rotation (1 ; 2) :");
            scanf("%d", &move);
        } while (move != 1 && move != 2);
        switch (face) {
            case 1:
                if (sens == 1) { UP_clockwise(Cube, move); }
                else { UP_anticlockwise(Cube, move); }
                break;
            case 2:
                if (sens == 1) { LEFT_clockwise(Cube, move); }
                else { LEFT_anticlockwise(Cube, move); }
                break;
            case 3:
                if (sens == 1) { FRONT_clockwise(Cube, move); }
                else { FRONT_anticlockwise(Cube, move); }
                break;
            case 4:
                if (sens == 1) { RIGHT_clockwise(Cube, move); }
                else { RIGHT_anticlockwise(Cube, move); }
                break;
            case 5:
                if (sens == 1) { BACK_clockwise(Cube, move); }
                else { BACK_anticlockwise(Cube, move); }
                break;
            case 6:
                if (sens == 1) { DOWN_clockwise(Cube, move); }
                else { DOWN_anticlockwise(Cube, move); }
                break;
        }
    } else {
        display_line() ;
        printf("HORIZONTAL ROTATION: 1                          VERTICALE ROTATION: 2\n") ;
        do {
            display_line() ;
            printf("Move:") ;
            scanf("%d", &move) ;
        } while(move != 1 && move != 2) ;
        if(move == 1) { horizontal_rotation(Cube) ; }
        else { vertical_rotation(Cube) ; }
    }
}

// à modifier ------------------------------------------------------------------------------------
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

//Rotation de la face UP dans le sens horaire.
void UP_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[0].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[4].Face[0][2-i] ;
            tmp[1] = Cube[3].Face[0][2-i] ;
            tmp[2] = Cube[2].Face[0][2-i] ;
            tmp[3] = Cube[1].Face[0][2-i] ;

            Cube[4].Face[0][2-i] = tmp[3] ;
            Cube[3].Face[0][2-i] = tmp[0] ;
            Cube[2].Face[0][2-i] = tmp[1] ;
            Cube[1].Face[0][2-i] = tmp[2] ;
        }
    }
}
//Rotation de la face UP dans le sens anti-horaire.
void UP_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[0].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[4].Face[0][2-i] ;
            tmp[1] = Cube[3].Face[0][2-i] ;
            tmp[2] = Cube[2].Face[0][2-i] ;
            tmp[3] = Cube[1].Face[0][2-i] ;

            Cube[4].Face[0][2-i] = tmp[1] ;
            Cube[3].Face[0][2-i] = tmp[2] ;
            Cube[2].Face[0][2-i] = tmp[3] ;
            Cube[1].Face[0][2-i] = tmp[0] ;
        }
    }
}

//Rotation de la face LEFT dans le sens horaire.
void LEFT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[1].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[2-i][0] ;
            tmp[1] = Cube[2].Face[2-i][0] ;
            tmp[2] = Cube[5].Face[i][0]   ;
            tmp[3] = Cube[4].Face[2-i][2] ;

            Cube[0].Face[2-i][0] = tmp[3] ;
            Cube[2].Face[2-i][0] = tmp[0] ;
            Cube[5].Face[i][0]   = tmp[1] ;
            Cube[4].Face[2-i][2] = tmp[2] ;
        }
    }
}
//Rotation de la face LEFT dans le sens anti-horaire.
void LEFT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[1].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[2-i][0] ;
            tmp[1] = Cube[2].Face[2-i][0] ;
            tmp[2] = Cube[5].Face[i][0]   ;
            tmp[3] = Cube[4].Face[2-i][2] ;

            Cube[0].Face[2-i][0] = tmp[1] ;
            Cube[2].Face[2-i][0] = tmp[2] ;
            Cube[5].Face[i][0]   = tmp[3] ;
            Cube[4].Face[2-i][2] = tmp[0] ;
        }
    }
}

//Rotation de la face FRONT dans le sens horaire.
void FRONT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[2].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[2][i]   ;
            tmp[1] = Cube[3].Face[i][0]   ;
            tmp[2] = Cube[5].Face[0][2-i] ;
            tmp[3] = Cube[1].Face[2-i][2] ;

            Cube[0].Face[2][i]   = tmp[3] ;
            Cube[3].Face[i][0]   = tmp[0] ;
            Cube[5].Face[0][2-i] = tmp[1] ;
            Cube[1].Face[2-i][2] = tmp[2] ;
        }
    }
}
//Rotation de la face FRONT dans le sens anti-horaire.
void FRONT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[2].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[2][i]   ;
            tmp[1] = Cube[3].Face[i][0]   ;
            tmp[2] = Cube[5].Face[0][2-i] ;
            tmp[3] = Cube[1].Face[2-i][2] ;

            Cube[0].Face[2][i]   = tmp[1] ;
            Cube[3].Face[i][0]   = tmp[2] ;
            Cube[5].Face[0][2-i] = tmp[3] ;
            Cube[1].Face[2-i][2] = tmp[0] ;
        }
    }
}

//probleme --------------------------------------------------------------------------------------
//Rotation de la face RIGHT dans le sens horaire.
void RIGHT_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[3].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[2-i][0] ;
            tmp[1] = Cube[4].Face[i][2]   ;
            tmp[2] = Cube[5].Face[2-i][0] ;
            tmp[3] = Cube[2].Face[2-i][0] ;

            Cube[0].Face[2-i][2] = tmp[3] ;
            Cube[4].Face[i][0]   = tmp[0] ;
            Cube[5].Face[2-i][2] = tmp[1] ;
            Cube[2].Face[2-i][2] = tmp[2] ;
        }
    }
}
//Rotation de la face RIGHT dans le sens anti-horaire.
void RIGHT_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[3].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++){
            tmp[0] = Cube[0].Face[2-i][0] ;
            tmp[1] = Cube[4].Face[i][2]   ;
            tmp[2] = Cube[5].Face[2-i][0] ;
            tmp[3] = Cube[2].Face[2-i][0] ;

            Cube[0].Face[2-i][2] = tmp[1] ;
            Cube[4].Face[i][0]   = tmp[2] ;
            Cube[5].Face[2-i][2] = tmp[3] ;
            Cube[2].Face[2-i][2] = tmp[0] ;
        }
    }
}

//Rotation de la face BACK dans le sens horaire.
void BACK_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[4].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[0][2-i] ;
            tmp[1] = Cube[1].Face[i][0]   ;
            tmp[2] = Cube[5].Face[2][2-i] ;
            tmp[3] = Cube[3].Face[2-i][2] ;

            Cube[0].Face[0][2-i] = tmp[3] ;
            Cube[1].Face[i][0]   = tmp[0] ;
            Cube[5].Face[2][2-i] = tmp[1] ;
            Cube[3].Face[2-i][2] = tmp[2] ;
        }
    }
}
//Rotation de la face BACK dans le sens anti-horaire.
void BACK_anticlockwise(T_RUBIKS * Cube, int move) {
    self_rotate(Cube[4].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[0].Face[0][2-i] ;
            tmp[1] = Cube[1].Face[i][0]   ;
            tmp[2] = Cube[5].Face[2][2-i] ;
            tmp[3] = Cube[3].Face[2-i][2] ;

            Cube[0].Face[0][2-i] = tmp[1] ;
            Cube[1].Face[i][0]   = tmp[2] ;
            Cube[5].Face[2][2-i] = tmp[3] ;
            Cube[3].Face[2-i][2] = tmp[0] ;
        }
    }
}

//Rotation de la face DOWN dans le sens horaire.
void DOWN_clockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[5].Face, 1, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[2].Face[2][i] ;
            tmp[1] = Cube[3].Face[2][i] ;
            tmp[2] = Cube[4].Face[2][i] ;
            tmp[3] = Cube[1].Face[2][i] ;

            Cube[2].Face[2][i] = tmp[3] ;
            Cube[3].Face[2][i] = tmp[0] ;
            Cube[4].Face[2][i] = tmp[1] ;
            Cube[1].Face[2][i] = tmp[2] ;
        }
    }
}
//Rotation de la face DOWN dans le sens anti-horaire.
void DOWN_anticlockwise(T_RUBIKS *Cube, int move) {
    self_rotate(Cube[5].Face, 0, move) ;
    T_COLOR tmp[4] ;
    for (int k = 0; k < move; k++) {
        for (int i = 0; i < 3; i++) {
            tmp[0] = Cube[2].Face[2][i] ;
            tmp[1] = Cube[3].Face[2][i] ;
            tmp[2] = Cube[4].Face[2][i] ;
            tmp[3] = Cube[1].Face[2][i] ;

            Cube[2].Face[2][i] = tmp[1] ;
            Cube[3].Face[2][i] = tmp[2] ;
            Cube[4].Face[2][i] = tmp[3] ;
            Cube[1].Face[2][i] = tmp[0] ;
        }
    }
}

//Retourne le Rubik's Cube horizontalement.
void horizontal_rotation(T_RUBIKS *Cube) {
    T_COLOR tmp ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[3].Face[i][j] ;
            Cube[3].Face[i][j] = Cube[1].Face[i][j] ;
            Cube[1].Face[i][j] = tmp ;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[2].Face[i][j] ;
            Cube[2].Face[i][j] = Cube[4].Face[i][j] ;
            Cube[4].Face[i][j] = tmp ;
        }
    }
    self_rotate(Cube[0].Face, 1, 2) ;
    self_rotate(Cube[5].Face, 1, 2) ;
}
//Retourne le Rubik's Cube verticalement.
void vertical_rotation(T_RUBIKS *Cube) {
    T_COLOR tmp ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[0].Face[i][j] ;
            Cube[0].Face[i][j] = Cube[5].Face[i][j] ;
            Cube[5].Face[i][j] = tmp ;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp = Cube[2].Face[i][j] ;
            Cube[2].Face[i][j] = Cube[4].Face[i][j] ;
            Cube[4].Face[i][j] = tmp ;
        }
    }
    self_rotate(Cube[3].Face, 1, 2) ;
    self_rotate(Cube[1].Face, 1, 2) ;
}