#include <stdio.h>
#include <string.h>

int logowanie(char login[]) {
    printf("Zaloguj sie: ");
    if (scanf("%24s", login) == 1) {
        if (strcmp(login, "admin") == 0) {
            printf("Witaj, szefie!\n");
        } else {
            printf("Witaj %s\n", login);
        }
        return 0;
    } else {
        printf("Niepoprawne dane\n");
        return 1;
    }
}