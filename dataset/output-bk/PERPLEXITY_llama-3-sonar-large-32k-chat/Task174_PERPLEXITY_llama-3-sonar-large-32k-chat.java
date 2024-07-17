public class Solution {
    public String shortestPalindrome(String s) {
        String rev_s = new StringBuilder(s).reverse().toString();
        for (int i = 0; i < s.length(); i++) {
            if (s.startsWith(rev_s.substring(i))) {
                return rev_s.substring(0, i) + s;
            }
        }
        return "";
    }
}