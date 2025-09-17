#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int arr[], int max);
void printArray(int arr[], int max);
void sortArray(int arr[], int max);
void printAverage(int arr[], int max);
void printMedian(int arr[], int max);
void printTypical(int arr[], int max);
int askForInput();
void run();

int main(void) {
  run();
  return 0;
}

void createArray(int arr[], int max) {
  srand(time(NULL));
  for (int i = 0; i < max; i++)
    arr[i] = rand() % 21 + 20;
}

void printArray(int arr[], int max) {
  for (int i = 0; i < max; i++)
    (i != max - 1) ? printf("%d, ", arr[i]) : printf("%d\n", arr[i]);
}

void sortArray(int arr[], int max) {
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < max - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printAverage(int arr[], int max) {
  int sum = 0;
  for (int i = 0; i < max; i++)
    sum += arr[i];
  printf("%.1f\n", (float)sum / max);
}

void printMedian(int arr[], int max) {
  sortArray(arr, max);
  if (max % 2 == 0)
    printf("%.1f\n", (float)arr[max / 2]);
  else
    printf("%.1f\n", (arr[max / 2] + arr[(max + 1) / 2]) / 2.0);
}

int askForInput() {
  int antalPersoner = 0;
  do {
    printf("Hur många personer vill du göra statistik på? ");
    scanf("%d", &antalPersoner);
    if (antalPersoner < 1 || antalPersoner > 1000)
      printf("Antalel måste vara mellan 1 - 1000.\n");
  } while (antalPersoner < 1 || antalPersoner > 1000);
  return antalPersoner;
}

void printTypical(int arr[], int max) {
  int maxOcc = 0;
  int occ = 0;
  for (int i = 0; i < max; i++) {
    if (arr[i] == arr[i + 1])
      occ++;
    else
      occ = 0;
    if (occ > maxOcc)
      maxOcc = occ;
  }
  occ = 0;
  for (int i = 0; i < max; i++) {
    if (arr[i] == arr[i + 1])
      occ++;
    else
      occ = 0;
    if (occ == maxOcc) {
      printf("%d ", arr[i]);
      occ = 0;
    }
  }
  printf("\n");
}

void run() {
  int antal = askForInput();
  int array[antal];
  createArray(array, antal);
  if (antal < 31)
    printArray(array, antal);
  printf("Medelvärdet: ");
  printAverage(array, antal);
  printf("Median: ");
  printMedian(array, antal);
  printf("Typvärde: ");
  printTypical(array, antal);
}
