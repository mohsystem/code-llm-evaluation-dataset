#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longest(string s1, string s2) {
    bool seen[26] = {false};
    string result = "";
    for (char c : s1 + s2) {
        if (!seen[c - 'a']) {
            result += c;
            seen[c - 'a'] = true;
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << endl;
    cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}