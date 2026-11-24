#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define READINGS_AMOUNT 8
#define READING_MIN 0
#define READING_MAX 100

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
    srand(time(NULL));

    int readings[READINGS_AMOUNT];
    int new_reading;

    puts("--- PIERWOTNE ODCZYTY ---");
    for (int i = 0; i < READINGS_AMOUNT; i++) {
        readings[i] = (READING_MIN + rand() % (READING_MAX+1));
        printf("%d ", readings[i]);
    }

    new_reading = get_int("\nPodaj nowy odczyt: ", READING_MIN, READING_MAX);

    for (int i = 0; i < READINGS_AMOUNT-1; i++) {
        readings[i] = readings[i+1];
    }
    readings[READINGS_AMOUNT-1] = new_reading;

    puts("--- ODCZYTY PO ZMIANIE ---");
    for (int i = 0; i < READINGS_AMOUNT; i++) {
        printf("%d ", readings[i]);
    }

} 