#ifndef ODCZYTY_H
#define ODCZYTY_H

void fill_tab(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);
void show_report(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);
void count_every_system_average_efficiency(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);
void show_weakest_system(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);
void find_needed_control_systems(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);
void analyze_selected_measurement(int rows, int cols, int tab[rows][cols]);
void add_new_measurement(int rows, int cols, int max_char, char devices[rows][max_char], int tab[rows][cols]);

#define DEVICES_AMOUNT 5
#define MEASUREMENT 7
#define MAX_CHAR 20
#define NEEDED_CONTROL 40
#define MIN_SCALE 0
#define MAX_SCALE 100

#endif