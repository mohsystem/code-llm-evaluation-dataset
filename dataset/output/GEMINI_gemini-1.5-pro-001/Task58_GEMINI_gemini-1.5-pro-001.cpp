#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool XO(string str) {
    int xCount = 0;
    int oCount = 0;

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (char c : str) {
        if (c == 'x') {
            xCount++;
        } else if (c == 'o') {
            oCount++;
        }
    }

    return xCount == oCount;
}

int main() {
    cout << boolalpha << XO("ooxx") << endl; // true
    cout << boolalpha << XO("xooxx") << endl; // false
    cout << boolalpha << XO("ooxXm") << endl; // true
    cout << boolalpha << XO("zpzpzpp") << endl; // true
    cout << boolalpha << XO("zzoo") << endl; // false
    return 0;
}