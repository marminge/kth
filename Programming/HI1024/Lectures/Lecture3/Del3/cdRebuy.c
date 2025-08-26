#include <stdio.h>
#include <stdlib.h>

int main() {
    const float grundpris = 9.9;
    double totalpris = 0;

    while (1) {
        printf("Vill du göra ett köp[1] eller avsluta[2]? ");
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

                printf("Totalpriset för %dst skivor är %.2fkr.\n\n", antalSkivor, totalpris);
                break;
            case 2:
                printf("Avslutar..\n");
                exit(0);
            default:
                printf("Ogiltigt val.\n\n");
        }
    }
    return 0;
}
