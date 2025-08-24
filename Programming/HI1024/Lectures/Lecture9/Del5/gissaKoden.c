#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void printArray(int *arr, int iter) {
    for (int i = 0; i < iter; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int *reverseArray(int *arr, int iter) {
    for (int i = 0; i < iter / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[iter - 1 - i];
        arr[iter - 1 - i] = temp;
    }
}

int *generateUserCode(const int iter) {
    int code;
    scanf("%d", &code);
    int *userCode = malloc(sizeof(int) * iter);
    for (int j = 0; j < iter; j++) {
        if (j != iter - 1)
            userCode[j] = code % 10;
        else
            userCode[j] = code;
        code /= 10;
    }
    reverseArray(userCode, iter);
    return userCode;
}

int *generateCompCode(const int iter) {
    srand(time(NULL));
    int *compCode = malloc(sizeof(int) * iter);
    for (int i = 0; i < iter; i++) {
        compCode[i] = rand() % 9 + 1;
    }

    return compCode;
}


bool compareNum(const int num1, const int num2) {
    return num1 == num2;
}

bool compareCode(const int *compArr, const int *userArr, int iter) {
    for (int j = 0; j < iter; j++) {
        if (compArr[j] != userArr[j])
            return false;
    }
    return true;
}

int main(void) {
    bool run = true;
    for (int i = 2; i < 6; i++) {
        run = true;
        int *compCode = generateCompCode(i);
        // Används för att fuska!
        // printArray(compCode, i);
        while (run) {
            printf("Gissa koden\n");

            int *userCode = generateUserCode(i);

            for (int j = 0; j < i; j++) {
                if (compareNum(userCode[j], compCode[j])) {
                    printf("%d", compCode[j]);
                } else
                    printf("*");
            }
            printf(": ");
            for (int j = 0; j < i; j++) {
                printf("%d", userCode[j]);
            }
            printf("\n");

            if (compareCode(compCode, userCode, i)) {
                for (int j = 0; j < i; j++)
                    printf("%d", compCode[j]);
                printf(" korrekt!\n");
                run = false;
                free(userCode);
            }
        }
    }

    return 0;
}
