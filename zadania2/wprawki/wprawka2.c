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
    int sum = 0;
    int max_digit = 0;
    int even_digit_amount = 0;

    int number = get_int("Podaj jakas liczbe: ", 1, INT_MAX);
    int n = 0;

    while (number > 0) {
        n = number % 10;
        sum += n;
        if (n > max_digit)
            max_digit = n;

        if (n % 2 == 0) {
            even_digit_amount++;
        }

        number /= 10;
    }

    puts("--- STATYSTYKI LICZBY ---");
    printf("Suma cyfr: %d\n", sum);
    printf("Najwieksza cyfra: %d\n", max_digit);
    printf("Liczba cyfr parzystych: %d\n", even_digit_amount);

    return 0;
}