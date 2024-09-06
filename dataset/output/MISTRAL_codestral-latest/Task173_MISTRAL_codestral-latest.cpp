#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = s[i] - 'a';
        }
        int a = 26;
        long mod = pow(2, 32);

        int check(int length) {
            long h = 0;
            for (int i = 0; i < length; i++) {
                h = (h * a + nums[i]) % mod;
            }
            unordered_set<long> seen;
            seen.insert(h);
            long aL = 1;
            for (int i = 1; i <= length; i++) {
                aL = (aL * a) % mod;
            }
            for (int start = 1; start <= n - length; start++) {
                h = (h * a - nums[start - 1] * aL + nums[start + length - 1]) % mod;
                if (seen.find(h) != seen.end()) {
                    return start;
                }
                seen.insert(h);
            }
            return -1;
        }

        int start = -1, length = 0;
        for (int k = 1; k < n; k++) {
            int pos = check(k);
            if (pos != -1 && k > length) {
                start = pos;
                length = k;
            }
        }
        return start != -1 ? s.substr(start, length) : "";
    }
};