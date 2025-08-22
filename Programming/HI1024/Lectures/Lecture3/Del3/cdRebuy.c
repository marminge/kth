#include <stdio.h>
#include <stdlib.h>

int main() {
    const float grundpris = 9.9;
    double totalpris = 0;

    char meny[] = "Vill du göra ett köp[1] eller avsluta[2]? ";

    while (1) {
        printf("%s", meny);
        int val;
        scanf("%d", &val);

        switch (val) {
            case 1:
                printf("Ange hur många skivor du vill köpa: ");
                int antalSkivor;
                scanf("%d", &antalSkivor);

                if (antalSkivor >= 50)
                    totalpris = antalSkivor * grundpris * .9;
                else if (antalSkivor >= 10)
                    totalpris = antalSkivor * grundpris * .95;
                else
                    totalpris = antalSkivor * grundpris;

                printf("Totalpriset för %dst skivor är %.2fkr.\n", antalSkivor, totalpris);
                break;
            case 2:
                printf("Avslutar..");
                exit(0);
            default:
                printf("Ogiltigt val.\n");
        }
    }
    return 0; // Gör ingenting eftersom att jag avslutar med exit(0)
}
