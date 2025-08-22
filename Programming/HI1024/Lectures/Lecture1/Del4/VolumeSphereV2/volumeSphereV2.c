#include <stdio.h>
#include <math.h>

int main(void) {
    float radie;
    printf("Ange radien: ");
    scanf("%f", &radie);



    printf("%.3fm³\n", 4.0f/3.0f * acos(-1) * (float)pow(radie, 3));

    return 0;
}