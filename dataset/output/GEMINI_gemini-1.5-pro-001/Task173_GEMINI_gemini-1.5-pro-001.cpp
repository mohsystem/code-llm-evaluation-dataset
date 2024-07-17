#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        vector<int> sa(n);
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
        }
        sort(sa.begin(), sa.end(), [&](int i, int j) { return s.substr(i) < s.substr(j); });

        vector<int> lcp(n);
        for (int i = 1; i < n; ++i) {
            int len = 0;
            while (sa[i] + len < n && sa[i - 1] + len < n && s[sa[i] + len] == s[sa[i - 1] + len]) {
                ++len;
            }
            lcp[i] = len;
        }

        int start = 0;
        int maxlen = 0;
        for (int i = 1; i < n; ++i) {
            if (lcp[i] > maxlen) {
                maxlen = lcp[i];
                start = sa[i];
            }
        }

        if (maxlen > 0) {
            return s.substr(start, maxlen);
        } else {
            return "";
        }
    }
};