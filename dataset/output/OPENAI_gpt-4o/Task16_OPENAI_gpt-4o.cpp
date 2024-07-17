#include <iostream>
#include <string>

using namespace std;

bool solution(const string &str, const string &ending) {
    if (ending.size() > str.size()) {
        return false;
    }
    return str.compare(str.size() - ending.size(), ending.size(), ending) == 0;
}

int main() {
    cout << solution("abc", "bc") << endl; // true
    cout << solution("abc", "d") << endl; // false
    return 0;
}