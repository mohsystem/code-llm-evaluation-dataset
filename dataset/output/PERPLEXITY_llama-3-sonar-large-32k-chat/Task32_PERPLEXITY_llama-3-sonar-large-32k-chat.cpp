#include <iostream>

int calculateYears(double principal, double interestRate, double taxRate, double desiredSum) {
    int years = 0;
    while (principal < desiredSum) {
        double interest = principal * interestRate;
        double tax = interest * taxRate;
        principal += interest - tax;
        years++;
    }
    return years;
}

int main() {
    double principal = 1000.00;
    double interestRate = 0.05;
    double taxRate = 0.18;
    double desiredSum = 1100.00;
    std::cout << calculateYears(principal, interestRate, taxRate, desiredSum) << std::endl;
    return 0;
}