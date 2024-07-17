#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 1, right = s.length();
        int start = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int pos = search(s, mid);
            if (pos != -1) {
                left = mid + 1;
                start = pos;
            } else {
                right = mid - 1;
            }
        }
        return start != -1 ? s.substr(start, left - 1) : "";
    }

private:
    int search(string s, int L) {
        int mod = pow(26, L);
        int a = 26;
        int h = 0;
        for (int i = 0; i < L; i++) {
            h = (h * a + (s[i] - 'a')) % mod;
        }
        unordered_set<int> seen;
        seen.insert(h);
        for (int i = L; i < s.length(); i++) {
            h = (h * a - (s[i - L] - 'a') * pow(a, L) + (s[i] - 'a')) % mod;
            if (seen.find(h) != seen.end()) {
                return i - L + 1;
            }
            seen.insert(h);
        }
        return -1;
    }
};