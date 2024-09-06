public class Task23_GEMINI_gemini_1_5_pro_001 {

    public static long findNb(long m) {
        long n = 1;
        long total = 0;
        while (total < m) {
            total += Math.pow(n, 3);
            if (total == m) {
                return n;
            }
            n++;
        }
        return -1;
    }
}