import java.util.*;

public class Task30_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String longest(String a, String b) {
        Set<Character> set = new HashSet<>();
        for (char c : a.toCharArray()) set.add(c);
        for (char c : b.toCharArray()) set.add(c);
        char[] chars = new char[set.size()];
        int i = 0;
        for (char c : set) chars[i++] = c;
        Arrays.sort(chars);
        return new String(chars);
    }
    public static void main(String[] args) {
        System.out.println(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
        System.out.println(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    }
}