#include <stdio.h>

void swap_values(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 80;
    int b = 2;
    puts("Przed zmiana:");
    printf("a=%d, b=%d\n", a, b);

    swap_values(&a, &b);
    puts("Po zmianie:");
    printf("a=%d, b=%d\n", a, b);
}