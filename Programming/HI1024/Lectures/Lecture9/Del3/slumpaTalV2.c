#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int longestOrder(int arr[], int n) {
    int longest = 0, temp = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            temp++;
        } else {
            if (temp > longest)
                longest = temp;
            temp = 1;
        }
    }
    return longest;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        (i == n - 1) ? printf("%d", arr[i]) : printf("%d, ", arr[i]);
    printf("\nLängsta följden är %d\n", longestOrder(arr, n));
}

int getMax() {
    int n;
    do {
        printf("Vilket är det högsta heltal du vill ha med (1-1000): ");
        scanf("%d", &n);
        if (n < 1 || n > 1000)
            printf("Du måste välja mellan 1 och 1000!\n");

    } while (n < 1 || n > 1000);

    return n;
}

void createOrder() {
    srand(time(NULL));
    int max = getMax();
    int arr[max];
    for (int i = 0; i < max; ++i) {
        arr[i] = rand() % max + 1;
    }

    printArray(arr, max);
}

int main(void) {

    createOrder();

    return 0;
}