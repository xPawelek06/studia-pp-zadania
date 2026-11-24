#include <stdio.h>

#define STEPS_GOAL 100000

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
    int steps_sum = 0;
    int day_steps;
    int how_many_days = 0;
    while(steps_sum < STEPS_GOAL) {
        day_steps = get_int("Podaj liczbe przebytych krokow: ", 0, STEPS_GOAL);
        steps_sum += day_steps;
        how_many_days++;
    }

    const char *word = "dni";
    if (how_many_days == 1) {
        word = "dzien";
    }
    printf("Osiagniecie celu %d krokow zajelo ci %d %s!\n", STEPS_GOAL, how_many_days, word);

    return 0;
}