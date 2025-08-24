#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func1(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void func2(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;
}

void func3(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int arr[5];

    func2(arr, 5);
    func3(arr, 5);
    func1(arr, 5);

    return 0;
}