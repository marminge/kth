#include <stdio.h>
#define MAX_LENGTH 100

int arrayLength(const char array[]) {
    int length = 0;
    for (int i = 0; array[i] != '\0'; i++)
        length++;
    return length;
}

void stringCat(char stringOne[], char stringTwo[]) {
    int lengthOne = arrayLength(stringOne);
    int lengthTwo = arrayLength(stringTwo);
    for (int i = 0; i < lengthTwo; i++)
        stringOne[lengthOne + i] = stringTwo[i];
}

int main(void) {
    char arrayOne[MAX_LENGTH] = "Hello ";
    char arrayTwo[] = "World!";
    stringCat(arrayOne, arrayTwo);
    printf("%s\n", arrayOne);

    return 0;
}
