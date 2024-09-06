#include <stdio.h>

int calculateYears(double P, double I, double T, double D) {
    int Y = 0;
    while (P < D) {
        double interest = P * I;
        double tax = interest * T;
        P += interest - tax;
        Y++;
    }
    return Y;
}