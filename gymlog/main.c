#include "logowanie.h"
#include "menu.h"
#include "serie.h"

int main(void) {
    char login[25];
    int tab_serii[MAX_SERII];
    int ilosc_serii = 0;

    if (logowanie(login) == 0) {
        menu(&ilosc_serii, tab_serii);
    }

    return 0;
}