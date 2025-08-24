#include <stdio.h>

void fakultetFunction(int n) {
    printf("%d\n", n);

    if(n >= 1){
        unsigned long long fakulteten = 1;
        for(int i = 1; i <= n; i++)
            fakulteten *= i;
        printf("%d! = %llu\n", n, fakulteten);
    }
}

int main(void) {
    fakultetFunction(22);

    return 0;
}