#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* void Exo1(){
    printf("Hello, World!\n");
    printf("MBAMA Darlish 08/11/2001");
}
void EXO2() {
        printf("  ##### \n");
        printf(" #\n #\n");
        printf("####");
        printf("#\n #\n #\n");
    }
void EXO3() {
    int i = 4;
    printf("        ######\n");
    printf("    ##          ##\n");
    for (i = 0; i < 4; i++) {
        printf("#\n");
    }
    printf("    ##          ##\n");
    printf("        ######\n");
}

void Quest4(){

    int x, y, i, m;
    y=0;
    for(i = 0; i < 3; i++)
    {
    printf("saisir un entier");
    scanf("%d", &x);
    y+=x;
}
    m=y/3;
    printf("la moyenne est %d",m);
}

void Quest5(){
    int p, s, L, l;
    printf("entrer la largeur\n");
    scanf("%d",&l);
    printf("entrer la longueur\n");
    scanf("%d",&L);
    p= (l+L)*2;
    s= l*L;
    printf("le perimètre est %d, et la surface est %d", p, s);
}
void Quest6(){
    int  a, s, j, d, i;
    d=1329;
    a= d/365;
    s= (d-(a*365))/7;
    j= (d-(a*365+ s*7));


    printf(" le nombre d'anné est %d et de semaine est %d et de jours est %d", a, s, j);
}

void EXO2_1 (){
    int x,y;
    printf("entrer un entier");
    scanf("%d",&x);
    printf("entrer un deuxième entier");
    scanf("%d", &y);
    if(x==y) {
        printf("vos entiers sont similaires");
    }
    else{
        printf("vos entiers ne sont aps les mêmes");
    }
}

void EXO2_2(){
    int x;
    printf("entrer un entier");
    scanf("%d",&x);
    if(x%2==0){
        printf("votre entier est paire");}
    else{
        printf("votre entier est impair");
    }

}
void EXO2_3(){
    int a, max,i;
    max=0;
    for(i=0;i<3;i++)
    {
        printf("entrer un entier");
        scanf("%d",&a);
        if(max<a){
            max=a;
        }
    }
    printf("%d est le maximum", max);
}

void EXO3_1(){
    int x, y, nbr, i;
    printf("entre votre entier le plus gra,d");
    scanf("%d", &x);
    printf("entrer votre second entier");
    scanf("%d", &y);
    i=0;
    nbr=1;
    while(x>y)
    {

        x=x-y;
        nbr+=1;
    }
printf("le resultat est %d", nbr);
}


void CompareDate(d1,d2){
    printf("entrer une date");
    scanf("%d,%d,%d", &d1.jour,&d1.mois,&d1.anne);
    printf("entrer une seconde date");
    scanf("%d,%d,%d",&d2.jour,&d2.mois,&d2.anne);
// TP2

void EXO1_1 (){
    int len, k,  T[100];
    printf("entrer la taille du tableau");
    scanf("%d",&len);
    for( int i=0; i<len; i++){
        do {
            printf("entrer une valeur");
            scanf("%d",&k);
        } while(k<0);
        T[i]=k;

    }
    for( int l=0; l<len; l++){
        printf("%d ",T[l]);
    }

}


void EXO1_4(){
    int len,val,n, x,  T[100];
    int j=0;
    printf("entrer la taille du tableau");
    scanf("%d",&len);
    for( int i=0; i<len; i++) {
        do {
            printf("entrer une valeur");
            scanf("%d", &x);
        } while (x < 0);
        T[i] = x;
    }
    printf("entrer votre valeur");
    scanf("%d",&val);
    while(n=0){

        if(val==T[j]){
            printf("votre valeur %d se treouve à la position %d", val, j);
            n++;
        }
        j++;
    }
}
void EXO1_5() {
    int len, val, x, T[100];
    int occ = 0;
    printf("entrer la taille du tableau");
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        do {
            printf("entrer une valeur");
            scanf("%d", &x);
        } while (x < 0);
        T[i] = x;
    }
    printf("entrer votre valeur");
    scanf("%d", &val);
    for(int j=0; j<len; j++){
        if (val==T[j]){
            occ++;
        }
    }
    if (occ==0){
        printf("votre valeur n'existe pas dans ce tableau");
    }
    else{
        printf("on retrouve %d fois votre valeur %d", occ,val);
    }
}
void EXO1_7(){
    int A[5] = {1, 2, 3, 17, 5};

    int *p;

    int i;

    p = A;

    for ( i = 0; i < 5; i++ )

        printf("%d - ", p + i );

    return 0;

 void EXO1_8(){
    char mot1[100];
    int i, N, temp;

    printf("Saisir un mot \n");
    scanf("%s", mot1);

    N = strlen(mot1);
    temp = mot1[0];
    for(i=0 ; i < (N-1) ; i++) {
        mot1[i] = mot1[i + 1];
        mot1[N - 1] = temp;
        printf("%s", mot1);
    }
    }
}

*/



// #################################"TP1 2022################33333337


void EXO2_1() {
    int x, y, z;
    printf("saisir trois entiers \n");

    scanf("%d,%d,%d", &x, &y, &z);

    printf("%d, %d, %d \n ", x, y, z);
    int s = x+y+z;
    printf(s);
}

void EXO2_2(){
    int x,y;
    char c;
    printf("saisir le calcule");
    scanf("%d %c %d", &x, &c, &y );



}

void EXO3_1(){
    float  r, pi=3.14;
    printf("saisir un rayon\n");
    scanf("%f", &r);
    printf("%f\n",2*pi*r );
    printf("%f\n",pi*r*r );
    printf("%f\n", r*2);
}

void EXO3_5(){
    int j, days = 1329, s, a;
    a = days/365 ;
    s = (days-a*365)/7 ;
    j = (days - a * 365)-(7 * s);
    if (days >0 ){
        if(a > 0){
            printf("%d\n", a);
        }
        if(s > 0){
            printf("%d\n", s);
        }
        if(j > 0){
            printf("%d\n", j);
        }
    }
    if (days <0 ){
        printf("Aucune conversion possible");
    }
}



void EXO3_6(){
    int money = 375, a, b, c, d, e, f, g;
    a = money/100;
    b= (money-(a*100))/50;
    c = ((money-(a*100))-(50*b))/20;
    d = ((money-(a*100))-(50*b)-(20*c))/10;
    e = ((money-(a*100))-(50*b)-(20*c)-(10*d))/5;
    f = ((money-(a*100))-(50*b)-(20*c)-(10*d)-(5*e))/2;
    g= (money-(a*100))-(50*b)-(20*c)-(10*d)-(5*e)-(f*2);
    printf("%d billet(s) de 100 e, %d billet(s) de 50e, %d billet(s) de 20 e, %d billet(s) de 10e, %d billet(s) de \n"
           "5 e, %d billet(s) de 2 e et %d billet(s) de 1 e.", a, b, c, d, e, f, g);
}


/*void EXO4_1(){
    int a;
    printf("saisire l'âge de l'enfant\n");
    scanf("%d",&a);
    switch (a) {
        case a>=6 && a<=7:{
            printf("Poussin de 6 à 7 ans\n");
            break;
        }
        case a>=8 && a<=9 :{

            printf("Pupille de 8 à 9 ans \n");
            break;
        }
        case a>=10 && a<=11:{
            printf("Minime de 10 à 11 ans\n");
            break;
        }
        case a>=12 && a<=14:{
            printf("Cadet de 12 à 14 ans\n");
            break;
        }

    }
}*/


// #################### TP2######################################

void EXO1_1_a(){
    int i;
    i=0;
    while (i < 11)
    {
        i+=2;
    }
    printf("******\n******\n******\ni = %d", i);
}

void EXO1_1_b(){
    int i;
    for (i = 7; i>-1;i--)
    {}
    printf("i = %d", i);
}

void EXO1_1_c(){
    int i;
    for (i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("******\n");
        }

    }
}


void EXO1_1_d(){
    int i;
    for (i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("**");
        }
        printf("\n");
    }
}

void EXO1_1_e(){
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {/*if(i == 2 && j== 3){
            printf("i = %d ****** j = %d", i, j);
        }*/}
    }printf("i = %d ****** j = %d", i, j);
}



void EXO1_2(){
    char char1;
    char char2;
    printf("Saisir un caractere :");
    scanf(" %c", &char1);
    printf("Saisir un autre caractere :");
    scanf(" %c", &char2);
    for(int i=1; i<6; i++){
        for(int j=i; j<i*i+1;j++){
            if (j%2==0){
                printf("%c", char1);
            } else{
                printf("%c", char2);
            }
        }printf("\n");
    }
}


void EXO1_3(){
    int x;
    do {
        printf("saisir un entier x entre -4 et 4 compris");
        scanf("%d",&x);
    } while (x<-4 || x>4);
    printf("%d", x);
}


void Exo2_1(){
    int r, x;
    printf("saisir un entier\n");
    r = scanf("%d", &x);
    if (r==1){
        printf("true");
    }
    else{
        printf("false");
    }
}

/*void tp_exo(){
    int exo, tp, r;
    printf("saisir un tp\n");
    r=scanf("%d", &tp);
    do {
        printf("saisir un etier pour le tp svp\n");
        scanf("%d", &tp);
    }
}*/

void TP3_Exo(){
    int TabA[100], TabB[100], n, len, r;
    //printf("saisir la taille du tableau");
   // scanf("%d", &len);
    do {
        printf("saisir la taille du tableau");
        r=scanf("%d", &len);
    } while (len<=0 || len>100 && r == 0 );


}

int main(){
    Exo2_1();
    return 0;
}










