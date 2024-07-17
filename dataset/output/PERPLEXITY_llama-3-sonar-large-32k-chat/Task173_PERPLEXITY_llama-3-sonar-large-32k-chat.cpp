class Solution {
public:
    string longestDupSubstring(string s) {
        int lo = 1, hi = s.length();
        string ans = "";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            string tmp = search(s, mid);
            if (tmp != "") {
                ans = tmp;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    string search(string s, int L) {
        unordered_set<string> seen;
        for (int i = 0; i <= s.length() - L; i++) {
            string tmp = s.substr(i, L);
            if (!seen.insert(tmp).second) {
                return tmp;
            }
        }
        return "";
    }
};