#include <stdio.h>
#include <math.h>


int polynomial(int x) {
    return 3*pow(x,5) + 2*pow(x,4) - 5*pow(x,3) - pow(x,2) + 7 * x - 6;
}

int main(void) {
    int userInput;
    printf("y(x) = 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6\n");
    printf("Enter a value for x to compute the function: ");
    scanf("%d", &userInput);


    printf("y(%d) = %d\n", userInput, polynomial(userInput));
    return 0;
}
