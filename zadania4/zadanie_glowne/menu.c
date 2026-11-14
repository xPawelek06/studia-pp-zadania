#include <stdio.h>
#include "odczyty.h"
#include "wejscie.h"

void menu(void) {
    int wybor;
    int ilosc_czujnikow;
    int odczyty = 0;
    double temp[MAX_CZUJNIKOW];
    int dziala = 1;

    printf("Witaj w systemie chlodzenia statku badawczego ARGO!\n");
    ilosc_czujnikow = pobierz_int("Ile czujnikow chcesz obsluzyc? ", 1, MAX_CZUJNIKOW);

    while (dziala) {
        printf("--- MENU ---\n");
        printf("1. Wprowadz odczyty czujnikow\n");
        printf("2. Wyswietl aktualne odczyty czujnikow\n");
        printf("3. Przeprowadz kalibracje\n");
        printf("4. Przeprowadz diagnostyke\n");
        printf("5. Reczna korekta odczytu wybranego czujnika\n");
        printf("6. Wyswietl raport\n");
        printf("7. Zakoncz dzialanie\n");
        wybor = pobierz_int("Co chcesz zrobic? ", 1, 7);

        switch(wybor) {
            case 1: {
                wprowadz_odczyty_czujnikow(ilosc_czujnikow, &odczyty, temp); 
                break;
            }
            case 2: {
                if (czy_sa_odczyty(odczyty) == 1) {
                    wyswietl_aktualne_odczyty(odczyty, temp);
                }
                break;
            }
            case 3: { 
                if (czy_sa_odczyty(odczyty) == 1) {
                    przeprowadz_kalibracje(odczyty, temp);
                } 
                break;
            }
            case 4: { 
                if (czy_sa_odczyty(odczyty) == 1) {
                    przeprowadz_diagnostyke(odczyty, temp); 
                }
                break;
            }
            case 5: { 
                if (czy_sa_odczyty(odczyty) == 1) {
                    reczna_korekta_odczytu(odczyty, ilosc_czujnikow, temp); 
                }
                break;
            }
            case 6: {
                if (czy_sa_odczyty(odczyty) == 1) {
                    wyswietl_raport(odczyty, temp);
                }
                break;
            }
            case 7: {
                printf("Pomyslnie zakonczono dzialanie\n");
                dziala = 0;
            }

        }
    }
}