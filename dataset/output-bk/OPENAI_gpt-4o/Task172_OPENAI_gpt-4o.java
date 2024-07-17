import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        System.out.println(distinctConcatenations("abcabcabc")); // Output: 3
        System.out.println(distinctConcatenations("leetcodeleetcode")); // Output: 2
    }

    public static int distinctConcatenations(String text) {
        HashSet<String> seen = new HashSet<>();
        int length = text.length();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j <= length; j++) {
                String sub = text.substring(i, j);
                if (sub.length() % 2 == 0) {
                    int halfLen = sub.length() / 2;
                    if (sub.substring(0, halfLen).equals(sub.substring(halfLen))) {
                        seen.add(sub);
                    }
                }
            }
        }
        return seen.size();
    }
}