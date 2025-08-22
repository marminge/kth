#include <stdio.h>

int main() {
  int maxtal;

  printf("Ange maxtal [Max 50]: ");
  scanf("%d", &maxtal);

  if(maxtal >= 1 && maxtal <= 50) {
    for(int i = 1; i <= maxtal; i++) {
      if(i == maxtal) {
        printf("%d", i);
        break;
      }
      printf("%d, ", i);
    }
    printf("\n");
  }else
    printf("Fel input.\n");


  return 0;
}
