#ifndef SERIE_H
#define SERIE_H

void dodaj_serie(int *ilosc_serii, int tab_serii[]);
void pokaz_serie(int ilosc_serii, int tab_serii[]);
void planer_serii(void);
void wyczysc(int *ilosc_serii);

#define MAX_SERII 5
#define MAX_SERII_TRENING 6
#define OBCIAZENIE_MAX 500
#define OBCIAZENIE_MIN 1

#endif