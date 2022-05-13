//
// Created by miche on 19/03/2022.
//
#include "Etudiant.h"
#include "stdlib.h"


void lireEtudiant(ETUDIANT* T)
{
    //T = (ETUDIANT *) malloc(sizeof (ETUDIANT*));
    printf("Saisir le nom de l'etudiant:  \n ");
    scanf(" %s", T->nom);
    printf("Saisir le prenom de l'etudiant: \n ");
    scanf("%s", T->prenom);
    printf("saisir le numero etudiant \n");
    scanf("%ld", &T->numEtud);
    printf("saisir la moyenne\n");
    scanf("%lf", &T->moyenne);
    printf("saisir la date de naissance\n");
    scanf("%d/%d/%d", &T->dateNaissance.jour, &T->dateNaissance.mois, &T->dateNaissance.annee);
    return T;

}

void afficherEtudiant(ETUDIANT* T){
   /* printf("Nom: %s\n Prenom: %s\n Date de naissance: %d/%d/%d\n Moyenne: %lf\n"
           , etu->nom, etu->prenom, etu->dateNaissance.jour, etu->dateNaissance.mois, etu->dateNaissance.annee,
           etu->moyenne);*/
    printf("%s_____%s_____%d/%d/%d_____%ld_____%lf\n",T->nom,T->prenom, T->dateNaissance.jour,T->dateNaissance.mois,T->dateNaissance.annee,T->numEtud ,T->moyenne);
}