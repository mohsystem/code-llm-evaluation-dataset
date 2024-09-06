#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int distinctAASubstrings(string text) {
    unordered_set<string> distinctSubstrings;
    int n = text.length();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j += 2) {
            string a = text.substr(i, (j + 1 - i) / 2);
            string b = text.substr(i + (j + 1 - i) / 2, (j + 1 - i) / 2);
            if (a == b) {
                distinctSubstrings.insert(text.substr(i, j - i + 1));
            }
        }
    }
    
    return distinctSubstrings.size();
}

int main() {
    string text1 = "abcabcabc";
    cout << distinctAASubstrings(text1) << endl;
    
    string text2 = "leetcodeleetcode";
    cout << distinctAASubstrings(text2) << endl;
    
    return 0;
}