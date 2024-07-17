import java.util.HashSet;
import java.util.Set;

class Solution {
    public static boolean  isIsogram(String str) {
        if (str.isEmpty()) {
            return true;
        }
        Set<Character> seen = new HashSet<>();
        for (char c : str.toLowerCase().toCharArray()) {
            if (!seen.add(c)) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.println(isIsogram("Dermatoglyphics"));
        System.out.println(isIsogram("aba"));
        System.out.println(isIsogram("moOse"));
    }
}