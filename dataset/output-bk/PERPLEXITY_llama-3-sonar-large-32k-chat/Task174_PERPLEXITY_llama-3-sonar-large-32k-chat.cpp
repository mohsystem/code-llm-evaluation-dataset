class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        for (int i = 0; i < s.length(); i++) {
            if (s.find(rev_s.substr(i)) == 0) {
                return rev_s.substr(0, i) + s;
            }
        }
        return "";
    }
};