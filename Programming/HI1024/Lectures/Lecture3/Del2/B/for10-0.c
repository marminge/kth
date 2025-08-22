#include <stdio.h>

int main() {
    for (int i = 10; i >= 0; i -= 2)
        (i != 0) ? printf("%d, ", i) : printf("%d", i);

    return 0;
}
