#include <stdio.h>

int main(void) {
    double sum = 0;
    int survey_ammount = 0;
    double max_survey = 0;

    puts("DZIENNE ZUZYCIE ENERGII");

    do {
        double number;
        char next_char;

        printf("Podaj pomiar: ");
        if (scanf("%lf%c", &number, &next_char) == 2 && next_char == '\n') {
            if (number < 0) {
                printf("Musisz podac liczbe nieujemna!\n");
                continue;
            } else if(number > 0) {
                sum += number;
                survey_ammount++;
                if (max_survey < number)
                    max_survey = number;
            } else {
                if (survey_ammount == 0) {
                    printf("Od razu podales wartosc 0. Nie ma co liczyc\n");
                    break;
                } else {
                    puts("--- STATYSTYKI POMIAROWE ---");
                    printf("Liczba pomiarow: %d\n", survey_ammount);
                    printf("Suma wszystkich pomiarow: %.2f\n", sum);
                    printf("Najwiekszy podany pomiar: %.2f\n", max_survey);
                    break;
                }
            }

        } else {
            printf("Musisz podac liczbe!\n");
            while(getchar() != '\n');
        }
    } while (1);

    return 0;
}