#include <iostream>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s) {
    if (s.length() == 0) return s;
    string rev_s = string(s.rbegin(), s.rend());
    for (int i = 0; i <= s.length(); i++) {
        if (s.substr(0, s.length() - i) == rev_s.substr(i)) {
            return rev_s.substr(0, i) + s;
        }
    }
    return "";
}

int main() {
    string s1 = "aacecaaa";
    string s2 = "abcd";
    cout << shortestPalindrome(s1) << endl;  // Output: aaacecaaa
    cout << shortestPalindrome(s2) << endl;  // Output: dcbabcd
    return 0;
}