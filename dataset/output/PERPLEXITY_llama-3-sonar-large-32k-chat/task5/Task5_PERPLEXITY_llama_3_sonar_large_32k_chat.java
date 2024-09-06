public class Task5_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int persistence(long n) {
        int count = 0;
        while (n >= 10) {
            n = multiplyDigits(n);
            count++;
        }
        return count;
    }

    public static long multiplyDigits(long n) {
        long product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        return product;
    }
}