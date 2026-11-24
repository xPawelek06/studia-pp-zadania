#include <stdio.h>
#include "menu.h"
#include "odczyty.h"
#include "wejscie.h"

typedef enum {
    MENU_SHOW_REPORT = 1,
    MENU_COUNT_EVERY_SYSTEM_AVERAGE_EFFICIENCY = 2,
    MENU_SHOW_WEAKEST_SYSTEM = 3,
    MENU_FIND_NEEDED_CONTROL_SYSTEMS = 4,
    MENU_ANALYZE_SELECTED_MEASUREMENT = 5,
    MENU_ADD_NEW_MEASUREMENT = 6,
    MENU_END = 7,
    MENU_COUNT_OPTIONS = 8,
} options_menu;

void menu(void) {
    char devices[DEVICES_AMOUNT][MAX_CHAR] = {"Navigation", "Life Support", "Communication", "Propulsion", "Shield Generator"};
    int tab[DEVICES_AMOUNT][MEASUREMENT];
    options_menu choice;

    puts("WITAJ W SYSTEMIE DIAGNOSTYCZNYM MONITORUJACYM SPRAWNOSC NAJWAZNIEJSZYCH URZADZEN POKLADOWYCH!");
    printf("Monitorujemy %d urzadzen:\n", DEVICES_AMOUNT);
    for (int i = 0; i < DEVICES_AMOUNT; i++) {
        printf("%d. %s\n", i+1, devices[i]);
    }

    fill_tab(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);

    do {
        puts("\n--- MENU ---");
        puts("1. Wyswietl raport");
        puts("2. Oblicz srednia sprawnosc kazdego systemu");
        puts("3. Wskaz najslabszy system");
        puts("4. Znajdz systemy wymagajace kontroli");
        puts("5. Przeanalizuj wybrany pomiar");
        puts("6. Dodaj nowe pomiary");
        puts("7. Zakoncz program");
        choice = get_int("Co chcesz zrobic? ", 1, MENU_COUNT_OPTIONS-1);

        switch(choice) {
            case MENU_SHOW_REPORT: {
                show_report(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);
                break;
            }
            case MENU_COUNT_EVERY_SYSTEM_AVERAGE_EFFICIENCY: {
                count_every_system_average_efficiency(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);
                break;
            }
            case MENU_SHOW_WEAKEST_SYSTEM: {
                show_weakest_system(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);
                break;
            }
            case MENU_FIND_NEEDED_CONTROL_SYSTEMS: {
                find_needed_control_systems(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);
                break;
            }
            case MENU_ANALYZE_SELECTED_MEASUREMENT: {
                analyze_selected_measurement(DEVICES_AMOUNT, MEASUREMENT, tab);
                break;
            }
            case MENU_ADD_NEW_MEASUREMENT: {
                add_new_measurement(DEVICES_AMOUNT, MEASUREMENT, MAX_CHAR, devices, tab);
                break;
            }
            case MENU_END: {
                puts("Pomyslnie zakonczono");
                break;
            }
            default: {
                puts("Niepoprawny wybor");
                break;
            }
        }
    } while(choice != MENU_END);
}