
class Solution {
    private static final long MOD = (1L << 63) - 1;
    private String s;
    
    public String longestDupSubstring(String s) {
        this.s = s;
        int left = 0, right = s.length();
        String res = "";
        while (left < right) {
            int mid = left + (right - left) / 2;
            String candidate = rabinKarp(mid);
            if (candidate != null) {
                left = mid + 1;
                res = candidate;
            } else {
                right = mid;
            }
        }
        return res;
    }
    
    private String rabinKarp(int len) {
        long p = 1;
        for (int i = 0; i < len - 1; i++) {
            p = (p * 26) % MOD;
        }
        
        long cur = 0;
        for (int i = 0; i < len; i++) {
            cur = (cur * 26 + s.charAt(i) - \'a\') % MOD;
        }
        
        Set<Long> seen = new HashSet<>();
        seen.add(cur);
        
        for (int i = len; i < s.length(); i++) {
            cur = (cur * 26 - (s.charAt(i - len) - \'a\') * p % MOD + MOD) % MOD;
            cur = (cur + s.charAt(i) - \'a\') % MOD;
            if (seen.contains(cur)) {
                return s.substring(i - len + 1, i + 1);
            }
            seen.add(cur);
        }
        return null;
    }
}
