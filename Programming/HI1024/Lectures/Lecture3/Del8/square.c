#include <stdio.h>

int main() {
    int square;
    printf("Storlek: ");
    scanf("%d", &square);
    int diag = 0;

    for (int i = 0; i < square; i++) {
        for (int j = 0; j < square; j++) {
            if (j == diag || j == square - diag - 1) {
                printf("*");
            } else {
                printf("+");
            }
        }
        diag++;
        printf("\n");
    }

    return 0;
}
