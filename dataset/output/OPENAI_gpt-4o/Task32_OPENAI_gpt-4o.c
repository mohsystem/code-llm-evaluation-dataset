#include <stdio.h>

int calculateYears(double P, double I, double T, double D) {
    int years = 0;
    while (P < D) {
        P += P * I * (1 - T);
        years++;
    }
    return years;
}

int main() {
    double P = 1000.00;
    double I = 0.05;
    double T = 0.18;
    double D = 1100.00;
    printf("%d\n", calculateYears(P, I, T, D));
    return 0;
}