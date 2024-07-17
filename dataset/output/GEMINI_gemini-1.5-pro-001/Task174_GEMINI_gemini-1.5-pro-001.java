class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        long base = 26, mod = (long) 1e9 + 7;
        long hashVal = 0, powBase = 1;
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            hashVal = (hashVal * base + (s.charAt(i) - 'a')) % mod;
            if (hashVal == ((s.charAt(i) - 'a') * powBase) % mod) {
                best = i;
            }
            powBase = (powBase * base) % mod;
        }
        String add = new StringBuilder(s.substring(best + 1)).reverse().toString();
        return add + s;
    }
}