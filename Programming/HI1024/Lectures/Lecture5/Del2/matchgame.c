#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int antalStickor = 15;
    srand(time(NULL));
    int turn = rand() + 1;

    printf("Välkommern till tändsticksspelet.\n");

    while (antalStickor > 0) {
        for (int i = 0; i < antalStickor; i++) printf("| ");
        printf("\n");

        if (turn % 2 == 1) {
            printf("Hur många stickor vill du ta? (1-3) ");
            int input;
            scanf("%d", &input);
            antalStickor -= input;
        } else {
            int datornsVal = (antalStickor <= 3) ? antalStickor : rand() % 3 + 1;
            printf("Datorn tar %d stickor.\n", datornsVal);
            antalStickor -= datornsVal;
        }
        turn++;
    }
    (turn % 2 == 1) ? printf("Datorn vann.\n") : printf("Du vann.\n");
    return 0;
}

