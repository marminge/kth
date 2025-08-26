#include <stdio.h>

int main(void) {
    char *s = " ";
    int veckodag, antaldagar;

    printf("Vilken dag är det idag (1-mån, 2-tid, ..., 7-sön: ");
    scanf("%d", &veckodag);
    printf("Ange antal dagar: ");
    scanf("%d", &antaldagar);

    int dagensDag = ((antaldagar % 7) + veckodag) % 7;

    switch (dagensDag) {
        case 1:
            s = "måndag";
            break;
        case 2:
            s = "tisdag";
            break;
        case 3:
            s = "onsdag";
            break;
        case 4:
            s = "torsdag";
            break;
        case 5:
            s = "fredag";
            break;
        case 6:
            s = "lördag";
            break;
        case 7:
            s = "söndag";
            break;
        default:
            printf("Något gick fel.");
    }

    printf("Om %d dagar är det %s.\n", antaldagar, s);

    return 0;
}
