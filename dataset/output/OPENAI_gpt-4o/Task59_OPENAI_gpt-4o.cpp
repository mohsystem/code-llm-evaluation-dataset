#include <iostream>
#include <string>
#include <cctype>

std::string accum(const std::string &s) {
    std::string result;
    for (size_t i = 0; i < s.size(); i++) {
        if (i > 0) result += "-";
        result += std::toupper(s[i]);
        for (size_t j = 0; j < i; j++) {
            result += std::tolower(s[i]);
        }
    }
    return result;
}

int main() {
    std::cout << accum("abcd") << std::endl;   // Output: A-Bb-Ccc-Dddd
    std::cout << accum("RqaEzty") << std::endl; // Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
    std::cout << accum("cwAt") << std::endl;  // Output: C-Ww-Aaa-Tttt
    return 0;
}