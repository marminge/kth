#include <stdio.h>

int main() {
    int n, m;
    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &m);
    int nCopy = n, mCopy = m;

    while (n != 0) {
        int remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("In lowest terms: %d/%d", nCopy / m, mCopy / m);
    return 0;
}
