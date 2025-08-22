#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++)
        (i != 10) ? printf("%d, ", i) : printf("%d", i);

    return 0;
}
