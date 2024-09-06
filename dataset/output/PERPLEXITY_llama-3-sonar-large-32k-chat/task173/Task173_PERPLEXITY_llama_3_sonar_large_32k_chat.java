public class Task173_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public String longestDupSubstring(String s) {
        int n = s.length();
        String longest = "";
        for (int len = n / 2; len >= 1; len--) {
            for (int i = 0; i <= n - len; i++) {
                String substr = s.substring(i, i + len);
                if (s.indexOf(substr) != s.lastIndexOf(substr) && substr.length() > longest.length()) {
                    longest = substr;
                }
            }
        }
        return longest;
    }
}