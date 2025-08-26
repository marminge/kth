#include <stdio.h>

int main(void) {
    int i = 5;
    int *p = &i;

    printf("i = %d\n", i);
    printf("i = %d\n", *p);
    printf("i = %d\n", *&i);

    /*
    Aliases for i
    i = *p
    i = *&p
    */
    return 0;
}
