public class Task32_MISTRAL_codestral_latest {
    public static int calculateYears(double principal, double interest, double tax, double desired) {
        int years = 0;
        while (principal < desired) {
            double interestEarned = principal * interest;
            double taxAmount = interestEarned * tax;
            principal += interestEarned - taxAmount;
            years++;
        }
        return years;
    }
}