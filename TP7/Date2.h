//
// Created by miche on 19/03/2022.
//

#ifndef UNTITLED3_DATE2_H
#define UNTITLED3_DATE2_H
#include <stdio.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;
void afficherDate(Date* d);
void lireDate(Date* d);
int compareDate(Date* d1,Date* d2);







#endif //UNTITLED3_DATE2_H
