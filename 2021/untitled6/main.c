#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
    char nom[20];
    float prix;
}Produit;

typedef struct {
    Produit *articles[10];
    int nb_articles;
}Panier;



float prixTolat (Panier *p){
    float total =0;
            for(int i=0; i<p ->nb_articles; i++)
                total += prixTolat;
            return total;
}
