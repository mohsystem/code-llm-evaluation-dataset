
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        vector<int> lps(temp.length(), 0);
        
        for (int i = 1; i < temp.length(); i++) {
            int j = lps[i-1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j-1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        return rev.substr(0, s.length() - lps.back()) + s;
    }
};

int main() {
    Solution sol;
    cout << sol.shortestPalindrome("aacecaaa") << endl;  // Output: "aaacecaaa"
    cout << sol.shortestPalindrome("abcd") << endl;      // Output: "dcbabcd"
    return 0;
}
