#include <stdio.h>
#include "Date2.h"
#include "Date.c"
//#include "Etudiant.h"
#include "classEtud.h"
//#include "classEtud.c"
#include <stdlib.h>

// tp 7

int main( void ){

    ETUDIANT *T;// mon_etudiant ;
    //T=&mon_etudiant;


    int N;
    CLASSE_ETUD *classe;
    classe = (CLASSE_ETUD*) malloc(sizeof (CLASSE_ETUD)); //////
//    printf("Saisir le nombre d'etudiants dans la classe");
//    scanf("%d",& N);
//    T = (ETUDIANT *) malloc (N * sizeof (ETUDIANT));
//
//
//    lireTabEtudiants(T, N );
//    afficherTabEtudiants( T, N) ;
//    printf("La moyenne de la classe est: %lf\n",moyTabEtudiants(T, N));
//    printf("L'indice de la meilleur moyenne est: %d\n",meilleurMoy(T,N));
    //printf("L'indice du plus jeune est: %d \n",plusJeuneEtudiant(T,N)) ;

    lireClasse(classe) ;

    afficherClasse(classe) ;

    libClasseEtud(classe) ;


    return 0;
}
