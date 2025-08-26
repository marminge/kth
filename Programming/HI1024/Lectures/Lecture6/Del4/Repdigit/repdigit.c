#include <math.h>
#include <stdio.h>

int main(void) {
    int number, numbersRepeated = 0;
    printf("Enter number: ");
    scanf("%d", &number);

    int numberLength = 1 + log10(number);
    int numbers[numberLength];
    for (int i = 0; i < numberLength; i++) {
        numbers[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < numberLength - 1; i++) {
        for (int j = 0; j < numberLength - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numberLength - 1; i++) {
        if (i > 0 && numbers[i] == numbers[i - 1]) {
        } else if (numbers[i] == numbers[i + 1]) {
            numbersRepeated++;
            if (numbersRepeated == 1) printf("Repeated digit(s): ");
            printf("%d ", numbers[i]);
        }
    }
    
    if (numbersRepeated == 0) 
        printf("No digits were repeated.\n");
    else
        printf("\n");

    return 0;
}
