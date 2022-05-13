//
// Created by miche on 19/03/2022.
//

#ifndef MAIN_C_CLASSETUD_H
#define MAIN_C_CLASSETUD_H
#include "Etudiant.h"
#include "Date2.h"

typedef struct {
    int nbEtud;
    ETUDIANT *listeEtud; // = malloc(nbEtud * sizeof(ETUDIANT));
    double moyClasse;
}CLASSE_ETUD;


void lireTabEtudiants(ETUDIANT * T, int N );

void afficherTabEtudiants(ETUDIANT * T, int N) ;

double moyTabEtudiants(ETUDIANT * T, int N) ;

int meilleurMoy(ETUDIANT * T, int N) ;

int plusJeuneEtudiant(ETUDIANT * T, int N) ;

void lireClasse(CLASSE_ETUD *) ;

void afficherClasse(CLASSE_ETUD *) ;

void libClasseEtud(CLASSE_ETUD *) ;



#endif //MAIN_C_CLASSETUD_H
