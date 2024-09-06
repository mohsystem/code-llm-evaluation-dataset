#include <stdio.h>

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
    // Test the function here
    return 0;
}