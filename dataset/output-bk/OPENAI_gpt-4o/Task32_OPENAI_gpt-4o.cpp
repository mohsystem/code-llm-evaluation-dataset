#include <iostream>

int calculateYears(double P, double I, double T, double D) {
    int years = 0;
    while (P < D) {
        double interest = P * I;
        double afterTax = interest - (interest * T);
        P += afterTax;
        years++;
    }
    return years;
}

int main() {
    double P = 1000.00;
    double I = 0.05;
    double T = 0.18;
    double D = 1100.00;
    int years = calculateYears(P, I, T, D);
    std::cout << years << std::endl;
    return 0;
}