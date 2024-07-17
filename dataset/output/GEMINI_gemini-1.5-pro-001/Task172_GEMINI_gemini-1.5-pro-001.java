import java.util.HashSet;

class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        HashSet<String> seen = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j += 2) {
                String sub = text.substring(i, j);
                if (sub.substring(0, (j - i) / 2).equals(sub.substring((j - i) / 2))) {
                    seen.add(sub);
                }
            }
        }
        return seen.size();
    }
}