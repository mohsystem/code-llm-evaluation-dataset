#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<string> seen;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j += 2) {
                string sub = text.substr(i, j - i);
                if (sub.substr(0, (j - i) / 2) == sub.substr((j - i) / 2)) {
                    seen.insert(sub);
                }
            }
        }
        return seen.size();
    }
};