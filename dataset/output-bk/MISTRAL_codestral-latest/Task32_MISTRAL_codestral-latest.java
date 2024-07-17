// Java
public class Main {
    public static void main(String[] args) {
        System.out.println(calculateYears(1000.0, 0.05, 0.18, 1100.0));
    }

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