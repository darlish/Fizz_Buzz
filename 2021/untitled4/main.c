#include <stdio.h>
#include <stdlib.h>

int main() {
    int *T;
    int val;
    printf("entrer le nombre de valeurs\n");
    scanf("%d\n",  &val);

    T = ((int*)malloc(val * sizeof(int)));
    if (T== NULL){
        printf("il n'y a pas assez d'espace");
    }
    for(int i=0; i<val; i++){
        printf("entrer un entier\n");
        scanf("%d", T+i);
    }
    for(int i=0; i<val; i++){
        printf("%d", *(T+i) );
    }
    return 0;
}
