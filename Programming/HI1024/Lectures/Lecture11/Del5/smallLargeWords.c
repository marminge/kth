#include <stdio.h>
#include <string.h>
#define WORDLENGTH 20
#define MAX 20

int arrayLength(const char array[]) {
    int length = 0;
    for (int i = 0; array[i] != '\0'; i++)
        length++;
    return length;
}

void addWords(char smallest[], char biggest[]) {
    char userInput[MAX];
    printf("När du angivit ett ord med fyra (4) bokstäver avslutas programmet.\n");
    do {
        printf("Skriv in ord: ");
        scanf("%s%*c", userInput);
        if (strcmp(userInput, biggest) > 0)
            strcpy(biggest, userInput);
        if (strcmp(userInput, smallest) < 0)
            strcpy(smallest, userInput);
        if (strlen(smallest) == 0)
            strcpy(smallest, userInput);
    } while (strlen(userInput) != 4);
}

int main(void) {
    char smallest[MAX] = {0};
    char biggest[MAX] = {0};

    addWords(smallest, biggest);
    printf("Smallest word: %s\n", smallest);
    printf("Biggest word: %s\n", biggest);

    return 0;
}
