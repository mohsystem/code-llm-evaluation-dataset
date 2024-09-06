
class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 0, right = s.length();
        string result = "";
        while (left < right) {
            int mid = left + (right - left) / 2;
            string candidate = rabinKarp(s, mid);
            if (!candidate.empty()) {
                left = mid + 1;
                result = candidate;
            } else {
                right = mid;
            }
        }
        return result;
    }

private:
    string rabinKarp(const string& s, int length) {
        long long q = (1LL << 31) - 1;
        long long h = 0;
        for (int i = 0; i < length; i++) {
            h = (h * 26 + s[i] - 'a') % q;
        }

        unordered_set<long long> seen;
        seen.insert(h);
        long long aL = 1;
        for (int i = 0; i < length; i++) {
            aL = (aL * 26) % q;
        }

        for (int start = 1; start <= s.length() - length; start++) {
            h = (h * 26 - (s[start - 1] - 'a') * aL % q + q) % q;
            h = (h + s[start + length - 1] - 'a') % q;
            if (seen.count(h)) {
                return s.substr(start, length);
            }
            seen.insert(h);
        }

        return "";
    }
};
