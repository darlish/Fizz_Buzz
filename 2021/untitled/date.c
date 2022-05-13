#include <stdio.h>
#include "date.h"
void lireDate( Date *d){
    printf("entrer votre date\n");
    printf("jour\n");
    scanf("%d/\n",&(*d).jour);
    printf("mois\n");
    scanf("%d/",&(d->mois));
    printf("anne\n");
    scanf("%d/",&(d->annee));
}
void afficheDate(Date *d){
    printf("%d/%d/%d\n", d->jour, d->mois, d->annee);

}