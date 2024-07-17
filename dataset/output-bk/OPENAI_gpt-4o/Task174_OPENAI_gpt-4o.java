public class Main {
    public static String shortestPalindrome(String s) {
        if (s.length() == 0) return s;
        String rev_s = new StringBuilder(s).reverse().toString();
        for (int i = 0; i <= s.length(); i++) {
            if (s.startsWith(rev_s.substring(i))) {
                return rev_s.substring(0, i) + s;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        String s1 = "aacecaaa";
        String s2 = "abcd";
        System.out.println(shortestPalindrome(s1));  // Output: aaacecaaa
        System.out.println(shortestPalindrome(s2));  // Output: dcbabcd
    }
}