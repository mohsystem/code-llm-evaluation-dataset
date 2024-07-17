#include <stdio.h>
int calculateYears(double principal, double interest, double tax, double desired) {
    int years = 0;
    while(principal < desired){
        principal += (principal * interest)*(1 - tax);
        years++;
    }
        return years;
}

int main() {
    double principal, interest, tax, desired;
    scanf("%lf", &principal);
    scanf("%lf", &interest);
    scanf("%lf", &tax);
    scanf("%lf", &desired);
    
    int result = calculateYears(principal, interest, tax, desired);
    printf("%d", result);
    return 0;
}