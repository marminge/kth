#include <stdio.h>

int arrayLength(const char array[]) {
    int length = 0;
    for (int i = 0; array[i] != '\0'; i++)
        length++;
    return length;
}

int main(void) {
    char array[] = "Hello World!";
    printf("%d\n", arrayLength(array));

    return 0;
}
