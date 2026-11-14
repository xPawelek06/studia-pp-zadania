#include <stdio.h>

int pobierz_int(const char *komunikat, int min, int max) {
    int liczba;
    char znak;

    while(1) {
        printf("%s", komunikat);
        if (scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba < min || liczba > max) {
                printf("Musisz podac liczbe z przedzialu: {%d-%d}\n", min, max);
                continue;
            }

            return liczba;
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }

}