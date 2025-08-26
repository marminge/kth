#include <stdio.h>

int num_digits(int n) {
    int iterations = 0;
    while (n != 0) {
        n /= 10;
        iterations++;
    }
    return iterations;;
}

int main(void) {
    printf("Ange ett heltal: ");
    int n;
    scanf("%d", &n);

    printf("%d\n", num_digits(n));

    return 0;
}
