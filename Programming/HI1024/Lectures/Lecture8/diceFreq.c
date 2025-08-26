#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DICE_SIDES 6

void rollDice(int n) {
    srand(time(NULL));

    int diceFreq[DICE_SIDES] = {0};

    for (int i = 0; i < n; i++)
        diceFreq[rand() % 6]++;
    printf("Värde\t\tFrekvens\n--------------------\n");
    for (int i = 0; i < DICE_SIDES; i++)
        printf("%d\t\t%d\n", i+1, diceFreq[i]);
}

int getN(void) {
    int n;
    printf("Hur många tärningskast vill du göra? ");
    scanf("%d", &n);
    return n;
}

int main(void) {
    rollDice(getN());

    return 0;
}