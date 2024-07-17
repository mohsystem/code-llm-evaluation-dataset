
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        vector<int> lps(temp.length(), 0);
        
        int length = 0;
        int i = 1;
        while (i < temp.length()) {
            if (temp[i] == temp[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return rev.substr(0, rev.length() - lps.back()) + s;
    }
};
