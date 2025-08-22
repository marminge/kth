#include <stdio.h>

int main() {
    int start = 1;
    while (start < 11) {
        ((start != 10) ? printf("%d, ", start) : printf("%d", start));
        start++;
    }
    return 0;
}
