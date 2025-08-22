#include <stdio.h>

int main() {
  int maxtal, counter = 1;

  printf("Ange maxtal [max 50]: ");

  scanf("%d", &maxtal);


  while(counter <= maxtal && maxtal <= 50 && maxtal >= 1) {
    printf("%d, ", counter);
    counter++;
  }
  
  printf("\n");

  return 0;
}
