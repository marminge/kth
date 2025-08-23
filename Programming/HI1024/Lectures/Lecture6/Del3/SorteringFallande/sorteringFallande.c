#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

int main(void) {
    srand(time(NULL));
    int numbers[20];

    for (int i = 0; i < LENGTH; i++) numbers[i] = rand() % 50;

    for (int i = LENGTH - 1; i >= 0; i--) {
        for (int j = LENGTH; j >= 0; j--) {
            if (numbers[i] < numbers[j - 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; i++) (i < 19) ? printf("%d ", numbers[i]) : printf("%d", numbers[i]);

    return 0;
}
