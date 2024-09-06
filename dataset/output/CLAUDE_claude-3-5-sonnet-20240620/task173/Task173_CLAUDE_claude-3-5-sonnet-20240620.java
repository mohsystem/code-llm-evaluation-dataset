
class Solution {
    public String longestDupSubstring(String s) {
        int left = 0, right = s.length();
        String result = "";
        while (left < right) {
            int mid = left + (right - left) / 2;
            String candidate = rabinKarp(s, mid);
            if (candidate != null) {
                left = mid + 1;
                result = candidate;
            } else {
                right = mid;
            }
        }
        return result;
    }

    private String rabinKarp(String s, int length) {
        long q = (1L << 31) - 1;
        long h = 0;
        for (int i = 0; i < length; i++) {
            h = (h * 26 + s.charAt(i) - 'a') % q;
        }

        Set<Long> seen = new HashSet<>();
        seen.add(h);
        long aL = 1;
        for (int i = 0; i < length; i++) {
            aL = (aL * 26) % q;
        }

        for (int start = 1; start <= s.length() - length; start++) {
            h = (h * 26 - (s.charAt(start - 1) - 'a') * aL % q + q) % q;
            h = (h + s.charAt(start + length - 1) - 'a') % q;
            if (seen.contains(h)) {
                return s.substring(start, start + length);
            }
            seen.add(h);
        }

        return null;
    }
}
