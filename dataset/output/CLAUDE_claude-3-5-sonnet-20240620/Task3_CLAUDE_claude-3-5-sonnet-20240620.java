
import java.util.HashSet;
import java.util.Set;

public class PangramChecker {
    public static boolean isPangram(String sentence) {
        Set<Character> letters = new HashSet<>();
        for (char c : sentence.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
                letters.add(c);
            }
        }
        return letters.size() == 26;
    }

    public static void main(String[] args) {
        String test1 = "The quick brown fox jumps over the lazy dog";
        String test2 = "This is not a pangram";
        System.out.println(isPangram(test1));  // true
        System.out.println(isPangram(test2));  // false
    }
}
