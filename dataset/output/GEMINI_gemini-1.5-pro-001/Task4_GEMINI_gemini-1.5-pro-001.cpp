#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isIsogram(string str) {
    if (str.empty()) {
        return true;
    }
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    unordered_set<char> seen;
    for (char c : str) {
        if (seen.count(c)) {
            return false;
        }
        seen.insert(c);
    }
    return true;
}