#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int numbers[2] = {rand() % 11, rand() % 11};

    if (numbers[0] > numbers[1]) {
        int temp = numbers[0];
        numbers[0] = numbers[1];
        numbers[1] = temp;
    }

    printf("%d, %d\n", numbers[0], numbers[1]);

    return 0;
}
