#include <stdio.h>

int main(void){
    int antalSkivor;
    const double grundpris = 9.9;
    double totalpris;

    printf("Ange hur många skivor du vill köpa: ");
    scanf("%d",&antalSkivor);

    if (antalSkivor >= 50)
        totalpris = antalSkivor * grundpris * .9;
    else if (antalSkivor >= 10)
        totalpris = antalSkivor * grundpris * .95;
    else
        totalpris = antalSkivor * grundpris;

    printf("Totalpriset för %dst skivor är %.2fkr.", antalSkivor, totalpris);

    return 0;
}