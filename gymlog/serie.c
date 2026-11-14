#include <stdio.h>
#include "wejscie.h"
#include "serie.h"

void dodaj_serie(int *ilosc_serii, int tab_serii[]) {
    int ciezar;

    ciezar = pobierz_int("Podaj ciezar: ", OBCIAZENIE_MIN, OBCIAZENIE_MAX);

    if (*ilosc_serii == MAX_SERII) {
        for (int i=1; i < *ilosc_serii; i++) {
            tab_serii[i-1] = tab_serii[i];
        }
        tab_serii[MAX_SERII-1] = ciezar;
    } else {
        tab_serii[*ilosc_serii] = ciezar;
        (*ilosc_serii)++;
    }
    printf("Pomyslnie dodano serie\n");
    printf("Seria %d: %dkg\n", *ilosc_serii, ciezar);
}

void pokaz_serie(int ilosc_serii, int tab_serii[]) {
    if (ilosc_serii == 0) {
        printf("Brak aktualnych serii\n");
    } else {
        for (int i=0; i <ilosc_serii; i++) {
            printf("Seria %d: %dkg\n", i+1, tab_serii[i]);
        }
    }
}

void planer_serii(void) {
    int ilosc_serii_lacznie;
    ilosc_serii_lacznie = pobierz_int("Ile serii chcesz zrobic lacznie? ", 1, 50);

    int ile_treningow;
    int ile_serii_na_ostatnim;

    if (ilosc_serii_lacznie / MAX_SERII_TRENING == 0) {
        ile_treningow = 1;
    } else if (ilosc_serii_lacznie % MAX_SERII_TRENING == 0) {
        ile_treningow = ilosc_serii_lacznie / MAX_SERII_TRENING;
    } else {
        ile_treningow = ilosc_serii_lacznie / MAX_SERII_TRENING + 1;
    }

    if (ilosc_serii_lacznie % MAX_SERII_TRENING == 0) {
        ile_serii_na_ostatnim = MAX_SERII_TRENING;
    } else {
        ile_serii_na_ostatnim = ilosc_serii_lacznie % MAX_SERII_TRENING;
    }

    printf("Podczas jednego treningu mozesz wykonac max %d serii\n", MAX_SERII_TRENING);
    printf("Aby wykonac %d serii:\n", ilosc_serii_lacznie);
    if (ile_treningow == 1) {
        if (ile_serii_na_ostatnim == 5 || ile_serii_na_ostatnim == 6) {
            printf("Potrzebujesz 1 trening, na ktorym zrobisz %d serii\n", ilosc_serii_lacznie);
        } else {
            printf("Potrzebujesz 1 trening, na ktorym zrobisz %d serie\n", ilosc_serii_lacznie);
        }
    } else if ((ile_treningow % 10 == 2) || (ile_treningow % 10 == 3) || (ile_treningow % 10 == 4)) {
        if (ile_serii_na_ostatnim == 5 || ile_serii_na_ostatnim == 6) {
            printf("Potrzebujesz %d treningi. Na ostatnim zrobisz %d serii\n", ile_treningow, ile_serii_na_ostatnim);
        } else {
            printf("Potrzebujesz %d treningi. Na ostatnim zrobisz %d serie\n", ile_treningow, ile_serii_na_ostatnim);
        }
    } else {
        if (ile_serii_na_ostatnim == 5 || ile_serii_na_ostatnim == 6) {
            printf("Potrzebujesz %d treningow. Na ostatnim zrobisz %d serii\n", ile_treningow, ile_serii_na_ostatnim);
        } else {
            printf("Potrzebujesz %d treningow. Na ostatnim zrobisz %d serie\n", ile_treningow, ile_serii_na_ostatnim);
        }
    }
}

void wyczysc(int *ilosc_serii) {
    (*ilosc_serii) = 0;
    printf("Pomyslnie wyczyszczono wszystkie serie\n");
}