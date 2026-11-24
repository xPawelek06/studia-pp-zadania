#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void fill_in_the_matrix(int cols, int matrix[][cols]) {
    int rows = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 101) - 50;
        }
    }
}

void print_the_matrix(int cols, const int matrix[][cols]) {
    int rows = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        puts("");
    }
}

int diagonal_sum(int cols, const int matrix[][cols]) {
    int rows = cols;
    int diagonal_sum = 0;

    for (int i = 0; i < rows; i++) {
        diagonal_sum += matrix[i][i];
    }
    return diagonal_sum;
}

int main(void) {
    srand(time(NULL));

    int matrix_size = get_int("Ile wierszy i kolumn ma miec kwadratowa macierz? ", 2, 10);
    int matrix[matrix_size][matrix_size];
    int sum;

    fill_in_the_matrix(matrix_size, matrix);
    print_the_matrix(matrix_size, matrix);
    sum = diagonal_sum(matrix_size, matrix);
    printf("Wynik: %d (", sum);
    for (int i = 0; i < matrix_size; i++) {
        printf("%d", matrix[i][i]);
        if (i < matrix_size-1) {
            printf(" + ");
        }
    }
    printf(")\n");
}