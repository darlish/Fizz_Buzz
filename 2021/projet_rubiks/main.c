#include <stdio.h>
#include <stdlib.h>
//#include "conio.h"
#include "conio.c"

#define I 6
#define J 3
#define K 3

int main(void){
    Rubiks cube[I];

    // initialisation des faces
    for(int i = 0; i<I; i++){
        cube[i].Type_face = DOWN; // Affectation d'un identifiant de face à chaque face du cube(pour l'instant toutes les mêmes = Down)
        for(int j = 0; j<J; j++){
            for(int k = 0; k<K; k++){
                cube[i].face[j][k] = B; // Affectation de la couleur de chaque face (pour l'instant toutes les mêmes = Orange)
            }
        }
    }

    // Affichage du résultat de l'initialisation
    for(int i = 0; i<I; i++){
        fprintf(stderr, "\n================FACE %d=====================\n", i+1); // Print de debug numéro de la face
        fprintf(stderr, "FACE ID: %d\nFACE COLOR:\n", (int) cube[i].Type_face); // Debug de l'identifiant de face
        for(int j = 0; j<J; j++){
            for(int k = 0; k<K; k++){
                fprintf(stderr, "%d", (int) cube[i].face[j][k]); // Debug de l'affectation des couleurs
            }
            printf("\n");
        }
    }




    return 0;
}

