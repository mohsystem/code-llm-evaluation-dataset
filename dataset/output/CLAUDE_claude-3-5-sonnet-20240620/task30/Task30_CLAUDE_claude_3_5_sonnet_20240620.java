
import java.util.*;

public class Task30_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String longest(String s1, String s2) {
        Set<Character> set = new HashSet<>();
        for (char c : (s1 + s2).toCharArray()) {
            set.add(c);
        }
        List<Character> list = new ArrayList<>(set);
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (char c : list) {
            sb.append(c);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
        System.out.println(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    }
}
