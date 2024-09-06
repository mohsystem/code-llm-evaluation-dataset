
class Solution {
public:
    static int calculateYears(double principal, double interest, double tax, double desired) {
        int years = 0;
        while (principal < desired) {
            double interestEarned = principal * interest;
            double taxPaid = interestEarned * tax;
            principal += interestEarned - taxPaid;
            years++;
        }
        return years;
    }
};
