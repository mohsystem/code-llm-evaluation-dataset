#include <string>
#include <algorithm>

bool isPangram(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (str.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}