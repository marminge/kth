#include <math.h>
#include <stdio.h>
#define TABLE_SIZE 10

int main(void) {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int numberLength = 1 + log10(number);
    int numbers[numberLength];

    for (int i = 0; i < numberLength; i++) {
        numbers[i] = number % 10;
        number /= 10;
    }

    int table[TABLE_SIZE] = {0};

    for (int i = 0; i < numberLength; i++)
        table[numbers[i]]++;

    printf("Digit:\t\t");
    for (int i = 0; i < TABLE_SIZE; i++) printf("%3d", i);
    printf("\nOccurrences:\t");
    for (int i = 0; i < TABLE_SIZE; i++) printf("%3d", table[i]);

    printf("\n");
    return 0;
}
