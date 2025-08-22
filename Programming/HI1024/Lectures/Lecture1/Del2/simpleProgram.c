#include <stdio.h>

int main(void) {
    int tid, hastighet;

    printf("Hur lång tid (h): ");
    scanf("%d", &tid);
    printf("Hur fort (km/h)? ");
    scanf("%d", &hastighet);

    printf("Om du färdas i %d h med hastigheten %d km/h kommer du %d.\n", tid, hastighet, tid*hastighet);

    return 0;
}