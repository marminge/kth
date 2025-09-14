#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void printValues(int arr[], int totalMeasurments);
int getMax(int arr[], int totalMeasurments);
int getMin(int arr[], int totalMeasurments);
float getAverage(int arr[], int totalMeasurments);
void getNormalizedValues(int arr[], int normArr[], int totalMeasurments);
void presentComputedValues(int arr[], int normArr[], int totalMeasurments);
void enterValues(int arr[], int *totalMeasurments);
void deleteAllValues(int *totalMeasurments);

void run();

int main(void) {
  run();
  return 0;
}

void run() {
  char choice = 'l';
  int measurments[10], normalizedValues[10];
  int totalMeasurments = 0;
  printf("Measurement tool 2.0\n");
  while (choice != 'q') {

    printf("VECRQ? ");

    if (scanf("%c%*c", &choice) != 0) {
      switch (choice) {
      case 'v':
        printValues(measurments, totalMeasurments);
        break;
      case 'e':
        enterValues(measurments, &totalMeasurments);
        break;
      case 'c':
        presentComputedValues(measurments, normalizedValues, totalMeasurments);
        break;
      case 'r':
        deleteAllValues(&totalMeasurments);
        break;
      case 'q':
        break;
      default:
        printf("Wrong input.\n");
        break;
      }
    } else {
      while (1) {
        char trash = getchar();
        if (trash == '\n')
          break;
      }
    }
  }
}

void printValues(int arr[], int totalMeasurments) {
  if (totalMeasurments != 0) {
    printf("[ ");
    for (int i = 0; i < totalMeasurments; i++) {
      printf("%d ", arr[i]);
    }
    printf("]\n");
  } else {
    printf("Your have no values to print.\n");
  }
}

void presentComputedValues(int arr[], int normArr[], int totalMeasurments) {
  if (totalMeasurments != 0) {
    printf("Max value: %d\n", getMax(arr, totalMeasurments));
    printf("Min value: %d\n", getMin(arr, totalMeasurments));
    printf("Avr value: %.2f\n", getAverage(arr, totalMeasurments));
    getNormalizedValues(arr, normArr, totalMeasurments);
    printf("[ ");
    for (int i = 0; i < totalMeasurments; i++) {
      printf("%d ", normArr[i]);
    }
    printf("]\n");
  } else {
    printf("Your have no values.\n");
  }
}
int getMax(int arr[], int totalMeasurments) {
  int max = arr[0];
  for (int i = 0; i < totalMeasurments; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int getMin(int arr[], int totalMeasurments) {
  int min = arr[0];
  for (int i = 0; i < totalMeasurments; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

float getAverage(int arr[], int totalMeasurments) {
  float total = 0.0;
  for (int i = 0; i < totalMeasurments; i++) {
    total += arr[i];
  }
  return total / totalMeasurments;
}

void getNormalizedValues(int arr[], int normArr[], int totalMeasurments) {
  for (int i = 0; i < totalMeasurments; i++) {
    normArr[i] = arr[i] - round(getAverage(arr, totalMeasurments));
  }
}

void enterValues(int arr[], int *totalMeasurments) {
  char choice = 'o';
  int measurement = 0;
  while (choice != 'q' && *totalMeasurments < 10) {
    printf("Enter measurement #%d (or q to quit) : ", *totalMeasurments + 1);
    if (scanf("%d%*c", &measurement) == 0) {
      scanf("%c%*c", &choice);
      if (choice != 'q') {
        printf("Invalid input.\n");
      }
    } else {
      arr[*totalMeasurments] = measurement;
      *totalMeasurments += 1;
    }
  }
  if (*totalMeasurments == 10) {
    printf("You cannot enter any more values.\n");
  }
}

void deleteAllValues(int *totalMeasurments) {
  if (*totalMeasurments != 0) {
    *totalMeasurments = 0;
    printf("You have now deleted your measurments\n");
  } else {
    printf("You have no measurements to delete.\n");
  }
}
