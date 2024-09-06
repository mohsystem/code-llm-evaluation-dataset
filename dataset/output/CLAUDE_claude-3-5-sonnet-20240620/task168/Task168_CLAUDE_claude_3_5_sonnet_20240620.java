
public class Task168_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String tweakLetters(String word, int[] arr) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (i < arr.length) {
                c = (char) ((c - 'a' + arr[i] + 26) % 26 + 'a');
            }
            result.append(c);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(tweakLetters("apple", new int[]{0, 1, -1, 0, -1}));
        System.out.println(tweakLetters("many", new int[]{0, 0, 0, -1}));
        System.out.println(tweakLetters("rhino", new int[]{1, 1, 1, 1, 1}));
    }
}
