class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        long long base = 26, mod = 1e9 + 7;
        long long hashVal = 0, powBase = 1;
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            hashVal = (hashVal * base + (s[i] - 'a')) % mod;
            if (i == 0 || this->isPalindrome(s, 0, i)) {
                best = i + 1;
            }
        }
        return string(s.rbegin(), s.rbegin() + n - best) + s;
    }

private:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};