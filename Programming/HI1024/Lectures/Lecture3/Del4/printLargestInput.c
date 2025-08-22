#include <stdio.h>

int main() {
    float userInput = 1, biggest = 0;

    while (userInput != 0) {
        printf("Enter a number: ");
        scanf("%f", &userInput);
        if (userInput > biggest)
            biggest = userInput;
    }
    printf("%f\n", biggest);
    return 0;
}
