public class Task23_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static long findNb(long m) {
        long n = 1;
        long volume = 0;
        while (volume < m) {
            volume += (long) Math.pow(n, 3);
            if (volume == m) {
                return n;
            }
            n++;
        }
        return -1;
    }
}