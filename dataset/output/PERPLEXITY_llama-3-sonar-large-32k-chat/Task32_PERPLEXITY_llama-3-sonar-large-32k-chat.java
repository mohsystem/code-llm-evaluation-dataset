public class Main {
    public static int calculateYears(double principal, double interestRate, double taxRate, double desiredSum) {
        int years = 0;
        while (principal < desiredSum) {
            double interest = principal * interestRate;
            double tax = interest * taxRate;
            principal += interest - tax;
            years++;
        }
        return years;
    }

    public static void main(String[] args) {
        double principal = 1000.00;
        double interestRate = 0.05;
        double taxRate = 0.18;
        double desiredSum = 1100.00;
        System.out.println(calculateYears(principal, interestRate, taxRate, desiredSum));
    }
}