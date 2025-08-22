#include <stdio.h>
#include <stdlib.h>

int main() {
  int userInput;

  printf("Ange veckodag [1-7]: ");

  scanf("%d", &userInput);
  
  char *veckodag;

  switch(userInput) {
    case 1:
      veckodag = "Måndag";
      break;
    case 2:
      veckodag = "Tisdag";
      break;
    case 3:
      veckodag = "Onsdag";
      break;
    case 4:
      veckodag = "Torsdag";
      break;
    case 5:
      veckodag = "Fredag";
      break;
    case 6:
      veckodag = "Lördag";
      break;
    case 7:
      veckodag = "Söndag";
      break;
    default:
      printf("Ogiltg input.\nAvslutar\n");
      exit(0);
  }
  
  printf("Det motsvarar %s.\nAvslutar\n", veckodag);

  return 0;
}
