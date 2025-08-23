#include <stdio.h>

int main(void) {
    int siffersumma = 0, userInput;

    printf("Mata in ett tal: ");
    scanf("%d", &userInput);

    while (userInput != 0) {
        siffersumma += userInput % 10;
        userInput = userInput / 10;
    }

    printf("Siffersumman är %d.", siffersumma);

    return 0;
}