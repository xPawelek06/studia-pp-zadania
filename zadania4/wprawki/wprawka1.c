#include <stdio.h>

double amplified_signal(double base_value, double gain, int steps) {
    double signal = base_value;
    
    for (int i = 0; i < steps; i++) {
        signal *= gain;
    }
    return signal;
}

int main(void) {
    double base_value = 2.0;
    double gain = 4.0;
    int steps = 5;
    double signal = amplified_signal(base_value, gain, steps);

    printf("Wynik: %.2f\n", signal);

    return 0;
}