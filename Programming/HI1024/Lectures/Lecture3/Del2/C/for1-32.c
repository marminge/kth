#include <stdio.h>

int main() {
    for (int i = 1; i <= 32; i *= 2)
        (i != 32) ? printf("%d, ", i) : printf("%d", i);

    return 0;
}