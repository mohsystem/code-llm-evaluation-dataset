#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool isIsogram(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    unordered_set<char> set;
    for (char c : s) {
        if (set.find(c) != set.end()) return false;
        set.insert(c);
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << isIsogram("Dermatoglyphics") << endl;  // True
    cout << isIsogram("aba") << endl;              // False
    cout << isIsogram("moOse") << endl;            // False
    return 0;
}