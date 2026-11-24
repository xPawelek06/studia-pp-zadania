#include <stdio.h>
#include "wejscie.h"

int get_int(const char *prompt, int min, int max) {
    int liczba; 
    char znak;

    while(1) {
        printf("%s", prompt);
        if(scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba < min || liczba > max) {
                printf("Musisz podac liczbe w przedziale: {%d-%d}!\n", min, max);
                continue;
            }
            return liczba;
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }
}