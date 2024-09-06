public class Task174_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public String shortestPalindrome(String s) {
        String a = s + "#" + new StringBuilder(s).reverse().toString();
        int[] k = new int[a.length()];
        for (int i = 1; i < a.length(); i++) {
            int j = k[i-1];
            while (j > 0 && a.charAt(i) != a.charAt(j)) {
                j = k[j-1];
            }
            k[i] = j + (a.charAt(i) == a.charAt(j)) ? 1 : 0;
        }
        return new StringBuilder(s.substring(k[k.length-1])).reverse().toString() + s;
    }
}