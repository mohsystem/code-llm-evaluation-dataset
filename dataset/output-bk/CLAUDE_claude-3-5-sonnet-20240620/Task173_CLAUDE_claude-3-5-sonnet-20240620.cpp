
class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 0, right = s.length();
        string res = "";
        while (left < right) {
            int mid = left + (right - left) / 2;
            string candidate = rabinKarp(s, mid);
            if (!candidate.empty()) {
                left = mid + 1;
                res = candidate;
            } else {
                right = mid;
            }
        }
        return res;
    }
    
private:
    const long long MOD = (1LL << 63) - 1;
    
    string rabinKarp(const string& s, int len) {
        if (len == 0) return "";
        long long p = 1;
        for (int i = 0; i < len - 1; i++) {
            p = (p * 26) % MOD;
        }
        
        long long cur = 0;
        for (int i = 0; i < len; i++) {
            cur = (cur * 26 + s[i] - \'a\') % MOD;
        }
        
        unordered_set<long long> seen;
        seen.insert(cur);
        
        for (int i = len; i < s.length(); i++) {
            cur = (cur * 26 - (s[i - len] - \'a\') * p % MOD + MOD) % MOD;
            cur = (cur + s[i] - \'a\') % MOD;
            if (seen.count(cur)) {
                return s.substr(i - len + 1, len);
            }
            seen.insert(cur);
        }
        return "";
    }
};
