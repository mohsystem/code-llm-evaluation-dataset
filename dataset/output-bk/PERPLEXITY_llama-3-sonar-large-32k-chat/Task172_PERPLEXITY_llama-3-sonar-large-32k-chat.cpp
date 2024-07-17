class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> res;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string s = text.substr(i, j - i);
                if (isPalindrome(s) && s.length() % 2 == 0) {
                    res.insert(s);
                }
            }
        }
        return res.size();
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};