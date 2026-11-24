#include <stdio.h>
#include <limits.h>

int get_int(const char *prompt, int min, int max) {
    int number;
    char next_char;

    while(1) {
        printf("%s", prompt);
        if(scanf("%d%c", &number, &next_char) == 2 && next_char == '\n') {
            if(number < min || number > max) {
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
    int choice = 0;
    int how_many_attempts = 0;
    int best_try = INT_MAX;
    int how_many_under_60 = 0;
    int sum = 0;

    while(1) {
        choice = get_int("Podaj czas: ", INT_MIN, INT_MAX);
        if (choice < 0) { break; }

        how_many_attempts++;
        sum += choice;

        if(best_try > choice) {
            best_try = choice;
        }
        if(choice < 60) {
            how_many_under_60++;
        }
    }
    if (how_many_attempts == 0) {
        puts("Nie podales zadnych poprawnych wartosci!");
    } else {
        double avg = (double)sum / how_many_attempts; 

        puts("--- STATYSTYKI ---");
        printf("Sredni czas: %.2f\n", avg);
        printf("Najlepszy wynik: %d\n", best_try);
        printf("Liczba wynikow ponizej 60 sekund: %d\n", how_many_under_60);
    }
    
    return 0;
}