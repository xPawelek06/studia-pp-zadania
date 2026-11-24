#include <stdio.h>
#include <limits.h>

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

int is_prime(int id) {
    if (id < 2)
        return 0;

    for (int i = 2; i < id; i++) {
        if (id % i == 0) 
            return 0;
    }
    return 1;
}

int main(void) {
    int id = 0;
    int is_id_prime = 0;
    id = get_int("Podaj id: ", 1, INT_MAX);
    is_id_prime = is_prime(id);

    if (is_id_prime == 1) 
        printf("ID: %d jest liczba pierwsza\n", id);
    else
        printf("ID: %d nie jest liczba pierwsza\n", id);
}