#include <stdio.h>

#define MOC_MAX 100
#define MOC_MIN 0

typedef enum {
    MOC_ZAKONCZ,
    MOC_ZWIEKSZ,
    MOC_ZMNIEJSZ,
    MOC_WYSWIETL,
    MENU_LICZBA,
} menu_opcji;

int pobierz_int(const char *komunikat, int min, int max) {
    int liczba;
    char znak;

    while(1) {
        printf(komunikat);
        if (scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba < min || liczba > max) {
                printf("Musisz podac liczbe z przedzialu: {%d-%d}\n", min, max);
            } else {
                return liczba;
            }
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }
}

int main(void) {
    int poziom_mocy = 0;
    int zwiekszenie = 0;
    int zmniejszenie = 0;
    menu_opcji wybor;

    printf("WITAJ W SYMULATORZE STEROWANIA PANELEM URZADZENIA DO ZUZYCIA ENERGII!\n");

    do {
        printf("--- MENU ---\n");
        printf("1. Zwieksz poziom mocy\n");
        printf("2. Zmniejsz poziom mocy\n");
        printf("3. Wyswietl aktualny poziom\n");
        printf("0. Zakoncz\n");
        wybor = pobierz_int("Co chcesz zrobic? ", 0, MENU_LICZBA-1);

        switch(wybor) {
            case MOC_ZAKONCZ: {
                printf("Pomyslnie zakonczono\n");
                break;
            }
            case MOC_ZWIEKSZ: {
                zwiekszenie = pobierz_int("O ile chcesz zwiekszyc poziom mocy? ", MOC_MIN, MOC_MAX);
                if (poziom_mocy+zwiekszenie > MOC_MAX) {
                    printf("Nie mozesz zwiekszyc poziomu mocy o %d. Przekroczysz wtedy dopuszczalna wartosc\n", zwiekszenie);
                    break;
                }
                poziom_mocy += zwiekszenie;
                printf("Udalo sie zwiekszyc poziom mocy!\n");
                printf("Aktualny poziom: %d\n", poziom_mocy);
                break;
            }
            case MOC_ZMNIEJSZ: {
                zmniejszenie = pobierz_int("O ile chcesz zmniejszyc poziom mocy? ", MOC_MIN, MOC_MAX);
                if(poziom_mocy-zmniejszenie < MOC_MIN) {
                    printf("Nie mozesz zmniejszyc poziomu mocy o %d. Zejdziesz wtedy ponizej dopuszczalna wartosc\n", zmniejszenie);
                    break;
                }
                poziom_mocy -= zmniejszenie;
                printf("Udalo sie zmniejszyc poziom mocy!\n");
                printf("Aktualny poziom: %d\n", poziom_mocy);
                break;
            }
            case MOC_WYSWIETL: {
                printf("Aktualny poziom mocy: %d\n", poziom_mocy);
                break;
            }
            default: {
                printf("Nieznana operacja\n");
                break;
            }
        }
    } while(wybor);
    
    return 0;
}