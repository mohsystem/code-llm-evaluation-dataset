#include <string>
#include <set>
#include <algorithm>

using namespace std;

string longest(const string& s1, const string& s2) {
    set<char> seen;
    string result;
    for (char c : s1 + s2) {
        if (seen.insert(c).second) {
            result += c;
        }
    }
    sort(result.begin(), result.end());
    return result;
}