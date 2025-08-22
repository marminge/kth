#include <stdio.h>

int main() {
    int start = 1;
    while (start < 33) {
        ((start != 32) ? printf("%d, ", start) : printf("%d", start));
        start *= 2;
    }
    return 0;
}
