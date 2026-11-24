#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RANDOM_RESULTS_AMOUNT 50
#define DICE 6

int main(void) {
    srand(time(NULL));
    int results[DICE] = {0};

    for (int i = 0; i < RANDOM_RESULTS_AMOUNT; i++) {
        int roll = ((rand() % DICE) + 1);
        results[roll-1]++;
    }

    puts("--- STATYSTYKI ---");
    puts("Ile razy wypadla dana wartosc:");
    for (int i = 0; i < DICE; i++) {
        printf("%d: ", i+1);
        for (int j = 0; j < results[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}