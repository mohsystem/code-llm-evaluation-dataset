#include <string>
#include <iostream>
using namespace std;
bool solution(string str1, string str2) {
    return str1.substr(str1.length() - str2.length()) == str2;
}
int main() {
    cout << (solution("abc", "bc") ? "true" : "false") << endl; // returns true
    cout << (solution("abc", "d") ? "true" : "false") << endl; // returns false
    return 0;
}