#include <stdio.h>

void avg_sum(const double arr[], const int n, double *avg, double *sum) {
    *sum = 0.0;
    for (int i = 0; i < n; i++)
        *sum += arr[i];
    *avg = *sum / n;
}

int main(void) {
    const int n = 5;
    const double arr[] = {1.2, 2.3, 5.3, 7.4, 1.5};
    double avg, sum;
    avg_sum(arr, n, &avg, &sum);
    printf("avg = %.2f\nsum = %.2f\n", avg, sum);

    return 0;
}
