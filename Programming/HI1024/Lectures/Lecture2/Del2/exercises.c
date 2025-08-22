#include <stdio.h>

void a(void) {
    int i = 5, j = 3;
    printf("%d %d", i / j, i % j);
}

void b(void) {
    int i = 2, j = 3;
    printf("%d", (i+10) % j);
}

void c(void) {
    int i = 7, j = 8, k = 9;
    printf("%d", (i+10) % k / j);
}

void d(void) {
    int i = 1, j = 2, k = 3;
    printf("%d", (i+5) % (j+2) / k);
}

int main(void) {
    d();
    return 0;
}