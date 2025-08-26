#include <stdio.h>
#include <string.h>
#define WORDLENGTH 30
#define MAX 100
#define WORDS 10

void printArray(char a[][WORDLENGTH+1]) {
    for(int i = 0; i < WORDS; i++)
        printf("%s\n", a[i]);
}

void swap(char s1[], char s2[]) {
    char temp[WORDLENGTH + 1];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}

void sort(char a[][WORDLENGTH+1]) {
    for(int i = 0; i < WORDS - 1; i++) {
        for(int j = 0; j < WORDS - 1 - i; i++) {
            if(strcmp(a[j], a[j+1]))
                swap(a[j], a[j+1]);
        }
    }
}

int main(void) {
    char wordBook[MAX][WORDLENGTH+1];

    for(int i = 0; i < WORDS; i++){
        printf("Skriv in ett ord: ");
        scanf("%s%*c", wordBook[i]);
    }
    sort(wordBook);
    printArray(wordBook);
    return 0;
}

