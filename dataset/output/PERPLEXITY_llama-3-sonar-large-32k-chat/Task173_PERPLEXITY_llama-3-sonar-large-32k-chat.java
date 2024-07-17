public class Solution {
    public String longestDupSubstring(String s) {
        int lo = 1, hi = s.length();
        String ans = "";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            String tmp = search(s, mid);
            if (!tmp.equals("")) {
                ans = tmp;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private String search(String s, int L) {
        Set<String> seen = new HashSet<>();
        for (int i = 0; i <= s.length() - L; i++) {
            String tmp = s.substring(i, i + L);
            if (!seen.add(tmp)) {
                return tmp;
            }
        }
        return "";
    }
}