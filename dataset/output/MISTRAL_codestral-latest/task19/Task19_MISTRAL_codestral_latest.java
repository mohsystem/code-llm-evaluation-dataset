public class Task19_MISTRAL_codestral_latest {
    public static String spinWords(String sentence) {
        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            if (word.length() >= 5) {
                result.append(new StringBuilder(word).reverse().toString());
            } else {
                result.append(word);
            }
            result.append(" ");
        }
        return result.toString().trim();
    }
}