import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isPangram(String s) {
        Set<Character> seen = new HashSet<>();
        for (char c : s.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
                seen.add(c);
            }
        }
        return seen.size() == 26;
    }
}