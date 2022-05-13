//fichier contenant les implémentations des fonction .c
#include<stdio.h>
#include <stdlib.h>
#include "fichier.h"
/*void afficherAleatoire(int a, int b)
{

    int num = (rand() %(b - a + 1)) + a;
    printf("%d ", num);
}
void saisie_valeurs(int *a,int *b){
    int r;
    printf("Borne inf :");
    r = scanf("%d",a);
    while(r !=1){
        r = getchar();
        printf("Erreur, il faut saisir un entier ");
        r = scanf("%d",a);
    }
    printf("Borne sup :");
    r = scanf("%d",b);
    while(r !=1){
        r = getchar();
        printf("Erreur, il faut saisir un entier ");
        r = scanf("%d",b);
    }
}


   int addition(int *a, int *b, int *result) {
        *result = *a + *b;
    }

    int soustraction(int *a, int *b, int *result) {
        *result = *a - *b;
    }

    int division(int *a, int *b, int *result) {
        *result = (*a / *b);
    }

    int multiplication(int *a, int *b, int *result) {
        *result = (*a * *b);
    }


}











