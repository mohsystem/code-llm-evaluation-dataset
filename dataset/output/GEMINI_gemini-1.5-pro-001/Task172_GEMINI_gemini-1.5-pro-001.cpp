class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> s;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string sub = text.substr(i, j - i);
                if (sub.length() % 2 == 0 && sub.substr(0, sub.length() / 2) == sub.substr(sub.length() / 2)) {
                    s.insert(sub);
                }
            }
        }
        return s.size();
    }
};