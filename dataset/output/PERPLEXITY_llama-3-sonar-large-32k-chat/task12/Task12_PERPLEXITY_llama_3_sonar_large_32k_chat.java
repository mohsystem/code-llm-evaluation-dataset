public class Task12_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String high(String s) {
        String[] words = s.split(" ");
        int maxScore = 0;
        String maxWord = "";
        for (String word : words) {
            int score = 0;
            for (char c : word.toCharArray()) {
                score += c - 96;
            }
            if (score > maxScore) {
                maxScore = score;
                maxWord = word;
            }
        }
        return maxWord;
    }
}