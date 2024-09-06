import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public static String longest(String s1, String s2) {
        StringBuilder sb = new StringBuilder();
        Set<Character> seen = new HashSet<>();
        for (char c : (s1 + s2).toCharArray()) {
            if (seen.add(c)) {
                sb.append(c);
            }
        }
        char[] chars = sb.toString().toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}