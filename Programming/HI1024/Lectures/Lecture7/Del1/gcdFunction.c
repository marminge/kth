#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int n, m;
    printf("Enter two integers: ");
    scanf("%d %d", &n, &m);


    printf("%d is the GCD\n", gcd(n, m));
    return 0;
}
