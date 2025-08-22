#include <stdio.h>

int main(void) {
    float r1, r2, rtot;

    printf("Resistansen hos R1 (ohm): ");
    scanf("%f", &r1);
    printf("Resistansen hos R2 (ohm): ");
    scanf("%f", &r2);
    rtot = (r1*r2) / (r1+r2);

    printf("Parallellkoppling: %6.5f ohm\n", rtot);
    printf("Ersättningsresistansen vid seriekoppling är %.1f ohm\n", r1+r2);

    return 0;
}