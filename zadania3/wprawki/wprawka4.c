#include <stdio.h>
#include <limits.h>

#define READINGS_AMOUNT 12

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

int longest_rising(const int readings[], int amount, int *start, int *end) {
    int current_length = 1;
    int max_length = 1;

    for (int i = 1; i < amount; i++) {
        if (readings[i] > readings[i-1]) {
            current_length++;

            if (current_length > max_length) {
                max_length = current_length;
                *start = i - current_length + 1;
                *end = i;
            }
        } else {
            current_length = 1;
        }
    }
    return max_length;
}

int main(void) {
    int readings[READINGS_AMOUNT];
    int max_length;
    int first_index = 0;
    int last_index = 0;

    for (int i = 0; i < READINGS_AMOUNT; i++) {
        readings[i] = get_int("Podaj pomiar: ", INT_MIN, INT_MAX);
    }
    max_length = longest_rising(readings, READINGS_AMOUNT, &first_index, &last_index);
    puts("--- STATYSTYKI ---");
    printf("Dlugosc najdluzszej serii: %d\n", max_length);
    printf("Indeks poczatku: %d\n", first_index);
    printf("Indeks konca: %d\n", last_index);

    return 0;
}