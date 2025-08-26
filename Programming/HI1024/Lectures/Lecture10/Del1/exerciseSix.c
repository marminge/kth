#include <stdio.h>

void find_two_largest(const int a[], const int n, int *largest, int *second_largest) {
    *largest = 0;
    *second_largest = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > *largest)
            *largest = a[i];
        else if (a[i] > *second_largest)
            *second_largest = a[i];
    }
}

int main(void) {
    const int n = 10;
    const int a[] = {1, 2, 3, 44, 25, 6, 7, 8, 9, 10};
    int largest, second_largest;

    find_two_largest(a, n, &largest, &second_largest);

    printf("Largest = %d\nSecond largest = %d\n", largest, second_largest);
    return 0;
}
