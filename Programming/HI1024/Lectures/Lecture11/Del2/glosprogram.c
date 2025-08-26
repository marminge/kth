#include <stdio.h>
#define WORDLENGTH 20
#define MAX 20

void addWord(char sve[][WORDLENGTH + 1], char eng[][WORDLENGTH + 1], int *nrOfWords) {
    printf("Skriv in orden som du vill lägga till.\n");
    printf("Gå tillbaka till menyn genom att ange 'q' för det svenska ordet.\n");
    for (int i = *nrOfWords; i < MAX; i++) {
        printf("Svenska: ");
        scanf("%s%*c", sve[*nrOfWords]);
        if (sve[*nrOfWords][0] == 'q') {
            sve[*nrOfWords][0] = '\000';
            break;
        }
        printf("Engelska: ");
        scanf("%s%*c", eng[*nrOfWords]);
        *nrOfWords += 1;
    }
}

void removeAllWords(char sve[][WORDLENGTH + 1], char eng[][WORDLENGTH + 1], int *nrOfWords) {
    if (*nrOfWords != 0) {
        for (int i = 0; i < *nrOfWords; i++) {
            sve[i][0] = '\000';
            eng[i][0] = '\000';
            *nrOfWords = 0;
        }
        printf("Listan är nu tom.\n");
    } else
        printf("Gloslistan är redan tom\n");
}

void printWords(char sve[][WORDLENGTH + 1], char eng[][WORDLENGTH + 1], int *nrOfWords) {
    if (*nrOfWords != 0) {
        for (int i = 0; i < *nrOfWords; i++)
            printf("%s - %s\n", sve[i], eng[i]);
    } else
        printf("Gloslistan är tom\n");
}

int meny() {
    int val;
    printf("(1) Skriv in (2) Skriv ut (3) Radera (4) Avsluta: ");
    scanf("%d", &val);
    return val;
}

int main(void) {
    char glosorSve[MAX][WORDLENGTH + 1] = {0};
    char glosorEng[MAX][WORDLENGTH + 1] = {0};
    int nrOfWords = 0, menyval = 0;

    while (menyval != 4) {
        menyval = meny();
        switch (menyval) {
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
                printf("Ogiltigt val.\n");
        }
    }
    return 0;
}
