#include <stdio.h>

int main() {
    int n, m;
    printf("Enter two integers: ");
    scanf("%d %d", &n, &m);

    while (n != 0) {
        int remainder = m % n;
        m = n;
        n = remainder;
    }
    printf("%d is the GCD", m);
    return 0;
}
