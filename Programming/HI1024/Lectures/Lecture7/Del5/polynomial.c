#include <stdio.h>
#include <math.h>


double polynomial(double x) {
    return 3*pow(x,5) + 2*pow(x,4) - 5*pow(x,3) - pow(x,2) + 7 * x - 6;
}

void run() {
    double userInput;
    printf("y(x) = 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6\n");
    printf("Enter a value for x to compute the function: ");
    scanf("%le", &userInput);


    printf("y(%g) = %g\n", userInput, polynomial(userInput));
}


int main(void) {
    run();
    return 0;
}
