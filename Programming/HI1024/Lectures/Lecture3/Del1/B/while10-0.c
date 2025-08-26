#include <stdio.h>

int main() {
    int start = 10;
    while (start >= 0) {
        ((start != 0) ? printf("%d, ", start) : printf("%d\n", start));
        start -= 2;
    }
    return 0;
}
