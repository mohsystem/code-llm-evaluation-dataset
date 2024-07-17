public class Main {
    public static String tweakLetters(String s, int[] tweaks) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = (char) (s.charAt(i) + tweaks[i]);
            if (c < 'a') {
                c += 26;
            } else if (c > 'z') {
                c -= 26;
            }
            result.append(c);
        }
        return result.toString();
    }
    public static void main(String[] args) {
        System.out.println(tweakLetters("apple", new int[]{0, 1, -1, 0, -1})); // "aqold"
        System.out.println(tweakLetters("many", new int[]{0, 0, 0, -1})); // "manx"
        System.out.println(tweakLetters("rhino", new int[]{1, 1, 1, 1, 1})); // "sijop"
    }
}