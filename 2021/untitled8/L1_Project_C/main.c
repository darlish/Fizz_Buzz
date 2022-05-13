#include "rubiks.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
//-----------------AFFICHAGE-----------------//
    display_line() ;
    printf("|                    ") ;
    printf("WELCOME TO RUBIK'S PROGRAM") ;
    printf("                    |\n") ;
    display_line() ;
//------------INITIALISATION-CUBE------------//
    T_RUBIKS *Cube ;
    create_rubiks(&Cube) ;
    init_rubiks(Cube) ;
    display_rubiks(Cube) ;
//-------------------------------------------//
    int rep, move, face ;

    do {
        display_menu() ;
        scanf("%d", &rep) ;
        switch(rep) {
            //Mélange du Rubik's Cube.
            case 1:
                display_line() ;
                do {
                    printf("Combien de mouvements:");
                    scanf("%d", &move);
                } while(move < 1) ;
                scramble_rubiks(Cube, move) ;
                break ;
            //Réinitialisation du Rubik's Cube (non-mélangé).
            case 2:
                init_rubiks(Cube) ;
                break ;
            //Laisser l'utilisateur jouer et bouger le Rubik's Cube.
            case 3:
                move_rubiks(Cube) ;
                break ;
            //Griser le Rubik's Cube (pour laisser l'utilisateur le remplir).
            case 4:
                blank_rubiks(Cube) ;
                break ;
            //Laisser l'utilisateur remplir le Rubik's Cube case par case.
            case 5:
                fill_rubiks(Cube) ;
                break ;
            //Le programme résout le Rubik's Cube (en 3 étapes ou l'utilisateur peut arrêter).
            case 6:
                break ;
        }
        display_line() ;
        display_rubiks(Cube) ;

    } while(0 < rep && rep < 7) ;

    c_textcolor(11) ;
    display_line() ;
    printf("Fermeture du programme ...\n") ;
    display_line() ;
    free_rubiks(&Cube) ;
    Cube = NULL ;
    printf("test if ok") ;

/*----------TEST----------//
    T_RUBIKS *Cube ;
    create_rubiks(&Cube) ;
    init_rubiks(Cube) ;
    display_rubiks(Cube) ;
    display_menu() ;
//----------TEST----------*/

    return 0 ;
}