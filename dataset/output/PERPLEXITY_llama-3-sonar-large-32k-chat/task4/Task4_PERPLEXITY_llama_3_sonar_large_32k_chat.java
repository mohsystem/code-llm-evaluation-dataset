import java.util.HashSet;
import java.util.Set;

public class Task4_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean isIsogram(String string) {
        string = string.toLowerCase();
        Set<Character> set = new HashSet<>();
        for (char c : string.toCharArray()) {
            if (!set.add(c)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isIsogram("Dermatoglyphics"));  // true
        System.out.println(isIsogram("aba"));  // false
        System.out.println(isIsogram("moOse"));  // false
    }
}