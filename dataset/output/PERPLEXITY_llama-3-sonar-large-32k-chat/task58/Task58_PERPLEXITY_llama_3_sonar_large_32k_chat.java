public class Task58_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean xo(String s) {
        s = s.toLowerCase();
        int xCount = 0, oCount = 0;
        for (char c : s.toCharArray()) {
            if (c == 'x') xCount++;
            if (c == 'o') oCount++;
        }
        return xCount == oCount;
    }
}