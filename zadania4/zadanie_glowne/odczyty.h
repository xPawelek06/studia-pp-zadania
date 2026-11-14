#ifndef ODCZYTY_H
#define ODCZYTY_H

int czy_sa_odczyty(int odczyty);
void wprowadz_odczyty_czujnikow(int ilosc_czujnikow, int *odczyty, double temp[]);
void wyswietl_aktualne_odczyty(int odczyty, double temp[]);
void przeprowadz_kalibracje(int odczyty, double temp[]);
void przeprowadz_diagnostyke(int odczyty, double temp[]);
void reczna_korekta_odczytu(int odczyty, int ilosc_czujnikow, double temp[]);
void wyswietl_raport(int odczyty, double temp[]);

#define MAX_CZUJNIKOW 20
#define WARTOSC_MIN -100
#define WARTOSC_MAX 200
#define BEZPIECZNA_WARTOSC_MIN 10
#define BEZPIECZNA_WARTOSC_MAX 80

#endif