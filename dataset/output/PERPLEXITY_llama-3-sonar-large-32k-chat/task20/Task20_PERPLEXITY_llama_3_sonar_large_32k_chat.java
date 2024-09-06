public class Task20_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static long digPow(int n, int p) {
        String strN = String.valueOf(n);
        long sumOfPowers = 0;
        for (int i = 0; i < strN.length(); i++) {
            sumOfPowers += Math.pow(Character.getNumericValue(strN.charAt(i)), p + i);
        }
        long k = sumOfPowers / n;
        return k * n == sumOfPowers ? k : -1;
    }
}