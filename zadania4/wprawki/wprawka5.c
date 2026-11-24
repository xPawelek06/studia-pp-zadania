#include <stdio.h>

#define MIN_TEMP -100.0
#define MAX_TEMP 100.0
#define MAX_MEASUREMENTS_AMOUNT 20

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

double get_double(const char *prompt, int min, int max) {
    double temp;
    char znak;

    while(1) {
        printf("%s", prompt);
        if (scanf("%lf%c", &temp, &znak) == 2 && znak == '\n') {
            if (temp < min || temp > max) {
                printf("Wartosc musi miescic sie w zakresie {%d-%d}!\n", min, max);
                continue;
            }

            return temp;
        } else {
            printf("Musisz podac liczbe!\n");
            while(getchar() != '\n');
        }
    }
}

void read_measurements(double data[], int how_many) {
    double measurement;
    for (int i = 0; i < how_many; i++) {
        printf("Pomiar nr %d\n", i+1);
        measurement = get_double("Podaj pomiar: ", MIN_TEMP, MAX_TEMP);
        data[i] = measurement;
    }
}

void print_measurements(const double data[], int how_many) {
    for (int i = 0; i < how_many; i++) {
        printf("Pomiar %d: %.3f\n", i+1, data[i]);
    }
}

void normalize(double data[], int how_many) {
    double min_temp = MAX_TEMP;
    double max_temp = MIN_TEMP;

    for (int i = 0; i < how_many; i++) {
        if (data[i] > max_temp)
            max_temp = data[i];
        
        if (data[i] < min_temp) 
            min_temp = data[i];
    }

    for (int i = 0; i < how_many; i++) {
        if (min_temp == max_temp) {
            data[i] = 0;
        } else {
            data[i] = (data[i] - min_temp)/(max_temp-min_temp);
        }
    }
}

int main(void) {
    int how_many_measurements = get_int("Podaj, ile pomiarow wprowadzisz: ", 1, MAX_MEASUREMENTS_AMOUNT);
    double data[how_many_measurements];

    read_measurements(data, how_many_measurements);
    puts("Pomiary przed normalizacja:");
    print_measurements(data, how_many_measurements);
    puts("Pomiary po normalizacji:");
    normalize(data, how_many_measurements);
    print_measurements(data, how_many_measurements);

    return 0;
}