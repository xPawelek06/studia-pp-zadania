#include <stdio.h>

#define POTRZEBNE_WARTOSCI 3

int main(void) {
    int pomiary[POTRZEBNE_WARTOSCI] = {0};
    int ktory_pomiar = 0;

    do {
        int liczba;
        char znak;

        printf("Podaj pomiar: ");
        if (scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba < 0) {
                printf("Musisz podac liczbe nieujemna!\n");
                continue;
            }
            if (ktory_pomiar < POTRZEBNE_WARTOSCI) {
                pomiary[ktory_pomiar] = liczba;
                ktory_pomiar++;
            } else {
                for (int i = 1; i < POTRZEBNE_WARTOSCI; i++) {
                    pomiary[i-1] = pomiary[i];
                }
                pomiary[POTRZEBNE_WARTOSCI-1] = liczba;
            }
            if (ktory_pomiar == POTRZEBNE_WARTOSCI && pomiary[2] > pomiary[1] && pomiary[1] > pomiary[0]) {
                printf("Trzy kolejne pomiary sa coraz wieksze. Konczymy\n");
                printf("Pomiar 1: %d\n", pomiary[0]);
                printf("Pomiar 2: %d\n", pomiary[1]);
                printf("Pomiar 3: %d\n", pomiary[2]);
                break;
            }
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    } while(1);

    return 0;
}