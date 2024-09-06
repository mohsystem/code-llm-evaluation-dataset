class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        long base = 26, mod = (long) 1e9 + 7;
        long hashVal = 0, powBase = 1;
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            hashVal = (hashVal * base + (s.charAt(i) - 'a')) % mod;
            if (i == 0 || this.isPalindrome(s, 0, i)) {
                best = i + 1;
            }
        }
        return new StringBuilder(s.substring(best)).reverse().toString() + s;
    }

    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
}