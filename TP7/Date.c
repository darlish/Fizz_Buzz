

#include "Date2.h"


void lireDate(Date* d)
{
    printf("saisir le jour, le MOIS et l'annee\n");
    scanf("%d/%d/%d", &d->jour, &d->mois, &d->annee);
}

void afficherDate(Date* d)
{
    printf("la date saisie est : %d/%d/%d\n", d->jour, d->mois, d->annee);
}


int compareDate(Date* d1, Date* d2){
    if (d1->annee == d2->annee && d1->mois == d2->mois && d1->jour == d2->jour){
        return 0;}

    if(d1->annee > d2->annee || (d1->annee == d2->annee && d1->mois > d2->mois) || (d1->annee == d2->annee && d1->mois == d2->mois && d1->jour > d2->jour)){
        return 1;}

    return -1;
}