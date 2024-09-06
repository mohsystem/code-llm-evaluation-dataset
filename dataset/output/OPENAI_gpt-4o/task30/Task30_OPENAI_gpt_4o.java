import java.util.*;

public class Task30_OPENAI_gpt_4o {
    public static String longest(String s1, String s2) {
        Set<Character> charSet = new HashSet<>();
        for (char c : (s1 + s2).toCharArray()) {
            charSet.add(c);
        }
        List<Character> charList = new ArrayList<>(charSet);
        Collections.sort(charList);
        StringBuilder sb = new StringBuilder();
        for (char c : charList) {
            sb.append(c);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String a = "xyaabbbccccdefww";
        String b = "xxxxyyyyabklmopq";
        System.out.println(longest(a, b));
        
        a = "abcdefghijklmnopqrstuvwxyz";
        System.out.println(longest(a, a));
    }
}