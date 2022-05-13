//
// Created by miche on 01/04/2022.
//
#include "stdio.h"
#include <stdlib.h>
#include "liste.h"
//#define Bool int
//#define True 1
//#define False 0


MAILLON* creer_maillon(int val){
    MAILLON* Liste = NULL;
    MAILLON * nouveau = (MAILLON*) malloc(sizeof (MAILLON))
    nouveau->valeur = val;
    nouveau->succ = NULL;
    return Liste;
}


Bool liste_vide(LISTE L){
    if(L == NULL){
        return True;
    }

    return False

}

LISTE ajouter_tete_liste (LISTE L, int val){
    MAILLON * tete=NULL;
    tete = creer_maillon(val);
    if (L==NULL){
        L = tete;
        return L
    }
    tete->succ = L;
    return tete;
}


LISTE ajouter_queue_liste(LISTE L, int val) {
    LISTE courant = L;
    LISTE nouveau = creer_maillon(val);
    if (L==NULL){
        L = nouveau;
        return L;
    }
    while (courant->succ != NULL){
            courant = courant->succ;
    }
    courant->succ = nouveau;
    return L;
}

int taille_liste(LISTE L){
    int cpt =0;
    if L= NULL{
        return -1
    }
    LISTE courant = L;
    while (courant->succ != NULL){
        courant = courant->succ;
        cpt ++;
    }
    return cpt;
}

void afficher_liste(LISTE L){
        MAILLON* courant = L;
        if (L==NULL){
            printf("La liste est vide \n");
        }
        else{
            do {
                printf("%d ",courant->valeur);
                courant->succ =courant->succ;
            }while (courant->succ != NULL);
        }
}


LISTE creer_liste(int taille){
    LISTE new = NULL;
    int random;
    for( int i==0, i<taille, i++){
        srand(r)
     new = ajouter_queue_liste(new, rand()%101);
    }
    return new;
}

int somme_liste(LISTE L){
    int sum=0;
    if (!(liste_vide(L))){
    LISTE courant = L;
    do{
        sum += courant->valeur;
        courant = courant->succ;
    } while (courant->succ != NULL);
        return sum;
    }
    return -1;
}

int max_liste(LISTE L){
    int max;
    if (!(liste_vide(L))){
        LISTE courant = L;
        max = courant->valeur;
        do{
            courant = courant->succ;
            if (max < courant->valeur){
                max = courant->valeur;
            }
        } while (courant->succ != NULL);
        return max;
        }
    return -1
}


int nombre_occurrence_liste(LISTE L, int val){
    if (!(liste_vide(L))){
        int occ = 0;
        LISTE courant = L;
        do{
            if ( courant->valeur == val){
                occ++;
            }
            courant = courant->succ;
        } while (courant!=NULL);

        return occ;
    } return -1;
}


LISTE concatener_deux_listes(LISTE L1, LISTE L2){
    LISTE courant = L1;
     do{
        courant = courant->succ;
    } while (courant->succ != NULL);
    courant->succ = L2;
    return L1;
}


int * copier_liste_tab(LISTE L){
    LISTE courant = L;
    int cpt = 0;
    int i = 0;
    int * Tab;
    while(courant != NULL){
        cpt ++;
        courant = courant->succ;

    }
    Tab = (int*) malloc(cpt * sizeof (int));
    courant = L;
    while(courant != NULL){
        Tab + i = Tab ourant->valeur;
        courant = courant->succ;
    }
    return Tab;
}


