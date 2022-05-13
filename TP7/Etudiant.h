//
// Created by miche on 19/03/2022.
//

#ifndef MAIN_C_ETUDIANT_H
#define MAIN_C_ETUDIANT_H
#include "Date2.h"


typedef struct{
    char nom[30];
    char prenom[30];
    Date dateNaissance;
    long numEtud;
    double moyenne;
}ETUDIANT;

void lireEtudiant(ETUDIANT*);

void afficherEtudiant(ETUDIANT*);

#endif //MAIN_C_ETUDIANT_H
