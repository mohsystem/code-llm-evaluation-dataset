public class Task168_MISTRAL_codestral_latest {
    public static String tweakLetters(String word, int[] tweaks) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            result.append((char) (word.charAt(i) + tweaks[i]));
        }
        return result.toString();
    }
}