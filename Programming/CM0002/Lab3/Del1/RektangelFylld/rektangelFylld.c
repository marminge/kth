#include <stdio.h>

int main() {
  int cols, rows;

  printf("Ange bredd: ");
  scanf("%d", &cols);
  printf("Ange höjd: ");
  scanf("%d", &rows);

  for (int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++)
      printf("*");
    printf("\n");
  }
  return 0;
}
