#include <stdio.h>
#include <math.h>

#define TIER_1_LIMIT_KM 10
#define TIER_1_RATE 5.0

#define TIER_2_LIMIT_KM 50
#define TIER_2_RATE 3.5

#define TIER_3_LIMIT_KM 100
#define TIER_3_RATE 2.0

typedef enum {
    MENU_END,
    MENU_CALCULATE,
    MENU_OPTIONS_COUNT,
} menu_options;

int get_int(const char *prompt, int min, int max) {
    int number;
    char next_char;

    while (1) {
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

double get_double(const char *prompt, double min, double max) {
    double number;
    char next_char;

    while (1) {
        printf("%s", prompt);
        if (scanf("%lf%c", &number, &next_char) == 2 && next_char == '\n') {
            if (number < min || number > max) {
                printf("Musisz podac liczbe z przedzialu: {%0.f-%0.f}!\n", min, max);
                continue;
            } 
            return number;
        } else {
            printf("Musisz podac liczbe!\n");
            while(getchar() != '\n');
        }
    }
}

void charge(void) {
    double km_entered = 0;
    double how_much_to_pay = 0;

    km_entered = get_double("Ile kilometrow przejechales? ", 0.0, TIER_3_LIMIT_KM);

    if (km_entered <= TIER_1_LIMIT_KM) {
        how_much_to_pay = round(km_entered) * TIER_1_RATE;
    } else if (km_entered <= TIER_2_LIMIT_KM) {
        how_much_to_pay = TIER_1_LIMIT_KM * TIER_1_RATE + round(km_entered - TIER_1_LIMIT_KM) * TIER_2_RATE;
    } else {
        how_much_to_pay = (TIER_1_LIMIT_KM * TIER_1_RATE) + ((TIER_2_LIMIT_KM-TIER_1_LIMIT_KM) * TIER_2_RATE) + (round(km_entered - TIER_2_LIMIT_KM) * TIER_3_RATE);
    }

    printf("Musisz zaplacic: %.2fzl\n", how_much_to_pay);
}

int main(void) {
    menu_options choice;

    puts("WITAJ W KALKULATORZE PRZEJECHANYCH KILOMETROW!");

    do {
        puts("--- MENU ---");
        puts("1. OBLICZ");
        puts("0. ZAKONCZ");
        choice = get_int("Co chcesz zrobic? ", 0, MENU_OPTIONS_COUNT-1);

        switch (choice) {
            case MENU_END: {
                puts("Pomyslnie zakonczono");
                break;
            }
            case MENU_CALCULATE: {
                charge();
                break;
            }
            default: {
                puts("Niepoprawny wybor");
                break;
            }
        }
    } while(choice != MENU_END);

    return 0;
}