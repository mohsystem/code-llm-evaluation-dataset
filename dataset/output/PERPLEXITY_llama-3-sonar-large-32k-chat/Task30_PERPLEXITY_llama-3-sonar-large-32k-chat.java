public class Main {
    public static void main(String[] args) {
        System.out.println(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
        System.out.println(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    }

    public static String longest(String s1, String s2) {
        String combined = s1 + s2;
        String unique = "";
        for (char c : combined.toCharArray()) {
            if (!unique.contains(String.valueOf(c))) {
                unique += c;
            }
        }
        char[] chars = unique.toCharArray();
        java.util.Arrays.sort(chars);
        return new String(chars);
    }
}