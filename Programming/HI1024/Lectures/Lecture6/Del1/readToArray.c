#include <stdio.h>

int main(void) {
    int numbers[10];
    int eights = 0;

    printf("Ange 10 heltal\n");
    for (int i = 0; i < 10; i++) {
        int input;
        printf("#%d: ", i + 1);
        scanf("%d", &input);
        numbers[i] = input;
    }

    for (int i = 0; i < 10; i++)
        if (numbers[i] == 8) eights++;

    printf("Det finns %dst 8:or.\n", eights);

    return 0;
}
