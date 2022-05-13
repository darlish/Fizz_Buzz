#include <stdio.h>

int main() {
    int x;
    do{
        printf("saisir un entier\n");
        scanf("%d", &x);
    }while(x<0);
    printf("%d", x);
    return 0;
}
