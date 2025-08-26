#include <stdio.h>

int main() {
    float userInput = 1, biggest = 0;

    printf("Ange hur många nummer du vill. Avsluta genom att ange '0'\n\n");

    while (userInput != 0) {
        printf("Enter a number: ");
        scanf("%f", &userInput);
        if (userInput > biggest)
            biggest = userInput;
    }
    printf("Det största numret som du angav var: %f\n", biggest);
    return 0;
}
