import java.util.HashSet;

public class Task4_OPENAI_gpt_4o {
    public static boolean isIsogram(String s) {
        s = s.toLowerCase();
        HashSet<Character> set = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (set.contains(c)) return false;
            set.add(c);
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isIsogram("Dermatoglyphics"));  // True
        System.out.println(isIsogram("aba"));              // False
        System.out.println(isIsogram("moOse"));            // False
    }
}