#include <stdio.h>
#include <stdlib.h>

int main () {
  int a = 100, b = 1;
  
  while(1) {
    if (a <= b) {
      printf("\n");
    printf("SLUT  a: %d, b: %d\n", a, b);
      exit(0);
    }
  
    printf("a: %d, b: %d\n", a, b);

    if (a/b > 20) {
      a /= 2;
      continue;
    } else if (b < a/2){
      b += 2;
      printf("b: %d\n", b);
    } else {
      b += 1;
      printf("b: %d\n", b);
    }
  }


  return 0;
}
