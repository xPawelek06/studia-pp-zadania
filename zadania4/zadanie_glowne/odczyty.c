#include <stdio.h>
#include "odczyty.h"
#include "wejscie.h"

int czy_sa_odczyty(int odczyty) {
    if (odczyty == 0) {
        printf("Musisz najpierw wprowadzic odczyty z czujnikow, aby uzyskac dostep do reszty opcji z menu\n");
        return 0;
    } else {
        return 1;
    }
}

int czy_w_przedziale(double wartosc, int min, int max) {
    if (wartosc > max || wartosc < min) {
        return 0;
    }
    
    return 1;
}

void wprowadz_odczyty_czujnikow(int ilosc_czujnikow, int *odczyty, double temp[]) {
    double wartosc;
    int wybor;
    int nadpisz = 0;

    if (ilosc_czujnikow == *odczyty) {
        printf("Masz juz wprowadzone wszystkie odczyty\n");
        printf("1. Nadpisz\n");
        printf("2. Nie nadpisuj\n");
        wybor = pobierz_int("Co chcesz zrobic? ", 1, 2);

        switch(wybor) {
            case 1: {
                (*odczyty) = 0;
                nadpisz = 0;
                break;
            }
            case 2: {
                nadpisz = 1;
            }
        }
    }
    if (nadpisz == 0) {
        for (int i = 0; i < ilosc_czujnikow; i++) {
            printf("Czujnik %d:\n", i+1);
            wartosc = pobierz_double("Podaj wartosc czujnika: ", WARTOSC_MIN, WARTOSC_MAX);

            temp[i] = wartosc;
            (*odczyty)++;
        }
    }
}

void wyswietl_aktualne_odczyty(int odczyty, double temp[]) {
    for (int i = 0; i < odczyty; i++) {
        printf("Czujnik %d: %.2f\n", i+1, temp[i]);
    }
}

void przeprowadz_kalibracje(int odczyty, double temp[]) {
    double wartosc;
    int czy_przeprowadzamy = 1;
    wartosc = pobierz_double("O ile chcesz zmienic wszystkie wartosci? ", WARTOSC_MIN-WARTOSC_MAX, WARTOSC_MAX-WARTOSC_MIN);

    for(int i = 0; i < odczyty; i++) {
        if (czy_w_przedziale(temp[i]+wartosc, WARTOSC_MIN, WARTOSC_MAX) == 0) {
            printf("Przy kalibracji wszystkich czujnikow o %.2f wartosc %d czujnika przekroczy techniczny zakres pomiarowy!\n", wartosc, i+1);
            printf("Przerywamy dzialanie\n");
            czy_przeprowadzamy = 0;
            break;
        }
    }

    if (czy_przeprowadzamy == 1) {
        for (int i = 0; i < odczyty; i++) {
            temp[i] += wartosc;
        }
    }
}

void przeprowadz_diagnostyke(int odczyty, double temp[]) {
    int ilosc_odczytow_ponad_bezpieczny_zakres = 0;
    int ktory_czujnik = 0;
    double jaka_wartosc = 0;

    if (odczyty == 0) {
        printf("Musisz ponownie wprowadzic odczyty z czujnikow, aby przeprowadzic diagnostyke\n");
    } else {
        for (int i = 0; i < odczyty; i++) {
            if (czy_w_przedziale(temp[i], BEZPIECZNA_WARTOSC_MIN, BEZPIECZNA_WARTOSC_MAX) == 0) {
                if (ilosc_odczytow_ponad_bezpieczny_zakres == 0) {
                    ktory_czujnik = i+1;
                    jaka_wartosc = temp[i];
                    ilosc_odczytow_ponad_bezpieczny_zakres++;
                } else {
                    ilosc_odczytow_ponad_bezpieczny_zakres++;
                }
            }
        }

        printf("--- DIAGNOSTYKA ---\n");
        if (ktory_czujnik == 0 && jaka_wartosc == 0) {
            printf("Zaden odczyt nie przekracza bezpiecznego zakresu!\n");
        } else {
            printf("Ilosc odczytow przekraczajaca bezpieczny zakres: %d\n", ilosc_odczytow_ponad_bezpieczny_zakres);
            printf("Pierwszy z nich:\n");
            printf("Czujnik %d: %.2f\n", ktory_czujnik, jaka_wartosc);
        }
    }
}

void reczna_korekta_odczytu(int odczyty, int ilosc_czujnikow, double temp[]) {
    int ktory_czujnik;
    double wartosc;

    for (int i = 0; i < odczyty; i++) {
        printf("Czujnik %d: %.2f\n", i+1, temp[i]);
    }

    ktory_czujnik = pobierz_int("Wartosc ktorego czujnika chcesz zmienic? ", 1, ilosc_czujnikow);
    wartosc = pobierz_double("Podaj nowa wartosc czujnika: ", WARTOSC_MIN, WARTOSC_MAX);

    temp[ktory_czujnik-1] = wartosc;
    printf("Pomyslnie zmieniono wartosc %d czujnika na %.2f\n", ktory_czujnik, temp[ktory_czujnik-1]);
}

void wyswietl_raport(int odczyty, double temp[]) {
    double suma = 0;
    double min_temp;
    double max_temp;
    int ktory_czujnik_max;
    int ktory_czujnik_min;

    for (int i = 0; i < odczyty; i++) {
        suma += temp[i];

        if (i == 0) {
            min_temp = temp[i];
            max_temp = temp[i];
            ktory_czujnik_max = i+1;
            ktory_czujnik_min = i+1;
        }
        if (min_temp > temp[i]) {
            min_temp = temp[i];
            ktory_czujnik_min = i+1;
        }
        if (max_temp < temp[i]) {
            max_temp = temp[i];
            ktory_czujnik_max = i+1;
        }
    }

    double srednia_temp = suma / odczyty;

    printf("--- RAPORT ---\n");
    printf("Czujnik z najnizsza temperatura:\n");
    printf("Czujnik %d: %.2f\n", ktory_czujnik_min, min_temp);
    printf("Czujnik z najwyzsza temperatura:\n");
    printf("Czujnik %d: %.2f\n", ktory_czujnik_max, max_temp);
    printf("Srednia temperatura: %.2f\n", srednia_temp);
}