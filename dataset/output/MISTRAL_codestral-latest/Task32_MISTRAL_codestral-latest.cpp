// C++
#include <iostream>

int calculateYears(double principal, double interest, double tax, double desired) {
    int years = 0;
    while (principal < desired) {
        double interestEarned = principal * interest;
        double taxAmount = interestEarned * tax;
        principal += interestEarned - taxAmount;
        years++;
    }
    return years;
}

int main() {
    std::cout << calculateYears(1000.0, 0.05, 0.18, 1100.0);
    return 0;
}