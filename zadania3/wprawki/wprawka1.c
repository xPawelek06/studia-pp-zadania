#include <stdio.h>
#include <limits.h>

#define READING_AMOUNT 8

int get_int(const char *prompt, int min, int max) {
    int number;
    char next_char;

    while(1) {
        printf("%s", prompt);
        if (scanf("%d%c", &number, &next_char) == 2 && next_char == '\n') {
            if (number < min || number > max) {
                printf("Musisz podac liczbe z przedzialu: {%d-%d}!\n", min, max);
                continue;
            }
            return number;
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }
}

int main(void) {
    int reading[READING_AMOUNT];
    int max_growth = INT_MIN;
    int max_decrease = INT_MAX;

    for (int i = 0; i < READING_AMOUNT; i++) {
        printf("Pomiar %d\n", i+1);
        int choice = get_int("Podaj pomiar: ", INT_MIN, INT_MAX);
        reading[i] = choice;

        if (i >= 1) {
            if (reading[i] > reading[i-1]) {
                if (max_growth < reading[i]-reading[i-1]) {
                    max_growth = reading[i]-reading[i-1];
                }
            } else if (reading[i] < reading[i-1]) {
                if (max_decrease > reading[i]-reading[i-1]) {
                    max_decrease = reading[i]-reading[i-1];
                }
            }
        }
    }

    puts("--- STATYSTYKI ---");
    if (max_decrease == INT_MAX && max_growth == INT_MIN) {
        puts("Wszystkie pomiary sa identyczne");
    } else if (max_decrease != INT_MAX && max_growth == INT_MIN) {
        puts("Nie ma zadnego pomiaru wiekszego od poprzedniego");
        printf("Maksymalny spadek: %d\n", max_decrease);
    } else if (max_decrease == INT_MAX && max_growth != INT_MIN) {
        printf("Maksymalny wzrost: %d\n", max_growth);
        puts("Nie ma zadnego pomiaru mniejszego od poprzedniego");
    } else {
        printf("Maksymalny wzrost: %d\n", max_growth);
        printf("Maksymalny spadek: %d\n", max_decrease);
    }
}