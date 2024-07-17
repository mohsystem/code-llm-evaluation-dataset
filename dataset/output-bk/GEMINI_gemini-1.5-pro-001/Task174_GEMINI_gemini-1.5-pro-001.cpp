class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        long long base = 26, mod = 1e9 + 7;
        long long hashVal = 0, powBase = 1;
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            hashVal = (hashVal * base + (s[i] - 'a')) % mod;
            if (hashVal == ((s[i] - 'a') * powBase) % mod) {
                best = i;
            }
            powBase = (powBase * base) % mod;
        }
        string add = s.substr(best + 1);
        reverse(add.begin(), add.end());
        return add + s;
    }
};