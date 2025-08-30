// #include <bits/pthreadtypes.h>
#include <stdio.h>
#include <string.h>
#define WORDLENGTH 100
#define MAX 50

void writeToFile(char s[][WORDLENGTH], int *counter) {
  FILE *fp = fopen("nameBook.txt", "a");
  if (fp != NULL) {
    printf("Enter name: ");
    scanf("%s%*c", s[*counter]);
    fprintf(fp, "%s\n", s[*counter]);
    *counter += 1;
    fclose(fp);
  } else {
    printf("Could not open file.\n");
  }
}

void printFromFile() {
  FILE *fp = fopen("nameBook.txt", "r");
  if (fp == NULL) {
    printf("The book is empty.\n");
  } else if (fp != NULL) {
    char temp[WORDLENGTH];
    while (fgets(temp, sizeof(temp), fp)) {
      printf("%s", temp);
    }
    fclose(fp);
  }
}

void writeFileToArray(char s[][WORDLENGTH], int *counter) {
  FILE *fp = fopen("nameBook.txt", "r");
  if (fp != NULL) {
    int count = 0;
    while (fgets(s[count], sizeof(strlen(s[count])), fp)) {
      count++;
    }
    *counter = count;
    fclose(fp);
  } else if (fp == NULL) {
    printf("There are no names in the book.\n");
  }
}

void clearFile(char s[][WORDLENGTH], int *counter) {
  if (remove("nameBook.txt") == 0) {
    printf("The book is now empty.\n");
    for (int i = 0; i < *counter; i++) {
      *s[i] = '\0';
    }
    *counter = 0;
  } else {
    printf("The book is already empty.\n");
  }
}

int main(void) {
  char s[MAX][WORDLENGTH];
  int counter = 0;

  writeFileToArray(s, &counter);
  printFromFile();
  writeToFile(s, &counter);
  printFromFile();
  clearFile(s, &counter);
  printFromFile();
  return 0;
}
