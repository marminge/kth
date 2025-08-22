#include <stdio.h>

int main(void) {
    int month, day, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("You entered the date %d%02d%d\n", year, month, day);

    return 0;
}
