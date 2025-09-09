#include <stdio.h>

int main(void) {
    int numbers[4];

    printf("Enter four integers\n");
    for (int i = 0; i < 4; i++) {
        printf("Nr %d: ", i+1);
        scanf("%d", &numbers[i]);
    }    

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4-1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    printf("Biggest number: %d\nSmallest: %d\n", numbers[3], numbers[0]);

    return 0;
}