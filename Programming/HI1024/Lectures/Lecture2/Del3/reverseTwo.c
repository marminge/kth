#include <stdio.h>

int main(void) {
    int userInput, inputReversed;

    printf("Ange ett tal: ");
    scanf("%d",&userInput);

    inputReversed = userInput % 10 * 10 + userInput / 10;

    printf("%d", inputReversed);

    return 0;
}