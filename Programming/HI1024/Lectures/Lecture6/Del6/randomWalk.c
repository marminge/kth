#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

int main(void) {
    char square[ROWS][COLS];
    srand(time(NULL));
    int currentStepRow = 0;
    int currentStepCol = 0;
    char currentLetter = 'A';
    int iteration = 0;


    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            square[i][j] = '.';

    square[currentStepRow][currentStepCol] = 'A';

    while (iteration != 25) {
        int nextStep = rand() % 4;
        switch (nextStep) {
            case 0:
                if (square[currentStepRow][currentStepCol - 1] == '.' && currentStepCol - 1 >= 0) {
                    currentStepCol--;
                } else if (square[currentStepRow][currentStepCol + 1] == '.' && currentStepCol + 1 <= 9) {
                    currentStepCol++;
                } else if (square[currentStepRow + 1][currentStepCol] == '.' && currentStepRow + 1 <= 9) {
                    currentStepRow++;
                } else if (square[currentStepRow - 1][currentStepCol] == '.' && currentStepRow - 1 >= 0) {
                    currentStepRow--;
                } else
                    goto out;
                break;
            case 1:
                if (square[currentStepRow - 1][currentStepCol] == '.' && currentStepRow - 1 >= 0) {
                    currentStepRow--;
                } else if (square[currentStepRow + 1][currentStepCol] == '.' && currentStepRow + 1 <= 9) {
                    currentStepRow++;
                } else if (square[currentStepRow][currentStepCol - 1] == '.' && currentStepCol - 1 >= 0) {
                    currentStepCol--;
                } else if (square[currentStepRow][currentStepCol + 1] == '.' && currentStepCol + 1 <= 9) {
                    currentStepCol++;
                } else
                    goto out;
                break;
            case 2:
                if (square[currentStepRow][currentStepCol + 1] == '.' && currentStepCol + 1 <= 9) {
                    currentStepCol++;
                } else if (square[currentStepRow - 1][currentStepCol] == '.' && currentStepRow - 1 >= 0) {
                    currentStepRow--;
                } else if (square[currentStepRow][currentStepCol - 1] == '.' && currentStepCol - 1 >= 0) {
                    currentStepCol--;
                } else if (square[currentStepRow + 1][currentStepCol] == '.' && currentStepRow + 1 <= 9) {
                    currentStepRow++;
                } else
                    goto out;
                break;
            case 3:
                if (square[currentStepRow + 1][currentStepCol] == '.' && currentStepRow + 1 <= 9) {
                    currentStepRow++;
                } else if (square[currentStepRow][currentStepCol + 1] == '.' && currentStepCol + 1 <= 9) {
                    currentStepCol++;
                } else if (square[currentStepRow][currentStepCol - 1] == '.' && currentStepCol - 1 >= 0) {
                    currentStepCol--;
                } else if (square[currentStepRow - 1][currentStepCol] == '.' && currentStepRow - 1 >= 0) {
                    currentStepRow--;
                } else
                    goto out;
                break;
        }
        currentLetter++;
        iteration++;
        square[currentStepRow][currentStepCol] = currentLetter;
    }
out:
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", square[i][j]);
        }
        printf("\n");
    }
    return 0;
}
