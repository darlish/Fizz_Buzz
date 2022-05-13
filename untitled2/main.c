#include <stdio.h>
#include <stdlib.h>


// Inclure la librairie qui permet d'utiliser les fonctions de l'allocation

int main()
{
    // Allouer dynamiquement l'entier n en utilisant un malloc
    int*n = (int*) malloc(1 * sizeof(int));

    // Allouer dynamiquement l'entier s en utilisant un calloc
    int *s = (int*) calloc(1, sizeof(int));

    printf("Veuillez saisir un nombre :\n");
    // Saisie de la valeur de n
    scanf("%d", n);
    // Initialisation de s
    *s = 0;
    // Compléter la condition d'arrêt
    for(int i=1; i<=*n ; i++)
    {
        // Effectuer la somme
        if (i%2 != 0){
            *s = *s+i;
            printf("%d \n", *s);
        }
    }
    // Affichage du résultat
    printf("La somme des nombres impairs est \n %d", *s);
    // Libérer l'espace alloué pour n
    free(n);
    // Libérer l'espace alloué pour s
    free(s);
    return 0;
}

