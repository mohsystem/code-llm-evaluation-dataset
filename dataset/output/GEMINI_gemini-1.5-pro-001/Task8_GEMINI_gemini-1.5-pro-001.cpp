#include <iostream>
#include <vector>

char findMissingLetter(std::vector<char> chars) {
    for (int i = 0; i < chars.size() - 1; i++) {
        if (chars[i + 1] - chars[i] != 1) {
            return static_cast<char>(chars[i] + 1);
        }
    }
    return ' ';
}