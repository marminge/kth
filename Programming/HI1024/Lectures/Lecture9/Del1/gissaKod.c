#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_LENGTH 3

// Används för att fuska.
/*
void skrivKod(int arr[]) {
    for (int j = 0; j < CODE_LENGTH; j++)
        printf("%d ", arr[j]);
    printf("\n");
}
*/

int compareArray(int arrComp[], int arrUser[]) {
    int correctAnsers = 0;
    for (int i = 0; i < CODE_LENGTH; i++)
        if (arrComp[i] == arrUser[i])
            correctAnsers++;

    return correctAnsers;
}

int main(void) {
    srand(time(NULL));
    int kod[CODE_LENGTH], userInput[CODE_LENGTH];

    int gissningar = 0;

    for (int i = 0; i < 3; i++)
        kod[i] = rand() % 10;

    do {
        printf("Gissa koden: ");
        scanf("%d %d %d", &userInput[0], &userInput[1], &userInput[2]);
        gissningar++;

        if (compareArray(userInput, kod) < 3)
            printf("Fel kod. Du hade %d rätt.\n", compareArray(kod, userInput));
        else
            printf("Rätt kod. Du behövde %d gissningar\n", gissningar);

    } while (compareArray(kod, userInput) != 3);

    return 0;
}
