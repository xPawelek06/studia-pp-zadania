#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_AMOUNT 1
#define MAX_AMOUNT 10

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
            matrix[i][j] = (rand() % 51);
        }
    }
}

void print_the_matrix(int rows, int cols, const int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        puts("");
    }
}

int bigget_number_in_row(int cols, int matrix[][cols], int which_row) {
    int biggest_number = matrix[which_row-1][0];

    for (int i = 0; i < cols; i++) {
        if (biggest_number < matrix[which_row-1][i]) {
            biggest_number = matrix[which_row-1][i];
        }
    }
    return biggest_number;
}

int main(void) {
    srand(time(NULL));

    int number_of_rows = get_int("Ile wierszy ma miec macierz? ", MIN_AMOUNT, MAX_AMOUNT);
    int number_of_cols = get_int("Ile kolumn ma miec macierz? ", MIN_AMOUNT, MAX_AMOUNT);
    int matrix[number_of_rows][number_of_cols];

    fill_in_the_matrix(number_of_rows, number_of_cols, matrix);
    print_the_matrix(number_of_rows, number_of_cols, matrix);
    
    int from_which_row = get_int("Z ktorego wiersza chcesz znalezc najwieksza wartosc: ", MIN_AMOUNT, number_of_rows);
    int biggest_number = bigget_number_in_row(number_of_cols, matrix, from_which_row);

    printf("Najwieksza wartosc w wierszu %d: %d\n", from_which_row, biggest_number);

    return 0;
}