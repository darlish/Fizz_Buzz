typedef struct{
    int jour;
    int mois;
    int annee;
}DATE;


void lireDate(DATE*);

void afficherDate(DATE *);

int comparerDates(DATE*, DATE*);