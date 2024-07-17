public class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        Set<String> res = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String s = text.substring(i, j);
                if (isPalindrome(s) && s.length() % 2 == 0) {
                    res.add(s);
                }
            }
        }
        return res.size();
    }

    private boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}