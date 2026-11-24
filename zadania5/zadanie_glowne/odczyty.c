#include <stdio.h>
#include <stdlib.h>
#include "odczyty.h"
#include "wejscie.h"

void fill_tab(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            tab[i][j] = (rand() % 31) + 70;
        }
    }
    show_report(rows, cols, max_char, devices, tab);
}

void show_report(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    puts("--- AKTUALNE WYNIKI WSZYSTKICH SYSTEMOW:");

    for(int i = 0; i < rows; i++) {
        printf("%s: - ", devices[i]);
        for(int j = 0; j < cols; j++) {
            printf("%d - ", tab[i][j]);
        }
        puts("");
    }
}

void count_every_system_average_efficiency(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    puts("--- SREDNIA POMIAROW KAZDEGO SYSTEMU ---");
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        printf("%s: ", devices[i]);
        for(int j = 0; j < cols; j++) {
            sum += tab[i][j];
        }
        double avg = (double)sum / cols;
        printf("%.2f\n", avg);
    }
}

void show_weakest_system(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    int weakest_system;
    int weakest_system_sum = 0;
    int sum = 0;
    double avg = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum += tab[i][j];
        }
        if(i == 0) {
            weakest_system = i;
            weakest_system_sum = sum;
        } else {
            if(weakest_system_sum > sum) {
                weakest_system = i;
                weakest_system_sum = sum;
            }
        }
        sum = 0;
    }
    avg = (double)weakest_system_sum / cols;
    printf("Najslabszy system: %s\n", devices[weakest_system]);
    printf("Srednia sprawnosc tego systemu: %.2f\n", avg);
}

void find_needed_control_systems(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    int is_needed_control = 0;
    int measurements_under_min = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(tab[i][j] < NEEDED_CONTROL) {
                measurements_under_min++;
            }
        }
        if (measurements_under_min != 0) {
            printf("System %s potrzebuje kontroli!\n", devices[i]);
            is_needed_control++;
            measurements_under_min = 0;
        }
    }
    if(is_needed_control == 0) {
        puts("Zaden system nie potrzebuje kontroli");
        puts("Wszystko jest w normie");
    }
}

void analyze_selected_measurement(int rows, int cols, int tab[rows][cols]) {
    int selected_measurement = get_int("Ktory pomiar chcesz przeanalizowac? ", 1, cols);
    int sum = 0;

    for(int i = 0; i < rows; i++) {
        sum += tab[i][selected_measurement-1];
    }
    double avg = (double)sum / rows;

    printf("Srednia sprawnosc pomiaru nr %d dla wszystkich urzadzen: %.2f\n", selected_measurement, avg);
}

void add_new_measurement(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        printf("System %s\n", devices[i]);
        int new_measurement = get_int("Podaj nowy pomiar dla systemu: ", MIN_SCALE, MAX_SCALE);
        for(int j = 0; j < cols-1; j++) {
            tab[i][j] = tab[i][j+1];
        }
        tab[i][cols-1] = new_measurement;
    }
    puts("Pomyslnie dodano nowe pomiary dla urzadzen");
}