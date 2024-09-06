public class Task17_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String toJadenCase(String phrase) {
        if (phrase == null || phrase.isEmpty()) return null;
        String[] words = phrase.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1).toLowerCase();
        }
        return String.join(" ", words);
    }
}