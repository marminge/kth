#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a, b, c, d;
    printf("Skriv in fyra nummer (** ** ** **): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    if (a > c)
        swap(&a, &c);
    if (b > d)
        swap(&b, &d);

    printf("Biggest: %d\nSmallest: %d\n", d, a);

    return 0;
}