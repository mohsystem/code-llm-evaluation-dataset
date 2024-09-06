class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length();
        return check(s, 1, n);
    }
    private String check(String s, int left, int right) {
        if (left > right) {
            return "";
        }
        int mid = left + (right - left) / 2;
        String substring = rabinKarp(s, mid);
        if (!substring.isEmpty()) {
            return substring;
        } else {
            String leftResult = check(s, left, mid - 1);
            String rightResult = check(s, mid + 1, right);
            return leftResult.length() >= rightResult.length() ? leftResult : rightResult;
        }
    }
    private String rabinKarp(String s, int length) {
        if (length == 0) {
            return "";
        }
        int n = s.length();
        Set<Long> seen = new HashSet<>();
        long modulus = (long) Math.pow(2, 32);
        long a = 26;
        long hash = 0;
        long power = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * a + (s.charAt(i) - 'a')) % modulus;
            power = (power * a) % modulus;
        }
        seen.add(hash);
        for (int i = 1; i <= n - length; i++) {
            hash = (hash * a - (s.charAt(i - 1) - 'a') * power % modulus + modulus) % modulus;
            hash = (hash + (s.charAt(i + length - 1) - 'a')) % modulus;
            if (seen.contains(hash)) {
                return s.substring(i, i + length);
            }
            seen.add(hash);
        }
        return "";
    }
}