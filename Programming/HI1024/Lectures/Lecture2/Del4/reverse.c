#include <stdio.h>
#include <math.h>

int main(void) {
    int userInput, inputReversed = 0;

    printf("Ange ett tal: ");
    scanf("%d",&userInput);
    int numOfNum = 1 + log10(userInput);


    for (int i = 1; i <= numOfNum; i++) {
        inputReversed += (userInput % 10) * pow(10, numOfNum - i);
        userInput = (userInput / 10);
    }

    printf("%d\n",inputReversed);

    return 0;
}