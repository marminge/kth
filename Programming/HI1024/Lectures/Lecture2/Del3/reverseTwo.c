#include <stdio.h>

int main(void) {
    int userInput, inputReversed;

    printf("Ange ett två-siffrigt tal: ");
    scanf("%d",&userInput);

    inputReversed = userInput % 10 * 10 + userInput / 10;

    printf("%d\n", inputReversed);

    return 0;
}