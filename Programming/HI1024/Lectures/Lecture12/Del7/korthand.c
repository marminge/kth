#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct kort {
    int value;
    char color;
} Kort;

typedef struct korthand {
    Kort allaKort[53];
    int antalKort;
} Korthand;

void printHand(Korthand hand) {
    for(int i = 0; i < hand.antalKort; i++) {
        if(i < hand.antalKort - 1)
            printf("%c %d, ", hand.allaKort[i].color, hand.allaKort[i].value);
        else
            printf("%c %d\n", hand.allaKort[i].color, hand.allaKort[i].value);
    }
}

void swap(Korthand *hand1, Korthand *hand2) {
    srand(time(NULL));
    int randomCard = rand() % hand1->antalKort;
    hand2->allaKort[hand2->antalKort] = hand1->allaKort[randomCard];
    hand2->antalKort += 1;

    for(int i = randomCard; i < hand1->antalKort; i++) {
        hand1->allaKort[i] = hand1->allaKort[i+1];
    }
    hand1->antalKort -= 1;
}

int main(void) {
    Korthand myHand = {{{2, 's'}, {12, 'h'}, {3, 'r'}, {8, 'r'}}, 4};
    Korthand yourHand = {{{3, 'k'}, {4, 'k'}, {5, 'k'}, {6, 'k'}, {7, 'k'}}, 5};

    printf("My hand\t\t");
    printHand(myHand);
    printf("Your hand\t");
    printHand(yourHand);
    swap(&myHand, &yourHand);
    printf("\n");
    printf("My hand\t\t");
    printHand(myHand);
    printf("Your hand\t");
    printHand(yourHand);

    return 0;
}
