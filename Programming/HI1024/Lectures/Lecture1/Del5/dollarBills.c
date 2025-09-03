#include <stdio.h>
#include <math.h>

int main(void) {
    int dollarAmount;
    int one = 0, five = 0, ten = 0, twenty = 0;


    printf("Enter a dollar amount: ");
    scanf("%d", &dollarAmount);

    if (dollarAmount >= 20) {
        int remain = (dollarAmount / 20);
        twenty = remain;
        dollarAmount -= remain * 20;
    }
    if (dollarAmount >= 10) {
        int remain = (dollarAmount / 10);
        ten = remain;
        dollarAmount -= remain * 10;
    }
    if (dollarAmount >= 5) {
        int remain = (dollarAmount / 5);
        five = remain;
        dollarAmount -= remain * 5;
    }
    if (dollarAmount >= 1) {
        int remain = dollarAmount;
        one = dollarAmount;
    }

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenty, ten, five, one);

    return 0;
}