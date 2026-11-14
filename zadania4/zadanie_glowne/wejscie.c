#include <stdio.h>
#include "odczyty.h"

int pobierz_int(const char *komunikat, int min, int max) {
    int liczba; 
    char znak;

    while(1) {
        printf("%s", komunikat);
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

double pobierz_double(const char *komunikat, int min, int max) {
    double temp;
    char znak;

    while(1) {
        printf("%s", komunikat);
        if (scanf("%lf%c", &temp, &znak) == 2 && znak == '\n') {
            if (temp < min || temp > max) {
                printf("Wartosc musi miescic sie w zakresie {%d-%d}!\n", min, max);
                continue;
            }

            return temp;
        } else {
            printf("Musisz podac liczbe!\n");
            while(getchar() != '\n');
        }
    }
}