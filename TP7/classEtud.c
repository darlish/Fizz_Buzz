//
// Created by miche on 19/03/2022.
//
#include "classEtud.h"
#include "stdlib.h"


void lireTabEtudiants(ETUDIANT * T, int N){
    for(int i=0; i < N; i++)
    {
        lireEtudiant((T+i));
       /* printf("Saisir les informations de l'etudiant numero %d\n", i+1);
        printf("Saisir son nom: ");
        scanf("%s", &(T+i)->nom);
        printf("saisir son prenom: ");
        scanf("%s", &(T+i)->prenom);
        printf("Saisir sa date de naissance: ");
        scanf("%d/%d/%d", &(T+i)->dateNaissance.jour,&(T+i)->dateNaissance.mois,&(T+i)->dateNaissance.annee);
        printf("saisir son numero etudiant: ");
        scanf("%ld", &(T+i)->numEtud);
        printf("saisir sa moyenne: ");
        scanf ("%lf", &(T+i)->moyenne);*/
    }
}


void afficherTabEtudiants(ETUDIANT * T, int N){
    printf("nom_____prenom_____date de naissance_____numero etudiant_____moyenne\n");
    for (int i =0; i<N; i++){
        afficherEtudiant(T+i);

    /*for (int i=0; i< T->nbEtud;i++){
        printf("%d: %s_____%s_____%d/%d/%d_____%ld_____lf\n", i+1
                , (T+i)->listeEtud->nom, (T+i)->listeEtud->prenom, (T+i)->listeEtud->dateNaissance.jour,(T+i)->listeEtud->dateNaissance.mois,
                (T+i)->listeEtud->dateNaissance.annee,(T+i)->listeEtud->numEtud ,(T+i)->listeEtud->moyenne);
}*/
}
}
double moyTabEtudiants (ETUDIANT * T, int N) {
    double moy= 0;
    for (int i=0; i<N; i++){
        moy += (T+i)->moyenne;
    }
    moy = moy/ N;
    return moy;
}



int meilleurMoy(ETUDIANT * T, int N){
    double max = (T)->moyenne;
    int indice;
    for(int i=0; i<N; i++){
        if ((T+i)->moyenne > max){
            max = (T+i)->moyenne;
            indice = i+0;
        }
    }
    return indice;
}


int plusJeuneEtudiant(ETUDIANT * T, int N){
    Date* d1=NULL;
    Date * d2=NULL;
    int min;
    d1->jour = (T)->dateNaissance.jour;
    d1->mois = (T)->dateNaissance.mois;
    d1->annee = (T)->dateNaissance.annee;
    for (int i=1;i<N; i++){
        d2->jour = (T+i)->dateNaissance.jour;
        d2->mois =(T+i)->dateNaissance.mois;
        d2->annee = (T+i)->dateNaissance.annee;
        if (compareDate( d1,d2 ) == -1){
            d1->jour = d2->jour;
            d1->mois = d2->mois;
            d1->annee = d2->annee;
            min = i-1;
        }
    }return min;
}


void lireClasse(CLASSE_ETUD * T){
    T->moyClasse=0;
    printf("saisir le nombre d'tudiant dans la classe\n");
    scanf("%d",&T->nbEtud);
    lireTabEtudiants((T)->listeEtud, T->nbEtud);
    int n=T->nbEtud;
    for (int i=0; i<n; i++){
        T->moyClasse= T->moyClasse + (T+i)->listeEtud->moyenne;
    }
    T->moyClasse =  T->moyClasse/T->nbEtud;
}

void afficherClasse(CLASSE_ETUD *T){
        printf("Le nombre d'étudiants est %d\n", T->nbEtud);
        afficherTabEtudiants(T->listeEtud, T->nbEtud);
        printf("La moyenne de la classe est %lf \n",T->moyClasse);

}


void libClasseEtud (CLASSE_ETUD *T){
        free(T->listeEtud);
        //T->listeEtud  =NULL;
       free(T);
       //T=NULL;
}



