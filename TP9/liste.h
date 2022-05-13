//
// Created by miche on 01/04/2022.
//

#define Bool int
#ifndef UNTITLED3_LISTE_H
#define UNTITLED3_LISTE_H
#define True 1
#define False 0
//#include "liste.c"

struct maillon
{
    int valeur;
    struct mailllon *succ;
};
/*-Définition du type maillon*/
typedef struct maillon MAILLON;
/*-Définition du type liste-*/

typedef MAILLON* LISTE;


MAILLON* creer_maillon(int);
Bool liste_vide(LISTE);
LISTE ajouter_tete_liste(LISTE, int);
LISTE ajouter_queue_liste(LISTE, int) ;
int taille_liste(LISTE );
void afficher_liste(LISTE);


LISTE creer_liste(int);
int somme_liste(LISTE);
 int max_liste(LISTE);
int nombre_occurrence_liste(LISTE, int) ;
LISTE concatener_deux_listes(LISTE, LISTE);
int* copier_liste_tab(LISTE);

#endif //UNTITLED3_LISTE_H
