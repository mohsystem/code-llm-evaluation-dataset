public class Task32_GEMINI_gemini_1_5_pro_001 {
    public static int calculateYears(double principal, double desired, double interest, double tax) {
        int years = 0;
        while (principal < desired) {
            principal += (principal * interest) * (1 - tax);
            years++;
        }
        return years;
    }
}