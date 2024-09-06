public class Task10_MISTRAL_codestral_latest {
    public static int getSum(int a, int b) {
        int sum = 0;
        for (int i = Math.min(a, b); i <= Math.max(a, b); i++) {
            sum += i;
        }
        return sum;
    }
}