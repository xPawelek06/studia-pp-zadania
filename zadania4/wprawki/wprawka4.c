#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_password_valid(const char password[]) {
    int is_any_digit = 0;
    int is_any_upper = 0;
    int is_any_special = 0;
    int len = strlen(password);

    if (strlen(password) < 8) {
        printf("Haslo musi zawierac co najmniej 8 znakow\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i]) == 0) {
            is_any_digit++;
        }
        if (isupper(password[i]) == 0) {
            is_any_upper++;
        }
        if (ispunct(password[i]) == 0) {
            is_any_special++;
        }

        if (is_any_digit == len) {
            printf("Haslo musi zawierac co najmniej jedna cyfre\n");
            return 0;
        } 
        if (is_any_upper == len) {
            printf("Haslo musi zawierac co najmniej jedna wielka litere\n");
            return 0;
        }
        if (is_any_special == len) {
            printf("Haslo musi zawierac co najmniej jeden znak specjalny\n");
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char password[20] = "Pawelek&";
    if (is_password_valid(password) == 1) {
        printf("Poprawnie stworzyles haslo!\n");
    } 

    return 0;
}