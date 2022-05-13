#include <stdio.h>
#include "date.h"
int main()
{
    //Date_t Date1;
    // reserver en memoir un espace mémoir de la taille de lastructure
    Date Date1;
   // Date1 = (Date *) malloc(sizeof(Date_t));
    lireDate(& Date1);
    afficheDate(&Date1);


}
