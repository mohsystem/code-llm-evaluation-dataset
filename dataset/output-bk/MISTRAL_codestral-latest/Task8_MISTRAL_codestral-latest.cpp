#include <iostream>

char findMissingLetter(char chars[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (chars[i + 1] - chars[i] > 1) {
            return chars[i] + 1;
        }
    }
    return '\0';
}

int main() {
    char chars1[] = {'a','b','c','d','f'};
    char chars2[] = {'O','Q','R','S'};
    std::cout << findMissingLetter(chars1, 5) << std::endl;  // 'e'
    std::cout << findMissingLetter(chars2, 4) << std::endl;  // 'P'
    return 0;
}