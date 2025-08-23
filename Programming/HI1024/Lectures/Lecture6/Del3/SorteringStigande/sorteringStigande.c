#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

int main(void) {
    srand(time(NULL));
    int numbers[20];

    for (int i = 0; i < LENGTH; i++) numbers[i] = rand() % 50;

    for (int i = 0; i < LENGTH - 1; i++) {
        for (int j = 0; j < LENGTH - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; i++) (i < 19) ? printf("%d ", numbers[i]) : printf("%d", numbers[i]);

    return 0;
}
