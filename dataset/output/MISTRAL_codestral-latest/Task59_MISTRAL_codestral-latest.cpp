#include <string>
#include <cctype>

std::string accum(const std::string &s) {
    std::string result;
    for (int i = 0; i < s.length(); i++) {
        if (i > 0) result += "-";
        result += toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result += tolower(s[i]);
        }
    }
    return result;
}