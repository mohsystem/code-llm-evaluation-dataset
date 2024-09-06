#include <iostream>
#include <string>

std::string accum(const std::string& s) {
    std::string result;
    for (int i = 0; i < s.length(); i++) {
        result += std::toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result += std::tolower(s[i]);
        }
        if (i < s.length() - 1) result += "-";
    }
    return result;
}

int main() {
    std::cout << accum("abcd") << std::endl;
    std::cout << accum("RqaEzty") << std::endl;
    std::cout << accum("cwAt") << std::endl;
    return 0;
}