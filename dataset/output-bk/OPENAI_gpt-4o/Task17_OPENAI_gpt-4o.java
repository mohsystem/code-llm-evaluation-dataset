import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        // Add test cases here
        System.out.println(toJadenCase("How can mirrors be real if our eyes aren't real"));
        System.out.println(toJadenCase(""));
        System.out.println(toJadenCase(null));
    }

    public static String toJadenCase(String phrase) {
        if (phrase == null || phrase.isEmpty()) {
            return null;
        }
        StringTokenizer tokens = new StringTokenizer(phrase);
        StringBuilder jadenCase = new StringBuilder();

        while (tokens.hasMoreTokens()) {
            String word = tokens.nextToken();
            jadenCase.append(Character.toUpperCase(word.charAt(0))).append(word.substring(1)).append(" ");
        }

        return jadenCase.toString().trim();
    }
}