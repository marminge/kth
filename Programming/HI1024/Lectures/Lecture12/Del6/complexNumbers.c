#include <stdio.h>
#include <math.h>

typedef struct complex {
    float real;
    float imag;
} Complex;

void printComplex(Complex number);

void multiplyComplex(Complex *number, float dec) {
    number->real *= dec;
    number->imag *= dec;
}

int equals(Complex number1, Complex number2) {
    return (number1.real == number2.real && number1.imag == number2.imag);
}

int main(void) {
    Complex c1 = {3, 2};
    Complex c2 = {2,-3};
    printComplex(c1);
    printComplex(c2);
    printf("\n");
    multiplyComplex(&c1, -2.5);
    multiplyComplex(&c2, -1);
    printComplex(c1);
    printComplex(c2);
    return 0;
}

void printComplex(Complex number) {
    if(number.real > 0 && number.imag > 0)
        printf("%.4f + %.4fi\n", number.real, number.imag);
    if(number.real < 0 && number.imag > 0)
        printf("%.4f + %.4fi\n", number.real, number.imag);
    if(number.real < 0 && number.imag < 0)
        printf("%.4f - %.4fi\n", number.real, fabs(number.imag));
    if(number.real > 0 && number.imag < 0)
        printf("%.4f - %.4fi\n", number.real, fabs(number.imag));
    if(number.real == 0 && number.imag > 0)
        printf("%.fi\n", number.imag);
    if(number.real == 0 && number.imag < 0)
        printf("%.4fi\n", number.imag);
    if(number.real > 0 && number.imag == 0)
        printf("%.4f\n", number.real);
    if(number.real < 0 && number.imag == 0)
        printf("%.4f\n", number.real);
    if(number.real == 0 && number.imag == 0)
        printf("0\n");
}
