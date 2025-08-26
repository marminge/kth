#include <stdio.h>
#define ROWS 5
#define COLS 5

int main(void) {
    int square[ROWS][COLS];
    int rowsTotal[ROWS] = {0};
    int colsTotal[COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &square[i][0], &square[i][1], &square[i][2], &square[i][3], &square[i][4]);
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowsTotal[i] += square[i][j];
            colsTotal[i] += square[j][i];
        }
    }
    printf("Rows totals: ");
    for (int i = 0; i < ROWS; i++) printf("%d ", rowsTotal[i]);
    printf("\nColumn totals: ");
    for (int i = 0; i < COLS; i++) printf("%d ", colsTotal[i]);

    printf("\n");
    return 0;
}
