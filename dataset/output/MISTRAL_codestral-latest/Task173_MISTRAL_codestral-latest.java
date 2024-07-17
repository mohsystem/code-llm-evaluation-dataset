public class Solution {
    public String longestDupSubstring(String s) {
        int left = 1, right = s.length();
        int start = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int pos = search(s, mid);
            if (pos != -1) {
                left = mid + 1;
                start = pos;
            } else {
                right = mid - 1;
            }
        }
        return start != -1 ? s.substring(start, start + left - 1) : "";
    }

    private int search(String s, int L) {
        int mod = (int) Math.pow(26, L);
        int a = 26;
        int h = 0;
        for (int i = 0; i < L; i++) {
            h = (h * a + (s.charAt(i) - 'a')) % mod;
        }
        Set<Integer> seen = new HashSet<>();
        seen.add(h);
        for (int i = L; i < s.length(); i++) {
            h = (h * a - (s.charAt(i - L) - 'a') * (int) Math.pow(a, L) + (s.charAt(i) - 'a')) % mod;
            if (seen.contains(h)) {
                return i - L + 1;
            }
            seen.add(h);
        }
        return -1;
    }
}