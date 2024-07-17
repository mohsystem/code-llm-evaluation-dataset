#include <iostream>
#include <unordered_set>
using namespace std;

string search(const string& s, int length) {
    unordered_set<string> seen;
    for (int i = 0; i + length <= s.length(); ++i) {
        string current = s.substr(i, length);
        if (seen.find(current) != seen.end()) {
            return current;
        }
        seen.insert(current);
    }
    return "";
}

string longestDupSubstring(const string& s) {
    int left = 1, right = s.size() - 1;
    string res = "";
    while (left <= right) {
        int mid = (left + right) / 2;
        string dup = search(s, mid);
        if (!dup.empty()) {
            res = dup;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    string s1 = "banana";
    string s2 = "abcd";
    cout << longestDupSubstring(s1) << endl; // Output: "ana"
    cout << longestDupSubstring(s2) << endl; // Output: ""
    return 0;
}