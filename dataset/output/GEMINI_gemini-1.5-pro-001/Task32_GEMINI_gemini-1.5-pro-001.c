#include <stdio.h>

int calculateYears(double principal, double desired, double interest, double tax) {
    int years = 0;
    while (principal < desired) {
        principal += (principal * interest) * (1 - tax);
        years++;
    }
    return years;
}