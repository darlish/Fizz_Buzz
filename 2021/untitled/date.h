//
// Created by miche on 14/05/2021.
//
#include <stdio.h>

#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

typedef struct {
    int jour;
    int mois;
    int annee;
}Date;
void lireDate(Date *d);
void afficheDate(Date *d);
int compareDates();


#endif //UNTITLED_DATE_H
