#include <iostream>
#include <string>
#include <cctype>

bool xo(std::string str) {
    int xCount = 0;
    int oCount = 0;
    for (char c : str) {
        if (std::tolower(c) == 'x') xCount++;
        if (std::tolower(c) == 'o') oCount++;
    }
    return xCount == oCount;
}

int main() {
    std::cout << std::boolalpha << xo("ooxx") << std::endl; // true
    std::cout << std::boolalpha << xo("xooxx") << std::endl; // false
    std::cout << std::boolalpha << xo("ooxXm") << std::endl; // true
    std::cout << std::boolalpha << xo("zpzpzpp") << std::endl; // true
    std::cout << std::boolalpha << xo("zzoo") << std::endl; // false
    return 0;
}