public class Task10_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int sumBetween(int a, int b) {
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        int sum = 0;
        for (int i = min; i <= max; i++) {
            sum += i;
        }
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(sumBetween(1, 0));
        System.out.println(sumBetween(1, 2));
        System.out.println(sumBetween(0, 1));
        System.out.println(sumBetween(1, 1));
        System.out.println(sumBetween(-1, 0));
        System.out.println(sumBetween(-1, 2));
    }
}