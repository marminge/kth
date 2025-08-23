#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int rand1 = rand() % 10 - 2;
    float rand2 = rand() / (float) RAND_MAX * 5.0 - 2.0;
    float rand3 = rand() / (float) RAND_MAX * 24;


    printf("Heltal -2 till 7 med samma sannolikhet: %d\n", rand1);
    printf("Decimaltal i intervallet -2 <= x <= 3: %.5f\n", rand2);
    printf("Decimaltal i intervallet 0 <= x <= 24: %.5f\n", rand3);

    return 0;
}
