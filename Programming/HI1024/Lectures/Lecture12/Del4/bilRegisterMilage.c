#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAX 100

struct car {
    char model[WORDLENGTH];
    int year;
    int milage;
};
typedef struct car Car;

enum menu {
    REGISTER = 1,
    PRINTALL,
    INCREASEMILAGE,
    END
};
typedef enum menu Menu;

void printCar(Car c) {
    printf("Bil: %s, Årsmodell: %d, mil: %d\n", c.model, c.year, c.milage);
}

Car createCar(char model[], int year, int milage) {
    Car c;
    strcpy(c.model, model);
    c.year = year;
    c.milage = milage;
    return c;
}

void regCars(Car reg[], int *nrOfCars) {
    char again[WORDLENGTH] = "ja", model[WORDLENGTH];
    int year, milage;
    while(strcmp(again, "ja") == 0) {
        printf("Ange modell: ");
        scanf("%s%*c", model);
        printf("Ange årsmodell: ");
        scanf("%d", &year);
        printf("Ange miltal: ");
        scanf("%d", &milage);
        reg[*nrOfCars] = createCar(model, year, milage);
        (*nrOfCars)++;
        printf("Vill du fortsätta? (ja/nej) ");
        scanf("%s%*c", again);
    }
}


void printRegister(Car reg[], int nrOfCars) {
    for(int i = 0; i < nrOfCars; i++) {
        printf("(%d) - ", i + 1);
        printCar(reg[i]);
    }
}

void increaseMilage(Car reg[], int nrOfCars) {
    int ökatMiltal, bil;
    printf("Vilken bil vill du öka miltalet på?\n");
    printRegister(reg, nrOfCars);
    scanf("%d", &bil);
    bil--;
    printf("Hur mycket vill du lägga till? ");
    scanf("%d", &ökatMiltal);
    reg[bil].milage += ökatMiltal;
}

int menuChoice() {
    int val;
    printf("(1) Registrera bilar\n(2) Skriv ur alla bilar\n(3) Öka mil\n(4) Avsluta\n");
    scanf("%d", &val);
    return val;
}

int main(void) {
    Car carRegister[MAX];
    int nrOfCars = 0;
    Menu menu;
    while(1) {
        menu = menuChoice();
        switch(menu) {
            case 1:
                regCars(carRegister, &nrOfCars);
                break;
            case 2:
                printRegister(carRegister, nrOfCars);
                break;
            case 3:
                increaseMilage(carRegister, nrOfCars);
                break;
            case 4:
                printf("Avslutar.\n");
                exit(1);
            default:
                printf("Ogiltigt val.");
        };
    }
    return 0;
}
