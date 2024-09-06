class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        Set<String> s = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String sub = text.substring(i, j);
                if (sub.length() % 2 == 0 && sub.substring(0, sub.length() / 2).equals(sub.substring(sub.length() / 2))) {
                    s.add(sub);
                }
            }
        }
        return s.size();
    }
}