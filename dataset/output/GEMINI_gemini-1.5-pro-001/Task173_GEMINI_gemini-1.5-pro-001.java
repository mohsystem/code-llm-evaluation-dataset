import java.util.Arrays;

class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length();
        Integer[] sa = new Integer[n];
        for (int i = 0; i < n; i++) {
            sa[i] = i;
        }
        Arrays.sort(sa, (i1, i2) -> s.substring(i1).compareTo(s.substring(i2)));

        int[] lcp = new int[n];
        for (int i = 1; i < n; i++) {
            lcp[i] = 0;
            while (sa[i] + lcp[i] < n && sa[i - 1] + lcp[i] < n && s.charAt(sa[i] + lcp[i]) == s.charAt(sa[i - 1] + lcp[i])) {
                lcp[i]++;
            }
        }

        int start = 0;
        int length = 0;
        for (int i = 1; i < n; i++) {
            if (lcp[i] > length) {
                length = lcp[i];
                start = sa[i];
            }
        }

        if (length > 0) {
            return s.substring(start, start + length);
        } else {
            return "";
        }
    }
}