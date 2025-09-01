#include <stdio.h>
#include <string.h>
#define NAMELENGTH 40

struct bankkonto {
    char name[NAMELENGTH];
    int saldo;
};

typedef struct bankkonto Bankkonto;

Bankkonto createAccount(char name[], int saldo) {
    Bankkonto bankkonto;
    strcpy(bankkonto.name, name);
    bankkonto.saldo = saldo;
    return bankkonto;
}

void transfer(Bankkonto *account1, Bankkonto *account2) {
    account2 -> saldo = account2 -> saldo + account1 -> saldo;
    account1 -> saldo = 0;
}

void printAccount(Bankkonto bankkonto) {
    printf("%s %d kr\n", bankkonto.name, bankkonto.saldo);
}

int main(void) {
    Bankkonto account1, account2;
    account1 = createAccount("Simran Singh", 3210);
    account2 = createAccount("Mark Asplund", 210);
  
    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);

    printAccount(account1);
    printAccount(account2);

    return 0;
}


