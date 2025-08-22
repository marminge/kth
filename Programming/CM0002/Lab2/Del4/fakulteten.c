#include <stdio.h>
#include <stdbool.h>

int main() {
  int userInput = 0;
  bool breaker = true;

   while(breaker) {
    printf("Ange ett positivt heltal: ");

    size_t fakulteten = 1;  //Upp till 22!

    if(scanf("%d", &userInput) == 0) {  // Kontrollerar om input är "valid" (int)
      while (getchar() == '\n');        // Rensar buffert av input. Läser av
      continue;                         // buffert från vänser till slut (\n)
    }

    if(userInput >= 1){
      for(int i = 1; i <= userInput; i++)
        fakulteten *= i;
      printf("%d! = %zu\n", userInput, fakulteten);
    }
    else if(userInput < 0)
      printf("Talet ska vara positivt.\n");
    else
      breaker = false;
  }

  printf("Avslutar.\n");

  return 0;
}
