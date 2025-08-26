#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 20
#define MAX 20

void addWord(char sve[][WORDLENGTH+1], char eng[][WORDLENGTH+1], int *nrOfWords) {
        for(int i = *nrOfWords; i < MAX; i++) {
            printf("Svenska: ");
            scanf("%s%*c", sve[*nrOfWords]);
            if(sve[*nrOfWords] == NULL){
                sve[i][WORDLENGTH+1] = '\0';
                break;
            }
            printf("Engelska: ");
            scanf("%s%*c",eng[*nrOfWords]);
            *nrOfWords++;
        }
}

void removeAllWords(char sve[][WORDLENGTH+1], char eng[][WORDLENGTH+1], int *nrOfWords) {
    if(sve[0] != NULL) {
        for(int i = 0; sve[i] != NULL; i++)
            for(int j = 0; sve[j] != NULL; j++){
                sve[i][*nrOfWords] = '\0';
                eng[i][*nrOfWords] = '\0';
            }
    }
}

void printWords(char sve[][WORDLENGTH+1], char eng[][WORDLENGTH+1], int *nrOfWords) {
    if(sve[0][*nrOfWords] != '\0') {
        for(int i = 0; sve[i] != NULL; i++)
            printf("%s - %s\n", sve[i], eng[i]);
    }
    else
        printf("Gloslistan är tom");
    printf("\n");
}

int meny() {
    int val = 3;
    while(val < 1 || val > 4) {
        val = 1;
        printf("(1) Skriv in (2) Skriv ut (3) Radera (4) Avsluta: ");
        scanf("%d", &val);
    }
    return val;
}

int main(void) {
    char glosorSve[MAX][WORDLENGTH+1];
    char glosorEng[MAX][WORDLENGTH+1];
    int nrOfWords = 0, menyval = 0;

    while(menyval != 4) {
        menyval = meny();
        switch(menyval) {
            case 1:
                addWord(glosorSve, glosorEng, &nrOfWords);
                break;
            case 2:
                printWords(glosorSve, glosorEng, &nrOfWords);
                break;
            case 3:
                removeAllWords(glosorSve, glosorEng, &nrOfWords);
                break;
            case 4:
                printf("Avslutar\n");
                break;
            default:
                exit(1);
        }
    }
    return 0;
}