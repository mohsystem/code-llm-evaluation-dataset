class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        string longest = "";
        for (int len = n / 2; len >= 1; len--) {
            for (int i = 0; i <= n - len; i++) {
                string substr = s.substr(i, len);
                size_t first = s.find(substr);
                size_t last = s.rfind(substr);
                if (first != last && substr.size() > longest.size()) {
                    longest = substr;
                }
            }
        }
        return longest;
    }
};