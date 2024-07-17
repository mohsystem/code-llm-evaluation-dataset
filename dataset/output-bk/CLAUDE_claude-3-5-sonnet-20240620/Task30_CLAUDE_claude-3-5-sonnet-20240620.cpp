
#include <iostream>
#include <string>
#include <set>

using namespace std;

string longest(const string& s1, const string& s2) {
    set<char> charSet;
    for (char c : s1) charSet.insert(c);
    for (char c : s2) charSet.insert(c);
    
    string result;
    for (char c : charSet) result += c;
    return result;
}

int main() {
    cout << longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") << endl;
    cout << longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}
