#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct temperaturdata Temperaturdata;
struct temperaturdata {
    char date[11];
    float values[MAX];
    int amountOfValues;
};

void printTemp(Temperaturdata temp) {
    printf("%s ", temp.date);
    for (int i = 0; i < temp.amountOfValues; i++) {
        (i < temp.amountOfValues - 1) ? printf("%g, ", temp.values[i]): printf("%g\n", temp.values[i]);
    }
}

void concatenate(Temperaturdata *temp1, Temperaturdata *temp2) {
    if(strcmp(temp1->date, temp2->date) == 0) {
        for(int i = 0; i < temp2->amountOfValues; i++) {
            if(temp1->amountOfValues < MAX) {
                temp1->values[temp1->amountOfValues] = temp2->values[i];
                temp1->amountOfValues += 1;
            }
        }
    }
}

int main(void) {
    Temperaturdata temperatures1 = {"2021-06-27", {18.8, 19.2, 18.3}, 3};
    Temperaturdata temperatures2 = {"2021-06-27", {22.1, 23.4}, 2};
    printTemp(temperatures1);
    concatenate(&temperatures1, &temperatures2);
    printTemp(temperatures1);
    return 0;
}
