
#include <iostream>

int calculateYears(double principal, double interest, double tax, double desired) {
    int years = 0;
    while (principal < desired) {
        double interestEarned = principal * interest;
        double taxPaid = interestEarned * tax;
        principal += interestEarned - taxPaid;
        years++;
    }
    return years;
}

int main() {
    std::cout << calculateYears(1000, 0.05, 0.18, 1100) << std::endl;
    return 0;
}
