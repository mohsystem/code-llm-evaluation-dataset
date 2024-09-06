
int calculate_years(double principal, double interest, double tax, double desired) {
    int years = 0;
    while (principal < desired) {
        double interest_earned = principal * interest;
        double tax_paid = interest_earned * tax;
        principal += interest_earned - tax_paid;
        years++;
    }
    return years;
}
