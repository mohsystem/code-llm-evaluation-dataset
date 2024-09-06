
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPangram(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (char c = 'a'; c <= 'z'; c++) {
        if (str.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string test = "The quick brown fox jumps over the lazy dog";
    std::cout << std::boolalpha << isPangram(test) << std::endl;
    return 0;
}
