#include <stdio.h>
#include "stdlib.h"
#include "liste.h"
#define True 1
#define False 0
#include <stdlib.h>

int main() {
    MAILLON * L=NULL;
    int k ;  
    L = creer_maillon(5);
//    int val;
//    L= creer_maillon(5);
    printf ("%d",L->valeur);

    return 0;
}
