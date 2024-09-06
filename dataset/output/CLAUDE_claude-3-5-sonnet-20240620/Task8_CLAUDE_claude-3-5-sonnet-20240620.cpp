
#include <iostream>
#include <vector>

char findMissingLetter(std::vector<char> chars) {
    for (size_t i = 0; i < chars.size() - 1; i++) {
        if (chars[i + 1] - chars[i] > 1) {
            return chars[i] + 1;
        }
    }
    return ' ';
}

int main() {
    std::cout << findMissingLetter({'a','b','c','d','f'}) << std::endl;  // Output: e
    std::cout << findMissingLetter({'O','Q','R','S'}) << std::endl;  // Output: P
    return 0;
}
