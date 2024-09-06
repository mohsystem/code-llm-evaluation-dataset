#include <iostream>
#include <string>
using namespace std;

bool xo(string s) {
    int xCount = 0, oCount = 0;
    for (char c : s) {
        if (tolower(c) == 'x') xCount++;
        if (tolower(c) == 'o') oCount++;
    }
    return xCount == oCount;
}