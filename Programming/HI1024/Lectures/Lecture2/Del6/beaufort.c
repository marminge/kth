#include <stdio.h>

int main(void) {
    int windspeed;
    printf("Enter a wind speed: ");
    scanf("%d",&windspeed);

    if (windspeed < 0) printf("The wind speed must be a positive integer.");
    else if (windspeed < 1) printf("Calm\n");
    else if (windspeed <= 3) printf("Light air\n");
    else if (windspeed <= 27) printf("Breeze\n");
    else if (windspeed <= 47) printf("Gale\n");
    else if (windspeed <= 63) printf("Storm\n");
    else if (windspeed > 63) printf("Hurricane\n");

    return 0;
}