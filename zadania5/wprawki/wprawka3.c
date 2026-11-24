#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_AMOUNT 1
#define MAX_AMOUNT 10
#define MIN_NUMBER 0
#define MAX_NUMBER 9

int get_int(const char *prompt, int min, int max) {
    int liczba; 
    char znak;

    while(1) {
        printf("%s", prompt);
        if(scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba < min || liczba > max) {
                printf("Musisz podac liczbe w przedziale: {%d-%d}!\n", min, max);
                continue;
            }
            return liczba;
        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }
}

void fill_in_the_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % (MAX_NUMBER+1));
        }
    }
}

void print_the_matrix(int rows, int cols, const int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        puts("");
    }
}

int searching_number(int rows, int cols, const int matrix[rows][cols], int number) {
    int how_many_times = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == number) {
                how_many_times++;
            }
        }
    }
    return how_many_times;
}

int main(void) {
    srand(time(NULL));

    int amount_of_rows = get_int("Ile wierszy ma miec macierz? ", MIN_AMOUNT, MAX_AMOUNT);
    int amount_of_cols = get_int("Ile kolumn ma miec macierz? ", MIN_AMOUNT, MAX_AMOUNT);

    int matrix[amount_of_rows][amount_of_cols];

    fill_in_the_matrix(amount_of_rows, amount_of_cols, matrix);
    print_the_matrix(amount_of_rows, amount_of_cols, matrix);

    int search_number = get_int("Jaka wartosc chcesz znalezc? ", MIN_NUMBER, MAX_NUMBER);
    int how_many = searching_number(amount_of_rows, amount_of_cols, matrix, search_number);

    printf("W naszej macierzy liczba %d wystepuje %d razy\n", search_number, how_many);

    return 0;
}