#include <stdio.h>
#include <limits.h>

int get_int(const char *prompt, int min, int max) {
    int number;
    char next_char;
    
    while (1) {
        printf(prompt);
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
    int number1 = 0;
    int number2 = 0;
    int meter = 0;

    while(1) {
        int choice_number = get_int("Podaj liczbe: ", 0, INT_MAX);

        if (meter == 0) {
            number1 = choice_number;
            meter++;
        } else if (meter == 1) {
            if (choice_number <= number1) {
                number1 = choice_number;
            } else {
                number2 = choice_number;
                meter++;
            }
        } else if (meter == 2) {
            if (choice_number <= number2) {
                number1 = choice_number;
                meter = 1;
            } else {
                puts("Trzy kolejne liczby sa rosnace, konczymy");
                printf("Liczba 1: %d\n", number1);
                printf("Liczba 2: %d\n", number2);
                printf("Liczba 3: %d\n", choice_number);
                break;
            }
        }
    }

    return 0;
}