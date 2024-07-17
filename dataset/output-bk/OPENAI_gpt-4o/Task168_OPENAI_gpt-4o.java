import java.util.Arrays;
import java.util.stream.Collectors;

public class Main {
    public static String tweakLetters(String txt, int[] arr) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < txt.length(); i++) {
            result.append((char) (txt.charAt(i) + arr[i]));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(tweakLetters("apple", new int[]{0, 1, -1, 0, -1}));
        System.out.println(tweakLetters("many", new int[]{0, 0, 0, -1}));
        System.out.println(tweakLetters("rhino", new int[]{1, 1, 1, 1, 1}));
    }
}