#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDLENGTH 50
#define MAX 100

typedef struct car {
  char model[WORDLENGTH];
  int year;
  int milage;
} Car;

typedef enum menu { REGISTER = 1, PRINTALL, INCREASEMILAGE, END } Menu;

void skrivTillFil(char s[], int year, int milage) {
  FILE *fp = fopen("bilregister.txt", "a");
  if (fp != NULL) {
    fprintf(fp, "%s %d %d\n", s, year, milage);
    fclose(fp);
  } else {
    printf("Could not open file.\n");
  }
}

void skrivUtFrånFil() {
  FILE *fp = fopen("bilregister.txt", "r");
  if (fp == NULL) {
    printf("Bilregistret är tomt.\n");
  } else if (fp != NULL) {
    char model[WORDLENGTH];
    int year;
    int milage;
    int counter = 1;
    while (fscanf(fp, "%s %d %d", model, &year, &milage) == 3) {
      printf("[%d] Modell: %s Årsmodell: %d Miltal: %d\n\n", counter, model,
             year, milage);
      counter++;
    }
    fclose(fp);
  }
}

void uppdateraFil(Car reg[], int nrOfCars) {
  remove("bilregister.txt");
  for (int i = 0; i < nrOfCars; i++) {
    skrivTillFil(reg[i].model, reg[i].year, reg[i].milage);
  }
}

Car createCar(char model[], int year, int milage) {
  Car c;
  strcpy(c.model, model);
  c.year = year;
  c.milage = milage;
  return c;
}

void uppdateraArray(Car reg[], int *nrOfCars) {
  FILE *fp = fopen("bilregister.txt", "r");
  if (fp != NULL) {
    char model[WORDLENGTH];
    int year;
    int milage;
    while (fscanf(fp, "%s %d %d", model, &year, &milage) == 3) {
      reg[*nrOfCars] = createCar(model, year, milage);
      *nrOfCars += 1;
    }
    fclose(fp);
  }
}

void regCars(Car reg[], int *nrOfCars) {
  char again[WORDLENGTH] = "ja", model[WORDLENGTH];
  int year, milage;
  while (strcmp(again, "ja") == 0) {
    printf("Ange modell: ");
    scanf("%s%*c", model);
    printf("Ange årsmodell: ");
    scanf("%d", &year);
    printf("Ange miltal: ");
    scanf("%d", &milage);
    reg[*nrOfCars] = createCar(model, year, milage);
    skrivTillFil(model, year, milage);
    (*nrOfCars)++;
    printf("Vill du fortsätta? (ja/nej) ");
    scanf("%s%*c", again);
  }
  printf("\n");
}

void increaseMilage(Car reg[]) {
  int ökatMiltal, bil;
  printf("Vilken bil vill du öka miltalet på?\n");
  skrivUtFrånFil();
  printf("Val: ");
  scanf("%d", &bil);
  bil--;
  printf("Hur mycket vill du lägga till? ");
  scanf("%d", &ökatMiltal);
  printf("\n");
  reg[bil].milage += ökatMiltal;
}

int menuChoice() {
  int val;
  printf("(1) Registrera bilar\n"
         "(2) Skriv ur alla bilar\n"
         "(3) Öka mil\n"
         "(4) Avsluta\n\n");
  printf("Val: ");
  scanf("%d", &val);
  printf("\n");
  return val;
}

int main(void) {
  Car carRegister[WORDLENGTH];
  int nrOfCars = 0;
  Menu menu;
  uppdateraArray(carRegister, &nrOfCars);
  while (1) {
    menu = menuChoice();
    switch (menu) {
    case 1:
      regCars(carRegister, &nrOfCars);
      break;
    case 2:
      skrivUtFrånFil();
      break;
    case 3:
      increaseMilage(carRegister);
      uppdateraFil(carRegister, nrOfCars);
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
