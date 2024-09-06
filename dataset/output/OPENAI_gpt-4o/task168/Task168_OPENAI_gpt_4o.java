import java.util.Arrays;

public class Task168_OPENAI_gpt_4o {
    public static String tweakLetters(String s, int[] arr) {
        StringBuilder result = new StringBuilder(s.length());
        for (int i = 0; i < s.length(); i++) {
            result.append((char) ( ((s.charAt(i) - 'a' + arr[i]) % 26 + 26) % 26 + 'a') );
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(tweakLetters("apple", new int[]{0, 1, -1, 0, -1}));  // "aqold"
        System.out.println(tweakLetters("many", new int[]{0, 0, 0, -1}));       // "manx"
        System.out.println(tweakLetters("rhino", new int[]{1, 1, 1, 1, 1}));    // "sijop"
    }
}