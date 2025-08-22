#include <stdio.h>

int main(void) {
    int a, b;
    printf("Ange a: ");
    scanf("%d", &a);
    printf("Ange b: ");
    scanf("%d", &b);
    int temp = a;
    a = b;
    b = temp;
    printf("a: %d, b: %d\n", a, b);

    return 0;
}