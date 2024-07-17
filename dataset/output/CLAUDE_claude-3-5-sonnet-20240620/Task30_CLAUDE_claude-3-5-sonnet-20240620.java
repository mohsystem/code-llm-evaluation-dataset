
import java.util.*;

public class Solution {
    public static String longest(String s1, String s2) {
        Set<Character> charSet = new HashSet<>();
        for (char c : (s1 + s2).toCharArray()) {
            charSet.add(c);
        }
        List<Character> charList = new ArrayList<>(charSet);
        Collections.sort(charList);
        StringBuilder result = new StringBuilder();
        for (char c : charList) {
            result.append(c);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
        System.out.println(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    }
}
