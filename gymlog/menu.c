#include <stdio.h>
#include "wejscie.h"
#include "serie.h"

void menu(int *ilosc_serii, int tab_serii[]) {
    int dziala = 1;
    int wybor;

    printf("WITAJ W GYMLOG'u\n");

    while (dziala) {
        printf("1. Dodaj serie\n");
        printf("2. Pokaz serie\n");
        printf("3. Planer serii\n");
        printf("4. Wyczysc\n");
        printf("5. Wyjscie\n");
        wybor = pobierz_int("Co chcesz zrobic? ", 1, 5);

        switch(wybor) {
            case 1: {
                dodaj_serie(ilosc_serii, tab_serii);
                break;
            }
            case 2: {
                pokaz_serie(*ilosc_serii, tab_serii);
                break;
            }
            case 3: {
                planer_serii();
                break;
            }
            case 4: {
                wyczysc(ilosc_serii);
                break;
            }

            case 5: {
                printf("Wylogowano\n");
                dziala = 0;
            }
        }
    }
}