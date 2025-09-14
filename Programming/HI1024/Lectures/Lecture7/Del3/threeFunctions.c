#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void printFunc(int arr[], int n);
void fillFunc(int arr[], int n);
void sortFunc(int arr[], int n);

int main(void) {
  int arr[SIZE];

  fillFunc(arr, SIZE);
  printFunc(arr, SIZE);
  sortFunc(arr, SIZE);
  printFunc(arr, SIZE);
  return 0;
}

void printFunc(int arr[], int n) {
  printf("Array: ");
  for (int i = 0; i < n; i++)
    printf("%3d ", arr[i]);
  printf("\n");
}

void fillFunc(int arr[], int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 21 - 10;
}

void sortFunc(int arr[], int n) {
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
