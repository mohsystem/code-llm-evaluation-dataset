import java.util.HashSet;
import java.util.Set;

public class Task3_OPENAI_gpt_4o {
    public static boolean isPangram(String s) {
        s = s.toLowerCase();
        Set<Character> alphabetSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                alphabetSet.add(c);
            }
        }
        return alphabetSet.size() == 26;
    }

    public static void main(String[] args) {
        String s = "The quick brown fox jumps over the lazy dog";
        System.out.println(isPangram(s));  // Output: true
    }
}