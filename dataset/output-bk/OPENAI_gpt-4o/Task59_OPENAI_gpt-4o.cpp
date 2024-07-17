#include <iostream>
#include <cctype>
using namespace std;

string accum(const string& s) {
    string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (i > 0) result += '-';
        result += toupper(s[i]);
        for (size_t j = 0; j < i; ++j) {
            result += tolower(s[i]);
        }
    }
    return result;
}

int main() {
    cout << accum("abcd") << endl;       // Output: A-Bb-Ccc-Dddd
    cout << accum("RqaEzty") << endl;    // Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
    cout << accum("cwAt") << endl;       // Output: C-Ww-Aaa-Tttt
    return 0;
}