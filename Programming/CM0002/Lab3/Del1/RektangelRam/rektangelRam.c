#include <stdio.h>

int main() {
  int cols, rows;

  printf("Ange bredd: ");
  scanf("%d", &cols);
  printf("Ange höjd: ");
  scanf("%d", &rows);

  for (int i = 0; i < rows; i++) {
    if(i == 0 || i == rows-1) {
      for(int j = 0; j < cols; j++)
        printf("*");
    } else {
      for(int j = 0; j < cols; j++) {
        if(j == 0 || j == cols-1)
          printf("*");
        else
          printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
