public class Main {
    public static String tweakLetters(String word, int[] tweaks) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            char c = (char) (((word.charAt(i) - 'a' + tweaks[i]) % 26) + 'a');
            result.append(c);
        }
        return result.toString();
    }
}