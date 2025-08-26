#include <stdio.h>

int main(void) {
    int numbers[4];

    printf("Enter four integers\n");
    for (int i = 0; i < 4; i++) {
        printf("Nr %d: ", i+1);
        scanf("%d", &numbers[i]);
    }    

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (numbers[i] > numbers[j]+1) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    printf("Biggest number: %d\nSmallest: %d\n", numbers[0], numbers[3]);

    return 0;
}