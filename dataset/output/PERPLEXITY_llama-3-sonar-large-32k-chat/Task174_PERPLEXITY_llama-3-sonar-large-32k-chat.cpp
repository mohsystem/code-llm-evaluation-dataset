class Solution {
public:
    string shortestPalindrome(string s) {
        string a = s + "#" + string(rbegin(s), rend(s));
        vector<int> k(a.size());
        for (int i = 1; i < a.size(); i++) {
            int j = k[i-1];
            while (j > 0 && a[i] != a[j]) {
                j = k[j-1];
            }
            k[i] = j + (a[i] == a[j]) ? 1 : 0;
        }
        return string(rbegin(s) + k[k.size()-1], rend(s)) + s;
    }
};