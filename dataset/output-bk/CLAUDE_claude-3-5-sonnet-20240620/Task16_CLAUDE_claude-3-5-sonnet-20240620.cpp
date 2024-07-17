
#include <iostream>
#include <string>

bool solution(const std::string &str, const std::string &ending) {
    if (ending.length() > str.length()) {
        return false;
    }
    return std::equal(ending.rbegin(), ending.rend(), str.rbegin());
}

int main() {
    std::cout << std::boolalpha;
    std::cout << solution("abc", "bc") << std::endl; // true
    std::cout << solution("abc", "d") << std::endl; // false
    return 0;
}
