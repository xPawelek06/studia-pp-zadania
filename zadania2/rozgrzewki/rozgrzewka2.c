#include <stdio.h>

#define CEL_MINUT 300

int main(void) {
    int liczba;
    char znak;
    int liczba_sesji = 0;
    int laczny_czas_nauki = 0;

    do {
        printf("Ile minut poswieciles na nauke? ");
        if (scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba <= 0) {
                printf("Liczba minut nie moze byc ujemna!\n");
            } else {
                laczny_czas_nauki += liczba;
                liczba_sesji++;
                printf("Sesja %d: %d minut\n", liczba_sesji, liczba);
            }
        } else {
            printf("Musisz podac liczbe calkotiwa!\n");
            while(getchar() != '\n');
        }
    } while (laczny_czas_nauki < CEL_MINUT);

    printf("Przeprowadziles %d sesji i w tym czasie poswieciles %d minut na nauke\n", liczba_sesji, laczny_czas_nauki);

    return 0;
}