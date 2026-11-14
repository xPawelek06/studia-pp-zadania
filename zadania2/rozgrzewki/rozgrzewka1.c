#include <stdio.h>

#define PIERWSZY_CYKL 120
#define ROZNICA_W_CYKLACH 8
#define ILOSC_CYKLI 10

int main(void) {
    int zuzycie[ILOSC_CYKLI];
    zuzycie[0] = PIERWSZY_CYKL;
    int calkowite_zuzycie = 0;

    for (int i = 1; i<ILOSC_CYKLI; i++) {
        zuzycie[i] = zuzycie[i-1] - ROZNICA_W_CYKLACH;
    }
    for (int i = 0; i < ILOSC_CYKLI; i++) {
        calkowite_zuzycie += zuzycie[i];
    }

    for(int i=0; i < ILOSC_CYKLI; i++) {
        printf("Cykl %d: %d\n", i+1, zuzycie[i]);
    }
    printf("Calkowite zuzycie energii: %d\n", calkowite_zuzycie);
    printf("Ilosc energii zuzyta w ostatnim cyklu: %d\n", zuzycie[ILOSC_CYKLI-1]);

    return 0;
}