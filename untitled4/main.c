#include <stdio.h>
# include "TD8.h"


int main() {
    int N;
    printf("Saisir un entier: ");
    scanf("%d",&N);

    printf("%d",fibonacci_rec(N));
    return 0;
}
