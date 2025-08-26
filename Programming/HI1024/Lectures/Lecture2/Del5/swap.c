#include <stdio.h>

int main(void) {
    int a, b;
    printf("Ange a: ");
    scanf("%d", &a);
    printf("Ange b: ");
    scanf("%d", &b);

    printf("a: %d, b: %d\n", a, b);
    printf("Swapping values...\n");
    int temp = a;
    a = b;
    b = temp;
    
    printf("a: %d, b: %d\n", a, b);

    return 0;
}